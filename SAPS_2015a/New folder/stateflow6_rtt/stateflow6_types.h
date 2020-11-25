/*
 * File: stateflow6_types.h
 *
 * Code generated for Simulink model 'stateflow6'.
 *
 * Model version                  : 1.100
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Wed Jan 04 19:39:34 2017
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_stateflow6_types_h_
#define RTW_HEADER_stateflow6_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef _DEFINED_TYPEDEF_FOR_ChartModeType_
#define _DEFINED_TYPEDEF_FOR_ChartModeType_

typedef enum {
  ChartModeType_None = 0,              /* Default value */
  ChartModeType_First_Object,
  ChartModeType_Park_Space,
  ChartModeType_Second_Object,
  ChartModeType_Stop_motor
} ChartModeType;

#endif

/* Parameters (auto storage) */
typedef struct P_stateflow6_T_ P_stateflow6_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_stateflow6_T RT_MODEL_stateflow6_T;

#endif                                 /* RTW_HEADER_stateflow6_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
