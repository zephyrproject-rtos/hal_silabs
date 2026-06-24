/***************************************************************************//**
 * @file
 * @brief LEDSINK Peripheral API
 *******************************************************************************
 * # License
 * <b>Copyright 2026 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

#include "sl_hal_ledsink.h"
#if defined(LEDSINK_PRESENT) 

#include "sl_common.h"
#include <stddef.h>

/***************************************************************************//**
 * @addtogroup ledsink LEDSINK
 * @brief LEDSINK Peripheral API
 * @details
 *   The LEDSINK module consists of these main parts:
 *   @li General LEDSINK configuration and enable control.
 *   @li Pattern configuration for each LED channel.
 *   @li Control functions for pattern start/stop and direct LED control.
 *   @li Interrupt handling.
 * @{
 ******************************************************************************/

/*******************************************************************************
 ***************************   LOCAL FUNCTIONS   *******************************
 ******************************************************************************/
static uint32_t ledsink_calculate_total_current_uA(LEDSINK_TypeDef *ledsink,
                                                   sl_hal_ledsink_led_channel_t led_channel,
                                                   uint8_t new_current_step);

/*******************************************************************************
 **************************   GLOBAL FUNCTIONS   *******************************
 ******************************************************************************/
extern __INLINE sl_status_t sl_hal_ledsink_enable_module(LEDSINK_TypeDef *ledsink);
extern __INLINE sl_status_t sl_hal_ledsink_disable_module(LEDSINK_TypeDef *ledsink);
extern __INLINE sl_status_t sl_hal_ledsink_reset(LEDSINK_TypeDef *ledsink);
extern __INLINE uint32_t sl_hal_ledsink_get_ctrl(LEDSINK_TypeDef *ledsink);
extern __INLINE sl_status_t sl_hal_ledsink_enable_bias_ref(LEDSINK_TypeDef *ledsink);
extern __INLINE sl_status_t sl_hal_ledsink_disable_bias_ref(LEDSINK_TypeDef *ledsink);
extern __INLINE bool sl_hal_ledsink_get_bias_ref_enabled(LEDSINK_TypeDef *ledsink);
extern __INLINE sl_status_t sl_hal_ledsink_enable_direct_led(LEDSINK_TypeDef *ledsink,
                                                             sl_hal_ledsink_led_channel_t led_channel);
extern __INLINE sl_status_t sl_hal_ledsink_disable_direct_led(LEDSINK_TypeDef *ledsink,
                                                              sl_hal_ledsink_led_channel_t led_channel);
extern __INLINE bool sl_hal_ledsink_get_direct_led_enabled(LEDSINK_TypeDef *ledsink,
                                                           sl_hal_ledsink_led_channel_t led_channel);
extern __INLINE sl_status_t sl_hal_ledsink_clear_interrupts(LEDSINK_TypeDef *ledsink, uint8_t flags_mask);
extern __INLINE uint8_t sl_hal_ledsink_get_pending_interrupts(LEDSINK_TypeDef *ledsink);
extern __INLINE sl_status_t sl_hal_ledsink_enable_interrupts(LEDSINK_TypeDef *ledsink, uint8_t interrupt_mask);
extern __INLINE uint8_t sl_hal_ledsink_get_enabled_interrupts(LEDSINK_TypeDef *ledsink);
extern __INLINE sl_status_t sl_hal_ledsink_set_dbg(LEDSINK_TypeDef *ledsink, uint8_t dbg_value);
extern __INLINE uint32_t sl_hal_ledsink_get_status(LEDSINK_TypeDef *ledsink);
extern __INLINE bool sl_hal_ledsink_get_ledvdd_fall_edge(LEDSINK_TypeDef *ledsink);
extern __INLINE uint32_t sl_hal_ledsink_get_sync_busy(LEDSINK_TypeDef *ledsink);
extern __INLINE uint8_t sl_hal_ledsink_get_channel_current(LEDSINK_TypeDef *ledsink,
                                                           sl_hal_ledsink_led_channel_t led_channel);
extern __INLINE uint32_t sl_hal_ledsink_get_pattern_execution_status(LEDSINK_TypeDef *ledsink,
                                                                     sl_hal_ledsink_led_channel_t led_channel);

