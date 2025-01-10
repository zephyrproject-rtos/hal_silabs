/***************************************************************************//**
 * @file
 * @brief This file contains the type definitions for SIxx3xx chip-specific
 *   aspects of RAIL.
 *******************************************************************************
 * # License
 * <b>Copyright 2024 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

#ifdef  SLI_LIBRARY_BUILD

// This file should not be included when doing SLI_LIBRARY_BUILDs

#else//!SLI_LIBRARY_BUILD

#ifndef __RAIL_CHIP_SPECIFIC_H_
#if !defined(__RAIL_TYPES_H__) && !defined(DOXYGEN_SHOULD_SKIP_THIS)
#warning rail_chip_specific.h should only be included by rail_types.h
#include "rail_types.h" // Force rail_chip_specific.h only within rail_types.h
#else // __RAIL_TYPES_H__
/// Include guard
#define __RAIL_CHIP_SPECIFIC_H_

#include "rail_features.h"
#ifdef RAIL_INTERNAL_BUILD
#include "rail_chip_specific_internal.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if     (defined(DOXYGEN_SHOULD_SKIP_THIS) && !defined(RAIL_ENUM))
//  Copied from rail_types.h to satisfy doxygen build.
/// The RAIL library does not use enumerations because the ARM EABI leaves their
/// size ambiguous, which causes problems if the application is built
/// with different flags than the library. Instead, uint8_t typedefs
/// are used in compiled code for all enumerations. For documentation purposes, this is
/// converted to an actual enumeration since it's much easier to read in Doxygen.
#define RAIL_ENUM(name) enum name
/// This macro is a more generic version of the \ref RAIL_ENUM() macro that
/// allows the size of the type to be overridden instead of forcing the use of
/// a uint8_t. See \ref RAIL_ENUM() for more information.
#define RAIL_ENUM_GENERIC(name, type) enum name
#endif //(defined(DOXYGEN_SHOULD_SKIP_THIS) && !defined(RAIL_ENUM))

/******************************************************************************
 * General Structures
 *****************************************************************************/
/**
 * @addtogroup General_SIXX3XX SIxx3xx
 * @ingroup General
 * @{
 * @brief Types specific to the SIxx3xx for general configuration.
 */

/** Synonym of \ref RAIL_EFR32_HANDLE for Series 3 */
#define RAIL_S3LPW_HANDLE RAIL_EFR32_HANDLE

#ifndef DOXYGEN_SHOULD_SKIP_THIS

/**
 * @def RAIL_SIXG301_STATE_BUFFER_BYTES
 * @brief The SIxG301 series size needed for
 *   \ref RAIL_StateBufferEntry_t::bufferBytes.
 */
#define RAIL_SIXG301_STATE_BUFFER_BYTES 624

#ifndef RAIL_STATE_BUFFER_BYTES
/**
 * @def RAIL_STATE_BUFFER_BYTES
 * @brief The size needed for \ref RAIL_StateBufferEntry_t::bufferBytes
 *   on this platform for this radio. This compile-time size may be slightly
 *   larger than what \ref RAIL_GetStateBufferSize() determines at run-time.
 */
#if (_SILICON_LABS_32B_SERIES_3_CONFIG == 301) || (_SILICON_LABS_32B_SERIES_3_CONFIG == 300)
#define RAIL_STATE_BUFFER_BYTES RAIL_SIXG301_STATE_BUFFER_BYTES
#else
#define RAIL_STATE_BUFFER_BYTES 0 // Sate Doxygen
#error "Unsupported platform!"
#endif
#endif //#ifndef RAIL_STATE_BUFFER_BYTES

#endif//DOXYGEN_SHOULD_SKIP_THIS

#ifndef DOXYGEN_SHOULD_SKIP_THIS

