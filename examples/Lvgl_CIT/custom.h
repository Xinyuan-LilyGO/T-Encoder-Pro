/*
 * @Description: None
 * @version: V1.0.0
 * @Author: LILYGO_L
 * @Date: 2023-10-06 10:54:55
 * @LastEditors: LILYGO_L
 * @LastEditTime: 2024-01-10 14:57:29
 * @License: GPL 3.0
 */
#pragma once

#include "gui_guider.h"
#include "Arduino_GFX_Library.h"
#include "pin_config.h"

class Lvgl_CIT_UI
{
public:
    enum Window_Current_State
    {
        Window_NULL = 0,
        Window_Home,
        Window_OLED_Brightness_Test,
        Window_OLED_Edge_Detection_Test,
        Window_OLED_Contrast_Test,
        Window_OLED_Display_Color_Test,
        Window_Rotary_Encoder_WS2812B_Test,
        Window_WIFI_STA_Test,
    };
    enum Window_Test_Result
    {
        Test_NULL = 0,
        Test_Pass,
        Test_Fail,
    };

    // Window
    uint8_t Window_Current_State = Window_Current_State::Window_NULL; // 当前正在运行的窗口
    bool Window_Initialization_Flag = false;
    bool Window_Button_Start_Testing_Flag = false;
    size_t Window_Load_Anim_Delay = 0; // 窗口等待动画加载延时

    // Result
    uint8_t Window_OLED_Brightness_Test_Result = Window_Test_Result::Test_NULL;
    uint8_t Window_OLED_Edge_Detection_Test_Result = Window_Test_Result::Test_NULL;
    uint8_t Window_OLED_Contrast_Test_Result = Window_Test_Result::Test_NULL;
    uint8_t Window_OLED_Display_Color_Test_Result = Window_Test_Result::Test_NULL;
    uint8_t Window_Rotary_Encoder_WS2812B_Test_Result = Window_Test_Result::Test_NULL;
    uint8_t Window_WIFI_STA_Test_Result = Window_Test_Result::Test_NULL;

    // WIFI
    uint8_t Window_WIFI_STA_Test_State = false;

    bool Breathing_Light_State = false;
    int32_t Breathing_Light_Brightness = -1;

    // LCD
    uint32_t LCD_Width = 0;
    uint32_t LCD_Height = 0;
};

void Btn_Start_Testing_Initialization(lv_ui *ui);
void Window_OLED_Brightness_Test_Loop(void);
void Window_OLED_Edge_Detection_Test_Loop(void);
void Window_OLED_Contrast_Test_Loop(void);
void Window_OLED_Display_Color_Test_Loop(void);
void Window_Rotary_Encoder_WS2812B_Test_Loop(void);
void Window_WIFI_STA_Test_Loop(void);

void custom_init(lv_ui *ui);

extern Lvgl_CIT_UI CIT_UI;
extern Arduino_GFX *gfx;
extern bool Wifi_Connection_Flag;

