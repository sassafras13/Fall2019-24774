/*
 * KF_LQR_hardware.c
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
#include "KF_LQR_hardware_dt.h"

/* Block signals (default storage) */
B_KF_LQR_hardware_T KF_LQR_hardware_B;

/* Continuous states */
X_KF_LQR_hardware_T KF_LQR_hardware_X;

/* Block states (default storage) */
DW_KF_LQR_hardware_T KF_LQR_hardware_DW;

/* Real-time model */
RT_MODEL_KF_LQR_hardware_T KF_LQR_hardware_M_;
RT_MODEL_KF_LQR_hardware_T *const KF_LQR_hardware_M = &KF_LQR_hardware_M_;

/* Simplified version of numjac.cpp, for use with RTW. */
void local_numjac( RTWSolverInfo *si, real_T *y, const real_T *Fty, real_T *fac,
                  real_T *dFdy )
{
  /* constants */
  real_T THRESH = 1e-6;
  real_T EPS = 2.2e-16;                /* utGetEps(); */
  real_T BL = pow(EPS, 0.75);
  real_T BU = pow(EPS, 0.25);
  real_T FACMIN = pow(EPS, 0.78);
  real_T FACMAX = 0.1;
  int_T nx = 6;
  real_T *x = rtsiGetContStates(si);
  real_T del;
  real_T difmax;
  real_T FdelRowmax;
  real_T temp;
  real_T Fdiff;
  real_T maybe;
  real_T xscale;
  real_T fscale;
  real_T *p;
  int_T rowmax;
  int_T i,j;
  if (x != y)
    (void) memcpy(x, y,
                  (uint_T)nx*sizeof(real_T));
  rtsiSetSolverComputingJacobian(si,true);
  for (p = dFdy, j = 0; j < nx; j++, p += nx) {
    /* Select an increment del for a difference approximation to
       column j of dFdy.  The vector fac accounts for experience
       gained in previous calls to numjac. */
    xscale = fabs(x[j]);
    if (xscale < THRESH)
      xscale = THRESH;
    temp = (x[j] + fac[j]*xscale);
    del = temp - y[j];
    while (del == 0.0) {
      if (fac[j] < FACMAX) {
        fac[j] *= 100.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
        temp = (x[j] + fac[j]*xscale);
        del = temp - x[j];
      } else {
        del = THRESH;                  /* thresh is nonzero */
        break;
      }
    }

    /* Keep del pointing into region. */
    if (Fty[j] >= 0.0)
      del = fabs(del);
    else
      del = -fabs(del);

    /* Form a difference approximation to column j of dFdy. */
    temp = x[j];
    x[j] += del;
    KF_LQR_hardware_output();
    rtsiSetdX(si,p);
    KF_LQR_hardware_derivatives();
    x[j] = temp;
    difmax = 0.0;
    rowmax = 0;
    FdelRowmax = p[0];
    temp = 1.0 / del;
    for (i = 0; i < nx; i++) {
      Fdiff = p[i] - Fty[i];
      maybe = fabs(Fdiff);
      if (maybe > difmax) {
        difmax = maybe;
        rowmax = i;
        FdelRowmax = p[i];
      }

      p[i] = temp * Fdiff;
    }

    /* Adjust fac for next call to numjac. */
    if (((FdelRowmax != 0.0) && (Fty[rowmax] != 0.0)) || (difmax == 0.0)) {
      fscale = fabs(FdelRowmax);
      if (fscale < fabs(Fty[rowmax]))
        fscale = fabs(Fty[rowmax]);
      if (difmax <= BL*fscale) {
        /* The difference is small, so increase the increment. */
        fac[j] *= 10.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
      } else if (difmax > BU*fscale) {
        /* The difference is large, so reduce the increment. */
        fac[j] *= 0.1;
        if (fac[j] < FACMIN)
          fac[j] = FACMIN;
      }
    }
  }

  rtsiSetSolverComputingJacobian(si,false);
}                                      /* end local_numjac */

