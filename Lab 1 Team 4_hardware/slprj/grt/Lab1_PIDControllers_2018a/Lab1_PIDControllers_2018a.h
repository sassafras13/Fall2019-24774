/*
 * Code generation for system model 'Lab1_PIDControllers_2018a'
 * For more details, see corresponding source file Lab1_PIDControllers_2018a.c
 *
 */

#ifndef RTW_HEADER_Lab1_PIDControllers_2018a_h_
#define RTW_HEADER_Lab1_PIDControllers_2018a_h_
#include <string.h>
#ifndef Lab1_PIDControllers_2018a_COMMON_INCLUDES_
# define Lab1_PIDControllers_2018a_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Lab1_PIDControllers_2018a_COMMON_INCLUDES_ */

#include "Lab1_PIDControllers_2018a_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Block states (default storage) for model 'Lab1_PIDControllers_2018a' */
typedef struct {
  real_T Filter_DSTATE;                /* '<S39>/Filter' */
  real_T Integrator_DSTATE;            /* '<S57>/Integrator' */
  real_T Integrator_DSTATE_e;          /* '<S153>/Integrator' */
  real_T Filter_DSTATE_j;              /* '<S135>/Filter' */
} DW_Lab1_PIDControllers_2018_f_T;

/* Parameters (default storage) */
struct P_Lab1_PIDControllers_2018a_T_ {
  real_T PitchPID_D;                   /* Mask Parameter: PitchPID_D
                                        * Referenced by: '<S34>/Derivative Gain'
                                        */
  real_T YawPID_D;                     /* Mask Parameter: YawPID_D
                                        * Referenced by: '<S130>/Derivative Gain'
                                        */
  real_T PitchPID_I;                   /* Mask Parameter: PitchPID_I
                                        * Referenced by: '<S47>/Integral Gain'
                                        */
  real_T YawPID_I;                     /* Mask Parameter: YawPID_I
                                        * Referenced by: '<S143>/Integral Gain'
                                        */
  real_T PitchPID_InitialConditionForFil;/* Mask Parameter: PitchPID_InitialConditionForFil
                                          * Referenced by: '<S39>/Filter'
                                          */
  real_T YawPID_InitialConditionForFilte;/* Mask Parameter: YawPID_InitialConditionForFilte
                                          * Referenced by: '<S135>/Filter'
                                          */
  real_T PitchPID_InitialConditionForInt;/* Mask Parameter: PitchPID_InitialConditionForInt
                                          * Referenced by: '<S57>/Integrator'
                                          */
  real_T YawPID_InitialConditionForInteg;/* Mask Parameter: YawPID_InitialConditionForInteg
                                          * Referenced by: '<S153>/Integrator'
                                          */
  real_T PitchPID_N;                   /* Mask Parameter: PitchPID_N
                                        * Referenced by: '<S67>/Filter Coefficient'
                                        */
  real_T YawPID_N;                     /* Mask Parameter: YawPID_N
                                        * Referenced by: '<S163>/Filter Coefficient'
                                        */
  real_T PitchPID_P;                   /* Mask Parameter: PitchPID_P
                                        * Referenced by: '<S74>/Proportional Gain'
                                        */
  real_T YawPID_P;                     /* Mask Parameter: YawPID_P
                                        * Referenced by: '<S170>/Proportional Gain'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S39>/Filter'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S57>/Integrator'
                                        */
  real_T Integrator_gainval_p;         /* Computed Parameter: Integrator_gainval_p
                                        * Referenced by: '<S153>/Integrator'
                                        */
  real_T Filter_gainval_i;             /* Computed Parameter: Filter_gainval_i
                                        * Referenced by: '<S135>/Filter'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Lab1_PIDControllers_2_T {
  const char_T **errorStatus;
};

typedef struct {
  DW_Lab1_PIDControllers_2018_f_T rtdw;
  RT_MODEL_Lab1_PIDControllers__T rtm;
} MdlrefDW_Lab1_PIDControllers__T;

/* Model reference registration function */
extern void Lab1_PIDControllers__initialize(const char_T **rt_errorStatus,
  RT_MODEL_Lab1_PIDControllers__T *const Lab1_PIDControllers_2018a_M,
  DW_Lab1_PIDControllers_2018_f_T *localDW);
extern void Lab1_PIDControllers_2018a_Init(DW_Lab1_PIDControllers_2018_f_T
  *localDW);
extern void Lab1_PIDControllers_2018a_Reset(DW_Lab1_PIDControllers_2018_f_T
  *localDW);
extern void Lab1_PIDControllers_2018a(const real_T *rtu_YawInput, const real_T
  *rtu_PitchInput, real_T rty_CombinedOutput[2], DW_Lab1_PIDControllers_2018_f_T
  *localDW);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Lab1_PIDControllers_2018a'
 * '<S1>'   : 'Lab1_PIDControllers_2018a/Pitch PID'
 * '<S2>'   : 'Lab1_PIDControllers_2018a/Yaw PID'
 * '<S3>'   : 'Lab1_PIDControllers_2018a/Pitch PID/Anti-windup'
 * '<S4>'   : 'Lab1_PIDControllers_2018a/Pitch PID/D Gain'
 * '<S5>'   : 'Lab1_PIDControllers_2018a/Pitch PID/Filter'
 * '<S6>'   : 'Lab1_PIDControllers_2018a/Pitch PID/Filter ICs'
 * '<S7>'   : 'Lab1_PIDControllers_2018a/Pitch PID/I Gain'
 * '<S8>'   : 'Lab1_PIDControllers_2018a/Pitch PID/Ideal P Gain'
 * '<S9>'   : 'Lab1_PIDControllers_2018a/Pitch PID/Ideal P Gain Fdbk'
 * '<S10>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Integrator'
 * '<S11>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Integrator ICs'
 * '<S12>'  : 'Lab1_PIDControllers_2018a/Pitch PID/N Copy'
 * '<S13>'  : 'Lab1_PIDControllers_2018a/Pitch PID/N Gain'
 * '<S14>'  : 'Lab1_PIDControllers_2018a/Pitch PID/P Copy'
 * '<S15>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Parallel P Gain'
 * '<S16>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Reset Signal'
 * '<S17>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Saturation'
 * '<S18>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Saturation Fdbk'
 * '<S19>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Sum'
 * '<S20>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Sum Fdbk'
 * '<S21>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Tracking Mode'
 * '<S22>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Tracking Mode Sum'
 * '<S23>'  : 'Lab1_PIDControllers_2018a/Pitch PID/postSat Signal'
 * '<S24>'  : 'Lab1_PIDControllers_2018a/Pitch PID/preSat Signal'
 * '<S25>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Anti-windup/Back Calculation'
 * '<S26>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Anti-windup/Cont. Clamping Ideal'
 * '<S27>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Anti-windup/Cont. Clamping Parallel'
 * '<S28>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Anti-windup/Disabled'
 * '<S29>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Anti-windup/Disc. Clamping Ideal'
 * '<S30>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Anti-windup/Disc. Clamping Parallel'
 * '<S31>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Anti-windup/Passthrough'
 * '<S32>'  : 'Lab1_PIDControllers_2018a/Pitch PID/D Gain/Disabled'
 * '<S33>'  : 'Lab1_PIDControllers_2018a/Pitch PID/D Gain/External Parameters'
 * '<S34>'  : 'Lab1_PIDControllers_2018a/Pitch PID/D Gain/Internal Parameters'
 * '<S35>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Filter/Cont. Filter'
 * '<S36>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Filter/Differentiator'
 * '<S37>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Filter/Disabled'
 * '<S38>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Filter/Disc. Backward Euler Filter'
 * '<S39>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Filter/Disc. Forward Euler Filter'
 * '<S40>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Filter/Disc. Trapezoidal Filter'
 * '<S41>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Filter ICs/Disabled'
 * '<S42>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Filter ICs/External IC'
 * '<S43>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Filter ICs/Internal IC - Differentiator'
 * '<S44>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Filter ICs/Internal IC - Filter'
 * '<S45>'  : 'Lab1_PIDControllers_2018a/Pitch PID/I Gain/Disabled'
 * '<S46>'  : 'Lab1_PIDControllers_2018a/Pitch PID/I Gain/External Parameters'
 * '<S47>'  : 'Lab1_PIDControllers_2018a/Pitch PID/I Gain/Internal Parameters'
 * '<S48>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Ideal P Gain/External Parameters'
 * '<S49>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Ideal P Gain/Internal Parameters'
 * '<S50>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Ideal P Gain/Passthrough'
 * '<S51>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Ideal P Gain Fdbk/Disabled'
 * '<S52>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Ideal P Gain Fdbk/External Parameters'
 * '<S53>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Ideal P Gain Fdbk/Internal Parameters'
 * '<S54>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Ideal P Gain Fdbk/Passthrough'
 * '<S55>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Integrator/Continuous'
 * '<S56>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Integrator/Disabled'
 * '<S57>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Integrator/Discrete'
 * '<S58>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Integrator ICs/Disabled'
 * '<S59>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Integrator ICs/External IC'
 * '<S60>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Integrator ICs/Internal IC'
 * '<S61>'  : 'Lab1_PIDControllers_2018a/Pitch PID/N Copy/Disabled'
 * '<S62>'  : 'Lab1_PIDControllers_2018a/Pitch PID/N Copy/Disabled wSignal Specification'
 * '<S63>'  : 'Lab1_PIDControllers_2018a/Pitch PID/N Copy/External Parameters'
 * '<S64>'  : 'Lab1_PIDControllers_2018a/Pitch PID/N Copy/Internal Parameters'
 * '<S65>'  : 'Lab1_PIDControllers_2018a/Pitch PID/N Gain/Disabled'
 * '<S66>'  : 'Lab1_PIDControllers_2018a/Pitch PID/N Gain/External Parameters'
 * '<S67>'  : 'Lab1_PIDControllers_2018a/Pitch PID/N Gain/Internal Parameters'
 * '<S68>'  : 'Lab1_PIDControllers_2018a/Pitch PID/N Gain/Passthrough'
 * '<S69>'  : 'Lab1_PIDControllers_2018a/Pitch PID/P Copy/Disabled'
 * '<S70>'  : 'Lab1_PIDControllers_2018a/Pitch PID/P Copy/External Parameters Ideal'
 * '<S71>'  : 'Lab1_PIDControllers_2018a/Pitch PID/P Copy/Internal Parameters Ideal'
 * '<S72>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Parallel P Gain/Disabled'
 * '<S73>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Parallel P Gain/External Parameters'
 * '<S74>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Parallel P Gain/Internal Parameters'
 * '<S75>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Parallel P Gain/Passthrough'
 * '<S76>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Reset Signal/Disabled'
 * '<S77>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Reset Signal/External Reset'
 * '<S78>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Saturation/Enabled'
 * '<S79>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Saturation/Passthrough'
 * '<S80>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Saturation Fdbk/Disabled'
 * '<S81>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Saturation Fdbk/Enabled'
 * '<S82>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Saturation Fdbk/Passthrough'
 * '<S83>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Sum/Passthrough_I'
 * '<S84>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Sum/Passthrough_P'
 * '<S85>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Sum/Sum_PD'
 * '<S86>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Sum/Sum_PI'
 * '<S87>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Sum/Sum_PID'
 * '<S88>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Sum Fdbk/Disabled'
 * '<S89>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Sum Fdbk/Enabled'
 * '<S90>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Sum Fdbk/Passthrough'
 * '<S91>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Tracking Mode/Disabled'
 * '<S92>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Tracking Mode/Enabled'
 * '<S93>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Tracking Mode Sum/Passthrough'
 * '<S94>'  : 'Lab1_PIDControllers_2018a/Pitch PID/Tracking Mode Sum/Tracking Mode'
 * '<S95>'  : 'Lab1_PIDControllers_2018a/Pitch PID/postSat Signal/Feedback_Path'
 * '<S96>'  : 'Lab1_PIDControllers_2018a/Pitch PID/postSat Signal/Forward_Path'
 * '<S97>'  : 'Lab1_PIDControllers_2018a/Pitch PID/preSat Signal/Feedback_Path'
 * '<S98>'  : 'Lab1_PIDControllers_2018a/Pitch PID/preSat Signal/Forward_Path'
 * '<S99>'  : 'Lab1_PIDControllers_2018a/Yaw PID/Anti-windup'
 * '<S100>' : 'Lab1_PIDControllers_2018a/Yaw PID/D Gain'
 * '<S101>' : 'Lab1_PIDControllers_2018a/Yaw PID/Filter'
 * '<S102>' : 'Lab1_PIDControllers_2018a/Yaw PID/Filter ICs'
 * '<S103>' : 'Lab1_PIDControllers_2018a/Yaw PID/I Gain'
 * '<S104>' : 'Lab1_PIDControllers_2018a/Yaw PID/Ideal P Gain'
 * '<S105>' : 'Lab1_PIDControllers_2018a/Yaw PID/Ideal P Gain Fdbk'
 * '<S106>' : 'Lab1_PIDControllers_2018a/Yaw PID/Integrator'
 * '<S107>' : 'Lab1_PIDControllers_2018a/Yaw PID/Integrator ICs'
 * '<S108>' : 'Lab1_PIDControllers_2018a/Yaw PID/N Copy'
 * '<S109>' : 'Lab1_PIDControllers_2018a/Yaw PID/N Gain'
 * '<S110>' : 'Lab1_PIDControllers_2018a/Yaw PID/P Copy'
 * '<S111>' : 'Lab1_PIDControllers_2018a/Yaw PID/Parallel P Gain'
 * '<S112>' : 'Lab1_PIDControllers_2018a/Yaw PID/Reset Signal'
 * '<S113>' : 'Lab1_PIDControllers_2018a/Yaw PID/Saturation'
 * '<S114>' : 'Lab1_PIDControllers_2018a/Yaw PID/Saturation Fdbk'
 * '<S115>' : 'Lab1_PIDControllers_2018a/Yaw PID/Sum'
 * '<S116>' : 'Lab1_PIDControllers_2018a/Yaw PID/Sum Fdbk'
 * '<S117>' : 'Lab1_PIDControllers_2018a/Yaw PID/Tracking Mode'
 * '<S118>' : 'Lab1_PIDControllers_2018a/Yaw PID/Tracking Mode Sum'
 * '<S119>' : 'Lab1_PIDControllers_2018a/Yaw PID/postSat Signal'
 * '<S120>' : 'Lab1_PIDControllers_2018a/Yaw PID/preSat Signal'
 * '<S121>' : 'Lab1_PIDControllers_2018a/Yaw PID/Anti-windup/Back Calculation'
 * '<S122>' : 'Lab1_PIDControllers_2018a/Yaw PID/Anti-windup/Cont. Clamping Ideal'
 * '<S123>' : 'Lab1_PIDControllers_2018a/Yaw PID/Anti-windup/Cont. Clamping Parallel'
 * '<S124>' : 'Lab1_PIDControllers_2018a/Yaw PID/Anti-windup/Disabled'
 * '<S125>' : 'Lab1_PIDControllers_2018a/Yaw PID/Anti-windup/Disc. Clamping Ideal'
 * '<S126>' : 'Lab1_PIDControllers_2018a/Yaw PID/Anti-windup/Disc. Clamping Parallel'
 * '<S127>' : 'Lab1_PIDControllers_2018a/Yaw PID/Anti-windup/Passthrough'
 * '<S128>' : 'Lab1_PIDControllers_2018a/Yaw PID/D Gain/Disabled'
 * '<S129>' : 'Lab1_PIDControllers_2018a/Yaw PID/D Gain/External Parameters'
 * '<S130>' : 'Lab1_PIDControllers_2018a/Yaw PID/D Gain/Internal Parameters'
 * '<S131>' : 'Lab1_PIDControllers_2018a/Yaw PID/Filter/Cont. Filter'
 * '<S132>' : 'Lab1_PIDControllers_2018a/Yaw PID/Filter/Differentiator'
 * '<S133>' : 'Lab1_PIDControllers_2018a/Yaw PID/Filter/Disabled'
 * '<S134>' : 'Lab1_PIDControllers_2018a/Yaw PID/Filter/Disc. Backward Euler Filter'
 * '<S135>' : 'Lab1_PIDControllers_2018a/Yaw PID/Filter/Disc. Forward Euler Filter'
 * '<S136>' : 'Lab1_PIDControllers_2018a/Yaw PID/Filter/Disc. Trapezoidal Filter'
 * '<S137>' : 'Lab1_PIDControllers_2018a/Yaw PID/Filter ICs/Disabled'
 * '<S138>' : 'Lab1_PIDControllers_2018a/Yaw PID/Filter ICs/External IC'
 * '<S139>' : 'Lab1_PIDControllers_2018a/Yaw PID/Filter ICs/Internal IC - Differentiator'
 * '<S140>' : 'Lab1_PIDControllers_2018a/Yaw PID/Filter ICs/Internal IC - Filter'
 * '<S141>' : 'Lab1_PIDControllers_2018a/Yaw PID/I Gain/Disabled'
 * '<S142>' : 'Lab1_PIDControllers_2018a/Yaw PID/I Gain/External Parameters'
 * '<S143>' : 'Lab1_PIDControllers_2018a/Yaw PID/I Gain/Internal Parameters'
 * '<S144>' : 'Lab1_PIDControllers_2018a/Yaw PID/Ideal P Gain/External Parameters'
 * '<S145>' : 'Lab1_PIDControllers_2018a/Yaw PID/Ideal P Gain/Internal Parameters'
 * '<S146>' : 'Lab1_PIDControllers_2018a/Yaw PID/Ideal P Gain/Passthrough'
 * '<S147>' : 'Lab1_PIDControllers_2018a/Yaw PID/Ideal P Gain Fdbk/Disabled'
 * '<S148>' : 'Lab1_PIDControllers_2018a/Yaw PID/Ideal P Gain Fdbk/External Parameters'
 * '<S149>' : 'Lab1_PIDControllers_2018a/Yaw PID/Ideal P Gain Fdbk/Internal Parameters'
 * '<S150>' : 'Lab1_PIDControllers_2018a/Yaw PID/Ideal P Gain Fdbk/Passthrough'
 * '<S151>' : 'Lab1_PIDControllers_2018a/Yaw PID/Integrator/Continuous'
 * '<S152>' : 'Lab1_PIDControllers_2018a/Yaw PID/Integrator/Disabled'
 * '<S153>' : 'Lab1_PIDControllers_2018a/Yaw PID/Integrator/Discrete'
 * '<S154>' : 'Lab1_PIDControllers_2018a/Yaw PID/Integrator ICs/Disabled'
 * '<S155>' : 'Lab1_PIDControllers_2018a/Yaw PID/Integrator ICs/External IC'
 * '<S156>' : 'Lab1_PIDControllers_2018a/Yaw PID/Integrator ICs/Internal IC'
 * '<S157>' : 'Lab1_PIDControllers_2018a/Yaw PID/N Copy/Disabled'
 * '<S158>' : 'Lab1_PIDControllers_2018a/Yaw PID/N Copy/Disabled wSignal Specification'
 * '<S159>' : 'Lab1_PIDControllers_2018a/Yaw PID/N Copy/External Parameters'
 * '<S160>' : 'Lab1_PIDControllers_2018a/Yaw PID/N Copy/Internal Parameters'
 * '<S161>' : 'Lab1_PIDControllers_2018a/Yaw PID/N Gain/Disabled'
 * '<S162>' : 'Lab1_PIDControllers_2018a/Yaw PID/N Gain/External Parameters'
 * '<S163>' : 'Lab1_PIDControllers_2018a/Yaw PID/N Gain/Internal Parameters'
 * '<S164>' : 'Lab1_PIDControllers_2018a/Yaw PID/N Gain/Passthrough'
 * '<S165>' : 'Lab1_PIDControllers_2018a/Yaw PID/P Copy/Disabled'
 * '<S166>' : 'Lab1_PIDControllers_2018a/Yaw PID/P Copy/External Parameters Ideal'
 * '<S167>' : 'Lab1_PIDControllers_2018a/Yaw PID/P Copy/Internal Parameters Ideal'
 * '<S168>' : 'Lab1_PIDControllers_2018a/Yaw PID/Parallel P Gain/Disabled'
 * '<S169>' : 'Lab1_PIDControllers_2018a/Yaw PID/Parallel P Gain/External Parameters'
 * '<S170>' : 'Lab1_PIDControllers_2018a/Yaw PID/Parallel P Gain/Internal Parameters'
 * '<S171>' : 'Lab1_PIDControllers_2018a/Yaw PID/Parallel P Gain/Passthrough'
 * '<S172>' : 'Lab1_PIDControllers_2018a/Yaw PID/Reset Signal/Disabled'
 * '<S173>' : 'Lab1_PIDControllers_2018a/Yaw PID/Reset Signal/External Reset'
 * '<S174>' : 'Lab1_PIDControllers_2018a/Yaw PID/Saturation/Enabled'
 * '<S175>' : 'Lab1_PIDControllers_2018a/Yaw PID/Saturation/Passthrough'
 * '<S176>' : 'Lab1_PIDControllers_2018a/Yaw PID/Saturation Fdbk/Disabled'
 * '<S177>' : 'Lab1_PIDControllers_2018a/Yaw PID/Saturation Fdbk/Enabled'
 * '<S178>' : 'Lab1_PIDControllers_2018a/Yaw PID/Saturation Fdbk/Passthrough'
 * '<S179>' : 'Lab1_PIDControllers_2018a/Yaw PID/Sum/Passthrough_I'
 * '<S180>' : 'Lab1_PIDControllers_2018a/Yaw PID/Sum/Passthrough_P'
 * '<S181>' : 'Lab1_PIDControllers_2018a/Yaw PID/Sum/Sum_PD'
 * '<S182>' : 'Lab1_PIDControllers_2018a/Yaw PID/Sum/Sum_PI'
 * '<S183>' : 'Lab1_PIDControllers_2018a/Yaw PID/Sum/Sum_PID'
 * '<S184>' : 'Lab1_PIDControllers_2018a/Yaw PID/Sum Fdbk/Disabled'
 * '<S185>' : 'Lab1_PIDControllers_2018a/Yaw PID/Sum Fdbk/Enabled'
 * '<S186>' : 'Lab1_PIDControllers_2018a/Yaw PID/Sum Fdbk/Passthrough'
 * '<S187>' : 'Lab1_PIDControllers_2018a/Yaw PID/Tracking Mode/Disabled'
 * '<S188>' : 'Lab1_PIDControllers_2018a/Yaw PID/Tracking Mode/Enabled'
 * '<S189>' : 'Lab1_PIDControllers_2018a/Yaw PID/Tracking Mode Sum/Passthrough'
 * '<S190>' : 'Lab1_PIDControllers_2018a/Yaw PID/Tracking Mode Sum/Tracking Mode'
 * '<S191>' : 'Lab1_PIDControllers_2018a/Yaw PID/postSat Signal/Feedback_Path'
 * '<S192>' : 'Lab1_PIDControllers_2018a/Yaw PID/postSat Signal/Forward_Path'
 * '<S193>' : 'Lab1_PIDControllers_2018a/Yaw PID/preSat Signal/Feedback_Path'
 * '<S194>' : 'Lab1_PIDControllers_2018a/Yaw PID/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_Lab1_PIDControllers_2018a_h_ */
