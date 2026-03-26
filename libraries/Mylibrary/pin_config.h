/*
 * @Description: None
 * @Author: LILYGO_L
 * @Date: 2023-06-05 13:01:59
 * @LastEditTime: 2026-03-26 13:44:34
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
#define SCREEN_SDIO0 11
#define SCREEN_SDIO1 13
#define SCREEN_SDIO2 7
#define SCREEN_SDIO3 14
#define SCREEN_SCLK 12
#define SCREEN_CS 10
#define SCREEN_RST 4
#define SCREEN_WIDTH 390
#define SCREEN_HEIGHT 390
#define SCREEN_EN 3

// Rotary Encoder
#define KNOB_DATA_A 1
#define KNOB_DATA_B 2
#define KNOB_KEY 0
