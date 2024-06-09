//------------------------------------------------------------------------------
// Copyright 2012 (c) Silicon Laboratories Inc.
//
// SPDX-License-Identifier: Zlib
//
// This siHAL software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//------------------------------------------------------------------------------
/// @file SI32_UART_B_Type.h
//
// Script: 0.59
// HAL Source: 0.7
// Version: 1

#ifndef __SI32_UART_B_TYPE_H__
#define __SI32_UART_B_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_UART_B_Registers.h"
#include "SI32_UART_B_Support.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_UART_B_initialize(SI32_UART_B_Type* basePointer,
///      uint32_t config,
///      uint32_t mode,
///      uint32_t flowcn,
///      uint32_t control,
///      uint32_t ipdelay,
///      uint32_t baudrate,
///      uint32_t fifocn,
///      uint32_t clkdiv)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  config
///  Valid range is 32 bits.
///  Write to CONFIG register.
///
/// @param[in]
///  mode
///  Valid range is 32 bits.
///  Write to MODE register.
///
/// @param[in]
///  flowcn
///  Valid range is 32 bits.
///  Write to FLOWCN register.
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///  Write to CONTROL register.
///
/// @param[in]
///  ipdelay
///  Valid range is 8 bits.
///  Write to IPDELAY register.
///
/// @param[in]
///  baudrate
///  Valid range is 32 bits.
///  Write to BAUDRATE register.
///
/// @param[in]
///  fifocn
///  Valid range is 32 bits.
///  Write to FIFOCN register.
///
/// @param[in]
///  clkdiv
///  Valid range is 32 bits.
///  Write to CLKDIV register.
///
void
_SI32_UART_B_initialize(SI32_UART_B_Type* /*basePointer*/,
   uint32_t, /*config*/
   uint32_t, /*mode*/
   uint32_t, /*flowcn*/
   uint32_t, /*control*/
   uint32_t, /*ipdelay*/
   uint32_t, /*baudrate*/
   uint32_t, /*fifocn*/
   uint32_t /*clkdiv*/);
///
/// @def SI32_UART_B_initialize(basePointer, config, mode, flowcn, control, ipdelay, baudrate, fifocn, clkdiv)
#define SI32_UART_B_initialize(basePointer, config, mode, flowcn, control, ipdelay, baudrate, fifocn, clkdiv) \
   _SI32_UART_B_initialize(basePointer, config, mode, flowcn, control, ipdelay, baudrate, fifocn, clkdiv) 


/// @fn _SI32_UART_B_write_config(SI32_UART_B_Type* basePointer,
///      uint32_t config)
///
/// @brief
/// Write to CONFIG register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  config
///  Valid range is 32 bits.
///
void
_SI32_UART_B_write_config(SI32_UART_B_Type* /*basePointer*/,
   uint32_t /*config*/);
///
/// @def SI32_UART_B_write_config(basePointer, config)
#define SI32_UART_B_write_config(basePointer, config) \
   (basePointer->CONFIG.U32 = config)


/// @fn _SI32_UART_B_read_config(SI32_UART_B_Type* basePointer)
///
/// @brief
/// Reads CONFIG register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_UART_B_read_config(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_read_config(basePointer)
#define SI32_UART_B_read_config(basePointer) \
(basePointer->CONFIG.U32)


/// @fn _SI32_UART_B_enable_rx_start_bit(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_rx_start_bit(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_rx_start_bit(basePointer)
#define SI32_UART_B_enable_rx_start_bit(basePointer) \
   (basePointer->CONFIG_SET = SI32_UART_B_CONFIG_RSTRTEN_ENABLED_U32)


/// @fn _SI32_UART_B_disable_rx_start_bit(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_rx_start_bit(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_rx_start_bit(basePointer)
#define SI32_UART_B_disable_rx_start_bit(basePointer) \
   (basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_RSTRTEN_MASK)


/// @fn _SI32_UART_B_enable_rx_parity_bit(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_rx_parity_bit(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_rx_parity_bit(basePointer)
#define SI32_UART_B_enable_rx_parity_bit(basePointer) \
   (basePointer->CONFIG_SET = SI32_UART_B_CONFIG_RPAREN_ENABLED_U32)


/// @fn _SI32_UART_B_disable_rx_parity_bit(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_rx_parity_bit(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_rx_parity_bit(basePointer)
#define SI32_UART_B_disable_rx_parity_bit(basePointer) \
   (basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_RPAREN_MASK)


/// @fn _SI32_UART_B_enable_rx_stop_bit(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_rx_stop_bit(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_rx_stop_bit(basePointer)
#define SI32_UART_B_enable_rx_stop_bit(basePointer) \
   (basePointer->CONFIG_SET = SI32_UART_B_CONFIG_RSTPEN_ENABLED_U32)


/// @fn _SI32_UART_B_disable_rx_stop_bit(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_rx_stop_bit(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_rx_stop_bit(basePointer)
#define SI32_UART_B_disable_rx_stop_bit(basePointer) \
   (basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_RSTPEN_MASK)


/// @fn _SI32_UART_B_select_rx_stop_bits(SI32_UART_B_Type* basePointer,
///      SI32_UART_B_STOP_BITS_Enum_Type bits)
///
/// @brief
/// Selects the number of receive stop bits to: 0 = 0.5 stop bit, 1 = 1
/// stop bit, 2 = 1.5 stop bits, 3 = 2 stop bits.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  bits
///  Valid range is 2 bits.
///
void
_SI32_UART_B_select_rx_stop_bits(SI32_UART_B_Type* /*basePointer*/,
   SI32_UART_B_STOP_BITS_Enum_Type /*bits*/);
///
/// @def SI32_UART_B_select_rx_stop_bits(basePointer, bits)
#define SI32_UART_B_select_rx_stop_bits(basePointer, bits) do{  \
   basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_RSTPMD_MASK;\
   basePointer->CONFIG_SET = bits << SI32_UART_B_CONFIG_RSTPMD_SHIFT;\
} while(0)


/// @fn _SI32_UART_B_select_rx_parity(SI32_UART_B_Type* basePointer,
///      SI32_UART_B_PARITY_Enum_Type parity)
///
/// @brief
/// Selects the receive parity to: 0 = odd, 1 = even, 2 = mark, 3 = space.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  parity
///  Valid range is 2 bits.
///
void
_SI32_UART_B_select_rx_parity(SI32_UART_B_Type* /*basePointer*/,
   SI32_UART_B_PARITY_Enum_Type /*parity*/);
///
/// @def SI32_UART_B_select_rx_parity(basePointer, parity)
#define SI32_UART_B_select_rx_parity(basePointer, parity) do{  \
   basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_RPARMD_MASK;\
   basePointer->CONFIG_SET = parity << SI32_UART_B_CONFIG_RPARMD_SHIFT;\
} while(0)


