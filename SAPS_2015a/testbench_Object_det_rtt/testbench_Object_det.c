/*
 * File: testbench_Object_det.c
 *
 * Code generated for Simulink model 'testbench_Object_det'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Sat Dec 03 04:59:56 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "testbench_Object_det.h"
#include "testbench_Object_det_private.h"
#include "testbench_Object_det_dt.h"

/* Block signals (auto storage) */
B_testbench_Object_det_T testbench_Object_det_B;

/* Block states (auto storage) */
DW_testbench_Object_det_T testbench_Object_det_DW;

/* Real-time model */
RT_MODEL_testbench_Object_det_T testbench_Object_det_M_;
RT_MODEL_testbench_Object_det_T *const testbench_Object_det_M =
  &testbench_Object_det_M_;
void sMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
                   n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T nj;
  uint32_T u1i;
  uint32_T yk;
  uint32_T a1;
  uint32_T a0;
  uint32_T b1;
  uint32_T w10;
  uint32_T w01;
  uint32_T cb;
  boolean_T isNegative1;
  boolean_T isNegative2;
  uint32_T cb1;
  uint32_T cb2;
  isNegative1 = ((u1[n1 - 1] & 2147483648U) != 0U);
  isNegative2 = ((u2[n2 - 1] & 2147483648U) != 0U);
  cb1 = 1U;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    cb = 0U;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535U;
    cb2 = 1U;
    k = n - i;
    nj = n2 <= k ? n2 : k;
    k = i;
    for (j = 0; j < nj; j++) {
      yk = y[k];
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

      b1 = u1i >> 16U;
      u1i &= 65535U;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk += cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1U;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

real_T sMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real_T y;
  int32_T i;
  int32_T exp_0;
  uint32_T u1i;
  uint32_T cb;
  y = 0.0;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648U) != 0U) {
    cb = 1U;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= ldexp(cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += ldexp(u1[i], exp_0);
      exp_0 += 32;
    }
  }

  return y;
}

