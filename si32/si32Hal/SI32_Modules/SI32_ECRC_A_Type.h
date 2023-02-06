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
/// @file SI32_ECRC_A_Type.h
//
// Script: 0.58
// HAL Source: 0.1
// Version: 1

#ifndef __SI32_ECRC_A_TYPE_H__
#define __SI32_ECRC_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_ECRC_A_Registers.h"

// support definitions
#include "SI32_ECRC_A_Support.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_ECRC_A_initialize(SI32_ECRC_A_Type* basePointer,
///      uint32_t control,
///      uint32_t poly,
///      uint32_t scontrol)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///  Write to the CONTROL register.
///
/// @param[in]
///  poly
///  Valid range is 32 bits.
///  Write to the POLY register.
///
/// @param[in]
///  scontrol
///  Valid range is 32 bits.
///  Write to the SCONTROL register.
///
void
_SI32_ECRC_A_initialize(SI32_ECRC_A_Type* /*basePointer*/,
   uint32_t, /*control*/
   uint32_t, /*poly*/
   uint32_t /*scontrol*/);
///
/// @def SI32_ECRC_A_initialize(basePointer, control, poly, scontrol)
#define SI32_ECRC_A_initialize(basePointer, control, poly, scontrol) do{  \
   basePointer->CONTROL.U32 = control;\
   basePointer->POLY.U32 = poly;\
   basePointer->SCONTROL.U32 = scontrol;\
} while(0)