/**
 * @typedef RAIL_TimerTick_t
 * @brief Internal RAIL hardware timer tick that drives the RAIL timebase.
 *   A tick is roughly 0.125 microseconds and it has a full 64-bit range
 *   (i.e, spanning 2^61 microseconds or ~73 millenia).
 *
 * @note \ref RAIL_TimerTicksToUs() can be used to convert the delta between
 *   two \ref RAIL_TimerTick_t values to microseconds.
 */
typedef uint64_t RAIL_TimerTick_t;

/**
 * @typedef RAIL_GetTimerTick_t
 * @brief A function pointer type for reading RAIL internal timer ticks.
 *
 * @param[in] timerTickType A timer tick type to read.
 * @return RAIL timer tick corresponding to the timerTickType.
 */
typedef RAIL_TimerTick_t (*RAIL_GetTimerTick_t)(RAIL_TimerTickType_t timerTickType);

/**
 * Function pointer of type \ref RAIL_GetTimerTick_t to read RAIL internal
 * timer ticks.
 */
extern RAIL_GetTimerTick_t RAIL_GetTimerTick;

/**
 * A global pointer to the memory address of the least significant 32 bits
 * of the \ref RAIL_TimerTick_t internal RAIL hardware timer that drives
 * the RAIL timebase.
 * It's 0.125 microsecond tick range is 2^29 microseconds or ~9 minutes.
 */
extern const volatile uint32_t *RAIL_TimerTick;

/**
 * A global pointer to the memory address of the least significant 32 bits
 * of the \ref RAIL_TimerTick_t internal RAIL hardware timer that captures
 * the latest RX packet reception time.
 * It's 0.125 microsecond tick range is 2^29 microseconds or ~9 minutes.
 *
 * @note This would not include the RX chain delay, so may not exactly
 *   correspond to the \ref RAIL_Time_t packet timestamp available within
 *   \ref RAIL_RxPacketDetails_t::timeReceived which reflects the actual
 *   on-air time that the packet finished.
 */
extern const volatile uint32_t *RAIL_RxPacketTimestamp;

/**
 * Get elapsed time, in microseconds, between two \ref RAIL_TimerTick_t ticks.
 *
 * @param[in] startTick Tick recorded at the start of the operation.
 * @param[in] endTick Tick recorded at the end of the operation.
 * @return The elapsed time, in microseconds, between two timer ticks.
 */
RAIL_Time_t RAIL_TimerTicksToUs(RAIL_TimerTick_t startTick,
                                RAIL_TimerTick_t endTick);

/**
 * Get \ref RAIL_TimerTick_t tick corresponding to a \ref RAIL_Time_t time.
 *
 * @param[in] microseconds Time in microseconds.
 * @return The \ref RAIL_TimerTick_t tick corresponding to the
 *   \ref RAIL_Time_t time.
 */
RAIL_TimerTick_t RAIL_UsToTimerTicks(RAIL_Time_t microseconds);

#endif//DOXYGEN_SHOULD_SKIP_THIS

/** @} */ // end of group General_SIXX3XX

/******************************************************************************
 * Multiprotocol
 *****************************************************************************/
/**
 * @addtogroup Multiprotocol_SIXX3XX SIxx3xx
 * @ingroup Multiprotocol
 * @{
 * @brief SIxx3xx-specific multiprotocol support defines.
 */

/**
 * @def TRANSITION_TIME_US
 * @brief Time it takes to take care of protocol switching.
 */
#define TRANSITION_TIME_US 510

/** @} */ // end of group Multiprotocol_SIXX3XX

/******************************************************************************
 * Calibration
 *****************************************************************************/
/**
 * @addtogroup Calibration_SIXX3XX SIxx3xx
 * @ingroup Calibration
 * @{
 * @brief SIxx3xx-specific Calibrations.
 */

/**
 * @def RAIL_RF_PATHS_2P4GIG
 * @brief Indicates the number of 2.4 GHz RF Paths suppported.
 */
