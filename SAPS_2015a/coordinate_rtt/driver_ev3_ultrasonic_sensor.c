/* Copyright 2013 The MathWorks, Inc. */

/**************************************
 * LEGO EV3 Ultrasonic Sensor Driver  *
 **************************************/

#include "driver_ev3.h"

extern int uartFile;
extern UART *pUart;
extern DEVCON DevCon;

// Initialize sensor
void initUltrasonicSensor(uint8_T portNumber)
{
    uint8_T PORT = portNumber - 1;
    if(uartFile == -1) {
        uartFile = open(UART_DEVICE_NAME, O_RDWR | O_SYNC);
        if(uartFile == -1) {
            _EV3_DEBUG_PRINTF(("Failed to open color sensor device file.\n"));
            return;
        }
    }
    
    if(pUart == NULL) {
        pUart = (UART*)mmap(0, sizeof(UART), PROT_READ | PROT_WRITE, MAP_FILE | MAP_SHARED, uartFile, 0);
        if(pUart == MAP_FAILED) {
            _EV3_DEBUG_PRINTF(("Failed to map color sensor memory.\n"));
            return;
        }
    }
    
    DevCon.Mode[PORT] = 0;
    DevCon.Connection[PORT] = CONN_INPUT_UART;
    DevCon.Type[PORT] = 30;
    
    _EV3_DEBUG_PRINTF(("Ultrasonic sensor initialized successfully on port %d.\n", portNumber));
}

// Get sensor value
uint8_T getUltrasonicSensorValue(uint8_T portNumber)
{
    uint8_T PORT = portNumber - 1;
    uint8_T rawData[2];
    int32_T rawResult;
    
    rawData[0] = pUart->Raw[PORT][pUart->Actual[PORT]][0];
    rawData[1] = pUart->Raw[PORT][pUart->Actual[PORT]][1];
    rawResult = *((int16_T*)(&rawData[0]));
    
    _EV3_DEBUG_PRINTF(("Ultrasonic sensor on %d port - %d %d %d %d\n", portNumber, rawData[0], rawData[1], rawResult, rawResult/10));
    
    return rawResult/10;
}

// Terminate sensor
void terminateUltrasonicSensor(uint8_T portNumber)
{
    close(uartFile);
    uartFile = -1;
}
