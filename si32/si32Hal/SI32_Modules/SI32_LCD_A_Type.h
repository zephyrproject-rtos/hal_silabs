//-----------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------
/// @file SI32_LCD_A_Type.h
//
// Script: 0.62
// HAL Source: 0.3
// Version: 1

#ifndef __SI32_LCD_A_TYPE_H__
#define __SI32_LCD_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_LCD_A_Registers.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_LCD_A_reset_module(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_reset_module(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_reset_module(basePointer)
#define SI32_LCD_A_reset_module(basePointer) do{  \
         basePointer->CONFIG.U32       = 0x000C7E35;\
         basePointer->CLKCONTROL.U32   = 0x14B0FC00;\
         basePointer->CTRSTCONTROL.U32 = 0x32800000;\
         basePointer->VBMCONTROL.U32   = 0xE2C00000;\
         basePointer->BLKCONTROL.U32   = 0x00000000;\
         basePointer->SEGCONTROL.U32   = 0x00000000;\
         basePointer->SEGMASK0.U32     = 0x00000000;\
         basePointer->SEGMASK1.U32     = 0x00000000;\
         basePointer->SEGDATA0.U32     = 0x00000000;\
         basePointer->SEGDATA1.U32     = 0x00000000;\
         basePointer->SEGDATA2.U32     = 0x00000000;\
         basePointer->SEGDATA3.U32     = 0x00000000;\
         basePointer->SEGDATA4.U32     = 0x00000000;\
} while(0)


/// @fn _SI32_LCD_A_initialize_module(SI32_LCD_A_Type* basePointer,
///      uint32_t config0,
///      uint32_t clock_control,
///      uint32_t write_blink_control,
///      uint32_t segment_control,
///      uint32_t write_contrast_control,
///      uint32_t vbat_monitor_control,
///      uint32_t segment_mask_0,
///      uint32_t segment_mask_1)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  config0
///  Valid range is 32 bits.
///
/// @param[in]
///  clock_control
///  Valid range is 32 bits.
///
/// @param[in]
///  write_blink_control
///  Valid range is 32 bits.
///
/// @param[in]
///  segment_control
///  Valid range is 32 bits.
///
/// @param[in]
///  write_contrast_control
///  Valid range is 32 bits.
///
/// @param[in]
///  vbat_monitor_control
///  Valid range is 32 bits.
///
/// @param[in]
///  segment_mask_0
///  Valid range is 32 bits.
///
/// @param[in]
///  segment_mask_1
///  Valid range is 32 bits.
///
void
_SI32_LCD_A_initialize_module(SI32_LCD_A_Type* /*basePointer*/,
   uint32_t, /*config0*/
   uint32_t, /*clock_control*/
   uint32_t, /*write_blink_control*/
   uint32_t, /*segment_control*/
   uint32_t, /*write_contrast_control*/
   uint32_t, /*vbat_monitor_control*/
   uint32_t, /*segment_mask_0*/
   uint32_t /*segment_mask_1*/);
///
/// @def SI32_LCD_A_initialize_module(basePointer, config0, clock_control, write_blink_control, segment_control, write_contrast_control, vbat_monitor_control, segment_mask_0, segment_mask_1)
#define SI32_LCD_A_initialize_module(basePointer, config0, clock_control, write_blink_control, segment_control, write_contrast_control, vbat_monitor_control, segment_mask_0, segment_mask_1) do{  \
   basePointer->CONFIG.U32 = config0;\
   basePointer->CLKCONTROL.U32 = clock_control;\
   basePointer->BLKCONTROL.U32 = write_blink_control;\
   basePointer->SEGCONTROL.U32 = segment_control;\
   basePointer->CTRSTCONTROL.U32 = write_contrast_control;\
   basePointer->VBMCONTROL.U32 = vbat_monitor_control;\
   basePointer->SEGMASK0.U32 = segment_mask_0;\
   basePointer->SEGMASK1.U32 = segment_mask_1;\
   basePointer->SEGDATA0.U32 = 0x00000000;\
   basePointer->SEGDATA1.U32 = 0x00000000;\
   basePointer->SEGDATA2.U32 = 0x00000000;\
   basePointer->SEGDATA3.U32 = 0x00000000;\
   basePointer->SEGDATA4.U32 = 0x00000000;\
} while(0)


/// @fn _SI32_LCD_A_enable_module(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_enable_module(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_enable_module(basePointer)
#define SI32_LCD_A_enable_module(basePointer) do{  \
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_LCDEN_MASK;\
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_RTCCEN_MASK;\
} while(0)


/// @fn _SI32_LCD_A_disable_module(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_disable_module(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_disable_module(basePointer)
#define SI32_LCD_A_disable_module(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_LCDEN_MASK;\
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_RTCCEN_MASK;\
} while(0)


/// @fn _SI32_LCD_A_is_module_enabled(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_LCD_A_is_module_enabled(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_is_module_enabled(basePointer)
#define SI32_LCD_A_is_module_enabled(basePointer) \
(basePointer->CONFIG.LCDEN)


/// @fn _SI32_LCD_A_select_static_mode(SI32_LCD_A_Type* basePointer)
///
/// @brief
/// Configure LCD for static mode. This function sets and clears all the
/// relavent bits.
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_select_static_mode(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_select_static_mode(basePointer)
#define SI32_LCD_A_select_static_mode(basePointer) do{  \
\
      basePointer->SEGCONTROL.SEGMD =\
      SI32_LCD_A_SEGCONTROL_SEGMD_STATIC_VALUE;\
\
      basePointer->SEGCONTROL.BIASMD =\
      SI32_LCD_A_SEGCONTROL_BIASMD_ONE_THIRD_VALUE;\
} while(0)


/// @fn _SI32_LCD_A_select_2_mux_mode(SI32_LCD_A_Type* basePointer)
///
/// @brief
/// Configure LCD for 2-mux mode. This function sets and clears all the
/// relavent bits.
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_select_2_mux_mode(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_select_2_mux_mode(basePointer)
#define SI32_LCD_A_select_2_mux_mode(basePointer) do{  \
\
      basePointer->SEGCONTROL.SEGMD =\
      SI32_LCD_A_SEGCONTROL_SEGMD_2_MUX_VALUE;\
\
      basePointer->SEGCONTROL.BIASMD =\
      SI32_LCD_A_SEGCONTROL_BIASMD_ONE_HALF_VALUE;\
\
      basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_BIASEN_MASK;\
} while(0)


/// @fn _SI32_LCD_A_select_3_mux_mode(SI32_LCD_A_Type* basePointer)
///
/// @brief
/// Configure LCD for 3-mux mode. This function sets and clears all the
/// relavent bits.
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_select_3_mux_mode(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_select_3_mux_mode(basePointer)
#define SI32_LCD_A_select_3_mux_mode(basePointer) do{  \
\
      basePointer->SEGCONTROL.SEGMD =\
      SI32_LCD_A_SEGCONTROL_SEGMD_3_MUX_VALUE;\
\
      basePointer->SEGCONTROL.BIASMD =\
      SI32_LCD_A_SEGCONTROL_BIASMD_ONE_THIRD_VALUE;\
\
      basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_BIASEN_MASK;\
} while(0)


