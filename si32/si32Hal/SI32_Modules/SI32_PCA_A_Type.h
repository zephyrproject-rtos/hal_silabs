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
/// @file SI32_PCA_A_Type.h
//
// Script: 0.58
// HAL Source: 0.2
// Version: 1

#ifndef __SI32_PCA_A_TYPE_H__
#define __SI32_PCA_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_PCA_A_Registers.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_PCA_A_initialize(SI32_PCA_A_Type* basePointer,
///      uint32_t mode,
///      uint32_t control,
///      uint32_t status,
///      uint32_t counter,
///      uint32_t limit)
///
/// @brief
/// Writes all PCA registers.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  mode
///  Valid range is 32 bits.
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///
/// @param[in]
///  status
///  Valid range is 32 bits.
///
/// @param[in]
///  counter
///  Valid range is 32 bits.
///
/// @param[in]
///  limit
///  Valid range is 32 bits.
///
void
_SI32_PCA_A_initialize(SI32_PCA_A_Type* /*basePointer*/,
   uint32_t, /*mode*/
   uint32_t, /*control*/
   uint32_t, /*status*/
   uint32_t, /*counter*/
   uint32_t /*limit*/);
///
/// @def SI32_PCA_A_initialize(basePointer, mode, control, status, counter, limit)
#define SI32_PCA_A_initialize(basePointer, mode, control, status, counter, limit) do{  \
   basePointer->MODE.U32 = mode;\
   basePointer->CONTROL.U32 = control;\
   basePointer->STATUS.U32 = status;\
   basePointer->COUNTER.U32 = counter;\
   basePointer->LIMIT.U32 = limit;\
} while(0)


/// @fn _SI32_PCA_A_write_mode(SI32_PCA_A_Type* basePointer,
///      uint32_t mode)
///
/// @brief
/// Writes MODE register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  mode
///  Valid range is 32 bits.
///
void
_SI32_PCA_A_write_mode(SI32_PCA_A_Type* /*basePointer*/,
   uint32_t /*mode*/);
///
/// @def SI32_PCA_A_write_mode(basePointer, mode)
#define SI32_PCA_A_write_mode(basePointer, mode) \
   (basePointer->MODE.U32 = mode)


/// @fn _SI32_PCA_A_read_mode(SI32_PCA_A_Type* basePointer)
///
/// @brief
/// Reads MODE register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PCA_A_read_mode(SI32_PCA_A_Type* /*basePointer*/);
///
/// @def SI32_PCA_A_read_mode(basePointer)
#define SI32_PCA_A_read_mode(basePointer) \
(basePointer->MODE.U32)


/// @fn _SI32_PCA_A_select_input_clock_divisor(SI32_PCA_A_Type* basePointer,
///      uint32_t divisor)
///
/// @brief
/// Selects the divisor for the input clock.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  divisor
///  Valid range is 1 to 1024.
///  PCA clock frequency is given by (input clock frequency) / (divisor +
///  1).
///
void
_SI32_PCA_A_select_input_clock_divisor(SI32_PCA_A_Type* /*basePointer*/,
   uint32_t /*divisor*/);
///
/// @def SI32_PCA_A_select_input_clock_divisor(basePointer, divisor)
#define SI32_PCA_A_select_input_clock_divisor(basePointer, divisor) \
   (basePointer->MODE.CLKDIV = divisor)


/// @fn _SI32_PCA_A_select_input_clock_apb(SI32_PCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PCA_A_select_input_clock_apb(SI32_PCA_A_Type* /*basePointer*/);
///
/// @def SI32_PCA_A_select_input_clock_apb(basePointer)
#define SI32_PCA_A_select_input_clock_apb(basePointer) \
   (basePointer->MODE.CLKSEL = SI32_PCA_A_MODE_CLKSEL_APB_VALUE)


/// @fn _SI32_PCA_A_select_input_clock_timer0_overflow(SI32_PCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PCA_A_select_input_clock_timer0_overflow(SI32_PCA_A_Type* /*basePointer*/);
///
/// @def SI32_PCA_A_select_input_clock_timer0_overflow(basePointer)
#define SI32_PCA_A_select_input_clock_timer0_overflow(basePointer) \
   (basePointer->MODE.CLKSEL = SI32_PCA_A_MODE_CLKSEL_TIMER0_VALUE)


