/*
 * File: untitled_data.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Tue Jan 31 19:07:26 2017
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_private.h"

/* Block parameters (auto storage) */
P_untitled_T untitled_P = {
  /*  Mask Parameter: RepeatingSequenceStair_OutValue
   * Referenced by: '<S1>/Vector'
   */
  { 3.0, 1.0, 4.0, 2.0, 1.0 },
  50U,                                 /* Mask Parameter: Speaker_speakerVolume
                                        * Referenced by: '<S2>/Speaker'
                                        */
  4U,                                  /* Mask Parameter: LimitedCounter_uplimit
                                        * Referenced by: '<S5>/FixPt Switch'
                                        */
  100U,                                /* Computed Parameter: Speaker_p2
                                        * Referenced by: '<S2>/Speaker'
                                        */
  100U,                                /* Computed Parameter: Speaker_p4
                                        * Referenced by: '<S2>/Speaker'
                                        */
  0U,                                  /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S5>/Constant'
                                        */
  0U,                                  /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S3>/Output'
                                        */
  1U,                                  /* Computed Parameter: Speaker_p1
                                        * Referenced by: '<S2>/Speaker'
                                        */
  1U                                   /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S4>/FixPt Constant'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
