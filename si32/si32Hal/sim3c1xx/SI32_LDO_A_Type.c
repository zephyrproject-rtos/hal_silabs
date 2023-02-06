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
/// @file SI32_LDO_A_Type.c
//
// This file applies to the SIM3C1XX_LDO_A module
//
// Script: 0.58
// HAL Source: 0.1
// Version: 3

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_LDO_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_LDO_A_write_control
//
// Write to CONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_LDO_A_write_control(
   SI32_LDO_A_Type * basePointer,
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LDO_A_read_control
//
// Reads CONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_LDO_A_read_control(
   SI32_LDO_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LDO_A_select_high_bias
//
//-----------------------------------------------------------------------------
void
_SI32_LDO_A_select_high_bias(
   SI32_LDO_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LDO_A_CONTROL_LDOIBIAS_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LDO_A_select_low_bias
//
//-----------------------------------------------------------------------------
void
_SI32_LDO_A_select_low_bias(
   SI32_LDO_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LDO_A_CONTROL_LDOIBIAS_LOWBIAS_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LDO_A_enable_bias
//
//-----------------------------------------------------------------------------
void
_SI32_LDO_A_enable_bias(
   SI32_LDO_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_LDO_A_CONTROL_LDOAEN_ENABLE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LDO_A_disable_bias
//
//-----------------------------------------------------------------------------
void
_SI32_LDO_A_disable_bias(
   SI32_LDO_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_LDO_A_CONTROL_LDOAEN_MASK;
   //}}
}


//-eof--------------------------------------------------------------------------
