/*
 * @Description: None
 * @Author: LILYGO_L
 * @Date: 2025-09-16 10:55:31
 * @LastEditTime: 2025-09-16 11:14:51
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

auto ESP32S3 = std::make_unique<Cpp_Bus_Driver::Tool>();

extern "C" void app_main(void)
{
    printf("Ciallo\n");

    ESP32S3->create_pwm(BUZZER_DATA, ledc_channel_t::LEDC_CHANNEL_1, 2000);

    while (1)
    {
        ESP32S3->set_pwm_duty(50);
        vTaskDelay(pdMS_TO_TICKS(1000));
        ESP32S3->set_pwm_duty(0);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}