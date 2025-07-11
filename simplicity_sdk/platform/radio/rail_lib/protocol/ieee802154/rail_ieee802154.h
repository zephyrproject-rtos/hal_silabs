/***************************************************************************//**
 * @file
 * @brief The IEEE 802.15.4 specific header file for the RAIL library.
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef __RAIL_IEEE802154_H__
#define __RAIL_IEEE802154_H__

#include "rail_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// @addtogroup IEEE802_15_4 IEEE 802.15.4
/// @ingroup Protocol_Specific
/// @brief IEEE 802.15.4 configuration routines
///
/// The functions in this group configure RAIL IEEE 802.15.4 hardware
/// acceleration which includes IEEE 802.15.4 format filtering, address
/// filtering, Acking, and filtering based on the frame type.
///
/// To configure IEEE 802.15.4 functionality, the application must first set up
/// a RAIL instance with \ref RAIL_Init() and other setup functions.
/// Instead of \ref RAIL_ConfigChannels(), however, an
/// application may use \ref RAIL_IEEE802154_Config2p4GHzRadio() to set up the
/// official IEEE 2.4 GHz 802.15.4 PHY. This configuration is shown below.
///
/// 802.15.4 defines its macAckWaitDuration from the end of the transmitted
/// packet to complete reception of the Ack. RAIL's ackTimeout only covers
/// sync word detection of the Ack. Therefore, subtract the Ack's
/// PHY header and payload time to get RAIL's ackTimeout setting.
/// For 2.4 GHz OQPSK, macAckWaitDuration is specified as 54 symbols;
/// subtracting 2-symbol PHY header and 10-symbol payload yields a RAIL
/// ackTimeout of 42 symbols or 672 microseconds at 16 microseconds/symbol.
/// @code{.c}
/// static RAIL_Handle_t railHandle = NULL; // Initialized somewhere else.
///
/// static const RAIL_IEEE802154_Config_t rail154Config = {
///   .addresses = NULL,
///   .ackConfig = {
///     .enable = true,     // Turn on auto Ack for IEEE 802.15.4.
///     .ackTimeout = 672,  // See note above: 54-12 sym * 16 us/sym = 672 us.
///     .rxTransitions = {
///       .success = RAIL_RF_STATE_RX,  // Return to RX after Ack processing
///       .error = RAIL_RF_STATE_RX,    // Ignored
///     },
///     .txTransitions = {
///       .success = RAIL_RF_STATE_RX,  // Return to RX after Ack processing
///       .error = RAIL_RF_STATE_RX,    // Ignored
///     },
///   },
///   .timings = {
///     .idleToRx = 100,
///     .idleToTx = 100,
///     .rxToTx = 192,    // 12 symbols * 16 us/symbol = 192 us
///     .txToRx = 192,    // 12 symbols * 16 us/symbol = 192 us
///     .rxSearchTimeout = 0, // Not used
///     .txToRxSearchTimeout = 0, // Not used
///   },
///   .framesMask = RAIL_IEEE802154_ACCEPT_STANDARD_FRAMES,
///   .promiscuousMode = false,  // Enable format and address filtering.
///   .isPanCoordinator = false,
///   .defaultFramePendingInOutgoingAcks = false,
/// };
///
/// void config154(void)
/// {
///   // Configure the radio and channels for 2.4 GHz IEEE 802.15.4.
///   RAIL_IEEE802154_Config2p4GHzRadio(railHandle);
///   // Initialize the IEEE 802.15.4 configuration using the static configuration above.
///   RAIL_IEEE802154_Init(railHandle, &rail154Config);
/// }
/// @endcode
///
/// To configure address filtering, call \ref
/// RAIL_IEEE802154_SetAddresses() with a structure containing all addresses or
/// call the individual \ref RAIL_IEEE802154_SetPanId(), \ref
/// RAIL_IEEE802154_SetShortAddress(), and \ref RAIL_IEEE802154_SetLongAddress()
/// APIs. RAIL supports \ref RAIL_IEEE802154_MAX_ADDRESSES number of address
/// pairs to receive packets from multiple IEEE
/// 802.15.4 networks at the same time. Broadcast addresses are supported by
/// default without any additional configuration so they do not consume one of
/// these slots. If the application does not require all address pairs, be sure
/// to set unused ones to the proper disabled value for each type. These can
/// be found in the \ref RAIL_IEEE802154_AddrConfig_t documentation. Below is
/// an example of setting filtering for one set of addresses.
/// @code{.c}
/// // PAN Id over-the-air value of 0x34 0x12.
/// // Short Address over-the-air byte order of 0x78 0x56.
/// // Long address with over-the-air byte order of 0x11 0x22 0x33 0x44 0x55 0x66 0x77 0x88.
///
/// // Set up all addresses simultaneously.
/// RAIL_Status_t setup1(void)
/// {
///   RAIL_IEEE802154_AddrConfig_t nodeAddress = {
///     { 0x1234, 0xFFFF, 0xFFFF },
///     { 0x5678, 0xFFFF, 0xFFFF },
///     { { 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88 },
///       { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
///       { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } }
///   };
///   return RAIL_IEEE802154_SetAddresses(railHandle, &nodeAddress);
/// }
///
/// // Alternatively, the addresses can be set up individually as follows:
/// void setup2(void)
/// {
///   RAIL_Status_t status;
///   const uint8_t longAddress[] = { 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88 };
///
///   status = RAIL_IEEE802154_SetPanId(railHandle, 0x1234, 0);
///   assert(status == RAIL_STATUS_NO_ERROR);
///   status = RAIL_IEEE802154_SetShortAddress(railHandle, 0x5678, 0);
///   assert(status == RAIL_STATUS_NO_ERROR);
///   status = RAIL_IEEE802154_SetLongAddress(railHandle, longAddress, 0);
///   assert(status == RAIL_STATUS_NO_ERROR);
/// }
/// @endcode
///
/// Address filtering will be enabled except when in promiscuous mode, which can
/// be set with \ref RAIL_IEEE802154_SetPromiscuousMode(). The addresses may be
/// changed at runtime. However, if you are receiving a packet while
/// reconfiguring the address filters, you may get undesired behavior so it's
/// safest to do this while not in receive.
///
/// Auto Ack is controlled by the \ref RAIL_IEEE802154_Config_t::ackConfig
/// and \ref RAIL_IEEE802154_Config_t::timings fields passed to \ref
/// RAIL_IEEE802154_Init(). After initialization, they may be controlled
/// using the normal \ref Auto_Ack and \ref State_Transitions APIs. When in IEEE
/// 802.15.4 mode, the Ack will generally have a 5 byte length, its Frame Type
/// will be Ack, its Frame Version 0 (2003), and its Frame Pending bit will be
/// false unless the \ref RAIL_EVENT_IEEE802154_DATA_REQUEST_COMMAND event is
/// triggered in which case it will default to the
/// \ref RAIL_IEEE802154_Config_t::defaultFramePendingInOutgoingAcks setting.
/// If the default Frame Pending setting is incorrect,
/// the app must call \ref RAIL_IEEE802154_ToggleFramePending()
/// (formerly \ref RAIL_IEEE802154_SetFramePending()) while handling the
/// \ref RAIL_EVENT_IEEE802154_DATA_REQUEST_COMMAND event.
///
/// This event must be turned on by the user and will fire whenever a data
/// request is being received so that the stack can determine if there
/// is pending data. Note that if the default Frame Pending bit needs to
/// be changed, it must be done quickly. Otherwise, the Ack may already
/// have been transmitted with the default setting. Check the return code of \ref
/// RAIL_IEEE802154_ToggleFramePending() to be sure that the bit was changed
/// in time.
///
/// Transmit and receive operations are done using the standard RAIL APIs in
/// IEEE 802.15.4 mode. To send packets using the correct CSMA configuration,
/// use \ref RAIL_CSMA_CONFIG_802_15_4_2003_2p4_GHz_OQPSK_CSMA define
/// that can initialize the csmaConfig structure passed to \ref
/// RAIL_StartCcaCsmaTx().
/// @{

/**
 * @enum RAIL_IEEE802154_AddressLength_t
 * @brief Different lengths that an 802.15.4 address can have
 */
RAIL_ENUM(RAIL_IEEE802154_AddressLength_t) {
  /** 2 byte short address. */
  RAIL_IEEE802154_ShortAddress = 2,
  /** 8 byte extended address. */
  RAIL_IEEE802154_LongAddress = 3,
};

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// Self-referencing defines minimize compiler complaints when using RAIL_ENUM
#define RAIL_IEEE802154_ShortAddress ((RAIL_IEEE802154_AddressLength_t) RAIL_IEEE802154_ShortAddress)
#define RAIL_IEEE802154_LongAddress  ((RAIL_IEEE802154_AddressLength_t) RAIL_IEEE802154_LongAddress)
#endif//DOXYGEN_SHOULD_SKIP_THIS

/**
 * @struct RAIL_IEEE802154_Address_t
 * @brief Representation of 802.15.4 address
 *
 * This structure is only used for received source address information
 * needed to perform Frame Pending lookup.
 */
typedef struct RAIL_IEEE802154_Address {
  /** Convenient storage for different address types. */
  union {
    /** Present for 2 byte addresses. */
    uint16_t shortAddress;
    /** Present for 8 byte addresses. */
    uint8_t longAddress[8];
  };
  /**
   * Enumeration of the received address length.
   */
  RAIL_IEEE802154_AddressLength_t length;
  /**
   * A bitmask representing which address filter(s) this packet has passed.
   * It is undefined on platforms lacking \ref RAIL_SUPPORTS_ADDR_FILTER_MASK.
   */
  RAIL_AddrFilterMask_t filterMask;
} RAIL_IEEE802154_Address_t;

/** The maximum number of allowed addresses of each type. */
#define RAIL_IEEE802154_MAX_ADDRESSES (3U)

/**
 * @struct RAIL_IEEE802154_AddrConfig_t
 * @brief A configuration structure for IEEE 802.15.4 Address Filtering.
 *
 * This structure allows configuration of multi-PAN functionality by specifying
 * multiple PAN Ids and short addresses. A packet will be received if it matches
 * an address and its corresponding PAN Id. Long address 0 and short address 0
 * match against PAN Id 0, etc. The broadcast PAN Id and address will work with
 * any address or PAN Id, respectively.
 *
 * @note The broadcast addresses are handled separately and do not need to be
 *   specified here. Any address to be ignored should be set with all bits high.
 */
typedef struct RAIL_IEEE802154_AddrConfig {
  /**
   * PAN Ids for destination filtering. All must be specified.
   * To disable a PAN Id, set it to the broadcast value, 0xFFFF.
   */
  uint16_t panId[RAIL_IEEE802154_MAX_ADDRESSES];
  /**
   * A short network addresses for destination filtering. All must be specified.
   * To disable a short address, set it to the broadcast value, 0xFFFF.
   */
  uint16_t shortAddr[RAIL_IEEE802154_MAX_ADDRESSES];
  /**
   * A 64-bit address for destination filtering. All must be specified.
   * This field is parsed in over-the-air byte order. To disable a long
   * address, set it to the reserved value of 0x00 00 00 00 00 00 00 00.
   */
  uint8_t longAddr[RAIL_IEEE802154_MAX_ADDRESSES][8];
} RAIL_IEEE802154_AddrConfig_t;

