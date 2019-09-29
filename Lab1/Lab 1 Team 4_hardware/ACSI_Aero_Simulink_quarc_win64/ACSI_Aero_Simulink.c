/*
 * ACSI_Aero_Simulink.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ACSI_Aero_Simulink".
 *
 * Model version              : 1.101
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Fri Sep  6 21:40:27 2019
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ACSI_Aero_Simulink.h"
#include "ACSI_Aero_Simulink_private.h"
#include "ACSI_Aero_Simulink_dt.h"

/* Block signals (default storage) */
B_ACSI_Aero_Simulink_T ACSI_Aero_Simulink_B;

/* Continuous states */
X_ACSI_Aero_Simulink_T ACSI_Aero_Simulink_X;

/* Block states (default storage) */
DW_ACSI_Aero_Simulink_T ACSI_Aero_Simulink_DW;

/* Real-time model */
RT_MODEL_ACSI_Aero_Simulink_T ACSI_Aero_Simulink_M_;
RT_MODEL_ACSI_Aero_Simulink_T *const ACSI_Aero_Simulink_M =
  &ACSI_Aero_Simulink_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  ACSI_Aero_Simulink_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void ACSI_Aero_Simulink_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadTimebase_o1[2];
  real_T rtb_HILReadTimebase_o2[2];
  real_T rtb_HILReadTimebase_o3[4];
  real_T rtb_LEDColour[3];
  real_T rtb_Sum_g;
  real_T rtb_Sum1;
  int8_T rtAction;
  real_T rtb_Sum1_tmp;
  if (rtmIsMajorTimeStep(ACSI_Aero_Simulink_M)) {
    /* set solver stop time */
    if (!(ACSI_Aero_Simulink_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ACSI_Aero_Simulink_M->solverInfo,
                            ((ACSI_Aero_Simulink_M->Timing.clockTickH0 + 1) *
        ACSI_Aero_Simulink_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ACSI_Aero_Simulink_M->solverInfo,
                            ((ACSI_Aero_Simulink_M->Timing.clockTick0 + 1) *
        ACSI_Aero_Simulink_M->Timing.stepSize0 +
        ACSI_Aero_Simulink_M->Timing.clockTickH0 *
        ACSI_Aero_Simulink_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ACSI_Aero_Simulink_M)) {
    ACSI_Aero_Simulink_M->Timing.t[0] = rtsiGetT
      (&ACSI_Aero_Simulink_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(ACSI_Aero_Simulink_DW.EnabledMovingAverage_SubsysRanB);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ACSI_Aero_Simulink_DW.SwitchCaseActionSubsystem_Subsy);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ACSI_Aero_Simulink_DW.SwitchCaseActionSubsystem1_Subs);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ACSI_Aero_Simulink_DW.SwitchCaseActionSubsystem2_Subs);
  if (rtmIsMajorTimeStep(ACSI_Aero_Simulink_M)) {
    /* S-Function (hil_read_timebase_block): '<S3>/HIL Read Timebase' */

    /* S-Function Block: ACSI_Aero_Simulink/Plant/HIL Read Timebase (hil_read_timebase_block) */
    {
      t_error result;
      result = hil_task_read(ACSI_Aero_Simulink_DW.HILReadTimebase_Task, 1,
        &rtb_HILReadTimebase_o1[0],
        &ACSI_Aero_Simulink_DW.HILReadTimebase_EncoderBuffer[0],
        NULL,
        &rtb_HILReadTimebase_o3[0]
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_M, _rt_error_message);
      } else {
        rtb_HILReadTimebase_o2[0] =
          ACSI_Aero_Simulink_DW.HILReadTimebase_EncoderBuffer[0];
        rtb_HILReadTimebase_o2[1] =
          ACSI_Aero_Simulink_DW.HILReadTimebase_EncoderBuffer[1];
      }
    }

    /* Gain: '<S3>/Counts to rads' */
    ACSI_Aero_Simulink_B.Countstorads[0] =
      ACSI_Aero_Simulink_P.Countstorads_Gain[0] * rtb_HILReadTimebase_o2[0];
    ACSI_Aero_Simulink_B.Countstorads[1] =
      ACSI_Aero_Simulink_P.Countstorads_Gain[1] * rtb_HILReadTimebase_o2[1];

    /* Outputs for Atomic SubSystem: '<S3>/Pitch Bias Removal' */
    /* Step: '<S197>/Step: end_time' incorporates:
     *  Step: '<S197>/Step: start_time'
     */
    rtb_Sum1 = ACSI_Aero_Simulink_M->Timing.t[1];
    if (rtb_Sum1 < ACSI_Aero_Simulink_P.PitchBiasRemoval_end_time) {
      ACSI_Aero_Simulink_B.Stepend_time = ACSI_Aero_Simulink_P.Stepend_time_Y0;
    } else {
      ACSI_Aero_Simulink_B.Stepend_time =
        ACSI_Aero_Simulink_P.Stepend_time_YFinal;
    }

    /* End of Step: '<S197>/Step: end_time' */

    /* Step: '<S197>/Step: start_time' */
    if (rtb_Sum1 < ACSI_Aero_Simulink_P.PitchBiasRemoval_start_time) {
      rtb_Sum1 = ACSI_Aero_Simulink_P.Stepstart_time_Y0;
    } else {
      rtb_Sum1 = ACSI_Aero_Simulink_P.Stepstart_time_YFinal;
    }

    /* Outputs for Enabled SubSystem: '<S197>/Enabled Moving Average' incorporates:
     *  EnablePort: '<S199>/Enable'
     */
    /* Logic: '<S197>/Logical Operator' incorporates:
     *  Logic: '<S197>/Logical Operator1'
     */
    if ((rtb_Sum1 != 0.0) && (!(ACSI_Aero_Simulink_B.Stepend_time != 0.0))) {
      if (!ACSI_Aero_Simulink_DW.EnabledMovingAverage_MODE) {
        /* InitializeConditions for UnitDelay: '<S203>/Unit Delay' */
        ACSI_Aero_Simulink_DW.UnitDelay_DSTATE =
          ACSI_Aero_Simulink_P.UnitDelay_InitialCondition;

        /* InitializeConditions for UnitDelay: '<S199>/Sum( k=1,n-1, x(k) )' */
        ACSI_Aero_Simulink_DW.Sumk1n1xk_DSTATE =
          ACSI_Aero_Simulink_P.Sumk1n1xk_InitialCondition;
        ACSI_Aero_Simulink_DW.EnabledMovingAverage_MODE = true;
      }

      /* Sum: '<S203>/Count' incorporates:
       *  Constant: '<S203>/unity'
       *  UnitDelay: '<S203>/Unit Delay'
       */
      ACSI_Aero_Simulink_B.Count = ACSI_Aero_Simulink_P.unity_Value +
        ACSI_Aero_Simulink_DW.UnitDelay_DSTATE;

      /* Sum: '<S199>/Sum' incorporates:
       *  Product: '<S3>/Ax//Az'
       *  Trigonometry: '<S3>/Calculate Pitch'
       *  UnitDelay: '<S199>/Sum( k=1,n-1, x(k) )'
       */
      ACSI_Aero_Simulink_B.Sum_j = atan(rtb_HILReadTimebase_o3[0] /
        rtb_HILReadTimebase_o3[1]) + ACSI_Aero_Simulink_DW.Sumk1n1xk_DSTATE;

      /* Product: '<S199>/div' */
      ACSI_Aero_Simulink_B.div = ACSI_Aero_Simulink_B.Sum_j /
        ACSI_Aero_Simulink_B.Count;
      srUpdateBC(ACSI_Aero_Simulink_DW.EnabledMovingAverage_SubsysRanB);
    } else {
      if (ACSI_Aero_Simulink_DW.EnabledMovingAverage_MODE) {
        ACSI_Aero_Simulink_DW.EnabledMovingAverage_MODE = false;
      }
    }

    /* End of Logic: '<S197>/Logical Operator' */
    /* End of Outputs for SubSystem: '<S197>/Enabled Moving Average' */

    /* SwitchCase: '<S197>/Switch Case' */
    rtAction = -1;
    if (ACSI_Aero_Simulink_P.PitchBiasRemoval_switch_id < 0.0) {
      rtb_Sum1 = ceil(ACSI_Aero_Simulink_P.PitchBiasRemoval_switch_id);
    } else {
      rtb_Sum1 = floor(ACSI_Aero_Simulink_P.PitchBiasRemoval_switch_id);
    }

    if (rtIsNaN(rtb_Sum1) || rtIsInf(rtb_Sum1)) {
      rtb_Sum1 = 0.0;
    } else {
      rtb_Sum1 = fmod(rtb_Sum1, 4.294967296E+9);
    }

    switch (rtb_Sum1 < 0.0 ? -(int32_T)(uint32_T)-rtb_Sum1 : (int32_T)(uint32_T)
            rtb_Sum1) {
     case 1:
      rtAction = 0;
      break;

     case 2:
      rtAction = 1;
      break;

     case 3:
      rtAction = 2;
      break;
    }

    ACSI_Aero_Simulink_DW.SwitchCase_ActiveSubsystem = rtAction;
    switch (rtAction) {
     case 0:
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S197>/Switch Case Action Subsystem1' incorporates:
       *  ActionPort: '<S201>/Action Port'
       */
      srUpdateBC(ACSI_Aero_Simulink_DW.SwitchCaseActionSubsystem1_Subs);

      /* End of Outputs for SubSystem: '<S197>/Switch Case Action Subsystem1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S197>/Switch Case Action Subsystem2' incorporates:
       *  ActionPort: '<S202>/Action Port'
       */
      srUpdateBC(ACSI_Aero_Simulink_DW.SwitchCaseActionSubsystem2_Subs);

      /* End of Outputs for SubSystem: '<S197>/Switch Case Action Subsystem2' */
      break;
    }

    /* End of SwitchCase: '<S197>/Switch Case' */
    /* End of Outputs for SubSystem: '<S3>/Pitch Bias Removal' */

    /* Sum: '<S3>/Sum' */
    ACSI_Aero_Simulink_B.Sum = ACSI_Aero_Simulink_B.Countstorads[0] -
      ACSI_Aero_Simulink_B.div;
  }

  /* SignalGenerator: '<Root>/Pitch ref' incorporates:
   *  SignalGenerator: '<Root>/Yaw ref'
   */
  rtb_Sum1_tmp = ACSI_Aero_Simulink_M->Timing.t[0];
  rtb_Sum1 = ACSI_Aero_Simulink_P.Pitchref_Frequency * rtb_Sum1_tmp;
  if (rtb_Sum1 - floor(rtb_Sum1) >= 0.5) {
    ACSI_Aero_Simulink_B.Pitchref = ACSI_Aero_Simulink_P.Pitchref_Amplitude;
  } else {
    ACSI_Aero_Simulink_B.Pitchref = -ACSI_Aero_Simulink_P.Pitchref_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Pitch ref' */

  /* Sum: '<Root>/Sum' */
  rtb_Sum_g = ACSI_Aero_Simulink_B.Pitchref - ACSI_Aero_Simulink_B.Sum;

  /* Gain: '<S68>/Filter Coefficient' incorporates:
   *  Gain: '<S35>/Derivative Gain'
   *  Integrator: '<S36>/Filter'
   *  Sum: '<S36>/SumD'
   */
  ACSI_Aero_Simulink_B.FilterCoefficient = (ACSI_Aero_Simulink_P.PIDController_D
    * rtb_Sum_g - ACSI_Aero_Simulink_X.Filter_CSTATE) *
    ACSI_Aero_Simulink_P.PIDController_N;

  /* SignalGenerator: '<Root>/Yaw ref' */
  rtb_Sum1 = ACSI_Aero_Simulink_P.Yawref_Frequency * rtb_Sum1_tmp;
  if (rtb_Sum1 - floor(rtb_Sum1) >= 0.5) {
    ACSI_Aero_Simulink_B.Yawref = ACSI_Aero_Simulink_P.Yawref_Amplitude;
  } else {
    ACSI_Aero_Simulink_B.Yawref = -ACSI_Aero_Simulink_P.Yawref_Amplitude;
  }

  /* Sum: '<Root>/Sum1' */
  rtb_Sum1 = ACSI_Aero_Simulink_B.Yawref - ACSI_Aero_Simulink_B.Countstorads[1];

  /* Gain: '<S164>/Filter Coefficient' incorporates:
   *  Gain: '<S131>/Derivative Gain'
   *  Integrator: '<S132>/Filter'
   *  Sum: '<S132>/SumD'
   */
  ACSI_Aero_Simulink_B.FilterCoefficient_c =
    (ACSI_Aero_Simulink_P.PIDController1_D * rtb_Sum1 -
     ACSI_Aero_Simulink_X.Filter_CSTATE_g) *
    ACSI_Aero_Simulink_P.PIDController1_N;

  /* Switch: '<S3>/Motor Enable' incorporates:
   *  Constant: '<S3>/No Control'
   */
  if (ACSI_Aero_Simulink_B.Stepend_time >
      ACSI_Aero_Simulink_P.MotorEnable_Threshold) {
    /* Sum: '<S88>/Sum' incorporates:
     *  Gain: '<S75>/Proportional Gain'
     *  Integrator: '<S56>/Integrator'
     */
    rtb_Sum1_tmp = (ACSI_Aero_Simulink_P.PIDController_P * rtb_Sum_g +
                    ACSI_Aero_Simulink_X.Integrator_CSTATE) +
      ACSI_Aero_Simulink_B.FilterCoefficient;

    /* Saturate: '<Root>/Saturation' */
    if (rtb_Sum1_tmp > ACSI_Aero_Simulink_P.Saturation_UpperSat) {
      rtb_Sum1_tmp = ACSI_Aero_Simulink_P.Saturation_UpperSat;
    } else {
      if (rtb_Sum1_tmp < ACSI_Aero_Simulink_P.Saturation_LowerSat) {
        rtb_Sum1_tmp = ACSI_Aero_Simulink_P.Saturation_LowerSat;
      }
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* Saturate: '<S3>/+//- 24V' */
    if (rtb_Sum1_tmp > ACSI_Aero_Simulink_P.u4V_UpperSat) {
      ACSI_Aero_Simulink_B.MotorEnable[0] = ACSI_Aero_Simulink_P.u4V_UpperSat;
    } else if (rtb_Sum1_tmp < ACSI_Aero_Simulink_P.u4V_LowerSat) {
      ACSI_Aero_Simulink_B.MotorEnable[0] = ACSI_Aero_Simulink_P.u4V_LowerSat;
    } else {
      ACSI_Aero_Simulink_B.MotorEnable[0] = rtb_Sum1_tmp;
    }

    /* Sum: '<S184>/Sum' incorporates:
     *  Gain: '<S171>/Proportional Gain'
     *  Integrator: '<S152>/Integrator'
     */
    rtb_Sum1_tmp = (ACSI_Aero_Simulink_P.PIDController1_P * rtb_Sum1 +
                    ACSI_Aero_Simulink_X.Integrator_CSTATE_m) +
      ACSI_Aero_Simulink_B.FilterCoefficient_c;

    /* Saturate: '<Root>/Saturation1' */
    if (rtb_Sum1_tmp > ACSI_Aero_Simulink_P.Saturation1_UpperSat) {
      rtb_Sum1_tmp = ACSI_Aero_Simulink_P.Saturation1_UpperSat;
    } else {
      if (rtb_Sum1_tmp < ACSI_Aero_Simulink_P.Saturation1_LowerSat) {
        rtb_Sum1_tmp = ACSI_Aero_Simulink_P.Saturation1_LowerSat;
      }
    }

    /* End of Saturate: '<Root>/Saturation1' */

    /* Saturate: '<S3>/+//- 24V' */
    if (rtb_Sum1_tmp > ACSI_Aero_Simulink_P.u4V_UpperSat) {
      ACSI_Aero_Simulink_B.MotorEnable[1] = ACSI_Aero_Simulink_P.u4V_UpperSat;
    } else if (rtb_Sum1_tmp < ACSI_Aero_Simulink_P.u4V_LowerSat) {
      ACSI_Aero_Simulink_B.MotorEnable[1] = ACSI_Aero_Simulink_P.u4V_LowerSat;
    } else {
      ACSI_Aero_Simulink_B.MotorEnable[1] = rtb_Sum1_tmp;
    }
  } else {
    ACSI_Aero_Simulink_B.MotorEnable[0] = ACSI_Aero_Simulink_P.NoControl_Value[0];
    ACSI_Aero_Simulink_B.MotorEnable[1] = ACSI_Aero_Simulink_P.NoControl_Value[1];
  }

  /* End of Switch: '<S3>/Motor Enable' */
  if (rtmIsMajorTimeStep(ACSI_Aero_Simulink_M)) {
    /* Switch: '<S3>/LED Colour' incorporates:
     *  Constant: '<S196>/Constant'
     *  Constant: '<S198>/Constant'
     */
    if (ACSI_Aero_Simulink_B.Stepend_time >
        ACSI_Aero_Simulink_P.LEDColour_Threshold) {
      rtb_LEDColour[0] = ACSI_Aero_Simulink_P.Green_color[0];
      rtb_LEDColour[1] = ACSI_Aero_Simulink_P.Green_color[1];
      rtb_LEDColour[2] = ACSI_Aero_Simulink_P.Green_color[2];
    } else {
      rtb_LEDColour[0] = ACSI_Aero_Simulink_P.Yellow_color[0];
      rtb_LEDColour[1] = ACSI_Aero_Simulink_P.Yellow_color[1];
      rtb_LEDColour[2] = ACSI_Aero_Simulink_P.Yellow_color[2];
    }

    /* End of Switch: '<S3>/LED Colour' */

    /* S-Function (hil_write_block): '<S3>/HIL Write' */

    /* S-Function Block: ACSI_Aero_Simulink/Plant/HIL Write (hil_write_block) */
    {
      t_error result;
      result = hil_write(ACSI_Aero_Simulink_DW.HILInitialize_Card,
                         ACSI_Aero_Simulink_P.HILWrite_analog_channels, 2U,
                         NULL, 0U,
                         NULL, 0U,
                         ACSI_Aero_Simulink_P.HILWrite_other_channels, 3U,
                         &ACSI_Aero_Simulink_B.MotorEnable[0],
                         NULL,
                         NULL,
                         &rtb_LEDColour[0]
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_M, _rt_error_message);
      }
    }
  }

  /* Gain: '<S48>/Integral Gain' */
  ACSI_Aero_Simulink_B.IntegralGain = ACSI_Aero_Simulink_P.PIDController_I *
    rtb_Sum_g;

  /* Gain: '<S144>/Integral Gain' */
  ACSI_Aero_Simulink_B.IntegralGain_i = ACSI_Aero_Simulink_P.PIDController1_I *
    rtb_Sum1;
}

/* Model update function */
void ACSI_Aero_Simulink_update(void)
{
  /* Update for Atomic SubSystem: '<S3>/Pitch Bias Removal' */
  /* Update for Enabled SubSystem: '<S197>/Enabled Moving Average' incorporates:
   *  EnablePort: '<S199>/Enable'
   */
  if (rtmIsMajorTimeStep(ACSI_Aero_Simulink_M) &&
      ACSI_Aero_Simulink_DW.EnabledMovingAverage_MODE) {
    /* Update for UnitDelay: '<S203>/Unit Delay' */
    ACSI_Aero_Simulink_DW.UnitDelay_DSTATE = ACSI_Aero_Simulink_B.Count;

    /* Update for UnitDelay: '<S199>/Sum( k=1,n-1, x(k) )' */
    ACSI_Aero_Simulink_DW.Sumk1n1xk_DSTATE = ACSI_Aero_Simulink_B.Sum_j;
  }

  /* End of Update for SubSystem: '<S197>/Enabled Moving Average' */
  /* End of Update for SubSystem: '<S3>/Pitch Bias Removal' */
  if (rtmIsMajorTimeStep(ACSI_Aero_Simulink_M)) {
    rt_ertODEUpdateContinuousStates(&ACSI_Aero_Simulink_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ACSI_Aero_Simulink_M->Timing.clockTick0)) {
    ++ACSI_Aero_Simulink_M->Timing.clockTickH0;
  }

  ACSI_Aero_Simulink_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ACSI_Aero_Simulink_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ACSI_Aero_Simulink_M->Timing.clockTick1)) {
      ++ACSI_Aero_Simulink_M->Timing.clockTickH1;
    }

    ACSI_Aero_Simulink_M->Timing.t[1] = ACSI_Aero_Simulink_M->Timing.clockTick1 *
      ACSI_Aero_Simulink_M->Timing.stepSize1 +
      ACSI_Aero_Simulink_M->Timing.clockTickH1 *
      ACSI_Aero_Simulink_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ACSI_Aero_Simulink_derivatives(void)
{
  XDot_ACSI_Aero_Simulink_T *_rtXdot;
  _rtXdot = ((XDot_ACSI_Aero_Simulink_T *) ACSI_Aero_Simulink_M->derivs);

  /* Derivatives for Integrator: '<S56>/Integrator' */
  _rtXdot->Integrator_CSTATE = ACSI_Aero_Simulink_B.IntegralGain;

  /* Derivatives for Integrator: '<S36>/Filter' */
  _rtXdot->Filter_CSTATE = ACSI_Aero_Simulink_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S152>/Integrator' */
  _rtXdot->Integrator_CSTATE_m = ACSI_Aero_Simulink_B.IntegralGain_i;

  /* Derivatives for Integrator: '<S132>/Filter' */
  _rtXdot->Filter_CSTATE_g = ACSI_Aero_Simulink_B.FilterCoefficient_c;
}