/// @fn _SI32_ECRC_A_write_control(SI32_ECRC_A_Type* basePointer,
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
_SI32_ECRC_A_write_control(SI32_ECRC_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_ECRC_A_write_control(basePointer, control)
#define SI32_ECRC_A_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_ECRC_A_read_control(SI32_ECRC_A_Type* basePointer)
///
/// @return
///  Read CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ECRC_A_read_control(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_read_control(basePointer)
#define SI32_ECRC_A_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_ECRC_A_initialize_seed_to_zero(SI32_ECRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ECRC_A_initialize_seed_to_zero(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_initialize_seed_to_zero(basePointer)
#define SI32_ECRC_A_initialize_seed_to_zero(basePointer) \
   (basePointer->CONTROL_SET = SI32_ECRC_A_CONTROL_SINITEN_MASK)


/// @fn _SI32_ECRC_A_initialize_seed_to_one(SI32_ECRC_A_Type* basePointer)
///
/// @brief
/// Initializes the DATA register to 0xFFFFFFFF.
///
/// @param[in]
///  basePointer
///
void
_SI32_ECRC_A_initialize_seed_to_one(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_initialize_seed_to_one(basePointer)
#define SI32_ECRC_A_initialize_seed_to_one(basePointer) do{  \
   basePointer->CONTROL_SET = SI32_ECRC_A_CONTROL_SEED_ALL_ONES_U32\
                              | SI32_ECRC_A_CONTROL_SINITEN_MASK;\
} while(0)


/// @fn _SI32_ECRC_A_enable_module(SI32_ECRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ECRC_A_enable_module(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_enable_module(basePointer)
#define SI32_ECRC_A_enable_module(basePointer) \
   (basePointer->CONTROL_SET = SI32_ECRC_A_CONTROL_CRCEN_MASK)


/// @fn _SI32_ECRC_A_disable_module(SI32_ECRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ECRC_A_disable_module(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_disable_module(basePointer)
#define SI32_ECRC_A_disable_module(basePointer) \
   (basePointer->CONTROL_CLR = SI32_ECRC_A_CONTROL_CRCEN_MASK)


/// @fn _SI32_ECRC_A_select_polynomial_fixed_32_bit(SI32_ECRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ECRC_A_select_polynomial_fixed_32_bit(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_select_polynomial_fixed_32_bit(basePointer)
#define SI32_ECRC_A_select_polynomial_fixed_32_bit(basePointer) \
   (basePointer->CONTROL_CLR = SI32_ECRC_A_CONTROL_POLYSEL_MASK)


/// @fn _SI32_ECRC_A_select_polynomial_programmable_16_bit(SI32_ECRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ECRC_A_select_polynomial_programmable_16_bit(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_select_polynomial_programmable_16_bit(basePointer)
#define SI32_ECRC_A_select_polynomial_programmable_16_bit(basePointer) \
   (basePointer->CONTROL_SET = SI32_ECRC_A_CONTROL_POLYSEL_MASK)


/// @fn _SI32_ECRC_A_select_byte_mode(SI32_ECRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ECRC_A_select_byte_mode(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_select_byte_mode(basePointer)
#define SI32_ECRC_A_select_byte_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_ECRC_A_CONTROL_BMDEN_MASK)


/// @fn _SI32_ECRC_A_select_word_mode(SI32_ECRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ECRC_A_select_word_mode(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_select_word_mode(basePointer)
#define SI32_ECRC_A_select_word_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_ECRC_A_CONTROL_BMDEN_MASK)


/// @fn _SI32_ECRC_A_enable_bit_reversal(SI32_ECRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ECRC_A_enable_bit_reversal(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_enable_bit_reversal(basePointer)
#define SI32_ECRC_A_enable_bit_reversal(basePointer) \
   (basePointer->CONTROL_SET = SI32_ECRC_A_CONTROL_BBREN_MASK)


/// @fn _SI32_ECRC_A_disable_bit_reversal(SI32_ECRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ECRC_A_disable_bit_reversal(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_disable_bit_reversal(basePointer)
#define SI32_ECRC_A_disable_bit_reversal(basePointer) \
   (basePointer->CONTROL_CLR = SI32_ECRC_A_CONTROL_BBREN_MASK)


/// @fn _SI32_ECRC_A_set_processing_order(SI32_ECRC_A_Type* basePointer,
///      SI32_ECRC_A_PROCESSING_ORDER_Enum_Type order)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  order
///  0 = no byte reorientation, 1 = 16-bit big endian order (input: B3 B2
///  B1 B0, output: B2 B3 B0 B1), 2 = 32-bit big endian order (input: B3 B2
///  B1 B0, output: B0 B1 B2 B3), 3 = reserved.
///
void
_SI32_ECRC_A_set_processing_order(SI32_ECRC_A_Type* /*basePointer*/,
   SI32_ECRC_A_PROCESSING_ORDER_Enum_Type /*order*/);
///
/// @def SI32_ECRC_A_set_processing_order(basePointer, order)
#define SI32_ECRC_A_set_processing_order(basePointer, order) \
   _SI32_ECRC_A_set_processing_order(basePointer, order)


/// @fn _SI32_ECRC_A_get_processing_order(SI32_ECRC_A_Type* basePointer)
///
/// @return
///  0 = no byte reorientation, 1 = 16-bit big endian order (input: B3 B2
///  B1 B0, output: B2 B3 B0 B1), 2 = 32-bit big endian order (input: B3 B2
///  B1 B0, output: B0 B1 B2 B3), 3 = reserved.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ECRC_A_get_processing_order(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_get_processing_order(basePointer)
#define SI32_ECRC_A_get_processing_order(basePointer) \
(basePointer->CONTROL.ORDER)


/// @fn _SI32_ECRC_A_enable_autoseed(SI32_ECRC_A_Type* basePointer)
///
/// @brief
/// Reading the DATA register will result in re-seeding the CRC. The re-
/// seed value depends on the seed and automatic seed byte settings.
///
/// @param[in]
///  basePointer
///
void
_SI32_ECRC_A_enable_autoseed(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_enable_autoseed(basePointer)
#define SI32_ECRC_A_enable_autoseed(basePointer) \
   (basePointer->CONTROL_SET = SI32_ECRC_A_CONTROL_ASEEDEN_ENABLED_U32)


/// @fn _SI32_ECRC_A_disable_autoseed(SI32_ECRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ECRC_A_disable_autoseed(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_disable_autoseed(basePointer)
#define SI32_ECRC_A_disable_autoseed(basePointer) \
   (basePointer->CONTROL_CLR = SI32_ECRC_A_CONTROL_ASEEDEN_MASK)


/// @fn _SI32_ECRC_A_select_autoseed_after_reading_lsb_mode(SI32_ECRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ECRC_A_select_autoseed_after_reading_lsb_mode(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_select_autoseed_after_reading_lsb_mode(basePointer)
#define SI32_ECRC_A_select_autoseed_after_reading_lsb_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_ECRC_A_CONTROL_ASEEDSEL_MASK)


/// @fn _SI32_ECRC_A_select_autoseed_after_reading_msb_mode(SI32_ECRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ECRC_A_select_autoseed_after_reading_msb_mode(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_select_autoseed_after_reading_msb_mode(basePointer)
#define SI32_ECRC_A_select_autoseed_after_reading_msb_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_ECRC_A_CONTROL_ASEEDSEL_MSB_READ_U32)


/// @fn _SI32_ECRC_A_write_poly(SI32_ECRC_A_Type* basePointer,
///      uint32_t poly)
///
/// @brief
/// Write to POLY register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  poly
///  Valid range is 32 bits.
///
void
_SI32_ECRC_A_write_poly(SI32_ECRC_A_Type* /*basePointer*/,
   uint32_t /*poly*/);
///
/// @def SI32_ECRC_A_write_poly(basePointer, poly)
#define SI32_ECRC_A_write_poly(basePointer, poly) \
   (basePointer->POLY.U32 = poly)


/// @fn _SI32_ECRC_A_read_poly(SI32_ECRC_A_Type* basePointer)
///
/// @brief
/// Read POLY register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ECRC_A_read_poly(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_read_poly(basePointer)
#define SI32_ECRC_A_read_poly(basePointer) \
(basePointer->POLY.U32)


/// @fn _SI32_ECRC_A_write_data(SI32_ECRC_A_Type* basePointer,
///      uint32_t data)
///
/// @brief
/// Write to DATA register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  data
///  Valid range is 32 bits.
///
void
_SI32_ECRC_A_write_data(SI32_ECRC_A_Type* /*basePointer*/,
   uint32_t /*data*/);
///
/// @def SI32_ECRC_A_write_data(basePointer, data)
#define SI32_ECRC_A_write_data(basePointer, data) \
   (basePointer->DATA.U32 = data)


/// @fn _SI32_ECRC_A_read_result(SI32_ECRC_A_Type* basePointer)
///
/// @brief
/// Read DATA register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ECRC_A_read_result(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_read_result(basePointer)
#define SI32_ECRC_A_read_result(basePointer) \
(basePointer->DATA.U32)


/// @fn _SI32_ECRC_A_read_bit_reversed_result(SI32_ECRC_A_Type* basePointer)
///
/// @brief
/// Read RDATA register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ECRC_A_read_bit_reversed_result(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_read_bit_reversed_result(basePointer)
#define SI32_ECRC_A_read_bit_reversed_result(basePointer) \
(basePointer->RDATA.U32)


/// @fn _SI32_ECRC_A_read_byte_reversed_result(SI32_ECRC_A_Type* basePointer)
///
/// @brief
/// Read BRDATA register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ECRC_A_read_byte_reversed_result(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_read_byte_reversed_result(basePointer)
#define SI32_ECRC_A_read_byte_reversed_result(basePointer) \
(basePointer->BRDATA.U32)


/// @fn _SI32_ECRC_A_write_scontrol(SI32_ECRC_A_Type* basePointer,
///      uint32_t scontrol)
///
/// @brief
/// Write to SCONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  scontrol
///  Valid range is 32 bits.
///
void
_SI32_ECRC_A_write_scontrol(SI32_ECRC_A_Type* /*basePointer*/,
   uint32_t /*scontrol*/);
///
/// @def SI32_ECRC_A_write_scontrol(basePointer, scontrol)
#define SI32_ECRC_A_write_scontrol(basePointer, scontrol) \
   (basePointer->SCONTROL.U32 = scontrol)


/// @fn _SI32_ECRC_A_read_scontrol(SI32_ECRC_A_Type* basePointer)
///
/// @brief
/// Read SCONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ECRC_A_read_scontrol(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_read_scontrol(basePointer)
#define SI32_ECRC_A_read_scontrol(basePointer) \
(basePointer->SCONTROL.U32)


/// @fn _SI32_ECRC_A_enable_snooping(SI32_ECRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ECRC_A_enable_snooping(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_enable_snooping(basePointer)
#define SI32_ECRC_A_enable_snooping(basePointer) \
   (basePointer->SCONTROL_SET = SI32_ECRC_A_SCONTROL_SEN_ENABLED_U32)


/// @fn _SI32_ECRC_A_disable_snooping(SI32_ECRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ECRC_A_disable_snooping(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_disable_snooping(basePointer)
#define SI32_ECRC_A_disable_snooping(basePointer) \
   (basePointer->SCONTROL_CLR = SI32_ECRC_A_SCONTROL_SEN_MASK)


/// @fn _SI32_ECRC_A_select_snooping_reads_mode(SI32_ECRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ECRC_A_select_snooping_reads_mode(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_select_snooping_reads_mode(basePointer)
#define SI32_ECRC_A_select_snooping_reads_mode(basePointer) \
   (basePointer->SCONTROL_SET = SI32_ECRC_A_SCONTROL_SDIRSEL_READS_U32)


/// @fn _SI32_ECRC_A_select_snooping_writes_mode(SI32_ECRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ECRC_A_select_snooping_writes_mode(SI32_ECRC_A_Type* /*basePointer*/);
///
/// @def SI32_ECRC_A_select_snooping_writes_mode(basePointer)
#define SI32_ECRC_A_select_snooping_writes_mode(basePointer) \
   (basePointer->SCONTROL_CLR = SI32_ECRC_A_SCONTROL_SDIRSEL_MASK)


/// @fn _SI32_ECRC_A_select_snooping_peripheral(SI32_ECRC_A_Type* basePointer,
///      SI32_ECRC_A_DEVICE_PERIPHERAL_Enum_Type speripheral)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  speripheral
///
void
_SI32_ECRC_A_select_snooping_peripheral(SI32_ECRC_A_Type* /*basePointer*/,
   SI32_ECRC_A_DEVICE_PERIPHERAL_Enum_Type /*speripheral*/);
///
/// @def SI32_ECRC_A_select_snooping_peripheral(basePointer, speripheral)
#define SI32_ECRC_A_select_snooping_peripheral(basePointer, speripheral) do{  \
   basePointer->SCONTROL_CLR = SI32_ECRC_A_SCONTROL_SPERISEL_MASK;\
   basePointer->SCONTROL_SET = speripheral << SI32_ECRC_A_SCONTROL_SPERISEL_SHIFT;\
} while(0)


/// @fn _SI32_ECRC_A_select_snooping_address(SI32_ECRC_A_Type* basePointer,
///      uint32_t saddress)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  saddress
///  Valid range is 10 bits.
///
void
_SI32_ECRC_A_select_snooping_address(SI32_ECRC_A_Type* /*basePointer*/,
   uint32_t /*saddress*/);
///
/// @def SI32_ECRC_A_select_snooping_address(basePointer, saddress)
#define SI32_ECRC_A_select_snooping_address(basePointer, saddress) \
   (basePointer->SCONTROL.SADDR = saddress)



#ifdef __cplusplus
}
#endif

#endif // __SI32_ECRC_A_TYPE_H__

//-eof--------------------------------------------------------------------------
