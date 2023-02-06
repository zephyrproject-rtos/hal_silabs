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
/// @file SI32_RSTSRC_A_Type.h
//
// This file applies to the SIM3L1XX_RSTSRC_A module
//
// Script: 0.59
// HAL Source: 0.2
// Version: 1

#ifndef __SI32_RSTSRC_A_TYPE_H__
#define __SI32_RSTSRC_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_SIM3L1XX_RSTSRC_A_Registers.h"

// support definitions
#include "SI32_RSTSRC_A_Support.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_RSTSRC_A_initialize(SI32_RSTSRC_A_Type* basePointer,
///      uint32_t reseten)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  reseten
///  Valid range is 32 bits.
///  Write to RESETEN register.
///
void
_SI32_RSTSRC_A_initialize(SI32_RSTSRC_A_Type* /*basePointer*/,
   uint32_t /*reseten*/);
///
/// @def SI32_RSTSRC_A_initialize(basePointer, reseten)
#define SI32_RSTSRC_A_initialize(basePointer, reseten) \
   (basePointer->RESETEN.U32 = reseten)


/// @fn _SI32_RSTSRC_A_write_reseten(SI32_RSTSRC_A_Type* basePointer,
///      uint32_t reseten)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  reseten
///  Valid range is 32 bits.
///  Write to RESETEN register.
///
void
_SI32_RSTSRC_A_write_reseten(SI32_RSTSRC_A_Type* /*basePointer*/,
   uint32_t /*reseten*/);
///
/// @def SI32_RSTSRC_A_write_reseten(basePointer, reseten)
#define SI32_RSTSRC_A_write_reseten(basePointer, reseten) \
   (basePointer->RESETEN.U32 = reseten)


/// @fn _SI32_RSTSRC_A_read_reseten(SI32_RSTSRC_A_Type* basePointer)
///
/// @return
///  Read RESETEN register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_RSTSRC_A_read_reseten(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_read_reseten(basePointer)
#define SI32_RSTSRC_A_read_reseten(basePointer) \
(basePointer->RESETEN.U32)


/// @fn _SI32_RSTSRC_A_enable_vdd_monitor_reset_source(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_enable_vdd_monitor_reset_source(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_enable_vdd_monitor_reset_source(basePointer)
#define SI32_RSTSRC_A_enable_vdd_monitor_reset_source(basePointer) \
   (basePointer->RESETEN_SET = SI32_RSTSRC_A_RESETEN_VMONREN_MASK)


/// @fn _SI32_RSTSRC_A_disable_vdd_monitor_reset_source(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_disable_vdd_monitor_reset_source(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_disable_vdd_monitor_reset_source(basePointer)
#define SI32_RSTSRC_A_disable_vdd_monitor_reset_source(basePointer) \
   (basePointer->RESETEN_CLR = SI32_RSTSRC_A_RESETEN_VMONREN_MASK)


/// @fn _SI32_RSTSRC_A_enable_missing_clock_detector_reset_source(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_enable_missing_clock_detector_reset_source(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_enable_missing_clock_detector_reset_source(basePointer)
#define SI32_RSTSRC_A_enable_missing_clock_detector_reset_source(basePointer) \
   (basePointer->RESETEN_SET = SI32_RSTSRC_A_RESETEN_MCDREN_MASK)


/// @fn _SI32_RSTSRC_A_disable_missing_clock_detector_reset_source(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_disable_missing_clock_detector_reset_source(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_disable_missing_clock_detector_reset_source(basePointer)
#define SI32_RSTSRC_A_disable_missing_clock_detector_reset_source(basePointer) \
   (basePointer->RESETEN_CLR = SI32_RSTSRC_A_RESETEN_MCDREN_MASK)


/// @fn _SI32_RSTSRC_A_enable_watchdog_timer_reset_source(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_enable_watchdog_timer_reset_source(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_enable_watchdog_timer_reset_source(basePointer)
#define SI32_RSTSRC_A_enable_watchdog_timer_reset_source(basePointer) \
   (basePointer->RESETEN_SET = SI32_RSTSRC_A_RESETEN_WDTREN_MASK)