#if (_SILICON_LABS_32B_SERIES_3_CONFIG == 301) || (_SILICON_LABS_32B_SERIES_3_CONFIG == 300)
#define RAIL_RF_PATHS_2P4GIG 1
#else
#define RAIL_RF_PATHS_2P4GIG 0
#endif

/**
 * @def RAIL_RF_PATHS_SUBGIG
 * @brief Indicates the number of Sub-GHz RF Paths supported.
 */
#define RAIL_RF_PATHS_SUBGIG 0

/**
 * @def RAIL_RF_PATHS
 * @brief Indicates the number of RF Paths supported.
 */
#define RAIL_RF_PATHS (RAIL_RF_PATHS_SUBGIG + RAIL_RF_PATHS_2P4GIG)

#if     (RAIL_RF_PATHS > RAIL_MAX_RF_PATHS)
#error "Update rail_types.h RAIL_MAX_RF_PATHS"
#endif

/**
 * @def RADIO_CONFIG_ENABLE_IRCAL_MULTIPLE_RF_PATHS
 * @brief Indicates this version of RAIL supports IR calibration on multiple RF paths
 * Needed for backwards compatibility.
 */
#if RAIL_RF_PATHS > 1
#define RADIO_CONFIG_ENABLE_IRCAL_MULTIPLE_RF_PATHS 1
#else
#ifdef  DOXYGEN_SHOULD_SKIP_THIS // Leave undefined except for doxygen
#define RADIO_CONFIG_ENABLE_IRCAL_MULTIPLE_RF_PATHS 0
#endif //DOXYGEN_SHOULD_SKIP_THIS
#endif //RAIL_RF_PATHS

/**
 * @struct RAIL_ChannelConfigEntryAttr
 * @brief A channel configuration entry attribute structure. Items listed
 *  are designed to be altered and updated during run-time.
 */
struct RAIL_ChannelConfigEntryAttr {
  /** IR calibration attributes specific to each channel configuration entry. */
 #if     RAIL_SUPPORTS_OFDM_PA
  RAIL_IrCalValues_t calValues;
 #else//!RAIL_SUPPORTS_OFDM_PA
  RAIL_RxIrCalValues_t calValues;
 #endif//RAIL_SUPPORTS_OFDM_PA
};

/** @} */ // end of group Calibration_SIXX3XX

/******************************************************************************
 * Transmit
 *****************************************************************************/
/**
 * @addtogroup PA_SIXX3XX SIxx3xx
 * @ingroup PA
 * @{
 * @brief Types specific to the SIxx3xx for dealing with the on-chip PAs.
 */

#if (_SILICON_LABS_32B_SERIES_3_CONFIG == 301) || (_SILICON_LABS_32B_SERIES_3_CONFIG == 300)
/**
 * The maximum valid value for the \ref RAIL_TxPowerLevel_t when in \ref
 * RAIL_TX_POWER_MODE_2P4GIG_HP or \ref RAIL_TX_POWER_MODE_2P4GIG_LP modes.
 */
#define RAIL_TX_POWER_LEVEL_2P4GIG_HP_LP_MAX     (95U)
/**
 * The minimum valid value for the \ref RAIL_TxPowerLevel_t when in \ref
 * RAIL_TX_POWER_MODE_2P4GIG_HP or \ref RAIL_TX_POWER_MODE_2P4GIG_LP modes.
 */
#define RAIL_TX_POWER_LEVEL_2P4GIG_HP_LP_MIN     (0U)
/** Legacy define for High Power (HP) and Low Power (LP) modes. */
#define RAIL_TX_POWER_LEVEL_2P4_LP_MIN        (RAIL_TX_POWER_LEVEL_2P4GIG_HP_LP_MIN)
/** Legacy define for High Power (HP) and Low Power (LP) modes. */
#define RAIL_TX_POWER_LEVEL_2P4_LP_MAX        (RAIL_TX_POWER_LEVEL_2P4GIG_HP_LP_MAX)
/** Legacy define for High Power (HP) and Low Power (LP) modes. */
#define RAIL_TX_POWER_LEVEL_2P4_HP_MIN        (RAIL_TX_POWER_LEVEL_2P4GIG_HP_LP_MIN)
/** Legacy define for High Power (HP) and Low Power (LP) modes. */
#define RAIL_TX_POWER_LEVEL_2P4_HP_MAX        (RAIL_TX_POWER_LEVEL_2P4GIG_HP_LP_MAX)
#else
#error "RAIL_TX_POWER_LEVEL not defined for this device"
#endif