/// @fn _SI32_PCA_A_select_input_clock_eci_high_to_low(SI32_PCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PCA_A_select_input_clock_eci_high_to_low(SI32_PCA_A_Type* /*basePointer*/);
///
/// @def SI32_PCA_A_select_input_clock_eci_high_to_low(basePointer)
#define SI32_PCA_A_select_input_clock_eci_high_to_low(basePointer) \
   (basePointer->MODE.CLKSEL = SI32_PCA_A_MODE_CLKSEL_HL_ECI_VALUE)


/// @fn _SI32_PCA_A_select_input_clock_external_oscillator(SI32_PCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PCA_A_select_input_clock_external_oscillator(SI32_PCA_A_Type* /*basePointer*/);
///
/// @def SI32_PCA_A_select_input_clock_external_oscillator(basePointer)
#define SI32_PCA_A_select_input_clock_external_oscillator(basePointer) \
   (basePointer->MODE.CLKSEL = SI32_PCA_A_MODE_CLKSEL_EXTOSCN_VALUE)


/// @fn _SI32_PCA_A_select_input_clock_eci(SI32_PCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PCA_A_select_input_clock_eci(SI32_PCA_A_Type* /*basePointer*/);
///
/// @def SI32_PCA_A_select_input_clock_eci(basePointer)
#define SI32_PCA_A_select_input_clock_eci(basePointer) \
   (basePointer->MODE.CLKSEL = SI32_PCA_A_MODE_CLKSEL_ECI_VALUE)


