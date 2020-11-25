/*
 * File: testbench_cp_fwd.c
 *
 * Code generated for Simulink model 'testbench_cp_fwd'.
 *
 * Model version                  : 1.43
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Wed Nov 16 20:40:13 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "testbench_cp_fwd.h"
#include "testbench_cp_fwd_private.h"
#include "testbench_cp_fwd_dt.h"

/* Block signals (auto storage) */
B_testbench_cp_fwd_T testbench_cp_fwd_B;

/* Real-time model */
RT_MODEL_testbench_cp_fwd_T testbench_cp_fwd_M_;
RT_MODEL_testbench_cp_fwd_T *const testbench_cp_fwd_M = &testbench_cp_fwd_M_;
int32_T MultiWord2sLong(const uint32_T u[])
{
  return (int32_T)u[0];
}

void sMultiWordShrRound(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T
  y[], int32_T n)
{
  int32_T nb;
  uint32_T n2m1;
  int32_T i;
  boolean_T u1LTZero;
  uint32_T maskHalfLSB;
  u1LTZero = ((u1[n1 - 1] & 2147483648U) != 0U);
  n2m1 = n2 - 1U;
  nb = (int32_T)(n2m1 >> 5);
  if (nb < n1) {
    n2m1 -= nb << 5;
    maskHalfLSB = 1U << n2m1;
    n2m1 = (2U << n2m1) - 1U;
    if (u1LTZero) {
      u1LTZero = ((u1[nb] & n2m1) > maskHalfLSB);
      if ((nb > 0) && ((u1[nb] & n2m1) == maskHalfLSB)) {
        i = 0;
        while ((!u1LTZero) && (i < nb)) {
          u1LTZero = (u1[i] != 0U);
          i++;
        }
      }
    } else {
      u1LTZero = ((u1[nb] & maskHalfLSB) != 0U);
    }
  }

  sMultiWordShr(u1, n1, n2, y, n);
  i = 0;
  while (u1LTZero && (i < n)) {
    y[i]++;
    if (y[i] != 0U) {
      u1LTZero = false;
    }

    i++;
  }
}

