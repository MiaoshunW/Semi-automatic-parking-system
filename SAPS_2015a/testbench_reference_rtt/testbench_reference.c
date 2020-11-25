/*
 * File: testbench_reference.c
 *
 * Code generated for Simulink model 'testbench_reference'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Fri Dec 02 16:33:45 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "testbench_reference.h"
#include "testbench_reference_private.h"
#include "testbench_reference_dt.h"

/* Block signals (auto storage) */
B_testbench_reference_T testbench_reference_B;

/* Continuous states */
X_testbench_reference_T testbench_reference_X;

/* Block states (auto storage) */
DW_testbench_reference_T testbench_reference_DW;

/* Real-time model */
RT_MODEL_testbench_reference_T testbench_reference_M_;
RT_MODEL_testbench_reference_T *const testbench_reference_M =
  &testbench_reference_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  testbench_reference_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  testbench_reference_output();
  testbench_reference_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  testbench_reference_output();
  testbench_reference_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void testbench_reference_output(void)
{
  int8_T tmp;
  real_T tmp_0;
  if (rtmIsMajorTimeStep(testbench_reference_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&testbench_reference_M->solverInfo,
                          ((testbench_reference_M->Timing.clockTick0+1)*
      testbench_reference_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(testbench_reference_M)) {
    testbench_reference_M->Timing.t[0] = rtsiGetT
      (&testbench_reference_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(testbench_reference_M)) {
    /* S-Function (ev3_encoder): '<Root>/Encoder' */
    testbench_reference_B.Position = getEncoderValueNoReset(1U);
  }

  /* Integrator: '<Root>/Integrator' */
  testbench_reference_B.Integrator = testbench_reference_X.Integrator_CSTATE;
  if (rtmIsMajorTimeStep(testbench_reference_M)) {
    /* SampleTimeMath: '<S1>/TSamp'
     *
     * About '<S1>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    testbench_reference_B.TSamp = (real_T)testbench_reference_P.TSamp_WtEt * 4.0
      * (real_T)testbench_reference_B.Position;

    /* Sum: '<S1>/Diff' incorporates:
     *  UnitDelay: '<S1>/UD'
     */
    testbench_reference_B.Diff = testbench_reference_B.TSamp -
      testbench_reference_DW.UD_DSTATE;

    /* FromWorkspace: '<S3>/FromWs' */
    {
      real_T *pDataValues = (real_T *)
        testbench_reference_DW.FromWs_PWORK.DataPtr;
      real_T *pTimeValues = (real_T *)
        testbench_reference_DW.FromWs_PWORK.TimePtr;
      int_T currTimeIndex = testbench_reference_DW.FromWs_IWORK.PrevIndex;
      real_T t = ((testbench_reference_M->Timing.clockTick1) * 0.01);

      /* Get index */
      if (t <= pTimeValues[0]) {
        currTimeIndex = 0;
      } else if (t >= pTimeValues[41]) {
        currTimeIndex = 40;
      } else {
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }
      }

      testbench_reference_DW.FromWs_IWORK.PrevIndex = currTimeIndex;

      /* Post output */
      {
        real_T t1 = pTimeValues[currTimeIndex];
        real_T t2 = pTimeValues[currTimeIndex + 1];
        if (t1 == t2) {
          if (t < t1) {
            testbench_reference_B.FromWs = pDataValues[currTimeIndex];
          } else {
            testbench_reference_B.FromWs = pDataValues[currTimeIndex + 1];
          }
        } else {
          real_T f1 = (t2 - t) / (t2 - t1);
          real_T f2 = 1.0 - f1;
          real_T d1;
          real_T d2;
          int_T TimeIndex= currTimeIndex;
          d1 = pDataValues[TimeIndex];
          d2 = pDataValues[TimeIndex + 1];
          testbench_reference_B.FromWs = (real_T) rtInterpolate(d1, d2, f1, f2);
          pDataValues += 42;
        }
      }
    }

    /* DataTypeConversion: '<S2>/Data Type Conversion' */
    tmp_0 = floor(testbench_reference_B.FromWs);
    if (tmp_0 < 128.0) {
      if (tmp_0 >= -128.0) {
        /* S-Function (ev3_motor): '<S2>/Motor' */
        tmp = (int8_T)tmp_0;
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
  }
}

/* Model update function */
void testbench_reference_update(void)
{
  if (rtmIsMajorTimeStep(testbench_reference_M)) {
    /* Update for UnitDelay: '<S1>/UD' */
    testbench_reference_DW.UD_DSTATE = testbench_reference_B.TSamp;
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(testbench_reference_M)!=-1) &&
        !((rtmGetTFinal(testbench_reference_M)-
           ((testbench_reference_M->Timing.clockTick1) * 0.01)) >
          ((testbench_reference_M->Timing.clockTick1) * 0.01) * (DBL_EPSILON)))
    {
      rtmSetErrorStatus(testbench_reference_M, "Simulation finished");
    }

    if (rtmGetStopRequested(testbench_reference_M)) {
      rtmSetErrorStatus(testbench_reference_M, "Simulation finished");
    }
  }

  if (rtmIsMajorTimeStep(testbench_reference_M)) {
    rt_ertODEUpdateContinuousStates(&testbench_reference_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ++testbench_reference_M->Timing.clockTick0;
  testbench_reference_M->Timing.t[0] = rtsiGetSolverStopTime
    (&testbench_reference_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    testbench_reference_M->Timing.clockTick1++;
  }
}

/* Derivatives for root system: '<Root>' */
void testbench_reference_derivatives(void)
{
  XDot_testbench_reference_T *_rtXdot;
  _rtXdot = ((XDot_testbench_reference_T *)
             testbench_reference_M->ModelData.derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = testbench_reference_B.Diff;
}

/* Model initialize function */
void testbench_reference_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)testbench_reference_M, 0,
                sizeof(RT_MODEL_testbench_reference_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&testbench_reference_M->solverInfo,
                          &testbench_reference_M->Timing.simTimeStep);
    rtsiSetTPtr(&testbench_reference_M->solverInfo, &rtmGetTPtr
                (testbench_reference_M));
    rtsiSetStepSizePtr(&testbench_reference_M->solverInfo,
                       &testbench_reference_M->Timing.stepSize0);
    rtsiSetdXPtr(&testbench_reference_M->solverInfo,
                 &testbench_reference_M->ModelData.derivs);
    rtsiSetContStatesPtr(&testbench_reference_M->solverInfo, (real_T **)
                         &testbench_reference_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&testbench_reference_M->solverInfo,
      &testbench_reference_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&testbench_reference_M->solverInfo,
                          (&rtmGetErrorStatus(testbench_reference_M)));
    rtsiSetRTModelPtr(&testbench_reference_M->solverInfo, testbench_reference_M);
  }

  rtsiSetSimTimeStep(&testbench_reference_M->solverInfo, MAJOR_TIME_STEP);
  testbench_reference_M->ModelData.intgData.y =
    testbench_reference_M->ModelData.odeY;
  testbench_reference_M->ModelData.intgData.f[0] =
    testbench_reference_M->ModelData.odeF[0];
  testbench_reference_M->ModelData.intgData.f[1] =
    testbench_reference_M->ModelData.odeF[1];
  testbench_reference_M->ModelData.intgData.f[2] =
    testbench_reference_M->ModelData.odeF[2];
  testbench_reference_M->ModelData.contStates = ((X_testbench_reference_T *)
    &testbench_reference_X);
  rtsiSetSolverData(&testbench_reference_M->solverInfo, (void *)
                    &testbench_reference_M->ModelData.intgData);
  rtsiSetSolverName(&testbench_reference_M->solverInfo,"ode3");
  rtmSetTPtr(testbench_reference_M, &testbench_reference_M->Timing.tArray[0]);
  rtmSetTFinal(testbench_reference_M, 25.0);
  testbench_reference_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  testbench_reference_M->Sizes.checksums[0] = (2255081123U);
  testbench_reference_M->Sizes.checksums[1] = (4136461115U);
  testbench_reference_M->Sizes.checksums[2] = (2426288193U);
  testbench_reference_M->Sizes.checksums[3] = (2617371367U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    testbench_reference_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(testbench_reference_M->extModeInfo,
      &testbench_reference_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(testbench_reference_M->extModeInfo,
                        testbench_reference_M->Sizes.checksums);
    rteiSetTPtr(testbench_reference_M->extModeInfo, rtmGetTPtr
                (testbench_reference_M));
  }

  /* block I/O */
  (void) memset(((void *) &testbench_reference_B), 0,
                sizeof(B_testbench_reference_T));

  /* states (continuous) */
  {
    (void) memset((void *)&testbench_reference_X, 0,
                  sizeof(X_testbench_reference_T));
  }

  /* states (dwork) */
  (void) memset((void *)&testbench_reference_DW, 0,
                sizeof(DW_testbench_reference_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    testbench_reference_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (ev3_encoder): '<Root>/Encoder' */
  initEncoder(1U);

  /* Start for FromWorkspace: '<S3>/FromWs' */
  {
    static real_T pTimeValues0[] = { 0.0, 1.0, 2.0, 2.0, 2.64, 2.64, 3.58, 3.58,
      5.0200000000000005, 5.0200000000000005, 6.0, 6.0, 7.38, 7.38, 8.72, 8.72,
      9.6000000000000014, 10.0, 10.0, 11.0, 11.0, 12.0, 12.0, 15.0, 15.0, 16.0,
      16.0, 17.0, 17.0, 19.0, 19.0, 20.0, 20.0, 21.0, 21.0, 22.0, 22.0, 23.5,
      23.5, 24.5, 24.5, 25.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 10.0, 0.0, -10.0, 0.0,
      25.0, 0.0, -25.0, 50.0, 50.0, -40.0, -40.0, 80.0, 80.0, 80.0, -90.0, -90.0,
      35.0, 35.0, 0.0, 0.0, 0.0, -20.0, -20.0, 40.0, -60.0, -60.0, 55.0, 55.0,
      0.0, 0.0, 0.0, -10.0, 30.0, 0.0, 80.0, 80.0, 0.0, -0.0 } ;

    testbench_reference_DW.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
    testbench_reference_DW.FromWs_PWORK.DataPtr = (void *) pDataValues0;
    testbench_reference_DW.FromWs_IWORK.PrevIndex = 0;
  }

  /* Start for S-Function (ev3_motor): '<S2>/Motor' */
  initMotor(1U);

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  testbench_reference_X.Integrator_CSTATE = testbench_reference_P.Integrator_IC;

  /* InitializeConditions for UnitDelay: '<S1>/UD' */
  testbench_reference_DW.UD_DSTATE =
    testbench_reference_P.DiscreteDerivative_ICPrevScaled;
}

/* Model terminate function */
void testbench_reference_terminate(void)
{
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