/**
 * @struct RAIL_IEEE802154_Config_t
 * @brief A configuration structure for IEEE 802.15.4 in RAIL.
 */
typedef struct RAIL_IEEE802154_Config {
  /**
   * Configure the RAIL Address Filter to allow the given destination
   * addresses. If this pointer is NULL, defer destination address configuration.
   * If a member of addresses is NULL, defer configuration of just that member.
   * This can be overridden via \ref RAIL_IEEE802154_SetAddresses(), or the
   * individual members can be changed via \ref RAIL_IEEE802154_SetPanId(), \ref
   * RAIL_IEEE802154_SetShortAddress(), and \ref RAIL_IEEE802154_SetLongAddress().
   */
  const RAIL_IEEE802154_AddrConfig_t *addresses;
  /**
   * Define the Acking configuration for the IEEE 802.15.4 implementation.
   */
  RAIL_AutoAckConfig_t ackConfig;
  /**
   * Define state timings for the IEEE 802.15.4 implementation.
   */
  RAIL_StateTiming_t timings;
  /**
   * Set which 802.15.4 frame types will be received, of Beacon, Data, Ack, and
   * Command. This setting can be overridden via \ref RAIL_IEEE802154_AcceptFrames().
   */
  uint8_t framesMask;
  /**
   * Enable promiscuous mode during configuration. This can be overridden via
   * \ref RAIL_IEEE802154_SetPromiscuousMode() afterwards.
   */
  bool promiscuousMode;
  /**
   * Set whether the device is a PAN Coordinator during configuration. This can
   * be overridden via \ref RAIL_IEEE802154_SetPanCoordinator() afterwards.
   */
  bool isPanCoordinator;
  /**
   * The default value for the Frame Pending bit in outgoing Acks for packets
   * that triggered the \ref RAIL_EVENT_IEEE802154_DATA_REQUEST_COMMAND event.
   * Such an Ack's Frame Pending bit can be inverted if necessary during the
   * handling of that event by calling \ref RAIL_IEEE802154_ToggleFramePending()
   * (formerly \ref RAIL_IEEE802154_SetFramePending()).
   */
  bool defaultFramePendingInOutgoingAcks;
} RAIL_IEEE802154_Config_t;

/** RX channel switching buffer size, in bytes. */
#ifdef  SLI_LIBRARY_BUILD
#define RAIL_IEEE802154_RX_CHANNEL_SWITCHING_BUF_BYTES (704U) // largest of below
#else//!SLI_LIBRARY_BUILD
#if     (_SILICON_LABS_32B_SERIES_2_CONFIG == 1)
#define RAIL_IEEE802154_RX_CHANNEL_SWITCHING_BUF_BYTES (704U)
#elif   ((_SILICON_LABS_32B_SERIES_2_CONFIG == 4) || (_SILICON_LABS_32B_SERIES_2_CONFIG == 6))
#define RAIL_IEEE802154_RX_CHANNEL_SWITCHING_BUF_BYTES (640U)
#else// RX channel switching not supported and series 3 do not use this parameter
#define RAIL_IEEE802154_RX_CHANNEL_SWITCHING_BUF_BYTES (0U)
#endif
#endif//SLI_LIBRARY_BUILD

/** Fixed-width type indicating the needed alignment for RX channel switching buffer. */
#define RAIL_IEEE802154_RX_CHANNEL_SWITCHING_BUF_ALIGNMENT_TYPE     uint32_t

/** Alignment that is needed for RX channel switching buffer. */
#define RAIL_IEEE802154_RX_CHANNEL_SWITCHING_BUF_ALIGNMENT          (sizeof(RAIL_IEEE802154_RX_CHANNEL_SWITCHING_BUF_ALIGNMENT_TYPE))

/** Maximum numbers of channels supported for RX channel switching */
#define RAIL_IEEE802154_RX_CHANNEL_SWITCHING_NUM_CHANNELS           (2U)

/**
 * @struct RAIL_IEEE802154_RxChannelSwitchingCfg_t
 * @brief A configuration structure for RX channel switching.
 */
typedef struct RAIL_IEEE802154_RxChannelSwitchingCfg {
  /**
   * Pointer to contiguous global read-write memory that will be used
   * by RAIL to store channel specific settings for concurrent listening,
   * for series 2 parts.
   * It need not be initialized and applications should never write
   * data anywhere in this buffer.
   * This parameter is not used for series 3 parts.
   *
   * @note the size of this buffer must be at least as large as the
   *   \ref RAIL_IEEE802154_RX_CHANNEL_SWITCHING_BUF_BYTES and needs to be word
   *   aligned.
   */
  RAIL_IEEE802154_RX_CHANNEL_SWITCHING_BUF_ALIGNMENT_TYPE *buffer;
  /**
   * For series 2 parts, this parameter must be set to the length of the buffer
   * array, in bytes. This way, during configuration, the software can confirm
   * it's writing within the range of the buffer.
   * The configuration API will return an error if bufferBytes is insufficient.
   * This parameter is not used for series 3 parts.
   */
  uint16_t bufferBytes;
  /**
   * Array to hold the channel numbers for RX channel switching.
   * @note Radio will switch between the exact channels specified, and not
   *   across an inclusive range of channels between the specified channels.
   */
  uint16_t channels[RAIL_IEEE802154_RX_CHANNEL_SWITCHING_NUM_CHANNELS];
} RAIL_IEEE802154_RxChannelSwitchingCfg_t;

/// @addtogroup IEEE802154_PHY IEEE 802.15.4 Radio Configurations
/// Radio configurations for the RAIL 802.15.4 Accelerator
///
/// These radio configurations are used to configure 802.15.4 when a function
/// such as \ref RAIL_IEEE802154_Config2p4GHzRadio() is called. Each radio
/// configuration listed below is compiled into the RAIL library as a weak
/// symbol that will take into account per-die defaults. If the board
/// configuration in use has different settings than the default, such as a
/// different radio subsystem clock frequency, these radio configurations can
/// be overridden to account for those settings.
/// @{

/**
 * Default PHY to use for 2.4 GHz 802.15.4. Will be NULL if
 * \ref RAIL_SUPPORTS_PROTOCOL_IEEE802154 or \ref RAIL_SUPPORTS_2P4GHZ_BAND
 * is 0.
 */
extern const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHz;

#ifndef DOXYGEN_UNDOCUMENTED
/**
 * Default PHY to use for 1 Mbps 2.4 GHz 802.15.4 with forward error correction.
 * Will be NULL if \ref RAIL_IEEE802154_SUPPORTS_2MBPS_PHY is 0.
 */
extern const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHz1MbpsFec;

/**
 * Default PHY to use for 2 Mbps 2.4 GHz 802.15.4. Will be NULL if
 * \ref RAIL_IEEE802154_SUPPORTS_2MBPS_PHY is 0.
 */
extern const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHz2Mbps;
#endif //DOXYGEN_UNDOCUMENTED

/**
 * Default PHY to use for 2.4 GHz 802.15.4 with antenna diversity. Will be NULL
 * if \ref RAIL_SUPPORTS_PROTOCOL_IEEE802154, \ref RAIL_SUPPORTS_2P4GHZ_BAND, or
 * \ref RAIL_SUPPORTS_ANTENNA_DIVERSITY is 0.
 */
extern const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzAntDiv;

/**
 * Default PHY to use for 2.4 GHz 802.15.4 optimized for coexistence. Will be
 * NULL if \ref RAIL_IEEE802154_SUPPORTS_COEX_PHY is 0.
 */
extern const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzCoex;

/**
 * Default PHY to use for 2.4 GHz 802.15.4 optimized for coexistence, while
 * supporting antenna diversity. Will be NULL if
 * \ref RAIL_SUPPORTS_ANTENNA_DIVERSITY or
 * \ref RAIL_IEEE802154_SUPPORTS_COEX_PHY is 0.
 */
extern const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzAntDivCoex;

/**
 * Default PHY to use for 2.4 GHz 802.15.4 with a configuration that supports a
 * front-end module. Will be NULL if
 * \ref RAIL_IEEE802154_SUPPORTS_FEM_PHY is 0.
 */
extern const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzFem;

/**
 * Default PHY to use for 2.4 GHz 802.15.4 with a configuration that supports a
 * front-end module and antenna diversity. Will be NULL if
 * \ref RAIL_IEEE802154_SUPPORTS_FEM_PHY or \ref RAIL_SUPPORTS_ANTENNA_DIVERSITY
 * is 0.
 */
extern const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzAntDivFem;

/**
 * Default PHY to use for 2.4 GHz 802.15.4 with a configuration that supports a
 * front-end module and is optimized for radio coexistence. Will be NULL if
 * \ref RAIL_IEEE802154_SUPPORTS_FEM_PHY or
 * \ref RAIL_IEEE802154_SUPPORTS_COEX_PHY is 0.
 */
extern const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzCoexFem;

/**
 * Default PHY to use for 2.4 GHz 802.15.4 with a configuration that supports a
 * front-end module and antenna diversity, and is optimized for radio
 * coexistence. Will be NULL if \ref RAIL_IEEE802154_SUPPORTS_FEM_PHY,
 * \ref RAIL_IEEE802154_SUPPORTS_COEX_PHY, or
 * \ref RAIL_SUPPORTS_ANTENNA_DIVERSITY is 0.
 */
extern const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzAntDivCoexFem;

/**
 * Default PHY to use for 2.4 GHz 802.15.4 with custom settings. Will be NULL
 * if \ref RAIL_IEEE802154_SUPPORTS_CUSTOM1_PHY is 0.
 */
extern const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzCustom1;

/**
 * Default PHY to use for 863 MHz GB868 802.15.4. Will be NULL if
 * \ref RAIL_IEEE802154_SUPPORTS_G_SUBSET_GB868 is 0.
 */
extern const RAIL_ChannelConfig_t *const RAIL_IEEE802154_PhyGB863MHz;

/**
 * Default PHY to use for 915 MHz GB868 802.15.4. Will be NULL if
 * \ref RAIL_IEEE802154_SUPPORTS_G_SUBSET_GB868 is 0.
 */
extern const RAIL_ChannelConfig_t *const RAIL_IEEE802154_PhyGB915MHz;

/**
 * Default PHY to use for 2.4 GHz 802.15.4 with RX channel switching. Will be
 * NULL if \ref RAIL_IEEE802154_SUPPORTS_RX_CHANNEL_SWITCHING is 0.
 */
extern const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzRxChSwitching;

/// @} // End of group IEEE802154_PHY

#ifndef SLI_LIBRAIL_ALIAS

/**
 * Initialize RAIL for IEEE802.15.4 features.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in] config A non-NULL pointer to an IEEE802154 configuration structure.
 * @return Status code indicating success of the function call.
 *
 * This function calls the following RAIL functions to configure the radio for
 * IEEE802.15.4 features.
 *
 * Initializes the following:
 *   - Enables IEEE802154 hardware acceleration
 *   - Configures RAIL Auto Ack functionality
 *   - Configures RAIL Address Filter for 802.15.4 address filtering
 *
 * It saves having to call the following functions individually:
 * - \ref RAIL_ConfigAutoAck()
 * - \ref RAIL_SetRxTransitions()
 * - \ref RAIL_SetTxTransitions()
 * - \ref RAIL_WriteAutoAckFifo()
 * - \ref RAIL_SetStateTiming()
 * - \ref RAIL_ConfigAddressFilter()
 * - \ref RAIL_EnableAddressFilter()
 *
 * It must be called before most of the RAIL_IEEE802154_* functions.
 */
