/*
 * File: testbench_state2.h
 *
 * Code generated for Simulink model 'testbench_state2'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Tue Jan 31 18:07:05 2017
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_testbench_state2_h_
#define RTW_HEADER_testbench_state2_h_
#include <math.h>
#include <stddef.h>
#ifndef testbench_state2_COMMON_INCLUDES_
# define testbench_state2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "driver_ev3.h"
#endif                                 /* testbench_state2_COMMON_INCLUDES_ */

#include "testbench_state2_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Parameters (auto storage) */
struct P_testbench_state2_T_ {
  real_T Motor_power_Value;            /* Expression: 20
                                        * Referenced by: '<Root>/Motor_power'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_testbench_state2_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_testbench_state2_T testbench_state2_P;

/* Model entry point functions */
extern void testbench_state2_initialize(void);
extern void testbench_state2_output(void);
extern void testbench_state2_update(void);
extern void testbench_state2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_testbench_state2_T *const testbench_state2_M;

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
 * '<Root>' : 'testbench_state2'
 * '<S1>'   : 'testbench_state2/Motor'
 * '<S2>'   : 'testbench_state2/Parking_Detection'
 * '<S3>'   : 'testbench_state2/Status Light'
 */
#endif                                 /* RTW_HEADER_testbench_state2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
