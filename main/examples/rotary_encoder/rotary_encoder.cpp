/*
 * @Description: None
 * @Author: LILYGO_L
 * @Date: 2025-09-16 11:16:43
 * @LastEditTime: 2025-09-16 11:53:57
 * @License: GPL 3.0
 */
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "pin_config.h"
#include "cpp_bus_driver_library.h"

enum Knob_State
{
    KNOB_NULL,
    KNOB_INCREMENT,
    KNOB_DECREMENT,
};

int32_t Knob_Data = 0;
bool Knob_Trigger_Flag = false;
uint8_t Knob_State_Flag = Knob_State::KNOB_NULL;

//  0B000000[KNOB_DATA_A][KNOB_DATA_B]
uint8_t Knob_Previous_Logical = 0B00000000;

size_t Knob_CycleTime = 0;

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

auto ESP32S3 = std::make_unique<Cpp_Bus_Driver::Tool>();

void Knob_Logical_Scan_Loop(void)
{
    uint8_t Knob_Logical_Scan = 0B00000000;

    if (ESP32S3->pin_read(KNOB_DATA_A) == 1)
    {
        Knob_Logical_Scan |= 0B00000010;
    }
    else
    {
        Knob_Logical_Scan &= 0B11111101;
    }

    if (ESP32S3->pin_read(KNOB_DATA_B) == 1)
    {
        Knob_Logical_Scan |= 0B00000001;
    }
    else
    {
        Knob_Logical_Scan &= 0B11111110;
    }

    if (Knob_Previous_Logical != Knob_Logical_Scan)
    {
        if (Knob_Logical_Scan == 0B00000000 || Knob_Logical_Scan == 0B00000011)
        {
            Knob_Previous_Logical = Knob_Logical_Scan;
            Knob_Trigger_Flag = true;
        }
        else
        {
            if (Knob_Logical_Scan == 0B00000010)
            {
                switch (Knob_Previous_Logical)
                {
                case 0B00000000:
                    Knob_State_Flag = Knob_State::KNOB_INCREMENT;
                    break;
                case 0B00000011:
                    Knob_State_Flag = Knob_State::KNOB_DECREMENT;
                    break;

                default:
                    break;
                }
            }
            if (Knob_Logical_Scan == 0B00000001)
            {
                switch (Knob_Previous_Logical)
                {
                case 0B00000000:
                    Knob_State_Flag = Knob_State::KNOB_DECREMENT;
                    break;
                case 0B00000011:
                    Knob_State_Flag = Knob_State::KNOB_INCREMENT;
                    break;

                default:
                    break;
                }
            }
        }
        // delay(10);
    }
}

extern "C" void app_main(void)
{
    printf("Ciallo\n");

    ESP32S3->pin_mode(KNOB_DATA_A, Cpp_Bus_Driver::Tool::Pin_Mode::INPUT, Cpp_Bus_Driver::Tool::Pin_Status::PULLUP);
    ESP32S3->pin_mode(KNOB_DATA_B, Cpp_Bus_Driver::Tool::Pin_Mode::INPUT, Cpp_Bus_Driver::Tool::Pin_Status::PULLUP);

    vTaskDelay(pdMS_TO_TICKS(1000));

    while (1)
    {
        if (ESP32S3->get_system_time_ms() > Knob_CycleTime)
        {
            Knob_Logical_Scan_Loop();
            Knob_CycleTime = ESP32S3->get_system_time_ms() + 20;
        }

        if (Knob_Trigger_Flag == true)
        {
            Knob_Trigger_Flag = false;

            switch (Knob_State_Flag)
            {
            case Knob_State::KNOB_INCREMENT:
                Knob_Data++;
                printf("\nKnob_Data: %ld\n", Knob_Data);
                break;
            case Knob_State::KNOB_DECREMENT:
                Knob_Data--;
                printf("\nKnob_Data: %ld\n", Knob_Data);
                break;

            default:
                break;
            }
        }

        // printf("\nKNOB_DATA_A: %d\n", ESP32S3->pin_read(KNOB_DATA_A));
        // printf("KNOB_DATA_B: %d\n", ESP32S3->pin_read(KNOB_DATA_B));
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