/// @fn _SI32_LCD_A_select_4_mux_mode(SI32_LCD_A_Type* basePointer)
///
/// @brief
/// Configure LCD for 4-mux mode. This function sets and clears all the
/// relavent bits.
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_select_4_mux_mode(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_select_4_mux_mode(basePointer)
#define SI32_LCD_A_select_4_mux_mode(basePointer) do{  \
\
      basePointer->SEGCONTROL.SEGMD =\
      SI32_LCD_A_SEGCONTROL_SEGMD_4_MUX_VALUE;\
\
      basePointer->SEGCONTROL.BIASMD =\
      SI32_LCD_A_SEGCONTROL_BIASMD_ONE_THIRD_VALUE;\
\
      basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_BIASEN_MASK;\
} while(0)


/// @fn _SI32_LCD_A_select_auto_contrast_bypass_mode(SI32_LCD_A_Type* basePointer)
///
/// @brief
/// Configure LCD the bypass auto-contrast mode. This function sets and
/// clears all the relavent bits.
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_select_auto_contrast_bypass_mode(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_select_auto_contrast_bypass_mode(basePointer)
#define SI32_LCD_A_select_auto_contrast_bypass_mode(basePointer) do{  \
\
      basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_CPFPDEN_MASK;\
\
      basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_CPBEN_MASK;\
\
      basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_CPACEN_MASK;\
\
      basePointer->VBMCONTROL.VBMEN = SI32_LCD_A_VBMCONTROL_VBMOEN_DISABLED_VALUE;\
} while(0)


/// @fn _SI32_LCD_A_select_auto_contrast_minimum_contrast_mode(SI32_LCD_A_Type* basePointer)
///
/// @brief
/// Configure LCD the minimum-contrast auto-contrast mode. This function
/// sets and clears all the relavent bits.
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_select_auto_contrast_minimum_contrast_mode(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_select_auto_contrast_minimum_contrast_mode(basePointer)
#define SI32_LCD_A_select_auto_contrast_minimum_contrast_mode(basePointer) do{  \
\
      basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_BIASEN_MASK;\
\
      basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_CPFPDEN_MASK;\
\
      basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_CPBEN_MASK;\
\
      basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_CPACEN_MASK;\
\
      basePointer->VBMCONTROL.U32 = (\
      SI32_LCD_A_VBMCONTROL_VBMEN_ENABLED_U32|\
      SI32_LCD_A_VBMCONTROL_VBMOEN_ENABLED_U32|\
      0x00000001);\
} while(0)


/// @fn _SI32_LCD_A_select_auto_contrast_constant_contrast_mode(SI32_LCD_A_Type* basePointer)
///
/// @brief
/// Configure LCD the constant-contrast auto-contrast mode. This function
/// sets and clears all the relavent bits.
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_select_auto_contrast_constant_contrast_mode(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_select_auto_contrast_constant_contrast_mode(basePointer)
#define SI32_LCD_A_select_auto_contrast_constant_contrast_mode(basePointer) do{  \
\
      basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_BIASEN_MASK;\
\
      basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_CPFPDEN_MASK;\
\
      basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_CPBEN_MASK;\
\
      basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_CPACEN_MASK;\
\
      basePointer->VBMCONTROL.U32 = (\
      SI32_LCD_A_VBMCONTROL_VBMEN_ENABLED_U32|\
      SI32_LCD_A_VBMCONTROL_VBMOEN_ENABLED_U32|\
      0x00000001);\
} while(0)


/// @fn _SI32_LCD_A_select_auto_contrast_auto_bypass_mode(SI32_LCD_A_Type* basePointer)
///
/// @brief
/// Configure LCD the auto-bypass auto-contrast mode. This function sets
/// and clears all the relavent bits.
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_select_auto_contrast_auto_bypass_mode(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_select_auto_contrast_auto_bypass_mode(basePointer)
#define SI32_LCD_A_select_auto_contrast_auto_bypass_mode(basePointer) do{  \
\
      basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_BIASEN_MASK;\
\
      basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_CPFPDEN_MASK;\
\
      basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_CPBEN_MASK;\
\
      basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_CPACEN_MASK;\
\
      basePointer->VBMCONTROL.U32 = (\
      SI32_LCD_A_VBMCONTROL_VBMEN_ENABLED_U32|\
      SI32_LCD_A_VBMCONTROL_VBMOEN_ENABLED_U32|\
      0x00000001);\
} while(0)


/// @fn _SI32_LCD_A_write_config(SI32_LCD_A_Type* basePointer,
///      uint32_t config)
///
/// @brief
/// Write to CONFIG0 register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  config
///  Valid range is 32 bits.
///
void
_SI32_LCD_A_write_config(SI32_LCD_A_Type* /*basePointer*/,
   uint32_t /*config*/);
///
/// @def SI32_LCD_A_write_config(basePointer, config)
#define SI32_LCD_A_write_config(basePointer, config) \
   (basePointer->CONFIG.U32 = config)


/// @fn _SI32_LCD_A_read_config(SI32_LCD_A_Type* basePointer)
///
/// @brief
/// Read from CONFIG0 register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LCD_A_read_config(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_read_config(basePointer)
#define SI32_LCD_A_read_config(basePointer) \
(basePointer->CONFIG.U32)


/// @fn _SI32_LCD_A_enable_charge_pump_full_drive_mode(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_enable_charge_pump_full_drive_mode(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_enable_charge_pump_full_drive_mode(basePointer)
#define SI32_LCD_A_enable_charge_pump_full_drive_mode(basePointer) \
   (basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_CPFPDEN_MASK)


/// @fn _SI32_LCD_A_disable_charge_pump_full_drive_mode(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_disable_charge_pump_full_drive_mode(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_disable_charge_pump_full_drive_mode(basePointer)
#define SI32_LCD_A_disable_charge_pump_full_drive_mode(basePointer) \
   (basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_CPFPDEN_MASK)


/// @fn _SI32_LCD_A_enable_lcd_missing_clock_detector(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_enable_lcd_missing_clock_detector(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_enable_lcd_missing_clock_detector(basePointer)
#define SI32_LCD_A_enable_lcd_missing_clock_detector(basePointer) \
   (basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_MCDEN_MASK)


/// @fn _SI32_LCD_A_disable_lcd_missing_clock_detector(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_disable_lcd_missing_clock_detector(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_disable_lcd_missing_clock_detector(basePointer)
#define SI32_LCD_A_disable_lcd_missing_clock_detector(basePointer) \
   (basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_MCDEN_MASK)