/**
 * The number of PA's on this chip (including Virtual PAs).
 */
#if (_SILICON_LABS_32B_SERIES_3_CONFIG == 301) || (_SILICON_LABS_32B_SERIES_3_CONFIG == 300)
#define RAIL_NUM_PA (2U)
#else
#error "RAIL_NUM_PA undefined for platform"
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// Self-referencing defines minimize compiler complaints when using RAIL_ENUM
// Only those supported per-platform are defined, for use with #ifdef in
// apps or librail code.
#if     RAIL_SUPPORTS_2P4GHZ_BAND
#define RAIL_TX_POWER_MODE_2P4GIG_HP ((RAIL_TxPowerMode_t) RAIL_TX_POWER_MODE_2P4GIG_HP)
#define RAIL_TX_POWER_MODE_2P4_HP ((RAIL_TxPowerMode_t) RAIL_TX_POWER_MODE_2P4_HP)
#define RAIL_TX_POWER_MODE_2P4GIG_LP ((RAIL_TxPowerMode_t) RAIL_TX_POWER_MODE_2P4GIG_LP)
#define RAIL_TX_POWER_MODE_2P4_LP ((RAIL_TxPowerMode_t) RAIL_TX_POWER_MODE_2P4_LP)
#define RAIL_TX_POWER_MODE_2P4GIG_HIGHEST ((RAIL_TxPowerMode_t) RAIL_TX_POWER_MODE_2P4GIG_HIGHEST)
#define RAIL_TX_POWER_MODE_2P4_HIGHEST ((RAIL_TxPowerMode_t) RAIL_TX_POWER_MODE_2P4_HIGHEST)
#endif//RAIL_SUPPORTS_2P4GHZ_BAND
#endif//DOXYGEN_SHOULD_SKIP_THIS

/** Convenience macro for any mapping table mode. */
#define RAIL_POWER_MODE_IS_ANY_DBM_POWERSETTING_MAPPING_TABLE(x) \
  (((x) == RAIL_TX_POWER_MODE_2P4GIG_HP)                         \
   || ((x) == RAIL_TX_POWER_MODE_2P4GIG_LP))

/** Convenience macro to check if the power mode supports raw setting. */
#define RAIL_POWER_MODE_SUPPORTS_RAW_SETTING(x) \
  (((x) == RAIL_TX_POWER_MODE_2P4GIG_HP) || ((x) == RAIL_TX_POWER_MODE_2P4GIG_LP))

/** @} */ // end of group PA_SIXX3XX

/******************************************************************************
 * RX Channel Hopping
 *****************************************************************************/
/**
 * @addtogroup Rx_Channel_Hopping_SIXX3XX SIxx3xx
 * @ingroup Rx_Channel_Hopping
 * @{
 * @brief SIxx3xx-specific RX channel hopping.
 */

/// The static amount of memory needed per channel for channel hopping, measured
/// in 32 bit words, regardless of the size of radio configuration structures.
#define RAIL_CHANNEL_HOPPING_BUFFER_SIZE_PER_CHANNEL (54U)

#if     (RAIL_CHANNEL_HOPPING_BUFFER_SIZE_PER_CHANNEL \
         > RAIL_CHANNEL_HOPPING_BUFFER_SIZE_PER_CHANNEL_WORST_CASE)
#error "Update rail_types.h RAIL_CHANNEL_HOPPING_BUFFER_SIZE_PER_CHANNEL_WORST_CASE"
#endif

