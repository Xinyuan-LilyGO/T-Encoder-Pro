/*
 * @Description: None
 * @Author: LILYGO_L
 * @Date: 2025-09-15 10:58:26
 * @LastEditTime: 2025-09-17 16:15:56
 * @License: GPL 3.0
 */
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "pin_config.h"
#include "arduino_cpp_bus_driver_library.h"
#include "TouchDrvCHSC5816.hpp"

size_t Cycle_Time = 0;

volatile bool interrupt_flag = false;

auto Touch = std::make_unique<TouchDrvCHSC5816>();

auto ESP32S3 = std::make_unique<Cpp_Bus_Driver::Tool>();

// void IIC_Scan(void)
// {
//     std::vector<uint8_t> address;
//     if (Iic_Bus->scan_7bit_address(&address) == true)
//     {
//         for (size_t i = 0; i < address.size(); i++)
//         {
//             printf("Discovered IIC devices[%u]: %#X\n", i, address[i]);
//         }
//     }
// }

extern "C" void app_main(void)
{
    printf("Ciallo\n");

    ESP32S3->pin_mode(SCREEN_EN, Cpp_Bus_Driver::Tool::Pin_Mode::OUTPUT);
    ESP32S3->pin_write(SCREEN_EN, 1);

    ESP32S3->pin_mode(SCREEN_RST, Cpp_Bus_Driver::Tool::Pin_Mode::OUTPUT);
    vTaskDelay(pdMS_TO_TICKS(100));
    ESP32S3->pin_write(SCREEN_RST, 1);
    vTaskDelay(pdMS_TO_TICKS(100));
    ESP32S3->pin_write(SCREEN_RST, 0);
    vTaskDelay(pdMS_TO_TICKS(100));
    ESP32S3->pin_write(SCREEN_RST, 1);

    ESP32S3->pin_mode(TOUCH_RST, Cpp_Bus_Driver::Tool::Pin_Mode::OUTPUT);
    vTaskDelay(pdMS_TO_TICKS(100));
    ESP32S3->pin_write(TOUCH_RST, 1);
    vTaskDelay(pdMS_TO_TICKS(100));
    ESP32S3->pin_write(TOUCH_RST, 0);
    vTaskDelay(pdMS_TO_TICKS(100));
    ESP32S3->pin_write(TOUCH_RST, 1);

    ESP32S3->create_gpio_interrupt(TOUCH_INT, Cpp_Bus_Driver::Tool::Interrupt_Mode::FALLING,
                                   [](void *arg) -> IRAM_ATTR void
                                   {
                                       interrupt_flag = true;
                                   });

    if (Touch->begin(Wire, CHSC5816_SLAVE_ADDRESS, IIC_SDA, IIC_SCL) == false)
    {
        printf("chsc5816 init fail\n");
    }
    else
    {
        printf("chsc5816 init success\n");
    }

    while (1)
    {
        // IIC_Scan();
        if (interrupt_flag == true)
        {
            if (esp_log_timestamp() > Cycle_Time)
            {
                int16_t x[2], y[2];

                uint8_t touched = Touch->getPoint(x, y);
                for (int i = 0; i < touched; ++i)
                {
                    printf("touch x[%d]: %d y[%d]: %d\n", i, x[i], i, y[i]);
                }

                Cycle_Time = esp_log_timestamp() + 100;
            }

            interrupt_flag = false;
        }

        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
