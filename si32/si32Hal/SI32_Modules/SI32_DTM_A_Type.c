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
/// @file SI32_DTM_A_Type.c
//
// Script: 0.6
// HAL Source: 0.2
// Version: 6

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_DTM_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_DTM_A_initialize
//
// Initializes all writeable DTM registers.
//-----------------------------------------------------------------------------
void
_SI32_DTM_A_initialize(
   SI32_DTM_A_Type * basePointer,
   // Initial CONTROL register value.
   uint32_t control,
   // Initial TIMEOUT register value.
   uint32_t timeout,
   // Initial MSTCOUNT register value.
   uint32_t mstcount,
   // Initial STATEADDR register value.
   uint32_t stateaddr)
{
   //{{
   basePointer->CONTROL.U32 = control;
   basePointer->TIMEOUT.U32 = timeout;
   basePointer->MSTCOUNT.U32 = mstcount;
   basePointer->STATEADDR.U32 = stateaddr;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_write_control
//
// Writes the CONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_DTM_A_write_control(
   SI32_DTM_A_Type * basePointer,
   // CONTROL register value.
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_read_control
//
// Reads the CONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_DTM_A_read_control(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_set_active_state_counter
//
// Sets the active state counter to the requested value.
//-----------------------------------------------------------------------------
void
_SI32_DTM_A_set_active_state_counter(
   SI32_DTM_A_Type * basePointer,
   // Requested active state count.
   uint32_t count)
{
   assert(count < 256);   // count < 2^8
   //{{
   basePointer->CONTROL_CLR = SI32_DTM_A_CONTROL_STCOUNT_MASK;
   basePointer->CONTROL_SET = (count)<<SI32_DTM_A_CONTROL_STCOUNT_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_get_active_state_counter
//
// Reads the active state counter.
//-----------------------------------------------------------------------------
uint32_t
_SI32_DTM_A_get_active_state_counter(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.STCOUNT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_set_active_state
//
// Sets the active state to the requested value.
//-----------------------------------------------------------------------------
void
_SI32_DTM_A_set_active_state(
   SI32_DTM_A_Type * basePointer,
   // Requested active state.
   uint32_t state)
{
   assert(state < 16);   // state < 2^4
   //{{
   basePointer->CONTROL_CLR = SI32_DTM_A_CONTROL_ST_MASK;
   basePointer->CONTROL_SET = (state)<<SI32_DTM_A_CONTROL_ST_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_get_active_state
//
// Reads the active state.
//-----------------------------------------------------------------------------
uint32_t
_SI32_DTM_A_get_active_state(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.ST;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_get_last_state
//
// Reads the last state.
//-----------------------------------------------------------------------------
uint32_t
_SI32_DTM_A_get_last_state(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.LASTST;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_set_inhibit_signal_selection
//
// Sets which DTMnINH.x signal is used for inhibit control.
//-----------------------------------------------------------------------------
void
_SI32_DTM_A_set_inhibit_signal_selection(
   SI32_DTM_A_Type * basePointer,
   // The requested inhibit signal.
   uint32_t signal)
{
   assert(signal < 16);   // signal < 2^4
   //{{
   basePointer->CONTROL_CLR = SI32_DTM_A_CONTROL_INHSSEL_MASK;
   basePointer->CONTROL_SET = (signal)<<SI32_DTM_A_CONTROL_INHSSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_get_inhibit_signal_selection
//
// Gets which DTMnINH.x signal is used for inhibit control.
//-----------------------------------------------------------------------------
uint32_t
_SI32_DTM_A_get_inhibit_signal_selection(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.INHSSEL;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_read_inhibit_signal_status
//
// Reads the status of the inhibit signal selected by the INHSEN field.
//-----------------------------------------------------------------------------
uint32_t
_SI32_DTM_A_read_inhibit_signal_status(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.INHF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_enable_stall_in_debug_mode
//
// Enables stalling the DTM module when the core is halted.
//-----------------------------------------------------------------------------
void
_SI32_DTM_A_enable_stall_in_debug_mode(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_DTM_A_CONTROL_DBGMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_disable_stall_in_debug_mode
//
// Disables stalling the DTM module when the core is halted.
//-----------------------------------------------------------------------------
void
_SI32_DTM_A_disable_stall_in_debug_mode(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_DTM_A_CONTROL_DBGMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_read_destination_dma_request_status
//
// Reads the status of the destination DMA request signal.
//-----------------------------------------------------------------------------
uint32_t
_SI32_DTM_A_read_destination_dma_request_status(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.DSTREQF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_read_source_dma_request_status
//
// Reads the status of the source DMA request signal.
//-----------------------------------------------------------------------------
uint32_t
_SI32_DTM_A_read_source_dma_request_status(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.SRCREQF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_enable_module_inhibit
//
// Pauses the DTM module. DMA requests are ignored.
//-----------------------------------------------------------------------------
void
_SI32_DTM_A_enable_module_inhibit(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_DTM_A_CONTROL_DTMINH_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_disable_module_inhibit
//
// Resumes the DTM module. DMA requests are honored.
//-----------------------------------------------------------------------------
void
_SI32_DTM_A_disable_module_inhibit(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_DTM_A_CONTROL_DTMINH_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_clear_timeout_error_interrupt
//
// Clears timeout error interrupt flag.
//-----------------------------------------------------------------------------
void
_SI32_DTM_A_clear_timeout_error_interrupt(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_DTM_A_CONTROL_TOERRI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_is_timeout_error_interrupt_pending
//
// Checks if timeout error interrupt flag is set.
//-----------------------------------------------------------------------------
bool
_SI32_DTM_A_is_timeout_error_interrupt_pending(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->CONTROL.TOERRI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_clear_dma_error_interrupt
//
// Clears DMA error interrupt flag.
//-----------------------------------------------------------------------------
void
_SI32_DTM_A_clear_dma_error_interrupt(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_DTM_A_CONTROL_DMAERRI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_is_dma_error_interrupt_pending
//
// Checks if DMA error interrupt flag is set.
//-----------------------------------------------------------------------------
bool
_SI32_DTM_A_is_dma_error_interrupt_pending(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->CONTROL.DMAERRI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_clear_module_interrupt
//
// Clears DTM module interrupt flag.
//-----------------------------------------------------------------------------
void
_SI32_DTM_A_clear_module_interrupt(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_DTM_A_CONTROL_DTMI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_is_module_interrupt_pending
//
// Checks if DTM module interrupt flag is set.
//-----------------------------------------------------------------------------
bool
_SI32_DTM_A_is_module_interrupt_pending(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->CONTROL.DTMI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_clear_all_interrupts
//
// Clear all DTM interrupt flags.
//-----------------------------------------------------------------------------
void
_SI32_DTM_A_clear_all_interrupts(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_DTM_A_CONTROL_TOERRI_MASK
                            | SI32_DTM_A_CONTROL_DMAERRI_MASK
                            | SI32_DTM_A_CONTROL_DTMI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_is_any_interrupt_pending
//
// Checks if any DTM interrupt flag is set.
//-----------------------------------------------------------------------------
bool
_SI32_DTM_A_is_any_interrupt_pending(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.U32 
                 & (SI32_DTM_A_CONTROL_TOERRI_MASK
                    | SI32_DTM_A_CONTROL_DMAERRI_MASK
                    | SI32_DTM_A_CONTROL_DTMI_MASK));
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_enable_module
//
// Enables the DTM module.
//-----------------------------------------------------------------------------
void
_SI32_DTM_A_enable_module(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_DTM_A_CONTROL_DTMEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_disable_module
//
// Disables the DTM module.
//-----------------------------------------------------------------------------
void
_SI32_DTM_A_disable_module(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_DTM_A_CONTROL_DTMEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_write_timeout
//
// Writes the TIMEOUT register.
//-----------------------------------------------------------------------------
void
_SI32_DTM_A_write_timeout(
   SI32_DTM_A_Type * basePointer,
   // TIMEOUT register value.
   uint32_t timeout)
{
   //{{
   basePointer->TIMEOUT.U32 = timeout;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_read_timeout
//
// Reads the TIMEOUT register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_DTM_A_read_timeout(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   return basePointer->TIMEOUT.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_set_timeout_counter_reload
//
// Sets the timeout counter reload value.
//-----------------------------------------------------------------------------
void
_SI32_DTM_A_set_timeout_counter_reload(
   SI32_DTM_A_Type * basePointer,
   // Timeout counter reload value.
   uint32_t toreload)
{
   assert(toreload < 65536);   // toreload < 2^16
   //{{
   basePointer->TIMEOUT.TORELOAD = toreload;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_get_timeout_counter_reload
//
// Reads the timeout counter reload value.
//-----------------------------------------------------------------------------
uint32_t
_SI32_DTM_A_get_timeout_counter_reload(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   return basePointer->TIMEOUT.TORELOAD;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_get_timeout_count
//
// Returns current value of the timeout counter.
//-----------------------------------------------------------------------------
uint32_t
_SI32_DTM_A_get_timeout_count(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   return basePointer->TIMEOUT.TOCOUNT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_set_master_count
//
// Sets the master counter value.
//-----------------------------------------------------------------------------
void
_SI32_DTM_A_set_master_count(
   SI32_DTM_A_Type * basePointer,
   // The requested master counter value.
   uint32_t count)
{
   assert(count < 65536);   // count < 2^16
   //{{
   basePointer->MSTCOUNT.MSTCOUNT_BITS = count;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_get_master_count
//
// Gets the master counter value.
//-----------------------------------------------------------------------------
uint32_t
_SI32_DTM_A_get_master_count(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   return basePointer->MSTCOUNT.MSTCOUNT_BITS;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_write_state_address
//
// Writes the STATEADDR register.
//-----------------------------------------------------------------------------
void
_SI32_DTM_A_write_state_address(
   SI32_DTM_A_Type * basePointer,
   // STATEADDR register value.
   uint32_t stateaddr)
{
   //{{
   basePointer->STATEADDR.U32 = (stateaddr) & SI32_DTM_A_STATEADDR_STATEADDR_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_read_state_address
//
// Reads the STATEADDR register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_DTM_A_read_state_address(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   return basePointer->STATEADDR.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DTM_A_read_state
//
// Reads the STATE register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_DTM_A_read_state(
   SI32_DTM_A_Type * basePointer)
{
   //{{
   return basePointer->STATE.U32;
   //}}
}


//-eof--------------------------------------------------------------------------
