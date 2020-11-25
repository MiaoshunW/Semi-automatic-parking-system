/*
 * File: testbench_encoder.c
 *
 * Code generated for Simulink model 'testbench_encoder'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Fri Dec 09 19:48:50 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "testbench_encoder.h"
#include "testbench_encoder_private.h"
#include "testbench_encoder_dt.h"

/* Block signals (auto storage) */
B_testbench_encoder_T testbench_encoder_B;

/* Block states (auto storage) */
DW_testbench_encoder_T testbench_encoder_DW;

/* Real-time model */
RT_MODEL_testbench_encoder_T testbench_encoder_M_;
RT_MODEL_testbench_encoder_T *const testbench_encoder_M = &testbench_encoder_M_;

/* Model output function */
void testbench_encoder_output(void)
{
  int8_T tmp;
  int8_T tmp_0;
  real_T rtb_length;
  real_T rtb_y;
  int32_T rtb_reset;
  uint8_T tmp_1;

  /* S-Function (ev3_encoder): '<Root>/Encoder' incorporates:
   *  UnitDelay: '<Root>/Unit Delay'
   */
  tmp = testbench_encoder_DW.UnitDelay_DSTATE;
  rtb_reset = getEncoderValueExternalReset(1U, &tmp);

  /* Gain: '<Root>/Gain1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  S-Function (ev3_encoder): '<Root>/Encoder'
   */
  testbench_encoder_B.Gain1 = testbench_encoder_P.Gain1_Gain * (real_T)rtb_reset;

  /* MATLAB Function: '<Root>/Encoder_function' incorporates:
   *  Constant: '<Root>/Motor_power'
   */
  /* MATLAB Function 'Encoder_function': '<S2>:1' */
  if (((testbench_encoder_B.Gain1 >= 30.0) && (testbench_encoder_B.Gain1 <= 35.0))
      || (testbench_encoder_B.Gain1 == 0.0)) {
    /* '<S2>:1:3' */
    /* '<S2>:1:4' */
    rtb_y = testbench_encoder_P.Motor_power_Value;

    /* '<S2>:1:5' */
    rtb_length = testbench_encoder_B.Gain1;

    /* '<S2>:1:6' */
    rtb_reset = 1;
  } else {
    /* '<S2>:1:8' */
    rtb_y = 0.0;

    /* '<S2>:1:9' */
    rtb_length = testbench_encoder_B.Gain1;

    /* '<S2>:1:10' */
    rtb_reset = 0;
  }

  /* End of MATLAB Function: '<Root>/Encoder_function' */

  /* S-Function (ev3_lcd): '<S1>/LCD' */
  tmp_1 = 0U;

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  rtb_length = floor(rtb_length);
  if (rtIsNaN(rtb_length) || rtIsInf(rtb_length)) {
    rtb_length = 0.0;
  } else {
    rtb_length = fmod(rtb_length, 4.294967296E+9);
  }

  /* S-Function (ev3_lcd): '<S1>/LCD' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  lcdDisplay(rtb_length < 0.0 ? -(int32_T)(uint32_T)-rtb_length : (int32_T)
             (uint32_T)rtb_length, &tmp_1, 1U, 1U);

  /* DataTypeConversion: '<S3>/Data Type Conversion' */
  rtb_length = floor(rtb_y);
  if (rtb_length < 128.0) {
    if (rtb_length >= -128.0) {
      /* S-Function (ev3_motor): '<S3>/Motor' */
      tmp_0 = (int8_T)rtb_length;
    } else {
      /* S-Function (ev3_motor): '<S3>/Motor' */
      tmp_0 = MIN_int8_T;
    }
  } else {
    /* S-Function (ev3_motor): '<S3>/Motor' */
    tmp_0 = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S3>/Data Type Conversion' */

  /* S-Function (ev3_motor): '<S3>/Motor' */
  setMotor(&tmp_0, 1U, 2U);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  testbench_encoder_B.DataTypeConversion1 = (int8_T)(int32_T)fmod(rtb_reset,
    256.0);
}

/* Model update function */
void testbench_encoder_update(void)
{
  /* Update for UnitDelay: '<Root>/Unit Delay' */
  testbench_encoder_DW.UnitDelay_DSTATE =
    testbench_encoder_B.DataTypeConversion1;

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(testbench_encoder_M)!=-1) &&
        !((rtmGetTFinal(testbench_encoder_M)-
           testbench_encoder_M->Timing.taskTime0) >
          testbench_encoder_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(testbench_encoder_M, "Simulation finished");
    }

    if (rtmGetStopRequested(testbench_encoder_M)) {
      rtmSetErrorStatus(testbench_encoder_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  testbench_encoder_M->Timing.taskTime0 =
    (++testbench_encoder_M->Timing.clockTick0) *
    testbench_encoder_M->Timing.stepSize0;
}

/* Model initialize function */
void testbench_encoder_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)testbench_encoder_M, 0,
                sizeof(RT_MODEL_testbench_encoder_T));
  rtmSetTFinal(testbench_encoder_M, -1);
  testbench_encoder_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  testbench_encoder_M->Sizes.checksums[0] = (2712309632U);
  testbench_encoder_M->Sizes.checksums[1] = (848610944U);
  testbench_encoder_M->Sizes.checksums[2] = (3995318074U);
  testbench_encoder_M->Sizes.checksums[3] = (1414633539U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    testbench_encoder_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(testbench_encoder_M->extModeInfo,
      &testbench_encoder_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(testbench_encoder_M->extModeInfo,
                        testbench_encoder_M->Sizes.checksums);
    rteiSetTPtr(testbench_encoder_M->extModeInfo, rtmGetTPtr(testbench_encoder_M));
  }

  /* block I/O */
  (void) memset(((void *) &testbench_encoder_B), 0,
                sizeof(B_testbench_encoder_T));

  /* states (dwork) */
  (void) memset((void *)&testbench_encoder_DW, 0,
                sizeof(DW_testbench_encoder_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    testbench_encoder_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (ev3_encoder): '<Root>/Encoder' */
  initEncoder(1U);

  /* Start for S-Function (ev3_lcd): '<S1>/LCD' */
  initLCD();

  /* Start for S-Function (ev3_motor): '<S3>/Motor' */
  initMotor(1U);

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  testbench_encoder_DW.UnitDelay_DSTATE =
    testbench_encoder_P.UnitDelay_InitialCondition;
}

/* Model terminate function */
void testbench_encoder_terminate(void)
{
  /* Terminate for S-Function (ev3_encoder): '<Root>/Encoder' */
  terminateEncoder(1U);

  /* Terminate for S-Function (ev3_lcd): '<S1>/LCD' */
  terminateLCD();

  /* Terminate for S-Function (ev3_motor): '<S3>/Motor' */
  terminateMotor(1U, 2U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
