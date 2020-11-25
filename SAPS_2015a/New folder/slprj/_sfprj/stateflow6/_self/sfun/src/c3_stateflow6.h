#ifndef __c3_stateflow6_h__
#define __c3_stateflow6_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef enum_ChartModeType
#define enum_ChartModeType

enum ChartModeType
{
  ChartModeType_None,
  ChartModeType_First_Object,
  ChartModeType_Park_Space,
  ChartModeType_Second_Object,
  ChartModeType_Stop_motor
};

#endif                                 /*enum_ChartModeType*/

#ifndef typedef_c3_ChartModeType
#define typedef_c3_ChartModeType

typedef enum ChartModeType c3_ChartModeType;

#endif                                 /*typedef_c3_ChartModeType*/

#ifndef typedef_SFc3_stateflow6InstanceStruct
#define typedef_SFc3_stateflow6InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c3_dataWrittenToVector[2];
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  int32_T *c3_sfEvent;
  boolean_T *c3_isStable;
  uint8_T *c3_is_active_c3_stateflow6;
  c3_ChartModeType *c3_ChartMode;
  real_T *c3_motor_input;
  real_T *c3_Motor;
  real_T *c3_UltrSnsr;
  real_T *c3_Encoder;
  real_T *c3_state_nr;
  real_T *c3_w;
  real_T *c3_ObjLength;
  real_T *c3_ParkLength;
  uint8_T *c3_temporalCounter_i1;
} SFc3_stateflow6InstanceStruct;

#endif                                 /*typedef_SFc3_stateflow6InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_stateflow6_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_stateflow6_get_check_sum(mxArray *plhs[]);
extern void c3_stateflow6_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