/// @fn _SI32_UART_B_select_rx_data_length(SI32_UART_B_Type* basePointer,
///      SI32_UART_B_DATA_LENGTH_Enum_Type length)
///
/// @brief
/// Selects the receiver data length to: 5 = 5 bits, 6 = 6 bits, 7 = 7
/// bits, 8 = 8 bits, 9 = 9 bits, 10 = 9 bit fixed mode.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  length
///  Valid range is 5 to 10.
///
void
_SI32_UART_B_select_rx_data_length(SI32_UART_B_Type* /*basePointer*/,
   SI32_UART_B_DATA_LENGTH_Enum_Type /*length*/);
///
/// @def SI32_UART_B_select_rx_data_length(basePointer, length)
#define SI32_UART_B_select_rx_data_length(basePointer, length) do{  \
   basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_RDATLN_MASK;\
   basePointer->CONFIG_SET = (length - 5) << SI32_UART_B_CONFIG_RDATLN_SHIFT;\
} while(0)


/// @fn _SI32_UART_B_enable_rx_irda_mode(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_rx_irda_mode(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_rx_irda_mode(basePointer)
#define SI32_UART_B_enable_rx_irda_mode(basePointer) \
   (basePointer->CONFIG_SET = SI32_UART_B_CONFIG_RIRDAEN_ENABLED_U32)


/// @fn _SI32_UART_B_disable_rx_irda_mode(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_rx_irda_mode(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_rx_irda_mode(basePointer)
#define SI32_UART_B_disable_rx_irda_mode(basePointer) \
   (basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_RIRDAEN_MASK)


/// @fn _SI32_UART_B_enable_rx_signal_inversion(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_rx_signal_inversion(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_rx_signal_inversion(basePointer)
#define SI32_UART_B_enable_rx_signal_inversion(basePointer) \
   (basePointer->CONFIG_SET = SI32_UART_B_CONFIG_RINVEN_ENABLED_U32)


/// @fn _SI32_UART_B_disable_rx_signal_inversion(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_rx_signal_inversion(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_rx_signal_inversion(basePointer)
#define SI32_UART_B_disable_rx_signal_inversion(basePointer) \
   (basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_RINVEN_MASK)


/// @fn _SI32_UART_B_enable_tx_start_bit(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_tx_start_bit(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_tx_start_bit(basePointer)
#define SI32_UART_B_enable_tx_start_bit(basePointer) \
   (basePointer->CONFIG_SET = SI32_UART_B_CONFIG_TSTRTEN_ENABLED_U32)


/// @fn _SI32_UART_B_disable_tx_start_bit(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_tx_start_bit(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_tx_start_bit(basePointer)
#define SI32_UART_B_disable_tx_start_bit(basePointer) \
   (basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_TSTRTEN_MASK)


/// @fn _SI32_UART_B_enable_tx_parity_bit(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_tx_parity_bit(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_tx_parity_bit(basePointer)
#define SI32_UART_B_enable_tx_parity_bit(basePointer) \
   (basePointer->CONFIG_SET = SI32_UART_B_CONFIG_TPAREN_ENABLED_U32)


/// @fn _SI32_UART_B_disable_tx_parity_bit(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_tx_parity_bit(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_tx_parity_bit(basePointer)
#define SI32_UART_B_disable_tx_parity_bit(basePointer) \
   (basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_TPAREN_MASK)


/// @fn _SI32_UART_B_enable_tx_stop_bit(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_tx_stop_bit(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_tx_stop_bit(basePointer)
#define SI32_UART_B_enable_tx_stop_bit(basePointer) \
   (basePointer->CONFIG_SET = SI32_UART_B_CONFIG_TSTPEN_ENABLED_U32)


/// @fn _SI32_UART_B_disable_tx_stop_bit(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_tx_stop_bit(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_tx_stop_bit(basePointer)
#define SI32_UART_B_disable_tx_stop_bit(basePointer) \
   (basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_TSTPEN_MASK)


/// @fn _SI32_UART_B_select_tx_stop_bits(SI32_UART_B_Type* basePointer,
///      SI32_UART_B_STOP_BITS_Enum_Type bits)
///
/// @brief
/// Sets the number of transmit stop bits to: 0 = 0.5 stop bit, 1 = 1 stop
/// bit, 2 = 1.5 stop bits, 3 = 2 stop bits.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  bits
///  Valid range is 2 bits.
///
void
_SI32_UART_B_select_tx_stop_bits(SI32_UART_B_Type* /*basePointer*/,
   SI32_UART_B_STOP_BITS_Enum_Type /*bits*/);
///
/// @def SI32_UART_B_select_tx_stop_bits(basePointer, bits)
#define SI32_UART_B_select_tx_stop_bits(basePointer, bits) do{  \
   basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_TSTPMD_MASK;\
   basePointer->CONFIG_SET = bits << SI32_UART_B_CONFIG_TSTPMD_SHIFT;\
} while(0)


/// @fn _SI32_UART_B_select_tx_parity(SI32_UART_B_Type* basePointer,
///      SI32_UART_B_PARITY_Enum_Type parity)
///
/// @brief
/// Sets the transmit parity to: 0 = odd, 1 = even, 2 = mark, 3 = space.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  parity
///  Valid range is 2 bits.
///
void
_SI32_UART_B_select_tx_parity(SI32_UART_B_Type* /*basePointer*/,
   SI32_UART_B_PARITY_Enum_Type /*parity*/);
///
/// @def SI32_UART_B_select_tx_parity(basePointer, parity)
#define SI32_UART_B_select_tx_parity(basePointer, parity) do{  \
	basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_TPARMD_MASK;\
   basePointer->CONFIG_SET = parity << SI32_UART_B_CONFIG_TPARMD_SHIFT;\
} while(0)


/// @fn _SI32_UART_B_select_tx_data_length(SI32_UART_B_Type* basePointer,
///      SI32_UART_B_DATA_LENGTH_Enum_Type length)
///
/// @brief
/// Sets the transmit data length to: 5 = 5 bits, 6 = 6 bits, 7 = 7 bits,
/// 8 = 8 bits, 9 = 9 bits, 10 = 9 bit fixed mode.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  length
///  Valid range is 5 to 10.
///
void
_SI32_UART_B_select_tx_data_length(SI32_UART_B_Type* /*basePointer*/,
   SI32_UART_B_DATA_LENGTH_Enum_Type /*length*/);
///
/// @def SI32_UART_B_select_tx_data_length(basePointer, length)
#define SI32_UART_B_select_tx_data_length(basePointer, length) do{  \
	basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_TDATLN_MASK;\
   basePointer->CONFIG_SET = (length - 5) << SI32_UART_B_CONFIG_TDATLN_SHIFT;\
} while(0)


/// @fn _SI32_UART_B_enable_tx_irda_mode(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_tx_irda_mode(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_tx_irda_mode(basePointer)
#define SI32_UART_B_enable_tx_irda_mode(basePointer) \
   (basePointer->CONFIG_SET = SI32_UART_B_CONFIG_TIRDAEN_ENABLED_U32)


/// @fn _SI32_UART_B_disable_tx_irda_mode(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_tx_irda_mode(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_tx_irda_mode(basePointer)
#define SI32_UART_B_disable_tx_irda_mode(basePointer) \
   (basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_TIRDAEN_MASK)


