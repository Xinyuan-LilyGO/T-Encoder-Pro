/*
 * @Description: None
 * @version: V1.0.0
 * @Author: LILYGO_L
 * @Date: 2023-10-05 11:31:11
 * @LastEditors: LILYGO_L
 * @LastEditTime: 2024-01-31 13:42:36
 * @License: GPL 3.0
 */
#include <Arduino.h>
#include <stdio.h>
#include "lvgl.h"
#include "widgets_init.h"
#include "custom.h"
#include "pin_config.h"
#include "events_init.h"
#include "Material_16Bit.h"
#include <WiFi.h>
#include <HTTPClient.h>

#define WIFI_SSID "xinyuandianzi"
#define WIFI_PASSWORD "AA15994823428"
// #define WIFI_SSID "LilyGo-AABB"
// #define WIFI_PASSWORD "xinyuandianzi"

#define WIFI_CONNECT_WAIT_MAX 5000

#define NTP_SERVER1 "pool.ntp.org"
#define NTP_SERVER2 "time.nist.gov"
#define GMT_OFFSET_SEC 8 * 3600 // Time zone setting function, written as 8 * 3600 in East Eighth Zone (UTC/GMT+8:00)
#define DAY_LIGHT_OFFSET_SEC 0  // Fill in 3600 for daylight saving time, otherwise fill in 0

enum KNOB_State
{
    KNOB_NULL,
    KNOB_INCREMENT,
    KNOB_DECREMENT,
};

static size_t CycleTime = 0;

/// Predefined RGB colors
static const uint32_t WS2812B_Color[] = {
    0x000000,
    0xFF0000,
    0x008000,
    0x0000FF,
};

int32_t KNOB_Data = 0;
bool KNOB_Trigger_Flag = false;
uint8_t KNOB_State_Flag = KNOB_State::KNOB_NULL;

bool Wifi_Connection_Flag = false;

//  0B000000[KNOB_DATA_A][KNOB_DATA_B]
uint8_t KNOB_Previous_Logical = 0B00000000;

size_t KNOB_CycleTime = 0;

void KNOB_Logical_Scan_Loop(void)
{
    uint8_t KNOB_Logical_Scan = 0B00000000;

    if (digitalRead(KNOB_DATA_A) == 1)
    {
        KNOB_Logical_Scan |= 0B00000010;
    }
    else
    {
        KNOB_Logical_Scan &= 0B11111101;
    }

    if (digitalRead(KNOB_DATA_B) == 1)
    {
        KNOB_Logical_Scan |= 0B00000001;
    }
    else
    {
        KNOB_Logical_Scan &= 0B11111110;
    }

    if (KNOB_Previous_Logical != KNOB_Logical_Scan)
    {
        if (KNOB_Logical_Scan == 0B00000000 || KNOB_Logical_Scan == 0B00000011)
        {
            KNOB_Previous_Logical = KNOB_Logical_Scan;
            KNOB_Trigger_Flag = true;
        }
        else
        {
            if (KNOB_Logical_Scan == 0B00000010)
            {
                switch (KNOB_Previous_Logical)
                {
                case 0B00000000:
                    KNOB_State_Flag = KNOB_State::KNOB_INCREMENT;
                    break;
                case 0B00000011:
                    KNOB_State_Flag = KNOB_State::KNOB_DECREMENT;
                    break;

                default:
                    break;
                }
            }
            if (KNOB_Logical_Scan == 0B00000001)
            {
                switch (KNOB_Previous_Logical)
                {
                case 0B00000000:
                    KNOB_State_Flag = KNOB_State::KNOB_DECREMENT;
                    break;
                case 0B00000011:
                    KNOB_State_Flag = KNOB_State::KNOB_INCREMENT;
                    break;

                default:
                    break;
                }
            }
        }
        // delay(10);
    }
}

