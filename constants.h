#ifndef CONSTANTS_H
#define CONSTANTS_H
void constants(void);
/*
LCD pins            GPIO pins
Vss-------------------GND
Vdd-------------------+5V
Vo--------------------GND
RS--------------------17
RW--------------------GND
E---------------------18
D4--------------------16
D5--------------------22
D6--------------------4
D7--------------------21




*/
/*define which ESP32 pins will interface with 1602 LCD*/
#define D7 21 
#define D6 4
#define D5 22
#define D4 16
#define RS 17   //CMD REG RS = LO     DATA REG RS = HI
#define E 18

enum{LO,HI};

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
/*Delay helpers*/
#define lcd_delay_us(s) esp_rom_delay_us(s)
#define lcd_delay_ms(s) vTaskDelay(pdMS_TO_TICKS(s))


#endif