/*
 * File: model2.c
 *
 * Code generated for Simulink model 'model2'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Tue Oct 18 16:10:31 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "model2.h"
#include "model2_private.h"

/* Block signals (auto storage) */
B_model2_T model2_B;

/* Real-time model */
RT_MODEL_model2_T model2_M_;
RT_MODEL_model2_T *const model2_M = &model2_M_;

/* Model output function */
void model2_output(void)
{
  real_T currentTime;
  int8_T tmp;

  /* Step: '<Root>/Step' */
  currentTime = model2_M->Timing.t[0];
  if (currentTime < model2_P.Step_Time) {
    /* DataTypeConversion: '<S1>/Data Type Conversion' */
    currentTime = floor(model2_P.Step_Y0);
    if (currentTime < 128.0) {
      if (currentTime >= -128.0) {
        model2_B.DataTypeConversion = (int8_T)currentTime;
      } else {
        model2_B.DataTypeConversion = MIN_int8_T;
      }
    } else {
      model2_B.DataTypeConversion = MAX_int8_T;
    }
  } else {
    /* DataTypeConversion: '<S1>/Data Type Conversion' */
    currentTime = floor(model2_P.Step_YFinal);
    if (currentTime < 128.0) {
      if (currentTime >= -128.0) {
        model2_B.DataTypeConversion = (int8_T)currentTime;
      } else {
        model2_B.DataTypeConversion = MIN_int8_T;
      }
    } else {
      model2_B.DataTypeConversion = MAX_int8_T;
    }
  }

  /* End of Step: '<Root>/Step' */

  /* S-Function (ev3_motor): '<S1>/Motor' */
  tmp = model2_B.DataTypeConversion;
  setMotor(&tmp, 2U, 2U);
}

/* Model update function */
void model2_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  model2_M->Timing.t[0] =
    (++model2_M->Timing.clockTick0) * model2_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.2, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    model2_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void model2_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)model2_M, 0,
                sizeof(RT_MODEL_model2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&model2_M->solverInfo, &model2_M->Timing.simTimeStep);
    rtsiSetTPtr(&model2_M->solverInfo, &rtmGetTPtr(model2_M));
    rtsiSetStepSizePtr(&model2_M->solverInfo, &model2_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&model2_M->solverInfo, ((const char_T **)
      (&rtmGetErrorStatus(model2_M))));
    rtsiSetRTModelPtr(&model2_M->solverInfo, model2_M);
  }

  rtsiSetSimTimeStep(&model2_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&model2_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(model2_M, &model2_M->Timing.tArray[0]);
  model2_M->Timing.stepSize0 = 0.2;

  /* block I/O */
  (void) memset(((void *) &model2_B), 0,
                sizeof(B_model2_T));

  /* Start for S-Function (ev3_motor): '<S1>/Motor' */
  initMotor(2U);
}

/* Model terminate function */
void model2_terminate(void)
{
  /* Terminate for S-Function (ev3_motor): '<S1>/Motor' */
  terminateMotor(2U, 2U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