void Wifi_STA_Test(void)
{
    String text;
    int wifi_num = 0;

    gfx->fillScreen(BLACK);
    gfx->setCursor(0, 0);
    gfx->setTextSize(2);
    gfx->setTextColor(GREEN);

    Serial.println("\nScanning wifi");
    gfx->printf("Scanning wifi\n");
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    wifi_num = WiFi.scanNetworks();
    if (wifi_num == 0)
    {
        text = "\nWiFi scan complete !\nNo wifi discovered.\n";
    }
    else
    {
        text = "\nWiFi scan complete !\n";
        text += wifi_num;
        text += " wifi discovered.\n\n";

        for (int i = 0; i < wifi_num; i++)
        {
            text += (i + 1);
            text += ": ";
            text += WiFi.SSID(i);
            text += " (";
            text += WiFi.RSSI(i);
            text += ")";
            text += (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " \n" : "*\n";
            delay(10);
        }
    }

    Serial.println(text);
    gfx->println(text);

    delay(3000);
    text.clear();
    gfx->fillScreen(BLACK);
    gfx->setCursor(0, 10);

    text = "Connecting to ";
    Serial.print("Connecting to ");
    gfx->printf("Connecting to\n");
    text += WIFI_SSID;
    text += "\n";

    Serial.print(WIFI_SSID);
    gfx->printf("%s", WIFI_SSID);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    uint32_t last_tick = millis();

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        gfx->printf(".");
        text += ".";
        delay(100);

        if (millis() - last_tick > WIFI_CONNECT_WAIT_MAX)
        {
            Wifi_Connection_Flag = false;
            break;
        }
        else
        {
            Wifi_Connection_Flag = true;
        }
    }

    if (Wifi_Connection_Flag == true)
    {
        text += "\nThe connection was successful ! \nTakes ";
        Serial.print("\nThe connection was successful ! \nTakes ");
        gfx->printf("\nThe connection was successful ! \nTakes ");
        text += millis() - last_tick;
        Serial.print(millis() - last_tick);
        gfx->print(millis() - last_tick);
        text += " ms\n";
        Serial.println(" ms\n");
        gfx->printf(" ms\n");

        gfx->setTextColor(GREEN);
        gfx->printf("\nWifi test passed!");
    }
    else
    {
        gfx->setTextColor(RED);
        gfx->printf("\nWifi test error!\n");
    }
}