RAIL_Status_t RAIL_IEEE802154_Init(RAIL_Handle_t railHandle,
                                   const RAIL_IEEE802154_Config_t *config);

/**
 * Configure the radio for 2.4 GHz 802.15.4 operation.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @return Status code indicating success of the function call.
 *
 * This initializes the radio for 2.4 GHz operation. It takes the place of
 * calling \ref RAIL_ConfigChannels(). After this call,
 * channels 11-26 will be available, giving the frequencies of those channels
 * on channel page 0, as defined by IEEE 802.15.4-2011 section 8.1.2.2.
 *
 * @note This call implicitly disables all \ref RAIL_IEEE802154_GOptions_t.
 */
RAIL_Status_t RAIL_IEEE802154_Config2p4GHzRadio(RAIL_Handle_t railHandle);

/**
 * Configure the radio for 2.4 GHz 802.15.4 operation with antenna diversity.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @return Status code indicating success of the function call.
 *
 * This initializes the radio for 2.4 GHz operation, but with a configuration
 * that supports antenna diversity. It takes the place of
 * calling \ref RAIL_ConfigChannels(). After this call,
 * channels 11-26 will be available, giving the frequencies of those channels
 * on channel page 0, as defined by IEEE 802.15.4-2011 section 8.1.2.2.
 *
 * @note This call implicitly disables all \ref RAIL_IEEE802154_GOptions_t.
 */
RAIL_Status_t RAIL_IEEE802154_Config2p4GHzRadioAntDiv(RAIL_Handle_t railHandle);

/**
 * Configure the radio for 2.4 GHz 802.15.4 operation with antenna diversity
 * optimized for radio coexistence.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @return Status code indicating success of the function call.
 *
 * This initializes the radio for 2.4 GHz operation, but with a configuration
 * that supports antenna diversity optimized for radio coexistence. It takes
 * the place of calling \ref RAIL_ConfigChannels(). After this call,
 * channels 11-26 will be available, giving the frequencies of those channels
 * on channel page 0, as defined by IEEE 802.15.4-2011 section 8.1.2.2.
 *
 * @note This call implicitly disables all \ref RAIL_IEEE802154_GOptions_t.
 */
RAIL_Status_t RAIL_IEEE802154_Config2p4GHzRadioAntDivCoex(RAIL_Handle_t railHandle);

/**
 * Configure the radio for 2.4 GHz 802.15.4 operation optimized for radio coexistence.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @return Status code indicating success of the function call.
 *
 * This initializes the radio for 2.4 GHz operation, but with a configuration
 * that supports radio coexistence. It takes the place of
 * calling \ref RAIL_ConfigChannels(). After this call,
 * channels 11-26 will be available, giving the frequencies of those channels
 * on channel page 0, as defined by IEEE 802.15.4-2011 section 8.1.2.2.
 *
 * @note This call implicitly disables all \ref RAIL_IEEE802154_GOptions_t.
 */
RAIL_Status_t RAIL_IEEE802154_Config2p4GHzRadioCoex(RAIL_Handle_t railHandle);

/**
 * Configure the radio for 2.4 GHz 802.15.4 operation with a front end module.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @return Status code indicating success of the function call.
 *
 * This initializes the radio for 2.4 GHz operation, but with a configuration
 * that supports a front end module. It takes the place of
 * calling \ref RAIL_ConfigChannels(). After this call,
 * channels 11-26 will be available, giving the frequencies of those channels
 * on channel page 0, as defined by IEEE 802.15.4-2011 section 8.1.2.2.
 *
 * @note This call implicitly disables all \ref RAIL_IEEE802154_GOptions_t.
 */
RAIL_Status_t RAIL_IEEE802154_Config2p4GHzRadioFem(RAIL_Handle_t railHandle);

/**
 * Configure the radio for 2.4 GHz 802.15.4 operation with antenna diversity
 * optimized for a front end module.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @return Status code indicating success of the function call.
 *
 * This initializes the radio for 2.4 GHz operation, but with a configuration
 * that supports antenna diversity and a front end module. It takes the place of
 * calling \ref RAIL_ConfigChannels(). After this call,
 * channels 11-26 will be available, giving the frequencies of those channels
 * on channel page 0, as defined by IEEE 802.15.4-2011 section 8.1.2.2.
 *
 * @note This call implicitly disables all \ref RAIL_IEEE802154_GOptions_t.
 */
RAIL_Status_t RAIL_IEEE802154_Config2p4GHzRadioAntDivFem(RAIL_Handle_t railHandle);

/**
 * Configure the radio for 2.4 GHz 802.15.4 operation optimized for radio coexistence
 * and a front end module.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @return Status code indicating success of the function call.
 *
 * This initializes the radio for 2.4 GHz operation, but with a configuration
 * that supports radio coexistence and a front end module. It takes the place of
 * calling \ref RAIL_ConfigChannels(). After this call,
 * channels 11-26 will be available, giving the frequencies of those channels
 * on channel page 0, as defined by IEEE 802.15.4-2011 section 8.1.2.2.
 *
 * @note This call implicitly disables all \ref RAIL_IEEE802154_GOptions_t.
 */
RAIL_Status_t RAIL_IEEE802154_Config2p4GHzRadioCoexFem(RAIL_Handle_t railHandle);

/**
 * Configure the radio for 2.4 GHz 802.15.4 operation with antenna diversity
 * optimized for radio coexistence and a front end module.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @return Status code indicating success of the function call.
 *
 * This initializes the radio for 2.4 GHz operation, but with a configuration
 * that supports antenna diversity, radio coexistence and a front end module.
 * It takes the place of calling \ref RAIL_ConfigChannels().
 * After this call, channels 11-26 will be available, giving the frequencies of
 * those channels on channel page 0, as defined by IEEE 802.15.4-2011 section 8.1.2.2.
 *
 * @note This call implicitly disables all \ref RAIL_IEEE802154_GOptions_t.
 */
RAIL_Status_t RAIL_IEEE802154_Config2p4GHzRadioAntDivCoexFem(RAIL_Handle_t railHandle);

#endif//SLI_LIBRAIL_ALIAS

#ifndef DOXYGEN_UNDOCUMENTED

/**
 * Time in microseconds to listen for a packet on the 2 Mbps channel.
 * This timeout can be configured at runtime using \ref RAIL_IEEE802154_Config2MbpsRxTimeout().
 */
#define RAIL_IEEE802154_2MBPS_RECEIVE_TIMEOUT_US 1500UL

#ifndef SLI_LIBRAIL_ALIAS

/**
 * Configure the radio for 2.4 GHz 802.15.4 for 250 kbps or 2 Mbps operation.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @return Status code indicating success of the function call.
 *
 * This initializes the radio for 2.4 GHz high speed operation.
 * It takes the place of calling \ref RAIL_ConfigChannels().
 * After this call, channels 11-26 will be available, giving the frequencies of
 * those channels on channel page 0, as defined by IEEE 802.15.4-2011 section 8.1.2.2
 * at 250 kbps.
 * Channels 11-26 will support transmitting and receiving using dual sync words.
 * Channels 27-42 will transmit and receive on the frequency of [channel - 16] at 2 Mbps.
 * Auto-ack and address filtering are disabled when channels 27-42 are selected.
 *
 * @note This call implicitly disables all \ref RAIL_IEEE802154_GOptions_t.
 *   This API can be safely used with 802.15.4/BLE DMP but not 802.15.4/802.15.4 DMP.
 */
RAIL_Status_t RAIL_IEEE802154_Config2p4GHzRadio2Mbps(RAIL_Handle_t railHandle);

/**
 * Configure the radio for 2.4 GHz 802.15.4 for 250 kbps or 1 Mbps forward error correction
 * operation.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @return Status code indicating success of the function call.
 *
 * This initializes the radio for 2.4 GHz high speed operation.
 * It takes the place of calling \ref RAIL_ConfigChannels().
 * After this call, channels 11-26 will be available, giving the frequencies of
 * those channels on channel page 0, as defined by IEEE 802.15.4-2011 section 8.1.2.2
 * at 250 kbps.
 * Channels 11-26 will support transmitting and receiving using dual sync words.
 * Channels 27-42 will transmit and receive on the frequency of [channel - 16] at 1 Mbps.
 * Auto-ack and address filtering are disabled when channels 27-42 are selected.
 *
 * @note This call implicitly disables all \ref RAIL_IEEE802154_GOptions_t.
 *   This API can be safely used with 802.15.4/BLE DMP but not 802.15.4/802.15.4 DMP.
 */
RAIL_Status_t RAIL_IEEE802154_Config2p4GHzRadio1MbpsFec(RAIL_Handle_t railHandle);

/**
 * Configure the 802.15.4 2 Mbps receive timeout.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in] timeout Time to listen for a packet on the 2 Mbps channel
 *   before switching back to the 250 kbps channel.
 * @return Status code indicating success of the function call.
 *
 * @note By default the 2 Mbps receive timeout is \ref RAIL_IEEE802154_2MBPS_RECEIVE_TIMEOUT_US.
 */
RAIL_Status_t RAIL_IEEE802154_Config2MbpsRxTimeout(RAIL_Handle_t railHandle,
                                                   RAIL_Time_t timeout);

/**
 * Configure the 802.15.4 2 Mbps mode switch receive channel.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in] channel 802.15.4 channel(11-26) to listen for a mode switch packet.
 * @return Status code indicating success of the function call.
 *
 * Mode switch to the 2 Mbps radio config will only occur on the provided channel.
 * Mode switch packets received on other channels will be ignored.
 */
RAIL_Status_t RAIL_IEEE802154_Config2MbpsRxChannel(RAIL_Handle_t railHandle,
                                                   uint16_t channel);

#endif//SLI_LIBRAIL_ALIAS

#endif //DOXYGEN_UNDOCUMENTED

/**
 * Configure the radio for 2.4 GHz 802.15.4 operation with custom
 * settings. It enables better interoperability with some proprietary
 * PHYs, but doesn't guarantee data sheet performance.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @return Status code indicating success of the function call.
 *
 * This initializes the radio for 2.4 GHz operation with
 * custom settings. It replaces needing to call
 * \ref RAIL_ConfigChannels().
 * Do not call this function unless instructed by Silicon Labs.
 *
 * @note This feature is only available on platforms where
 *   \ref RAIL_IEEE802154_SUPPORTS_CUSTOM1_PHY is true.
 */
RAIL_Status_t RAIL_IEEE802154_Config2p4GHzRadioCustom1(RAIL_Handle_t railHandle);

#ifndef SLI_LIBRAIL_ALIAS

/**
 * Configure the radio for Sub-GHz GB868 863 MHz 802.15.4 operation.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @return Status code indicating success of the function call.
 *
 * This initializes the radio for Sub-GHz GB868 863 MHz operation. It takes the
 * place of calling \ref RAIL_ConfigChannels().
 * After this call, GB868 channels in the 863 MHz band (channel pages 28, 29,
 * and 30 -- logical channels 0x80..0x9A, 0xA0..0xA8, 0xC0..0xDA, respectively)
 * will be available, as defined by Rev 22 of the Zigbee Specification, 2017
 * document 05-3474-22, section D.10.2.1.3.2.
 *
 * @note This call implicitly enables \ref RAIL_IEEE802154_G_OPTION_GB868.
 */