/***************************************************************************//**
 *   Configure auto fail-safe mode selection.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_configure_auto_failsafe(LEDSINK_TypeDef *ledsink,
                                                   bool auto_failsafe)
{
  // Make sure the module exists on the selected chip.
  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }
  if (auto_failsafe) {
    /* Set AUTOFAILSAFE bit */
    ledsink->CFG0 |= LEDSINK_CFG0_AUTOFAILSAFE;
  } else {
    /* Clear AUTOFAILSAFE bit */
    ledsink->CFG0 &= ~LEDSINK_CFG0_AUTOFAILSAFE;
  }

  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Configure LEDSINK drive mode (HW pattern generator or SW direct control).
 ******************************************************************************/
sl_status_t sl_hal_ledsink_set_drive_mode(LEDSINK_TypeDef *ledsink,
                                          sl_hal_ledsink_drive_mode_t drive_mode)
{
  uint32_t cfg;

  // Make sure the module exists on the selected chip.
  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }
  if (drive_mode > SL_HAL_LEDSINK_DRIVE_MODE_SWCONTROL) {
    return SL_STATUS_INVALID_PARAMETER;
  }
  cfg = ledsink->CFG0;
  cfg = (cfg & ~LEDSINK_CFG0_DRIVEMODE) | ((uint32_t)drive_mode << _LEDSINK_CFG0_DRIVEMODE_SHIFT);
  ledsink->CFG0 = cfg & _LEDSINK_CFG0_MASK;
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Configure start and stop trigger sources.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_set_trigger_source(LEDSINK_TypeDef *ledsink,
                                              sl_hal_ledsink_trigger_source_t start_trigger,
                                              sl_hal_ledsink_trigger_source_t stop_trigger)
{
  uint32_t cfg1;

  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }
  if ((start_trigger > SL_HAL_LEDSINK_TRIGGER_SOURCE_PRS3)
      || (stop_trigger > SL_HAL_LEDSINK_TRIGGER_SOURCE_PRS3)) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  cfg1 = ledsink->CFG1;
  cfg1 &= ~(_LEDSINK_CFG1_STARTTRIGSOURCESEL_MASK | _LEDSINK_CFG1_STOPTRIGSOURCESEL_MASK);
  cfg1 |= ((uint32_t)start_trigger << _LEDSINK_CFG1_STARTTRIGSOURCESEL_SHIFT)
          | ((uint32_t)stop_trigger << _LEDSINK_CFG1_STOPTRIGSOURCESEL_SHIFT);
  ledsink->CFG1 = cfg1 & _LEDSINK_CFG1_MASK;

  return SL_STATUS_OK;
}

/***************************************************************************//**
 *  Configure number of clock cycles per Pattern-Bit granularity of 2ms
 ******************************************************************************/
sl_status_t sl_hal_ledsink_set_cycles_per_bit(LEDSINK_TypeDef *ledsink,
                                              uint16_t cycles_per_bit)
{
  const uint16_t max_cycles_per_bit = (_LEDSINK_CFG1_CYCLESPERBIT_MASK >> _LEDSINK_CFG1_CYCLESPERBIT_SHIFT);

  // Make sure the module exists on the selected chip.
  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }
  // Make sure the cycles per bit is valid.
  if (cycles_per_bit > max_cycles_per_bit) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  ledsink->CFG1 = ((ledsink->CFG1 & ~_LEDSINK_CFG1_CYCLESPERBIT_MASK)
                   | ((uint32_t)cycles_per_bit << _LEDSINK_CFG1_CYCLESPERBIT_SHIFT))
                  & _LEDSINK_CFG1_MASK;

  return SL_STATUS_OK;
}

