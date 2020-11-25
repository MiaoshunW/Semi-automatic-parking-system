/*
 * File: stateflow6.c
 *
 * Code generated for Simulink model 'stateflow6'.
 *
 * Model version                  : 1.100
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Wed Jan 04 19:39:34 2017
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "stateflow6.h"
#include "stateflow6_private.h"
#include "stateflow6_dt.h"

/* Named constants for Chart: '<Root>/Chart' */
#define stateflow6_CALL_EVENT_g        (-1)

/* Block signals (auto storage) */
B_stateflow6_T stateflow6_B;

/* Block states (auto storage) */
DW_stateflow6_T stateflow6_DW;

/* Real-time model */
RT_MODEL_stateflow6_T stateflow6_M_;
RT_MODEL_stateflow6_T *const stateflow6_M = &stateflow6_M_;

/* Model output function */
void stateflow6_output(void)
{
  uint8_T rtb_UltrasonicSensor_0;
  int8_T tmp;
  int32_T rtb_Positon_0;
  int8_T tmp_0;
  real_T tmp_1;

  /* Reset subsysRan breadcrumbs */
  srClearBC(stateflow6_DW.ObjectDetection_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(stateflow6_DW.ParkingSpaceDetection_SubsysRan);

  /* Constant: '<Root>/Constant2' */
  stateflow6_B.Constant2 = stateflow6_P.Constant2_Value;

  /* S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  rtb_UltrasonicSensor_0 = getUltrasonicSensorValue(1U);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor'
   */
  stateflow6_B.DataTypeConversion1 = rtb_UltrasonicSensor_0;

  /* S-Function (ev3_encoder): '<Root>/Encoder' incorporates:
   *  Delay: '<Root>/Delay1'
   */
  tmp = stateflow6_DW.Delay1_DSTATE;
  rtb_Positon_0 = getEncoderValueExternalReset(1U, &tmp);

  /* Gain: '<Root>/Gain1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  S-Function (ev3_encoder): '<Root>/Encoder'
   */
  stateflow6_B.Encoder = stateflow6_P.Gain1_Gain * (real_T)rtb_Positon_0;

  /* Delay: '<Root>/Delay2' */
  stateflow6_B.Delay2 = stateflow6_DW.Delay2_DSTATE;

  /* Constant: '<Root>/Constant1' */
  stateflow6_B.Constant1 = stateflow6_P.ObjLength;

  /* Constant: '<Root>/Constant' */
  stateflow6_B.Constant = stateflow6_P.ParkLength;

  /* Chart: '<Root>/Chart' */
  if (stateflow6_DW.temporalCounter_i1 < 31U) {
    stateflow6_DW.temporalCounter_i1++;
  }

  /* Gateway: Chart */
  stateflow6_DW.sfEvent = stateflow6_CALL_EVENT_g;

  /* During: Chart */
  if (stateflow6_DW.is_active_c3_stateflow6 == 0U) {
    /* Entry: Chart */
    stateflow6_DW.is_active_c3_stateflow6 = 1U;

    /* Entry Internal: Chart */
    /* Transition: '<S1>:74' */
    stateflow6_B.ChartMode = ChartModeType_First_Object;
    stateflow6_DW.temporalCounter_i1 = 0U;

    /* Entry 'First_Object': '<S1>:57' */
    stateflow6_B.state_nr = 1.0;
  } else {
    switch (stateflow6_B.ChartMode) {
     case ChartModeType_First_Object:
      /* During 'First_Object': '<S1>:57' */
      if ((stateflow6_DW.temporalCounter_i1 >= 20U) &&
          ((stateflow6_B.DataTypeConversion1 - stateflow6_B.Delay2 > 2.0) ||
           ((stateflow6_B.DataTypeConversion1 - stateflow6_B.Delay2 < -2.0) &&
            (stateflow6_B.Encoder < stateflow6_B.Constant1)))) {
        /* Transition: '<S1>:159' */
        /* Transition: '<S1>:161' */
        stateflow6_B.ChartMode = ChartModeType_First_Object;
        stateflow6_DW.temporalCounter_i1 = 0U;

        /* Entry 'First_Object': '<S1>:57' */
        stateflow6_B.state_nr = 1.0;
      } else if ((stateflow6_B.DataTypeConversion1 > 24.0) &&
                 (stateflow6_B.Encoder >= stateflow6_B.Constant1)) {
        /* Transition: '<S1>:83' */
        stateflow6_B.ChartMode = ChartModeType_Park_Space;
        stateflow6_DW.temporalCounter_i1 = 0U;

        /* Entry 'Park_Space': '<S1>:59' */
        stateflow6_B.state_nr = 2.0;
      } else {
        ObjDetn(stateflow6_B.Constant2, stateflow6_B.DataTypeConversion1,
                stateflow6_B.Encoder, stateflow6_B.Delay2, &stateflow6_B.Motor);
      }
      break;

     case ChartModeType_Park_Space:
      /* During 'Park_Space': '<S1>:59' */
      if ((stateflow6_B.DataTypeConversion1 < 40.0) &&
          (stateflow6_B.DataTypeConversion1 > 24.0) && (stateflow6_B.Encoder <
           stateflow6_B.Constant)) {
        /* Transition: '<S1>:95' */
        stateflow6_B.ChartMode = ChartModeType_First_Object;
        stateflow6_DW.temporalCounter_i1 = 0U;

        /* Entry 'First_Object': '<S1>:57' */
        stateflow6_B.state_nr = 1.0;
      } else if ((stateflow6_DW.temporalCounter_i1 >= 20U) &&
                 ((stateflow6_B.DataTypeConversion1 - stateflow6_B.Delay2 > 2.0)
                  || ((stateflow6_B.DataTypeConversion1 - stateflow6_B.Delay2 <
                       -2.0) && (stateflow6_B.Encoder < stateflow6_B.Constant))))
      {
        /* Transition: '<S1>:162' */
        /* Transition: '<S1>:161' */
        stateflow6_B.ChartMode = ChartModeType_First_Object;
        stateflow6_DW.temporalCounter_i1 = 0U;

        /* Entry 'First_Object': '<S1>:57' */
        stateflow6_B.state_nr = 1.0;
      } else if ((stateflow6_B.DataTypeConversion1 < 24.0) &&
                 (stateflow6_B.Encoder >= stateflow6_B.Constant)) {
        /* Transition: '<S1>:122' */
        stateflow6_B.ChartMode = ChartModeType_Second_Object;
        stateflow6_DW.temporalCounter_i1 = 0U;

        /* Entry 'Second_Object': '<S1>:118' */
        stateflow6_B.state_nr = 3.0;
      } else {
        ParkDetn(stateflow6_B.Constant2, stateflow6_B.DataTypeConversion1,
                 stateflow6_B.Encoder, stateflow6_B.Delay2, &stateflow6_B.Motor);
      }
      break;

     case ChartModeType_Second_Object:
      /* During 'Second_Object': '<S1>:118' */
      if ((stateflow6_DW.temporalCounter_i1 >= 20U) &&
          ((stateflow6_B.DataTypeConversion1 - stateflow6_B.Delay2 > 2.0) ||
           ((stateflow6_B.DataTypeConversion1 - stateflow6_B.Delay2 < -2.0) &&
            (stateflow6_B.Encoder < stateflow6_B.Constant1)))) {
        /* Transition: '<S1>:165' */
        /* Transition: '<S1>:161' */
        stateflow6_B.ChartMode = ChartModeType_First_Object;
        stateflow6_DW.temporalCounter_i1 = 0U;

        /* Entry 'First_Object': '<S1>:57' */
        stateflow6_B.state_nr = 1.0;
      } else if ((stateflow6_B.DataTypeConversion1 > 24.0) &&
                 (stateflow6_B.Encoder > stateflow6_B.Constant1)) {
        /* Transition: '<S1>:133' */
        stateflow6_B.ChartMode = ChartModeType_Stop_motor;

        /* Entry 'Stop_motor': '<S1>:132' */
        stateflow6_B.Motor = 0.0;
        stateflow6_B.state_nr = 5.0;
      } else {
        ObjDetn(stateflow6_B.Constant2, stateflow6_B.DataTypeConversion1,
                stateflow6_B.Encoder, stateflow6_B.Delay2, &stateflow6_B.Motor);
      }
      break;

     default:
      /* During 'Stop_motor': '<S1>:132' */
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  tmp_1 = floor(stateflow6_B.Motor);
  if (tmp_1 < 128.0) {
    if (tmp_1 >= -128.0) {
      /* S-Function (ev3_motor): '<S2>/Motor' */
      tmp_0 = (int8_T)tmp_1;
    } else {
      /* S-Function (ev3_motor): '<S2>/Motor' */
      tmp_0 = MIN_int8_T;
    }
  } else {
    /* S-Function (ev3_motor): '<S2>/Motor' */
    tmp_0 = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

  /* S-Function (ev3_motor): '<S2>/Motor' */
  setMotor(&tmp_0, 1U, 2U);

  /* Sum: '<Root>/Add1' */
  stateflow6_B.UltrDiff = stateflow6_B.DataTypeConversion1 - stateflow6_B.Delay2;

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Delay: '<Root>/Delay'
   *  Sum: '<Root>/Add'
   */
  tmp_1 = floor(stateflow6_B.state_nr - stateflow6_DW.Delay_DSTATE);
  if (rtIsNaN(tmp_1) || rtIsInf(tmp_1)) {
    tmp_1 = 0.0;
  } else {
    tmp_1 = fmod(tmp_1, 256.0);
  }

  stateflow6_B.DataTypeConversion3 = (int8_T)(tmp_1 < 0.0 ? (int32_T)(int8_T)
    -(int8_T)(uint8_T)-tmp_1 : (int32_T)(int8_T)(uint8_T)tmp_1);

  /* End of DataTypeConversion: '<Root>/Data Type Conversion3' */
}

/* Model update function */
void stateflow6_update(void)
{
  /* Update for Delay: '<Root>/Delay1' */
  stateflow6_DW.Delay1_DSTATE = stateflow6_B.DataTypeConversion3;

  /* Update for Delay: '<Root>/Delay2' */
  stateflow6_DW.Delay2_DSTATE = stateflow6_B.DataTypeConversion1;

  /* Update for Delay: '<Root>/Delay' */
  stateflow6_DW.Delay_DSTATE = stateflow6_B.state_nr;

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(stateflow6_M)!=-1) &&
        !((rtmGetTFinal(stateflow6_M)-stateflow6_M->Timing.taskTime0) >
          stateflow6_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(stateflow6_M, "Simulation finished");
    }

    if (rtmGetStopRequested(stateflow6_M)) {
      rtmSetErrorStatus(stateflow6_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  stateflow6_M->Timing.taskTime0 =
    (++stateflow6_M->Timing.clockTick0) * stateflow6_M->Timing.stepSize0;
}

/* Model initialize function */
void stateflow6_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)stateflow6_M, 0,
                sizeof(RT_MODEL_stateflow6_T));
  rtmSetTFinal(stateflow6_M, 7.0);
  stateflow6_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  stateflow6_M->Sizes.checksums[0] = (3640691288U);
  stateflow6_M->Sizes.checksums[1] = (836691234U);
  stateflow6_M->Sizes.checksums[2] = (918085951U);
  stateflow6_M->Sizes.checksums[3] = (2700641475U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    stateflow6_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&stateflow6_DW.ObjectDetection_SubsysRanBC;
    systemRan[3] = (sysRanDType *)&stateflow6_DW.ObjectDetection_SubsysRanBC;
    systemRan[4] = (sysRanDType *)&stateflow6_DW.ParkingSpaceDetection_SubsysRan;
    systemRan[5] = (sysRanDType *)&stateflow6_DW.ParkingSpaceDetection_SubsysRan;
    rteiSetModelMappingInfoPtr(stateflow6_M->extModeInfo,
      &stateflow6_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(stateflow6_M->extModeInfo, stateflow6_M->Sizes.checksums);
    rteiSetTPtr(stateflow6_M->extModeInfo, rtmGetTPtr(stateflow6_M));
  }

  /* block I/O */
  (void) memset(((void *) &stateflow6_B), 0,
                sizeof(B_stateflow6_T));

  {
    stateflow6_B.ChartMode = ChartModeType_None;
  }

  /* states (dwork) */
  (void) memset((void *)&stateflow6_DW, 0,
                sizeof(DW_stateflow6_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    stateflow6_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for Constant: '<Root>/Constant2' */
  stateflow6_B.Constant2 = stateflow6_P.Constant2_Value;

  /* Start for S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  initUltrasonicSensor(1U);

  /* Start for S-Function (ev3_encoder): '<Root>/Encoder' */
  initEncoder(1U);

  /* Start for Constant: '<Root>/Constant1' */
  stateflow6_B.Constant1 = stateflow6_P.ObjLength;

  /* Start for Constant: '<Root>/Constant' */
  stateflow6_B.Constant = stateflow6_P.ParkLength;

  /* Start for S-Function (ev3_motor): '<S2>/Motor' */
  initMotor(1U);

  /* InitializeConditions for Delay: '<Root>/Delay1' */
  stateflow6_DW.Delay1_DSTATE = stateflow6_P.Delay1_InitialCondition;

  /* InitializeConditions for Delay: '<Root>/Delay2' */
  stateflow6_DW.Delay2_DSTATE = stateflow6_P.Delay2_InitialCondition;

  /* InitializeConditions for Chart: '<Root>/Chart' */
  stateflow6_DW.sfEvent = stateflow6_CALL_EVENT_g;
  stateflow6_DW.temporalCounter_i1 = 0U;
  stateflow6_DW.is_active_c3_stateflow6 = 0U;
  stateflow6_B.ChartMode = ChartModeType_None;

  /* InitializeConditions for Delay: '<Root>/Delay' */
  stateflow6_DW.Delay_DSTATE = stateflow6_P.Delay_InitialCondition;
}

/* Model terminate function */
void stateflow6_terminate(void)
{
  /* Terminate for S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  terminateUltrasonicSensor(1U);

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
