#ifndef __c3_simulink_function_h__
#define __c3_simulink_function_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_simulink_functionInstanceStruct
#define typedef_SFc3_simulink_functionInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c3_dataWrittenToVector[8];
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  int32_T *c3_sfEvent;
  boolean_T *c3_isStable;
  uint8_T *c3_is_active_c3_simulink_function;
  uint8_T *c3_is_c3_simulink_function;
  uint8_T *c3_is_Parking_s;
  real_T *c3_ObjLengthMin;
  real_T *c3_ObjLengthMax;
  real_T *c3_ObjCarGapMin;
  real_T *c3_ObjCarGapMax;
  real_T *c3_ParkLengthMin;
  real_T *c3_ParkLengthMax;
  real_T *c3_ParkCarDepthMin;
  real_T *c3_ParkCarDepthMax;
  real_T *c3_ParkUltrSnsrOffset;
  real_T *c3_ObjUltrSnsrOffset;
  real_T *c3_motor_input;
  real_T *c3_UltrSnsr;
  real_T *c3_Motor;
  real_T *c3_state_nr;
  real_T *c3_UltrSnsrPrv;
  real_T *c3_Encoder;
  real_T *c3_EncoderB;
  real_T *c3_motor_zero;
  real_T *c3_MotorB1;
  real_T *c3_b_motor_input;
  real_T *c3_b_UltrSnsr;
  real_T *c3_b_Encoder;
  real_T *c3_b_UltrSnsrPrv;
  real_T *c3_b_Motor;
  real_T *c3_b_EncoderB;
  real_T *c3_c_Encoder;
  real_T *c3_MotorB;
  real_T *c3_c_Motor;
  real_T *c3_c_motor_input;
  real_T *c3_c_UltrSnsr;
  real_T *c3_d_Encoder;
  real_T *c3_c_UltrSnsrPrv;
  real_T *c3_d_Motor;
  real_T *c3_d_motor_input;
  real_T *c3_d_UltrSnsr;
  real_T *c3_e_Encoder;
  real_T *c3_d_UltrSnsrPrv;
  real_T *c3_e_Motor;
  uint8_T *c3_temporalCounter_i1;
} SFc3_simulink_functionInstanceStruct;

#endif                                 /*typedef_SFc3_simulink_functionInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_simulink_function_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c3_simulink_function_get_check_sum(mxArray *plhs[]);
extern void c3_simulink_function_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
