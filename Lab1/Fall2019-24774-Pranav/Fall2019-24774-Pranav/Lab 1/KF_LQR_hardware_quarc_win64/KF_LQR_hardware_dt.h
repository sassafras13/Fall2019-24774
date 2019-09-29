/*
 * KF_LQR_hardware_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_card),
  sizeof(t_task)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_card",
  "t_task"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&KF_LQR_hardware_B.PitchRef), 0, 0, 57 }
  ,

  { (char_T *)(&KF_LQR_hardware_DW.UnitDelay_DSTATE), 0, 0, 16 },

  { (char_T *)(&KF_LQR_hardware_DW.HILInitialize_Card), 14, 0, 1 },

  { (char_T *)(&KF_LQR_hardware_DW.HILReadTimebase_Task), 15, 0, 1 },

  { (char_T *)(&KF_LQR_hardware_DW.HILWrite_PWORK), 11, 0, 14 },

  { (char_T *)(&KF_LQR_hardware_DW.HILInitialize_ClockModes), 6, 0, 15 },

  { (char_T *)(&KF_LQR_hardware_DW.MemoryX_IWORK), 10, 0, 1 },

  { (char_T *)(&KF_LQR_hardware_DW.SwitchCase_ActiveSubsystem), 2, 0, 6 },

  { (char_T *)(&KF_LQR_hardware_DW.HILInitialize_DOBits[0]), 8, 0, 4 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  9U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&KF_LQR_hardware_P.Green_color[0]), 0, 0, 9 },

  { (char_T *)(&KF_LQR_hardware_P.HILReadTimebase_clock), 6, 0, 1 },

  { (char_T *)(&KF_LQR_hardware_P.HILReadTimebase_analog_channels[0]), 7, 0, 14
  },

  { (char_T *)(&KF_LQR_hardware_P.Lykyhatkk1_Y0), 0, 0, 114 },

  { (char_T *)(&KF_LQR_hardware_P.HILInitialize_CKChannels), 6, 0, 4 },

  { (char_T *)(&KF_LQR_hardware_P.HILInitialize_AIChannels[0]), 7, 0, 14 },

  { (char_T *)(&KF_LQR_hardware_P.HILInitialize_Active), 8, 0, 38 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  7U,
  rtPTransitions
};

/* [EOF] KF_LQR_hardware_dt.h */