/// @fn _SI32_LCD_A_is_lcd_missing_clock_detector_enabled(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_LCD_A_is_lcd_missing_clock_detector_enabled(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_is_lcd_missing_clock_detector_enabled(basePointer)
#define SI32_LCD_A_is_lcd_missing_clock_detector_enabled(basePointer) \
(basePointer->CONFIG.MCDEN)


/// @fn _SI32_LCD_A_enable_rtc_clock_request(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_enable_rtc_clock_request(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_enable_rtc_clock_request(basePointer)
#define SI32_LCD_A_enable_rtc_clock_request(basePointer) \
   (basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_RTCCEN_MASK)


/// @fn _SI32_LCD_A_disable_rtc_clock_request(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_disable_rtc_clock_request(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_disable_rtc_clock_request(basePointer)
#define SI32_LCD_A_disable_rtc_clock_request(basePointer) \
   (basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_RTCCEN_MASK)


/// @fn _SI32_LCD_A_enable_lcd_bias(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_enable_lcd_bias(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_enable_lcd_bias(basePointer)
#define SI32_LCD_A_enable_lcd_bias(basePointer) \
   (basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_BIASEN_MASK)


/// @fn _SI32_LCD_A_disable_lcd_bias(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_disable_lcd_bias(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_disable_lcd_bias(basePointer)
#define SI32_LCD_A_disable_lcd_bias(basePointer) \
   (basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_BIASEN_MASK)


/// @fn _SI32_LCD_A_is_lcd_bias_enabled(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_LCD_A_is_lcd_bias_enabled(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_is_lcd_bias_enabled(basePointer)
#define SI32_LCD_A_is_lcd_bias_enabled(basePointer) \
(basePointer->CONFIG.BIASEN)


/// @fn _SI32_LCD_A_enable_dcdc_bias(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_enable_dcdc_bias(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_enable_dcdc_bias(basePointer)
#define SI32_LCD_A_enable_dcdc_bias(basePointer) \
   (basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_DCDCBIASEN_MASK)


/// @fn _SI32_LCD_A_disable_dcdc_bias(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_disable_dcdc_bias(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_disable_dcdc_bias(basePointer)
#define SI32_LCD_A_disable_dcdc_bias(basePointer) \
   (basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_DCDCBIASEN_MASK)


/// @fn _SI32_LCD_A_is_dcdc_bias_enabled(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_LCD_A_is_dcdc_bias_enabled(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_is_dcdc_bias_enabled(basePointer)
#define SI32_LCD_A_is_dcdc_bias_enabled(basePointer) \
(basePointer->CONFIG.DCDCBIASEN)


/// @fn _SI32_LCD_A_enable_dcdc_standby(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_enable_dcdc_standby(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_enable_dcdc_standby(basePointer)
#define SI32_LCD_A_enable_dcdc_standby(basePointer) \
   (basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_DCDCSTDBYEN_MASK)


/// @fn _SI32_LCD_A_disable_dcdc_standby(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_disable_dcdc_standby(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_disable_dcdc_standby(basePointer)
#define SI32_LCD_A_disable_dcdc_standby(basePointer) \
   (basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_DCDCSTDBYEN_MASK)


/// @fn _SI32_LCD_A_is_dcdc_standby_enabled(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_LCD_A_is_dcdc_standby_enabled(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_is_dcdc_standby_enabled(basePointer)
#define SI32_LCD_A_is_dcdc_standby_enabled(basePointer) \
(basePointer->CONFIG.DCDCSTDBYEN)


/// @fn _SI32_LCD_A_enable_charge_pump_bypass(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_enable_charge_pump_bypass(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_enable_charge_pump_bypass(basePointer)
#define SI32_LCD_A_enable_charge_pump_bypass(basePointer) \
   (basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_CPBEN_MASK)


/// @fn _SI32_LCD_A_disable_charge_pump_bypass(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_disable_charge_pump_bypass(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_disable_charge_pump_bypass(basePointer)
#define SI32_LCD_A_disable_charge_pump_bypass(basePointer) \
   (basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_CPBEN_MASK)


/// @fn _SI32_LCD_A_enable_high_contrast_voltage_low_power_mode(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_enable_high_contrast_voltage_low_power_mode(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_enable_high_contrast_voltage_low_power_mode(basePointer)
#define SI32_LCD_A_enable_high_contrast_voltage_low_power_mode(basePointer) \
   (basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_HCVLPMEN_MASK)


/// @fn _SI32_LCD_A_disable_high_contrast_voltage_low_power_mode(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_disable_high_contrast_voltage_low_power_mode(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_disable_high_contrast_voltage_low_power_mode(basePointer)
#define SI32_LCD_A_disable_high_contrast_voltage_low_power_mode(basePointer) \
   (basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_HCVLPMEN_MASK)


/// @fn _SI32_LCD_A_enable_vbat_monitor_low_power_mode(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_enable_vbat_monitor_low_power_mode(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_enable_vbat_monitor_low_power_mode(basePointer)
#define SI32_LCD_A_enable_vbat_monitor_low_power_mode(basePointer) \
   (basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_VBMLPEN_MASK)


/// @fn _SI32_LCD_A_disable_vbat_monitor_low_power_mode(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_disable_vbat_monitor_low_power_mode(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_disable_vbat_monitor_low_power_mode(basePointer)
#define SI32_LCD_A_disable_vbat_monitor_low_power_mode(basePointer) \
   (basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_VBMLPEN_MASK)


/// @fn _SI32_LCD_A_enable_charge_pump_oscillator_low_power_mode(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_enable_charge_pump_oscillator_low_power_mode(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_enable_charge_pump_oscillator_low_power_mode(basePointer)
#define SI32_LCD_A_enable_charge_pump_oscillator_low_power_mode(basePointer) \
   (basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_CPOLPEN_MASK)


/// @fn _SI32_LCD_A_disable_charge_pump_oscillator_low_power_mode(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_disable_charge_pump_oscillator_low_power_mode(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_disable_charge_pump_oscillator_low_power_mode(basePointer)
#define SI32_LCD_A_disable_charge_pump_oscillator_low_power_mode(basePointer) \
   (basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_CPOLPEN_MASK)


/// @fn _SI32_LCD_A_enable_comparator_buffer_low_power_mode(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_enable_comparator_buffer_low_power_mode(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_enable_comparator_buffer_low_power_mode(basePointer)
#define SI32_LCD_A_enable_comparator_buffer_low_power_mode(basePointer) \
   (basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_CMPBLPEN_MASK)


/// @fn _SI32_LCD_A_disable_comparator_buffer_low_power_mode(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_disable_comparator_buffer_low_power_mode(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_disable_comparator_buffer_low_power_mode(basePointer)
#define SI32_LCD_A_disable_comparator_buffer_low_power_mode(basePointer) \
   (basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_CMPBLPEN_MASK)