/// @fn _SI32_RSTSRC_A_disable_watchdog_timer_reset_source(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_disable_watchdog_timer_reset_source(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_disable_watchdog_timer_reset_source(basePointer)
#define SI32_RSTSRC_A_disable_watchdog_timer_reset_source(basePointer) \
   (basePointer->RESETEN_CLR = SI32_RSTSRC_A_RESETEN_WDTREN_MASK)


/// @fn _SI32_RSTSRC_A_generate_software_reset(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_generate_software_reset(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_generate_software_reset(basePointer)
#define SI32_RSTSRC_A_generate_software_reset(basePointer) \
   (basePointer->RESETEN_SET = SI32_RSTSRC_A_RESETEN_SWREN_MASK)


/// @fn _SI32_RSTSRC_A_enable_comparator0_reset_source(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_enable_comparator0_reset_source(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_enable_comparator0_reset_source(basePointer)
#define SI32_RSTSRC_A_enable_comparator0_reset_source(basePointer) \
   (basePointer->RESETEN_SET = SI32_RSTSRC_A_RESETEN_CMP0REN_MASK)


/// @fn _SI32_RSTSRC_A_disable_comparator0_reset_source(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_disable_comparator0_reset_source(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_disable_comparator0_reset_source(basePointer)
#define SI32_RSTSRC_A_disable_comparator0_reset_source(basePointer) \
   (basePointer->RESETEN_CLR = SI32_RSTSRC_A_RESETEN_CMP0REN_MASK)


/// @fn _SI32_RSTSRC_A_enable_comparator1_reset_source(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_enable_comparator1_reset_source(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_enable_comparator1_reset_source(basePointer)
#define SI32_RSTSRC_A_enable_comparator1_reset_source(basePointer) \
   (basePointer->RESETEN_SET = SI32_RSTSRC_A_RESETEN_CMP1REN_MASK)


/// @fn _SI32_RSTSRC_A_disable_comparator1_reset_source(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_disable_comparator1_reset_source(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_disable_comparator1_reset_source(basePointer)
#define SI32_RSTSRC_A_disable_comparator1_reset_source(basePointer) \
   (basePointer->RESETEN_CLR = SI32_RSTSRC_A_RESETEN_CMP1REN_MASK)


/// @fn _SI32_RSTSRC_A_enable_low_power_mode_charge_pump_reset_source(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_enable_low_power_mode_charge_pump_reset_source(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_enable_low_power_mode_charge_pump_reset_source(basePointer)
#define SI32_RSTSRC_A_enable_low_power_mode_charge_pump_reset_source(basePointer) \
   (basePointer->RESETEN_SET = SI32_RSTSRC_A_RESETEN_CPFREN_MASK)


/// @fn _SI32_RSTSRC_A_disable_low_power_mode_charge_pump_reset_source(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_disable_low_power_mode_charge_pump_reset_source(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_disable_low_power_mode_charge_pump_reset_source(basePointer)
#define SI32_RSTSRC_A_disable_low_power_mode_charge_pump_reset_source(basePointer) \
   (basePointer->RESETEN_CLR = SI32_RSTSRC_A_RESETEN_CPFREN_MASK)


/// @fn _SI32_RSTSRC_A_enable_rtc0_reset_source(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_enable_rtc0_reset_source(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_enable_rtc0_reset_source(basePointer)
#define SI32_RSTSRC_A_enable_rtc0_reset_source(basePointer) \
   (basePointer->RESETEN_SET = SI32_RSTSRC_A_RESETEN_RTC0REN_MASK)


/// @fn _SI32_RSTSRC_A_disable_rtc0_reset_source(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_disable_rtc0_reset_source(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_disable_rtc0_reset_source(basePointer)
#define SI32_RSTSRC_A_disable_rtc0_reset_source(basePointer) \
   (basePointer->RESETEN_CLR = SI32_RSTSRC_A_RESETEN_RTC0REN_MASK)


/// @fn _SI32_RSTSRC_A_enable_system_reset_to_low_power_charge_pump(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_enable_system_reset_to_low_power_charge_pump(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_enable_system_reset_to_low_power_charge_pump(basePointer)
#define SI32_RSTSRC_A_enable_system_reset_to_low_power_charge_pump(basePointer) \
   (basePointer->RESETEN_SET = SI32_RSTSRC_A_RESETEN_CPMREN_MASK)


