/*
 * File: simulink_function_data.c
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

#include "simulink_function.h"
#include "simulink_function_private.h"

/* Block parameters (auto storage) */
P_simulink_function_T simulink_function_P = {
  20.0,                                /* Variable: ObjCarGapMax
                                        * Referenced by: '<S1>/ObjCarGapMax'
                                        */
  4.0,                                 /* Variable: ObjCarGapMin
                                        * Referenced by: '<S1>/ObjCarGapMin'
                                        */
  35.0,                                /* Variable: ObjLengthMax
                                        * Referenced by: '<S1>/ObjLengthMax'
                                        */
  25.0,                                /* Variable: ObjLengthMin
                                        * Referenced by: '<S1>/ObjLengthMin'
                                        */
  2.0,                                 /* Variable: ObjUltrSnsrOffset
                                        * Referenced by: '<S1>/ObjUltrSnsrOffset'
                                        */
  40.0,                                /* Variable: ParkCarDepthMax
                                        * Referenced by: '<S1>/ParkCarDepthMax'
                                        */
  24.0,                                /* Variable: ParkCarDepthMin
                                        * Referenced by: '<S1>/ParkCarDepthMin'
                                        */
  46.0,                                /* Variable: ParkLengthMax
                                        * Referenced by: '<S1>/ParkLengthMax'
                                        */
  35.0,                                /* Variable: ParkLengthMin
                                        * Referenced by: '<S1>/ParkLengthMin'
                                        */
  5.0,                                 /* Variable: ParkUltrSnsrOffset
                                        * Referenced by: '<S1>/ParkUltrSnsrOffset'
                                        */
  9.92,                                /* Expression: 9.92
                                        * Referenced by: '<S9>/Gain'
                                        */
  30.0,                                /* Expression: 30
                                        * Referenced by: '<Root>/motor_input'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Delay2'
                                        */
  0.10080645161290323,                 /* Expression: 1/9.92
                                        * Referenced by: '<S4>/Gain1'
                                        */
  0.10080645161290323,                 /* Expression: 1/9.92
                                        * Referenced by: '<S4>/Gain2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/motor_zero'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay2_DelayLength
                                        * Referenced by: '<S4>/Delay2'
                                        */
  1U,                                  /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S4>/Delay1'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S4>/Delay'
                                        */
  0                                    /* Computed Parameter: Delay1_InitialCondition
                                        * Referenced by: '<S4>/Delay1'
                                        */
};

/* Constant parameters (auto storage) */
const ConstP_simulink_function_T simulink_function_ConstP = {
  /* Expression: lcdStr1
   * Referenced by: '<S14>/LCD'
   */
  { 101U, 110U, 99U, 32U, 65U, 0U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
