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
/// @file SI32_EMIF_A_Type.c
//
// Script: 0.58
// HAL Source: 0.1
// Version: 3

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_EMIF_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_EMIF_A_initialize
//
//-----------------------------------------------------------------------------
void
_SI32_EMIF_A_initialize(
   SI32_EMIF_A_Type * basePointer,
   // Value for the CONTROL register.
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIF_A_read_control
//
// Read CONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_EMIF_A_read_control(
   SI32_EMIF_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIF_A_write_control
//
// Write to CONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_EMIF_A_write_control(
   SI32_EMIF_A_Type * basePointer,
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIF_A_disable_interface_0
//
//-----------------------------------------------------------------------------
void
_SI32_EMIF_A_disable_interface_0(
   SI32_EMIF_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EMIF_A_CONTROL_IF0EN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIF_A_enable_interface_0
//
//-----------------------------------------------------------------------------
void
_SI32_EMIF_A_enable_interface_0(
   SI32_EMIF_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EMIF_A_CONTROL_IF0EN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIF_A_disable_interface_1
//
//-----------------------------------------------------------------------------
void
_SI32_EMIF_A_disable_interface_1(
   SI32_EMIF_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EMIF_A_CONTROL_IF1EN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIF_A_enable_interface_1
//
//-----------------------------------------------------------------------------
void
_SI32_EMIF_A_enable_interface_1(
   SI32_EMIF_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EMIF_A_CONTROL_IF1EN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIF_A_is_interface_0_active
//
//-----------------------------------------------------------------------------
bool
_SI32_EMIF_A_is_interface_0_active(
   SI32_EMIF_A_Type * basePointer)
{
   //{{
  return (bool)basePointer->CONTROL.IF0EN;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIF_A_is_interface_1_active
//
//-----------------------------------------------------------------------------
bool
_SI32_EMIF_A_is_interface_1_active(
   SI32_EMIF_A_Type * basePointer)
{
   //{{
  return (bool)basePointer->CONTROL.IF1EN;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIF_A_enable_off_state
//
//-----------------------------------------------------------------------------
void
_SI32_EMIF_A_enable_off_state(
   SI32_EMIF_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EMIF_A_CONTROL_OFFSTEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIF_A_disable_off_state
//
//-----------------------------------------------------------------------------
void
_SI32_EMIF_A_disable_off_state(
   SI32_EMIF_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EMIF_A_CONTROL_OFFSTEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIF_A_is_off
//
//-----------------------------------------------------------------------------
bool
_SI32_EMIF_A_is_off(
   SI32_EMIF_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->STATUS.OFFSTS);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIF_A_is_idle
//
//-----------------------------------------------------------------------------
bool
_SI32_EMIF_A_is_idle(
   SI32_EMIF_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->STATUS.IDLESTS);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIF_A_is_running
//
//-----------------------------------------------------------------------------
bool
_SI32_EMIF_A_is_running(
   SI32_EMIF_A_Type * basePointer)
{
   //{{
   return (bool)!(basePointer->STATUS.U32
                  & (SI32_EMIF_A_STATUS_IDLESTS_MASK
                     | SI32_EMIF_A_STATUS_OFFSTS_MASK));
   //}}
}


//-eof--------------------------------------------------------------------------
