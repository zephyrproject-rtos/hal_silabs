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
/// @file SI32_CMP_A_Type.h
//
// Script: 0.58
// HAL Source: 0.3
// Version: 1

#ifndef __SI32_CMP_A_TYPE_H__
#define __SI32_CMP_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_CMP_A_Registers.h"

// support definitions
#include "SI32_CMP_A_Support.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_CMP_A_initialize(SI32_CMP_A_Type* basePointer,
///      uint32_t control,
///      uint32_t mode)
///
/// @brief
/// Writes all CMP registers.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///
/// @param[in]
///  mode
///  Valid range is 32 bits.
///
void
_SI32_CMP_A_initialize(SI32_CMP_A_Type* /*basePointer*/,
   uint32_t, /*control*/
   uint32_t /*mode*/);
///
/// @def SI32_CMP_A_initialize(basePointer, control, mode)
#define SI32_CMP_A_initialize(basePointer, control, mode) do{  \
	basePointer->CONTROL.U32 = control;\
	basePointer->MODE.U32 = mode;\
} while(0)


/// @fn _SI32_CMP_A_write_control(SI32_CMP_A_Type* basePointer,
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
_SI32_CMP_A_write_control(SI32_CMP_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_CMP_A_write_control(basePointer, control)
#define SI32_CMP_A_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_CMP_A_read_control(SI32_CMP_A_Type* basePointer)
///
/// @brief
/// Reads CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_CMP_A_read_control(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_read_control(basePointer)
#define SI32_CMP_A_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_CMP_A_is_rising_edge_interrupt_pending(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_CMP_A_is_rising_edge_interrupt_pending(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_is_rising_edge_interrupt_pending(basePointer)
#define SI32_CMP_A_is_rising_edge_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.CMPRI))


/// @fn _SI32_CMP_A_clear_rising_edge_interrupt(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CMP_A_clear_rising_edge_interrupt(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_clear_rising_edge_interrupt(basePointer)
#define SI32_CMP_A_clear_rising_edge_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_CMP_A_CONTROL_CMPRI_MASK)


/// @fn _SI32_CMP_A_is_falling_edge_interrupt_pending(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_CMP_A_is_falling_edge_interrupt_pending(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_is_falling_edge_interrupt_pending(basePointer)
#define SI32_CMP_A_is_falling_edge_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.CMPFI))


/// @fn _SI32_CMP_A_clear_falling_edge_interrupt(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CMP_A_clear_falling_edge_interrupt(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_clear_falling_edge_interrupt(basePointer)
#define SI32_CMP_A_clear_falling_edge_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_CMP_A_CONTROL_CMPFI_MASK)


/// @fn _SI32_CMP_A_is_positive_input_greater_than_negative_input(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_CMP_A_is_positive_input_greater_than_negative_input(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_is_positive_input_greater_than_negative_input(basePointer)
#define SI32_CMP_A_is_positive_input_greater_than_negative_input(basePointer) \
((bool)(basePointer->CONTROL.CMPOUT))


/// @fn _SI32_CMP_A_enable_module(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CMP_A_enable_module(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_enable_module(basePointer)
#define SI32_CMP_A_enable_module(basePointer) \
   (basePointer->CONTROL_SET = SI32_CMP_A_CONTROL_CMPEN_MASK)


/// @fn _SI32_CMP_A_disable_module(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CMP_A_disable_module(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_disable_module(basePointer)
#define SI32_CMP_A_disable_module(basePointer) \
   (basePointer->CONTROL_CLR = SI32_CMP_A_CONTROL_CMPEN_MASK)


/// @fn _SI32_CMP_A_write_mode(SI32_CMP_A_Type* basePointer,
///      uint32_t mode)
///
/// @brief
/// Writes MODE register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  mode
///  Valid range is 32 bits.
///
void
_SI32_CMP_A_write_mode(SI32_CMP_A_Type* /*basePointer*/,
   uint32_t /*mode*/);
///
/// @def SI32_CMP_A_write_mode(basePointer, mode)
#define SI32_CMP_A_write_mode(basePointer, mode) \
   (basePointer->MODE.U32 = mode)


/// @fn _SI32_CMP_A_read_mode(SI32_CMP_A_Type* basePointer)
///
/// @brief
/// Reads MODE register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_CMP_A_read_mode(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_read_mode(basePointer)
#define SI32_CMP_A_read_mode(basePointer) \
(basePointer->MODE.U32)


/// @fn _SI32_CMP_A_select_negative_input(SI32_CMP_A_Type* basePointer,
///      uint32_t input)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  input
///  Valid range is 4 bits.
///  Selects negative input from 0 (CMPnN.0) to 15 (CMPnN.15).
///
void
_SI32_CMP_A_select_negative_input(SI32_CMP_A_Type* /*basePointer*/,
   uint32_t /*input*/);
///
/// @def SI32_CMP_A_select_negative_input(basePointer, input)
#define SI32_CMP_A_select_negative_input(basePointer, input) do{  \
   basePointer->MODE_CLR = SI32_CMP_A_MODE_NMUX_MASK;\
   basePointer->MODE_SET = input << SI32_CMP_A_MODE_NMUX_SHIFT;\
} while(0)


