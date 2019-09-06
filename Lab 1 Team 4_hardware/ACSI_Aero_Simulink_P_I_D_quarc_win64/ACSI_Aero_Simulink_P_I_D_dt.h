/*
 * ACSI_Aero_Simulink_P_I_D_dt.h
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
  { (char_T *)(&ACSI_Aero_Simulink_P_I_D_B.Internal[0]), 0, 0, 19 }
  ,

  { (char_T *)(&ACSI_Aero_Simulink_P_I_D_DW.UnitDelay_DSTATE), 0, 0, 16 },

  { (char_T *)(&ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card), 14, 0, 1 },

  { (char_T *)(&ACSI_Aero_Simulink_P_I_D_DW.HILReadTimebase_Task), 15, 0, 1 },

  { (char_T *)(&ACSI_Aero_Simulink_P_I_D_DW.HILWrite_PWORK), 11, 0, 5 },

  { (char_T *)(&ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_ClockModes), 6, 0, 15
  },

  { (char_T *)(&ACSI_Aero_Simulink_P_I_D_DW.SwitchCase_ActiveSubsystem), 2, 0, 5
  },

  { (char_T *)(&ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_DOBits[0]), 8, 0, 3 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  8U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&ACSI_Aero_Simulink_P_I_D_P.PIDController_D), 0, 0, 21 },

  { (char_T *)(&ACSI_Aero_Simulink_P_I_D_P.HILReadTimebase_clock), 6, 0, 1 },

  { (char_T *)(&ACSI_Aero_Simulink_P_I_D_P.HILReadTimebase_analog_channels[0]),
    7, 0, 14 },

  { (char_T *)(&ACSI_Aero_Simulink_P_I_D_P.u4V_UpperSat), 0, 0, 89 },

  { (char_T *)(&ACSI_Aero_Simulink_P_I_D_P.HILInitialize_CKChannels), 6, 0, 4 },

  { (char_T *)(&ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AIChannels[0]), 7, 0,
    14 },

  { (char_T *)(&ACSI_Aero_Simulink_P_I_D_P.HILInitialize_Active), 8, 0, 37 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  7U,
  rtPTransitions
};

/* [EOF] ACSI_Aero_Simulink_P_I_D_dt.h */
