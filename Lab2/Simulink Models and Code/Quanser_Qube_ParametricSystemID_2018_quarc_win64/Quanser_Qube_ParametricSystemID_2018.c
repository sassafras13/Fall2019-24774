/*
 * Quanser_Qube_ParametricSystemID_2018.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Quanser_Qube_ParametricSystemID_2018".
 *
 * Model version              : 1.461
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Wed Oct  2 20:38:42 2019
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Quanser_Qube_ParametricSystemID_2018.h"
#include "Quanser_Qube_ParametricSystemID_2018_private.h"
#include "Quanser_Qube_ParametricSystemID_2018_dt.h"

/* Block signals (default storage) */
B_Quanser_Qube_ParametricSyst_T Quanser_Qube_ParametricSystem_B;

/* Continuous states */
X_Quanser_Qube_ParametricSyst_T Quanser_Qube_ParametricSystem_X;

/* Block states (default storage) */
DW_Quanser_Qube_ParametricSys_T Quanser_Qube_ParametricSyste_DW;

/* Real-time model */
RT_MODEL_Quanser_Qube_Paramet_T Quanser_Qube_ParametricSyste_M_;
RT_MODEL_Quanser_Qube_Paramet_T *const Quanser_Qube_ParametricSyste_M =
  &Quanser_Qube_ParametricSyste_M_;
