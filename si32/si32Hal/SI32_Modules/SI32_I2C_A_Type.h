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
/// @file SI32_I2C_A_Type.h
//
// Script: 0.58
// HAL Source: 0.3
// Version: 1

#ifndef __SI32_I2C_A_TYPE_H__
#define __SI32_I2C_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_I2C_A_Registers.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_I2C_A_initialize(SI32_I2C_A_Type* basePointer,
///      uint32_t control,
///      uint32_t config,
///      uint32_t saddress,
///      uint32_t smask,
///      uint32_t timer,
///      uint32_t timerrl,
///      uint32_t sconfig,
///      uint32_t i2cdma)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///  Write to CONTROL register.
///
/// @param[in]
///  config
///  Valid range is 32 bits.
///  Write to CONFIG register.
///
/// @param[in]
///  saddress
///  Valid range is 32 bits.
///  Write to SADDRESS register.
///
/// @param[in]
///  smask
///  Valid range is 32 bits.
///  Write to SMASK register.
///
/// @param[in]
///  timer
///  Valid range is 32 bits.
///  Write to TIMER register.
///
/// @param[in]
///  timerrl
///  Valid range is 32 bits.
///  Write to TIMERRL register.
///
/// @param[in]
///  sconfig
///  Valid range is 32 bits.
///  Write to SCONFIG register.
///
/// @param[in]
///  i2cdma
///  Valid range is 32 bits.
///  Write to I2CDMA register.
///
void
_SI32_I2C_A_initialize(SI32_I2C_A_Type* /*basePointer*/,
   uint32_t, /*control*/
   uint32_t, /*config*/
   uint32_t, /*saddress*/
   uint32_t, /*smask*/
   uint32_t, /*timer*/
   uint32_t, /*timerrl*/
   uint32_t, /*sconfig*/
   uint32_t /*i2cdma*/);
///
/// @def SI32_I2C_A_initialize(basePointer, control, config, saddress, smask, timer, timerrl, sconfig, i2cdma)
#define SI32_I2C_A_initialize(basePointer, control, config, saddress, smask, timer, timerrl, sconfig, i2cdma) do{  \
   basePointer->CONTROL.U32 = control;\
   basePointer->CONFIG.U32 = config;\
   basePointer->SADDRESS.U32 = saddress;\
   basePointer->SMASK.U32 = smask;\
   basePointer->TIMER.U32 = timer;\
   basePointer->TIMERRL.U32 = timerrl;\
   basePointer->SCONFIG.U32 = sconfig;\
   basePointer->I2CDMA.U32 = i2cdma;\
} while(0)


