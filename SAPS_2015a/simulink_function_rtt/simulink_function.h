/*
 * File: simulink_function.h
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

#ifndef RTW_HEADER_simulink_function_h_
#define RTW_HEADER_simulink_function_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef simulink_function_COMMON_INCLUDES_
# define simulink_function_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "driver_ev3.h"
#endif                                 /* simulink_function_COMMON_INCLUDES_ */

#include "simulink_function_types.h"

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

/* Block signals for system '<S5>/ObjDetn' */
typedef struct {
  real_T rearmotor;                    /* '<S6>/MATLAB Function' */
} B_ObjDetn_simulink_function_T;

/* Block states (auto storage) for system '<S5>/ObjDetn' */
typedef struct {
  int8_T ObjDetn_SubsysRanBC;          /* '<S5>/ObjDetn' */
} DW_ObjDetn_simulink_function_T;

/* Block signals (auto storage) */
typedef struct {
  real_T ObjLengthMin;                 /* '<S1>/ObjLengthMin' */
  real_T ObjLengthMax;                 /* '<S1>/ObjLengthMax' */
  real_T ObjCarGapMin;                 /* '<S1>/ObjCarGapMin' */
  real_T ObjCarGapMax;                 /* '<S1>/ObjCarGapMax' */
  real_T ParkLengthMin;                /* '<S1>/ParkLengthMin' */
  real_T ParkLengthMax;                /* '<S1>/ParkLengthMax' */
  real_T ParkCarDepthMin;              /* '<S1>/ParkCarDepthMin' */
  real_T ParkCarDepthMax;              /* '<S1>/ParkCarDepthMax' */
  real_T ParkUltrSnsrOffset;           /* '<S1>/ParkUltrSnsrOffset' */
  real_T ObjUltrSnsrOffset;            /* '<S1>/ObjUltrSnsrOffset' */
  real_T motor_input;                  /* '<Root>/motor_input' */
  real_T UltrSnsr;                     /* '<S4>/Data Type Conversion1' */
  real_T Delay2;                       /* '<S4>/Delay2' */
  real_T EncoderA;                     /* '<S4>/Gain1' */
  real_T Gain2;                        /* '<S4>/Gain2' */
  real_T motor_zero;                   /* '<Root>/motor_zero' */
  real_T UltrDiff;                     /* '<S4>/Add1' */
  real_T Motor;                        /* '<S4>/SAPS Brain' */
  real_T state_nr;                     /* '<S4>/SAPS Brain' */
  real_T MotorB1;                      /* '<S4>/SAPS Brain' */
  real_T motor_input_p;                /* '<S4>/SAPS Brain' */
  real_T UltrSnsr_m;                   /* '<S4>/SAPS Brain' */
  real_T Encoder;                      /* '<S4>/SAPS Brain' */
  real_T UltrSnsrPrv;                  /* '<S4>/SAPS Brain' */
  real_T EncoderB;                     /* '<S4>/SAPS Brain' */
  real_T Encoder_p;                    /* '<S4>/SAPS Brain' */
  real_T motor_input_c;                /* '<S4>/SAPS Brain' */
  real_T UltrSnsr_g;                   /* '<S4>/SAPS Brain' */
  real_T Encoder_h;                    /* '<S4>/SAPS Brain' */
  real_T UltrSnsrPrv_p;                /* '<S4>/SAPS Brain' */
  real_T motor_input_n;                /* '<S4>/SAPS Brain' */
  real_T UltrSnsr_n;                   /* '<S4>/SAPS Brain' */
  real_T Encoder_i;                    /* '<S4>/SAPS Brain' */
  real_T UltrSnsrPrv_o;                /* '<S4>/SAPS Brain' */
  real_T DataTypeConversion1;          /* '<S8>/Data Type Conversion1' */
  real_T DataTypeConversion;           /* '<S8>/Data Type Conversion' */
  real_T rearmotor;                    /* '<S8>/MATLAB Function' */
  real_T Gain;                         /* '<S9>/Gain' */
  real_T Motor_power_A;                /* '<S9>/rear_wheel_ function' */
  real_T Motor_power_B;                /* '<S9>/ Steering_Function' */
  int8_T DataTypeConversion3;          /* '<S4>/Data Type Conversion3' */
  B_ObjDetn_simulink_function_T ObjDetn2;/* '<S5>/ObjDetn2' */
  B_ObjDetn_simulink_function_T ObjDetn;/* '<S5>/ObjDetn' */
} B_simulink_function_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Delay2_DSTATE;                /* '<S4>/Delay2' */
  real_T Delay_DSTATE;                 /* '<S4>/Delay' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<S4>/To Workspace1' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<S4>/To Workspace2' */

  struct {
    void *LoggedData;
  } Scope_PWORK_i;                     /* '<S8>/Scope' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK_p;              /* '<S8>/To Workspace2' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK;                      /* '<S16>/FromWs' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK_e;                    /* '<S15>/FromWs' */

  int32_T sfEvent;                     /* '<S4>/SAPS Brain' */
  struct {
    int_T PrevIndex;
  } FromWs_IWORK;                      /* '<S16>/FromWs' */

  struct {
    int_T PrevIndex;
  } FromWs_IWORK_d;                    /* '<S15>/FromWs' */

  int8_T Delay1_DSTATE;                /* '<S4>/Delay1' */
  int8_T ThreeCmPark_SubsysRanBC;      /* '<S5>/ThreeCmPark' */
  int8_T ParkDetn_SubsysRanBC;         /* '<S5>/ParkDetn' */
  uint8_T is_active_c3_simulink_function;/* '<S4>/SAPS Brain' */
  uint8_T is_c3_simulink_function;     /* '<S4>/SAPS Brain' */
  uint8_T is_Parking_s;                /* '<S4>/SAPS Brain' */
  uint8_T temporalCounter_i1;          /* '<S4>/SAPS Brain' */
  boolean_T isStable;                  /* '<S4>/SAPS Brain' */
  DW_ObjDetn_simulink_function_T ObjDetn2;/* '<S5>/ObjDetn2' */
  DW_ObjDetn_simulink_function_T ObjDetn;/* '<S5>/ObjDetn' */
} DW_simulink_function_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: lcdStr1
   * Referenced by: '<S14>/LCD'
   */
  uint8_T LCD_p1[6];
} ConstP_simulink_function_T;