/* Model initialize function */
void ACSI_Aero_Simulink_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S3>/HIL Initialize' */

  /* S-Function Block: ACSI_Aero_Simulink/Plant/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("quanser_aero_usb", "0",
                      &ACSI_Aero_Simulink_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ACSI_Aero_Simulink_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_watchdog_clear(ACSI_Aero_Simulink_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ACSI_Aero_Simulink_M, _rt_error_message);
      return;
    }

    if ((ACSI_Aero_Simulink_P.HILInitialize_AIPStart && !is_switching) ||
        (ACSI_Aero_Simulink_P.HILInitialize_AIPEnter && is_switching)) {
      ACSI_Aero_Simulink_DW.HILInitialize_AIMinimums[0] =
        (ACSI_Aero_Simulink_P.HILInitialize_AILow);
      ACSI_Aero_Simulink_DW.HILInitialize_AIMinimums[1] =
        (ACSI_Aero_Simulink_P.HILInitialize_AILow);
      ACSI_Aero_Simulink_DW.HILInitialize_AIMaximums[0] =
        ACSI_Aero_Simulink_P.HILInitialize_AIHigh;
      ACSI_Aero_Simulink_DW.HILInitialize_AIMaximums[1] =
        ACSI_Aero_Simulink_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges
        (ACSI_Aero_Simulink_DW.HILInitialize_Card,
         ACSI_Aero_Simulink_P.HILInitialize_AIChannels, 2U,
         &ACSI_Aero_Simulink_DW.HILInitialize_AIMinimums[0],
         &ACSI_Aero_Simulink_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_M, _rt_error_message);
        return;
      }

      ACSI_Aero_Simulink_DW.HILInitialize_AIConfigValues[0] =
        ACSI_Aero_Simulink_P.HILInitialize_AIConfiguration;
      ACSI_Aero_Simulink_DW.HILInitialize_AIConfigValues[1] =
        ACSI_Aero_Simulink_P.HILInitialize_AIConfiguration;
      result = hil_set_analog_input_configuration
        (ACSI_Aero_Simulink_DW.HILInitialize_Card,
         ACSI_Aero_Simulink_P.HILInitialize_AIChannels, 2U,
         (t_analog_input_configuration *)
         &ACSI_Aero_Simulink_DW.HILInitialize_AIConfigValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_M, _rt_error_message);
        return;
      }
    }

    if ((ACSI_Aero_Simulink_P.HILInitialize_AOPStart && !is_switching) ||
        (ACSI_Aero_Simulink_P.HILInitialize_AOPEnter && is_switching)) {
      ACSI_Aero_Simulink_DW.HILInitialize_AOMinimums[0] =
        (ACSI_Aero_Simulink_P.HILInitialize_AOLow);
      ACSI_Aero_Simulink_DW.HILInitialize_AOMinimums[1] =
        (ACSI_Aero_Simulink_P.HILInitialize_AOLow);
      ACSI_Aero_Simulink_DW.HILInitialize_AOMaximums[0] =
        ACSI_Aero_Simulink_P.HILInitialize_AOHigh;
      ACSI_Aero_Simulink_DW.HILInitialize_AOMaximums[1] =
        ACSI_Aero_Simulink_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges
        (ACSI_Aero_Simulink_DW.HILInitialize_Card,
         ACSI_Aero_Simulink_P.HILInitialize_AOChannels, 2U,
         &ACSI_Aero_Simulink_DW.HILInitialize_AOMinimums[0],
         &ACSI_Aero_Simulink_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_M, _rt_error_message);
        return;
      }
    }

    if ((ACSI_Aero_Simulink_P.HILInitialize_AOStart && !is_switching) ||
        (ACSI_Aero_Simulink_P.HILInitialize_AOEnter && is_switching)) {
      ACSI_Aero_Simulink_DW.HILInitialize_AOVoltages[0] =
        ACSI_Aero_Simulink_P.HILInitialize_AOInitial;
      ACSI_Aero_Simulink_DW.HILInitialize_AOVoltages[1] =
        ACSI_Aero_Simulink_P.HILInitialize_AOInitial;
      result = hil_write_analog(ACSI_Aero_Simulink_DW.HILInitialize_Card,
        ACSI_Aero_Simulink_P.HILInitialize_AOChannels, 2U,
        &ACSI_Aero_Simulink_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_M, _rt_error_message);
        return;
      }
    }

    if (ACSI_Aero_Simulink_P.HILInitialize_AOReset) {
      ACSI_Aero_Simulink_DW.HILInitialize_AOVoltages[0] =
        ACSI_Aero_Simulink_P.HILInitialize_AOWatchdog;
      ACSI_Aero_Simulink_DW.HILInitialize_AOVoltages[1] =
        ACSI_Aero_Simulink_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (ACSI_Aero_Simulink_DW.HILInitialize_Card,
         ACSI_Aero_Simulink_P.HILInitialize_AOChannels, 2U,
         &ACSI_Aero_Simulink_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(ACSI_Aero_Simulink_DW.HILInitialize_Card,
      NULL, 0U, ACSI_Aero_Simulink_P.HILInitialize_DOChannels, 2U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ACSI_Aero_Simulink_M, _rt_error_message);
      return;
    }

    if ((ACSI_Aero_Simulink_P.HILInitialize_DOStart && !is_switching) ||
        (ACSI_Aero_Simulink_P.HILInitialize_DOEnter && is_switching)) {
      ACSI_Aero_Simulink_DW.HILInitialize_DOBits[0] =
        ACSI_Aero_Simulink_P.HILInitialize_DOInitial;
      ACSI_Aero_Simulink_DW.HILInitialize_DOBits[1] =
        ACSI_Aero_Simulink_P.HILInitialize_DOInitial;
      result = hil_write_digital(ACSI_Aero_Simulink_DW.HILInitialize_Card,
        ACSI_Aero_Simulink_P.HILInitialize_DOChannels, 2U, (t_boolean *)
        &ACSI_Aero_Simulink_DW.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_M, _rt_error_message);
        return;
      }
    }

    if (ACSI_Aero_Simulink_P.HILInitialize_DOReset) {
      ACSI_Aero_Simulink_DW.HILInitialize_DOStates[0] =
        ACSI_Aero_Simulink_P.HILInitialize_DOWatchdog;
      ACSI_Aero_Simulink_DW.HILInitialize_DOStates[1] =
        ACSI_Aero_Simulink_P.HILInitialize_DOWatchdog;
      result = hil_watchdog_set_digital_expiration_state
        (ACSI_Aero_Simulink_DW.HILInitialize_Card,
         ACSI_Aero_Simulink_P.HILInitialize_DOChannels, 2U, (const
          t_digital_state *) &ACSI_Aero_Simulink_DW.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_M, _rt_error_message);
        return;
      }
    }

    if ((ACSI_Aero_Simulink_P.HILInitialize_EIPStart && !is_switching) ||
        (ACSI_Aero_Simulink_P.HILInitialize_EIPEnter && is_switching)) {
      ACSI_Aero_Simulink_DW.HILInitialize_QuadratureModes[0] =
        ACSI_Aero_Simulink_P.HILInitialize_EIQuadrature;
      ACSI_Aero_Simulink_DW.HILInitialize_QuadratureModes[1] =
        ACSI_Aero_Simulink_P.HILInitialize_EIQuadrature;
      ACSI_Aero_Simulink_DW.HILInitialize_QuadratureModes[2] =
        ACSI_Aero_Simulink_P.HILInitialize_EIQuadrature;
      ACSI_Aero_Simulink_DW.HILInitialize_QuadratureModes[3] =
        ACSI_Aero_Simulink_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (ACSI_Aero_Simulink_DW.HILInitialize_Card,
         ACSI_Aero_Simulink_P.HILInitialize_EIChannels, 4U,
         (t_encoder_quadrature_mode *)
         &ACSI_Aero_Simulink_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_M, _rt_error_message);
        return;
      }
    }

    if ((ACSI_Aero_Simulink_P.HILInitialize_EIStart && !is_switching) ||
        (ACSI_Aero_Simulink_P.HILInitialize_EIEnter && is_switching)) {
      ACSI_Aero_Simulink_DW.HILInitialize_InitialEICounts[0] =
        ACSI_Aero_Simulink_P.HILInitialize_EIInitial;
      ACSI_Aero_Simulink_DW.HILInitialize_InitialEICounts[1] =
        ACSI_Aero_Simulink_P.HILInitialize_EIInitial;
      ACSI_Aero_Simulink_DW.HILInitialize_InitialEICounts[2] =
        ACSI_Aero_Simulink_P.HILInitialize_EIInitial;
      ACSI_Aero_Simulink_DW.HILInitialize_InitialEICounts[3] =
        ACSI_Aero_Simulink_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(ACSI_Aero_Simulink_DW.HILInitialize_Card,
        ACSI_Aero_Simulink_P.HILInitialize_EIChannels, 4U,
        &ACSI_Aero_Simulink_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_M, _rt_error_message);
        return;
      }
    }

    if ((ACSI_Aero_Simulink_P.HILInitialize_OOStart && !is_switching) ||
        (ACSI_Aero_Simulink_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(ACSI_Aero_Simulink_DW.HILInitialize_Card,
        ACSI_Aero_Simulink_P.HILInitialize_OOChannels, 3U,
        ACSI_Aero_Simulink_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_M, _rt_error_message);
        return;
      }
    }

    if (ACSI_Aero_Simulink_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (ACSI_Aero_Simulink_DW.HILInitialize_Card,
         ACSI_Aero_Simulink_P.HILInitialize_OOChannels, 3U,
         ACSI_Aero_Simulink_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_timebase_block): '<S3>/HIL Read Timebase' */

  /* S-Function Block: ACSI_Aero_Simulink/Plant/HIL Read Timebase (hil_read_timebase_block) */
  {
    t_error result;
    result = hil_task_create_reader(ACSI_Aero_Simulink_DW.HILInitialize_Card,
      ACSI_Aero_Simulink_P.HILReadTimebase_samples_in_buff,
      ACSI_Aero_Simulink_P.HILReadTimebase_analog_channels, 2U,
      ACSI_Aero_Simulink_P.HILReadTimebase_encoder_channel, 2U,
      NULL, 0U,
      ACSI_Aero_Simulink_P.HILReadTimebase_other_channels, 4U,
      &ACSI_Aero_Simulink_DW.HILReadTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ACSI_Aero_Simulink_M, _rt_error_message);
    }
  }

  /* Start for Atomic SubSystem: '<S3>/Pitch Bias Removal' */
  /* Start for Enabled SubSystem: '<S197>/Enabled Moving Average' */
  ACSI_Aero_Simulink_DW.EnabledMovingAverage_MODE = false;

  /* End of Start for SubSystem: '<S197>/Enabled Moving Average' */

  /* Start for SwitchCase: '<S197>/Switch Case' */
  ACSI_Aero_Simulink_DW.SwitchCase_ActiveSubsystem = -1;

  /* End of Start for SubSystem: '<S3>/Pitch Bias Removal' */

  /* InitializeConditions for Integrator: '<S56>/Integrator' */
  ACSI_Aero_Simulink_X.Integrator_CSTATE =
    ACSI_Aero_Simulink_P.PIDController_InitialConditio_e;

  /* InitializeConditions for Integrator: '<S36>/Filter' */
  ACSI_Aero_Simulink_X.Filter_CSTATE =
    ACSI_Aero_Simulink_P.PIDController_InitialConditionF;

  /* InitializeConditions for Integrator: '<S152>/Integrator' */
  ACSI_Aero_Simulink_X.Integrator_CSTATE_m =
    ACSI_Aero_Simulink_P.PIDController1_InitialConditi_e;

  /* InitializeConditions for Integrator: '<S132>/Filter' */
  ACSI_Aero_Simulink_X.Filter_CSTATE_g =
    ACSI_Aero_Simulink_P.PIDController1_InitialCondition;

  /* SystemInitialize for Atomic SubSystem: '<S3>/Pitch Bias Removal' */
  /* SystemInitialize for Enabled SubSystem: '<S197>/Enabled Moving Average' */
  /* InitializeConditions for UnitDelay: '<S203>/Unit Delay' */
  ACSI_Aero_Simulink_DW.UnitDelay_DSTATE =
    ACSI_Aero_Simulink_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S199>/Sum( k=1,n-1, x(k) )' */
  ACSI_Aero_Simulink_DW.Sumk1n1xk_DSTATE =
    ACSI_Aero_Simulink_P.Sumk1n1xk_InitialCondition;

  /* SystemInitialize for Outport: '<S199>/x_avg_n' */
  ACSI_Aero_Simulink_B.div = ACSI_Aero_Simulink_P.x_avg_n_Y0;

  /* End of SystemInitialize for SubSystem: '<S197>/Enabled Moving Average' */
  /* End of SystemInitialize for SubSystem: '<S3>/Pitch Bias Removal' */
}