/// @fn _SI32_CMP_A_select_positive_input(SI32_CMP_A_Type* basePointer,
///      uint32_t input)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  input
///  Valid range is 4 bits.
///  Selects positive input from 0 (CMPnP.0) to 15 (CMPnP.15).
///
void
_SI32_CMP_A_select_positive_input(SI32_CMP_A_Type* /*basePointer*/,
   uint32_t /*input*/);
///
/// @def SI32_CMP_A_select_positive_input(basePointer, input)
#define SI32_CMP_A_select_positive_input(basePointer, input) do{  \
   basePointer->MODE_CLR = SI32_CMP_A_MODE_PMUX_MASK;\
   basePointer->MODE_SET = input << SI32_CMP_A_MODE_PMUX_SHIFT;\
} while(0)


/// @fn _SI32_CMP_A_select_mux(SI32_CMP_A_Type* basePointer,
///      SI32_CMP_A_INPUT_MUX_Enum_Type mux)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  mux
///  Valid range is 2 bits.
///  0: Configures the positive input to connect to the signal based off of
///  CMXOP and the negative input to connect to the signal based off of
///  CMXON.  1: Configures the negative input to connect to VDD and the
///  positive input to connect to the signal based off of CMXOP.  2:
///  Configures the negative input to connect to the signal based off of
///  CMXON and the positive input to connect to the DAC.  3: Configures the
///  negative input to connect to the DAC and the positive input to connect
///  to the signal based off of CMXOP.
///
void
_SI32_CMP_A_select_mux(SI32_CMP_A_Type* /*basePointer*/,
   SI32_CMP_A_INPUT_MUX_Enum_Type /*mux*/);
///
/// @def SI32_CMP_A_select_mux(basePointer, mux)
#define SI32_CMP_A_select_mux(basePointer, mux) do{  \
   basePointer->MODE_CLR = SI32_CMP_A_MODE_INMUX_MASK;\
   basePointer->MODE_SET = mux << SI32_CMP_A_MODE_INMUX_SHIFT;\
} while(0)


/// @fn _SI32_CMP_A_select_response_power_mode(SI32_CMP_A_Type* basePointer,
///      SI32_CMP_A_RESPONSE_POWER_MODE_Enum_Type mode)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  mode
///  Valid range is 2 bits.
///  From mode 0 (fastest response time, highest power consumption) to mode
///  3 (slowest response time, lowest power consumption).
///
void
_SI32_CMP_A_select_response_power_mode(SI32_CMP_A_Type* /*basePointer*/,
   SI32_CMP_A_RESPONSE_POWER_MODE_Enum_Type /*mode*/);
///
/// @def SI32_CMP_A_select_response_power_mode(basePointer, mode)
#define SI32_CMP_A_select_response_power_mode(basePointer, mode) do{  \
   basePointer->MODE_CLR = SI32_CMP_A_MODE_CMPMD_MASK;\
   basePointer->MODE_SET = mode << SI32_CMP_A_MODE_CMPMD_SHIFT;\
} while(0)


/// @fn _SI32_CMP_A_enable_falling_edge_interrupt(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CMP_A_enable_falling_edge_interrupt(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_enable_falling_edge_interrupt(basePointer)
#define SI32_CMP_A_enable_falling_edge_interrupt(basePointer) \
   (basePointer->MODE_SET = SI32_CMP_A_MODE_FIEN_MASK)


/// @fn _SI32_CMP_A_disable_falling_edge_interrupt(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CMP_A_disable_falling_edge_interrupt(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_disable_falling_edge_interrupt(basePointer)
#define SI32_CMP_A_disable_falling_edge_interrupt(basePointer) \
   (basePointer->MODE_CLR = SI32_CMP_A_MODE_FIEN_MASK)