/// @fn _SI32_PCA_A_write_control(SI32_PCA_A_Type* basePointer,
///      uint32_t control)
///
/// @brief
/// Writes CONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///
void
_SI32_PCA_A_write_control(SI32_PCA_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_PCA_A_write_control(basePointer, control)
#define SI32_PCA_A_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_PCA_A_read_control(SI32_PCA_A_Type* basePointer)
///
/// @brief
/// Reads CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PCA_A_read_control(SI32_PCA_A_Type* /*basePointer*/);
///
/// @def SI32_PCA_A_read_control(basePointer)
#define SI32_PCA_A_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_PCA_A_enable_counter_overflow_interrupt(SI32_PCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PCA_A_enable_counter_overflow_interrupt(SI32_PCA_A_Type* /*basePointer*/);
///
/// @def SI32_PCA_A_enable_counter_overflow_interrupt(basePointer)
#define SI32_PCA_A_enable_counter_overflow_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_PCA_A_CONTROL_OVFIEN_MASK)


/// @fn _SI32_PCA_A_disable_counter_overflow_interrupt(SI32_PCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PCA_A_disable_counter_overflow_interrupt(SI32_PCA_A_Type* /*basePointer*/);
///
/// @def SI32_PCA_A_disable_counter_overflow_interrupt(basePointer)
#define SI32_PCA_A_disable_counter_overflow_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_PCA_A_CONTROL_OVFIEN_MASK)


/// @fn _SI32_PCA_A_is_counter_overflow_interrupt_enabled(SI32_PCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_PCA_A_is_counter_overflow_interrupt_enabled(SI32_PCA_A_Type* /*basePointer*/);
///
/// @def SI32_PCA_A_is_counter_overflow_interrupt_enabled(basePointer)
#define SI32_PCA_A_is_counter_overflow_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.OVFIEN))


/// @fn _SI32_PCA_A_enable_stall_in_debug_mode(SI32_PCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PCA_A_enable_stall_in_debug_mode(SI32_PCA_A_Type* /*basePointer*/);
///
/// @def SI32_PCA_A_enable_stall_in_debug_mode(basePointer)
#define SI32_PCA_A_enable_stall_in_debug_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_PCA_A_CONTROL_DBGMD_MASK)


/// @fn _SI32_PCA_A_disable_stall_in_debug_mode(SI32_PCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PCA_A_disable_stall_in_debug_mode(SI32_PCA_A_Type* /*basePointer*/);
///
/// @def SI32_PCA_A_disable_stall_in_debug_mode(basePointer)
#define SI32_PCA_A_disable_stall_in_debug_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_PCA_A_CONTROL_DBGMD_MASK)


/// @fn _SI32_PCA_A_is_clock_divider_in_phase_2(SI32_PCA_A_Type* basePointer)
///
/// @return
///  Returns TRUE if clock divider is in second count-down phase, FALSE if
///  clock divider is in first count-down phase.
///
/// @param[in]
///  basePointer
///
bool
_SI32_PCA_A_is_clock_divider_in_phase_2(SI32_PCA_A_Type* /*basePointer*/);
///
/// @def SI32_PCA_A_is_clock_divider_in_phase_2(basePointer)
#define SI32_PCA_A_is_clock_divider_in_phase_2(basePointer) \
((bool)(basePointer->CONTROL.DIVST))


/// @fn _SI32_PCA_A_select_clock_divider_state_phase_1(SI32_PCA_A_Type* basePointer)
///
/// @brief
/// Sets the clock divider to first count-down phase.
///
/// @param[in]
///  basePointer
///
void
_SI32_PCA_A_select_clock_divider_state_phase_1(SI32_PCA_A_Type* /*basePointer*/);
///
/// @def SI32_PCA_A_select_clock_divider_state_phase_1(basePointer)
#define SI32_PCA_A_select_clock_divider_state_phase_1(basePointer) \
   (basePointer->CONTROL_CLR = SI32_PCA_A_CONTROL_DIVST_MASK)


/// @fn _SI32_PCA_A_select_clock_divider_state_phase_2(SI32_PCA_A_Type* basePointer)
///
/// @brief
/// Sets the clock divider to second count-down phase.
///
/// @param[in]
///  basePointer
///
void
_SI32_PCA_A_select_clock_divider_state_phase_2(SI32_PCA_A_Type* /*basePointer*/);
///
/// @def SI32_PCA_A_select_clock_divider_state_phase_2(basePointer)
#define SI32_PCA_A_select_clock_divider_state_phase_2(basePointer) \
   (basePointer->CONTROL_SET = SI32_PCA_A_CONTROL_DIVST_MASK)


/// @fn _SI32_PCA_A_get_clock_divider(SI32_PCA_A_Type* basePointer)
///
/// @brief
/// Gets PCA clock divider.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PCA_A_get_clock_divider(SI32_PCA_A_Type* /*basePointer*/);
///
/// @def SI32_PCA_A_get_clock_divider(basePointer)
#define SI32_PCA_A_get_clock_divider(basePointer) \
(basePointer->CONTROL.DIV)


/// @fn _SI32_PCA_A_set_clock_divider(SI32_PCA_A_Type* basePointer,
///      uint32_t divider)
///
/// @brief
/// Sets PCA clock divider.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  divider
///  Valid range is 10 bits.
///
void
_SI32_PCA_A_set_clock_divider(SI32_PCA_A_Type* /*basePointer*/,
   uint32_t /*divider*/);
///
/// @def SI32_PCA_A_set_clock_divider(basePointer, divider)
#define SI32_PCA_A_set_clock_divider(basePointer, divider) \
   (basePointer->CONTROL.DIV = divider)


/// @fn _SI32_PCA_A_write_status(SI32_PCA_A_Type* basePointer,
///      uint32_t status)
///
/// @brief
/// Writes STATUS register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  status
///  Valid range is 32 bits.
///
void
_SI32_PCA_A_write_status(SI32_PCA_A_Type* /*basePointer*/,
   uint32_t /*status*/);
///
/// @def SI32_PCA_A_write_status(basePointer, status)
#define SI32_PCA_A_write_status(basePointer, status) \
   (basePointer->STATUS.U32 = status)


/// @fn _SI32_PCA_A_read_status(SI32_PCA_A_Type* basePointer)
///
/// @brief
/// Reads STATUS register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PCA_A_read_status(SI32_PCA_A_Type* /*basePointer*/);
///
/// @def SI32_PCA_A_read_status(basePointer)
#define SI32_PCA_A_read_status(basePointer) \
(basePointer->STATUS.U32)


/// @fn _SI32_PCA_A_is_channel_n_capture_compare_interrupt_pending(SI32_PCA_A_Type* basePointer,
///      uint32_t channel)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel
///  Valid range is 0 to 1.
///  Channel number (0-1).
///
bool
_SI32_PCA_A_is_channel_n_capture_compare_interrupt_pending(SI32_PCA_A_Type* /*basePointer*/,
   uint32_t /*channel*/);
///
/// @def SI32_PCA_A_is_channel_n_capture_compare_interrupt_pending(basePointer, channel)
#define SI32_PCA_A_is_channel_n_capture_compare_interrupt_pending(basePointer, channel) \
   _SI32_PCA_A_is_channel_n_capture_compare_interrupt_pending(basePointer, channel) 


/// @fn _SI32_PCA_A_set_channel_n_capture_compare_interrupt(SI32_PCA_A_Type* basePointer,
///      uint32_t channel)
///
/// @brief
/// Forces channel n capture/compare interrupt.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel
///  Valid range is 0 to 1.
///  Channel number (0-1).
///
void
_SI32_PCA_A_set_channel_n_capture_compare_interrupt(SI32_PCA_A_Type* /*basePointer*/,
   uint32_t /*channel*/);
///
/// @def SI32_PCA_A_set_channel_n_capture_compare_interrupt(basePointer, channel)
#define SI32_PCA_A_set_channel_n_capture_compare_interrupt(basePointer, channel) \
   _SI32_PCA_A_set_channel_n_capture_compare_interrupt(basePointer, channel) 


/// @fn _SI32_PCA_A_clear_channel_n_capture_compare_interrupt(SI32_PCA_A_Type* basePointer,
///      uint32_t channel)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel
///  Valid range is 0 to 1.
///  Channel number (0-1).
///
void
_SI32_PCA_A_clear_channel_n_capture_compare_interrupt(SI32_PCA_A_Type* /*basePointer*/,
   uint32_t /*channel*/);
///
/// @def SI32_PCA_A_clear_channel_n_capture_compare_interrupt(basePointer, channel)
#define SI32_PCA_A_clear_channel_n_capture_compare_interrupt(basePointer, channel) \
   _SI32_PCA_A_clear_channel_n_capture_compare_interrupt(basePointer, channel) 


/// @fn _SI32_PCA_A_start_counter_timer(SI32_PCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PCA_A_start_counter_timer(SI32_PCA_A_Type* /*basePointer*/);
///
/// @def SI32_PCA_A_start_counter_timer(basePointer)
#define SI32_PCA_A_start_counter_timer(basePointer) \
   (basePointer->STATUS_SET = SI32_PCA_A_STATUS_RUN_MASK)


/// @fn _SI32_PCA_A_stop_counter_timer(SI32_PCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PCA_A_stop_counter_timer(SI32_PCA_A_Type* /*basePointer*/);
///
/// @def SI32_PCA_A_stop_counter_timer(basePointer)
#define SI32_PCA_A_stop_counter_timer(basePointer) \
   (basePointer->STATUS_CLR = SI32_PCA_A_STATUS_RUN_MASK)


/// @fn _SI32_PCA_A_is_counter_timer_overflow_interrupt_pending(SI32_PCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_PCA_A_is_counter_timer_overflow_interrupt_pending(SI32_PCA_A_Type* /*basePointer*/);
///
/// @def SI32_PCA_A_is_counter_timer_overflow_interrupt_pending(basePointer)
#define SI32_PCA_A_is_counter_timer_overflow_interrupt_pending(basePointer) \
((bool)(basePointer->STATUS.OVFI))


/// @fn _SI32_PCA_A_set_counter_timer_overflow_interrupt(SI32_PCA_A_Type* basePointer)
///
/// @brief
/// Forces PCA counter/timer overflow interrupt.
///
/// @param[in]
///  basePointer
///
void
_SI32_PCA_A_set_counter_timer_overflow_interrupt(SI32_PCA_A_Type* /*basePointer*/);
///
/// @def SI32_PCA_A_set_counter_timer_overflow_interrupt(basePointer)
#define SI32_PCA_A_set_counter_timer_overflow_interrupt(basePointer) \
   (basePointer->STATUS_SET = SI32_PCA_A_STATUS_OVFI_MASK)


/// @fn _SI32_PCA_A_clear_counter_timer_overflow_interrupt(SI32_PCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PCA_A_clear_counter_timer_overflow_interrupt(SI32_PCA_A_Type* /*basePointer*/);
///
/// @def SI32_PCA_A_clear_counter_timer_overflow_interrupt(basePointer)
#define SI32_PCA_A_clear_counter_timer_overflow_interrupt(basePointer) \
   (basePointer->STATUS_CLR = SI32_PCA_A_STATUS_OVFI_MASK)


/// @fn _SI32_PCA_A_is_channel_n_intermediate_overflow_interrupt_pending(SI32_PCA_A_Type* basePointer,
///      uint32_t channel)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel
///  Valid range is 0 to 1.
///  Channel number (0-1).
///
bool
_SI32_PCA_A_is_channel_n_intermediate_overflow_interrupt_pending(SI32_PCA_A_Type* /*basePointer*/,
   uint32_t /*channel*/);
///
/// @def SI32_PCA_A_is_channel_n_intermediate_overflow_interrupt_pending(basePointer, channel)
#define SI32_PCA_A_is_channel_n_intermediate_overflow_interrupt_pending(basePointer, channel) \
   _SI32_PCA_A_is_channel_n_intermediate_overflow_interrupt_pending(basePointer, channel) 


/// @fn _SI32_PCA_A_set_channel_n_intermediate_overflow_interrupt(SI32_PCA_A_Type* basePointer,
///      uint32_t channel)
///
/// @brief
/// Forces channel n intermediate overflow interrupt.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel
///  Valid range is 0 to 1.
///  Channel number (0-1).
///
void
_SI32_PCA_A_set_channel_n_intermediate_overflow_interrupt(SI32_PCA_A_Type* /*basePointer*/,
   uint32_t /*channel*/);
///
/// @def SI32_PCA_A_set_channel_n_intermediate_overflow_interrupt(basePointer, channel)
#define SI32_PCA_A_set_channel_n_intermediate_overflow_interrupt(basePointer, channel) \
   _SI32_PCA_A_set_channel_n_intermediate_overflow_interrupt(basePointer, channel) 


/// @fn _SI32_PCA_A_clear_channel_n_intermediate_overflow_interrupt(SI32_PCA_A_Type* basePointer,
///      uint32_t channel)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel
///  Valid range is 0 to 1.
///  Channel number (0-1).
///
void
_SI32_PCA_A_clear_channel_n_intermediate_overflow_interrupt(SI32_PCA_A_Type* /*basePointer*/,
   uint32_t /*channel*/);
///
/// @def SI32_PCA_A_clear_channel_n_intermediate_overflow_interrupt(basePointer, channel)
#define SI32_PCA_A_clear_channel_n_intermediate_overflow_interrupt(basePointer, channel) \
   _SI32_PCA_A_clear_channel_n_intermediate_overflow_interrupt(basePointer, channel) 


/// @fn _SI32_PCA_A_write_counter(SI32_PCA_A_Type* basePointer,
///      uint32_t counter)
///
/// @brief
/// Writes COUNTER register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  counter
///  Valid range is 32 bits.
///
void
_SI32_PCA_A_write_counter(SI32_PCA_A_Type* /*basePointer*/,
   uint32_t /*counter*/);
///
/// @def SI32_PCA_A_write_counter(basePointer, counter)
#define SI32_PCA_A_write_counter(basePointer, counter) \
   (basePointer->COUNTER.U32 = counter)


/// @fn _SI32_PCA_A_read_counter(SI32_PCA_A_Type* basePointer)
///
/// @brief
/// Reads COUNTER register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PCA_A_read_counter(SI32_PCA_A_Type* /*basePointer*/);
///
/// @def SI32_PCA_A_read_counter(basePointer)
#define SI32_PCA_A_read_counter(basePointer) \
((uint32_t)(basePointer->COUNTER.U32))


/// @fn _SI32_PCA_A_write_limit(SI32_PCA_A_Type* basePointer,
///      uint32_t limit)
///
/// @brief
/// Writes LIMIT register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  limit
///  Valid range is 32 bits.
///
void
_SI32_PCA_A_write_limit(SI32_PCA_A_Type* /*basePointer*/,
   uint32_t /*limit*/);
///
/// @def SI32_PCA_A_write_limit(basePointer, limit)
#define SI32_PCA_A_write_limit(basePointer, limit) \
   (basePointer->LIMIT.U32 = limit)


/// @fn _SI32_PCA_A_read_limit(SI32_PCA_A_Type* basePointer)
///
/// @brief
/// Reads LIMIT register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PCA_A_read_limit(SI32_PCA_A_Type* /*basePointer*/);
///
/// @def SI32_PCA_A_read_limit(basePointer)
#define SI32_PCA_A_read_limit(basePointer) \
((uint32_t)(basePointer->LIMIT.U32))



#ifdef __cplusplus
}
#endif

#endif // __SI32_PCA_A_TYPE_H__

//-eof--------------------------------------------------------------------------
