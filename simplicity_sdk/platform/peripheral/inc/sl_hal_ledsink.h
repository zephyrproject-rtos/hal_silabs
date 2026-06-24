/***************************************************************************//**
 * @file
 * @brief LEDSINK peripheral API
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

#ifndef SL_HAL_LEDSINK_H
#define SL_HAL_LEDSINK_H

#include "em_device.h"
#if defined(LEDSINK_PRESENT)

#ifdef __cplusplus
extern "C" {
#endif

#include "sl_common.h"
#include "sl_enum.h"
/***************************************************************************//**
 * @addtogroup ledsink LEDSINK - LED Sink Controller
 * @{
 ******************************************************************************/

/*******************************************************************************
 ********************************   DEFINES   **********************************
 ******************************************************************************/

/// Check if LEDSINK instance is valid.
 #define SL_HAL_LEDSINK_REF_VALID(ledsink_ref)    (LEDSINK_NUM(ledsink_ref) != -1)

/// Maximum number of LED channels supported.
#define SL_HAL_LEDSINK_MAX_LED_CHANNELS          4U

/// Bit mask for valid LED channel bits (bits 0-3).
/// This mask represents the valid channel selection bits used across CTRL, CMD,
/// and other registers where channels 0-3 are represented by bits 0-3.
#define SL_HAL_LEDSINK_CHANNEL_MASK             ((1U << SL_HAL_LEDSINK_MAX_LED_CHANNELS) - 1U)

/// Maximum pattern length in bits.
#define SL_HAL_LEDSINK_MAX_PATTERN_VALID_LENGTH        40U

/// Maximum valid current step value for 15 mA per channel limit.
///   current step = 29 corresponds to 15.0 mA (maximum per channel).
/// Values 30-31 exceed the 15mA per-channel limit and are invalid.
#define SL_HAL_LEDSINK_MAX_CURRENT_STEP              29U

/// Maximum current per LED channel (15 mA = 15000 uA).
/// LEDSINK supports analog dimming with 5-bit resolution (32 steps: current step 0-31).
/// Analog dimming range: 0.5 mA to 15 mA per channel.
/// Current calculation: I(uA) = (current step + 1) * 500
/// - current step = 0  → 0.5 mA (minimum)
/// - current step = 29 → 15.0 mA (maximum per channel)
#define SL_HAL_LEDSINK_MAX_CURRENT_PER_CHANNEL_UA  15000U

/// Maximum total current limit across all LED channels (30 mA = 30000 uA).
#define SL_HAL_LEDSINK_MAX_CURRENT_LIMIT_UA      30000U

/// Validation macro for PWM cycle offset.
/// Returns true if the offset value is within the valid range (0-3).
#define SL_HAL_LEDSINK_PWM_CYCLE_OFFSET_IS_VALID(offset)  ((offset) <= SL_HAL_LEDSINK_PWM_OFFSET_270_DEG)
/*******************************************************************************
 ********************************   ENUMS   ************************************
 ******************************************************************************/

/// LEDSINK drive mode selection.
SL_ENUM(sl_hal_ledsink_drive_mode_t) {
  SL_HAL_LEDSINK_DRIVE_MODE_PATTERNGEN = 0,  /**< Hardware pattern generator drives the LEDs. */
  SL_HAL_LEDSINK_DRIVE_MODE_SWCONTROL        /**< Software directly controls LEDs via DRCTLEDCTRL. */
};

/// Trigger source selection for start/stop.
SL_ENUM(sl_hal_ledsink_trigger_source_t) {
  SL_HAL_LEDSINK_TRIGGER_SOURCE_SW = 0,      /**< Software trigger. */
  SL_HAL_LEDSINK_TRIGGER_SOURCE_PRS0,        /**< PRS channel 0. */
  SL_HAL_LEDSINK_TRIGGER_SOURCE_PRS1,        /**< PRS channel 1. */
  SL_HAL_LEDSINK_TRIGGER_SOURCE_PRS2,        /**< PRS channel 2. */
  SL_HAL_LEDSINK_TRIGGER_SOURCE_PRS3         /**< PRS channel 3. */
};