void Btn_Start_Testing_Initialization(lv_ui *ui)
{
    // Write codes Test_btn_1
    ui->Test_btn_1 = lv_btn_create(ui->Test);
    ui->Test_btn_1_label = lv_label_create(ui->Test_btn_1);
    lv_label_set_text(ui->Test_btn_1_label, "Start testing");
    lv_label_set_long_mode(ui->Test_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Test_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Test_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Test_btn_1, CIT_UI.LCD_Width / 9.1, CIT_UI.LCD_Height / 3.2);
    lv_obj_set_size(ui->Test_btn_1, CIT_UI.LCD_Width / 1.28, CIT_UI.LCD_Height / 4.2);
    lv_obj_set_scrollbar_mode(ui->Test_btn_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for Test_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Test_btn_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Test_btn_1, lv_color_hex(0xff7f58), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Test_btn_1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Test_btn_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Test_btn_1, lv_color_hex(0xc9c9c9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Test_btn_1, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Test_btn_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Test_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Test_btn_1, &lv_font_arial_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Test_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Update current screen layout.
    lv_obj_update_layout(ui->Test);

    // Init events for screen.
    events_init_Test(ui);
}

void Window_Rotary_Encoder_WS2812B_Test_Loop(void)
{
    if (millis() > CycleTime)
    {
        gfx->fillScreen(WHITE);

        gfx->setCursor(50, CIT_UI.LCD_Width / 2);
        gfx->setTextColor(ORANGE);
        gfx->setTextSize(3);
        gfx->printf("Rotate the knob");

        CycleTime = millis() + 3000; // 3000ms
    }

    if (millis() > KNOB_CycleTime)
    {
        KNOB_Logical_Scan_Loop();
        KNOB_CycleTime = millis() + 20; // 20ms
    }

    if (KNOB_Trigger_Flag == true)
    {
        KNOB_Trigger_Flag = false;

        switch (KNOB_State_Flag)
        {
        case KNOB_State::KNOB_INCREMENT:
            KNOB_Data++;
            CycleTime = millis() + 3000; // 3000ms
            Serial.printf("\nKNOB_Data: %d\n", KNOB_Data);

            if (KNOB_Data > 3)
            {
                KNOB_Data = 0;
            }

            gfx->fillScreen(WHITE);

            gfx->setCursor(60, 100);
            gfx->setTextColor(PINK);
            gfx->setTextSize(3);
            gfx->printf("[KNOB Trigger]");

            gfx->setCursor(60, 130);
            gfx->printf("[KNOB Data]: %d", KNOB_Data);

            gfx->setCursor(60, 200);
            gfx->printf("[Buzzer SET]: ");

            switch (KNOB_Data)
            {
            case 0:
                gfx->printf("OFF");
                ledcWrite(1, 0);
                break;
            case 1:
                gfx->printf("1");
                ledcSetup(1, 1500, 8);
                ledcWrite(1, 127);
                delay(100);
                ledcWrite(1, 0);
                break;
            case 2:
                gfx->printf("2");
                ledcSetup(1, 2000, 8);
                ledcWrite(1, 127);
                delay(100);
                ledcWrite(1, 0);
                break;
            case 3:
                gfx->printf("3");
                ledcSetup(1, 2500, 8);
                ledcWrite(1, 127);
                delay(100);
                ledcWrite(1, 0);
                break;

            default:
                break;
            }

            break;
        case KNOB_State::KNOB_DECREMENT:
            KNOB_Data--;
            CycleTime = millis() + 3000; // 3000ms
            Serial.printf("\nKNOB_Data: %d\n", KNOB_Data);

            if (KNOB_Data < 0)
            {
                KNOB_Data = 3;
            }

            gfx->fillScreen(WHITE);

            gfx->setCursor(60, 100);
            gfx->setTextColor(PURPLE);
            gfx->setTextSize(3);
            gfx->printf("[KNOB Trigger]");

            gfx->setCursor(60, 130);
            gfx->printf("[KNOB Data]: %d", KNOB_Data);

            gfx->setCursor(60, 200);
            gfx->printf("[Buzzer SET]: ");

            switch (KNOB_Data)
            {
            case 0:
                gfx->printf("OFF");
                ledcWrite(1, 0);
                break;
            case 1:
                gfx->printf("1");
                ledcSetup(1, 1500, 8);
                ledcWrite(1, 127);
                delay(100);
                ledcWrite(1, 0);
                break;
            case 2:
                gfx->printf("2");
                ledcSetup(1, 2000, 8);
                ledcWrite(1, 127);
                delay(100);
                ledcWrite(1, 0);
                break;
            case 3:
                gfx->printf("3");
                ledcSetup(1, 2500, 8);
                ledcWrite(1, 127);
                delay(100);
                ledcWrite(1, 0);
                break;

            default:
                break;
            }
            break;

        default:
            break;
        }
    }
}

void Window_OLED_Brightness_Test_Loop(void)
{
    if (CIT_UI.Window_Button_Start_Testing_Flag == true)
    {
        CIT_UI.Window_Button_Start_Testing_Flag = false;

        for (int i = 255; i > 0; i--)
        {
            gfx->Display_Brightness(i);
            delay(5);
        }
        delay(1000);
        for (int i = 0; i <= 255; i++)
        {
            gfx->Display_Brightness(i);
            delay(2);
        }
        delay(500);
    }
}

void Window_OLED_Edge_Detection_Test_Loop(void)
{
    if (CIT_UI.Window_Button_Start_Testing_Flag == true)
    {
        CIT_UI.Window_Button_Start_Testing_Flag = false;

        gfx->fillScreen(WHITE);

        gfx->setCursor(100, CIT_UI.LCD_Width / 2);
        gfx->setTextColor(ORANGE);
        gfx->setTextSize(3);
        gfx->printf("R=388px");
        gfx->drawRect(1, 1, 390 - 2, 390 - 2, RED);
        delay(3000);
        gfx->fillScreen(WHITE);
        gfx->setCursor(100, CIT_UI.LCD_Width / 2);
        gfx->printf("R=390px");
        gfx->drawRect(0, 0, 390, 390, RED);
        delay(3000);
        gfx->fillScreen(WHITE);
        gfx->setCursor(100, CIT_UI.LCD_Width / 2);
        gfx->printf("R=388px");
        gfx->drawRect(1, 1, 390 - 2, 390 - 2, RED);
        delay(5000);

        // Write the load screen code.
        lv_obj_t *act_scr = lv_scr_act();
        lv_disp_t *d = lv_obj_get_disp(act_scr);
        if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
        {
            if (guider_ui.Test_del == true)
            {
                setup_scr_Test(&guider_ui);
            }
            lv_scr_load_anim(guider_ui.Test, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, true);
            guider_ui.Test_del = true;
        }

        CIT_UI.Window_Initialization_Flag = false;
    }
}

void Window_OLED_Contrast_Test_Loop(void)
{
    if (CIT_UI.Window_Button_Start_Testing_Flag == true)
    {
        CIT_UI.Window_Button_Start_Testing_Flag = false;

        gfx->fillScreen(RED);
        gfx->setCursor(10, CIT_UI.LCD_Width / 2);
        gfx->setTextColor(WHITE);
        gfx->setTextSize(2);

        gfx->printf("OLED Contrast: Contrast Off");
        gfx->SetContrast(SH8601_ContrastOff);
        delay(2000);

        gfx->setCursor(10, CIT_UI.LCD_Width / 2);
        gfx->fillScreen(RED);
        gfx->printf("OLED Contrast: Low Contrast");
        gfx->SetContrast(SH8601_LowContrast);
        delay(2000);

        gfx->setCursor(10, CIT_UI.LCD_Width / 2);
        gfx->fillScreen(RED);
        gfx->printf("OLED Contrast: Medium Contrast");
        gfx->SetContrast(SH8601_MediumContrast);
        delay(2000);

        gfx->setCursor(10, CIT_UI.LCD_Width / 2);
        gfx->fillScreen(RED);
        gfx->printf("OLED Contrast: High Contrast");
        gfx->SetContrast(SH8601_HighContrast);
        delay(2000);

        gfx->SetContrast(SH8601_ContrastOff);

        // Write the load screen code.
        lv_obj_t *act_scr = lv_scr_act();
        lv_disp_t *d = lv_obj_get_disp(act_scr);
        if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
        {
            if (guider_ui.Test_del == true)
            {
                setup_scr_Test(&guider_ui);
            }
            lv_scr_load_anim(guider_ui.Test, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, true);
            guider_ui.Test_del = true;
        }

        CIT_UI.Window_Initialization_Flag = false;
    }
}

void Window_OLED_Display_Color_Test_Loop(void)
{
    if (CIT_UI.Window_Button_Start_Testing_Flag == true)
    {
        CIT_UI.Window_Button_Start_Testing_Flag = false;

        gfx->fillScreen(RED);
        delay(3000);
        gfx->fillScreen(GREEN);
        delay(3000);
        gfx->fillScreen(BLUE);
        delay(3000);
        gfx->fillScreen(WHITE);

        gfx->draw16bitRGBBitmap(0, 0, (uint16_t *)gImage_1, CIT_UI.LCD_Width, CIT_UI.LCD_Height);
        delay(3000);

        gfx->draw16bitRGBBitmap(0, 0, (uint16_t *)gImage_2, CIT_UI.LCD_Width, CIT_UI.LCD_Height);
        delay(3000);

        gfx->draw16bitRGBBitmap(0, 0, (uint16_t *)gImage_3, CIT_UI.LCD_Width, CIT_UI.LCD_Height);
        delay(3000);

        // Write the load screen code.
        lv_obj_t *act_scr = lv_scr_act();
        lv_disp_t *d = lv_obj_get_disp(act_scr);
        if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
        {
            if (guider_ui.Test_del == true)
            {
                setup_scr_Test(&guider_ui);
            }
            lv_scr_load_anim(guider_ui.Test, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, true);
            guider_ui.Test_del = true;
        }

        CIT_UI.Window_Initialization_Flag = false;
    }
}

void Window_WIFI_STA_Test_Loop(void)
{
    if (Wifi_Connection_Flag == false)
    {
        Wifi_STA_Test();

        delay(2000);

        if (Wifi_Connection_Flag == true)
        {
            // Obtain and set the time from the network time server
            // After successful acquisition, the chip will use the RTC clock to update the holding time
            configTime(GMT_OFFSET_SEC, DAY_LIGHT_OFFSET_SEC, NTP_SERVER1, NTP_SERVER2);

            delay(3000);

            struct tm timeinfo;
            if (!getLocalTime(&timeinfo, 10000))
            {
                Serial.println("Failed to obtain time");
                gfx->setCursor(100, 200);
                gfx->setTextColor(RED);
                gfx->print("Failed to obtain time!");
                Wifi_Connection_Flag = false;
                return;
            }
            Serial.println("Get time success");
            Serial.println(&timeinfo, "%A,%B %d %Y %H:%M:%S"); // Format Output
            gfx->setCursor(120, 200);
            gfx->setTextColor(ORANGE);
            gfx->print(&timeinfo, " %Y");
            gfx->setCursor(120, 220);
            gfx->print(&timeinfo, "%B %d");
            gfx->setCursor(120, 240);
            gfx->print(&timeinfo, "%H:%M:%S");
        }
        else
        {
            gfx->setCursor(20, 200);
            gfx->setTextColor(RED);
            gfx->print("Not connected to the network");
        }
        delay(1000);
    }
}

/**
 * Create a demo application
 */
void custom_init(lv_ui *ui)
{
}
