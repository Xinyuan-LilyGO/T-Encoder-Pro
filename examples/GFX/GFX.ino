/*
 * @Description(CN):
 *      GFX测试程序
 *
 * @Description(EN):
 *      GFX test program
 *
 * @version: V1.0.0
 * @Author: LILYGO_L
 * @Date: 2023-09-06 10:58:19
 * @LastEditors: LILYGO_L
 * @LastEditTime: 2024-02-02 16:24:06
 * @License: GPL 3.0
 */
#include <Arduino.h>
#include "Arduino_GFX_Library.h"
#include "pin_config.h"

// DXQ120MYB2416A
Arduino_DataBus *bus = new Arduino_ESP32QSPI(
    LCD_CS /* CS */, LCD_SCLK /* SCK */, LCD_SDIO0 /* SDIO0 */,
    LCD_SDIO1 /* SDIO1 */, LCD_SDIO2 /* SDIO2 */, LCD_SDIO3 /* SDIO3 */);

Arduino_GFX *gfx = new Arduino_SH8601(bus, LCD_RST /* RST */, 0 /* rotation */,
                                      false /* IPS */, LCD_WIDTH, LCD_HEIGHT);

void setup()
{
    Serial.begin(115200);
    Serial.println("Ciallo");

    pinMode(LCD_VCI_EN, OUTPUT);
    digitalWrite(LCD_VCI_EN, HIGH);

    gfx->begin();
    gfx->fillScreen(PINK);

    for (uint8_t i = 0; i < 255; i++)
    {
        gfx->Display_Brightness(i);
        delay(3);
    }
    for (uint8_t i = 0; i < 4; i++)
    {
        gfx->SetContrast(i);
        delay(2000);
    }
    gfx->SetContrast(SH8601_ContrastOff);

    gfx->setCursor(20, 250);
    gfx->setTextColor(YELLOW);
    gfx->println("Ciallo1~(L *##*L)^**");
}

void loop()
{
    // gfx->fillScreen(PINK);
    delay(1000);
}
