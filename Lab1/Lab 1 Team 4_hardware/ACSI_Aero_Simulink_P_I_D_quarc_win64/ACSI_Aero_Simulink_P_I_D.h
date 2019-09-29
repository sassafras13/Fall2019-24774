/*
 * ACSI_Aero_Simulink_P_I_D.h
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

#ifndef RTW_HEADER_ACSI_Aero_Simulink_P_I_D_h_
#define RTW_HEADER_ACSI_Aero_Simulink_P_I_D_h_
#include <math.h>
#include <string.h>
#ifndef ACSI_Aero_Simulink_P_I_D_COMMON_INCLUDES_
# define ACSI_Aero_Simulink_P_I_D_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "hil.h"
#include "quanser_messages.h"
#include "quanser_extern.h"
#endif                                 /* ACSI_Aero_Simulink_P_I_D_COMMON_INCLUDES_ */

#include "ACSI_Aero_Simulink_P_I_D_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
# define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
# define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
# define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
# define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
# define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
# define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ()
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
# define rtmGetSelf(rtm)               ()
#endif

#ifndef rtmSetSelf
# define rtmSetSelf(rtm, val)          ()
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGettimingBridge
# define rtmGettimingBridge(rtm)       ()
#endif

#ifndef rtmSettimingBridge
# define rtmSettimingBridge(rtm, val)  ()
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define ACSI_Aero_Simulink_P_I_D_rtModel RT_MODEL_ACSI_Aero_Simulink_P_T

/* Block signals (default storage) */
typedef struct {
  real_T Internal[2];                  /* '<S1>/Internal' */
  real_T MotorEnable[2];               /* '<S5>/Motor Enable' */
  real_T Countstorads[2];              /* '<S5>/Counts to rads' */
  real_T Sum;                          /* '<S5>/Sum' */
  real_T Pitchref;                     /* '<Root>/Pitch ref' */
  real_T Yawref;                       /* '<Root>/Yaw ref' */
  real_T FilterCoefficient;            /* '<S74>/Filter Coefficient' */
  real_T FilterCoefficient_c;          /* '<S170>/Filter Coefficient' */
  real_T TmpSignalConversionAtInternalIn[2];/* '<S1>/Input Delay' */
  real_T IntegralGain;                 /* '<S54>/Integral Gain' */
  real_T IntegralGain_i;               /* '<S150>/Integral Gain' */
  real_T Stepend_time;                 /* '<S203>/Step: end_time' */
  real_T Count;                        /* '<S209>/Count' */
  real_T Sum_j;                        /* '<S205>/Sum' */
  real_T div;                          /* '<S205>/div' */
} B_ACSI_Aero_Simulink_P_I_D_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S209>/Unit Delay' */
  real_T Sumk1n1xk_DSTATE;             /* '<S205>/Sum( k=1,n-1, x(k) )' */
  real_T HILInitialize_AIMinimums[2];  /* '<S5>/HIL Initialize' */
  real_T HILInitialize_AIMaximums[2];  /* '<S5>/HIL Initialize' */
  real_T HILInitialize_AOMinimums[2];  /* '<S5>/HIL Initialize' */
  real_T HILInitialize_AOMaximums[2];  /* '<S5>/HIL Initialize' */
  real_T HILInitialize_AOVoltages[2];  /* '<S5>/HIL Initialize' */
  real_T HILInitialize_FilterFrequency[4];/* '<S5>/HIL Initialize' */
  t_card HILInitialize_Card;           /* '<S5>/HIL Initialize' */
  t_task HILReadTimebase_Task;         /* '<S5>/HIL Read Timebase' */
  void *HILWrite_PWORK;                /* '<S5>/HIL Write' */
  struct {
    void *LoggedData[2];
  } Pitch_PWORK;                       /* '<Root>/Pitch ' */

  struct {
    void *LoggedData[2];
  } Yaw_PWORK;                         /* '<Root>/Yaw ' */

  int32_T HILInitialize_ClockModes;    /* '<S5>/HIL Initialize' */
  int32_T HILInitialize_AIConfigValues[2];/* '<S5>/HIL Initialize' */
  int32_T HILInitialize_DOStates[2];   /* '<S5>/HIL Initialize' */
  int32_T HILInitialize_QuadratureModes[4];/* '<S5>/HIL Initialize' */
  int32_T HILInitialize_InitialEICounts[4];/* '<S5>/HIL Initialize' */
  int32_T HILReadTimebase_EncoderBuffer[2];/* '<S5>/HIL Read Timebase' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S203>/Switch Case' */
  int8_T SwitchCaseActionSubsystem2_Subs;/* '<S203>/Switch Case Action Subsystem2' */
  int8_T SwitchCaseActionSubsystem1_Subs;/* '<S203>/Switch Case Action Subsystem1' */
  int8_T SwitchCaseActionSubsystem_Subsy;/* '<S203>/Switch Case Action Subsystem' */
  int8_T EnabledMovingAverage_SubsysRanB;/* '<S203>/Enabled Moving Average' */
  boolean_T HILInitialize_DOBits[2];   /* '<S5>/HIL Initialize' */
  boolean_T EnabledMovingAverage_MODE; /* '<S203>/Enabled Moving Average' */
} DW_ACSI_Aero_Simulink_P_I_D_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Internal_CSTATE[8];           /* '<S1>/Internal' */
  real_T Internal_CSTATE_h[4];         /* '<S2>/Internal' */
  real_T Integrator_CSTATE;            /* '<S62>/Integrator' */
  real_T Filter_CSTATE;                /* '<S42>/Filter' */
  real_T Integrator_CSTATE_m;          /* '<S158>/Integrator' */
  real_T Filter_CSTATE_g;              /* '<S138>/Filter' */
} X_ACSI_Aero_Simulink_P_I_D_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Internal_CSTATE[8];           /* '<S1>/Internal' */
  real_T Internal_CSTATE_h[4];         /* '<S2>/Internal' */
  real_T Integrator_CSTATE;            /* '<S62>/Integrator' */
  real_T Filter_CSTATE;                /* '<S42>/Filter' */
  real_T Integrator_CSTATE_m;          /* '<S158>/Integrator' */
  real_T Filter_CSTATE_g;              /* '<S138>/Filter' */
} XDot_ACSI_Aero_Simulink_P_I_D_T;

