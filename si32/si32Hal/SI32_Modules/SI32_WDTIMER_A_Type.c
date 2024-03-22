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
/// @file SI32_WDTIMER_A_Type.c
//
// Script: 0.58
// HAL Source: 0.5
// Version: 2

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_WDTIMER_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_WDTIMER_A_initialize
//
//-----------------------------------------------------------------------------
void
_SI32_WDTIMER_A_initialize(
   SI32_WDTIMER_A_Type * basePointer,
   // Write to CONTROL register.
   uint32_t control,
   // Write to THRESHOLD register.
   uint32_t threshold)
{
   //{{
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;
   basePointer->CONTROL.U32 = control;
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;
   basePointer->THRESHOLD.U32 = threshold;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_WDTIMER_A_write_control
//
// Write to CONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_WDTIMER_A_write_control(
   SI32_WDTIMER_A_Type * basePointer,
   uint32_t control)
{
   //{{
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_WDTIMER_A_read_control
//
// Read from CONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_WDTIMER_A_read_control(
   SI32_WDTIMER_A_Type * basePointer)
{
   //{{
	return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_WDTIMER_A_enable_early_warning_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_WDTIMER_A_enable_early_warning_interrupt(
   SI32_WDTIMER_A_Type * basePointer)
{
   //{{
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;
   basePointer->CONTROL_SET = SI32_WDTIMER_A_CONTROL_EWIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_WDTIMER_A_disable_early_warning_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_WDTIMER_A_disable_early_warning_interrupt(
   SI32_WDTIMER_A_Type * basePointer)
{
   //{{
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;
   basePointer->CONTROL_CLR = SI32_WDTIMER_A_CONTROL_EWIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_WDTIMER_A_is_early_warning_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_WDTIMER_A_is_early_warning_interrupt_enabled(
   SI32_WDTIMER_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.EWIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_WDTIMER_A_enable_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_WDTIMER_A_enable_stall_in_debug_mode(
   SI32_WDTIMER_A_Type * basePointer)
{
   //{{
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;
   basePointer->CONTROL_SET = SI32_WDTIMER_A_CONTROL_DBGMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_WDTIMER_A_disable_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_WDTIMER_A_disable_stall_in_debug_mode(
   SI32_WDTIMER_A_Type * basePointer)
{
   //{{
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;
   basePointer->CONTROL_CLR = SI32_WDTIMER_A_CONTROL_DBGMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_WDTIMER_A_received_attention_key
//
//-----------------------------------------------------------------------------
bool
_SI32_WDTIMER_A_received_attention_key(
   SI32_WDTIMER_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->STATUS.KEYSTS);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_WDTIMER_A_is_module_writable
//
//-----------------------------------------------------------------------------
bool
_SI32_WDTIMER_A_is_module_writable(
   SI32_WDTIMER_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->STATUS.PRIVSTS);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_WDTIMER_A_is_early_warning_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_WDTIMER_A_is_early_warning_interrupt_pending(
   SI32_WDTIMER_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->STATUS.EWI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_WDTIMER_A_clear_early_warning_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_WDTIMER_A_clear_early_warning_interrupt(
   SI32_WDTIMER_A_Type * basePointer)
{
   //{{
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;
   basePointer->STATUS_CLR = SI32_WDTIMER_A_STATUS_EWI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_WDTIMER_A_is_counter_less_than_reset_threshold
//
//-----------------------------------------------------------------------------
bool
_SI32_WDTIMER_A_is_counter_less_than_reset_threshold(
   SI32_WDTIMER_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->STATUS.RTHF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_WDTIMER_A_is_threshold_update_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_WDTIMER_A_is_threshold_update_pending(
   SI32_WDTIMER_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->STATUS.UPDSTS);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_WDTIMER_A_write_threshold
//
// Write to THRESHOLD register.
//-----------------------------------------------------------------------------
void
_SI32_WDTIMER_A_write_threshold(
   SI32_WDTIMER_A_Type * basePointer,
   uint32_t threshold)
{
   //{{
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;
   basePointer->THRESHOLD.U32 = threshold;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_WDTIMER_A_read_threshold
//
// Reads from THRESHOLD register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_WDTIMER_A_read_threshold(
   SI32_WDTIMER_A_Type * basePointer)
{
   //{{
	return basePointer->THRESHOLD.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_WDTIMER_A_set_early_warning_threshold
//
// Write value to the  EWTH register. When the WDT counter matches EWTH,
// a WDT interrupt will occur if WDT early warning interrupts are
// enabled.
//-----------------------------------------------------------------------------
void
_SI32_WDTIMER_A_set_early_warning_threshold(
   SI32_WDTIMER_A_Type * basePointer,
   uint32_t count)
{
   assert(count < 65536);   // count < 2^16
   //{{
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;
   basePointer->THRESHOLD.U32 &= ~SI32_WDTIMER_A_THRESHOLD_EWTH_MASK;
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;
   basePointer->THRESHOLD.U32 |= count;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_WDTIMER_A_get_early_warning_threshold
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_WDTIMER_A_get_early_warning_threshold(
   SI32_WDTIMER_A_Type * basePointer)
{
   //{{
	return basePointer->THRESHOLD.EWTH;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_WDTIMER_A_set_reset_threshold
//
// Write value to the RTH register. When the WDT counter matches RTH, a
// system reset will occur if it is enabled as a reset source.
//-----------------------------------------------------------------------------
void
_SI32_WDTIMER_A_set_reset_threshold(
   SI32_WDTIMER_A_Type * basePointer,
   uint32_t count)
{
   assert(count < 65536);   // count < 2^16
   //{{
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;
   basePointer->THRESHOLD.U32 &= ~SI32_WDTIMER_A_THRESHOLD_RTH_MASK;
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;
   basePointer->THRESHOLD.U32 |= count << SI32_WDTIMER_A_THRESHOLD_RTH_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_WDTIMER_A_get_reset_threshold
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_WDTIMER_A_get_reset_threshold(
   SI32_WDTIMER_A_Type * basePointer)
{
   //{{
	return basePointer->THRESHOLD.RTH;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_WDTIMER_A_reset_counter
//
// Writes attention key and reset key.
//-----------------------------------------------------------------------------
void
_SI32_WDTIMER_A_reset_counter(
   SI32_WDTIMER_A_Type * basePointer)
{
   //{{
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_RESET_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_WDTIMER_A_stop_counter
//
// Writes attention key and disable key.
//-----------------------------------------------------------------------------
void
_SI32_WDTIMER_A_stop_counter(
   SI32_WDTIMER_A_Type * basePointer)
{
   //{{
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_DISABLE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_WDTIMER_A_start_counter
//
// Writes attention key and start key.
//-----------------------------------------------------------------------------
void
_SI32_WDTIMER_A_start_counter(
   SI32_WDTIMER_A_Type * basePointer)
{
   //{{
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_START_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_WDTIMER_A_lock_until_reset
//
// Writes attention key and reset key.
//-----------------------------------------------------------------------------
void
_SI32_WDTIMER_A_lock_until_reset(
   SI32_WDTIMER_A_Type * basePointer)
{
   //{{
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_LOCK_U32;
   //}}
}


//-eof--------------------------------------------------------------------------