/***************************************************************************//**
 *   Configure number of clock cycles per Pattern-Bit granularity of 2ms.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_set_cycles_per_sec(LEDSINK_TypeDef *ledsink,
                                              uint32_t cycles_per_sec)
{
  // Make sure the module exists on the selected chip.
  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }
  // Make sure the cycles per sec is valid.
  if (cycles_per_sec > _LEDSINK_CFG2_CYCLESPERSEC_MASK) {
    return SL_STATUS_INVALID_PARAMETER;
  }
  ledsink->CFG2 = ((ledsink->CFG2 & ~_LEDSINK_CFG2_CYCLESPERSEC_MASK)
                   | ((uint32_t)cycles_per_sec << _LEDSINK_CFG2_CYCLESPERSEC_SHIFT))
                  & _LEDSINK_CFG2_MASK;

  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Configurable LED bias to LED enable delays w.r.t No.of per_clk cycles.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_set_analog_bias_to_led_delay(LEDSINK_TypeDef *ledsink,
                                                        uint8_t delay)
{
  const uint8_t max_delay = (_LEDSINK_CFG2_ANABIASTOLEDDELAY_MASK >> _LEDSINK_CFG2_ANABIASTOLEDDELAY_SHIFT);

  // Make sure the module exists on the selected chip.
  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }
  // Make sure the delay is valid.
  if (delay > max_delay) {
    return SL_STATUS_INVALID_PARAMETER;
  }
  ledsink->CFG2 = ((ledsink->CFG2 & ~_LEDSINK_CFG2_ANABIASTOLEDDELAY_MASK)
                   | ((uint32_t)delay << _LEDSINK_CFG2_ANABIASTOLEDDELAY_SHIFT))
                  & _LEDSINK_CFG2_MASK;

  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Configure PRS start and stop trigger edge selection.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_set_prs_edge(LEDSINK_TypeDef *ledsink,
                                        sl_hal_ledsink_prs_edge_t prs_start_edge,
                                        sl_hal_ledsink_prs_edge_t prs_stop_edge)
{
  uint32_t cfg3;

  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  cfg3 = ledsink->CFG3;
  cfg3 &= ~(LEDSINK_CFG3_PRSSTARTEDGESEL | LEDSINK_CFG3_PRSSTOPEDGESEL);

  if (prs_start_edge == SL_HAL_LEDSINK_PRS_EDGE_POSITIVE) {
    cfg3 |= LEDSINK_CFG3_PRSSTARTEDGESEL;
  }
  if (prs_stop_edge == SL_HAL_LEDSINK_PRS_EDGE_POSITIVE) {
    cfg3 |= LEDSINK_CFG3_PRSSTOPEDGESEL;
  }
  ledsink->CFG3 = cfg3;

  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Start pattern execution for multiple LED channels simultaneously.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_start_pattern_mask(LEDSINK_TypeDef *ledsink,
                                              uint8_t channel_mask)
{
  // Make sure the module exists on the selected chip.
  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  // Validate that channel_mask only has bits 0-3 set (channels 0-3).
  if ((channel_mask & ~SL_HAL_LEDSINK_CHANNEL_MASK) != 0U) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  // Set STARTTRIG bits for the specified channels.
  // channel_mask bits 0-3 map directly to CMD bits 0-3 (LED0-3 STARTTRIG).
  ledsink->CMD_SET = ((channel_mask & SL_HAL_LEDSINK_CHANNEL_MASK)
                      << _LEDSINK_CMD_LED0STARTTRIG_SHIFT);
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Stop pattern execution for multiple LED channels simultaneously.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_stop_pattern_mask(LEDSINK_TypeDef *ledsink,
                                             uint8_t channel_mask)
{
  // Make sure the module exists on the selected chip.
  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  // Validate that channel_mask only has bits 0-3 set (channels 0-3).
  if ((channel_mask & ~SL_HAL_LEDSINK_CHANNEL_MASK) != 0U) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  // Set STOPTRIG bits for the specified channels.
  // channel_mask bits 0-3 map to CMD bits 4-7 (LED0-3 STOPTRIG).
  ledsink->CMD_SET = ((channel_mask & SL_HAL_LEDSINK_CHANNEL_MASK)
                      << _LEDSINK_CMD_LED0STOPTRIG_SHIFT);
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Enable multiple LED channels simultaneously.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_enable_led_channels(LEDSINK_TypeDef *ledsink,
                                               uint8_t channel_mask)
{
  // Make sure the module exists on the selected chip.
  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  // Validate that channel_mask only has bits 0-3 set (channels 0-3).
  if ((channel_mask & ~SL_HAL_LEDSINK_CHANNEL_MASK) != 0U) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  // Enable the specified channels.
  ledsink->CTRL_SET = (channel_mask & SL_HAL_LEDSINK_CHANNEL_MASK);

  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Disable multiple LED channels simultaneously.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_disable_led_channels(LEDSINK_TypeDef *ledsink,
                                                uint8_t channel_mask)
{
  // Make sure the module exists on the selected chip.
  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  // Validate that channel_mask only has bits 0-3 set (channels 0-3).
  if ((channel_mask & ~SL_HAL_LEDSINK_CHANNEL_MASK) != 0U) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  // Disable the specified channels.
  ledsink->CTRL_CLR = (channel_mask & SL_HAL_LEDSINK_CHANNEL_MASK);
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Set flashing pattern for a LED channel.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_set_pattern(LEDSINK_TypeDef *ledsink,
                                       sl_hal_ledsink_led_channel_t led_channel,
                                       uint32_t pattern_lsb,
                                       uint8_t pattern_msb,
                                       uint8_t pattern_length)
{
  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }
  if (led_channel >= SL_HAL_LEDSINK_MAX_LED_CHANNELS) {
    return SL_STATUS_INVALID_PARAMETER;
  }
  if ((pattern_length < 1U) || (pattern_length > SL_HAL_LEDSINK_MAX_PATTERN_VALID_LENGTH)) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  ledsink->CFGSEQ[led_channel].FLSHPTRNLSB = pattern_lsb & _LEDSINK_FLSHPTRNLSB_FLASHINGPATTERNLSB_MASK;
  ledsink->CFGSEQ[led_channel].FLSHPTRNMSB = pattern_msb & _LEDSINK_FLSHPTRNMSB_FLASHINGPATTERNMSB_MASK;
  ledsink->CFGSEQ[led_channel].PTRNVLDLEN = pattern_length & _LEDSINK_PTRNVLDLEN_PATTERNVALIDLENGTH_MASK;
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Configure bit ON and OFF periods for a LED channel.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_set_bit_period(LEDSINK_TypeDef *ledsink,
                                          sl_hal_ledsink_led_channel_t led_channel,
                                          uint8_t bit_on_period,
                                          uint8_t bit_off_period)
{
  uint32_t cfg;

  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }
  if (led_channel >= SL_HAL_LEDSINK_MAX_LED_CHANNELS) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  cfg = ledsink->CFGSEQ[led_channel].BITONOFFRPTCFG;
  cfg &= ~(_LEDSINK_BITONOFFRPTCFG_BITONPERIOD_MASK | _LEDSINK_BITONOFFRPTCFG_BITOFFPERIOD_MASK);
  cfg |= ((uint32_t)bit_on_period << _LEDSINK_BITONOFFRPTCFG_BITONPERIOD_SHIFT)
         | ((uint32_t)bit_off_period << _LEDSINK_BITONOFFRPTCFG_BITOFFPERIOD_SHIFT);
  ledsink->CFGSEQ[led_channel].BITONOFFRPTCFG = cfg;
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Configure repeat duration and type for a LED channel.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_set_repeat(LEDSINK_TypeDef *ledsink,
                                      sl_hal_ledsink_led_channel_t led_channel,
                                      uint16_t repeat_duration,
                                      sl_hal_ledsink_repeat_type_t repeat_type)
{
  uint32_t max_repeat = _LEDSINK_BITONOFFRPTCFG_REPEATDURATION_MASK
                        >> _LEDSINK_BITONOFFRPTCFG_REPEATDURATION_SHIFT;
  uint32_t cfg;

  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }
  if (led_channel >= SL_HAL_LEDSINK_MAX_LED_CHANNELS) {
    return SL_STATUS_INVALID_PARAMETER;
  }
  if (repeat_duration > max_repeat) {
    return SL_STATUS_INVALID_PARAMETER;
  }
  if (repeat_type > SL_HAL_LEDSINK_REPEAT_TYPE_TIME) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  cfg = ledsink->CFGSEQ[led_channel].BITONOFFRPTCFG;
  cfg &= ~(_LEDSINK_BITONOFFRPTCFG_REPEATDURATION_MASK | LEDSINK_BITONOFFRPTCFG_REPEATTYPE);
  cfg |= (((uint32_t)repeat_duration << _LEDSINK_BITONOFFRPTCFG_REPEATDURATION_SHIFT)
          & _LEDSINK_BITONOFFRPTCFG_REPEATDURATION_MASK)
         | ((uint32_t)repeat_type << _LEDSINK_BITONOFFRPTCFG_REPEATTYPE_SHIFT);
  ledsink->CFGSEQ[led_channel].BITONOFFRPTCFG = cfg;
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Configure PWM for a LED channel.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_configure_pwm(LEDSINK_TypeDef *ledsink,
                                         sl_hal_ledsink_led_channel_t led_channel,
                                         const sl_hal_ledsink_pwm_config_t *pwm_config)
{
  uint32_t max_duty = _LEDSINK_PWMCYCLECFG_PWMDUTYCYCLE_MASK
                      >> _LEDSINK_PWMCYCLECFG_PWMDUTYCYCLE_SHIFT;
  uint32_t cfg;

  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }
  if (led_channel >= SL_HAL_LEDSINK_MAX_LED_CHANNELS) {
    return SL_STATUS_INVALID_PARAMETER;
  }
  if (pwm_config == NULL) {
    return SL_STATUS_INVALID_PARAMETER;
  }
  if (pwm_config->duty_cycle > max_duty) {
    return SL_STATUS_INVALID_PARAMETER;
  }
  if (!SL_HAL_LEDSINK_PWM_CYCLE_OFFSET_IS_VALID(pwm_config->cycle_offset)) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  cfg = ((uint32_t)pwm_config->duty_cycle << _LEDSINK_PWMCYCLECFG_PWMDUTYCYCLE_SHIFT)
        | ((uint32_t)pwm_config->cycle_offset << _LEDSINK_PWMCYCLECFG_PWMCYCLEOFFSET_SHIFT);
  if (pwm_config->enable) {
    cfg |= LEDSINK_PWMCYCLECFG_PWMEN;
  }
  ledsink->CFGSEQ[led_channel].PWMCYCLECFG = cfg & _LEDSINK_PWMCYCLECFG_MASK;
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Set LED current for a channel.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_set_channel_current(LEDSINK_TypeDef *ledsink,
                                               sl_hal_ledsink_led_channel_t led_channel,
                                               uint8_t current_step)
{
  uint32_t total_current_uA;

  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }
  if (led_channel >= SL_HAL_LEDSINK_MAX_LED_CHANNELS) {
    return SL_STATUS_INVALID_PARAMETER;
  }
  if (current_step > SL_HAL_LEDSINK_MAX_CURRENT_STEP) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  total_current_uA = ledsink_calculate_total_current_uA(ledsink, led_channel, current_step);
  if (total_current_uA > SL_HAL_LEDSINK_MAX_CURRENT_LIMIT_UA) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  ledsink->CFGSEQ[led_channel].CURRCTRL = (ledsink->CFGSEQ[led_channel].CURRCTRL & ~_LEDSINK_CURRCTRL_CURRSET_MASK)
                                          | ((uint32_t)current_step << _LEDSINK_CURRCTRL_CURRSET_SHIFT);
  return SL_STATUS_OK;
}

/*******************************************************************************
 ***************************   LOCAL FUNCTIONS   *******************************
 ******************************************************************************/