/* State disabled  */
typedef struct {
  boolean_T Internal_CSTATE[8];        /* '<S1>/Internal' */
  boolean_T Internal_CSTATE_h[4];      /* '<S2>/Internal' */
  boolean_T Integrator_CSTATE;         /* '<S62>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S42>/Filter' */
  boolean_T Integrator_CSTATE_m;       /* '<S158>/Integrator' */
  boolean_T Filter_CSTATE_g;           /* '<S138>/Filter' */
} XDis_ACSI_Aero_Simulink_P_I_D_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            ACSI_Aero_Simulink_P_I_D_B
#define BlockIO                        B_ACSI_Aero_Simulink_P_I_D_T
#define rtX                            ACSI_Aero_Simulink_P_I_D_X
#define ContinuousStates               X_ACSI_Aero_Simulink_P_I_D_T
#define rtXdot                         ACSI_Aero_Simulink_P_I_D_XDot
#define StateDerivatives               XDot_ACSI_Aero_Simulink_P_I_D_T
#define tXdis                          ACSI_Aero_Simulink_P_I_D_XDis
#define StateDisabled                  XDis_ACSI_Aero_Simulink_P_I_D_T
#define rtP                            ACSI_Aero_Simulink_P_I_D_P
#define Parameters                     P_ACSI_Aero_Simulink_P_I_D_T
#define rtDWork                        ACSI_Aero_Simulink_P_I_D_DW
#define D_Work                         DW_ACSI_Aero_Simulink_P_I_D_T