/// @fn _SI32_LCD_A_enable_automatic_bias_switching(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_enable_automatic_bias_switching(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_enable_automatic_bias_switching(basePointer)
#define SI32_LCD_A_enable_automatic_bias_switching(basePointer) \
   (basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_BIASSEN_MASK)


/// @fn _SI32_LCD_A_disable_automatic_bias_switching(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_disable_automatic_bias_switching(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_disable_automatic_bias_switching(basePointer)
#define SI32_LCD_A_disable_automatic_bias_switching(basePointer) \
   (basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_BIASSEN_MASK)


/// @fn _SI32_LCD_A_enable_force_bias_continuous_mode(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_enable_force_bias_continuous_mode(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_enable_force_bias_continuous_mode(basePointer)
#define SI32_LCD_A_enable_force_bias_continuous_mode(basePointer) \
   (basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_FBIASCEN_MASK)


/// @fn _SI32_LCD_A_disable_force_bias_continuous_mode(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_disable_force_bias_continuous_mode(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_disable_force_bias_continuous_mode(basePointer)
#define SI32_LCD_A_disable_force_bias_continuous_mode(basePointer) \
   (basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_FBIASCEN_MASK)


/// @fn _SI32_LCD_A_enable_high_contrast_voltage_comparator_bypass(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_enable_high_contrast_voltage_comparator_bypass(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_enable_high_contrast_voltage_comparator_bypass(basePointer)
#define SI32_LCD_A_enable_high_contrast_voltage_comparator_bypass(basePointer) \
   (basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_HCVCBYPEN_MASK)


/// @fn _SI32_LCD_A_disable_high_contrast_voltage_comparator_bypass(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_disable_high_contrast_voltage_comparator_bypass(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_disable_high_contrast_voltage_comparator_bypass(basePointer)
#define SI32_LCD_A_disable_high_contrast_voltage_comparator_bypass(basePointer) \
   (basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_HCVCBYPEN_MASK)


/// @fn _SI32_LCD_A_enable_high_contrast_voltage_comparator_force_on(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_enable_high_contrast_voltage_comparator_force_on(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_enable_high_contrast_voltage_comparator_force_on(basePointer)
#define SI32_LCD_A_enable_high_contrast_voltage_comparator_force_on(basePointer) \
   (basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_HCVCFOEN_MASK)


/// @fn _SI32_LCD_A_disable_high_contrast_voltage_comparator_force_on(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_disable_high_contrast_voltage_comparator_force_on(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_disable_high_contrast_voltage_comparator_force_on(basePointer)
#define SI32_LCD_A_disable_high_contrast_voltage_comparator_force_on(basePointer) \
   (basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_HCVCFOEN_MASK)


/// @fn _SI32_LCD_A_select_high_contrast_voltage_comparator_high_hysterisis_mode(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_select_high_contrast_voltage_comparator_high_hysterisis_mode(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_select_high_contrast_voltage_comparator_high_hysterisis_mode(basePointer)
#define SI32_LCD_A_select_high_contrast_voltage_comparator_high_hysterisis_mode(basePointer) \
   (basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_HCVCHMD_MASK)


/// @fn _SI32_LCD_A_select_high_contrast_voltage_comparator_low_hysterisis_mode(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_select_high_contrast_voltage_comparator_low_hysterisis_mode(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_select_high_contrast_voltage_comparator_low_hysterisis_mode(basePointer)
#define SI32_LCD_A_select_high_contrast_voltage_comparator_low_hysterisis_mode(basePointer) \
   (basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_HCVCHMD_MASK)


/// @fn _SI32_LCD_A_select_high_contrast_voltage_comparator_high_bias_mode(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_select_high_contrast_voltage_comparator_high_bias_mode(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_select_high_contrast_voltage_comparator_high_bias_mode(basePointer)
#define SI32_LCD_A_select_high_contrast_voltage_comparator_high_bias_mode(basePointer) \
   (basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_HCVCBMD_MASK)


/// @fn _SI32_LCD_A_select_high_contrast_voltage_comparator_low_bias_mode(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_select_high_contrast_voltage_comparator_low_bias_mode(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_select_high_contrast_voltage_comparator_low_bias_mode(basePointer)
#define SI32_LCD_A_select_high_contrast_voltage_comparator_low_bias_mode(basePointer) \
   (basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_HCVCBMD_MASK)


/// @fn _SI32_LCD_A_write_clkcontrol(SI32_LCD_A_Type* basePointer,
///      uint32_t value)
///
/// @brief
/// Write to CLKCONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 32 bits.
///
void
_SI32_LCD_A_write_clkcontrol(SI32_LCD_A_Type* /*basePointer*/,
   uint32_t /*value*/);
///
/// @def SI32_LCD_A_write_clkcontrol(basePointer, value)
#define SI32_LCD_A_write_clkcontrol(basePointer, value) \
   (basePointer->CLKCONTROL.U32 = value)


/// @fn _SI32_LCD_A_read_clkcontrol(SI32_LCD_A_Type* basePointer)
///
/// @brief
/// Read from CLKCONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LCD_A_read_clkcontrol(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_read_clkcontrol(basePointer)
#define SI32_LCD_A_read_clkcontrol(basePointer) \
(basePointer->CLKCONTROL.U32)


/// @fn _SI32_LCD_A_write_clock_divider(SI32_LCD_A_Type* basePointer,
///      uwide16_t value)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 10 bits.
///
void
_SI32_LCD_A_write_clock_divider(SI32_LCD_A_Type* /*basePointer*/,
   uwide16_t /*value*/);
///
/// @def SI32_LCD_A_write_clock_divider(basePointer, value)
#define SI32_LCD_A_write_clock_divider(basePointer, value) \
   (basePointer->CLKCONTROL.CLKDIV = value)


/// @fn _SI32_LCD_A_select_rtc_clock_divider_divide_by_1(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_select_rtc_clock_divider_divide_by_1(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_select_rtc_clock_divider_divide_by_1(basePointer)
#define SI32_LCD_A_select_rtc_clock_divider_divide_by_1(basePointer) do{  \
   basePointer->CLKCONTROL.RTCCLKDIV =\
      SI32_LCD_A_CLKCONTROL_RTCCLKDIV_DIVIDE_BY_1_VALUE;\
} while(0)


/// @fn _SI32_LCD_A_select_rtc_clock_divider_divide_by_2(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_select_rtc_clock_divider_divide_by_2(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_select_rtc_clock_divider_divide_by_2(basePointer)
#define SI32_LCD_A_select_rtc_clock_divider_divide_by_2(basePointer) do{  \
   basePointer->CLKCONTROL.RTCCLKDIV =\
      SI32_LCD_A_CLKCONTROL_RTCCLKDIV_DIVIDE_BY_2_VALUE;\
} while(0)