/// @fn _SI32_RSTSRC_A_disable_system_reset_to_low_power_charge_pump(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_disable_system_reset_to_low_power_charge_pump(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_disable_system_reset_to_low_power_charge_pump(basePointer)
#define SI32_RSTSRC_A_disable_system_reset_to_low_power_charge_pump(basePointer) \
   (basePointer->RESETEN_CLR = SI32_RSTSRC_A_RESETEN_CPMREN_MASK)


/// @fn _SI32_RSTSRC_A_enable_system_reset_to_uart(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_enable_system_reset_to_uart(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_enable_system_reset_to_uart(basePointer)
#define SI32_RSTSRC_A_enable_system_reset_to_uart(basePointer) \
   (basePointer->RESETEN_SET = SI32_RSTSRC_A_RESETEN_UART0MREN_MASK)


/// @fn _SI32_RSTSRC_A_disable_system_reset_to_uart(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_disable_system_reset_to_uart(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_disable_system_reset_to_uart(basePointer)
#define SI32_RSTSRC_A_disable_system_reset_to_uart(basePointer) \
   (basePointer->RESETEN_CLR = SI32_RSTSRC_A_RESETEN_UART0MREN_MASK)


/// @fn _SI32_RSTSRC_A_enable_system_reset_to_lcd(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_enable_system_reset_to_lcd(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_enable_system_reset_to_lcd(basePointer)
#define SI32_RSTSRC_A_enable_system_reset_to_lcd(basePointer) \
   (basePointer->RESETEN_SET = SI32_RSTSRC_A_RESETEN_LCD0MREN_MASK)


/// @fn _SI32_RSTSRC_A_disable_system_reset_to_lcd(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_disable_system_reset_to_lcd(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_disable_system_reset_to_lcd(basePointer)
#define SI32_RSTSRC_A_disable_system_reset_to_lcd(basePointer) \
   (basePointer->RESETEN_CLR = SI32_RSTSRC_A_RESETEN_LCD0MREN_MASK)


/// @fn _SI32_RSTSRC_A_enable_system_reset_to_acctr(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_enable_system_reset_to_acctr(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_enable_system_reset_to_acctr(basePointer)
#define SI32_RSTSRC_A_enable_system_reset_to_acctr(basePointer) \
   (basePointer->RESETEN_SET = SI32_RSTSRC_A_RESETEN_ACC0MREN_MASK)


/// @fn _SI32_RSTSRC_A_disable_system_reset_to_acctr(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_disable_system_reset_to_acctr(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_disable_system_reset_to_acctr(basePointer)
#define SI32_RSTSRC_A_disable_system_reset_to_acctr(basePointer) \
   (basePointer->RESETEN_CLR = SI32_RSTSRC_A_RESETEN_ACC0MREN_MASK)


/// @fn _SI32_RSTSRC_A_enable_system_reset_to_rtc(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_enable_system_reset_to_rtc(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_enable_system_reset_to_rtc(basePointer)
#define SI32_RSTSRC_A_enable_system_reset_to_rtc(basePointer) \
   (basePointer->RESETEN_SET = SI32_RSTSRC_A_RESETEN_RTC0MREN_MASK)


/// @fn _SI32_RSTSRC_A_disable_system_reset_to_rtc(SI32_RSTSRC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_RSTSRC_A_disable_system_reset_to_rtc(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_disable_system_reset_to_rtc(basePointer)
#define SI32_RSTSRC_A_disable_system_reset_to_rtc(basePointer) \
   (basePointer->RESETEN_CLR = SI32_RSTSRC_A_RESETEN_RTC0MREN_MASK)


/// @fn _SI32_RSTSRC_A_get_last_reset_source(SI32_RSTSRC_A_Type* basePointer)
///
/// @return
///  Returns the source of the last reset.
///
/// @param[in]
///  basePointer
///
SI32_RSTSRC_Enum_Type
_SI32_RSTSRC_A_get_last_reset_source(SI32_RSTSRC_A_Type* /*basePointer*/);
///
/// @def SI32_RSTSRC_A_get_last_reset_source(basePointer)
#define SI32_RSTSRC_A_get_last_reset_source(basePointer) \
   _SI32_RSTSRC_A_get_last_reset_source(basePointer)



#ifdef __cplusplus
}
#endif

#endif // __SI32_RSTSRC_A_TYPE_H__

//-eof--------------------------------------------------------------------------