/** @} */  // end of group Rx_Channel_Hopping_SIXX3XX

/******************************************************************************
 * Sleep Structures
 *****************************************************************************/
/**
 * @addtogroup Sleep_SIXX3XX SIxx3xx
 * @ingroup Sleep
 * @{
 * @brief SIxx3xx-specific Sleeping.
 */

/// Default PRS channel to use when configuring sleep
#define RAIL_TIMER_SYNC_PRS_CHANNEL_DEFAULT  (7U)

/// Default RTCC channel to use when configuring sleep
#define RAIL_TIMER_SYNC_RTCC_CHANNEL_DEFAULT (0U)

/** @} */ // end of group Sleep_SIXX3XX

/******************************************************************************
 * State Transitions
 *****************************************************************************/
/**
 * @addtogroup State_Transitions_SIXX3XX SIxx3xx
 * @ingroup State_Transitions
 * @{
 * @brief SIxx3xx-specific State Transitions.
 */

/**
 * @def RAIL_MINIMUM_TRANSITION_US
 * @brief The minimum value for a consistent RAIL transition
 * @note Transitions may need to be slower than this when using longer
 *   \ref RAIL_TxPowerConfig_t::rampTime values
 */
#define RAIL_MINIMUM_TRANSITION_US (100U)

/**
 * @def RAIL_MAXIMUM_TRANSITION_US
 * @brief The maximum value for a consistent RAIL transition
 */
#define RAIL_MAXIMUM_TRANSITION_US (1000000U)

/**
 * @enum RAIL_RadioStateSix3x_t
 * @brief Detailed Series 3 Radio state machine states.
 */
RAIL_ENUM(RAIL_RadioStateSix3x_t) {
  /** Radio is off. */
  RAIL_RAC_STATE_SIX3X_OFF = 0,
  /** Radio is enabling the receiver. */
  RAIL_RAC_STATE_SIX3X_RXWARM = 1,
  /** Radio is listening for incoming frames. */
  RAIL_RAC_STATE_SIX3X_RXSEARCH = 2,
  /** Radio is receiving a frame. */
  RAIL_RAC_STATE_SIX3X_RXFRAME = 3,
  /** Radio is wrapping up after receiving a frame. */
  RAIL_RAC_STATE_SIX3X_RXWRAPUP = 4,
  /** Radio is enabling transmitter. */
  RAIL_RAC_STATE_SIX3X_TXWARM = 5,
  /** Radio is transmitting data. */
  RAIL_RAC_STATE_SIX3X_TX = 6,
  /** Radio is wrapping up after transmitting a frame. */
  RAIL_RAC_STATE_SIX3X_TXWRAPUP = 7,
  /** Radio is powering down and going to OFF state. */
  RAIL_RAC_STATE_SIX3X_SHUTDOWN = 8,
  /** Radio power-on-reset state. */
  RAIL_RAC_STATE_SIX3X_POR = 9,
  /** Invalid Radio state, must be the last entry. */
  RAIL_RAC_STATE_SIX3X_NONE
};

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// Self-referencing defines minimize compiler complaints when using RAIL_ENUM
#define RAIL_RAC_STATE_SIX3X_OFF         ((RAIL_RadioStateSix3x_t) RAIL_RAC_STATE_SIX3X_OFF)
#define RAIL_RAC_STATE_SIX3X_RXWARM      ((RAIL_RadioStateSix3x_t) RAIL_RAC_STATE_SIX3X_RXWARM)
#define RAIL_RAC_STATE_SIX3X_RXSEARCH    ((RAIL_RadioStateSix3x_t) RAIL_RAC_STATE_SIX3X_RXSEARCH)
#define RAIL_RAC_STATE_SIX3X_RXFRAME     ((RAIL_RadioStateSix3x_t) RAIL_RAC_STATE_SIX3X_RXFRAME)
#define RAIL_RAC_STATE_SIX3X_RXWRAPUP    ((RAIL_RadioStateSix3x_t) RAIL_RAC_STATE_SIX3X_RXWRAPUP)
#define RAIL_RAC_STATE_SIX3X_TXWARM      ((RAIL_RadioStateSix3x_t) RAIL_RAC_STATE_SIX3X_TXWARM)
#define RAIL_RAC_STATE_SIX3X_TX          ((RAIL_RadioStateSix3x_t) RAIL_RAC_STATE_SIX3X_TX)
#define RAIL_RAC_STATE_SIX3X_TXWRAPUP    ((RAIL_RadioStateSix3x_t) RAIL_RAC_STATE_SIX3X_TXWRAPUP)
#define RAIL_RAC_STATE_SIX3X_SHUTDOWN    ((RAIL_RadioStateSix3x_t) RAIL_RAC_STATE_SIX3X_SHUTDOWN)
#define RAIL_RAC_STATE_SIX3X_POR         ((RAIL_RadioStateSix3x_t) RAIL_RAC_STATE_SIX3X_POR)
#define RAIL_RAC_STATE_SIX3X_NONE        ((RAIL_RadioStateSix3x_t) RAIL_RAC_STATE_SIX3X_NONE)
/**
 * Redefined to use \ref RAIL_RadioStateSix3x_t instead of \ref RAIL_RadioStateEfr32_t.
 */