RAIL_Status_t RAIL_IEEE802154_ConfigGB863MHzRadio(RAIL_Handle_t railHandle);

/**
 * Configure the radio for Sub-GHz GB868 915 MHz 802.15.4 operation.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @return Status code indicating success of the function call.
 *
 * This initializes the radio for Sub-GHz GB868 915 MHz operation. It takes the
 * place of calling \ref RAIL_ConfigChannels().
 * After this call, GB868 channels in the 915 MHz band (channel page 31 --
 * logical channels 0xE0..0xFA) will be available, as defined by Rev 22 of
 * the Zigbee Specification, 2017 document 05-3474-22, section D.10.2.1.3.2.
 *
 * @note This call implicitly enables \ref RAIL_IEEE802154_G_OPTION_GB868.
 */
RAIL_Status_t RAIL_IEEE802154_ConfigGB915MHzRadio(RAIL_Handle_t railHandle);

/**
 * De-initialize IEEE802.15.4 hardware acceleration.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @return Status code indicating success of the function call.
 *
 * Disables and resets all IEE802.15.4 hardware acceleration features. This
 * function should only be called when the radio is IDLE. This calls the
 * following:
 * - \ref RAIL_SetStateTiming(), to reset all timings to 100 us
 * - \ref RAIL_EnableAddressFilter() passing false for its enable parameter
 * - \ref RAIL_ResetAddressFilter()
 */
RAIL_Status_t RAIL_IEEE802154_Deinit(RAIL_Handle_t railHandle);

/**
 * Return whether IEEE802.15.4 hardware acceleration is currently enabled.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @return true if IEEE802.15.4 hardware acceleration was enabled to start with
 *   and false otherwise.
 */
bool RAIL_IEEE802154_IsEnabled(RAIL_Handle_t railHandle);

#endif//SLI_LIBRAIL_ALIAS

/**
 * @enum RAIL_IEEE802154_PtiRadioConfig_t
 * @brief 802.15.4 PTI radio configuration mode
 */
RAIL_ENUM_GENERIC(RAIL_IEEE802154_PtiRadioConfig_t, uint16_t) {
  /**
   * Built-in 2.4 GHz 802.15.4 radio configuration.
   */
  RAIL_IEEE802154_PTI_RADIO_CONFIG_2P4GHZ = 0x00U,
  /**
   * Built-in 2.4 GHz 802.15.4 radio configuration
   * with RX antenna diversity support.
   */
  RAIL_IEEE802154_PTI_RADIO_CONFIG_2P4GHZ_ANTDIV = 0x01U,
  /**
   * Built-in 2.4 GHz 802.15.4 radio configuration
   * optimized for radio coexistence.
   */
  RAIL_IEEE802154_PTI_RADIO_CONFIG_2P4GHZ_COEX = 0x02U,
  /**
   * Built-in 2.4 GHz 802.15.4 radio configuration with
   * RX antenna diversity support optimized for radio coexistence.
   */
  RAIL_IEEE802154_PTI_RADIO_CONFIG_2P4GHZ_ANTDIV_COEX = 0x03U,
  /**
   * Built-in 2.4 GHz 802.15.4 radio configuration
   * optimized for front end modules.
   */
  RAIL_IEEE802154_PTI_RADIO_CONFIG_2P4GHZ_FEM = 0x08U,
  /**
   * Built-in 2.4 GHz 802.15.4 radio configuration
   * with RX antenna diversity support optimized for
   * front end modules.
   */
  RAIL_IEEE802154_PTI_RADIO_CONFIG_2P4GHZ_FEM_ANTDIV = 0x09U,
  /**
   * Built-in 2.4 GHz 802.15.4 radio configuration
   * optimized for radio coexistence and front end modules.
   */
  RAIL_IEEE802154_PTI_RADIO_CONFIG_2P4GHZ_FEM_COEX = 0x0AU,
  /**
   * Built-in 2.4 GHz 802.15.4 radio configuration with
   * RX antenna diversity support optimized for radio coexistence
   * and front end modules.
   */
  RAIL_IEEE802154_PTI_RADIO_CONFIG_2P4GHZ_FEM_ANTDIV_COEX = 0x0BU,
  /**
   * Built-in 863 MHz GB868 802.15.4 radio configuration.
   */
  RAIL_IEEE802154_PTI_RADIO_CONFIG_863MHZ_GB868 = 0x85U,
  /**
   * Built-in 915 MHz GB868 802.15.4 radio configuration.
   */
  RAIL_IEEE802154_PTI_RADIO_CONFIG_915MHZ_GB868 = 0x86U,
  /**
   * External 915 MHz Zigbee R23 802.15.4 NA radio configuration.
   */
  RAIL_IEEE802154_PTI_RADIO_CONFIG_915MHZ_R23_NA_EXT = 0x97U,
};

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// Self-referencing defines minimize compiler complaints when using RAIL_ENUM
#define RAIL_IEEE802154_PTI_RADIO_CONFIG_2P4GHZ             ((RAIL_IEEE802154_PtiRadioConfig_t) RAIL_IEEE802154_PTI_RADIO_CONFIG_2P4GHZ)
#define RAIL_IEEE802154_PTI_RADIO_CONFIG_2P4GHZ_ANTDIV      ((RAIL_IEEE802154_PtiRadioConfig_t) RAIL_IEEE802154_PTI_RADIO_CONFIG_2P4GHZ_ANTDIV)
#define RAIL_IEEE802154_PTI_RADIO_CONFIG_2P4GHZ_COEX        ((RAIL_IEEE802154_PtiRadioConfig_t) RAIL_IEEE802154_PTI_RADIO_CONFIG_2P4GHZ_COEX)
#define RAIL_IEEE802154_PTI_RADIO_CONFIG_2P4GHZ_ANTDIV_COEX ((RAIL_IEEE802154_PtiRadioConfig_t) RAIL_IEEE802154_PTI_RADIO_CONFIG_2P4GHZ_ANTDIV_COEX)
#define RAIL_IEEE802154_PTI_RADIO_CONFIG_863MHZ_GB868       ((RAIL_IEEE802154_PtiRadioConfig_t) RAIL_IEEE802154_PTI_RADIO_CONFIG_863MHZ_GB868)
#define RAIL_IEEE802154_PTI_RADIO_CONFIG_915MHZ_GB868       ((RAIL_IEEE802154_PtiRadioConfig_t) RAIL_IEEE802154_PTI_RADIO_CONFIG_915MHZ_GB868)
#define RAIL_IEEE802154_PTI_RADIO_CONFIG_915MHZ_R23_NA_EXT  ((RAIL_IEEE802154_PtiRadioConfig_t) RAIL_IEEE802154_PTI_RADIO_CONFIG_915MHZ_R23_NA_EXT)
#endif//DOXYGEN_SHOULD_SKIP_THIS

#ifndef SLI_LIBRAIL_ALIAS

/**
 * Return IEEE802.15.4 PTI radio config.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @return PTI (Packet Trace Information) radio config Id.
 */
RAIL_IEEE802154_PtiRadioConfig_t RAIL_IEEE802154_GetPtiRadioConfig(RAIL_Handle_t railHandle);

#ifndef DOXYGEN_UNDOCUMENTED
/**
 * Set IEEE802.15.4 PTI radio config (for Silicon Labs internal use only).
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in] ptiRadioConfigId PTI (Packet Trace Information) radio config Id.
 * @return Status code indicating success of the function call.
 */
RAIL_Status_t RAIL_IEEE802154_SetPtiRadioConfig(RAIL_Handle_t railHandle,
                                                RAIL_IEEE802154_PtiRadioConfig_t ptiRadioConfigId);
#endif//DOXYGEN_UNDOCUMENTED

/**
 * Configure the RAIL Address Filter for 802.15.4 filtering.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in] addresses A pointer to the address information that should be used.
 * @return Status code indicating success of the function call. If this returns
 *   an error, the 802.15.4 address filter is in an undefined state.
 *
 * Set up the 802.15.4 address filter to accept messages to the given
 * addresses. This will return false if any of the addresses failed to be set.
 * If NULL is passed in for addresses, all addresses will be set to their
 * reset value.
 */
RAIL_Status_t RAIL_IEEE802154_SetAddresses(RAIL_Handle_t railHandle,
                                           const RAIL_IEEE802154_AddrConfig_t *addresses);

/**
 * Set a PAN Id for 802.15.4 address filtering.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in] panId The 16-bit PAN Id information.
 *   This will be matched against the destination PAN Id of incoming messages.
 *   The PAN Id is sent little endian over the air, meaning panId[7:0] is first in
 *   the payload followed by panId[15:8]. Set to 0xFFFF to disable for this index.
 * @param[in] index Indicates which PAN Id to set. Must be below
 *   \ref RAIL_IEEE802154_MAX_ADDRESSES.
 * @return Status code indicating success of the function call.
 *
 * Set up the 802.15.4 address filter to accept messages to the given PAN Id.
 */
RAIL_Status_t RAIL_IEEE802154_SetPanId(RAIL_Handle_t railHandle,
                                       uint16_t panId,
                                       uint8_t index);

/**
 * Set a short address for 802.15.4 address filtering.
 *
 * @param[in] railHandle A handle of RAIL instance
 * @param[in] shortAddr 16 bit short address value. This will be matched against the
 *   destination short address of incoming messages. The short address is sent
 *   little endian over the air meaning shortAddr[7:0] is first in the payload
 *   followed by shortAddr[15:8]. Set to 0xFFFF to disable for this index.
 * @param[in] index Which short address to set. Must be below
 *   \ref RAIL_IEEE802154_MAX_ADDRESSES.
 * @return Status code indicating success of the function call.
 *
 * Set up the 802.15.4 address filter to accept messages to the given short
 * address.
 */
RAIL_Status_t RAIL_IEEE802154_SetShortAddress(RAIL_Handle_t railHandle,
                                              uint16_t shortAddr,
                                              uint8_t index);

/**
 * Set a long address for 802.15.4 address filtering.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in] longAddr A pointer to an 8-byte array containing the long address
 *   information. The long address must be in over-the-air byte order. This will
 *   be matched against the destination long address of incoming messages. Set to
 *   0x00 00 00 00 00 00 00 00 to disable for this index.
 * @param[in] index Indicates which long address to set. Must be below
 *   \ref RAIL_IEEE802154_MAX_ADDRESSES.
 * @return Status code indicating success of the function call.
 *
 * Set up the 802.15.4 address filter to accept messages to the given long
 * address.
 */
RAIL_Status_t RAIL_IEEE802154_SetLongAddress(RAIL_Handle_t railHandle,
                                             const uint8_t *longAddr,
                                             uint8_t index);

/**
 * Set whether the current node is a PAN coordinator.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in] isPanCoordinator true if this device is a PAN coordinator.
 * @return Status code indicating success of the function call.
 *
 * If the device is a PAN Coordinator, it will accept data and command
 * frames with no destination address. This function will fail if 802.15.4
 * hardware acceleration is not currently enabled by calling
 * \ref RAIL_IEEE802154_Init(). This setting may be changed
 * at any time when 802.15.4 hardware acceleration is enabled.
 */