/// @fn _SI32_CMP_A_is_falling_edge_interrupt_enabled(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_CMP_A_is_falling_edge_interrupt_enabled(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_is_falling_edge_interrupt_enabled(basePointer)
#define SI32_CMP_A_is_falling_edge_interrupt_enabled(basePointer) \
((bool)(basePointer->MODE.FIEN))


/// @fn _SI32_CMP_A_enable_rising_edge_interrupt(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CMP_A_enable_rising_edge_interrupt(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_enable_rising_edge_interrupt(basePointer)
#define SI32_CMP_A_enable_rising_edge_interrupt(basePointer) \
   (basePointer->MODE_SET = SI32_CMP_A_MODE_RIEN_MASK)


/// @fn _SI32_CMP_A_disable_rising_edge_interrupt(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CMP_A_disable_rising_edge_interrupt(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_disable_rising_edge_interrupt(basePointer)
#define SI32_CMP_A_disable_rising_edge_interrupt(basePointer) \
   (basePointer->MODE_CLR = SI32_CMP_A_MODE_RIEN_MASK)


/// @fn _SI32_CMP_A_is_rising_edge_interrupt_enabled(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_CMP_A_is_rising_edge_interrupt_enabled(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_is_rising_edge_interrupt_enabled(basePointer)
#define SI32_CMP_A_is_rising_edge_interrupt_enabled(basePointer) \
((bool)(basePointer->MODE.RIEN))


/// @fn _SI32_CMP_A_write_dac_level_setting(SI32_CMP_A_Type* basePointer,
///      uint32_t value)
///
/// @brief
/// Writes the DAC level setting.  The setting represents (REFDAC / 64) *
/// VREF.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 6 bits.
///
void
_SI32_CMP_A_write_dac_level_setting(SI32_CMP_A_Type* /*basePointer*/,
   uint32_t /*value*/);
///
/// @def SI32_CMP_A_write_dac_level_setting(basePointer, value)
#define SI32_CMP_A_write_dac_level_setting(basePointer, value) do{  \
   basePointer->MODE_CLR = SI32_CMP_A_MODE_DACLVL_MASK;\
   basePointer->MODE_SET = value << SI32_CMP_A_MODE_DACLVL_SHIFT;\
} while(0)


/// @fn _SI32_CMP_A_read_dac_level_setting(SI32_CMP_A_Type* basePointer)
///
/// @brief
/// Reads the DAC level setting.  The setting represents (REFDAC / 64) *
/// VREF.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_CMP_A_read_dac_level_setting(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_read_dac_level_setting(basePointer)
#define SI32_CMP_A_read_dac_level_setting(basePointer) \
(basePointer->MODE.DACLVL)


/// @fn _SI32_CMP_A_enable_negative_weak_pullup(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CMP_A_enable_negative_weak_pullup(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_enable_negative_weak_pullup(basePointer)
#define SI32_CMP_A_enable_negative_weak_pullup(basePointer) \
   (basePointer->MODE_SET = SI32_CMP_A_MODE_NWPUEN_MASK)


/// @fn _SI32_CMP_A_disable_negative_weak_pullup(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CMP_A_disable_negative_weak_pullup(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_disable_negative_weak_pullup(basePointer)
#define SI32_CMP_A_disable_negative_weak_pullup(basePointer) \
   (basePointer->MODE_CLR = SI32_CMP_A_MODE_NWPUEN_MASK)


/// @fn _SI32_CMP_A_enable_positive_weak_pullup(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CMP_A_enable_positive_weak_pullup(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_enable_positive_weak_pullup(basePointer)
#define SI32_CMP_A_enable_positive_weak_pullup(basePointer) \
   (basePointer->MODE_SET = SI32_CMP_A_MODE_PWPUEN_MASK)


/// @fn _SI32_CMP_A_disable_positive_weak_pullup(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CMP_A_disable_positive_weak_pullup(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_disable_positive_weak_pullup(basePointer)
#define SI32_CMP_A_disable_positive_weak_pullup(basePointer) \
   (basePointer->MODE_CLR = SI32_CMP_A_MODE_PWPUEN_MASK)


/// @fn _SI32_CMP_A_select_negative_hysteresis_disabled(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CMP_A_select_negative_hysteresis_disabled(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_select_negative_hysteresis_disabled(basePointer)
#define SI32_CMP_A_select_negative_hysteresis_disabled(basePointer) \
   (basePointer->MODE_CLR = SI32_CMP_A_MODE_CMPHYN_MASK)


