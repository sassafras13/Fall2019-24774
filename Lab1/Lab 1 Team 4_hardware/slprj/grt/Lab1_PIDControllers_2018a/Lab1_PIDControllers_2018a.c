/*
 * Code generation for system model 'Lab1_PIDControllers_2018a'
 *
 * Model                      : Lab1_PIDControllers_2018a
 * Model version              : 1.5
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Fri Sep  6 20:40:00 2019
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "Lab1_PIDControllers_2018a.h"
#include "Lab1_PIDControllers_2018a_private.h"

P_Lab1_PIDControllers_2018a_T Lab1_PIDControllers_2018a_P = {
  /* Mask Parameter: PitchPID_D
   * Referenced by: '<S34>/Derivative Gain'
   */
  200.0,

  /* Mask Parameter: YawPID_D
   * Referenced by: '<S130>/Derivative Gain'
   */
  300.0,

  /* Mask Parameter: PitchPID_I
   * Referenced by: '<S47>/Integral Gain'
   */
  20.0,

  /* Mask Parameter: YawPID_I
   * Referenced by: '<S143>/Integral Gain'
   */
  15.0,

  /* Mask Parameter: PitchPID_InitialConditionForFil
   * Referenced by: '<S39>/Filter'
   */
  0.0,

  /* Mask Parameter: YawPID_InitialConditionForFilte
   * Referenced by: '<S135>/Filter'
   */
  0.0,

  /* Mask Parameter: PitchPID_InitialConditionForInt
   * Referenced by: '<S57>/Integrator'
   */
  0.0,

  /* Mask Parameter: YawPID_InitialConditionForInteg
   * Referenced by: '<S153>/Integrator'
   */
  0.0,

  /* Mask Parameter: PitchPID_N
   * Referenced by: '<S67>/Filter Coefficient'
   */
  1000.0,

  /* Mask Parameter: YawPID_N
   * Referenced by: '<S163>/Filter Coefficient'
   */
  1000.0,

  /* Mask Parameter: PitchPID_P
   * Referenced by: '<S74>/Proportional Gain'
   */
  200.0,

  /* Mask Parameter: YawPID_P
   * Referenced by: '<S170>/Proportional Gain'
   */
  100.0,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S39>/Filter'
   */
  0.2,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S57>/Integrator'
   */
  0.2,

  /* Computed Parameter: Integrator_gainval_p
   * Referenced by: '<S153>/Integrator'
   */
  0.2,

  /* Computed Parameter: Filter_gainval_i
   * Referenced by: '<S135>/Filter'
   */
  0.2
};

/* System initialize for referenced model: 'Lab1_PIDControllers_2018a' */
void Lab1_PIDControllers_2018a_Init(DW_Lab1_PIDControllers_2018_f_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S39>/Filter' */
  localDW->Filter_DSTATE =
    Lab1_PIDControllers_2018a_P.PitchPID_InitialConditionForFil;

  /* InitializeConditions for DiscreteIntegrator: '<S57>/Integrator' */
  localDW->Integrator_DSTATE =
    Lab1_PIDControllers_2018a_P.PitchPID_InitialConditionForInt;

  /* InitializeConditions for DiscreteIntegrator: '<S153>/Integrator' */
  localDW->Integrator_DSTATE_e =
    Lab1_PIDControllers_2018a_P.YawPID_InitialConditionForInteg;

  /* InitializeConditions for DiscreteIntegrator: '<S135>/Filter' */
  localDW->Filter_DSTATE_j =
    Lab1_PIDControllers_2018a_P.YawPID_InitialConditionForFilte;
}

/* System reset for referenced model: 'Lab1_PIDControllers_2018a' */
void Lab1_PIDControllers_2018a_Reset(DW_Lab1_PIDControllers_2018_f_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S39>/Filter' */
  localDW->Filter_DSTATE =
    Lab1_PIDControllers_2018a_P.PitchPID_InitialConditionForFil;

  /* InitializeConditions for DiscreteIntegrator: '<S57>/Integrator' */
  localDW->Integrator_DSTATE =
    Lab1_PIDControllers_2018a_P.PitchPID_InitialConditionForInt;

  /* InitializeConditions for DiscreteIntegrator: '<S153>/Integrator' */
  localDW->Integrator_DSTATE_e =
    Lab1_PIDControllers_2018a_P.YawPID_InitialConditionForInteg;

  /* InitializeConditions for DiscreteIntegrator: '<S135>/Filter' */
  localDW->Filter_DSTATE_j =
    Lab1_PIDControllers_2018a_P.YawPID_InitialConditionForFilte;
}