/* Model terminate function */
void ACSI_Aero_Simulink_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S3>/HIL Initialize' */

  /* S-Function Block: ACSI_Aero_Simulink/Plant/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(ACSI_Aero_Simulink_DW.HILInitialize_Card);
    hil_monitor_stop_all(ACSI_Aero_Simulink_DW.HILInitialize_Card);
    is_switching = false;
    if ((ACSI_Aero_Simulink_P.HILInitialize_AOTerminate && !is_switching) ||
        (ACSI_Aero_Simulink_P.HILInitialize_AOExit && is_switching)) {
      ACSI_Aero_Simulink_DW.HILInitialize_AOVoltages[0] =
        ACSI_Aero_Simulink_P.HILInitialize_AOFinal;
      ACSI_Aero_Simulink_DW.HILInitialize_AOVoltages[1] =
        ACSI_Aero_Simulink_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    }

    if ((ACSI_Aero_Simulink_P.HILInitialize_DOTerminate && !is_switching) ||
        (ACSI_Aero_Simulink_P.HILInitialize_DOExit && is_switching)) {
      ACSI_Aero_Simulink_DW.HILInitialize_DOBits[0] =
        ACSI_Aero_Simulink_P.HILInitialize_DOFinal;
      ACSI_Aero_Simulink_DW.HILInitialize_DOBits[1] =
        ACSI_Aero_Simulink_P.HILInitialize_DOFinal;
      num_final_digital_outputs = 2U;
    }

    if ((ACSI_Aero_Simulink_P.HILInitialize_OOTerminate && !is_switching) ||
        (ACSI_Aero_Simulink_P.HILInitialize_OOExit && is_switching)) {
      num_final_other_outputs = 3U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_digital_outputs > 0
        || num_final_other_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(ACSI_Aero_Simulink_DW.HILInitialize_Card
                         , ACSI_Aero_Simulink_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , ACSI_Aero_Simulink_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , ACSI_Aero_Simulink_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &ACSI_Aero_Simulink_DW.HILInitialize_AOVoltages[0]
                         , NULL
                         , (t_boolean *)
                         &ACSI_Aero_Simulink_DW.HILInitialize_DOBits[0]
                         , ACSI_Aero_Simulink_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (ACSI_Aero_Simulink_DW.HILInitialize_Card,
             ACSI_Aero_Simulink_P.HILInitialize_AOChannels,
             num_final_analog_outputs,
             &ACSI_Aero_Simulink_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (ACSI_Aero_Simulink_DW.HILInitialize_Card,
             ACSI_Aero_Simulink_P.HILInitialize_DOChannels,
             num_final_digital_outputs, (t_boolean *)
             &ACSI_Aero_Simulink_DW.HILInitialize_DOBits[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other
            (ACSI_Aero_Simulink_DW.HILInitialize_Card,
             ACSI_Aero_Simulink_P.HILInitialize_OOChannels,
             num_final_other_outputs, ACSI_Aero_Simulink_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(ACSI_Aero_Simulink_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(ACSI_Aero_Simulink_DW.HILInitialize_Card);
    hil_monitor_delete_all(ACSI_Aero_Simulink_DW.HILInitialize_Card);
    hil_close(ACSI_Aero_Simulink_DW.HILInitialize_Card);
    ACSI_Aero_Simulink_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  ACSI_Aero_Simulink_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ACSI_Aero_Simulink_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  ACSI_Aero_Simulink_initialize();
}

void MdlTerminate(void)
{
  ACSI_Aero_Simulink_terminate();
}

/* Registration function */
RT_MODEL_ACSI_Aero_Simulink_T *ACSI_Aero_Simulink(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ACSI_Aero_Simulink_M, 0,
                sizeof(RT_MODEL_ACSI_Aero_Simulink_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ACSI_Aero_Simulink_M->solverInfo,
                          &ACSI_Aero_Simulink_M->Timing.simTimeStep);
    rtsiSetTPtr(&ACSI_Aero_Simulink_M->solverInfo, &rtmGetTPtr
                (ACSI_Aero_Simulink_M));
    rtsiSetStepSizePtr(&ACSI_Aero_Simulink_M->solverInfo,
                       &ACSI_Aero_Simulink_M->Timing.stepSize0);
    rtsiSetdXPtr(&ACSI_Aero_Simulink_M->solverInfo,
                 &ACSI_Aero_Simulink_M->derivs);
    rtsiSetContStatesPtr(&ACSI_Aero_Simulink_M->solverInfo, (real_T **)
                         &ACSI_Aero_Simulink_M->contStates);
    rtsiSetNumContStatesPtr(&ACSI_Aero_Simulink_M->solverInfo,
      &ACSI_Aero_Simulink_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ACSI_Aero_Simulink_M->solverInfo,
      &ACSI_Aero_Simulink_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ACSI_Aero_Simulink_M->solverInfo,
      &ACSI_Aero_Simulink_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ACSI_Aero_Simulink_M->solverInfo,
      &ACSI_Aero_Simulink_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ACSI_Aero_Simulink_M->solverInfo, (&rtmGetErrorStatus
      (ACSI_Aero_Simulink_M)));
    rtsiSetRTModelPtr(&ACSI_Aero_Simulink_M->solverInfo, ACSI_Aero_Simulink_M);
  }

  rtsiSetSimTimeStep(&ACSI_Aero_Simulink_M->solverInfo, MAJOR_TIME_STEP);
  ACSI_Aero_Simulink_M->intgData.f[0] = ACSI_Aero_Simulink_M->odeF[0];
  ACSI_Aero_Simulink_M->contStates = ((real_T *) &ACSI_Aero_Simulink_X);
  rtsiSetSolverData(&ACSI_Aero_Simulink_M->solverInfo, (void *)
                    &ACSI_Aero_Simulink_M->intgData);
  rtsiSetSolverName(&ACSI_Aero_Simulink_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ACSI_Aero_Simulink_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ACSI_Aero_Simulink_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ACSI_Aero_Simulink_M->Timing.sampleTimes =
      (&ACSI_Aero_Simulink_M->Timing.sampleTimesArray[0]);
    ACSI_Aero_Simulink_M->Timing.offsetTimes =
      (&ACSI_Aero_Simulink_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ACSI_Aero_Simulink_M->Timing.sampleTimes[0] = (0.0);
    ACSI_Aero_Simulink_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    ACSI_Aero_Simulink_M->Timing.offsetTimes[0] = (0.0);
    ACSI_Aero_Simulink_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ACSI_Aero_Simulink_M, &ACSI_Aero_Simulink_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ACSI_Aero_Simulink_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ACSI_Aero_Simulink_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ACSI_Aero_Simulink_M, 120.0);
  ACSI_Aero_Simulink_M->Timing.stepSize0 = 0.002;
  ACSI_Aero_Simulink_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  ACSI_Aero_Simulink_M->Sizes.checksums[0] = (4284967985U);
  ACSI_Aero_Simulink_M->Sizes.checksums[1] = (253897905U);
  ACSI_Aero_Simulink_M->Sizes.checksums[2] = (689750561U);
  ACSI_Aero_Simulink_M->Sizes.checksums[3] = (3096592708U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    ACSI_Aero_Simulink_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &ACSI_Aero_Simulink_DW.EnabledMovingAverage_SubsysRanB;
    systemRan[3] = (sysRanDType *)
      &ACSI_Aero_Simulink_DW.SwitchCaseActionSubsystem_Subsy;
    systemRan[4] = (sysRanDType *)
      &ACSI_Aero_Simulink_DW.SwitchCaseActionSubsystem1_Subs;
    systemRan[5] = (sysRanDType *)
      &ACSI_Aero_Simulink_DW.SwitchCaseActionSubsystem2_Subs;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ACSI_Aero_Simulink_M->extModeInfo,
      &ACSI_Aero_Simulink_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ACSI_Aero_Simulink_M->extModeInfo,
                        ACSI_Aero_Simulink_M->Sizes.checksums);
    rteiSetTPtr(ACSI_Aero_Simulink_M->extModeInfo, rtmGetTPtr
                (ACSI_Aero_Simulink_M));
  }

  ACSI_Aero_Simulink_M->solverInfoPtr = (&ACSI_Aero_Simulink_M->solverInfo);
  ACSI_Aero_Simulink_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&ACSI_Aero_Simulink_M->solverInfo, 0.002);
  rtsiSetSolverMode(&ACSI_Aero_Simulink_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ACSI_Aero_Simulink_M->blockIO = ((void *) &ACSI_Aero_Simulink_B);
  (void) memset(((void *) &ACSI_Aero_Simulink_B), 0,
                sizeof(B_ACSI_Aero_Simulink_T));

  /* parameters */
  ACSI_Aero_Simulink_M->defaultParam = ((real_T *)&ACSI_Aero_Simulink_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ACSI_Aero_Simulink_X;
    ACSI_Aero_Simulink_M->contStates = (x);
    (void) memset((void *)&ACSI_Aero_Simulink_X, 0,
                  sizeof(X_ACSI_Aero_Simulink_T));
  }

  /* states (dwork) */
  ACSI_Aero_Simulink_M->dwork = ((void *) &ACSI_Aero_Simulink_DW);
  (void) memset((void *)&ACSI_Aero_Simulink_DW, 0,
                sizeof(DW_ACSI_Aero_Simulink_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ACSI_Aero_Simulink_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  ACSI_Aero_Simulink_M->Sizes.numContStates = (4);/* Number of continuous states */
  ACSI_Aero_Simulink_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ACSI_Aero_Simulink_M->Sizes.numY = (0);/* Number of model outputs */
  ACSI_Aero_Simulink_M->Sizes.numU = (0);/* Number of model inputs */
  ACSI_Aero_Simulink_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ACSI_Aero_Simulink_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ACSI_Aero_Simulink_M->Sizes.numBlocks = (60);/* Number of blocks */
  ACSI_Aero_Simulink_M->Sizes.numBlockIO = (15);/* Number of block outputs */
  ACSI_Aero_Simulink_M->Sizes.numBlockPrms = (138);/* Sum of parameter "widths" */
  return ACSI_Aero_Simulink_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
