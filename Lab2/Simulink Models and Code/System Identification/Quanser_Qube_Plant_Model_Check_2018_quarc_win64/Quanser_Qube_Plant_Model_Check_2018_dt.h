/*
 * Quanser_Qube_Plant_Model_Check_2018_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Quanser_Qube_Plant_Model_Check_2018".
 *
 * Model version              : 1.458
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Wed Oct  2 19:44:28 2019
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
  { (char_T *)(&Quanser_Qube_Plant_Model_Chec_B.HILReadEncoderTimebase_o1), 0, 0,
    20 }
  ,

  { (char_T *)(&Quanser_Qube_Plant_Model_Che_DW.HILInitialize_FilterFrequency[0]),
    0, 0, 2 },

  { (char_T *)(&Quanser_Qube_Plant_Model_Che_DW.HILInitialize_Card), 14, 0, 1 },

  { (char_T *)(&Quanser_Qube_Plant_Model_Che_DW.HILReadEncoderTimebase_Task), 15,
    0, 1 },

  { (char_T *)(&Quanser_Qube_Plant_Model_Che_DW.HILWriteAnalog_PWORK), 11, 0, 10
  },

  { (char_T *)(&Quanser_Qube_Plant_Model_Che_DW.HILInitialize_ClockModes), 6, 0,
    8 },

  { (char_T *)(&Quanser_Qube_Plant_Model_Che_DW.ToFile_IWORK.Count), 10, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  7U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Quanser_Qube_Plant_Model_Chec_P.HILReadEncoderTimebase_clock), 6,
    0, 1 },

  { (char_T *)(&Quanser_Qube_Plant_Model_Chec_P.HILReadEncoderTimebase_channels
               [0]), 7, 0, 4 },

  { (char_T *)(&Quanser_Qube_Plant_Model_Chec_P.HILInitialize_OOTerminate), 0, 0,
    42 },

  { (char_T *)(&Quanser_Qube_Plant_Model_Chec_P.HILInitialize_CKChannels), 6, 0,
    3 },

  { (char_T *)(&Quanser_Qube_Plant_Model_Chec_P.HILInitialize_AIChannels), 7, 0,
    9 },

  { (char_T *)(&Quanser_Qube_Plant_Model_Chec_P.HILInitialize_Active), 8, 0, 37
  }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] Quanser_Qube_Plant_Model_Check_2018_dt.h */
