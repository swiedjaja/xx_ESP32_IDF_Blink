#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#define LED_BUILTIN 33
void app_main() {
    gpio_pad_select_gpio(LED_BUILTIN);
    gpio_set_direction(LED_BUILTIN, GPIO_MODE_OUTPUT);    
    while (1)
    {
        gpio_set_level(LED_BUILTIN, 0);
        printf("Hello World\n");
        fflush(stdout);
        vTaskDelay(100/portTICK_RATE_MS);
        gpio_set_level(LED_BUILTIN, 1);
        vTaskDelay(1000/portTICK_RATE_MS);
    }
}