/// @fn _SI32_I2C_A_write_control(SI32_I2C_A_Type* basePointer,
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
_SI32_I2C_A_write_control(SI32_I2C_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_I2C_A_write_control(basePointer, control)
#define SI32_I2C_A_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_I2C_A_read_control(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Read CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2C_A_read_control(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_read_control(basePointer)
#define SI32_I2C_A_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_I2C_A_is_busy(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_busy(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_busy(basePointer)
#define SI32_I2C_A_is_busy(basePointer) \
((bool)(basePointer->CONTROL.BUSYF))


/// @fn _SI32_I2C_A_is_ack_received(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Returns TRUE is ACK was recevied and returns FALSE if NACK was
/// received.
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_ack_received(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_ack_received(basePointer)
#define SI32_I2C_A_is_ack_received(basePointer) \
((bool)(basePointer->CONTROL.ACK))


/// @fn _SI32_I2C_A_send_ack(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_send_ack(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_send_ack(basePointer)
#define SI32_I2C_A_send_ack(basePointer) \
   (basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_ACK_SET_U32)


/// @fn _SI32_I2C_A_send_nack(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_send_nack(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_send_nack(basePointer)
#define SI32_I2C_A_send_nack(basePointer) \
   (basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_ACK_MASK)


/// @fn _SI32_I2C_A_has_arblost_error_occurred(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_has_arblost_error_occurred(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_has_arblost_error_occurred(basePointer)
#define SI32_I2C_A_has_arblost_error_occurred(basePointer) \
((bool)(basePointer->CONTROL.ARBLF))


/// @fn _SI32_I2C_A_is_ack_requested(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_ack_requested(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_ack_requested(basePointer)
#define SI32_I2C_A_is_ack_requested(basePointer) \
((bool)(basePointer->CONTROL.ACKRQF))


/// @fn _SI32_I2C_A_set_stop(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_set_stop(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_set_stop(basePointer)
#define SI32_I2C_A_set_stop(basePointer) \
   (basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_STO_SET_U32)


/// @fn _SI32_I2C_A_clear_stop(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_clear_stop(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_clear_stop(basePointer)
#define SI32_I2C_A_clear_stop(basePointer) \
   (basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_STO_MASK)


/// @fn _SI32_I2C_A_is_stop_set(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_stop_set(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_stop_set(basePointer)
#define SI32_I2C_A_is_stop_set(basePointer) \
((bool)(basePointer->CONTROL.STO))


/// @fn _SI32_I2C_A_set_start(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_set_start(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_set_start(basePointer)
#define SI32_I2C_A_set_start(basePointer) \
   (basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_STA_SET_U32)


/// @fn _SI32_I2C_A_clear_start(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_clear_start(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_clear_start(basePointer)
#define SI32_I2C_A_clear_start(basePointer) \
   (basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_STA_MASK)


/// @fn _SI32_I2C_A_is_start_set(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_start_set(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_start_set(basePointer)
#define SI32_I2C_A_is_start_set(basePointer) \
((bool)(basePointer->CONTROL.STA))


/// @fn _SI32_I2C_A_is_tx_mode_enabled(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_tx_mode_enabled(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_tx_mode_enabled(basePointer)
#define SI32_I2C_A_is_tx_mode_enabled(basePointer) \
((bool)(basePointer->CONTROL.TXMDF))


/// @fn _SI32_I2C_A_is_master_mode_enabled(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_master_mode_enabled(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_master_mode_enabled(basePointer)
#define SI32_I2C_A_is_master_mode_enabled(basePointer) \
((bool)(basePointer->CONTROL.MSMDF))


/// @fn _SI32_I2C_A_clear_stop_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_clear_stop_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_clear_stop_interrupt(basePointer)
#define SI32_I2C_A_clear_stop_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_STOI_MASK)


/// @fn _SI32_I2C_A_is_stop_interrupt_pending(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_stop_interrupt_pending(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_stop_interrupt_pending(basePointer)
#define SI32_I2C_A_is_stop_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.STOI))


/// @fn _SI32_I2C_A_clear_ack_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_clear_ack_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_clear_ack_interrupt(basePointer)
#define SI32_I2C_A_clear_ack_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_ACKI_MASK)


/// @fn _SI32_I2C_A_is_ack_interrupt_pending(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_ack_interrupt_pending(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_ack_interrupt_pending(basePointer)
#define SI32_I2C_A_is_ack_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.ACKI))


/// @fn _SI32_I2C_A_clear_rx_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_clear_rx_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_clear_rx_interrupt(basePointer)
#define SI32_I2C_A_clear_rx_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_RXI_MASK)


/// @fn _SI32_I2C_A_is_rx_interrupt_pending(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_rx_interrupt_pending(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_rx_interrupt_pending(basePointer)
#define SI32_I2C_A_is_rx_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.RXI))


/// @fn _SI32_I2C_A_clear_tx_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_clear_tx_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_clear_tx_interrupt(basePointer)
#define SI32_I2C_A_clear_tx_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_TXI_MASK)


/// @fn _SI32_I2C_A_is_tx_interrupt_pending(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_tx_interrupt_pending(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_tx_interrupt_pending(basePointer)
#define SI32_I2C_A_is_tx_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.TXI))


/// @fn _SI32_I2C_A_clear_start_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_clear_start_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_clear_start_interrupt(basePointer)
#define SI32_I2C_A_clear_start_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_STAI_MASK)


/// @fn _SI32_I2C_A_is_start_interrupt_pending(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_start_interrupt_pending(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_start_interrupt_pending(basePointer)
#define SI32_I2C_A_is_start_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.STAI))


/// @fn _SI32_I2C_A_clear_arblost_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_clear_arblost_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_clear_arblost_interrupt(basePointer)
#define SI32_I2C_A_clear_arblost_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_ARBLI_MASK)


/// @fn _SI32_I2C_A_is_arblost_interrupt_pending(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_arblost_interrupt_pending(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_arblost_interrupt_pending(basePointer)
#define SI32_I2C_A_is_arblost_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.ARBLI))


/// @fn _SI32_I2C_A_clear_timer0_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_clear_timer0_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_clear_timer0_interrupt(basePointer)
#define SI32_I2C_A_clear_timer0_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_T0I_MASK)


/// @fn _SI32_I2C_A_is_timer0_interrupt_pending(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Overflow event for Timer 0.
///
/// @return
///  Returns TRUE is a Timer 0 overflow interrupt is pending, otherwise
///  returns FALSE.
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_timer0_interrupt_pending(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_timer0_interrupt_pending(basePointer)
#define SI32_I2C_A_is_timer0_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.T0I))


/// @fn _SI32_I2C_A_clear_timer1_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_clear_timer1_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_clear_timer1_interrupt(basePointer)
#define SI32_I2C_A_clear_timer1_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_T1I_MASK)


/// @fn _SI32_I2C_A_is_timer1_interrupt_pending(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Overflow event for Timer 1.
///
/// @return
///  Returns TRUE is a Timer 1 overflow interrupt is pending, otherwise
///  returns FALSE.
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_timer1_interrupt_pending(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_timer1_interrupt_pending(basePointer)
#define SI32_I2C_A_is_timer1_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.T1I))


/// @fn _SI32_I2C_A_clear_timer2_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_clear_timer2_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_clear_timer2_interrupt(basePointer)
#define SI32_I2C_A_clear_timer2_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_T2I_MASK)


/// @fn _SI32_I2C_A_is_timer2_interrupt_pending(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Overflow event for Timer 2.
///
/// @return
///  Returns TRUE is a Timer 2 overflow interrupt is pending, otherwise
///  returns FALSE.
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_timer2_interrupt_pending(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_timer2_interrupt_pending(basePointer)
#define SI32_I2C_A_is_timer2_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.T2I))


/// @fn _SI32_I2C_A_clear_timer3_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_clear_timer3_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_clear_timer3_interrupt(basePointer)
#define SI32_I2C_A_clear_timer3_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_T3I_MASK)


/// @fn _SI32_I2C_A_is_timer3_interrupt_pending(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Overflow event for Timer 3.
///
/// @return
///  Returns TRUE is a Timer 3 overflow interrupt is pending, otherwise
///  returns FALSE.
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_timer3_interrupt_pending(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_timer3_interrupt_pending(basePointer)
#define SI32_I2C_A_is_timer3_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.T3I))


/// @fn _SI32_I2C_A_arm_rx(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_arm_rx(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_arm_rx(basePointer)
#define SI32_I2C_A_arm_rx(basePointer) \
   (basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_RXARM_ENABLED_U32)


/// @fn _SI32_I2C_A_disarm_rx(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_disarm_rx(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_disarm_rx(basePointer)
#define SI32_I2C_A_disarm_rx(basePointer) \
   (basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_RXARM_MASK)


/// @fn _SI32_I2C_A_is_rx_in_progress(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Returns TRUE if a receive is in progress and returns FALSE if a
/// receive is not in progress.
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_rx_in_progress(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_rx_in_progress(basePointer)
#define SI32_I2C_A_is_rx_in_progress(basePointer) \
((bool)(basePointer->CONTROL.RXARM))


/// @fn _SI32_I2C_A_arm_tx(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_arm_tx(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_arm_tx(basePointer)
#define SI32_I2C_A_arm_tx(basePointer) \
   (basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_TXARM_ENABLED_U32)


/// @fn _SI32_I2C_A_disarm_tx(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_disarm_tx(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_disarm_tx(basePointer)
#define SI32_I2C_A_disarm_tx(basePointer) \
   (basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_TXARM_MASK)


/// @fn _SI32_I2C_A_is_tx_in_progress(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Returns TRUE if a transmit is in progress and returns FALSE if a
/// transmit is not in progress.
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_tx_in_progress(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_tx_in_progress(basePointer)
#define SI32_I2C_A_is_tx_in_progress(basePointer) \
((bool)(basePointer->CONTROL.TXARM))


/// @fn _SI32_I2C_A_is_general_call_address_detected(SI32_I2C_A_Type* basePointer)
///
/// @return
///  Returns TRUE if a general call address is received and returns FALSE
///  if a slave address is received.
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_general_call_address_detected(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_general_call_address_detected(basePointer)
#define SI32_I2C_A_is_general_call_address_detected(basePointer) \
((bool)(basePointer->CONTROL.GCEN))


/// @fn _SI32_I2C_A_enable_auto_tx_or_rx(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_enable_auto_tx_or_rx(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_enable_auto_tx_or_rx(basePointer)
#define SI32_I2C_A_enable_auto_tx_or_rx(basePointer) \
   (basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_ATXRXEN_MASK)


/// @fn _SI32_I2C_A_disable_auto_tx_or_rx(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_disable_auto_tx_or_rx(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_disable_auto_tx_or_rx(basePointer)
#define SI32_I2C_A_disable_auto_tx_or_rx(basePointer) \
   (basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_ATXRXEN_MASK)


/// @fn _SI32_I2C_A_enable_input_filter(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_enable_input_filter(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_enable_input_filter(basePointer)
#define SI32_I2C_A_enable_input_filter(basePointer) \
   (basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_FMD_ENABLED_U32)


/// @fn _SI32_I2C_A_disable_input_filter(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_disable_input_filter(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_disable_input_filter(basePointer)
#define SI32_I2C_A_disable_input_filter(basePointer) \
   (basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_FMD_MASK)


/// @fn _SI32_I2C_A_enable_stall_in_debug_mode(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Stalls the module when debug mode is active.
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_enable_stall_in_debug_mode(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_enable_stall_in_debug_mode(basePointer)
#define SI32_I2C_A_enable_stall_in_debug_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_DBGMD_HALT_U32)


/// @fn _SI32_I2C_A_disable_stall_in_debug_mode(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Normal operation when debug mode is active.
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_disable_stall_in_debug_mode(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_disable_stall_in_debug_mode(basePointer)
#define SI32_I2C_A_disable_stall_in_debug_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_DBGMD_MASK)


/// @fn _SI32_I2C_A_enable_slave_mode(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_enable_slave_mode(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_enable_slave_mode(basePointer)
#define SI32_I2C_A_enable_slave_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_SMINH_MASK)


/// @fn _SI32_I2C_A_disable_slave_mode(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_disable_slave_mode(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_disable_slave_mode(basePointer)
#define SI32_I2C_A_disable_slave_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_SMINH_ACTIVE_U32)


/// @fn _SI32_I2C_A_enable_auto_ack(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_enable_auto_ack(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_enable_auto_ack(basePointer)
#define SI32_I2C_A_enable_auto_ack(basePointer) \
   (basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_HACKEN_ENABLED_U32)


/// @fn _SI32_I2C_A_disable_auto_ack(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_disable_auto_ack(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_disable_auto_ack(basePointer)
#define SI32_I2C_A_disable_auto_ack(basePointer) \
   (basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_HACKEN_MASK)


/// @fn _SI32_I2C_A_enable_last_byte_ack(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_enable_last_byte_ack(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_enable_last_byte_ack(basePointer)
#define SI32_I2C_A_enable_last_byte_ack(basePointer) \
   (basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_LBACKEN_ENABLED_U32)


/// @fn _SI32_I2C_A_disable_last_byte_ack(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_disable_last_byte_ack(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_disable_last_byte_ack(basePointer)
#define SI32_I2C_A_disable_last_byte_ack(basePointer) \
   (basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_LBACKEN_MASK)


/// @fn _SI32_I2C_A_enable_general_call_address_decode(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_enable_general_call_address_decode(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_enable_general_call_address_decode(basePointer)
#define SI32_I2C_A_enable_general_call_address_decode(basePointer) \
   (basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_GCEN_MASK)


/// @fn _SI32_I2C_A_disable_general_call_address_decode(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_disable_general_call_address_decode(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_disable_general_call_address_decode(basePointer)
#define SI32_I2C_A_disable_general_call_address_decode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_GCEN_MASK)


/// @fn _SI32_I2C_A_reset_module(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_reset_module(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_reset_module(basePointer)
#define SI32_I2C_A_reset_module(basePointer) do{  \
   basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_RESET_MASK;\
   basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_RESET_MASK;\
} while(0)


/// @fn _SI32_I2C_A_enable_module(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_enable_module(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_enable_module(basePointer)
#define SI32_I2C_A_enable_module(basePointer) \
   (basePointer->CONTROL_SET = SI32_I2C_A_CONTROL_I2CEN_MASK)


/// @fn _SI32_I2C_A_disable_module(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_disable_module(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_disable_module(basePointer)
#define SI32_I2C_A_disable_module(basePointer) \
   (basePointer->CONTROL_CLR = SI32_I2C_A_CONTROL_I2CEN_MASK)


/// @fn _SI32_I2C_A_write_config(SI32_I2C_A_Type* basePointer,
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
_SI32_I2C_A_write_config(SI32_I2C_A_Type* /*basePointer*/,
   uint32_t /*config*/);
///
/// @def SI32_I2C_A_write_config(basePointer, config)
#define SI32_I2C_A_write_config(basePointer, config) \
   (basePointer->CONFIG.U32 = config)


/// @fn _SI32_I2C_A_read_config(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Reads CONFIG register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2C_A_read_config(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_read_config(basePointer)
#define SI32_I2C_A_read_config(basePointer) \
(basePointer->CONFIG.U32)


/// @fn _SI32_I2C_A_set_scaler_value(SI32_I2C_A_Type* basePointer,
///      uint32_t value)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 6 bits.
///
void
_SI32_I2C_A_set_scaler_value(SI32_I2C_A_Type* /*basePointer*/,
   uint32_t /*value*/);
///
/// @def SI32_I2C_A_set_scaler_value(basePointer, value)
#define SI32_I2C_A_set_scaler_value(basePointer, value) \
   (basePointer->CONFIG.SCALER = value)


/// @fn _SI32_I2C_A_get_scaler_value(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2C_A_get_scaler_value(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_get_scaler_value(basePointer)
#define SI32_I2C_A_get_scaler_value(basePointer) \
(basePointer->CONFIG.SCALER)


/// @fn _SI32_I2C_A_enable_stop_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_enable_stop_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_enable_stop_interrupt(basePointer)
#define SI32_I2C_A_enable_stop_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_STOIEN_ENABLED_U32)


/// @fn _SI32_I2C_A_disable_stop_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_disable_stop_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_disable_stop_interrupt(basePointer)
#define SI32_I2C_A_disable_stop_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_STOIEN_MASK)


/// @fn _SI32_I2C_A_is_stop_interrupt_enabled(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_stop_interrupt_enabled(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_stop_interrupt_enabled(basePointer)
#define SI32_I2C_A_is_stop_interrupt_enabled(basePointer) \
((bool)(basePointer->CONFIG.STOIEN))


/// @fn _SI32_I2C_A_enable_ack_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_enable_ack_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_enable_ack_interrupt(basePointer)
#define SI32_I2C_A_enable_ack_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_ACKIEN_ENABLED_U32)


/// @fn _SI32_I2C_A_disable_ack_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_disable_ack_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_disable_ack_interrupt(basePointer)
#define SI32_I2C_A_disable_ack_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_ACKIEN_MASK)


/// @fn _SI32_I2C_A_is_ack_interrupt_enabled(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_ack_interrupt_enabled(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_ack_interrupt_enabled(basePointer)
#define SI32_I2C_A_is_ack_interrupt_enabled(basePointer) \
((bool)(basePointer->CONFIG.ACKIEN))


/// @fn _SI32_I2C_A_enable_rx_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_enable_rx_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_enable_rx_interrupt(basePointer)
#define SI32_I2C_A_enable_rx_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_RXIEN_ENABLED_U32)


/// @fn _SI32_I2C_A_disable_rx_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_disable_rx_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_disable_rx_interrupt(basePointer)
#define SI32_I2C_A_disable_rx_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_RXIEN_MASK)


/// @fn _SI32_I2C_A_is_rx_interrupt_enabled(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_rx_interrupt_enabled(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_rx_interrupt_enabled(basePointer)
#define SI32_I2C_A_is_rx_interrupt_enabled(basePointer) \
((bool)(basePointer->CONFIG.RXIEN))


/// @fn _SI32_I2C_A_enable_tx_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_enable_tx_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_enable_tx_interrupt(basePointer)
#define SI32_I2C_A_enable_tx_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_TXIEN_ENABLED_U32)


/// @fn _SI32_I2C_A_disable_tx_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_disable_tx_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_disable_tx_interrupt(basePointer)
#define SI32_I2C_A_disable_tx_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_TXIEN_MASK)


/// @fn _SI32_I2C_A_is_tx_interrupt_enabled(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_tx_interrupt_enabled(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_tx_interrupt_enabled(basePointer)
#define SI32_I2C_A_is_tx_interrupt_enabled(basePointer) \
((bool)(basePointer->CONFIG.TXIEN))


/// @fn _SI32_I2C_A_enable_start_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_enable_start_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_enable_start_interrupt(basePointer)
#define SI32_I2C_A_enable_start_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_STAIEN_ENABLED_U32)


/// @fn _SI32_I2C_A_disable_start_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_disable_start_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_disable_start_interrupt(basePointer)
#define SI32_I2C_A_disable_start_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_STAIEN_MASK)


/// @fn _SI32_I2C_A_is_start_interrupt_enabled(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_start_interrupt_enabled(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_start_interrupt_enabled(basePointer)
#define SI32_I2C_A_is_start_interrupt_enabled(basePointer) \
((bool)(basePointer->CONFIG.STAIEN))


/// @fn _SI32_I2C_A_enable_arblost_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_enable_arblost_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_enable_arblost_interrupt(basePointer)
#define SI32_I2C_A_enable_arblost_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_ARBLIEN_MASK)


/// @fn _SI32_I2C_A_disable_arblost_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_disable_arblost_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_disable_arblost_interrupt(basePointer)
#define SI32_I2C_A_disable_arblost_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_ARBLIEN_MASK)


/// @fn _SI32_I2C_A_is_arblost_interrupt_enabled(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_arblost_interrupt_enabled(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_arblost_interrupt_enabled(basePointer)
#define SI32_I2C_A_is_arblost_interrupt_enabled(basePointer) \
((bool)(basePointer->CONFIG.ARBLIEN))


/// @fn _SI32_I2C_A_enable_timer0_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Enable interrupt for overflow event for Timer 0.
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_enable_timer0_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_enable_timer0_interrupt(basePointer)
#define SI32_I2C_A_enable_timer0_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_T0IEN_ENABLED_U32)


/// @fn _SI32_I2C_A_disable_timer0_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_disable_timer0_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_disable_timer0_interrupt(basePointer)
#define SI32_I2C_A_disable_timer0_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_T0IEN_MASK)


/// @fn _SI32_I2C_A_is_timer0_interrupt_enabled(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_timer0_interrupt_enabled(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_timer0_interrupt_enabled(basePointer)
#define SI32_I2C_A_is_timer0_interrupt_enabled(basePointer) \
((bool)(basePointer->CONFIG.T0IEN))


/// @fn _SI32_I2C_A_enable_timer1_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Enable interrupt for overflow event for Timer 1.
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_enable_timer1_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_enable_timer1_interrupt(basePointer)
#define SI32_I2C_A_enable_timer1_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_T1IEN_ENABLED_U32)


/// @fn _SI32_I2C_A_disable_timer1_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_disable_timer1_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_disable_timer1_interrupt(basePointer)
#define SI32_I2C_A_disable_timer1_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_T1IEN_MASK)


/// @fn _SI32_I2C_A_is_timer1_interrupt_enabled(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_timer1_interrupt_enabled(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_timer1_interrupt_enabled(basePointer)
#define SI32_I2C_A_is_timer1_interrupt_enabled(basePointer) \
((bool)(basePointer->CONFIG.T1IEN))


/// @fn _SI32_I2C_A_enable_timer2_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Enable interrupt for overflow event for Timer 2.
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_enable_timer2_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_enable_timer2_interrupt(basePointer)
#define SI32_I2C_A_enable_timer2_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_T2IEN_ENABLED_U32)


/// @fn _SI32_I2C_A_disable_timer2_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_disable_timer2_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_disable_timer2_interrupt(basePointer)
#define SI32_I2C_A_disable_timer2_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_T2IEN_MASK)


/// @fn _SI32_I2C_A_is_timer2_interrupt_enabled(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_timer2_interrupt_enabled(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_timer2_interrupt_enabled(basePointer)
#define SI32_I2C_A_is_timer2_interrupt_enabled(basePointer) \
((bool)(basePointer->CONFIG.T2IEN))


/// @fn _SI32_I2C_A_enable_timer3_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Enable interrupt for overflow event for Timer 3.
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_enable_timer3_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_enable_timer3_interrupt(basePointer)
#define SI32_I2C_A_enable_timer3_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_T3IEN_ENABLED_U32)


/// @fn _SI32_I2C_A_disable_timer3_interrupt(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_disable_timer3_interrupt(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_disable_timer3_interrupt(basePointer)
#define SI32_I2C_A_disable_timer3_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_T3IEN_MASK)


/// @fn _SI32_I2C_A_is_timer3_interrupt_enabled(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_timer3_interrupt_enabled(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_timer3_interrupt_enabled(basePointer)
#define SI32_I2C_A_is_timer3_interrupt_enabled(basePointer) \
((bool)(basePointer->CONFIG.T3IEN))


/// @fn _SI32_I2C_A_get_byte_count(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Returns the number of bytes to transmit or receive if DMA is disabled.
///
/// @return
///  0 = four bytes, 1 = one byte, 2 = two bytes, and 3 = three bytes.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2C_A_get_byte_count(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_get_byte_count(basePointer)
#define SI32_I2C_A_get_byte_count(basePointer) \
(basePointer->CONFIG.BC)


/// @fn _SI32_I2C_A_set_byte_count(SI32_I2C_A_Type* basePointer,
///      uint32_t value)
///
/// @brief
/// Returns the number of bytes to transmit or receive if DMA is disabled.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 2 bits.
///  0 = four bytes, 1 = one byte, 2 = two bytes, and 3 = three bytes.
///
void
_SI32_I2C_A_set_byte_count(SI32_I2C_A_Type* /*basePointer*/,
   uint32_t /*value*/);
///
/// @def SI32_I2C_A_set_byte_count(basePointer, value)
#define SI32_I2C_A_set_byte_count(basePointer, value) \
   (basePointer->CONFIG.BC = value)


/// @fn _SI32_I2C_A_get_byte_pointer(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Returns the byte of the current transfer being sent or receieved. When
/// this value equals the byte count, the transfer is completed. This
/// setting has no effect when DMA mode is enabled.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2C_A_get_byte_pointer(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_get_byte_pointer(basePointer)
#define SI32_I2C_A_get_byte_pointer(basePointer) \
(basePointer->CONFIG.BP)


/// @fn _SI32_I2C_A_start_timer0(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_start_timer0(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_start_timer0(basePointer)
#define SI32_I2C_A_start_timer0(basePointer) \
   (basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_T0RUN_MASK)


/// @fn _SI32_I2C_A_stop_timer0(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_stop_timer0(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_stop_timer0(basePointer)
#define SI32_I2C_A_stop_timer0(basePointer) \
   (basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_T0RUN_MASK)


/// @fn _SI32_I2C_A_start_timer1(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_start_timer1(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_start_timer1(basePointer)
#define SI32_I2C_A_start_timer1(basePointer) \
   (basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_T1RUN_MASK)


/// @fn _SI32_I2C_A_stop_timer1(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_stop_timer1(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_stop_timer1(basePointer)
#define SI32_I2C_A_stop_timer1(basePointer) \
   (basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_T1RUN_MASK)


/// @fn _SI32_I2C_A_start_timer2(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_start_timer2(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_start_timer2(basePointer)
#define SI32_I2C_A_start_timer2(basePointer) \
   (basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_T2RUN_MASK)


/// @fn _SI32_I2C_A_stop_timer2(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_stop_timer2(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_stop_timer2(basePointer)
#define SI32_I2C_A_stop_timer2(basePointer) \
   (basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_T2RUN_MASK)


/// @fn _SI32_I2C_A_start_timer3(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_start_timer3(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_start_timer3(basePointer)
#define SI32_I2C_A_start_timer3(basePointer) \
   (basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_T3RUN_MASK)


/// @fn _SI32_I2C_A_stop_timer3(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_stop_timer3(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_stop_timer3(basePointer)
#define SI32_I2C_A_stop_timer3(basePointer) \
   (basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_T3RUN_MASK)


/// @fn _SI32_I2C_A_enter_32bit_timer_mode(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Timer is configured as one 32-bit timer.
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_enter_32bit_timer_mode(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_enter_32bit_timer_mode(basePointer)
#define SI32_I2C_A_enter_32bit_timer_mode(basePointer) \
   (basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_TMD_MASK)


/// @fn _SI32_I2C_A_enter_16bit_timer_mode(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Timer is configured as two 16-bit timers (16-bit high and 16-bit low).
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_enter_16bit_timer_mode(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_enter_16bit_timer_mode(basePointer)
#define SI32_I2C_A_enter_16bit_timer_mode(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_TMD_MASK;\
   basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_TMD_MODE1_U32;\
} while(0)


/// @fn _SI32_I2C_A_enter_8bit_timer_mode(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Timer is configured as four 8-bit timers (8-bit timer3, 8-bit timer2,
/// 8-bit timer1, 8-bit timer0).
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_enter_8bit_timer_mode(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_enter_8bit_timer_mode(basePointer)
#define SI32_I2C_A_enter_8bit_timer_mode(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_TMD_MASK;\
   basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_TMD_MODE2_U32;\
} while(0)


/// @fn _SI32_I2C_A_enter_16bit_two_8bit_timer_mode(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Timer is configured as one 16-bit timer (16-bit high timer) and two
/// 8-bit timers (8-bit timer1, 8-bit timer0).
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_enter_16bit_two_8bit_timer_mode(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_enter_16bit_two_8bit_timer_mode(basePointer)
#define SI32_I2C_A_enter_16bit_two_8bit_timer_mode(basePointer) \
   (basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_TMD_MODE3_U32)


/// @fn _SI32_I2C_A_enable_all_timers(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_enable_all_timers(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_enable_all_timers(basePointer)
#define SI32_I2C_A_enable_all_timers(basePointer) \
   (basePointer->CONFIG_SET = SI32_I2C_A_CONFIG_TIMEREN_MASK)


/// @fn _SI32_I2C_A_disable_all_timers(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_disable_all_timers(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_disable_all_timers(basePointer)
#define SI32_I2C_A_disable_all_timers(basePointer) \
   (basePointer->CONFIG_CLR = SI32_I2C_A_CONFIG_TIMEREN_MASK)


/// @fn _SI32_I2C_A_write_saddress(SI32_I2C_A_Type* basePointer,
///      uint32_t saddress)
///
/// @brief
/// Write to SADDRESS register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  saddress
///  Valid range is 32 bits.
///
void
_SI32_I2C_A_write_saddress(SI32_I2C_A_Type* /*basePointer*/,
   uint32_t /*saddress*/);
///
/// @def SI32_I2C_A_write_saddress(basePointer, saddress)
#define SI32_I2C_A_write_saddress(basePointer, saddress) \
   (basePointer->SADDRESS.U32 = saddress)


/// @fn _SI32_I2C_A_read_saddress(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Reads SADDRESS register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2C_A_read_saddress(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_read_saddress(basePointer)
#define SI32_I2C_A_read_saddress(basePointer) \
(basePointer->SADDRESS.U32)


/// @fn _SI32_I2C_A_write_smask(SI32_I2C_A_Type* basePointer,
///      uint32_t smask)
///
/// @brief
/// Write to SMASK register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  smask
///  Valid range is 32 bits.
///
void
_SI32_I2C_A_write_smask(SI32_I2C_A_Type* /*basePointer*/,
   uint32_t /*smask*/);
///
/// @def SI32_I2C_A_write_smask(basePointer, smask)
#define SI32_I2C_A_write_smask(basePointer, smask) \
   (basePointer->SMASK.U32 = smask)


/// @fn _SI32_I2C_A_read_smask(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Reads SMASK register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2C_A_read_smask(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_read_smask(basePointer)
#define SI32_I2C_A_read_smask(basePointer) \
(basePointer->SMASK.U32)


/// @fn _SI32_I2C_A_write_data(SI32_I2C_A_Type* basePointer,
///      uint32_t value)
///
/// @brief
/// Write to DATA register. This function writes four bytes of data to the
/// TX/RX buffer. For each transaction, the hardware will start from the
/// least significant byte.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 32 bits.
///
void
_SI32_I2C_A_write_data(SI32_I2C_A_Type* /*basePointer*/,
   uint32_t /*value*/);
///
/// @def SI32_I2C_A_write_data(basePointer, value)
#define SI32_I2C_A_write_data(basePointer, value) \
   (basePointer->DATA.DATA_BITS = value)


/// @fn _SI32_I2C_A_read_data(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Reads DATA register. Returns four bytes of data from the TX/RX buffer.
/// For each transaction, the hardware will start from the least
/// significant byte.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2C_A_read_data(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_read_data(basePointer)
#define SI32_I2C_A_read_data(basePointer) \
(basePointer->DATA.DATA_BITS)


/// @fn _SI32_I2C_A_write_timer(SI32_I2C_A_Type* basePointer,
///      uint32_t timer)
///
/// @brief
/// Write to TIMER register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  timer
///  Valid range is 32 bits.
///
void
_SI32_I2C_A_write_timer(SI32_I2C_A_Type* /*basePointer*/,
   uint32_t /*timer*/);
///
/// @def SI32_I2C_A_write_timer(basePointer, timer)
#define SI32_I2C_A_write_timer(basePointer, timer) \
   (basePointer->TIMER.U32 = timer)


/// @fn _SI32_I2C_A_read_timer(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Reads TIMER register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2C_A_read_timer(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_read_timer(basePointer)
#define SI32_I2C_A_read_timer(basePointer) \
(basePointer->TIMER.U32)


/// @fn _SI32_I2C_A_set_timer0_u8(SI32_I2C_A_Type* basePointer,
///      uwide8_t value)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 8 bits.
///
void
_SI32_I2C_A_set_timer0_u8(SI32_I2C_A_Type* /*basePointer*/,
   uwide8_t /*value*/);
///
/// @def SI32_I2C_A_set_timer0_u8(basePointer, value)
#define SI32_I2C_A_set_timer0_u8(basePointer, value) \
   (basePointer->TIMER.T0 = value)


/// @fn _SI32_I2C_A_get_timer0_u8(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_I2C_A_get_timer0_u8(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_get_timer0_u8(basePointer)
#define SI32_I2C_A_get_timer0_u8(basePointer) \
(basePointer->TIMER.T0)


/// @fn _SI32_I2C_A_set_timer1_u8(SI32_I2C_A_Type* basePointer,
///      uwide8_t value)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 8 bits.
///
void
_SI32_I2C_A_set_timer1_u8(SI32_I2C_A_Type* /*basePointer*/,
   uwide8_t /*value*/);
///
/// @def SI32_I2C_A_set_timer1_u8(basePointer, value)
#define SI32_I2C_A_set_timer1_u8(basePointer, value) \
   (basePointer->TIMER.T1 = value)


/// @fn _SI32_I2C_A_get_timer1_u8(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_I2C_A_get_timer1_u8(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_get_timer1_u8(basePointer)
#define SI32_I2C_A_get_timer1_u8(basePointer) \
(basePointer->TIMER.T1)


/// @fn _SI32_I2C_A_set_timer2_u8(SI32_I2C_A_Type* basePointer,
///      uwide8_t value)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 8 bits.
///
void
_SI32_I2C_A_set_timer2_u8(SI32_I2C_A_Type* /*basePointer*/,
   uwide8_t /*value*/);
///
/// @def SI32_I2C_A_set_timer2_u8(basePointer, value)
#define SI32_I2C_A_set_timer2_u8(basePointer, value) \
   (basePointer->TIMER.T2 = value)


/// @fn _SI32_I2C_A_get_timer2_u8(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_I2C_A_get_timer2_u8(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_get_timer2_u8(basePointer)
#define SI32_I2C_A_get_timer2_u8(basePointer) \
(basePointer->TIMER.T2)


/// @fn _SI32_I2C_A_set_timer3_u8(SI32_I2C_A_Type* basePointer,
///      uwide8_t value)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 8 bits.
///
void
_SI32_I2C_A_set_timer3_u8(SI32_I2C_A_Type* /*basePointer*/,
   uwide8_t /*value*/);
///
/// @def SI32_I2C_A_set_timer3_u8(basePointer, value)
#define SI32_I2C_A_set_timer3_u8(basePointer, value) \
   (basePointer->TIMER.T3 = value)


/// @fn _SI32_I2C_A_get_timer3_u8(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_I2C_A_get_timer3_u8(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_get_timer3_u8(basePointer)
#define SI32_I2C_A_get_timer3_u8(basePointer) \
(basePointer->TIMER.T3)


/// @fn _SI32_I2C_A_set_timer_low_u16(SI32_I2C_A_Type* basePointer,
///      uwide16_t value)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 16 bits.
///
void
_SI32_I2C_A_set_timer_low_u16(SI32_I2C_A_Type* /*basePointer*/,
   uwide16_t /*value*/);
///
/// @def SI32_I2C_A_set_timer_low_u16(basePointer, value)
#define SI32_I2C_A_set_timer_low_u16(basePointer, value) do{  \
   basePointer->TIMER.T1 = (value >> 8) & 0xFF;\
   basePointer->TIMER.T0 = (value     ) & 0xFF;\
} while(0)


/// @fn _SI32_I2C_A_get_timer_low_u16(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uwide16_t
_SI32_I2C_A_get_timer_low_u16(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_get_timer_low_u16(basePointer)
#define SI32_I2C_A_get_timer_low_u16(basePointer) \
((basePointer->TIMER.T1 << 8) | basePointer->TIMER.T0)


/// @fn _SI32_I2C_A_set_timer_high_u16(SI32_I2C_A_Type* basePointer,
///      uwide16_t value)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 16 bits.
///
void
_SI32_I2C_A_set_timer_high_u16(SI32_I2C_A_Type* /*basePointer*/,
   uwide16_t /*value*/);
///
/// @def SI32_I2C_A_set_timer_high_u16(basePointer, value)
#define SI32_I2C_A_set_timer_high_u16(basePointer, value) do{  \
   basePointer->TIMER.T3 = (value >>  8) & 0xFF;\
   basePointer->TIMER.T2 = (value      ) & 0xFF;\
} while(0)


/// @fn _SI32_I2C_A_get_timer_high_u16(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uwide16_t
_SI32_I2C_A_get_timer_high_u16(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_get_timer_high_u16(basePointer)
#define SI32_I2C_A_get_timer_high_u16(basePointer) \
((basePointer->TIMER.T3 << 8) | basePointer->TIMER.T2)


/// @fn _SI32_I2C_A_write_timerrl(SI32_I2C_A_Type* basePointer,
///      uint32_t timerrl)
///
/// @brief
/// Write to TIMERRL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  timerrl
///  Valid range is 32 bits.
///
void
_SI32_I2C_A_write_timerrl(SI32_I2C_A_Type* /*basePointer*/,
   uint32_t /*timerrl*/);
///
/// @def SI32_I2C_A_write_timerrl(basePointer, timerrl)
#define SI32_I2C_A_write_timerrl(basePointer, timerrl) \
   (basePointer->TIMERRL.U32 = timerrl)


/// @fn _SI32_I2C_A_read_timerrl(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Reads TIMERRL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2C_A_read_timerrl(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_read_timerrl(basePointer)
#define SI32_I2C_A_read_timerrl(basePointer) \
(basePointer->TIMERRL.U32)


/// @fn _SI32_I2C_A_set_timer0_reload(SI32_I2C_A_Type* basePointer,
///      uwide8_t value)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 8 bits.
///
void
_SI32_I2C_A_set_timer0_reload(SI32_I2C_A_Type* /*basePointer*/,
   uwide8_t /*value*/);
///
/// @def SI32_I2C_A_set_timer0_reload(basePointer, value)
#define SI32_I2C_A_set_timer0_reload(basePointer, value) \
   (basePointer->TIMERRL.T0RL = value)


/// @fn _SI32_I2C_A_get_timer0_reload(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_I2C_A_get_timer0_reload(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_get_timer0_reload(basePointer)
#define SI32_I2C_A_get_timer0_reload(basePointer) \
(basePointer->TIMERRL.T0RL)


/// @fn _SI32_I2C_A_set_timer1_reload(SI32_I2C_A_Type* basePointer,
///      uwide8_t value)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 8 bits.
///
void
_SI32_I2C_A_set_timer1_reload(SI32_I2C_A_Type* /*basePointer*/,
   uwide8_t /*value*/);
///
/// @def SI32_I2C_A_set_timer1_reload(basePointer, value)
#define SI32_I2C_A_set_timer1_reload(basePointer, value) \
   (basePointer->TIMERRL.T1RL = value)


/// @fn _SI32_I2C_A_get_timer1_reload(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_I2C_A_get_timer1_reload(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_get_timer1_reload(basePointer)
#define SI32_I2C_A_get_timer1_reload(basePointer) \
(basePointer->TIMERRL.T1RL)


/// @fn _SI32_I2C_A_set_timer2_reload(SI32_I2C_A_Type* basePointer,
///      uwide8_t value)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 8 bits.
///
void
_SI32_I2C_A_set_timer2_reload(SI32_I2C_A_Type* /*basePointer*/,
   uwide8_t /*value*/);
///
/// @def SI32_I2C_A_set_timer2_reload(basePointer, value)
#define SI32_I2C_A_set_timer2_reload(basePointer, value) \
   (basePointer->TIMERRL.T2RL = value)


/// @fn _SI32_I2C_A_get_timer2_reload(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_I2C_A_get_timer2_reload(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_get_timer2_reload(basePointer)
#define SI32_I2C_A_get_timer2_reload(basePointer) \
(basePointer->TIMERRL.T2RL)


/// @fn _SI32_I2C_A_set_timer3_reload(SI32_I2C_A_Type* basePointer,
///      uwide8_t value)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 8 bits.
///
void
_SI32_I2C_A_set_timer3_reload(SI32_I2C_A_Type* /*basePointer*/,
   uwide8_t /*value*/);
///
/// @def SI32_I2C_A_set_timer3_reload(basePointer, value)
#define SI32_I2C_A_set_timer3_reload(basePointer, value) \
   (basePointer->TIMERRL.T3RL = value)


/// @fn _SI32_I2C_A_get_timer3_reload(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_I2C_A_get_timer3_reload(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_get_timer3_reload(basePointer)
#define SI32_I2C_A_get_timer3_reload(basePointer) \
(basePointer->TIMERRL.T3RL)


/// @fn _SI32_I2C_A_set_16bit_timer_reload_low(SI32_I2C_A_Type* basePointer,
///      uwide16_t value)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 16 bits.
///
void
_SI32_I2C_A_set_16bit_timer_reload_low(SI32_I2C_A_Type* /*basePointer*/,
   uwide16_t /*value*/);
///
/// @def SI32_I2C_A_set_16bit_timer_reload_low(basePointer, value)
#define SI32_I2C_A_set_16bit_timer_reload_low(basePointer, value) do{  \
   basePointer->TIMERRL.T1RL = (value >> 8) & 0xFF;\
   basePointer->TIMERRL.T0RL = (value     ) & 0xFF;\
} while(0)


/// @fn _SI32_I2C_A_get_16bit_timer_reload_low(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uwide16_t
_SI32_I2C_A_get_16bit_timer_reload_low(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_get_16bit_timer_reload_low(basePointer)
#define SI32_I2C_A_get_16bit_timer_reload_low(basePointer) \
((basePointer->TIMERRL.T1RL << 8) | basePointer->TIMERRL.T0RL)


/// @fn _SI32_I2C_A_set_16bit_timer_reload_high(SI32_I2C_A_Type* basePointer,
///      uwide16_t value)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 16 bits.
///
void
_SI32_I2C_A_set_16bit_timer_reload_high(SI32_I2C_A_Type* /*basePointer*/,
   uwide16_t /*value*/);
///
/// @def SI32_I2C_A_set_16bit_timer_reload_high(basePointer, value)
#define SI32_I2C_A_set_16bit_timer_reload_high(basePointer, value) do{  \
   basePointer->TIMERRL.T3RL = (value >>  8) & 0xFF;\
   basePointer->TIMERRL.T2RL = (value      ) & 0xFF;\
} while(0)


/// @fn _SI32_I2C_A_get_16bit_timer_reload_high(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uwide16_t
_SI32_I2C_A_get_16bit_timer_reload_high(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_get_16bit_timer_reload_high(basePointer)
#define SI32_I2C_A_get_16bit_timer_reload_high(basePointer) \
((basePointer->TIMERRL.T3RL << 8) | basePointer->TIMERRL.T2RL)


/// @fn _SI32_I2C_A_write_sconfig(SI32_I2C_A_Type* basePointer,
///      uint32_t sconfig)
///
/// @brief
/// Write to SCONFIG register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  sconfig
///  Valid range is 32 bits.
///
void
_SI32_I2C_A_write_sconfig(SI32_I2C_A_Type* /*basePointer*/,
   uint32_t /*sconfig*/);
///
/// @def SI32_I2C_A_write_sconfig(basePointer, sconfig)
#define SI32_I2C_A_write_sconfig(basePointer, sconfig) \
   (basePointer->SCONFIG.U32 = sconfig)


/// @fn _SI32_I2C_A_read_sconfig(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Reads SCONFIG register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2C_A_read_sconfig(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_read_sconfig(basePointer)
#define SI32_I2C_A_read_sconfig(basePointer) \
(basePointer->SCONFIG.U32)


/// @fn _SI32_I2C_A_set_extended_data_setup_time(SI32_I2C_A_Type* basePointer,
///      uint32_t value)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 4 bits.
///
void
_SI32_I2C_A_set_extended_data_setup_time(SI32_I2C_A_Type* /*basePointer*/,
   uint32_t /*value*/);
///
/// @def SI32_I2C_A_set_extended_data_setup_time(basePointer, value)
#define SI32_I2C_A_set_extended_data_setup_time(basePointer, value) \
   (basePointer->SCONFIG.SETUP = value)


/// @fn _SI32_I2C_A_get_extended_data_setup_time(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2C_A_get_extended_data_setup_time(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_get_extended_data_setup_time(basePointer)
#define SI32_I2C_A_get_extended_data_setup_time(basePointer) \
(basePointer->SCONFIG.SETUP)


/// @fn _SI32_I2C_A_set_extended_data_hold_time(SI32_I2C_A_Type* basePointer,
///      uint32_t value)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 4 bits.
///
void
_SI32_I2C_A_set_extended_data_hold_time(SI32_I2C_A_Type* /*basePointer*/,
   uint32_t /*value*/);
///
/// @def SI32_I2C_A_set_extended_data_hold_time(basePointer, value)
#define SI32_I2C_A_set_extended_data_hold_time(basePointer, value) \
   (basePointer->SCONFIG.HOLD = value)


/// @fn _SI32_I2C_A_get_extended_data_hold_time(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2C_A_get_extended_data_hold_time(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_get_extended_data_hold_time(basePointer)
#define SI32_I2C_A_get_extended_data_hold_time(basePointer) \
(basePointer->SCONFIG.HOLD)


/// @fn _SI32_I2C_A_set_scl_low_period_reload(SI32_I2C_A_Type* basePointer,
///      uwide8_t value)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 8 bits.
///
void
_SI32_I2C_A_set_scl_low_period_reload(SI32_I2C_A_Type* /*basePointer*/,
   uwide8_t /*value*/);
///
/// @def SI32_I2C_A_set_scl_low_period_reload(basePointer, value)
#define SI32_I2C_A_set_scl_low_period_reload(basePointer, value) \
   (basePointer->SCONFIG.SCLL = value)


/// @fn _SI32_I2C_A_get_scl_low_period_reload(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_I2C_A_get_scl_low_period_reload(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_get_scl_low_period_reload(basePointer)
#define SI32_I2C_A_get_scl_low_period_reload(basePointer) \
(basePointer->SCONFIG.SCLL)


/// @fn _SI32_I2C_A_write_i2cdma(SI32_I2C_A_Type* basePointer,
///      uint32_t i2cdma)
///
/// @brief
/// Write to I2CDMA register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  i2cdma
///  Valid range is 32 bits.
///
void
_SI32_I2C_A_write_i2cdma(SI32_I2C_A_Type* /*basePointer*/,
   uint32_t /*i2cdma*/);
///
/// @def SI32_I2C_A_write_i2cdma(basePointer, i2cdma)
#define SI32_I2C_A_write_i2cdma(basePointer, i2cdma) \
   (basePointer->I2CDMA.U32 = i2cdma)


/// @fn _SI32_I2C_A_read_i2cdma(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Reads I2CDMA register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2C_A_read_i2cdma(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_read_i2cdma(basePointer)
#define SI32_I2C_A_read_i2cdma(basePointer) \
(basePointer->I2CDMA.U32)


/// @fn _SI32_I2C_A_set_dma_byte_count(SI32_I2C_A_Type* basePointer,
///      uwide8_t value)
///
/// @brief
/// Writes the number of bytes to transmit or receive.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 8 bits.
///
void
_SI32_I2C_A_set_dma_byte_count(SI32_I2C_A_Type* /*basePointer*/,
   uwide8_t /*value*/);
///
/// @def SI32_I2C_A_set_dma_byte_count(basePointer, value)
#define SI32_I2C_A_set_dma_byte_count(basePointer, value) \
   (basePointer->I2CDMA.DMALEN = value)


/// @fn _SI32_I2C_A_get_dma_byte_count(SI32_I2C_A_Type* basePointer)
///
/// @brief
/// Returns the number of bytes to transmit or receive.
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_I2C_A_get_dma_byte_count(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_get_dma_byte_count(basePointer)
#define SI32_I2C_A_get_dma_byte_count(basePointer) \
(basePointer->I2CDMA.DMALEN)


/// @fn _SI32_I2C_A_enable_dma(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_enable_dma(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_enable_dma(basePointer)
#define SI32_I2C_A_enable_dma(basePointer) \
   (basePointer->I2CDMA.DMAEN = SI32_I2C_A_I2CDMA_DMAEN_ENABLED_VALUE)


/// @fn _SI32_I2C_A_disable_dma(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2C_A_disable_dma(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_disable_dma(basePointer)
#define SI32_I2C_A_disable_dma(basePointer) \
   (basePointer->I2CDMA.DMAEN = SI32_I2C_A_I2CDMA_DMAEN_DISABLED_VALUE)


/// @fn _SI32_I2C_A_is_dma_enabled(SI32_I2C_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2C_A_is_dma_enabled(SI32_I2C_A_Type* /*basePointer*/);
///
/// @def SI32_I2C_A_is_dma_enabled(basePointer)
#define SI32_I2C_A_is_dma_enabled(basePointer) \
((bool)(basePointer->I2CDMA.DMAEN))



#ifdef __cplusplus
}
#endif

#endif // __SI32_I2C_A_TYPE_H__

//-eof--------------------------------------------------------------------------
