#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include "device.h"
#include "gpio_arduino.h"

void app_main() {
    gpio_pinMode(LED_RED, OUTPUT);
    gpio_pinMode(LED_GREEN, OUTPUT);
    while (1)
    {
        gpio_set_level(LED_RED, LED_ON);
        printf("Hello World\n");
        fflush(stdout);
        vTaskDelay(100/portTICK_RATE_MS);
        gpio_set_level(LED_RED, LED_OFF);
        vTaskDelay(1000/portTICK_RATE_MS);
    }
}