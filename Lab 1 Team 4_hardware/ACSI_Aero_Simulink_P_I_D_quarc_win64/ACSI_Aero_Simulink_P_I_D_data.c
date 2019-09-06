/*
 * ACSI_Aero_Simulink_P_I_D_data.c
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

/* Block parameters (default storage) */
P_ACSI_Aero_Simulink_P_I_D_T ACSI_Aero_Simulink_P_I_D_P = {
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S41>/Derivative Gain'
   */
  400.0,

  /* Mask Parameter: PIDController1_D
   * Referenced by: '<S137>/Derivative Gain'
   */
  600.0,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S54>/Integral Gain'
   */
  10.0,

  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S150>/Integral Gain'
   */
  20.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S42>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S138>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_e
   * Referenced by: '<S62>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditi_e
   * Referenced by: '<S158>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S74>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController1_N
   * Referenced by: '<S170>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S81>/Proportional Gain'
   */
  700.0,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S177>/Proportional Gain'
   */
  700.0,

  /* Mask Parameter: Green_color
   * Referenced by: '<S202>/Constant'
   */
  { 1.0, 0.0, 1.0 },

  /* Mask Parameter: Yellow_color
   * Referenced by: '<S204>/Constant'
   */
  { 1.0, 1.0, 0.0 },

  /* Mask Parameter: PitchBiasRemoval_end_time
   * Referenced by: '<S203>/Step: end_time'
   */
  1.0,

  /* Mask Parameter: PitchBiasRemoval_start_time
   * Referenced by: '<S203>/Step: start_time'
   */
  0.0,

  /* Mask Parameter: PitchBiasRemoval_switch_id
   * Referenced by: '<S203>/Constant'
   */
  1.0,

  /* Mask Parameter: HILReadTimebase_clock
   * Referenced by: '<S5>/HIL Read Timebase'
   */
  0,

  /* Mask Parameter: HILReadTimebase_analog_channels
   * Referenced by: '<S5>/HIL Read Timebase'
   */
  { 0U, 1U },

  /* Mask Parameter: HILWrite_analog_channels
   * Referenced by: '<S5>/HIL Write'
   */
  { 0U, 1U },

  /* Mask Parameter: HILReadTimebase_encoder_channel
   * Referenced by: '<S5>/HIL Read Timebase'
   */
  { 2U, 3U },

  /* Mask Parameter: HILReadTimebase_other_channels
   * Referenced by: '<S5>/HIL Read Timebase'
   */
  { 4000U, 4002U, 14000U, 14001U },

  /* Mask Parameter: HILWrite_other_channels
   * Referenced by: '<S5>/HIL Write'
   */
  { 11000U, 11001U, 11002U },

  /* Mask Parameter: HILReadTimebase_samples_in_buff
   * Referenced by: '<S5>/HIL Read Timebase'
   */
  500U,

  /* Expression: 24
   * Referenced by: '<S5>/+//- 24V'
   */
  24.0,

  /* Expression: -24
   * Referenced by: '<S5>/+//- 24V'
   */
  -24.0,

  /* Computed Parameter: x_avg_n_Y0
   * Referenced by: '<S205>/x_avg_n'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S209>/unity'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S209>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S205>/Sum( k=1,n-1, x(k) )'
   */
  0.0,

  /* Expression: [0]
   * Referenced by: '<S206>/zero'
   */
  0.0,

  /* Expression: [0]
   * Referenced by: '<S207>/Vbiased'
   */
  0.0,

  /* Expression: [0]
   * Referenced by: '<S208>/Vunbiased'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S203>/Step: start_time'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S203>/Step: start_time'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S203>/Step: end_time'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S203>/Step: end_time'
   */
  1.0,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<S5>/HIL Initialize'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<S5>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<S5>/HIL Initialize'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<S5>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<S5>/HIL Initialize'
   */
  0.0,

  /* Expression: final_other_outputs
   * Referenced by: '<S5>/HIL Initialize'
   */
  { 1.0, 0.0, 0.0 },

  /* Expression: analog_input_maximums
   * Referenced by: '<S5>/HIL Initialize'
   */
  3.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<S5>/HIL Initialize'
   */
  -3.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<S5>/HIL Initialize'
   */
  24.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<S5>/HIL Initialize'
   */
  -24.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<S5>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_analog_outputs
   * Referenced by: '<S5>/HIL Initialize'
   */
  0.0,

  /* Expression: initial_other_outputs
   * Referenced by: '<S5>/HIL Initialize'
   */
  { 0.0, 1.0, 0.0 },

  /* Expression: watchdog_other_outputs
   * Referenced by: '<S5>/HIL Initialize'
   */
  { 0.0, 0.0, 1.0 },

  /* Computed Parameter: Internal_A
   * Referenced by: '<S1>/Internal'
   */
  { 1.0, 1.0, -1.7116658915672016, -0.32492547725674159, -1.0003608197651563,
    1.0, 1.0, -1.7116658915672016, -0.32492547725674159, -1.0003608197651563 },

  /* Computed Parameter: Internal_B
   * Referenced by: '<S1>/Internal'
   */
  { 0.050258454494405726, -0.12277155515299648, 0.0959479585802291,
    0.10003608197651566 },

  /* Computed Parameter: Internal_C
   * Referenced by: '<S1>/Internal'
   */
  { 1.0, 1.0 },

  /* Computed Parameter: Internal_A_i
   * Referenced by: '<S2>/Internal'
   */
  { 2294.8503325807578, -4.3575826527885733, -200.0, 3.8690457215984495E-17,
    -1.0129877295500909E-15, -2048.0, -5.761705220907701E-17,
    -1.0100942860388909E-16, 4.8828124999999991, -200.0 },

  /* Computed Parameter: Internal_B_k
   * Referenced by: '<S2>/Internal'
   */
  { 7.3790535384260566E-11, -8.7705384200551789E+6, 9.8276723682499714E+6,
    -1.7630201244568708E-10 },

  /* Computed Parameter: Internal_C_p
   * Referenced by: '<S2>/Internal'
   */
  { -0.028363260791649893, -1.2952774768141813, 0.029566692863711587,
    -1.2092912221288967, 0.014856946128959462, 0.67847867833123787,
    0.0362863957872824, -1.4841301362491004 },

  /* Computed Parameter: Internal_D
   * Referenced by: '<S2>/Internal'
   */
  { 59519.286306963331, -57086.942076019819, 73046.396831273174,
    29902.68394458179 },

  /* Expression: [0 0]
   * Referenced by: '<S5>/No Control'
   */
  { 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S5>/Motor Enable'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/LED Colour'
   */
  0.0,

  /* Expression: [2*pi/2048 2*pi/4096]
   * Referenced by: '<S5>/Counts to rads'
   */
  { 0.0030679615757712823, 0.0015339807878856412 },

  /* Expression: pi/6
   * Referenced by: '<Root>/Pitch ref'
   */
  0.52359877559829882,

  /* Computed Parameter: Pitchref_Frequency
   * Referenced by: '<Root>/Pitch ref'
   */
  0.063661977236758135,

  /* Expression: 0
   * Referenced by: '<Root>/Yaw ref'
   */
  0.0,

  /* Computed Parameter: Yawref_Frequency
   * Referenced by: '<Root>/Yaw ref'
   */
  0.079577471545947673,

  /* Expression: 25
   * Referenced by: '<Root>/Saturation'
   */
  25.0,

  /* Expression: -25
   * Referenced by: '<Root>/Saturation'
   */
  -25.0,

  /* Expression: 25
   * Referenced by: '<Root>/Saturation1'
   */
  25.0,

  /* Expression: -25
   * Referenced by: '<Root>/Saturation1'
   */
  -25.0,

  /* Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIConfiguration
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOWatchdog
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<S5>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<S5>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_DOChannels
   * Referenced by: '<S5>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<S5>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<S5>/HIL Initialize'
   */
  4U,

  /* Computed Parameter: HILInitialize_OOChannels
   * Referenced by: '<S5>/HIL Initialize'
   */
  { 11000U, 11001U, 11002U },

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<S5>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<S5>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<S5>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<S5>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<S5>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<S5>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<S5>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<S5>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<S5>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILReadTimebase_Active
   * Referenced by: '<S5>/HIL Read Timebase'
   */
  1,

  /* Computed Parameter: HILWrite_Active
   * Referenced by: '<S5>/HIL Write'
   */
  0
};
