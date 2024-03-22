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
/// @file SI32_USART_A_Type.h
//
// Script: 0.59
// HAL Source: 0.6
// Version: 1

#ifndef __SI32_USART_A_TYPE_H__
#define __SI32_USART_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_USART_A_Registers.h"
#include "SI32_USART_A_Support.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_USART_A_initialize(SI32_USART_A_Type* basePointer,
///      uint32_t config,
///      uint32_t mode,
///      uint32_t flowcn,
///      uint32_t control,
///      uint32_t ipdelay,
///      uint32_t baudrate,
///      uint32_t fifocn)
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
///  Valid range is 32 bits.
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
void
_SI32_USART_A_initialize(SI32_USART_A_Type* /*basePointer*/,
   uint32_t, /*config*/
   uint32_t, /*mode*/
   uint32_t, /*flowcn*/
   uint32_t, /*control*/
   uint32_t, /*ipdelay*/
   uint32_t, /*baudrate*/
   uint32_t /*fifocn*/);
///
/// @def SI32_USART_A_initialize(basePointer, config, mode, flowcn, control, ipdelay, baudrate, fifocn)
#define SI32_USART_A_initialize(basePointer, config, mode, flowcn, control, ipdelay, baudrate, fifocn) \
   _SI32_USART_A_initialize(basePointer, config, mode, flowcn, control, ipdelay, baudrate, fifocn) 


/// @fn _SI32_USART_A_write_config(SI32_USART_A_Type* basePointer,
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
_SI32_USART_A_write_config(SI32_USART_A_Type* /*basePointer*/,
   uint32_t /*config*/);
///
/// @def SI32_USART_A_write_config(basePointer, config)
#define SI32_USART_A_write_config(basePointer, config) \
   (basePointer->CONFIG.U32 = config)


/// @fn _SI32_USART_A_read_config(SI32_USART_A_Type* basePointer)
///
/// @brief
/// Reads CONFIG register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USART_A_read_config(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_read_config(basePointer)
#define SI32_USART_A_read_config(basePointer) \
(basePointer->CONFIG.U32)


