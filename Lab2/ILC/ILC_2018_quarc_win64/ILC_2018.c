/*
 * ILC_2018.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ILC_2018".
 *
 * Model version              : 1.462
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Wed Oct  9 19:10:38 2019
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ILC_2018.h"
#include "ILC_2018_private.h"
#include "ILC_2018_dt.h"

/* Block signals (default storage) */
B_ILC_2018_T ILC_2018_B;

/* Continuous states */
X_ILC_2018_T ILC_2018_X;

/* Block states (default storage) */
DW_ILC_2018_T ILC_2018_DW;

/* Real-time model */
RT_MODEL_ILC_2018_T ILC_2018_M_;
RT_MODEL_ILC_2018_T *const ILC_2018_M = &ILC_2018_M_;

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
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  ILC_2018_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void ILC_2018_output(void)
{
  real_T temp;
  real_T u1;
  real_T u2;
  if (rtmIsMajorTimeStep(ILC_2018_M)) {
    /* set solver stop time */
    if (!(ILC_2018_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ILC_2018_M->solverInfo,
                            ((ILC_2018_M->Timing.clockTickH0 + 1) *
        ILC_2018_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ILC_2018_M->solverInfo,
                            ((ILC_2018_M->Timing.clockTick0 + 1) *
        ILC_2018_M->Timing.stepSize0 + ILC_2018_M->Timing.clockTickH0 *
        ILC_2018_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ILC_2018_M)) {
    ILC_2018_M->Timing.t[0] = rtsiGetT(&ILC_2018_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ILC_2018_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

    /* S-Function Block: ILC_2018/Plant/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(ILC_2018_DW.HILReadEncoderTimebase_Task, 1,
        &ILC_2018_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ILC_2018_M, _rt_error_message);
      } else {
        ILC_2018_B.HILReadEncoderTimebase_o1 =
          ILC_2018_DW.HILReadEncoderTimebase_Buffer[0];
        ILC_2018_B.HILReadEncoderTimebase_o2 =
          ILC_2018_DW.HILReadEncoderTimebase_Buffer[1];
      }
    }

    /* Gain: '<S99>/Pendulum:  counts to rad' */
    ILC_2018_B.Pendulumcountstorad = ILC_2018_P.Pendulumcountstorad_Gain *
      ILC_2018_B.HILReadEncoderTimebase_o2;

    /* Gain: '<S99>/Arm: counts to rad' */
    ILC_2018_B.Armcountstorad = ILC_2018_P.Armcountstorad_Gain *
      ILC_2018_B.HILReadEncoderTimebase_o1;
  }

  /* SignalGenerator: '<Root>/Signal Generator' */
  temp = 6.2831853071795862 * ILC_2018_M->Timing.t[0];
  ILC_2018_B.SignalGenerator = sin(ILC_2018_P.SignalGenerator_Frequency * temp) *
    ILC_2018_P.SignalGenerator_Amplitude;

  /* Sum: '<Root>/Sum1' */
  ILC_2018_B.Sum1 = ILC_2018_B.SignalGenerator - ILC_2018_B.Armcountstorad;

  /* Gain: '<Root>/Gain' */
  ILC_2018_B.Gain = ILC_2018_P.Gain_Gain * ILC_2018_B.Sum1;

  /* Gain: '<S74>/Proportional Gain' */
  ILC_2018_B.ProportionalGain = ILC_2018_P.Kp * ILC_2018_B.Gain;

  /* Integrator: '<S55>/Integrator' */
  ILC_2018_B.Integrator = ILC_2018_X.Integrator_CSTATE;

  /* Gain: '<S34>/Derivative Gain' */
  ILC_2018_B.DerivativeGain = ILC_2018_P.Kd * ILC_2018_B.Gain;

  /* Integrator: '<S35>/Filter' */
  ILC_2018_B.Filter = ILC_2018_X.Filter_CSTATE;

  /* Sum: '<S35>/SumD' */
  ILC_2018_B.SumD = ILC_2018_B.DerivativeGain - ILC_2018_B.Filter;

  /* Gain: '<S67>/Filter Coefficient' */
  ILC_2018_B.FilterCoefficient = ILC_2018_P.PIDController_N * ILC_2018_B.SumD;

  /* Sum: '<S87>/Sum' */
  ILC_2018_B.Sum = (ILC_2018_B.ProportionalGain + ILC_2018_B.Integrator) +
    ILC_2018_B.FilterCoefficient;

  /* FromWorkspace: '<Root>/From Workspace' */
  {
    real_T *pDataValues = (real_T *) ILC_2018_DW.FromWorkspace_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) ILC_2018_DW.FromWorkspace_PWORK.TimePtr;
    int_T currTimeIndex = ILC_2018_DW.FromWorkspace_IWORK.PrevIndex;
    real_T t = ILC_2018_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[10]) {
      currTimeIndex = 9;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    ILC_2018_DW.FromWorkspace_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          ILC_2018_B.FromWorkspace = pDataValues[currTimeIndex];
        } else {
          ILC_2018_B.FromWorkspace = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        ILC_2018_B.FromWorkspace = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 11;
      }
    }
  }

  /* Sum: '<Root>/Sum2' */
  ILC_2018_B.Sum2 = ILC_2018_B.Sum + ILC_2018_B.FromWorkspace;

  /* Saturate: '<S2>/Saturation' */
  temp = ILC_2018_B.Sum2;
  u1 = ILC_2018_P.Saturation_LowerSat;
  u2 = ILC_2018_P.Saturation_UpperSat;
  if (temp > u2) {
    ILC_2018_B.Saturation = u2;
  } else if (temp < u1) {
    ILC_2018_B.Saturation = u1;
  } else {
    ILC_2018_B.Saturation = temp;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Gain: '<S2>/For +ve CCW' */
  ILC_2018_B.ForveCCW = ILC_2018_P.ForveCCW_Gain * ILC_2018_B.Saturation;
  if (rtmIsMajorTimeStep(ILC_2018_M)) {
    /* S-Function (hil_write_analog_block): '<S2>/HIL Write Analog' */

    /* S-Function Block: ILC_2018/Plant/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(ILC_2018_DW.HILInitialize_Card,
        &ILC_2018_P.HILWriteAnalog_channels, 1, &ILC_2018_B.ForveCCW);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ILC_2018_M, _rt_error_message);
      }
    }

    /* SignalConversion: '<Root>/TmpSignal ConversionAtTo FileInport1' */
    ILC_2018_B.TmpSignalConversionAtToFileInpo[0] = ILC_2018_B.SignalGenerator;
    ILC_2018_B.TmpSignalConversionAtToFileInpo[1] =
      ILC_2018_B.Pendulumcountstorad;
    ILC_2018_B.TmpSignalConversionAtToFileInpo[2] = ILC_2018_B.Armcountstorad;

    /* ToFile: '<Root>/To File' */
    {
      if (!(++ILC_2018_DW.ToFile_IWORK.Decimation % 1) &&
          (ILC_2018_DW.ToFile_IWORK.Count * (3 + 1)) + 1 < 100000000 ) {
        FILE *fp = (FILE *) ILC_2018_DW.ToFile_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[3 + 1];
          ILC_2018_DW.ToFile_IWORK.Decimation = 0;
          u[0] = ILC_2018_M->Timing.t[1];
          u[1] = ILC_2018_B.TmpSignalConversionAtToFileInpo[0];
          u[2] = ILC_2018_B.TmpSignalConversionAtToFileInpo[1];
          u[3] = ILC_2018_B.TmpSignalConversionAtToFileInpo[2];
          if (fwrite(u, sizeof(real_T), 3 + 1, fp) != 3 + 1) {
            rtmSetErrorStatus(ILC_2018_M,
                              "Error writing to MAT-file response.mat");
            return;
          }

          if (((++ILC_2018_DW.ToFile_IWORK.Count) * (3 + 1))+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file response.mat.\n");
          }
        }
      }
    }
  }

  /* Gain: '<S47>/Integral Gain' */
  ILC_2018_B.IntegralGain = ILC_2018_P.Ki * ILC_2018_B.Gain;
}

/* Model update function */
void ILC_2018_update(void)
{
  if (rtmIsMajorTimeStep(ILC_2018_M)) {
    rt_ertODEUpdateContinuousStates(&ILC_2018_M->solverInfo);
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
  if (!(++ILC_2018_M->Timing.clockTick0)) {
    ++ILC_2018_M->Timing.clockTickH0;
  }

  ILC_2018_M->Timing.t[0] = rtsiGetSolverStopTime(&ILC_2018_M->solverInfo);

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
    if (!(++ILC_2018_M->Timing.clockTick1)) {
      ++ILC_2018_M->Timing.clockTickH1;
    }

    ILC_2018_M->Timing.t[1] = ILC_2018_M->Timing.clockTick1 *
      ILC_2018_M->Timing.stepSize1 + ILC_2018_M->Timing.clockTickH1 *
      ILC_2018_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ILC_2018_derivatives(void)
{
  XDot_ILC_2018_T *_rtXdot;
  _rtXdot = ((XDot_ILC_2018_T *) ILC_2018_M->derivs);

  /* Derivatives for Integrator: '<S55>/Integrator' */
  _rtXdot->Integrator_CSTATE = ILC_2018_B.IntegralGain;

  /* Derivatives for Integrator: '<S35>/Filter' */
  _rtXdot->Filter_CSTATE = ILC_2018_B.FilterCoefficient;
}

/* Model initialize function */
void ILC_2018_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S2>/HIL Initialize' */

  /* S-Function Block: ILC_2018/Plant/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo2_usb", "0", &ILC_2018_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ILC_2018_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_watchdog_clear(ILC_2018_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ILC_2018_M, _rt_error_message);
      return;
    }

    if ((ILC_2018_P.HILInitialize_AIPStart && !is_switching) ||
        (ILC_2018_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(ILC_2018_DW.HILInitialize_Card,
        &ILC_2018_P.HILInitialize_AIChannels, 1U,
        &ILC_2018_P.HILInitialize_AILow, &ILC_2018_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ILC_2018_M, _rt_error_message);
        return;
      }
    }

    if ((ILC_2018_P.HILInitialize_AOPStart && !is_switching) ||
        (ILC_2018_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(ILC_2018_DW.HILInitialize_Card,
        &ILC_2018_P.HILInitialize_AOChannels, 1U,
        &ILC_2018_P.HILInitialize_AOLow, &ILC_2018_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ILC_2018_M, _rt_error_message);
        return;
      }
    }

    if ((ILC_2018_P.HILInitialize_AOStart && !is_switching) ||
        (ILC_2018_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(ILC_2018_DW.HILInitialize_Card,
        &ILC_2018_P.HILInitialize_AOChannels, 1U,
        &ILC_2018_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ILC_2018_M, _rt_error_message);
        return;
      }
    }

    if (ILC_2018_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (ILC_2018_DW.HILInitialize_Card, &ILC_2018_P.HILInitialize_AOChannels,
         1U, &ILC_2018_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ILC_2018_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(ILC_2018_DW.HILInitialize_Card, NULL, 0U,
      &ILC_2018_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ILC_2018_M, _rt_error_message);
      return;
    }

    if ((ILC_2018_P.HILInitialize_DOStart && !is_switching) ||
        (ILC_2018_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(ILC_2018_DW.HILInitialize_Card,
        &ILC_2018_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &ILC_2018_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ILC_2018_M, _rt_error_message);
        return;
      }
    }

    if (ILC_2018_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (ILC_2018_DW.HILInitialize_Card, &ILC_2018_P.HILInitialize_DOChannels,
         1U, (const t_digital_state *) &ILC_2018_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ILC_2018_M, _rt_error_message);
        return;
      }
    }

    if ((ILC_2018_P.HILInitialize_EIPStart && !is_switching) ||
        (ILC_2018_P.HILInitialize_EIPEnter && is_switching)) {
      ILC_2018_DW.HILInitialize_QuadratureModes[0] =
        ILC_2018_P.HILInitialize_EIQuadrature;
      ILC_2018_DW.HILInitialize_QuadratureModes[1] =
        ILC_2018_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(ILC_2018_DW.HILInitialize_Card,
        ILC_2018_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode *)
        &ILC_2018_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ILC_2018_M, _rt_error_message);
        return;
      }
    }

    if ((ILC_2018_P.HILInitialize_EIStart && !is_switching) ||
        (ILC_2018_P.HILInitialize_EIEnter && is_switching)) {
      ILC_2018_DW.HILInitialize_InitialEICounts[0] =
        ILC_2018_P.HILInitialize_EIInitial;
      ILC_2018_DW.HILInitialize_InitialEICounts[1] =
        ILC_2018_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(ILC_2018_DW.HILInitialize_Card,
        ILC_2018_P.HILInitialize_EIChannels, 2U,
        &ILC_2018_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ILC_2018_M, _rt_error_message);
        return;
      }
    }

    if ((ILC_2018_P.HILInitialize_OOStart && !is_switching) ||
        (ILC_2018_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(ILC_2018_DW.HILInitialize_Card,
        ILC_2018_P.HILInitialize_OOChannels, 3U,
        ILC_2018_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ILC_2018_M, _rt_error_message);
        return;
      }
    }

    if (ILC_2018_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (ILC_2018_DW.HILInitialize_Card, ILC_2018_P.HILInitialize_OOChannels, 3U,
         ILC_2018_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ILC_2018_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

  /* S-Function Block: ILC_2018/Plant/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(ILC_2018_DW.HILInitialize_Card,
      ILC_2018_P.HILReadEncoderTimebase_samples_,
      ILC_2018_P.HILReadEncoderTimebase_channels, 2,
      &ILC_2018_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ILC_2018_M, _rt_error_message);
    }
  }

  /* Start for FromWorkspace: '<Root>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.1, 0.2, 0.30000000000000004, 0.4,
      0.5, 0.6, 0.7, 0.8, 0.9, 1.0 } ;

    static real_T pDataValues0[] = { 0.17592455836693655, 0.34568541305518213,
      0.52152663422754109, 0.67887676191060342, 0.8177080418949616,
      0.96253643011791956, 1.0887905192249254, 1.1903066976130185,
      1.291601000106243, 1.368102111353078, 0.0 } ;

    ILC_2018_DW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    ILC_2018_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    ILC_2018_DW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* Start for ToFile: '<Root>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "response.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ILC_2018_M, "Error creating .mat file response.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 3 + 1, 0, "ans")) {
      rtmSetErrorStatus(ILC_2018_M,
                        "Error writing mat file header to file response.mat");
      return;
    }

    ILC_2018_DW.ToFile_IWORK.Count = 0;
    ILC_2018_DW.ToFile_IWORK.Decimation = -1;
    ILC_2018_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* InitializeConditions for Integrator: '<S55>/Integrator' */
  ILC_2018_X.Integrator_CSTATE = ILC_2018_P.PIDController_InitialConditio_l;

  /* InitializeConditions for Integrator: '<S35>/Filter' */
  ILC_2018_X.Filter_CSTATE = ILC_2018_P.PIDController_InitialConditionF;
}

/* Model terminate function */
void ILC_2018_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S2>/HIL Initialize' */

  /* S-Function Block: ILC_2018/Plant/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(ILC_2018_DW.HILInitialize_Card);
    hil_monitor_stop_all(ILC_2018_DW.HILInitialize_Card);
    is_switching = false;
    if ((ILC_2018_P.HILInitialize_AOTerminate && !is_switching) ||
        (ILC_2018_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    }

    if ((ILC_2018_P.HILInitialize_DOTerminate && !is_switching) ||
        (ILC_2018_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    }

    if ((ILC_2018_P.HILInitialize_OOTerminate && !is_switching) ||
        (ILC_2018_P.HILInitialize_OOExit && is_switching)) {
      num_final_other_outputs = 3U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_digital_outputs > 0
        || num_final_other_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(ILC_2018_DW.HILInitialize_Card
                         , &ILC_2018_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &ILC_2018_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , ILC_2018_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &ILC_2018_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *) &ILC_2018_P.HILInitialize_DOFinal
                         , ILC_2018_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(ILC_2018_DW.HILInitialize_Card,
            &ILC_2018_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &ILC_2018_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(ILC_2018_DW.HILInitialize_Card,
            &ILC_2018_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &ILC_2018_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(ILC_2018_DW.HILInitialize_Card,
            ILC_2018_P.HILInitialize_OOChannels, num_final_other_outputs,
            ILC_2018_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(ILC_2018_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(ILC_2018_DW.HILInitialize_Card);
    hil_monitor_delete_all(ILC_2018_DW.HILInitialize_Card);
    hil_close(ILC_2018_DW.HILInitialize_Card);
    ILC_2018_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for ToFile: '<Root>/To File' */
  {
    FILE *fp = (FILE *) ILC_2018_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "response.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ILC_2018_M, "Error closing MAT-file response.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ILC_2018_M, "Error reopening MAT-file response.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 3 + 1, ILC_2018_DW.ToFile_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(ILC_2018_M,
                          "Error writing header for ans to MAT-file response.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ILC_2018_M, "Error closing MAT-file response.mat");
        return;
      }

      ILC_2018_DW.ToFile_PWORK.FilePtr = (NULL);
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
  ILC_2018_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ILC_2018_update();
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
  ILC_2018_initialize();
}

void MdlTerminate(void)
{
  ILC_2018_terminate();
}

/* Registration function */
RT_MODEL_ILC_2018_T *ILC_2018(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ILC_2018_M, 0,
                sizeof(RT_MODEL_ILC_2018_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ILC_2018_M->solverInfo,
                          &ILC_2018_M->Timing.simTimeStep);
    rtsiSetTPtr(&ILC_2018_M->solverInfo, &rtmGetTPtr(ILC_2018_M));
    rtsiSetStepSizePtr(&ILC_2018_M->solverInfo, &ILC_2018_M->Timing.stepSize0);
    rtsiSetdXPtr(&ILC_2018_M->solverInfo, &ILC_2018_M->derivs);
    rtsiSetContStatesPtr(&ILC_2018_M->solverInfo, (real_T **)
                         &ILC_2018_M->contStates);
    rtsiSetNumContStatesPtr(&ILC_2018_M->solverInfo,
      &ILC_2018_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ILC_2018_M->solverInfo,
      &ILC_2018_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ILC_2018_M->solverInfo,
      &ILC_2018_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ILC_2018_M->solverInfo,
      &ILC_2018_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ILC_2018_M->solverInfo, (&rtmGetErrorStatus
      (ILC_2018_M)));
    rtsiSetRTModelPtr(&ILC_2018_M->solverInfo, ILC_2018_M);
  }

  rtsiSetSimTimeStep(&ILC_2018_M->solverInfo, MAJOR_TIME_STEP);
  ILC_2018_M->intgData.f[0] = ILC_2018_M->odeF[0];
  ILC_2018_M->contStates = ((real_T *) &ILC_2018_X);
  rtsiSetSolverData(&ILC_2018_M->solverInfo, (void *)&ILC_2018_M->intgData);
  rtsiSetSolverName(&ILC_2018_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ILC_2018_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ILC_2018_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ILC_2018_M->Timing.sampleTimes = (&ILC_2018_M->Timing.sampleTimesArray[0]);
    ILC_2018_M->Timing.offsetTimes = (&ILC_2018_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ILC_2018_M->Timing.sampleTimes[0] = (0.0);
    ILC_2018_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    ILC_2018_M->Timing.offsetTimes[0] = (0.0);
    ILC_2018_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ILC_2018_M, &ILC_2018_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ILC_2018_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ILC_2018_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ILC_2018_M, 1.0);
  ILC_2018_M->Timing.stepSize0 = 0.002;
  ILC_2018_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  ILC_2018_M->Sizes.checksums[0] = (3093031116U);
  ILC_2018_M->Sizes.checksums[1] = (1405111903U);
  ILC_2018_M->Sizes.checksums[2] = (3665696047U);
  ILC_2018_M->Sizes.checksums[3] = (3704635403U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    ILC_2018_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ILC_2018_M->extModeInfo,
      &ILC_2018_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ILC_2018_M->extModeInfo, ILC_2018_M->Sizes.checksums);
    rteiSetTPtr(ILC_2018_M->extModeInfo, rtmGetTPtr(ILC_2018_M));
  }

  ILC_2018_M->solverInfoPtr = (&ILC_2018_M->solverInfo);
  ILC_2018_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&ILC_2018_M->solverInfo, 0.002);
  rtsiSetSolverMode(&ILC_2018_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ILC_2018_M->blockIO = ((void *) &ILC_2018_B);

  {
    ILC_2018_B.HILReadEncoderTimebase_o1 = 0.0;
    ILC_2018_B.HILReadEncoderTimebase_o2 = 0.0;
    ILC_2018_B.Pendulumcountstorad = 0.0;
    ILC_2018_B.Armcountstorad = 0.0;
    ILC_2018_B.SignalGenerator = 0.0;
    ILC_2018_B.Sum1 = 0.0;
    ILC_2018_B.Gain = 0.0;
    ILC_2018_B.ProportionalGain = 0.0;
    ILC_2018_B.Integrator = 0.0;
    ILC_2018_B.DerivativeGain = 0.0;
    ILC_2018_B.Filter = 0.0;
    ILC_2018_B.SumD = 0.0;
    ILC_2018_B.FilterCoefficient = 0.0;
    ILC_2018_B.Sum = 0.0;
    ILC_2018_B.FromWorkspace = 0.0;
    ILC_2018_B.Sum2 = 0.0;
    ILC_2018_B.Saturation = 0.0;
    ILC_2018_B.ForveCCW = 0.0;
    ILC_2018_B.TmpSignalConversionAtToFileInpo[0] = 0.0;
    ILC_2018_B.TmpSignalConversionAtToFileInpo[1] = 0.0;
    ILC_2018_B.TmpSignalConversionAtToFileInpo[2] = 0.0;
    ILC_2018_B.IntegralGain = 0.0;
  }

  /* parameters */
  ILC_2018_M->defaultParam = ((real_T *)&ILC_2018_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ILC_2018_X;
    ILC_2018_M->contStates = (x);
    (void) memset((void *)&ILC_2018_X, 0,
                  sizeof(X_ILC_2018_T));
  }

  /* states (dwork) */
  ILC_2018_M->dwork = ((void *) &ILC_2018_DW);
  (void) memset((void *)&ILC_2018_DW, 0,
                sizeof(DW_ILC_2018_T));
  ILC_2018_DW.HILInitialize_FilterFrequency[0] = 0.0;
  ILC_2018_DW.HILInitialize_FilterFrequency[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ILC_2018_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  ILC_2018_M->Sizes.numContStates = (2);/* Number of continuous states */
  ILC_2018_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ILC_2018_M->Sizes.numY = (0);        /* Number of model outputs */
  ILC_2018_M->Sizes.numU = (0);        /* Number of model inputs */
  ILC_2018_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ILC_2018_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ILC_2018_M->Sizes.numBlocks = (23);  /* Number of blocks */
  ILC_2018_M->Sizes.numBlockIO = (20); /* Number of block outputs */
  ILC_2018_M->Sizes.numBlockPrms = (88);/* Sum of parameter "widths" */
  return ILC_2018_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