/// @fn _SI32_UART_B_enable_tx_signal_inversion(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_tx_signal_inversion(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_tx_signal_inversion(basePointer)
#define SI32_UART_B_enable_tx_signal_inversion(basePointer) \
   (basePointer->CONFIG_SET = SI32_UART_B_CONFIG_TINVEN_ENABLED_U32)


/// @fn _SI32_UART_B_disable_tx_signal_inversion(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_tx_signal_inversion(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_tx_signal_inversion(basePointer)
#define SI32_UART_B_disable_tx_signal_inversion(basePointer) \
   (basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_TINVEN_MASK)


/// @fn _SI32_UART_B_write_mode(SI32_UART_B_Type* basePointer,
///      uint32_t mode)
///
/// @brief
/// Write to MODE register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  mode
///  Valid range is 32 bits.
///
void
_SI32_UART_B_write_mode(SI32_UART_B_Type* /*basePointer*/,
   uint32_t /*mode*/);
///
/// @def SI32_UART_B_write_mode(basePointer, mode)
#define SI32_UART_B_write_mode(basePointer, mode) \
   (basePointer->MODE.U32 = mode)


/// @fn _SI32_UART_B_read_mode(SI32_UART_B_Type* basePointer)
///
/// @brief
/// Reads MODE register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_UART_B_read_mode(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_read_mode(basePointer)
#define SI32_UART_B_read_mode(basePointer) \
(basePointer->MODE.U32)


/// @fn _SI32_UART_B_select_rtc_clock_mode(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_select_rtc_clock_mode(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_select_rtc_clock_mode(basePointer)
#define SI32_UART_B_select_rtc_clock_mode(basePointer) do{  \
	basePointer->MODE_SET = SI32_UART_B_MODE_RTCCKMD_RTC0TCLK_U32;\
} while(0)


/// @fn _SI32_UART_B_select_apb_clock_mode(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_select_apb_clock_mode(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_select_apb_clock_mode(basePointer)
#define SI32_UART_B_select_apb_clock_mode(basePointer) \
   (basePointer->MODE_CLR = SI32_UART_B_MODE_RTCCKMD_MASK)


/// @fn _SI32_UART_B_enter_rtc_baud_rate_mode(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enter_rtc_baud_rate_mode(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enter_rtc_baud_rate_mode(basePointer)
#define SI32_UART_B_enter_rtc_baud_rate_mode(basePointer) \
   (basePointer->MODE_SET = SI32_UART_B_MODE_RTCBDMD_ENABLED_U32)


/// @fn _SI32_UART_B_exit_rtc_baud_rate_mode(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_exit_rtc_baud_rate_mode(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_exit_rtc_baud_rate_mode(basePointer)
#define SI32_UART_B_exit_rtc_baud_rate_mode(basePointer) \
   (basePointer->MODE_CLR = SI32_UART_B_MODE_RTCBDMD_MASK)


/// @fn _SI32_UART_B_select_internal_clock_on_demand(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_select_internal_clock_on_demand(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_select_internal_clock_on_demand(basePointer)
#define SI32_UART_B_select_internal_clock_on_demand(basePointer) \
   (basePointer->MODE_CLR = SI32_UART_B_MODE_FORCECLK_MASK)


/// @fn _SI32_UART_B_select_internal_clock_always_on(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_select_internal_clock_always_on(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_select_internal_clock_always_on(basePointer)
#define SI32_UART_B_select_internal_clock_always_on(basePointer) \
   (basePointer->MODE_SET = SI32_UART_B_MODE_FORCECLK_ENABLED_U32)


/// @fn _SI32_UART_B_is_clock_switch_busy(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_UART_B_is_clock_switch_busy(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_is_clock_switch_busy(basePointer)
#define SI32_UART_B_is_clock_switch_busy(basePointer) \
((bool)(basePointer->MODE.CLKBUSY))


/// @fn _SI32_UART_B_enable_rx_clock_switch(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_rx_clock_switch(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_rx_clock_switch(basePointer)
#define SI32_UART_B_enable_rx_clock_switch(basePointer) \
   (basePointer->MODE_SET = SI32_UART_B_MODE_RXCLKSW_ENABLED_U32)


/// @fn _SI32_UART_B_disable_rx_clock_switch(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_rx_clock_switch(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_rx_clock_switch(basePointer)
#define SI32_UART_B_disable_rx_clock_switch(basePointer) \
   (basePointer->MODE_CLR = SI32_UART_B_MODE_RXCLKSW_MASK)


/// @fn _SI32_UART_B_enable_tx_clock_switch(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_tx_clock_switch(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_tx_clock_switch(basePointer)
#define SI32_UART_B_enable_tx_clock_switch(basePointer) \
   (basePointer->MODE_SET = SI32_UART_B_MODE_TXCLKSW_ENABLED_U32)


/// @fn _SI32_UART_B_disable_tx_clock_switch(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_tx_clock_switch(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_tx_clock_switch(basePointer)
#define SI32_UART_B_disable_tx_clock_switch(basePointer) \
   (basePointer->MODE_CLR = SI32_UART_B_MODE_TXCLKSW_MASK)


/// @fn _SI32_UART_B_enable_stall_in_debug_mode(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_stall_in_debug_mode(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_stall_in_debug_mode(basePointer)
#define SI32_UART_B_enable_stall_in_debug_mode(basePointer) \
   (basePointer->MODE_SET = SI32_UART_B_MODE_DBGMD_HALT_U32)


/// @fn _SI32_UART_B_disable_stall_in_debug_mode(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_stall_in_debug_mode(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_stall_in_debug_mode(basePointer)
#define SI32_UART_B_disable_stall_in_debug_mode(basePointer) \
   (basePointer->MODE_CLR = SI32_UART_B_MODE_DBGMD_MASK)


/// @fn _SI32_UART_B_exit_loopback_mode(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_exit_loopback_mode(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_exit_loopback_mode(basePointer)
#define SI32_UART_B_exit_loopback_mode(basePointer) \
   (basePointer->MODE_CLR = SI32_UART_B_MODE_LBMD_MASK)


/// @fn _SI32_UART_B_enter_receive_loopback_mode(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enter_receive_loopback_mode(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enter_receive_loopback_mode(basePointer)
#define SI32_UART_B_enter_receive_loopback_mode(basePointer) do{  \
	basePointer->MODE_CLR = SI32_UART_B_MODE_LBMD_MASK;\
   basePointer->MODE_SET = SI32_UART_B_MODE_LBMD_RXONLY_U32;\
} while(0)


/// @fn _SI32_UART_B_enter_transmit_loopback_mode(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enter_transmit_loopback_mode(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enter_transmit_loopback_mode(basePointer)
#define SI32_UART_B_enter_transmit_loopback_mode(basePointer) do{  \
	basePointer->MODE_CLR = SI32_UART_B_MODE_LBMD_MASK;\
   basePointer->MODE_SET = SI32_UART_B_MODE_LBMD_TXONLY_U32;\
} while(0)


