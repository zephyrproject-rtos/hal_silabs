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
/// @file SI32_LPTIMER_A_Type.c
//
// Script: 0.58
// HAL Source: 0.4
// Version: 5

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_LPTIMER_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_initialize
//
// Writes all LPTIMER registers.
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_initialize(
   SI32_LPTIMER_A_Type * basePointer,
   uint32_t control,
   uint32_t data,
   uint32_t status)
{
   //{{
   basePointer->CONTROL.U32 = control;
   basePointer->DATA.U32 = data;
   basePointer->STATUS.U32 = status;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_write_control
//
// Writes CONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_write_control(
   SI32_LPTIMER_A_Type * basePointer,
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_read_control
//
// Reads CONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_LPTIMER_A_read_control(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_select_free_run_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_select_free_run_mode(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_A_CONTROL_CMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_select_rising_edge_increment_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_select_rising_edge_increment_mode(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_A_CONTROL_CMD_MASK;
   basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_CMD_RISING_EDGE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_select_falling_edge_increment_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_select_falling_edge_increment_mode(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_A_CONTROL_CMD_MASK;
   basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_CMD_FALLING_EDGE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_select_both_edge_increment_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_select_both_edge_increment_mode(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_CMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_select_timer_source
//
// Selects the external trigger for the timer.
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_select_timer_source(
   SI32_LPTIMER_A_Type * basePointer,
   // External trigger source select from 0 to 15 (0 = LPTnT0, ..., 15 =
   // LPTnT15).
   uint32_t source)
{
   assert(source < 16);   // source < 2^4
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_A_CONTROL_EXTSEL_MASK;
   basePointer->CONTROL_SET = source << SI32_LPTIMER_A_CONTROL_EXTSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_start_timer_write
//
// Initiates copy from DATA register to internal timer register.
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_start_timer_write(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_TMRSET_SET_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_has_timer_write_occurred
//
// Returns whether or not the last timer write request has finished.
//-----------------------------------------------------------------------------
bool
_SI32_LPTIMER_A_has_timer_write_occurred(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   return !(bool)(basePointer->CONTROL.TMRSET);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_start_timer_read
//
// Initiates copy from internal timer register to DATA register.
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_start_timer_read(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_TMRCAP_SET_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_has_timer_read_occurred
//
// Returns whether or not the last timer read request has finished.
//-----------------------------------------------------------------------------
bool
_SI32_LPTIMER_A_has_timer_read_occurred(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   return !(bool)(basePointer->CONTROL.TMRCAP);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_start_comparator_write
//
// Initiates copy from DATA register to internal comparator register.
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_start_comparator_write(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_CMPSET_SET_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_has_comparator_write_occurred
//
// Returns whether or not the last comparator write request has finished.
//-----------------------------------------------------------------------------
bool
_SI32_LPTIMER_A_has_comparator_write_occurred(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   return !(bool)(basePointer->CONTROL.CMPSET);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_start_comparator_read
//
// Initiates copy from internal comparator register to DATA register.
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_start_comparator_read(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_CMPCAP_SET_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_has_comparator_read_occurred
//
// Returns whether or not the last comparator read request has finished.
//-----------------------------------------------------------------------------
bool
_SI32_LPTIMER_A_has_comparator_read_occurred(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   return !(bool)(basePointer->CONTROL.CMPCAP);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_enable_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_enable_overflow_interrupt(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_OVFIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_disable_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_disable_overflow_interrupt(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_A_CONTROL_OVFIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_is_overflow_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_LPTIMER_A_is_overflow_interrupt_enabled(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.OVFIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_enable_compare_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_enable_compare_interrupt(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_CMPIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_disable_compare_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_disable_compare_interrupt(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_A_CONTROL_CMPIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_is_compare_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_LPTIMER_A_is_compare_interrupt_enabled(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.CMPIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_enable_output_toggle_upon_overflow
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_enable_output_toggle_upon_overflow(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_OVFTMD_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_disable_output_toggle_upon_overflow
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_disable_output_toggle_upon_overflow(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_A_CONTROL_OVFTMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_enable_output_toggle_upon_compare
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_enable_output_toggle_upon_compare(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_CMPTMD_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_disable_output_toggle_upon_compare
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_disable_output_toggle_upon_compare(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_A_CONTROL_CMPTMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_enable_timer_reset_upon_compare
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_enable_timer_reset_upon_compare(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_CMPRSTEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_disable_timer_reset_upon_compare
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_disable_timer_reset_upon_compare(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_A_CONTROL_CMPRSTEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_enable_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_enable_stall_in_debug_mode(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_DBGMD_HALT_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_disable_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_disable_stall_in_debug_mode(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_A_CONTROL_DBGMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_start_timer
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_start_timer(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_RUN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_stop_timer
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_stop_timer(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LPTIMER_A_CONTROL_RUN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_write_data
//
// Writes DATA register.
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_write_data(
   SI32_LPTIMER_A_Type * basePointer,
   uint32_t data)
{
   //{{
   basePointer->DATA.U32 = data;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_read_data
//
// Reads DATA register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_LPTIMER_A_read_data(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   return basePointer->DATA.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_write_status
//
// Writes STATUS register.
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_write_status(
   SI32_LPTIMER_A_Type * basePointer,
   uint32_t status)
{
   //{{
   basePointer->STATUS.U32 = status;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_read_status
//
// Reads STATUS register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_LPTIMER_A_read_status(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_is_overflow_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_LPTIMER_A_is_overflow_interrupt_pending(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->STATUS.OVFI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_clear_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_clear_overflow_interrupt(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_CLR = SI32_LPTIMER_A_STATUS_OVFI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_is_compare_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_LPTIMER_A_is_compare_interrupt_pending(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->STATUS.CMPI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LPTIMER_A_clear_compare_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_LPTIMER_A_clear_compare_interrupt(
   SI32_LPTIMER_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_CLR = SI32_LPTIMER_A_STATUS_CMPI_MASK;
   //}}
}


//-eof--------------------------------------------------------------------------