/***************************************************************************//**
 * Calculate total current across all LED channels.
 *
 * @details
 *   This is a helper function to calculate the total current that would result from setting
 *   a new current step value for a specific channel. LEDSINK supports analog dimming with 5-bit
 *   resolution (32 steps). The analog dimming range is from 0.5 mA to 15 mA per channel.
 *   The current calculation is: I_LEDx (mA) = (current step + 1) × 0.5 mA.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @param[in] led_channel      LED channel number (0-3) for which the new
 *                             current step value applies.
 *
 * @param[in] new_current_step   New current step value (0-31). 5-bit resolution
 *                             (32 steps).
 *
 * @return                     Total current in microamperes (uA) across all
 *                             channels.
 ******************************************************************************/
static uint32_t ledsink_calculate_total_current_uA(LEDSINK_TypeDef *ledsink,
                                                   sl_hal_ledsink_led_channel_t led_channel,
                                                   uint8_t new_current_step)
{
  uint32_t total_current_uA = 0U;

  for (uint8_t ch = 0; ch < SL_HAL_LEDSINK_MAX_LED_CHANNELS; ch++) {
    uint8_t current_step;
    if (ch == led_channel) {
      /* Use the new value for this channel */
      current_step = new_current_step;
    } else {
      /* Read current value for other channels. */
      current_step = (uint8_t)(ledsink->CFGSEQ[ch].CURRCTRL & _LEDSINK_CURRCTRL_CURRSET_MASK);
    }
    /* Calculate current: I_LEDx (mA) = (current step + 1) × 0.5 mA */
    total_current_uA += ((uint32_t)current_step + 1U) * 500U;
  }

  return total_current_uA;
}

/** @} (end addtogroup ledsink) */
#endif /* defined(LEDSINK_PRESENT) */
