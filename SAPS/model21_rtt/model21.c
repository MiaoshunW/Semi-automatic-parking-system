/*
 * File: model21.c
 *
 * Code generated for Simulink model 'model21'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Tue Oct 18 16:44:06 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "model21.h"
#include "model21_private.h"

/* Real-time model */
RT_MODEL_model21_T model21_M_;
RT_MODEL_model21_T *const model21_M = &model21_M_;

/* Model output function */
void model21_output(void)
{
  int32_T rtb_GyroSensor_0;
  int8_T tmp;
  real_T tmp_0;

  /* S-Function (ev3_gyro_sensor): '<Root>/Gyro Sensor' */
  rtb_GyroSensor_0 = getGyroSensorValue(1U);

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (model21_P.Constant_Value > model21_P.Switch_Threshold) {
    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  S-Function (ev3_gyro_sensor): '<Root>/Gyro Sensor'
     */
    if (rtb_GyroSensor_0 > 127) {
      rtb_GyroSensor_0 = 127;
    } else {
      if (rtb_GyroSensor_0 < -128) {
        rtb_GyroSensor_0 = -128;
      }
    }

    /* S-Function (ev3_motor): '<S1>/Motor' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     */
    tmp = (int8_T)rtb_GyroSensor_0;
  } else {
    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    tmp_0 = floor(model21_P.Constant1_Value);
    if (tmp_0 < 128.0) {
      if (tmp_0 >= -128.0) {
        /* S-Function (ev3_motor): '<S1>/Motor' */
        tmp = (int8_T)tmp_0;
      } else {
        /* S-Function (ev3_motor): '<S1>/Motor' */
        tmp = MIN_int8_T;
      }
    } else {
      /* S-Function (ev3_motor): '<S1>/Motor' */
      tmp = MAX_int8_T;
    }
  }

  /* End of Switch: '<Root>/Switch' */

  /* S-Function (ev3_motor): '<S1>/Motor' */
  setMotor(&tmp, 2U, 2U);
}

/* Model update function */
void model21_update(void)
{
  /* (no update code required) */
}

/* Model initialize function */
void model21_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(model21_M, (NULL));

  /* Start for S-Function (ev3_gyro_sensor): '<Root>/Gyro Sensor' */
  initGyroSensor(1U);

  /* Start for S-Function (ev3_motor): '<S1>/Motor' */
  initMotor(2U);
}

/* Model terminate function */
void model21_terminate(void)
{
  /* Terminate for S-Function (ev3_gyro_sensor): '<Root>/Gyro Sensor' */
  terminateGyroSensor(1U);

  /* Terminate for S-Function (ev3_motor): '<S1>/Motor' */
  terminateMotor(2U, 2U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
