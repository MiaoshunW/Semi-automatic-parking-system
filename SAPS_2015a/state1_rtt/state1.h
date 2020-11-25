/*
 * File: state1.h
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

#ifndef RTW_HEADER_state1_h_
#define RTW_HEADER_state1_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef state1_COMMON_INCLUDES_
# define state1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "driver_ev3.h"
#endif                                 /* state1_COMMON_INCLUDES_ */

#include "state1_types.h"

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
  real_T Diff;                         /* '<S5>/Diff' */
  real_T rearmotor;                    /* '<S4>/MATLAB Function' */
  int32_T Position;                    /* '<Root>/Encoder' */
  uint8_T UltrasonicSensor;            /* '<Root>/Ultrasonic Sensor' */
  boolean_T RelationalOperator;        /* '<S7>/Relational Operator' */
  boolean_T RelationalOperator1;       /* '<S7>/Relational Operator1' */
  boolean_T LogicalOperator;           /* '<S4>/Logical Operator' */
} B_state1_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S5>/UD' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  int32_T sfEvent;                     /* '<Root>/Chart' */
  uint32_T Park_ELAPS_T;               /* '<Root>/Park' */
  uint32_T Park_PREV_T;                /* '<Root>/Park' */
  int8_T Park_SubsysRanBC;             /* '<Root>/Park' */
  uint8_T is_active_c3_state1;         /* '<Root>/Chart' */
  uint8_T is_c3_state1;                /* '<Root>/Chart' */
  boolean_T isStable;                  /* '<Root>/Chart' */
} DW_state1_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: lcdStr1
   * Referenced by: '<S2>/LCD'
   */
  uint8_T LCD_p1[8];
} ConstP_state1_T;

/* Parameters (auto storage) */
struct P_state1_T_ {
  real_T DiscreteDerivative_ICPrevScaled;/* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                          * Referenced by: '<S5>/UD'
                                          */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S5>/TSamp'
                                        */
  real_T Constant_Value;               /* Expression: 30
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 36
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Constant1_Value_h;            /* Expression: 20
                                        * Referenced by: '<Root>/Constant1'
                                        */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S4>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_state1_T {
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
extern P_state1_T state1_P;

/* Block signals (auto storage) */
extern B_state1_T state1_B;

/* Block states (auto storage) */
extern DW_state1_T state1_DW;

/* Constant parameters (auto storage) */
extern const ConstP_state1_T state1_ConstP;

/* Model entry point functions */
extern void state1_initialize(void);
extern void state1_output(void);
extern void state1_update(void);
extern void state1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_state1_T *const state1_M;

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
 * '<Root>' : 'state1'
 * '<S1>'   : 'state1/Chart'
 * '<S2>'   : 'state1/Display2'
 * '<S3>'   : 'state1/Motor2'
 * '<S4>'   : 'state1/Park'
 * '<S5>'   : 'state1/Park/Discrete Derivative'
 * '<S6>'   : 'state1/Park/MATLAB Function'
 * '<S7>'   : 'state1/Park/Subsystem'
 */
#endif                                 /* RTW_HEADER_state1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