#ifdef  RAIL_RAC_STATE_NONE
#undef  RAIL_RAC_STATE_NONE
#define RAIL_RAC_STATE_NONE RAIL_RAC_STATE_SIX3X_NONE
#endif
#endif//DOXYGEN_SHOULD_SKIP_THIS

/**
 * Internal Radio State type mapping for SIxx3xx chips.
 */
typedef RAIL_RadioStateSix3x_t RAIL_RacRadioState_t;

/** @} */ // end of group State_Transitions_SIXX3XX

#ifndef DOXYGEN_SHOULD_SKIP_THIS

/******************************************************************************
 * Sequencer User Structures
 *****************************************************************************/
/**
 * @addtogroup Sequencer_User_SIXX3XX Sequencer User
 * @ingroup RAIL_API
 * @{
 * @brief Types specific to the SIxx3xx for dealing with the Sequencer User.
 */

/**
 * TODO: Document and cleanup.
 */
typedef struct RAIL_UserCommonGlobal {
  void *pLocSeqVirtualReg;
  void *pLocSeqTiming;
  void *pLocUserSeqConfig;
  void *pLocRtccsyncConfig;
  void *pLocStateVarConfig;
  void *pLocGenericPhyConfig;
  void *pLocpSeqTimestamp;
  void *pLocpSeqMisc;
  void *pLocpNewFeatureConfig;
} RAIL_UserCommonGlobal_t;

/**
 * TODO: Document and cleanup.
 */
typedef struct UserSeqShMem {
  /**
   * pointer to the start of M33 and sequencer shared memory.
   * TBD: This part of memory should be moved to user memory instead of in generic_seq_common.h
   */
  void *pStart;
  /**
   * size of shared memory in bytes.
   * TBD: This part of memory should be moved to user memory instead of in generic_seq_common.h
   */
  uint32_t szBytes;
} UserSeqShMem_t;

/**
 * TODO: Document and cleanup.
 */
typedef void (*RAIL_SEQ_UserStartMain_t)(void);

/**
 * @struct RAIL_SeqUserAppInfo_t
 * @brief RAIL sequencer user application structure.
 *
 * This structure describes the user application that is loaded on the sequencer.
 */