/// @fn _SI32_LCD_A_select_rtc_clock_divider_divide_by_4(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_select_rtc_clock_divider_divide_by_4(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_select_rtc_clock_divider_divide_by_4(basePointer)
#define SI32_LCD_A_select_rtc_clock_divider_divide_by_4(basePointer) do{  \
   basePointer->CLKCONTROL.RTCCLKDIV =\
      SI32_LCD_A_CLKCONTROL_RTCCLKDIV_DIVIDE_BY_4_VALUE;\
} while(0)


/// @fn _SI32_LCD_A_select_rtc_clock_divider_divide_by_8(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_select_rtc_clock_divider_divide_by_8(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_select_rtc_clock_divider_divide_by_8(basePointer)
#define SI32_LCD_A_select_rtc_clock_divider_divide_by_8(basePointer) do{  \
   basePointer->CLKCONTROL.RTCCLKDIV =\
      SI32_LCD_A_CLKCONTROL_RTCCLKDIV_DIVIDE_BY_8_VALUE;\
} while(0)


/// @fn _SI32_LCD_A_write_blkcontrol(SI32_LCD_A_Type* basePointer,
///      uint32_t value)
///
/// @brief
/// Write to BLKCONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 32 bits.
///
void
_SI32_LCD_A_write_blkcontrol(SI32_LCD_A_Type* /*basePointer*/,
   uint32_t /*value*/);
///
/// @def SI32_LCD_A_write_blkcontrol(basePointer, value)
#define SI32_LCD_A_write_blkcontrol(basePointer, value) \
   (basePointer->BLKCONTROL.U32 = value)


/// @fn _SI32_LCD_A_read_blkcontrol(SI32_LCD_A_Type* basePointer)
///
/// @brief
/// Read from BLKCONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LCD_A_read_blkcontrol(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_read_blkcontrol(basePointer)
#define SI32_LCD_A_read_blkcontrol(basePointer) \
(basePointer->BLKCONTROL.U32)


/// @fn _SI32_LCD_A_write_lcd_blink_mask(SI32_LCD_A_Type* basePointer,
///      uwide8_t value)
///
/// @brief
/// Write to LCD Blink Mask (CTRSTCONTROL[0:4]).
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 8 bits.
///
void
_SI32_LCD_A_write_lcd_blink_mask(SI32_LCD_A_Type* /*basePointer*/,
   uwide8_t /*value*/);
///
/// @def SI32_LCD_A_write_lcd_blink_mask(basePointer, value)
#define SI32_LCD_A_write_lcd_blink_mask(basePointer, value) \
   (basePointer->BLKCONTROL.BLKMASK = value)


/// @fn _SI32_LCD_A_write_lcd_blink_exponent(SI32_LCD_A_Type* basePointer,
///      uwide8_t value)
///
/// @brief
/// Write to LCD Blink Rate (CTRSTCONTROL[0:4]).
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 4 bits.
///
void
_SI32_LCD_A_write_lcd_blink_exponent(SI32_LCD_A_Type* /*basePointer*/,
   uwide8_t /*value*/);
///
/// @def SI32_LCD_A_write_lcd_blink_exponent(basePointer, value)
#define SI32_LCD_A_write_lcd_blink_exponent(basePointer, value) \
   (basePointer->BLKCONTROL.BLKREXP = value)


/// @fn _SI32_LCD_A_write_segcontrol(SI32_LCD_A_Type* basePointer,
///      uint32_t value)
///
/// @brief
/// Write to SEGCONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 32 bits.
///
void
_SI32_LCD_A_write_segcontrol(SI32_LCD_A_Type* /*basePointer*/,
   uint32_t /*value*/);
///
/// @def SI32_LCD_A_write_segcontrol(basePointer, value)
#define SI32_LCD_A_write_segcontrol(basePointer, value) \
   (basePointer->SEGCONTROL.U32 = value)


/// @fn _SI32_LCD_A_read_segcontrol(SI32_LCD_A_Type* basePointer)
///
/// @brief
/// Read from SEGCONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LCD_A_read_segcontrol(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_read_segcontrol(basePointer)
#define SI32_LCD_A_read_segcontrol(basePointer) \
(basePointer->SEGCONTROL.U32)


/// @fn _SI32_LCD_A_select_one_third_bias(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_select_one_third_bias(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_select_one_third_bias(basePointer)
#define SI32_LCD_A_select_one_third_bias(basePointer) do{  \
   basePointer->SEGCONTROL.BIASMD =\
      SI32_LCD_A_SEGCONTROL_BIASMD_ONE_THIRD_VALUE;\
} while(0)


/// @fn _SI32_LCD_A_select_one_half_bias(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_select_one_half_bias(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_select_one_half_bias(basePointer)
#define SI32_LCD_A_select_one_half_bias(basePointer) do{  \
   basePointer->SEGCONTROL.BIASMD =\
      SI32_LCD_A_SEGCONTROL_BIASMD_ONE_HALF_VALUE;\
} while(0)


/// @fn _SI32_LCD_A_select_segment_mode_static(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_select_segment_mode_static(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_select_segment_mode_static(basePointer)
#define SI32_LCD_A_select_segment_mode_static(basePointer) do{  \
   basePointer->SEGCONTROL.SEGMD =\
      SI32_LCD_A_SEGCONTROL_SEGMD_STATIC_VALUE;\
} while(0)


/// @fn _SI32_LCD_A_select_segment_mode_2_mux(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_select_segment_mode_2_mux(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_select_segment_mode_2_mux(basePointer)
#define SI32_LCD_A_select_segment_mode_2_mux(basePointer) do{  \
   basePointer->SEGCONTROL.SEGMD =\
      SI32_LCD_A_SEGCONTROL_SEGMD_2_MUX_VALUE;\
} while(0)


/// @fn _SI32_LCD_A_select_segment_mode_3_mux(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_select_segment_mode_3_mux(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_select_segment_mode_3_mux(basePointer)
#define SI32_LCD_A_select_segment_mode_3_mux(basePointer) do{  \
   basePointer->SEGCONTROL.SEGMD =\
      SI32_LCD_A_SEGCONTROL_SEGMD_3_MUX_VALUE;\
} while(0)


/// @fn _SI32_LCD_A_select_segment_mode_4_mux(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_select_segment_mode_4_mux(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_select_segment_mode_4_mux(basePointer)
#define SI32_LCD_A_select_segment_mode_4_mux(basePointer) do{  \
   basePointer->SEGCONTROL.SEGMD =\
      SI32_LCD_A_SEGCONTROL_SEGMD_4_MUX_VALUE;\
} while(0)


/// @fn _SI32_LCD_A_enable_blank_all_segments(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_enable_blank_all_segments(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_enable_blank_all_segments(basePointer)
#define SI32_LCD_A_enable_blank_all_segments(basePointer) do{  \
   basePointer->SEGCONTROL.BLANKEN =\
      SI32_LCD_A_SEGCONTROL_BLANKEN_ENABLED_VALUE;\
} while(0)


