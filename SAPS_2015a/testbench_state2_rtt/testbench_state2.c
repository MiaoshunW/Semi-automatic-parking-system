/*
 * File: testbench_state2.c
 *
 * Code generated for Simulink model 'testbench_state2'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Tue Jan 31 18:07:05 2017
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "testbench_state2.h"
#include "testbench_state2_private.h"

/* Real-time model */
RT_MODEL_testbench_state2_T testbench_state2_M_;
RT_MODEL_testbench_state2_T *const testbench_state2_M = &testbench_state2_M_;

/* Model output function */
void testbench_state2_output(void)
{
  uint8_T rtb_UltrasonicSensor_0;
  int8_T tmp;
  int8_T tmp_0;
  real_T rtb_rearmotor;
  int32_T rtb_sts_light;

  /* S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  rtb_UltrasonicSensor_0 = getUltrasonicSensorValue(1U);

  /* MATLAB Function: '<Root>/Parking_Detection' incorporates:
   *  Constant: '<Root>/Motor_power'
   *  S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor'
   */
  /* MATLAB Function 'Parking_Detection': '<S2>:1' */
  if ((rtb_UltrasonicSensor_0 > 24) && (rtb_UltrasonicSensor_0 <= 40)) {
    /* '<S2>:1:3' */
    /* '<S2>:1:4' */
    rtb_rearmotor = testbench_state2_P.Motor_power_Value;

    /* '<S2>:1:5' */
    rtb_sts_light = 1;
  } else {
    /* '<S2>:1:7' */
    rtb_rearmotor = testbench_state2_P.Motor_power_Value;

    /* '<S2>:1:8' */
    rtb_sts_light = 2;
  }

  /* End of MATLAB Function: '<Root>/Parking_Detection' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  rtb_rearmotor = floor(rtb_rearmotor);
  if (rtb_rearmotor < 128.0) {
    if (rtb_rearmotor >= -128.0) {
      /* S-Function (ev3_motor): '<S1>/Motor' */
      tmp = (int8_T)rtb_rearmotor;
    } else {
      /* S-Function (ev3_motor): '<S1>/Motor' */
      tmp = MIN_int8_T;
    }
  } else {
    /* S-Function (ev3_motor): '<S1>/Motor' */
    tmp = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (ev3_motor): '<S1>/Motor' */
  setMotor(&tmp, 1U, 2U);

  /* S-Function (ev3_led): '<S3>/Status Lights' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  tmp_0 = (int8_T)(int32_T)fmod(rtb_sts_light, 256.0);
  setLED(&tmp_0);

  /* S-Function (ev3_encoder): '<Root>/Encoder' */
  getEncoderValueNoReset(1U);
}

/* Model update function */
void testbench_state2_update(void)
{
  /* (no update code required) */
}

/* Model initialize function */
void testbench_state2_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(testbench_state2_M, (NULL));

  /* Start for S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  initUltrasonicSensor(1U);

  /* Start for S-Function (ev3_motor): '<S1>/Motor' */
  initMotor(1U);

  /* Start for S-Function (ev3_led): '<S3>/Status Lights' */
  initLED();

  /* Start for S-Function (ev3_encoder): '<Root>/Encoder' */
  initEncoder(1U);
}

/* Model terminate function */
void testbench_state2_terminate(void)
{
  /* Terminate for S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  terminateUltrasonicSensor(1U);

  /* Terminate for S-Function (ev3_motor): '<S1>/Motor' */
  terminateMotor(1U, 2U);

  /* Terminate for S-Function (ev3_led): '<S3>/Status Lights' */
  terminateLED();

  /* Terminate for S-Function (ev3_encoder): '<Root>/Encoder' */
  terminateEncoder(1U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