/// PRS edge selection.
SL_ENUM(sl_hal_ledsink_prs_edge_t) {
  SL_HAL_LEDSINK_PRS_EDGE_NEGATIVE = 0,      /**< Negative edge. */
  SL_HAL_LEDSINK_PRS_EDGE_POSITIVE           /**< Positive edge. */
};

/// PWM repeat type.
SL_ENUM(sl_hal_ledsink_repeat_type_t) {
  SL_HAL_LEDSINK_REPEAT_TYPE_NUM = 0,    /**< Repeat by number. */
  SL_HAL_LEDSINK_REPEAT_TYPE_TIME        /**< Repeat by time. */
};

/// PWM cycle offset (phase offset in steps of 90 degrees).
SL_ENUM(sl_hal_ledsink_pwm_cycle_offset_t) {
  SL_HAL_LEDSINK_PWM_OFFSET_0_DEG = 0,       /**< 0 degrees phase offset. */
  SL_HAL_LEDSINK_PWM_OFFSET_90_DEG,          /**< 90 degrees phase offset. */
  SL_HAL_LEDSINK_PWM_OFFSET_180_DEG,         /**< 180 degrees phase offset. */
  SL_HAL_LEDSINK_PWM_OFFSET_270_DEG          /**< 270 degrees phase offset. */
};

/// LED channel number.
SL_ENUM(sl_hal_ledsink_led_channel_t) {
  SL_HAL_LEDSINK_LED_CHANNEL_0 = 0,          /**< LED channel 0. */
  SL_HAL_LEDSINK_LED_CHANNEL_1,              /**< LED channel 1. */
  SL_HAL_LEDSINK_LED_CHANNEL_2,              /**< LED channel 2. */
  SL_HAL_LEDSINK_LED_CHANNEL_3               /**< LED channel 3. */
};

/*******************************************************************************
 ******************************   STRUCTS   ***********************************
 ******************************************************************************/
/// Per-channel PWM configuration (PWMCYCLECFG register).
typedef struct {
  bool                              enable;            /**< Enable/disable PWM modulation. */
  uint8_t                           duty_cycle;        /**< Duty cycle (0-15, maps to N/16). */
  sl_hal_ledsink_pwm_cycle_offset_t cycle_offset;      /**< Phase offset (0/90/180/270 deg). */
} sl_hal_ledsink_pwm_config_t;

/*******************************************************************************
 *****************************   PROTOTYPES   **********************************
 ******************************************************************************/