/// @fn _SI32_LCD_A_disable_blank_all_segments(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_disable_blank_all_segments(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_disable_blank_all_segments(basePointer)
#define SI32_LCD_A_disable_blank_all_segments(basePointer) do{  \
   basePointer->SEGCONTROL.BLANKEN =\
      SI32_LCD_A_SEGCONTROL_BLANKEN_DISABLED_VALUE;\
} while(0)


/// @fn _SI32_LCD_A_enable_reset_phase(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_enable_reset_phase(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_enable_reset_phase(basePointer)
#define SI32_LCD_A_enable_reset_phase(basePointer) \
   (basePointer->SEGCONTROL.RPHEN = SI32_LCD_A_SEGCONTROL_RPHEN_ENABLED_VALUE)


/// @fn _SI32_LCD_A_disable_reset_phase(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_disable_reset_phase(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_disable_reset_phase(basePointer)
#define SI32_LCD_A_disable_reset_phase(basePointer) \
   (basePointer->SEGCONTROL.RPHEN = SI32_LCD_A_SEGCONTROL_RPHEN_DISABLED_VALUE)


/// @fn _SI32_LCD_A_write_reset_phase_count_u8(SI32_LCD_A_Type* basePointer,
///      uwide8_t value)
///
/// @brief
/// Write to Reset Phase Count.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 3 bits.
///
void
_SI32_LCD_A_write_reset_phase_count_u8(SI32_LCD_A_Type* /*basePointer*/,
   uwide8_t /*value*/);
///
/// @def SI32_LCD_A_write_reset_phase_count_u8(basePointer, value)
#define SI32_LCD_A_write_reset_phase_count_u8(basePointer, value) \
   (basePointer->SEGCONTROL.RPHMD = value)


/// @fn _SI32_LCD_A_write_ctrstcontrol(SI32_LCD_A_Type* basePointer,
///      uint32_t value)
///
/// @brief
/// Write to CTRSTCONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 32 bits.
///
void
_SI32_LCD_A_write_ctrstcontrol(SI32_LCD_A_Type* /*basePointer*/,
   uint32_t /*value*/);
///
/// @def SI32_LCD_A_write_ctrstcontrol(basePointer, value)
#define SI32_LCD_A_write_ctrstcontrol(basePointer, value) \
   (basePointer->CTRSTCONTROL.U32 = value)


/// @fn _SI32_LCD_A_read_ctrstcontrol(SI32_LCD_A_Type* basePointer)
///
/// @brief
/// Read from CTRSTCONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LCD_A_read_ctrstcontrol(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_read_ctrstcontrol(basePointer)
#define SI32_LCD_A_read_ctrstcontrol(basePointer) \
(basePointer->CTRSTCONTROL.U32)


/// @fn _SI32_LCD_A_write_lcd_contrast(SI32_LCD_A_Type* basePointer,
///      uwide8_t value)
///
/// @brief
/// Write to LCD Contrast (CTRSTCONTROL[0:4]).
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 5 bits.
///
void
_SI32_LCD_A_write_lcd_contrast(SI32_LCD_A_Type* /*basePointer*/,
   uwide8_t /*value*/);
///
/// @def SI32_LCD_A_write_lcd_contrast(basePointer, value)
#define SI32_LCD_A_write_lcd_contrast(basePointer, value) \
   (basePointer->CTRSTCONTROL.CTRST = value)


/// @fn _SI32_LCD_A_write_vbmcontrol(SI32_LCD_A_Type* basePointer,
///      uint32_t value)
///
/// @brief
/// Write to VBMCONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 32 bits.
///
void
_SI32_LCD_A_write_vbmcontrol(SI32_LCD_A_Type* /*basePointer*/,
   uint32_t /*value*/);
///
/// @def SI32_LCD_A_write_vbmcontrol(basePointer, value)
#define SI32_LCD_A_write_vbmcontrol(basePointer, value) \
   (basePointer->VBMCONTROL.U32 = value)


/// @fn _SI32_LCD_A_read_vbmcontrol(SI32_LCD_A_Type* basePointer)
///
/// @brief
/// Read from VBMCONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LCD_A_read_vbmcontrol(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_read_vbmcontrol(basePointer)
#define SI32_LCD_A_read_vbmcontrol(basePointer) \
(basePointer->VBMCONTROL.U32)


/// @fn _SI32_LCD_A_write_vbat_monitor_threshold(SI32_LCD_A_Type* basePointer,
///      uwide8_t value)
///
/// @brief
/// Write to VMON Threshold (VBMON_CN[0:4]).
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 5 bits.
///
void
_SI32_LCD_A_write_vbat_monitor_threshold(SI32_LCD_A_Type* /*basePointer*/,
   uwide8_t /*value*/);
///
/// @def SI32_LCD_A_write_vbat_monitor_threshold(basePointer, value)
#define SI32_LCD_A_write_vbat_monitor_threshold(basePointer, value) \
   (basePointer->VBMCONTROL.VBMTH = value)


/// @fn _SI32_LCD_A_enable_vbat_monitor_capacitor_divider(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_enable_vbat_monitor_capacitor_divider(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_enable_vbat_monitor_capacitor_divider(basePointer)
#define SI32_LCD_A_enable_vbat_monitor_capacitor_divider(basePointer) \
   (basePointer->VBMCONTROL.VBMCDEN = SI32_LCD_A_VBMCONTROL_VBMCDEN_ENABLED_VALUE)


/// @fn _SI32_LCD_A_disable_vbat_monitor_capacitor_divider(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_disable_vbat_monitor_capacitor_divider(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_disable_vbat_monitor_capacitor_divider(basePointer)
#define SI32_LCD_A_disable_vbat_monitor_capacitor_divider(basePointer) \
   (basePointer->VBMCONTROL.VBMCDEN = SI32_LCD_A_VBMCONTROL_VBMCDEN_DISABLED_VALUE)


/// @fn _SI32_LCD_A_enable_vbat_monitor_offset(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_enable_vbat_monitor_offset(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_enable_vbat_monitor_offset(basePointer)
#define SI32_LCD_A_enable_vbat_monitor_offset(basePointer) \
   (basePointer->VBMCONTROL.VBMOEN = SI32_LCD_A_VBMCONTROL_VBMOEN_ENABLED_VALUE)


/// @fn _SI32_LCD_A_disable_vbat_monitor_offset(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_disable_vbat_monitor_offset(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_disable_vbat_monitor_offset(basePointer)
#define SI32_LCD_A_disable_vbat_monitor_offset(basePointer) \
   (basePointer->VBMCONTROL.VBMOEN = SI32_LCD_A_VBMCONTROL_VBMOEN_DISABLED_VALUE)


/// @fn _SI32_LCD_A_enable_vbat_monitor(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_enable_vbat_monitor(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_enable_vbat_monitor(basePointer)
#define SI32_LCD_A_enable_vbat_monitor(basePointer) \
   (basePointer->VBMCONTROL.VBMEN = SI32_LCD_A_VBMCONTROL_VBMEN_ENABLED_VALUE)