/// @fn _SI32_UART_B_enter_full_loopback_mode(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enter_full_loopback_mode(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enter_full_loopback_mode(basePointer)
#define SI32_UART_B_enter_full_loopback_mode(basePointer) \
   (basePointer->MODE_SET = SI32_UART_B_MODE_LBMD_BOTH_U32)


/// @fn _SI32_UART_B_enter_half_duplex_mode(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enter_half_duplex_mode(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enter_half_duplex_mode(basePointer)
#define SI32_UART_B_enter_half_duplex_mode(basePointer) \
   (basePointer->MODE_SET = SI32_UART_B_MODE_DUPLEXMD_HALF_DUPLEX_U32)


/// @fn _SI32_UART_B_enter_full_duplex_mode(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enter_full_duplex_mode(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enter_full_duplex_mode(basePointer)
#define SI32_UART_B_enter_full_duplex_mode(basePointer) \
   (basePointer->MODE_CLR = SI32_UART_B_MODE_DUPLEXMD_MASK)


/// @fn _SI32_UART_B_disable_idle_tristate(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_idle_tristate(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_idle_tristate(basePointer)
#define SI32_UART_B_disable_idle_tristate(basePointer) \
   (basePointer->MODE_CLR = SI32_UART_B_MODE_ITSEN_MASK)


/// @fn _SI32_UART_B_enable_idle_tristate(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_idle_tristate(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_idle_tristate(basePointer)
#define SI32_UART_B_enable_idle_tristate(basePointer) \
   (basePointer->MODE_SET = SI32_UART_B_MODE_ITSEN_ENABLED_U32)


/// @fn _SI32_UART_B_write_flowcn(SI32_UART_B_Type* basePointer,
///      uint32_t flowcn)
///
/// @brief
/// Write to FLOWCN register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  flowcn
///  Valid range is 32 bits.
///
void
_SI32_UART_B_write_flowcn(SI32_UART_B_Type* /*basePointer*/,
   uint32_t /*flowcn*/);
///
/// @def SI32_UART_B_write_flowcn(basePointer, flowcn)
#define SI32_UART_B_write_flowcn(basePointer, flowcn) \
   (basePointer->FLOWCN.U32 = flowcn)


/// @fn _SI32_UART_B_read_flowcn(SI32_UART_B_Type* basePointer)
///
/// @brief
/// Reads FLOWCN register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_UART_B_read_flowcn(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_read_flowcn(basePointer)
#define SI32_UART_B_read_flowcn(basePointer) \
(basePointer->FLOWCN.U32)


/// @fn _SI32_UART_B_read_rx_input(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_UART_B_read_rx_input(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_read_rx_input(basePointer)
#define SI32_UART_B_read_rx_input(basePointer) \
((bool)(basePointer->FLOWCN.RX))


/// @fn _SI32_UART_B_enable_tx_output(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_tx_output(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_tx_output(basePointer)
#define SI32_UART_B_enable_tx_output(basePointer) \
   (basePointer->FLOWCN_SET = SI32_UART_B_FLOWCN_TXOEN_ENABLED_U32)


/// @fn _SI32_UART_B_disable_tx_output(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_tx_output(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_tx_output(basePointer)
#define SI32_UART_B_disable_tx_output(basePointer) \
   (basePointer->FLOWCN_CLR = SI32_UART_B_FLOWCN_TXOEN_MASK)


/// @fn _SI32_UART_B_read_tx_output(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_UART_B_read_tx_output(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_read_tx_output(basePointer)
#define SI32_UART_B_read_tx_output(basePointer) \
((bool)(basePointer->FLOWCN.TX))


/// @fn _SI32_UART_B_clear_tx(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_clear_tx(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_clear_tx(basePointer)
#define SI32_UART_B_clear_tx(basePointer) \
   (basePointer->FLOWCN_CLR = SI32_UART_B_FLOWCN_TX_MASK)


/// @fn _SI32_UART_B_set_tx(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_set_tx(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_set_tx(basePointer)
#define SI32_UART_B_set_tx(basePointer) \
   (basePointer->FLOWCN_SET = SI32_UART_B_FLOWCN_TX_HIGH_U32)


/// @fn _SI32_UART_B_select_tx_irda_pulse_width(SI32_UART_B_Type* basePointer,
///      SI32_UART_B_IRDA_PULSE_WIDTH_Enum_Type width)
///
/// @brief
/// Selects the transmitter IrDA pulse width to: 0 = 1/16th of a bit
/// period, 1 = 1/8th of a bit period, 2 = 3/16th of a bit period, 3 =
/// 1/4th of a bit period.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  width
///  Valid range is 2 bits.
///
void
_SI32_UART_B_select_tx_irda_pulse_width(SI32_UART_B_Type* /*basePointer*/,
   SI32_UART_B_IRDA_PULSE_WIDTH_Enum_Type /*width*/);
///
/// @def SI32_UART_B_select_tx_irda_pulse_width(basePointer, width)
#define SI32_UART_B_select_tx_irda_pulse_width(basePointer, width) do{  \
	basePointer->FLOWCN_CLR = SI32_UART_B_FLOWCN_TIRDAPW_MASK;\
   basePointer->FLOWCN_SET = width << SI32_UART_B_FLOWCN_TIRDAPW_SHIFT;\
} while(0)