// TBD: Is this the right place for this structure?  This should probably stays internal?????
typedef struct {
  /// Version of the structure? do we need this? how would this work?
  uint32_t version;
  /// Pointer to the start of user executable in memory.
  uint8_t *pProgramStartMem;
  /// Pointer to the start of user executable storage.
  uint8_t *pProgramStartLoc;
  /// Size of user executable in bytes.
  uint32_t programSzB;
  /// Main user function entry.
  RAIL_SEQ_UserStartMain_t programInitStart;
  /// Pointer to the start of user initialized data in memory.
  uint8_t *pDataStartMem;
  /// Pointer to the start of user initialized data storage.
  uint8_t *pDataStartLoc;
  /// Size of user initialized data in bytes.
  uint32_t dataSzB;
  /// Pointer to the start of user un-initialized data in memory.
  uint8_t *pScratchStartMem;
  /// Size of user un-initialized data in bytes.
  uint32_t scratchSzB;
} RAIL_SeqUserAppInfo_t;

/**
 * @typedef RAIL_UserCpReqCb_t
 * @brief Callback function type used to indicate status of user copy request.
 *
 * @param[in] pCpReq A non-NULL pointer to the user copy request.
 * @param[in] reqStatus The status of the request.
 */
typedef void(*RAIL_UserCpReqCb_t)(const void *pCpReq,
                                  RAIL_Status_t reqStatus);

//FIXME: these are not RAIL_Status_t values, and need doxygen
#define RAIL_USER_CP_REQ_STATUS_FLAG_STARTED           1U
#define RAIL_USER_CP_REQ_STATUS_FLAG_COMPLETED         2U
#define RAIL_USER_CP_REQ_STATUS_FLAG_REQ_HOST          4U
#define RAIL_USER_CP_REQ_STATUS_FLAG_INVALID_PARAMETER 8U

/**
 * @struct RAIL_UserCpReq_t
 * @brief Memory copy request configuration structure.
 *
 * This structure describes the user request to copy contents from one memory area to another.
 */
typedef struct RAIL_UserCpReq {
  // Pointer to the next request; NULL if none.
  struct RAIL_UserCpReq *pNext;
  // Non-NULL pointer to the location to copy from.
  const uint8_t *pSrc;
  // Non-NULL pointer to the location to copy to.
  uint8_t *pDst;
  // The number of bytes to copy.
  uint16_t xferSzBytes;
  // Status of the request.
  volatile uint8_t statusFlag;
  // Reserved.
  volatile uint8_t reserved;
  // A pointer to the callback called on completion or error. May be NULL.
  RAIL_UserCpReqCb_t pCpReqCB;
} RAIL_UserCpReq_t;

/**
 * Load sequencer user application to memory.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in] pSeqUserApp A pointer to the structure describing the user
 *   sequencer application metadata.
 * @return Status code indicating success of the function call.
 *
 * Attempts to load sequencer user application to the sequencer memory and
 * execute its initialization function.
 */
RAIL_Status_t RAIL_LoadUserSeqApp(RAIL_Handle_t railHandle,
                                  const RAIL_SeqUserAppInfo_t *pSeqUserApp);

/**
 * Send a shutdown message to the sequencer user application.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @return Status code indicating success of the function call.
 */
RAIL_Status_t RAIL_ShutdownUserSeqApp(RAIL_Handle_t railHandle);

/**
 * Indicate whether this chip supports Sequencer User.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @return true if Sequencer User is supported; false otherwise.
 */
bool RAIL_SupportsUserSequencer(RAIL_Handle_t railHandle);

/**
 * Get the sequencer user common global variables.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[out] pCommonGlobal A non-NULL pointer to store the common global variables.
 * @return Status code indicating success of the function call.
 */
RAIL_Status_t RAIL_USER_printCommonGlobal(RAIL_Handle_t railHandle,
                                          RAIL_UserCommonGlobal_t *pCommonGlobal);

/**
 * Get sequencer user mailbox message.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[out] pMsg A non-NULL pointer to the message filled in by the call.
 * @return Status code indicating success of the function call.
 */
RAIL_Status_t RAIL_USER_GetMboxMsg(RAIL_Handle_t railHandle,
                                   uint32_t *pMsg);

/**
 * Send user mailbox message to the sequencer.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in] msg A message to send.
 * @return Status code indicating success of the function call.
 */
