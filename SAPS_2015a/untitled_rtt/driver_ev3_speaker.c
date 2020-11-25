/* License:
 *
 * The contents of this file are subject to the Mozilla Public License
 * Version 1.1 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
 * License for the specific language governing rights and limitations
 * under the License.
 *
 * The Initial Developer of this code is John Hansen.
 * Portions created by John Hansen are Copyright (C) 2009-2013 John Hansen.
 * All Rights Reserved.
 *
 * ----------------------------------------------------------------------------
 *
 * \author John Hansen (bricxcc_at_comcast.net)
 * \date 2013-07-10
 * \version 1
 */

/* 2014-01-01 Modified by The MathWorks, Inc. */


/**************************************
 *     LEGO EV3 Speaker Driver        *
 **************************************/

#include "driver_ev3.h"
#include "ev3_constants.h"

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <limits.h>
#include <errno.h>

#define STEP_SIZE_TABLE_ENTRIES 89
#define INDEX_TABLE_ENTRIES     16

// sound commands
#define SOUND_CMD_BREAK   0
#define SOUND_CMD_TONE    1
#define SOUND_CMD_PLAY    2
#define SOUND_CMD_REPEAT  3
#define SOUND_CMD_SERVICE 4

#define SOUND_MODE_ONCE           0x00
#define SOUND_LOOP                0x01
#define SOUND_ADPCM_INIT_VALPREV  0x7F
#define SOUND_ADPCM_INIT_INDEX    20
#define SOUND_MAX_DATA_SIZE       250
#define SOUND_CHUNK               250
#define SOUND_ADPCM_CHUNK         125
#define SOUND_MASTER_CLOCK        132000000
#define SOUND_TONE_MASTER_CLOCK   1031250
#define SOUND_MIN_FRQ             250
#define SOUND_MAX_FRQ             10000
#define SOUND_MAX_LEVEL           8
#define SOUND_FILE_BUFFER_SIZE    (SOUND_CHUNK + 2) //!< 12.8 mS @ 8KHz
#define SOUND_BUFFER_COUNT        3
#define SOUND_FILE_FORMAT_RAW_SOUND   0x0100 //!< RSO-file
#define SOUND_FILE_FORMAT_ADPCM_SOUND 0x0101 //!< RSO-file compressed

const short StepSizeTable[STEP_SIZE_TABLE_ENTRIES] = {
    7, 8, 9, 10, 11, 12, 13, 14, 16, 17,
    19, 21, 23, 25, 28, 31, 34, 37, 41, 45,
    50, 55, 60, 66, 73, 80, 88, 97, 107, 118,
    130, 143, 157, 173, 190, 209, 230, 253, 279, 307,
    337, 371, 408, 449, 494, 544, 598, 658, 724, 796,
    876, 963, 1060, 1166, 1282, 1411, 1552, 1707, 1878, 2066,
    2272, 2499, 2749, 3024, 3327, 3660, 4026, 4428, 4871, 5358,
    5894, 6484, 7132, 7845, 8630, 9493, 10442, 11487, 12635, 13899,
    15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794, 32767
};

const short IndexTable[INDEX_TABLE_ENTRIES] = {
    -1, -1, -1, -1, 2, 4, 6, 8,
    -1, -1, -1, -1, 2, 4, 6, 8
};

typedef struct {
    byte Busy;
} SOUND_BUSY;

typedef struct {
    int SoundDriverDescriptor;
    int hSoundFile;
    byte SoundOwner;
    byte SoundState;
    SOUND_BUSY Sound;
    SOUND_BUSY *pSound;
    byte SoundMuted;
    unsigned short BytesLeft;
    unsigned short SoundFileFormat;
    int SoundDataLength;
    unsigned short SoundSampleRate;
    unsigned short SoundPlayMode;
    int SoundFileLength;
    short ValPrev;
    short Index;
    short Step;
    byte BytesToWrite;
    byte StopLoop;
    char PathBuffer[FILENAME_SIZE];
    struct stat FileStatus;
    byte SoundData[SOUND_FILE_BUFFER_SIZE + 1];
} SoundGlobals;

SoundGlobals SoundInstance;

bool SoundInitialized()
{
    return (SoundInstance.pSound != NULL) &&
            (SoundInstance.pSound != &SoundInstance.Sound);
}