/// @fn _SI32_CMP_A_select_negative_hysteresis_5mv(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CMP_A_select_negative_hysteresis_5mv(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_select_negative_hysteresis_5mv(basePointer)
#define SI32_CMP_A_select_negative_hysteresis_5mv(basePointer) do{  \
   basePointer->MODE_CLR = SI32_CMP_A_MODE_CMPHYN_MASK;\
   basePointer->MODE_SET = SI32_CMP_A_MODE_CMPHYN_NEG_5_MV_U32;\
} while(0)


/// @fn _SI32_CMP_A_select_negative_hysteresis_10mv(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CMP_A_select_negative_hysteresis_10mv(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_select_negative_hysteresis_10mv(basePointer)
#define SI32_CMP_A_select_negative_hysteresis_10mv(basePointer) do{  \
   basePointer->MODE_CLR = SI32_CMP_A_MODE_CMPHYN_MASK;\
   basePointer->MODE_SET = SI32_CMP_A_MODE_CMPHYN_NEG_10_MV_U32;\
} while(0)


/// @fn _SI32_CMP_A_select_negative_hysteresis_20mv(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CMP_A_select_negative_hysteresis_20mv(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_select_negative_hysteresis_20mv(basePointer)
#define SI32_CMP_A_select_negative_hysteresis_20mv(basePointer) do{  \
   basePointer->MODE_CLR = SI32_CMP_A_MODE_CMPHYN_MASK;\
   basePointer->MODE_SET = SI32_CMP_A_MODE_CMPHYN_NEG_20_MV_U32;\
} while(0)


/// @fn _SI32_CMP_A_select_positive_hysteresis_disabled(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CMP_A_select_positive_hysteresis_disabled(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_select_positive_hysteresis_disabled(basePointer)
#define SI32_CMP_A_select_positive_hysteresis_disabled(basePointer) \
   (basePointer->MODE_CLR = SI32_CMP_A_MODE_CMPHYP_MASK)


/// @fn _SI32_CMP_A_select_positive_hysteresis_5mv(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CMP_A_select_positive_hysteresis_5mv(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_select_positive_hysteresis_5mv(basePointer)
#define SI32_CMP_A_select_positive_hysteresis_5mv(basePointer) do{  \
   basePointer->MODE_CLR = SI32_CMP_A_MODE_CMPHYP_MASK;\
   basePointer->MODE_SET = SI32_CMP_A_MODE_CMPHYP_POS_5_MV_U32;\
} while(0)


/// @fn _SI32_CMP_A_select_positive_hysteresis_10mv(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CMP_A_select_positive_hysteresis_10mv(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_select_positive_hysteresis_10mv(basePointer)
#define SI32_CMP_A_select_positive_hysteresis_10mv(basePointer) do{  \
   basePointer->MODE_CLR = SI32_CMP_A_MODE_CMPHYP_MASK;\
   basePointer->MODE_SET = SI32_CMP_A_MODE_CMPHYP_POS_10_MV_U32;\
} while(0)


/// @fn _SI32_CMP_A_select_positive_hysteresis_20mv(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CMP_A_select_positive_hysteresis_20mv(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_select_positive_hysteresis_20mv(basePointer)
#define SI32_CMP_A_select_positive_hysteresis_20mv(basePointer) do{  \
   basePointer->MODE_CLR = SI32_CMP_A_MODE_CMPHYP_MASK;\
   basePointer->MODE_SET = SI32_CMP_A_MODE_CMPHYP_POS_20_MV_U32;\
} while(0)


/// @fn _SI32_CMP_A_enable_inverted_output(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CMP_A_enable_inverted_output(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_enable_inverted_output(basePointer)
#define SI32_CMP_A_enable_inverted_output(basePointer) \
   (basePointer->MODE_SET = SI32_CMP_A_MODE_INVEN_MASK)


/// @fn _SI32_CMP_A_disable_inverted_output(SI32_CMP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CMP_A_disable_inverted_output(SI32_CMP_A_Type* /*basePointer*/);
///
/// @def SI32_CMP_A_disable_inverted_output(basePointer)
#define SI32_CMP_A_disable_inverted_output(basePointer) \
   (basePointer->MODE_CLR = SI32_CMP_A_MODE_INVEN_MASK)



#ifdef __cplusplus
}
#endif

#endif // __SI32_CMP_A_TYPE_H__

//-eof--------------------------------------------------------------------------
