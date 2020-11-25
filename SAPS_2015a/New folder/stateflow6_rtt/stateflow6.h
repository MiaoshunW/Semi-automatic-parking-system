/*
 * File: stateflow6.h
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

#ifndef RTW_HEADER_stateflow6_h_
#define RTW_HEADER_stateflow6_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef stateflow6_COMMON_INCLUDES_
# define stateflow6_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "driver_ev3.h"
#endif                                 /* stateflow6_COMMON_INCLUDES_ */

#include "stateflow6_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Child system includes */
#include "ObjDetn_private.h"
#include "ObjDetn.h"
#include "ParkDetn_private.h"
#include "ParkDetn.h"
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
  real_T Constant2;                    /* '<Root>/Constant2' */
  real_T DataTypeConversion1;          /* '<Root>/Data Type Conversion1' */
  real_T Encoder;                      /* '<Root>/Gain1' */
  real_T Delay2;                       /* '<Root>/Delay2' */
  real_T Constant1;                    /* '<Root>/Constant1' */
  real_T Constant;                     /* '<Root>/Constant' */
  real_T UltrDiff;                     /* '<Root>/Add1' */
  real_T DataTypeConversion1_a;        /* '<S4>/Data Type Conversion1' */
  real_T DataTypeConversion;           /* '<S4>/Data Type Conversion' */
  real_T DataTypeConversion1_ao;       /* '<S3>/Data Type Conversion1' */
  real_T DataTypeConversion_h;         /* '<S3>/Data Type Conversion' */
  real_T Motor;                        /* '<Root>/Chart' */
  real_T state_nr;                     /* '<Root>/Chart' */
  ChartModeType ChartMode;             /* '<Root>/Chart' */
  int8_T DataTypeConversion3;          /* '<Root>/Data Type Conversion3' */
} B_stateflow6_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Delay2_DSTATE;                /* '<Root>/Delay2' */
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<Root>/To Workspace1' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<Root>/To Workspace2' */

  struct {
    void *LoggedData;
  } state_nr_PWORK;                    /* '<Root>/state_nr' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S4>/Scope' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK_c;              /* '<S4>/To Workspace2' */

  struct {
    void *LoggedData;
  } Scope_PWORK_c;                     /* '<S3>/Scope' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK_k;              /* '<S3>/To Workspace2' */

  int32_T sfEvent;                     /* '<Root>/Chart' */
  int8_T Delay1_DSTATE;                /* '<Root>/Delay1' */
  int8_T ObjectDetection_SubsysRanBC;  /* '<Root>/Object Detection' */
  int8_T ParkingSpaceDetection_SubsysRan;/* '<Root>/Parking Space Detection' */
  uint8_T is_active_c3_stateflow6;     /* '<Root>/Chart' */
  uint8_T temporalCounter_i1;          /* '<Root>/Chart' */
  boolean_T isStable;                  /* '<Root>/Chart' */
} DW_stateflow6_T;

/* Parameters (auto storage) */
struct P_stateflow6_T_ {
  real_T ObjLength;                    /* Variable: ObjLength
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T ParkLength;                   /* Variable: ParkLength
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 30
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/9.92
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<Root>/Delay2'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<Root>/Delay'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<Root>/Delay1'
                                        */
  uint32_T Delay2_DelayLength;         /* Computed Parameter: Delay2_DelayLength
                                        * Referenced by: '<Root>/Delay2'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<Root>/Delay'
                                        */
  int8_T Delay1_InitialCondition;      /* Computed Parameter: Delay1_InitialCondition
                                        * Referenced by: '<Root>/Delay1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_stateflow6_T {
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
extern P_stateflow6_T stateflow6_P;

/* Block signals (auto storage) */
extern B_stateflow6_T stateflow6_B;

/* Block states (auto storage) */
extern DW_stateflow6_T stateflow6_DW;

/* Model entry point functions */
extern void stateflow6_initialize(void);
extern void stateflow6_output(void);
extern void stateflow6_update(void);
extern void stateflow6_terminate(void);

/* Real-time Model object */
extern RT_MODEL_stateflow6_T *const stateflow6_M;

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
 * '<Root>' : 'stateflow6'
 * '<S1>'   : 'stateflow6/Chart'
 * '<S2>'   : 'stateflow6/Motor'
 * '<S3>'   : 'stateflow6/Object Detection'
 * '<S4>'   : 'stateflow6/Parking Space Detection'
 * '<S5>'   : 'stateflow6/Object Detection/MATLAB Function'
 * '<S6>'   : 'stateflow6/Parking Space Detection/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_stateflow6_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
