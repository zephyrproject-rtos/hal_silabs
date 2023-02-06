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
/// @file SI32_EPCA_A_Type.c
//
// Script: 0.58
// HAL Source: 1.0
// Version: 6

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_EPCA_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_EPCA_A_initialize
//
// Writes all EPCA registers.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_initialize(
   SI32_EPCA_A_Type * basePointer,
   // The specified DPTR field is incremented after the function completes.
   uint32_t mode,
   uint32_t control,
   uint32_t status,
   uint32_t counter,
   uint32_t limit,
   uint32_t limitupd,
   uint32_t dtime,
   // Writes based on the specified DPTR field in the mode parameter.
   uint32_t dtarget)
{
   //{{
   basePointer->MODE.U32 = mode;
   basePointer->CONTROL.U32 = control;
   basePointer->STATUS.U32 = status;
   basePointer->COUNTER.U32 = counter;
   basePointer->LIMIT.U32 = limit;
   basePointer->LIMITUPD.U32 = limitupd;
   basePointer->DTIME.U32 = dtime;
   basePointer->DTARGET.U32 = dtarget;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_write_mode
//
// Writes MODE register.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_write_mode(
   SI32_EPCA_A_Type * basePointer,
   uint32_t mode)
{
   //{{
   basePointer->MODE.U32 = mode;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_read_mode
//
// Reads MODE register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_EPCA_A_read_mode(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   return basePointer->MODE.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_select_input_clock_divisor
//
// Selects the divisor for the input clock.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_select_input_clock_divisor(
   SI32_EPCA_A_Type * basePointer,
   // EPCA clock frequency is given by (input clock frequency) / (divisor +
   // 1).
   uint32_t divisor)
{
   assert(divisor < 1024);   // divisor < 2^10
   //{{
   basePointer->MODE.CLKDIV = divisor;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_select_input_clock_apb
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_select_input_clock_apb(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->MODE.CLKSEL = SI32_EPCA_A_MODE_CLKSEL_APB_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_select_input_clock_timer0_overflow
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_select_input_clock_timer0_overflow(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->MODE.CLKSEL = SI32_EPCA_A_MODE_CLKSEL_TIMER0_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_select_input_clock_eci_high_to_low
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_select_input_clock_eci_high_to_low(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->MODE.CLKSEL = SI32_EPCA_A_MODE_CLKSEL_HL_ECI_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_select_input_clock_external_oscillator
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_select_input_clock_external_oscillator(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->MODE.CLKSEL = SI32_EPCA_A_MODE_CLKSEL_EXTOSCN_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_select_input_clock_eci
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_select_input_clock_eci(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->MODE.CLKSEL = SI32_EPCA_A_MODE_CLKSEL_ECI_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_select_high_drive_port_0_differential
//
// Selects non-differential output from channels 0-5 to high-drive pins.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_select_high_drive_port_0_differential(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->MODE.HDOSEL = SI32_EPCA_A_MODE_HDOSEL_NO_DIFF_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_select_high_drive_port_1_differential
//
// Selects differential output from channel 5 and non-differential output
// from channels 1-4 to high-drive pins.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_select_high_drive_port_1_differential(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->MODE.HDOSEL = SI32_EPCA_A_MODE_HDOSEL_ONE_DIFF_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_select_high_drive_port_2_differential
//
// Selects differential output from channels 4-5 and non-differential
// output from channels 2-3 to high-drive pins.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_select_high_drive_port_2_differential(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->MODE.HDOSEL = SI32_EPCA_A_MODE_HDOSEL_TWO_DIFF_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_select_high_drive_port_3_differential
//
// Selects differential output from channels 3-5 to high-drive pins.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_select_high_drive_port_3_differential(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->MODE.HDOSEL = SI32_EPCA_A_MODE_HDOSEL_THREE_DIFF_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_get_dma_write_end_index
//
// Returns last register to be accessed in a new DMA write transfer set.
//-----------------------------------------------------------------------------
uint32_t
_SI32_EPCA_A_get_dma_write_end_index(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   return basePointer->MODE.DEND;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_set_dma_write_end_index
//
// Sets last register to be accessed in a new DMA write transfer set.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_set_dma_write_end_index(
   SI32_EPCA_A_Type * basePointer,
   // Last register: (0 = LIMIT, 1 = channel 0 CCAPVUPD, ..., 6 = channel 5
   // CCAPVUPD).
   uint32_t index)
{
   assert(index < 8);   // index < 2^3
   //{{
   basePointer->MODE.DEND = index;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_get_dma_write_transfer_pointer
//
// Returns current target of the DMA.
//-----------------------------------------------------------------------------
uint32_t
_SI32_EPCA_A_get_dma_write_transfer_pointer(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   return basePointer->MODE.DPTR;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_set_dma_write_transfer_pointer
//
// Sets current target of the DMA.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_set_dma_write_transfer_pointer(
   SI32_EPCA_A_Type * basePointer,
   // Target: (0 = LIMIT, 1 = channel 0 CCAPVUPD, ..., 6 = channel 5
   // CCAPVUPD).
   uint32_t index)
{
   assert(index < 8);   // index < 2^3
   //{{
   basePointer->MODE.DPTR = index;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_get_dma_target_start_index
//
// Returns first register to be accessed in a new DMA write transfer set.
//-----------------------------------------------------------------------------
uint32_t
_SI32_EPCA_A_get_dma_target_start_index(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   return basePointer->MODE.DSTART;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_set_dma_target_start_index
//
// Sets first register to be accessed in a new DMA write transfer set.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_set_dma_target_start_index(
   SI32_EPCA_A_Type * basePointer,
   // First register: (0 = LIMIT, 1 = channel 0 CCAPVUPD, ..., 6 = channel 5
   // CCAPVUPD).
   uint32_t index)
{
   assert(index < 8);   // index < 2^3
   //{{
   basePointer->MODE.DSTART = index;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_is_dma_busy
//
//-----------------------------------------------------------------------------
bool
_SI32_EPCA_A_is_dma_busy(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   return basePointer->MODE.DBUSYF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_set_dma_busy
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_set_dma_busy(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->MODE.DBUSYF = SI32_EPCA_A_MODE_DBUSYF_BUSY_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_clear_dma_busy
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_clear_dma_busy(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->MODE.DBUSYF = SI32_EPCA_A_MODE_DBUSYF_IDLE_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_select_standard_drive_port_0_differential
//
// Selects non-differential output from channels 0-5 to standard pins.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_select_standard_drive_port_0_differential(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->MODE.STDOSEL = SI32_EPCA_A_MODE_STDOSEL_NO_DIFF_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_select_standard_drive_port_1_differential
//
// Selects differential output from channel 2 and non-differential output
// from channels 0-1 and 3-4 to standard pins.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_select_standard_drive_port_1_differential(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->MODE.STDOSEL = SI32_EPCA_A_MODE_STDOSEL_ONE_DIFF_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_select_standard_drive_port_2_differential
//
// Selects differential output from channels 1-2 and non-differential
// output from channels 0-3 to standard pins.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_select_standard_drive_port_2_differential(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->MODE.STDOSEL = SI32_EPCA_A_MODE_STDOSEL_TWO_DIFF_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_select_standard_drive_port_3_differential
//
// Selects differential output from channels 0-2 to standard pins.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_select_standard_drive_port_3_differential(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->MODE.STDOSEL = SI32_EPCA_A_MODE_STDOSEL_THREE_DIFF_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_write_control
//
// Writes CONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_write_control(
   SI32_EPCA_A_Type * basePointer,
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_read_control
//
// Reads CONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_EPCA_A_read_control(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_enable_counter_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_enable_counter_overflow_interrupt(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EPCA_A_CONTROL_OVFIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_disable_counter_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_disable_counter_overflow_interrupt(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EPCA_A_CONTROL_OVFIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_is_counter_overflow_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_EPCA_A_is_counter_overflow_interrupt_enabled(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.OVFIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_enable_counter_overflow_dma_request
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_enable_counter_overflow_dma_request(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EPCA_A_CONTROL_OVFDEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_disable_counter_overflow_dma_request
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_disable_counter_overflow_dma_request(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EPCA_A_CONTROL_OVFDEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_enable_counter_overflow_synchronization_signal
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_enable_counter_overflow_synchronization_signal(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EPCA_A_CONTROL_OVFSEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_disable_counter_overflow_synchronization_signal
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_disable_counter_overflow_synchronization_signal(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EPCA_A_CONTROL_OVFSEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_enable_halt_input_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_enable_halt_input_interrupt(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EPCA_A_CONTROL_HALTIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_disable_halt_input_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_disable_halt_input_interrupt(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EPCA_A_CONTROL_HALTIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_is_halt_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_EPCA_A_is_halt_interrupt_enabled(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.HALTIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_enable_internal_register_update_on_overflow
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_enable_internal_register_update_on_overflow(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EPCA_A_CONTROL_NOUPD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_disable_internal_register_update_on_overflow
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_disable_internal_register_update_on_overflow(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EPCA_A_CONTROL_NOUPD_ACTIVE_U32;
   //}}
}


//-----------------------------------------------------------------------------
// _SI32_EPCA_A_enable_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_enable_stall_in_debug_mode(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EPCA_A_CONTROL_DBGMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_disable_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_disable_stall_in_debug_mode(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EPCA_A_CONTROL_DBGMD_RUN_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_enable_halt_input
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_enable_halt_input(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EPCA_A_CONTROL_HALTEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_disable_halt_input
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_disable_halt_input(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EPCA_A_CONTROL_HALTEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_select_synchronous_input_trigger
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_select_synchronous_input_trigger(
   SI32_EPCA_A_Type * basePointer,
   // Input trigger number (0 = EPCAnT0, ..., 3 = EPCAnT3).
   uint32_t trigger)
{
   assert((trigger >= 0) && (trigger <= 3));
   //{{
   basePointer->CONTROL_CLR = SI32_EPCA_A_CONTROL_STSEL_MASK;
   basePointer->CONTROL_SET = trigger << SI32_EPCA_A_CONTROL_STSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_select_synchronous_input_trigger_edge_falling
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_select_synchronous_input_trigger_edge_falling(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EPCA_A_CONTROL_STESEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_select_synchronous_input_trigger_edge_rising
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_select_synchronous_input_trigger_edge_rising(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EPCA_A_CONTROL_STESEL_RISING_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_enable_synchronous_input_trigger
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_enable_synchronous_input_trigger(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EPCA_A_CONTROL_STEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_disable_synchronous_input_trigger
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_disable_synchronous_input_trigger(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EPCA_A_CONTROL_STEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_is_clock_divider_in_phase_2
//
//-----------------------------------------------------------------------------
bool
_SI32_EPCA_A_is_clock_divider_in_phase_2(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.DIVST);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_select_clock_divider_state_phase_1
//
// Sets the clock divider to first count-down phase.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_select_clock_divider_state_phase_1(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EPCA_A_CONTROL_DIVST_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_select_clock_divider_state_phase_2
//
// Sets the clock divider to second count-down phase.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_select_clock_divider_state_phase_2(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EPCA_A_CONTROL_DIVST_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_get_clock_divider
//
// Gets EPCA clock divider.
//-----------------------------------------------------------------------------
uint32_t
_SI32_EPCA_A_get_clock_divider(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.DIV;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_set_clock_divider
//
// Sets EPCA clock divider.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_set_clock_divider(
   SI32_EPCA_A_Type * basePointer,
   uint32_t divider)
{
   assert(divider < 1024);   // divider < 2^10
   //{{
   basePointer->CONTROL_CLR = SI32_EPCA_A_CONTROL_DIV_MASK;
   basePointer->CONTROL_SET = divider << SI32_EPCA_A_CONTROL_DIV_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_write_status
//
// Writes STATUS register.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_write_status(
   SI32_EPCA_A_Type * basePointer,
   uint32_t status)
{
   //{{
   basePointer->STATUS.U32 = status;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_read_status
//
// Reads STATUS register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_EPCA_A_read_status(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_is_channel_n_capture_compare_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_EPCA_A_is_channel_n_capture_compare_interrupt_pending(
   SI32_EPCA_A_Type * basePointer,
   // Channel number (0-5).
   uint32_t channel)
{
   assert((channel >= 0) && (channel <= 5));
   //{{
   if (channel == 0)
   {
      return (bool)(basePointer->STATUS.C0CCI);
   }
   else if (channel == 1)
   {
      return (bool)(basePointer->STATUS.C1CCI);
   }
   else if (channel == 2)
   {
      return (bool)(basePointer->STATUS.C2CCI);
   }
   else if (channel == 3)
   {
      return (bool)(basePointer->STATUS.C3CCI);
   }
   else if (channel == 4)
   {
      return (bool)(basePointer->STATUS.C4CCI);
   }
   else
   {
      return (bool)(basePointer->STATUS.C5CCI);
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_set_channel_n_capture_compare_interrupt
//
// Forces channel n capture/compare interrupt.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_set_channel_n_capture_compare_interrupt(
   SI32_EPCA_A_Type * basePointer,
   // Channel number (0-5).
   uint32_t channel)
{
   assert((channel >= 0) && (channel <= 5));
   //{{
   if (channel == 0)
   {
      basePointer->STATUS_SET = SI32_EPCA_A_STATUS_C0CCI_MASK;
   }
   else if (channel == 1)
   {
      basePointer->STATUS_SET = SI32_EPCA_A_STATUS_C1CCI_MASK;
   }
   else if (channel == 2)
   {
      basePointer->STATUS_SET = SI32_EPCA_A_STATUS_C2CCI_MASK;
   }
   else if (channel == 3)
   {
      basePointer->STATUS_SET = SI32_EPCA_A_STATUS_C3CCI_MASK;
   }
   else if (channel == 4)
   {
      basePointer->STATUS_SET = SI32_EPCA_A_STATUS_C4CCI_MASK;
   }
   else if (channel == 5)
   {
      basePointer->STATUS_SET = SI32_EPCA_A_STATUS_C5CCI_MASK;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_clear_channel_n_capture_compare_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_clear_channel_n_capture_compare_interrupt(
   SI32_EPCA_A_Type * basePointer,
   // Channel number (0-5).
   uint32_t channel)
{
   assert((channel >= 0) && (channel <= 5));
   //{{
   if (channel == 0)
   {
      basePointer->STATUS_CLR = SI32_EPCA_A_STATUS_C0CCI_MASK;
   }
   else if (channel == 1)
   {
      basePointer->STATUS_CLR = SI32_EPCA_A_STATUS_C1CCI_MASK;
   }
   else if (channel == 2)
   {
      basePointer->STATUS_CLR = SI32_EPCA_A_STATUS_C2CCI_MASK;
   }
   else if (channel == 3)
   {
      basePointer->STATUS_CLR = SI32_EPCA_A_STATUS_C3CCI_MASK;
   }
   else if (channel == 4)
   {
      basePointer->STATUS_CLR = SI32_EPCA_A_STATUS_C4CCI_MASK;
   }
   else if (channel == 5)
   {
      basePointer->STATUS_CLR = SI32_EPCA_A_STATUS_C5CCI_MASK;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_start_counter_timer
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_start_counter_timer(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_SET = SI32_EPCA_A_STATUS_RUN_START_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_stop_counter_timer
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_stop_counter_timer(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_CLR = SI32_EPCA_A_STATUS_RUN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_is_counter_timer_overflow_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_EPCA_A_is_counter_timer_overflow_interrupt_pending(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->STATUS.OVFI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_set_counter_timer_overflow_interrupt
//
// Forces EPCA counter/timer overflow interrupt.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_set_counter_timer_overflow_interrupt(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_SET = SI32_EPCA_A_STATUS_OVFI_SET_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_clear_counter_timer_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_clear_counter_timer_overflow_interrupt(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_CLR = SI32_EPCA_A_STATUS_OVFI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_is_register_update_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_EPCA_A_is_register_update_pending(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->STATUS.UPDCF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_set_register_update_complete_flag
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_set_register_update_complete_flag(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_SET = SI32_EPCA_A_STATUS_UPDCF_FULL_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_clear_register_update_complete_flag
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_clear_register_update_complete_flag(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_CLR = SI32_EPCA_A_STATUS_UPDCF_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_is_halt_input_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_EPCA_A_is_halt_input_interrupt_pending(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->STATUS.HALTI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_set_halt_input_interrupt
//
// Forces halt input interrupt (PB_HDKill).
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_set_halt_input_interrupt(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_SET = SI32_EPCA_A_STATUS_HALTI_SET_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_clear_halt_input_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_clear_halt_input_interrupt(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_CLR = SI32_EPCA_A_STATUS_HALTI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_is_channel_n_intermediate_overflow_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_EPCA_A_is_channel_n_intermediate_overflow_interrupt_pending(
   SI32_EPCA_A_Type * basePointer,
   // Channel number (0-5).
   uint32_t channel)
{
   assert((channel >= 0) && (channel <= 5));
   //{{
   if (channel == 0)
   {
      return (bool)(basePointer->STATUS.C0IOVFI);
   }
   else if (channel == 1)
   {
      return (bool)(basePointer->STATUS.C1IOVFI);
   }
   else if (channel == 2)
   {
      return (bool)(basePointer->STATUS.C2IOVFI);
   }
   else if (channel == 3)
   {
      return (bool)(basePointer->STATUS.C3IOVFI);
   }
   else if (channel == 4)
   {
      return (bool)(basePointer->STATUS.C4IOVFI);
   }
   else
   {
      return (bool)(basePointer->STATUS.C5IOVFI);
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_set_channel_n_intermediate_overflow_interrupt
//
// Forces channel n intermediate overflow interrupt.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_set_channel_n_intermediate_overflow_interrupt(
   SI32_EPCA_A_Type * basePointer,
   // Channel number (0-5).
   uint32_t channel)
{
   assert((channel >= 0) && (channel <= 5));
   //{{
   if (channel == 0)
   {
      basePointer->STATUS_SET = SI32_EPCA_A_STATUS_C0IOVFI_MASK;
   }
   else if (channel == 1)
   {
      basePointer->STATUS_SET = SI32_EPCA_A_STATUS_C1IOVFI_MASK;
   }
   else if (channel == 2)
   {
      basePointer->STATUS_SET = SI32_EPCA_A_STATUS_C2IOVFI_MASK;
   }
   else if (channel == 3)
   {
      basePointer->STATUS_SET = SI32_EPCA_A_STATUS_C3IOVFI_MASK;
   }
   else if (channel == 4)
   {
      basePointer->STATUS_SET = SI32_EPCA_A_STATUS_C4IOVFI_MASK;
   }
   else
   {
      basePointer->STATUS_SET = SI32_EPCA_A_STATUS_C5IOVFI_MASK;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_clear_channel_n_intermediate_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_clear_channel_n_intermediate_overflow_interrupt(
   SI32_EPCA_A_Type * basePointer,
   // Channel number (0-5).
   uint32_t channel)
{
   assert((channel >= 0) && (channel <= 5));
   //{{
   if (channel == 0)
   {
      basePointer->STATUS_CLR = SI32_EPCA_A_STATUS_C0IOVFI_MASK;
   }
   else if (channel == 1)
   {
      basePointer->STATUS_CLR = SI32_EPCA_A_STATUS_C1IOVFI_MASK;
   }
   else if (channel == 2)
   {
      basePointer->STATUS_CLR = SI32_EPCA_A_STATUS_C2IOVFI_MASK;
   }
   else if (channel == 3)
   {
      basePointer->STATUS_CLR = SI32_EPCA_A_STATUS_C3IOVFI_MASK;
   }
   else if (channel == 4)
   {
      basePointer->STATUS_CLR = SI32_EPCA_A_STATUS_C4IOVFI_MASK;
   }
   else if (channel == 5)
   {
      basePointer->STATUS_CLR = SI32_EPCA_A_STATUS_C5IOVFI_MASK;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_write_counter
//
// Writes COUNTER register.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_write_counter(
   SI32_EPCA_A_Type * basePointer,
   uwide16_t counter)
{
   //{{
   basePointer->COUNTER.U32 = counter;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_read_counter
//
// Reads COUNTER register.
//-----------------------------------------------------------------------------
uwide16_t
_SI32_EPCA_A_read_counter(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   return basePointer->COUNTER.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_write_limit
//
// Writes LIMIT register.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_write_limit(
   SI32_EPCA_A_Type * basePointer,
   uwide16_t limit)
{
   //{{
   basePointer->LIMIT.U32 = limit;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_read_limit
//
// Reads LIMIT register.
//-----------------------------------------------------------------------------
uwide16_t
_SI32_EPCA_A_read_limit(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   return basePointer->LIMIT.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_write_limitupd
//
// Writes LIMITUPD register.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_write_limitupd(
   SI32_EPCA_A_Type * basePointer,
   uwide16_t limitupd)
{
   //{{
   basePointer->LIMITUPD.U32 = limitupd;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_read_limitupd
//
// Reads LIMITUPD register.
//-----------------------------------------------------------------------------
uwide16_t
_SI32_EPCA_A_read_limitupd(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   return basePointer->LIMITUPD.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_write_dtime
//
// Writes DTIME register.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_write_dtime(
   SI32_EPCA_A_Type * basePointer,
   uwide16_t dtime)
{
   //{{
   basePointer->DTIME.U32 = dtime;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_read_dtime
//
// Reads DTIME register.
//-----------------------------------------------------------------------------
uwide16_t
_SI32_EPCA_A_read_dtime(
   SI32_EPCA_A_Type * basePointer)
{
   //{{
   return basePointer->DTIME.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_write_phase_x_delay_time
//
// Writes the delay time after deasserting the phase-x output.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_write_phase_x_delay_time(
   SI32_EPCA_A_Type * basePointer,
   uwide8_t value)
{
   assert(value < 256);   // value < 2^8
   //{{
   basePointer->DTIME.DTIMEX = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_write_phase_y_delay_time
//
// Writes the delay time after deasserting the phase-y output.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_write_phase_y_delay_time(
   SI32_EPCA_A_Type * basePointer,
   uwide8_t value)
{
   assert(value < 256);   // value < 2^8
   //{{
   basePointer->DTIME.DTIMEY = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCA_A_write_dtarget
//
// Writes DTARGET register.
//-----------------------------------------------------------------------------
void
_SI32_EPCA_A_write_dtarget(
   SI32_EPCA_A_Type * basePointer,
   uint32_t dtarget)
{
   //{{
   basePointer->DTARGET.U32 = dtarget;
   //}}
}


//-eof--------------------------------------------------------------------------
