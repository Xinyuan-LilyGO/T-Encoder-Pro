/*
 * @Description: None
 * @version: None
 * @Author: None
 * @Date: 2023-06-05 13:01:59
 * @LastEditors: LILYGO_L
 * @LastEditTime: 2024-02-02 17:40:55
 */
#pragma once

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