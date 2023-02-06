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
/// @file SI32_EXTOSC_A_Type.h
//
// Script: 0.58
// HAL Source: 0.2
// Version: 1

#ifndef __SI32_EXTOSC_A_TYPE_H__
#define __SI32_EXTOSC_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_EXTOSC_A_Registers.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_EXTOSC_A_initialize(SI32_EXTOSC_A_Type* basePointer,
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
_SI32_EXTOSC_A_initialize(SI32_EXTOSC_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_EXTOSC_A_initialize(basePointer, control)
#define SI32_EXTOSC_A_initialize(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_EXTOSC_A_write_control(SI32_EXTOSC_A_Type* basePointer,
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
_SI32_EXTOSC_A_write_control(SI32_EXTOSC_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_EXTOSC_A_write_control(basePointer, control)
#define SI32_EXTOSC_A_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_EXTOSC_A_read_control(SI32_EXTOSC_A_Type* basePointer)
///
/// @return
///  Read CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_EXTOSC_A_read_control(SI32_EXTOSC_A_Type* /*basePointer*/);
///
/// @def SI32_EXTOSC_A_read_control(basePointer)
#define SI32_EXTOSC_A_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_EXTOSC_A_set_frequency_control_range(SI32_EXTOSC_A_Type* basePointer,
///      uint32_t freqcn)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  freqcn
///  Valid range is 3 bits.
///  Frequency control range value.
///
void
_SI32_EXTOSC_A_set_frequency_control_range(SI32_EXTOSC_A_Type* /*basePointer*/,
   uint32_t /*freqcn*/);
///
/// @def SI32_EXTOSC_A_set_frequency_control_range(basePointer, freqcn)
#define SI32_EXTOSC_A_set_frequency_control_range(basePointer, freqcn) do{  \
   basePointer->CONTROL_CLR = SI32_EXTOSC_A_CONTROL_FREQCN_MASK;\
   basePointer->CONTROL_SET = freqcn;\
} while(0)


/// @fn _SI32_EXTOSC_A_is_oscillator_valid(SI32_EXTOSC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_EXTOSC_A_is_oscillator_valid(SI32_EXTOSC_A_Type* /*basePointer*/);
///
/// @def SI32_EXTOSC_A_is_oscillator_valid(basePointer)
#define SI32_EXTOSC_A_is_oscillator_valid(basePointer) \
((bool)(basePointer->CONTROL.OSCVLDF))


/// @fn _SI32_EXTOSC_A_select_oscillator_mode_off(SI32_EXTOSC_A_Type* basePointer)
///
/// @brief
/// Turn off the external oscillator circuit.
///
/// @param[in]
///  basePointer
///
void
_SI32_EXTOSC_A_select_oscillator_mode_off(SI32_EXTOSC_A_Type* /*basePointer*/);
///
/// @def SI32_EXTOSC_A_select_oscillator_mode_off(basePointer)
#define SI32_EXTOSC_A_select_oscillator_mode_off(basePointer) \
   (basePointer->CONTROL_CLR = SI32_EXTOSC_A_CONTROL_OSCMD_MASK)


/// @fn _SI32_EXTOSC_A_select_oscillator_mode_cmos(SI32_EXTOSC_A_Type* basePointer)
///
/// @brief
/// Use external CMOS clock as the external oscillator source.
///
/// @param[in]
///  basePointer
///
void
_SI32_EXTOSC_A_select_oscillator_mode_cmos(SI32_EXTOSC_A_Type* /*basePointer*/);
///
/// @def SI32_EXTOSC_A_select_oscillator_mode_cmos(basePointer)
#define SI32_EXTOSC_A_select_oscillator_mode_cmos(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_EXTOSC_A_CONTROL_OSCMD_MASK;\
   basePointer->CONTROL_SET = SI32_EXTOSC_A_CONTROL_OSCMD_CMOS_U32;\
} while(0)


