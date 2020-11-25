/*
 * File: simulink_function_private.h
 *
 * Code generated for Simulink model 'simulink_function'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Sat Jan 14 01:16:25 2017
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_simulink_function_private_h_
#define RTW_HEADER_simulink_function_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* Used by FromWorkspace Block: '<S16>/FromWs' */
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
#endif

extern void simulink_function_ObjDetn(real_T rtu_motor_input, real_T
  rtu_UltrSnsr, B_ObjDetn_simulink_function_T *localB,
  DW_ObjDetn_simulink_function_T *localDW);

#endif                                 /* RTW_HEADER_simulink_function_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