RAIL_Status_t RAIL_IEEE802154_SetPanCoordinator(RAIL_Handle_t railHandle,
                                                bool isPanCoordinator);

/**
 * Set whether to enable 802.15.4 promiscuous mode.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in] enable true if all frames and addresses should be accepted.
 * @return Status code indicating success of the function call.
 *
 * If promiscuous mode is enabled, no frame or address filtering steps
 * will be performed other than checking the CRC. This function will fail if
 * 802.15.4 hardware acceleration is not currently enabled by calling
 * \ref RAIL_IEEE802154_Init(). This setting may be changed at any time when
 * 802.15.4 hardware acceleration is enabled.
 */
RAIL_Status_t RAIL_IEEE802154_SetPromiscuousMode(RAIL_Handle_t railHandle,
                                                 bool enable);

#endif//SLI_LIBRAIL_ALIAS

/**
 * @enum RAIL_IEEE802154_EOptions_t
 * @brief 802.15.4E-2012 options, in reality a bitmask.
 */
RAIL_ENUM_GENERIC(RAIL_IEEE802154_EOptions_t, uint32_t) {
  /** Shift position of \ref RAIL_IEEE802154_E_OPTION_GB868 bit. */
  RAIL_IEEE802154_E_OPTION_GB868_SHIFT = 0,
  /** Shift position of \ref RAIL_IEEE802154_E_OPTION_ENH_ACK bit. */
  RAIL_IEEE802154_E_OPTION_ENH_ACK_SHIFT,
  /** Shift position of \ref RAIL_IEEE802154_E_OPTION_IMPLICIT_BROADCAST bit. */
  RAIL_IEEE802154_E_OPTION_IMPLICIT_BROADCAST_SHIFT,
};

/** A value representing no options enabled. */
#define RAIL_IEEE802154_E_OPTIONS_NONE 0UL
/** All options disabled by default . */
#define RAIL_IEEE802154_E_OPTIONS_DEFAULT RAIL_IEEE802154_E_OPTIONS_NONE

/**
 * An option to enable/disable 802.15.4E-2012 features needed for GB868.
 * When not promiscuous, RAIL normally accepts only 802.15.4 MAC frames
 * whose MAC header Frame Version is 0 (802.15.4-2003) or 1 (802.15.4-2006),
 * filtering out higher Frame Version packets (as \ref
 * RAIL_RX_PACKET_ABORT_FORMAT).
 * Enabling this feature additionally allows Frame Version 2 (802.15.4E-2012 /
 * 802.15.4-2015) packets to be accepted and passed to the application.
 *
 * @note Enabling this feature also automatically enables \ref
 *   RAIL_IEEE802154_E_OPTION_ENH_ACK on platforms that support
 *   that feature.
 *
 * @note This feature does not automatically enable receiving Multipurpose
 *   frames; that can be enabled via \ref RAIL_IEEE802154_AcceptFrames()'s
 *   \ref RAIL_IEEE802154_ACCEPT_MULTIPURPOSE_FRAMES.
 */
#define RAIL_IEEE802154_E_OPTION_GB868 (1UL << RAIL_IEEE802154_E_OPTION_GB868_SHIFT)

/**
 * An option to enable/disable 802.15.4E-2012 features needed for Enhanced Acks.
 * This option requires that \ref RAIL_IEEE802154_E_OPTION_GB868 also be
 * enabled, and is enabled automatically on platforms that support this
 * feature. It exists as a separate flag to allow runtime detection of whether
 * the platform supports this feature or not.
 *
 * When enabled, only an Enhanced Ack is expected in response to a transmitted
 * Ack-requesting 802.15.4E Version 2 frame. RAIL only knows how to construct
 * 802.15.4 Immediate Acks but not Enhanced Acks.
 *
 * This option causes \ref RAIL_EVENT_IEEE802154_DATA_REQUEST_COMMAND to be
 * issued for Ack-requesting Version 2 MAC Command frames, Data frames
 * (if \ref RAIL_IEEE802154_EnableDataFramePending() is enabled), and
 * Multipurpose Frames (if \ref RAIL_IEEE802154_ACCEPT_MULTIPURPOSE_FRAMES
 * is enabled).
 *
 * The application is expected to handle this event by calling \ref
 * RAIL_GetRxIncomingPacketInfo() and parsing the partly-received incoming
 * frame to determine the type of Ack needed:
 * - If an Immediate Ack, determine Frame Pending needs based on the packet
 *   type and addressing information and call \ref
 *   RAIL_IEEE802154_ToggleFramePending() if necessary;
 * - If an Enhanced Ack, generate the complete payload of the Enhanced Ack
 *   including any Frame Pending information and call \ref
 *   RAIL_IEEE802154_WriteEnhAck() in time for that Enhanced Ack to
 *   be sent. If not called in time, \ref RAIL_EVENT_TXACK_UNDERFLOW will
 *   likely result.
 *   Note that if 802.15.4 MAC-level encryption is used with Version 2
 *   frames, the application should decrypt the MAC Command byte in a
 *   MAC Command frame to determine whether it is a Data Request or other
 *   MAC Command.
 *
 * An application can also enable \ref
 * RAIL_IEEE802154_EnableEarlyFramePending() if the protocol doesn't
 * need to examine the MAC Command byte of MAC Command frames but can
 * infer it to be a Data Request.
 *
 * On 802.15.4E GB868 platforms that lack this support, legacy Immediate Acks
 * are sent/expected for received/transmitted Ack-requesting 802.15.4E Frame
 * Version 2 frames; calls to \ref RAIL_IEEE802154_WriteEnhAck() have no
 * effect. Attempting to use this feature via \ref
 * RAIL_IEEE802154_ConfigEOptions() returns an error.
 */
#define RAIL_IEEE802154_E_OPTION_ENH_ACK (1UL << RAIL_IEEE802154_E_OPTION_ENH_ACK_SHIFT)

/**
 * An option to enable/disable 802.15.4E-2012 macImplicitBroadcast feature.
 *
 * When enabled, received Frame Version 2 frames without a destination
 * PAN Id or destination address are treated as though they are addressed
 * to the broadcast PAN Id and broadcast short address. When disabled, such
 * frames are filtered unless the device is the PAN coordinator and
 * appropriate source addressing information exists in the packet
 */
#define RAIL_IEEE802154_E_OPTION_IMPLICIT_BROADCAST (1UL << RAIL_IEEE802154_E_OPTION_IMPLICIT_BROADCAST_SHIFT)

/** A value representing all possible options. */
#define RAIL_IEEE802154_E_OPTIONS_ALL 0xFFFFFFFFUL

#ifndef SLI_LIBRAIL_ALIAS

/**
 * Configure certain 802.15.4E-2012 / 802.15.4-2015 Frame Version 2 features.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in] mask A bitmask containing which options should be modified.
 * @param[in] options A bitmask containing desired options settings.
 *   Bit positions for each option are found in the \ref
 *   RAIL_IEEE802154_EOptions_t.
 * @return Status code indicating success of the function call.
 *
 * This function will fail if 802.15.4 hardware acceleration is not
 * currently enabled by calling \ref RAIL_IEEE802154_Init() or the platform
 * does not support the feature(s).
 * These settings may be changed at any time when 802.15.4 hardware
 * acceleration is enabled.
 */
RAIL_Status_t RAIL_IEEE802154_ConfigEOptions(RAIL_Handle_t railHandle,
                                             RAIL_IEEE802154_EOptions_t mask,
                                             RAIL_IEEE802154_EOptions_t options);

#endif//SLI_LIBRAIL_ALIAS

/**
 * @enum RAIL_IEEE802154_GOptions_t
 * @brief 802.15.4G-2012 options, in reality a bitmask.
 */
RAIL_ENUM_GENERIC(RAIL_IEEE802154_GOptions_t, uint32_t) {
  /** Shift position of \ref RAIL_IEEE802154_G_OPTION_GB868 bit. */
  RAIL_IEEE802154_G_OPTION_GB868_SHIFT = 0,
  /** Shift position of \ref RAIL_IEEE802154_G_OPTION_DYNFEC bit. */
  RAIL_IEEE802154_G_OPTION_DYNFEC_SHIFT,
  /** Shift position of \ref RAIL_IEEE802154_G_OPTION_WISUN_MODESWITCH bit. */
  RAIL_IEEE802154_G_OPTION_WISUN_MODESWITCH_SHIFT,
};

/** A value representing no options enabled. */
#define RAIL_IEEE802154_G_OPTIONS_NONE 0UL
/** All options disabled by default . */
#define RAIL_IEEE802154_G_OPTIONS_DEFAULT RAIL_IEEE802154_G_OPTIONS_NONE

/**
 * An option to enable/disable 802.15.4G-2012 features needed for GB868.
 * Normally RAIL supports 802.15.4-2003 and -2006 radio configurations
 * that have the single-byte PHY header allowing frames up to 128 bytes
 * in size. This feature must be enabled for 802.15.4G-2012 or
 * 802.15.4-2015 SUN PHY radio configurations with the two-byte
 * bit-reversed-length PHY header format.
 *
 * While GB868 only supports whitened non-FEC non-mode-switch frames
 * up to 129 bytes including 2-byte CRC, this option also enables:
 * - On platforms where \ref RAIL_FEAT_IEEE802154_G_4BYTE_CRC_SUPPORTED
 *   is true: automatic per-packet 2/4-byte Frame Check Sequence (FCS)
 *   reception and transmission based on the FCS Type bit in the
 *   received/transmitted PHY header. This includes Ack reception
 *   and automatically-generated Acks reflect the CRC size of the
 *   incoming frame being acknowledged (i.e., their MAC payload will be
 *   increased to 7 bytes when sending 4-byte FCS).
 *   On other platforms, only the 2-byte FCS is supported.
 * - On platforms where \ref RAIL_FEAT_IEEE802154_G_UNWHITENED_RX_SUPPORTED
 *   and/or \ref RAIL_FEAT_IEEE802154_G_UNWHITENED_TX_SUPPORTED are true:
 *   automatic per-packet whitened/unwhitened reception and transmission,
 *   respectively, based on the Data Whitening bit in the received/transmitted
 *   PHY header. This includes Ack reception and automatically-generated Acks
 *   which reflect the whitening of the incoming frame being acknowledged.
 *   On other platforms, only whitened frames are supported.
 * - Support for frames up to 2049 bytes per the radio configuration's
 *   maximum packet length setting.
 *
 * @note Sending/receiving whitened frames assumes the radio configuration
 *   has established an appropriate 802.15.4-compliant whitening algorithm.
 *   RAIL does not itself override the radio configuration's whitening
 *   settings other than to enable/disable it per-packet based on the
 *   packet's PHY header Data Whitening flag.
 */
#define RAIL_IEEE802154_G_OPTION_GB868 (1UL << RAIL_IEEE802154_G_OPTION_GB868_SHIFT)

