/*
 * File: state1_data.c
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

/* Block parameters (auto storage) */
P_state1_T state1_P = {
  800.0,                               /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                        * Referenced by: '<S5>/UD'
                                        */
  1.0,                                 /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S5>/TSamp'
                                        */
  30.0,                                /* Expression: 30
                                        * Referenced by: '<S7>/Constant'
                                        */
  36.0,                                /* Expression: 36
                                        * Referenced by: '<S7>/Constant1'
                                        */
  20.0,                                /* Expression: 20
                                        * Referenced by: '<Root>/Constant1'
                                        */
  1731841652                           /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S4>/Gain'
                                        */
};

/* Constant parameters (auto storage) */
const ConstP_state1_T state1_ConstP = {
  /* Expression: lcdStr1
   * Referenced by: '<S2>/LCD'
   */
  { 79U, 98U, 106U, 95U, 68U, 101U, 116U, 0U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
