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
/// @file SI32_VREG_A_Type.h
//
// Script: 0.58
// HAL Source: 0.3
// Version: 1

#ifndef __SI32_VREG_A_TYPE_H__
#define __SI32_VREG_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_VREG_A_Registers.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_VREG_A_initialize(SI32_VREG_A_Type* basePointer,
///      uint32_t control)
///
/// @brief
/// Writes all VREG registers.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///
void
_SI32_VREG_A_initialize(SI32_VREG_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_VREG_A_initialize(basePointer, control)
#define SI32_VREG_A_initialize(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_VREG_A_write_control(SI32_VREG_A_Type* basePointer,
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
_SI32_VREG_A_write_control(SI32_VREG_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_VREG_A_write_control(basePointer, control)
#define SI32_VREG_A_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_VREG_A_read_control(SI32_VREG_A_Type* basePointer)
///
/// @brief
/// Reads CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_VREG_A_read_control(SI32_VREG_A_Type* /*basePointer*/);
///
/// @def SI32_VREG_A_read_control(basePointer)
#define SI32_VREG_A_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_VREG_A_is_vbus_valid(SI32_VREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_VREG_A_is_vbus_valid(SI32_VREG_A_Type* /*basePointer*/);
///
/// @def SI32_VREG_A_is_vbus_valid(basePointer)
#define SI32_VREG_A_is_vbus_valid(basePointer) \
(basePointer->CONTROL.VBUSVLDF)


/// @fn _SI32_VREG_A_enter_suspend_mode(SI32_VREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_VREG_A_enter_suspend_mode(SI32_VREG_A_Type* /*basePointer*/);
///
/// @def SI32_VREG_A_enter_suspend_mode(basePointer)
#define SI32_VREG_A_enter_suspend_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_VREG_A_CONTROL_SUSEN_ENABLED_U32)


/// @fn _SI32_VREG_A_exit_suspend_mode(SI32_VREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_VREG_A_exit_suspend_mode(SI32_VREG_A_Type* /*basePointer*/);
///
/// @def SI32_VREG_A_exit_suspend_mode(basePointer)
#define SI32_VREG_A_exit_suspend_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_VREG_A_CONTROL_SUSEN_MASK)


/// @fn _SI32_VREG_A_enable_band_gap(SI32_VREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_VREG_A_enable_band_gap(SI32_VREG_A_Type* /*basePointer*/);
///
/// @def SI32_VREG_A_enable_band_gap(basePointer)
#define SI32_VREG_A_enable_band_gap(basePointer) \
   (basePointer->CONTROL_CLR = SI32_VREG_A_CONTROL_BGDIS_MASK)


/// @fn _SI32_VREG_A_disable_band_gap(SI32_VREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_VREG_A_disable_band_gap(SI32_VREG_A_Type* /*basePointer*/);
///
/// @def SI32_VREG_A_disable_band_gap(basePointer)
#define SI32_VREG_A_disable_band_gap(basePointer) \
   (basePointer->CONTROL_SET = SI32_VREG_A_CONTROL_BGDIS_ACTIVE_U32)


/// @fn _SI32_VREG_A_enable_vreg_sense(SI32_VREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_VREG_A_enable_vreg_sense(SI32_VREG_A_Type* /*basePointer*/);
///
/// @def SI32_VREG_A_enable_vreg_sense(basePointer)
#define SI32_VREG_A_enable_vreg_sense(basePointer) \
   (basePointer->CONTROL_SET = SI32_VREG_A_CONTROL_SENSEEN_ENABLED_U32)


/// @fn _SI32_VREG_A_disable_vreg_sense(SI32_VREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_VREG_A_disable_vreg_sense(SI32_VREG_A_Type* /*basePointer*/);
///
/// @def SI32_VREG_A_disable_vreg_sense(basePointer)
#define SI32_VREG_A_disable_vreg_sense(basePointer) \
   (basePointer->CONTROL_CLR = SI32_VREG_A_CONTROL_SENSEEN_MASK)


/// @fn _SI32_VREG_A_is_vbus_invalid_interrupt_pending(SI32_VREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_VREG_A_is_vbus_invalid_interrupt_pending(SI32_VREG_A_Type* /*basePointer*/);
///
/// @def SI32_VREG_A_is_vbus_invalid_interrupt_pending(basePointer)
#define SI32_VREG_A_is_vbus_invalid_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.VBUSIVLDI))


/// @fn _SI32_VREG_A_clear_vbus_invalid_interrupt(SI32_VREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_VREG_A_clear_vbus_invalid_interrupt(SI32_VREG_A_Type* /*basePointer*/);
///
/// @def SI32_VREG_A_clear_vbus_invalid_interrupt(basePointer)
#define SI32_VREG_A_clear_vbus_invalid_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_VREG_A_CONTROL_VBUSIVLDI_MASK)


/// @fn _SI32_VREG_A_enable_vbus_invalid_interrupt(SI32_VREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_VREG_A_enable_vbus_invalid_interrupt(SI32_VREG_A_Type* /*basePointer*/);
///
/// @def SI32_VREG_A_enable_vbus_invalid_interrupt(basePointer)
#define SI32_VREG_A_enable_vbus_invalid_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_VREG_A_CONTROL_VBUSIVLDIEN_ENABLED_U32)


/// @fn _SI32_VREG_A_disable_vbus_invalid_interrupt(SI32_VREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_VREG_A_disable_vbus_invalid_interrupt(SI32_VREG_A_Type* /*basePointer*/);
///
/// @def SI32_VREG_A_disable_vbus_invalid_interrupt(basePointer)
#define SI32_VREG_A_disable_vbus_invalid_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_VREG_A_CONTROL_VBUSIVLDIEN_MASK)


/// @fn _SI32_VREG_A_is_vbus_invalid_interrupt_enabled(SI32_VREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_VREG_A_is_vbus_invalid_interrupt_enabled(SI32_VREG_A_Type* /*basePointer*/);
///
/// @def SI32_VREG_A_is_vbus_invalid_interrupt_enabled(basePointer)
#define SI32_VREG_A_is_vbus_invalid_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.VBUSIVLDIEN))


/// @fn _SI32_VREG_A_enable_voltage_regulator(SI32_VREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_VREG_A_enable_voltage_regulator(SI32_VREG_A_Type* /*basePointer*/);
///
/// @def SI32_VREG_A_enable_voltage_regulator(basePointer)
#define SI32_VREG_A_enable_voltage_regulator(basePointer) \
   (basePointer->CONTROL_CLR = SI32_VREG_A_CONTROL_VREGDIS_MASK)


/// @fn _SI32_VREG_A_disable_voltage_regulator(SI32_VREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_VREG_A_disable_voltage_regulator(SI32_VREG_A_Type* /*basePointer*/);
///
/// @def SI32_VREG_A_disable_voltage_regulator(basePointer)
#define SI32_VREG_A_disable_voltage_regulator(basePointer) \
   (basePointer->CONTROL_SET = SI32_VREG_A_CONTROL_VREGDIS_ACTIVE_U32)



#ifdef __cplusplus
}
#endif

#endif // __SI32_VREG_A_TYPE_H__

//-eof--------------------------------------------------------------------------
