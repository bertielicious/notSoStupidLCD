#include "constants.h"
#include "byteToNib.h"
void printAstring(uint8_t *ptr)
{
    while(*ptr !=0)
    {
        byteToNib(*ptr, HI);
        ptr++;
    }

}