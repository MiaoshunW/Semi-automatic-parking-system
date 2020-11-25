/*
 * File: ultrasonic1.c
 *
 * Code generated for Simulink model 'ultrasonic1'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Sat Dec 03 03:52:45 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ultrasonic1.h"
#include "ultrasonic1_private.h"
#include "ultrasonic1_dt.h"

/* Block signals (auto storage) */
B_ultrasonic1_T ultrasonic1_B;

/* Block states (auto storage) */
DW_ultrasonic1_T ultrasonic1_DW;

/* Real-time model */
RT_MODEL_ultrasonic1_T ultrasonic1_M_;
RT_MODEL_ultrasonic1_T *const ultrasonic1_M = &ultrasonic1_M_;

/* Model output function */
void ultrasonic1_output(void)
{
  int8_T tmp;
  real_T tmp_0;

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant'
   */
  tmp_0 = floor(ultrasonic1_P.Constant_Value);
  if (tmp_0 < 128.0) {
    if (tmp_0 >= -128.0) {
      /* S-Function (ev3_motor): '<S1>/Motor' */
      tmp = (int8_T)tmp_0;
    } else {
      /* S-Function (ev3_motor): '<S1>/Motor' */
      tmp = MIN_int8_T;
    }
  } else {
    /* S-Function (ev3_motor): '<S1>/Motor' */
    tmp = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (ev3_motor): '<S1>/Motor' */
  setMotor(&tmp, 1U, 2U);

  /* S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  ultrasonic1_B.UltrasonicSensor = getUltrasonicSensorValue(1U);
}

/* Model update function */
void ultrasonic1_update(void)
{
  /* signal main to stop simulation */
  {                                    /* Sample time: [0.03s, 0.0s] */
    if ((rtmGetTFinal(ultrasonic1_M)!=-1) &&
        !((rtmGetTFinal(ultrasonic1_M)-ultrasonic1_M->Timing.taskTime0) >
          ultrasonic1_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(ultrasonic1_M, "Simulation finished");
    }

    if (rtmGetStopRequested(ultrasonic1_M)) {
      rtmSetErrorStatus(ultrasonic1_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ultrasonic1_M->Timing.taskTime0 =
    (++ultrasonic1_M->Timing.clockTick0) * ultrasonic1_M->Timing.stepSize0;
}

/* Model initialize function */
void ultrasonic1_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)ultrasonic1_M, 0,
                sizeof(RT_MODEL_ultrasonic1_T));
  rtmSetTFinal(ultrasonic1_M, 4.9799999999999995);
  ultrasonic1_M->Timing.stepSize0 = 0.03;

  /* External mode info */
  ultrasonic1_M->Sizes.checksums[0] = (2285525055U);
  ultrasonic1_M->Sizes.checksums[1] = (2825063759U);
  ultrasonic1_M->Sizes.checksums[2] = (481206034U);
  ultrasonic1_M->Sizes.checksums[3] = (1363386050U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    ultrasonic1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ultrasonic1_M->extModeInfo,
      &ultrasonic1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ultrasonic1_M->extModeInfo,
                        ultrasonic1_M->Sizes.checksums);
    rteiSetTPtr(ultrasonic1_M->extModeInfo, rtmGetTPtr(ultrasonic1_M));
  }

  /* block I/O */
  (void) memset(((void *) &ultrasonic1_B), 0,
                sizeof(B_ultrasonic1_T));

  /* states (dwork) */
  (void) memset((void *)&ultrasonic1_DW, 0,
                sizeof(DW_ultrasonic1_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ultrasonic1_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (ev3_motor): '<S1>/Motor' */
  initMotor(1U);

  /* Start for S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  initUltrasonicSensor(1U);
}

/* Model terminate function */
void ultrasonic1_terminate(void)
{
  /* Terminate for S-Function (ev3_motor): '<S1>/Motor' */
  terminateMotor(1U, 2U);

  /* Terminate for S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  terminateUltrasonicSensor(1U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
