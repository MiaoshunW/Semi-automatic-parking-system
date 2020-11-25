/*
 * File: straight2.c
 *
 * Code generated for Simulink model 'straight2'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Thu Dec 15 21:39:51 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "straight2.h"
#include "straight2_private.h"
#include "straight2_dt.h"

/* Block signals (auto storage) */
B_straight2_T straight2_B;

/* Block states (auto storage) */
DW_straight2_T straight2_DW;

/* Real-time model */
RT_MODEL_straight2_T straight2_M_;
RT_MODEL_straight2_T *const straight2_M = &straight2_M_;

/* Model output function */
void straight2_output(void)
{
  int8_T tmp;
  int8_T tmp_0;
  int32_T rtb_y;
  real_T tmp_1;

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant'
   */
  tmp_1 = floor(straight2_P.Constant_Value);
  if (tmp_1 < 128.0) {
    if (tmp_1 >= -128.0) {
      /* S-Function (ev3_motor): '<S3>/Motor' */
      tmp = (int8_T)tmp_1;
    } else {
      /* S-Function (ev3_motor): '<S3>/Motor' */
      tmp = MIN_int8_T;
    }
  } else {
    /* S-Function (ev3_motor): '<S3>/Motor' */
    tmp = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S3>/Data Type Conversion' */

  /* S-Function (ev3_motor): '<S3>/Motor' */
  setMotor(&tmp, 1U, 2U);

  /* S-Function (ev3_encoder): '<Root>/Encoder' */
  straight2_B.Encoder = getEncoderValueNoReset(2U);

  /* MATLAB Function: '<Root>/MATLAB Function' */
  /* MATLAB Function 'MATLAB Function': '<S1>:1' */
  if (straight2_B.Encoder <= 50) {
    /* '<S1>:1:3' */
    /* '<S1>:1:4' */
    rtb_y = 80;
  } else {
    /* '<S1>:1:6' */
    rtb_y = -80;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* S-Function (ev3_motor): '<S2>/Motor' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  tmp_0 = (int8_T)rtb_y;
  setMotor(&tmp_0, 2U, 2U);

  /* S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  straight2_B.UltrasonicSensor = getUltrasonicSensorValue(1U);
}

/* Model update function */
void straight2_update(void)
{
  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(straight2_M)!=-1) &&
        !((rtmGetTFinal(straight2_M)-straight2_M->Timing.taskTime0) >
          straight2_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(straight2_M, "Simulation finished");
    }

    if (rtmGetStopRequested(straight2_M)) {
      rtmSetErrorStatus(straight2_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  straight2_M->Timing.taskTime0 =
    (++straight2_M->Timing.clockTick0) * straight2_M->Timing.stepSize0;
}

/* Model initialize function */
void straight2_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)straight2_M, 0,
                sizeof(RT_MODEL_straight2_T));
  rtmSetTFinal(straight2_M, 40.0);
  straight2_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  straight2_M->Sizes.checksums[0] = (1043265957U);
  straight2_M->Sizes.checksums[1] = (2447296753U);
  straight2_M->Sizes.checksums[2] = (1260658592U);
  straight2_M->Sizes.checksums[3] = (2600025484U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    straight2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(straight2_M->extModeInfo,
      &straight2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(straight2_M->extModeInfo, straight2_M->Sizes.checksums);
    rteiSetTPtr(straight2_M->extModeInfo, rtmGetTPtr(straight2_M));
  }

  /* block I/O */
  (void) memset(((void *) &straight2_B), 0,
                sizeof(B_straight2_T));

  /* states (dwork) */
  (void) memset((void *)&straight2_DW, 0,
                sizeof(DW_straight2_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    straight2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (ev3_motor): '<S3>/Motor' */
  initMotor(1U);

  /* Start for S-Function (ev3_encoder): '<Root>/Encoder' */
  initEncoder(2U);

  /* Start for S-Function (ev3_motor): '<S2>/Motor' */
  initMotor(2U);

  /* Start for S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  initUltrasonicSensor(1U);
}

/* Model terminate function */
void straight2_terminate(void)
{
  /* Terminate for S-Function (ev3_motor): '<S3>/Motor' */
  terminateMotor(1U, 2U);

  /* Terminate for S-Function (ev3_encoder): '<Root>/Encoder' */
  terminateEncoder(2U);

  /* Terminate for S-Function (ev3_motor): '<S2>/Motor' */
  terminateMotor(2U, 2U);

  /* Terminate for S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  terminateUltrasonicSensor(1U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
