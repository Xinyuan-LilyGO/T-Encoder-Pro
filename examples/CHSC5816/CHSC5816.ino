/*
 * @Description: None
 * @version: V1.0.0
 * @Author: LILYGO_L
 * @Date: 2023-11-01 16:33:23
 * @LastEditors: LILYGO_L
 * @LastEditTime: 2023-11-22 15:38:35
 * @License: GPL 3.0
 */
#include <Arduino.h>
#include "TouchDrvCHSC5816.hpp"
#include "Wire.h"
#include "pin_config.h"

TouchDrvCHSC5816 touch;

TouchDrvInterface *pTouch;

void scan_i2c_device(TwoWire &i2c)
{
    Serial.println("Scanning for I2C devices ...");
    Serial.print("      ");
    for (int i = 0; i < 0x10; i++)
    {
        Serial.printf("0x%02X|", i);
    }
    uint8_t error;
    for (int j = 0; j < 0x80; j += 0x10)
    {
        Serial.println();
        Serial.printf("0x%02X |", j);
        for (int i = 0; i < 0x10; i++)
        {
            Wire.beginTransmission(i | j);
            error = Wire.endTransmission();
            if (error == 0)
                Serial.printf("0x%02X|", i | j);
            else
                Serial.print(" -- |");
        }
    }
    Serial.println();
}

void setup()
{
    Serial.begin(115200);

    // scan_i2c_device(Wire);

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

void loop()
{
    int16_t x[2], y[2];
    if (digitalRead(TOUCH_INT) == LOW)
    {
        uint8_t touched = touch.getPoint(x, y);
        for (int i = 0; i < touched; ++i)
        {
            Serial.print("X[");
            Serial.print(i);
            Serial.print("]:");
            Serial.print(x[i]);
            Serial.print(" ");
            Serial.print(" Y[");
            Serial.print(i);
            Serial.print("]:");
            Serial.print(y[i]);
            Serial.print(" ");
        }
        Serial.println();
    }
}
