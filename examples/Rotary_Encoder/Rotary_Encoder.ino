/*
 * @Description: None
 * @version: V1.0.0
 * @Author: None
 * @Date: 2024-01-03 17:59:46
 * @LastEditors: LILYGO_L
 * @LastEditTime: 2024-01-09 18:30:00
 * @License: GPL 3.0
 */
#include <Arduino.h>
#include "pin_config.h"

enum KNOB_State
{
    KNOB_NULL,
    KNOB_INCREMENT,
    KNOB_DECREMENT,
};

int32_t KNOB_Data = 0;
bool KNOB_Trigger_Flag = false;
uint8_t KNOB_State_Flag = KNOB_State::KNOB_NULL;

//  0B000000[KNOB_DATA_A][KNOB_DATA_B]
uint8_t KNOB_Previous_Logical = 0B00000000;

size_t KNOB_CycleTime = 0;

// 顺时针转
//  KNOB_DATA_A=0 KNOB_DATA_B=0
//  KNOB_DATA_A=1 KNOB_DATA_B=0  //正在旋转
//  KNOB_DATA_A=1 KNOB_DATA_B=1
//  KNOB_DATA_A=0 KNOB_DATA_B=1  //正在旋转

// 逆时针转
//  KNOB_DATA_A=0 KNOB_DATA_B=0
//  KNOB_DATA_A=0 KNOB_DATA_B=1  //正在旋转
//  KNOB_DATA_A=1 KNOB_DATA_B=1
//  KNOB_DATA_A=1 KNOB_DATA_B=0  //正在旋转

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

void setup()
{
    Serial.begin(115200);
    Serial.println("Ciallo");

    pinMode(KNOB_DATA_A, INPUT_PULLUP);
    pinMode(KNOB_DATA_B, INPUT_PULLUP);

    delay(1000);
}

void loop()
{
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
            Serial.printf("\nKNOB_Data: %d\n", KNOB_Data);
            break;
        case KNOB_State::KNOB_DECREMENT:
            KNOB_Data--;
            Serial.printf("\nKNOB_Data: %d\n", KNOB_Data);
            break;

        default:
            break;
        }
    }

    // Serial.printf("\nKNOB_DATA_A: %d\n", digitalRead(KNOB_DATA_A));
    // Serial.printf("KNOB_DATA_B: %d\n", digitalRead(KNOB_DATA_B));
    // delay(100);
}
