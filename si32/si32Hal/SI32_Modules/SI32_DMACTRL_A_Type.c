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
/// @file SI32_DMACTRL_A_Type.c
//
// Script: 0.58
// HAL Source: 0.2
// Version: 3

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_DMACTRL_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_initialize
//
//-----------------------------------------------------------------------------
void
_SI32_DMACTRL_A_initialize(
   SI32_DMACTRL_A_Type * basePointer,
   // Write to CONFIG register.
   uint32_t config,
   // Write to BASEPTR register.
   uint32_t baseptr,
   // Write to CHSWRCN register.
   uint32_t chswrcn,
   // Write to CHREQM register.
   uint32_t chreqm,
   // Write to CHEN register.
   uint32_t chen,
   // Write to CHALT register.
   uint32_t chalt,
   // Write to CHHP register.
   uint32_t chhp,
   // Write to BERR register.
   uint32_t berr)
{
   //{{
   basePointer->CONFIG.U32 = config;
   basePointer->BASEPTR.U32 = baseptr;
   basePointer->CHSWRCN.U32 = chswrcn;
   basePointer->CHREQMCLR.U32 = 0xFFFFFFFF;
   basePointer->CHREQMSET.U32 = chreqm;
   basePointer->CHENCLR.U32 = 0xFFFFFFFF;
   basePointer->CHENSET.U32 = chen;
   basePointer->CHALTCLR.U32 = 0xFFFFFFFF;
   basePointer->CHALTSET.U32 = chalt;
   basePointer->CHHPCLR.U32 = 0xFFFFFFFF;
   basePointer->CHHPSET.U32 = chhp;
   basePointer->BERRCLR.U32 = berr;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_is_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_DMACTRL_A_is_enabled(
   SI32_DMACTRL_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->STATUS.DMAENSTS);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_get_state
//
//-----------------------------------------------------------------------------
SI32_DMACTRL_A_STATE_Enum_Type
_SI32_DMACTRL_A_get_state(
   SI32_DMACTRL_A_Type * basePointer)
{
   //{{
   return (SI32_DMACTRL_A_STATE_Enum_Type)basePointer->STATUS.STATE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_get_number_of_channels
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_DMACTRL_A_get_number_of_channels(
   SI32_DMACTRL_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.NUMCHAN + 1;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_write_config
//
// Write to CONFIG register.
//-----------------------------------------------------------------------------
void
_SI32_DMACTRL_A_write_config(
   SI32_DMACTRL_A_Type * basePointer,
   uwide8_t config)
{
   //{{
   basePointer->CONFIG.U32 = config;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_enable_module
//
//-----------------------------------------------------------------------------
void
_SI32_DMACTRL_A_enable_module(
   SI32_DMACTRL_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG.DMAEN = SI32_DMACTRL_A_CONFIG_DMAEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_disable_module
//
//-----------------------------------------------------------------------------
void
_SI32_DMACTRL_A_disable_module(
   SI32_DMACTRL_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG.DMAEN = SI32_DMACTRL_A_CONFIG_DMAEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_read_baseptr
//
// Read BASEPTR register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_DMACTRL_A_read_baseptr(
   SI32_DMACTRL_A_Type * basePointer)
{
   //{{
   return basePointer->BASEPTR.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_write_baseptr
//
// Write to BASEPTR register.
//-----------------------------------------------------------------------------
void
_SI32_DMACTRL_A_write_baseptr(
   SI32_DMACTRL_A_Type * basePointer,
   uint32_t baseptr)
{
   //{{
   basePointer->BASEPTR.U32 = (baseptr & SI32_DMACTRL_A_BASEPTR_BASEPTR_MASK);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_read_abaseptr
//
// Read ABASEPTR register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_DMACTRL_A_read_abaseptr(
   SI32_DMACTRL_A_Type * basePointer)
{
   //{{
   return basePointer->ABASEPTR.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_write_chswrcn
//
// Write to CHSWRCN register.
//-----------------------------------------------------------------------------
void
_SI32_DMACTRL_A_write_chswrcn(
   SI32_DMACTRL_A_Type * basePointer,
   uint32_t chswrcn)
{
   //{{
   basePointer->CHSWRCN.U32 = chswrcn;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_generate_software_request
//
//-----------------------------------------------------------------------------
void
_SI32_DMACTRL_A_generate_software_request(
   SI32_DMACTRL_A_Type * basePointer,
   // Set the channels software request bit.
   uint32_t channel_number)
{
   assert(channel_number < 16);   // channel_number < 2^4
   //{{
   basePointer->CHSWRCN.U32 |= (1 << channel_number);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_read_chreqm
//
// Read CHREQM register.
//-----------------------------------------------------------------------------
uwide16_t
_SI32_DMACTRL_A_read_chreqm(
   SI32_DMACTRL_A_Type * basePointer)
{
   //{{
   return basePointer->CHREQMSET.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_write_chreqm
//
// Write to CHREQM register.
//-----------------------------------------------------------------------------
void
_SI32_DMACTRL_A_write_chreqm(
   SI32_DMACTRL_A_Type * basePointer,
   uint32_t chreqm)
{
   //{{
   basePointer->CHREQMCLR.U32 = 0xFFFFFFFF;
   basePointer->CHREQMSET.U32 = chreqm;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_enable_data_request
//
//-----------------------------------------------------------------------------
void
_SI32_DMACTRL_A_enable_data_request(
   SI32_DMACTRL_A_Type * basePointer,
   uint32_t channel_number)
{
   assert(channel_number < 16);   // channel_number < 2^4
   //{{
   basePointer->CHREQMCLR.U32 = (1 << channel_number);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_disable_data_request
//
//-----------------------------------------------------------------------------
void
_SI32_DMACTRL_A_disable_data_request(
   SI32_DMACTRL_A_Type * basePointer,
   uint32_t channel_number)
{
   assert(channel_number < 16);   // channel_number < 2^4
   //{{
   basePointer->CHREQMSET.U32 = (1 << channel_number);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_read_chen
//
// Read CHEN register.
//-----------------------------------------------------------------------------
uwide16_t
_SI32_DMACTRL_A_read_chen(
   SI32_DMACTRL_A_Type * basePointer)
{
   //{{
   return basePointer->CHENSET.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_write_chen
//
// Write to CHEN register.
//-----------------------------------------------------------------------------
void
_SI32_DMACTRL_A_write_chen(
   SI32_DMACTRL_A_Type * basePointer,
   uint32_t chen)
{
   //{{
   basePointer->CHENCLR.U32 = 0xFFFFFFFF;
   basePointer->CHENSET.U32 = chen;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_is_channel_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_DMACTRL_A_is_channel_enabled(
   SI32_DMACTRL_A_Type * basePointer,
   uint32_t channel_number)
{
   assert(channel_number < 16);   // channel_number < 2^4
   //{{
   return (bool)((basePointer->CHENSET.U32 >> channel_number) & 0x1);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_enable_channel
//
//-----------------------------------------------------------------------------
void
_SI32_DMACTRL_A_enable_channel(
   SI32_DMACTRL_A_Type * basePointer,
   uint32_t channel_number)
{
   assert(channel_number < 16);   // channel_number < 2^4
   //{{
   basePointer->CHENSET.U32 = (1 << channel_number);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_disable_channel
//
//-----------------------------------------------------------------------------
void
_SI32_DMACTRL_A_disable_channel(
   SI32_DMACTRL_A_Type * basePointer,
   uint32_t channel_number)
{
   assert(channel_number < 16);   // channel_number < 2^4
   //{{
   basePointer->CHENCLR.U32 = (1 << channel_number);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_read_chalt
//
// Read CHALT registe.
//-----------------------------------------------------------------------------
uwide16_t
_SI32_DMACTRL_A_read_chalt(
   SI32_DMACTRL_A_Type * basePointer)
{
   //{{
   return basePointer->CHALTSET.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_write_chalt
//
// Write to CHALT register.
//-----------------------------------------------------------------------------
void
_SI32_DMACTRL_A_write_chalt(
   SI32_DMACTRL_A_Type * basePointer,
   uint32_t chalt)
{
   //{{
   basePointer->CHALTCLR.U32 = 0xFFFFFFFF;
   basePointer->CHALTSET.U32 = chalt;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_is_primary_selected
//
//-----------------------------------------------------------------------------
bool
_SI32_DMACTRL_A_is_primary_selected(
   SI32_DMACTRL_A_Type * basePointer,
   uint32_t channel_number)
{
   assert(channel_number < 16);   // channel_number < 2^4
   //{{
   return !(bool)((basePointer->CHALTSET.U32 >> channel_number) & 0x1);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_select_alternate_data_structure
//
//-----------------------------------------------------------------------------
void
_SI32_DMACTRL_A_select_alternate_data_structure(
   SI32_DMACTRL_A_Type * basePointer,
   uint32_t channel_number)
{
   assert(channel_number < 16);   // channel_number < 2^4
   //{{
   basePointer->CHALTSET.U32 = (1 << channel_number);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_select_primary_data_structure
//
//-----------------------------------------------------------------------------
void
_SI32_DMACTRL_A_select_primary_data_structure(
   SI32_DMACTRL_A_Type * basePointer,
   uint32_t channel_number)
{
   assert(channel_number < 16);   // channel_number < 2^4
   //{{
   basePointer->CHALTCLR.U32 = (1 << channel_number);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_read_chhp
//
// Read CHHP register.
//-----------------------------------------------------------------------------
uwide16_t
_SI32_DMACTRL_A_read_chhp(
   SI32_DMACTRL_A_Type * basePointer)
{
   //{{
   return basePointer->CHHPSET.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_write_chhp
//
// Write to CHHP register.
//-----------------------------------------------------------------------------
void
_SI32_DMACTRL_A_write_chhp(
   SI32_DMACTRL_A_Type * basePointer,
   uint32_t chhp)
{
   //{{
   basePointer->CHHPCLR.U32 = 0xFFFFFFFF;
   basePointer->CHHPSET.U32 = chhp;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_select_channel_high_priority
//
//-----------------------------------------------------------------------------
void
_SI32_DMACTRL_A_select_channel_high_priority(
   SI32_DMACTRL_A_Type * basePointer,
   uint32_t channel_number)
{
   assert(channel_number < 16);   // channel_number < 2^4
   //{{
   basePointer->CHHPSET.U32 = (1 << channel_number);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_select_channel_default_priority
//
//-----------------------------------------------------------------------------
void
_SI32_DMACTRL_A_select_channel_default_priority(
   SI32_DMACTRL_A_Type * basePointer,
   uint32_t channel_number)
{
   assert(channel_number < 16);   // channel_number < 2^4
   //{{
   basePointer->CHHPCLR.U32 = (1 << channel_number);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_read_berr
//
// Read BERR register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_DMACTRL_A_read_berr(
   SI32_DMACTRL_A_Type * basePointer)
{
   //{{
   return basePointer->BERRCLR.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_write_berr
//
// Write to BERR register.
//-----------------------------------------------------------------------------
void
_SI32_DMACTRL_A_write_berr(
   SI32_DMACTRL_A_Type * basePointer,
   uint32_t berr)
{
   //{{
   basePointer->BERRCLR.U32 = berr;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_clear_bus_error
//
//-----------------------------------------------------------------------------
void
_SI32_DMACTRL_A_clear_bus_error(
   SI32_DMACTRL_A_Type * basePointer)
{
   //{{
   basePointer->BERRCLR.ERROR = SI32_DMACTRL_A_BERRCLR_ERROR_CLEAR_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DMACTRL_A_is_bus_error_set
//
//-----------------------------------------------------------------------------
bool
_SI32_DMACTRL_A_is_bus_error_set(
   SI32_DMACTRL_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->BERRCLR.ERROR);
   //}}
}


//-eof--------------------------------------------------------------------------