static void rate_scheduler(void);

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Quanser_Qube_ParametricSyste_M->Timing.TaskCounters.TID[2])++;
  if ((Quanser_Qube_ParametricSyste_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    Quanser_Qube_ParametricSyste_M->Timing.TaskCounters.TID[2] = 0;
  }

  Quanser_Qube_ParametricSyste_M->Timing.sampleHits[2] =
    (Quanser_Qube_ParametricSyste_M->Timing.TaskCounters.TID[2] == 0);
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Quanser_Qube_ParametricSystemID_2018_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;
  real_T sr;
  real_T si;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

/* Model output function */
void Quanser_Qube_ParametricSystemID_2018_output(void)
{
  real_T x;
  real_T u1;
  real_T u2;
  if (rtmIsMajorTimeStep(Quanser_Qube_ParametricSyste_M)) {
    /* set solver stop time */
    if (!(Quanser_Qube_ParametricSyste_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Quanser_Qube_ParametricSyste_M->solverInfo,
                            ((Quanser_Qube_ParametricSyste_M->Timing.clockTickH0
        + 1) * Quanser_Qube_ParametricSyste_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Quanser_Qube_ParametricSyste_M->solverInfo,
                            ((Quanser_Qube_ParametricSyste_M->Timing.clockTick0
        + 1) * Quanser_Qube_ParametricSyste_M->Timing.stepSize0 +
        Quanser_Qube_ParametricSyste_M->Timing.clockTickH0 *
        Quanser_Qube_ParametricSyste_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Quanser_Qube_ParametricSyste_M)) {
    Quanser_Qube_ParametricSyste_M->Timing.t[0] = rtsiGetT
      (&Quanser_Qube_ParametricSyste_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Quanser_Qube_ParametricSyste_M) &&
      Quanser_Qube_ParametricSyste_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (hil_read_encoder_timebase_block): '<S3>/HIL Read Encoder Timebase' */

    /* S-Function Block: Quanser_Qube_ParametricSystemID_2018/Plant/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (Quanser_Qube_ParametricSyste_DW.HILReadEncoderTimebase_Task, 1,
         &Quanser_Qube_ParametricSyste_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M, _rt_error_message);
      } else {
        Quanser_Qube_ParametricSystem_B.HILReadEncoderTimebase_o1 =
          Quanser_Qube_ParametricSyste_DW.HILReadEncoderTimebase_Buffer[0];
        Quanser_Qube_ParametricSystem_B.HILReadEncoderTimebase_o2 =
          Quanser_Qube_ParametricSyste_DW.HILReadEncoderTimebase_Buffer[1];
      }
    }

    /* Gain: '<S6>/Pendulum:  counts to rad' */
    Quanser_Qube_ParametricSystem_B.Pendulumcountstorad =
      Quanser_Qube_ParametricSystem_P.Pendulumcountstorad_Gain *
      Quanser_Qube_ParametricSystem_B.HILReadEncoderTimebase_o2;

    /* Gain: '<S6>/Arm: counts to rad' */
    Quanser_Qube_ParametricSystem_B.Armcountstorad =
      Quanser_Qube_ParametricSystem_P.Armcountstorad_Gain *
      Quanser_Qube_ParametricSystem_B.HILReadEncoderTimebase_o1;
  }

  if (rtmIsMajorTimeStep(Quanser_Qube_ParametricSyste_M) &&
      Quanser_Qube_ParametricSyste_M->Timing.TaskCounters.TID[2] == 0) {
    /* RandomNumber: '<S1>/White Noise' */
    Quanser_Qube_ParametricSystem_B.WhiteNoise =
      Quanser_Qube_ParametricSyste_DW.NextOutput;

    /* Gain: '<S1>/Output' */
    x = Quanser_Qube_ParametricSystem_P.BandLimitedWhiteNoise_Cov;
    x = sqrt(x);
    x /= 0.1;
    Quanser_Qube_ParametricSystem_B.Output = x *
      Quanser_Qube_ParametricSystem_B.WhiteNoise;

    /* Saturate: '<S3>/Saturation' */
    x = Quanser_Qube_ParametricSystem_B.Output;
    u1 = Quanser_Qube_ParametricSystem_P.Saturation_LowerSat;
    u2 = Quanser_Qube_ParametricSystem_P.Saturation_UpperSat;
    if (x > u2) {
      Quanser_Qube_ParametricSystem_B.Saturation = u2;
    } else if (x < u1) {
      Quanser_Qube_ParametricSystem_B.Saturation = u1;
    } else {
      Quanser_Qube_ParametricSystem_B.Saturation = x;
    }

    /* End of Saturate: '<S3>/Saturation' */

    /* Gain: '<S3>/For +ve CCW' */
    Quanser_Qube_ParametricSystem_B.ForveCCW =
      Quanser_Qube_ParametricSystem_P.ForveCCW_Gain *
      Quanser_Qube_ParametricSystem_B.Saturation;

    /* S-Function (hil_write_analog_block): '<S3>/HIL Write Analog' */

    /* S-Function Block: Quanser_Qube_ParametricSystemID_2018/Plant/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog
        (Quanser_Qube_ParametricSyste_DW.HILInitialize_Card,
         &Quanser_Qube_ParametricSystem_P.HILWriteAnalog_channels, 1,
         &Quanser_Qube_ParametricSystem_B.ForveCCW);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M, _rt_error_message);
      }
    }
  }

  /* StateSpace: '<S2>/Internal' */
  Quanser_Qube_ParametricSystem_B.Internal[0] = 0.0;
  Quanser_Qube_ParametricSystem_B.Internal[1] = 0.0;
  Quanser_Qube_ParametricSystem_B.Internal[2] = 0.0;
  Quanser_Qube_ParametricSystem_B.Internal[3] = 0.0;
  Quanser_Qube_ParametricSystem_B.Internal[0] +=
    Quanser_Qube_ParametricSystem_P.Internal_C[0] *
    Quanser_Qube_ParametricSystem_X.Internal_CSTATE[0];
  Quanser_Qube_ParametricSystem_B.Internal[1] +=
    Quanser_Qube_ParametricSystem_P.Internal_C[1] *
    Quanser_Qube_ParametricSystem_X.Internal_CSTATE[1];
  Quanser_Qube_ParametricSystem_B.Internal[2] +=
    Quanser_Qube_ParametricSystem_P.Internal_C[2] *
    Quanser_Qube_ParametricSystem_X.Internal_CSTATE[2];
  Quanser_Qube_ParametricSystem_B.Internal[3] +=
    Quanser_Qube_ParametricSystem_P.Internal_C[3] *
    Quanser_Qube_ParametricSystem_X.Internal_CSTATE[3];
  if (rtmIsMajorTimeStep(Quanser_Qube_ParametricSyste_M) &&
      Quanser_Qube_ParametricSyste_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion: '<Root>/TmpSignal ConversionAtTo FileInport1' */
    Quanser_Qube_ParametricSystem_B.TmpSignalConversionAtToFileInpo[0] =
      Quanser_Qube_ParametricSystem_B.Internal[0];
    Quanser_Qube_ParametricSystem_B.TmpSignalConversionAtToFileInpo[1] =
      Quanser_Qube_ParametricSystem_B.Internal[1];
    Quanser_Qube_ParametricSystem_B.TmpSignalConversionAtToFileInpo[2] =
      Quanser_Qube_ParametricSystem_B.Pendulumcountstorad;
    Quanser_Qube_ParametricSystem_B.TmpSignalConversionAtToFileInpo[3] =
      Quanser_Qube_ParametricSystem_B.Output;

    /* ToFile: '<Root>/To File' */
    {
      if (!(++Quanser_Qube_ParametricSyste_DW.ToFile_IWORK.Decimation % 1) &&
          (Quanser_Qube_ParametricSyste_DW.ToFile_IWORK.Count * (4 + 1)) + 1 <
          100000000 ) {
        FILE *fp = (FILE *) Quanser_Qube_ParametricSyste_DW.ToFile_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[4 + 1];
          Quanser_Qube_ParametricSyste_DW.ToFile_IWORK.Decimation = 0;
          u[0] = Quanser_Qube_ParametricSyste_M->Timing.t[1];
          u[1] =
            Quanser_Qube_ParametricSystem_B.TmpSignalConversionAtToFileInpo[0];
          u[2] =
            Quanser_Qube_ParametricSystem_B.TmpSignalConversionAtToFileInpo[1];
          u[3] =
            Quanser_Qube_ParametricSystem_B.TmpSignalConversionAtToFileInpo[2];
          u[4] =
            Quanser_Qube_ParametricSystem_B.TmpSignalConversionAtToFileInpo[3];
          if (fwrite(u, sizeof(real_T), 4 + 1, fp) != 4 + 1) {
            rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M,
                              "Error writing to MAT-file sysID_parametric_alpha_input4.mat");
            return;
          }

          if (((++Quanser_Qube_ParametricSyste_DW.ToFile_IWORK.Count) * (4 + 1))
              +1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file sysID_parametric_alpha_input4.mat.\n");
          }
        }
      }
    }

    /* SignalConversion: '<Root>/TmpSignal ConversionAtTo File1Inport1' */
    Quanser_Qube_ParametricSystem_B.TmpSignalConversionAtToFile1Inp[0] =
      Quanser_Qube_ParametricSystem_B.Internal[2];
    Quanser_Qube_ParametricSystem_B.TmpSignalConversionAtToFile1Inp[1] =
      Quanser_Qube_ParametricSystem_B.Internal[3];
    Quanser_Qube_ParametricSystem_B.TmpSignalConversionAtToFile1Inp[2] =
      Quanser_Qube_ParametricSystem_B.Armcountstorad;
    Quanser_Qube_ParametricSystem_B.TmpSignalConversionAtToFile1Inp[3] =
      Quanser_Qube_ParametricSystem_B.Output;

    /* ToFile: '<Root>/To File1' */
    {
      if (!(++Quanser_Qube_ParametricSyste_DW.ToFile1_IWORK.Decimation % 1) &&
          (Quanser_Qube_ParametricSyste_DW.ToFile1_IWORK.Count * (4 + 1)) + 1 <
          100000000 ) {
        FILE *fp = (FILE *)
          Quanser_Qube_ParametricSyste_DW.ToFile1_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[4 + 1];
          Quanser_Qube_ParametricSyste_DW.ToFile1_IWORK.Decimation = 0;
          u[0] = Quanser_Qube_ParametricSyste_M->Timing.t[1];
          u[1] =
            Quanser_Qube_ParametricSystem_B.TmpSignalConversionAtToFile1Inp[0];
          u[2] =
            Quanser_Qube_ParametricSystem_B.TmpSignalConversionAtToFile1Inp[1];
          u[3] =
            Quanser_Qube_ParametricSystem_B.TmpSignalConversionAtToFile1Inp[2];
          u[4] =
            Quanser_Qube_ParametricSystem_B.TmpSignalConversionAtToFile1Inp[3];
          if (fwrite(u, sizeof(real_T), 4 + 1, fp) != 4 + 1) {
            rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M,
                              "Error writing to MAT-file sysID_parametric_theta_input4.mat");
            return;
          }

          if (((++Quanser_Qube_ParametricSyste_DW.ToFile1_IWORK.Count) * (4 + 1))
              +1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file sysID_parametric_theta_input4.mat.\n");
          }
        }
      }
    }
  }
}

/* Model update function */
void Quanser_Qube_ParametricSystemID_2018_update(void)
{
  if (rtmIsMajorTimeStep(Quanser_Qube_ParametricSyste_M) &&
      Quanser_Qube_ParametricSyste_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for RandomNumber: '<S1>/White Noise' */
    Quanser_Qube_ParametricSyste_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&Quanser_Qube_ParametricSyste_DW.RandSeed) *
      Quanser_Qube_ParametricSystem_P.WhiteNoise_StdDev +
      Quanser_Qube_ParametricSystem_P.WhiteNoise_Mean;
  }

  if (rtmIsMajorTimeStep(Quanser_Qube_ParametricSyste_M)) {
    rt_ertODEUpdateContinuousStates(&Quanser_Qube_ParametricSyste_M->solverInfo);
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
  if (!(++Quanser_Qube_ParametricSyste_M->Timing.clockTick0)) {
    ++Quanser_Qube_ParametricSyste_M->Timing.clockTickH0;
  }

  Quanser_Qube_ParametricSyste_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Quanser_Qube_ParametricSyste_M->solverInfo);

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
    if (!(++Quanser_Qube_ParametricSyste_M->Timing.clockTick1)) {
      ++Quanser_Qube_ParametricSyste_M->Timing.clockTickH1;
    }

    Quanser_Qube_ParametricSyste_M->Timing.t[1] =
      Quanser_Qube_ParametricSyste_M->Timing.clockTick1 *
      Quanser_Qube_ParametricSyste_M->Timing.stepSize1 +
      Quanser_Qube_ParametricSyste_M->Timing.clockTickH1 *
      Quanser_Qube_ParametricSyste_M->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(Quanser_Qube_ParametricSyste_M) &&
      Quanser_Qube_ParametricSyste_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Quanser_Qube_ParametricSyste_M->Timing.clockTick2)) {
      ++Quanser_Qube_ParametricSyste_M->Timing.clockTickH2;
    }

    Quanser_Qube_ParametricSyste_M->Timing.t[2] =
      Quanser_Qube_ParametricSyste_M->Timing.clockTick2 *
      Quanser_Qube_ParametricSyste_M->Timing.stepSize2 +
      Quanser_Qube_ParametricSyste_M->Timing.clockTickH2 *
      Quanser_Qube_ParametricSyste_M->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void Quanser_Qube_ParametricSystemID_2018_derivatives(void)
{
  XDot_Quanser_Qube_ParametricS_T *_rtXdot;
  _rtXdot = ((XDot_Quanser_Qube_ParametricS_T *)
             Quanser_Qube_ParametricSyste_M->derivs);

  /* Derivatives for StateSpace: '<S2>/Internal' */
  _rtXdot->Internal_CSTATE[0] = 0.0;
  _rtXdot->Internal_CSTATE[1] = 0.0;
  _rtXdot->Internal_CSTATE[2] = 0.0;
  _rtXdot->Internal_CSTATE[3] = 0.0;
  _rtXdot->Internal_CSTATE[0] += Quanser_Qube_ParametricSystem_P.Internal_A[0] *
    Quanser_Qube_ParametricSystem_X.Internal_CSTATE[2];
  _rtXdot->Internal_CSTATE[1] += Quanser_Qube_ParametricSystem_P.Internal_A[1] *
    Quanser_Qube_ParametricSystem_X.Internal_CSTATE[3];
  _rtXdot->Internal_CSTATE[2] += Quanser_Qube_ParametricSystem_P.Internal_A[2] *
    Quanser_Qube_ParametricSystem_X.Internal_CSTATE[1];
  _rtXdot->Internal_CSTATE[2] += Quanser_Qube_ParametricSystem_P.Internal_A[3] *
    Quanser_Qube_ParametricSystem_X.Internal_CSTATE[2];
  _rtXdot->Internal_CSTATE[2] += Quanser_Qube_ParametricSystem_P.Internal_A[4] *
    Quanser_Qube_ParametricSystem_X.Internal_CSTATE[3];
  _rtXdot->Internal_CSTATE[3] += Quanser_Qube_ParametricSystem_P.Internal_A[5] *
    Quanser_Qube_ParametricSystem_X.Internal_CSTATE[1];
  _rtXdot->Internal_CSTATE[3] += Quanser_Qube_ParametricSystem_P.Internal_A[6] *
    Quanser_Qube_ParametricSystem_X.Internal_CSTATE[2];
  _rtXdot->Internal_CSTATE[3] += Quanser_Qube_ParametricSystem_P.Internal_A[7] *
    Quanser_Qube_ParametricSystem_X.Internal_CSTATE[3];
  _rtXdot->Internal_CSTATE[2] += Quanser_Qube_ParametricSystem_P.Internal_B[0] *
    Quanser_Qube_ParametricSystem_B.Output;
  _rtXdot->Internal_CSTATE[3] += Quanser_Qube_ParametricSystem_P.Internal_B[1] *
    Quanser_Qube_ParametricSystem_B.Output;
}

