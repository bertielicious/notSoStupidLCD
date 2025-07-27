#include <stdint.h>
#include <stdbool.h>
#include "constants.h"
#include "driver/gpio.h"
#include "pulse.h"

void sendNibble(uint8_t nibble, bool LCD_RS)
{
    gpio_set_level(RS, LCD_RS);
   

     //nibble
    gpio_set_level(D7, (nibble & 0x08)>>3);
    gpio_set_level(D6, (nibble & 0x04)>>2);
    gpio_set_level(D5, (nibble & 0x02)>>1);
    gpio_set_level(D4, (nibble & 0x01)>>0);
    pulse();
    lcd_delay_ms(10);// LCD shows garbage if delay is less than 10ms
}