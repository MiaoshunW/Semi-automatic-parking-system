/*
 * File: simulink_function.c
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

#include "simulink_function.h"
#include "simulink_function_private.h"
#include "simulink_function_dt.h"

/* Named constants for Chart: '<S4>/SAPS Brain' */
#define simulink_IN_ThreecmParkAdjust_s ((uint8_T)5U)
#define simulink_f_IN_SixcmParkAdjust_s ((uint8_T)3U)
#define simulink_fun_IN_First_Object_s1 ((uint8_T)1U)
#define simulink_fun_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define simulink_fun_IN_Second_Object_s ((uint8_T)5U)
#define simulink_funct_IN_ThreeCmPark_s ((uint8_T)4U)
#define simulink_functi_IN_NinecmPark_s ((uint8_T)1U)
#define simulink_functi_IN_Park_Space_s ((uint8_T)2U)
#define simulink_functio_IN_SixCmPark_s ((uint8_T)2U)
#define simulink_function_IN_Parking_s ((uint8_T)3U)
#define simulink_function_IN_Reverse_s ((uint8_T)4U)

/* Block signals (auto storage) */
B_simulink_function_T simulink_function_B;

/* Block states (auto storage) */
DW_simulink_function_T simulink_function_DW;

/* Real-time model */
RT_MODEL_simulink_function_T simulink_function_M_;
RT_MODEL_simulink_function_T *const simulink_function_M = &simulink_function_M_;

/*
 * Output and update for function-call system:
 *    '<S5>/ObjDetn'
 *    '<S5>/ObjDetn2'
 */
void simulink_function_ObjDetn(real_T rtu_motor_input, real_T rtu_UltrSnsr,
  B_ObjDetn_simulink_function_T *localB, DW_ObjDetn_simulink_function_T *localDW)
{
  /* MATLAB Function: '<S6>/MATLAB Function' */
  /* MATLAB Function 'SAPS/SAPS Brain/ObjDetn/MATLAB Function': '<S10>:1' */
  /* d = z */
  /* u = 0; %Encoder reset */
  /* x = w; */
  /* lenght=0; */
  /* reset1=0; */
  /* state2=0; */
  /* if(sensor_input>ObjCarGapMin)&&(sensor_input<=ObjCarGapMax) */
  if ((rtu_UltrSnsr > 4.0) && (rtu_UltrSnsr <= 20.0)) {
    /* '<S10>:1:10' */
    /* '<S10>:1:11' */
    localB->rearmotor = rtu_motor_input;

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
    /* '<S10>:1:34' */
    localB->rearmotor = rtu_motor_input - 10.0;

    /* state2=0; */
  }

  /* End of MATLAB Function: '<S6>/MATLAB Function' */
  localDW->ObjDetn_SubsysRanBC = 4;
}

