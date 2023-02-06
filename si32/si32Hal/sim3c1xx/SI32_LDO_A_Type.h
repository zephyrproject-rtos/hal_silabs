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
/// @file SI32_LDO_A_Type.h
//
// This file applies to the SIM3C1XX_LDO_A module
//
// Script: 0.58
// HAL Source: 0.1
// Version: 1

#ifndef __SI32_LDO_A_TYPE_H__
#define __SI32_LDO_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_SIM3C1XX_LDO_A_Registers.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_LDO_A_write_control(SI32_LDO_A_Type* basePointer,
///      uint32_t control)
///
/// @brief
/// Write to CONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///
void
_SI32_LDO_A_write_control(SI32_LDO_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_LDO_A_write_control(basePointer, control)
#define SI32_LDO_A_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_LDO_A_read_control(SI32_LDO_A_Type* basePointer)
///
/// @brief
/// Reads CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LDO_A_read_control(SI32_LDO_A_Type* /*basePointer*/);
///
/// @def SI32_LDO_A_read_control(basePointer)
#define SI32_LDO_A_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_LDO_A_select_high_bias(SI32_LDO_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LDO_A_select_high_bias(SI32_LDO_A_Type* /*basePointer*/);
///
/// @def SI32_LDO_A_select_high_bias(basePointer)
#define SI32_LDO_A_select_high_bias(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LDO_A_CONTROL_LDOIBIAS_MASK)


/// @fn _SI32_LDO_A_select_low_bias(SI32_LDO_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LDO_A_select_low_bias(SI32_LDO_A_Type* /*basePointer*/);
///
/// @def SI32_LDO_A_select_low_bias(basePointer)
#define SI32_LDO_A_select_low_bias(basePointer) \
   (basePointer->CONTROL_SET = SI32_LDO_A_CONTROL_LDOIBIAS_LOWBIAS_U32)


/// @fn _SI32_LDO_A_enable_bias(SI32_LDO_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LDO_A_enable_bias(SI32_LDO_A_Type* /*basePointer*/);
///
/// @def SI32_LDO_A_enable_bias(basePointer)
#define SI32_LDO_A_enable_bias(basePointer) \
   (basePointer->CONTROL_SET = SI32_LDO_A_CONTROL_LDOAEN_ENABLE_U32)


/// @fn _SI32_LDO_A_disable_bias(SI32_LDO_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LDO_A_disable_bias(SI32_LDO_A_Type* /*basePointer*/);
///
/// @def SI32_LDO_A_disable_bias(basePointer)
#define SI32_LDO_A_disable_bias(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LDO_A_CONTROL_LDOAEN_MASK)



#ifdef __cplusplus
}
#endif

#endif // __SI32_LDO_A_TYPE_H__

//-eof--------------------------------------------------------------------------