/// @fn _SI32_LCD_A_disable_vbat_monitor(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_disable_vbat_monitor(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_disable_vbat_monitor(basePointer)
#define SI32_LCD_A_disable_vbat_monitor(basePointer) \
   (basePointer->VBMCONTROL.VBMEN = SI32_LCD_A_VBMCONTROL_VBMEN_DISABLED_VALUE)


/// @fn _SI32_LCD_A_is_vbat_monitor_enabled(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_LCD_A_is_vbat_monitor_enabled(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_is_vbat_monitor_enabled(basePointer)
#define SI32_LCD_A_is_vbat_monitor_enabled(basePointer) \
((basePointer->VBMCONTROL.VBMEN))


/// @fn _SI32_LCD_A_write_segmask0(SI32_LCD_A_Type* basePointer,
///      uint32_t value)
///
/// @brief
/// Write to SEGMASK0 word.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 32 bits.
///
void
_SI32_LCD_A_write_segmask0(SI32_LCD_A_Type* /*basePointer*/,
   uint32_t /*value*/);
///
/// @def SI32_LCD_A_write_segmask0(basePointer, value)
#define SI32_LCD_A_write_segmask0(basePointer, value) \
   (basePointer->SEGMASK0.U32 = value)


/// @fn _SI32_LCD_A_read_segmask0(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LCD_A_read_segmask0(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_read_segmask0(basePointer)
#define SI32_LCD_A_read_segmask0(basePointer) \
(basePointer->SEGMASK0.U32)


/// @fn _SI32_LCD_A_write_segmask1(SI32_LCD_A_Type* basePointer,
///      uwide8_t value)
///
/// @brief
/// Write to SEGMASK1 word.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 8 bits.
///
void
_SI32_LCD_A_write_segmask1(SI32_LCD_A_Type* /*basePointer*/,
   uwide8_t /*value*/);
///
/// @def SI32_LCD_A_write_segmask1(basePointer, value)
#define SI32_LCD_A_write_segmask1(basePointer, value) \
   (basePointer->SEGMASK1.SEGEN = value)


/// @fn _SI32_LCD_A_read_segmask1(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_LCD_A_read_segmask1(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_read_segmask1(basePointer)
#define SI32_LCD_A_read_segmask1(basePointer) \
(basePointer->SEGMASK1.SEGEN)


/// @fn _SI32_LCD_A_write_number_of_segments(SI32_LCD_A_Type* basePointer,
///      uwide8_t value)
///
/// @brief
/// Enable block of contiguous segments with number of segments specified.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 0 to 40.
///
void
_SI32_LCD_A_write_number_of_segments(SI32_LCD_A_Type* /*basePointer*/,
   uwide8_t /*value*/);
///
/// @def SI32_LCD_A_write_number_of_segments(basePointer, value)
#define SI32_LCD_A_write_number_of_segments(basePointer, value) \
   _SI32_LCD_A_write_number_of_segments(basePointer, value) 


/// @fn _SI32_LCD_A_write_segdata0(SI32_LCD_A_Type* basePointer,
///      uint32_t value)
///
/// @brief
/// Write to SEGDATA0.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 32 bits.
///
void
_SI32_LCD_A_write_segdata0(SI32_LCD_A_Type* /*basePointer*/,
   uint32_t /*value*/);
///
/// @def SI32_LCD_A_write_segdata0(basePointer, value)
#define SI32_LCD_A_write_segdata0(basePointer, value) \
   (basePointer->SEGDATA0.U32 = value)


/// @fn _SI32_LCD_A_read_segdata0(SI32_LCD_A_Type* basePointer)
///
/// @brief
/// Read from SEGDATA0.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LCD_A_read_segdata0(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_read_segdata0(basePointer)
#define SI32_LCD_A_read_segdata0(basePointer) \
(basePointer->SEGDATA0.U32)


/// @fn _SI32_LCD_A_write_segdata1(SI32_LCD_A_Type* basePointer,
///      uint32_t value)
///
/// @brief
/// Write to SEGDATA1.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 32 bits.
///
void
_SI32_LCD_A_write_segdata1(SI32_LCD_A_Type* /*basePointer*/,
   uint32_t /*value*/);
///
/// @def SI32_LCD_A_write_segdata1(basePointer, value)
#define SI32_LCD_A_write_segdata1(basePointer, value) \
   (basePointer->SEGDATA1.U32 = value)


/// @fn _SI32_LCD_A_read_segdata1(SI32_LCD_A_Type* basePointer)
///
/// @brief
/// Read from SEGDATA1.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LCD_A_read_segdata1(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_read_segdata1(basePointer)
#define SI32_LCD_A_read_segdata1(basePointer) \
(basePointer->SEGDATA1.U32)


/// @fn _SI32_LCD_A_write_segdata2(SI32_LCD_A_Type* basePointer,
///      uint32_t value)
///
/// @brief
/// Write to SEGDATA2.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 32 bits.
///
void
_SI32_LCD_A_write_segdata2(SI32_LCD_A_Type* /*basePointer*/,
   uint32_t /*value*/);
///
/// @def SI32_LCD_A_write_segdata2(basePointer, value)
#define SI32_LCD_A_write_segdata2(basePointer, value) \
   (basePointer->SEGDATA2.U32 = value)


/// @fn _SI32_LCD_A_read_segdata2(SI32_LCD_A_Type* basePointer)
///
/// @brief
/// Read from SEGDATA2.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LCD_A_read_segdata2(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_read_segdata2(basePointer)
#define SI32_LCD_A_read_segdata2(basePointer) \
(basePointer->SEGDATA2.U32)


/// @fn _SI32_LCD_A_write_segdata3(SI32_LCD_A_Type* basePointer,
///      uint32_t value)
///
/// @brief
/// Write to SEGDATA3.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 32 bits.
///
void
_SI32_LCD_A_write_segdata3(SI32_LCD_A_Type* /*basePointer*/,
   uint32_t /*value*/);
///
/// @def SI32_LCD_A_write_segdata3(basePointer, value)
#define SI32_LCD_A_write_segdata3(basePointer, value) \
   (basePointer->SEGDATA3.U32 = value)


/// @fn _SI32_LCD_A_read_segdata3(SI32_LCD_A_Type* basePointer)
///
/// @brief
/// Read from SEGDATA3.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LCD_A_read_segdata3(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_read_segdata3(basePointer)
#define SI32_LCD_A_read_segdata3(basePointer) \
(basePointer->SEGDATA3.U32)


/// @fn _SI32_LCD_A_write_segdata4(SI32_LCD_A_Type* basePointer,
///      uint32_t value)
///
/// @brief
/// Write to SEGDATA4.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 32 bits.
///
void
_SI32_LCD_A_write_segdata4(SI32_LCD_A_Type* /*basePointer*/,
   uint32_t /*value*/);
