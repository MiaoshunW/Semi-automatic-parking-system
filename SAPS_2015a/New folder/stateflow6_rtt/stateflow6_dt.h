/*
 * stateflow6_dt.h
 *
 * Code generation for model "stateflow6".
 *
 * Model version              : 1.100
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Wed Jan 04 19:39:34 2017
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(ChartModeType)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "ChartModeType"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&stateflow6_B.Constant2), 0, 0, 13 },

  { (char_T *)(&stateflow6_B.ChartMode), 14, 0, 1 },

  { (char_T *)(&stateflow6_B.DataTypeConversion3), 2, 0, 1 }
  ,

  { (char_T *)(&stateflow6_DW.Delay2_DSTATE), 0, 0, 2 },

  { (char_T *)(&stateflow6_DW.ToWorkspace1_PWORK.LoggedData), 11, 0, 7 },

  { (char_T *)(&stateflow6_DW.sfEvent), 6, 0, 1 },

  { (char_T *)(&stateflow6_DW.Delay1_DSTATE), 2, 0, 3 },

  { (char_T *)(&stateflow6_DW.is_active_c3_stateflow6), 3, 0, 2 },

  { (char_T *)(&stateflow6_DW.isStable), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  9U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&stateflow6_P.ObjLength), 0, 0, 6 },

  { (char_T *)(&stateflow6_P.Delay1_DelayLength), 7, 0, 3 },

  { (char_T *)(&stateflow6_P.Delay1_InitialCondition), 2, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] stateflow6_dt.h */
