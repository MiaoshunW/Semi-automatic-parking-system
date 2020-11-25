/*
 * simulink_function_dt.h
 *
 * Code generation for model "simulink_function".
 *
 * Model version              : 1.6
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Sat Jan 14 01:16:25 2017
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
  2*sizeof(uint32_T)
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
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&simulink_function_B.ObjLengthMin), 0, 0, 40 },

  { (char_T *)(&simulink_function_B.DataTypeConversion3), 2, 0, 1 },

  { (char_T *)(&simulink_function_B.ObjDetn2.rearmotor), 0, 0, 1 },

  { (char_T *)(&simulink_function_B.ObjDetn.rearmotor), 0, 0, 1 }
  ,

  { (char_T *)(&simulink_function_DW.Delay2_DSTATE), 0, 0, 2 },

  { (char_T *)(&simulink_function_DW.Scope_PWORK.LoggedData), 11, 0, 7 },

  { (char_T *)(&simulink_function_DW.sfEvent), 6, 0, 1 },

  { (char_T *)(&simulink_function_DW.FromWs_IWORK.PrevIndex), 10, 0, 2 },

  { (char_T *)(&simulink_function_DW.Delay1_DSTATE), 2, 0, 3 },

  { (char_T *)(&simulink_function_DW.is_active_c3_simulink_function), 3, 0, 4 },

  { (char_T *)(&simulink_function_DW.isStable), 8, 0, 1 },

  { (char_T *)(&simulink_function_DW.ObjDetn2.ObjDetn_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&simulink_function_DW.ObjDetn.ObjDetn_SubsysRanBC), 2, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  13U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&simulink_function_P.ObjCarGapMax), 0, 0, 17 },

  { (char_T *)(&simulink_function_P.Delay2_DelayLength), 7, 0, 3 },

  { (char_T *)(&simulink_function_P.Delay1_InitialCondition), 2, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] simulink_function_dt.h */
