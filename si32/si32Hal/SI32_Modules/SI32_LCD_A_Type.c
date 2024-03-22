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
/// @file SI32_LCD_A_Type.c
//
// Script: 0.58
// HAL Source: 0.1
// Version: 12

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_LCD_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_LCD_A_reset_module
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_reset_module(
   SI32_LCD_A_Type * basePointer)
{
   //{{
         basePointer->CONFIG.U32       = 0x000C7E35;
         basePointer->CLKCONTROL.U32   = 0x14B0FC00;
         basePointer->CTRSTCONTROL.U32 = 0x32800000;
         basePointer->VBMCONTROL.U32   = 0xE2C00000;
         basePointer->BLKCONTROL.U32   = 0x00000000;
         basePointer->SEGCONTROL.U32   = 0x00000000;
         basePointer->SEGMASK0.U32     = 0x00000000;
         basePointer->SEGMASK1.U32     = 0x00000000;
         basePointer->SEGDATA0.U32     = 0x00000000;
         basePointer->SEGDATA1.U32     = 0x00000000;
         basePointer->SEGDATA2.U32     = 0x00000000;
         basePointer->SEGDATA3.U32     = 0x00000000;
         basePointer->SEGDATA4.U32     = 0x00000000;
      //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_initialize_module
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_initialize_module(
   SI32_LCD_A_Type * basePointer,
   uint32_t config0,
   uint32_t clock_control,
   uint32_t write_blink_control,
   uint32_t segment_control,
   uint32_t write_contrast_control,
   uint32_t vbat_monitor_control,
   uint32_t segment_mask_0,
   uint32_t segment_mask_1)
{
   //{{
   basePointer->CONFIG.U32 = config0;
   basePointer->CLKCONTROL.U32 = clock_control;
   basePointer->BLKCONTROL.U32 = write_blink_control;
   basePointer->SEGCONTROL.U32 = segment_control;
   basePointer->CTRSTCONTROL.U32 = write_contrast_control;
   basePointer->VBMCONTROL.U32 = vbat_monitor_control;
   basePointer->SEGMASK0.U32 = segment_mask_0;
   basePointer->SEGMASK1.U32 = segment_mask_1;
   basePointer->SEGDATA0.U32 = 0x00000000;
   basePointer->SEGDATA1.U32 = 0x00000000;
   basePointer->SEGDATA2.U32 = 0x00000000;
   basePointer->SEGDATA3.U32 = 0x00000000;
   basePointer->SEGDATA4.U32 = 0x00000000;

   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_enable_module
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_enable_module(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_LCDEN_MASK;
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_RTCCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_disable_module
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_disable_module(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_LCDEN_MASK;
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_RTCCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_is_module_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_LCD_A_is_module_enabled(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   return basePointer->CONFIG.LCDEN;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_select_static_mode
//
// Configure LCD for static mode. This function sets and clears all the
// relavent bits.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_select_static_mode(
   SI32_LCD_A_Type * basePointer)
{
   //{{

   // select static mode
   basePointer->SEGCONTROL.SEGMD =
      SI32_LCD_A_SEGCONTROL_SEGMD_STATIC_VALUE;

   // Reset bias mode.
   basePointer->SEGCONTROL.BIASMD =
      SI32_LCD_A_SEGCONTROL_BIASMD_ONE_THIRD_VALUE;

   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_select_2_mux_mode
//
// Configure LCD for 2-mux mode. This function sets and clears all the
// relavent bits.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_select_2_mux_mode(
   SI32_LCD_A_Type * basePointer)
{
   //{{

   // select 2-mux mode
   basePointer->SEGCONTROL.SEGMD =
      SI32_LCD_A_SEGCONTROL_SEGMD_2_MUX_VALUE;

   // 2-mux mode requires one-half bias
   basePointer->SEGCONTROL.BIASMD =
      SI32_LCD_A_SEGCONTROL_BIASMD_ONE_HALF_VALUE;

   // enable bias
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_BIASEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_select_3_mux_mode
//
// Configure LCD for 3-mux mode. This function sets and clears all the
// relavent bits.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_select_3_mux_mode(
   SI32_LCD_A_Type * basePointer)
{
   //{{

   // select 3-mux mode
   basePointer->SEGCONTROL.SEGMD =
      SI32_LCD_A_SEGCONTROL_SEGMD_3_MUX_VALUE;

   // 3-mux mode requires one-third bias
   basePointer->SEGCONTROL.BIASMD =
      SI32_LCD_A_SEGCONTROL_BIASMD_ONE_THIRD_VALUE;

   // enable bias
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_BIASEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_select_4_mux_mode
//
// Configure LCD for 4-mux mode. This function sets and clears all the
// relavent bits.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_select_4_mux_mode(
   SI32_LCD_A_Type * basePointer)
{
   //{{

   // select 4-mux mode
   basePointer->SEGCONTROL.SEGMD =
      SI32_LCD_A_SEGCONTROL_SEGMD_4_MUX_VALUE;

   // 4-mux mode requires one-third bias
   basePointer->SEGCONTROL.BIASMD =
      SI32_LCD_A_SEGCONTROL_BIASMD_ONE_THIRD_VALUE;

   // enable bias
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_BIASEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_select_auto_contrast_bypass_mode
//
// Configure LCD the bypass auto-contrast mode. This function sets and
// clears all the relavent bits.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_select_auto_contrast_bypass_mode(
   SI32_LCD_A_Type * basePointer)
{
   //{{

   // disable full-power charge pump
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_CPFPDEN_MASK;

   // enable charge pump bypass
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_CPBEN_MASK;

   // clear charge pump auto-contrast mode
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_CPACEN_MASK;

   // Disable VBAT monitor
   basePointer->VBMCONTROL.VBMEN = SI32_LCD_A_VBMCONTROL_VBMOEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_select_auto_contrast_minimum_contrast_mode
//
// Configure LCD the minimum-contrast auto-contrast mode. This function
// sets and clears all the relavent bits.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_select_auto_contrast_minimum_contrast_mode(
   SI32_LCD_A_Type * basePointer)
{
   //{{

   // enable bias
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_BIASEN_MASK;

   // disable full-power charge pump
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_CPFPDEN_MASK;

   // enable charge pump bypass
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_CPBEN_MASK;

   // enable charge pump auto-contrast mode
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_CPACEN_MASK;

   // Enable Vbat monitor, offset mode, add 1 count.
   basePointer->VBMCONTROL.U32 = (
      SI32_LCD_A_VBMCONTROL_VBMEN_ENABLED_U32|
      SI32_LCD_A_VBMCONTROL_VBMOEN_ENABLED_U32|
      0x00000001);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_select_auto_contrast_constant_contrast_mode
//
// Configure LCD the constant-contrast auto-contrast mode. This function
// sets and clears all the relavent bits.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_select_auto_contrast_constant_contrast_mode(
   SI32_LCD_A_Type * basePointer)
{
   //{{

   // enable bias
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_BIASEN_MASK;

   // enable full-power charge pump
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_CPFPDEN_MASK;

   // disable charge pump bypass
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_CPBEN_MASK;

   // enable charge pump auto-contrast mode
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_CPACEN_MASK;

   // Enable Vbat monitor, offset mode, add 1 count.
   basePointer->VBMCONTROL.U32 = (
      SI32_LCD_A_VBMCONTROL_VBMEN_ENABLED_U32|
      SI32_LCD_A_VBMCONTROL_VBMOEN_ENABLED_U32|
      0x00000001);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_select_auto_contrast_auto_bypass_mode
//
// Configure LCD the auto-bypass auto-contrast mode. This function sets
// and clears all the relavent bits.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_select_auto_contrast_auto_bypass_mode(
   SI32_LCD_A_Type * basePointer)
{
   //{{

   // enable bias
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_BIASEN_MASK;

   // enable full-power charge pump
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_CPFPDEN_MASK;

   // disable charge pump bypass
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_CPBEN_MASK;

   // clear charge pump auto-contrast mode
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_CPACEN_MASK;

   // Enable Vbat monitor, offset mode, add 1 count.
   basePointer->VBMCONTROL.U32 = (
      SI32_LCD_A_VBMCONTROL_VBMEN_ENABLED_U32|
      SI32_LCD_A_VBMCONTROL_VBMOEN_ENABLED_U32|
      0x00000001);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_write_config
//
// Write to CONFIG register.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_write_config(
   SI32_LCD_A_Type * basePointer,
   uint32_t config)
{
   //{{
   basePointer->CONFIG.U32 = config;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_read_config
//
// Read from CONFIG register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_LCD_A_read_config(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   return basePointer->CONFIG.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_enable_charge_pump_full_drive_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_enable_charge_pump_full_drive_mode(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_CPFPDEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_disable_charge_pump_full_drive_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_disable_charge_pump_full_drive_mode(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_CPFPDEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_enable_lcd_missing_clock_detector
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_enable_lcd_missing_clock_detector(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_MCDEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_disable_lcd_missing_clock_detector
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_disable_lcd_missing_clock_detector(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_MCDEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_is_lcd_missing_clock_detector_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_LCD_A_is_lcd_missing_clock_detector_enabled(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   return basePointer->CONFIG.MCDEN;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_enable_rtc_clock_request
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_enable_rtc_clock_request(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_RTCCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_disable_rtc_clock_request
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_disable_rtc_clock_request(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_RTCCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_enable_lcd_bias
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_enable_lcd_bias(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_BIASEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_disable_lcd_bias
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_disable_lcd_bias(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_BIASEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_is_lcd_bias_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_LCD_A_is_lcd_bias_enabled(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   return basePointer->CONFIG.BIASEN;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_enable_dcdc_bias
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_enable_dcdc_bias(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_DCDCBIASEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_disable_dcdc_bias
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_disable_dcdc_bias(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_DCDCBIASEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_is_dcdc_bias_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_LCD_A_is_dcdc_bias_enabled(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   return basePointer->CONFIG.DCDCBIASEN;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_enable_dcdc_standby
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_enable_dcdc_standby(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_DCDCSTDBYEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_disable_dcdc_standby
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_disable_dcdc_standby(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_DCDCSTDBYEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_is_dcdc_standby_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_LCD_A_is_dcdc_standby_enabled(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   return basePointer->CONFIG.DCDCSTDBYEN;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_enable_charge_pump_bypass
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_enable_charge_pump_bypass(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_CPBEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_disable_charge_pump_bypass
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_disable_charge_pump_bypass(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_CPBEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_enable_high_contrast_voltage_low_power_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_enable_high_contrast_voltage_low_power_mode(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_HCVLPMEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_disable_high_contrast_voltage_low_power_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_disable_high_contrast_voltage_low_power_mode(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_HCVLPMEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_enable_vbat_monitor_low_power_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_enable_vbat_monitor_low_power_mode(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_VBMLPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_disable_vbat_monitor_low_power_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_disable_vbat_monitor_low_power_mode(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_VBMLPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_enable_charge_pump_oscillator_low_power_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_enable_charge_pump_oscillator_low_power_mode(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_CPOLPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_disable_charge_pump_oscillator_low_power_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_disable_charge_pump_oscillator_low_power_mode(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_CPOLPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_enable_comparator_buffer_low_power_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_enable_comparator_buffer_low_power_mode(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_CMPBLPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_disable_comparator_buffer_low_power_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_disable_comparator_buffer_low_power_mode(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_CMPBLPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_enable_automatic_bias_switching
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_enable_automatic_bias_switching(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_BIASSEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_disable_automatic_bias_switching
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_disable_automatic_bias_switching(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_BIASSEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_enable_force_bias_continuous_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_enable_force_bias_continuous_mode(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_FBIASCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_disable_force_bias_continuous_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_disable_force_bias_continuous_mode(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_FBIASCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_enable_high_contrast_voltage_comparator_bypass
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_enable_high_contrast_voltage_comparator_bypass(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_HCVCBYPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_disable_high_contrast_voltage_comparator_bypass
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_disable_high_contrast_voltage_comparator_bypass(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_HCVCBYPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_enable_high_contrast_voltage_comparator_force_on
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_enable_high_contrast_voltage_comparator_force_on(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_HCVCFOEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_disable_high_contrast_voltage_comparator_force_on
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_disable_high_contrast_voltage_comparator_force_on(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_HCVCFOEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_select_high_contrast_voltage_comparator_high_hysterisis_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_select_high_contrast_voltage_comparator_high_hysterisis_mode(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_HCVCHMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_select_high_contrast_voltage_comparator_low_hysterisis_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_select_high_contrast_voltage_comparator_low_hysterisis_mode(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_HCVCHMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_select_high_contrast_voltage_comparator_high_bias_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_select_high_contrast_voltage_comparator_high_bias_mode(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_LCD_A_CONFIG_HCVCBMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_select_high_contrast_voltage_comparator_low_bias_mode
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_select_high_contrast_voltage_comparator_low_bias_mode(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_LCD_A_CONFIG_HCVCBMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_write_clkcontrol
//
// Write to CLKCONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_write_clkcontrol(
   SI32_LCD_A_Type * basePointer,
   uint32_t value)
{
   //{{
   basePointer->CLKCONTROL.U32 = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_read_clkcontrol
//
// Read from CLKCONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_LCD_A_read_clkcontrol(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   return basePointer->CLKCONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_write_clock_divider
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_write_clock_divider(
   SI32_LCD_A_Type * basePointer,
   uwide16_t value)
{
   assert(value < 1024);   // value < 2^10
   //{{
   basePointer->CLKCONTROL.CLKDIV = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_select_rtc_clock_divider_divide_by_1
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_select_rtc_clock_divider_divide_by_1(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CLKCONTROL.RTCCLKDIV =
      SI32_LCD_A_CLKCONTROL_RTCCLKDIV_DIVIDE_BY_1_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_select_rtc_clock_divider_divide_by_2
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_select_rtc_clock_divider_divide_by_2(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CLKCONTROL.RTCCLKDIV =
      SI32_LCD_A_CLKCONTROL_RTCCLKDIV_DIVIDE_BY_2_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_select_rtc_clock_divider_divide_by_4
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_select_rtc_clock_divider_divide_by_4(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CLKCONTROL.RTCCLKDIV =
      SI32_LCD_A_CLKCONTROL_RTCCLKDIV_DIVIDE_BY_4_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_select_rtc_clock_divider_divide_by_8
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_select_rtc_clock_divider_divide_by_8(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->CLKCONTROL.RTCCLKDIV =
      SI32_LCD_A_CLKCONTROL_RTCCLKDIV_DIVIDE_BY_8_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_write_blkcontrol
//
// Write to BLKCONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_write_blkcontrol(
   SI32_LCD_A_Type * basePointer,
   uint32_t value)
{
   //{{
   basePointer->BLKCONTROL.U32 = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_read_blkcontrol
//
// Read from BLKCONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_LCD_A_read_blkcontrol(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   return basePointer->BLKCONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_write_lcd_blink_mask
//
// Write to LCD Blink Mask (CTRSTCONTROL[0:4]).
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_write_lcd_blink_mask(
   SI32_LCD_A_Type * basePointer,
   uwide8_t value)
{
   assert(value < 256);   // value < 2^8
   //{{
   basePointer->BLKCONTROL.BLKMASK = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_write_lcd_blink_exponent
//
// Write to LCD Blink Rate (CTRSTCONTROL[0:4]).
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_write_lcd_blink_exponent(
   SI32_LCD_A_Type * basePointer,
   uwide8_t value)
{
   assert(value < 16);   // value < 2^4
   //{{
   basePointer->BLKCONTROL.BLKREXP = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_write_segcontrol
//
// Write to SEGCONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_write_segcontrol(
   SI32_LCD_A_Type * basePointer,
   uint32_t value)
{
   //{{
   basePointer->SEGCONTROL.U32 = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_read_segcontrol
//
// Read from SEGCONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_LCD_A_read_segcontrol(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   return basePointer->SEGCONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_select_one_third_bias
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_select_one_third_bias(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->SEGCONTROL.BIASMD =
      SI32_LCD_A_SEGCONTROL_BIASMD_ONE_THIRD_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_select_one_half_bias
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_select_one_half_bias(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->SEGCONTROL.BIASMD =
      SI32_LCD_A_SEGCONTROL_BIASMD_ONE_HALF_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_select_segment_mode_static
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_select_segment_mode_static(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->SEGCONTROL.SEGMD =
      SI32_LCD_A_SEGCONTROL_SEGMD_STATIC_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_select_segment_mode_2_mux
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_select_segment_mode_2_mux(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->SEGCONTROL.SEGMD =
      SI32_LCD_A_SEGCONTROL_SEGMD_2_MUX_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_select_segment_mode_3_mux
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_select_segment_mode_3_mux(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->SEGCONTROL.SEGMD =
      SI32_LCD_A_SEGCONTROL_SEGMD_3_MUX_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_select_segment_mode_4_mux
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_select_segment_mode_4_mux(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->SEGCONTROL.SEGMD =
      SI32_LCD_A_SEGCONTROL_SEGMD_4_MUX_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_enable_blank_all_segments
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_enable_blank_all_segments(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->SEGCONTROL.BLANKEN =
      SI32_LCD_A_SEGCONTROL_BLANKEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_disable_blank_all_segments
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_disable_blank_all_segments(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->SEGCONTROL.BLANKEN =
      SI32_LCD_A_SEGCONTROL_BLANKEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_enable_reset_phase
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_enable_reset_phase(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->SEGCONTROL.RPHEN = SI32_LCD_A_SEGCONTROL_RPHEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_disable_reset_phase
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_disable_reset_phase(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->SEGCONTROL.RPHEN = SI32_LCD_A_SEGCONTROL_RPHEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_write_reset_phase_count_u8
//
// Write to Reset Phase Count.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_write_reset_phase_count_u8(
   SI32_LCD_A_Type * basePointer,
   uwide8_t value)
{
   assert(value < 8);   // value < 2^3
   //{{
   basePointer->SEGCONTROL.RPHMD = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_write_ctrstcontrol
//
// Write to CTRSTCONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_write_ctrstcontrol(
   SI32_LCD_A_Type * basePointer,
   uint32_t value)
{
   //{{
   basePointer->CTRSTCONTROL.U32 = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_read_ctrstcontrol
//
// Read from CTRSTCONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_LCD_A_read_ctrstcontrol(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   return basePointer->CTRSTCONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_write_lcd_contrast
//
// Write to LCD Contrast (CTRSTCONTROL[0:4]).
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_write_lcd_contrast(
   SI32_LCD_A_Type * basePointer,
   uwide8_t value)
{
   assert(value < 32);   // value < 2^5
   //{{
   basePointer->CTRSTCONTROL.CTRST = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_write_vbmcontrol
//
// Write to VBMCONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_write_vbmcontrol(
   SI32_LCD_A_Type * basePointer,
   uint32_t value)
{
   //{{
   basePointer->VBMCONTROL.U32 = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_read_vbmcontrol
//
// Read from VBMCONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_LCD_A_read_vbmcontrol(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   return basePointer->VBMCONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_write_vbat_monitor_threshold
//
// Write to VMON Threshold (VBMON_CN[0:4]).
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_write_vbat_monitor_threshold(
   SI32_LCD_A_Type * basePointer,
   uwide8_t value)
{
   assert(value < 32);   // value < 2^5
   //{{
   basePointer->VBMCONTROL.VBMTH = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_enable_vbat_monitor_capacitor_divider
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_enable_vbat_monitor_capacitor_divider(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->VBMCONTROL.VBMCDEN = SI32_LCD_A_VBMCONTROL_VBMCDEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_disable_vbat_monitor_capacitor_divider
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_disable_vbat_monitor_capacitor_divider(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->VBMCONTROL.VBMCDEN = SI32_LCD_A_VBMCONTROL_VBMCDEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_enable_vbat_monitor_offset
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_enable_vbat_monitor_offset(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->VBMCONTROL.VBMOEN = SI32_LCD_A_VBMCONTROL_VBMOEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_disable_vbat_monitor_offset
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_disable_vbat_monitor_offset(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->VBMCONTROL.VBMOEN = SI32_LCD_A_VBMCONTROL_VBMOEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_enable_vbat_monitor
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_enable_vbat_monitor(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->VBMCONTROL.VBMEN = SI32_LCD_A_VBMCONTROL_VBMEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_disable_vbat_monitor
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_disable_vbat_monitor(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   basePointer->VBMCONTROL.VBMEN = SI32_LCD_A_VBMCONTROL_VBMEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_is_vbat_monitor_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_LCD_A_is_vbat_monitor_enabled(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   return (basePointer->VBMCONTROL.VBMEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_write_segmask0
//
// Write to SEGMASK0 word.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_write_segmask0(
   SI32_LCD_A_Type * basePointer,
   uint32_t value)
{
   //{{
   basePointer->SEGMASK0.U32 = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_read_segmask0
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_LCD_A_read_segmask0(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   return basePointer->SEGMASK0.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_write_segmask1
//
// Write to SEGMASK0 word.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_write_segmask1(
   SI32_LCD_A_Type * basePointer,
   uwide8_t value)
{
   assert(value < 256);   // value < 2^8
   //{{
   basePointer->SEGMASK1.SEGEN = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_read_segment_mask_1
//
//-----------------------------------------------------------------------------
uwide8_t
_SI32_LCD_A_read_segmask1(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   return basePointer->SEGMASK1.SEGEN;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_write_number_of_segments
//
// Enable block of contiguous segments with number of segments specified.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_write_number_of_segments(
   SI32_LCD_A_Type * basePointer,
   uwide8_t value)
{
   assert((value >= 0) && (value <= 40));
   //{{
   if(value>32)
   {
      basePointer->SEGMASK0.U32 = 0xFFFFFFFF;;
      basePointer->SEGMASK1.U32 = 0x000000FF>>(40-value);
   }
   else
   {
      basePointer->SEGMASK0.U32 = 0xFFFFFFFF>>(32-value);;
      basePointer->SEGMASK1.U32 = 0x00000000;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_write_segdata0
//
// Write to SEGDATA0.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_write_segdata0(
   SI32_LCD_A_Type * basePointer,
   uint32_t value)
{
   //{{
   basePointer->SEGDATA0.U32 = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_read_segdata0
//
// Read from SEGDATA0.
//-----------------------------------------------------------------------------
uint32_t
_SI32_LCD_A_read_segdata0(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   return basePointer->SEGDATA0.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_write_segdata1
//
// Write to SEGDATA1.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_write_segdata1(
   SI32_LCD_A_Type * basePointer,
   uint32_t value)
{
   //{{
   basePointer->SEGDATA1.U32 = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_read_segdata1
//
// Read from SEGDATA1.
//-----------------------------------------------------------------------------
uint32_t
_SI32_LCD_A_read_segdata1(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   return basePointer->SEGDATA1.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_write_segdata2
//
// Write to SEGDATA2.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_write_segdata2(
   SI32_LCD_A_Type * basePointer,
   uint32_t value)
{
   //{{
   basePointer->SEGDATA2.U32 = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_read_segdata2
//
// Read from SEGDATA2.
//-----------------------------------------------------------------------------
uint32_t
_SI32_LCD_A_read_segdata2(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   return basePointer->SEGDATA2.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_write_segdata3
//
// Write to SEGDATA3.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_write_segdata3(
   SI32_LCD_A_Type * basePointer,
   uint32_t value)
{
   //{{
   basePointer->SEGDATA3.U32 = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_read_segdata3
//
// Read from SEGDATA3.
//-----------------------------------------------------------------------------
uint32_t
_SI32_LCD_A_read_segdata3(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   return basePointer->SEGDATA3.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_write_segdata4
//
// Write to SEGDATA4.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_write_segdata4(
   SI32_LCD_A_Type * basePointer,
   uint32_t value)
{
   //{{
   basePointer->SEGDATA4.U32 = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_read_segdata4
//
// Read from SEGDATA4.
//-----------------------------------------------------------------------------
uint32_t
_SI32_LCD_A_read_segdata4(
   SI32_LCD_A_Type * basePointer)
{
   //{{
   return basePointer->SEGDATA4.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_clear_all_segment_data
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_clear_all_segment_data(
   SI32_LCD_A_Type * basePointer)
{
   //{{
      basePointer->SEGDATA0.U32 = 0x00000000;
      basePointer->SEGDATA1.U32 = 0x00000000;
      basePointer->SEGDATA2.U32 = 0x00000000;
      basePointer->SEGDATA3.U32 = 0x00000000;
      basePointer->SEGDATA4.U32 = 0x00000000;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_write_segment_data_u32
//
// Write to LCD segment data word using index.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_write_segment_data_u32(
   SI32_LCD_A_Type * basePointer,
   uint32_t value,
   uwide8_t index)
{
   assert((index >= 0) && (index <= 4));
   //{{
   switch (index)
   {
      case 0:
         basePointer->SEGDATA0.U32 = value;
         break;

      case 1:
         basePointer->SEGDATA1.U32 = value;
         break;

      case 2:
         basePointer->SEGDATA2.U32 = value;
         break;

      case 3:
         basePointer->SEGDATA3.U32 = value;
         break;

      case 4:
         basePointer->SEGDATA4.U32 = value;
         break;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_write_segment_data_u16
//
// Write to LCD segment data half-word using index.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_write_segment_data_u16(
   SI32_LCD_A_Type * basePointer,
   uwide16_t value,
   uwide8_t index)
{
   assert(value < 65536);   // value < 2^16
   assert((index >= 0) && (index <= 9));
   //{{
   switch (index>>1)
   {
      case 0:
         basePointer->SEGDATA0.U16[index&1] = value;
         //*((uint16_t *)(&(basePointer->SEGDATA0.U32))[index&1]) = value;
         break;

      case 1:
         basePointer->SEGDATA1.U16[index&1] = value;
         //*((uint16_t *)(&(basePointer->SEGDATA1.U32))[index&0x00000001]) = value;
         break;

      case 2:
         basePointer->SEGDATA2.U16[index&1] = value;
         //*((uint16_t *)(&(basePointer->SEGDATA2.U32))[index&0x00000001]) = value;
         break;

      case 3:
         basePointer->SEGDATA3.U16[index&1] = value;
         //*((uint16_t *)(&(basePointer->SEGDATA3.U32))[index&0x00000001]) = value;
         break;

      case 4:
         basePointer->SEGDATA4.U16[index&1] = value;
         //*((uint16_t *)(&(basePointer->SEGDATA4.U32))[index&0x00000001]) = value;
         break;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_write_segment_data_u8
//
// Write to LCD segment data byte using index.
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_write_segment_data_u8(
   SI32_LCD_A_Type * basePointer,
   uwide8_t value,
   uwide8_t index)
{
   assert(value < 256);   // value < 2^8
   assert((index >= 0) && (index <= 19));
   //{{

   switch (index>>2)
   {
      case 0:
         basePointer->SEGDATA0.U8[index&3] = value;
         //*((uint8_t *)(&(basePointer->SEGDATA0.U32))[index&0x00000003]) = value;
         break;

      case 1:
         basePointer->SEGDATA1.U8[index&3] = value;
         //*((uint8_t *)(&(basePointer->SEGDATA1.U32))[index&0x00000003]) = value;
         break;

      case 2:
         basePointer->SEGDATA2.U8[index&3] = value;
         //*((uint8_t *)(&(basePointer->SEGDATA2.U32))[index&0x00000003]) = value;
         break;

      case 3:
         basePointer->SEGDATA3.U8[index&3] = value;
         //*((uint8_t *)(&(basePointer->SEGDATA3.U32))[index&0x00000003]) = value;
         break;

      case 4:
         basePointer->SEGDATA4.U8[index&3] = value;
         //*((uint8_t *)(&(basePointer->SEGDATA4.U32))[index&0x00000003]) = value;
         break;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_read_segment_data_u32
//
// Read LCD segment data word using index.
//-----------------------------------------------------------------------------
uint32_t
_SI32_LCD_A_read_segment_data_u32(
   SI32_LCD_A_Type * basePointer,
   uwide8_t index)
{
   assert((index >= 0) && (index <= 4));
   //{{
   switch (index)
   {
      case 0:
         return basePointer->SEGDATA0.U32;

      case 1:
         return basePointer->SEGDATA1.U32;

      case 2:
         return basePointer->SEGDATA2.U32;

      case 3:
         return basePointer->SEGDATA3.U32;

      case 4:
         return basePointer->SEGDATA4.U32;

      default:
         return 0;

   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_read_segment_data_u16
//
// Read LCD segment data half-word using index.
//-----------------------------------------------------------------------------
uwide16_t
_SI32_LCD_A_read_segment_data_u16(
   SI32_LCD_A_Type * basePointer,
   uwide8_t index)
{
   assert((index >= 0) && (index <= 9));
   //{{
   switch (index>>1)
   {
      case 0:
         return basePointer->SEGDATA0.U16[index&1];
         //return *((uint16_t *)(&(basePointer->SEGDATA0.U32))[index&1]);

      case 1:
         return basePointer->SEGDATA1.U16[index&1];
         //return *((uint16_t *)(&(basePointer->SEGDATA1.U32))[index&1]);

      case 2:
         return basePointer->SEGDATA2.U16[index&1];
         //return *((uint16_t *)(&(basePointer->SEGDATA2.U32))[index&1]);

      case 3:
         return basePointer->SEGDATA3.U16[index&1];
         //return *((uint16_t *)(&(basePointer->SEGDATA3.U32))[index&1]);

      case 4:
         return basePointer->SEGDATA4.U16[index&1];
         //return *((uint16_t *)(&(basePointer->SEGDATA4.U32))[index&1]);

      default:
         return 0;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_read_segment_data_u8
//
// Read LCD segment data half-word using index.
//-----------------------------------------------------------------------------
uwide8_t
_SI32_LCD_A_read_segment_data_u8(
   SI32_LCD_A_Type * basePointer,
   uwide8_t index)
{
   assert((index >= 0) && (index <= 19));
   //{{
   switch (index>>2)
   {
      case 0:
         return basePointer->SEGDATA0.U8[index&3];
         //return *((uint8_t *)(&(basePointer->SEGDATA0.U32))[index&3]);

      case 1:
         return basePointer->SEGDATA1.U8[index&3];
         //return *((uint8_t *)(&(basePointer->SEGDATA0.U32))[index&3]);

      case 2:
         return basePointer->SEGDATA2.U8[index&3];
         //return *((uint8_t *)(&(basePointer->SEGDATA0.U32))[index&3]);

      case 3:
         return basePointer->SEGDATA3.U8[index&3];
         //return *((uint8_t *)(&(basePointer->SEGDATA0.U32))[index&3]);

      case 4:
         return basePointer->SEGDATA4.U8[index&3];
         //return *((uint8_t *)(&(basePointer->SEGDATA0.U32))[index&3]);

      default:
         return 0;

   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_set_segment_bit
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_set_segment_bit(
   SI32_LCD_A_Type * basePointer,
   // Set segment bit (0 thorugh 159).
   uwide8_t index)
{
   assert((index >= 0) && (index <= 159));
   //{{
   switch (index >> 5 )
   {
      case 0:
         basePointer->SEGDATA0.U32 |= (1<<(index&0x1F));
         break;

      case 1:
         basePointer->SEGDATA1.U32 |= (1<<(index&0x1F));
         break;

      case 2:
         basePointer->SEGDATA2.U32 |= (1<<(index&0x1F));
         break;

      case 3:
         basePointer->SEGDATA3.U32 |= (1<<(index&0x1F));
         break;

      case 4:
         basePointer->SEGDATA4.U32 |= (1<<(index&0x1F));
         break;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_LCD_A_clear_segment_bit
//
//-----------------------------------------------------------------------------
void
_SI32_LCD_A_clear_segment_bit(
   SI32_LCD_A_Type * basePointer,
   // Set segment bit (0 thorugh 159).
   uwide8_t index)
{
   assert((index >= 0) && (index <= 159));
   //{{
   switch (index >> 5 )
   {
      case 0:
         basePointer->SEGDATA0.U32 &= ~(1<<(index&0x1F));
         break;

      case 1:
         basePointer->SEGDATA1.U32 &= ~(1<<(index&0x1F));
         break;

      case 2:
         basePointer->SEGDATA2.U32 &= ~(1<<(index&0x1F));
         break;

      case 3:
         basePointer->SEGDATA3.U32 &= ~(1<<(index&0x1F));
         break;

      case 4:
         basePointer->SEGDATA4.U32 &= ~(1<<(index&0x1F));
         break;
   }
   //}}
}


//-eof--------------------------------------------------------------------------
