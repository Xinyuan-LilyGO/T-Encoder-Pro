# 1 "C:\\Users\\XK\\AppData\\Local\\Temp\\tmpsoo5ac6n"
#include <Arduino.h>
# 1 "D:/Information/VSCode/GitHub/T-Encoder-Pro/arduino-esp32-libs_V2.0.14/examples/Lvgl_CIT/Lvgl_CIT.ino"
# 15 "D:/Information/VSCode/GitHub/T-Encoder-Pro/arduino-esp32-libs_V2.0.14/examples/Lvgl_CIT/Lvgl_CIT.ino"
#include "custom.h"
#include "lvgl.h"
#include "gui_guider.h"
#include "events_init.h"
#include "TouchDrvCHSC5816.hpp"
#include "material_16bit.h"

static size_t Window_CycleTime1 = 0;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t *disp_draw_buf;
static lv_disp_drv_t disp_drv;


Arduino_DataBus *bus = new Arduino_ESP32QSPI(
    LCD_CS , LCD_SCLK , LCD_SDIO0 ,
    LCD_SDIO1 , LCD_SDIO2 , LCD_SDIO3 );

Arduino_GFX *gfx = new Arduino_SH8601(bus, LCD_RST , 0 ,
                                      false , LCD_WIDTH, LCD_HEIGHT);

TouchDrvCHSC5816 touch;
TouchDrvInterface *pTouch;

lv_ui guider_ui;
Lvgl_CIT_UI CIT_UI;
void CHSC5816_Initialization(void);
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
void my_touchpad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);
void lvgl_initialization(void);
void setup();
void loop();
#line 42 "D:/Information/VSCode/GitHub/T-Encoder-Pro/arduino-esp32-libs_V2.0.14/examples/Lvgl_CIT/Lvgl_CIT.ino"
void CHSC5816_Initialization(void)
{
    TouchDrvCHSC5816 *pd1 = static_cast<TouchDrvCHSC5816 *>(pTouch);

    touch.setPins(TOUCH_RST, TOUCH_INT);
    if (!touch.begin(Wire, CHSC5816_SLAVE_ADDRESS, IIC_SDA, IIC_SCL))
    {
        Serial.println("Failed to find CHSC5816 - check your wiring!");
        while (1)
        {
            delay(1000);
        }
    }

    Serial.println("Init CHSC5816 Touch device success!");
}


void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

#if (LV_COLOR_16_SWAP != 0)
    gfx->draw16bitBeRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#else
    gfx->draw16bitRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#endif

    lv_disp_flush_ready(disp);
}


void my_touchpad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    int16_t Touch_x[2], Touch_y[2];
    uint8_t touchpad = touch.getPoint(Touch_x, Touch_y);

    if (touchpad > 0)
    {
        data->state = LV_INDEV_STATE_PR;


        data->point.x = Touch_x[0];
        data->point.y = Touch_y[0];






    }
    else
    {
        data->state = LV_INDEV_STATE_REL;
    }
}

void lvgl_initialization(void)
{
    lv_init();

    CIT_UI.LCD_Width = gfx->width();
    CIT_UI.LCD_Height = gfx->height();

    disp_draw_buf = (lv_color_t *)heap_caps_malloc(sizeof(lv_color_t) * CIT_UI.LCD_Width * 40, MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT);

    while (!disp_draw_buf)
    {
        Serial.println("LVGL disp_draw_buf allocate failed!");
        delay(1000);
    }

    lv_disp_draw_buf_init(&draw_buf, disp_draw_buf, NULL, CIT_UI.LCD_Width * 40);


    lv_disp_drv_init(&disp_drv);

    disp_drv.hor_res = CIT_UI.LCD_Width;
    disp_drv.ver_res = CIT_UI.LCD_Height;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);


    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register(&indev_drv);
}

