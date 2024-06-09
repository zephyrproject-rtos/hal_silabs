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
/// @file SI32_LPTIMER_B_Type.c
//
// Script: 0.59
// HAL Source: 0.1
// Version: 1

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_LPTIMER_B_Type.h"


//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_initialize
//
// Writes all LPTIMER registers.
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_initialize(
   SI32_LPTIMER_B_Type * basePointer,
   uint32_t control,
   uint32_t count,
   uint32_t threshold,
   uint32_t status)
{
   //{{
   basePointer->CONTROL.U32 = control;
   basePointer->COUNT.U32 = count;
   basePointer->THRESHOLD.U32 = threshold;
   basePointer->STATUS.U32 = status;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_write_control
//
// Writes CONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_write_control(
   SI32_LPTIMER_B_Type * basePointer,
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_read_control
//
// Reads CONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_LPTIMER_B_read_control(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_select_free_run_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_select_free_run_mode(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_CMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_select_rising_edge_increment_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_select_rising_edge_increment_mode(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_CMD_MASK;
   basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_CMD_RISING_EDGE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_select_falling_edge_increment_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_select_falling_edge_increment_mode(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_CMD_MASK;
   basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_CMD_FALLING_EDGE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_select_both_edge_increment_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_select_both_edge_increment_mode(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_CMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_select_timer_source
//
// Selects the external trigger for the timer.
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_select_timer_source(
   SI32_LPTIMER_B_Type * basePointer,
   // External trigger source select from 0 to 15 (0 = LPTnT0, ..., 15 =
   // LPTnT15).
   uint32_t source)
{
   assert(source < 16);   // source < 2^4
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_EXTSEL_MASK;
   basePointer->CONTROL_SET = source << SI32_LPTIMER_B_CONTROL_EXTSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_start_timer_write
//
// Initiates copy from DATA register to internal timer register.
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_start_timer_write(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_TMRSET_SET_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_has_timer_write_occurred
//
// Returns whether or not the last timer write request has finished.
//-----------------------------------------------------------------------------
bool
_SI32_LPTIMER_B_has_timer_write_occurred(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   return !(bool)(basePointer->CONTROL.TMRSET);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_start_timer_read
//
// Initiates copy from internal timer register to DATA register.
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_start_timer_read(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_TMRCAP_SET_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_has_timer_read_occurred
//
// Returns whether or not the last timer read request has finished.
//-----------------------------------------------------------------------------
bool
_SI32_LPTIMER_B_has_timer_read_occurred(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   return !(bool)(basePointer->CONTROL.TMRCAP);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_enter_high_speed_timer_access_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_enter_high_speed_timer_access_mode(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_HSMDEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_exit_high_speed_timer_access_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_exit_high_speed_timer_access_mode(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_HSMDEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_enable_compare0_threshold
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_enable_compare0_threshold(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_CMP0EN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_disable_compare0_threshold
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_disable_compare0_threshold(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_CMP0EN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_enable_compare1_threshold
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_enable_compare1_threshold(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_CMP1EN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_disable_compare1_threshold
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_disable_compare1_threshold(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_CMP1EN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_enable_output
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_enable_output(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_OUTEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_disable_output
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_disable_output(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_OUTEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_enable_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_enable_overflow_interrupt(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_OVFIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_disable_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_disable_overflow_interrupt(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_OVFIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_is_overflow_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_LPTIMER_B_is_overflow_interrupt_enabled(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.OVFIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_enable_compare0_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_enable_compare0_interrupt(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_CMP0IEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_disable_compare0_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_disable_compare0_interrupt(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_CMP0IEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_is_compare0_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_LPTIMER_B_is_compare0_interrupt_enabled(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.CMP0IEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_enable_overflow_set_output
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_enable_overflow_set_output(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_OVFOEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_disable_overflow_set_output
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_disable_overflow_set_output(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_OVFOEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_enable_compare0_event_to_clear_output
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_enable_compare0_event_to_clear_output(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_CMP0OEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_disable_compare0_event_to_clear_output
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_disable_compare0_event_to_clear_output(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_CMP0OEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_enable_compare1_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_enable_compare1_interrupt(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_CMP1IEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_disable_compare1_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_disable_compare1_interrupt(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_CMP1IEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_is_compare1_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_LPTIMER_B_is_compare1_interrupt_enabled(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.CMP1IEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_enable_compare1_event_to_set_output
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_enable_compare1_event_to_set_output(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_CMP1OEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_disable_compare1_event_to_set_output
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_disable_compare1_event_to_set_output(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_CMP1OEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_enable_output_inversion
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_enable_output_inversion(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_OUTINVEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_disable_output_inversion
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_disable_output_inversion(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_OUTINVEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_enable_timer_reset_upon_compare0
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_enable_timer_reset_upon_compare0(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_CMP0RSTEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_disable_timer_reset_upon_compare0
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_disable_timer_reset_upon_compare0(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_CMP0RSTEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_enable_timer_reset_upon_compare1
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_enable_timer_reset_upon_compare1(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_CMP1RSTEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_disable_timer_reset_upon_compare1
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_disable_timer_reset_upon_compare1(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_CMP1RSTEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_enable_module_clock
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_enable_module_clock(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_MCLKEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_disable_module_clock
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_disable_module_clock(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_MCLKEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_enable_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_enable_stall_in_debug_mode(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_DBGMD_HALT_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_disable_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_disable_stall_in_debug_mode(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_DBGMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_start_timer
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_start_timer(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_RUN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_stop_timer
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_stop_timer(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_RUN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_write_count
//
// Writes COUNT register.
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_write_count(
   SI32_LPTIMER_B_Type * basePointer,
   uint32_t count)
{
   //{{
   basePointer->COUNT.U32 = count;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_read_count
//
// Reads COUNT register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_LPTIMER_B_read_count(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   return basePointer->COUNT.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_write_timer_value
//
// Writes the Timer Value field.
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_write_timer_value(
   SI32_LPTIMER_B_Type * basePointer,
   uint32_t value)
{
   assert(value < 65536);   // value < 2^16
   //{{
   basePointer->COUNT.TIMER = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_read_timer_value
//
// Reads the Timer Value field.
//-----------------------------------------------------------------------------
uint32_t
_SI32_LPTIMER_B_read_timer_value(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   return basePointer->COUNT.TIMER;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_write_threshold
//
// Writes THRESHOLD register.
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_write_threshold(
   SI32_LPTIMER_B_Type * basePointer,
   uint32_t threshold)
{
   //{{
   basePointer->THRESHOLD.U32 = threshold;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_read_threshold
//
// Reads THRESHOLD register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_LPTIMER_B_read_threshold(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   return basePointer->THRESHOLD.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_write_compare0
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_write_compare0(
   SI32_LPTIMER_B_Type * basePointer,
   uint32_t compare0)
{
   assert(compare0 < 65536);   // compare0 < 2^16
   //{{
   basePointer->THRESHOLD.COMPARE0 = compare0;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_read_compare0
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_LPTIMER_B_read_compare0(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   return basePointer->THRESHOLD.COMPARE0;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_write_compare1
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_write_compare1(
   SI32_LPTIMER_B_Type * basePointer,
   uint32_t compare1)
{
   assert(compare1 < 65536);   // compare1 < 2^16
   //{{
   basePointer->THRESHOLD.COMPARE1 = compare1;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_read_compare1
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_LPTIMER_B_read_compare1(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   return basePointer->THRESHOLD.COMPARE1;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_write_status
//
// Writes STATUS register.
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_write_status(
   SI32_LPTIMER_B_Type * basePointer,
   uint32_t status)
{
   //{{
   basePointer->STATUS.U32 = status;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_read_status
//
// Reads STATUS register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_LPTIMER_B_read_status(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   return basePointer->STATUS.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_is_overflow_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_LPTIMER_B_is_overflow_interrupt_pending(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   return (bool)(basePointer->STATUS.OVFI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_clear_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_clear_overflow_interrupt(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->STATUS_CLR = SI32_LPTIMER_B_STATUS_OVFI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_is_compare0_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_LPTIMER_B_is_compare0_interrupt_pending(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   return (bool)(basePointer->STATUS.CMP0I);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_clear_compare0_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_clear_compare0_interrupt(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->STATUS_CLR = SI32_LPTIMER_B_STATUS_CMP0I_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_is_compare1_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_LPTIMER_B_is_compare1_interrupt_pending(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   //{{
   return (bool)(basePointer->STATUS.CMP1I);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_B_clear_compare1_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_B_clear_compare1_interrupt(
   SI32_LPTIMER_B_Type * basePointer)
{
   //{{
   basePointer->STATUS_CLR = SI32_LPTIMER_B_STATUS_CMP1I_MASK;
   //}}
}


//-eof--------------------------------------------------------------------------