/**
 * An option to enable/disable 802.15.4G dynamic FEC feature (SUN FSK only).
 * The sync word, called start-of-frame delimiter (SFD) in the 15.4 spec, indicates whether
 * the rest of the packet is FEC encoded or not. This feature requires per-packet
 * dual sync word detection and specific receiver pausing.
 * Note that this feature is only available on platforms where
 * \ref RAIL_IEEE802154_SUPPORTS_G_DYNFEC is true.
 *
 * This option is only valid for SUN PHYs that have the FEC configured and enabled.
 *
 * The sync word used during transmit is selected with \ref RAIL_TX_OPTION_SYNC_WORD_ID.
 *
 * The sync word corresponding to the FEC encoded mode must be SYNC1, with SYNC2 indicating non-FEC.
 * Sync words are set appropriately in all Sun FEC-enabled PHYs so there should
 * never be a need to call \ref RAIL_ConfigSyncWords() when this option is enabled.
 *
 * Also, dual sync word detection is set in all SUN FEC enabled PHYs, then there is no need
 * to change \ref RAIL_RX_OPTION_ENABLE_DUALSYNC.
 */
#define RAIL_IEEE802154_G_OPTION_DYNFEC (1UL << RAIL_IEEE802154_G_OPTION_DYNFEC_SHIFT)

/**
 * An option to enable/disable Wi-SUN Mode Switch feature.
 * This feature consists in switching to a new PHY mode with a higher rate typically
 * by sending/receiving a specific Mode Switch packet that indicates the incoming new PHY mode.
 * The Mode Switch packet is an FSK-modulated 2-byte PHY header with no payload.
 * Because this feature relies on specific receiver pausing, note that it is only available
 * on platforms where \ref RAIL_IEEE802154_SUPPORTS_G_MODESWITCH is true.
 */
#define RAIL_IEEE802154_G_OPTION_WISUN_MODESWITCH (1UL << RAIL_IEEE802154_G_OPTION_WISUN_MODESWITCH_SHIFT)

/** A value representing all possible options. */
#define RAIL_IEEE802154_G_OPTIONS_ALL 0xFFFFFFFFUL

#ifndef SLI_LIBRAIL_ALIAS

/**
 * Configure certain 802.15.4G-2012 / 802.15.4-2015 SUN PHY features
 * (only for radio configurations designed accordingly).
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in] mask A bitmask containing which options should be modified.
 * @param[in] options A bitmask containing desired options settings.
 *   Bit positions for each option are found in the \ref
 *   RAIL_IEEE802154_GOptions_t.
 * @return Status code indicating success of the function call.
 *
 * This function will fail if 802.15.4 hardware acceleration is not
 * currently enabled by calling \ref RAIL_IEEE802154_Init(), the platform does
 * not support the feature(s), the radio configuration is not appropriate,
 * or the radio is not idle.
 */
RAIL_Status_t RAIL_IEEE802154_ConfigGOptions(RAIL_Handle_t railHandle,
                                             RAIL_IEEE802154_GOptions_t mask,
                                             RAIL_IEEE802154_GOptions_t options);

#endif//SLI_LIBRAIL_ALIAS

/**
 * @struct RAIL_IEEE802154_ModeSwitchPhr_t
 * @brief A structure containing the PHY Mode Id value and the corresponding mode
 *   switch PHR as defined in Wi-SUN spec.
 *   These structures are usually generated by the radio configurator.
 */
typedef struct RAIL_IEEE802154_ModeSwitchPhr {
  /** PHY mode Id. */
  uint8_t phyModeId;
  /** Corresponding Mode Switch PHY header. */
  uint16_t phr;
} RAIL_IEEE802154_ModeSwitchPhr_t;

#ifndef DOXYGEN_UNDOCUMENTED
/** When filtering PHY Mode Id, this is the minimum OFDM value */
#define MIN_OFDM_PHY_MODE_ID (0x20U)
/** When filtering PHY Mode Id, this is the maximum OFDM value */
#define MAX_OFDM_PHY_MODE_ID (0x5FU)
#endif //DOXYGEN_UNDOCUMENTED

#ifndef SLI_LIBRAIL_ALIAS

/**
 * Compute channel to switch to given a targeted PHY Mode Id
 * in the context of Wi-SUN mode switching.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in] newPhyModeId A targeted PHY Mode Id.
 * @param[out] pChannel A pointer to the channel to switch to.
 * @return Status code indicating success of the function call.
 *
 * This function will fail if:
 * - the targeted PHY Mode Id is the same as the current PHY Mode Id
 * - called on a platform that lacks \ref RAIL_IEEE802154_SUPPORTS_G_MODESWITCH
 * - called on a platform that doesn't have 802154G options enabled
 *     by \ref RAIL_IEEE802154_ConfigGOptions().
 * For newPhyModeId associated with a FSK FEC_off PHY, if dynamic FEC is
 * activated (see \ref RAIL_IEEE802154_G_OPTION_DYNFEC), the returned
 * channel can correspond to the associated FSK FEC_on PHY corresponding
 * then to PHY Mode Id = newPhyModeId + 16
 */
RAIL_Status_t RAIL_IEEE802154_ComputeChannelFromPhyModeId(RAIL_Handle_t railHandle,
                                                          uint8_t newPhyModeId,
                                                          uint16_t *pChannel);

#endif//SLI_LIBRAIL_ALIAS

/**
 * Manage forbidden channels during mode switch.
 *
 * @param[in] currentBaseFreq The current frequency of the base channel.
 * @param[in] newPhyModeId A targeted PHY Mode Id.
 * @param[in] configEntryNewPhyModeId A pointer to \ref RAIL_ChannelConfigEntry_t
 *   structure corresponding to the new PHY configEntry.
 * @param[in,out] pChannel A pointer to the channel to switch to. If channel
 *   is valid, the function must just return. If channel is forbidden, the
 *   function must update it with the closest valid channel. The highest
 *   channel must be selected in case of two valid channels being equidistant
 *   to a forbidden channel.
 * @return Status code indicating success of the function call. It must
 *   return \ref RAIL_STATUS_INVALID_PARAMETER for failure or \ref
 *   RAIL_STATUS_NO_ERROR for success.
 *
 * This function must fail if no valid channel has been found. If so, RAIL will
 * abort the mode switch.
 *
 * @note This callback will only be called on platforms where
 *   \ref RAIL_IEEE802154_SUPPORTS_G_MODESWITCH is true, \ref
 *   RAIL_IEEE802154_G_OPTION_WISUN_MODESWITCH was successfully enabled,
 *   and a valid mode switch PHY header is received.
 */
RAIL_Status_t RAILCb_IEEE802154_IsModeSwitchNewChannelValid(uint32_t currentBaseFreq,
                                                            uint8_t newPhyModeId,
                                                            const RAIL_ChannelConfigEntry_t *configEntryNewPhyModeId,
                                                            uint16_t *pChannel);

/// When receiving packets, accept 802.15.4 BEACON frame types.
#define RAIL_IEEE802154_ACCEPT_BEACON_FRAMES       (0x01)
/// When receiving packets, accept 802.15.4 DATA frame types.
#define RAIL_IEEE802154_ACCEPT_DATA_FRAMES         (0x02)
/// When receiving packets, accept 802.15.4 Ack frame types.
/// @note Expected Ack frame types will still be accepted regardless
///   of this setting when waiting for an Ack after a transmit that
///   used \ref RAIL_TX_OPTION_WAIT_FOR_ACK and auto-Ack is enabled.
#define RAIL_IEEE802154_ACCEPT_ACK_FRAMES          (0x04)
/// When receiving packets, accept 802.15.4 COMMAND frame types.
#define RAIL_IEEE802154_ACCEPT_COMMAND_FRAMES      (0x08)
// Reserved for possible future use:               (0x10)
/// When receiving packets, accept 802.15.4-2015 Multipurpose frame types.
#define RAIL_IEEE802154_ACCEPT_MULTIPURPOSE_FRAMES (0x20)

/// In standard operation, accept BEACON, DATA and COMMAND frames.
/// Don't receive Ack frames unless waiting for Ack (i.e., only
/// receive expected Acks).
#define RAIL_IEEE802154_ACCEPT_STANDARD_FRAMES (RAIL_IEEE802154_ACCEPT_BEACON_FRAMES \
                                                | RAIL_IEEE802154_ACCEPT_DATA_FRAMES \
                                                | RAIL_IEEE802154_ACCEPT_COMMAND_FRAMES)

#ifndef SLI_LIBRAIL_ALIAS

/**
 * Set which 802.15.4 frame types to accept.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in] framesMask A mask containing which 802.15.4 frame types to receive.
 * @return Status code indicating success of the function call.
 *
 * This function will fail if 802.15.4 hardware acceleration is not currently
 * enabled by calling \ref RAIL_IEEE802154_Init() or framesMask requests an
 * unsupported frame type.
 * This setting may be changed at any time when 802.15.4 hardware
 * acceleration is enabled. Only Beacon, Data, Ack, Command, and Multipurpose
 * frames may be received.
 * The RAIL_IEEE802154_ACCEPT_*_FRAMES defines may be combined to create a
 * bitmask to pass into this function.
 *
 * \ref RAIL_IEEE802154_ACCEPT_ACK_FRAMES behaves slightly different than the
 * other defines. If \ref RAIL_IEEE802154_ACCEPT_ACK_FRAMES is set, the radio
 * will accept an Ack frame during normal packet reception, but only a
 * truly expected Ack will have its \ref RAIL_RxPacketDetails_t::isAck true.
 * If \ref RAIL_IEEE802154_ACCEPT_ACK_FRAMES is not set, Ack frames will be
 * filtered unless they're expected when the radio is waiting for an Ack.
 */
RAIL_Status_t RAIL_IEEE802154_AcceptFrames(RAIL_Handle_t railHandle,
                                           uint8_t framesMask);

/**
 * Enable early Frame Pending lookup event notification
 * (\ref RAIL_EVENT_IEEE802154_DATA_REQUEST_COMMAND).
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in] enable true to enable, false to disable.
 * @return Status code indicating success of the function call.
 *
 * Normally, \ref RAIL_EVENT_IEEE802154_DATA_REQUEST_COMMAND is triggered after
 * receiving the entire MAC header and MAC command byte for an Ack-requesting
 * MAC command frame. Version 0/1 frames also require that command to be a
 * Data Request for this event to occur.
 * Enabling this feature causes this event to be triggered earlier to allow for
 * more time to determine the type of Ack needed (Immediate or Enhanced) and/or
 * perform frame pending lookup to influence the outgoing Ack by using \ref
 * RAIL_IEEE802154_WriteEnhAck() or \ref RAIL_IEEE802154_ToggleFramePending().
 *
 * For Frame Version 0/1 packets and for Frame Version 2 packets when \ref
 * RAIL_IEEE802154_E_OPTION_ENH_ACK is not in use, "early" means right
 * after receiving the source address information in the MAC header.
 *
 * For Frame Version 2 packets when \ref RAIL_IEEE802154_E_OPTION_ENH_ACK
 * is in use, "early" means right after receiving any Auxiliary Security
 * header which follows the source address information in the MAC header.
 *
 * This feature is useful when the protocol knows an Ack-requesting MAC
 * Command must be a data poll without needing to receive the MAC Command
 * byte, giving it a bit more time to adjust Frame Pending or generate an
 * Enhanced Ack.
 *
 * This function will fail if 802.15.4 hardware acceleration is not
 * currently enabled by calling \ref RAIL_IEEE802154_Init(),
 * or on platforms that do not support this feature.
 * This setting may be changed at any time when 802.15.4 hardware
 * acceleration is enabled.
 */
