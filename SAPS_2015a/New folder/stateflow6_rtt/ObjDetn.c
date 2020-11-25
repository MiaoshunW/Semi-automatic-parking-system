/*
 * File: ObjDetn.c
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

#include "ObjDetn.h"

/* Include model header file for global data */
#include "stateflow6.h"
#include "stateflow6_private.h"

/* Output and update for Simulink Function: '<Root>/Object Detection' */
void ObjDetn(real_T rtu_input, real_T rtu_Snsr, real_T rtu_Enc, real_T rtu_ww,
             real_T *rty_Mot)
{
  real_T rtb_rearmotor;
  UNUSED_PARAMETER(rtu_ww);

  /* DataTypeConversion: '<S3>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S3>/TmpSignal ConversionAtEncOutport1'
   */
  stateflow6_B.DataTypeConversion1_ao = rtu_Enc;

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  SignalConversion: '<S3>/TmpSignal ConversionAtSnsrOutport1'
   */
  stateflow6_B.DataTypeConversion_h = rtu_Snsr;

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  SignalConversion: '<S3>/TmpSignal ConversionAtinputOutport1'
   */
  /* MATLAB Function 'Object Detection/MATLAB Function': '<S5>:1' */
  /* d = z */
  /* u = 0; %Encoder reset */
  /* x = w; */
  /* lenght=0; */
  /* reset1=0; */
  /* state2=0; */
  if ((stateflow6_B.DataTypeConversion_h > 4.0) &&
      (stateflow6_B.DataTypeConversion_h <= 24.0)) {
    /* '<S5>:1:9' */
    /* '<S5>:1:10' */
    rtb_rearmotor = rtu_input;

    /*      if((sensor_input-w)>2)|| ((sensor_input-w)<-2) */
    /*          rearmotor = motor_input - 15; */
    /*      elseif(sensor_input>4)&&(sensor_input<=20) */
    /*          rearmotor = motor_input-5; */
    /*      end */
    /*     if (Enc>=30)&&(Enc<=32) */
    /*        length1=30; */
    /*         rearmotor=0; */
    /*         reset1=1; */
    /*    state2=1;         */
    /*   end */
    /* elseif(sensor_input>20)&&(sensor_input<=35) */
    /*    rearmotor=motor_input; */
    /* else(sensor_input>24)&&(sensor_input<=61) */
    /*    x = u; */
    /*   rearmotor=motor_input-10; */
    /*  u=1;     */
    /* if(sensor_input<=20) */
    /*     rearmotor=0;    */
    /* else((sensor_input-z)>2)||((sensor_input-z)<-2) */
    /*  rearmotor=0; */
  } else {
    /* '<S5>:1:33' */
    rtb_rearmotor = rtu_input - 10.0;

    /* state2=0; */
  }

  /* End of MATLAB Function: '<S3>/MATLAB Function' */

  /* SignalConversion: '<S3>/TmpSignal ConversionAtMotInport1' */
  *rty_Mot = rtb_rearmotor;
  stateflow6_DW.ObjectDetection_SubsysRanBC = 4;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