int WriteToSoundDevice(char * bytes, int num_bytes)
{
    ssize_t result = -1;
    int sndHandle = open(LMS_SOUND_DEVICE_NAME, O_WRONLY);
    if (sndHandle >= 0)
    {
        // for some reason write is not returning num_bytes -
        // it usually returns zero
        result = write(sndHandle, bytes, num_bytes);
//printf("result = %zd\n", result);
        close(sndHandle);
//    if (result >= 0)
//      return num_bytes;
    }
    return (int)result;
}

void SoundCloseDevices()
{
    if (!SoundInitialized())
        return;
    
    if ((SoundInstance.pSound != NULL) &&
            (SoundInstance.pSound != &SoundInstance.Sound))
    {
        munmap(SoundInstance.pSound, sizeof(unsigned short));
    }
    
    SoundInstance.pSound = NULL;
}

bool SoundInit()
{
    int sndHandle;
    bool Result = SoundInitialized();
    if (!Result)
    {
        SoundInstance.SoundDriverDescriptor = -1;
        SoundInstance.hSoundFile = -1;
        SoundInstance.pSound = &SoundInstance.Sound;
        
        // Create a Shared Memory entry for signaling the driver state BUSY or NOT BUSY
        
        sndHandle = open(LMS_SOUND_DEVICE_NAME, O_RDWR | O_SYNC);
        if (sndHandle != -1)
        {
            SOUND_BUSY * pTmp = (SOUND_BUSY*)mmap(0, sizeof(unsigned short),
                    PROT_READ | PROT_WRITE, MAP_FILE | MAP_SHARED, sndHandle, 0);
            if (pTmp == MAP_FAILED)
            {
                SoundCloseDevices();
//        LogErrorNumber(SOUND_SHARED_MEMORY);
                close(sndHandle);
                // result is already false
            }
            else
            {
                SoundInstance.pSound = pTmp;
                close(sndHandle);
                Result = TRUE;
            }
        }
    }
    return Result;
}

bool SoundOpen()
{
    return TRUE;
}

bool SoundClose()
{
    StopSound();
    return TRUE;
}

bool SoundExit()
{
    // make sure we close before we exit
    SoundClose();
    SoundCloseDevices();
    return TRUE;
}



void PlayToneEx(unsigned short frequency, unsigned short duration, byte volume)
{
    if (!SoundInitialized())
        return;
    
    // sound system must not be muted to play a sound
    if (SoundInstance.SoundMuted != 0)
        return;
    
    (*SoundInstance.pSound).Busy = TRUE;
    byte SoundData[6];
    SoundData[0] = SOUND_CMD_TONE;
    //SoundData[1] = (byte)(volume);
    SoundData[1] = (byte)((volume*13)/100);
    SoundData[2] = (byte)(frequency);
    SoundData[3] = (byte)(frequency >> 8);
    SoundData[4] = (byte)(duration);
    SoundData[5] = (byte)(duration >> 8);
    SoundInstance.SoundState = SOUND_STATE_TONE;
    WriteToSoundDevice(SoundData, sizeof(SoundData)); // write 6 bytes
}

int SoundState()
{
    if (SoundInitialized())
        return SoundInstance.SoundState;
    return SOUND_STATE_IDLE;
}

void StopSound()
{
    if (!SoundInitialized())
        return;
    byte cmd = SOUND_CMD_BREAK;
    SoundInstance.SoundState = SOUND_STATE_IDLE;
    if (SoundInstance.hSoundFile >= 0)
    {
        close(SoundInstance.hSoundFile);
        SoundInstance.hSoundFile  = -1;
    }
    WriteToSoundDevice(&cmd, 1);
}

void MuteSound()
{
    // first stop any playing sounds
    StopSound();
    SoundInstance.SoundMuted = 1;
}

void UnmuteSound()
{
    SoundInstance.SoundMuted = 0;
}

void ClearSound()
{
    // a synonym for StopSound;
    StopSound();
}

/*******************************************/

/* freq in */
void playSoundFreqOnly(uint32_T in1, uint32_T vol, uint32_T dura)
{
    PlayToneEx(in1, dura, vol);
}

/* vol in */
void playSoundVolumeOnly(uint32_T in1, uint32_T freq, uint32_T dura)
{
    PlayToneEx(freq, dura, in1);
}

/* freq and vol */
void playSoundBoth(uint32_T in1, uint32_T in2, uint32_T dura)
{
    PlayToneEx(in1, dura, in2);
}

/* initialize speaker */
void initSpeaker() {
    SoundInit();
}

/* terminate speaker */
void terminateSpeaker() {
    SoundExit();
}



