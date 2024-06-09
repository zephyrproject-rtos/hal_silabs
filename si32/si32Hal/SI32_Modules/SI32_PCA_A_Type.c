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
/// @file SI32_PCA_A_Type.c
//
// Script: 0.58
// HAL Source: 0.2
// Version: 5

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_PCA_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_PCA_A_initialize
//
// Writes all PCA registers.
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_initialize(
   SI32_PCA_A_Type * basePointer,
   uint32_t mode,
   uint32_t control,
   uint32_t status,
   uint32_t counter,
   uint32_t limit)
{
   //{{
   basePointer->MODE.U32 = mode;
   basePointer->CONTROL.U32 = control;
   basePointer->STATUS.U32 = status;
   basePointer->COUNTER.U32 = counter;
   basePointer->LIMIT.U32 = limit;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_write_mode
//
// Writes MODE register.
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_write_mode(
   SI32_PCA_A_Type * basePointer,
   uint32_t mode)
{
   //{{
   basePointer->MODE.U32 = mode;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_read_mode
//
// Reads MODE register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PCA_A_read_mode(
   SI32_PCA_A_Type * basePointer)
{
   //{{
   return basePointer->MODE.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_select_input_clock_divisor
//
// Selects the divisor for the input clock.
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_select_input_clock_divisor(
   SI32_PCA_A_Type * basePointer,
   // PCA clock frequency is given by (input clock frequency) / (divisor +
   // 1).
   uint32_t divisor)
{
   assert(divisor < 1024);   // divisor < 2^10
   //{{
   basePointer->MODE.CLKDIV = divisor;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_select_input_clock_apb
//
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_select_input_clock_apb(
   SI32_PCA_A_Type * basePointer)
{
   //{{
   basePointer->MODE.CLKSEL = SI32_PCA_A_MODE_CLKSEL_APB_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_select_input_clock_timer0_overflow
//
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_select_input_clock_timer0_overflow(
   SI32_PCA_A_Type * basePointer)
{
   //{{
   basePointer->MODE.CLKSEL = SI32_PCA_A_MODE_CLKSEL_TIMER0_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_select_input_clock_eci_high_to_low
//
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_select_input_clock_eci_high_to_low(
   SI32_PCA_A_Type * basePointer)
{
   //{{
   basePointer->MODE.CLKSEL = SI32_PCA_A_MODE_CLKSEL_HL_ECI_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_select_input_clock_external_oscillator
//
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_select_input_clock_external_oscillator(
   SI32_PCA_A_Type * basePointer)
{
   //{{
   basePointer->MODE.CLKSEL = SI32_PCA_A_MODE_CLKSEL_EXTOSCN_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_select_input_clock_eci
//
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_select_input_clock_eci(
   SI32_PCA_A_Type * basePointer)
{
   //{{
   basePointer->MODE.CLKSEL = SI32_PCA_A_MODE_CLKSEL_ECI_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_write_control
//
// Writes CONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_write_control(
   SI32_PCA_A_Type * basePointer,
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_read_control
//
// Reads CONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PCA_A_read_control(
   SI32_PCA_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_enable_counter_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_enable_counter_overflow_interrupt(
   SI32_PCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_PCA_A_CONTROL_OVFIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_disable_counter_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_disable_counter_overflow_interrupt(
   SI32_PCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PCA_A_CONTROL_OVFIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_is_counter_overflow_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_PCA_A_is_counter_overflow_interrupt_enabled(
   SI32_PCA_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.OVFIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_enable_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_enable_stall_in_debug_mode(
   SI32_PCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PCA_A_CONTROL_DBGMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_disable_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_disable_stall_in_debug_mode(
   SI32_PCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_PCA_A_CONTROL_DBGMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_is_clock_divider_in_phase_2
//
//-----------------------------------------------------------------------------
bool
_SI32_PCA_A_is_clock_divider_in_phase_2(
   SI32_PCA_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.DIVST);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_select_clock_divider_state_phase_1
//
// Sets the clock divider to first count-down phase.
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_select_clock_divider_state_phase_1(
   SI32_PCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PCA_A_CONTROL_DIVST_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_select_clock_divider_state_phase_2
//
// Sets the clock divider to second count-down phase.
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_select_clock_divider_state_phase_2(
   SI32_PCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_PCA_A_CONTROL_DIVST_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_get_clock_divider
//
// Gets PCA clock divider.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PCA_A_get_clock_divider(
   SI32_PCA_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.DIV;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_set_clock_divider
//
// Sets PCA clock divider.
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_set_clock_divider(
   SI32_PCA_A_Type * basePointer,
   uint32_t divider)
{
   assert(divider < 1024);   // divider < 2^10
   //{{
   basePointer->CONTROL.DIV = divider;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_write_status
//
// Writes STATUS register.
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_write_status(
   SI32_PCA_A_Type * basePointer,
   uint32_t status)
{
   //{{
   basePointer->STATUS.U32 = status;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_read_status
//
// Reads STATUS register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PCA_A_read_status(
   SI32_PCA_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_is_channel_n_capture_compare_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_PCA_A_is_channel_n_capture_compare_interrupt_pending(
   SI32_PCA_A_Type * basePointer,
   // Channel number (0-1).
   uint32_t channel)
{
   assert((channel >= 0) && (channel <= 1));
   //{{
   if (channel == 0)
   {
      return (bool)(basePointer->STATUS.C0CCI);
   }
   else if (channel == 1)
   {
      return (bool)(basePointer->STATUS.C1CCI);
   }
   else
   {
      return false;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_set_channel_n_capture_compare_interrupt
//
// Forces channel n capture/compare interrupt.
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_set_channel_n_capture_compare_interrupt(
   SI32_PCA_A_Type * basePointer,
   // Channel number (0-1).
   uint32_t channel)
{
   assert((channel >= 0) && (channel <= 1));
   //{{
   if (channel == 0)
   {
      basePointer->STATUS_SET = SI32_PCA_A_STATUS_C0CCI_MASK;
   }
   else if (channel == 1)
   {
      basePointer->STATUS_SET = SI32_PCA_A_STATUS_C1CCI_MASK;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_clear_channel_n_capture_compare_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_clear_channel_n_capture_compare_interrupt(
   SI32_PCA_A_Type * basePointer,
   // Channel number (0-1).
   uint32_t channel)
{
   assert((channel >= 0) && (channel <= 1));
   //{{
   if (channel == 0)
   {
      basePointer->STATUS_CLR = SI32_PCA_A_STATUS_C0CCI_MASK;
   }
   else if (channel == 1)
   {
      basePointer->STATUS_CLR = SI32_PCA_A_STATUS_C1CCI_MASK;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_start_counter_timer
//
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_start_counter_timer(
   SI32_PCA_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_SET = SI32_PCA_A_STATUS_RUN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_stop_counter_timer
//
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_stop_counter_timer(
   SI32_PCA_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_CLR = SI32_PCA_A_STATUS_RUN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_is_counter_timer_overflow_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_PCA_A_is_counter_timer_overflow_interrupt_pending(
   SI32_PCA_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->STATUS.OVFI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_set_counter_timer_overflow_interrupt
//
// Forces PCA counter/timer overflow interrupt.
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_set_counter_timer_overflow_interrupt(
   SI32_PCA_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_SET = SI32_PCA_A_STATUS_OVFI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_clear_counter_timer_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_clear_counter_timer_overflow_interrupt(
   SI32_PCA_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_CLR = SI32_PCA_A_STATUS_OVFI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_is_channel_n_intermediate_overflow_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_PCA_A_is_channel_n_intermediate_overflow_interrupt_pending(
   SI32_PCA_A_Type * basePointer,
   // Channel number (0-1).
   uint32_t channel)
{
   assert((channel >= 0) && (channel <= 1));
   //{{
   if (channel == 0)
   {
      return (bool)(basePointer->STATUS.C0IOVFI);
   }
   else if (channel == 1)
   {
      return (bool)(basePointer->STATUS.C1IOVFI);
   }
   else
   {
      return false;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_set_channel_n_intermediate_overflow_interrupt
//
// Forces channel n intermediate overflow interrupt.
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_set_channel_n_intermediate_overflow_interrupt(
   SI32_PCA_A_Type * basePointer,
   // Channel number (0-1).
   uint32_t channel)
{
   assert((channel >= 0) && (channel <= 1));
   //{{
   if (channel == 0)
   {
      basePointer->STATUS_SET = SI32_PCA_A_STATUS_C0IOVFI_MASK;
   }
   else if (channel == 1)
   {
      basePointer->STATUS_SET = SI32_PCA_A_STATUS_C1IOVFI_MASK;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_clear_channel_n_intermediate_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_clear_channel_n_intermediate_overflow_interrupt(
   SI32_PCA_A_Type * basePointer,
   // Channel number (0-1).
   uint32_t channel)
{
   assert((channel >= 0) && (channel <= 1));
   //{{
   if (channel == 0)
   {
      basePointer->STATUS_CLR = SI32_PCA_A_STATUS_C0IOVFI_MASK;
   }
   else if (channel == 1)
   {
      basePointer->STATUS_CLR = SI32_PCA_A_STATUS_C1IOVFI_MASK;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_write_counter
//
// Writes COUNTER register.
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_write_counter(
   SI32_PCA_A_Type * basePointer,
   uint32_t counter)
{
   //{{
   basePointer->COUNTER.U32 = counter;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_read_counter
//
// Reads COUNTER register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PCA_A_read_counter(
   SI32_PCA_A_Type * basePointer)
{
   //{{
   return (uint32_t)(basePointer->COUNTER.U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_write_limit
//
// Writes LIMIT register.
//-----------------------------------------------------------------------------
void
_SI32_PCA_A_write_limit(
   SI32_PCA_A_Type * basePointer,
   uint32_t limit)
{
   //{{
   basePointer->LIMIT.U32 = limit;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PCA_A_read_limit
//
// Reads LIMIT register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PCA_A_read_limit(
   SI32_PCA_A_Type * basePointer)
{
   //{{
   return (uint32_t)(basePointer->LIMIT.U32);
   //}}
}


//-eof--------------------------------------------------------------------------