/***************************************************************************//**
 * Configure auto fail-safe mode in CFG register.
 *
 * @details
 * When Auto Fail-safe mode is enabled, the LEDSINK will turn off the LED
 * when the LEDVDD drop fall edge is detected.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @param[in] auto_failsafe    true to enable Auto Fail-safe mode, false to disable.
 *
 * @return                     On Success returns SL_STATUS_OK.
 *                             On Failure returns SL_STATUS_INVALID_PARAMETER.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_configure_auto_failsafe(LEDSINK_TypeDef *ledsink,
                                                   bool auto_failsafe);

/***************************************************************************//**
 * Configure LEDSINK drive mode (HW pattern generator or SW direct control).
 *
 * @details
 *  The DRIVEMODE bit in the CFG0 register selects between hardware pattern
 *  generator mode (LEDs driven by core logic) and software direct control mode
 *  (bypass HW controls to GP_LED).
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @param[in] drive_mode       Drive mode selection (PATTERNGEN or SWCONTROL).
 *
 * @return                     On Success returns SL_STATUS_OK.
 *                             On Failure returns SL_STATUS_INVALID_PARAMETER.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_set_drive_mode(LEDSINK_TypeDef *ledsink,
                                          sl_hal_ledsink_drive_mode_t drive_mode);

/***************************************************************************//**
 * Configure start and stop trigger sources.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 * @param[in] start_trigger    Start trigger source selection (SW or PRS0-PRS3).
 * @param[in] stop_trigger     Stop trigger source selection (SW or PRS0-PRS3).
 *
 * @return  SL_STATUS_OK on success, SL_STATUS_INVALID_PARAMETER on failure.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_set_trigger_source(LEDSINK_TypeDef *ledsink,
                                              sl_hal_ledsink_trigger_source_t start_trigger,
                                              sl_hal_ledsink_trigger_source_t stop_trigger);

/***************************************************************************//**
 * Configure number of clock cycles per Pattern-Bit granularity of 2ms.
 *
 * @note
 *   This should be programmed to non-zero value
 *   No.of clock cycles per Pattern-Bit = Peripheral clock * 2ms.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @param[in] cycles_per_bit   Number of clock cycles per Pattern-Bit granularity of 2ms.
 *
 * @return                     On Success returns SL_STATUS_OK.
 *                             On Failure returns SL_STATUS_INVALID_PARAMETER.
 *                                                SL_STATUS_INVALID_PARAMETER.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_set_cycles_per_bit(LEDSINK_TypeDef *ledsink,
                                              uint16_t cycles_per_bit);

/***************************************************************************//**
 * Configure number of clock cycles per Pattern-Bit granularity of 2ms.
 *
 * @note
 *   This should be programmed to non-zero value.
 *   No.of clock cycles per second = Peripheral clock * 1 second.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @param[in] cycles_per_sec   Number of clock cycles per second.
 *
 * @return                     On Success returns SL_STATUS_OK.
 *                             On Failure returns SL_STATUS_INVALID_PARAMETER.
 *                                                SL_STATUS_INVALID_PARAMETER.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_set_cycles_per_sec(LEDSINK_TypeDef *ledsink,
                                              uint32_t cycles_per_sec);

/***************************************************************************//**
 * Configure LED bias to LED enable delays w.r.t No.of per_clk cycles.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @param[in] delay             Analog bias to LED delay value (0-7).
 *
 * @return                     On Success returns SL_STATUS_OK.
 *                             On Failure returns SL_STATUS_INVALID_PARAMETER.
 *                                                SL_STATUS_INVALID_PARAMETER.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_set_analog_bias_to_led_delay(LEDSINK_TypeDef *ledsink,
                                                        uint8_t delay);

/***************************************************************************//**
 * Configure PRS start and stop trigger edge selection.
 *
 * @note
 *   - Edge settings are only effective when the corresponding trigger source
 *     is set to a PRS channel (PRS0-PRS3) via sl_hal_ledsink_set_trigger_source().
 *   - If a trigger source is set to SWTRIGGER, its edge configuration is ignored.
 *   - When start and stop triggers share the same PRS channel, their edges
 *     must be configured to opposite polarities.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 * @param[in] prs_start_edge   PRS start trigger edge (negative or positive).
 * @param[in] prs_stop_edge    PRS stop trigger edge (negative or positive).
 *
 * @return  SL_STATUS_OK on success, SL_STATUS_INVALID_PARAMETER on failure.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_set_prs_edge(LEDSINK_TypeDef *ledsink,
                                        sl_hal_ledsink_prs_edge_t prs_start_edge,
                                        sl_hal_ledsink_prs_edge_t prs_stop_edge);

/***************************************************************************//**
 * Enable multiple LED channels simultaneously.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @param[in] channel_mask      Bit mask of channels to enable (bits 0-3).
 *
 * @return                     On Success returns SL_STATUS_OK.
 *                             On Failure returns SL_STATUS_INVALID_PARAMETER.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_enable_led_channels(LEDSINK_TypeDef *ledsink,
                                               uint8_t channel_mask);

/***************************************************************************//**
 * Disable multiple LED channels simultaneously.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @param[in] channel_mask      Bit mask of channels to disable (bits 0-3).
 *
 * @return                     On Success returns SL_STATUS_OK.
 *                             On Failure returns SL_STATUS_INVALID_PARAMETER.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_disable_led_channels(LEDSINK_TypeDef *ledsink,
                                                uint8_t channel_mask);

/***************************************************************************//**
 * Start pattern execution for multiple LED channels simultaneously.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @param[in] channel_mask      Bit mask of channels to start (bits 0-3 correspond
 *                             to channels 0-3). Example: 0x3 = start channels 0
 *                             and 1, 0xF = start all channels.
 *
 * @return                     On Success returns SL_STATUS_OK.
 *                             On Failure returns SL_STATUS_INVALID_PARAMETER.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_start_pattern_mask(LEDSINK_TypeDef *ledsink,
                                              uint8_t channel_mask);

/***************************************************************************//**
 * Stop pattern execution for multiple LED channels simultaneously.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @param[in] channel_mask      Bit mask of channels to stop (bits 0-3).
 *
 * @return                     On Success returns SL_STATUS_OK.
 *                             On Failure returns SL_STATUS_INVALID_PARAMETER.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_stop_pattern_mask(LEDSINK_TypeDef *ledsink,
                                             uint8_t channel_mask);

/***************************************************************************//**
 * Set flashing pattern for a LED channel.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 * @param[in] led_channel      LED channel number (0-3).
 * @param[in] pattern_lsb      Pattern bits [31:0].
 * @param[in] pattern_msb      Pattern bits [39:32].
 * @param[in] pattern_length   Valid pattern length (1-40 bits).
 *
 * @return  SL_STATUS_OK on success, SL_STATUS_INVALID_PARAMETER on failure.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_set_pattern(LEDSINK_TypeDef *ledsink,
                                       sl_hal_ledsink_led_channel_t led_channel,
                                       uint32_t pattern_lsb,
                                       uint8_t pattern_msb,
                                       uint8_t pattern_length);

/***************************************************************************//**
 * Configure bit ON and OFF periods for a LED channel.
 *
 * Both fields reside in the BITONOFFRPTCFG register and are written in a
 * single read-modify-write operation.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 * @param[in] led_channel      LED channel number (0-3).
 * @param[in] bit_on_period    Bit ON period value (0-255) in cycles_per_bit units.
 * @param[in] bit_off_period   Bit OFF period value (0-255) in cycles_per_bit units.
 *
 * @return  SL_STATUS_OK on success, SL_STATUS_INVALID_PARAMETER on failure.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_set_bit_period(LEDSINK_TypeDef *ledsink,
                                          sl_hal_ledsink_led_channel_t led_channel,
                                          uint8_t bit_on_period,
                                          uint8_t bit_off_period);

/***************************************************************************//**
 * Configure repeat duration and type for a LED channel.
 *
 * Both fields reside in the BITONOFFRPTCFG register and are written in a
 * single read-modify-write operation.
 *
 * @note
 *   - REPEATNUM (0): repeat_duration is the number of times to repeat.
 *   - REPEATTIME (1): repeat_duration is the time in increments of 1 second.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 * @param[in] led_channel      LED channel number (0-3).
 * @param[in] repeat_duration  Repeat duration value (0-32767).
 * @param[in] repeat_type      Repeat type selection (NUM or TIME).
 *
 * @return  SL_STATUS_OK on success, SL_STATUS_INVALID_PARAMETER on failure.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_set_repeat(LEDSINK_TypeDef *ledsink,
                                      sl_hal_ledsink_led_channel_t led_channel,
                                      uint16_t repeat_duration,
                                      sl_hal_ledsink_repeat_type_t repeat_type);

/***************************************************************************//**
 * Configure PWM for a LED channel (enable, duty cycle, and phase offset).
 *
 * All fields map to the PWMCYCLECFG register and are written in a single
 * register write.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 * @param[in] led_channel      LED channel number (0-3).
 * @param[in] pwm_config       Pointer to PWM configuration struct.
 *
 * @return  SL_STATUS_OK on success, SL_STATUS_INVALID_PARAMETER on failure.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_configure_pwm(LEDSINK_TypeDef *ledsink,
                                         sl_hal_ledsink_led_channel_t led_channel,
                                         const sl_hal_ledsink_pwm_config_t *pwm_config);

/***************************************************************************//**
 * Set LED current for a channel.
 * LEDSINK supports analog dimming with 5-bit resolution (32 steps).
 * Current range: 0.5 mA to 15 mA per channel.
 * Total current across all enabled channels must not exceed 30 mA.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @param[in] led_channel      LED channel number (0-3).
 *
 * @param[in] current_step      Current setting value (0-29). I = (current_step + 1) * 0.5 mA.
 *
 * @return                     On Success returns SL_STATUS_OK.
 *                             On Failure returns SL_STATUS_INVALID_PARAMETER.
 ******************************************************************************/
