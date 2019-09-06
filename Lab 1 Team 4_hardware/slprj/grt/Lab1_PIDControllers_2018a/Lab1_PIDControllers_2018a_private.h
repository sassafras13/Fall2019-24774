/*
 * Lab1_PIDControllers_2018a_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Lab1_PIDControllers_2018a".
 *
 * Model version              : 1.5
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Fri Sep  6 20:40:00 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Lab1_PIDControllers_2018a_private_h_
#define RTW_HEADER_Lab1_PIDControllers_2018a_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
# define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

extern P_Lab1_PIDControllers_2018a_T Lab1_PIDControllers_2018a_P;

#endif                                 /* RTW_HEADER_Lab1_PIDControllers_2018a_private_h_ */
