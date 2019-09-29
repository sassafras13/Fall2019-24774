/*
 * ACSI_Aero_Simulink_P_I_D.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ACSI_Aero_Simulink_P_I_D".
 *
 * Model version              : 1.102
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Fri Sep  6 22:32:05 2019
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ACSI_Aero_Simulink_P_I_D.h"
#include "ACSI_Aero_Simulink_P_I_D_private.h"
#include "ACSI_Aero_Simulink_P_I_D_dt.h"

/* Block signals (default storage) */
B_ACSI_Aero_Simulink_P_I_D_T ACSI_Aero_Simulink_P_I_D_B;

/* Continuous states */
X_ACSI_Aero_Simulink_P_I_D_T ACSI_Aero_Simulink_P_I_D_X;

/* Block states (default storage) */
DW_ACSI_Aero_Simulink_P_I_D_T ACSI_Aero_Simulink_P_I_D_DW;

/* Real-time model */
RT_MODEL_ACSI_Aero_Simulink_P_T ACSI_Aero_Simulink_P_I_D_M_;
RT_MODEL_ACSI_Aero_Simulink_P_T *const ACSI_Aero_Simulink_P_I_D_M =
  &ACSI_Aero_Simulink_P_I_D_M_;

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
  int_T nXc = 16;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  ACSI_Aero_Simulink_P_I_D_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void ACSI_Aero_Simulink_P_I_D_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadTimebase_o1[2];
  real_T rtb_HILReadTimebase_o2[2];
  real_T rtb_HILReadTimebase_o3[4];
  real_T rtb_LEDColour[3];
  int8_T rtAction;
  real_T rtb_Internal_idx_0;
  real_T rtb_Internal_idx_1;
  real_T u0;
  if (rtmIsMajorTimeStep(ACSI_Aero_Simulink_P_I_D_M)) {
    /* set solver stop time */
    if (!(ACSI_Aero_Simulink_P_I_D_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ACSI_Aero_Simulink_P_I_D_M->solverInfo,
                            ((ACSI_Aero_Simulink_P_I_D_M->Timing.clockTickH0 + 1)
        * ACSI_Aero_Simulink_P_I_D_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ACSI_Aero_Simulink_P_I_D_M->solverInfo,
                            ((ACSI_Aero_Simulink_P_I_D_M->Timing.clockTick0 + 1)
        * ACSI_Aero_Simulink_P_I_D_M->Timing.stepSize0 +
        ACSI_Aero_Simulink_P_I_D_M->Timing.clockTickH0 *
        ACSI_Aero_Simulink_P_I_D_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ACSI_Aero_Simulink_P_I_D_M)) {
    ACSI_Aero_Simulink_P_I_D_M->Timing.t[0] = rtsiGetT
      (&ACSI_Aero_Simulink_P_I_D_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(ACSI_Aero_Simulink_P_I_D_DW.EnabledMovingAverage_SubsysRanB);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ACSI_Aero_Simulink_P_I_D_DW.SwitchCaseActionSubsystem_Subsy);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ACSI_Aero_Simulink_P_I_D_DW.SwitchCaseActionSubsystem1_Subs);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ACSI_Aero_Simulink_P_I_D_DW.SwitchCaseActionSubsystem2_Subs);
  if (rtmIsMajorTimeStep(ACSI_Aero_Simulink_P_I_D_M)) {
    /* S-Function (hil_read_timebase_block): '<S5>/HIL Read Timebase' */

    /* S-Function Block: ACSI_Aero_Simulink_P_I_D/Plant/HIL Read Timebase (hil_read_timebase_block) */
    {
      t_error result;
      result = hil_task_read(ACSI_Aero_Simulink_P_I_D_DW.HILReadTimebase_Task, 1,
        &rtb_HILReadTimebase_o1[0],
        &ACSI_Aero_Simulink_P_I_D_DW.HILReadTimebase_EncoderBuffer[0],
        NULL,
        &rtb_HILReadTimebase_o3[0]
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_P_I_D_M, _rt_error_message);
      } else {
        rtb_HILReadTimebase_o2[0] =
          ACSI_Aero_Simulink_P_I_D_DW.HILReadTimebase_EncoderBuffer[0];
        rtb_HILReadTimebase_o2[1] =
          ACSI_Aero_Simulink_P_I_D_DW.HILReadTimebase_EncoderBuffer[1];
      }
    }
  }

  /* StateSpace: '<S1>/Internal' */
  ACSI_Aero_Simulink_P_I_D_B.Internal[0] = 0.0;
  ACSI_Aero_Simulink_P_I_D_B.Internal[0] +=
    ACSI_Aero_Simulink_P_I_D_P.Internal_C[0] *
    ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE[0];
  ACSI_Aero_Simulink_P_I_D_B.Internal[1] = 0.0;
  ACSI_Aero_Simulink_P_I_D_B.Internal[1] +=
    ACSI_Aero_Simulink_P_I_D_P.Internal_C[1] *
    ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE[5];

  /* StateSpace: '<S2>/Internal' */
  rtb_Internal_idx_0 = ((((ACSI_Aero_Simulink_P_I_D_P.Internal_C_p[0] *
    ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE_h[0] +
    ACSI_Aero_Simulink_P_I_D_P.Internal_C_p[1] *
    ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE_h[1]) +
    ACSI_Aero_Simulink_P_I_D_P.Internal_C_p[2] *
    ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE_h[2]) +
    ACSI_Aero_Simulink_P_I_D_P.Internal_C_p[3] *
    ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE_h[3]) +
                        ACSI_Aero_Simulink_P_I_D_P.Internal_D[0] *
                        ACSI_Aero_Simulink_P_I_D_B.Internal[0]) +
    ACSI_Aero_Simulink_P_I_D_P.Internal_D[1] *
    ACSI_Aero_Simulink_P_I_D_B.Internal[1];
  rtb_Internal_idx_1 = ((((ACSI_Aero_Simulink_P_I_D_P.Internal_C_p[4] *
    ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE_h[0] +
    ACSI_Aero_Simulink_P_I_D_P.Internal_C_p[5] *
    ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE_h[1]) +
    ACSI_Aero_Simulink_P_I_D_P.Internal_C_p[6] *
    ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE_h[2]) +
    ACSI_Aero_Simulink_P_I_D_P.Internal_C_p[7] *
    ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE_h[3]) +
                        ACSI_Aero_Simulink_P_I_D_P.Internal_D[2] *
                        ACSI_Aero_Simulink_P_I_D_B.Internal[0]) +
    ACSI_Aero_Simulink_P_I_D_P.Internal_D[3] *
    ACSI_Aero_Simulink_P_I_D_B.Internal[1];
  if (rtmIsMajorTimeStep(ACSI_Aero_Simulink_P_I_D_M)) {
    /* Outputs for Atomic SubSystem: '<S5>/Pitch Bias Removal' */
    /* Step: '<S203>/Step: end_time' incorporates:
     *  Step: '<S203>/Step: start_time'
     */
    u0 = ACSI_Aero_Simulink_P_I_D_M->Timing.t[1];
    if (u0 < ACSI_Aero_Simulink_P_I_D_P.PitchBiasRemoval_end_time) {
      ACSI_Aero_Simulink_P_I_D_B.Stepend_time =
        ACSI_Aero_Simulink_P_I_D_P.Stepend_time_Y0;
    } else {
      ACSI_Aero_Simulink_P_I_D_B.Stepend_time =
        ACSI_Aero_Simulink_P_I_D_P.Stepend_time_YFinal;
    }

    /* End of Step: '<S203>/Step: end_time' */

    /* Step: '<S203>/Step: start_time' */
    if (u0 < ACSI_Aero_Simulink_P_I_D_P.PitchBiasRemoval_start_time) {
      u0 = ACSI_Aero_Simulink_P_I_D_P.Stepstart_time_Y0;
    } else {
      u0 = ACSI_Aero_Simulink_P_I_D_P.Stepstart_time_YFinal;
    }

    /* Outputs for Enabled SubSystem: '<S203>/Enabled Moving Average' incorporates:
     *  EnablePort: '<S205>/Enable'
     */
    /* Logic: '<S203>/Logical Operator' incorporates:
     *  Logic: '<S203>/Logical Operator1'
     */
    if ((u0 != 0.0) && (!(ACSI_Aero_Simulink_P_I_D_B.Stepend_time != 0.0))) {
      if (!ACSI_Aero_Simulink_P_I_D_DW.EnabledMovingAverage_MODE) {
        /* InitializeConditions for UnitDelay: '<S209>/Unit Delay' */
        ACSI_Aero_Simulink_P_I_D_DW.UnitDelay_DSTATE =
          ACSI_Aero_Simulink_P_I_D_P.UnitDelay_InitialCondition;

        /* InitializeConditions for UnitDelay: '<S205>/Sum( k=1,n-1, x(k) )' */
        ACSI_Aero_Simulink_P_I_D_DW.Sumk1n1xk_DSTATE =
          ACSI_Aero_Simulink_P_I_D_P.Sumk1n1xk_InitialCondition;
        ACSI_Aero_Simulink_P_I_D_DW.EnabledMovingAverage_MODE = true;
      }

      /* Sum: '<S209>/Count' incorporates:
       *  Constant: '<S209>/unity'
       *  UnitDelay: '<S209>/Unit Delay'
       */
      ACSI_Aero_Simulink_P_I_D_B.Count = ACSI_Aero_Simulink_P_I_D_P.unity_Value
        + ACSI_Aero_Simulink_P_I_D_DW.UnitDelay_DSTATE;

      /* Sum: '<S205>/Sum' incorporates:
       *  Product: '<S5>/Ax//Az'
       *  Trigonometry: '<S5>/Calculate Pitch'
       *  UnitDelay: '<S205>/Sum( k=1,n-1, x(k) )'
       */
      ACSI_Aero_Simulink_P_I_D_B.Sum_j = atan(rtb_HILReadTimebase_o3[0] /
        rtb_HILReadTimebase_o3[1]) +
        ACSI_Aero_Simulink_P_I_D_DW.Sumk1n1xk_DSTATE;

      /* Product: '<S205>/div' */
      ACSI_Aero_Simulink_P_I_D_B.div = ACSI_Aero_Simulink_P_I_D_B.Sum_j /
        ACSI_Aero_Simulink_P_I_D_B.Count;
      srUpdateBC(ACSI_Aero_Simulink_P_I_D_DW.EnabledMovingAverage_SubsysRanB);
    } else {
      if (ACSI_Aero_Simulink_P_I_D_DW.EnabledMovingAverage_MODE) {
        ACSI_Aero_Simulink_P_I_D_DW.EnabledMovingAverage_MODE = false;
      }
    }

    /* End of Logic: '<S203>/Logical Operator' */
    /* End of Outputs for SubSystem: '<S203>/Enabled Moving Average' */

    /* SwitchCase: '<S203>/Switch Case' */
    rtAction = -1;
    if (ACSI_Aero_Simulink_P_I_D_P.PitchBiasRemoval_switch_id < 0.0) {
      u0 = ceil(ACSI_Aero_Simulink_P_I_D_P.PitchBiasRemoval_switch_id);
    } else {
      u0 = floor(ACSI_Aero_Simulink_P_I_D_P.PitchBiasRemoval_switch_id);
    }

    if (rtIsNaN(u0) || rtIsInf(u0)) {
      u0 = 0.0;
    } else {
      u0 = fmod(u0, 4.294967296E+9);
    }

    switch (u0 < 0.0 ? -(int32_T)(uint32_T)-u0 : (int32_T)(uint32_T)u0) {
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

    ACSI_Aero_Simulink_P_I_D_DW.SwitchCase_ActiveSubsystem = rtAction;
    switch (rtAction) {
     case 0:
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S203>/Switch Case Action Subsystem1' incorporates:
       *  ActionPort: '<S207>/Action Port'
       */
      srUpdateBC(ACSI_Aero_Simulink_P_I_D_DW.SwitchCaseActionSubsystem1_Subs);

      /* End of Outputs for SubSystem: '<S203>/Switch Case Action Subsystem1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S203>/Switch Case Action Subsystem2' incorporates:
       *  ActionPort: '<S208>/Action Port'
       */
      srUpdateBC(ACSI_Aero_Simulink_P_I_D_DW.SwitchCaseActionSubsystem2_Subs);

      /* End of Outputs for SubSystem: '<S203>/Switch Case Action Subsystem2' */
      break;
    }

    /* End of SwitchCase: '<S203>/Switch Case' */
    /* End of Outputs for SubSystem: '<S5>/Pitch Bias Removal' */
  }

  /* Switch: '<S5>/Motor Enable' incorporates:
   *  Constant: '<S5>/No Control'
   */
  if (ACSI_Aero_Simulink_P_I_D_B.Stepend_time >
      ACSI_Aero_Simulink_P_I_D_P.MotorEnable_Threshold) {
    /* Saturate: '<S5>/+//- 24V' */
    if (rtb_Internal_idx_0 > ACSI_Aero_Simulink_P_I_D_P.u4V_UpperSat) {
      ACSI_Aero_Simulink_P_I_D_B.MotorEnable[0] =
        ACSI_Aero_Simulink_P_I_D_P.u4V_UpperSat;
    } else if (rtb_Internal_idx_0 < ACSI_Aero_Simulink_P_I_D_P.u4V_LowerSat) {
      ACSI_Aero_Simulink_P_I_D_B.MotorEnable[0] =
        ACSI_Aero_Simulink_P_I_D_P.u4V_LowerSat;
    } else {
      ACSI_Aero_Simulink_P_I_D_B.MotorEnable[0] = rtb_Internal_idx_0;
    }

    if (rtb_Internal_idx_1 > ACSI_Aero_Simulink_P_I_D_P.u4V_UpperSat) {
      ACSI_Aero_Simulink_P_I_D_B.MotorEnable[1] =
        ACSI_Aero_Simulink_P_I_D_P.u4V_UpperSat;
    } else if (rtb_Internal_idx_1 < ACSI_Aero_Simulink_P_I_D_P.u4V_LowerSat) {
      ACSI_Aero_Simulink_P_I_D_B.MotorEnable[1] =
        ACSI_Aero_Simulink_P_I_D_P.u4V_LowerSat;
    } else {
      ACSI_Aero_Simulink_P_I_D_B.MotorEnable[1] = rtb_Internal_idx_1;
    }

    /* End of Saturate: '<S5>/+//- 24V' */
  } else {
    ACSI_Aero_Simulink_P_I_D_B.MotorEnable[0] =
      ACSI_Aero_Simulink_P_I_D_P.NoControl_Value[0];
    ACSI_Aero_Simulink_P_I_D_B.MotorEnable[1] =
      ACSI_Aero_Simulink_P_I_D_P.NoControl_Value[1];
  }

  /* End of Switch: '<S5>/Motor Enable' */
  if (rtmIsMajorTimeStep(ACSI_Aero_Simulink_P_I_D_M)) {
    /* Switch: '<S5>/LED Colour' incorporates:
     *  Constant: '<S202>/Constant'
     *  Constant: '<S204>/Constant'
     */
    if (ACSI_Aero_Simulink_P_I_D_B.Stepend_time >
        ACSI_Aero_Simulink_P_I_D_P.LEDColour_Threshold) {
      rtb_LEDColour[0] = ACSI_Aero_Simulink_P_I_D_P.Green_color[0];
      rtb_LEDColour[1] = ACSI_Aero_Simulink_P_I_D_P.Green_color[1];
      rtb_LEDColour[2] = ACSI_Aero_Simulink_P_I_D_P.Green_color[2];
    } else {
      rtb_LEDColour[0] = ACSI_Aero_Simulink_P_I_D_P.Yellow_color[0];
      rtb_LEDColour[1] = ACSI_Aero_Simulink_P_I_D_P.Yellow_color[1];
      rtb_LEDColour[2] = ACSI_Aero_Simulink_P_I_D_P.Yellow_color[2];
    }

    /* End of Switch: '<S5>/LED Colour' */

    /* S-Function (hil_write_block): '<S5>/HIL Write' */

    /* S-Function Block: ACSI_Aero_Simulink_P_I_D/Plant/HIL Write (hil_write_block) */
    {
      t_error result;
      result = hil_write(ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card,
                         ACSI_Aero_Simulink_P_I_D_P.HILWrite_analog_channels, 2U,
                         NULL, 0U,
                         NULL, 0U,
                         ACSI_Aero_Simulink_P_I_D_P.HILWrite_other_channels, 3U,
                         &ACSI_Aero_Simulink_P_I_D_B.MotorEnable[0],
                         NULL,
                         NULL,
                         &rtb_LEDColour[0]
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_P_I_D_M, _rt_error_message);
      }
    }

    /* Gain: '<S5>/Counts to rads' */
    ACSI_Aero_Simulink_P_I_D_B.Countstorads[0] =
      ACSI_Aero_Simulink_P_I_D_P.Countstorads_Gain[0] * rtb_HILReadTimebase_o2[0];
    ACSI_Aero_Simulink_P_I_D_B.Countstorads[1] =
      ACSI_Aero_Simulink_P_I_D_P.Countstorads_Gain[1] * rtb_HILReadTimebase_o2[1];

    /* Sum: '<S5>/Sum' */
    ACSI_Aero_Simulink_P_I_D_B.Sum = ACSI_Aero_Simulink_P_I_D_B.Countstorads[0]
      - ACSI_Aero_Simulink_P_I_D_B.div;
  }

  /* SignalGenerator: '<Root>/Pitch ref' incorporates:
   *  SignalGenerator: '<Root>/Yaw ref'
   */
  rtb_Internal_idx_1 = ACSI_Aero_Simulink_P_I_D_M->Timing.t[0];
  rtb_Internal_idx_0 = ACSI_Aero_Simulink_P_I_D_P.Pitchref_Frequency *
    rtb_Internal_idx_1;
  if (rtb_Internal_idx_0 - floor(rtb_Internal_idx_0) >= 0.5) {
    ACSI_Aero_Simulink_P_I_D_B.Pitchref =
      ACSI_Aero_Simulink_P_I_D_P.Pitchref_Amplitude;
  } else {
    ACSI_Aero_Simulink_P_I_D_B.Pitchref =
      -ACSI_Aero_Simulink_P_I_D_P.Pitchref_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Pitch ref' */
  if (rtmIsMajorTimeStep(ACSI_Aero_Simulink_P_I_D_M)) {
  }

  /* SignalGenerator: '<Root>/Yaw ref' */
  rtb_Internal_idx_0 = ACSI_Aero_Simulink_P_I_D_P.Yawref_Frequency *
    rtb_Internal_idx_1;
  if (rtb_Internal_idx_0 - floor(rtb_Internal_idx_0) >= 0.5) {
    ACSI_Aero_Simulink_P_I_D_B.Yawref =
      ACSI_Aero_Simulink_P_I_D_P.Yawref_Amplitude;
  } else {
    ACSI_Aero_Simulink_P_I_D_B.Yawref =
      -ACSI_Aero_Simulink_P_I_D_P.Yawref_Amplitude;
  }

  if (rtmIsMajorTimeStep(ACSI_Aero_Simulink_P_I_D_M)) {
  }

  /* Sum: '<Root>/Sum' */
  rtb_Internal_idx_0 = ACSI_Aero_Simulink_P_I_D_B.Pitchref -
    ACSI_Aero_Simulink_P_I_D_B.Sum;

  /* Gain: '<S74>/Filter Coefficient' incorporates:
   *  Gain: '<S41>/Derivative Gain'
   *  Integrator: '<S42>/Filter'
   *  Sum: '<S42>/SumD'
   */
  ACSI_Aero_Simulink_P_I_D_B.FilterCoefficient =
    (ACSI_Aero_Simulink_P_I_D_P.PIDController_D * rtb_Internal_idx_0 -
     ACSI_Aero_Simulink_P_I_D_X.Filter_CSTATE) *
    ACSI_Aero_Simulink_P_I_D_P.PIDController_N;

  /* Sum: '<Root>/Sum1' */
  rtb_Internal_idx_1 = ACSI_Aero_Simulink_P_I_D_B.Yawref -
    ACSI_Aero_Simulink_P_I_D_B.Countstorads[1];

  /* Gain: '<S170>/Filter Coefficient' incorporates:
   *  Gain: '<S137>/Derivative Gain'
   *  Integrator: '<S138>/Filter'
   *  Sum: '<S138>/SumD'
   */
  ACSI_Aero_Simulink_P_I_D_B.FilterCoefficient_c =
    (ACSI_Aero_Simulink_P_I_D_P.PIDController1_D * rtb_Internal_idx_1 -
     ACSI_Aero_Simulink_P_I_D_X.Filter_CSTATE_g) *
    ACSI_Aero_Simulink_P_I_D_P.PIDController1_N;

  /* Sum: '<S94>/Sum' incorporates:
   *  Gain: '<S81>/Proportional Gain'
   *  Integrator: '<S62>/Integrator'
   */
  u0 = (ACSI_Aero_Simulink_P_I_D_P.PIDController_P * rtb_Internal_idx_0 +
        ACSI_Aero_Simulink_P_I_D_X.Integrator_CSTATE) +
    ACSI_Aero_Simulink_P_I_D_B.FilterCoefficient;

  /* Saturate: '<Root>/Saturation' */
  if (u0 > ACSI_Aero_Simulink_P_I_D_P.Saturation_UpperSat) {
    /* SignalConversion: '<S1>/TmpSignal ConversionAtInternalInport1' */
    ACSI_Aero_Simulink_P_I_D_B.TmpSignalConversionAtInternalIn[0] =
      ACSI_Aero_Simulink_P_I_D_P.Saturation_UpperSat;
  } else if (u0 < ACSI_Aero_Simulink_P_I_D_P.Saturation_LowerSat) {
    /* SignalConversion: '<S1>/TmpSignal ConversionAtInternalInport1' */
    ACSI_Aero_Simulink_P_I_D_B.TmpSignalConversionAtInternalIn[0] =
      ACSI_Aero_Simulink_P_I_D_P.Saturation_LowerSat;
  } else {
    /* SignalConversion: '<S1>/TmpSignal ConversionAtInternalInport1' */
    ACSI_Aero_Simulink_P_I_D_B.TmpSignalConversionAtInternalIn[0] = u0;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Sum: '<S190>/Sum' incorporates:
   *  Gain: '<S177>/Proportional Gain'
   *  Integrator: '<S158>/Integrator'
   */
  u0 = (ACSI_Aero_Simulink_P_I_D_P.PIDController1_P * rtb_Internal_idx_1 +
        ACSI_Aero_Simulink_P_I_D_X.Integrator_CSTATE_m) +
    ACSI_Aero_Simulink_P_I_D_B.FilterCoefficient_c;

  /* Saturate: '<Root>/Saturation1' */
  if (u0 > ACSI_Aero_Simulink_P_I_D_P.Saturation1_UpperSat) {
    /* SignalConversion: '<S1>/TmpSignal ConversionAtInternalInport1' */
    ACSI_Aero_Simulink_P_I_D_B.TmpSignalConversionAtInternalIn[1] =
      ACSI_Aero_Simulink_P_I_D_P.Saturation1_UpperSat;
  } else if (u0 < ACSI_Aero_Simulink_P_I_D_P.Saturation1_LowerSat) {
    /* SignalConversion: '<S1>/TmpSignal ConversionAtInternalInport1' */
    ACSI_Aero_Simulink_P_I_D_B.TmpSignalConversionAtInternalIn[1] =
      ACSI_Aero_Simulink_P_I_D_P.Saturation1_LowerSat;
  } else {
    /* SignalConversion: '<S1>/TmpSignal ConversionAtInternalInport1' */
    ACSI_Aero_Simulink_P_I_D_B.TmpSignalConversionAtInternalIn[1] = u0;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* Gain: '<S54>/Integral Gain' */
  ACSI_Aero_Simulink_P_I_D_B.IntegralGain =
    ACSI_Aero_Simulink_P_I_D_P.PIDController_I * rtb_Internal_idx_0;

  /* Gain: '<S150>/Integral Gain' */
  ACSI_Aero_Simulink_P_I_D_B.IntegralGain_i =
    ACSI_Aero_Simulink_P_I_D_P.PIDController1_I * rtb_Internal_idx_1;
}

/* Model update function */
void ACSI_Aero_Simulink_P_I_D_update(void)
{
  /* Update for Atomic SubSystem: '<S5>/Pitch Bias Removal' */
  /* Update for Enabled SubSystem: '<S203>/Enabled Moving Average' incorporates:
   *  EnablePort: '<S205>/Enable'
   */
  if (rtmIsMajorTimeStep(ACSI_Aero_Simulink_P_I_D_M) &&
      ACSI_Aero_Simulink_P_I_D_DW.EnabledMovingAverage_MODE) {
    /* Update for UnitDelay: '<S209>/Unit Delay' */
    ACSI_Aero_Simulink_P_I_D_DW.UnitDelay_DSTATE =
      ACSI_Aero_Simulink_P_I_D_B.Count;

    /* Update for UnitDelay: '<S205>/Sum( k=1,n-1, x(k) )' */
    ACSI_Aero_Simulink_P_I_D_DW.Sumk1n1xk_DSTATE =
      ACSI_Aero_Simulink_P_I_D_B.Sum_j;
  }

  /* End of Update for SubSystem: '<S203>/Enabled Moving Average' */
  /* End of Update for SubSystem: '<S5>/Pitch Bias Removal' */
  if (rtmIsMajorTimeStep(ACSI_Aero_Simulink_P_I_D_M)) {
    rt_ertODEUpdateContinuousStates(&ACSI_Aero_Simulink_P_I_D_M->solverInfo);
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
  if (!(++ACSI_Aero_Simulink_P_I_D_M->Timing.clockTick0)) {
    ++ACSI_Aero_Simulink_P_I_D_M->Timing.clockTickH0;
  }

  ACSI_Aero_Simulink_P_I_D_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ACSI_Aero_Simulink_P_I_D_M->solverInfo);

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
    if (!(++ACSI_Aero_Simulink_P_I_D_M->Timing.clockTick1)) {
      ++ACSI_Aero_Simulink_P_I_D_M->Timing.clockTickH1;
    }

    ACSI_Aero_Simulink_P_I_D_M->Timing.t[1] =
      ACSI_Aero_Simulink_P_I_D_M->Timing.clockTick1 *
      ACSI_Aero_Simulink_P_I_D_M->Timing.stepSize1 +
      ACSI_Aero_Simulink_P_I_D_M->Timing.clockTickH1 *
      ACSI_Aero_Simulink_P_I_D_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ACSI_Aero_Simulink_P_I_D_derivatives(void)
{
  int_T is;
  int_T ci;
  static const int8_T ir[9] = { 0, 1, 2, 4, 5, 6, 7, 9, 10 };

  static const int8_T ir_0[9] = { 0, 0, 0, 1, 2, 2, 2, 3, 4 };

  static const int8_T jc[10] = { 2, 3, 0, 2, 3, 6, 7, 4, 6, 7 };

  static const int8_T jc_0[4] = { 0, 0, 1, 1 };

  XDot_ACSI_Aero_Simulink_P_I_D_T *_rtXdot;
  _rtXdot = ((XDot_ACSI_Aero_Simulink_P_I_D_T *)
             ACSI_Aero_Simulink_P_I_D_M->derivs);

  /* Derivatives for StateSpace: '<S1>/Internal' */
  for (is = 0; is < 8; is++) {
    _rtXdot->Internal_CSTATE[is] = 0.0;
    for (ci = ir[is]; ci < ir[is + 1]; ci++) {
      _rtXdot->Internal_CSTATE[is] += ACSI_Aero_Simulink_P_I_D_P.Internal_A[ci] *
        ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE[jc[ci]];
    }
  }

  for (is = 0; is < 8; is++) {
    for (ci = ir_0[is]; ci < ir_0[is + 1]; ci++) {
      _rtXdot->Internal_CSTATE[is] += ACSI_Aero_Simulink_P_I_D_P.Internal_B[ci] *
        ACSI_Aero_Simulink_P_I_D_B.TmpSignalConversionAtInternalIn[jc_0[ci]];
    }
  }

  /* End of Derivatives for StateSpace: '<S1>/Internal' */

  /* Derivatives for StateSpace: '<S2>/Internal' */
  _rtXdot->Internal_CSTATE_h[0] = 0.0;
  _rtXdot->Internal_CSTATE_h[1] = 0.0;
  _rtXdot->Internal_CSTATE_h[2] = 0.0;
  _rtXdot->Internal_CSTATE_h[3] = 0.0;
  _rtXdot->Internal_CSTATE_h[0] += ACSI_Aero_Simulink_P_I_D_P.Internal_A_i[0] *
    ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE_h[1];
  _rtXdot->Internal_CSTATE_h[1] += ACSI_Aero_Simulink_P_I_D_P.Internal_A_i[1] *
    ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE_h[0];
  _rtXdot->Internal_CSTATE_h[1] += ACSI_Aero_Simulink_P_I_D_P.Internal_A_i[2] *
    ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE_h[1];
  _rtXdot->Internal_CSTATE_h[1] += ACSI_Aero_Simulink_P_I_D_P.Internal_A_i[3] *
    ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE_h[2];
  _rtXdot->Internal_CSTATE_h[1] += ACSI_Aero_Simulink_P_I_D_P.Internal_A_i[4] *
    ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE_h[3];
  _rtXdot->Internal_CSTATE_h[2] += ACSI_Aero_Simulink_P_I_D_P.Internal_A_i[5] *
    ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE_h[3];
  _rtXdot->Internal_CSTATE_h[3] += ACSI_Aero_Simulink_P_I_D_P.Internal_A_i[6] *
    ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE_h[0];
  _rtXdot->Internal_CSTATE_h[3] += ACSI_Aero_Simulink_P_I_D_P.Internal_A_i[7] *
    ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE_h[1];
  _rtXdot->Internal_CSTATE_h[3] += ACSI_Aero_Simulink_P_I_D_P.Internal_A_i[8] *
    ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE_h[2];
  _rtXdot->Internal_CSTATE_h[3] += ACSI_Aero_Simulink_P_I_D_P.Internal_A_i[9] *
    ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE_h[3];
  _rtXdot->Internal_CSTATE_h[1] += ACSI_Aero_Simulink_P_I_D_P.Internal_B_k[0] *
    ACSI_Aero_Simulink_P_I_D_B.Internal[0];
  _rtXdot->Internal_CSTATE_h[1] += ACSI_Aero_Simulink_P_I_D_P.Internal_B_k[1] *
    ACSI_Aero_Simulink_P_I_D_B.Internal[1];
  _rtXdot->Internal_CSTATE_h[3] += ACSI_Aero_Simulink_P_I_D_P.Internal_B_k[2] *
    ACSI_Aero_Simulink_P_I_D_B.Internal[0];
  _rtXdot->Internal_CSTATE_h[3] += ACSI_Aero_Simulink_P_I_D_P.Internal_B_k[3] *
    ACSI_Aero_Simulink_P_I_D_B.Internal[1];

  /* Derivatives for Integrator: '<S62>/Integrator' */
  _rtXdot->Integrator_CSTATE = ACSI_Aero_Simulink_P_I_D_B.IntegralGain;

  /* Derivatives for Integrator: '<S42>/Filter' */
  _rtXdot->Filter_CSTATE = ACSI_Aero_Simulink_P_I_D_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S158>/Integrator' */
  _rtXdot->Integrator_CSTATE_m = ACSI_Aero_Simulink_P_I_D_B.IntegralGain_i;

  /* Derivatives for Integrator: '<S138>/Filter' */
  _rtXdot->Filter_CSTATE_g = ACSI_Aero_Simulink_P_I_D_B.FilterCoefficient_c;
}

/* Model initialize function */
void ACSI_Aero_Simulink_P_I_D_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S5>/HIL Initialize' */

  /* S-Function Block: ACSI_Aero_Simulink_P_I_D/Plant/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("quanser_aero_usb", "0",
                      &ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ACSI_Aero_Simulink_P_I_D_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card, " ", 2);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ACSI_Aero_Simulink_P_I_D_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ACSI_Aero_Simulink_P_I_D_M, _rt_error_message);
      return;
    }

    if ((ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AIPStart && !is_switching) ||
        (ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AIPEnter && is_switching)) {
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AIMinimums[0] =
        (ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AILow);
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AIMinimums[1] =
        (ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AILow);
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AIMaximums[0] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AIHigh;
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AIMaximums[1] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges
        (ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card,
         ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AIChannels, 2U,
         &ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AIMinimums[0],
         &ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_P_I_D_M, _rt_error_message);
        return;
      }

      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AIConfigValues[0] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AIConfiguration;
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AIConfigValues[1] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AIConfiguration;
      result = hil_set_analog_input_configuration
        (ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card,
         ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AIChannels, 2U,
         (t_analog_input_configuration *)
         &ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AIConfigValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_P_I_D_M, _rt_error_message);
        return;
      }
    }

    if ((ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOPStart && !is_switching) ||
        (ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOPEnter && is_switching)) {
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AOMinimums[0] =
        (ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOLow);
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AOMinimums[1] =
        (ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOLow);
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AOMaximums[0] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOHigh;
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AOMaximums[1] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges
        (ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card,
         ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOChannels, 2U,
         &ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AOMinimums[0],
         &ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_P_I_D_M, _rt_error_message);
        return;
      }
    }

    if ((ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOStart && !is_switching) ||
        (ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOEnter && is_switching)) {
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AOVoltages[0] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOInitial;
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AOVoltages[1] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOInitial;
      result = hil_write_analog(ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card,
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOChannels, 2U,
        &ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_P_I_D_M, _rt_error_message);
        return;
      }
    }

    if (ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOReset) {
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AOVoltages[0] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOWatchdog;
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AOVoltages[1] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card,
         ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOChannels, 2U,
         &ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_P_I_D_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions
      (ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card, NULL, 0U,
       ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOChannels, 2U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ACSI_Aero_Simulink_P_I_D_M, _rt_error_message);
      return;
    }

    if ((ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOStart && !is_switching) ||
        (ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOEnter && is_switching)) {
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_DOBits[0] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOInitial;
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_DOBits[1] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOInitial;
      result = hil_write_digital(ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card,
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOChannels, 2U, (t_boolean *)
        &ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_P_I_D_M, _rt_error_message);
        return;
      }
    }

    if (ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOReset) {
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_DOStates[0] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOWatchdog;
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_DOStates[1] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOWatchdog;
      result = hil_watchdog_set_digital_expiration_state
        (ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card,
         ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOChannels, 2U, (const
          t_digital_state *)
         &ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_P_I_D_M, _rt_error_message);
        return;
      }
    }

    if ((ACSI_Aero_Simulink_P_I_D_P.HILInitialize_EIPStart && !is_switching) ||
        (ACSI_Aero_Simulink_P_I_D_P.HILInitialize_EIPEnter && is_switching)) {
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_QuadratureModes[0] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_EIQuadrature;
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_QuadratureModes[1] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_EIQuadrature;
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_QuadratureModes[2] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_EIQuadrature;
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_QuadratureModes[3] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card,
         ACSI_Aero_Simulink_P_I_D_P.HILInitialize_EIChannels, 4U,
         (t_encoder_quadrature_mode *)
         &ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_P_I_D_M, _rt_error_message);
        return;
      }
    }

    if ((ACSI_Aero_Simulink_P_I_D_P.HILInitialize_EIStart && !is_switching) ||
        (ACSI_Aero_Simulink_P_I_D_P.HILInitialize_EIEnter && is_switching)) {
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_InitialEICounts[0] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_EIInitial;
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_InitialEICounts[1] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_EIInitial;
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_InitialEICounts[2] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_EIInitial;
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_InitialEICounts[3] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts
        (ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card,
         ACSI_Aero_Simulink_P_I_D_P.HILInitialize_EIChannels, 4U,
         &ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_P_I_D_M, _rt_error_message);
        return;
      }
    }

    if ((ACSI_Aero_Simulink_P_I_D_P.HILInitialize_OOStart && !is_switching) ||
        (ACSI_Aero_Simulink_P_I_D_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card,
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_OOChannels, 3U,
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_P_I_D_M, _rt_error_message);
        return;
      }
    }

    if (ACSI_Aero_Simulink_P_I_D_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card,
         ACSI_Aero_Simulink_P_I_D_P.HILInitialize_OOChannels, 3U,
         ACSI_Aero_Simulink_P_I_D_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ACSI_Aero_Simulink_P_I_D_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_timebase_block): '<S5>/HIL Read Timebase' */

  /* S-Function Block: ACSI_Aero_Simulink_P_I_D/Plant/HIL Read Timebase (hil_read_timebase_block) */
  {
    t_error result;
    result = hil_task_create_reader
      (ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card,
       ACSI_Aero_Simulink_P_I_D_P.HILReadTimebase_samples_in_buff,
       ACSI_Aero_Simulink_P_I_D_P.HILReadTimebase_analog_channels, 2U,
       ACSI_Aero_Simulink_P_I_D_P.HILReadTimebase_encoder_channel, 2U,
       NULL, 0U,
       ACSI_Aero_Simulink_P_I_D_P.HILReadTimebase_other_channels, 4U,
       &ACSI_Aero_Simulink_P_I_D_DW.HILReadTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ACSI_Aero_Simulink_P_I_D_M, _rt_error_message);
    }
  }

  /* Start for Atomic SubSystem: '<S5>/Pitch Bias Removal' */
  /* Start for Enabled SubSystem: '<S203>/Enabled Moving Average' */
  ACSI_Aero_Simulink_P_I_D_DW.EnabledMovingAverage_MODE = false;

  /* End of Start for SubSystem: '<S203>/Enabled Moving Average' */

  /* Start for SwitchCase: '<S203>/Switch Case' */
  ACSI_Aero_Simulink_P_I_D_DW.SwitchCase_ActiveSubsystem = -1;

  /* End of Start for SubSystem: '<S5>/Pitch Bias Removal' */

  /* InitializeConditions for StateSpace: '<S1>/Internal' */
  memset(&ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE[0], 0, sizeof(real_T) << 3U);

  /* InitializeConditions for StateSpace: '<S2>/Internal' */
  ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE_h[0] = 0.0;
  ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE_h[1] = 0.0;
  ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE_h[2] = 0.0;
  ACSI_Aero_Simulink_P_I_D_X.Internal_CSTATE_h[3] = 0.0;

  /* InitializeConditions for Integrator: '<S62>/Integrator' */
  ACSI_Aero_Simulink_P_I_D_X.Integrator_CSTATE =
    ACSI_Aero_Simulink_P_I_D_P.PIDController_InitialConditio_e;

  /* InitializeConditions for Integrator: '<S42>/Filter' */
  ACSI_Aero_Simulink_P_I_D_X.Filter_CSTATE =
    ACSI_Aero_Simulink_P_I_D_P.PIDController_InitialConditionF;

  /* InitializeConditions for Integrator: '<S158>/Integrator' */
  ACSI_Aero_Simulink_P_I_D_X.Integrator_CSTATE_m =
    ACSI_Aero_Simulink_P_I_D_P.PIDController1_InitialConditi_e;

  /* InitializeConditions for Integrator: '<S138>/Filter' */
  ACSI_Aero_Simulink_P_I_D_X.Filter_CSTATE_g =
    ACSI_Aero_Simulink_P_I_D_P.PIDController1_InitialCondition;

  /* SystemInitialize for Atomic SubSystem: '<S5>/Pitch Bias Removal' */
  /* SystemInitialize for Enabled SubSystem: '<S203>/Enabled Moving Average' */
  /* InitializeConditions for UnitDelay: '<S209>/Unit Delay' */
  ACSI_Aero_Simulink_P_I_D_DW.UnitDelay_DSTATE =
    ACSI_Aero_Simulink_P_I_D_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S205>/Sum( k=1,n-1, x(k) )' */
  ACSI_Aero_Simulink_P_I_D_DW.Sumk1n1xk_DSTATE =
    ACSI_Aero_Simulink_P_I_D_P.Sumk1n1xk_InitialCondition;

  /* SystemInitialize for Outport: '<S205>/x_avg_n' */
  ACSI_Aero_Simulink_P_I_D_B.div = ACSI_Aero_Simulink_P_I_D_P.x_avg_n_Y0;

  /* End of SystemInitialize for SubSystem: '<S203>/Enabled Moving Average' */
  /* End of SystemInitialize for SubSystem: '<S5>/Pitch Bias Removal' */
}

/* Model terminate function */
void ACSI_Aero_Simulink_P_I_D_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S5>/HIL Initialize' */

  /* S-Function Block: ACSI_Aero_Simulink_P_I_D/Plant/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card);
    hil_monitor_stop_all(ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card);
    is_switching = false;
    if ((ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOTerminate && !is_switching) ||
        (ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOExit && is_switching)) {
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AOVoltages[0] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOFinal;
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AOVoltages[1] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    }

    if ((ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOTerminate && !is_switching) ||
        (ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOExit && is_switching)) {
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_DOBits[0] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOFinal;
      ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_DOBits[1] =
        ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOFinal;
      num_final_digital_outputs = 2U;
    }

    if ((ACSI_Aero_Simulink_P_I_D_P.HILInitialize_OOTerminate && !is_switching) ||
        (ACSI_Aero_Simulink_P_I_D_P.HILInitialize_OOExit && is_switching)) {
      num_final_other_outputs = 3U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_digital_outputs > 0
        || num_final_other_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card
                         , ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , ACSI_Aero_Simulink_P_I_D_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         ,
                         &ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AOVoltages[0]
                         , NULL
                         , (t_boolean *)
                         &ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_DOBits[0]
                         , ACSI_Aero_Simulink_P_I_D_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card,
             ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOChannels,
             num_final_analog_outputs,
             &ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card,
             ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOChannels,
             num_final_digital_outputs, (t_boolean *)
             &ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_DOBits[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other
            (ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card,
             ACSI_Aero_Simulink_P_I_D_P.HILInitialize_OOChannels,
             num_final_other_outputs,
             ACSI_Aero_Simulink_P_I_D_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(ACSI_Aero_Simulink_P_I_D_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card);
    hil_monitor_delete_all(ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card);
    hil_close(ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card);
    ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card = NULL;
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
  ACSI_Aero_Simulink_P_I_D_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ACSI_Aero_Simulink_P_I_D_update();
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
  ACSI_Aero_Simulink_P_I_D_initialize();
}

void MdlTerminate(void)
{
  ACSI_Aero_Simulink_P_I_D_terminate();
}

/* Registration function */
RT_MODEL_ACSI_Aero_Simulink_P_T *ACSI_Aero_Simulink_P_I_D(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ACSI_Aero_Simulink_P_I_D_M, 0,
                sizeof(RT_MODEL_ACSI_Aero_Simulink_P_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ACSI_Aero_Simulink_P_I_D_M->solverInfo,
                          &ACSI_Aero_Simulink_P_I_D_M->Timing.simTimeStep);
    rtsiSetTPtr(&ACSI_Aero_Simulink_P_I_D_M->solverInfo, &rtmGetTPtr
                (ACSI_Aero_Simulink_P_I_D_M));
    rtsiSetStepSizePtr(&ACSI_Aero_Simulink_P_I_D_M->solverInfo,
                       &ACSI_Aero_Simulink_P_I_D_M->Timing.stepSize0);
    rtsiSetdXPtr(&ACSI_Aero_Simulink_P_I_D_M->solverInfo,
                 &ACSI_Aero_Simulink_P_I_D_M->derivs);
    rtsiSetContStatesPtr(&ACSI_Aero_Simulink_P_I_D_M->solverInfo, (real_T **)
                         &ACSI_Aero_Simulink_P_I_D_M->contStates);
    rtsiSetNumContStatesPtr(&ACSI_Aero_Simulink_P_I_D_M->solverInfo,
      &ACSI_Aero_Simulink_P_I_D_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ACSI_Aero_Simulink_P_I_D_M->solverInfo,
      &ACSI_Aero_Simulink_P_I_D_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ACSI_Aero_Simulink_P_I_D_M->solverInfo,
      &ACSI_Aero_Simulink_P_I_D_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ACSI_Aero_Simulink_P_I_D_M->solverInfo,
      &ACSI_Aero_Simulink_P_I_D_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ACSI_Aero_Simulink_P_I_D_M->solverInfo,
                          (&rtmGetErrorStatus(ACSI_Aero_Simulink_P_I_D_M)));
    rtsiSetRTModelPtr(&ACSI_Aero_Simulink_P_I_D_M->solverInfo,
                      ACSI_Aero_Simulink_P_I_D_M);
  }

  rtsiSetSimTimeStep(&ACSI_Aero_Simulink_P_I_D_M->solverInfo, MAJOR_TIME_STEP);
  ACSI_Aero_Simulink_P_I_D_M->intgData.f[0] = ACSI_Aero_Simulink_P_I_D_M->odeF[0];
  ACSI_Aero_Simulink_P_I_D_M->contStates = ((real_T *)
    &ACSI_Aero_Simulink_P_I_D_X);
  rtsiSetSolverData(&ACSI_Aero_Simulink_P_I_D_M->solverInfo, (void *)
                    &ACSI_Aero_Simulink_P_I_D_M->intgData);
  rtsiSetSolverName(&ACSI_Aero_Simulink_P_I_D_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ACSI_Aero_Simulink_P_I_D_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ACSI_Aero_Simulink_P_I_D_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ACSI_Aero_Simulink_P_I_D_M->Timing.sampleTimes =
      (&ACSI_Aero_Simulink_P_I_D_M->Timing.sampleTimesArray[0]);
    ACSI_Aero_Simulink_P_I_D_M->Timing.offsetTimes =
      (&ACSI_Aero_Simulink_P_I_D_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ACSI_Aero_Simulink_P_I_D_M->Timing.sampleTimes[0] = (0.0);
    ACSI_Aero_Simulink_P_I_D_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    ACSI_Aero_Simulink_P_I_D_M->Timing.offsetTimes[0] = (0.0);
    ACSI_Aero_Simulink_P_I_D_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ACSI_Aero_Simulink_P_I_D_M,
             &ACSI_Aero_Simulink_P_I_D_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ACSI_Aero_Simulink_P_I_D_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ACSI_Aero_Simulink_P_I_D_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ACSI_Aero_Simulink_P_I_D_M, 120.0);
  ACSI_Aero_Simulink_P_I_D_M->Timing.stepSize0 = 0.002;
  ACSI_Aero_Simulink_P_I_D_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  ACSI_Aero_Simulink_P_I_D_M->Sizes.checksums[0] = (600995082U);
  ACSI_Aero_Simulink_P_I_D_M->Sizes.checksums[1] = (895382310U);
  ACSI_Aero_Simulink_P_I_D_M->Sizes.checksums[2] = (4048983063U);
  ACSI_Aero_Simulink_P_I_D_M->Sizes.checksums[3] = (2775504548U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    ACSI_Aero_Simulink_P_I_D_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &ACSI_Aero_Simulink_P_I_D_DW.EnabledMovingAverage_SubsysRanB;
    systemRan[3] = (sysRanDType *)
      &ACSI_Aero_Simulink_P_I_D_DW.SwitchCaseActionSubsystem_Subsy;
    systemRan[4] = (sysRanDType *)
      &ACSI_Aero_Simulink_P_I_D_DW.SwitchCaseActionSubsystem1_Subs;
    systemRan[5] = (sysRanDType *)
      &ACSI_Aero_Simulink_P_I_D_DW.SwitchCaseActionSubsystem2_Subs;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ACSI_Aero_Simulink_P_I_D_M->extModeInfo,
      &ACSI_Aero_Simulink_P_I_D_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ACSI_Aero_Simulink_P_I_D_M->extModeInfo,
                        ACSI_Aero_Simulink_P_I_D_M->Sizes.checksums);
    rteiSetTPtr(ACSI_Aero_Simulink_P_I_D_M->extModeInfo, rtmGetTPtr
                (ACSI_Aero_Simulink_P_I_D_M));
  }

  ACSI_Aero_Simulink_P_I_D_M->solverInfoPtr =
    (&ACSI_Aero_Simulink_P_I_D_M->solverInfo);
  ACSI_Aero_Simulink_P_I_D_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&ACSI_Aero_Simulink_P_I_D_M->solverInfo, 0.002);
  rtsiSetSolverMode(&ACSI_Aero_Simulink_P_I_D_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ACSI_Aero_Simulink_P_I_D_M->blockIO = ((void *) &ACSI_Aero_Simulink_P_I_D_B);
  (void) memset(((void *) &ACSI_Aero_Simulink_P_I_D_B), 0,
                sizeof(B_ACSI_Aero_Simulink_P_I_D_T));

  /* parameters */
  ACSI_Aero_Simulink_P_I_D_M->defaultParam = ((real_T *)
    &ACSI_Aero_Simulink_P_I_D_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ACSI_Aero_Simulink_P_I_D_X;
    ACSI_Aero_Simulink_P_I_D_M->contStates = (x);
    (void) memset((void *)&ACSI_Aero_Simulink_P_I_D_X, 0,
                  sizeof(X_ACSI_Aero_Simulink_P_I_D_T));
  }

  /* states (dwork) */
  ACSI_Aero_Simulink_P_I_D_M->dwork = ((void *) &ACSI_Aero_Simulink_P_I_D_DW);
  (void) memset((void *)&ACSI_Aero_Simulink_P_I_D_DW, 0,
                sizeof(DW_ACSI_Aero_Simulink_P_I_D_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ACSI_Aero_Simulink_P_I_D_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  ACSI_Aero_Simulink_P_I_D_M->Sizes.numContStates = (16);/* Number of continuous states */
  ACSI_Aero_Simulink_P_I_D_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ACSI_Aero_Simulink_P_I_D_M->Sizes.numY = (0);/* Number of model outputs */
  ACSI_Aero_Simulink_P_I_D_M->Sizes.numU = (0);/* Number of model inputs */
  ACSI_Aero_Simulink_P_I_D_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ACSI_Aero_Simulink_P_I_D_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ACSI_Aero_Simulink_P_I_D_M->Sizes.numBlocks = (61);/* Number of blocks */
  ACSI_Aero_Simulink_P_I_D_M->Sizes.numBlockIO = (17);/* Number of block outputs */
  ACSI_Aero_Simulink_P_I_D_M->Sizes.numBlockPrms = (180);/* Sum of parameter "widths" */
  return ACSI_Aero_Simulink_P_I_D_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
