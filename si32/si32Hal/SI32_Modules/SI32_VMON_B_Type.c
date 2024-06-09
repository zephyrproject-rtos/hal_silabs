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
/// @file SI32_VMON_B_Type.c
//
// Script: 0.59
// HAL Source: 0.1
// Version: 1

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_VMON_B_Type.h"


//-----------------------------------------------------------------------------
// _SI32_VMON_B_initialize
//
// Writes all VMON registers.
//-----------------------------------------------------------------------------
void
_SI32_VMON_B_initialize(
   SI32_VMON_B_Type * basePointer,
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_B_write_control
//
// Writes CONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_VMON_B_write_control(
   SI32_VMON_B_Type * basePointer,
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_B_read_control
//
// Reads CONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_VMON_B_read_control(
   SI32_VMON_B_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_B_is_vbat_above_reset_threshold
//
//-----------------------------------------------------------------------------
bool
_SI32_VMON_B_is_vbat_above_reset_threshold(
   SI32_VMON_B_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.VBATRSTF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_B_is_vbat_low_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_VMON_B_is_vbat_low_interrupt_pending(
   SI32_VMON_B_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.VBATLI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_B_select_vbat_high_threshold
//
//-----------------------------------------------------------------------------
void
_SI32_VMON_B_select_vbat_high_threshold(
   SI32_VMON_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_VMON_B_CONTROL_VBATHITHEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_B_select_vbat_standard_threshold
//
//-----------------------------------------------------------------------------
void
_SI32_VMON_B_select_vbat_standard_threshold(
   SI32_VMON_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_VMON_B_CONTROL_VBATHITHEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_B_enable_vbat_low_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_VMON_B_enable_vbat_low_interrupt(
   SI32_VMON_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_VMON_B_CONTROL_VBATLIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_B_disable_vbat_low_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_VMON_B_disable_vbat_low_interrupt(
   SI32_VMON_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_VMON_B_CONTROL_VBATLIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_B_is_vbat_low_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_VMON_B_is_vbat_low_interrupt_enabled(
   SI32_VMON_B_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.VBATLIEN;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_B_enable_vbat_supply_monitor
//
//-----------------------------------------------------------------------------
void
_SI32_VMON_B_enable_vbat_supply_monitor(
   SI32_VMON_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_VMON_B_CONTROL_VMONEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_B_disable_vbat_supply_monitor
//
//-----------------------------------------------------------------------------
void
_SI32_VMON_B_disable_vbat_supply_monitor(
   SI32_VMON_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_VMON_B_CONTROL_VMONEN_MASK;
   //}}
}


//-eof--------------------------------------------------------------------------
