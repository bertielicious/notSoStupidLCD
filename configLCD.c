/*
configure 1602 LCD with a 4 bit uController interface usine D4 to D7
*/
#include "constants.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdint.h>
#include "byteToNib.h"
#include "sendNibble.h"
#include "pulse.h"

void configLCD(void)
{
    //wait for 100ms to allow LCD to wake up    step 1
    vTaskDelay(110/portTICK_PERIOD_MS);

   gpio_set_level(E, LO);

    
    
    sendNibble(0x03,LO);                     //    step 2 special case of function set, lower 4 bits are irrelevant
    sendNibble(0x03,LO);                     //    step 3 special case of function set, lower 4 bits are irrelevant
    sendNibble(0x03,LO);                     //    step 4 special case of function set, lower 4 bits are irrelevant

    //function set (interface is 4 bits long)
    sendNibble(0x02,LO);                     //    step 5 initial function set to change interface to 4 bit
    sendNibble(0x08,LO);                     //    step 6 Function set
    sendNibble(0x00,LO);                     //    step 7 Function set
    sendNibble(0x02,LO);                     //    step 8
    sendNibble(0x08,LO);                     //    step 9
    sendNibble(0x00,LO);                     //    step 9
    sendNibble(0x01,LO); 
    sendNibble(0x00,LO); 
    sendNibble(0x06,LO); 
    sendNibble(0x00,LO); 
    sendNibble(0x0c, LO);                   //  display on/off control, display is on, cursor and blinking off
     
    
   
}