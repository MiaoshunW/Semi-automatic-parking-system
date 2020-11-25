/*
 * File: model21.h
 *
 * Code generated for Simulink model 'model21'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Tue Oct 18 16:44:06 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_model21_h_
#define RTW_HEADER_model21_h_
#include <math.h>
#include <stddef.h>
#ifndef model21_COMMON_INCLUDES_
# define model21_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "driver_ev3.h"
#endif                                 /* model21_COMMON_INCLUDES_ */

#include "model21_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Parameters (auto storage) */
struct P_model21_T_ {
  real_T Constant1_Value;              /* Expression: 10
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 60
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 200
                                        * Referenced by: '<Root>/Switch'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_model21_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_model21_T model21_P;

/* Model entry point functions */
extern void model21_initialize(void);
extern void model21_output(void);
extern void model21_update(void);
extern void model21_terminate(void);

/* Real-time Model object */
extern RT_MODEL_model21_T *const model21_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'model21'
 * '<S1>'   : 'model21/Motor1'
 */
#endif                                 /* RTW_HEADER_model21_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
