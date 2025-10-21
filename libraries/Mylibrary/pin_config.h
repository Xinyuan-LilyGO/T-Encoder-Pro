/*
 * @Description: None
 * @Author: LILYGO_L
 * @Date: 2025-10-21 09:21:05
 * @LastEditTime: 2025-10-21 15:45:43
 * @License: GPL 3.0
 */
#pragma once

// #define DXQ120MYB2416A      // SH8601屏幕 CHSC5816触摸
#define TFD12MASBCTB4_V0_07 // CO5300屏幕 CST816触摸

#if defined DXQ120MYB2416A
#elif defined TFD12MASBCTB4_V0_07
// CST816
#define CST816_ADDRESS 0x15
#else
#error "Unknown macro definition. Please select the correct macro definition."
#endif

// BUZZER_DATA
#define BUZZER_DATA 17

// IIC
#define IIC_SDA 5
#define IIC_SCL 6

// TOUCH
#define TOUCH_INT 9
#define TOUCH_RST 8

// DXQ120MYB2416A
#define LCD_SDIO0 11
#define LCD_SDIO1 13
#define LCD_SDIO2 7
#define LCD_SDIO3 14
#define LCD_SCLK 12
#define LCD_CS 10
#define LCD_RST 4
#define LCD_WIDTH 390
#define LCD_HEIGHT 390
#define LCD_VCI_EN 3

// Rotary Encoder
#define KNOB_DATA_A 1
#define KNOB_DATA_B 2
#define KNOB_KEY 0


/****************************************
********** factory ui demo pin **********
****************************************/
// touch key-press 
#define TOUCH_KEY_PRESS_PIN 16  
// Servo motors
#define SERVO_MOTORS  15        

// WS2812B_DATA
// #define WS2812B_DATA 18
#define WS2812B_DATA    43  // TX
#define WS2812B_LED_NUM 12  // RX

// encoder

#define ENCODE_A_PIN KNOB_DATA_A
#define ENCODE_B_PIN KNOB_DATA_B
#define ENCODE_K_PIN KNOB_KEY