/*
 * File: testbench_encoder.h
 *
 * Code generated for Simulink model 'testbench_encoder'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Fri Dec 09 19:48:50 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_testbench_encoder_h_
#define RTW_HEADER_testbench_encoder_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef testbench_encoder_COMMON_INCLUDES_
# define testbench_encoder_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "driver_ev3.h"
#endif                                 /* testbench_encoder_COMMON_INCLUDES_ */

#include "testbench_encoder_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Gain1;                        /* '<Root>/Gain1' */
  int8_T DataTypeConversion1;          /* '<Root>/Data Type Conversion1' */
} B_testbench_encoder_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  int8_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
} DW_testbench_encoder_T;

/* Parameters (auto storage) */
struct P_testbench_encoder_T_ {
  real_T Gain1_Gain;                   /* Expression: 1/9.92
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Motor_power_Value;            /* Expression: 20
                                        * Referenced by: '<Root>/Motor_power'
                                        */
  int8_T UnitDelay_InitialCondition;   /* Computed Parameter: UnitDelay_InitialCondition
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_testbench_encoder_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_testbench_encoder_T testbench_encoder_P;

/* Block signals (auto storage) */
extern B_testbench_encoder_T testbench_encoder_B;

/* Block states (auto storage) */
extern DW_testbench_encoder_T testbench_encoder_DW;

/* Model entry point functions */
extern void testbench_encoder_initialize(void);
extern void testbench_encoder_output(void);
extern void testbench_encoder_update(void);
extern void testbench_encoder_terminate(void);

/* Real-time Model object */
extern RT_MODEL_testbench_encoder_T *const testbench_encoder_M;

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
 * '<Root>' : 'testbench_encoder'
 * '<S1>'   : 'testbench_encoder/Display1'
 * '<S2>'   : 'testbench_encoder/Encoder_function'
 * '<S3>'   : 'testbench_encoder/Motor'
 */
#endif                                 /* RTW_HEADER_testbench_encoder_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
