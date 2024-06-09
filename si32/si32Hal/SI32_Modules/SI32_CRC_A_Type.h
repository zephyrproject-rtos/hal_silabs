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
/// @file SI32_CRC_A_Type.h
//
// Script: 0.58
// HAL Source: 0.3
// Version: 1

#ifndef __SI32_CRC_A_TYPE_H__
#define __SI32_CRC_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_CRC_A_Registers.h"

// support defeinitions
#include "SI32_CRC_A_Support.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_CRC_A_initialize(SI32_CRC_A_Type* basePointer,
///      uint32_t control)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///  Write to the CONTROL register.
///
void
_SI32_CRC_A_initialize(SI32_CRC_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_CRC_A_initialize(basePointer, control)
#define SI32_CRC_A_initialize(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_CRC_A_write_control(SI32_CRC_A_Type* basePointer,
///      uint32_t control)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///  Write to CONTROL register.
///
void
_SI32_CRC_A_write_control(SI32_CRC_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_CRC_A_write_control(basePointer, control)
#define SI32_CRC_A_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_CRC_A_read_control(SI32_CRC_A_Type* basePointer)
///
/// @return
///  Read CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_CRC_A_read_control(SI32_CRC_A_Type* /*basePointer*/);
///
/// @def SI32_CRC_A_read_control(basePointer)
#define SI32_CRC_A_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_CRC_A_initialize_seed_to_zero(SI32_CRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CRC_A_initialize_seed_to_zero(SI32_CRC_A_Type* /*basePointer*/);
///
/// @def SI32_CRC_A_initialize_seed_to_zero(basePointer)
#define SI32_CRC_A_initialize_seed_to_zero(basePointer) \
   (basePointer->CONTROL_SET = SI32_CRC_A_CONTROL_SINITEN_MASK)


/// @fn _SI32_CRC_A_initialize_seed_to_one(SI32_CRC_A_Type* basePointer)
///
/// @brief
/// Initializes the DATA register to 0xFFFFFFFF.
///
/// @param[in]
///  basePointer
///
void
_SI32_CRC_A_initialize_seed_to_one(SI32_CRC_A_Type* /*basePointer*/);
///
/// @def SI32_CRC_A_initialize_seed_to_one(basePointer)
#define SI32_CRC_A_initialize_seed_to_one(basePointer) do{  \
   basePointer->CONTROL_SET = SI32_CRC_A_CONTROL_SEED_ALL_ONES_U32\
                              | SI32_CRC_A_CONTROL_SINITEN_MASK;\
} while(0)


/// @fn _SI32_CRC_A_enable_module(SI32_CRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CRC_A_enable_module(SI32_CRC_A_Type* /*basePointer*/);
///
/// @def SI32_CRC_A_enable_module(basePointer)
#define SI32_CRC_A_enable_module(basePointer) \
   (basePointer->CONTROL_SET = SI32_CRC_A_CONTROL_CRCEN_MASK)


/// @fn _SI32_CRC_A_disable_module(SI32_CRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CRC_A_disable_module(SI32_CRC_A_Type* /*basePointer*/);
///
/// @def SI32_CRC_A_disable_module(basePointer)
#define SI32_CRC_A_disable_module(basePointer) \
   (basePointer->CONTROL_CLR = SI32_CRC_A_CONTROL_CRCEN_MASK)


/// @fn _SI32_CRC_A_select_polynomial_32_bit_04C11DB7(SI32_CRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CRC_A_select_polynomial_32_bit_04C11DB7(SI32_CRC_A_Type* /*basePointer*/);
///
/// @def SI32_CRC_A_select_polynomial_32_bit_04C11DB7(basePointer)
#define SI32_CRC_A_select_polynomial_32_bit_04C11DB7(basePointer) \
   (basePointer->CONTROL_CLR = SI32_CRC_A_CONTROL_POLYSEL_MASK)


/// @fn _SI32_CRC_A_select_polynomial_16_bit_1021(SI32_CRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CRC_A_select_polynomial_16_bit_1021(SI32_CRC_A_Type* /*basePointer*/);
///
/// @def SI32_CRC_A_select_polynomial_16_bit_1021(basePointer)
#define SI32_CRC_A_select_polynomial_16_bit_1021(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_CRC_A_CONTROL_POLYSEL_MASK;\
   basePointer->CONTROL_SET = SI32_CRC_A_CONTROL_POLYSEL_CRC_16_1021_U32;\
} while(0)


/// @fn _SI32_CRC_A_select_polynomial_16_bit_3D65(SI32_CRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CRC_A_select_polynomial_16_bit_3D65(SI32_CRC_A_Type* /*basePointer*/);
///
/// @def SI32_CRC_A_select_polynomial_16_bit_3D65(basePointer)
#define SI32_CRC_A_select_polynomial_16_bit_3D65(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_CRC_A_CONTROL_POLYSEL_MASK;\
   basePointer->CONTROL_SET = SI32_CRC_A_CONTROL_POLYSEL_CRC_16_3D65_U32;\
} while(0)


/// @fn _SI32_CRC_A_select_polynomial_16_bit_8005(SI32_CRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CRC_A_select_polynomial_16_bit_8005(SI32_CRC_A_Type* /*basePointer*/);
///
/// @def SI32_CRC_A_select_polynomial_16_bit_8005(basePointer)
#define SI32_CRC_A_select_polynomial_16_bit_8005(basePointer) \
   (basePointer->CONTROL_SET = SI32_CRC_A_CONTROL_POLYSEL_CRC_16_8005_U32)


