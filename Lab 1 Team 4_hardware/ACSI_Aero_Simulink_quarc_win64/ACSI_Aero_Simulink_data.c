/*
 * ACSI_Aero_Simulink_data.c
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

/* Block parameters (default storage) */
P_ACSI_Aero_Simulink_T ACSI_Aero_Simulink_P = {
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S35>/Derivative Gain'
   */
  400.0,

  /* Mask Parameter: PIDController1_D
   * Referenced by: '<S131>/Derivative Gain'
   */
  600.0,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S48>/Integral Gain'
   */
  10.0,

  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S144>/Integral Gain'
   */
  20.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S36>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S132>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_e
   * Referenced by: '<S56>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditi_e
   * Referenced by: '<S152>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S68>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController1_N
   * Referenced by: '<S164>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S75>/Proportional Gain'
   */
  700.0,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S171>/Proportional Gain'
   */
  700.0,

  /* Mask Parameter: Green_color
   * Referenced by: '<S196>/Constant'
   */
  { 1.0, 0.0, 1.0 },

  /* Mask Parameter: Yellow_color
   * Referenced by: '<S198>/Constant'
   */
  { 1.0, 1.0, 0.0 },

  /* Mask Parameter: PitchBiasRemoval_end_time
   * Referenced by: '<S197>/Step: end_time'
   */
  1.0,

  /* Mask Parameter: PitchBiasRemoval_start_time
   * Referenced by: '<S197>/Step: start_time'
   */
  0.0,

  /* Mask Parameter: PitchBiasRemoval_switch_id
   * Referenced by: '<S197>/Constant'
   */
  1.0,

  /* Mask Parameter: HILReadTimebase_clock
   * Referenced by: '<S3>/HIL Read Timebase'
   */
  0,

  /* Mask Parameter: HILReadTimebase_analog_channels
   * Referenced by: '<S3>/HIL Read Timebase'
   */
  { 0U, 1U },

  /* Mask Parameter: HILWrite_analog_channels
   * Referenced by: '<S3>/HIL Write'
   */
  { 0U, 1U },

  /* Mask Parameter: HILReadTimebase_encoder_channel
   * Referenced by: '<S3>/HIL Read Timebase'
   */
  { 2U, 3U },

  /* Mask Parameter: HILReadTimebase_other_channels
   * Referenced by: '<S3>/HIL Read Timebase'
   */
  { 4000U, 4002U, 14000U, 14001U },

  /* Mask Parameter: HILWrite_other_channels
   * Referenced by: '<S3>/HIL Write'
   */
  { 11000U, 11001U, 11002U },

  /* Mask Parameter: HILReadTimebase_samples_in_buff
   * Referenced by: '<S3>/HIL Read Timebase'
   */
  500U,

  /* Expression: 25
   * Referenced by: '<Root>/Saturation1'
   */
  25.0,

  /* Expression: -25
   * Referenced by: '<Root>/Saturation1'
   */
  -25.0,

  /* Expression: 25
   * Referenced by: '<Root>/Saturation'
   */
  25.0,

  /* Expression: -25
   * Referenced by: '<Root>/Saturation'
   */
  -25.0,

  /* Expression: 24
   * Referenced by: '<S3>/+//- 24V'
   */
  24.0,

  /* Expression: -24
   * Referenced by: '<S3>/+//- 24V'
   */
  -24.0,

  /* Computed Parameter: x_avg_n_Y0
   * Referenced by: '<S199>/x_avg_n'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S203>/unity'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S203>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S199>/Sum( k=1,n-1, x(k) )'
   */
  0.0,

  /* Expression: [0]
   * Referenced by: '<S200>/zero'
   */
  0.0,

  /* Expression: [0]
   * Referenced by: '<S201>/Vbiased'
   */
  0.0,

  /* Expression: [0]
   * Referenced by: '<S202>/Vunbiased'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S197>/Step: start_time'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S197>/Step: start_time'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S197>/Step: end_time'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S197>/Step: end_time'
   */
  1.0,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<S3>/HIL Initialize'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<S3>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<S3>/HIL Initialize'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<S3>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<S3>/HIL Initialize'
   */
  0.0,

  /* Expression: final_other_outputs
   * Referenced by: '<S3>/HIL Initialize'
   */
  { 1.0, 0.0, 0.0 },

  /* Expression: analog_input_maximums
   * Referenced by: '<S3>/HIL Initialize'
   */
  3.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<S3>/HIL Initialize'
   */
  -3.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<S3>/HIL Initialize'
   */
  24.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<S3>/HIL Initialize'
   */
  -24.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<S3>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_analog_outputs
   * Referenced by: '<S3>/HIL Initialize'
   */
  0.0,

  /* Expression: initial_other_outputs
   * Referenced by: '<S3>/HIL Initialize'
   */
  { 0.0, 1.0, 0.0 },

  /* Expression: watchdog_other_outputs
   * Referenced by: '<S3>/HIL Initialize'
   */
  { 0.0, 0.0, 1.0 },

  /* Expression: [2*pi/2048 2*pi/4096]
   * Referenced by: '<S3>/Counts to rads'
   */
  { 0.0030679615757712823, 0.0015339807878856412 },

  /* Expression: 0
   * Referenced by: '<Root>/Pitch ref'
   */
  0.0,

  /* Computed Parameter: Pitchref_Frequency
   * Referenced by: '<Root>/Pitch ref'
   */
  0.063661977236758135,

  /* Expression: pi/4
   * Referenced by: '<Root>/Yaw ref'
   */
  0.78539816339744828,

  /* Computed Parameter: Yawref_Frequency
   * Referenced by: '<Root>/Yaw ref'
   */
  0.079577471545947673,

  /* Expression: [0 0]
   * Referenced by: '<S3>/No Control'
   */
  { 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S3>/Motor Enable'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/LED Colour'
   */
  0.0,

  /* Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIConfiguration
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOWatchdog
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<S3>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<S3>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_DOChannels
   * Referenced by: '<S3>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<S3>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<S3>/HIL Initialize'
   */
  4U,

  /* Computed Parameter: HILInitialize_OOChannels
   * Referenced by: '<S3>/HIL Initialize'
   */
  { 11000U, 11001U, 11002U },

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<S3>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<S3>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<S3>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<S3>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<S3>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<S3>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<S3>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<S3>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<S3>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILReadTimebase_Active
   * Referenced by: '<S3>/HIL Read Timebase'
   */
  1,

  /* Computed Parameter: HILWrite_Active
   * Referenced by: '<S3>/HIL Write'
   */
  0
};
