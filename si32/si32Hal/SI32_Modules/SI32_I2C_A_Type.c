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
/// @file SI32_I2C_A_Type.c
//
// Script: 0.58
// HAL Source: 0.3
// Version: 10

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_I2C_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_I2C_A_initialize
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_initialize(
   SI32_I2C_A_Type * basePointer,
   // Write to CONTROL register.
   uint32_t control,
   // Write to CONFIG register.
   uint32_t config,
   // Write to SADDRESS register.
   uint32_t saddress,
   // Write to SMASK register.
   uint32_t smask,
   // Write to TIMER register.
   uint32_t timer,
   // Write to TIMERRL register.
   uint32_t timerrl,
   // Write to SCONFIG register.
   uint32_t sconfig,
   // Write to I2CDMA register.
   uint32_t i2cdma)
{
   //{{
   basePointer->CONTROL.U32 = control;
   basePointer->CONFIG.U32 = config;
   basePointer->SADDRESS.U32 = saddress;
   basePointer->SMASK.U32 = smask;
   basePointer->TIMER.U32 = timer;
   basePointer->TIMERRL.U32 = timerrl;
   basePointer->SCONFIG.U32 = sconfig;
   basePointer->I2CDMA.U32 = i2cdma;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_write_control
//
// Write to CONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_write_control(
   SI32_I2C_A_Type * basePointer,
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_read_control
//
// Read CONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2C_A_read_control(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_busy
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_busy(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.BUSYF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_ack_received
//
// Returns TRUE is ACK was recevied and returns FALSE if NACK was
// received.
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_ack_received(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.ACK);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_send_ack
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_send_ack(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_ACK_SET_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_send_nack
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_send_nack(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_ACK_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_has_arblost_error_occurred
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_has_arblost_error_occurred(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.ARBLF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_ack_requested
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_ack_requested(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.ACKRQF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_set_stop
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_set_stop(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_STO_SET_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_clear_stop
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_clear_stop(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_STO_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_stop_set
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_stop_set(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.STO);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_set_start
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_set_start(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_STA_SET_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_clear_start
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_clear_start(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_STA_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_start_set
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_start_set(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.STA);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_tx_mode_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_tx_mode_enabled(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.TXMDF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_master_mode_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_master_mode_enabled(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.MSMDF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_clear_stop_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_clear_stop_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_STOI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_stop_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_stop_interrupt_pending(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.STOI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_clear_ack_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_clear_ack_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_ACKI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_ack_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_ack_interrupt_pending(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.ACKI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_clear_rx_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_clear_rx_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_RXI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_rx_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_rx_interrupt_pending(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.RXI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_clear_tx_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_clear_tx_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_TXI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_tx_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_tx_interrupt_pending(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.TXI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_clear_start_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_clear_start_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_STAI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_start_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_start_interrupt_pending(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.STAI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_clear_arblost_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_clear_arblost_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_ARBLI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_arblost_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_arblost_interrupt_pending(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.ARBLI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_clear_timer0_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_clear_timer0_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_T0I_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_timer0_interrupt_pending
//
// Overflow event for Timer 0.
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_timer0_interrupt_pending(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.T0I);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_clear_timer1_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_clear_timer1_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_T1I_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_timer1_interrupt_pending
//
// Overflow event for Timer 1.
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_timer1_interrupt_pending(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.T1I);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_clear_timer2_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_clear_timer2_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_T2I_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_timer2_interrupt_pending
//
// Overflow event for Timer 2.
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_timer2_interrupt_pending(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.T2I);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_clear_timer3_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_clear_timer3_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_T3I_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_timer3_interrupt_pending
//
// Overflow event for Timer 3.
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_timer3_interrupt_pending(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.T3I);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_arm_rx
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_arm_rx(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_RXARM_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_disarm_rx
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_disarm_rx(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_RXARM_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_rx_in_progress
//
// Returns TRUE if a receive is in progress and returns FALSE if a
// receive is not in progress.
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_rx_in_progress(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.RXARM);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_arm_tx
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_arm_tx(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_TXARM_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_disarm_tx
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_disarm_tx(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_TXARM_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_tx_in_progress
//
// Returns TRUE if a transmit is in progress and returns FALSE if a
// transmit is not in progress.
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_tx_in_progress(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.TXARM);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_general_call_address_detected
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_general_call_address_detected(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.GCEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_enable_auto_tx_or_rx
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_enable_auto_tx_or_rx(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_ATXRXEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_disable_auto_tx_or_rx
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_disable_auto_tx_or_rx(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_ATXRXEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_enable_input_filter
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_enable_input_filter(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_FMD_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_disable_input_filter
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_disable_input_filter(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_FMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_enable_stall_in_debug_mode
//
// Stalls the module when debug mode is active.
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_enable_stall_in_debug_mode(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_DBGMD_HALT_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_disable_stall_in_debug_mode
//
// Normal operation when debug mode is active.
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_disable_stall_in_debug_mode(
   SI32_I2C_A_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_DBGMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_enable_slave_mode
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_enable_slave_mode(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_SMINH_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_disable_slave_mode
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_disable_slave_mode(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_SMINH_ACTIVE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_enable_auto_ack
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_enable_auto_ack(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_HACKEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_disable_auto_ack
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_disable_auto_ack(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_HACKEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_enable_last_byte_ack
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_enable_last_byte_ack(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_LBACKEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_disable_last_byte_ack
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_disable_last_byte_ack(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_LBACKEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_enable_general_call_address_decode
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_enable_general_call_address_decode(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_GCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_disable_general_call_address_decode
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_disable_general_call_address_decode(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_GCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_reset_module
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_reset_module(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_RESET_MASK;
   basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_RESET_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_enable_module
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_enable_module(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_I2CEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_disable_module
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_disable_module(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_I2CEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_write_config
//
// Write to CONFIG register.
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_write_config(
   SI32_I2C_A_Type * basePointer,
   uint32_t config)
{
   //{{
   basePointer->CONFIG.U32 = config;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_read_config
//
// Reads CONFIG register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2C_A_read_config(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return basePointer->CONFIG.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_set_scaler_value
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_set_scaler_value(
   SI32_I2C_A_Type * basePointer,
   uint32_t value)
{
   assert(value < 64);   // value < 2^6
   //{{
   basePointer->CONFIG.SCALER = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_get_scaler_value
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2C_A_get_scaler_value(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return basePointer->CONFIG.SCALER;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_enable_stop_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_enable_stop_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_STOIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_disable_stop_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_disable_stop_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_STOIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_stop_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_stop_interrupt_enabled(
   SI32_I2C_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONFIG.STOIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_enable_ack_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_enable_ack_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_ACKIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_disable_ack_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_disable_ack_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_ACKIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_ack_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_ack_interrupt_enabled(
   SI32_I2C_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONFIG.ACKIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_enable_rx_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_enable_rx_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_RXIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_disable_rx_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_disable_rx_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_RXIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_rx_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_rx_interrupt_enabled(
   SI32_I2C_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONFIG.RXIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_enable_tx_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_enable_tx_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_TXIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_disable_tx_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_disable_tx_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_TXIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_tx_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_tx_interrupt_enabled(
   SI32_I2C_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONFIG.TXIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_enable_start_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_enable_start_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_STAIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_disable_start_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_disable_start_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_STAIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_start_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_start_interrupt_enabled(
   SI32_I2C_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONFIG.STAIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_enable_arblost_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_enable_arblost_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_ARBLIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_disable_arblost_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_disable_arblost_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_ARBLIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_arblost_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_arblost_interrupt_enabled(
   SI32_I2C_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONFIG.ARBLIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_enable_timer0_interrupt
//
// Enable interrupt for overflow event for Timer 0.
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_enable_timer0_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_T0IEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_disable_timer0_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_disable_timer0_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_T0IEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_timer0_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_timer0_interrupt_enabled(
   SI32_I2C_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONFIG.T0IEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_enable_timer1_interrupt
//
// Enable interrupt for overflow event for Timer 1.
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_enable_timer1_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_T1IEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_disable_timer1_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_disable_timer1_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_T1IEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_timer1_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_timer1_interrupt_enabled(
   SI32_I2C_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONFIG.T1IEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_enable_timer2_interrupt
//
// Enable interrupt for overflow event for Timer 2.
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_enable_timer2_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_T2IEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_disable_timer2_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_disable_timer2_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_T2IEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_timer2_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_timer2_interrupt_enabled(
   SI32_I2C_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONFIG.T2IEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_enable_timer3_interrupt
//
// Enable interrupt for overflow event for Timer 3.
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_enable_timer3_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_T3IEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_disable_timer3_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_disable_timer3_interrupt(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_T3IEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_timer3_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_timer3_interrupt_enabled(
   SI32_I2C_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONFIG.T3IEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_get_byte_count
//
// Returns the number of bytes to transmit or receive if DMA is disabled.
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2C_A_get_byte_count(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return basePointer->CONFIG.BC;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_set_byte_count
//
// Returns the number of bytes to transmit or receive if DMA is disabled.
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_set_byte_count(
   SI32_I2C_A_Type * basePointer,
   // 0 = four bytes, 1 = one byte, 2 = two bytes, and 3 = three bytes.
   uint32_t value)
{
   assert(value < 4);   // value < 2^2
   //{{
   basePointer->CONFIG.BC = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_get_byte_pointer
//
// Returns the byte of the current transfer being sent or receieved. When
// this value equals the byte count, the transfer is completed. This
// setting has no effect when DMA mode is enabled.
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2C_A_get_byte_pointer(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return basePointer->CONFIG.BP;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_start_timer0
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_start_timer0(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_T0RUN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_stop_timer0
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_stop_timer0(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_T0RUN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_start_timer1
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_start_timer1(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_T1RUN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_stop_timer1
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_stop_timer1(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_T1RUN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_start_timer2
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_start_timer2(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_T2RUN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_stop_timer2
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_stop_timer2(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_T2RUN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_start_timer3
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_start_timer3(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_T3RUN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_stop_timer3
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_stop_timer3(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_T3RUN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_enter_32bit_timer_mode
//
// Timer is configured as one 32-bit timer.
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_enter_32bit_timer_mode(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_TMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_enter_16bit_timer_mode
//
// Timer is configured as two 16-bit timers (16-bit high and 16-bit low).
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_enter_16bit_timer_mode(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_TMD_MASK;
   basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_TMD_MODE1_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_enter_8bit_timer_mode
//
// Timer is configured as four 8-bit timers (8-bit timer3, 8-bit timer2,
// 8-bit timer1, 8-bit timer0).
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_enter_8bit_timer_mode(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_TMD_MASK;
   basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_TMD_MODE2_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_enter_16bit_two_8bit_timer_mode
//
// Timer is configured as one 16-bit timer (16-bit high timer) and two
// 8-bit timers (8-bit timer1, 8-bit timer0).
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_enter_16bit_two_8bit_timer_mode(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_TMD_MODE3_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_enable_all_timers
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_enable_all_timers(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_TIMEREN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_disable_all_timers
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_disable_all_timers(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_TIMEREN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_write_saddress
//
// Write to SADDRESS register.
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_write_saddress(
   SI32_I2C_A_Type * basePointer,
   uint32_t saddress)
{
   //{{
   basePointer->SADDRESS.U32 = saddress;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_read_saddress
//
// Reads SADDRESS register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2C_A_read_saddress(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return basePointer->SADDRESS.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_write_smask
//
// Write to SMASK register.
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_write_smask(
   SI32_I2C_A_Type * basePointer,
   uint32_t smask)
{
   //{{
   basePointer->SMASK.U32 = smask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_read_smask
//
// Reads SMASK register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2C_A_read_smask(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return basePointer->SMASK.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_write_data
//
// Write to DATA register. This function writes four bytes of data to the
// TX/RX buffer. For each transaction, the hardware will start from the
// least significant byte.
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_write_data(
   SI32_I2C_A_Type * basePointer,
   uint32_t value)
{
   //{{
   basePointer->DATA.DATA_BITS = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_read_data
//
// Reads DATA register. Returns four bytes of data from the TX/RX buffer.
// For each transaction, the hardware will start from the least
// significant byte.
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2C_A_read_data(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return basePointer->DATA.DATA_BITS;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_write_timer
//
// Write to TIMER register.
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_write_timer(
   SI32_I2C_A_Type * basePointer,
   uint32_t timer)
{
   //{{
   basePointer->TIMER.U32 = timer;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_read_timer
//
// Reads TIMER register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2C_A_read_timer(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return basePointer->TIMER.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_set_timer0_u8
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_set_timer0_u8(
   SI32_I2C_A_Type * basePointer,
   uwide8_t value)
{
   assert(value < 256);   // value < 2^8
   //{{
   basePointer->TIMER.T0 = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_get_timer0_u8
//
//-----------------------------------------------------------------------------
uwide8_t
_SI32_I2C_A_get_timer0_u8(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return basePointer->TIMER.T0;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_set_timer1_u8
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_set_timer1_u8(
   SI32_I2C_A_Type * basePointer,
   uwide8_t value)
{
   assert(value < 256);   // value < 2^8
   //{{
   basePointer->TIMER.T1 = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_get_timer1_u8
//
//-----------------------------------------------------------------------------
uwide8_t
_SI32_I2C_A_get_timer1_u8(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return basePointer->TIMER.T1;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_set_timer2_u8
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_set_timer2_u8(
   SI32_I2C_A_Type * basePointer,
   uwide8_t value)
{
   assert(value < 256);   // value < 2^8
   //{{
   basePointer->TIMER.T2 = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_get_timer2_u8
//
//-----------------------------------------------------------------------------
uwide8_t
_SI32_I2C_A_get_timer2_u8(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return basePointer->TIMER.T2;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_set_timer3_u8
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_set_timer3_u8(
   SI32_I2C_A_Type * basePointer,
   uwide8_t value)
{
   assert(value < 256);   // value < 2^8
   //{{
   basePointer->TIMER.T3 = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_get_timer3_u8
//
//-----------------------------------------------------------------------------
uwide8_t
_SI32_I2C_A_get_timer3_u8(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return basePointer->TIMER.T3;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_set_timer_low_u16
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_set_timer_low_u16(
   SI32_I2C_A_Type * basePointer,
   uwide16_t value)
{
   assert(value < 65536);   // value < 2^16
   //{{
   basePointer->TIMER.T1 = (value >> 8) & 0xFF;
   basePointer->TIMER.T0 = (value     ) & 0xFF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_get_timer_low_u16
//
//-----------------------------------------------------------------------------
uwide16_t
_SI32_I2C_A_get_timer_low_u16(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (basePointer->TIMER.T1 << 8) | basePointer->TIMER.T0;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_set_timer_high_u16
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_set_timer_high_u16(
   SI32_I2C_A_Type * basePointer,
   uwide16_t value)
{
   assert(value < 65536);   // value < 2^16
   //{{
   basePointer->TIMER.T3 = (value >>  8) & 0xFF;
   basePointer->TIMER.T2 = (value      ) & 0xFF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_get_timer_high_u16
//
//-----------------------------------------------------------------------------
uwide16_t
_SI32_I2C_A_get_timer_high_u16(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (basePointer->TIMER.T3 << 8) | basePointer->TIMER.T2;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_write_timerrl
//
// Write to TIMERRL register.
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_write_timerrl(
   SI32_I2C_A_Type * basePointer,
   uint32_t timerrl)
{
   //{{
   basePointer->TIMERRL.U32 = timerrl;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_read_timerrl
//
// Reads TIMERRL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2C_A_read_timerrl(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return basePointer->TIMERRL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_set_timer0_reload
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_set_timer0_reload(
   SI32_I2C_A_Type * basePointer,
   uwide8_t value)
{
   assert(value < 256);   // value < 2^8
   //{{
   basePointer->TIMERRL.T0RL = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_get_timer0_reload
//
//-----------------------------------------------------------------------------
uwide8_t
_SI32_I2C_A_get_timer0_reload(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return basePointer->TIMERRL.T0RL;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_set_timer1_reload
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_set_timer1_reload(
   SI32_I2C_A_Type * basePointer,
   uwide8_t value)
{
   assert(value < 256);   // value < 2^8
   //{{
   basePointer->TIMERRL.T1RL = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_get_timer1_reload
//
//-----------------------------------------------------------------------------
uwide8_t
_SI32_I2C_A_get_timer1_reload(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return basePointer->TIMERRL.T1RL;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_set_timer2_reload
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_set_timer2_reload(
   SI32_I2C_A_Type * basePointer,
   uwide8_t value)
{
   assert(value < 256);   // value < 2^8
   //{{
   basePointer->TIMERRL.T2RL = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_get_timer2_reload
//
//-----------------------------------------------------------------------------
uwide8_t
_SI32_I2C_A_get_timer2_reload(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return basePointer->TIMERRL.T2RL;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_set_timer3_reload
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_set_timer3_reload(
   SI32_I2C_A_Type * basePointer,
   uwide8_t value)
{
   assert(value < 256);   // value < 2^8
   //{{
   basePointer->TIMERRL.T3RL = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_get_timer3_reload
//
//-----------------------------------------------------------------------------
uwide8_t
_SI32_I2C_A_get_timer3_reload(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return basePointer->TIMERRL.T3RL;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_set_16bit_timer_reload_low
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_set_16bit_timer_reload_low(
   SI32_I2C_A_Type * basePointer,
   uwide16_t value)
{
   assert(value < 65536);   // value < 2^16
   //{{
   basePointer->TIMERRL.T1RL = (value >> 8) & 0xFF;
   basePointer->TIMERRL.T0RL = (value     ) & 0xFF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_get_16bit_timer_reload_low
//
//-----------------------------------------------------------------------------
uwide16_t
_SI32_I2C_A_get_16bit_timer_reload_low(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (basePointer->TIMERRL.T1RL << 8) | basePointer->TIMERRL.T0RL;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_set_16bit_timer_reload_high
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_set_16bit_timer_reload_high(
   SI32_I2C_A_Type * basePointer,
   uwide16_t value)
{
   assert(value < 65536);   // value < 2^16
   //{{
   basePointer->TIMERRL.T3RL = (value >>  8) & 0xFF;
   basePointer->TIMERRL.T2RL = (value      ) & 0xFF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_get_16bit_timer_reload_high
//
//-----------------------------------------------------------------------------
uwide16_t
_SI32_I2C_A_get_16bit_timer_reload_high(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (basePointer->TIMERRL.T3RL << 8) | basePointer->TIMERRL.T2RL;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_write_sconfig
//
// Write to SCONFIG register.
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_write_sconfig(
   SI32_I2C_A_Type * basePointer,
   uint32_t sconfig)
{
   //{{
   basePointer->SCONFIG.U32 = sconfig;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_read_sconfig
//
// Reads SCONFIG register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2C_A_read_sconfig(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return basePointer->SCONFIG.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_set_extended_data_setup_time
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_set_extended_data_setup_time(
   SI32_I2C_A_Type * basePointer,
   uint32_t value)
{
   assert(value < 16);   // value < 2^4
   //{{
   basePointer->SCONFIG.SETUP = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_get_extended_data_setup_time
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2C_A_get_extended_data_setup_time(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return basePointer->SCONFIG.SETUP;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_set_extended_data_hold_time
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_set_extended_data_hold_time(
   SI32_I2C_A_Type * basePointer,
   uint32_t value)
{
   assert(value < 16);   // value < 2^4
   //{{
   basePointer->SCONFIG.HOLD = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_get_extended_data_hold_time
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2C_A_get_extended_data_hold_time(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return basePointer->SCONFIG.HOLD;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_set_scl_low_period_reload
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_set_scl_low_period_reload(
   SI32_I2C_A_Type * basePointer,
   uwide8_t value)
{
   assert(value < 256);   // value < 2^8
   //{{
   basePointer->SCONFIG.SCLL = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_get_scl_low_period_reload
//
//-----------------------------------------------------------------------------
uwide8_t
_SI32_I2C_A_get_scl_low_period_reload(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return basePointer->SCONFIG.SCLL;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_write_i2cdma
//
// Write to I2CDMA register.
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_write_i2cdma(
   SI32_I2C_A_Type * basePointer,
   uint32_t i2cdma)
{
   //{{
   basePointer->I2CDMA.U32 = i2cdma;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_read_i2cdma
//
// Reads I2CDMA register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2C_A_read_i2cdma(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return basePointer->I2CDMA.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_set_dma_byte_count
//
// Writes the number of bytes to transmit or receive.
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_set_dma_byte_count(
   SI32_I2C_A_Type * basePointer,
   uwide8_t value)
{
   assert(value < 256);   // value < 2^8
   //{{
   basePointer->I2CDMA.DMALEN = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_get_dma_byte_count
//
// Returns the number of bytes to transmit or receive.
//-----------------------------------------------------------------------------
uwide8_t
_SI32_I2C_A_get_dma_byte_count(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return basePointer->I2CDMA.DMALEN;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_enable_dma
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_enable_dma(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->I2CDMA.DMAEN = SI32_I2C_A_I2CDMA_DMAEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_disable_dma
//
//-----------------------------------------------------------------------------
void
_SI32_I2C_A_disable_dma(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   basePointer->I2CDMA.DMAEN = SI32_I2C_A_I2CDMA_DMAEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2C_A_is_dma_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_I2C_A_is_dma_enabled(
   SI32_I2C_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->I2CDMA.DMAEN);
   //}}
}


//-eof--------------------------------------------------------------------------