/// @fn _SI32_UART_B_write_control(SI32_UART_B_Type* basePointer,
///      uint32_t control)
///
/// @brief
/// Write to CONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///
void
_SI32_UART_B_write_control(SI32_UART_B_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_UART_B_write_control(basePointer, control)
#define SI32_UART_B_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_UART_B_read_control(SI32_UART_B_Type* basePointer)
///
/// @brief
/// Reads CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_UART_B_read_control(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_read_control(basePointer)
#define SI32_UART_B_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_UART_B_is_rx_frame_error_interrupt_pending(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_UART_B_is_rx_frame_error_interrupt_pending(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_is_rx_frame_error_interrupt_pending(basePointer)
#define SI32_UART_B_is_rx_frame_error_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.RFRMERI))


/// @fn _SI32_UART_B_clear_rx_frame_error_interrupt(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_clear_rx_frame_error_interrupt(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_clear_rx_frame_error_interrupt(basePointer)
#define SI32_UART_B_clear_rx_frame_error_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_RFRMERI_MASK)


/// @fn _SI32_UART_B_is_rx_parity_error_interrupt_pending(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_UART_B_is_rx_parity_error_interrupt_pending(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_is_rx_parity_error_interrupt_pending(basePointer)
#define SI32_UART_B_is_rx_parity_error_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.RPARERI))


/// @fn _SI32_UART_B_clear_rx_parity_error_interrupt(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_clear_rx_parity_error_interrupt(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_clear_rx_parity_error_interrupt(basePointer)
#define SI32_UART_B_clear_rx_parity_error_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_RPARERI_MASK)


/// @fn _SI32_UART_B_is_rx_overrun_interrupt_pending(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_UART_B_is_rx_overrun_interrupt_pending(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_is_rx_overrun_interrupt_pending(basePointer)
#define SI32_UART_B_is_rx_overrun_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.ROREI))


/// @fn _SI32_UART_B_clear_rx_overrun_error_interrupt(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_clear_rx_overrun_error_interrupt(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_clear_rx_overrun_error_interrupt(basePointer)
#define SI32_UART_B_clear_rx_overrun_error_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_ROREI_MASK)


/// @fn _SI32_UART_B_is_rx_data_request_interrupt_pending(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_UART_B_is_rx_data_request_interrupt_pending(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_is_rx_data_request_interrupt_pending(basePointer)
#define SI32_UART_B_is_rx_data_request_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.RDREQI))


/// @fn _SI32_UART_B_clear_rx_data_request_interrupt(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_clear_rx_data_request_interrupt(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_clear_rx_data_request_interrupt(basePointer)
#define SI32_UART_B_clear_rx_data_request_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_RDREQI_MASK)


/// @fn _SI32_UART_B_enable_rx_error_interrupts(SI32_UART_B_Type* basePointer)
///
/// @brief
/// Enables the receive overrun error, frame error, and parity error
/// interrupts.
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_rx_error_interrupts(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_rx_error_interrupts(basePointer)
#define SI32_UART_B_enable_rx_error_interrupts(basePointer) \
   (basePointer->CONTROL_SET = SI32_UART_B_CONTROL_RERIEN_ENABLED_U32)


/// @fn _SI32_UART_B_disable_rx_error_interrupts(SI32_UART_B_Type* basePointer)
///
/// @brief
/// Disables the receive overrun error, frame error, and parity error
/// interrupts.
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_rx_error_interrupts(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_rx_error_interrupts(basePointer)
#define SI32_UART_B_disable_rx_error_interrupts(basePointer) \
   (basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_RERIEN_MASK)


/// @fn _SI32_UART_B_is_rx_error_interrupts_enabled(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_UART_B_is_rx_error_interrupts_enabled(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_is_rx_error_interrupts_enabled(basePointer)
#define SI32_UART_B_is_rx_error_interrupts_enabled(basePointer) \
((bool)(basePointer->CONTROL.RERIEN))


/// @fn _SI32_UART_B_enable_rx_data_request_interrupt(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_rx_data_request_interrupt(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_rx_data_request_interrupt(basePointer)
#define SI32_UART_B_enable_rx_data_request_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_UART_B_CONTROL_RDREQIEN_ENABLED_U32)


/// @fn _SI32_UART_B_disable_rx_data_request_interrupt(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_rx_data_request_interrupt(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_rx_data_request_interrupt(basePointer)
#define SI32_UART_B_disable_rx_data_request_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_RDREQIEN_MASK)


/// @fn _SI32_UART_B_is_rx_data_request_interrupt_enabled(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_UART_B_is_rx_data_request_interrupt_enabled(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_is_rx_data_request_interrupt_enabled(basePointer)
#define SI32_UART_B_is_rx_data_request_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.RDREQIEN))


/// @fn _SI32_UART_B_exit_match_mode(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_exit_match_mode(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_exit_match_mode(basePointer)
#define SI32_UART_B_exit_match_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_MATMD_MASK)


/// @fn _SI32_UART_B_enter_match_mode_store_byte(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enter_match_mode_store_byte(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enter_match_mode_store_byte(basePointer)
#define SI32_UART_B_enter_match_mode_store_byte(basePointer) do{  \
	basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_MATMD_MASK;\
   basePointer->CONTROL_SET = SI32_UART_B_CONTROL_MATMD_MCE_U32;\
} while(0)


/// @fn _SI32_UART_B_enter_match_mode_generate_frame_error(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enter_match_mode_generate_frame_error(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enter_match_mode_generate_frame_error(basePointer)
#define SI32_UART_B_enter_match_mode_generate_frame_error(basePointer) do{  \
	basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_MATMD_MASK;\
   basePointer->CONTROL_SET = SI32_UART_B_CONTROL_MATMD_FRAME_U32;\
} while(0)


/// @fn _SI32_UART_B_enter_match_mode_store_bit(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enter_match_mode_store_bit(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enter_match_mode_store_bit(basePointer)
#define SI32_UART_B_enter_match_mode_store_bit(basePointer) \
   (basePointer->CONTROL_SET = SI32_UART_B_CONTROL_MATMD_STORE_U32)


/// @fn _SI32_UART_B_enable_rx_autobaud(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_rx_autobaud(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_rx_autobaud(basePointer)
#define SI32_UART_B_enable_rx_autobaud(basePointer) \
   (basePointer->CONTROL_SET = SI32_UART_B_CONTROL_RABDEN_ENABLED_U32)


/// @fn _SI32_UART_B_disable_rx_autobaud(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_rx_autobaud(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_rx_autobaud(basePointer)
#define SI32_UART_B_disable_rx_autobaud(basePointer) \
   (basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_RABDEN_MASK)


/// @fn _SI32_UART_B_is_rx_busy(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_UART_B_is_rx_busy(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_is_rx_busy(basePointer)
#define SI32_UART_B_is_rx_busy(basePointer) \
((bool)(basePointer->CONTROL.RBUSYF))


/// @fn _SI32_UART_B_set_rbit(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_set_rbit(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_set_rbit(basePointer)
#define SI32_UART_B_set_rbit(basePointer) \
   (basePointer->CONTROL_SET = SI32_UART_B_CONTROL_RBIT_SET_U32)


/// @fn _SI32_UART_B_clear_rbit(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_clear_rbit(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_clear_rbit(basePointer)
#define SI32_UART_B_clear_rbit(basePointer) \
   (basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_RBIT_MASK)


/// @fn _SI32_UART_B_read_rbit(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_UART_B_read_rbit(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_read_rbit(basePointer)
#define SI32_UART_B_read_rbit(basePointer) \
((bool)(basePointer->CONTROL.RBIT))


/// @fn _SI32_UART_B_enable_rx_one_shot(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_rx_one_shot(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_rx_one_shot(basePointer)
#define SI32_UART_B_enable_rx_one_shot(basePointer) \
   (basePointer->CONTROL_SET = SI32_UART_B_CONTROL_ROSEN_ENABLED_U32)


/// @fn _SI32_UART_B_disable_rx_one_shot(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_rx_one_shot(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_rx_one_shot(basePointer)
#define SI32_UART_B_disable_rx_one_shot(basePointer) \
   (basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_ROSEN_MASK)


/// @fn _SI32_UART_B_enable_rx_inhibit(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_rx_inhibit(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_rx_inhibit(basePointer)
#define SI32_UART_B_enable_rx_inhibit(basePointer) \
   (basePointer->CONTROL_SET = SI32_UART_B_CONTROL_RINH_ACTIVE_U32)


/// @fn _SI32_UART_B_disable_rx_inhibit(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_rx_inhibit(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_rx_inhibit(basePointer)
#define SI32_UART_B_disable_rx_inhibit(basePointer) \
   (basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_RINH_MASK)


/// @fn _SI32_UART_B_enable_rx(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_rx(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_rx(basePointer)
#define SI32_UART_B_enable_rx(basePointer) \
   (basePointer->CONTROL_SET = SI32_UART_B_CONTROL_REN_ENABLED_U32)


/// @fn _SI32_UART_B_disable_rx(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_rx(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_rx(basePointer)
#define SI32_UART_B_disable_rx(basePointer) \
   (basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_REN_MASK)


/// @fn _SI32_UART_B_is_tx_data_request_interrupt_pending(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_UART_B_is_tx_data_request_interrupt_pending(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_is_tx_data_request_interrupt_pending(basePointer)
#define SI32_UART_B_is_tx_data_request_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.TDREQI))


/// @fn _SI32_UART_B_is_tx_complete(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_UART_B_is_tx_complete(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_is_tx_complete(basePointer)
#define SI32_UART_B_is_tx_complete(basePointer) \
((bool)(basePointer->CONTROL.TCPTI))


/// @fn _SI32_UART_B_clear_tx_complete_interrupt(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_clear_tx_complete_interrupt(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_clear_tx_complete_interrupt(basePointer)
#define SI32_UART_B_clear_tx_complete_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_TCPTI_MASK)


/// @fn _SI32_UART_B_select_tx_complete_threshold_end_of_transmission(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_select_tx_complete_threshold_end_of_transmission(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_select_tx_complete_threshold_end_of_transmission(basePointer)
#define SI32_UART_B_select_tx_complete_threshold_end_of_transmission(basePointer) \
   (basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_TCPTTH_MASK)


/// @fn _SI32_UART_B_select_tx_complete_threshold_no_more_data(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_select_tx_complete_threshold_no_more_data(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_select_tx_complete_threshold_no_more_data(basePointer)
#define SI32_UART_B_select_tx_complete_threshold_no_more_data(basePointer) \
   (basePointer->CONTROL_SET = SI32_UART_B_CONTROL_TCPTTH_SET_ON_EMPTY_U32)


/// @fn _SI32_UART_B_enable_tx_data_request_interrupt(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_tx_data_request_interrupt(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_tx_data_request_interrupt(basePointer)
#define SI32_UART_B_enable_tx_data_request_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_UART_B_CONTROL_TDREQIEN_ENABLED_U32)


/// @fn _SI32_UART_B_disable_tx_data_request_interrupt(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_tx_data_request_interrupt(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_tx_data_request_interrupt(basePointer)
#define SI32_UART_B_disable_tx_data_request_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_TDREQIEN_MASK)


/// @fn _SI32_UART_B_is_tx_data_request_interrupt_enabled(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_UART_B_is_tx_data_request_interrupt_enabled(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_is_tx_data_request_interrupt_enabled(basePointer)
#define SI32_UART_B_is_tx_data_request_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.TDREQIEN))


/// @fn _SI32_UART_B_enable_tx_complete_interrupt(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_tx_complete_interrupt(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_tx_complete_interrupt(basePointer)
#define SI32_UART_B_enable_tx_complete_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_UART_B_CONTROL_TCPTIEN_ENABLED_U32)


/// @fn _SI32_UART_B_disable_tx_complete_interrupt(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_tx_complete_interrupt(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_tx_complete_interrupt(basePointer)
#define SI32_UART_B_disable_tx_complete_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_TCPTIEN_MASK)


/// @fn _SI32_UART_B_is_tx_complete_interrupt_enabled(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_UART_B_is_tx_complete_interrupt_enabled(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_is_tx_complete_interrupt_enabled(basePointer)
#define SI32_UART_B_is_tx_complete_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.TCPTIEN))


/// @fn _SI32_UART_B_is_tx_busy(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_UART_B_is_tx_busy(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_is_tx_busy(basePointer)
#define SI32_UART_B_is_tx_busy(basePointer) \
((bool)(basePointer->CONTROL.TBUSYF))


/// @fn _SI32_UART_B_set_tbit(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_set_tbit(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_set_tbit(basePointer)
#define SI32_UART_B_set_tbit(basePointer) \
   (basePointer->CONTROL_SET = SI32_UART_B_CONTROL_TBIT_SET_U32)


/// @fn _SI32_UART_B_clear_tbit(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_clear_tbit(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_clear_tbit(basePointer)
#define SI32_UART_B_clear_tbit(basePointer) \
   (basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_TBIT_MASK)


/// @fn _SI32_UART_B_enable_tx_inhibit(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_tx_inhibit(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_tx_inhibit(basePointer)
#define SI32_UART_B_enable_tx_inhibit(basePointer) \
   (basePointer->CONTROL_SET = SI32_UART_B_CONTROL_TINH_ACTIVE_U32)


/// @fn _SI32_UART_B_disable_tx_inhibit(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_tx_inhibit(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_tx_inhibit(basePointer)
#define SI32_UART_B_disable_tx_inhibit(basePointer) \
   (basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_TINH_MASK)


/// @fn _SI32_UART_B_enable_tx(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_enable_tx(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_enable_tx(basePointer)
#define SI32_UART_B_enable_tx(basePointer) \
   (basePointer->CONTROL_SET = SI32_UART_B_CONTROL_TEN_ENABLED_U32)


/// @fn _SI32_UART_B_disable_tx(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_disable_tx(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_disable_tx(basePointer)
#define SI32_UART_B_disable_tx(basePointer) \
   (basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_TEN_MASK)


/// @fn _SI32_UART_B_write_ipdelay(SI32_UART_B_Type* basePointer,
///      uint32_t ipdelay)
///
/// @brief
/// Write to IPDELAY register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  ipdelay
///  Valid range is 32 bits.
///
void
_SI32_UART_B_write_ipdelay(SI32_UART_B_Type* /*basePointer*/,
   uint32_t /*ipdelay*/);
///
/// @def SI32_UART_B_write_ipdelay(basePointer, ipdelay)
#define SI32_UART_B_write_ipdelay(basePointer, ipdelay) \
   (basePointer->IPDELAY.U32 = ipdelay)


/// @fn _SI32_UART_B_read_ipdelay(SI32_UART_B_Type* basePointer)
///
/// @brief
/// Reads IPDELAY register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_UART_B_read_ipdelay(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_read_ipdelay(basePointer)
#define SI32_UART_B_read_ipdelay(basePointer) \
(basePointer->IPDELAY.U32)


/// @fn _SI32_UART_B_write_ipdelay_bits(SI32_UART_B_Type* basePointer,
///      uint32_t ipdelay)
///
/// @brief
/// Write to IPDELAY bitfield.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  ipdelay
///  Valid range is 8 bits.
///
void
_SI32_UART_B_write_ipdelay_bits(SI32_UART_B_Type* /*basePointer*/,
   uint32_t /*ipdelay*/);
///
/// @def SI32_UART_B_write_ipdelay_bits(basePointer, ipdelay)
#define SI32_UART_B_write_ipdelay_bits(basePointer, ipdelay) \
   (basePointer->IPDELAY.IPDELAY_BITS = ipdelay)


/// @fn _SI32_UART_B_read_ipdelay_bits(SI32_UART_B_Type* basePointer)
///
/// @brief
/// Reads IPDELAY bitfield.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_UART_B_read_ipdelay_bits(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_read_ipdelay_bits(basePointer)
#define SI32_UART_B_read_ipdelay_bits(basePointer) \
(basePointer->IPDELAY.IPDELAY_BITS)


/// @fn _SI32_UART_B_write_baudrate(SI32_UART_B_Type* basePointer,
///      uint32_t baudrate)
///
/// @brief
/// Write to BAUDRATE register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  baudrate
///  Valid range is 32 bits.
///
void
_SI32_UART_B_write_baudrate(SI32_UART_B_Type* /*basePointer*/,
   uint32_t /*baudrate*/);
///
/// @def SI32_UART_B_write_baudrate(basePointer, baudrate)
#define SI32_UART_B_write_baudrate(basePointer, baudrate) \
   (basePointer->BAUDRATE.U32 = baudrate)


/// @fn _SI32_UART_B_read_baudrate(SI32_UART_B_Type* basePointer)
///
/// @brief
/// Reads BAUDRATE register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_UART_B_read_baudrate(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_read_baudrate(basePointer)
#define SI32_UART_B_read_baudrate(basePointer) \
(basePointer->BAUDRATE.U32)


/// @fn _SI32_UART_B_set_rx_baudrate(SI32_UART_B_Type* basePointer,
///      uwide16_t rxbaud)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  rxbaud
///  Valid range is 16 bits.
///
void
_SI32_UART_B_set_rx_baudrate(SI32_UART_B_Type* /*basePointer*/,
   uwide16_t /*rxbaud*/);
///
/// @def SI32_UART_B_set_rx_baudrate(basePointer, rxbaud)
#define SI32_UART_B_set_rx_baudrate(basePointer, rxbaud) \
   (basePointer->BAUDRATE.RBAUD = rxbaud)


/// @fn _SI32_UART_B_set_tx_baudrate(SI32_UART_B_Type* basePointer,
///      uwide16_t txbaud)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  txbaud
///  Valid range is 16 bits.
///
void
_SI32_UART_B_set_tx_baudrate(SI32_UART_B_Type* /*basePointer*/,
   uwide16_t /*txbaud*/);
///
/// @def SI32_UART_B_set_tx_baudrate(basePointer, txbaud)
#define SI32_UART_B_set_tx_baudrate(basePointer, txbaud) \
   (basePointer->BAUDRATE.TBAUD = txbaud)


/// @fn _SI32_UART_B_write_fifocn(SI32_UART_B_Type* basePointer,
///      uint32_t fifocn)
///
/// @brief
/// Write to FIFOCN register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  fifocn
///  Valid range is 32 bits.
///
void
_SI32_UART_B_write_fifocn(SI32_UART_B_Type* /*basePointer*/,
   uint32_t /*fifocn*/);
///
/// @def SI32_UART_B_write_fifocn(basePointer, fifocn)
#define SI32_UART_B_write_fifocn(basePointer, fifocn) \
   _SI32_UART_B_write_fifocn(basePointer, fifocn) 


/// @fn _SI32_UART_B_read_fifocn(SI32_UART_B_Type* basePointer)
///
/// @brief
/// Reads FIFOCN register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_UART_B_read_fifocn(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_read_fifocn(basePointer)
#define SI32_UART_B_read_fifocn(basePointer) \
(basePointer->FIFOCN.U32)


/// @fn _SI32_UART_B_read_rx_fifo_count(SI32_UART_B_Type* basePointer)
///
/// @brief
/// Returns number of bytes in receive FIFO.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_UART_B_read_rx_fifo_count(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_read_rx_fifo_count(basePointer)
#define SI32_UART_B_read_rx_fifo_count(basePointer) \
((uint32_t)(basePointer->FIFOCN.RCNT))


/// @fn _SI32_UART_B_select_rx_fifo_threshold_1(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_select_rx_fifo_threshold_1(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_select_rx_fifo_threshold_1(basePointer)
#define SI32_UART_B_select_rx_fifo_threshold_1(basePointer) \
   (basePointer->FIFOCN_CLR = SI32_UART_B_FIFOCN_RFTH_MASK)


/// @fn _SI32_UART_B_select_rx_fifo_threshold_2(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_select_rx_fifo_threshold_2(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_select_rx_fifo_threshold_2(basePointer)
#define SI32_UART_B_select_rx_fifo_threshold_2(basePointer) do{  \
   basePointer->FIFOCN_CLR = SI32_UART_B_FIFOCN_RFTH_MASK;\
   basePointer->FIFOCN_SET = SI32_UART_B_FIFOCN_RFTH_TWO_U32;\
} while(0)


