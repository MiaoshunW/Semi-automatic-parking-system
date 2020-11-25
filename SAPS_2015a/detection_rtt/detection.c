/*
 * File: detection.c
 *
 * Code generated for Simulink model 'detection'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Mon Dec 05 18:46:45 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "detection.h"
#include "detection_private.h"
#include "detection_dt.h"

/* Real-time model */
RT_MODEL_detection_T detection_M_;
RT_MODEL_detection_T *const detection_M = &detection_M_;

/* Model output function */
void detection_output(void)
{
  int8_T tmp;
  int32_T rtb_y;

  /* S-Function (ev3_encoder): '<Root>/Encoder' */
  rtb_y = getEncoderValueNoReset(1U);

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  S-Function (ev3_encoder): '<Root>/Encoder'
   */
  /* MATLAB Function 'MATLAB Function': '<S1>:1' */
  if (rtb_y >= 800) {
    /* '<S1>:1:3' */
    /* '<S1>:1:4' */
    rtb_y = 0;
  } else {
    /* '<S1>:1:6' */
    rtb_y = 40;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* S-Function (ev3_motor): '<S2>/Motor' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  tmp = (int8_T)rtb_y;
  setMotor(&tmp, 1U, 2U);
}

/* Model update function */
void detection_update(void)
{
  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(detection_M)!=-1) &&
        !((rtmGetTFinal(detection_M)-detection_M->Timing.taskTime0) >
          detection_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(detection_M, "Simulation finished");
    }

    if (rtmGetStopRequested(detection_M)) {
      rtmSetErrorStatus(detection_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  detection_M->Timing.taskTime0 =
    (++detection_M->Timing.clockTick0) * detection_M->Timing.stepSize0;
}

/* Model initialize function */
void detection_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)detection_M, 0,
                sizeof(RT_MODEL_detection_T));
  rtmSetTFinal(detection_M, 10.0);
  detection_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  detection_M->Sizes.checksums[0] = (192762156U);
  detection_M->Sizes.checksums[1] = (1340435027U);
  detection_M->Sizes.checksums[2] = (3143222863U);
  detection_M->Sizes.checksums[3] = (3564629835U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    detection_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(detection_M->extModeInfo,
      &detection_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(detection_M->extModeInfo, detection_M->Sizes.checksums);
    rteiSetTPtr(detection_M->extModeInfo, rtmGetTPtr(detection_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    detection_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];
  }

  /* Start for S-Function (ev3_encoder): '<Root>/Encoder' */
  initEncoder(1U);

  /* Start for S-Function (ev3_motor): '<S2>/Motor' */
  initMotor(1U);
}

/* Model terminate function */
void detection_terminate(void)
{
  /* Terminate for S-Function (ev3_encoder): '<Root>/Encoder' */
  terminateEncoder(1U);

  /* Terminate for S-Function (ev3_motor): '<S2>/Motor' */
  terminateMotor(1U, 2U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