/* Model output function */
void testbench_Object_det_output(void)
{
  uint8_T rtb_UltrasonicSensor_0;
  int8_T tmp;
  real_T rtb_rearmotor;
  int64m_T rtb_Gain;
  uint32_T tmp_0;
  uint32_T tmp_1;

  /* S-Function (ev3_encoder): '<Root>/Encoder' */
  testbench_Object_det_B.Position = getEncoderValueNoReset(1U);

  /* SampleTimeMath: '<S1>/TSamp'
   *
   * About '<S1>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  testbench_Object_det_B.TSamp = (real_T)testbench_Object_det_P.TSamp_WtEt * 4.0
    * (real_T)testbench_Object_det_B.Position;

  /* Sum: '<S1>/Diff' incorporates:
   *  UnitDelay: '<S1>/UD'
   */
  testbench_Object_det_B.Diff = testbench_Object_det_B.TSamp -
    testbench_Object_det_DW.UD_DSTATE;

  /* Gain: '<Root>/Gain' */
  tmp_0 = (uint32_T)testbench_Object_det_P.Gain_Gain;
  tmp_1 = (uint32_T)testbench_Object_det_B.Position;
  sMultiWordMul(&tmp_0, 1, &tmp_1, 1, &rtb_Gain.chunks[0U], 2);

  /* RelationalOperator: '<S5>/Relational Operator' incorporates:
   *  Constant: '<S5>/Constant'
   */
  testbench_Object_det_B.RelationalOperator = (sMultiWord2Double
    (&rtb_Gain.chunks[0U], 2, 0) * 5.8207660913467407E-11 >=
    testbench_Object_det_P.Constant_Value);

  /* RelationalOperator: '<S5>/Relational Operator1' incorporates:
   *  Constant: '<S5>/Constant1'
   */
  testbench_Object_det_B.RelationalOperator1 = (sMultiWord2Double
    (&rtb_Gain.chunks[0U], 2, 0) * 5.8207660913467407E-11 <=
    testbench_Object_det_P.Constant1_Value);

  /* Logic: '<Root>/Logical Operator' */
  testbench_Object_det_B.LogicalOperator =
    (testbench_Object_det_B.RelationalOperator &&
     testbench_Object_det_B.RelationalOperator1);

  /* S-Function (ev3_lcd): '<S2>/LCD' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  lcdDisplay(testbench_Object_det_B.LogicalOperator,
             testbench_Object_det_ConstP.LCD_p1, 1U, 1U);

  /* S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  rtb_UltrasonicSensor_0 = getUltrasonicSensorValue(1U);

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant'
   *  S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor'
   */
  /* MATLAB Function 'MATLAB Function': '<S3>:1' */
  if ((rtb_UltrasonicSensor_0 > 4) && (rtb_UltrasonicSensor_0 <= 20) &&
      testbench_Object_det_B.LogicalOperator) {
    /* '<S3>:1:3' */
    /* '<S3>:1:4' */
    rtb_rearmotor = testbench_Object_det_P.Constant_Value_k;

    /* elseif(sensor_input>20)&&(sensor_input<=35) */
    /*    rearmotor=motor_input; */
  } else {
    /* '<S3>:1:8' */
    rtb_rearmotor = 0.0;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  rtb_rearmotor = floor(rtb_rearmotor);
  if (rtb_rearmotor < 128.0) {
    if (rtb_rearmotor >= -128.0) {
      /* S-Function (ev3_motor): '<S4>/Motor' */
      tmp = (int8_T)rtb_rearmotor;
    } else {
      /* S-Function (ev3_motor): '<S4>/Motor' */
      tmp = MIN_int8_T;
    }
  } else {
    /* S-Function (ev3_motor): '<S4>/Motor' */
    tmp = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

  /* S-Function (ev3_motor): '<S4>/Motor' */
  setMotor(&tmp, 1U, 2U);
}

/* Model update function */
void testbench_Object_det_update(void)
{
  /* Update for UnitDelay: '<S1>/UD' */
  testbench_Object_det_DW.UD_DSTATE = testbench_Object_det_B.TSamp;

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(testbench_Object_det_M)!=-1) &&
        !((rtmGetTFinal(testbench_Object_det_M)-
           testbench_Object_det_M->Timing.taskTime0) >
          testbench_Object_det_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(testbench_Object_det_M, "Simulation finished");
    }

    if (rtmGetStopRequested(testbench_Object_det_M)) {
      rtmSetErrorStatus(testbench_Object_det_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  testbench_Object_det_M->Timing.taskTime0 =
    (++testbench_Object_det_M->Timing.clockTick0) *
    testbench_Object_det_M->Timing.stepSize0;
}

/* Model initialize function */
void testbench_Object_det_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)testbench_Object_det_M, 0,
                sizeof(RT_MODEL_testbench_Object_det_T));
  rtmSetTFinal(testbench_Object_det_M, -1);
  testbench_Object_det_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  testbench_Object_det_M->Sizes.checksums[0] = (3448972348U);
  testbench_Object_det_M->Sizes.checksums[1] = (3221461096U);
  testbench_Object_det_M->Sizes.checksums[2] = (2495939190U);
  testbench_Object_det_M->Sizes.checksums[3] = (4277337846U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    testbench_Object_det_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(testbench_Object_det_M->extModeInfo,
      &testbench_Object_det_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(testbench_Object_det_M->extModeInfo,
                        testbench_Object_det_M->Sizes.checksums);
    rteiSetTPtr(testbench_Object_det_M->extModeInfo, rtmGetTPtr
                (testbench_Object_det_M));
  }

  /* block I/O */
  (void) memset(((void *) &testbench_Object_det_B), 0,
                sizeof(B_testbench_Object_det_T));

  /* states (dwork) */
  (void) memset((void *)&testbench_Object_det_DW, 0,
                sizeof(DW_testbench_Object_det_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    testbench_Object_det_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 31;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (ev3_encoder): '<Root>/Encoder' */
  initEncoder(1U);

  /* Start for S-Function (ev3_lcd): '<S2>/LCD' */
  initLCD();

  /* Start for S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  initUltrasonicSensor(1U);

  /* Start for S-Function (ev3_motor): '<S4>/Motor' */
  initMotor(1U);

  /* InitializeConditions for UnitDelay: '<S1>/UD' */
  testbench_Object_det_DW.UD_DSTATE =
    testbench_Object_det_P.DiscreteDerivative_ICPrevScaled;
}

/* Model terminate function */
void testbench_Object_det_terminate(void)
{
  /* Terminate for S-Function (ev3_encoder): '<Root>/Encoder' */
  terminateEncoder(1U);

  /* Terminate for S-Function (ev3_lcd): '<S2>/LCD' */
  terminateLCD();

  /* Terminate for S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  terminateUltrasonicSensor(1U);

  /* Terminate for S-Function (ev3_motor): '<S4>/Motor' */
  terminateMotor(1U, 2U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