sl_status_t sl_hal_ledsink_set_channel_current(LEDSINK_TypeDef *ledsink,
                                               sl_hal_ledsink_led_channel_t led_channel,
                                               uint8_t current_step);

/***************************************************************************//**
 * Enable LEDSINK peripheral.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @return                     On Success returns SL_STATUS_OK.
 *                             On Failure returns SL_STATUS_INVALID_PARAMETER.
 ******************************************************************************/
__INLINE sl_status_t sl_hal_ledsink_enable_module(LEDSINK_TypeDef *ledsink)
{
  // Make sure the module exists on the selected chip.
  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  ledsink->EN_SET = LEDSINK_EN_EN;

  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Disable LEDSINK peripheral.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @return                     On Success returns SL_STATUS_OK.
 *                             On Failure returns SL_STATUS_INVALID_PARAMETER.
 ******************************************************************************/
__INLINE sl_status_t sl_hal_ledsink_disable_module(LEDSINK_TypeDef *ledsink)
{
  // Make sure the module exists on the selected chip.
  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  ledsink->EN_CLR = LEDSINK_EN_EN;

  // Wait for DISABLING to be set (disable sequence started).
  while (ledsink->EN & LEDSINK_EN_DISABLING) {
    // Wait for disabling to finish.
  }

  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Reset the LEDSINK peripheral.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @return                     On Success returns SL_STATUS_OK.
 *                             On Failure returns SL_STATUS_INVALID_PARAMETER.
 ******************************************************************************/
__INLINE sl_status_t sl_hal_ledsink_reset(LEDSINK_TypeDef *ledsink)
{
  // Make sure the module exists on the selected chip.
  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  ledsink->SWRST_SET = LEDSINK_SWRST_SWRST;

  // Wait for RESETTING to clear (reset sequence complete).
  while (ledsink->SWRST & LEDSINK_SWRST_RESETTING) {
    // Wait for reset to finish.
  }

  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Get control register value.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @return                     Current CTRL register value.
 ******************************************************************************/
__INLINE uint32_t sl_hal_ledsink_get_ctrl(LEDSINK_TypeDef *ledsink)
{
  // Make sure the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_LEDSINK_REF_VALID(ledsink));
  // Get the control register value.

  return ledsink->CTRL;
}

/***************************************************************************//**
 * Enable the analog bias reference in SW direct-drive mode.
 *
 * @details
 *   This function sets the ENBIASREF bit in the DRCTLEDCTRL register,
 *   which drives the bias_en_ref signal to the GP_LED analog macro.
 *
 * @note:
 *   - This API is effective only when CFG0.DRIVEMODE = SWCONTROL (SW direct-drive mode).
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @return                     On Success returns SL_STATUS_OK.
 *                             On Failure returns SL_STATUS_INVALID_PARAMETER.
 ******************************************************************************/
__INLINE sl_status_t sl_hal_ledsink_enable_bias_ref(LEDSINK_TypeDef *ledsink)
{
  // Make sure the module exists on the selected chip.
  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  // Set the ENBIASREF bit.
  ledsink->DRCTLEDCTRL |= LEDSINK_DRCTLEDCTRL_ENBIASREF;
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Disable the analog bias reference in SW direct-drive mode.
 *
 * @details
 *   This function clears the ENBIASREF bit in the DRCTLEDCTRL register,
 *   which disables the bias_en_ref signal to the GP_LED analog macro.
 *
 * @note:
 *   - This API is effective only when CFG0.DRIVEMODE = SWCONTROL (SW direct-drive mode).
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @return                     On Success returns SL_STATUS_OK.
 *                             On Failure returns SL_STATUS_INVALID_PARAMETER.
 ******************************************************************************/
__INLINE sl_status_t sl_hal_ledsink_disable_bias_ref(LEDSINK_TypeDef *ledsink)
{
  // Make sure the module exists on the selected chip.
  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  // Clear the ENBIASREF bit.
  ledsink->DRCTLEDCTRL &= ~LEDSINK_DRCTLEDCTRL_ENBIASREF;
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Get the analog bias reference enable status in SW direct-drive mode.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @return                     true if bias reference is enabled, false otherwise.
 ******************************************************************************/
__INLINE bool sl_hal_ledsink_get_bias_ref_enabled(LEDSINK_TypeDef *ledsink)
{
  EFM_ASSERT(SL_HAL_LEDSINK_REF_VALID(ledsink));

  // Check if ENBIASREF bit is set in DRCTLEDCTRL register to determine if
  // bias reference is enabled in software direct-drive mode.
  return ((ledsink->DRCTLEDCTRL & LEDSINK_DRCTLEDCTRL_ENBIASREF) != 0);
}

/***************************************************************************//**
 * Enable direct LED control for a specific channel in SW direct-drive mode.
 *
 * @note:
 *  This API is effective only when CFG0.DRIVEMODE = SWCONTROL (SW direct-drive mode).
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @param[in] led_channel      LED channel number (0-3).
 *
 * @return                     On Success returns SL_STATUS_OK.
 *                             On Failure returns SL_STATUS_INVALID_PARAMETER.
 ******************************************************************************/
__INLINE sl_status_t sl_hal_ledsink_enable_direct_led(LEDSINK_TypeDef *ledsink,
                                                      sl_hal_ledsink_led_channel_t led_channel)
{
  // Make sure the module exists on the selected chip.
  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  // Make sure the channel number is valid.
  if (led_channel >= SL_HAL_LEDSINK_MAX_LED_CHANNELS) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  // Set the ENLED bit.
  ledsink->DRCTLEDCTRL |= (LEDSINK_DRCTLEDCTRL_ENLED_ENLED0 << led_channel);

  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Disable direct LED control for a specific channel in SW direct-drive mode.
 *
 * @note:
 *   - This API is effective only when CFG0.DRIVEMODE = SWCONTROL (SW direct-drive mode).
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @param[in] led_channel      LED channel number (0-3).
 *
 * @return                     On Success returns SL_STATUS_OK.
 *                             On Failure returns SL_STATUS_INVALID_PARAMETER.
 ******************************************************************************/
__INLINE sl_status_t sl_hal_ledsink_disable_direct_led(LEDSINK_TypeDef *ledsink,
                                                       sl_hal_ledsink_led_channel_t led_channel)
{
  // Make sure the module exists on the selected chip.
  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  // Make sure the channel number is valid.
  if (led_channel >= SL_HAL_LEDSINK_MAX_LED_CHANNELS) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  // Clear the ENLED bit.
  ledsink->DRCTLEDCTRL &= ~(LEDSINK_DRCTLEDCTRL_ENLED_ENLED0 << led_channel);

  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Get direct LED control enable status for a specific LED channel.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @param[in] led_channel      LED channel number (0-3).
 *
 * @return                     true if direct LED control is enabled for the
 *                             channel, false otherwise.
 ******************************************************************************/
__INLINE bool sl_hal_ledsink_get_direct_led_enabled(LEDSINK_TypeDef *ledsink,
                                                    sl_hal_ledsink_led_channel_t led_channel)
{
  uint32_t enled_mask;

  // Make sure the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_LEDSINK_REF_VALID(ledsink));
  // Make sure the channel number is valid.
  EFM_ASSERT(led_channel < SL_HAL_LEDSINK_MAX_LED_CHANNELS);

  enled_mask = LEDSINK_DRCTLEDCTRL_ENLED_ENLED0 << led_channel;
  return (ledsink->DRCTLEDCTRL & enled_mask) != 0;
}

/***************************************************************************//**
 * Clear one or more pending LEDSINK interrupts.
 *
 * @details
 * Available interrupt sources:
 * - LEDVDDDROPIF [0]: LEDVDD is dropped
 * - LED0PATTERNDONEIF [1]: LED0 pattern completed
 * - LED1PATTERNDONEIF [2]: LED1 pattern completed
 * - LED2PATTERNDONEIF [3]: LED2 pattern completed
 * - LED3PATTERNDONEIF [4]: LED3 pattern completed
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @param[in] flags_mask       Pending LEDSINK interrupt source(s) to clear.
 *
 * @return                     On Success returns SL_STATUS_OK.
 *                             On Failure returns SL_STATUS_INVALID_PARAMETER.
 ******************************************************************************/
__INLINE sl_status_t sl_hal_ledsink_clear_interrupts(LEDSINK_TypeDef *ledsink,
                                                     uint8_t flags_mask)
{
  // Make sure the module exists on the selected chip.
  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  // Make sure the flags mask is valid.
  if (flags_mask & ~_LEDSINK_IF_MASK) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  // Clear the interrupts.
  ledsink->IF_CLR = flags_mask & _LEDSINK_IF_MASK;
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Get pending LEDSINK interrupt flags.
 *
 * @details
 * Available interrupt sources:
 * - LEDVDDDROPIF [0]: LEDVDD is dropped
 * - LED0PATTERNDONEIF [1]: LED0 pattern completed
 * - LED1PATTERNDONEIF [2]: LED1 pattern completed
 * - LED2PATTERNDONEIF [3]: LED2 pattern completed
 * - LED3PATTERNDONEIF [4]: LED3 pattern completed
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @return                     LEDSINK interrupt source(s) pending. Returns one
 *                             or more valid interrupt sources.
 ******************************************************************************/
__INLINE uint8_t sl_hal_ledsink_get_pending_interrupts(LEDSINK_TypeDef *ledsink)
{
  // Make sure the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_LEDSINK_REF_VALID(ledsink));

  return ledsink->IF & _LEDSINK_IF_MASK;
}

/***************************************************************************//**
 * Enable one or more LEDSINK interrupts.
 *
 * @details
 * Available interrupt sources:
 * - LEDVDDDROPIF [0]: LEDVDD is dropped
 * - LED0PATTERNDONEIF [1]: LED0 pattern completed
 * - LED1PATTERNDONEIF [2]: LED1 pattern completed
 * - LED2PATTERNDONEIF [3]: LED2 pattern completed
 * - LED3PATTERNDONEIF [4]: LED3 pattern completed
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @param[in] interrupt_mask   LEDSINK interrupt sources to enable.
 *
 * @return                     On Success returns SL_STATUS_OK.
 *                             On Failure returns SL_STATUS_INVALID_PARAMETER.
 ******************************************************************************/
__INLINE sl_status_t sl_hal_ledsink_enable_interrupts(LEDSINK_TypeDef *ledsink,
                                                      uint8_t interrupt_mask)
{
  // Make sure the module exists on the selected chip.
  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  // Make sure the interrupt mask is valid.
  if (interrupt_mask & ~_LEDSINK_IEN_MASK) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  // Enable the interrupts.
  ledsink->IEN_SET = interrupt_mask & _LEDSINK_IEN_MASK;
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Get enabled LEDSINK interrupt flags.
 *
 * @details
 * Available interrupt sources:
 * - LEDVDDDROPIF [0]: LEDVDD is dropped
 * - LED0PATTERNDONEIF [1]: LED0 pattern completed
 * - LED1PATTERNDONEIF [2]: LED1 pattern completed
 * - LED2PATTERNDONEIF [3]: LED2 pattern completed
 * - LED3PATTERNDONEIF [4]: LED3 pattern completed
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @return                     LEDSINK interrupt source(s) enabled. Returns one
 *                             or more valid enabled interrupt sources.
 ******************************************************************************/
__INLINE uint8_t sl_hal_ledsink_get_enabled_interrupts(LEDSINK_TypeDef *ledsink)
{
  // Make sure the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_LEDSINK_REF_VALID(ledsink));

  return ledsink->IEN;
}

/***************************************************************************//**
 * Set debug bus control register value.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @param[in] dbg_value        Debug bus control value (0-7).
 *
 * @return                     On Success returns SL_STATUS_OK.
 *                             On Failure returns SL_STATUS_INVALID_PARAMETER.
 ******************************************************************************/
__INLINE sl_status_t sl_hal_ledsink_set_dbg(LEDSINK_TypeDef *ledsink, uint8_t dbg_value)
{
  if (!SL_HAL_LEDSINK_REF_VALID(ledsink)) {
    return SL_STATUS_INVALID_PARAMETER;
  }
  // Make sure the debug value is valid.
  if (dbg_value > _LEDSINK_DBG_MASK) {
    return SL_STATUS_INVALID_PARAMETER;
  }
  // Set the debug value.
  ledsink->DBG = dbg_value & _LEDSINK_DBG_MASK;

  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Get LEDSINK status register value.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @return                     Current STATUS register value.
 ******************************************************************************/
__INLINE uint32_t sl_hal_ledsink_get_status(LEDSINK_TypeDef *ledsink)
{
  // Make sure the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_LEDSINK_REF_VALID(ledsink));

  return ledsink->STATUS;
}

/***************************************************************************//**
 * Get LEDVDD fall edge status.
 *
 * @details
 *   This function checks the LEDVDDFALLEDGE bit in the STATUS register, which
 *   indicates that LEDVDD has dropped below the threshold. This bit is automatically
 *   set/cleared by hardware based on the LEDVDD voltage level.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @return                     true if LEDVDD fall edge detected (LEDVDD dropped),
 *                             false if LEDVDD is stable above threshold.
 ******************************************************************************/
__INLINE bool sl_hal_ledsink_get_ledvdd_fall_edge(LEDSINK_TypeDef *ledsink)
{
  // Make sure the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_LEDSINK_REF_VALID(ledsink));

  return (ledsink->STATUS & LEDSINK_STATUS_LEDVDDFALLEDGE) != 0U;
}

/***************************************************************************//**
 * Get synchronization busy register value.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @return                     Current SYNCBUSY register value.
 ******************************************************************************/
__INLINE uint32_t sl_hal_ledsink_get_sync_busy(LEDSINK_TypeDef *ledsink)
{
  // Make sure the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_LEDSINK_REF_VALID(ledsink));

  return ledsink->SYNCBUSY;
}

/***************************************************************************//**
 * Get LED current setting for a channel.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @param[in] led_channel      LED channel number (0-3).
 *
 * @return                     Current step value (0-29).
 ******************************************************************************/
__INLINE uint8_t sl_hal_ledsink_get_channel_current(LEDSINK_TypeDef *ledsink,
                                                    sl_hal_ledsink_led_channel_t led_channel)
{
  // Make sure the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_LEDSINK_REF_VALID(ledsink));
  // Make sure the channel number is valid.
  EFM_ASSERT(led_channel < SL_HAL_LEDSINK_MAX_LED_CHANNELS);
  return (uint8_t)((ledsink->CFGSEQ[led_channel].CURRCTRL & _LEDSINK_CURRCTRL_CURRSET_MASK) >> _LEDSINK_CURRCTRL_CURRSET_SHIFT);
}

/***************************************************************************//**
 * Get pattern execution status register (PTRNEXSTS) value for a LED channel.
 *
 * @details
 *   This function returns the raw PTRNEXSTS register value for the specified
 *   LED channel. The register values are: 0x0: Pattern idle, 0x1: Pattern busy,
 *   0x2: Pattern done.
 *
 * @param[in] ledsink          A pointer to the LEDSINK peripheral register block.
 *
 * @param[in] led_channel      LED channel number (0-3).
 *
 * @return                     PTRNEXSTS register value (0x0 = idle, 0x1 = busy,
 *                             0x2 = done).
 ******************************************************************************/
__INLINE uint32_t sl_hal_ledsink_get_pattern_execution_status(LEDSINK_TypeDef *ledsink,
                                                              sl_hal_ledsink_led_channel_t led_channel)
{
  // Make sure the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_LEDSINK_REF_VALID(ledsink));
  // Make sure the channel number is valid.
  EFM_ASSERT(led_channel < SL_HAL_LEDSINK_MAX_LED_CHANNELS);
  return ledsink->CFGSEQ[led_channel].PTRNEXSTS;
}

/** @} (end addtogroup ledsink) */
#ifdef __cplusplus
}
#endif

#endif /* defined(LEDSINK_PRESENT) */
#endif /* SL_HAL_LEDSINK_H */