void sMultiWordShr(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[],
                   int32_T n)
{
  int32_T nb;
  int32_T i;
  uint32_T ys;
  uint32_T yi;
  uint32_T u1i;
  int32_T nc;
  uint32_T nr;
  uint32_T nl;
  int32_T i1;
  nb = (int32_T)(n2 >> 5);
  i = 0;
  ys = (u1[n1 - 1] & 2147483648U) != 0U ? MAX_uint32_T : 0U;
  if (nb < n1) {
    nc = n + nb;
    if (nc > n1) {
      nc = n1;
    }

    nr = n2 - ((uint32_T)nb << 5);
    if (nr > 0U) {
      nl = 32U - nr;
      u1i = u1[nb];
      for (i1 = nb + 1; i1 < nc; i1++) {
        yi = u1i >> nr;
        u1i = u1[i1];
        y[i] = u1i << nl | yi;
        i++;
      }

      yi = u1i >> nr;
      u1i = nc < n1 ? u1[nc] : ys;
      y[i] = u1i << nl | yi;
      i++;
    } else {
      for (i1 = nb; i1 < nc; i1++) {
        y[i] = u1[i1];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

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

/* Model output function */
void testbench_cp_fwd_output(void)
{
  int32_T rtb_Encoder_0;
  int8_T tmp;
  int8_T tmp_0;
  real_T tmp_1;
  int64m_T tmp_2;
  int64m_T tmp_3;
  uint32_T tmp_4;
  uint32_T tmp_5;

  /* S-Function (ev3_encoder): '<Root>/Encoder' */
  rtb_Encoder_0 = getEncoderValueNoReset(1U);

  /* Gain: '<Root>/Gain' incorporates:
   *  S-Function (ev3_encoder): '<Root>/Encoder'
   */
  tmp_4 = (uint32_T)testbench_cp_fwd_P.Gain_Gain;
  tmp_5 = (uint32_T)rtb_Encoder_0;
  sMultiWordMul(&tmp_4, 1, &tmp_5, 1, &tmp_3.chunks[0U], 2);

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  sMultiWordShrRound(&tmp_3.chunks[0U], 2, 35U, &tmp_2.chunks[0U], 2);
  testbench_cp_fwd_B.DataTypeConversion = (int16_T)MultiWord2sLong
    (&tmp_2.chunks[0U]);

  /* S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  getUltrasonicSensorValue(1U);

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Motor_power_input'
   */
  /* MATLAB Function 'MATLAB Function': '<S1>:1' */
  /* '<S1>:1:5' */
  /* sts=1; */
  /* %if(encA<=25) */
  /* Motor_power_A=Motor_input;   */
  tmp_1 = floor(testbench_cp_fwd_P.Motor_power_input_Value);
  if (tmp_1 < 128.0) {
    if (tmp_1 >= -128.0) {
      /* S-Function (ev3_motor): '<S2>/Motor' */
      tmp = (int8_T)tmp_1;
    } else {
      /* S-Function (ev3_motor): '<S2>/Motor' */
      tmp = MIN_int8_T;
    }
  } else {
    /* S-Function (ev3_motor): '<S2>/Motor' */
    tmp = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

  /* S-Function (ev3_motor): '<S2>/Motor' */
  setMotor(&tmp, 1U, 2U);

  /* S-Function (ev3_led): '<S3>/Status Lights' */
  tmp_0 = 0;
  setLED(&tmp_0);
}

/* Model update function */
void testbench_cp_fwd_update(void)
{
  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(testbench_cp_fwd_M)!=-1) &&
        !((rtmGetTFinal(testbench_cp_fwd_M)-testbench_cp_fwd_M->Timing.taskTime0)
          > testbench_cp_fwd_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(testbench_cp_fwd_M, "Simulation finished");
    }

    if (rtmGetStopRequested(testbench_cp_fwd_M)) {
      rtmSetErrorStatus(testbench_cp_fwd_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  testbench_cp_fwd_M->Timing.taskTime0 =
    (++testbench_cp_fwd_M->Timing.clockTick0) *
    testbench_cp_fwd_M->Timing.stepSize0;
}

/* Model initialize function */
void testbench_cp_fwd_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)testbench_cp_fwd_M, 0,
                sizeof(RT_MODEL_testbench_cp_fwd_T));
  rtmSetTFinal(testbench_cp_fwd_M, -1);
  testbench_cp_fwd_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  testbench_cp_fwd_M->Sizes.checksums[0] = (232450656U);
  testbench_cp_fwd_M->Sizes.checksums[1] = (1773040384U);
  testbench_cp_fwd_M->Sizes.checksums[2] = (2627224182U);
  testbench_cp_fwd_M->Sizes.checksums[3] = (3167325903U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    testbench_cp_fwd_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(testbench_cp_fwd_M->extModeInfo,
      &testbench_cp_fwd_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(testbench_cp_fwd_M->extModeInfo,
                        testbench_cp_fwd_M->Sizes.checksums);
    rteiSetTPtr(testbench_cp_fwd_M->extModeInfo, rtmGetTPtr(testbench_cp_fwd_M));
  }

  /* block I/O */
  (void) memset(((void *) &testbench_cp_fwd_B), 0,
                sizeof(B_testbench_cp_fwd_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    testbench_cp_fwd_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 30;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (ev3_encoder): '<Root>/Encoder' */
  initEncoder(1U);

  /* Start for S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  initUltrasonicSensor(1U);

  /* Start for S-Function (ev3_motor): '<S2>/Motor' */
  initMotor(1U);

  /* Start for S-Function (ev3_led): '<S3>/Status Lights' */
  initLED();
}

/* Model terminate function */
void testbench_cp_fwd_terminate(void)
{
  /* Terminate for S-Function (ev3_encoder): '<Root>/Encoder' */
  terminateEncoder(1U);

  /* Terminate for S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  terminateUltrasonicSensor(1U);

  /* Terminate for S-Function (ev3_motor): '<S2>/Motor' */
  terminateMotor(1U, 2U);

  /* Terminate for S-Function (ev3_led): '<S3>/Status Lights' */
  terminateLED();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
