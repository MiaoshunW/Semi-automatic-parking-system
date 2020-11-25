/*
 * File: coordinate.c
 *
 * Code generated for Simulink model 'coordinate'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Fri Nov 25 15:58:45 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "coordinate.h"
#include "coordinate_private.h"
#include "coordinate_dt.h"

/* Block signals (auto storage) */
B_coordinate_T coordinate_B;

/* Block states (auto storage) */
DW_coordinate_T coordinate_DW;

/* Real-time model */
RT_MODEL_coordinate_T coordinate_M_;
RT_MODEL_coordinate_T *const coordinate_M = &coordinate_M_;

/* Model output function */
void coordinate_output(void)
{
  int8_T tmp;
  uint8_T rtb_UltrasonicSensor_0;
  real_T tmp_0;

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant'
   */
  tmp_0 = floor(coordinate_P.Constant_Value);
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
  rtb_UltrasonicSensor_0 = getUltrasonicSensorValue(1U);

  /* Saturate: '<Root>/Saturation' incorporates:
   *  S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor'
   */
  if (rtb_UltrasonicSensor_0 > coordinate_P.Saturation_UpperSat) {
    coordinate_B.Saturation = coordinate_P.Saturation_UpperSat;
  } else if (rtb_UltrasonicSensor_0 < coordinate_P.Saturation_LowerSat) {
    coordinate_B.Saturation = coordinate_P.Saturation_LowerSat;
  } else {
    coordinate_B.Saturation = rtb_UltrasonicSensor_0;
  }

  /* End of Saturate: '<Root>/Saturation' */
}

/* Model update function */
void coordinate_update(void)
{
  /* signal main to stop simulation */
  {                                    /* Sample time: [0.03s, 0.0s] */
    if ((rtmGetTFinal(coordinate_M)!=-1) &&
        !((rtmGetTFinal(coordinate_M)-coordinate_M->Timing.taskTime0) >
          coordinate_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(coordinate_M, "Simulation finished");
    }

    if (rtmGetStopRequested(coordinate_M)) {
      rtmSetErrorStatus(coordinate_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  coordinate_M->Timing.taskTime0 =
    (++coordinate_M->Timing.clockTick0) * coordinate_M->Timing.stepSize0;
}

/* Model initialize function */
void coordinate_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)coordinate_M, 0,
                sizeof(RT_MODEL_coordinate_T));
  rtmSetTFinal(coordinate_M, 9.99);
  coordinate_M->Timing.stepSize0 = 0.03;

  /* External mode info */
  coordinate_M->Sizes.checksums[0] = (2042025467U);
  coordinate_M->Sizes.checksums[1] = (378418531U);
  coordinate_M->Sizes.checksums[2] = (2031034208U);
  coordinate_M->Sizes.checksums[3] = (3679656339U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    coordinate_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(coordinate_M->extModeInfo,
      &coordinate_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(coordinate_M->extModeInfo, coordinate_M->Sizes.checksums);
    rteiSetTPtr(coordinate_M->extModeInfo, rtmGetTPtr(coordinate_M));
  }

  /* block I/O */
  (void) memset(((void *) &coordinate_B), 0,
                sizeof(B_coordinate_T));

  /* states (dwork) */
  (void) memset((void *)&coordinate_DW, 0,
                sizeof(DW_coordinate_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    coordinate_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void coordinate_terminate(void)
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
