/*
 * @Description: iic_scan
 * @Author: LILYGO_L
 * @Date: 2025-06-13 12:06:14
 * @LastEditTime: 2025-09-15 11:46:49
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

auto IIC_Bus = std::make_shared<Cpp_Bus_Driver::Hardware_Iic_1>(IIC_SDA, IIC_SCL, I2C_NUM_0);

void IIC_Scan(void)
{
    std::vector<uint8_t> address;
    if (IIC_Bus->scan_7bit_address(&address) == true)
    {
        for (size_t i = 0; i < address.size(); i++)
        {
            printf("Discovered IIC devices[%u]: %#X\n", i, address[i]);
        }
    }
}

extern "C" void app_main(void)
{
    printf("Ciallo\n");

    IIC_Bus->pin_mode(SCREEN_EN, Cpp_Bus_Driver::Tool::Pin_Mode::OUTPUT, Cpp_Bus_Driver::Tool::Pin_Status::PULLUP);
    IIC_Bus->pin_write(SCREEN_EN, 1);

    IIC_Bus->pin_mode(SCREEN_RST, Cpp_Bus_Driver::Tool::Pin_Mode::OUTPUT, Cpp_Bus_Driver::Tool::Pin_Status::PULLUP);
    IIC_Bus->pin_write(SCREEN_RST, 1);

    vTaskDelay(pdMS_TO_TICKS(100));

    IIC_Bus->begin();

    while (1)
    {
        IIC_Scan();
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
