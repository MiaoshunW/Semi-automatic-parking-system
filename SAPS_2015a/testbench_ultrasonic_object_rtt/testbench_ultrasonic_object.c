/*
 * File: testbench_ultrasonic_object.c
 *
 * Code generated for Simulink model 'testbench_ultrasonic_object'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Sat Dec 03 02:01:41 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "testbench_ultrasonic_object.h"
#include "testbench_ultrasonic_object_private.h"
#include "testbench_ultrasonic_object_dt.h"

/* Block signals (auto storage) */
B_testbench_ultrasonic_object_T testbench_ultrasonic_object_B;

/* Block states (auto storage) */
DW_testbench_ultrasonic_objec_T testbench_ultrasonic_object_DW;

/* Real-time model */
RT_MODEL_testbench_ultrasonic_T testbench_ultrasonic_object_M_;
RT_MODEL_testbench_ultrasonic_T *const testbench_ultrasonic_object_M =
  &testbench_ultrasonic_object_M_;

/* Model output function */
void testbench_ultrasonic_object_output(void)
{
  uint8_T rtb_UltrasonicSensor_0;
  int8_T tmp;
  real_T tmp_0;

  /* S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  rtb_UltrasonicSensor_0 = getUltrasonicSensorValue(1U);

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S2>/Constant'
   *  RelationalOperator: '<S1>/Compare'
   *  S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor'
   */
  testbench_ultrasonic_object_B.Compare = (uint8_T)((rtb_UltrasonicSensor_0 >=
    testbench_ultrasonic_object_P.CompareToConstant_const) <=
    testbench_ultrasonic_object_P.CompareToConstant1_const);

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant'
   */
  tmp_0 = floor(testbench_ultrasonic_object_P.Constant_Value);
  if (tmp_0 < 128.0) {
    if (tmp_0 >= -128.0) {
      /* S-Function (ev3_motor): '<S3>/Motor' */
      tmp = (int8_T)tmp_0;
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
}

/* Model update function */
void testbench_ultrasonic_object_update(void)
{
  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(testbench_ultrasonic_object_M)!=-1) &&
        !((rtmGetTFinal(testbench_ultrasonic_object_M)-
           testbench_ultrasonic_object_M->Timing.taskTime0) >
          testbench_ultrasonic_object_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(testbench_ultrasonic_object_M, "Simulation finished");
    }

    if (rtmGetStopRequested(testbench_ultrasonic_object_M)) {
      rtmSetErrorStatus(testbench_ultrasonic_object_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  testbench_ultrasonic_object_M->Timing.taskTime0 =
    (++testbench_ultrasonic_object_M->Timing.clockTick0) *
    testbench_ultrasonic_object_M->Timing.stepSize0;
}

/* Model initialize function */
void testbench_ultrasonic_object_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)testbench_ultrasonic_object_M, 0,
                sizeof(RT_MODEL_testbench_ultrasonic_T));
  rtmSetTFinal(testbench_ultrasonic_object_M, 5.0);
  testbench_ultrasonic_object_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  testbench_ultrasonic_object_M->Sizes.checksums[0] = (4120459576U);
  testbench_ultrasonic_object_M->Sizes.checksums[1] = (2980050932U);
  testbench_ultrasonic_object_M->Sizes.checksums[2] = (2575726174U);
  testbench_ultrasonic_object_M->Sizes.checksums[3] = (2815632294U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    testbench_ultrasonic_object_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(testbench_ultrasonic_object_M->extModeInfo,
      &testbench_ultrasonic_object_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(testbench_ultrasonic_object_M->extModeInfo,
                        testbench_ultrasonic_object_M->Sizes.checksums);
    rteiSetTPtr(testbench_ultrasonic_object_M->extModeInfo, rtmGetTPtr
                (testbench_ultrasonic_object_M));
  }

  /* block I/O */
  (void) memset(((void *) &testbench_ultrasonic_object_B), 0,
                sizeof(B_testbench_ultrasonic_object_T));

  /* states (dwork) */
  (void) memset((void *)&testbench_ultrasonic_object_DW, 0,
                sizeof(DW_testbench_ultrasonic_objec_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    testbench_ultrasonic_object_M->SpecialInfo.mappingInfo = (&dtInfo);
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

  /* Start for S-Function (ev3_motor): '<S3>/Motor' */
  initMotor(1U);
}

/* Model terminate function */
void testbench_ultrasonic_object_terminate(void)
{
  /* Terminate for S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  terminateUltrasonicSensor(1U);

  /* Terminate for S-Function (ev3_motor): '<S3>/Motor' */
  terminateMotor(1U, 2U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
