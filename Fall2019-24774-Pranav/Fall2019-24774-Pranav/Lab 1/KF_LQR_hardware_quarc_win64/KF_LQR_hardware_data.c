/*
 * KF_LQR_hardware_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "KF_LQR_hardware".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Wed Sep 18 00:02:53 2019
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "KF_LQR_hardware.h"
#include "KF_LQR_hardware_private.h"

/* Block parameters (default storage) */
P_KF_LQR_hardware_T KF_LQR_hardware_P = {
  /* Mask Parameter: Green_color
   * Referenced by: '<S57>/Constant'
   */
  { 0.0, 1.0, 0.0 },

  /* Mask Parameter: Yellow_color
   * Referenced by: '<S59>/Constant'
   */
  { 1.0, 1.0, 0.0 },

  /* Mask Parameter: PitchBiasRemoval_end_time
   * Referenced by: '<S58>/Step: end_time'
   */
  1.0,

  /* Mask Parameter: PitchBiasRemoval_start_time
   * Referenced by: '<S58>/Step: start_time'
   */
  0.0,

  /* Mask Parameter: PitchBiasRemoval_switch_id
   * Referenced by: '<S58>/Constant'
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

  /* Expression: 0
   * Referenced by: '<S48>/L*(y[k]-yhat[k|k-1])'
   */
  0.0,

  /* Expression: 24
   * Referenced by: '<S5>/+//- 24V'
   */
  24.0,

  /* Expression: -24
   * Referenced by: '<S5>/+//- 24V'
   */
  -24.0,

  /* Computed Parameter: x_avg_n_Y0
   * Referenced by: '<S60>/x_avg_n'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S64>/unity'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S64>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S60>/Sum( k=1,n-1, x(k) )'
   */
  0.0,

  /* Expression: [0]
   * Referenced by: '<S61>/zero'
   */
  0.0,

  /* Expression: [0]
   * Referenced by: '<S62>/Vbiased'
   */
  0.0,

  /* Expression: [0]
   * Referenced by: '<S63>/Vunbiased'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S58>/Step: start_time'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S58>/Step: start_time'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S58>/Step: end_time'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S58>/Step: end_time'
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

  /* Expression: pi/6
   * Referenced by: '<Root>/Pitch Ref'
   */
  0.52359877559829882,

  /* Computed Parameter: PitchRef_Frequency
   * Referenced by: '<Root>/Pitch Ref'
   */
  0.063661977236758135,

  /* Expression: pi/4
   * Referenced by: '<Root>/Yaw Ref'
   */
  0.78539816339744828,

  /* Computed Parameter: YawRef_Frequency
   * Referenced by: '<Root>/Yaw Ref'
   */
  0.079577471545947673,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant1'
   */
  0.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S1>/X0'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Computed Parameter: Internal_D
   * Referenced by: '<S2>/Internal'
   */
  { 270.80958063526975, -82.743456024453948, 56.138424835860135,
    -27.63545791166737, 296.10101271614894, 41.856371379657617,
    63.672144684295674, 14.201127557633344 },

  /* Expression: 25
   * Referenced by: '<Root>/Saturation'
   */
  25.0,

  /* Expression: -25
   * Referenced by: '<Root>/Saturation'
   */
  -25.0,

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

  /* Computed Parameter: Internal_A
   * Referenced by: '<S3>/Internal'
   */
  -50.0,

  /* Computed Parameter: Internal_B
   * Referenced by: '<S3>/Internal'
   */
  64.0,

  /* Computed Parameter: Internal_C
   * Referenced by: '<S3>/Internal'
   */
  -39.0625,

  /* Computed Parameter: Internal_D_p
   * Referenced by: '<S3>/Internal'
   */
  50.0,

  /* Expression: 0.0
   * Referenced by: '<S3>/Internal'
   */
  0.0,

  /* Computed Parameter: Internal_A_n
   * Referenced by: '<S4>/Internal'
   */
  -50.0,

  /* Computed Parameter: Internal_B_d
   * Referenced by: '<S4>/Internal'
   */
  64.0,

  /* Computed Parameter: Internal_C_i
   * Referenced by: '<S4>/Internal'
   */
  -39.0625,

  /* Computed Parameter: Internal_D_a
   * Referenced by: '<S4>/Internal'
   */
  50.0,

  /* Expression: 0.0
   * Referenced by: '<S4>/Internal'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S1>/A'
   */
  { 0.0, 0.0, -1.7116658915672016, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    -0.32492547725674159, 0.0, 0.0, 1.0, 0.0, -1.0003608197651563 },

  /* Expression: pInitialization.B
   * Referenced by: '<S1>/B'
   */
  { 0.0, 0.0, 0.050258454494405726, -0.12277155515299648, 0.0, 0.0,
    0.0959479585802291, 0.10003608197651566 },

  /* Expression: pInitialization.C
   * Referenced by: '<S1>/C'
   */
  { 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: pInitialization.L
   * Referenced by: '<S6>/KalmanGainL'
   */
  { 274.57979069954524, 7.9598464169144345E-15, 197.03073030303031,
    2.8892144828648157E-15, 7.9598464169144345E-15, 274.27357028979139,
    -2.4686288082427156E-15, 112.99567975450461 },

  /* Expression: pInitialization.D
   * Referenced by: '<S1>/D'
   */
  { 0.0, 0.0, 0.0, 0.0 },

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
  0,

  /* Expression: true()
   * Referenced by: '<S1>/Enable'
   */
  1
};