/* Model initialize function */
void Quanser_Qube_ParametricSystemID_2018_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S3>/HIL Initialize' */

  /* S-Function Block: Quanser_Qube_ParametricSystemID_2018/Plant/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo2_usb", "0",
                      &Quanser_Qube_ParametricSyste_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (Quanser_Qube_ParametricSyste_DW.HILInitialize_Card, " ", 2);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear
      (Quanser_Qube_ParametricSyste_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M, _rt_error_message);
      return;
    }

    if ((Quanser_Qube_ParametricSystem_P.HILInitialize_AIPStart && !is_switching)
        || (Quanser_Qube_ParametricSystem_P.HILInitialize_AIPEnter &&
            is_switching)) {
      result = hil_set_analog_input_ranges
        (Quanser_Qube_ParametricSyste_DW.HILInitialize_Card,
         &Quanser_Qube_ParametricSystem_P.HILInitialize_AIChannels, 1U,
         &Quanser_Qube_ParametricSystem_P.HILInitialize_AILow,
         &Quanser_Qube_ParametricSystem_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M, _rt_error_message);
        return;
      }
    }

    if ((Quanser_Qube_ParametricSystem_P.HILInitialize_AOPStart && !is_switching)
        || (Quanser_Qube_ParametricSystem_P.HILInitialize_AOPEnter &&
            is_switching)) {
      result = hil_set_analog_output_ranges
        (Quanser_Qube_ParametricSyste_DW.HILInitialize_Card,
         &Quanser_Qube_ParametricSystem_P.HILInitialize_AOChannels, 1U,
         &Quanser_Qube_ParametricSystem_P.HILInitialize_AOLow,
         &Quanser_Qube_ParametricSystem_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M, _rt_error_message);
        return;
      }
    }

    if ((Quanser_Qube_ParametricSystem_P.HILInitialize_AOStart && !is_switching)
        || (Quanser_Qube_ParametricSystem_P.HILInitialize_AOEnter &&
            is_switching)) {
      result = hil_write_analog
        (Quanser_Qube_ParametricSyste_DW.HILInitialize_Card,
         &Quanser_Qube_ParametricSystem_P.HILInitialize_AOChannels, 1U,
         &Quanser_Qube_ParametricSystem_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M, _rt_error_message);
        return;
      }
    }

    if (Quanser_Qube_ParametricSystem_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (Quanser_Qube_ParametricSyste_DW.HILInitialize_Card,
         &Quanser_Qube_ParametricSystem_P.HILInitialize_AOChannels, 1U,
         &Quanser_Qube_ParametricSystem_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions
      (Quanser_Qube_ParametricSyste_DW.HILInitialize_Card, NULL, 0U,
       &Quanser_Qube_ParametricSystem_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M, _rt_error_message);
      return;
    }

    if ((Quanser_Qube_ParametricSystem_P.HILInitialize_DOStart && !is_switching)
        || (Quanser_Qube_ParametricSystem_P.HILInitialize_DOEnter &&
            is_switching)) {
      result = hil_write_digital
        (Quanser_Qube_ParametricSyste_DW.HILInitialize_Card,
         &Quanser_Qube_ParametricSystem_P.HILInitialize_DOChannels, 1U,
         (t_boolean *) &Quanser_Qube_ParametricSystem_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M, _rt_error_message);
        return;
      }
    }

    if (Quanser_Qube_ParametricSystem_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (Quanser_Qube_ParametricSyste_DW.HILInitialize_Card,
         &Quanser_Qube_ParametricSystem_P.HILInitialize_DOChannels, 1U, (const
          t_digital_state *)
         &Quanser_Qube_ParametricSystem_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M, _rt_error_message);
        return;
      }
    }

    if ((Quanser_Qube_ParametricSystem_P.HILInitialize_EIPStart && !is_switching)
        || (Quanser_Qube_ParametricSystem_P.HILInitialize_EIPEnter &&
            is_switching)) {
      Quanser_Qube_ParametricSyste_DW.HILInitialize_QuadratureModes[0] =
        Quanser_Qube_ParametricSystem_P.HILInitialize_EIQuadrature;
      Quanser_Qube_ParametricSyste_DW.HILInitialize_QuadratureModes[1] =
        Quanser_Qube_ParametricSystem_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (Quanser_Qube_ParametricSyste_DW.HILInitialize_Card,
         Quanser_Qube_ParametricSystem_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &Quanser_Qube_ParametricSyste_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M, _rt_error_message);
        return;
      }
    }

    if ((Quanser_Qube_ParametricSystem_P.HILInitialize_EIStart && !is_switching)
        || (Quanser_Qube_ParametricSystem_P.HILInitialize_EIEnter &&
            is_switching)) {
      Quanser_Qube_ParametricSyste_DW.HILInitialize_InitialEICounts[0] =
        Quanser_Qube_ParametricSystem_P.HILInitialize_EIInitial;
      Quanser_Qube_ParametricSyste_DW.HILInitialize_InitialEICounts[1] =
        Quanser_Qube_ParametricSystem_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts
        (Quanser_Qube_ParametricSyste_DW.HILInitialize_Card,
         Quanser_Qube_ParametricSystem_P.HILInitialize_EIChannels, 2U,
         &Quanser_Qube_ParametricSyste_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M, _rt_error_message);
        return;
      }
    }

    if ((Quanser_Qube_ParametricSystem_P.HILInitialize_OOStart && !is_switching)
        || (Quanser_Qube_ParametricSystem_P.HILInitialize_OOEnter &&
            is_switching)) {
      result = hil_write_other
        (Quanser_Qube_ParametricSyste_DW.HILInitialize_Card,
         Quanser_Qube_ParametricSystem_P.HILInitialize_OOChannels, 3U,
         Quanser_Qube_ParametricSystem_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M, _rt_error_message);
        return;
      }
    }

    if (Quanser_Qube_ParametricSystem_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (Quanser_Qube_ParametricSyste_DW.HILInitialize_Card,
         Quanser_Qube_ParametricSystem_P.HILInitialize_OOChannels, 3U,
         Quanser_Qube_ParametricSystem_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S3>/HIL Read Encoder Timebase' */

  /* S-Function Block: Quanser_Qube_ParametricSystemID_2018/Plant/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (Quanser_Qube_ParametricSyste_DW.HILInitialize_Card,
       Quanser_Qube_ParametricSystem_P.HILReadEncoderTimebase_samples_,
       Quanser_Qube_ParametricSystem_P.HILReadEncoderTimebase_channels, 2,
       &Quanser_Qube_ParametricSyste_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M, _rt_error_message);
    }
  }

  /* Start for ToFile: '<Root>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "sysID_parametric_alpha_input4.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M,
                        "Error creating .mat file sysID_parametric_alpha_input4.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 4 + 1, 0, "ans")) {
      rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M,
                        "Error writing mat file header to file sysID_parametric_alpha_input4.mat");
      return;
    }

    Quanser_Qube_ParametricSyste_DW.ToFile_IWORK.Count = 0;
    Quanser_Qube_ParametricSyste_DW.ToFile_IWORK.Decimation = -1;
    Quanser_Qube_ParametricSyste_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "sysID_parametric_theta_input4.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M,
                        "Error creating .mat file sysID_parametric_theta_input4.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 4 + 1, 0, "ans")) {
      rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M,
                        "Error writing mat file header to file sysID_parametric_theta_input4.mat");
      return;
    }

    Quanser_Qube_ParametricSyste_DW.ToFile1_IWORK.Count = 0;
    Quanser_Qube_ParametricSyste_DW.ToFile1_IWORK.Decimation = -1;
    Quanser_Qube_ParametricSyste_DW.ToFile1_PWORK.FilePtr = fp;
  }

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* InitializeConditions for RandomNumber: '<S1>/White Noise' */
    tmp = floor(Quanser_Qube_ParametricSystem_P.BandLimitedWhiteNoise_seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    Quanser_Qube_ParametricSyste_DW.RandSeed = tseed;
    Quanser_Qube_ParametricSyste_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&Quanser_Qube_ParametricSyste_DW.RandSeed) *
      Quanser_Qube_ParametricSystem_P.WhiteNoise_StdDev +
      Quanser_Qube_ParametricSystem_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S1>/White Noise' */

    /* InitializeConditions for StateSpace: '<S2>/Internal' */
    Quanser_Qube_ParametricSystem_X.Internal_CSTATE[0] = 0.0;
    Quanser_Qube_ParametricSystem_X.Internal_CSTATE[1] = 0.0;
    Quanser_Qube_ParametricSystem_X.Internal_CSTATE[2] = 0.0;
    Quanser_Qube_ParametricSystem_X.Internal_CSTATE[3] = 0.0;
  }
}