/// @fn _SI32_EXTOSC_A_select_oscillator_mode_cmos_div2(SI32_EXTOSC_A_Type* basePointer)
///
/// @brief
/// Use external CMOS clock with divide-by-2 stage as the external
/// oscillator source.
///
/// @param[in]
///  basePointer
///
void
_SI32_EXTOSC_A_select_oscillator_mode_cmos_div2(SI32_EXTOSC_A_Type* /*basePointer*/);
///
/// @def SI32_EXTOSC_A_select_oscillator_mode_cmos_div2(basePointer)
#define SI32_EXTOSC_A_select_oscillator_mode_cmos_div2(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_EXTOSC_A_CONTROL_OSCMD_MASK;\
   basePointer->CONTROL_SET = SI32_EXTOSC_A_CONTROL_OSCMD_CMOSDIV2_U32;\
} while(0)


/// @fn _SI32_EXTOSC_A_select_oscillator_mode_rc_div2(SI32_EXTOSC_A_Type* basePointer)
///
/// @brief
/// Use external RC oscillator with divide-by-2 stage as the external
/// oscillator source.
///
/// @param[in]
///  basePointer
///
void
_SI32_EXTOSC_A_select_oscillator_mode_rc_div2(SI32_EXTOSC_A_Type* /*basePointer*/);
///
/// @def SI32_EXTOSC_A_select_oscillator_mode_rc_div2(basePointer)
#define SI32_EXTOSC_A_select_oscillator_mode_rc_div2(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_EXTOSC_A_CONTROL_OSCMD_MASK;\
   basePointer->CONTROL_SET = SI32_EXTOSC_A_CONTROL_OSCMD_RC_U32;\
} while(0)


/// @fn _SI32_EXTOSC_A_select_oscillator_mode_c_div2(SI32_EXTOSC_A_Type* basePointer)
///
/// @brief
/// Use external C oscillator with divide-by-2 stage as the external
/// oscillator source.
///
/// @param[in]
///  basePointer
///
void
_SI32_EXTOSC_A_select_oscillator_mode_c_div2(SI32_EXTOSC_A_Type* /*basePointer*/);
///
/// @def SI32_EXTOSC_A_select_oscillator_mode_c_div2(basePointer)
#define SI32_EXTOSC_A_select_oscillator_mode_c_div2(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_EXTOSC_A_CONTROL_OSCMD_MASK;\
   basePointer->CONTROL_SET = SI32_EXTOSC_A_CONTROL_OSCMD_C_U32;\
} while(0)


/// @fn _SI32_EXTOSC_A_select_oscillator_mode_crystal(SI32_EXTOSC_A_Type* basePointer)
///
/// @brief
/// Use external crystal oscillator as the external oscillator source.
///
/// @param[in]
///  basePointer
///
void
_SI32_EXTOSC_A_select_oscillator_mode_crystal(SI32_EXTOSC_A_Type* /*basePointer*/);
///
/// @def SI32_EXTOSC_A_select_oscillator_mode_crystal(basePointer)
#define SI32_EXTOSC_A_select_oscillator_mode_crystal(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_EXTOSC_A_CONTROL_OSCMD_MASK;\
   basePointer->CONTROL_SET = SI32_EXTOSC_A_CONTROL_OSCMD_XTAL_U32;\
} while(0)


/// @fn _SI32_EXTOSC_A_select_oscillator_mode_crystal_div2(SI32_EXTOSC_A_Type* basePointer)
///
/// @brief
/// Use external crystal oscillator with divide-by-2 stage as the external
/// oscillator source.
///
/// @param[in]
///  basePointer
///
void
_SI32_EXTOSC_A_select_oscillator_mode_crystal_div2(SI32_EXTOSC_A_Type* /*basePointer*/);
///
/// @def SI32_EXTOSC_A_select_oscillator_mode_crystal_div2(basePointer)
#define SI32_EXTOSC_A_select_oscillator_mode_crystal_div2(basePointer) \
   (basePointer->CONTROL_SET	= SI32_EXTOSC_A_CONTROL_OSCMD_XTALDIV2_U32)



#ifdef __cplusplus
}
#endif

#endif // __SI32_EXTOSC_A_TYPE_H__

//-eof--------------------------------------------------------------------------
