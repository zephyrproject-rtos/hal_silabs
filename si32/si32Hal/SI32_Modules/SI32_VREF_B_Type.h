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
/// @file SI32_VREF_B_Type.h
//
// Script: 0.61
// HAL Source: 0.1
// Version: 1

#ifndef __SI32_VREF_B_TYPE_H__
#define __SI32_VREF_B_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_VREF_B_Registers.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_VREF_B_initialize(SI32_VREF_B_Type* basePointer,
///      uint32_t control)
///
/// @brief
/// Writes all VREF registers.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///
void
_SI32_VREF_B_initialize(SI32_VREF_B_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_VREF_B_initialize(basePointer, control)
#define SI32_VREF_B_initialize(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_VREF_B_write_control(SI32_VREF_B_Type* basePointer,
///      uint32_t control)
///
/// @brief
/// Writes CONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///
void
_SI32_VREF_B_write_control(SI32_VREF_B_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_VREF_B_write_control(basePointer, control)
#define SI32_VREF_B_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_VREF_B_read_control(SI32_VREF_B_Type* basePointer)
///
/// @brief
/// Reads CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_VREF_B_read_control(SI32_VREF_B_Type* /*basePointer*/);
///
/// @def SI32_VREF_B_read_control(basePointer)
#define SI32_VREF_B_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_VREF_B_select_1p2_volts(SI32_VREF_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_VREF_B_select_1p2_volts(SI32_VREF_B_Type* /*basePointer*/);
///
/// @def SI32_VREF_B_select_1p2_volts(basePointer)
#define SI32_VREF_B_select_1p2_volts(basePointer) \
   (basePointer->CONTROL_CLR = SI32_VREF_B_CONTROL_VREF2X_MASK)


/// @fn _SI32_VREF_B_select_2p4_volts(SI32_VREF_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_VREF_B_select_2p4_volts(SI32_VREF_B_Type* /*basePointer*/);
///
/// @def SI32_VREF_B_select_2p4_volts(basePointer)
#define SI32_VREF_B_select_2p4_volts(basePointer) \
   (basePointer->CONTROL_SET = SI32_VREF_B_CONTROL_VREF2X_MASK)


/// @fn _SI32_VREF_B_enable_temperature_sensor(SI32_VREF_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_VREF_B_enable_temperature_sensor(SI32_VREF_B_Type* /*basePointer*/);
///
/// @def SI32_VREF_B_enable_temperature_sensor(basePointer)
#define SI32_VREF_B_enable_temperature_sensor(basePointer) \
   (basePointer->CONTROL_SET = SI32_VREF_B_CONTROL_TEMPEN_MASK)


/// @fn _SI32_VREF_B_disable_temperature_sensor(SI32_VREF_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_VREF_B_disable_temperature_sensor(SI32_VREF_B_Type* /*basePointer*/);
///
/// @def SI32_VREF_B_disable_temperature_sensor(basePointer)
#define SI32_VREF_B_disable_temperature_sensor(basePointer) \
   (basePointer->CONTROL_CLR = SI32_VREF_B_CONTROL_TEMPEN_MASK)


/// @fn _SI32_VREF_B_enable_voltage_reference(SI32_VREF_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_VREF_B_enable_voltage_reference(SI32_VREF_B_Type* /*basePointer*/);
///
/// @def SI32_VREF_B_enable_voltage_reference(basePointer)
#define SI32_VREF_B_enable_voltage_reference(basePointer) \
   (basePointer->CONTROL_SET = SI32_VREF_B_CONTROL_VREFOUTEN_MASK)


/// @fn _SI32_VREF_B_disable_voltage_reference(SI32_VREF_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_VREF_B_disable_voltage_reference(SI32_VREF_B_Type* /*basePointer*/);
///
/// @def SI32_VREF_B_disable_voltage_reference(basePointer)
#define SI32_VREF_B_disable_voltage_reference(basePointer) \
   (basePointer->CONTROL_CLR = SI32_VREF_B_CONTROL_VREFOUTEN_MASK)



#ifdef __cplusplus
}
#endif

#endif // __SI32_VREF_B_TYPE_H__

//-eof--------------------------------------------------------------------------
