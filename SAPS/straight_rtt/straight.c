/*
 * File: straight.c
 *
 * Code generated for Simulink model 'straight'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Thu Dec 15 21:21:04 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "straight.h"
#include "straight_private.h"
#include "straight_dt.h"

/* Block signals (auto storage) */
B_straight_T straight_B;

/* Block states (auto storage) */
DW_straight_T straight_DW;

/* Real-time model */
RT_MODEL_straight_T straight_M_;
RT_MODEL_straight_T *const straight_M = &straight_M_;

/* Model output function */
void straight_output(void)
{
  int8_T tmp;
  int8_T tmp_0;
  real_T tmp_1;

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant'
   */
  tmp_1 = floor(straight_P.Constant_Value);
  if (tmp_1 < 128.0) {
    if (tmp_1 >= -128.0) {
      /* S-Function (ev3_motor): '<S2>/Motor' */
      tmp = (int8_T)tmp_1;
    } else {
      /* S-Function (ev3_motor): '<S2>/Motor' */
      tmp = MIN_int8_T;
    }
  } else {
    /* S-Function (ev3_motor): '<S2>/Motor' */
    tmp = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

  /* S-Function (ev3_motor): '<S2>/Motor' */
  setMotor(&tmp, 1U, 2U);

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  tmp_1 = floor(straight_P.Constant1_Value);
  if (tmp_1 < 128.0) {
    if (tmp_1 >= -128.0) {
      /* S-Function (ev3_motor): '<S1>/Motor' */
      tmp_0 = (int8_T)tmp_1;
    } else {
      /* S-Function (ev3_motor): '<S1>/Motor' */
      tmp_0 = MIN_int8_T;
    }
  } else {
    /* S-Function (ev3_motor): '<S1>/Motor' */
    tmp_0 = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (ev3_motor): '<S1>/Motor' */
  setMotor(&tmp_0, 2U, 2U);

  /* S-Function (ev3_encoder): '<Root>/Encoder' */
  straight_B.Encoder = getEncoderValueNoReset(2U);

  /* S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  straight_B.UltrasonicSensor = getUltrasonicSensorValue(1U);
}

/* Model update function */
void straight_update(void)
{
  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(straight_M)!=-1) &&
        !((rtmGetTFinal(straight_M)-straight_M->Timing.taskTime0) >
          straight_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(straight_M, "Simulation finished");
    }

    if (rtmGetStopRequested(straight_M)) {
      rtmSetErrorStatus(straight_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  straight_M->Timing.taskTime0 =
    (++straight_M->Timing.clockTick0) * straight_M->Timing.stepSize0;
}

/* Model initialize function */
void straight_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)straight_M, 0,
                sizeof(RT_MODEL_straight_T));
  rtmSetTFinal(straight_M, 40.0);
  straight_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  straight_M->Sizes.checksums[0] = (3290598771U);
  straight_M->Sizes.checksums[1] = (2222320623U);
  straight_M->Sizes.checksums[2] = (1991157182U);
  straight_M->Sizes.checksums[3] = (1568632327U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    straight_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(straight_M->extModeInfo,
      &straight_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(straight_M->extModeInfo, straight_M->Sizes.checksums);
    rteiSetTPtr(straight_M->extModeInfo, rtmGetTPtr(straight_M));
  }

  /* block I/O */
  (void) memset(((void *) &straight_B), 0,
                sizeof(B_straight_T));

  /* states (dwork) */
  (void) memset((void *)&straight_DW, 0,
                sizeof(DW_straight_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    straight_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (ev3_motor): '<S2>/Motor' */
  initMotor(1U);

  /* Start for S-Function (ev3_motor): '<S1>/Motor' */
  initMotor(2U);

  /* Start for S-Function (ev3_encoder): '<Root>/Encoder' */
  initEncoder(2U);

  /* Start for S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  initUltrasonicSensor(1U);
}

/* Model terminate function */
void straight_terminate(void)
{
  /* Terminate for S-Function (ev3_motor): '<S2>/Motor' */
  terminateMotor(1U, 2U);

  /* Terminate for S-Function (ev3_motor): '<S1>/Motor' */
  terminateMotor(2U, 2U);

  /* Terminate for S-Function (ev3_encoder): '<Root>/Encoder' */
  terminateEncoder(2U);

  /* Terminate for S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  terminateUltrasonicSensor(1U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