/* Model terminate function */
void Quanser_Qube_ParametricSystemID_2018_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S3>/HIL Initialize' */

  /* S-Function Block: Quanser_Qube_ParametricSystemID_2018/Plant/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(Quanser_Qube_ParametricSyste_DW.HILInitialize_Card);
    hil_monitor_stop_all(Quanser_Qube_ParametricSyste_DW.HILInitialize_Card);
    is_switching = false;
    if ((Quanser_Qube_ParametricSystem_P.HILInitialize_AOTerminate &&
         !is_switching) || (Quanser_Qube_ParametricSystem_P.HILInitialize_AOExit
         && is_switching)) {
      num_final_analog_outputs = 1U;
    }

    if ((Quanser_Qube_ParametricSystem_P.HILInitialize_DOTerminate &&
         !is_switching) || (Quanser_Qube_ParametricSystem_P.HILInitialize_DOExit
         && is_switching)) {
      num_final_digital_outputs = 1U;
    }

    if ((Quanser_Qube_ParametricSystem_P.HILInitialize_OOTerminate &&
         !is_switching) || (Quanser_Qube_ParametricSystem_P.HILInitialize_OOExit
         && is_switching)) {
      num_final_other_outputs = 3U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_digital_outputs > 0
        || num_final_other_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(Quanser_Qube_ParametricSyste_DW.HILInitialize_Card
                         ,
                         &Quanser_Qube_ParametricSystem_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         ,
                         &Quanser_Qube_ParametricSystem_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         ,
                         Quanser_Qube_ParametricSystem_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         ,
                         &Quanser_Qube_ParametricSystem_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *)
                         &Quanser_Qube_ParametricSystem_P.HILInitialize_DOFinal
                         , Quanser_Qube_ParametricSystem_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (Quanser_Qube_ParametricSyste_DW.HILInitialize_Card,
             &Quanser_Qube_ParametricSystem_P.HILInitialize_AOChannels,
             num_final_analog_outputs,
             &Quanser_Qube_ParametricSystem_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (Quanser_Qube_ParametricSyste_DW.HILInitialize_Card,
             &Quanser_Qube_ParametricSystem_P.HILInitialize_DOChannels,
             num_final_digital_outputs, (t_boolean *)
             &Quanser_Qube_ParametricSystem_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other
            (Quanser_Qube_ParametricSyste_DW.HILInitialize_Card,
             Quanser_Qube_ParametricSystem_P.HILInitialize_OOChannels,
             num_final_other_outputs,
             Quanser_Qube_ParametricSystem_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Quanser_Qube_ParametricSyste_DW.HILInitialize_Card);
    hil_monitor_delete_all(Quanser_Qube_ParametricSyste_DW.HILInitialize_Card);
    hil_close(Quanser_Qube_ParametricSyste_DW.HILInitialize_Card);
    Quanser_Qube_ParametricSyste_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for ToFile: '<Root>/To File' */
  {
    FILE *fp = (FILE *) Quanser_Qube_ParametricSyste_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "sysID_parametric_alpha_input4.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M,
                          "Error closing MAT-file sysID_parametric_alpha_input4.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M,
                          "Error reopening MAT-file sysID_parametric_alpha_input4.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 4 + 1,
           Quanser_Qube_ParametricSyste_DW.ToFile_IWORK.Count, "ans")) {
        rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M,
                          "Error writing header for ans to MAT-file sysID_parametric_alpha_input4.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M,
                          "Error closing MAT-file sysID_parametric_alpha_input4.mat");
        return;
      }

      Quanser_Qube_ParametricSyste_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (FILE *) Quanser_Qube_ParametricSyste_DW.ToFile1_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "sysID_parametric_theta_input4.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M,
                          "Error closing MAT-file sysID_parametric_theta_input4.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M,
                          "Error reopening MAT-file sysID_parametric_theta_input4.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 4 + 1,
           Quanser_Qube_ParametricSyste_DW.ToFile1_IWORK.Count, "ans")) {
        rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M,
                          "Error writing header for ans to MAT-file sysID_parametric_theta_input4.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(Quanser_Qube_ParametricSyste_M,
                          "Error closing MAT-file sysID_parametric_theta_input4.mat");
        return;
      }

      Quanser_Qube_ParametricSyste_DW.ToFile1_PWORK.FilePtr = (NULL);
    }
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
  Quanser_Qube_ParametricSystemID_2018_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Quanser_Qube_ParametricSystemID_2018_update();
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
  Quanser_Qube_ParametricSystemID_2018_initialize();
}