/// @fn _SI32_USART_A_enable_rx_start_bit(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_rx_start_bit(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_rx_start_bit(basePointer)
#define SI32_USART_A_enable_rx_start_bit(basePointer) \
   (basePointer->CONFIG_SET = SI32_USART_A_CONFIG_RSTRTEN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_rx_start_bit(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_rx_start_bit(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_rx_start_bit(basePointer)
#define SI32_USART_A_disable_rx_start_bit(basePointer) \
   (basePointer->CONFIG_CLR = SI32_USART_A_CONFIG_RSTRTEN_MASK)


/// @fn _SI32_USART_A_enable_rx_parity_bit(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_rx_parity_bit(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_rx_parity_bit(basePointer)
#define SI32_USART_A_enable_rx_parity_bit(basePointer) \
   (basePointer->CONFIG_SET = SI32_USART_A_CONFIG_RPAREN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_rx_parity_bit(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_rx_parity_bit(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_rx_parity_bit(basePointer)
#define SI32_USART_A_disable_rx_parity_bit(basePointer) \
   (basePointer->CONFIG_CLR = SI32_USART_A_CONFIG_RPAREN_MASK)


/// @fn _SI32_USART_A_enable_rx_stop_bit(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_rx_stop_bit(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_rx_stop_bit(basePointer)
#define SI32_USART_A_enable_rx_stop_bit(basePointer) \
   (basePointer->CONFIG_SET = SI32_USART_A_CONFIG_RSTPEN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_rx_stop_bit(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_rx_stop_bit(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_rx_stop_bit(basePointer)
#define SI32_USART_A_disable_rx_stop_bit(basePointer) \
   (basePointer->CONFIG_CLR = SI32_USART_A_CONFIG_RSTPEN_MASK)


/// @fn _SI32_USART_A_select_rx_stop_bits(SI32_USART_A_Type* basePointer,
///      SI32_USART_A_STOP_BITS_Enum_Type bits)
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
_SI32_USART_A_select_rx_stop_bits(SI32_USART_A_Type* /*basePointer*/,
   SI32_USART_A_STOP_BITS_Enum_Type /*bits*/);
///
/// @def SI32_USART_A_select_rx_stop_bits(basePointer, bits)
#define SI32_USART_A_select_rx_stop_bits(basePointer, bits) do{  \
   basePointer->CONFIG_CLR = SI32_USART_A_CONFIG_RSTPMD_MASK;\
   basePointer->CONFIG_SET = bits << SI32_USART_A_CONFIG_RSTPMD_SHIFT;\
} while(0)


/// @fn _SI32_USART_A_select_rx_parity(SI32_USART_A_Type* basePointer,
///      SI32_USART_A_PARITY_Enum_Type parity)
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
_SI32_USART_A_select_rx_parity(SI32_USART_A_Type* /*basePointer*/,
   SI32_USART_A_PARITY_Enum_Type /*parity*/);
///
/// @def SI32_USART_A_select_rx_parity(basePointer, parity)
#define SI32_USART_A_select_rx_parity(basePointer, parity) do{  \
   basePointer->CONFIG_CLR = SI32_USART_A_CONFIG_RPARMD_MASK;\
   basePointer->CONFIG_SET = parity << SI32_USART_A_CONFIG_RPARMD_SHIFT;\
} while(0)


/// @fn _SI32_USART_A_select_rx_data_length(SI32_USART_A_Type* basePointer,
///      SI32_USART_A_DATA_LENGTH_Enum_Type length)
///
/// @brief
/// Sets the receiver data length to: 5 = 5 bits, 6 = 6 bits, 7 = 7 bits,
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
_SI32_USART_A_select_rx_data_length(SI32_USART_A_Type* /*basePointer*/,
   SI32_USART_A_DATA_LENGTH_Enum_Type /*length*/);
///
/// @def SI32_USART_A_select_rx_data_length(basePointer, length)
#define SI32_USART_A_select_rx_data_length(basePointer, length) do{  \
   basePointer->CONFIG_CLR = SI32_USART_A_CONFIG_RDATLN_MASK;\
   basePointer->CONFIG_SET = (length - 5) << SI32_USART_A_CONFIG_RDATLN_SHIFT;\
} while(0)


/// @fn _SI32_USART_A_enable_rx_smartcard_parity_response(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_rx_smartcard_parity_response(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_rx_smartcard_parity_response(basePointer)
#define SI32_USART_A_enable_rx_smartcard_parity_response(basePointer) \
   (basePointer->CONFIG_SET = SI32_USART_A_CONFIG_RSCEN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_rx_smartcard_parity_response(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_rx_smartcard_parity_response(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_rx_smartcard_parity_response(basePointer)
#define SI32_USART_A_disable_rx_smartcard_parity_response(basePointer) \
   (basePointer->CONFIG_CLR = SI32_USART_A_CONFIG_RSCEN_MASK)


/// @fn _SI32_USART_A_enable_rx_irda_mode(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_rx_irda_mode(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_rx_irda_mode(basePointer)
#define SI32_USART_A_enable_rx_irda_mode(basePointer) \
   (basePointer->CONFIG_SET = SI32_USART_A_CONFIG_RIRDAEN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_rx_irda_mode(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_rx_irda_mode(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_rx_irda_mode(basePointer)
#define SI32_USART_A_disable_rx_irda_mode(basePointer) \
   (basePointer->CONFIG_CLR = SI32_USART_A_CONFIG_RIRDAEN_MASK)


/// @fn _SI32_USART_A_enable_rx_signal_inversion(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_rx_signal_inversion(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_rx_signal_inversion(basePointer)
#define SI32_USART_A_enable_rx_signal_inversion(basePointer) \
   (basePointer->CONFIG_SET = SI32_USART_A_CONFIG_RINVEN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_rx_signal_inversion(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_rx_signal_inversion(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_rx_signal_inversion(basePointer)
#define SI32_USART_A_disable_rx_signal_inversion(basePointer) \
   (basePointer->CONFIG_CLR = SI32_USART_A_CONFIG_RINVEN_MASK)


/// @fn _SI32_USART_A_select_rx_asynchronous_mode(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_select_rx_asynchronous_mode(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_select_rx_asynchronous_mode(basePointer)
#define SI32_USART_A_select_rx_asynchronous_mode(basePointer) \
   (basePointer->CONFIG_CLR = SI32_USART_A_CONFIG_RSYNCEN_MASK)


/// @fn _SI32_USART_A_select_rx_synchronous_mode(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_select_rx_synchronous_mode(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_select_rx_synchronous_mode(basePointer)
#define SI32_USART_A_select_rx_synchronous_mode(basePointer) \
   (basePointer->CONFIG_SET = SI32_USART_A_CONFIG_RSYNCEN_ENABLED_U32)


/// @fn _SI32_USART_A_enable_tx_start_bit(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_tx_start_bit(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_tx_start_bit(basePointer)
#define SI32_USART_A_enable_tx_start_bit(basePointer) \
   (basePointer->CONFIG_SET = SI32_USART_A_CONFIG_TSTRTEN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_tx_start_bit(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_tx_start_bit(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_tx_start_bit(basePointer)
#define SI32_USART_A_disable_tx_start_bit(basePointer) \
   (basePointer->CONFIG_CLR = SI32_USART_A_CONFIG_TSTRTEN_MASK)


/// @fn _SI32_USART_A_enable_tx_parity_bit(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_tx_parity_bit(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_tx_parity_bit(basePointer)
#define SI32_USART_A_enable_tx_parity_bit(basePointer) \
   (basePointer->CONFIG_SET = SI32_USART_A_CONFIG_TPAREN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_tx_parity_bit(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_tx_parity_bit(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_tx_parity_bit(basePointer)
#define SI32_USART_A_disable_tx_parity_bit(basePointer) \
   (basePointer->CONFIG_CLR = SI32_USART_A_CONFIG_TPAREN_MASK)


/// @fn _SI32_USART_A_enable_tx_stop_bit(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_tx_stop_bit(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_tx_stop_bit(basePointer)
#define SI32_USART_A_enable_tx_stop_bit(basePointer) \
   (basePointer->CONFIG_SET = SI32_USART_A_CONFIG_TSTPEN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_tx_stop_bit(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_tx_stop_bit(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_tx_stop_bit(basePointer)
#define SI32_USART_A_disable_tx_stop_bit(basePointer) \
   (basePointer->CONFIG_CLR = SI32_USART_A_CONFIG_TSTPEN_MASK)


/// @fn _SI32_USART_A_select_tx_stop_bits(SI32_USART_A_Type* basePointer,
///      SI32_USART_A_STOP_BITS_Enum_Type bits)
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
_SI32_USART_A_select_tx_stop_bits(SI32_USART_A_Type* /*basePointer*/,
   SI32_USART_A_STOP_BITS_Enum_Type /*bits*/);
///
/// @def SI32_USART_A_select_tx_stop_bits(basePointer, bits)
#define SI32_USART_A_select_tx_stop_bits(basePointer, bits) do{  \
   basePointer->CONFIG_CLR = SI32_USART_A_CONFIG_TSTPMD_MASK;\
   basePointer->CONFIG_SET = bits << SI32_USART_A_CONFIG_TSTPMD_SHIFT;\
} while(0)


/// @fn _SI32_USART_A_select_tx_parity(SI32_USART_A_Type* basePointer,
///      SI32_USART_A_PARITY_Enum_Type parity)
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
_SI32_USART_A_select_tx_parity(SI32_USART_A_Type* /*basePointer*/,
   SI32_USART_A_PARITY_Enum_Type /*parity*/);
///
/// @def SI32_USART_A_select_tx_parity(basePointer, parity)
#define SI32_USART_A_select_tx_parity(basePointer, parity) do{  \
   basePointer->CONFIG_CLR = SI32_USART_A_CONFIG_TPARMD_MASK;\
   basePointer->CONFIG_SET = parity << SI32_USART_A_CONFIG_TPARMD_SHIFT;\
} while(0)


/// @fn _SI32_USART_A_select_tx_data_length(SI32_USART_A_Type* basePointer,
///      SI32_USART_A_DATA_LENGTH_Enum_Type length)
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
_SI32_USART_A_select_tx_data_length(SI32_USART_A_Type* /*basePointer*/,
   SI32_USART_A_DATA_LENGTH_Enum_Type /*length*/);
///
/// @def SI32_USART_A_select_tx_data_length(basePointer, length)
#define SI32_USART_A_select_tx_data_length(basePointer, length) do{  \
   basePointer->CONFIG_CLR = SI32_USART_A_CONFIG_TDATLN_MASK;\
   basePointer->CONFIG_SET = (length - 5) << SI32_USART_A_CONFIG_TDATLN_SHIFT;\
} while(0)


/// @fn _SI32_USART_A_enable_tx_smartcard_parity_check(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_tx_smartcard_parity_check(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_tx_smartcard_parity_check(basePointer)
#define SI32_USART_A_enable_tx_smartcard_parity_check(basePointer) \
   (basePointer->CONFIG_SET = SI32_USART_A_CONFIG_TSCEN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_tx_smartcard_parity_check(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_tx_smartcard_parity_check(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_tx_smartcard_parity_check(basePointer)
#define SI32_USART_A_disable_tx_smartcard_parity_check(basePointer) \
   (basePointer->CONFIG_CLR = SI32_USART_A_CONFIG_TSCEN_MASK)


/// @fn _SI32_USART_A_enable_tx_irda_mode(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_tx_irda_mode(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_tx_irda_mode(basePointer)
#define SI32_USART_A_enable_tx_irda_mode(basePointer) \
   (basePointer->CONFIG_SET = SI32_USART_A_CONFIG_TIRDAEN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_tx_irda_mode(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_tx_irda_mode(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_tx_irda_mode(basePointer)
#define SI32_USART_A_disable_tx_irda_mode(basePointer) \
   (basePointer->CONFIG_CLR = SI32_USART_A_CONFIG_TIRDAEN_MASK)


/// @fn _SI32_USART_A_enable_tx_signal_inversion(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_tx_signal_inversion(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_tx_signal_inversion(basePointer)
#define SI32_USART_A_enable_tx_signal_inversion(basePointer) \
   (basePointer->CONFIG_SET = SI32_USART_A_CONFIG_TINVEN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_tx_signal_inversion(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_tx_signal_inversion(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_tx_signal_inversion(basePointer)
#define SI32_USART_A_disable_tx_signal_inversion(basePointer) \
   (basePointer->CONFIG_CLR = SI32_USART_A_CONFIG_TINVEN_MASK)


/// @fn _SI32_USART_A_select_tx_asynchronous_mode(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_select_tx_asynchronous_mode(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_select_tx_asynchronous_mode(basePointer)
#define SI32_USART_A_select_tx_asynchronous_mode(basePointer) \
   (basePointer->CONFIG_CLR = SI32_USART_A_CONFIG_TSYNCEN_MASK)


/// @fn _SI32_USART_A_select_tx_synchronous_mode(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_select_tx_synchronous_mode(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_select_tx_synchronous_mode(basePointer)
#define SI32_USART_A_select_tx_synchronous_mode(basePointer) \
   (basePointer->CONFIG_SET = SI32_USART_A_CONFIG_TSYNCEN_ENABLED_U32)


/// @fn _SI32_USART_A_write_mode(SI32_USART_A_Type* basePointer,
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
_SI32_USART_A_write_mode(SI32_USART_A_Type* /*basePointer*/,
   uint32_t /*mode*/);
///
/// @def SI32_USART_A_write_mode(basePointer, mode)
#define SI32_USART_A_write_mode(basePointer, mode) \
   (basePointer->MODE.U32 = mode)


/// @fn _SI32_USART_A_read_mode(SI32_USART_A_Type* basePointer)
///
/// @brief
/// Reads MODE register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USART_A_read_mode(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_read_mode(basePointer)
#define SI32_USART_A_read_mode(basePointer) \
(basePointer->MODE.U32)


/// @fn _SI32_USART_A_enable_stall_in_debug_mode(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_stall_in_debug_mode(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_stall_in_debug_mode(basePointer)
#define SI32_USART_A_enable_stall_in_debug_mode(basePointer) \
   (basePointer->MODE_SET = SI32_USART_A_MODE_DBGMD_HALT_U32)


/// @fn _SI32_USART_A_disable_stall_in_debug_mode(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_stall_in_debug_mode(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_stall_in_debug_mode(basePointer)
#define SI32_USART_A_disable_stall_in_debug_mode(basePointer) \
   (basePointer->MODE_CLR = SI32_USART_A_MODE_DBGMD_MASK)


/// @fn _SI32_USART_A_exit_loopback_mode(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_exit_loopback_mode(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_exit_loopback_mode(basePointer)
#define SI32_USART_A_exit_loopback_mode(basePointer) \
   (basePointer->MODE_CLR = SI32_USART_A_MODE_LBMD_MASK)


/// @fn _SI32_USART_A_enter_receive_loopback_mode(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enter_receive_loopback_mode(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enter_receive_loopback_mode(basePointer)
#define SI32_USART_A_enter_receive_loopback_mode(basePointer) do{  \
   basePointer->MODE_CLR = SI32_USART_A_MODE_LBMD_MASK;\
   basePointer->MODE_SET = SI32_USART_A_MODE_LBMD_RXONLY_U32;\
} while(0)


/// @fn _SI32_USART_A_enter_transmit_loopback_mode(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enter_transmit_loopback_mode(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enter_transmit_loopback_mode(basePointer)
#define SI32_USART_A_enter_transmit_loopback_mode(basePointer) do{  \
   basePointer->MODE_CLR = SI32_USART_A_MODE_LBMD_MASK;\
   basePointer->MODE_SET = SI32_USART_A_MODE_LBMD_TXONLY_U32;\
} while(0)


/// @fn _SI32_USART_A_enter_full_loopback_mode(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enter_full_loopback_mode(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enter_full_loopback_mode(basePointer)
#define SI32_USART_A_enter_full_loopback_mode(basePointer) \
   (basePointer->MODE_SET = SI32_USART_A_MODE_LBMD_BOTH_U32)


/// @fn _SI32_USART_A_enable_master_generate_clock_during_stop(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_master_generate_clock_during_stop(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_master_generate_clock_during_stop(basePointer)
#define SI32_USART_A_enable_master_generate_clock_during_stop(basePointer) \
   (basePointer->MODE_SET = SI32_USART_A_MODE_STPSTCLK_ENABLED_U32)


/// @fn _SI32_USART_A_disable_master_generate_clock_during_stop(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_master_generate_clock_during_stop(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_master_generate_clock_during_stop(basePointer)
#define SI32_USART_A_disable_master_generate_clock_during_stop(basePointer) \
   (basePointer->MODE_CLR = SI32_USART_A_MODE_STPSTCLK_MASK)


/// @fn _SI32_USART_A_enable_master_generate_clock_during_start(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_master_generate_clock_during_start(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_master_generate_clock_during_start(basePointer)
#define SI32_USART_A_enable_master_generate_clock_during_start(basePointer) \
   (basePointer->MODE_SET = SI32_USART_A_MODE_STRTSTCLK_ENABLED_U32)


/// @fn _SI32_USART_A_disable_master_generate_clock_during_start(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_master_generate_clock_during_start(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_master_generate_clock_during_start(basePointer)
#define SI32_USART_A_disable_master_generate_clock_during_start(basePointer) \
   (basePointer->MODE_CLR = SI32_USART_A_MODE_STRTSTCLK_MASK)


/// @fn _SI32_USART_A_enable_master_generate_clock_between_transfers(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_master_generate_clock_between_transfers(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_master_generate_clock_between_transfers(basePointer)
#define SI32_USART_A_enable_master_generate_clock_between_transfers(basePointer) \
   (basePointer->MODE_SET = SI32_USART_A_MODE_ISTCLK_ENABLED_U32)


/// @fn _SI32_USART_A_disable_master_generate_clock_between_transfers(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_master_generate_clock_between_transfers(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_master_generate_clock_between_transfers(basePointer)
#define SI32_USART_A_disable_master_generate_clock_between_transfers(basePointer) \
   (basePointer->MODE_CLR = SI32_USART_A_MODE_ISTCLK_MASK)


/// @fn _SI32_USART_A_enter_half_duplex_mode(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enter_half_duplex_mode(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enter_half_duplex_mode(basePointer)
#define SI32_USART_A_enter_half_duplex_mode(basePointer) \
   (basePointer->MODE_SET = SI32_USART_A_MODE_DUPLEXMD_HALF_DUPLEX_U32)


/// @fn _SI32_USART_A_enter_full_duplex_mode(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enter_full_duplex_mode(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enter_full_duplex_mode(basePointer)
#define SI32_USART_A_enter_full_duplex_mode(basePointer) \
   (basePointer->MODE_CLR = SI32_USART_A_MODE_DUPLEXMD_MASK)


/// @fn _SI32_USART_A_select_sync_clock_low_during_idle(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_select_sync_clock_low_during_idle(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_select_sync_clock_low_during_idle(basePointer)
#define SI32_USART_A_select_sync_clock_low_during_idle(basePointer) \
   (basePointer->MODE_CLR = SI32_USART_A_MODE_CLKIDLE_MASK)


/// @fn _SI32_USART_A_select_sync_clock_high_during_idle(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_select_sync_clock_high_during_idle(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_select_sync_clock_high_during_idle(basePointer)
#define SI32_USART_A_select_sync_clock_high_during_idle(basePointer) \
   (basePointer->MODE_SET = SI32_USART_A_MODE_CLKIDLE_IDLE_HIGH_U32)


/// @fn _SI32_USART_A_select_clock_edge_falling(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_select_clock_edge_falling(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_select_clock_edge_falling(basePointer)
#define SI32_USART_A_select_clock_edge_falling(basePointer) \
   (basePointer->MODE_CLR = SI32_USART_A_MODE_CLKESEL_MASK)


/// @fn _SI32_USART_A_select_clock_edge_rising(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_select_clock_edge_rising(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_select_clock_edge_rising(basePointer)
#define SI32_USART_A_select_clock_edge_rising(basePointer) \
   (basePointer->MODE_SET = SI32_USART_A_MODE_CLKESEL_RISING_U32)


/// @fn _SI32_USART_A_disable_idle_tristate(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_idle_tristate(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_idle_tristate(basePointer)
#define SI32_USART_A_disable_idle_tristate(basePointer) \
   (basePointer->MODE_CLR = SI32_USART_A_MODE_ITSEN_MASK)


/// @fn _SI32_USART_A_enable_idle_tristate(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_idle_tristate(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_idle_tristate(basePointer)
#define SI32_USART_A_enable_idle_tristate(basePointer) \
   (basePointer->MODE_SET = SI32_USART_A_MODE_ITSEN_ENABLED_U32)


/// @fn _SI32_USART_A_enter_master_mode(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enter_master_mode(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enter_master_mode(basePointer)
#define SI32_USART_A_enter_master_mode(basePointer) \
   (basePointer->MODE_SET = SI32_USART_A_MODE_OPMD_MASTER_U32)


/// @fn _SI32_USART_A_enter_slave_mode(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enter_slave_mode(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enter_slave_mode(basePointer)
#define SI32_USART_A_enter_slave_mode(basePointer) \
   (basePointer->MODE_CLR = SI32_USART_A_MODE_OPMD_MASK)


/// @fn _SI32_USART_A_write_flowcn(SI32_USART_A_Type* basePointer,
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
_SI32_USART_A_write_flowcn(SI32_USART_A_Type* /*basePointer*/,
   uint32_t /*flowcn*/);
///
/// @def SI32_USART_A_write_flowcn(basePointer, flowcn)
#define SI32_USART_A_write_flowcn(basePointer, flowcn) \
   (basePointer->FLOWCN.U32 = flowcn)


/// @fn _SI32_USART_A_read_flowcn(SI32_USART_A_Type* basePointer)
///
/// @brief
/// Reads FLOWCN register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USART_A_read_flowcn(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_read_flowcn(basePointer)
#define SI32_USART_A_read_flowcn(basePointer) \
(basePointer->FLOWCN.U32)


/// @fn _SI32_USART_A_clear_rts(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_clear_rts(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_clear_rts(basePointer)
#define SI32_USART_A_clear_rts(basePointer) \
   (basePointer->FLOWCN_CLR = SI32_USART_A_FLOWCN_RTS_MASK)


/// @fn _SI32_USART_A_set_rts(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_set_rts(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_set_rts(basePointer)
#define SI32_USART_A_set_rts(basePointer) \
   (basePointer->FLOWCN_SET = SI32_USART_A_FLOWCN_RTS_HIGH_U32)


/// @fn _SI32_USART_A_read_rts_output(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_read_rts_output(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_read_rts_output(basePointer)
#define SI32_USART_A_read_rts_output(basePointer) \
((bool)(basePointer->FLOWCN.RTS))


/// @fn _SI32_USART_A_read_rx_input(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_read_rx_input(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_read_rx_input(basePointer)
#define SI32_USART_A_read_rx_input(basePointer) \
((bool)(basePointer->FLOWCN.RX))


/// @fn _SI32_USART_A_enable_rts_inversion(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_rts_inversion(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_rts_inversion(basePointer)
#define SI32_USART_A_enable_rts_inversion(basePointer) \
   (basePointer->FLOWCN_SET = SI32_USART_A_FLOWCN_RTSINVEN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_rts_inversion(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_rts_inversion(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_rts_inversion(basePointer)
#define SI32_USART_A_disable_rts_inversion(basePointer) \
   (basePointer->FLOWCN_CLR = SI32_USART_A_FLOWCN_RTSINVEN_MASK)


/// @fn _SI32_USART_A_select_rts_deassert_on_full(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_select_rts_deassert_on_full(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_select_rts_deassert_on_full(basePointer)
#define SI32_USART_A_select_rts_deassert_on_full(basePointer) \
   (basePointer->FLOWCN_CLR = SI32_USART_A_FLOWCN_RTSTH_MASK)


/// @fn _SI32_USART_A_select_rts_deassert_on_byte_free(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_select_rts_deassert_on_byte_free(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_select_rts_deassert_on_byte_free(basePointer)
#define SI32_USART_A_select_rts_deassert_on_byte_free(basePointer) \
   (basePointer->FLOWCN_SET = SI32_USART_A_FLOWCN_RTSTH_ONE_BYTE_FREE_U32)


/// @fn _SI32_USART_A_enable_rts(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_rts(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_rts(basePointer)
#define SI32_USART_A_enable_rts(basePointer) \
   (basePointer->FLOWCN_SET = SI32_USART_A_FLOWCN_RTSEN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_rts(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_rts(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_rts(basePointer)
#define SI32_USART_A_disable_rts(basePointer) \
   (basePointer->FLOWCN_CLR = SI32_USART_A_FLOWCN_RTSEN_MASK)


/// @fn _SI32_USART_A_read_cts_input(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_read_cts_input(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_read_cts_input(basePointer)
#define SI32_USART_A_read_cts_input(basePointer) \
((bool)(basePointer->FLOWCN.CTS))


/// @fn _SI32_USART_A_read_tx_output(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_read_tx_output(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_read_tx_output(basePointer)
#define SI32_USART_A_read_tx_output(basePointer) \
((bool)(basePointer->FLOWCN.TX))


/// @fn _SI32_USART_A_clear_tx(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_clear_tx(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_clear_tx(basePointer)
#define SI32_USART_A_clear_tx(basePointer) \
   (basePointer->FLOWCN_CLR = SI32_USART_A_FLOWCN_TX_MASK)


/// @fn _SI32_USART_A_set_tx(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_set_tx(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_set_tx(basePointer)
#define SI32_USART_A_set_tx(basePointer) \
   (basePointer->FLOWCN_SET = SI32_USART_A_FLOWCN_TX_HIGH_U32)


/// @fn _SI32_USART_A_set_sync_clock_low(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_set_sync_clock_low(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_set_sync_clock_low(basePointer)
#define SI32_USART_A_set_sync_clock_low(basePointer) \
   (basePointer->FLOWCN_CLR = SI32_USART_A_FLOWCN_UCLK_MASK)


/// @fn _SI32_USART_A_set_sync_clock_high(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_set_sync_clock_high(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_set_sync_clock_high(basePointer)
#define SI32_USART_A_set_sync_clock_high(basePointer) \
   (basePointer->FLOWCN_SET = SI32_USART_A_FLOWCN_UCLK_HIGH_U32)


/// @fn _SI32_USART_A_read_sync_clock(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_read_sync_clock(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_read_sync_clock(basePointer)
#define SI32_USART_A_read_sync_clock(basePointer) \
((bool)(basePointer->FLOWCN.UCLK))


/// @fn _SI32_USART_A_enable_cts_inversion(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_cts_inversion(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_cts_inversion(basePointer)
#define SI32_USART_A_enable_cts_inversion(basePointer) \
   (basePointer->FLOWCN_SET = SI32_USART_A_FLOWCN_CTSINVEN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_cts_inversion(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_cts_inversion(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_cts_inversion(basePointer)
#define SI32_USART_A_disable_cts_inversion(basePointer) \
   (basePointer->FLOWCN_CLR = SI32_USART_A_FLOWCN_CTSINVEN_MASK)


/// @fn _SI32_USART_A_enable_cts(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_cts(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_cts(basePointer)
#define SI32_USART_A_enable_cts(basePointer) \
   (basePointer->FLOWCN_SET = SI32_USART_A_FLOWCN_CTSEN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_cts(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_cts(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_cts(basePointer)
#define SI32_USART_A_disable_cts(basePointer) \
   (basePointer->FLOWCN_CLR = SI32_USART_A_FLOWCN_CTSEN_MASK)


/// @fn _SI32_USART_A_select_tx_irda_pulse_width(SI32_USART_A_Type* basePointer,
///      uint32_t width)
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
_SI32_USART_A_select_tx_irda_pulse_width(SI32_USART_A_Type* /*basePointer*/,
   uint32_t /*width*/);
///
/// @def SI32_USART_A_select_tx_irda_pulse_width(basePointer, width)
#define SI32_USART_A_select_tx_irda_pulse_width(basePointer, width) do{  \
   basePointer->FLOWCN_CLR = SI32_USART_A_FLOWCN_TIRDAPW_MASK;\
   basePointer->FLOWCN_SET = width << SI32_USART_A_FLOWCN_TIRDAPW_SHIFT;\
} while(0)


/// @fn _SI32_USART_A_write_control(SI32_USART_A_Type* basePointer,
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
_SI32_USART_A_write_control(SI32_USART_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_USART_A_write_control(basePointer, control)
#define SI32_USART_A_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_USART_A_read_control(SI32_USART_A_Type* basePointer)
///
/// @brief
/// Reads CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USART_A_read_control(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_read_control(basePointer)
#define SI32_USART_A_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_USART_A_is_rx_frame_error_interrupt_pending(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_is_rx_frame_error_interrupt_pending(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_is_rx_frame_error_interrupt_pending(basePointer)
#define SI32_USART_A_is_rx_frame_error_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.RFRMERI))


/// @fn _SI32_USART_A_clear_rx_frame_error_interrupt(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_clear_rx_frame_error_interrupt(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_clear_rx_frame_error_interrupt(basePointer)
#define SI32_USART_A_clear_rx_frame_error_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_USART_A_CONTROL_RFRMERI_MASK)


/// @fn _SI32_USART_A_is_rx_parity_error_interrupt_pending(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_is_rx_parity_error_interrupt_pending(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_is_rx_parity_error_interrupt_pending(basePointer)
#define SI32_USART_A_is_rx_parity_error_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.RPARERI))


/// @fn _SI32_USART_A_clear_rx_parity_error_interrupt(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_clear_rx_parity_error_interrupt(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_clear_rx_parity_error_interrupt(basePointer)
#define SI32_USART_A_clear_rx_parity_error_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_USART_A_CONTROL_RPARERI_MASK)


/// @fn _SI32_USART_A_is_rx_overrun_interrupt_pending(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_is_rx_overrun_interrupt_pending(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_is_rx_overrun_interrupt_pending(basePointer)
#define SI32_USART_A_is_rx_overrun_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.ROREI))


/// @fn _SI32_USART_A_clear_rx_overrun_error_interrupt(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_clear_rx_overrun_error_interrupt(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_clear_rx_overrun_error_interrupt(basePointer)
#define SI32_USART_A_clear_rx_overrun_error_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_USART_A_CONTROL_ROREI_MASK)


/// @fn _SI32_USART_A_is_rx_data_request_interrupt_pending(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_is_rx_data_request_interrupt_pending(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_is_rx_data_request_interrupt_pending(basePointer)
#define SI32_USART_A_is_rx_data_request_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.RDREQI))


/// @fn _SI32_USART_A_clear_rx_data_request_interrupt(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_clear_rx_data_request_interrupt(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_clear_rx_data_request_interrupt(basePointer)
#define SI32_USART_A_clear_rx_data_request_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_USART_A_CONTROL_RDREQI_MASK)


/// @fn _SI32_USART_A_enable_rx_error_interrupts(SI32_USART_A_Type* basePointer)
///
/// @brief
/// Enables the receive overrun error, frame error, and parity error
/// interrupts.
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_rx_error_interrupts(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_rx_error_interrupts(basePointer)
#define SI32_USART_A_enable_rx_error_interrupts(basePointer) \
   (basePointer->CONTROL_SET = SI32_USART_A_CONTROL_RERIEN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_rx_error_interrupts(SI32_USART_A_Type* basePointer)
///
/// @brief
/// Disables the receive overrun error, frame error, and parity error
/// interrupts.
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_rx_error_interrupts(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_rx_error_interrupts(basePointer)
#define SI32_USART_A_disable_rx_error_interrupts(basePointer) \
   (basePointer->CONTROL_CLR = SI32_USART_A_CONTROL_RERIEN_MASK)


/// @fn _SI32_USART_A_is_rx_error_interrupts_enabled(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_is_rx_error_interrupts_enabled(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_is_rx_error_interrupts_enabled(basePointer)
#define SI32_USART_A_is_rx_error_interrupts_enabled(basePointer) \
((bool)(basePointer->CONTROL.RERIEN))


/// @fn _SI32_USART_A_enable_rx_data_request_interrupt(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_rx_data_request_interrupt(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_rx_data_request_interrupt(basePointer)
#define SI32_USART_A_enable_rx_data_request_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_USART_A_CONTROL_RDREQIEN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_rx_data_request_interrupt(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_rx_data_request_interrupt(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_rx_data_request_interrupt(basePointer)
#define SI32_USART_A_disable_rx_data_request_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_USART_A_CONTROL_RDREQIEN_MASK)


/// @fn _SI32_USART_A_is_rx_data_request_interrupt_enabled(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_is_rx_data_request_interrupt_enabled(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_is_rx_data_request_interrupt_enabled(basePointer)
#define SI32_USART_A_is_rx_data_request_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.RDREQIEN))


/// @fn _SI32_USART_A_exit_match_mode(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_exit_match_mode(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_exit_match_mode(basePointer)
#define SI32_USART_A_exit_match_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_USART_A_CONTROL_MATMD_MASK)


/// @fn _SI32_USART_A_enter_match_mode_store_byte(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enter_match_mode_store_byte(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enter_match_mode_store_byte(basePointer)
#define SI32_USART_A_enter_match_mode_store_byte(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_USART_A_CONTROL_MATMD_MASK;\
   basePointer->CONTROL_SET = SI32_USART_A_CONTROL_MATMD_MCE_U32;\
} while(0)


/// @fn _SI32_USART_A_enter_match_mode_generate_frame_error(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enter_match_mode_generate_frame_error(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enter_match_mode_generate_frame_error(basePointer)
#define SI32_USART_A_enter_match_mode_generate_frame_error(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_USART_A_CONTROL_MATMD_MASK;\
   basePointer->CONTROL_SET = SI32_USART_A_CONTROL_MATMD_FRAME_U32;\
} while(0)


/// @fn _SI32_USART_A_enter_match_mode_store_bit(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enter_match_mode_store_bit(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enter_match_mode_store_bit(basePointer)
#define SI32_USART_A_enter_match_mode_store_bit(basePointer) \
   (basePointer->CONTROL_SET = SI32_USART_A_CONTROL_MATMD_STORE_U32)


/// @fn _SI32_USART_A_enable_rx_autobaud(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_rx_autobaud(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_rx_autobaud(basePointer)
#define SI32_USART_A_enable_rx_autobaud(basePointer) \
   (basePointer->CONTROL_SET = SI32_USART_A_CONTROL_RABDEN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_rx_autobaud(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_rx_autobaud(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_rx_autobaud(basePointer)
#define SI32_USART_A_disable_rx_autobaud(basePointer) \
   (basePointer->CONTROL_CLR = SI32_USART_A_CONTROL_RABDEN_MASK)


/// @fn _SI32_USART_A_is_rx_busy(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_is_rx_busy(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_is_rx_busy(basePointer)
#define SI32_USART_A_is_rx_busy(basePointer) \
((bool)(basePointer->CONTROL.RBUSYF))


/// @fn _SI32_USART_A_set_rbit(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_set_rbit(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_set_rbit(basePointer)
#define SI32_USART_A_set_rbit(basePointer) \
   (basePointer->CONTROL_SET = SI32_USART_A_CONTROL_RBIT_SET_U32)


/// @fn _SI32_USART_A_clear_rbit(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_clear_rbit(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_clear_rbit(basePointer)
#define SI32_USART_A_clear_rbit(basePointer) \
   (basePointer->CONTROL_CLR = SI32_USART_A_CONTROL_RBIT_MASK)


/// @fn _SI32_USART_A_read_rbit(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_read_rbit(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_read_rbit(basePointer)
#define SI32_USART_A_read_rbit(basePointer) \
((bool)(basePointer->CONTROL.RBIT))


/// @fn _SI32_USART_A_enable_rx_one_shot(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_rx_one_shot(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_rx_one_shot(basePointer)
#define SI32_USART_A_enable_rx_one_shot(basePointer) \
   (basePointer->CONTROL_SET = SI32_USART_A_CONTROL_ROSEN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_rx_one_shot(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_rx_one_shot(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_rx_one_shot(basePointer)
#define SI32_USART_A_disable_rx_one_shot(basePointer) \
   (basePointer->CONTROL_CLR = SI32_USART_A_CONTROL_ROSEN_MASK)


/// @fn _SI32_USART_A_enable_rx_inhibit(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_rx_inhibit(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_rx_inhibit(basePointer)
#define SI32_USART_A_enable_rx_inhibit(basePointer) \
   (basePointer->CONTROL_SET = SI32_USART_A_CONTROL_RINH_ACTIVE_U32)


/// @fn _SI32_USART_A_disable_rx_inhibit(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_rx_inhibit(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_rx_inhibit(basePointer)
#define SI32_USART_A_disable_rx_inhibit(basePointer) \
   (basePointer->CONTROL_CLR = SI32_USART_A_CONTROL_RINH_MASK)


/// @fn _SI32_USART_A_enable_rx(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_rx(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_rx(basePointer)
#define SI32_USART_A_enable_rx(basePointer) \
   (basePointer->CONTROL_SET = SI32_USART_A_CONTROL_REN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_rx(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_rx(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_rx(basePointer)
#define SI32_USART_A_disable_rx(basePointer) \
   (basePointer->CONTROL_CLR = SI32_USART_A_CONTROL_REN_MASK)


/// @fn _SI32_USART_A_is_tx_smartcard_parity_error_interrupt_pending(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_is_tx_smartcard_parity_error_interrupt_pending(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_is_tx_smartcard_parity_error_interrupt_pending(basePointer)
#define SI32_USART_A_is_tx_smartcard_parity_error_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.TSCERI))


/// @fn _SI32_USART_A_clear_tx_smartcard_parity_error_interrupt(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_clear_tx_smartcard_parity_error_interrupt(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_clear_tx_smartcard_parity_error_interrupt(basePointer)
#define SI32_USART_A_clear_tx_smartcard_parity_error_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_USART_A_CONTROL_TSCERI_MASK)


/// @fn _SI32_USART_A_is_tx_underrun_interrupt_pending(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_is_tx_underrun_interrupt_pending(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_is_tx_underrun_interrupt_pending(basePointer)
#define SI32_USART_A_is_tx_underrun_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.TUREI))


/// @fn _SI32_USART_A_clear_tx_underrun_interrupt(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_clear_tx_underrun_interrupt(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_clear_tx_underrun_interrupt(basePointer)
#define SI32_USART_A_clear_tx_underrun_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_USART_A_CONTROL_TUREI_MASK)


/// @fn _SI32_USART_A_is_tx_data_request_interrupt_pending(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_is_tx_data_request_interrupt_pending(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_is_tx_data_request_interrupt_pending(basePointer)
#define SI32_USART_A_is_tx_data_request_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.TDREQI))


/// @fn _SI32_USART_A_is_tx_complete(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_is_tx_complete(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_is_tx_complete(basePointer)
#define SI32_USART_A_is_tx_complete(basePointer) \
((bool)(basePointer->CONTROL.TCPTI))


/// @fn _SI32_USART_A_clear_tx_complete_interrupt(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_clear_tx_complete_interrupt(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_clear_tx_complete_interrupt(basePointer)
#define SI32_USART_A_clear_tx_complete_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_USART_A_CONTROL_TCPTI_MASK)


/// @fn _SI32_USART_A_select_tx_complete_threshold_end_of_transmission(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_select_tx_complete_threshold_end_of_transmission(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_select_tx_complete_threshold_end_of_transmission(basePointer)
#define SI32_USART_A_select_tx_complete_threshold_end_of_transmission(basePointer) \
   (basePointer->CONTROL_CLR = SI32_USART_A_CONTROL_TCPTTH_MASK)


/// @fn _SI32_USART_A_select_tx_complete_threshold_no_more_data(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_select_tx_complete_threshold_no_more_data(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_select_tx_complete_threshold_no_more_data(basePointer)
#define SI32_USART_A_select_tx_complete_threshold_no_more_data(basePointer) \
   (basePointer->CONTROL_SET = SI32_USART_A_CONTROL_TCPTTH_SET_ON_EMPTY_U32)


/// @fn _SI32_USART_A_enable_tx_error_interrupts(SI32_USART_A_Type* basePointer)
///
/// @brief
/// Enables the transmit underrun error, frame error, and smart card
/// parity error interrupts.
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_tx_error_interrupts(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_tx_error_interrupts(basePointer)
#define SI32_USART_A_enable_tx_error_interrupts(basePointer) \
   (basePointer->CONTROL_SET = SI32_USART_A_CONTROL_TERIEN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_tx_error_interrupts(SI32_USART_A_Type* basePointer)
///
/// @brief
/// Disables the transmit underrun error, frame error, and smart card
/// parity error interrupts.
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_tx_error_interrupts(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_tx_error_interrupts(basePointer)
#define SI32_USART_A_disable_tx_error_interrupts(basePointer) \
   (basePointer->CONTROL_CLR = SI32_USART_A_CONTROL_TERIEN_MASK)


/// @fn _SI32_USART_A_is_tx_error_interrupts_enabled(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_is_tx_error_interrupts_enabled(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_is_tx_error_interrupts_enabled(basePointer)
#define SI32_USART_A_is_tx_error_interrupts_enabled(basePointer) \
((bool)(basePointer->CONTROL.TERIEN))


/// @fn _SI32_USART_A_enable_tx_data_request_interrupt(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_tx_data_request_interrupt(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_tx_data_request_interrupt(basePointer)
#define SI32_USART_A_enable_tx_data_request_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_USART_A_CONTROL_TDREQIEN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_tx_data_request_interrupt(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_tx_data_request_interrupt(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_tx_data_request_interrupt(basePointer)
#define SI32_USART_A_disable_tx_data_request_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_USART_A_CONTROL_TDREQIEN_MASK)


/// @fn _SI32_USART_A_is_tx_data_request_interrupt_enabled(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_is_tx_data_request_interrupt_enabled(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_is_tx_data_request_interrupt_enabled(basePointer)
#define SI32_USART_A_is_tx_data_request_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.TDREQIEN))


/// @fn _SI32_USART_A_enable_tx_complete_interrupt(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_tx_complete_interrupt(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_tx_complete_interrupt(basePointer)
#define SI32_USART_A_enable_tx_complete_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_USART_A_CONTROL_TCPTIEN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_tx_complete_interrupt(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_tx_complete_interrupt(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_tx_complete_interrupt(basePointer)
#define SI32_USART_A_disable_tx_complete_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_USART_A_CONTROL_TCPTIEN_MASK)


/// @fn _SI32_USART_A_is_tx_complete_interrupt_enabled(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_is_tx_complete_interrupt_enabled(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_is_tx_complete_interrupt_enabled(basePointer)
#define SI32_USART_A_is_tx_complete_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.TCPTIEN))


/// @fn _SI32_USART_A_is_tx_busy(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_is_tx_busy(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_is_tx_busy(basePointer)
#define SI32_USART_A_is_tx_busy(basePointer) \
((bool)(basePointer->CONTROL.TBUSYF))


/// @fn _SI32_USART_A_set_tbit(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_set_tbit(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_set_tbit(basePointer)
#define SI32_USART_A_set_tbit(basePointer) \
   (basePointer->CONTROL_SET = SI32_USART_A_CONTROL_TBIT_SET_U32)


/// @fn _SI32_USART_A_clear_tbit(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_clear_tbit(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_clear_tbit(basePointer)
#define SI32_USART_A_clear_tbit(basePointer) \
   (basePointer->CONTROL_CLR = SI32_USART_A_CONTROL_TBIT_MASK)


/// @fn _SI32_USART_A_enable_tx_inhibit(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_tx_inhibit(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_tx_inhibit(basePointer)
#define SI32_USART_A_enable_tx_inhibit(basePointer) \
   (basePointer->CONTROL_SET = SI32_USART_A_CONTROL_TINH_ACTIVE_U32)


/// @fn _SI32_USART_A_disable_tx_inhibit(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_tx_inhibit(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_tx_inhibit(basePointer)
#define SI32_USART_A_disable_tx_inhibit(basePointer) \
   (basePointer->CONTROL_CLR = SI32_USART_A_CONTROL_TINH_MASK)


/// @fn _SI32_USART_A_enable_tx(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_tx(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_tx(basePointer)
#define SI32_USART_A_enable_tx(basePointer) \
   (basePointer->CONTROL_SET = SI32_USART_A_CONTROL_TEN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_tx(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_tx(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_tx(basePointer)
#define SI32_USART_A_disable_tx(basePointer) \
   (basePointer->CONTROL_CLR = SI32_USART_A_CONTROL_TEN_MASK)


/// @fn _SI32_USART_A_write_ipdelay(SI32_USART_A_Type* basePointer,
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
_SI32_USART_A_write_ipdelay(SI32_USART_A_Type* /*basePointer*/,
   uint32_t /*ipdelay*/);
///
/// @def SI32_USART_A_write_ipdelay(basePointer, ipdelay)
#define SI32_USART_A_write_ipdelay(basePointer, ipdelay) \
   (basePointer->IPDELAY.U32 = ipdelay)


/// @fn _SI32_USART_A_read_ipdelay(SI32_USART_A_Type* basePointer)
///
/// @brief
/// Reads IPDELAY register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USART_A_read_ipdelay(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_read_ipdelay(basePointer)
#define SI32_USART_A_read_ipdelay(basePointer) \
(basePointer->IPDELAY.U32)


/// @fn _SI32_USART_A_write_ipdelay_bits(SI32_USART_A_Type* basePointer,
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
_SI32_USART_A_write_ipdelay_bits(SI32_USART_A_Type* /*basePointer*/,
   uint32_t /*ipdelay*/);
///
/// @def SI32_USART_A_write_ipdelay_bits(basePointer, ipdelay)
#define SI32_USART_A_write_ipdelay_bits(basePointer, ipdelay) \
   (basePointer->IPDELAY.IPDELAY_BITS = ipdelay)


/// @fn _SI32_USART_A_read_ipdelay_bits(SI32_USART_A_Type* basePointer)
///
/// @brief
/// Reads IPDELAY bitfield.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USART_A_read_ipdelay_bits(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_read_ipdelay_bits(basePointer)
#define SI32_USART_A_read_ipdelay_bits(basePointer) \
(basePointer->IPDELAY.IPDELAY_BITS)


/// @fn _SI32_USART_A_write_baudrate(SI32_USART_A_Type* basePointer,
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
_SI32_USART_A_write_baudrate(SI32_USART_A_Type* /*basePointer*/,
   uint32_t /*baudrate*/);
///
/// @def SI32_USART_A_write_baudrate(basePointer, baudrate)
#define SI32_USART_A_write_baudrate(basePointer, baudrate) \
   (basePointer->BAUDRATE.U32 = baudrate)


/// @fn _SI32_USART_A_read_baudrate(SI32_USART_A_Type* basePointer)
///
/// @brief
/// Reads BAUDRATE register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USART_A_read_baudrate(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_read_baudrate(basePointer)
#define SI32_USART_A_read_baudrate(basePointer) \
(basePointer->BAUDRATE.U32)


/// @fn _SI32_USART_A_set_rx_baudrate(SI32_USART_A_Type* basePointer,
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
_SI32_USART_A_set_rx_baudrate(SI32_USART_A_Type* /*basePointer*/,
   uwide16_t /*rxbaud*/);
///
/// @def SI32_USART_A_set_rx_baudrate(basePointer, rxbaud)
#define SI32_USART_A_set_rx_baudrate(basePointer, rxbaud) \
   (basePointer->BAUDRATE.RBAUD = rxbaud)


/// @fn _SI32_USART_A_set_tx_baudrate(SI32_USART_A_Type* basePointer,
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
_SI32_USART_A_set_tx_baudrate(SI32_USART_A_Type* /*basePointer*/,
   uwide16_t /*txbaud*/);
///
/// @def SI32_USART_A_set_tx_baudrate(basePointer, txbaud)
#define SI32_USART_A_set_tx_baudrate(basePointer, txbaud) \
   (basePointer->BAUDRATE.TBAUD = txbaud)


/// @fn _SI32_USART_A_write_fifocn(SI32_USART_A_Type* basePointer,
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
_SI32_USART_A_write_fifocn(SI32_USART_A_Type* /*basePointer*/,
   uint32_t /*fifocn*/);
///
/// @def SI32_USART_A_write_fifocn(basePointer, fifocn)
#define SI32_USART_A_write_fifocn(basePointer, fifocn) \
   _SI32_USART_A_write_fifocn(basePointer, fifocn) 


/// @fn _SI32_USART_A_read_fifocn(SI32_USART_A_Type* basePointer)
///
/// @brief
/// Reads FIFOCN register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USART_A_read_fifocn(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_read_fifocn(basePointer)
#define SI32_USART_A_read_fifocn(basePointer) \
(basePointer->FIFOCN.U32)


/// @fn _SI32_USART_A_read_rx_fifo_count(SI32_USART_A_Type* basePointer)
///
/// @brief
/// Returns number of bytes in receive FIFO.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USART_A_read_rx_fifo_count(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_read_rx_fifo_count(basePointer)
#define SI32_USART_A_read_rx_fifo_count(basePointer) \
((uint32_t)(basePointer->FIFOCN.RCNT))


/// @fn _SI32_USART_A_select_rx_fifo_threshold_1(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_select_rx_fifo_threshold_1(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_select_rx_fifo_threshold_1(basePointer)
#define SI32_USART_A_select_rx_fifo_threshold_1(basePointer) \
   (basePointer->FIFOCN_CLR = SI32_USART_A_FIFOCN_RFTH_MASK)


/// @fn _SI32_USART_A_select_rx_fifo_threshold_2(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_select_rx_fifo_threshold_2(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_select_rx_fifo_threshold_2(basePointer)
#define SI32_USART_A_select_rx_fifo_threshold_2(basePointer) do{  \
   basePointer->FIFOCN_CLR = SI32_USART_A_FIFOCN_RFTH_MASK;\
   basePointer->FIFOCN_SET = SI32_USART_A_FIFOCN_RFTH_TWO_U32;\
} while(0)


/// @fn _SI32_USART_A_select_rx_fifo_threshold_4(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_select_rx_fifo_threshold_4(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_select_rx_fifo_threshold_4(basePointer)
#define SI32_USART_A_select_rx_fifo_threshold_4(basePointer) do{  \
   basePointer->FIFOCN_CLR = SI32_USART_A_FIFOCN_RFTH_MASK;\
   basePointer->FIFOCN_SET = SI32_USART_A_FIFOCN_RFTH_FOUR_U32;\
} while(0)


/// @fn _SI32_USART_A_enable_rx_fifo_dma_request(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_rx_fifo_dma_request(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_rx_fifo_dma_request(basePointer)
#define SI32_USART_A_enable_rx_fifo_dma_request(basePointer) \
   (basePointer->FIFOCN_SET = SI32_USART_A_FIFOCN_RDMAEN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_rx_fifo_dma_request(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_rx_fifo_dma_request(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_rx_fifo_dma_request(basePointer)
#define SI32_USART_A_disable_rx_fifo_dma_request(basePointer) \
   (basePointer->FIFOCN_CLR = SI32_USART_A_FIFOCN_RDMAEN_MASK)


/// @fn _SI32_USART_A_flush_rx_fifo(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_flush_rx_fifo(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_flush_rx_fifo(basePointer)
#define SI32_USART_A_flush_rx_fifo(basePointer) \
   (basePointer->FIFOCN_SET = SI32_USART_A_FIFOCN_RFIFOFL_SET_U32)


/// @fn _SI32_USART_A_is_rx_fifo_error_interrupt_pending(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_is_rx_fifo_error_interrupt_pending(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_is_rx_fifo_error_interrupt_pending(basePointer)
#define SI32_USART_A_is_rx_fifo_error_interrupt_pending(basePointer) \
((bool)(basePointer->FIFOCN.RFERI))


/// @fn _SI32_USART_A_clear_rx_fifo_error_interrupt(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_clear_rx_fifo_error_interrupt(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_clear_rx_fifo_error_interrupt(basePointer)
#define SI32_USART_A_clear_rx_fifo_error_interrupt(basePointer) \
   (basePointer->FIFOCN_CLR = SI32_USART_A_FIFOCN_RFERI_MASK)


/// @fn _SI32_USART_A_is_rx_shift_register_full(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_is_rx_shift_register_full(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_is_rx_shift_register_full(basePointer)
#define SI32_USART_A_is_rx_shift_register_full(basePointer) \
((bool)(basePointer->FIFOCN.RSRFULLF))


/// @fn _SI32_USART_A_read_tx_fifo_count(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USART_A_read_tx_fifo_count(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_read_tx_fifo_count(basePointer)
#define SI32_USART_A_read_tx_fifo_count(basePointer) \
((uint32_t)(basePointer->FIFOCN.TCNT))


/// @fn _SI32_USART_A_select_tx_fifo_threshold_for_request_to_1(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_select_tx_fifo_threshold_for_request_to_1(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_select_tx_fifo_threshold_for_request_to_1(basePointer)
#define SI32_USART_A_select_tx_fifo_threshold_for_request_to_1(basePointer) \
   (basePointer->FIFOCN_CLR = SI32_USART_A_FIFOCN_TFTH_MASK)


/// @fn _SI32_USART_A_select_tx_fifo_threshold_for_request_to_2(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_select_tx_fifo_threshold_for_request_to_2(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_select_tx_fifo_threshold_for_request_to_2(basePointer)
#define SI32_USART_A_select_tx_fifo_threshold_for_request_to_2(basePointer) do{  \
   basePointer->FIFOCN_CLR = SI32_USART_A_FIFOCN_TFTH_MASK;\
   basePointer->FIFOCN_SET = SI32_USART_A_FIFOCN_TFTH_TWO_U32;\
} while(0)


/// @fn _SI32_USART_A_select_tx_fifo_threshold_for_request_to_4(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_select_tx_fifo_threshold_for_request_to_4(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_select_tx_fifo_threshold_for_request_to_4(basePointer)
#define SI32_USART_A_select_tx_fifo_threshold_for_request_to_4(basePointer) do{  \
   basePointer->FIFOCN_CLR = SI32_USART_A_FIFOCN_TFTH_MASK;\
   basePointer->FIFOCN_SET = SI32_USART_A_FIFOCN_TFTH_FOUR_U32;\
} while(0)


/// @fn _SI32_USART_A_enable_tx_fifo_dma_request(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_enable_tx_fifo_dma_request(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_enable_tx_fifo_dma_request(basePointer)
#define SI32_USART_A_enable_tx_fifo_dma_request(basePointer) \
   (basePointer->FIFOCN_SET = SI32_USART_A_FIFOCN_TDMAEN_ENABLED_U32)


/// @fn _SI32_USART_A_disable_tx_fifo_dma_request(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_disable_tx_fifo_dma_request(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_disable_tx_fifo_dma_request(basePointer)
#define SI32_USART_A_disable_tx_fifo_dma_request(basePointer) \
   (basePointer->FIFOCN_CLR = SI32_USART_A_FIFOCN_TDMAEN_MASK)


/// @fn _SI32_USART_A_flush_tx_fifo(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_flush_tx_fifo(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_flush_tx_fifo(basePointer)
#define SI32_USART_A_flush_tx_fifo(basePointer) \
   (basePointer->FIFOCN_SET = SI32_USART_A_FIFOCN_TFIFOFL_SET_U32)


/// @fn _SI32_USART_A_is_tx_fifo_error_interrupt_pending(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_is_tx_fifo_error_interrupt_pending(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_is_tx_fifo_error_interrupt_pending(basePointer)
#define SI32_USART_A_is_tx_fifo_error_interrupt_pending(basePointer) \
((bool)(basePointer->FIFOCN.TFERI))


/// @fn _SI32_USART_A_clear_tx_fifo_error_interrupt(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USART_A_clear_tx_fifo_error_interrupt(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_clear_tx_fifo_error_interrupt(basePointer)
#define SI32_USART_A_clear_tx_fifo_error_interrupt(basePointer) \
   (basePointer->FIFOCN_CLR = SI32_USART_A_FIFOCN_TFERI_MASK)


/// @fn _SI32_USART_A_is_tx_shift_register_full(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USART_A_is_tx_shift_register_full(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_is_tx_shift_register_full(basePointer)
#define SI32_USART_A_is_tx_shift_register_full(basePointer) \
((bool)(basePointer->FIFOCN.TSRFULLF))


/// @fn _SI32_USART_A_read_data_u32(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USART_A_read_data_u32(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_read_data_u32(basePointer)
#define SI32_USART_A_read_data_u32(basePointer) \
((uint32_t)(basePointer->DATA.U32))


/// @fn _SI32_USART_A_read_data_u16(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint16_t
_SI32_USART_A_read_data_u16(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_read_data_u16(basePointer)
#define SI32_USART_A_read_data_u16(basePointer) \
(basePointer->DATA.U16)


/// @fn _SI32_USART_A_read_data_u8(SI32_USART_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint8_t
_SI32_USART_A_read_data_u8(SI32_USART_A_Type* /*basePointer*/);
///
/// @def SI32_USART_A_read_data_u8(basePointer)
#define SI32_USART_A_read_data_u8(basePointer) \
(basePointer->DATA.U8)


/// @fn _SI32_USART_A_write_data_u32(SI32_USART_A_Type* basePointer,
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
_SI32_USART_A_write_data_u32(SI32_USART_A_Type* /*basePointer*/,
   uint32_t /*dataval*/);
///
/// @def SI32_USART_A_write_data_u32(basePointer, dataval)
#define SI32_USART_A_write_data_u32(basePointer, dataval) \
   (basePointer->DATA.U32 = dataval)


/// @fn _SI32_USART_A_write_data_u16(SI32_USART_A_Type* basePointer,
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
_SI32_USART_A_write_data_u16(SI32_USART_A_Type* /*basePointer*/,
   uwide16_t /*dataval*/);
///
/// @def SI32_USART_A_write_data_u16(basePointer, dataval)
#define SI32_USART_A_write_data_u16(basePointer, dataval) \
   (basePointer->DATA.U16 = dataval)


/// @fn _SI32_USART_A_write_data_u8(SI32_USART_A_Type* basePointer,
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
_SI32_USART_A_write_data_u8(SI32_USART_A_Type* /*basePointer*/,
   uwide8_t /*dataval*/);
///
/// @def SI32_USART_A_write_data_u8(basePointer, dataval)
#define SI32_USART_A_write_data_u8(basePointer, dataval) \
   (basePointer->DATA.U8 = dataval)



#ifdef __cplusplus
}
#endif

#endif // __SI32_USART_A_TYPE_H__

//-eof--------------------------------------------------------------------------