/*
 * This function updates continuous states using the ODE14x fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static int_T rt_ODE14x_N[4] = { 12, 8, 6, 4 };

  time_T t0 = rtsiGetT(si);
  time_T t1 = t0;
  time_T h = rtsiGetStepSize(si);
  real_T *x1 = rtsiGetContStates(si);
  int_T order = rtsiGetSolverExtrapolationOrder(si);
  int_T numIter = rtsiGetSolverNumberNewtonIterations(si);
  ODE14X_IntgData *id = (ODE14X_IntgData *)rtsiGetSolverData(si);
  real_T *x0 = id->x0;
  real_T *f0 = id->f0;
  real_T *x1start = id->x1start;
  real_T *f1 = id->f1;
  real_T *Delta = id->Delta;
  real_T *E = id->E;
  real_T *fac = id->fac;
  real_T *dfdx = id->DFDX;
  real_T *W = id->W;
  int_T *pivots = id->pivots;
  real_T *xtmp = id->xtmp;
  real_T *ztmp = id->ztmp;
  int_T *N = &(rt_ODE14x_N[0]);
  int_T i,j,k,iter;
  int_T nx = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(x0, x1,
                (uint_T)nx*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */

  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  KF_LQR_hardware_derivatives();
  local_numjac(si,x0,f0,fac,dfdx );
  for (j = 0; j < order; j++) {
    real_T *p;
    real_T hN = h/N[j];

    /* Get the iteration matrix and solution at t0 */

    /* [L,U] = lu(M - hN*J) */
    (void) memcpy(W, dfdx,
                  (uint_T)nx*nx*sizeof(real_T));
    for (p = W, i = 0; i < nx*nx; i++, p++) {
      *p *= (-hN);
    }

    for (p = W, i = 0; i < nx; i++, p += (nx+1)) {
      *p += 1.0;
    }

    rt_lu_real(W, nx,
               pivots);

    /* First Newton's iteration at t0. */
    /* rhs = hN*f0 */
    for (i = 0; i < nx; i++) {
      Delta[i] = hN*f0[i];
    }

    /* Delta = (U \ (L \ rhs)) */
    rt_ForwardSubstitutionRR_Dbl(W, Delta,
      f1, nx,
      1, pivots,
      1);
    rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
      Delta, nx,
      1, 0);

    /* ytmp = y0 + Delta
       ztmp = (ytmp-y0)/h
     */
    (void) memcpy(x1, x0,
                  (uint_T)nx*sizeof(real_T));
    for (i = 0; i < nx; i++) {
      x1[i] += Delta[i];
      ztmp[i] = Delta[i]/hN;
    }

    /* Additional Newton's iterations, if desired.
       for iter = 2:NewtIter
       rhs = hN*feval(odefun,tn,ytmp,extraArgs{:}) - M*(ytmp - yn);
       if statedepM   % only for state dep. Mdel ~= 0
       Mdel = M - feval(massfun,tn,ytmp);
       rhs = rhs + Mdel*ztmp*h;
       end
       Delta = ( U \ ( L \ rhs ) );
       ytmp = ytmp + Delta;
       ztmp = (ytmp - yn)/h
       end
     */
    rtsiSetT(si, t0);
    rtsiSetdX(si, f1);
    for (iter = 1; iter < numIter; iter++) {
      KF_LQR_hardware_output();
      KF_LQR_hardware_derivatives();
      for (i = 0; i < nx; i++) {
        Delta[i] = hN*f1[i];
        xtmp[i] = x1[i] - x0[i];
      }

      /* rhs = hN*f(tn,ytmp) - (ytmp-yn) */
      for (i = 0; i < nx; i++) {
        Delta[i] -= xtmp[i];
      }

      rt_ForwardSubstitutionRR_Dbl(W, Delta,
        f1, nx,
        1, pivots,
        1);
      rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
        Delta, nx,
        1, 0);

      /* ytmp = ytmp + delta
         ztmp = (ytmp - yn)/h
       */
      for (i = 0; i < nx; i++) {
        x1[i] += Delta[i];
        ztmp[i] = (x1[i] - x0[i])/hN;
      }
    }

    /* Steps from t0+hN to t1 -- subintegration of N(j) steps for extrapolation
       ttmp = t0;
       for i = 2:N(j)
       ttmp = ttmp + hN
       ytmp0 = ytmp;
       for iter = 1:NewtIter
       rhs = (ytmp0 - ytmp) + hN*feval(odefun,ttmp,ytmp,extraArgs{:});
       Delta = ( U \ ( L \ rhs ) );
       ytmp = ytmp + Delta;
       end
       end
     */
    for (k = 1; k < N[j]; k++) {
      t1 = t0 + k*hN;
      (void) memcpy(x1start, x1,
                    (uint_T)nx*sizeof(real_T));
      rtsiSetT(si, t1);
      rtsiSetdX(si, f1);
      for (iter = 0; iter < numIter; iter++) {
        KF_LQR_hardware_output();
        KF_LQR_hardware_derivatives();
        if (iter == 0) {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
          }
        } else {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
            xtmp[i] = (x1[i]-x1start[i]);
          }

          /* rhs = hN*f(tn,ytmp) - M*(ytmp-yn) */
          for (i = 0; i < nx; i++) {
            Delta[i] -= xtmp[i];
          }
        }

        rt_ForwardSubstitutionRR_Dbl(W, Delta,
          f1, nx,
          1, pivots,
          1);
        rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
          Delta, nx,
          1, 0);

        /* ytmp = ytmp + Delta
           ztmp = (ytmp - ytmp0)/h
         */
        for (i = 0; i < nx; i++) {
          x1[i] += Delta[i];
          ztmp[i] = (x1[i] - x1start[i])/hN;
        }
      }
    }

    /* Extrapolate to order j
       E(:,j) = ytmp
       for k = j:-1:2
       coef = N(k-1)/(N(j) - N(k-1))
       E(:,k-1) = E(:,k) + coef*( E(:,k) - E(:,k-1) )
       end
     */
    (void) memcpy(&(E[nx*j]), x1,
                  (uint_T)nx*sizeof(real_T));
    for (k = j; k > 0; k--) {
      real_T coef = (real_T)(N[k-1]) / (N[j]-N[k-1]);
      for (i = 0; i < nx; i++) {
        x1[i] = E[nx*k+i] + coef*(E[nx*k+i] - E[nx*(k-1)+i]);
      }

      (void) memcpy(&(E[nx*(k-1)]), x1,
                    (uint_T)nx*sizeof(real_T));
    }
  }

  /* x1 = E(:,1); */
  (void) memcpy(x1, E,
                (uint_T)nx*sizeof(real_T));

  /* t1 = t0 + h; */
  rtsiSetT(si,rtsiGetSolverStopTime(si));
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void KF_LQR_hardware_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadTimebase_o1[2];
  real_T rtb_HILReadTimebase_o2[2];
  real_T rtb_HILReadTimebase_o3[4];
  real_T rtb_LEDColour[3];
  real_T temp;
  int8_T rtAction;
  int32_T i;
  real_T temp_tmp;
  if (rtmIsMajorTimeStep(KF_LQR_hardware_M)) {
    /* set solver stop time */
    if (!(KF_LQR_hardware_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&KF_LQR_hardware_M->solverInfo,
                            ((KF_LQR_hardware_M->Timing.clockTickH0 + 1) *
        KF_LQR_hardware_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&KF_LQR_hardware_M->solverInfo,
                            ((KF_LQR_hardware_M->Timing.clockTick0 + 1) *
        KF_LQR_hardware_M->Timing.stepSize0 +
        KF_LQR_hardware_M->Timing.clockTickH0 *
        KF_LQR_hardware_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(KF_LQR_hardware_M)) {
    KF_LQR_hardware_M->Timing.t[0] = rtsiGetT(&KF_LQR_hardware_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(KF_LQR_hardware_DW.MeasurementUpdate_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(KF_LQR_hardware_DW.EnabledMovingAverage_SubsysRanB);

  /* Reset subsysRan breadcrumbs */
  srClearBC(KF_LQR_hardware_DW.SwitchCaseActionSubsystem_Subsy);

  /* Reset subsysRan breadcrumbs */
  srClearBC(KF_LQR_hardware_DW.SwitchCaseActionSubsystem1_Subs);

  /* Reset subsysRan breadcrumbs */
  srClearBC(KF_LQR_hardware_DW.SwitchCaseActionSubsystem2_Subs);
  if (rtmIsMajorTimeStep(KF_LQR_hardware_M)) {
    /* S-Function (hil_read_timebase_block): '<S5>/HIL Read Timebase' */

    /* S-Function Block: KF_LQR_hardware/Plant/HIL Read Timebase (hil_read_timebase_block) */
    {
      t_error result;
      result = hil_task_read(KF_LQR_hardware_DW.HILReadTimebase_Task, 1,
        &rtb_HILReadTimebase_o1[0],
        &KF_LQR_hardware_DW.HILReadTimebase_EncoderBuffer[0],
        NULL,
        &rtb_HILReadTimebase_o3[0]
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KF_LQR_hardware_M, _rt_error_message);
      } else {
        rtb_HILReadTimebase_o2[0] =
          KF_LQR_hardware_DW.HILReadTimebase_EncoderBuffer[0];
        rtb_HILReadTimebase_o2[1] =
          KF_LQR_hardware_DW.HILReadTimebase_EncoderBuffer[1];
      }
    }
  }

  /* SignalGenerator: '<Root>/Pitch Ref' incorporates:
   *  SignalGenerator: '<Root>/Yaw Ref'
   */
  temp_tmp = KF_LQR_hardware_M->Timing.t[0];
  temp = KF_LQR_hardware_P.PitchRef_Frequency * temp_tmp;
  if (temp - floor(temp) >= 0.5) {
    KF_LQR_hardware_B.PitchRef = KF_LQR_hardware_P.PitchRef_Amplitude;
  } else {
    KF_LQR_hardware_B.PitchRef = -KF_LQR_hardware_P.PitchRef_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Pitch Ref' */

  /* SignalGenerator: '<Root>/Yaw Ref' */
  temp = KF_LQR_hardware_P.YawRef_Frequency * temp_tmp;
  if (temp - floor(temp) >= 0.5) {
    KF_LQR_hardware_B.YawRef = KF_LQR_hardware_P.YawRef_Amplitude;
  } else {
    KF_LQR_hardware_B.YawRef = -KF_LQR_hardware_P.YawRef_Amplitude;
  }

  if (rtmIsMajorTimeStep(KF_LQR_hardware_M)) {
    /* Constant: '<S1>/X0' */
    KF_LQR_hardware_B.X0[0] = KF_LQR_hardware_P.X0_Value[0];
    KF_LQR_hardware_B.X0[1] = KF_LQR_hardware_P.X0_Value[1];
    KF_LQR_hardware_B.X0[2] = KF_LQR_hardware_P.X0_Value[2];
    KF_LQR_hardware_B.X0[3] = KF_LQR_hardware_P.X0_Value[3];
  }

  /* Integrator: '<S1>/MemoryX' */
  if (KF_LQR_hardware_DW.MemoryX_IWORK != 0) {
    KF_LQR_hardware_X.MemoryX_CSTATE[0] = KF_LQR_hardware_B.X0[0];
    KF_LQR_hardware_X.MemoryX_CSTATE[1] = KF_LQR_hardware_B.X0[1];
    KF_LQR_hardware_X.MemoryX_CSTATE[2] = KF_LQR_hardware_B.X0[2];
    KF_LQR_hardware_X.MemoryX_CSTATE[3] = KF_LQR_hardware_B.X0[3];
  }

  KF_LQR_hardware_B.MemoryX[0] = KF_LQR_hardware_X.MemoryX_CSTATE[0];

  /* Reshape: '<S1>/Reshapexhat' */
  KF_LQR_hardware_B.Reshapexhat[0] = KF_LQR_hardware_B.MemoryX[0];

  /* Integrator: '<S1>/MemoryX' */
  KF_LQR_hardware_B.MemoryX[1] = KF_LQR_hardware_X.MemoryX_CSTATE[1];

  /* Reshape: '<S1>/Reshapexhat' */
  KF_LQR_hardware_B.Reshapexhat[1] = KF_LQR_hardware_B.MemoryX[1];

  /* Integrator: '<S1>/MemoryX' */
  KF_LQR_hardware_B.MemoryX[2] = KF_LQR_hardware_X.MemoryX_CSTATE[2];

  /* Reshape: '<S1>/Reshapexhat' */
  KF_LQR_hardware_B.Reshapexhat[2] = KF_LQR_hardware_B.MemoryX[2];

  /* Integrator: '<S1>/MemoryX' */
  KF_LQR_hardware_B.MemoryX[3] = KF_LQR_hardware_X.MemoryX_CSTATE[3];

  /* Reshape: '<S1>/Reshapexhat' */
  KF_LQR_hardware_B.Reshapexhat[3] = KF_LQR_hardware_B.MemoryX[3];

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   */
  KF_LQR_hardware_B.Sum2[0] = KF_LQR_hardware_B.PitchRef -
    KF_LQR_hardware_B.Reshapexhat[0];
  KF_LQR_hardware_B.Sum2[1] = KF_LQR_hardware_B.YawRef -
    KF_LQR_hardware_B.Reshapexhat[1];
  KF_LQR_hardware_B.Sum2[2] = KF_LQR_hardware_P.Constant_Value -
    KF_LQR_hardware_B.Reshapexhat[2];
  KF_LQR_hardware_B.Sum2[3] = KF_LQR_hardware_P.Constant1_Value -
    KF_LQR_hardware_B.Reshapexhat[3];

  /* StateSpace: '<S2>/Internal' */
  KF_LQR_hardware_B.Internal[0] = 0.0;
  KF_LQR_hardware_B.Internal[1] = 0.0;
  KF_LQR_hardware_B.Internal[0] += KF_LQR_hardware_P.Internal_D[0] *
    KF_LQR_hardware_B.Sum2[0];
  KF_LQR_hardware_B.Internal[0] += KF_LQR_hardware_P.Internal_D[1] *
    KF_LQR_hardware_B.Sum2[1];
  KF_LQR_hardware_B.Internal[0] += KF_LQR_hardware_P.Internal_D[2] *
    KF_LQR_hardware_B.Sum2[2];
  KF_LQR_hardware_B.Internal[0] += KF_LQR_hardware_P.Internal_D[3] *
    KF_LQR_hardware_B.Sum2[3];
  KF_LQR_hardware_B.Internal[1] += KF_LQR_hardware_P.Internal_D[4] *
    KF_LQR_hardware_B.Sum2[0];
  KF_LQR_hardware_B.Internal[1] += KF_LQR_hardware_P.Internal_D[5] *
    KF_LQR_hardware_B.Sum2[1];
  KF_LQR_hardware_B.Internal[1] += KF_LQR_hardware_P.Internal_D[6] *
    KF_LQR_hardware_B.Sum2[2];
  KF_LQR_hardware_B.Internal[1] += KF_LQR_hardware_P.Internal_D[7] *
    KF_LQR_hardware_B.Sum2[3];

  /* Saturate: '<Root>/Saturation' */
  if (KF_LQR_hardware_B.Internal[0] > KF_LQR_hardware_P.Saturation_UpperSat) {
    KF_LQR_hardware_B.Saturation[0] = KF_LQR_hardware_P.Saturation_UpperSat;
  } else if (KF_LQR_hardware_B.Internal[0] <
             KF_LQR_hardware_P.Saturation_LowerSat) {
    KF_LQR_hardware_B.Saturation[0] = KF_LQR_hardware_P.Saturation_LowerSat;
  } else {
    KF_LQR_hardware_B.Saturation[0] = KF_LQR_hardware_B.Internal[0];
  }

  if (KF_LQR_hardware_B.Internal[1] > KF_LQR_hardware_P.Saturation_UpperSat) {
    KF_LQR_hardware_B.Saturation[1] = KF_LQR_hardware_P.Saturation_UpperSat;
  } else if (KF_LQR_hardware_B.Internal[1] <
             KF_LQR_hardware_P.Saturation_LowerSat) {
    KF_LQR_hardware_B.Saturation[1] = KF_LQR_hardware_P.Saturation_LowerSat;
  } else {
    KF_LQR_hardware_B.Saturation[1] = KF_LQR_hardware_B.Internal[1];
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (rtmIsMajorTimeStep(KF_LQR_hardware_M)) {
    /* Outputs for Atomic SubSystem: '<S5>/Pitch Bias Removal' */
    /* Step: '<S58>/Step: end_time' incorporates:
     *  Step: '<S58>/Step: start_time'
     */
    temp_tmp = KF_LQR_hardware_M->Timing.t[1];
    if (temp_tmp < KF_LQR_hardware_P.PitchBiasRemoval_end_time) {
      KF_LQR_hardware_B.Stepend_time = KF_LQR_hardware_P.Stepend_time_Y0;
    } else {
      KF_LQR_hardware_B.Stepend_time = KF_LQR_hardware_P.Stepend_time_YFinal;
    }

    /* End of Step: '<S58>/Step: end_time' */

    /* Step: '<S58>/Step: start_time' */
    if (temp_tmp < KF_LQR_hardware_P.PitchBiasRemoval_start_time) {
      temp_tmp = KF_LQR_hardware_P.Stepstart_time_Y0;
    } else {
      temp_tmp = KF_LQR_hardware_P.Stepstart_time_YFinal;
    }

    /* Outputs for Enabled SubSystem: '<S58>/Enabled Moving Average' incorporates:
     *  EnablePort: '<S60>/Enable'
     */
    /* Logic: '<S58>/Logical Operator' incorporates:
     *  Logic: '<S58>/Logical Operator1'
     */
    if ((temp_tmp != 0.0) && (!(KF_LQR_hardware_B.Stepend_time != 0.0))) {
      if (!KF_LQR_hardware_DW.EnabledMovingAverage_MODE) {
        /* InitializeConditions for UnitDelay: '<S64>/Unit Delay' */
        KF_LQR_hardware_DW.UnitDelay_DSTATE =
          KF_LQR_hardware_P.UnitDelay_InitialCondition;

        /* InitializeConditions for UnitDelay: '<S60>/Sum( k=1,n-1, x(k) )' */
        KF_LQR_hardware_DW.Sumk1n1xk_DSTATE =
          KF_LQR_hardware_P.Sumk1n1xk_InitialCondition;
        KF_LQR_hardware_DW.EnabledMovingAverage_MODE = true;
      }

      /* Sum: '<S64>/Count' incorporates:
       *  Constant: '<S64>/unity'
       *  UnitDelay: '<S64>/Unit Delay'
       */
      KF_LQR_hardware_B.Count = KF_LQR_hardware_P.unity_Value +
        KF_LQR_hardware_DW.UnitDelay_DSTATE;

      /* Sum: '<S60>/Sum' incorporates:
       *  Product: '<S5>/Ax//Az'
       *  Trigonometry: '<S5>/Calculate Pitch'
       *  UnitDelay: '<S60>/Sum( k=1,n-1, x(k) )'
       */
      KF_LQR_hardware_B.Sum_m = atan(rtb_HILReadTimebase_o3[0] /
        rtb_HILReadTimebase_o3[1]) + KF_LQR_hardware_DW.Sumk1n1xk_DSTATE;

      /* Product: '<S60>/div' */
      KF_LQR_hardware_B.div = KF_LQR_hardware_B.Sum_m / KF_LQR_hardware_B.Count;
      srUpdateBC(KF_LQR_hardware_DW.EnabledMovingAverage_SubsysRanB);
    } else {
      if (KF_LQR_hardware_DW.EnabledMovingAverage_MODE) {
        KF_LQR_hardware_DW.EnabledMovingAverage_MODE = false;
      }
    }

    /* End of Logic: '<S58>/Logical Operator' */
    /* End of Outputs for SubSystem: '<S58>/Enabled Moving Average' */

    /* SwitchCase: '<S58>/Switch Case' */
    rtAction = -1;
    temp_tmp = trunc(KF_LQR_hardware_P.PitchBiasRemoval_switch_id);
    if (rtIsNaN(temp_tmp) || rtIsInf(temp_tmp)) {
      temp_tmp = 0.0;
    } else {
      temp_tmp = fmod(temp_tmp, 4.294967296E+9);
    }

    switch (temp_tmp < 0.0 ? -(int32_T)(uint32_T)-temp_tmp : (int32_T)(uint32_T)
            temp_tmp) {
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

    KF_LQR_hardware_DW.SwitchCase_ActiveSubsystem = rtAction;
    switch (rtAction) {
     case 0:
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S58>/Switch Case Action Subsystem1' incorporates:
       *  ActionPort: '<S62>/Action Port'
       */
      srUpdateBC(KF_LQR_hardware_DW.SwitchCaseActionSubsystem1_Subs);

      /* End of Outputs for SubSystem: '<S58>/Switch Case Action Subsystem1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S58>/Switch Case Action Subsystem2' incorporates:
       *  ActionPort: '<S63>/Action Port'
       */
      srUpdateBC(KF_LQR_hardware_DW.SwitchCaseActionSubsystem2_Subs);

      /* End of Outputs for SubSystem: '<S58>/Switch Case Action Subsystem2' */
      break;
    }

    /* End of SwitchCase: '<S58>/Switch Case' */
    /* End of Outputs for SubSystem: '<S5>/Pitch Bias Removal' */
  }

  /* Switch: '<S5>/Motor Enable' incorporates:
   *  Constant: '<S5>/No Control'
   */
  if (KF_LQR_hardware_B.Stepend_time > KF_LQR_hardware_P.MotorEnable_Threshold)
  {
    /* Saturate: '<S5>/+//- 24V' */
    if (KF_LQR_hardware_B.Saturation[0] > KF_LQR_hardware_P.u4V_UpperSat) {
      KF_LQR_hardware_B.MotorEnable[0] = KF_LQR_hardware_P.u4V_UpperSat;
    } else if (KF_LQR_hardware_B.Saturation[0] < KF_LQR_hardware_P.u4V_LowerSat)
    {
      KF_LQR_hardware_B.MotorEnable[0] = KF_LQR_hardware_P.u4V_LowerSat;
    } else {
      KF_LQR_hardware_B.MotorEnable[0] = KF_LQR_hardware_B.Saturation[0];
    }

    if (KF_LQR_hardware_B.Saturation[1] > KF_LQR_hardware_P.u4V_UpperSat) {
      KF_LQR_hardware_B.MotorEnable[1] = KF_LQR_hardware_P.u4V_UpperSat;
    } else if (KF_LQR_hardware_B.Saturation[1] < KF_LQR_hardware_P.u4V_LowerSat)
    {
      KF_LQR_hardware_B.MotorEnable[1] = KF_LQR_hardware_P.u4V_LowerSat;
    } else {
      KF_LQR_hardware_B.MotorEnable[1] = KF_LQR_hardware_B.Saturation[1];
    }

    /* End of Saturate: '<S5>/+//- 24V' */
  } else {
    KF_LQR_hardware_B.MotorEnable[0] = KF_LQR_hardware_P.NoControl_Value[0];
    KF_LQR_hardware_B.MotorEnable[1] = KF_LQR_hardware_P.NoControl_Value[1];
  }

  /* End of Switch: '<S5>/Motor Enable' */
  if (rtmIsMajorTimeStep(KF_LQR_hardware_M)) {
    /* Switch: '<S5>/LED Colour' incorporates:
     *  Constant: '<S57>/Constant'
     *  Constant: '<S59>/Constant'
     */
    if (KF_LQR_hardware_B.Stepend_time > KF_LQR_hardware_P.LEDColour_Threshold)
    {
      rtb_LEDColour[0] = KF_LQR_hardware_P.Green_color[0];
      rtb_LEDColour[1] = KF_LQR_hardware_P.Green_color[1];
      rtb_LEDColour[2] = KF_LQR_hardware_P.Green_color[2];
    } else {
      rtb_LEDColour[0] = KF_LQR_hardware_P.Yellow_color[0];
      rtb_LEDColour[1] = KF_LQR_hardware_P.Yellow_color[1];
      rtb_LEDColour[2] = KF_LQR_hardware_P.Yellow_color[2];
    }

    /* End of Switch: '<S5>/LED Colour' */

    /* S-Function (hil_write_block): '<S5>/HIL Write' */

    /* S-Function Block: KF_LQR_hardware/Plant/HIL Write (hil_write_block) */
    {
      t_error result;
      result = hil_write(KF_LQR_hardware_DW.HILInitialize_Card,
                         KF_LQR_hardware_P.HILWrite_analog_channels, 2U,
                         NULL, 0U,
                         NULL, 0U,
                         KF_LQR_hardware_P.HILWrite_other_channels, 3U,
                         &KF_LQR_hardware_B.MotorEnable[0],
                         NULL,
                         NULL,
                         &rtb_LEDColour[0]
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KF_LQR_hardware_M, _rt_error_message);
      }
    }

    /* Gain: '<S5>/Counts to rads' */
    KF_LQR_hardware_B.Countstorads[0] = KF_LQR_hardware_P.Countstorads_Gain[0] *
      rtb_HILReadTimebase_o2[0];
    KF_LQR_hardware_B.Countstorads[1] = KF_LQR_hardware_P.Countstorads_Gain[1] *
      rtb_HILReadTimebase_o2[1];

    /* Sum: '<S5>/Sum' */
    KF_LQR_hardware_B.Sum = KF_LQR_hardware_B.Countstorads[0] -
      KF_LQR_hardware_B.div;
  }

  /* StateSpace: '<S3>/Internal' */
  KF_LQR_hardware_B.Internal_c = 0.0;
  KF_LQR_hardware_B.Internal_c += KF_LQR_hardware_P.Internal_C *
    KF_LQR_hardware_X.Internal_CSTATE;
  KF_LQR_hardware_B.Internal_c += KF_LQR_hardware_P.Internal_D_p *
    KF_LQR_hardware_B.Sum;

  /* StateSpace: '<S4>/Internal' */
  KF_LQR_hardware_B.Internal_f = 0.0;
  KF_LQR_hardware_B.Internal_f += KF_LQR_hardware_P.Internal_C_i *
    KF_LQR_hardware_X.Internal_CSTATE_c;
  KF_LQR_hardware_B.Internal_f += KF_LQR_hardware_P.Internal_D_a *
    KF_LQR_hardware_B.Countstorads[1];
  if (rtmIsMajorTimeStep(KF_LQR_hardware_M)) {
  }

  for (i = 0; i < 4; i++) {
    /* Product: '<S23>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S1>/A'
     */
    KF_LQR_hardware_B.Akxhatkk1[i] = 0.0;
    KF_LQR_hardware_B.Akxhatkk1[i] += KF_LQR_hardware_P.A_Value[i] *
      KF_LQR_hardware_B.MemoryX[0];
    KF_LQR_hardware_B.Akxhatkk1[i] += KF_LQR_hardware_P.A_Value[i + 4] *
      KF_LQR_hardware_B.MemoryX[1];
    KF_LQR_hardware_B.Akxhatkk1[i] += KF_LQR_hardware_P.A_Value[i + 8] *
      KF_LQR_hardware_B.MemoryX[2];
    KF_LQR_hardware_B.Akxhatkk1[i] += KF_LQR_hardware_P.A_Value[i + 12] *
      KF_LQR_hardware_B.MemoryX[3];

    /* Product: '<S23>/B[k]*u[k]' incorporates:
     *  Constant: '<S1>/B'
     */
    KF_LQR_hardware_B.Bkuk[i] = 0.0;
    KF_LQR_hardware_B.Bkuk[i] += KF_LQR_hardware_P.B_Value[i] *
      KF_LQR_hardware_B.Saturation[0];
    KF_LQR_hardware_B.Bkuk[i] += KF_LQR_hardware_P.B_Value[i + 4] *
      KF_LQR_hardware_B.Saturation[1];
  }

  /* Outputs for Enabled SubSystem: '<S23>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S48>/Enable'
   */
  if (rtmIsMajorTimeStep(KF_LQR_hardware_M) && rtmIsMajorTimeStep
      (KF_LQR_hardware_M)) {
    /* Constant: '<S1>/Enable' */
    if (KF_LQR_hardware_P.Enable_Value) {
      if (!KF_LQR_hardware_DW.MeasurementUpdate_MODE) {
        KF_LQR_hardware_DW.MeasurementUpdate_MODE = true;
      }
    } else {
      if (KF_LQR_hardware_DW.MeasurementUpdate_MODE) {
        /* Disable for Outport: '<S48>/L*(y[k]-yhat[k|k-1])' */
        KF_LQR_hardware_B.Product3[0] = KF_LQR_hardware_P.Lykyhatkk1_Y0;
        KF_LQR_hardware_B.Product3[1] = KF_LQR_hardware_P.Lykyhatkk1_Y0;
        KF_LQR_hardware_B.Product3[2] = KF_LQR_hardware_P.Lykyhatkk1_Y0;
        KF_LQR_hardware_B.Product3[3] = KF_LQR_hardware_P.Lykyhatkk1_Y0;
        KF_LQR_hardware_DW.MeasurementUpdate_MODE = false;
      }
    }

    /* End of Constant: '<S1>/Enable' */
  }

  if (KF_LQR_hardware_DW.MeasurementUpdate_MODE) {
    for (i = 0; i < 2; i++) {
      /* Product: '<S48>/C[k]*xhat[k|k-1]' incorporates:
       *  Constant: '<S1>/C'
       */
      KF_LQR_hardware_B.Ckxhatkk1[i] = 0.0;
      KF_LQR_hardware_B.Ckxhatkk1[i] += KF_LQR_hardware_P.C_Value[i] *
        KF_LQR_hardware_B.MemoryX[0];
      KF_LQR_hardware_B.Ckxhatkk1[i] += KF_LQR_hardware_P.C_Value[i + 2] *
        KF_LQR_hardware_B.MemoryX[1];
      KF_LQR_hardware_B.Ckxhatkk1[i] += KF_LQR_hardware_P.C_Value[i + 4] *
        KF_LQR_hardware_B.MemoryX[2];
      KF_LQR_hardware_B.Ckxhatkk1[i] += KF_LQR_hardware_P.C_Value[i + 6] *
        KF_LQR_hardware_B.MemoryX[3];

      /* Product: '<S48>/D[k]*u[k]' incorporates:
       *  Constant: '<S1>/D'
       */
      KF_LQR_hardware_B.Dkuk[i] = 0.0;
      KF_LQR_hardware_B.Dkuk[i] += KF_LQR_hardware_P.D_Value[i] *
        KF_LQR_hardware_B.Saturation[0];
      KF_LQR_hardware_B.Dkuk[i] += KF_LQR_hardware_P.D_Value[i + 2] *
        KF_LQR_hardware_B.Saturation[1];

      /* Sum: '<S48>/Add1' */
      KF_LQR_hardware_B.yhatkk1[i] = KF_LQR_hardware_B.Ckxhatkk1[i] +
        KF_LQR_hardware_B.Dkuk[i];
    }

    /* Sum: '<S48>/Sum' */
    KF_LQR_hardware_B.Sum_d[0] = KF_LQR_hardware_B.Sum -
      KF_LQR_hardware_B.yhatkk1[0];
    KF_LQR_hardware_B.Sum_d[1] = KF_LQR_hardware_B.Countstorads[1] -
      KF_LQR_hardware_B.yhatkk1[1];

    /* Product: '<S48>/Product3' incorporates:
     *  Constant: '<S6>/KalmanGainL'
     */
    for (i = 0; i < 4; i++) {
      KF_LQR_hardware_B.Product3[i] = 0.0;
      KF_LQR_hardware_B.Product3[i] += KF_LQR_hardware_P.KalmanGainL_Value[i] *
        KF_LQR_hardware_B.Sum_d[0];
      KF_LQR_hardware_B.Product3[i] += KF_LQR_hardware_P.KalmanGainL_Value[i + 4]
        * KF_LQR_hardware_B.Sum_d[1];
    }

    /* End of Product: '<S48>/Product3' */
    if (rtmIsMajorTimeStep(KF_LQR_hardware_M)) {
      srUpdateBC(KF_LQR_hardware_DW.MeasurementUpdate_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S23>/MeasurementUpdate' */

  /* Sum: '<S23>/Add' */
  KF_LQR_hardware_B.Add[0] = (KF_LQR_hardware_B.Bkuk[0] +
    KF_LQR_hardware_B.Akxhatkk1[0]) + KF_LQR_hardware_B.Product3[0];
  KF_LQR_hardware_B.Add[1] = (KF_LQR_hardware_B.Bkuk[1] +
    KF_LQR_hardware_B.Akxhatkk1[1]) + KF_LQR_hardware_B.Product3[1];
  KF_LQR_hardware_B.Add[2] = (KF_LQR_hardware_B.Bkuk[2] +
    KF_LQR_hardware_B.Akxhatkk1[2]) + KF_LQR_hardware_B.Product3[2];
  KF_LQR_hardware_B.Add[3] = (KF_LQR_hardware_B.Bkuk[3] +
    KF_LQR_hardware_B.Akxhatkk1[3]) + KF_LQR_hardware_B.Product3[3];
}

/* Model update function */
void KF_LQR_hardware_update(void)
{
  /* Update for Integrator: '<S1>/MemoryX' */
  KF_LQR_hardware_DW.MemoryX_IWORK = 0;

  /* Update for Atomic SubSystem: '<S5>/Pitch Bias Removal' */
  /* Update for Enabled SubSystem: '<S58>/Enabled Moving Average' incorporates:
   *  EnablePort: '<S60>/Enable'
   */
  if (rtmIsMajorTimeStep(KF_LQR_hardware_M) &&
      KF_LQR_hardware_DW.EnabledMovingAverage_MODE) {
    /* Update for UnitDelay: '<S64>/Unit Delay' */
    KF_LQR_hardware_DW.UnitDelay_DSTATE = KF_LQR_hardware_B.Count;

    /* Update for UnitDelay: '<S60>/Sum( k=1,n-1, x(k) )' */
    KF_LQR_hardware_DW.Sumk1n1xk_DSTATE = KF_LQR_hardware_B.Sum_m;
  }

  /* End of Update for SubSystem: '<S58>/Enabled Moving Average' */
  /* End of Update for SubSystem: '<S5>/Pitch Bias Removal' */
  if (rtmIsMajorTimeStep(KF_LQR_hardware_M)) {
    rt_ertODEUpdateContinuousStates(&KF_LQR_hardware_M->solverInfo);
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
  if (!(++KF_LQR_hardware_M->Timing.clockTick0)) {
    ++KF_LQR_hardware_M->Timing.clockTickH0;
  }

  KF_LQR_hardware_M->Timing.t[0] = rtsiGetSolverStopTime
    (&KF_LQR_hardware_M->solverInfo);

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
    if (!(++KF_LQR_hardware_M->Timing.clockTick1)) {
      ++KF_LQR_hardware_M->Timing.clockTickH1;
    }

    KF_LQR_hardware_M->Timing.t[1] = KF_LQR_hardware_M->Timing.clockTick1 *
      KF_LQR_hardware_M->Timing.stepSize1 +
      KF_LQR_hardware_M->Timing.clockTickH1 *
      KF_LQR_hardware_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void KF_LQR_hardware_derivatives(void)
{
  XDot_KF_LQR_hardware_T *_rtXdot;
  _rtXdot = ((XDot_KF_LQR_hardware_T *) KF_LQR_hardware_M->derivs);

  /* Derivatives for Integrator: '<S1>/MemoryX' */
  _rtXdot->MemoryX_CSTATE[0] = KF_LQR_hardware_B.Add[0];
  _rtXdot->MemoryX_CSTATE[1] = KF_LQR_hardware_B.Add[1];
  _rtXdot->MemoryX_CSTATE[2] = KF_LQR_hardware_B.Add[2];
  _rtXdot->MemoryX_CSTATE[3] = KF_LQR_hardware_B.Add[3];

  /* Derivatives for StateSpace: '<S3>/Internal' */
  _rtXdot->Internal_CSTATE = 0.0;
  _rtXdot->Internal_CSTATE += KF_LQR_hardware_P.Internal_A *
    KF_LQR_hardware_X.Internal_CSTATE;
  _rtXdot->Internal_CSTATE += KF_LQR_hardware_P.Internal_B *
    KF_LQR_hardware_B.Sum;

  /* Derivatives for StateSpace: '<S4>/Internal' */
  _rtXdot->Internal_CSTATE_c = 0.0;
  _rtXdot->Internal_CSTATE_c += KF_LQR_hardware_P.Internal_A_n *
    KF_LQR_hardware_X.Internal_CSTATE_c;
  _rtXdot->Internal_CSTATE_c += KF_LQR_hardware_P.Internal_B_d *
    KF_LQR_hardware_B.Countstorads[1];
}

/* Model initialize function */
void KF_LQR_hardware_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S5>/HIL Initialize' */

  /* S-Function Block: KF_LQR_hardware/Plant/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("quanser_aero_usb", "0",
                      &KF_LQR_hardware_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(KF_LQR_hardware_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_watchdog_clear(KF_LQR_hardware_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(KF_LQR_hardware_M, _rt_error_message);
      return;
    }

    if ((KF_LQR_hardware_P.HILInitialize_AIPStart && !is_switching) ||
        (KF_LQR_hardware_P.HILInitialize_AIPEnter && is_switching)) {
      KF_LQR_hardware_DW.HILInitialize_AIMinimums[0] =
        (KF_LQR_hardware_P.HILInitialize_AILow);
      KF_LQR_hardware_DW.HILInitialize_AIMinimums[1] =
        (KF_LQR_hardware_P.HILInitialize_AILow);
      KF_LQR_hardware_DW.HILInitialize_AIMaximums[0] =
        KF_LQR_hardware_P.HILInitialize_AIHigh;
      KF_LQR_hardware_DW.HILInitialize_AIMaximums[1] =
        KF_LQR_hardware_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges(KF_LQR_hardware_DW.HILInitialize_Card,
        KF_LQR_hardware_P.HILInitialize_AIChannels, 2U,
        &KF_LQR_hardware_DW.HILInitialize_AIMinimums[0],
        &KF_LQR_hardware_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KF_LQR_hardware_M, _rt_error_message);
        return;
      }

      KF_LQR_hardware_DW.HILInitialize_AIConfigValues[0] =
        KF_LQR_hardware_P.HILInitialize_AIConfiguration;
      KF_LQR_hardware_DW.HILInitialize_AIConfigValues[1] =
        KF_LQR_hardware_P.HILInitialize_AIConfiguration;
      result = hil_set_analog_input_configuration
        (KF_LQR_hardware_DW.HILInitialize_Card,
         KF_LQR_hardware_P.HILInitialize_AIChannels, 2U,
         (t_analog_input_configuration *)
         &KF_LQR_hardware_DW.HILInitialize_AIConfigValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KF_LQR_hardware_M, _rt_error_message);
        return;
      }
    }

    if ((KF_LQR_hardware_P.HILInitialize_AOPStart && !is_switching) ||
        (KF_LQR_hardware_P.HILInitialize_AOPEnter && is_switching)) {
      KF_LQR_hardware_DW.HILInitialize_AOMinimums[0] =
        (KF_LQR_hardware_P.HILInitialize_AOLow);
      KF_LQR_hardware_DW.HILInitialize_AOMinimums[1] =
        (KF_LQR_hardware_P.HILInitialize_AOLow);
      KF_LQR_hardware_DW.HILInitialize_AOMaximums[0] =
        KF_LQR_hardware_P.HILInitialize_AOHigh;
      KF_LQR_hardware_DW.HILInitialize_AOMaximums[1] =
        KF_LQR_hardware_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges
        (KF_LQR_hardware_DW.HILInitialize_Card,
         KF_LQR_hardware_P.HILInitialize_AOChannels, 2U,
         &KF_LQR_hardware_DW.HILInitialize_AOMinimums[0],
         &KF_LQR_hardware_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KF_LQR_hardware_M, _rt_error_message);
        return;
      }
    }

    if ((KF_LQR_hardware_P.HILInitialize_AOStart && !is_switching) ||
        (KF_LQR_hardware_P.HILInitialize_AOEnter && is_switching)) {
      KF_LQR_hardware_DW.HILInitialize_AOVoltages[0] =
        KF_LQR_hardware_P.HILInitialize_AOInitial;
      KF_LQR_hardware_DW.HILInitialize_AOVoltages[1] =
        KF_LQR_hardware_P.HILInitialize_AOInitial;
      result = hil_write_analog(KF_LQR_hardware_DW.HILInitialize_Card,
        KF_LQR_hardware_P.HILInitialize_AOChannels, 2U,
        &KF_LQR_hardware_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KF_LQR_hardware_M, _rt_error_message);
        return;
      }
    }

    if (KF_LQR_hardware_P.HILInitialize_AOReset) {
      KF_LQR_hardware_DW.HILInitialize_AOVoltages[0] =
        KF_LQR_hardware_P.HILInitialize_AOWatchdog;
      KF_LQR_hardware_DW.HILInitialize_AOVoltages[1] =
        KF_LQR_hardware_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (KF_LQR_hardware_DW.HILInitialize_Card,
         KF_LQR_hardware_P.HILInitialize_AOChannels, 2U,
         &KF_LQR_hardware_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KF_LQR_hardware_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(KF_LQR_hardware_DW.HILInitialize_Card,
      NULL, 0U, KF_LQR_hardware_P.HILInitialize_DOChannels, 2U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(KF_LQR_hardware_M, _rt_error_message);
      return;
    }

    if ((KF_LQR_hardware_P.HILInitialize_DOStart && !is_switching) ||
        (KF_LQR_hardware_P.HILInitialize_DOEnter && is_switching)) {
      KF_LQR_hardware_DW.HILInitialize_DOBits[0] =
        KF_LQR_hardware_P.HILInitialize_DOInitial;
      KF_LQR_hardware_DW.HILInitialize_DOBits[1] =
        KF_LQR_hardware_P.HILInitialize_DOInitial;
      result = hil_write_digital(KF_LQR_hardware_DW.HILInitialize_Card,
        KF_LQR_hardware_P.HILInitialize_DOChannels, 2U, (t_boolean *)
        &KF_LQR_hardware_DW.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KF_LQR_hardware_M, _rt_error_message);
        return;
      }
    }

    if (KF_LQR_hardware_P.HILInitialize_DOReset) {
      KF_LQR_hardware_DW.HILInitialize_DOStates[0] =
        KF_LQR_hardware_P.HILInitialize_DOWatchdog;
      KF_LQR_hardware_DW.HILInitialize_DOStates[1] =
        KF_LQR_hardware_P.HILInitialize_DOWatchdog;
      result = hil_watchdog_set_digital_expiration_state
        (KF_LQR_hardware_DW.HILInitialize_Card,
         KF_LQR_hardware_P.HILInitialize_DOChannels, 2U, (const t_digital_state *)
         &KF_LQR_hardware_DW.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KF_LQR_hardware_M, _rt_error_message);
        return;
      }
    }

    if ((KF_LQR_hardware_P.HILInitialize_EIPStart && !is_switching) ||
        (KF_LQR_hardware_P.HILInitialize_EIPEnter && is_switching)) {
      KF_LQR_hardware_DW.HILInitialize_QuadratureModes[0] =
        KF_LQR_hardware_P.HILInitialize_EIQuadrature;
      KF_LQR_hardware_DW.HILInitialize_QuadratureModes[1] =
        KF_LQR_hardware_P.HILInitialize_EIQuadrature;
      KF_LQR_hardware_DW.HILInitialize_QuadratureModes[2] =
        KF_LQR_hardware_P.HILInitialize_EIQuadrature;
      KF_LQR_hardware_DW.HILInitialize_QuadratureModes[3] =
        KF_LQR_hardware_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (KF_LQR_hardware_DW.HILInitialize_Card,
         KF_LQR_hardware_P.HILInitialize_EIChannels, 4U,
         (t_encoder_quadrature_mode *)
         &KF_LQR_hardware_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KF_LQR_hardware_M, _rt_error_message);
        return;
      }
    }

    if ((KF_LQR_hardware_P.HILInitialize_EIStart && !is_switching) ||
        (KF_LQR_hardware_P.HILInitialize_EIEnter && is_switching)) {
      KF_LQR_hardware_DW.HILInitialize_InitialEICounts[0] =
        KF_LQR_hardware_P.HILInitialize_EIInitial;
      KF_LQR_hardware_DW.HILInitialize_InitialEICounts[1] =
        KF_LQR_hardware_P.HILInitialize_EIInitial;
      KF_LQR_hardware_DW.HILInitialize_InitialEICounts[2] =
        KF_LQR_hardware_P.HILInitialize_EIInitial;
      KF_LQR_hardware_DW.HILInitialize_InitialEICounts[3] =
        KF_LQR_hardware_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(KF_LQR_hardware_DW.HILInitialize_Card,
        KF_LQR_hardware_P.HILInitialize_EIChannels, 4U,
        &KF_LQR_hardware_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KF_LQR_hardware_M, _rt_error_message);
        return;
      }
    }

    if ((KF_LQR_hardware_P.HILInitialize_OOStart && !is_switching) ||
        (KF_LQR_hardware_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(KF_LQR_hardware_DW.HILInitialize_Card,
        KF_LQR_hardware_P.HILInitialize_OOChannels, 3U,
        KF_LQR_hardware_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KF_LQR_hardware_M, _rt_error_message);
        return;
      }
    }

    if (KF_LQR_hardware_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (KF_LQR_hardware_DW.HILInitialize_Card,
         KF_LQR_hardware_P.HILInitialize_OOChannels, 3U,
         KF_LQR_hardware_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KF_LQR_hardware_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_timebase_block): '<S5>/HIL Read Timebase' */

  /* S-Function Block: KF_LQR_hardware/Plant/HIL Read Timebase (hil_read_timebase_block) */
  {
    t_error result;
    result = hil_task_create_reader(KF_LQR_hardware_DW.HILInitialize_Card,
      KF_LQR_hardware_P.HILReadTimebase_samples_in_buff,
      KF_LQR_hardware_P.HILReadTimebase_analog_channels, 2U,
      KF_LQR_hardware_P.HILReadTimebase_encoder_channel, 2U,
      NULL, 0U,
      KF_LQR_hardware_P.HILReadTimebase_other_channels, 4U,
      &KF_LQR_hardware_DW.HILReadTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(KF_LQR_hardware_M, _rt_error_message);
    }
  }

  /* Start for Constant: '<S1>/X0' */
  KF_LQR_hardware_B.X0[0] = KF_LQR_hardware_P.X0_Value[0];
  KF_LQR_hardware_B.X0[1] = KF_LQR_hardware_P.X0_Value[1];
  KF_LQR_hardware_B.X0[2] = KF_LQR_hardware_P.X0_Value[2];
  KF_LQR_hardware_B.X0[3] = KF_LQR_hardware_P.X0_Value[3];

  /* Start for Atomic SubSystem: '<S5>/Pitch Bias Removal' */
  /* Start for Enabled SubSystem: '<S58>/Enabled Moving Average' */
  KF_LQR_hardware_DW.EnabledMovingAverage_MODE = false;

  /* End of Start for SubSystem: '<S58>/Enabled Moving Average' */

  /* Start for SwitchCase: '<S58>/Switch Case' */
  KF_LQR_hardware_DW.SwitchCase_ActiveSubsystem = -1;

  /* End of Start for SubSystem: '<S5>/Pitch Bias Removal' */
  /* Start for Enabled SubSystem: '<S23>/MeasurementUpdate' */
  KF_LQR_hardware_DW.MeasurementUpdate_MODE = false;

  /* End of Start for SubSystem: '<S23>/MeasurementUpdate' */

  /* InitializeConditions for Integrator: '<S1>/MemoryX' */
  if (rtmIsFirstInitCond(KF_LQR_hardware_M)) {
    KF_LQR_hardware_X.MemoryX_CSTATE[0] = 0.0;
    KF_LQR_hardware_X.MemoryX_CSTATE[1] = 0.0;
    KF_LQR_hardware_X.MemoryX_CSTATE[2] = 0.0;
    KF_LQR_hardware_X.MemoryX_CSTATE[3] = 0.0;
  }

  KF_LQR_hardware_DW.MemoryX_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S1>/MemoryX' */

  /* InitializeConditions for StateSpace: '<S3>/Internal' */
  KF_LQR_hardware_X.Internal_CSTATE =
    KF_LQR_hardware_P.Internal_InitialCondition;

  /* InitializeConditions for StateSpace: '<S4>/Internal' */
  KF_LQR_hardware_X.Internal_CSTATE_c =
    KF_LQR_hardware_P.Internal_InitialCondition_i;

  /* SystemInitialize for Atomic SubSystem: '<S5>/Pitch Bias Removal' */
  /* SystemInitialize for Enabled SubSystem: '<S58>/Enabled Moving Average' */
  /* InitializeConditions for UnitDelay: '<S64>/Unit Delay' */
  KF_LQR_hardware_DW.UnitDelay_DSTATE =
    KF_LQR_hardware_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S60>/Sum( k=1,n-1, x(k) )' */
  KF_LQR_hardware_DW.Sumk1n1xk_DSTATE =
    KF_LQR_hardware_P.Sumk1n1xk_InitialCondition;

  /* SystemInitialize for Outport: '<S60>/x_avg_n' */
  KF_LQR_hardware_B.div = KF_LQR_hardware_P.x_avg_n_Y0;

  /* End of SystemInitialize for SubSystem: '<S58>/Enabled Moving Average' */
  /* End of SystemInitialize for SubSystem: '<S5>/Pitch Bias Removal' */

  /* SystemInitialize for Enabled SubSystem: '<S23>/MeasurementUpdate' */
  /* SystemInitialize for Outport: '<S48>/L*(y[k]-yhat[k|k-1])' */
  KF_LQR_hardware_B.Product3[0] = KF_LQR_hardware_P.Lykyhatkk1_Y0;
  KF_LQR_hardware_B.Product3[1] = KF_LQR_hardware_P.Lykyhatkk1_Y0;
  KF_LQR_hardware_B.Product3[2] = KF_LQR_hardware_P.Lykyhatkk1_Y0;
  KF_LQR_hardware_B.Product3[3] = KF_LQR_hardware_P.Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S23>/MeasurementUpdate' */

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(KF_LQR_hardware_M)) {
    rtmSetFirstInitCond(KF_LQR_hardware_M, 0);
  }
}

/* Model terminate function */
void KF_LQR_hardware_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S5>/HIL Initialize' */

  /* S-Function Block: KF_LQR_hardware/Plant/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(KF_LQR_hardware_DW.HILInitialize_Card);
    hil_monitor_stop_all(KF_LQR_hardware_DW.HILInitialize_Card);
    is_switching = false;
    if ((KF_LQR_hardware_P.HILInitialize_AOTerminate && !is_switching) ||
        (KF_LQR_hardware_P.HILInitialize_AOExit && is_switching)) {
      KF_LQR_hardware_DW.HILInitialize_AOVoltages[0] =
        KF_LQR_hardware_P.HILInitialize_AOFinal;
      KF_LQR_hardware_DW.HILInitialize_AOVoltages[1] =
        KF_LQR_hardware_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    }

    if ((KF_LQR_hardware_P.HILInitialize_DOTerminate && !is_switching) ||
        (KF_LQR_hardware_P.HILInitialize_DOExit && is_switching)) {
      KF_LQR_hardware_DW.HILInitialize_DOBits[0] =
        KF_LQR_hardware_P.HILInitialize_DOFinal;
      KF_LQR_hardware_DW.HILInitialize_DOBits[1] =
        KF_LQR_hardware_P.HILInitialize_DOFinal;
      num_final_digital_outputs = 2U;
    }

    if ((KF_LQR_hardware_P.HILInitialize_OOTerminate && !is_switching) ||
        (KF_LQR_hardware_P.HILInitialize_OOExit && is_switching)) {
      num_final_other_outputs = 3U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_digital_outputs > 0
        || num_final_other_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(KF_LQR_hardware_DW.HILInitialize_Card
                         , KF_LQR_hardware_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , KF_LQR_hardware_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , KF_LQR_hardware_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &KF_LQR_hardware_DW.HILInitialize_AOVoltages[0]
                         , NULL
                         , (t_boolean *)
                         &KF_LQR_hardware_DW.HILInitialize_DOBits[0]
                         , KF_LQR_hardware_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(KF_LQR_hardware_DW.HILInitialize_Card,
            KF_LQR_hardware_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &KF_LQR_hardware_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(KF_LQR_hardware_DW.HILInitialize_Card,
            KF_LQR_hardware_P.HILInitialize_DOChannels,
            num_final_digital_outputs, (t_boolean *)
            &KF_LQR_hardware_DW.HILInitialize_DOBits[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(KF_LQR_hardware_DW.HILInitialize_Card,
            KF_LQR_hardware_P.HILInitialize_OOChannels, num_final_other_outputs,
            KF_LQR_hardware_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(KF_LQR_hardware_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(KF_LQR_hardware_DW.HILInitialize_Card);
    hil_monitor_delete_all(KF_LQR_hardware_DW.HILInitialize_Card);
    hil_close(KF_LQR_hardware_DW.HILInitialize_Card);
    KF_LQR_hardware_DW.HILInitialize_Card = NULL;
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
  KF_LQR_hardware_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  KF_LQR_hardware_update();
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
  KF_LQR_hardware_initialize();
}

void MdlTerminate(void)
{
  KF_LQR_hardware_terminate();
}

/* Registration function */
RT_MODEL_KF_LQR_hardware_T *KF_LQR_hardware(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)KF_LQR_hardware_M, 0,
                sizeof(RT_MODEL_KF_LQR_hardware_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&KF_LQR_hardware_M->solverInfo,
                          &KF_LQR_hardware_M->Timing.simTimeStep);
    rtsiSetTPtr(&KF_LQR_hardware_M->solverInfo, &rtmGetTPtr(KF_LQR_hardware_M));
    rtsiSetStepSizePtr(&KF_LQR_hardware_M->solverInfo,
                       &KF_LQR_hardware_M->Timing.stepSize0);
    rtsiSetdXPtr(&KF_LQR_hardware_M->solverInfo, &KF_LQR_hardware_M->derivs);
    rtsiSetContStatesPtr(&KF_LQR_hardware_M->solverInfo, (real_T **)
                         &KF_LQR_hardware_M->contStates);
    rtsiSetNumContStatesPtr(&KF_LQR_hardware_M->solverInfo,
      &KF_LQR_hardware_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&KF_LQR_hardware_M->solverInfo,
      &KF_LQR_hardware_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&KF_LQR_hardware_M->solverInfo,
      &KF_LQR_hardware_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&KF_LQR_hardware_M->solverInfo,
      &KF_LQR_hardware_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&KF_LQR_hardware_M->solverInfo, (&rtmGetErrorStatus
      (KF_LQR_hardware_M)));
    rtsiSetRTModelPtr(&KF_LQR_hardware_M->solverInfo, KF_LQR_hardware_M);
  }

  rtsiSetSimTimeStep(&KF_LQR_hardware_M->solverInfo, MAJOR_TIME_STEP);
  KF_LQR_hardware_M->intgData.x0 = KF_LQR_hardware_M->odeX0;
  KF_LQR_hardware_M->intgData.f0 = KF_LQR_hardware_M->odeF0;
  KF_LQR_hardware_M->intgData.x1start = KF_LQR_hardware_M->odeX1START;
  KF_LQR_hardware_M->intgData.f1 = KF_LQR_hardware_M->odeF1;
  KF_LQR_hardware_M->intgData.Delta = KF_LQR_hardware_M->odeDELTA;
  KF_LQR_hardware_M->intgData.E = KF_LQR_hardware_M->odeE;
  KF_LQR_hardware_M->intgData.fac = KF_LQR_hardware_M->odeFAC;

  /* initialize */
  {
    int_T i;
    real_T *f = KF_LQR_hardware_M->intgData.fac;
    for (i = 0; i < (int_T)(sizeof(KF_LQR_hardware_M->odeFAC)/sizeof(real_T)); i
         ++) {
      f[i] = 1.5e-8;
    }
  }

  KF_LQR_hardware_M->intgData.DFDX = KF_LQR_hardware_M->odeDFDX;
  KF_LQR_hardware_M->intgData.W = KF_LQR_hardware_M->odeW;
  KF_LQR_hardware_M->intgData.pivots = KF_LQR_hardware_M->odePIVOTS;
  KF_LQR_hardware_M->intgData.xtmp = KF_LQR_hardware_M->odeXTMP;
  KF_LQR_hardware_M->intgData.ztmp = KF_LQR_hardware_M->odeZTMP;
  KF_LQR_hardware_M->intgData.isFirstStep = true;
  rtsiSetSolverExtrapolationOrder(&KF_LQR_hardware_M->solverInfo, 4);
  rtsiSetSolverNumberNewtonIterations(&KF_LQR_hardware_M->solverInfo, 1);
  KF_LQR_hardware_M->contStates = ((real_T *) &KF_LQR_hardware_X);
  rtsiSetSolverData(&KF_LQR_hardware_M->solverInfo, (void *)
                    &KF_LQR_hardware_M->intgData);
  rtsiSetSolverName(&KF_LQR_hardware_M->solverInfo,"ode14x");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = KF_LQR_hardware_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    KF_LQR_hardware_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    KF_LQR_hardware_M->Timing.sampleTimes =
      (&KF_LQR_hardware_M->Timing.sampleTimesArray[0]);
    KF_LQR_hardware_M->Timing.offsetTimes =
      (&KF_LQR_hardware_M->Timing.offsetTimesArray[0]);

    /* task periods */
    KF_LQR_hardware_M->Timing.sampleTimes[0] = (0.0);
    KF_LQR_hardware_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    KF_LQR_hardware_M->Timing.offsetTimes[0] = (0.0);
    KF_LQR_hardware_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(KF_LQR_hardware_M, &KF_LQR_hardware_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = KF_LQR_hardware_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    KF_LQR_hardware_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(KF_LQR_hardware_M, -1);
  KF_LQR_hardware_M->Timing.stepSize0 = 0.002;
  KF_LQR_hardware_M->Timing.stepSize1 = 0.002;
  rtmSetFirstInitCond(KF_LQR_hardware_M, 1);

  /* External mode info */
  KF_LQR_hardware_M->Sizes.checksums[0] = (3347256247U);
  KF_LQR_hardware_M->Sizes.checksums[1] = (492568938U);
  KF_LQR_hardware_M->Sizes.checksums[2] = (718339741U);
  KF_LQR_hardware_M->Sizes.checksums[3] = (32063684U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[8];
    KF_LQR_hardware_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &KF_LQR_hardware_DW.MeasurementUpdate_SubsysRanBC;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)
      &KF_LQR_hardware_DW.EnabledMovingAverage_SubsysRanB;
    systemRan[4] = (sysRanDType *)
      &KF_LQR_hardware_DW.SwitchCaseActionSubsystem_Subsy;
    systemRan[5] = (sysRanDType *)
      &KF_LQR_hardware_DW.SwitchCaseActionSubsystem1_Subs;
    systemRan[6] = (sysRanDType *)
      &KF_LQR_hardware_DW.SwitchCaseActionSubsystem2_Subs;
    systemRan[7] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(KF_LQR_hardware_M->extModeInfo,
      &KF_LQR_hardware_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(KF_LQR_hardware_M->extModeInfo,
                        KF_LQR_hardware_M->Sizes.checksums);
    rteiSetTPtr(KF_LQR_hardware_M->extModeInfo, rtmGetTPtr(KF_LQR_hardware_M));
  }

  KF_LQR_hardware_M->solverInfoPtr = (&KF_LQR_hardware_M->solverInfo);
  KF_LQR_hardware_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&KF_LQR_hardware_M->solverInfo, 0.002);
  rtsiSetSolverMode(&KF_LQR_hardware_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  KF_LQR_hardware_M->blockIO = ((void *) &KF_LQR_hardware_B);
  (void) memset(((void *) &KF_LQR_hardware_B), 0,
                sizeof(B_KF_LQR_hardware_T));

  /* parameters */
  KF_LQR_hardware_M->defaultParam = ((real_T *)&KF_LQR_hardware_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &KF_LQR_hardware_X;
    KF_LQR_hardware_M->contStates = (x);
    (void) memset((void *)&KF_LQR_hardware_X, 0,
                  sizeof(X_KF_LQR_hardware_T));
  }

  /* states (dwork) */
  KF_LQR_hardware_M->dwork = ((void *) &KF_LQR_hardware_DW);
  (void) memset((void *)&KF_LQR_hardware_DW, 0,
                sizeof(DW_KF_LQR_hardware_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    KF_LQR_hardware_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  KF_LQR_hardware_M->Sizes.numContStates = (6);/* Number of continuous states */
  KF_LQR_hardware_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  KF_LQR_hardware_M->Sizes.numY = (0); /* Number of model outputs */
  KF_LQR_hardware_M->Sizes.numU = (0); /* Number of model inputs */
  KF_LQR_hardware_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  KF_LQR_hardware_M->Sizes.numSampTimes = (2);/* Number of sample times */
  KF_LQR_hardware_M->Sizes.numBlocks = (70);/* Number of blocks */
  KF_LQR_hardware_M->Sizes.numBlockIO = (27);/* Number of block outputs */
  KF_LQR_hardware_M->Sizes.numBlockPrms = (194);/* Sum of parameter "widths" */
  return KF_LQR_hardware_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