RAIL_Status_t RAIL_IEEE802154_EnableEarlyFramePending(RAIL_Handle_t railHandle,
                                                      bool enable);

/**
 * Enable Frame Pending lookup event notification
 * (\ref RAIL_EVENT_IEEE802154_DATA_REQUEST_COMMAND) for MAC Data frames.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in] enable true to enable, false to disable.
 * @return Status code indicating success of the function call.
 *
 * Normally \ref RAIL_EVENT_IEEE802154_DATA_REQUEST_COMMAND is triggered only
 * for Ack-requesting MAC command frames.
 * Enabling this feature causes this event to also be triggered for MAC data
 * frames, at the same point in the packet as \ref
 * RAIL_IEEE802154_EnableEarlyFramePending() would trigger.
 * This feature is necessary to support the Thread Basil-Hayden Enhanced
 * Frame Pending feature in Version 0/1 frames, and to support Version 2
 * Data frames which require an Enhanced Ack.
 *
 * This function will fail if 802.15.4 hardware acceleration is not
 * currently enabled by calling \ref RAIL_IEEE802154_Init().
 * This setting may be changed at any time when 802.15.4 hardware acceleration
 * is enabled.
 */
RAIL_Status_t RAIL_IEEE802154_EnableDataFramePending(RAIL_Handle_t railHandle,
                                                     bool enable);

/**
 * Change the Frame Pending bit on the outgoing legacy Immediate Ack from
 * the default specified by
 * \ref RAIL_IEEE802154_Config_t::defaultFramePendingInOutgoingAcks.
 *
 * @param[in] railHandle A handle of RAIL instance
 * @return Status code indicating success of the function call.
 *
 * This function must only be called while processing the \ref
 * RAIL_EVENT_IEEE802154_DATA_REQUEST_COMMAND if the Ack
 * for this packet should go out with its Frame Pending bit set differently
 * than what was specified by
 * \ref RAIL_IEEE802154_Config_t::defaultFramePendingInOutgoingAcks.
 *
 * It's intended only for use with 802.15.4 legacy immediate Acks and
 * not 802.15.4E enhanced Acks.
 * This will return \ref RAIL_STATUS_INVALID_STATE if it is too late to
 * modify the outgoing Immediate Ack.
 */
RAIL_Status_t RAIL_IEEE802154_SetFramePending(RAIL_Handle_t railHandle);

/**
 * Alternate naming for function \ref RAIL_IEEE802154_SetFramePending
 * to depict it is used for changing the default setting specified by
 * \ref RAIL_IEEE802154_Config_t::defaultFramePendingInOutgoingAcks in
 * an outgoing Ack.
 */
 #define RAIL_IEEE802154_ToggleFramePending RAIL_IEEE802154_SetFramePending

/**
 * Get the source address of the incoming data request.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[out] pAddress A pointer to \ref RAIL_IEEE802154_Address_t structure
 *   to populate with source address information.
 * @return Status code indicating success of the function call.
 *
 * This function must only be called when handling the \ref
 * RAIL_EVENT_IEEE802154_DATA_REQUEST_COMMAND event. This will return
 * \ref RAIL_STATUS_INVALID_STATE if the address information is stale
 * (i.e., it is too late to affect the outgoing Ack).
 */
RAIL_Status_t RAIL_IEEE802154_GetAddress(RAIL_Handle_t railHandle,
                                         RAIL_IEEE802154_Address_t *pAddress);

/**
 * Write the Auto-Ack FIFO for the next outgoing 802.15.4E Enhanced Ack.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in] ackData A pointer to Ack data to transmit
 *   This may be NULL, in which case it's assumed the data has already
 *   been emplaced into the Ack buffer and RAIL just needs to be told
 *   how many bytes are there. Use \ref RAIL_GetAutoAckFifo() to get
 *   the address of RAIL's Auto-Ack buffer in RAM and its size.
 * @param[in] ackDataLen Length of Ack data, in bytes.
 *   If this exceeds \ref RAIL_AUTOACK_MAX_LENGTH the function
 *   will return \ref RAIL_STATUS_INVALID_PARAMETER.
 * @return Status code indicating success of the function call.
 *
 * This function sets the Auto-Ack data to use in acknowledging the frame
 * being received. It must only be called while processing the \ref
 * RAIL_EVENT_IEEE802154_DATA_REQUEST_COMMAND, and is intended for use
 * when packet information from \ref RAIL_GetRxIncomingPacketInfo()
 * indicates an 802.15.4E Enhanced Ack must be sent instead of a legacy
 * Immediate Ack. \ref RAIL_IEEE802154_ToggleFramePending() should not be
 * called for an Enhanced Ack; instead the Enhanced Ack's Frame Control
 * Field should have the Frame Pending bit set appropriately in its ackData.
 * This will return \ref RAIL_STATUS_INVALID_STATE if it is too late to
 * write the outgoing Ack -- a situation that will likely trigger
 * a \ref RAIL_EVENT_TXACK_UNDERFLOW event. When successful, the Enhanced
 * ackData will only be sent once. Subsequent packets needing an Enhanced
 * Ack will each need to call this function to write their Ack information.
 */
RAIL_Status_t RAIL_IEEE802154_WriteEnhAck(RAIL_Handle_t railHandle,
                                          const uint8_t *ackData,
                                          uint16_t ackDataLen);

/**
 * Set a separate RX packet to TX state transition turnaround time for
 * sending an Enhanced Ack.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in,out] pRxToEnhAckTx A pointer to the turnaround transition requested
 *   for Enhanced Acks. It will be updated with the actual time set.
 *   Requesting a time of 0 will sync the Enhanced Ack turnaround time with
 *   that used for immediate Acks (and output 0). Requesting a time of \ref
 *   RAIL_TRANSITION_TIME_KEEP will output the current Enhanced Ack timing
 *   parameter (0 if it is the same as that used for Immediate Acks).
 * @return Status code indicating a success of the function call.
 *   An error will not update the pRxToEnhAckTx output parameter.
 *
 * Normally Immediate and Enhanced Acks are both sent using the
 * \ref RAIL_IEEE802154_Config_t::timings rxToTx turnaround time.
 * If the stack needs more time to prepare an Enhanced Ack, it can
 * call this function after \ref RAIL_IEEE802154_Init() to set a
 * longer turnaround time used just for Enhanced Ack transmits.
 *
 * This function will fail on platforms that lack
 * \ref RAIL_IEEE802154_SUPPORTS_E_ENHANCED_ACK.
 */
RAIL_Status_t RAIL_IEEE802154_SetRxToEnhAckTx(RAIL_Handle_t railHandle,
                                              RAIL_TransitionTime_t *pRxToEnhAckTx);

/**
 * Convert RSSI into 802.15.4 Link Quality Indication (LQI) metric
 * compatible with the Silicon Labs Zigbee stack.
 *
 * @param[in] origLqi The original LQI, for example from
 *   \ref RAIL_RxPacketDetails_t::lqi.
 *   This parameter is not currently used but may be used in the future.
 * @param[in] rssiDbm The RSSI in dBm, for example from
 *   \ref RAIL_RxPacketDetails_t::rssi.
 * @return An LQI value (range 0..255 but not all intermediate values are
 *   possible) based on the rssiDbm and the chip's RSSI sensitivity range.
 *
 * This function is compatible with \ref RAIL_ConvertLqiCallback_t and
 * is suitable to pass to \ref RAIL_ConvertLqi().
 */
uint8_t RAIL_IEEE802154_ConvertRssiToLqi(uint8_t origLqi, int8_t rssiDbm);

/**
 * Convert RSSI into 802.15.4 Energy Detection (ED) metric
 * compatible with the Silicon Labs Zigbee stack.
 *
 * @param[in] rssiDbm The RSSI in dBm, for example from
 *   \ref RAIL_RxPacketDetails_t::rssi.
 * @return An Energy Detect value (range 0..255 but not all intermediate
 *   values are possible) based on the rssiDbm and the chip's RSSI
 *   sensitivity range.
 */
uint8_t RAIL_IEEE802154_ConvertRssiToEd(int8_t rssiDbm);

#endif//SLI_LIBRAIL_ALIAS

/**
 * @enum RAIL_IEEE802154_CcaMode_t
 * @brief Available CCA modes.
 */
RAIL_ENUM(RAIL_IEEE802154_CcaMode_t) {
  /**
   * RSSI-based CCA. CCA reports a busy medium upon detecting any energy
   * above \ref RAIL_CsmaConfig_t::ccaThreshold.
   */
  RAIL_IEEE802154_CCA_MODE_RSSI = 0,
  /**
   * Signal Identifier-based CCA. CCA reports a busy medium only upon the
   * detection of a signal compliant with this standard with the same modulation
   * and spreading characteristics of the PHY that is currently in use.
   */
  RAIL_IEEE802154_CCA_MODE_SIGNAL,
  /**
   * RSSI or signal identifier-based CCA. CCA reports a busy medium on
   * either detecting any energy above \ref RAIL_CsmaConfig_t.ccaThreshold
   * or detection of a signal compliant with this standard with the same
   * modulation and spreading characteristics of the PHY that is currently in use.
   */
  RAIL_IEEE802154_CCA_MODE_SIGNAL_OR_RSSI,
  /**
   * RSSI and signal identifier-based CCA. CCA reports a busy medium only
   * on detecting any energy above \ref RAIL_CsmaConfig_t.ccaThreshold of a
   * signal compliant with this standard with the same modulation and spreading
   * characteristics of the PHY that is currently in use.
   */
  RAIL_IEEE802154_CCA_MODE_SIGNAL_AND_RSSI,
  /**
   * ALOHA. Always transmit CCA=1. CCA always reports an idle medium.
   */
  RAIL_IEEE802154_CCA_MODE_ALWAYS_TRANSMIT,
  /**
   * Number of CCA modes. Must be last.
   */
  RAIL_IEEE802154_CCA_MODE_COUNT
};

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// Self-referencing defines minimize compiler complaints when using RAIL_ENUM
#define RAIL_IEEE802154_CCA_MODE_RSSI            ((RAIL_IEEE802154_CcaMode_t) RAIL_IEEE802154_CCA_MODE_RSSI)
#define RAIL_IEEE802154_CCA_MODE_SIGNAL          ((RAIL_IEEE802154_CcaMode_t) RAIL_IEEE802154_CCA_MODE_SIGNAL)
#define RAIL_IEEE802154_CCA_MODE_SIGNAL_OR_RSSI  ((RAIL_IEEE802154_CcaMode_t) RAIL_IEEE802154_CCA_MODE_SIGNAL_OR_RSSI)
#define RAIL_IEEE802154_CCA_MODE_SIGNAL_AND_RSSI ((RAIL_IEEE802154_CcaMode_t) RAIL_IEEE802154_CCA_MODE_SIGNAL_AND_RSSI)
#define RAIL_IEEE802154_CCA_MODE_ALWAYS_TRANSMIT ((RAIL_IEEE802154_CcaMode_t) RAIL_IEEE802154_CCA_MODE_ALWAYS_TRANSMIT)
#define RAIL_IEEE802154_CCA_MODE_COUNT           ((RAIL_IEEE802154_CcaMode_t) RAIL_IEEE802154_CCA_MODE_COUNT)
#endif//DOXYGEN_SHOULD_SKIP_THIS