RAIL_Status_t RAIL_USER_SendMbox(RAIL_Handle_t railHandle,
                                 uint32_t msg);

/**
 * Initialize internal RAIL state used to run a user application on
 * the sequencer.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @return Status code indicating success of the function call.
 */
RAIL_Status_t RAIL_USER_startSeqCtrl(RAIL_Handle_t railHandle);

/**
 * Initialize a semaphore.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in,out] pSemaphore A non-NULL pointer to a 32-bit aligned
 *   semaphore location updated to become an unacquired semaphore.
 * @return Status code indicating success of the function call.
 *
 * @note This must be called from the hsot for each semaphore's memory location.
 */
RAIL_Status_t RAIL_USER_InitSemaphore(RAIL_Handle_t railHandle,
                                      uint32_t *pSemaphore);

/**
 * Acquire a semaphore lock.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in,out] pSemaphore A non-NULL pointer to the semaphore location
 *   which will be updated if the lock was acquired.
 * @return Status code indicating success of the function call:
 *   \ref RAIL_STATUS_NO_ERROR if lock was acquired;
 *   \ref RAIL_STATUS_INVALID_PARAMETER if the lock is corrupted (the lock need to be initialized with \ref RAIL_USER_InitSemaphore());
 *   \ref RAIL_STATUS_INVALID_CALL if the lock has been acquired by another processor;
 *   \ref RAIL_STATUS_INVALID_STATE if the lock has been acquired before by the current processor;
 *   \ref RAIL_STATUS_SUSPENDED if the lock has been changed recently, user can try to acuire it again
 *
 * This function attempts to acquire (lock) a semaphore that was previously
 * initialized by \ref RAIL_USER_InitSemaphore().
 */
RAIL_Status_t RAIL_USER_TryLockSemaphore(RAIL_Handle_t railHandle,
                                         uint32_t *pSemaphore);

/**
 * Release a semaphore.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in,out] pSemaphore A non-NULL pointer to the semaphore location
 *   which will be updated if the semaphore was released.
 * @return Status code indicating success of the function call.
 *
 * This function releases a semaphore that was previously initialized by
 * \ref RAIL_USER_InitSemaphore() and acquired by \ref RAIL_USER_TryLockSemaphore().
 */
RAIL_Status_t RAIL_USER_ReleaseSemaphore(RAIL_Handle_t railHandle,
                                         uint32_t *pSemaphore);

/**
 * Initilize which DMA to use to copy user data.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in] dmaChannel The DMA channel to use.
 * @return Status code indicating success of the function call.
 */
RAIL_Status_t RAIL_USER_InitCp(RAIL_Handle_t railHandle,
                               uint32_t dmaChannel);

/**
 * Start a request to copy user data.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in,out] pCpReqHead A non-NULL pointer to the start of a chain of user copy request configurations.
 * @param[in,out] pCpReqTail A non-NULL pointer to the last configuration in the chain.
 * @return Status code indicating success of the function call.
 *
 * This function will initiate copy operations for each element in the linked
 * list chain between pCpReqHead and pCpReqTail, inclusive.  The \ref
 * RAIL_UserCpReq_t::statusFlag of each element in the chain will be
 * updated as the operation progresses to completion or failure.
 *
 * @note Before using this function, \ref RAIL_USER_InitCp() must be
 *   called once from the host.
 */
RAIL_Status_t RAIL_USER_StartCpReq(RAIL_Handle_t railHandle,
                                   RAIL_UserCpReq_t *pCpReqHead,
                                   RAIL_UserCpReq_t *pCpReqTail);

/** @} */ // end of group Sequencer_User_SIXX3XX

#endif//DOXYGEN_SHOULD_SKIP_THIS

#ifdef __cplusplus
}
#endif

#endif //__RAIL_TYPES_H__

#endif //__RAIL_CHIP_SPECIFIC_H_

#endif //SLI_LIBRARY_BUILD
