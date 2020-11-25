/* Copyright 2013 The MathWorks, Inc. */

/**************************************
 *     LEGO EV3 LED Driver            *
 **************************************/

#include "driver_ev3.h"

int ledFile = -1;

// Initialize LED
void initLED()
{
    ledFile = open(UI_DEVICE_NAME, O_WRONLY);
    if(ledFile == -1) {
        _EV3_DEBUG_PRINTF(("Failed to initialize led.\n"));
    }
    _EV3_DEBUG_PRINTF(("Successfully initialized led.\n"));
}

// Control LED
void setLED(int8_T* inData)
{
    uint8_T Color = 0;
    uint8_T led_command[2] = {0};
    
    switch(*inData) {
        case 1:
        case 2:
        case 3:
            Color = *inData;
            break;
        case 4:
        case 5:
        case 6:
            Color = *inData + 3;
            break;
        default:
            Color = 0;
    }
    
    _EV3_DEBUG_PRINTF(("Set led to color %d.\n", Color));
    
    led_command[0] = '0' + Color;
    write(ledFile, led_command, 2);
}

// Terminate LED
void terminateLED()
{
    uint8_T led_command[2] = {'0', 0};
    write(ledFile, led_command, 2);
    
    close(ledFile);
    ledFile = -1;
}
