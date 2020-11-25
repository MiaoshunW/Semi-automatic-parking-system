/*
 * File: testbench_Object_det_data.c
 *
 * Code generated for Simulink model 'testbench_Object_det'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Sat Dec 03 04:59:56 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "testbench_Object_det.h"
#include "testbench_Object_det_private.h"

/* Block parameters (auto storage) */
P_testbench_Object_det_T testbench_Object_det_P = {
  800.0,                               /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                        * Referenced by: '<S1>/UD'
                                        */
  30.0,                                /* Expression: 30
                                        * Referenced by: '<S5>/Constant'
                                        */
  36.0,                                /* Expression: 36
                                        * Referenced by: '<S5>/Constant1'
                                        */
  20.0,                                /* Expression: 20
                                        * Referenced by: '<Root>/Constant'
                                        */
  1731841652,                          /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  25                                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S1>/TSamp'
                                        */
};

/* Constant parameters (auto storage) */
const ConstP_testbench_Object_det_T testbench_Object_det_ConstP = {
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
