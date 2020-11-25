/*
 * File: state1.c
 *
 * Code generated for Simulink model 'state1'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Tue Dec 06 16:27:04 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "state1.h"
#include "state1_private.h"
#include "state1_dt.h"

/* Named constants for Chart: '<Root>/Chart' */
#define state1_IN_NO_ACTIVE_CHILD      ((uint8_T)0U)
#define state1_IN_ParkSpotDectd        ((uint8_T)1U)

/* Block signals (auto storage) */
B_state1_T state1_B;

/* Block states (auto storage) */
DW_state1_T state1_DW;

/* Real-time model */
RT_MODEL_state1_T state1_M_;
RT_MODEL_state1_T *const state1_M = &state1_M_;
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
void state1_output(void)
{
  int8_T tmp;
  real_T rtb_TSamp;
  int64m_T rtb_Gain;
  uint32_T tmp_0;
  uint32_T tmp_1;

  /* Reset subsysRan breadcrumbs */
  srClearBC(state1_DW.Park_SubsysRanBC);

  /* S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  state1_B.UltrasonicSensor = getUltrasonicSensorValue(1U);

  /* S-Function (ev3_encoder): '<Root>/Encoder' */
  state1_B.Position = getEncoderValueNoReset(1U);

  /* Chart: '<Root>/Chart' */
  /* Gateway: Chart */
  state1_DW.sfEvent = -1;

  /* During: Chart */
  if (state1_DW.is_active_c3_state1 == 0U) {
    /* Entry: Chart */
    state1_DW.is_active_c3_state1 = 1U;

    /* Entry Internal: Chart */
    /* Transition: '<S1>:11' */
    state1_DW.is_c3_state1 = state1_IN_ParkSpotDectd;

    /* Outputs for Function Call SubSystem: '<Root>/Park' */
    /* Entry 'ParkSpotDectd': '<S1>:10' */
    /* Event: '<S1>:34' */
    state1_DW.Park_ELAPS_T = state1_M->Timing.clockTick0 - state1_DW.Park_PREV_T;
    state1_DW.Park_PREV_T = state1_M->Timing.clockTick0;

    /* SampleTimeMath: '<S5>/TSamp'
     *
     * About '<S5>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp = (real_T)state1_B.Position / ((real_T)state1_DW.Park_ELAPS_T
      * 0.01 * state1_P.TSamp_WtEt);

    /* Sum: '<S5>/Diff' incorporates:
     *  UnitDelay: '<S5>/UD'
     */
    state1_B.Diff = rtb_TSamp - state1_DW.UD_DSTATE;

    /* Gain: '<S4>/Gain' */
    tmp_0 = (uint32_T)state1_P.Gain_Gain;
    tmp_1 = (uint32_T)state1_B.Position;
    sMultiWordMul(&tmp_0, 1, &tmp_1, 1, &rtb_Gain.chunks[0U], 2);

    /* RelationalOperator: '<S7>/Relational Operator' incorporates:
     *  Constant: '<S7>/Constant'
     */
    state1_B.RelationalOperator = (sMultiWord2Double(&rtb_Gain.chunks[0U], 2, 0)
      * 5.8207660913467407E-11 >= state1_P.Constant_Value);

    /* RelationalOperator: '<S7>/Relational Operator1' incorporates:
     *  Constant: '<S7>/Constant1'
     */
    state1_B.RelationalOperator1 = (sMultiWord2Double(&rtb_Gain.chunks[0U], 2, 0)
      * 5.8207660913467407E-11 <= state1_P.Constant1_Value);

    /* Logic: '<S4>/Logical Operator' */
    state1_B.LogicalOperator = (state1_B.RelationalOperator &&
      state1_B.RelationalOperator1);

    /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
     *  Constant: '<Root>/Constant1'
     *  DataTypeConversion: '<S4>/Data Type Conversion'
     */
    /* MATLAB Function 'Park/MATLAB Function': '<S6>:1' */
    if ((state1_B.UltrasonicSensor > 4) && (state1_B.UltrasonicSensor <= 20) &&
        state1_B.LogicalOperator) {
      /* '<S6>:1:3' */
      /* '<S6>:1:4' */
      state1_B.rearmotor = state1_P.Constant1_Value_h;

      /* elseif(sensor_input>20)&&(sensor_input<=35) */
      /*    rearmotor=motor_input; */
    } else {
      /* '<S6>:1:8' */
      state1_B.rearmotor = 0.0;
    }

    /* End of MATLAB Function: '<S4>/MATLAB Function' */

    /* Update for UnitDelay: '<S5>/UD' */
    state1_DW.UD_DSTATE = rtb_TSamp;
    state1_DW.Park_SubsysRanBC = 4;

    /* End of Outputs for SubSystem: '<Root>/Park' */
  } else {
    /* During 'ParkSpotDectd': '<S1>:10' */
  }

  /* End of Chart: '<Root>/Chart' */

  /* S-Function (ev3_lcd): '<S2>/LCD' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  lcdDisplay(state1_B.LogicalOperator, state1_ConstP.LCD_p1, 1U, 1U);

  /* DataTypeConversion: '<S3>/Data Type Conversion' */
  rtb_TSamp = floor(state1_B.rearmotor);
  if (rtb_TSamp < 128.0) {
    if (rtb_TSamp >= -128.0) {
      /* S-Function (ev3_motor): '<S3>/Motor' */
      tmp = (int8_T)rtb_TSamp;
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
void state1_update(void)
{
  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(state1_M)!=-1) &&
        !((rtmGetTFinal(state1_M)-state1_M->Timing.taskTime0) >
          state1_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(state1_M, "Simulation finished");
    }

    if (rtmGetStopRequested(state1_M)) {
      rtmSetErrorStatus(state1_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  state1_M->Timing.taskTime0 =
    (++state1_M->Timing.clockTick0) * state1_M->Timing.stepSize0;
}

/* Model initialize function */
void state1_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)state1_M, 0,
                sizeof(RT_MODEL_state1_T));
  rtmSetTFinal(state1_M, 10.0);
  state1_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  state1_M->Sizes.checksums[0] = (2275329929U);
  state1_M->Sizes.checksums[1] = (58396198U);
  state1_M->Sizes.checksums[2] = (2494132507U);
  state1_M->Sizes.checksums[3] = (1261968765U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    state1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&state1_DW.Park_SubsysRanBC;
    systemRan[3] = (sysRanDType *)&state1_DW.Park_SubsysRanBC;
    rteiSetModelMappingInfoPtr(state1_M->extModeInfo,
      &state1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(state1_M->extModeInfo, state1_M->Sizes.checksums);
    rteiSetTPtr(state1_M->extModeInfo, rtmGetTPtr(state1_M));
  }

  /* block I/O */
  (void) memset(((void *) &state1_B), 0,
                sizeof(B_state1_T));

  /* states (dwork) */
  (void) memset((void *)&state1_DW, 0,
                sizeof(DW_state1_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    state1_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 30;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  initUltrasonicSensor(1U);

  /* Start for S-Function (ev3_encoder): '<Root>/Encoder' */
  initEncoder(1U);

  /* Start for S-Function (ev3_lcd): '<S2>/LCD' */
  initLCD();

  /* Start for S-Function (ev3_motor): '<S3>/Motor' */
  initMotor(1U);
  state1_DW.sfEvent = -1;
  state1_DW.is_active_c3_state1 = 0U;
  state1_DW.is_c3_state1 = state1_IN_NO_ACTIVE_CHILD;

  /* InitializeConditions for Chart: '<Root>/Chart' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/Park'
   */
  state1_DW.Park_PREV_T = state1_M->Timing.clockTick0;

  /* InitializeConditions for UnitDelay: '<S5>/UD' */
  state1_DW.UD_DSTATE = state1_P.DiscreteDerivative_ICPrevScaled;
}

/* Model terminate function */
void state1_terminate(void)
{
  /* Terminate for S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  terminateUltrasonicSensor(1U);

  /* Terminate for S-Function (ev3_encoder): '<Root>/Encoder' */
  terminateEncoder(1U);

  /* Terminate for S-Function (ev3_lcd): '<S2>/LCD' */
  terminateLCD();

  /* Terminate for S-Function (ev3_motor): '<S3>/Motor' */
  terminateMotor(1U, 2U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