/**
 * @enum RAIL_IEEE802154_SignalIdentifierMode_t
 * @brief Available Signal identifier modes.
 */
RAIL_ENUM(RAIL_IEEE802154_SignalIdentifierMode_t) {
  /** Disable signal detection mode. */
  RAIL_IEEE802154_SIGNAL_IDENTIFIER_MODE_DISABLE = 0,
  /** 2.4 GHz 802.15.4 signal detection mode. */
  RAIL_IEEE802154_SIGNAL_IDENTIFIER_MODE_154
};

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// Self-referencing defines minimize compiler complaints when using RAIL_ENUM
#define RAIL_IEEE802154_SIGNAL_IDENTIFIER_MODE_DISABLE ((RAIL_IEEE802154_SignalIdentifierMode_t) RAIL_IEEE802154_SIGNAL_IDENTIFIER_MODE_DISABLE)
#define RAIL_IEEE802154_SIGNAL_IDENTIFIER_MODE_154     ((RAIL_IEEE802154_SignalIdentifierMode_t) RAIL_IEEE802154_SIGNAL_IDENTIFIER_MODE_154)
#endif//DOXYGEN_SHOULD_SKIP_THIS

#ifndef SLI_LIBRAIL_ALIAS

/**
 * Configure signal identifier for 802.15.4 signal detection.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in] signalIdentifierMode Mode of signal identifier operation.
 *
 * This features allows detection of 2.4 GHz 802.15.4 signal on air. This
 * function must be called once before \ref RAIL_IEEE802154_EnableSignalDetection()
 * to configure and enable signal identifier.
 *
 * To enable event for signal detection \ref RAIL_ConfigEvents() must be called
 * for enabling \ref RAIL_EVENT_SIGNAL_DETECTED.
 *
 * This function is only supported by chips where
 * \ref RAIL_IEEE802154_SUPPORTS_SIGNAL_IDENTIFIER and
 * \ref RAIL_IEEE802154_SupportsSignalIdentifier() are true.
 *
 * @return Status code indicating success of the function call.
 */
RAIL_Status_t RAIL_IEEE802154_ConfigSignalIdentifier(RAIL_Handle_t railHandle,
                                                     RAIL_IEEE802154_SignalIdentifierMode_t signalIdentifierMode);

/**
 * Enable or disable signal identifier for 802.15.4 signal detection.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in] enable Signal detection is enabled if true, disabled if false.
 *
 * \ref RAIL_IEEE802154_ConfigSignalIdentifier() must be called once before calling
 * this function to configure and enable signal identifier.
 * Once a signal is detected signal detection will be turned off and this
 * function should be called to re-enable the signal detection without needing
 * to call \ref RAIL_IEEE802154_ConfigSignalIdentifier() if the signal identifier
 * is already configured and enabled.
 *
 * This function is only supported by chips where
 * \ref RAIL_IEEE802154_SUPPORTS_SIGNAL_IDENTIFIER and
 * \ref RAIL_IEEE802154_SupportsSignalIdentifier() are true.
 *
 * @return Status code indicating success of the function call.
 */
RAIL_Status_t RAIL_IEEE802154_EnableSignalDetection(RAIL_Handle_t railHandle,
                                                    bool enable);

/**
 * @brief Backward compatible name for the \ref
 *   RAIL_IEEE802154_EnableSignalDetection API.
 */
#define RAIL_IEEE802154_EnableSignalIdentifier RAIL_IEEE802154_EnableSignalDetection

/**
 * Set 802.15.4 CCA mode.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in] ccaMode Mode of CCA operation.
 *
 * This function sets the CCA mode \ref RAIL_IEEE802154_CcaMode_t.
 * If not called, RAIL_IEEE802154_CCA_MODE_RSSI (RSSI-based CCA) is used for CCA.
 *
 * In \ref RAIL_IEEE802154_CCA_MODE_SIGNAL, \ref RAIL_IEEE802154_CCA_MODE_SIGNAL_OR_RSSI and
 * \ref RAIL_IEEE802154_CCA_MODE_SIGNAL_AND_RSSI the signal identifier is enabled
 * for the duration of LBT. If previously enabled by
 * \ref RAIL_IEEE802154_ConfigSignalIdentifier(), the signal identifier will remain
 * active until triggered.
 *
 * This function is only supported by chips where
 * \ref RAIL_IEEE802154_SUPPORTS_SIGNAL_IDENTIFIER and
 * \ref RAIL_IEEE802154_SupportsSignalIdentifier() are true.
 *
 * @return Status code indicating success of the function call.
 *   An error should be returned if ccaMode is unsuppported on a given device.
 */
RAIL_Status_t RAIL_IEEE802154_ConfigCcaMode(RAIL_Handle_t railHandle,
                                            RAIL_IEEE802154_CcaMode_t ccaMode);

#ifndef DOXYGEN_UNDOCUMENTED
/**
 * Allow certain malformed MAC Header frames to be received.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in] allow true to allow, false to disallow.
 * @return Status code indicating success of the function call.
 *
 * When allowed, certain MAC header formats that 802.15.4 deems
 * illegal will be received rather than filtered. This is to
 * support interoperablity with an old spec-violating 802.15.4
 * peer and is only supported on certain EFR32 Series 2 platforms.
 *
 * @note \ref RAIL_IEEE802154_SetPanCoordinator() must also be
 *   enabled to receive malformed frames lacking destination
 *   address information.
 */
RAIL_Status_t RAIL_IEEE802154_AllowMalformed(RAIL_Handle_t railHandle,
                                             bool allow);
#endif //DOXYGEN_UNDOCUMENTED

/**
 * Configure RX channel switching for 802.15.4.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[in] pConfig A pointer to \ref RAIL_IEEE802154_RxChannelSwitchingCfg_t
 *  structure. NULL will disable any switching previously set up. The feature can
 *  also be disabled by disabling \ref RAIL_RX_OPTION_CHANNEL_SWITCHING.
 * @return Status code indicating success of the function call.
 *   For series 3 parts:
 *     return \ref RAIL_STATUS_INVALID_STATE if IEEE 802.15.4 is not enabled via
 *       \ref RAIL_IEEE802154_Init(),
 *     return RAIL_STATUS_NO_ERROR otherwise.
 *
 * This function configures RX channel switching, allowing reception of 2.4 GHz
 * 802.15.4 signals on two different radio channels within the same PHY.
 * This function should be called once before \ref RAIL_StartRx() and/or
 * enabling \ref RAIL_RX_OPTION_CHANNEL_SWITCHING.
 *
 * When \ref RAIL_RX_OPTION_CHANNEL_SWITCHING is enabled, channel switching
 * will occur during normal listening but is suspended when starting any kind
 * of transmit, including scheduled or CSMA transmits.
 * It remains suspended after a \ref RAIL_TX_OPTION_WAIT_FOR_ACK
 * transmit until the Ack is received or times out.
 *
 * When \ref RAIL_RX_OPTION_CHANNEL_SWITCHING is disabled after switching
 * has been active, the radio could be left listening on either channel,
 * so the application should call \ref RAIL_StartRx() to put it on the
 * desired non-switching channel.
 *
 * @note Switching is cancelled on any PHY change, so this function would
 *   need to be re-called to reestablish switching after such a change.
 *   When RX channel switching is active, receive sensitivity and
 *   performance are slightly impacted.
 *
 * @note Switching is stopped on any channel change that is not from
 *   \ref RAIL_IEEE802154_RxChannelSwitchingCfg_t but is resumed
 *   on configuring back the appropriate channel.
 *
 * @parblock
 * @note For series 2 parts:
 *   If the two channels are same, the function behaves the same as if
 *     pConfig was NULL.
 * @note IEEE 802.15.4 must be enabled via \ref RAIL_IEEE802154_Init(), and the
 *     radio must be in the idle state when configuring RX channel switching.
 *     A DMA channel must be allocated with \ref RAIL_UseDma() or by
 *     incorporating the \ref rail_util_dma plugin; otherwise this API will
 *     return \ref RAIL_STATUS_INVALID_CALL.
 *     This feature also requires a PRS channel, internally allocated by the
 *     RAIL library, to use and hold onto for future use. If no PRS channel is
 *     available, the function returns \ref RAIL_STATUS_INVALID_PARAMETER.
 * @note This function internally uses \ref RAIL_EnableCacheSynthCal() to
 *     enable/disable the sequencer cache to store the synth calibration value.
 * @warning For series 2 parts, this function relies on LDMA access and RAIL is
 *   meant to run in TrustZone non-secure world, it is not supported if LDMA
 *   is configured as secure peripheral and it will return
 *   \ref RAIL_STATUS_INVALID_CALL.
 * @endparblock
 *
 * @parblock
 * @note For series 3 parts:
 * @note IEEE 802.15.4 must be enabled via \ref RAIL_IEEE802154_Init().
 * @note If the two channels are same, the function will do channel switching
 *   on a single frequency but will still duty cycle if PHY allows it.
 *
 * @note \ref RAIL_RX_OPTION_CHANNEL_SWITCHING is only considered when
 *   \ref RAIL_StartRx() or \ref RAIL_PrepareChannel() is called, not instantly.
 * @endparblock
 */
RAIL_Status_t RAIL_IEEE802154_ConfigRxChannelSwitching(RAIL_Handle_t railHandle,
                                                       const RAIL_IEEE802154_RxChannelSwitchingCfg_t *pConfig);

/** @} */ // end of IEEE802.15.4

/// @addtogroup Calibration
/// @brief IEEE802154 protocol-specific APIs for calibrating the radio.
/// @{

/**
 * Calibrate image rejection for IEEE 802.15.4 2.4 GHz.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[out] imageRejection A pointer to the result of the image rejection calibration.
 * @return Status code indicating success of the function call.
 *
 * Some chips have protocol-specific image rejection calibrations programmed
 * into their flash. This function will either get the value from flash and
 * apply it, or run the image rejection algorithm to find the value.
 */
RAIL_Status_t RAIL_IEEE802154_CalibrateIr2p4Ghz(RAIL_Handle_t railHandle,
                                                uint32_t *imageRejection);

#endif//SLI_LIBRAIL_ALIAS

/**
 * Calibrate image rejection for IEEE 802.15.4 915 MHz and 868 MHz.
 *
 * @param[in] railHandle A RAIL instance handle.
 * @param[out] imageRejection The result of the image rejection calibration.
 * @return Status code indicating success of the function call.
 *
 * Some chips have protocol-specific image rejection calibrations programmed
 * into their flash. This function will either get the value from flash and
 * apply it, or run the image rejection algorithm to find the value.
 *
 * @deprecated Please use \ref RAIL_CalibrateIrAlt instead.
 */
RAIL_Status_t RAIL_IEEE802154_CalibrateIrSubGhz(RAIL_Handle_t railHandle,
                                                uint32_t *imageRejection);

/// @} // End of group Calibration

#ifdef __cplusplus
}
#endif

#ifdef RAIL_INTERNAL_BUILD
#include "rail_ieee802154_internal.h"
#endif

#endif // __RAIL_IEEE802154_H__
