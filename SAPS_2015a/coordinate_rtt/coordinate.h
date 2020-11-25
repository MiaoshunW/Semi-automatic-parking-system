/*
 * File: coordinate.h
 *
 * Code generated for Simulink model 'coordinate'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Fri Nov 25 15:58:45 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_coordinate_h_
#define RTW_HEADER_coordinate_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef coordinate_COMMON_INCLUDES_
# define coordinate_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "driver_ev3.h"
#endif                                 /* coordinate_COMMON_INCLUDES_ */

#include "coordinate_types.h"

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
  uint8_T Saturation;                  /* '<Root>/Saturation' */
} B_coordinate_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */
} DW_coordinate_T;

/* Parameters (auto storage) */
struct P_coordinate_T_ {
  real_T Constant_Value;               /* Expression: -25
                                        * Referenced by: '<Root>/Constant'
                                        */
  uint8_T Saturation_UpperSat;         /* Computed Parameter: Saturation_UpperSat
                                        * Referenced by: '<Root>/Saturation'
                                        */
  uint8_T Saturation_LowerSat;         /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<Root>/Saturation'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_coordinate_T {
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
extern P_coordinate_T coordinate_P;

/* Block signals (auto storage) */
extern B_coordinate_T coordinate_B;

/* Block states (auto storage) */
extern DW_coordinate_T coordinate_DW;

/* Model entry point functions */
extern void coordinate_initialize(void);
extern void coordinate_output(void);
extern void coordinate_update(void);
extern void coordinate_terminate(void);

/* Real-time Model object */
extern RT_MODEL_coordinate_T *const coordinate_M;

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
 * '<Root>' : 'coordinate'
 * '<S1>'   : 'coordinate/Motor'
 */
#endif                                 /* RTW_HEADER_coordinate_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