void setup()
{
    Serial.begin(115200);
    Serial.println("Ciallo");

    pinMode(KNOB_DATA_A, INPUT_PULLUP);
    pinMode(KNOB_DATA_B, INPUT_PULLUP);
    pinMode(BUZZER_DATA, OUTPUT);

    ledcAttachPin(BUZZER_DATA, 1);
    ledcSetup(1, 2000, 8);
    ledcWrite(1, 0);

    pinMode(LCD_VCI_EN, OUTPUT);
    digitalWrite(LCD_VCI_EN, HIGH);

    CHSC5816_Initialization();

    gfx->begin(40000000);
    gfx->fillScreen(BLACK);

    gfx->draw16bitRGBBitmap(0, 0, (uint16_t *)gImage_4, LCD_WIDTH, LCD_HEIGHT);

    for (int i = 0; i <= 255; i++)
    {
        gfx->Display_Brightness(i);
        delay(3);
    }

    delay(3000);

    lvgl_initialization();

    setup_ui(&guider_ui);
    events_init(&guider_ui);

    ledcWrite(1, 127);
    delay(1000);
    ledcWrite(1, 0);
}

void loop()
{
    lv_timer_handler();


    switch (CIT_UI.Window_Current_State)
    {
    case CIT_UI.Window_Current_State::Window_OLED_Brightness_Test:
        if (CIT_UI.Window_Initialization_Flag == false)
        {
            CIT_UI.Window_Initialization_Flag = true;
            Btn_Start_Testing_Initialization(&guider_ui);
        }
        else
        {
            if (millis() > Window_CycleTime1)
            {
                Window_OLED_Brightness_Test_Loop();
                Window_CycleTime1 = millis() + 1;
            }
        }
        break;
    case CIT_UI.Window_Current_State::Window_OLED_Edge_Detection_Test:
        if (CIT_UI.Window_Initialization_Flag == false)
        {
            CIT_UI.Window_Initialization_Flag = true;
            Btn_Start_Testing_Initialization(&guider_ui);
        }
        else
        {
            if (millis() > Window_CycleTime1)
            {
                Window_OLED_Edge_Detection_Test_Loop();
                Window_CycleTime1 = millis() + 1;
            }
        }
        break;

    case CIT_UI.Window_Current_State::Window_OLED_Contrast_Test:
        if (CIT_UI.Window_Initialization_Flag == false)
        {
            CIT_UI.Window_Initialization_Flag = true;
            Btn_Start_Testing_Initialization(&guider_ui);
        }
        else
        {
            if (millis() > Window_CycleTime1)
            {
                Window_OLED_Contrast_Test_Loop();
                Window_CycleTime1 = millis() + 1;
            }
        }
        break;
    case CIT_UI.Window_Current_State::Window_OLED_Display_Color_Test:
        if (CIT_UI.Window_Initialization_Flag == false)
        {
            CIT_UI.Window_Initialization_Flag = true;
            Btn_Start_Testing_Initialization(&guider_ui);
        }
        else
        {
            if (millis() > Window_CycleTime1)
            {
                Window_OLED_Display_Color_Test_Loop();
                Window_CycleTime1 = millis() + 1;
            }
        }
        break;
    case CIT_UI.Window_Current_State::Window_Rotary_Encoder_WS2812B_Test:
        if (CIT_UI.Window_Initialization_Flag == false)
        {
            CIT_UI.Window_Initialization_Flag = true;

            lv_obj_add_flag(guider_ui.Test_btnm_1, LV_OBJ_FLAG_HIDDEN);

            lv_obj_update_layout(guider_ui.Test);

            CIT_UI.Window_Load_Anim_Delay = millis() + 500;
        }
        else
        {
            if (millis() > CIT_UI.Window_Load_Anim_Delay)
            {
                if (millis() > Window_CycleTime1)
                {
                    Window_Rotary_Encoder_WS2812B_Test_Loop();
                    Window_CycleTime1 = millis() + 1;
                }
            }
        }
        break;
    case CIT_UI.Window_Current_State::Window_WIFI_STA_Test:
        if (CIT_UI.Window_Initialization_Flag == false)
        {
            CIT_UI.Window_Initialization_Flag = true;

            lv_obj_add_flag(guider_ui.Test_btnm_1, LV_OBJ_FLAG_HIDDEN);

            lv_obj_update_layout(guider_ui.Test);

            Wifi_Connection_Flag = false;

            CIT_UI.Window_Load_Anim_Delay = millis() + 500;
        }
        else
        {
            if (millis() > CIT_UI.Window_Load_Anim_Delay)
            {
                if (millis() > Window_CycleTime1)
                {
                    Window_WIFI_STA_Test_Loop();
                    Window_CycleTime1 = millis() + 1;
                }
            }
        }
        break;

    default:
        break;
    }
}