void MdlTerminate(void)
{
  Quanser_Qube_ParametricSystemID_2018_terminate();
}

/* Registration function */
RT_MODEL_Quanser_Qube_Paramet_T *Quanser_Qube_ParametricSystemID_2018(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Quanser_Qube_ParametricSyste_M, 0,
                sizeof(RT_MODEL_Quanser_Qube_Paramet_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Quanser_Qube_ParametricSyste_M->solverInfo,
                          &Quanser_Qube_ParametricSyste_M->Timing.simTimeStep);
    rtsiSetTPtr(&Quanser_Qube_ParametricSyste_M->solverInfo, &rtmGetTPtr
                (Quanser_Qube_ParametricSyste_M));
    rtsiSetStepSizePtr(&Quanser_Qube_ParametricSyste_M->solverInfo,
                       &Quanser_Qube_ParametricSyste_M->Timing.stepSize0);
    rtsiSetdXPtr(&Quanser_Qube_ParametricSyste_M->solverInfo,
                 &Quanser_Qube_ParametricSyste_M->derivs);
    rtsiSetContStatesPtr(&Quanser_Qube_ParametricSyste_M->solverInfo, (real_T **)
                         &Quanser_Qube_ParametricSyste_M->contStates);
    rtsiSetNumContStatesPtr(&Quanser_Qube_ParametricSyste_M->solverInfo,
      &Quanser_Qube_ParametricSyste_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Quanser_Qube_ParametricSyste_M->solverInfo,
      &Quanser_Qube_ParametricSyste_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&Quanser_Qube_ParametricSyste_M->solverInfo,
       &Quanser_Qube_ParametricSyste_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&Quanser_Qube_ParametricSyste_M->solverInfo,
       &Quanser_Qube_ParametricSyste_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Quanser_Qube_ParametricSyste_M->solverInfo,
                          (&rtmGetErrorStatus(Quanser_Qube_ParametricSyste_M)));
    rtsiSetRTModelPtr(&Quanser_Qube_ParametricSyste_M->solverInfo,
                      Quanser_Qube_ParametricSyste_M);
  }

  rtsiSetSimTimeStep(&Quanser_Qube_ParametricSyste_M->solverInfo,
                     MAJOR_TIME_STEP);
  Quanser_Qube_ParametricSyste_M->intgData.f[0] =
    Quanser_Qube_ParametricSyste_M->odeF[0];
  Quanser_Qube_ParametricSyste_M->contStates = ((real_T *)
    &Quanser_Qube_ParametricSystem_X);
  rtsiSetSolverData(&Quanser_Qube_ParametricSyste_M->solverInfo, (void *)
                    &Quanser_Qube_ParametricSyste_M->intgData);
  rtsiSetSolverName(&Quanser_Qube_ParametricSyste_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      Quanser_Qube_ParametricSyste_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    Quanser_Qube_ParametricSyste_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Quanser_Qube_ParametricSyste_M->Timing.sampleTimes =
      (&Quanser_Qube_ParametricSyste_M->Timing.sampleTimesArray[0]);
    Quanser_Qube_ParametricSyste_M->Timing.offsetTimes =
      (&Quanser_Qube_ParametricSyste_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Quanser_Qube_ParametricSyste_M->Timing.sampleTimes[0] = (0.0);
    Quanser_Qube_ParametricSyste_M->Timing.sampleTimes[1] = (0.002);
    Quanser_Qube_ParametricSyste_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    Quanser_Qube_ParametricSyste_M->Timing.offsetTimes[0] = (0.0);
    Quanser_Qube_ParametricSyste_M->Timing.offsetTimes[1] = (0.0);
    Quanser_Qube_ParametricSyste_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(Quanser_Qube_ParametricSyste_M,
             &Quanser_Qube_ParametricSyste_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Quanser_Qube_ParametricSyste_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    Quanser_Qube_ParametricSyste_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Quanser_Qube_ParametricSyste_M, 10.0);
  Quanser_Qube_ParametricSyste_M->Timing.stepSize0 = 0.002;
  Quanser_Qube_ParametricSyste_M->Timing.stepSize1 = 0.002;
  Quanser_Qube_ParametricSyste_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  Quanser_Qube_ParametricSyste_M->Sizes.checksums[0] = (1181783351U);
  Quanser_Qube_ParametricSyste_M->Sizes.checksums[1] = (1308684498U);
  Quanser_Qube_ParametricSyste_M->Sizes.checksums[2] = (1646017726U);
  Quanser_Qube_ParametricSyste_M->Sizes.checksums[3] = (348077071U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Quanser_Qube_ParametricSyste_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Quanser_Qube_ParametricSyste_M->extModeInfo,
      &Quanser_Qube_ParametricSyste_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Quanser_Qube_ParametricSyste_M->extModeInfo,
                        Quanser_Qube_ParametricSyste_M->Sizes.checksums);
    rteiSetTPtr(Quanser_Qube_ParametricSyste_M->extModeInfo, rtmGetTPtr
                (Quanser_Qube_ParametricSyste_M));
  }

  Quanser_Qube_ParametricSyste_M->solverInfoPtr =
    (&Quanser_Qube_ParametricSyste_M->solverInfo);
  Quanser_Qube_ParametricSyste_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&Quanser_Qube_ParametricSyste_M->solverInfo, 0.002);
  rtsiSetSolverMode(&Quanser_Qube_ParametricSyste_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Quanser_Qube_ParametricSyste_M->blockIO = ((void *)
    &Quanser_Qube_ParametricSystem_B);

  {
    Quanser_Qube_ParametricSystem_B.HILReadEncoderTimebase_o1 = 0.0;
    Quanser_Qube_ParametricSystem_B.HILReadEncoderTimebase_o2 = 0.0;
    Quanser_Qube_ParametricSystem_B.Pendulumcountstorad = 0.0;
    Quanser_Qube_ParametricSystem_B.Armcountstorad = 0.0;
    Quanser_Qube_ParametricSystem_B.WhiteNoise = 0.0;
    Quanser_Qube_ParametricSystem_B.Output = 0.0;
    Quanser_Qube_ParametricSystem_B.Saturation = 0.0;
    Quanser_Qube_ParametricSystem_B.ForveCCW = 0.0;
    Quanser_Qube_ParametricSystem_B.Internal[0] = 0.0;
    Quanser_Qube_ParametricSystem_B.Internal[1] = 0.0;
    Quanser_Qube_ParametricSystem_B.Internal[2] = 0.0;
    Quanser_Qube_ParametricSystem_B.Internal[3] = 0.0;
    Quanser_Qube_ParametricSystem_B.TmpSignalConversionAtToFileInpo[0] = 0.0;
    Quanser_Qube_ParametricSystem_B.TmpSignalConversionAtToFileInpo[1] = 0.0;
    Quanser_Qube_ParametricSystem_B.TmpSignalConversionAtToFileInpo[2] = 0.0;
    Quanser_Qube_ParametricSystem_B.TmpSignalConversionAtToFileInpo[3] = 0.0;
    Quanser_Qube_ParametricSystem_B.TmpSignalConversionAtToFile1Inp[0] = 0.0;
    Quanser_Qube_ParametricSystem_B.TmpSignalConversionAtToFile1Inp[1] = 0.0;
    Quanser_Qube_ParametricSystem_B.TmpSignalConversionAtToFile1Inp[2] = 0.0;
    Quanser_Qube_ParametricSystem_B.TmpSignalConversionAtToFile1Inp[3] = 0.0;
  }

  /* parameters */
  Quanser_Qube_ParametricSyste_M->defaultParam = ((real_T *)
    &Quanser_Qube_ParametricSystem_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Quanser_Qube_ParametricSystem_X;
    Quanser_Qube_ParametricSyste_M->contStates = (x);
    (void) memset((void *)&Quanser_Qube_ParametricSystem_X, 0,
                  sizeof(X_Quanser_Qube_ParametricSyst_T));
  }

  /* states (dwork) */
  Quanser_Qube_ParametricSyste_M->dwork = ((void *)
    &Quanser_Qube_ParametricSyste_DW);
  (void) memset((void *)&Quanser_Qube_ParametricSyste_DW, 0,
                sizeof(DW_Quanser_Qube_ParametricSys_T));
  Quanser_Qube_ParametricSyste_DW.HILInitialize_FilterFrequency[0] = 0.0;
  Quanser_Qube_ParametricSyste_DW.HILInitialize_FilterFrequency[1] = 0.0;
  Quanser_Qube_ParametricSyste_DW.NextOutput = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Quanser_Qube_ParametricSyste_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Quanser_Qube_ParametricSyste_M->Sizes.numContStates = (4);/* Number of continuous states */
  Quanser_Qube_ParametricSyste_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  Quanser_Qube_ParametricSyste_M->Sizes.numY = (0);/* Number of model outputs */
  Quanser_Qube_ParametricSyste_M->Sizes.numU = (0);/* Number of model inputs */
  Quanser_Qube_ParametricSyste_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Quanser_Qube_ParametricSyste_M->Sizes.numSampTimes = (3);/* Number of sample times */
  Quanser_Qube_ParametricSyste_M->Sizes.numBlocks = (17);/* Number of blocks */
  Quanser_Qube_ParametricSyste_M->Sizes.numBlockIO = (11);/* Number of block outputs */
  Quanser_Qube_ParametricSyste_M->Sizes.numBlockPrms = (97);/* Sum of parameter "widths" */
  return Quanser_Qube_ParametricSyste_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
