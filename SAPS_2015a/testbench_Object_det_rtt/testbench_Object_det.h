/*
 * File: testbench_Object_det.h
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

#ifndef RTW_HEADER_testbench_Object_det_h_
#define RTW_HEADER_testbench_Object_det_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef testbench_Object_det_COMMON_INCLUDES_
# define testbench_Object_det_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "driver_ev3.h"
#endif                                 /* testbench_Object_det_COMMON_INCLUDES_ */

#include "testbench_Object_det_types.h"

/* Shared type includes */
#include "multiword_types.h"

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
  real_T TSamp;                        /* '<S1>/TSamp' */
  real_T Diff;                         /* '<S1>/Diff' */
  int32_T Position;                    /* '<Root>/Encoder' */
  boolean_T RelationalOperator;        /* '<S5>/Relational Operator' */
  boolean_T RelationalOperator1;       /* '<S5>/Relational Operator1' */
  boolean_T LogicalOperator;           /* '<Root>/Logical Operator' */
} B_testbench_Object_det_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S1>/UD' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_testbench_Object_det_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: lcdStr1
   * Referenced by: '<S2>/LCD'
   */
  uint8_T LCD_p1[8];
} ConstP_testbench_Object_det_T;

/* Parameters (auto storage) */
struct P_testbench_Object_det_T_ {
  real_T DiscreteDerivative_ICPrevScaled;/* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                          * Referenced by: '<S1>/UD'
                                          */
  real_T Constant_Value;               /* Expression: 30
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 36
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Constant_Value_k;             /* Expression: 20
                                        * Referenced by: '<Root>/Constant'
                                        */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  int32_T TSamp_WtEt;                  /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S1>/TSamp'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_testbench_Object_det_T {
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
extern P_testbench_Object_det_T testbench_Object_det_P;

/* Block signals (auto storage) */
extern B_testbench_Object_det_T testbench_Object_det_B;

/* Block states (auto storage) */
extern DW_testbench_Object_det_T testbench_Object_det_DW;

/* Constant parameters (auto storage) */
extern const ConstP_testbench_Object_det_T testbench_Object_det_ConstP;

/* Model entry point functions */
extern void testbench_Object_det_initialize(void);
extern void testbench_Object_det_output(void);
extern void testbench_Object_det_update(void);
extern void testbench_Object_det_terminate(void);

/* Real-time Model object */
extern RT_MODEL_testbench_Object_det_T *const testbench_Object_det_M;

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
 * '<Root>' : 'testbench_Object_det'
 * '<S1>'   : 'testbench_Object_det/Discrete Derivative'
 * '<S2>'   : 'testbench_Object_det/Display2'
 * '<S3>'   : 'testbench_Object_det/MATLAB Function'
 * '<S4>'   : 'testbench_Object_det/Motor'
 * '<S5>'   : 'testbench_Object_det/Subsystem'
 */
#endif                                 /* RTW_HEADER_testbench_Object_det_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