/* Parameters (default storage) */
struct P_ACSI_Aero_Simulink_P_I_D_T_ {
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S41>/Derivative Gain'
                                        */
  real_T PIDController1_D;             /* Mask Parameter: PIDController1_D
                                        * Referenced by: '<S137>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S54>/Integral Gain'
                                        */
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S150>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;/* Mask Parameter: PIDController_InitialConditionF
                                          * Referenced by: '<S42>/Filter'
                                          */
  real_T PIDController1_InitialCondition;/* Mask Parameter: PIDController1_InitialCondition
                                          * Referenced by: '<S138>/Filter'
                                          */
  real_T PIDController_InitialConditio_e;/* Mask Parameter: PIDController_InitialConditio_e
                                          * Referenced by: '<S62>/Integrator'
                                          */
  real_T PIDController1_InitialConditi_e;/* Mask Parameter: PIDController1_InitialConditi_e
                                          * Referenced by: '<S158>/Integrator'
                                          */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S74>/Filter Coefficient'
                                        */
  real_T PIDController1_N;             /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S170>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S81>/Proportional Gain'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S177>/Proportional Gain'
                                        */
  real_T Green_color[3];               /* Mask Parameter: Green_color
                                        * Referenced by: '<S202>/Constant'
                                        */
  real_T Yellow_color[3];              /* Mask Parameter: Yellow_color
                                        * Referenced by: '<S204>/Constant'
                                        */
  real_T PitchBiasRemoval_end_time;    /* Mask Parameter: PitchBiasRemoval_end_time
                                        * Referenced by: '<S203>/Step: end_time'
                                        */
  real_T PitchBiasRemoval_start_time;  /* Mask Parameter: PitchBiasRemoval_start_time
                                        * Referenced by: '<S203>/Step: start_time'
                                        */
  real_T PitchBiasRemoval_switch_id;   /* Mask Parameter: PitchBiasRemoval_switch_id
                                        * Referenced by: '<S203>/Constant'
                                        */
  int32_T HILReadTimebase_clock;       /* Mask Parameter: HILReadTimebase_clock
                                        * Referenced by: '<S5>/HIL Read Timebase'
                                        */
  uint32_T HILReadTimebase_analog_channels[2];/* Mask Parameter: HILReadTimebase_analog_channels
                                               * Referenced by: '<S5>/HIL Read Timebase'
                                               */
  uint32_T HILWrite_analog_channels[2];/* Mask Parameter: HILWrite_analog_channels
                                        * Referenced by: '<S5>/HIL Write'
                                        */
  uint32_T HILReadTimebase_encoder_channel[2];/* Mask Parameter: HILReadTimebase_encoder_channel
                                               * Referenced by: '<S5>/HIL Read Timebase'
                                               */
  uint32_T HILReadTimebase_other_channels[4];/* Mask Parameter: HILReadTimebase_other_channels
                                              * Referenced by: '<S5>/HIL Read Timebase'
                                              */
  uint32_T HILWrite_other_channels[3]; /* Mask Parameter: HILWrite_other_channels
                                        * Referenced by: '<S5>/HIL Write'
                                        */
  uint32_T HILReadTimebase_samples_in_buff;/* Mask Parameter: HILReadTimebase_samples_in_buff
                                            * Referenced by: '<S5>/HIL Read Timebase'
                                            */
  real_T u4V_UpperSat;                 /* Expression: 24
                                        * Referenced by: '<S5>/+//- 24V'
                                        */
  real_T u4V_LowerSat;                 /* Expression: -24
                                        * Referenced by: '<S5>/+//- 24V'
                                        */
  real_T x_avg_n_Y0;                   /* Computed Parameter: x_avg_n_Y0
                                        * Referenced by: '<S205>/x_avg_n'
                                        */
  real_T unity_Value;                  /* Expression: 1
                                        * Referenced by: '<S209>/unity'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S209>/Unit Delay'
                                        */
  real_T Sumk1n1xk_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S205>/Sum( k=1,n-1, x(k) )'
                                        */
  real_T zero_Y0;                      /* Expression: [0]
                                        * Referenced by: '<S206>/zero'
                                        */
  real_T Vbiased_Y0;                   /* Expression: [0]
                                        * Referenced by: '<S207>/Vbiased'
                                        */
  real_T Vunbiased_Y0;                 /* Expression: [0]
                                        * Referenced by: '<S208>/Vunbiased'
                                        */
  real_T Stepstart_time_Y0;            /* Expression: 0
                                        * Referenced by: '<S203>/Step: start_time'
                                        */
  real_T Stepstart_time_YFinal;        /* Expression: 1
                                        * Referenced by: '<S203>/Step: start_time'
                                        */
  real_T Stepend_time_Y0;              /* Expression: 0
                                        * Referenced by: '<S203>/Step: end_time'
                                        */
  real_T Stepend_time_YFinal;          /* Expression: 1
                                        * Referenced by: '<S203>/Step: end_time'
                                        */
  real_T HILInitialize_OOTerminate;    /* Expression: set_other_outputs_at_terminate
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  real_T HILInitialize_OOExit;         /* Expression: set_other_outputs_at_switch_out
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  real_T HILInitialize_OOStart;        /* Expression: set_other_outputs_at_start
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  real_T HILInitialize_OOEnter;        /* Expression: set_other_outputs_at_switch_in
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  real_T HILInitialize_AOFinal;        /* Expression: final_analog_outputs
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  real_T HILInitialize_OOFinal[3];     /* Expression: final_other_outputs
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  real_T HILInitialize_AIHigh;         /* Expression: analog_input_maximums
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  real_T HILInitialize_AILow;          /* Expression: analog_input_minimums
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  real_T HILInitialize_AOHigh;         /* Expression: analog_output_maximums
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  real_T HILInitialize_AOLow;          /* Expression: analog_output_minimums
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  real_T HILInitialize_AOInitial;      /* Expression: initial_analog_outputs
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  real_T HILInitialize_AOWatchdog;     /* Expression: watchdog_analog_outputs
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  real_T HILInitialize_OOInitial[3];   /* Expression: initial_other_outputs
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  real_T HILInitialize_OOWatchdog[3];  /* Expression: watchdog_other_outputs
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  real_T Internal_A[10];               /* Computed Parameter: Internal_A
                                        * Referenced by: '<S1>/Internal'
                                        */
  real_T Internal_B[4];                /* Computed Parameter: Internal_B
                                        * Referenced by: '<S1>/Internal'
                                        */
  real_T Internal_C[2];                /* Computed Parameter: Internal_C
                                        * Referenced by: '<S1>/Internal'
                                        */
  real_T Internal_A_i[10];             /* Computed Parameter: Internal_A_i
                                        * Referenced by: '<S2>/Internal'
                                        */
  real_T Internal_B_k[4];              /* Computed Parameter: Internal_B_k
                                        * Referenced by: '<S2>/Internal'
                                        */
  real_T Internal_C_p[8];              /* Computed Parameter: Internal_C_p
                                        * Referenced by: '<S2>/Internal'
                                        */
  real_T Internal_D[4];                /* Computed Parameter: Internal_D
                                        * Referenced by: '<S2>/Internal'
                                        */
  real_T NoControl_Value[2];           /* Expression: [0 0]
                                        * Referenced by: '<S5>/No Control'
                                        */
  real_T MotorEnable_Threshold;        /* Expression: 0
                                        * Referenced by: '<S5>/Motor Enable'
                                        */
  real_T LEDColour_Threshold;          /* Expression: 0
                                        * Referenced by: '<S5>/LED Colour'
                                        */
  real_T Countstorads_Gain[2];         /* Expression: [2*pi/2048 2*pi/4096]
                                        * Referenced by: '<S5>/Counts to rads'
                                        */
  real_T Pitchref_Amplitude;           /* Expression: pi/6
                                        * Referenced by: '<Root>/Pitch ref'
                                        */
  real_T Pitchref_Frequency;           /* Computed Parameter: Pitchref_Frequency
                                        * Referenced by: '<Root>/Pitch ref'
                                        */
  real_T Yawref_Amplitude;             /* Expression: 0
                                        * Referenced by: '<Root>/Yaw ref'
                                        */
  real_T Yawref_Frequency;             /* Computed Parameter: Yawref_Frequency
                                        * Referenced by: '<Root>/Yaw ref'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 25
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -25
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 25
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -25
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  int32_T HILInitialize_CKChannels;    /* Computed Parameter: HILInitialize_CKChannels
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  int32_T HILInitialize_AIConfiguration;/* Computed Parameter: HILInitialize_AIConfiguration
                                         * Referenced by: '<S5>/HIL Initialize'
                                         */
  int32_T HILInitialize_DOWatchdog;    /* Computed Parameter: HILInitialize_DOWatchdog
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  int32_T HILInitialize_EIInitial;     /* Computed Parameter: HILInitialize_EIInitial
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  uint32_T HILInitialize_AIChannels[2];/* Computed Parameter: HILInitialize_AIChannels
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  uint32_T HILInitialize_AOChannels[2];/* Computed Parameter: HILInitialize_AOChannels
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  uint32_T HILInitialize_DOChannels[2];/* Computed Parameter: HILInitialize_DOChannels
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  uint32_T HILInitialize_EIChannels[4];/* Computed Parameter: HILInitialize_EIChannels
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  uint32_T HILInitialize_EIQuadrature; /* Computed Parameter: HILInitialize_EIQuadrature
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  uint32_T HILInitialize_OOChannels[3];/* Computed Parameter: HILInitialize_OOChannels
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_Active;      /* Computed Parameter: HILInitialize_Active
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOTerminate; /* Computed Parameter: HILInitialize_AOTerminate
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOExit;      /* Computed Parameter: HILInitialize_AOExit
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOTerminate; /* Computed Parameter: HILInitialize_DOTerminate
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOExit;      /* Computed Parameter: HILInitialize_DOExit
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POTerminate; /* Computed Parameter: HILInitialize_POTerminate
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POExit;      /* Computed Parameter: HILInitialize_POExit
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKPStart;    /* Computed Parameter: HILInitialize_CKPStart
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKPEnter;    /* Computed Parameter: HILInitialize_CKPEnter
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKStart;     /* Computed Parameter: HILInitialize_CKStart
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKEnter;     /* Computed Parameter: HILInitialize_CKEnter
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AIPStart;    /* Computed Parameter: HILInitialize_AIPStart
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AIPEnter;    /* Computed Parameter: HILInitialize_AIPEnter
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOPStart;    /* Computed Parameter: HILInitialize_AOPStart
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOPEnter;    /* Computed Parameter: HILInitialize_AOPEnter
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOStart;     /* Computed Parameter: HILInitialize_AOStart
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOEnter;     /* Computed Parameter: HILInitialize_AOEnter
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOReset;     /* Computed Parameter: HILInitialize_AOReset
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOPStart;    /* Computed Parameter: HILInitialize_DOPStart
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOPEnter;    /* Computed Parameter: HILInitialize_DOPEnter
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOStart;     /* Computed Parameter: HILInitialize_DOStart
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOEnter;     /* Computed Parameter: HILInitialize_DOEnter
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOReset;     /* Computed Parameter: HILInitialize_DOReset
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIPStart;    /* Computed Parameter: HILInitialize_EIPStart
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIPEnter;    /* Computed Parameter: HILInitialize_EIPEnter
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIStart;     /* Computed Parameter: HILInitialize_EIStart
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIEnter;     /* Computed Parameter: HILInitialize_EIEnter
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POPStart;    /* Computed Parameter: HILInitialize_POPStart
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POPEnter;    /* Computed Parameter: HILInitialize_POPEnter
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POStart;     /* Computed Parameter: HILInitialize_POStart
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POEnter;     /* Computed Parameter: HILInitialize_POEnter
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POReset;     /* Computed Parameter: HILInitialize_POReset
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_OOReset;     /* Computed Parameter: HILInitialize_OOReset
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOFinal;     /* Computed Parameter: HILInitialize_DOFinal
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOInitial;   /* Computed Parameter: HILInitialize_DOInitial
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  boolean_T HILReadTimebase_Active;    /* Computed Parameter: HILReadTimebase_Active
                                        * Referenced by: '<S5>/HIL Read Timebase'
                                        */
  boolean_T HILWrite_Active;           /* Computed Parameter: HILWrite_Active
                                        * Referenced by: '<S5>/HIL Write'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ACSI_Aero_Simulink_P__T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][16];
  ODE1_IntgData intgData;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_ACSI_Aero_Simulink_P_I_D_T ACSI_Aero_Simulink_P_I_D_P;

/* Block signals (default storage) */
extern B_ACSI_Aero_Simulink_P_I_D_T ACSI_Aero_Simulink_P_I_D_B;

/* Continuous states (default storage) */
extern X_ACSI_Aero_Simulink_P_I_D_T ACSI_Aero_Simulink_P_I_D_X;

/* Block states (default storage) */
extern DW_ACSI_Aero_Simulink_P_I_D_T ACSI_Aero_Simulink_P_I_D_DW;

/* Model entry point functions */
extern void ACSI_Aero_Simulink_P_I_D_initialize(void);
extern void ACSI_Aero_Simulink_P_I_D_output(void);
extern void ACSI_Aero_Simulink_P_I_D_update(void);
extern void ACSI_Aero_Simulink_P_I_D_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern ACSI_Aero_Simulink_P_I_D_rtModel *ACSI_Aero_Simulink_P_I_D(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_ACSI_Aero_Simulink_P_T *const ACSI_Aero_Simulink_P_I_D_M;

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
 * '<Root>' : 'ACSI_Aero_Simulink_P_I_D'
 * '<S1>'   : 'ACSI_Aero_Simulink_P_I_D/LTI System'
 * '<S2>'   : 'ACSI_Aero_Simulink_P_I_D/LTI System1'
 * '<S3>'   : 'ACSI_Aero_Simulink_P_I_D/PID Controller'
 * '<S4>'   : 'ACSI_Aero_Simulink_P_I_D/PID Controller1'
 * '<S5>'   : 'ACSI_Aero_Simulink_P_I_D/Plant'
 * '<S6>'   : 'ACSI_Aero_Simulink_P_I_D/LTI System/Input Delay'
 * '<S7>'   : 'ACSI_Aero_Simulink_P_I_D/LTI System/Output Delay'
 * '<S8>'   : 'ACSI_Aero_Simulink_P_I_D/LTI System1/Input Delay'
 * '<S9>'   : 'ACSI_Aero_Simulink_P_I_D/LTI System1/Output Delay'
 * '<S10>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Anti-windup'
 * '<S11>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/D Gain'
 * '<S12>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Filter'
 * '<S13>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Filter ICs'
 * '<S14>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/I Gain'
 * '<S15>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Ideal P Gain'
 * '<S16>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Ideal P Gain Fdbk'
 * '<S17>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Integrator'
 * '<S18>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Integrator ICs'
 * '<S19>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/N Copy'
 * '<S20>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/N Gain'
 * '<S21>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/P Copy'
 * '<S22>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Parallel P Gain'
 * '<S23>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Reset Signal'
 * '<S24>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Saturation'
 * '<S25>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Saturation Fdbk'
 * '<S26>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Sum'
 * '<S27>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Sum Fdbk'
 * '<S28>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Tracking Mode'
 * '<S29>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Tracking Mode Sum'
 * '<S30>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/postSat Signal'
 * '<S31>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/preSat Signal'
 * '<S32>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Anti-windup/Back Calculation'
 * '<S33>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Anti-windup/Cont. Clamping Ideal'
 * '<S34>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Anti-windup/Cont. Clamping Parallel'
 * '<S35>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Anti-windup/Disabled'
 * '<S36>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Anti-windup/Disc. Clamping Ideal'
 * '<S37>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S38>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Anti-windup/Passthrough'
 * '<S39>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/D Gain/Disabled'
 * '<S40>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/D Gain/External Parameters'
 * '<S41>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/D Gain/Internal Parameters'
 * '<S42>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Filter/Cont. Filter'
 * '<S43>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Filter/Differentiator'
 * '<S44>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Filter/Disabled'
 * '<S45>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Filter/Disc. Backward Euler Filter'
 * '<S46>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S47>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Filter/Disc. Trapezoidal Filter'
 * '<S48>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Filter ICs/Disabled'
 * '<S49>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Filter ICs/External IC'
 * '<S50>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Filter ICs/Internal IC - Differentiator'
 * '<S51>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S52>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/I Gain/Disabled'
 * '<S53>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/I Gain/External Parameters'
 * '<S54>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/I Gain/Internal Parameters'
 * '<S55>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Ideal P Gain/External Parameters'
 * '<S56>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Ideal P Gain/Internal Parameters'
 * '<S57>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Ideal P Gain/Passthrough'
 * '<S58>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S59>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Ideal P Gain Fdbk/External Parameters'
 * '<S60>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Ideal P Gain Fdbk/Internal Parameters'
 * '<S61>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Ideal P Gain Fdbk/Passthrough'
 * '<S62>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Integrator/Continuous'
 * '<S63>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Integrator/Disabled'
 * '<S64>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Integrator/Discrete'
 * '<S65>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Integrator ICs/Disabled'
 * '<S66>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Integrator ICs/External IC'
 * '<S67>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Integrator ICs/Internal IC'
 * '<S68>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/N Copy/Disabled'
 * '<S69>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S70>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/N Copy/External Parameters'
 * '<S71>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/N Copy/Internal Parameters'
 * '<S72>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/N Gain/Disabled'
 * '<S73>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/N Gain/External Parameters'
 * '<S74>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/N Gain/Internal Parameters'
 * '<S75>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/N Gain/Passthrough'
 * '<S76>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/P Copy/Disabled'
 * '<S77>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/P Copy/External Parameters Ideal'
 * '<S78>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/P Copy/Internal Parameters Ideal'
 * '<S79>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Parallel P Gain/Disabled'
 * '<S80>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Parallel P Gain/External Parameters'
 * '<S81>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S82>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Parallel P Gain/Passthrough'
 * '<S83>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Reset Signal/Disabled'
 * '<S84>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Reset Signal/External Reset'
 * '<S85>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Saturation/Enabled'
 * '<S86>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Saturation/Passthrough'
 * '<S87>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Saturation Fdbk/Disabled'
 * '<S88>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Saturation Fdbk/Enabled'
 * '<S89>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Saturation Fdbk/Passthrough'
 * '<S90>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Sum/Passthrough_I'
 * '<S91>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Sum/Passthrough_P'
 * '<S92>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Sum/Sum_PD'
 * '<S93>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Sum/Sum_PI'
 * '<S94>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Sum/Sum_PID'
 * '<S95>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Sum Fdbk/Disabled'
 * '<S96>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Sum Fdbk/Enabled'
 * '<S97>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Sum Fdbk/Passthrough'
 * '<S98>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Tracking Mode/Disabled'
 * '<S99>'  : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Tracking Mode/Enabled'
 * '<S100>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S101>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S102>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller/postSat Signal/Feedback_Path'
 * '<S103>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller/postSat Signal/Forward_Path'
 * '<S104>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller/preSat Signal/Feedback_Path'
 * '<S105>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller/preSat Signal/Forward_Path'
 * '<S106>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Anti-windup'
 * '<S107>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/D Gain'
 * '<S108>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Filter'
 * '<S109>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Filter ICs'
 * '<S110>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/I Gain'
 * '<S111>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Ideal P Gain'
 * '<S112>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Ideal P Gain Fdbk'
 * '<S113>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Integrator'
 * '<S114>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Integrator ICs'
 * '<S115>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/N Copy'
 * '<S116>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/N Gain'
 * '<S117>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/P Copy'
 * '<S118>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Parallel P Gain'
 * '<S119>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Reset Signal'
 * '<S120>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Saturation'
 * '<S121>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Saturation Fdbk'
 * '<S122>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Sum'
 * '<S123>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Sum Fdbk'
 * '<S124>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Tracking Mode'
 * '<S125>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Tracking Mode Sum'
 * '<S126>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/postSat Signal'
 * '<S127>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/preSat Signal'
 * '<S128>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Anti-windup/Back Calculation'
 * '<S129>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Anti-windup/Cont. Clamping Ideal'
 * '<S130>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Anti-windup/Cont. Clamping Parallel'
 * '<S131>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Anti-windup/Disabled'
 * '<S132>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Anti-windup/Disc. Clamping Ideal'
 * '<S133>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S134>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Anti-windup/Passthrough'
 * '<S135>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/D Gain/Disabled'
 * '<S136>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/D Gain/External Parameters'
 * '<S137>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/D Gain/Internal Parameters'
 * '<S138>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Filter/Cont. Filter'
 * '<S139>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Filter/Differentiator'
 * '<S140>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Filter/Disabled'
 * '<S141>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Filter/Disc. Backward Euler Filter'
 * '<S142>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S143>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Filter/Disc. Trapezoidal Filter'
 * '<S144>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Filter ICs/Disabled'
 * '<S145>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Filter ICs/External IC'
 * '<S146>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Filter ICs/Internal IC - Differentiator'
 * '<S147>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S148>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/I Gain/Disabled'
 * '<S149>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/I Gain/External Parameters'
 * '<S150>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/I Gain/Internal Parameters'
 * '<S151>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Ideal P Gain/External Parameters'
 * '<S152>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Ideal P Gain/Internal Parameters'
 * '<S153>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Ideal P Gain/Passthrough'
 * '<S154>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S155>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Ideal P Gain Fdbk/External Parameters'
 * '<S156>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Ideal P Gain Fdbk/Internal Parameters'
 * '<S157>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Ideal P Gain Fdbk/Passthrough'
 * '<S158>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Integrator/Continuous'
 * '<S159>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Integrator/Disabled'
 * '<S160>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Integrator/Discrete'
 * '<S161>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Integrator ICs/Disabled'
 * '<S162>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Integrator ICs/External IC'
 * '<S163>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Integrator ICs/Internal IC'
 * '<S164>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/N Copy/Disabled'
 * '<S165>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S166>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/N Copy/External Parameters'
 * '<S167>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/N Copy/Internal Parameters'
 * '<S168>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/N Gain/Disabled'
 * '<S169>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/N Gain/External Parameters'
 * '<S170>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/N Gain/Internal Parameters'
 * '<S171>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/N Gain/Passthrough'
 * '<S172>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/P Copy/Disabled'
 * '<S173>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/P Copy/External Parameters Ideal'
 * '<S174>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/P Copy/Internal Parameters Ideal'
 * '<S175>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Parallel P Gain/Disabled'
 * '<S176>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Parallel P Gain/External Parameters'
 * '<S177>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S178>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Parallel P Gain/Passthrough'
 * '<S179>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Reset Signal/Disabled'
 * '<S180>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Reset Signal/External Reset'
 * '<S181>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Saturation/Enabled'
 * '<S182>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Saturation/Passthrough'
 * '<S183>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Saturation Fdbk/Disabled'
 * '<S184>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Saturation Fdbk/Enabled'
 * '<S185>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Saturation Fdbk/Passthrough'
 * '<S186>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Sum/Passthrough_I'
 * '<S187>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Sum/Passthrough_P'
 * '<S188>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Sum/Sum_PD'
 * '<S189>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Sum/Sum_PI'
 * '<S190>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Sum/Sum_PID'
 * '<S191>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Sum Fdbk/Disabled'
 * '<S192>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Sum Fdbk/Enabled'
 * '<S193>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Sum Fdbk/Passthrough'
 * '<S194>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Tracking Mode/Disabled'
 * '<S195>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Tracking Mode/Enabled'
 * '<S196>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S197>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/Tracking Mode Sum/Tracking Mode'
 * '<S198>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/postSat Signal/Feedback_Path'
 * '<S199>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/postSat Signal/Forward_Path'
 * '<S200>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/preSat Signal/Feedback_Path'
 * '<S201>' : 'ACSI_Aero_Simulink_P_I_D/PID Controller1/preSat Signal/Forward_Path'
 * '<S202>' : 'ACSI_Aero_Simulink_P_I_D/Plant/Green'
 * '<S203>' : 'ACSI_Aero_Simulink_P_I_D/Plant/Pitch Bias Removal'
 * '<S204>' : 'ACSI_Aero_Simulink_P_I_D/Plant/Yellow'
 * '<S205>' : 'ACSI_Aero_Simulink_P_I_D/Plant/Pitch Bias Removal/Enabled Moving Average'
 * '<S206>' : 'ACSI_Aero_Simulink_P_I_D/Plant/Pitch Bias Removal/Switch Case Action Subsystem'
 * '<S207>' : 'ACSI_Aero_Simulink_P_I_D/Plant/Pitch Bias Removal/Switch Case Action Subsystem1'
 * '<S208>' : 'ACSI_Aero_Simulink_P_I_D/Plant/Pitch Bias Removal/Switch Case Action Subsystem2'
 * '<S209>' : 'ACSI_Aero_Simulink_P_I_D/Plant/Pitch Bias Removal/Enabled Moving Average/Increment'
 */
#endif                                 /* RTW_HEADER_ACSI_Aero_Simulink_P_I_D_h_ */
