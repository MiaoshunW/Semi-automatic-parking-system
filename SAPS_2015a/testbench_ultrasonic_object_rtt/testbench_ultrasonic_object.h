/*
 * File: testbench_ultrasonic_object.h
 *
 * Code generated for Simulink model 'testbench_ultrasonic_object'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Sat Dec 03 02:01:41 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_testbench_ultrasonic_object_h_
#define RTW_HEADER_testbench_ultrasonic_object_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef testbench_ultrasonic_object_COMMON_INCLUDES_
# define testbench_ultrasonic_object_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "driver_ev3.h"
#endif                                 /* testbench_ultrasonic_object_COMMON_INCLUDES_ */

#include "testbench_ultrasonic_object_types.h"

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
  uint8_T Compare;                     /* '<S2>/Compare' */
} B_testbench_ultrasonic_object_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */
} DW_testbench_ultrasonic_objec_T;

/* Parameters (auto storage) */
struct P_testbench_ultrasonic_object_T_ {
  uint8_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S1>/Constant'
                                        */
  uint8_T CompareToConstant1_const;    /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant_Value;               /* Expression: 20
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_testbench_ultrasonic__T {
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
extern P_testbench_ultrasonic_object_T testbench_ultrasonic_object_P;

/* Block signals (auto storage) */
extern B_testbench_ultrasonic_object_T testbench_ultrasonic_object_B;

/* Block states (auto storage) */
extern DW_testbench_ultrasonic_objec_T testbench_ultrasonic_object_DW;

/* Model entry point functions */
extern void testbench_ultrasonic_object_initialize(void);
extern void testbench_ultrasonic_object_output(void);
extern void testbench_ultrasonic_object_update(void);
extern void testbench_ultrasonic_object_terminate(void);

/* Real-time Model object */
extern RT_MODEL_testbench_ultrasonic_T *const testbench_ultrasonic_object_M;

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
 * '<Root>' : 'testbench_ultrasonic_object'
 * '<S1>'   : 'testbench_ultrasonic_object/Compare To Constant'
 * '<S2>'   : 'testbench_ultrasonic_object/Compare To Constant1'
 * '<S3>'   : 'testbench_ultrasonic_object/Motor'
 */
#endif                                 /* RTW_HEADER_testbench_ultrasonic_object_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
