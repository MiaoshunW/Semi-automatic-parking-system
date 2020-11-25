/*
 * File: testbench_straight.c
 *
 * Code generated for Simulink model 'testbench_straight'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Thu Dec 08 17:21:12 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "testbench_straight.h"
#include "testbench_straight_private.h"
#include "testbench_straight_dt.h"

/* Block signals (auto storage) */
B_testbench_straight_T testbench_straight_B;

/* Block states (auto storage) */
DW_testbench_straight_T testbench_straight_DW;

/* Real-time model */
RT_MODEL_testbench_straight_T testbench_straight_M_;
RT_MODEL_testbench_straight_T *const testbench_straight_M =
  &testbench_straight_M_;

/* Model output function */
void testbench_straight_output(void)
{
  int8_T tmp;
  int8_T tmp_0;
  real_T tmp_1;

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant'
   */
  tmp_1 = floor(testbench_straight_P.Constant_Value);
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

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (ev3_motor): '<S1>/Motor' */
  setMotor(&tmp, 1U, 2U);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  testbench_straight_B.PulseGenerator = (testbench_straight_DW.clockTickCounter <
    testbench_straight_P.PulseGenerator_Duty) &&
    (testbench_straight_DW.clockTickCounter >= 0) ?
    testbench_straight_P.PulseGenerator_Amp : 0.0;
  if (testbench_straight_DW.clockTickCounter >=
      testbench_straight_P.PulseGenerator_Period - 1.0) {
    testbench_straight_DW.clockTickCounter = 0;
  } else {
    testbench_straight_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  tmp_1 = floor(testbench_straight_B.PulseGenerator);
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
  setMotor(&tmp_0, 2U, 2U);
}

/* Model update function */
void testbench_straight_update(void)
{
  /* signal main to stop simulation */
  {                                    /* Sample time: [0.5s, 0.0s] */
    if ((rtmGetTFinal(testbench_straight_M)!=-1) &&
        !((rtmGetTFinal(testbench_straight_M)-
           testbench_straight_M->Timing.taskTime0) >
          testbench_straight_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(testbench_straight_M, "Simulation finished");
    }

    if (rtmGetStopRequested(testbench_straight_M)) {
      rtmSetErrorStatus(testbench_straight_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  testbench_straight_M->Timing.taskTime0 =
    (++testbench_straight_M->Timing.clockTick0) *
    testbench_straight_M->Timing.stepSize0;
}

/* Model initialize function */
void testbench_straight_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)testbench_straight_M, 0,
                sizeof(RT_MODEL_testbench_straight_T));
  rtmSetTFinal(testbench_straight_M, 10.0);
  testbench_straight_M->Timing.stepSize0 = 0.5;

  /* External mode info */
  testbench_straight_M->Sizes.checksums[0] = (305286744U);
  testbench_straight_M->Sizes.checksums[1] = (3810693955U);
  testbench_straight_M->Sizes.checksums[2] = (281459440U);
  testbench_straight_M->Sizes.checksums[3] = (347883883U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    testbench_straight_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(testbench_straight_M->extModeInfo,
      &testbench_straight_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(testbench_straight_M->extModeInfo,
                        testbench_straight_M->Sizes.checksums);
    rteiSetTPtr(testbench_straight_M->extModeInfo, rtmGetTPtr
                (testbench_straight_M));
  }

  /* block I/O */
  (void) memset(((void *) &testbench_straight_B), 0,
                sizeof(B_testbench_straight_T));

  /* states (dwork) */
  (void) memset((void *)&testbench_straight_DW, 0,
                sizeof(DW_testbench_straight_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    testbench_straight_M->SpecialInfo.mappingInfo = (&dtInfo);
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

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  testbench_straight_DW.clockTickCounter = 0;

  /* Start for S-Function (ev3_motor): '<S2>/Motor' */
  initMotor(2U);
}

/* Model terminate function */
void testbench_straight_terminate(void)
{
  /* Terminate for S-Function (ev3_motor): '<S1>/Motor' */
  terminateMotor(1U, 2U);

  /* Terminate for S-Function (ev3_motor): '<S2>/Motor' */
  terminateMotor(2U, 2U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