/* Model output function */
void simulink_function_output(void)
{
  /* local block i/o variables */
  real_T rtb_FromWs[3];
  real_T rtb_FromWs_p[3];
  uint8_T rtb_UltrasonicSensor_0;
  int8_T tmp;
  int32_T rtb_EncoderB_0;
  int8_T tmp_0;
  int8_T tmp_1;
  real_T tmp_2;

  /* Reset subsysRan breadcrumbs */
  srClearBC(simulink_function_DW.ObjDetn.ObjDetn_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(simulink_function_DW.ThreeCmPark_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(simulink_function_DW.ParkDetn_SubsysRanBC);

  /* Constant: '<S1>/ObjLengthMin' */
  simulink_function_B.ObjLengthMin = simulink_function_P.ObjLengthMin;

  /* Constant: '<S1>/ObjLengthMax' */
  simulink_function_B.ObjLengthMax = simulink_function_P.ObjLengthMax;

  /* Constant: '<S1>/ObjCarGapMin' */
  simulink_function_B.ObjCarGapMin = simulink_function_P.ObjCarGapMin;

  /* Constant: '<S1>/ObjCarGapMax' */
  simulink_function_B.ObjCarGapMax = simulink_function_P.ObjCarGapMax;

  /* Constant: '<S1>/ParkLengthMin' */
  simulink_function_B.ParkLengthMin = simulink_function_P.ParkLengthMin;

  /* Constant: '<S1>/ParkLengthMax' */
  simulink_function_B.ParkLengthMax = simulink_function_P.ParkLengthMax;

  /* Constant: '<S1>/ParkCarDepthMin' */
  simulink_function_B.ParkCarDepthMin = simulink_function_P.ParkCarDepthMin;

  /* Constant: '<S1>/ParkCarDepthMax' */
  simulink_function_B.ParkCarDepthMax = simulink_function_P.ParkCarDepthMax;

  /* Constant: '<S1>/ParkUltrSnsrOffset' */
  simulink_function_B.ParkUltrSnsrOffset =
    simulink_function_P.ParkUltrSnsrOffset;

  /* Constant: '<S1>/ObjUltrSnsrOffset' */
  simulink_function_B.ObjUltrSnsrOffset = simulink_function_P.ObjUltrSnsrOffset;

  /* Constant: '<Root>/motor_input' */
  simulink_function_B.motor_input = simulink_function_P.motor_input_Value;

  /* S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  rtb_UltrasonicSensor_0 = getUltrasonicSensorValue(1U);

  /* DataTypeConversion: '<S4>/Data Type Conversion1' incorporates:
   *  S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor'
   */
  simulink_function_B.UltrSnsr = rtb_UltrasonicSensor_0;

  /* Delay: '<S4>/Delay2' */
  simulink_function_B.Delay2 = simulink_function_DW.Delay2_DSTATE;

  /* S-Function (ev3_encoder): '<Root>/Encoder' incorporates:
   *  Delay: '<S4>/Delay1'
   */
  tmp = simulink_function_DW.Delay1_DSTATE;
  rtb_EncoderB_0 = getEncoderValueExternalReset(1U, &tmp);

  /* Gain: '<S4>/Gain1' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion2'
   *  S-Function (ev3_encoder): '<Root>/Encoder'
   */
  simulink_function_B.EncoderA = simulink_function_P.Gain1_Gain * (real_T)
    rtb_EncoderB_0;

  /* S-Function (ev3_encoder): '<Root>/EncoderB' */
  rtb_EncoderB_0 = getEncoderValueNoReset(2U);

  /* Gain: '<S4>/Gain2' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion4'
   *  S-Function (ev3_encoder): '<Root>/EncoderB'
   */
  simulink_function_B.Gain2 = simulink_function_P.Gain2_Gain * (real_T)
    rtb_EncoderB_0;

  /* Constant: '<Root>/motor_zero' */
  simulink_function_B.motor_zero = simulink_function_P.motor_zero_Value;

  /* Chart: '<S4>/SAPS Brain' */
  if (simulink_function_DW.temporalCounter_i1 < 15U) {
    simulink_function_DW.temporalCounter_i1++;
  }

  /* Gateway: SAPS/SAPS Brain */
  simulink_function_DW.sfEvent = -1;

  /* During: SAPS/SAPS Brain */
  if (simulink_function_DW.is_active_c3_simulink_function == 0U) {
    /* Entry: SAPS/SAPS Brain */
    simulink_function_DW.is_active_c3_simulink_function = 1U;

    /* Entry Internal: SAPS/SAPS Brain */
    /* Transition: '<S5>:250' */
    simulink_function_DW.is_c3_simulink_function =
      simulink_fun_IN_First_Object_s1;
    simulink_function_DW.temporalCounter_i1 = 0U;

    /* Entry 'First_Object_s1': '<S5>:229' */
    /* state_nr=1; */
  } else {
    switch (simulink_function_DW.is_c3_simulink_function) {
     case simulink_fun_IN_First_Object_s1:
      /* During 'First_Object_s1': '<S5>:229' */
      if ((simulink_function_DW.temporalCounter_i1 >= 10U) &&
          ((simulink_function_B.UltrSnsr - simulink_function_B.Delay2 >
            simulink_function_B.ObjUltrSnsrOffset) ||
           ((simulink_function_B.UltrSnsr - simulink_function_B.Delay2 <
             -simulink_function_B.ObjUltrSnsrOffset) &&
            (simulink_function_B.EncoderA < simulink_function_B.ObjLengthMin))))
      {
        /* Transition: '<S5>:253' */
        /* Transition: '<S5>:251' */
        simulink_function_DW.is_c3_simulink_function =
          simulink_fun_IN_First_Object_s1;
        simulink_function_DW.temporalCounter_i1 = 0U;

        /* Entry 'First_Object_s1': '<S5>:229' */
        /* state_nr=1; */
      } else if ((simulink_function_B.UltrSnsr >=
                  simulink_function_B.ParkCarDepthMin) &&
                 (simulink_function_B.UltrSnsr <=
                  simulink_function_B.ParkCarDepthMax) &&
                 (simulink_function_B.EncoderA >=
                  simulink_function_B.ObjLengthMin) &&
                 (simulink_function_B.EncoderA <=
                  simulink_function_B.ObjLengthMax)) {
        /* Transition: '<S5>:252' */
        simulink_function_DW.is_c3_simulink_function =
          simulink_functi_IN_Park_Space_s;
        simulink_function_DW.temporalCounter_i1 = 0U;

        /* Entry 'Park_Space_s': '<S5>:244' */
        /* state_nr=2; */
      } else {
        /* Simulink Function 'ObjDetn': '<S5>:220' */
        simulink_function_B.motor_input_p = simulink_function_B.motor_input;
        simulink_function_B.UltrSnsr_m = simulink_function_B.UltrSnsr;
        simulink_function_B.Encoder = simulink_function_B.EncoderA;
        simulink_function_B.UltrSnsrPrv = simulink_function_B.Delay2;

        /* Outputs for Function Call SubSystem: '<S5>/ObjDetn' */
        simulink_function_ObjDetn(simulink_function_B.motor_input_p,
          simulink_function_B.UltrSnsr_m, &simulink_function_B.ObjDetn,
          &simulink_function_DW.ObjDetn);

        /* End of Outputs for SubSystem: '<S5>/ObjDetn' */
        simulink_function_B.Motor = simulink_function_B.ObjDetn.rearmotor;
      }
      break;

     case simulink_functi_IN_Park_Space_s:
      /* During 'Park_Space_s': '<S5>:244' */
      if ((simulink_function_DW.temporalCounter_i1 >= 10U) &&
          ((simulink_function_B.UltrSnsr - simulink_function_B.Delay2 >
            simulink_function_B.ParkUltrSnsrOffset) ||
           ((simulink_function_B.UltrSnsr - simulink_function_B.Delay2 <
             -simulink_function_B.ParkUltrSnsrOffset) &&
            (simulink_function_B.EncoderA < simulink_function_B.ParkLengthMin))))
      {
        /* Transition: '<S5>:255' */
        /* Transition: '<S5>:251' */
        simulink_function_DW.is_c3_simulink_function =
          simulink_fun_IN_First_Object_s1;
        simulink_function_DW.temporalCounter_i1 = 0U;

        /* Entry 'First_Object_s1': '<S5>:229' */
        /* state_nr=1; */
      } else if ((simulink_function_B.UltrSnsr >
                  simulink_function_B.ObjCarGapMin) &&
                 (simulink_function_B.UltrSnsr <=
                  simulink_function_B.ObjCarGapMax) &&
                 (simulink_function_B.EncoderA >=
                  simulink_function_B.ParkLengthMin) &&
                 (simulink_function_B.EncoderA <=
                  simulink_function_B.ParkLengthMax)) {
        /* Transition: '<S5>:257' */
        simulink_function_DW.is_c3_simulink_function =
          simulink_fun_IN_Second_Object_s;
        simulink_function_DW.temporalCounter_i1 = 0U;
      } else {
        /* Simulink Function 'ParkDetn': '<S5>:227' */
        simulink_function_B.motor_input_c = simulink_function_B.motor_input;
        simulink_function_B.UltrSnsr_g = simulink_function_B.UltrSnsr;
        simulink_function_B.Encoder_h = simulink_function_B.EncoderA;
        simulink_function_B.UltrSnsrPrv_p = simulink_function_B.Delay2;

        /* Outputs for Function Call SubSystem: '<S5>/ParkDetn' */
        /* DataTypeConversion: '<S8>/Data Type Conversion1' */
        simulink_function_B.DataTypeConversion1 = simulink_function_B.Encoder_h;

        /* DataTypeConversion: '<S8>/Data Type Conversion' */
        simulink_function_B.DataTypeConversion = simulink_function_B.UltrSnsr_g;

        /* MATLAB Function: '<S8>/MATLAB Function' */
        /* MATLAB Function 'SAPS/SAPS Brain/ParkDetn/MATLAB Function': '<S12>:1' */
        /* d = z */
        /* u = 0; %Encoder reset */
        /*  x = w; */
        /*  length2=0; */
        /* reset11=0; */
        /* state3=0; */
        /* if(sensor_input>ParkCarDepthMin)&&(sensor_input<=ParkCarDepthMax) */
        if ((simulink_function_B.DataTypeConversion > 24.0) &&
            (simulink_function_B.DataTypeConversion <= 40.0)) {
          /* '<S12>:1:10' */
          /* '<S12>:1:11' */
          simulink_function_B.rearmotor = simulink_function_B.motor_input_c -
            10.0;

          /*      if((sensor_input-w)>2)||((sensor_input-w)<-2) */
          /*          rearmotor = motor_input - 15; */
          /*      elseif(sensor_input>4)&&(sensor_input<=20) */
          /*          rearmotor = motor_input-15; */
          /*       end */
          /*   if (Enc>=73)&&(Enc<=74) */
          /*      length2=Enc; */
          /*        rearmotor=0; */
          /*         reset11=1; */
          /*     state3=1;         */
          /* end */
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
          /* '<S12>:1:35' */
          simulink_function_B.rearmotor = simulink_function_B.motor_input_c -
            10.0;

          /* state3=0; */
        }

        /* End of MATLAB Function: '<S8>/MATLAB Function' */
        simulink_function_DW.ParkDetn_SubsysRanBC = 4;

        /* End of Outputs for SubSystem: '<S5>/ParkDetn' */
        simulink_function_B.Motor = simulink_function_B.rearmotor;
      }
      break;

     case simulink_function_IN_Parking_s:
      /* During 'Parking_s': '<S5>:230' */
      switch (simulink_function_DW.is_Parking_s) {
       case simulink_functi_IN_NinecmPark_s:
        /* During 'NinecmPark_s': '<S5>:232' */
        /* [MotorB,Motor] = NineCmPark(EncoderB,Encoder) */
        break;

       case simulink_functio_IN_SixCmPark_s:
        /* During 'SixCmPark_s': '<S5>:234' */
        /* [MotorB,Motor] = SixCmPark(EncoderB,Encoder) */
        break;

       case simulink_f_IN_SixcmParkAdjust_s:
        /* During 'SixcmParkAdjust_s': '<S5>:236' */
        if (simulink_function_B.EncoderA >= -12.5) {
          /* Transition: '<S5>:237' */
          /* Exit 'SixcmParkAdjust_s': '<S5>:236' */
          simulink_function_B.Motor = simulink_function_B.motor_zero;
          simulink_function_DW.is_Parking_s = simulink_functio_IN_SixCmPark_s;
        } else {
          simulink_function_B.Motor = -simulink_function_B.motor_input;
        }
        break;

       case simulink_funct_IN_ThreeCmPark_s:
        /* During 'ThreeCmPark_s': '<S5>:233' */
        break;

       default:
        /* During 'ThreecmParkAdjust_s': '<S5>:228' */
        if (simulink_function_B.EncoderA >= -18.5) {
          /* Transition: '<S5>:239' */
          /* Exit 'ThreecmParkAdjust_s': '<S5>:228' */
          simulink_function_B.Motor = simulink_function_B.motor_zero;
          simulink_function_DW.is_Parking_s = simulink_funct_IN_ThreeCmPark_s;

          /* Entry 'ThreeCmPark_s': '<S5>:233' */
          /* Simulink Function 'ThreeCmPark': '<S5>:226' */
          simulink_function_B.EncoderB = simulink_function_B.Gain2;
          simulink_function_B.Encoder_p = simulink_function_B.EncoderA;

          /* Outputs for Function Call SubSystem: '<S5>/ThreeCmPark' */

          /* FromWorkspace: '<S16>/FromWs' */
          {
            real_T *pDataValues = (real_T *)
              simulink_function_DW.FromWs_PWORK.DataPtr;
            real_T *pTimeValues = (real_T *)
              simulink_function_DW.FromWs_PWORK.TimePtr;
            int_T currTimeIndex = simulink_function_DW.FromWs_IWORK.PrevIndex;
            real_T t = simulink_function_M->Timing.taskTime0;

            /* Get index */
            if (t <= pTimeValues[0]) {
              currTimeIndex = 0;
            } else if (t >= pTimeValues[13]) {
              currTimeIndex = 12;
            } else {
              if (t < pTimeValues[currTimeIndex]) {
                while (t < pTimeValues[currTimeIndex]) {
                  currTimeIndex--;
                }
              } else {
                while (t >= pTimeValues[currTimeIndex + 1]) {
                  currTimeIndex++;
                }
              }
            }

            simulink_function_DW.FromWs_IWORK.PrevIndex = currTimeIndex;

            /* Post output */
            {
              real_T t1 = pTimeValues[currTimeIndex];
              real_T t2 = pTimeValues[currTimeIndex + 1];
              if (t1 == t2) {
                if (t < t1) {
                  {
                    int_T elIdx;
                    for (elIdx = 0; elIdx < 3; ++elIdx) {
                      (&rtb_FromWs[0])[elIdx] = pDataValues[currTimeIndex];
                      pDataValues += 14;
                    }
                  }
                } else {
                  {
                    int_T elIdx;
                    for (elIdx = 0; elIdx < 3; ++elIdx) {
                      (&rtb_FromWs[0])[elIdx] = pDataValues[currTimeIndex + 1];
                      pDataValues += 14;
                    }
                  }
                }
              } else {
                real_T f1 = (t2 - t) / (t2 - t1);
                real_T f2 = 1.0 - f1;
                real_T d1;
                real_T d2;
                int_T TimeIndex= currTimeIndex;

                {
                  int_T elIdx;
                  for (elIdx = 0; elIdx < 3; ++elIdx) {
                    d1 = pDataValues[TimeIndex];
                    d2 = pDataValues[TimeIndex + 1];
                    (&rtb_FromWs[0])[elIdx] = (real_T) rtInterpolate(d1, d2, f1,
                      f2);
                    pDataValues += 14;
                  }
                }
              }
            }
          }

          /* MATLAB Function: '<S9>/ Steering_Function' */
          /* MATLAB Function 'SAPS/SAPS Brain/ThreeCmPark/ Steering_Function': '<S13>:1' */
          if ((rtb_FromWs[0] == 1.0) && (simulink_function_B.EncoderB >= -400.0))
          {
            /* '<S13>:1:3' */
            /* '<S13>:1:4' */
            simulink_function_B.Motor_power_B = -70.0;
          } else if ((rtb_FromWs[1] == 1.0) && (simulink_function_B.EncoderB <=
                      400.0)) {
            /* '<S13>:1:5' */
            /* '<S13>:1:6' */
            simulink_function_B.Motor_power_B = 70.0;
          } else if ((rtb_FromWs[2] == 1.0) && (simulink_function_B.EncoderB >=
                      5.0)) {
            /* '<S13>:1:7' */
            /*  %%  while(encB~=0) */
            /* '<S13>:1:9' */
            simulink_function_B.Motor_power_B = -70.0;
          } else {
            /* '<S13>:1:11' */
            simulink_function_B.Motor_power_B = 0.0;
          }

          /* End of MATLAB Function: '<S9>/ Steering_Function' */

          /* Gain: '<S9>/Gain' */
          simulink_function_B.Gain = simulink_function_P.Gain_Gain *
            simulink_function_B.Encoder_p;

          /* DataTypeConversion: '<S14>/Data Type Conversion' */
          tmp_2 = floor(simulink_function_B.Gain);
          if (rtIsNaN(tmp_2) || rtIsInf(tmp_2)) {
            tmp_2 = 0.0;
          } else {
            tmp_2 = fmod(tmp_2, 4.294967296E+9);
          }

          /* S-Function (ev3_lcd): '<S14>/LCD' incorporates:
           *  DataTypeConversion: '<S14>/Data Type Conversion'
           */
          lcdDisplay(tmp_2 < 0.0 ? -(int32_T)(uint32_T)-tmp_2 : (int32_T)
                     (uint32_T)tmp_2, simulink_function_ConstP.LCD_p1, 1U, 1U);

          /* FromWorkspace: '<S15>/FromWs' */
          {
            real_T *pDataValues = (real_T *)
              simulink_function_DW.FromWs_PWORK_e.DataPtr;
            real_T *pTimeValues = (real_T *)
              simulink_function_DW.FromWs_PWORK_e.TimePtr;
            int_T currTimeIndex = simulink_function_DW.FromWs_IWORK_d.PrevIndex;
            real_T t = simulink_function_M->Timing.taskTime0;

            /* Get index */
            if (t <= pTimeValues[0]) {
              currTimeIndex = 0;
            } else if (t >= pTimeValues[13]) {
              currTimeIndex = 12;
            } else {
              if (t < pTimeValues[currTimeIndex]) {
                while (t < pTimeValues[currTimeIndex]) {
                  currTimeIndex--;
                }
              } else {
                while (t >= pTimeValues[currTimeIndex + 1]) {
                  currTimeIndex++;
                }
              }
            }

            simulink_function_DW.FromWs_IWORK_d.PrevIndex = currTimeIndex;

            /* Post output */
            {
              real_T t1 = pTimeValues[currTimeIndex];
              real_T t2 = pTimeValues[currTimeIndex + 1];
              if (t1 == t2) {
                if (t < t1) {
                  {
                    int_T elIdx;
                    for (elIdx = 0; elIdx < 3; ++elIdx) {
                      (&rtb_FromWs_p[0])[elIdx] = pDataValues[currTimeIndex];
                      pDataValues += 14;
                    }
                  }
                } else {
                  {
                    int_T elIdx;
                    for (elIdx = 0; elIdx < 3; ++elIdx) {
                      (&rtb_FromWs_p[0])[elIdx] = pDataValues[currTimeIndex + 1];
                      pDataValues += 14;
                    }
                  }
                }
              } else {
                real_T f1 = (t2 - t) / (t2 - t1);
                real_T f2 = 1.0 - f1;
                real_T d1;
                real_T d2;
                int_T TimeIndex= currTimeIndex;

                {
                  int_T elIdx;
                  for (elIdx = 0; elIdx < 3; ++elIdx) {
                    d1 = pDataValues[TimeIndex];
                    d2 = pDataValues[TimeIndex + 1];
                    (&rtb_FromWs_p[0])[elIdx] = (real_T) rtInterpolate(d1, d2,
                      f1, f2);
                    pDataValues += 14;
                  }
                }
              }
            }
          }

          /* MATLAB Function: '<S9>/rear_wheel_ function' */
          /* MATLAB Function 'SAPS/SAPS Brain/ThreeCmPark/rear_wheel_ function': '<S17>:1' */
          if ((rtb_FromWs_p[0] == 1.0) && (simulink_function_B.Gain >= -240.0))
          {
            /* '<S17>:1:3' */
            /* '<S17>:1:4' */
            simulink_function_B.Motor_power_A = -30.0;
          } else if ((rtb_FromWs_p[1] == 1.0) && (simulink_function_B.Gain >=
                      -500.0)) {
            /* '<S17>:1:5' */
            /* '<S17>:1:6' */
            simulink_function_B.Motor_power_A = -30.0;
          } else if ((rtb_FromWs_p[2] == 1.0) && (simulink_function_B.Gain <=
                      -445.0)) {
            /* '<S17>:1:7' */
            /* '<S17>:1:8' */
            simulink_function_B.Motor_power_A = 30.0;
          } else {
            /* '<S17>:1:10' */
            simulink_function_B.Motor_power_A = 0.0;
          }

          /* End of MATLAB Function: '<S9>/rear_wheel_ function' */
          simulink_function_DW.ThreeCmPark_SubsysRanBC = 4;

          /* End of Outputs for SubSystem: '<S5>/ThreeCmPark' */
          simulink_function_B.MotorB1 = simulink_function_B.Motor_power_B;
          simulink_function_B.Motor = simulink_function_B.Motor_power_A;

          /* MotorB = ThreeCmPark(EncoderB,Encoder) */
        } else {
          simulink_function_B.Motor = -simulink_function_B.motor_input;
        }
        break;
      }
      break;

     case simulink_function_IN_Reverse_s:
      /* During 'Reverse_s': '<S5>:248' */
      if (simulink_function_B.EncoderA >= -11.0) {
        /* Transition: '<S5>:256' */
        /* Exit 'Reverse_s': '<S5>:248' */
        simulink_function_B.Motor = simulink_function_B.motor_zero;
        simulink_function_DW.is_c3_simulink_function =
          simulink_function_IN_Parking_s;

        /* Entry 'Parking_s': '<S5>:230' */
        simulink_function_B.state_nr = 5.0;

        /* Entry Internal 'Parking_s': '<S5>:230' */
        /* Transition: '<S5>:238' */
        if ((simulink_function_B.UltrSnsr > 5.0) &&
            (simulink_function_B.UltrSnsr <= 7.0)) {
          /* Transition: '<S5>:241' */
          simulink_function_DW.is_Parking_s = simulink_f_IN_SixcmParkAdjust_s;
        } else if ((simulink_function_B.UltrSnsr > 7.0) &&
                   (simulink_function_B.UltrSnsr <= 10.0)) {
          /* Transition: '<S5>:242' */
          simulink_function_DW.is_Parking_s = simulink_functi_IN_NinecmPark_s;
        } else {
          if (simulink_function_B.UltrSnsr <= 5.0) {
            /* Transition: '<S5>:240' */
            simulink_function_DW.is_Parking_s = simulink_IN_ThreecmParkAdjust_s;
          }
        }
      } else {
        simulink_function_B.Motor = -simulink_function_B.motor_input;
      }
      break;

     default:
      /* During 'Second_Object_s': '<S5>:245' */
      if ((simulink_function_B.UltrSnsr >= simulink_function_B.ObjCarGapMin) &&
          (simulink_function_B.UltrSnsr <= simulink_function_B.ObjCarGapMax) &&
          (simulink_function_B.EncoderA >= simulink_function_B.ObjLengthMin) &&
          (simulink_function_B.EncoderA <= simulink_function_B.ObjLengthMax)) {
        /* Transition: '<S5>:258' */
        /* Exit 'Second_Object_s': '<S5>:245' */
        simulink_function_B.Motor = simulink_function_B.motor_zero;
        simulink_function_DW.is_c3_simulink_function =
          simulink_function_IN_Reverse_s;

        /* Entry 'Reverse_s': '<S5>:248' */
        /* state_nr=4; */
      } else if ((simulink_function_DW.temporalCounter_i1 >= 10U) &&
                 ((simulink_function_B.UltrSnsr - simulink_function_B.Delay2 >
                   simulink_function_B.ObjUltrSnsrOffset) ||
                  ((simulink_function_B.UltrSnsr - simulink_function_B.Delay2 <
                    -simulink_function_B.ObjUltrSnsrOffset) &&
                   (simulink_function_B.EncoderA <
                    simulink_function_B.ObjLengthMin)))) {
        /* Transition: '<S5>:254' */
        /* Transition: '<S5>:251' */
        /* Exit 'Second_Object_s': '<S5>:245' */
        simulink_function_B.Motor = simulink_function_B.motor_zero;
        simulink_function_DW.is_c3_simulink_function =
          simulink_fun_IN_First_Object_s1;
        simulink_function_DW.temporalCounter_i1 = 0U;

        /* Entry 'First_Object_s1': '<S5>:229' */
        /* state_nr=1; */
      } else {
        /* Simulink Function 'ObjDetn2': '<S5>:269' */
        simulink_function_B.motor_input_n = simulink_function_B.motor_input;
        simulink_function_B.UltrSnsr_n = simulink_function_B.UltrSnsr;
        simulink_function_B.Encoder_i = simulink_function_B.EncoderA;
        simulink_function_B.UltrSnsrPrv_o = simulink_function_B.Delay2;

        /* Outputs for Function Call SubSystem: '<S5>/ObjDetn2' */
        simulink_function_ObjDetn(simulink_function_B.motor_input_n,
          simulink_function_B.UltrSnsr_n, &simulink_function_B.ObjDetn2,
          &simulink_function_DW.ObjDetn2);

        /* End of Outputs for SubSystem: '<S5>/ObjDetn2' */
        simulink_function_B.Motor = simulink_function_B.ObjDetn2.rearmotor;
      }
      break;
    }
  }

  /* End of Chart: '<S4>/SAPS Brain' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  tmp_2 = floor(simulink_function_B.Motor);
  if (tmp_2 < 128.0) {
    if (tmp_2 >= -128.0) {
      /* S-Function (ev3_motor): '<S2>/Motor' */
      tmp_0 = (int8_T)tmp_2;
    } else {
      /* S-Function (ev3_motor): '<S2>/Motor' */
      tmp_0 = MIN_int8_T;
    }
  } else {
    /* S-Function (ev3_motor): '<S2>/Motor' */
    tmp_0 = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

  /* S-Function (ev3_motor): '<S2>/Motor' */
  setMotor(&tmp_0, 1U, 2U);

  /* DataTypeConversion: '<S3>/Data Type Conversion' */
  tmp_2 = floor(simulink_function_B.MotorB1);
  if (tmp_2 < 128.0) {
    if (tmp_2 >= -128.0) {
      /* S-Function (ev3_motor): '<S3>/Motor' */
      tmp_1 = (int8_T)tmp_2;
    } else {
      /* S-Function (ev3_motor): '<S3>/Motor' */
      tmp_1 = MIN_int8_T;
    }
  } else {
    /* S-Function (ev3_motor): '<S3>/Motor' */
    tmp_1 = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S3>/Data Type Conversion' */

  /* S-Function (ev3_motor): '<S3>/Motor' */
  setMotor(&tmp_1, 2U, 2U);

  /* Sum: '<S4>/Add1' */
  simulink_function_B.UltrDiff = simulink_function_B.UltrSnsr -
    simulink_function_B.Delay2;

  /* DataTypeConversion: '<S4>/Data Type Conversion3' incorporates:
   *  Delay: '<S4>/Delay'
   *  Sum: '<S4>/Add'
   */
  tmp_2 = floor(simulink_function_B.state_nr - simulink_function_DW.Delay_DSTATE);
  if (rtIsNaN(tmp_2) || rtIsInf(tmp_2)) {
    tmp_2 = 0.0;
  } else {
    tmp_2 = fmod(tmp_2, 256.0);
  }

  simulink_function_B.DataTypeConversion3 = (int8_T)(tmp_2 < 0.0 ? (int32_T)
    (int8_T)-(int8_T)(uint8_T)-tmp_2 : (int32_T)(int8_T)(uint8_T)tmp_2);

  /* End of DataTypeConversion: '<S4>/Data Type Conversion3' */
}

/* Model update function */
void simulink_function_update(void)
{
  /* Update for Delay: '<S4>/Delay2' */
  simulink_function_DW.Delay2_DSTATE = simulink_function_B.UltrSnsr;

  /* Update for Delay: '<S4>/Delay1' */
  simulink_function_DW.Delay1_DSTATE = simulink_function_B.DataTypeConversion3;

  /* Update for Delay: '<S4>/Delay' */
  simulink_function_DW.Delay_DSTATE = simulink_function_B.state_nr;

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(simulink_function_M)!=-1) &&
        !((rtmGetTFinal(simulink_function_M)-
           simulink_function_M->Timing.taskTime0) >
          simulink_function_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(simulink_function_M, "Simulation finished");
    }

    if (rtmGetStopRequested(simulink_function_M)) {
      rtmSetErrorStatus(simulink_function_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  simulink_function_M->Timing.taskTime0 =
    (++simulink_function_M->Timing.clockTick0) *
    simulink_function_M->Timing.stepSize0;
}

/* Model initialize function */
void simulink_function_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)simulink_function_M, 0,
                sizeof(RT_MODEL_simulink_function_T));
  rtmSetTFinal(simulink_function_M, -1);
  simulink_function_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  simulink_function_M->Sizes.checksums[0] = (3480656111U);
  simulink_function_M->Sizes.checksums[1] = (3000692761U);
  simulink_function_M->Sizes.checksums[2] = (4073228206U);
  simulink_function_M->Sizes.checksums[3] = (4262084815U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[11];
    simulink_function_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &simulink_function_DW.ObjDetn.ObjDetn_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &simulink_function_DW.ObjDetn.ObjDetn_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &simulink_function_DW.ObjDetn2.ObjDetn_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &simulink_function_DW.ObjDetn2.ObjDetn_SubsysRanBC;
    systemRan[5] = (sysRanDType *)&simulink_function_DW.ParkDetn_SubsysRanBC;
    systemRan[6] = (sysRanDType *)&simulink_function_DW.ParkDetn_SubsysRanBC;
    systemRan[7] = (sysRanDType *)&simulink_function_DW.ThreeCmPark_SubsysRanBC;
    systemRan[8] = (sysRanDType *)&simulink_function_DW.ThreeCmPark_SubsysRanBC;
    systemRan[9] = (sysRanDType *)&simulink_function_DW.ThreeCmPark_SubsysRanBC;
    systemRan[10] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(simulink_function_M->extModeInfo,
      &simulink_function_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(simulink_function_M->extModeInfo,
                        simulink_function_M->Sizes.checksums);
    rteiSetTPtr(simulink_function_M->extModeInfo, rtmGetTPtr(simulink_function_M));
  }

  /* block I/O */
  (void) memset(((void *) &simulink_function_B), 0,
                sizeof(B_simulink_function_T));

  /* states (dwork) */
  (void) memset((void *)&simulink_function_DW, 0,
                sizeof(DW_simulink_function_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    simulink_function_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for Constant: '<S1>/ObjLengthMin' */
  simulink_function_B.ObjLengthMin = simulink_function_P.ObjLengthMin;

  /* Start for Constant: '<S1>/ObjLengthMax' */
  simulink_function_B.ObjLengthMax = simulink_function_P.ObjLengthMax;

  /* Start for Constant: '<S1>/ObjCarGapMin' */
  simulink_function_B.ObjCarGapMin = simulink_function_P.ObjCarGapMin;

  /* Start for Constant: '<S1>/ObjCarGapMax' */
  simulink_function_B.ObjCarGapMax = simulink_function_P.ObjCarGapMax;

  /* Start for Constant: '<S1>/ParkLengthMin' */
  simulink_function_B.ParkLengthMin = simulink_function_P.ParkLengthMin;

  /* Start for Constant: '<S1>/ParkLengthMax' */
  simulink_function_B.ParkLengthMax = simulink_function_P.ParkLengthMax;

  /* Start for Constant: '<S1>/ParkCarDepthMin' */
  simulink_function_B.ParkCarDepthMin = simulink_function_P.ParkCarDepthMin;

  /* Start for Constant: '<S1>/ParkCarDepthMax' */
  simulink_function_B.ParkCarDepthMax = simulink_function_P.ParkCarDepthMax;

  /* Start for Constant: '<S1>/ParkUltrSnsrOffset' */
  simulink_function_B.ParkUltrSnsrOffset =
    simulink_function_P.ParkUltrSnsrOffset;

  /* Start for Constant: '<S1>/ObjUltrSnsrOffset' */
  simulink_function_B.ObjUltrSnsrOffset = simulink_function_P.ObjUltrSnsrOffset;

  /* Start for Constant: '<Root>/motor_input' */
  simulink_function_B.motor_input = simulink_function_P.motor_input_Value;

  /* Start for S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  initUltrasonicSensor(1U);

  /* Start for S-Function (ev3_encoder): '<Root>/Encoder' */
  initEncoder(1U);

  /* Start for S-Function (ev3_encoder): '<Root>/EncoderB' */
  initEncoder(2U);

  /* Start for Constant: '<Root>/motor_zero' */
  simulink_function_B.motor_zero = simulink_function_P.motor_zero_Value;

  /* Start for Chart: '<S4>/SAPS Brain' incorporates:
   *  Start for SubSystem: '<S5>/ThreeCmPark'
   */
  /* Start for FromWorkspace: '<S16>/FromWs' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.12, 0.12, 2.02, 2.02, 5.0, 5.0, 7.0,
      7.0, 10.0, 10.0, 12.0, 12.0, 20.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
      1.0, 0.0, 0.0 } ;

    simulink_function_DW.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
    simulink_function_DW.FromWs_PWORK.DataPtr = (void *) pDataValues0;
    simulink_function_DW.FromWs_IWORK.PrevIndex = 0;
  }

  /* Start for S-Function (ev3_lcd): '<S14>/LCD' */
  initLCD();

  /* Start for FromWorkspace: '<S15>/FromWs' */
  {
    static real_T pTimeValues0[] = { 0.0, 2.0, 2.0, 5.0, 5.0, 7.1000000000000005,
      7.1000000000000005, 10.0, 10.0, 12.75, 12.75, 15.950000000000001,
      15.950000000000001, 20.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
      1.0, 0.0, 0.0 } ;

    simulink_function_DW.FromWs_PWORK_e.TimePtr = (void *) pTimeValues0;
    simulink_function_DW.FromWs_PWORK_e.DataPtr = (void *) pDataValues0;
    simulink_function_DW.FromWs_IWORK_d.PrevIndex = 0;
  }

  /* Start for S-Function (ev3_motor): '<S2>/Motor' */
  initMotor(1U);

  /* Start for S-Function (ev3_motor): '<S3>/Motor' */
  initMotor(2U);

  /* InitializeConditions for Delay: '<S4>/Delay2' */
  simulink_function_DW.Delay2_DSTATE =
    simulink_function_P.Delay2_InitialCondition;

  /* InitializeConditions for Delay: '<S4>/Delay1' */
  simulink_function_DW.Delay1_DSTATE =
    simulink_function_P.Delay1_InitialCondition;

  /* InitializeConditions for Chart: '<S4>/SAPS Brain' */
  simulink_function_DW.sfEvent = -1;
  simulink_function_DW.is_Parking_s = simulink_fun_IN_NO_ACTIVE_CHILD;
  simulink_function_DW.temporalCounter_i1 = 0U;
  simulink_function_DW.is_active_c3_simulink_function = 0U;
  simulink_function_DW.is_c3_simulink_function = simulink_fun_IN_NO_ACTIVE_CHILD;

  /* InitializeConditions for Delay: '<S4>/Delay' */
  simulink_function_DW.Delay_DSTATE = simulink_function_P.Delay_InitialCondition;
}

/* Model terminate function */
void simulink_function_terminate(void)
{
  /* Terminate for S-Function (ev3_ultrasonic_sensor): '<Root>/Ultrasonic Sensor' */
  terminateUltrasonicSensor(1U);

  /* Terminate for S-Function (ev3_encoder): '<Root>/Encoder' */
  terminateEncoder(1U);

  /* Terminate for S-Function (ev3_encoder): '<Root>/EncoderB' */
  terminateEncoder(2U);

  /* Terminate for S-Function (ev3_lcd): '<S14>/LCD' */
  terminateLCD();

  /* Terminate for S-Function (ev3_motor): '<S2>/Motor' */
  terminateMotor(1U, 2U);

  /* Terminate for S-Function (ev3_motor): '<S3>/Motor' */
  terminateMotor(2U, 2U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