/// @fn _SI32_UART_B_select_rx_fifo_threshold_4(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_select_rx_fifo_threshold_4(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_select_rx_fifo_threshold_4(basePointer)
#define SI32_UART_B_select_rx_fifo_threshold_4(basePointer) do{  \
   basePointer->FIFOCN_CLR = SI32_UART_B_FIFOCN_RFTH_MASK;\
   basePointer->FIFOCN_SET = SI32_UART_B_FIFOCN_RFTH_FOUR_U32;\
} while(0)


/// @fn _SI32_UART_B_flush_rx_fifo(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_flush_rx_fifo(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_flush_rx_fifo(basePointer)
#define SI32_UART_B_flush_rx_fifo(basePointer) \
   (basePointer->FIFOCN_SET = SI32_UART_B_FIFOCN_RFIFOFL_SET_U32)


/// @fn _SI32_UART_B_is_rx_fifo_error_interrupt_pending(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_UART_B_is_rx_fifo_error_interrupt_pending(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_is_rx_fifo_error_interrupt_pending(basePointer)
#define SI32_UART_B_is_rx_fifo_error_interrupt_pending(basePointer) \
((bool)(basePointer->FIFOCN.RFERI))


/// @fn _SI32_UART_B_clear_rx_fifo_error_interrupt(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_clear_rx_fifo_error_interrupt(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_clear_rx_fifo_error_interrupt(basePointer)
#define SI32_UART_B_clear_rx_fifo_error_interrupt(basePointer) \
   (basePointer->FIFOCN_CLR = SI32_UART_B_FIFOCN_RFERI_MASK)