/* Output and update for referenced model: 'Lab1_PIDControllers_2018a' */
void Lab1_PIDControllers_2018a(const real_T *rtu_YawInput, const real_T
  *rtu_PitchInput, real_T rty_CombinedOutput[2], DW_Lab1_PIDControllers_2018_f_T
  *localDW)
{
  real_T rtb_FilterCoefficient;
  real_T rtb_FilterCoefficient_k;

  /* Gain: '<S67>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S39>/Filter'
   *  Gain: '<S34>/Derivative Gain'
   *  Sum: '<S39>/SumD'
   */
  rtb_FilterCoefficient = (Lab1_PIDControllers_2018a_P.PitchPID_D *
    *rtu_PitchInput - localDW->Filter_DSTATE) *
    Lab1_PIDControllers_2018a_P.PitchPID_N;

  /* Gain: '<S163>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S135>/Filter'
   *  Gain: '<S130>/Derivative Gain'
   *  Sum: '<S135>/SumD'
   */
  rtb_FilterCoefficient_k = (Lab1_PIDControllers_2018a_P.YawPID_D *
    *rtu_YawInput - localDW->Filter_DSTATE_j) *
    Lab1_PIDControllers_2018a_P.YawPID_N;

  /* SignalConversion: '<Root>/TmpSignal ConversionAtCombined OutputInport1' incorporates:
   *  DiscreteIntegrator: '<S153>/Integrator'
   *  DiscreteIntegrator: '<S57>/Integrator'
   *  Gain: '<S170>/Proportional Gain'
   *  Gain: '<S74>/Proportional Gain'
   *  Sum: '<S183>/Sum'
   *  Sum: '<S87>/Sum'
   */
  rty_CombinedOutput[0] = (Lab1_PIDControllers_2018a_P.YawPID_P * *rtu_YawInput
    + localDW->Integrator_DSTATE_e) + rtb_FilterCoefficient_k;
  rty_CombinedOutput[1] = (Lab1_PIDControllers_2018a_P.PitchPID_P *
    *rtu_PitchInput + localDW->Integrator_DSTATE) + rtb_FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S39>/Filter' */
  localDW->Filter_DSTATE += Lab1_PIDControllers_2018a_P.Filter_gainval *
    rtb_FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S57>/Integrator' incorporates:
   *  Gain: '<S47>/Integral Gain'
   */
  localDW->Integrator_DSTATE += Lab1_PIDControllers_2018a_P.PitchPID_I *
    *rtu_PitchInput * Lab1_PIDControllers_2018a_P.Integrator_gainval;

  /* Update for DiscreteIntegrator: '<S153>/Integrator' incorporates:
   *  Gain: '<S143>/Integral Gain'
   */
  localDW->Integrator_DSTATE_e += Lab1_PIDControllers_2018a_P.YawPID_I *
    *rtu_YawInput * Lab1_PIDControllers_2018a_P.Integrator_gainval_p;

  /* Update for DiscreteIntegrator: '<S135>/Filter' */
  localDW->Filter_DSTATE_j += Lab1_PIDControllers_2018a_P.Filter_gainval_i *
    rtb_FilterCoefficient_k;
}

/* Model initialize function */
void Lab1_PIDControllers__initialize(const char_T **rt_errorStatus,
  RT_MODEL_Lab1_PIDControllers__T *const Lab1_PIDControllers_2018a_M,
  DW_Lab1_PIDControllers_2018_f_T *localDW)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(Lab1_PIDControllers_2018a_M, rt_errorStatus);

  /* states (dwork) */
  (void) memset((void *)localDW, 0,
                sizeof(DW_Lab1_PIDControllers_2018_f_T));
}
