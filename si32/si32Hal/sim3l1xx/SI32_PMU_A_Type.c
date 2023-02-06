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
/// @file SI32_PMU_A_Type.c
//
// This file applies to the SIM3L1XX_PMU_A module
//
// Script: 0.59
// HAL Source: 0.9
// Version: 6

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_PMU_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_PMU_A_initialize
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_initialize(
   SI32_PMU_A_Type * basePointer,
   uint32_t control,
   uint32_t config,
   uint32_t wakeen,
   uwide16_t pwen,
   uwide16_t pwpol)
{
   assert(control < 16777216);   // control < 2^24
   assert(config < 65536);   // config < 2^16
   assert(wakeen < 512);   // wakeen < 2^9
   assert(pwen < 65536);   // pwen < 2^16
   assert(pwpol < 65536);   // pwpol < 2^16
   //{{
   basePointer->CONTROL.U32 = control & 0x00FF0079;
   basePointer->CONFIG.U32 =
      (((basePointer->CONFIG.U32)&~0x00000D70)
      |(config&0x00000D70));
   basePointer->WAKEEN.U32 = wakeen;
   basePointer->PWEN.U32 = pwen;
   basePointer->PWPOL.U32 = pwpol;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_read_control
//
// Read CONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PMU_A_read_control(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_write_control
//
// Write to CONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_write_control(
   SI32_PMU_A_Type * basePointer,
   uint32_t control)
{
   assert(control < 16777216);   // control < 2^24
   //{{
   basePointer->CONTROL.U32 = control & 0x00FF0079;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_clear_wakeup_flags
//
// Clears all PMU status flags.
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_clear_wakeup_flags(
   SI32_PMU_A_Type * basePointer)
{
   //{{
     basePointer->CONTROL_CLR = SI32_PMU_A_CONTROL_WAKECLR_MASK;
     basePointer->STATUS_CLR  = (SI32_PMU_A_STATUS_PM8EF_MASK
         | SI32_PMU_A_STATUS_PORF_MASK);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_pin_wake
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_pin_wake(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_PMU_A_CONTROL_PWAKEEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_pin_wake
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_pin_wake(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PMU_A_CONTROL_PWAKEEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_asleep_pin_out
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_asleep_pin_out(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_PMU_A_CONTROL_PMUASLPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_asleep_pin_out
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_asleep_pin_out(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PMU_A_CONTROL_PMUASLPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_low_power_charge_pump_monitor
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_low_power_charge_pump_monitor(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_PMU_A_CONTROL_CPMONEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_low_power_charge_pump_monitor
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_low_power_charge_pump_monitor(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PMU_A_CONTROL_CPMONEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_low_power_charge_pump_monitor_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_low_power_charge_pump_monitor_interrupt(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_PMU_A_CONTROL_CPMONIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_low_power_charge_pump_monitor_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_low_power_charge_pump_monitor_interrupt(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PMU_A_CONTROL_CPMONIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_ram_0_retention
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_ram_0_retention(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_PMU_A_CONTROL_RAM0REN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_ram_0_retention
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_ram_0_retention(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PMU_A_CONTROL_RAM0REN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_ram_1_retention
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_ram_1_retention(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_PMU_A_CONTROL_RAM1REN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_ram_1_retention
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_ram_1_retention(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PMU_A_CONTROL_RAM1REN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_ram_2_retention
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_ram_2_retention(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_PMU_A_CONTROL_RAM2REN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_ram_2_retention
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_ram_2_retention(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PMU_A_CONTROL_RAM2REN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_ram_3_retention
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_ram_3_retention(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_PMU_A_CONTROL_RAM3REN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_ram_3_retention
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_ram_3_retention(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PMU_A_CONTROL_RAM3REN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_ram_4_retention
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_ram_4_retention(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_PMU_A_CONTROL_RAM4REN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_ram_4_retention
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_ram_4_retention(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PMU_A_CONTROL_RAM4REN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_ram_5_retention
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_ram_5_retention(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_PMU_A_CONTROL_RAM5REN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_ram_5_retention
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_ram_5_retention(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PMU_A_CONTROL_RAM5REN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_ram_6_retention
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_ram_6_retention(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_PMU_A_CONTROL_RAM6REN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_ram_6_retention
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_ram_6_retention(
   SI32_PMU_A_Type * basePointer)
{
   //{{
    basePointer->CONTROL_CLR = SI32_PMU_A_CONTROL_RAM6REN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_ram_7_retention
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_ram_7_retention(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_PMU_A_CONTROL_RAM7REN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_ram_7_retention
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_ram_7_retention(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PMU_A_CONTROL_RAM7REN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_set_ram_retention_enable_mask
//
// Write mask to RAMxREN bits.
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_set_ram_retention_enable_mask(
   SI32_PMU_A_Type * basePointer,
   uwide8_t mask)
{
   assert(mask < 256);   // mask < 2^8
   //{{
   basePointer->CONTROL.U32 =
      ((basePointer->CONTROL.U32) & 0xFF00FFFF)
      |(mask<<SI32_PMU_A_CONTROL_RAM0REN_SHIFT);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_read_config
//
// Read CONFIG register.
//-----------------------------------------------------------------------------
uwide16_t
_SI32_PMU_A_read_config(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   return basePointer->CONFIG.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_write_config
//
// Write to CONFIG register.
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_write_config(
   SI32_PMU_A_Type * basePointer,
   uwide16_t config)
{
   assert(config < 65536);   // config < 2^16
   //{{
   basePointer->CONFIG.U32 =
      (((basePointer->CONFIG.U32)&~0x00000D70)
      |(config&0x00000D70));
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_select_vdrv_connected_to_vbat
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_select_vdrv_connected_to_vbat(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG.VDRVSMD = SI32_PMU_A_CONFIG_VDRVSMD_VBAT_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_select_vdrv_connected_to_vdc
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_select_vdrv_connected_to_vdc(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG.VDRVSMD = SI32_PMU_A_CONFIG_VDRVSMD_VDC_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_select_vdrv_high_impedence
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_select_vdrv_high_impedence(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG.VDRVSMD = SI32_PMU_A_CONFIG_VDRVSMD_HIGHZ_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_low_power_charge_pump
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_low_power_charge_pump(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_PMU_A_CONFIG_CPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_low_power_charge_pump
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_low_power_charge_pump(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_PMU_A_CONFIG_CPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_set_low_power_charge_pump_load
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_set_low_power_charge_pump_load(
   SI32_PMU_A_Type * basePointer,
   uwide8_t load)
{
   assert(load < 4);   // load < 2^2
   //{{
   basePointer->CONFIG.CPLOAD = load;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_read_status
//
// Returns STATUS register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PMU_A_read_status(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_is_power_mode_8_exit_flag_set
//
//-----------------------------------------------------------------------------
bool
_SI32_PMU_A_is_power_mode_8_exit_flag_set(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   return (bool) basePointer->STATUS.PM8EF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_is_pin_wakeup_event_flag_set
//
//-----------------------------------------------------------------------------
bool
_SI32_PMU_A_is_pin_wakeup_event_flag_set(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   return (bool) basePointer->STATUS.PWAKEF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_is_power_on_reset_event_flag_set
//
//-----------------------------------------------------------------------------
bool
_SI32_PMU_A_is_power_on_reset_event_flag_set(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   return (bool) basePointer->STATUS.PORF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_is_low_power_charge_pump_voltage_above_threshold
//
//-----------------------------------------------------------------------------
bool
_SI32_PMU_A_is_low_power_charge_pump_voltage_above_threshold(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   return (bool) basePointer->STATUS.CPSTS;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_read_wakeen
//
// Read WAKEEN register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PMU_A_read_wakeen(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   return basePointer->WAKEEN.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_write_wakeen
//
// Write to WAKEEN register.
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_write_wakeen(
   SI32_PMU_A_Type * basePointer,
   uint32_t wakeen)
{
   assert(wakeen < 512);   // wakeen < 2^9
   //{{
   basePointer->WAKEEN.U32 = wakeen;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_rtc0_fail_wake_event
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_rtc0_fail_wake_event(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->WAKEEN_SET = SI32_PMU_A_WAKEEN_RTC0FWEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_rtc0_fail_wake_event
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_rtc0_fail_wake_event(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->WAKEEN_CLR = SI32_PMU_A_WAKEEN_RTC0FWEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_rtc0_alarm_wake_event
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_rtc0_alarm_wake_event(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->WAKEEN_SET = SI32_PMU_A_WAKEEN_RTC0A0WEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_rtc0_alarm_wake_event
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_rtc0_alarm_wake_event(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->WAKEEN_CLR = SI32_PMU_A_WAKEEN_RTC0A0WEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_comparator0_wake_event
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_comparator0_wake_event(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->WAKEEN_SET = SI32_PMU_A_WAKEEN_CMP0WEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_comparator0_wake_event
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_comparator0_wake_event(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->WAKEEN_CLR = SI32_PMU_A_WAKEEN_CMP0WEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_advanced_capture_counter_wake_event
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_advanced_capture_counter_wake_event(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->WAKEEN_SET = SI32_PMU_A_WAKEEN_ACC0WEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_advanced_capture_counter_wake_event
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_advanced_capture_counter_wake_event(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->WAKEEN_CLR = SI32_PMU_A_WAKEEN_ACC0WEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_lcd_vbat_monitor_wake_event
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_lcd_vbat_monitor_wake_event(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->WAKEEN_SET = SI32_PMU_A_WAKEEN_LCDMONWEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_lcd_vbat_monitor_wake_event
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_lcd_vbat_monitor_wake_event(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->WAKEEN_CLR = SI32_PMU_A_WAKEEN_LCDMONWEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_pin_wake_event
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_pin_wake_event(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->WAKEEN_SET = SI32_PMU_A_WAKEEN_PWAKEWEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_pin_wake_event
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_pin_wake_event(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->WAKEEN_CLR = SI32_PMU_A_WAKEEN_PWAKEWEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_lptimer0_wake_event
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_lptimer0_wake_event(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->WAKEEN_SET = SI32_PMU_A_WAKEEN_LPT0WEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_lptimer0_wake_event
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_lptimer0_wake_event(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->WAKEEN_CLR = SI32_PMU_A_WAKEEN_LPT0WEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_uart0_wake_event
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_uart0_wake_event(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->WAKEEN_SET = SI32_PMU_A_WAKEEN_UART0WEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_uart0_wake_event
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_uart0_wake_event(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->WAKEEN_CLR = SI32_PMU_A_WAKEEN_UART0WEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_low_power_charge_pump_wake_event
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_low_power_charge_pump_wake_event(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->WAKEEN_SET = SI32_PMU_A_WAKEEN_CPFWEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_low_power_charge_pump_wake_event
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_low_power_charge_pump_wake_event(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->WAKEEN_CLR = SI32_PMU_A_WAKEEN_CPFWEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_get_last_wakeup_source
//
//-----------------------------------------------------------------------------
SI32_PMU_Wakeup_Enum_Type
_SI32_PMU_A_get_last_wakeup_source(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   SI32_PMU_Wakeup_Enum_Type last_wake;
   if (!basePointer->STATUS.PM8EF)
   {
      last_wake = SI32_NO_WAKEUP;
   }
   else if (basePointer->WAKESTATUS.RSTWF)
   {
      last_wake = SI32_RESET_WAKEUP;
   }
   else if (basePointer->WAKESTATUS.PWAKEWF && basePointer->WAKEEN.PWAKEWEN)
   {
      last_wake = SI32_PIN_WAKEUP;
   }
   else if (basePointer->WAKESTATUS.LPT0WF && basePointer->WAKEEN.LPT0WEN)
   {
      last_wake = SI32_LPTIMER0_WAKEUP;
   }
   else if (basePointer->WAKESTATUS.CMP0WF && basePointer->WAKEEN.CMP0WEN)
   {
      last_wake = SI32_CMP0_WAKEUP;
   }
   else if (basePointer->WAKESTATUS.RTC0A0WF && basePointer->WAKEEN.RTC0A0WEN)
   {
      last_wake = SI32_RTC0_ALARM_WAKEUP;
   }
   else if (basePointer->WAKESTATUS.RTC0FWF && basePointer->WAKEEN.RTC0FWEN)
   {
      last_wake = SI32_RTC0_FAIL_WAKEUP;
   }
   else if (basePointer->WAKESTATUS.ACC0WF && basePointer->WAKEEN.ACC0WEN)
   {
      last_wake = SI32_ADVANCED_CAPTURE_COUNTER_WAKEUP;
   }
   else if (basePointer->WAKESTATUS.LCDMONWF && basePointer->WAKEEN.LCDMONWEN)
   {
      last_wake = SI32_LCD_MONITOR_WAKEUP;
   }
   else if (basePointer->WAKESTATUS.UART0WF && basePointer->WAKEEN.UART0WEN)
   {
      last_wake = SI32_UART0_WAKEUP;
   }
   else
   {
      last_wake = SI32_WAKEUP_ERROR;
   }
   return last_wake;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_is_rtc0_fail_wakeup_flag_set
//
//-----------------------------------------------------------------------------
bool
_SI32_PMU_A_is_rtc0_fail_wakeup_flag_set(
   SI32_PMU_A_Type * basePointer)
{
   //{{
  return (bool) basePointer->WAKESTATUS.RTC0FWF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_is_rtc0_alarm_wakeup_flag_set
//
//-----------------------------------------------------------------------------
bool
_SI32_PMU_A_is_rtc0_alarm_wakeup_flag_set(
   SI32_PMU_A_Type * basePointer)
{
   //{{
  return (bool) basePointer->WAKESTATUS.RTC0A0WF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_is_comparator0_wakeup_flag_set
//
//-----------------------------------------------------------------------------
bool
_SI32_PMU_A_is_comparator0_wakeup_flag_set(
   SI32_PMU_A_Type * basePointer)
{
   //{{
  return (bool) basePointer->WAKESTATUS.CMP0WF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_is_advance_capture_counter_wakeup_flag_set
//
//-----------------------------------------------------------------------------
bool
_SI32_PMU_A_is_advance_capture_counter_wakeup_flag_set(
   SI32_PMU_A_Type * basePointer)
{
   //{{
  return (bool) basePointer->WAKESTATUS.ACC0WF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_is_lcd_monitor_wakeup_flag_set
//
//-----------------------------------------------------------------------------
bool
_SI32_PMU_A_is_lcd_monitor_wakeup_flag_set(
   SI32_PMU_A_Type * basePointer)
{
   //{{
  return (bool) basePointer->WAKESTATUS.LCDMONWF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_is_pin_wakeup_flag_set
//
//-----------------------------------------------------------------------------
bool
_SI32_PMU_A_is_pin_wakeup_flag_set(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   return (bool) basePointer->WAKESTATUS.PWAKEWF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_is_lptimer0_wakeup_flag_set
//
//-----------------------------------------------------------------------------
bool
_SI32_PMU_A_is_lptimer0_wakeup_flag_set(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   return (bool) basePointer->WAKESTATUS.LPT0WF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_is_uart_wakeup_flag_set
//
//-----------------------------------------------------------------------------
bool
_SI32_PMU_A_is_uart_wakeup_flag_set(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   return (bool) basePointer->WAKESTATUS.UART0WF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_is_low_power_charge_pump_wakeup_flag_set
//
//-----------------------------------------------------------------------------
bool
_SI32_PMU_A_is_low_power_charge_pump_wakeup_flag_set(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   return (bool) basePointer->WAKESTATUS.CPFWF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_read_pwen
//
// Read PWEN register.
//-----------------------------------------------------------------------------
uwide16_t
_SI32_PMU_A_read_pwen(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   return basePointer->PWEN.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_write_pwen
//
// Write to PWEN register.
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_write_pwen(
   SI32_PMU_A_Type * basePointer,
   uwide16_t pwen)
{
   assert(pwen < 65536);   // pwen < 2^16
   //{{
   basePointer->PWEN.U32 = pwen;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_read_pwpol
//
// Read PWPOL register.
//-----------------------------------------------------------------------------
uwide16_t
_SI32_PMU_A_read_pwpol(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   return basePointer->PWPOL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_write_pwpol
//
// Write to PWPOL register.
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_write_pwpol(
   SI32_PMU_A_Type * basePointer,
   uwide16_t pwpol)
{
   assert(pwpol < 65536);   // pwpol < 2^16
   //{{
   basePointer->PWPOL.U32 = pwpol;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_set_pin_wake_events
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_set_pin_wake_events(
   SI32_PMU_A_Type * basePointer,
   // Write to PWEN register.
   uwide16_t pwen,
   // Write to PWPOL register.
   uwide16_t pwpol)
{
   assert(pwen < 65536);   // pwen < 2^16
   assert(pwpol < 65536);   // pwpol < 2^16
   //{{
   basePointer->PWEN.U32 = pwen;
   basePointer->PWPOL.U32 = pwpol;
   //}}
}


//-eof--------------------------------------------------------------------------
