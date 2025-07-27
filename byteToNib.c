#include <stdint.h>
#include <stdbool.h>
#include "constants.h"
#include "driver/gpio.h"
#include "pulse.h"
/* this function is used to write 8-bit character data using 4 bit mode to the 1602 LCD*/
void byteToNib(uint8_t byte, bool LCD_RS)
{
    gpio_set_level(RS, LCD_RS);
    //high nibble
    gpio_set_level(D7, (byte & 0x80)>>7);
    gpio_set_level(D6, (byte & 0x40)>>6);
    gpio_set_level(D5, (byte & 0x20)>>5);
    gpio_set_level(D4, (byte & 0x10)>>4);
    pulse();
    lcd_delay_ms(5);

     //low nibble
    gpio_set_level(D7, (byte & 0x08)>>3);
    gpio_set_level(D6, (byte & 0x04)>>2);
    gpio_set_level(D5, (byte & 0x02)>>1);
    gpio_set_level(D4, (byte & 0x01)>>0);
    pulse();
    lcd_delay_ms(5);
}