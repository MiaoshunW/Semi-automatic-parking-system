/*
 * File: ultra.c
 *
 * Code generated for Simulink model 'ultra'.
 *
 * Model version                  : 1.36
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Thu Dec 15 17:03:14 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ultra.h"
#include "ultra_private.h"
#include "ultra_dt.h"

/* Block signals (auto storage) */
B_ultra_T ultra_B;

/* Block states (auto storage) */
DW_ultra_T ultra_DW;

/* Real-time model */
RT_MODEL_ultra_T ultra_M_;
RT_MODEL_ultra_T *const ultra_M = &ultra_M_;

/* Model output function */
void ultra_output(void)
{
  uint8_T rtb_UltrasonicSensor_0;
  int8_T tmp;
  int32_T rtb_y;

  /* S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  rtb_UltrasonicSensor_0 = getUltrasonicSensorValue(1U);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor'
   */
  ultra_B.DataTypeConversion1 = rtb_UltrasonicSensor_0;

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant'
   */
  /* MATLAB Function 'MATLAB Function': '<S1>:1' */
  /* '<S1>:1:2' */
  rtb_y = 30;
  if (((real32_T)ultra_B.DataTypeConversion1 - ultra_P.dis_cm > 30.0F) ||
      ((real32_T)ultra_B.DataTypeConversion1 - ultra_P.dis_cm < -30.0F)) {
    /* '<S1>:1:4' */
    /* '<S1>:1:5' */
    rtb_y = 0;
  } else {
    if ((ultra_B.DataTypeConversion1 > 4.0) && (ultra_B.DataTypeConversion1 <=
         20.0)) {
      /* '<S1>:1:6' */
      /* '<S1>:1:7' */
      rtb_y = 40;
    }
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* S-Function (ev3_motor): '<S2>/Motor' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  tmp = (int8_T)rtb_y;
  setMotor(&tmp, 1U, 2U);
}

/* Model update function */
void ultra_update(void)
{
  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(ultra_M)!=-1) &&
        !((rtmGetTFinal(ultra_M)-ultra_M->Timing.taskTime0) >
          ultra_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(ultra_M, "Simulation finished");
    }

    if (rtmGetStopRequested(ultra_M)) {
      rtmSetErrorStatus(ultra_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ultra_M->Timing.taskTime0 =
    (++ultra_M->Timing.clockTick0) * ultra_M->Timing.stepSize0;
}

/* Model initialize function */
void ultra_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)ultra_M, 0,
                sizeof(RT_MODEL_ultra_T));
  rtmSetTFinal(ultra_M, -1);
  ultra_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  ultra_M->Sizes.checksums[0] = (81358714U);
  ultra_M->Sizes.checksums[1] = (2853078525U);
  ultra_M->Sizes.checksums[2] = (1440612942U);
  ultra_M->Sizes.checksums[3] = (425945523U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    ultra_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ultra_M->extModeInfo,
      &ultra_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ultra_M->extModeInfo, ultra_M->Sizes.checksums);
    rteiSetTPtr(ultra_M->extModeInfo, rtmGetTPtr(ultra_M));
  }

  /* block I/O */
  (void) memset(((void *) &ultra_B), 0,
                sizeof(B_ultra_T));

  /* states (dwork) */
  (void) memset((void *)&ultra_DW, 0,
                sizeof(DW_ultra_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ultra_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  initUltrasonicSensor(1U);

  /* Start for S-Function (ev3_motor): '<S2>/Motor' */
  initMotor(1U);
}

/* Model terminate function */
void ultra_terminate(void)
{
  /* Terminate for S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  terminateUltrasonicSensor(1U);

  /* Terminate for S-Function (ev3_motor): '<S2>/Motor' */
  terminateMotor(1U, 2U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
