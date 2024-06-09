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
/// @file SI32_UART_B_Type.c
//
// Script: 0.59
// HAL Source: 0.7
// Version: 8

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_UART_B_Type.h"


//-----------------------------------------------------------------------------
// _SI32_UART_B_initialize
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_initialize(
   SI32_UART_B_Type * basePointer,
   // Write to CONFIG register.
   uint32_t config,
   // Write to MODE register.
   uint32_t mode,
   // Write to FLOWCN register.
   uint32_t flowcn,
   // Write to CONTROL register.
   uint32_t control,
   // Write to IPDELAY register.
   uint32_t ipdelay,
   // Write to BAUDRATE register.
   uint32_t baudrate,
   // Write to FIFOCN register.
   uint32_t fifocn,
   // Write to CLKDIV register.
   uint32_t clkdiv)
{
   assert(ipdelay < 256);   // ipdelay < 2^8
   //{{
   basePointer->CONFIG.U32 = config;
   basePointer->MODE.U32 = mode;
   basePointer->FLOWCN.U32 = flowcn;
   basePointer->CONTROL.U32 = control;
   basePointer->IPDELAY.U32 = ipdelay;
   basePointer->BAUDRATE.U32 = baudrate;
   basePointer->FIFOCN.U32 = fifocn;
   basePointer->CLKDIV.U32 = clkdiv;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_write_config
//
// Write to CONFIG register.
//-----------------------------------------------------------------------------
void
_SI32_UART_B_write_config(
   SI32_UART_B_Type * basePointer,
   uint32_t config)
{
   //{{
   basePointer->CONFIG.U32 = config;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_read_config
//
// Reads CONFIG register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_UART_B_read_config(
   SI32_UART_B_Type * basePointer)
{
   //{{
   return basePointer->CONFIG.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_rx_start_bit
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_rx_start_bit(
   SI32_UART_B_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_UART_B_CONFIG_RSTRTEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_rx_start_bit
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_rx_start_bit(
   SI32_UART_B_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_RSTRTEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_rx_parity_bit
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_rx_parity_bit(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONFIG_SET = SI32_UART_B_CONFIG_RPAREN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_rx_parity_bit
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_rx_parity_bit(
   SI32_UART_B_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_RPAREN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_rx_stop_bit
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_rx_stop_bit(
   SI32_UART_B_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_UART_B_CONFIG_RSTPEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_rx_stop_bit
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_rx_stop_bit(
   SI32_UART_B_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_RSTPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_select_rx_stop_bits
//
// Selects the number of receive stop bits to: 0 = 0.5 stop bit, 1 = 1
// stop bit, 2 = 1.5 stop bits, 3 = 2 stop bits.
//-----------------------------------------------------------------------------
void
_SI32_UART_B_select_rx_stop_bits(
   SI32_UART_B_Type * basePointer,
   SI32_UART_B_STOP_BITS_Enum_Type bits)
{
   assert(bits < 4);   // bits < 2^2
   //{{
   basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_RSTPMD_MASK;
   basePointer->CONFIG_SET = bits << SI32_UART_B_CONFIG_RSTPMD_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_select_rx_parity
//
// Selects the receive parity to: 0 = odd, 1 = even, 2 = mark, 3 = space.
//-----------------------------------------------------------------------------
void
_SI32_UART_B_select_rx_parity(
   SI32_UART_B_Type * basePointer,
   SI32_UART_B_PARITY_Enum_Type parity)
{
   assert(parity < 4);   // parity < 2^2
   //{{
   basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_RPARMD_MASK;
   basePointer->CONFIG_SET = parity << SI32_UART_B_CONFIG_RPARMD_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_select_rx_data_length
//
// Selects the receiver data length to: 5 = 5 bits, 6 = 6 bits, 7 = 7
// bits, 8 = 8 bits, 9 = 9 bits, 10 = 9 bit fixed mode.
//-----------------------------------------------------------------------------
void
_SI32_UART_B_select_rx_data_length(
   SI32_UART_B_Type * basePointer,
   SI32_UART_B_DATA_LENGTH_Enum_Type length)
{
   assert((length >= 5) && (length <= 10));
   //{{
   basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_RDATLN_MASK;
   basePointer->CONFIG_SET = (length - 5) << SI32_UART_B_CONFIG_RDATLN_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_rx_irda_mode
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_rx_irda_mode(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONFIG_SET = SI32_UART_B_CONFIG_RIRDAEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_rx_irda_mode
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_rx_irda_mode(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_RIRDAEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_rx_signal_inversion
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_rx_signal_inversion(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONFIG_SET = SI32_UART_B_CONFIG_RINVEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_rx_signal_inversion
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_rx_signal_inversion(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_RINVEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_tx_start_bit
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_tx_start_bit(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONFIG_SET = SI32_UART_B_CONFIG_TSTRTEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_tx_start_bit
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_tx_start_bit(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_TSTRTEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_tx_parity_bit
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_tx_parity_bit(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONFIG_SET = SI32_UART_B_CONFIG_TPAREN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_tx_parity_bit
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_tx_parity_bit(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_TPAREN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_tx_stop_bit
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_tx_stop_bit(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONFIG_SET = SI32_UART_B_CONFIG_TSTPEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_tx_stop_bit
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_tx_stop_bit(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_TSTPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_select_tx_stop_bits
//
// Sets the number of transmit stop bits to: 0 = 0.5 stop bit, 1 = 1 stop
// bit, 2 = 1.5 stop bits, 3 = 2 stop bits.
//-----------------------------------------------------------------------------
void
_SI32_UART_B_select_tx_stop_bits(
   SI32_UART_B_Type * basePointer,
   SI32_UART_B_STOP_BITS_Enum_Type bits)
{
   assert(bits < 4);   // bits < 2^2
   //{{
   basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_TSTPMD_MASK;
   basePointer->CONFIG_SET = bits << SI32_UART_B_CONFIG_TSTPMD_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_select_tx_parity
//
// Sets the transmit parity to: 0 = odd, 1 = even, 2 = mark, 3 = space.
//-----------------------------------------------------------------------------
void
_SI32_UART_B_select_tx_parity(
   SI32_UART_B_Type * basePointer,
   SI32_UART_B_PARITY_Enum_Type parity)
{
   assert(parity < 4);   // parity < 2^2
   //{{
	basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_TPARMD_MASK;
   basePointer->CONFIG_SET = parity << SI32_UART_B_CONFIG_TPARMD_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_select_tx_data_length
//
// Sets the transmit data length to: 5 = 5 bits, 6 = 6 bits, 7 = 7 bits,
// 8 = 8 bits, 9 = 9 bits, 10 = 9 bit fixed mode.
//-----------------------------------------------------------------------------
void
_SI32_UART_B_select_tx_data_length(
   SI32_UART_B_Type * basePointer,
   SI32_UART_B_DATA_LENGTH_Enum_Type length)
{
   assert((length >= 5) && (length <= 10));
   //{{
	basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_TDATLN_MASK;
   basePointer->CONFIG_SET = (length - 5) << SI32_UART_B_CONFIG_TDATLN_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_tx_irda_mode
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_tx_irda_mode(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONFIG_SET = SI32_UART_B_CONFIG_TIRDAEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_tx_irda_mode
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_tx_irda_mode(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_TIRDAEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_tx_signal_inversion
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_tx_signal_inversion(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONFIG_SET = SI32_UART_B_CONFIG_TINVEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_tx_signal_inversion
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_tx_signal_inversion(
   SI32_UART_B_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_UART_B_CONFIG_TINVEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_write_mode
//
// Write to MODE register.
//-----------------------------------------------------------------------------
void
_SI32_UART_B_write_mode(
   SI32_UART_B_Type * basePointer,
   uint32_t mode)
{
   //{{
	basePointer->MODE.U32 = mode;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_read_mode
//
// Reads MODE register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_UART_B_read_mode(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return basePointer->MODE.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_select_rtc_clock_mode
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_select_rtc_clock_mode(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->MODE_SET = SI32_UART_B_MODE_RTCCKMD_RTC0TCLK_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_select_apb_clock_mode
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_select_apb_clock_mode(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->MODE_CLR = SI32_UART_B_MODE_RTCCKMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enter_rtc_baud_rate_mode
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enter_rtc_baud_rate_mode(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->MODE_SET = SI32_UART_B_MODE_RTCBDMD_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_exit_rtc_baud_rate_mode
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_exit_rtc_baud_rate_mode(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->MODE_CLR = SI32_UART_B_MODE_RTCBDMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_select_internal_clock_on_demand
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_select_internal_clock_on_demand(
   SI32_UART_B_Type * basePointer)
{
   //{{
   basePointer->MODE_CLR = SI32_UART_B_MODE_FORCECLK_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_select_internal_clock_always_on
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_select_internal_clock_always_on(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->MODE_SET = SI32_UART_B_MODE_FORCECLK_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_is_clock_switch_busy
//
//-----------------------------------------------------------------------------
bool
_SI32_UART_B_is_clock_switch_busy(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return (bool)(basePointer->MODE.CLKBUSY);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_rx_clock_switch
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_rx_clock_switch(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->MODE_SET = SI32_UART_B_MODE_RXCLKSW_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_rx_clock_switch
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_rx_clock_switch(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->MODE_CLR = SI32_UART_B_MODE_RXCLKSW_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_tx_clock_switch
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_tx_clock_switch(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->MODE_SET = SI32_UART_B_MODE_TXCLKSW_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_tx_clock_switch
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_tx_clock_switch(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->MODE_CLR = SI32_UART_B_MODE_TXCLKSW_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_stall_in_debug_mode(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->MODE_SET = SI32_UART_B_MODE_DBGMD_HALT_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_stall_in_debug_mode(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->MODE_CLR = SI32_UART_B_MODE_DBGMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_exit_loopback_mode
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_exit_loopback_mode(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->MODE_CLR = SI32_UART_B_MODE_LBMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enter_receive_loopback_mode
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enter_receive_loopback_mode(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->MODE_CLR = SI32_UART_B_MODE_LBMD_MASK;
   basePointer->MODE_SET = SI32_UART_B_MODE_LBMD_RXONLY_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enter_transmit_loopback_mode
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enter_transmit_loopback_mode(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->MODE_CLR = SI32_UART_B_MODE_LBMD_MASK;
   basePointer->MODE_SET = SI32_UART_B_MODE_LBMD_TXONLY_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enter_full_loopback_mode
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enter_full_loopback_mode(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->MODE_SET = SI32_UART_B_MODE_LBMD_BOTH_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enter_half_duplex_mode
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enter_half_duplex_mode(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->MODE_SET = SI32_UART_B_MODE_DUPLEXMD_HALF_DUPLEX_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enter_full_duplex_mode
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enter_full_duplex_mode(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->MODE_CLR = SI32_UART_B_MODE_DUPLEXMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_idle_tristate
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_idle_tristate(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->MODE_CLR = SI32_UART_B_MODE_ITSEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_idle_tristate
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_idle_tristate(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->MODE_SET = SI32_UART_B_MODE_ITSEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_write_flowcn
//
// Write to FLOWCN register.
//-----------------------------------------------------------------------------
void
_SI32_UART_B_write_flowcn(
   SI32_UART_B_Type * basePointer,
   uint32_t flowcn)
{
   //{{
	basePointer->FLOWCN.U32 = flowcn;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_read_flowcn
//
// Reads FLOWCN register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_UART_B_read_flowcn(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return basePointer->FLOWCN.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_read_rx_input
//
//-----------------------------------------------------------------------------
bool
_SI32_UART_B_read_rx_input(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return (bool)(basePointer->FLOWCN.RX);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_tx_output
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_tx_output(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->FLOWCN_SET = SI32_UART_B_FLOWCN_TXOEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_tx_output
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_tx_output(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->FLOWCN_CLR = SI32_UART_B_FLOWCN_TXOEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_read_tx_output
//
//-----------------------------------------------------------------------------
bool
_SI32_UART_B_read_tx_output(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return (bool)(basePointer->FLOWCN.TX);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_clear_tx
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_clear_tx(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->FLOWCN_CLR = SI32_UART_B_FLOWCN_TX_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_set_tx
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_set_tx(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->FLOWCN_SET = SI32_UART_B_FLOWCN_TX_HIGH_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_select_tx_irda_pulse_width
//
// Selects the transmitter IrDA pulse width to: 0 = 1/16th of a bit
// period, 1 = 1/8th of a bit period, 2 = 3/16th of a bit period, 3 =
// 1/4th of a bit period.
//-----------------------------------------------------------------------------
void
_SI32_UART_B_select_tx_irda_pulse_width(
   SI32_UART_B_Type * basePointer,
   SI32_UART_B_IRDA_PULSE_WIDTH_Enum_Type width)
{
   assert(width < 4);   // width < 2^2
   //{{
	basePointer->FLOWCN_CLR = SI32_UART_B_FLOWCN_TIRDAPW_MASK;
   basePointer->FLOWCN_SET = width << SI32_UART_B_FLOWCN_TIRDAPW_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_write_control
//
// Write to CONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_UART_B_write_control(
   SI32_UART_B_Type * basePointer,
   uint32_t control)
{
   //{{
	basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_read_control
//
// Reads CONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_UART_B_read_control(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_is_rx_frame_error_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_UART_B_is_rx_frame_error_interrupt_pending(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.RFRMERI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_clear_rx_frame_error_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_clear_rx_frame_error_interrupt(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_RFRMERI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_is_rx_parity_error_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_UART_B_is_rx_parity_error_interrupt_pending(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.RPARERI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_clear_rx_parity_error_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_clear_rx_parity_error_interrupt(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_RPARERI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_is_rx_overrun_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_UART_B_is_rx_overrun_interrupt_pending(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.ROREI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_clear_rx_overrun_error_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_clear_rx_overrun_error_interrupt(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_ROREI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_is_rx_data_request_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_UART_B_is_rx_data_request_interrupt_pending(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.RDREQI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_clear_rx_data_request_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_clear_rx_data_request_interrupt(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_RDREQI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_rx_error_interrupts
//
// Enables the receive overrun error, frame error, and parity error
// interrupts.
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_rx_error_interrupts(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_SET = SI32_UART_B_CONTROL_RERIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_rx_error_interrupts
//
// Disables the receive overrun error, frame error, and parity error
// interrupts.
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_rx_error_interrupts(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_RERIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_is_rx_error_interrupts_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_UART_B_is_rx_error_interrupts_enabled(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.RERIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_rx_data_request_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_rx_data_request_interrupt(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_SET = SI32_UART_B_CONTROL_RDREQIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_rx_data_request_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_rx_data_request_interrupt(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_RDREQIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_is_rx_data_request_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_UART_B_is_rx_data_request_interrupt_enabled(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.RDREQIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_exit_match_mode
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_exit_match_mode(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_MATMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enter_match_mode_store_byte
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enter_match_mode_store_byte(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_MATMD_MASK;
   basePointer->CONTROL_SET = SI32_UART_B_CONTROL_MATMD_MCE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enter_match_mode_generate_frame_error
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enter_match_mode_generate_frame_error(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_MATMD_MASK;
   basePointer->CONTROL_SET = SI32_UART_B_CONTROL_MATMD_FRAME_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enter_match_mode_store_bit
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enter_match_mode_store_bit(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_SET = SI32_UART_B_CONTROL_MATMD_STORE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_rx_autobaud
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_rx_autobaud(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_SET = SI32_UART_B_CONTROL_RABDEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_rx_autobaud
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_rx_autobaud(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_RABDEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_is_rx_busy
//
//-----------------------------------------------------------------------------
bool
_SI32_UART_B_is_rx_busy(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.RBUSYF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_set_rbit
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_set_rbit(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_SET = SI32_UART_B_CONTROL_RBIT_SET_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_clear_rbit
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_clear_rbit(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_RBIT_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_read_rbit
//
//-----------------------------------------------------------------------------
bool
_SI32_UART_B_read_rbit(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.RBIT);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_rx_one_shot
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_rx_one_shot(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_SET = SI32_UART_B_CONTROL_ROSEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_rx_one_shot
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_rx_one_shot(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_ROSEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_rx_inhibit
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_rx_inhibit(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_SET = SI32_UART_B_CONTROL_RINH_ACTIVE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_rx_inhibit
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_rx_inhibit(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_RINH_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_rx
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_rx(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_SET = SI32_UART_B_CONTROL_REN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_rx
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_rx(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_REN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_is_tx_data_request_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_UART_B_is_tx_data_request_interrupt_pending(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.TDREQI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_is_tx_complete
//
//-----------------------------------------------------------------------------
bool
_SI32_UART_B_is_tx_complete(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.TCPTI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_clear_tx_complete_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_clear_tx_complete_interrupt(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_TCPTI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_select_tx_complete_threshold_end_of_transmission
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_select_tx_complete_threshold_end_of_transmission(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_TCPTTH_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_select_tx_complete_threshold_no_more_data
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_select_tx_complete_threshold_no_more_data(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_SET = SI32_UART_B_CONTROL_TCPTTH_SET_ON_EMPTY_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_tx_data_request_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_tx_data_request_interrupt(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_SET = SI32_UART_B_CONTROL_TDREQIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_tx_data_request_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_tx_data_request_interrupt(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_TDREQIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_is_tx_data_request_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_UART_B_is_tx_data_request_interrupt_enabled(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.TDREQIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_tx_complete_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_tx_complete_interrupt(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_SET = SI32_UART_B_CONTROL_TCPTIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_tx_complete_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_tx_complete_interrupt(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_TCPTIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_is_tx_complete_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_UART_B_is_tx_complete_interrupt_enabled(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.TCPTIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_is_tx_busy
//
//-----------------------------------------------------------------------------
bool
_SI32_UART_B_is_tx_busy(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.TBUSYF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_set_tbit
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_set_tbit(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_SET = SI32_UART_B_CONTROL_TBIT_SET_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_clear_tbit
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_clear_tbit(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_TBIT_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_tx_inhibit
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_tx_inhibit(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_SET = SI32_UART_B_CONTROL_TINH_ACTIVE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_tx_inhibit
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_tx_inhibit(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_TINH_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_enable_tx
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_enable_tx(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_SET = SI32_UART_B_CONTROL_TEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_disable_tx
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_disable_tx(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_UART_B_CONTROL_TEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_write_ipdelay
//
// Write to IPDELAY register.
//-----------------------------------------------------------------------------
void
_SI32_UART_B_write_ipdelay(
   SI32_UART_B_Type * basePointer,
   uint32_t ipdelay)
{
   //{{
	basePointer->IPDELAY.U32 = ipdelay;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_read_ipdelay
//
// Reads IPDELAY register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_UART_B_read_ipdelay(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return basePointer->IPDELAY.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_write_ipdelay_bits
//
// Write to IPDELAY bitfield.
//-----------------------------------------------------------------------------
void
_SI32_UART_B_write_ipdelay_bits(
   SI32_UART_B_Type * basePointer,
   uint32_t ipdelay)
{
   assert(ipdelay < 256);   // ipdelay < 2^8
   //{{
	basePointer->IPDELAY.IPDELAY_BITS = ipdelay;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_read_ipdelay_bits
//
// Reads IPDELAY bitfield.
//-----------------------------------------------------------------------------
uint32_t
_SI32_UART_B_read_ipdelay_bits(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return basePointer->IPDELAY.IPDELAY_BITS;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_write_baudrate
//
// Write to BAUDRATE register.
//-----------------------------------------------------------------------------
void
_SI32_UART_B_write_baudrate(
   SI32_UART_B_Type * basePointer,
   uint32_t baudrate)
{
   //{{
	basePointer->BAUDRATE.U32 = baudrate;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_read_baudrate
//
// Reads BAUDRATE register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_UART_B_read_baudrate(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return basePointer->BAUDRATE.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_set_rx_baudrate
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_set_rx_baudrate(
   SI32_UART_B_Type * basePointer,
   uwide16_t rxbaud)
{
   assert(rxbaud < 65536);   // rxbaud < 2^16
   //{{
	basePointer->BAUDRATE.RBAUD = rxbaud;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_set_tx_baudrate
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_set_tx_baudrate(
   SI32_UART_B_Type * basePointer,
   uwide16_t txbaud)
{
   assert(txbaud < 65536);   // txbaud < 2^16
   //{{
	basePointer->BAUDRATE.TBAUD = txbaud;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_write_fifocn
//
// Write to FIFOCN register.
//-----------------------------------------------------------------------------
void
_SI32_UART_B_write_fifocn(
   SI32_UART_B_Type * basePointer,
   uint32_t fifocn)
{
   //{{
	basePointer->FIFOCN.U32 = fifocn;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_read_fifocn
//
// Reads FIFOCN register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_UART_B_read_fifocn(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return basePointer->FIFOCN.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_read_rx_fifo_count
//
// Returns number of bytes in receive FIFO.
//-----------------------------------------------------------------------------
uint32_t
_SI32_UART_B_read_rx_fifo_count(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return (uint32_t)(basePointer->FIFOCN.RCNT);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_select_rx_fifo_threshold_1
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_select_rx_fifo_threshold_1(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->FIFOCN_CLR = SI32_UART_B_FIFOCN_RFTH_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_select_rx_fifo_threshold_2
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_select_rx_fifo_threshold_2(
   SI32_UART_B_Type * basePointer)
{
   //{{
   basePointer->FIFOCN_CLR = SI32_UART_B_FIFOCN_RFTH_MASK;
   basePointer->FIFOCN_SET = SI32_UART_B_FIFOCN_RFTH_TWO_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_select_rx_fifo_threshold_4
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_select_rx_fifo_threshold_4(
   SI32_UART_B_Type * basePointer)
{
   //{{
   basePointer->FIFOCN_CLR = SI32_UART_B_FIFOCN_RFTH_MASK;
   basePointer->FIFOCN_SET = SI32_UART_B_FIFOCN_RFTH_FOUR_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_flush_rx_fifo
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_flush_rx_fifo(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->FIFOCN_SET = SI32_UART_B_FIFOCN_RFIFOFL_SET_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_is_rx_fifo_error_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_UART_B_is_rx_fifo_error_interrupt_pending(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return (bool)(basePointer->FIFOCN.RFERI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_clear_rx_fifo_error_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_clear_rx_fifo_error_interrupt(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->FIFOCN_CLR = SI32_UART_B_FIFOCN_RFERI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_is_rx_shift_register_full
//
//-----------------------------------------------------------------------------
bool
_SI32_UART_B_is_rx_shift_register_full(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return (bool)(basePointer->FIFOCN.RSRFULLF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_read_tx_fifo_count
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_UART_B_read_tx_fifo_count(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return (uint32_t)(basePointer->FIFOCN.TCNT);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_select_tx_fifo_threshold_for_request_to_1
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_select_tx_fifo_threshold_for_request_to_1(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->FIFOCN_CLR = SI32_UART_B_FIFOCN_TFTH_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_select_tx_fifo_threshold_for_request_to_2
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_select_tx_fifo_threshold_for_request_to_2(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->FIFOCN_CLR = SI32_UART_B_FIFOCN_TFTH_MASK;
   basePointer->FIFOCN_SET = SI32_UART_B_FIFOCN_TFTH_TWO_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_select_tx_fifo_threshold_for_request_to_4
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_select_tx_fifo_threshold_for_request_to_4(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->FIFOCN_CLR = SI32_UART_B_FIFOCN_TFTH_MASK;
   basePointer->FIFOCN_SET = SI32_UART_B_FIFOCN_TFTH_FOUR_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_flush_tx_fifo
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_flush_tx_fifo(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->FIFOCN_SET = SI32_UART_B_FIFOCN_TFIFOFL_SET_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_is_tx_fifo_error_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_UART_B_is_tx_fifo_error_interrupt_pending(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return (bool)(basePointer->FIFOCN.TFERI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_clear_tx_fifo_error_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_clear_tx_fifo_error_interrupt(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->FIFOCN_CLR = SI32_UART_B_FIFOCN_TFERI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_is_tx_shift_register_full
//
//-----------------------------------------------------------------------------
bool
_SI32_UART_B_is_tx_shift_register_full(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return (bool)(basePointer->FIFOCN.TSRFULLF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_read_data_u32
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_UART_B_read_data_u32(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return (uint32_t)(basePointer->DATA.U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_read_data_u16
//
//-----------------------------------------------------------------------------
uint16_t
_SI32_UART_B_read_data_u16(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return basePointer->DATA.U16;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_read_data_u8
//
//-----------------------------------------------------------------------------
uint8_t
_SI32_UART_B_read_data_u8(
   SI32_UART_B_Type * basePointer)
{
   //{{
	return basePointer->DATA.U8;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_write_data_u32
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_write_data_u32(
   SI32_UART_B_Type * basePointer,
   uint32_t dataval)
{
   //{{
	basePointer->DATA.U32 = dataval;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_write_data_u16
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_write_data_u16(
   SI32_UART_B_Type * basePointer,
   uwide16_t dataval)
{
   assert(dataval < 65536);   // dataval < 2^16
   //{{
	basePointer->DATA.U16 = dataval;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_write_data_u8
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_write_data_u8(
   SI32_UART_B_Type * basePointer,
   uwide8_t dataval)
{
   assert(dataval < 256);   // dataval < 2^8
   //{{
   basePointer->DATA.U8 = dataval;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_write_clkdiv
//
// Write to CLKDIV register.
//-----------------------------------------------------------------------------
void
_SI32_UART_B_write_clkdiv(
   SI32_UART_B_Type * basePointer,
   uint32_t clkdiv)
{
   //{{
	basePointer->CLKDIV.U32 = clkdiv;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_read_clkdiv
//
// Reads CLKDIV register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_UART_B_read_clkdiv(
   SI32_UART_B_Type * basePointer)
{
   //{{
   return basePointer->CLKDIV.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_select_clock_source_apb_div1
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_select_clock_source_apb_div1(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CLKDIV.CLKDIV_BITS = SI32_UART_B_CLKDIV_CLKDIV_DIV1_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_select_clock_source_apb_div2
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_select_clock_source_apb_div2(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CLKDIV.CLKDIV_BITS = SI32_UART_B_CLKDIV_CLKDIV_DIV2_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_UART_B_select_clock_source_apb_div4
//
//-----------------------------------------------------------------------------
void
_SI32_UART_B_select_clock_source_apb_div4(
   SI32_UART_B_Type * basePointer)
{
   //{{
	basePointer->CLKDIV.CLKDIV_BITS = SI32_UART_B_CLKDIV_CLKDIV_DIV4_VALUE;
   //}}
}


//-eof--------------------------------------------------------------------------