/* Parameters (auto storage) */
struct P_simulink_function_T_ {
  real_T ObjCarGapMax;                 /* Variable: ObjCarGapMax
                                        * Referenced by: '<S1>/ObjCarGapMax'
                                        */
  real_T ObjCarGapMin;                 /* Variable: ObjCarGapMin
                                        * Referenced by: '<S1>/ObjCarGapMin'
                                        */
  real_T ObjLengthMax;                 /* Variable: ObjLengthMax
                                        * Referenced by: '<S1>/ObjLengthMax'
                                        */
  real_T ObjLengthMin;                 /* Variable: ObjLengthMin
                                        * Referenced by: '<S1>/ObjLengthMin'
                                        */
  real_T ObjUltrSnsrOffset;            /* Variable: ObjUltrSnsrOffset
                                        * Referenced by: '<S1>/ObjUltrSnsrOffset'
                                        */
  real_T ParkCarDepthMax;              /* Variable: ParkCarDepthMax
                                        * Referenced by: '<S1>/ParkCarDepthMax'
                                        */
  real_T ParkCarDepthMin;              /* Variable: ParkCarDepthMin
                                        * Referenced by: '<S1>/ParkCarDepthMin'
                                        */
  real_T ParkLengthMax;                /* Variable: ParkLengthMax
                                        * Referenced by: '<S1>/ParkLengthMax'
                                        */
  real_T ParkLengthMin;                /* Variable: ParkLengthMin
                                        * Referenced by: '<S1>/ParkLengthMin'
                                        */
  real_T ParkUltrSnsrOffset;           /* Variable: ParkUltrSnsrOffset
                                        * Referenced by: '<S1>/ParkUltrSnsrOffset'
                                        */
  real_T Gain_Gain;                    /* Expression: 9.92
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T motor_input_Value;            /* Expression: 30
                                        * Referenced by: '<Root>/motor_input'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S4>/Delay2'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/9.92
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/9.92
                                        * Referenced by: '<S4>/Gain2'
                                        */
  real_T motor_zero_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/motor_zero'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S4>/Delay'
                                        */
  uint32_T Delay2_DelayLength;         /* Computed Parameter: Delay2_DelayLength
                                        * Referenced by: '<S4>/Delay2'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S4>/Delay1'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S4>/Delay'
                                        */
  int8_T Delay1_InitialCondition;      /* Computed Parameter: Delay1_InitialCondition
                                        * Referenced by: '<S4>/Delay1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_simulink_function_T {
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
extern P_simulink_function_T simulink_function_P;

/* Block signals (auto storage) */
extern B_simulink_function_T simulink_function_B;

/* Block states (auto storage) */
extern DW_simulink_function_T simulink_function_DW;

/* Constant parameters (auto storage) */
extern const ConstP_simulink_function_T simulink_function_ConstP;

/* Model entry point functions */
extern void simulink_function_initialize(void);
extern void simulink_function_output(void);
extern void simulink_function_update(void);
extern void simulink_function_terminate(void);

/* Real-time Model object */
extern RT_MODEL_simulink_function_T *const simulink_function_M;

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
 * '<Root>' : 'simulink_function'
 * '<S1>'   : 'simulink_function/Intialisation'
 * '<S2>'   : 'simulink_function/MotorA'
 * '<S3>'   : 'simulink_function/MotorB'
 * '<S4>'   : 'simulink_function/SAPS'
 * '<S5>'   : 'simulink_function/SAPS/SAPS Brain'
 * '<S6>'   : 'simulink_function/SAPS/SAPS Brain/ObjDetn'
 * '<S7>'   : 'simulink_function/SAPS/SAPS Brain/ObjDetn2'
 * '<S8>'   : 'simulink_function/SAPS/SAPS Brain/ParkDetn'
 * '<S9>'   : 'simulink_function/SAPS/SAPS Brain/ThreeCmPark'
 * '<S10>'  : 'simulink_function/SAPS/SAPS Brain/ObjDetn/MATLAB Function'
 * '<S11>'  : 'simulink_function/SAPS/SAPS Brain/ObjDetn2/MATLAB Function'
 * '<S12>'  : 'simulink_function/SAPS/SAPS Brain/ParkDetn/MATLAB Function'
 * '<S13>'  : 'simulink_function/SAPS/SAPS Brain/ThreeCmPark/ Steering_Function'
 * '<S14>'  : 'simulink_function/SAPS/SAPS Brain/ThreeCmPark/Display1'
 * '<S15>'  : 'simulink_function/SAPS/SAPS Brain/ThreeCmPark/Signal Builder'
 * '<S16>'  : 'simulink_function/SAPS/SAPS Brain/ThreeCmPark/Signal Builder1'
 * '<S17>'  : 'simulink_function/SAPS/SAPS Brain/ThreeCmPark/rear_wheel_ function'
 */
#endif                                 /* RTW_HEADER_simulink_function_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
