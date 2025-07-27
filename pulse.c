#include "constants.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
void pulse(void)
{
    gpio_set_level(E, LO);
    esp_rom_delay_us(10);
    gpio_set_level(E, HI);
    esp_rom_delay_us(20);
    gpio_set_level(E, LO);
    esp_rom_delay_us(100);

}