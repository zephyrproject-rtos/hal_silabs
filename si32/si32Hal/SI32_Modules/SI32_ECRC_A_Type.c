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
/// @file SI32_ECRC_A_Type.c
//
// Script: 0.58
// HAL Source: 0.1
// Version: 10

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_ECRC_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_ECRC_A_initialize
//
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_initialize(
   SI32_ECRC_A_Type * basePointer,
   // Write to the CONTROL register.
   uint32_t control,
   // Write to the POLY register.
   uint32_t poly,
   // Write to the SCONTROL register.
   uint32_t scontrol)
{
   //{{
   basePointer->CONTROL.U32 = control;
   basePointer->POLY.U32 = poly;
   basePointer->SCONTROL.U32 = scontrol;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_write_control
//
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_write_control(
   SI32_ECRC_A_Type * basePointer,
   // Write to CONTROL register.
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_read_control
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_ECRC_A_read_control(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_initialize_seed_to_zero
//
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_initialize_seed_to_zero(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_ECRC_A_CONTROL_SINITEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_initialize_seed_to_one
//
// Initializes the DATA register to 0xFFFFFFFF.
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_initialize_seed_to_one(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_ECRC_A_CONTROL_SEED_ALL_ONES_U32
                              | SI32_ECRC_A_CONTROL_SINITEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_enable_module
//
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_enable_module(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_ECRC_A_CONTROL_CRCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_disable_module
//
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_disable_module(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_ECRC_A_CONTROL_CRCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_select_polynomial_fixed_32_bit
//
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_select_polynomial_fixed_32_bit(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_ECRC_A_CONTROL_POLYSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_select_polynomial_programmable_16_bit
//
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_select_polynomial_programmable_16_bit(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_ECRC_A_CONTROL_POLYSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_select_byte_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_select_byte_mode(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_ECRC_A_CONTROL_BMDEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_select_word_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_select_word_mode(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_ECRC_A_CONTROL_BMDEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_enable_bit_reversal
//
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_enable_bit_reversal(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_ECRC_A_CONTROL_BBREN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_disable_bit_reversal
//
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_disable_bit_reversal(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_ECRC_A_CONTROL_BBREN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_set_processing_order
//
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_set_processing_order(
   SI32_ECRC_A_Type * basePointer,
   // 0 = no byte reorientation, 1 = 16-bit big endian order (input: B3 B2
   // B1 B0, output: B2 B3 B0 B1), 2 = 32-bit big endian order (input: B3 B2
   // B1 B0, output: B0 B1 B2 B3), 3 = reserved.
   SI32_ECRC_A_PROCESSING_ORDER_Enum_Type order)
{
   //{{
   switch (order)
   {
      case 0:
         basePointer->CONTROL_CLR = SI32_ECRC_A_CONTROL_ORDER_MASK
                                 | SI32_ECRC_A_CONTROL_ORDER_NO_REORDER_U32;
         break;
      case 1:
         basePointer->CONTROL_CLR = SI32_ECRC_A_CONTROL_ORDER_MASK;
         basePointer->CONTROL_SET = SI32_ECRC_A_CONTROL_ORDER_BIG_ENDIAN_16_U32;
         break;
      case 2:
         basePointer->CONTROL_CLR = SI32_ECRC_A_CONTROL_ORDER_MASK;
         basePointer->CONTROL_SET = SI32_ECRC_A_CONTROL_ORDER_BIG_ENDIAN_32_U32;
         break;
      default:
         break;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_get_processing_order
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_ECRC_A_get_processing_order(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.ORDER;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_enable_autoseed
//
// Reading the DATA register will result in re-seeding the CRC. The re-
// seed value depends on the seed and automatic seed byte settings.
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_enable_autoseed(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_ECRC_A_CONTROL_ASEEDEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_disable_autoseed
//
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_disable_autoseed(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_ECRC_A_CONTROL_ASEEDEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_select_autoseed_after_reading_lsb_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_select_autoseed_after_reading_lsb_mode(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_ECRC_A_CONTROL_ASEEDSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_select_autoseed_after_reading_msb_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_select_autoseed_after_reading_msb_mode(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_ECRC_A_CONTROL_ASEEDSEL_MSB_READ_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_write_poly
//
// Write to POLY register.
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_write_poly(
   SI32_ECRC_A_Type * basePointer,
   uint32_t poly)
{
   //{{
   basePointer->POLY.U32 = poly;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_read_poly
//
// Read POLY register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_ECRC_A_read_poly(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   return basePointer->POLY.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_write_data
//
// Write to DATA register.
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_write_data(
   SI32_ECRC_A_Type * basePointer,
   uint32_t data)
{
   //{{
   basePointer->DATA.U32 = data;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_read_result
//
// Read DATA register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_ECRC_A_read_result(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   return basePointer->DATA.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_read_bit_reversed_result
//
// Read RDATA register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_ECRC_A_read_bit_reversed_result(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   return basePointer->RDATA.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_read_byte_reversed_result
//
// Read BRDATA register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_ECRC_A_read_byte_reversed_result(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   return basePointer->BRDATA.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_write_scontrol
//
// Write to SCONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_write_scontrol(
   SI32_ECRC_A_Type * basePointer,
   uint32_t scontrol)
{
   //{{
   basePointer->SCONTROL.U32 = scontrol;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_read_scontrol
//
// Read SCONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_ECRC_A_read_scontrol(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   return basePointer->SCONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_enable_snooping
//
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_enable_snooping(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   basePointer->SCONTROL_SET = SI32_ECRC_A_SCONTROL_SEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_disable_snooping
//
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_disable_snooping(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   basePointer->SCONTROL_CLR = SI32_ECRC_A_SCONTROL_SEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_select_snooping_reads_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_select_snooping_reads_mode(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   basePointer->SCONTROL_SET = SI32_ECRC_A_SCONTROL_SDIRSEL_READS_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_select_snooping_writes_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_select_snooping_writes_mode(
   SI32_ECRC_A_Type * basePointer)
{
   //{{
   basePointer->SCONTROL_CLR = SI32_ECRC_A_SCONTROL_SDIRSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_select_snooping_peripheral
//
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_select_snooping_peripheral(
   SI32_ECRC_A_Type * basePointer,
   SI32_ECRC_A_DEVICE_PERIPHERAL_Enum_Type speripheral)
{
   //{{
   basePointer->SCONTROL_CLR = SI32_ECRC_A_SCONTROL_SPERISEL_MASK;
   basePointer->SCONTROL_SET = speripheral << SI32_ECRC_A_SCONTROL_SPERISEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ECRC_A_select_snooping_address
//
//-----------------------------------------------------------------------------
void
_SI32_ECRC_A_select_snooping_address(
   SI32_ECRC_A_Type * basePointer,
   uint32_t saddress)
{
   assert(saddress < 1024);   // saddress < 2^10
   //{{
   basePointer->SCONTROL.SADDR = saddress;
   //}}
}


//-eof--------------------------------------------------------------------------