/// @fn _SI32_UART_B_is_rx_shift_register_full(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_UART_B_is_rx_shift_register_full(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_is_rx_shift_register_full(basePointer)
#define SI32_UART_B_is_rx_shift_register_full(basePointer) \
((bool)(basePointer->FIFOCN.RSRFULLF))


/// @fn _SI32_UART_B_read_tx_fifo_count(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_UART_B_read_tx_fifo_count(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_read_tx_fifo_count(basePointer)
#define SI32_UART_B_read_tx_fifo_count(basePointer) \
((uint32_t)(basePointer->FIFOCN.TCNT))


/// @fn _SI32_UART_B_select_tx_fifo_threshold_for_request_to_1(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_select_tx_fifo_threshold_for_request_to_1(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_select_tx_fifo_threshold_for_request_to_1(basePointer)
#define SI32_UART_B_select_tx_fifo_threshold_for_request_to_1(basePointer) \
   (basePointer->FIFOCN_CLR = SI32_UART_B_FIFOCN_TFTH_MASK)


/// @fn _SI32_UART_B_select_tx_fifo_threshold_for_request_to_2(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_select_tx_fifo_threshold_for_request_to_2(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_select_tx_fifo_threshold_for_request_to_2(basePointer)
#define SI32_UART_B_select_tx_fifo_threshold_for_request_to_2(basePointer) do{  \
	basePointer->FIFOCN_CLR = SI32_UART_B_FIFOCN_TFTH_MASK;\
   basePointer->FIFOCN_SET = SI32_UART_B_FIFOCN_TFTH_TWO_U32;\
} while(0)