///
/// @def SI32_LCD_A_write_segdata4(basePointer, value)
#define SI32_LCD_A_write_segdata4(basePointer, value) \
   (basePointer->SEGDATA4.U32 = value)


/// @fn _SI32_LCD_A_read_segdata4(SI32_LCD_A_Type* basePointer)
///
/// @brief
/// Read from SEGDATA4.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LCD_A_read_segdata4(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_read_segdata4(basePointer)
#define SI32_LCD_A_read_segdata4(basePointer) \
(basePointer->SEGDATA4.U32)


/// @fn _SI32_LCD_A_clear_all_segment_data(SI32_LCD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LCD_A_clear_all_segment_data(SI32_LCD_A_Type* /*basePointer*/);
///
/// @def SI32_LCD_A_clear_all_segment_data(basePointer)
#define SI32_LCD_A_clear_all_segment_data(basePointer) do{  \
      basePointer->SEGDATA0.U32 = 0x00000000;\
      basePointer->SEGDATA1.U32 = 0x00000000;\
      basePointer->SEGDATA2.U32 = 0x00000000;\
      basePointer->SEGDATA3.U32 = 0x00000000;\
      basePointer->SEGDATA4.U32 = 0x00000000;\
} while(0)


/// @fn _SI32_LCD_A_write_segment_data_u32(SI32_LCD_A_Type* basePointer,
///      uint32_t value,
///      uwide8_t index)
///
/// @brief
/// Write to LCD segment data word using index.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 32 bits.
///
/// @param[in]
///  index
///  Valid range is 0 to 4.
///
void
_SI32_LCD_A_write_segment_data_u32(SI32_LCD_A_Type* /*basePointer*/,
   uint32_t, /*value*/
   uwide8_t /*index*/);
///
/// @def SI32_LCD_A_write_segment_data_u32(basePointer, value, index)
#define SI32_LCD_A_write_segment_data_u32(basePointer, value, index) \
   _SI32_LCD_A_write_segment_data_u32(basePointer, value, index) 


/// @fn _SI32_LCD_A_write_segment_data_u16(SI32_LCD_A_Type* basePointer,
///      uwide16_t value,
///      uwide8_t index)
///
/// @brief
/// Write to LCD segment data half-word using index.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 16 bits.
///
/// @param[in]
///  index
///  Valid range is 0 to 9.
///
void
_SI32_LCD_A_write_segment_data_u16(SI32_LCD_A_Type* /*basePointer*/,
   uwide16_t, /*value*/
   uwide8_t /*index*/);
///
/// @def SI32_LCD_A_write_segment_data_u16(basePointer, value, index)
#define SI32_LCD_A_write_segment_data_u16(basePointer, value, index) \
   _SI32_LCD_A_write_segment_data_u16(basePointer, value, index) 


/// @fn _SI32_LCD_A_write_segment_data_u8(SI32_LCD_A_Type* basePointer,
///      uwide8_t value,
///      uwide8_t index)
///
/// @brief
/// Write to LCD segment data byte using index.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 8 bits.
///
/// @param[in]
///  index
///  Valid range is 0 to 19.
///
void
_SI32_LCD_A_write_segment_data_u8(SI32_LCD_A_Type* /*basePointer*/,
   uwide8_t, /*value*/
   uwide8_t /*index*/);
///
/// @def SI32_LCD_A_write_segment_data_u8(basePointer, value, index)
#define SI32_LCD_A_write_segment_data_u8(basePointer, value, index) \
   _SI32_LCD_A_write_segment_data_u8(basePointer, value, index) 


/// @fn _SI32_LCD_A_read_segment_data_u32(SI32_LCD_A_Type* basePointer,
///      uwide8_t index)
///
/// @brief
/// Read LCD segment data word using index.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  index
///  Valid range is 0 to 4.
///
uint32_t
_SI32_LCD_A_read_segment_data_u32(SI32_LCD_A_Type* /*basePointer*/,
   uwide8_t /*index*/);
///
/// @def SI32_LCD_A_read_segment_data_u32(basePointer, index)
#define SI32_LCD_A_read_segment_data_u32(basePointer, index) \
   _SI32_LCD_A_read_segment_data_u32(basePointer, index) 


/// @fn _SI32_LCD_A_read_segment_data_u16(SI32_LCD_A_Type* basePointer,
///      uwide8_t index)
///
/// @brief
/// Read LCD segment data half-word using index.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  index
///  Valid range is 0 to 9.
///
uwide16_t
_SI32_LCD_A_read_segment_data_u16(SI32_LCD_A_Type* /*basePointer*/,
   uwide8_t /*index*/);
///
/// @def SI32_LCD_A_read_segment_data_u16(basePointer, index)
#define SI32_LCD_A_read_segment_data_u16(basePointer, index) \
   _SI32_LCD_A_read_segment_data_u16(basePointer, index) 


/// @fn _SI32_LCD_A_read_segment_data_u8(SI32_LCD_A_Type* basePointer,
///      uwide8_t index)
///
/// @brief
/// Read LCD segment data half-word using index.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  index
///  Valid range is 0 to 19.
///
uwide8_t
_SI32_LCD_A_read_segment_data_u8(SI32_LCD_A_Type* /*basePointer*/,
   uwide8_t /*index*/);
///
/// @def SI32_LCD_A_read_segment_data_u8(basePointer, index)
#define SI32_LCD_A_read_segment_data_u8(basePointer, index) \
   _SI32_LCD_A_read_segment_data_u8(basePointer, index) 


/// @fn _SI32_LCD_A_set_segment_bit(SI32_LCD_A_Type* basePointer,
///      uwide8_t index)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  index
///  Valid range is 0 to 159.
///  Set segment bit (0 thorugh 159).
///
void
_SI32_LCD_A_set_segment_bit(SI32_LCD_A_Type* /*basePointer*/,
   uwide8_t /*index*/);
///
/// @def SI32_LCD_A_set_segment_bit(basePointer, index)
#define SI32_LCD_A_set_segment_bit(basePointer, index) \
   _SI32_LCD_A_set_segment_bit(basePointer, index) 


/// @fn _SI32_LCD_A_clear_segment_bit(SI32_LCD_A_Type* basePointer,
///      uwide8_t index)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  index
///  Valid range is 0 to 159.
///  Set segment bit (0 thorugh 159).
///
void
_SI32_LCD_A_clear_segment_bit(SI32_LCD_A_Type* /*basePointer*/,
   uwide8_t /*index*/);
///
/// @def SI32_LCD_A_clear_segment_bit(basePointer, index)
#define SI32_LCD_A_clear_segment_bit(basePointer, index) \
   _SI32_LCD_A_clear_segment_bit(basePointer, index) 



#ifdef __cplusplus
}
#endif

#endif // __SI32_LCD_A_TYPE_H__

//-eof--------------------------------------------------------------------------
