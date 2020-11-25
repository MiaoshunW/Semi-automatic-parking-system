/* Copyright 2013 The MathWorks, Inc. */

/**************************************
 *      LEGO EV3 Encoder Driver       *
 **************************************/

#include "driver_ev3.h"

static int encoderFile = -1;
static MOTORDATA *pEncoder;

// Initialize encoder
void initEncoder(uint8_T portNumber)
{
    if(encoderFile == -1) {
        encoderFile = open(MOTOR_DEVICE_NAME, O_RDWR | O_SYNC);
        if(encoderFile == -1) {
            _EV3_DEBUG_PRINTF(("Failed to open encoder device file.\n"));
            exit(1);
        }
        pEncoder = (MOTORDATA*)mmap(0, sizeof(MOTORDATA)*vmOUTPUTS, PROT_READ | PROT_WRITE, MAP_FILE | MAP_SHARED, encoderFile, 0);
        if(pEncoder == MAP_FAILED) {
            _EV3_DEBUG_PRINTF(("Failed to map encoder memory.\n"));
            exit(1);
        }
        _EV3_DEBUG_PRINTF(("Successfully initialize encoder - %d - %d.\n", encoderFile, pEncoder));
    }
}

// Get encoder value
int32_T getEncoderValueNoReset(uint8_T portNumber)
{
    uint8_T PORT = portNumber - 1;
    int32_T rawResult;
    
    rawResult = pEncoder[PORT].TachoSensor;
    
    _EV3_DEBUG_PRINTF(("No Reset: Encoder on %d output port - %d %d %d %d\n", portNumber, pEncoder[PORT].Speed, pEncoder[PORT].TachoCounts, pEncoder[PORT].TachoSensor, rawResult));
    
    return rawResult;
}

int32_T getEncoderValueSampleReset(uint8_T portNumber)
{
    uint8_T PORT = portNumber - 1;
    static int32_T oldResult[4];
    int32_T newResult;
    int32_T result;
    
    newResult = pEncoder[PORT].TachoSensor;
    result = newResult - oldResult[PORT];
    oldResult[PORT] = newResult;
    
    _EV3_DEBUG_PRINTF(("Sample Reset: Encoder on %d output port - %d %d %d - %d\n", portNumber, pEncoder[PORT].Speed, pEncoder[PORT].TachoCounts, pEncoder[PORT].TachoSensor, result));
    return result;
}

int32_T getEncoderValueExternalReset(uint8_T portNumber, int8_T *in)
{
    uint8_T PORT = portNumber - 1;
    static int32_T oldResult[4];
    int32_T newResult;
    int32_T result;
    
    newResult = pEncoder[PORT].TachoSensor;
    result = newResult - oldResult[PORT];
    if(*in != 0) {
        oldResult[PORT] = newResult;
    }
    
    _EV3_DEBUG_PRINTF(("External Reset: Encoder on %d output port - %d %d %d - %d\n", portNumber, pEncoder[PORT].Speed, pEncoder[PORT].TachoCounts, pEncoder[PORT].TachoSensor, result));
    return result;
}

// Terminate encoder
void terminateEncoder(uint8_T portNumber)
{
    if(encoderFile != -1) {
        close(encoderFile);
        encoderFile = -1;
        _EV3_DEBUG_PRINTF(("Closing encoder file.\n"));
    }
}
