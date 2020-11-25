/*
 * File: testbench_str.c
 *
 * Code generated for Simulink model 'testbench_str'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Sat Dec 10 17:11:52 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "testbench_str.h"
#include "testbench_str_private.h"
#include "testbench_str_dt.h"

/* Block signals (auto storage) */
B_testbench_str_T testbench_str_B;

/* Block states (auto storage) */
DW_testbench_str_T testbench_str_DW;

/* Real-time model */
RT_MODEL_testbench_str_T testbench_str_M_;
RT_MODEL_testbench_str_T *const testbench_str_M = &testbench_str_M_;

/* Model output function */
void testbench_str_output(void)
{
  int8_T tmp;
  int8_T tmp_0;
  real_T tmp_1;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  testbench_str_B.PulseGenerator = (testbench_str_DW.clockTickCounter <
    testbench_str_P.PulseGenerator_Duty) && (testbench_str_DW.clockTickCounter >=
    0) ? testbench_str_P.PulseGenerator_Amp : 0.0;
  if (testbench_str_DW.clockTickCounter >= testbench_str_P.PulseGenerator_Period
      - 1.0) {
    testbench_str_DW.clockTickCounter = 0;
  } else {
    testbench_str_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Switch: '<Root>/Switch' */
  if (testbench_str_B.PulseGenerator > testbench_str_P.Switch_Threshold) {
    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  Constant: '<Root>/Constant'
     */
    tmp_1 = floor(testbench_str_P.Constant_Value);
    if (tmp_1 < 128.0) {
      if (tmp_1 >= -128.0) {
        /* S-Function (ev3_motor): '<S1>/Motor' */
        tmp = (int8_T)tmp_1;
      } else {
        /* S-Function (ev3_motor): '<S1>/Motor' */
        tmp = MIN_int8_T;
      }
    } else {
      /* S-Function (ev3_motor): '<S1>/Motor' */
      tmp = MAX_int8_T;
    }
  } else {
    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    tmp_1 = floor(testbench_str_P.Constant1_Value);
    if (tmp_1 < 128.0) {
      if (tmp_1 >= -128.0) {
        /* S-Function (ev3_motor): '<S1>/Motor' */
        tmp = (int8_T)tmp_1;
      } else {
        /* S-Function (ev3_motor): '<S1>/Motor' */
        tmp = MIN_int8_T;
      }
    } else {
      /* S-Function (ev3_motor): '<S1>/Motor' */
      tmp = MAX_int8_T;
    }
  }

  /* End of Switch: '<Root>/Switch' */

  /* S-Function (ev3_motor): '<S1>/Motor' */
  setMotor(&tmp, 2U, 2U);

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  tmp_1 = floor(testbench_str_P.Constant2_Value);
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
}

/* Model update function */
void testbench_str_update(void)
{
  /* signal main to stop simulation */
  {                                    /* Sample time: [1.0s, 0.0s] */
    if ((rtmGetTFinal(testbench_str_M)!=-1) &&
        !((rtmGetTFinal(testbench_str_M)-testbench_str_M->Timing.taskTime0) >
          testbench_str_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(testbench_str_M, "Simulation finished");
    }

    if (rtmGetStopRequested(testbench_str_M)) {
      rtmSetErrorStatus(testbench_str_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  testbench_str_M->Timing.taskTime0 =
    (++testbench_str_M->Timing.clockTick0) * testbench_str_M->Timing.stepSize0;
}

/* Model initialize function */
void testbench_str_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)testbench_str_M, 0,
                sizeof(RT_MODEL_testbench_str_T));
  rtmSetTFinal(testbench_str_M, -1);
  testbench_str_M->Timing.stepSize0 = 1.0;

  /* External mode info */
  testbench_str_M->Sizes.checksums[0] = (3861783960U);
  testbench_str_M->Sizes.checksums[1] = (970117022U);
  testbench_str_M->Sizes.checksums[2] = (4255974324U);
  testbench_str_M->Sizes.checksums[3] = (1091253685U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    testbench_str_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(testbench_str_M->extModeInfo,
      &testbench_str_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(testbench_str_M->extModeInfo,
                        testbench_str_M->Sizes.checksums);
    rteiSetTPtr(testbench_str_M->extModeInfo, rtmGetTPtr(testbench_str_M));
  }

  /* block I/O */
  (void) memset(((void *) &testbench_str_B), 0,
                sizeof(B_testbench_str_T));

  /* states (dwork) */
  (void) memset((void *)&testbench_str_DW, 0,
                sizeof(DW_testbench_str_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    testbench_str_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  testbench_str_DW.clockTickCounter = 0;

  /* Start for S-Function (ev3_motor): '<S1>/Motor' */
  initMotor(2U);

  /* Start for S-Function (ev3_motor): '<S2>/Motor' */
  initMotor(1U);
}

/* Model terminate function */
void testbench_str_terminate(void)
{
  /* Terminate for S-Function (ev3_motor): '<S1>/Motor' */
  terminateMotor(2U, 2U);

  /* Terminate for S-Function (ev3_motor): '<S2>/Motor' */
  terminateMotor(1U, 2U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
