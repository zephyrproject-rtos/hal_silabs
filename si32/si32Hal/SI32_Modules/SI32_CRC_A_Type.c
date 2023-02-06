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
/// @file SI32_CRC_A_Type.c
//
// Script: 0.58
// HAL Source: 0.3
// Version: 5

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_CRC_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_CRC_A_initialize
//
//-----------------------------------------------------------------------------
void
_SI32_CRC_A_initialize(
   SI32_CRC_A_Type * basePointer,
   // Write to the CONTROL register.
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CRC_A_write_control
//
//-----------------------------------------------------------------------------
void
_SI32_CRC_A_write_control(
   SI32_CRC_A_Type * basePointer,
   // Write to CONTROL register.
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CRC_A_read_control
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_CRC_A_read_control(
   SI32_CRC_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CRC_A_initialize_seed_to_zero
//
//-----------------------------------------------------------------------------
void
_SI32_CRC_A_initialize_seed_to_zero(
   SI32_CRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_CRC_A_CONTROL_SINITEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CRC_A_initialize_seed_to_one
//
// Initializes the DATA register to 0xFFFFFFFF.
//-----------------------------------------------------------------------------
void
_SI32_CRC_A_initialize_seed_to_one(
   SI32_CRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_CRC_A_CONTROL_SEED_ALL_ONES_U32
                              | SI32_CRC_A_CONTROL_SINITEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CRC_A_enable_module
//
//-----------------------------------------------------------------------------
void
_SI32_CRC_A_enable_module(
   SI32_CRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_CRC_A_CONTROL_CRCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CRC_A_disable_module
//
//-----------------------------------------------------------------------------
void
_SI32_CRC_A_disable_module(
   SI32_CRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_CRC_A_CONTROL_CRCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CRC_A_select_polynomial_32_bit_04C11DB7
//
//-----------------------------------------------------------------------------
void
_SI32_CRC_A_select_polynomial_32_bit_04C11DB7(
   SI32_CRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_CRC_A_CONTROL_POLYSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CRC_A_select_polynomial_16_bit_1021
//
//-----------------------------------------------------------------------------
void
_SI32_CRC_A_select_polynomial_16_bit_1021(
   SI32_CRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_CRC_A_CONTROL_POLYSEL_MASK;
   basePointer->CONTROL_SET = SI32_CRC_A_CONTROL_POLYSEL_CRC_16_1021_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CRC_A_select_polynomial_16_bit_3D65
//
//-----------------------------------------------------------------------------
void
_SI32_CRC_A_select_polynomial_16_bit_3D65(
   SI32_CRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_CRC_A_CONTROL_POLYSEL_MASK;
   basePointer->CONTROL_SET = SI32_CRC_A_CONTROL_POLYSEL_CRC_16_3D65_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CRC_A_select_polynomial_16_bit_8005
//
//-----------------------------------------------------------------------------
void
_SI32_CRC_A_select_polynomial_16_bit_8005(
   SI32_CRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_CRC_A_CONTROL_POLYSEL_CRC_16_8005_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CRC_A_get_polynomial
//
//-----------------------------------------------------------------------------
SI32_CRC_A_POLYNOMIAL_Enum_Type
_SI32_CRC_A_get_polynomial(
   SI32_CRC_A_Type * basePointer)
{
   //{{
	SI32_CRC_A_POLYNOMIAL_Enum_Type result;
	switch (basePointer->CONTROL.POLYSEL)
	{
	   case SI32_CRC_A_CONTROL_POLYSEL_CRC_32_04C11DB7_VALUE:
	      result = SI32_CRC_A_POLYNOMIAL_32_BIT_04C11DB7;
	   case SI32_CRC_A_CONTROL_POLYSEL_CRC_16_1021_VALUE:
	      result = SI32_CRC_A_POLYNOMIAL_16_BIT_1021;
	   case SI32_CRC_A_CONTROL_POLYSEL_CRC_16_3D65_VALUE:
	      result = SI32_CRC_A_POLYNOMIAL_16_BIT_3D65;
	   case SI32_CRC_A_CONTROL_POLYSEL_CRC_16_8005_VALUE:
	      result = SI32_CRC_A_POLYNOMIAL_16_BIT_8005;
	}
	return result;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CRC_A_select_byte_mode
//
//-----------------------------------------------------------------------------
void
_SI32_CRC_A_select_byte_mode(
   SI32_CRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_CRC_A_CONTROL_BMDEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CRC_A_select_word_mode
//
//-----------------------------------------------------------------------------
void
_SI32_CRC_A_select_word_mode(
   SI32_CRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_CRC_A_CONTROL_BMDEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CRC_A_enable_bit_reversal
//
//-----------------------------------------------------------------------------
void
_SI32_CRC_A_enable_bit_reversal(
   SI32_CRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_CRC_A_CONTROL_BBREN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CRC_A_disable_bit_reversal
//
//-----------------------------------------------------------------------------
void
_SI32_CRC_A_disable_bit_reversal(
   SI32_CRC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_CRC_A_CONTROL_BBREN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CRC_A_set_processing_order
//
//-----------------------------------------------------------------------------
void
_SI32_CRC_A_set_processing_order(
   SI32_CRC_A_Type * basePointer,
   // 0 = no byte reorientation, 1 = 16-bit big endian order (input: B3 B2
   // B1 B0, output: B2 B3 B0 B1), 2 = 32-bit big endian order (input: B3 B2
   // B1 B0, output: B0 B1 B2 B3), 3 = reserved.
   SI32_CRC_A_PROCESSING_ORDER_Enum_Type order)
{
   assert(order < 4);   // order < 2^2
   //{{
   basePointer->CONTROL_CLR = SI32_CRC_A_CONTROL_ORDER_MASK;
   basePointer->CONTROL_SET = order << SI32_CRC_A_CONTROL_ORDER_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CRC_A_get_processing_order
//
//-----------------------------------------------------------------------------
SI32_CRC_A_PROCESSING_ORDER_Enum_Type
_SI32_CRC_A_get_processing_order(
   SI32_CRC_A_Type * basePointer)
{
   //{{
	SI32_CRC_A_PROCESSING_ORDER_Enum_Type result;
   switch (basePointer->CONTROL.ORDER)
  	{
	   case SI32_CRC_A_CONTROL_ORDER_NO_REORDER_VALUE:
	      result = SI32_CRC_A_PROCESSING_ORDER_NO_BYTE_REORIENTATION;
	   case SI32_CRC_A_CONTROL_ORDER_BIG_ENDIAN_16_VALUE:
	      result= SI32_CRC_A_PROCESSING_ORDER_16_BIT_BIG_ENDIAN;
	   case SI32_CRC_A_CONTROL_ORDER_BIG_ENDIAN_32_VALUE:
	      result = SI32_CRC_A_PROCESSING_ORDER_32_BIT_BIG_ENDIAN;
	}
	return result;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CRC_A_write_data
//
//-----------------------------------------------------------------------------
void
_SI32_CRC_A_write_data(
   SI32_CRC_A_Type * basePointer,
   uint32_t crcin)
{
   //{{
   basePointer->DATA.U32 = crcin;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CRC_A_read_result
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_CRC_A_read_result(
   SI32_CRC_A_Type * basePointer)
{
   //{{
   return basePointer->DATA.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CRC_A_read_bit_reversed_result
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_CRC_A_read_bit_reversed_result(
   SI32_CRC_A_Type * basePointer)
{
   //{{
   return basePointer->RDATA.U32;
   //}}
}


//-eof--------------------------------------------------------------------------