/// @fn _SI32_UART_B_select_tx_fifo_threshold_for_request_to_4(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_select_tx_fifo_threshold_for_request_to_4(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_select_tx_fifo_threshold_for_request_to_4(basePointer)
#define SI32_UART_B_select_tx_fifo_threshold_for_request_to_4(basePointer) do{  \
	basePointer->FIFOCN_CLR = SI32_UART_B_FIFOCN_TFTH_MASK;\
   basePointer->FIFOCN_SET = SI32_UART_B_FIFOCN_TFTH_FOUR_U32;\
} while(0)


/// @fn _SI32_UART_B_flush_tx_fifo(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_flush_tx_fifo(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_flush_tx_fifo(basePointer)
#define SI32_UART_B_flush_tx_fifo(basePointer) \
   (basePointer->FIFOCN_SET = SI32_UART_B_FIFOCN_TFIFOFL_SET_U32)


/// @fn _SI32_UART_B_is_tx_fifo_error_interrupt_pending(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_UART_B_is_tx_fifo_error_interrupt_pending(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_is_tx_fifo_error_interrupt_pending(basePointer)
#define SI32_UART_B_is_tx_fifo_error_interrupt_pending(basePointer) \
((bool)(basePointer->FIFOCN.TFERI))


/// @fn _SI32_UART_B_clear_tx_fifo_error_interrupt(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_clear_tx_fifo_error_interrupt(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_clear_tx_fifo_error_interrupt(basePointer)
#define SI32_UART_B_clear_tx_fifo_error_interrupt(basePointer) \
   (basePointer->FIFOCN_CLR = SI32_UART_B_FIFOCN_TFERI_MASK)


/// @fn _SI32_UART_B_is_tx_shift_register_full(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_UART_B_is_tx_shift_register_full(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_is_tx_shift_register_full(basePointer)
#define SI32_UART_B_is_tx_shift_register_full(basePointer) \
((bool)(basePointer->FIFOCN.TSRFULLF))


/// @fn _SI32_UART_B_read_data_u32(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_UART_B_read_data_u32(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_read_data_u32(basePointer)
#define SI32_UART_B_read_data_u32(basePointer) \
((uint32_t)(basePointer->DATA.U32))


/// @fn _SI32_UART_B_read_data_u16(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint16_t
_SI32_UART_B_read_data_u16(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_read_data_u16(basePointer)
#define SI32_UART_B_read_data_u16(basePointer) \
(basePointer->DATA.U16)


/// @fn _SI32_UART_B_read_data_u8(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint8_t
_SI32_UART_B_read_data_u8(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_read_data_u8(basePointer)
#define SI32_UART_B_read_data_u8(basePointer) \
(basePointer->DATA.U8)


/// @fn _SI32_UART_B_write_data_u32(SI32_UART_B_Type* basePointer,
///      uint32_t dataval)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  dataval
///  Valid range is 32 bits.
///
void
_SI32_UART_B_write_data_u32(SI32_UART_B_Type* /*basePointer*/,
   uint32_t /*dataval*/);
///
/// @def SI32_UART_B_write_data_u32(basePointer, dataval)
#define SI32_UART_B_write_data_u32(basePointer, dataval) \
   (basePointer->DATA.U32 = dataval)


/// @fn _SI32_UART_B_write_data_u16(SI32_UART_B_Type* basePointer,
///      uwide16_t dataval)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  dataval
///  Valid range is 16 bits.
///
void
_SI32_UART_B_write_data_u16(SI32_UART_B_Type* /*basePointer*/,
   uwide16_t /*dataval*/);
///
/// @def SI32_UART_B_write_data_u16(basePointer, dataval)
#define SI32_UART_B_write_data_u16(basePointer, dataval) \
   (basePointer->DATA.U16 = dataval)


/// @fn _SI32_UART_B_write_data_u8(SI32_UART_B_Type* basePointer,
///      uwide8_t dataval)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  dataval
///  Valid range is 8 bits.
///
void
_SI32_UART_B_write_data_u8(SI32_UART_B_Type* /*basePointer*/,
   uwide8_t /*dataval*/);
///
/// @def SI32_UART_B_write_data_u8(basePointer, dataval)
#define SI32_UART_B_write_data_u8(basePointer, dataval) \
   (basePointer->DATA.U8 = dataval)


/// @fn _SI32_UART_B_write_clkdiv(SI32_UART_B_Type* basePointer,
///      uint32_t clkdiv)
///
/// @brief
/// Write to CLKDIV register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  clkdiv
///  Valid range is 32 bits.
///
void
_SI32_UART_B_write_clkdiv(SI32_UART_B_Type* /*basePointer*/,
   uint32_t /*clkdiv*/);
///
/// @def SI32_UART_B_write_clkdiv(basePointer, clkdiv)
#define SI32_UART_B_write_clkdiv(basePointer, clkdiv) \
   (basePointer->CLKDIV.U32 = clkdiv)


/// @fn _SI32_UART_B_read_clkdiv(SI32_UART_B_Type* basePointer)
///
/// @brief
/// Reads CLKDIV register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_UART_B_read_clkdiv(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_read_clkdiv(basePointer)
#define SI32_UART_B_read_clkdiv(basePointer) \
(basePointer->CLKDIV.U32)


/// @fn _SI32_UART_B_select_clock_source_apb_div1(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_select_clock_source_apb_div1(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_select_clock_source_apb_div1(basePointer)
#define SI32_UART_B_select_clock_source_apb_div1(basePointer) \
   (basePointer->CLKDIV.CLKDIV_BITS = SI32_UART_B_CLKDIV_CLKDIV_DIV1_VALUE)


/// @fn _SI32_UART_B_select_clock_source_apb_div2(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_select_clock_source_apb_div2(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_select_clock_source_apb_div2(basePointer)
#define SI32_UART_B_select_clock_source_apb_div2(basePointer) \
   (basePointer->CLKDIV.CLKDIV_BITS = SI32_UART_B_CLKDIV_CLKDIV_DIV2_VALUE)


/// @fn _SI32_UART_B_select_clock_source_apb_div4(SI32_UART_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_UART_B_select_clock_source_apb_div4(SI32_UART_B_Type* /*basePointer*/);
///
/// @def SI32_UART_B_select_clock_source_apb_div4(basePointer)
#define SI32_UART_B_select_clock_source_apb_div4(basePointer) \
   (basePointer->CLKDIV.CLKDIV_BITS = SI32_UART_B_CLKDIV_CLKDIV_DIV4_VALUE)



#ifdef __cplusplus
}
#endif

#endif // __SI32_UART_B_TYPE_H__

//-eof--------------------------------------------------------------------------
