/*
 * File: testbench_sensor.c
 *
 * Code generated for Simulink model 'testbench_sensor'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Fri Dec 02 19:40:17 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "testbench_sensor.h"
#include "testbench_sensor_private.h"
#include "testbench_sensor_dt.h"

/* Real-time model */
RT_MODEL_testbench_sensor_T testbench_sensor_M_;
RT_MODEL_testbench_sensor_T *const testbench_sensor_M = &testbench_sensor_M_;

/* Model output function */
void testbench_sensor_output(void)
{
  uint8_T rtb_UltrasonicSensor_0;
  int8_T tmp;
  int32_T rtb_rearmotor;

  /* S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  rtb_UltrasonicSensor_0 = getUltrasonicSensorValue(1U);

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor'
   */
  /* MATLAB Function 'MATLAB Function': '<S1>:1' */
  if ((rtb_UltrasonicSensor_0 > 4) && (rtb_UltrasonicSensor_0 <= 20)) {
    /* '<S1>:1:3' */
    /* '<S1>:1:4' */
    rtb_rearmotor = 30;
  } else if ((rtb_UltrasonicSensor_0 > 20) && (rtb_UltrasonicSensor_0 <= 35)) {
    /* '<S1>:1:5' */
    /* '<S1>:1:6' */
    rtb_rearmotor = 50;
  } else {
    /* '<S1>:1:8' */
    rtb_rearmotor = 0;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* S-Function (ev3_motor): '<S2>/Motor' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  tmp = (int8_T)rtb_rearmotor;
  setMotor(&tmp, 1U, 2U);
}

/* Model update function */
void testbench_sensor_update(void)
{
  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(testbench_sensor_M)!=-1) &&
        !((rtmGetTFinal(testbench_sensor_M)-testbench_sensor_M->Timing.taskTime0)
          > testbench_sensor_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(testbench_sensor_M, "Simulation finished");
    }

    if (rtmGetStopRequested(testbench_sensor_M)) {
      rtmSetErrorStatus(testbench_sensor_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  testbench_sensor_M->Timing.taskTime0 =
    (++testbench_sensor_M->Timing.clockTick0) *
    testbench_sensor_M->Timing.stepSize0;
}

/* Model initialize function */
void testbench_sensor_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)testbench_sensor_M, 0,
                sizeof(RT_MODEL_testbench_sensor_T));
  rtmSetTFinal(testbench_sensor_M, 10.0);
  testbench_sensor_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  testbench_sensor_M->Sizes.checksums[0] = (4105621806U);
  testbench_sensor_M->Sizes.checksums[1] = (571839917U);
  testbench_sensor_M->Sizes.checksums[2] = (1387537258U);
  testbench_sensor_M->Sizes.checksums[3] = (2737590713U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    testbench_sensor_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(testbench_sensor_M->extModeInfo,
      &testbench_sensor_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(testbench_sensor_M->extModeInfo,
                        testbench_sensor_M->Sizes.checksums);
    rteiSetTPtr(testbench_sensor_M->extModeInfo, rtmGetTPtr(testbench_sensor_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    testbench_sensor_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];
  }

  /* Start for S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  initUltrasonicSensor(1U);

  /* Start for S-Function (ev3_motor): '<S2>/Motor' */
  initMotor(1U);
}

/* Model terminate function */
void testbench_sensor_terminate(void)
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