/// @fn _SI32_CRC_A_get_polynomial(SI32_CRC_A_Type* basePointer)
///
/// @return
///  0 = 32-bit polynomial (0x04C11DB7), 1 = 16-bit polynomial (0x1021), 2
///  = 16-bit polynomial (0x3D65), 3 = 16-bit polynomial (0x8005).
///
/// @param[in]
///  basePointer
///
SI32_CRC_A_POLYNOMIAL_Enum_Type
_SI32_CRC_A_get_polynomial(SI32_CRC_A_Type* /*basePointer*/);
///
/// @def SI32_CRC_A_get_polynomial(basePointer)
#define SI32_CRC_A_get_polynomial(basePointer) \
   _SI32_CRC_A_get_polynomial(basePointer)


/// @fn _SI32_CRC_A_select_byte_mode(SI32_CRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CRC_A_select_byte_mode(SI32_CRC_A_Type* /*basePointer*/);
///
/// @def SI32_CRC_A_select_byte_mode(basePointer)
#define SI32_CRC_A_select_byte_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_CRC_A_CONTROL_BMDEN_MASK)


/// @fn _SI32_CRC_A_select_word_mode(SI32_CRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CRC_A_select_word_mode(SI32_CRC_A_Type* /*basePointer*/);
///
/// @def SI32_CRC_A_select_word_mode(basePointer)
#define SI32_CRC_A_select_word_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_CRC_A_CONTROL_BMDEN_MASK)


/// @fn _SI32_CRC_A_enable_bit_reversal(SI32_CRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CRC_A_enable_bit_reversal(SI32_CRC_A_Type* /*basePointer*/);
///
/// @def SI32_CRC_A_enable_bit_reversal(basePointer)
#define SI32_CRC_A_enable_bit_reversal(basePointer) \
   (basePointer->CONTROL_SET = SI32_CRC_A_CONTROL_BBREN_MASK)


/// @fn _SI32_CRC_A_disable_bit_reversal(SI32_CRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CRC_A_disable_bit_reversal(SI32_CRC_A_Type* /*basePointer*/);
///
/// @def SI32_CRC_A_disable_bit_reversal(basePointer)
#define SI32_CRC_A_disable_bit_reversal(basePointer) \
   (basePointer->CONTROL_CLR = SI32_CRC_A_CONTROL_BBREN_MASK)


/// @fn _SI32_CRC_A_set_processing_order(SI32_CRC_A_Type* basePointer,
///      SI32_CRC_A_PROCESSING_ORDER_Enum_Type order)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  order
///  Valid range is 2 bits.
///  0 = no byte reorientation, 1 = 16-bit big endian order (input: B3 B2
///  B1 B0, output: B2 B3 B0 B1), 2 = 32-bit big endian order (input: B3 B2
///  B1 B0, output: B0 B1 B2 B3), 3 = reserved.
///
void
_SI32_CRC_A_set_processing_order(SI32_CRC_A_Type* /*basePointer*/,
   SI32_CRC_A_PROCESSING_ORDER_Enum_Type /*order*/);
///
/// @def SI32_CRC_A_set_processing_order(basePointer, order)
#define SI32_CRC_A_set_processing_order(basePointer, order) do{  \
   basePointer->CONTROL_CLR = SI32_CRC_A_CONTROL_ORDER_MASK;\
   basePointer->CONTROL_SET = order << SI32_CRC_A_CONTROL_ORDER_SHIFT;\
} while(0)


/// @fn _SI32_CRC_A_get_processing_order(SI32_CRC_A_Type* basePointer)
///
/// @return
///  0 = no byte reorientation, 1 = 16-bit big endian order (input: B3 B2
///  B1 B0, output: B2 B3 B0 B1), 2 = 32-bit big endian order (input: B3 B2
///  B1 B0, output: B0 B1 B2 B3), 3 = reserved.
///
/// @param[in]
///  basePointer
///
SI32_CRC_A_PROCESSING_ORDER_Enum_Type
_SI32_CRC_A_get_processing_order(SI32_CRC_A_Type* /*basePointer*/);
///
/// @def SI32_CRC_A_get_processing_order(basePointer)
#define SI32_CRC_A_get_processing_order(basePointer) \
   _SI32_CRC_A_get_processing_order(basePointer)


/// @fn _SI32_CRC_A_write_data(SI32_CRC_A_Type* basePointer,
///      uint32_t crcin)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  crcin
///  Valid range is 32 bits.
///
void
_SI32_CRC_A_write_data(SI32_CRC_A_Type* /*basePointer*/,
   uint32_t /*crcin*/);
///
/// @def SI32_CRC_A_write_data(basePointer, crcin)
#define SI32_CRC_A_write_data(basePointer, crcin) \
   (basePointer->DATA.U32 = crcin)


/// @fn _SI32_CRC_A_read_result(SI32_CRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_CRC_A_read_result(SI32_CRC_A_Type* /*basePointer*/);
///
/// @def SI32_CRC_A_read_result(basePointer)
#define SI32_CRC_A_read_result(basePointer) \
(basePointer->DATA.U32)


/// @fn _SI32_CRC_A_read_bit_reversed_result(SI32_CRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_CRC_A_read_bit_reversed_result(SI32_CRC_A_Type* /*basePointer*/);
///
/// @def SI32_CRC_A_read_bit_reversed_result(basePointer)
#define SI32_CRC_A_read_bit_reversed_result(basePointer) \
(basePointer->RDATA.U32)



#ifdef __cplusplus
}
#endif

#endif // __SI32_CRC_A_TYPE_H__

//-eof--------------------------------------------------------------------------
