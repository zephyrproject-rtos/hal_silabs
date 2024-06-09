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
// This file applies to the SIM3C1XX_PMU_A module
//
// Script: 0.58
// HAL Source: 0.1
// Version: 1

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
   assert(control < 32);   // control < 2^5
   assert(config < 65536);   // config < 2^16
   assert(wakeen < 512);   // wakeen < 2^9
   assert(pwen < 65536);   // pwen < 2^16
   assert(pwpol < 65536);   // pwpol < 2^16
   //{{
   basePointer->CONTROL.U32 = control;
   basePointer->CONFIG.U32 = config;
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
   assert(control < 32);   // control < 2^5
   //{{
   basePointer->CONTROL.U32 = control;
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
     basePointer->STATUS_CLR  = SI32_PMU_A_STATUS_PORF_MASK
                              | SI32_PMU_A_STATUS_PM9EF_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_clear_por_flag
//
// Clears POR flag in the PMU.
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_clear_por_flag(
   SI32_PMU_A_Type * basePointer)
{
   //{{
     basePointer->STATUS_CLR  = SI32_PMU_A_STATUS_PORF_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_clear_pmu_level_shifter_hold
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_clear_pmu_level_shifter_hold(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PMU_A_CONTROL_PERILPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_clear_pin_level_shifter_hold
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_clear_pin_level_shifter_hold(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PMU_A_CONTROL_PINLPEN_MASK;
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
   basePointer->CONFIG.U32 = config;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_rtc0_fail_reset
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_rtc0_fail_reset(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_PMU_A_CONFIG_RTC0FREN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_rtc0_fail_reset
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_rtc0_fail_reset(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_PMU_A_CONFIG_RTC0FREN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_rtc0_alarm_reset
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_rtc0_alarm_reset(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_PMU_A_CONFIG_RTC0AREN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_rtc0_alarm_reset
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_rtc0_alarm_reset(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_PMU_A_CONFIG_RTC0AREN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_comparator0_reset
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_comparator0_reset(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_PMU_A_CONFIG_CMP0REN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_comparator0_reset
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_comparator0_reset(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_PMU_A_CONFIG_CMP0REN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_pin_wake_reset
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_pin_wake_reset(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_PMU_A_CONFIG_PWAKEREN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_pin_wake_reset
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_pin_wake_reset(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_PMU_A_CONFIG_PWAKEREN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_enable_lptimer0_reset
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_lptimer0_reset(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_PMU_A_CONFIG_LPT0REN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_lptimer0_reset
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_lptimer0_reset(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_PMU_A_CONFIG_LPT0REN_MASK;
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
// _SI32_PMU_A_is_wakeup_event_flag_set
//
//-----------------------------------------------------------------------------
bool
_SI32_PMU_A_is_wakeup_event_flag_set(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   return (bool) basePointer->STATUS.PM9EF;
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
// _SI32_PMU_A_get_last_wakeup_source
//
//-----------------------------------------------------------------------------
SI32_PMU_Wakeup_Enum_Type
_SI32_PMU_A_get_last_wakeup_source(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   SI32_PMU_Wakeup_Enum_Type last_wake;
   if (!basePointer->STATUS.PM9EF)
   {
      last_wake = SI32_NO_WAKEUP;
   }
   else if (basePointer->WAKESTATUS.RSTWF && basePointer->WAKEEN.RSTWEN)
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
   else if (basePointer->WAKESTATUS.RTC0AWF && basePointer->WAKEEN.RTC0AWEN)
   {
      last_wake = SI32_RTC0_ALARM_WAKEUP;
   }
   else if (basePointer->WAKESTATUS.RTC0FWF && basePointer->WAKEEN.RTC0FWEN)
   {
      last_wake = SI32_RTC0_FAIL_WAKEUP;
   }
   else
   {
      last_wake = SI32_WAKEUP_ERROR;
   }
   return last_wake;
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
   basePointer->WAKEEN_SET = SI32_PMU_A_WAKEEN_RTC0AWEN_MASK;
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
   basePointer->WAKEEN_CLR = SI32_PMU_A_WAKEEN_RTC0AWEN_MASK;
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
// _SI32_PMU_A_enable_reset_pin_wake_event
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_enable_reset_pin_wake_event(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->WAKEEN_SET = SI32_PMU_A_WAKEEN_RSTWEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PMU_A_disable_reset_pin_wake_event
//
//-----------------------------------------------------------------------------
void
_SI32_PMU_A_disable_reset_pin_wake_event(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   basePointer->WAKEEN_CLR = SI32_PMU_A_WAKEEN_RSTWEN_MASK;
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
  return (bool) basePointer->WAKESTATUS.RTC0AWF;
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
// _SI32_PMU_A_is_reset_pin_wakeup_flag_set
//
//-----------------------------------------------------------------------------
bool
_SI32_PMU_A_is_reset_pin_wakeup_flag_set(
   SI32_PMU_A_Type * basePointer)
{
   //{{
   return (bool) basePointer->WAKESTATUS.RSTWF;
   //}}
}


//-eof--------------------------------------------------------------------------
