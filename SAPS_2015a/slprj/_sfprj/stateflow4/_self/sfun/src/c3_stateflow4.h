#ifndef __c3_stateflow4_h__
#define __c3_stateflow4_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_stateflow4InstanceStruct
#define typedef_SFc3_stateflow4InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c3_dataWrittenToVector[1];
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  int32_T *c3_sfEvent;
  boolean_T *c3_isStable;
  boolean_T *c3_doneDoubleBufferReInit;
  uint8_T *c3_is_active_c3_stateflow4;
  real_T *c3_motor_input;
  real_T *c3_Motor;
  real_T *c3_UltrSnsr;
  real_T *c3_Encoder;
} SFc3_stateflow4InstanceStruct;

#endif                                 /*typedef_SFc3_stateflow4InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_stateflow4_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_stateflow4_get_check_sum(mxArray *plhs[]);
extern void c3_stateflow4_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
