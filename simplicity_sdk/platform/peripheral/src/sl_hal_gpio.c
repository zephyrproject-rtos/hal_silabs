/***************************************************************************//**
 * @file
 * @brief General Purpose IO (GPIO) peripheral API.
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

#include "sl_hal_gpio.h"
#if defined(GPIO_PRESENT)
#include "sl_hal_bus.h"

/*******************************************************************************
 **************************   GLOBAL FUNCTIONS   *******************************
 ******************************************************************************/
extern __INLINE void sl_hal_gpio_lock(void);
extern __INLINE void sl_hal_gpio_unlock(void);
extern __INLINE uint32_t sl_hal_gpio_get_lock_status(void);
extern __INLINE bool sl_hal_gpio_is_gpio_port(sl_gpio_port_t port);
#if defined(HSIO_PRESENT)
extern __INLINE bool sl_hal_gpio_is_hsio_port(sl_gpio_port_t port);
#endif
extern __INLINE void sl_hal_gpio_set_pin(const sl_gpio_t *gpio);
extern __INLINE void sl_hal_gpio_set_port(sl_gpio_port_t port,
                                          uint32_t pins);
extern __INLINE void sl_hal_gpio_set_port_value(sl_gpio_port_t port,
                                                uint32_t val,
                                                uint32_t mask);
extern __INLINE void sl_hal_gpio_clear_pin(const sl_gpio_t *gpio);
extern __INLINE void sl_hal_gpio_clear_port(sl_gpio_port_t port,
                                            uint32_t pins);
extern __INLINE bool sl_hal_gpio_get_pin_input(const sl_gpio_t *gpio);
extern __INLINE bool sl_hal_gpio_get_pin_output(const sl_gpio_t *gpio);
extern __INLINE uint32_t sl_hal_gpio_get_port_input(sl_gpio_port_t port);
extern __INLINE uint32_t sl_hal_gpio_get_port_output(sl_gpio_port_t port);
extern __INLINE void sl_hal_gpio_toggle_pin(const sl_gpio_t *gpio);
extern __INLINE void sl_hal_gpio_toggle_port(sl_gpio_port_t port,
                                             uint32_t pins);
extern __INLINE sl_status_t sl_hal_gpio_set_slew_rate(const sl_gpio_t *gpio,
                                                      uint8_t slewrate);
extern __INLINE sl_status_t sl_hal_gpio_get_slew_rate(const sl_gpio_t *gpio,
                                                      uint8_t *slewrate);
#if defined(_GPIO_P_CTRL_SLEWRATEALT_MASK)
extern __INLINE void sl_hal_gpio_set_slew_rate_alternate(sl_gpio_port_t port,
                                                         uint8_t slewrate_alt);
extern __INLINE uint8_t sl_hal_gpio_get_slew_rate_alternate(sl_gpio_port_t port);
#endif
extern __INLINE void sl_hal_gpio_enable_interrupts(uint32_t flags);
extern __INLINE void sl_hal_gpio_disable_interrupts(uint32_t flags);
extern __INLINE void sl_hal_gpio_clear_interrupts(uint32_t flags);
extern __INLINE void sl_hal_gpio_set_interrupts(uint32_t flags);
extern __INLINE uint32_t sl_hal_gpio_get_pending_interrupts(void);
extern __INLINE uint32_t sl_hal_gpio_get_enabled_interrupts(void);
extern __INLINE uint32_t sl_hal_gpio_get_enabled_pending_interrupts(void);
extern __INLINE int32_t sl_hal_gpio_get_external_interrupt_number(uint8_t pin,
                                                                  uint32_t enabled_interrupts_mask);
extern __INLINE int32_t sl_hal_gpio_get_em4_interrupt_number(const sl_gpio_t *gpio);
extern __INLINE void sl_hal_gpio_set_pin_em4_retention(bool enable);
extern __INLINE void sl_hal_gpio_disable_pin_em4_wakeup (uint32_t pinmask);
extern __INLINE uint32_t sl_hal_gpio_get_pin_em4_wakeup_cause(void);
extern __INLINE void sl_hal_gpio_enable_debug_swo(bool enable);
extern __INLINE void sl_hal_gpio_enable_debug_swd_clk(bool enable);
extern __INLINE void sl_hal_gpio_enable_debug_swd_io(bool enable);
#if defined(_HSIO_P_PRDRVSTRENGTH_PRDRVSTRENGTH0_MASK) && defined(HSIO_PRESENT)
extern __INLINE sl_status_t sl_hal_gpio_set_pre_driver_strength(sl_gpio_t *gpio,
                                                                uint8_t predrv_strength);
extern __INLINE sl_status_t sl_hal_gpio_get_pre_driver_strength(sl_gpio_t *gpio,
                                                                uint8_t *predrv_strength);
#endif
#if defined(_HSIO_P_DRVSTRENGTH_MASK) && defined(HSIO_PRESENT)
extern __INLINE sl_status_t sl_hal_gpio_set_drive_strength(sl_gpio_t *gpio,
                                                           uint8_t drive_strength);
extern __INLINE sl_status_t sl_hal_gpio_get_drive_strength(sl_gpio_t *gpio,
                                                           uint8_t *drive_strength);
#endif
#if defined(_HSIO_P_HSRX_MASK) && defined(HSIO_PRESENT)
extern __INLINE sl_status_t sl_hal_gpio_is_high_speed_rx_enabled(sl_gpio_t *gpio,
                                                                bool *is_enabled);
extern __INLINE sl_status_t sl_hal_gpio_configure_high_speed_rx(sl_gpio_t *gpio,
                                                                bool enable);
#endif
#if defined(_HSIO_P_HSRXHYST_MASK) && defined(HSIO_PRESENT)
extern __INLINE sl_status_t sl_hal_gpio_set_high_speed_rx_hysteresis(sl_gpio_t *gpio,
                                                                     uint8_t hysteresis);
extern __INLINE sl_status_t sl_hal_gpio_get_high_speed_rx_hysteresis(sl_gpio_t *gpio,
                                                                     uint8_t *hysteresis);
#endif
#if defined(_HSIO_P_NONOVRLPDIS_MASK) && defined(HSIO_PRESENT)
extern __INLINE sl_status_t sl_hal_gpio_set_non_overlap_protection_disable(sl_gpio_t *gpio,
                                                                          bool disable);
extern __INLINE sl_status_t sl_hal_gpio_get_non_overlap_protection_disable(sl_gpio_t *gpio,
                                                                          bool *disable);
#endif

/*******************************************************************************
 ***************************   LOCAL FUNCTIONS   *******************************
 ******************************************************************************/
static sl_gpio_mode_t sl_hal_gpio_map_gpio_mode(sl_gpio_mode_t mode);
static sl_gpio_mode_t sl_hal_gpio_map_gpio_reg_to_mode(sl_gpio_mode_t mode);
#if defined(HSIO_PRESENT)
static sl_gpio_mode_t sl_hal_gpio_map_hsio_mode(sl_gpio_mode_t mode);
static sl_gpio_mode_t sl_hal_gpio_map_hsio_reg_to_mode(sl_gpio_mode_t mode);
#endif

/*******************************************************************************
 **************************   GLOBAL FUNCTIONS   *******************************
 ******************************************************************************/

/***************************************************************************//**
 *   Sets the mode for GPIO pin.
 ******************************************************************************/
void sl_hal_gpio_set_pin_mode(const sl_gpio_t *gpio,
                              sl_gpio_mode_t mode,
                              bool output_value)
{
  EFM_ASSERT(gpio != NULL);
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  EFM_ASSERT(sl_hal_gpio_get_lock_status() == 0);

  sl_gpio_mode_t gpio_mode = SL_GPIO_MODE_DISABLED;
#if defined(HSIO_PRESENT)
  bool is_hsio = sl_hal_gpio_is_hsio_port(gpio->port);
  uint8_t hsio_index = is_hsio ? SL_HAL_HSIO_PORT_INDEX(gpio->port) : 0u;
  gpio_mode = is_hsio ? sl_hal_gpio_map_hsio_mode(mode) : sl_hal_gpio_map_gpio_mode(mode);
#else
  gpio_mode = sl_hal_gpio_map_gpio_mode(mode);
#endif

  EFM_ASSERT(SL_HAL_GPIO_MODE_IS_VALID(gpio_mode));

  // If disabling a pin, do not modify DOUT to reduce the chance of
  // a glitch/spike (may not be sufficient precaution in all use cases).
  // As mode settings are dependent on DOUT values, setting output value
  // prior to mode. @ref enum - sl_gpio_mode_t
  if (mode != SL_GPIO_MODE_DISABLED) {
    if (output_value) {
      sl_hal_gpio_set_pin(gpio);
    } else {
      sl_hal_gpio_clear_pin(gpio);
    }
  }

  // There are two registers controlling the pins for each port.
  // The MODEL register controls pins 0-7 and MODEH controls pins 8-15.
#if defined(HSIO_PRESENT)
  if (is_hsio) {
    if (gpio->pin < 8) {
      sl_hal_bus_reg_write_mask(&(GPIO->H[hsio_index].MODEL),
                                0xFu << (gpio->pin * 4),
                                gpio_mode << (gpio->pin * 4));
    } else {
      sl_hal_bus_reg_write_mask(&(GPIO->H[hsio_index].MODEH),
                                0xFu << ((gpio->pin - 8) * 4),
                                gpio_mode << ((gpio->pin - 8) * 4));
    }
  } else
#endif
  {
    if (gpio->pin < 8) {
      sl_hal_bus_reg_write_mask(&(GPIO->P[gpio->port].MODEL),
                                0xFu << (gpio->pin * 4),
                                gpio_mode << (gpio->pin * 4));
    } else {
      sl_hal_bus_reg_write_mask(&(GPIO->P[gpio->port].MODEH),
                                0xFu << ((gpio->pin - 8) * 4),
                                gpio_mode << ((gpio->pin - 8) * 4));
    }
  }

  // SL_GPIO_MODE_DISABLED based on DOUT Value (low/high) act as two different configurations.
  // By setting mode to disabled first and then modifying the DOUT value, so that
  // previous mode configuration on given pin not effected.
  if (mode == SL_GPIO_MODE_DISABLED) {
    if (output_value) {
      sl_hal_gpio_set_pin(gpio);
    } else {
      sl_hal_gpio_clear_pin(gpio);
    }
  }
}

/***************************************************************************//**
 *  Get the mode for a GPIO pin.
 ******************************************************************************/
sl_gpio_mode_t sl_hal_gpio_get_pin_mode(const sl_gpio_t *gpio)
{
  EFM_ASSERT(gpio != NULL);
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));

  sl_gpio_mode_t mode = SL_GPIO_MODE_DISABLED;
#if defined(HSIO_PRESENT)
  bool is_hsio = sl_hal_gpio_is_hsio_port(gpio->port);
  uint8_t hsio_index = is_hsio ? SL_HAL_HSIO_PORT_INDEX(gpio->port) : 0u;
#endif

  // Determine the current mode of the GPIO pin based on the pin number.
#if defined(HSIO_PRESENT)
  if (is_hsio) {
    if (gpio->pin < 8) {
      mode = (sl_gpio_mode_t) ((GPIO->H[hsio_index].MODEL >> (gpio->pin * 4)) & 0xF);
    } else {
      mode = (sl_gpio_mode_t) ((GPIO->H[hsio_index].MODEH >> ((gpio->pin - 8) * 4)) & 0xF);
    }
  } else
#endif
  {
    if (gpio->pin < 8) {
      mode = (sl_gpio_mode_t) ((GPIO->P[gpio->port].MODEL >> (gpio->pin * 4)) & 0xF);
    } else {
      mode = (sl_gpio_mode_t) ((GPIO->P[gpio->port].MODEH >> ((gpio->pin - 8) * 4)) & 0xF);
    }
  }

  // Map the hardware-specific mode to the corresponding sl_gpio_mode_t value
#if defined(HSIO_PRESENT)
  if (is_hsio) {
    return sl_hal_gpio_map_hsio_reg_to_mode(mode);
  }
#endif
  return sl_hal_gpio_map_gpio_reg_to_mode(mode);
}

/***************************************************************************//**
 *   Configure the GPIO pin interrupt.
 ******************************************************************************/
int32_t sl_hal_gpio_configure_external_interrupt(const sl_gpio_t *gpio,
                                                 int32_t int_no,
                                                 sl_gpio_interrupt_flag_t flags)
{
  EFM_ASSERT(gpio != NULL);
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  EFM_ASSERT(SL_GPIO_FLAG_IS_VALID(flags));
  EFM_ASSERT(sl_hal_gpio_get_lock_status() == 0);

  if (int_no != SL_GPIO_INTERRUPT_UNAVAILABLE && int_no >= 0) {
#if defined(_GPIO_EXTIPINSELL_MASK)
    EFM_ASSERT(SL_HAL_GPIO_INTNO_PIN_VALID(int_no, gpio->pin));
#endif
  }

#if !defined(_GPIO_EXTIPINSELL_MASK)
  int_no = gpio->pin;
#endif

  if (int_no == SL_GPIO_INTERRUPT_UNAVAILABLE) {
    uint32_t interrupts_enabled = sl_hal_gpio_get_enabled_interrupts();
    int_no = sl_hal_gpio_get_external_interrupt_number(gpio->pin, interrupts_enabled);
  }

  if (int_no != SL_GPIO_INTERRUPT_UNAVAILABLE && int_no >= 0) {
    if (int_no < 8) {
      // The EXTIPSELL register controls pins 0-7 of the interrupt configuration.
#if defined(_GPIO_EXTIPSELL_EXTIPSEL0_MASK)
      sl_hal_bus_reg_write_mask(&GPIO->EXTIPSELL,
                                _GPIO_EXTIPSELL_EXTIPSEL0_MASK
                                << (_GPIO_EXTIPSELL_EXTIPSEL1_SHIFT * int_no),
                                (uint32_t)gpio->port << (_GPIO_EXTIPSELL_EXTIPSEL1_SHIFT * int_no));
#endif
      // The EXTIPINSELL register controls interrupt 0-7 of the interrupt/pin number mapping.
#if defined(_GPIO_EXTIPINSELL_EXTIPINSEL0_MASK)
      sl_hal_bus_reg_write_mask(&GPIO->EXTIPINSELL,
                                _GPIO_EXTIPINSELL_EXTIPINSEL0_MASK
                                << (_GPIO_EXTIPINSELL_EXTIPINSEL1_SHIFT * int_no),
                                ((gpio->pin % 4) & _GPIO_EXTIPINSELL_EXTIPINSEL0_MASK)
                                << (_GPIO_EXTIPINSELL_EXTIPINSEL1_SHIFT * int_no));
#endif
    } else {
      // EXTIPSELH controls pins 8-15 of the interrupt configuration.
#if defined(_GPIO_EXTIPSELH_EXTIPSEL0_MASK)
      uint32_t tmp = int_no - 8;
      sl_hal_bus_reg_write_mask(&GPIO->EXTIPSELH,
                                _GPIO_EXTIPSELH_EXTIPSEL0_MASK
                                << (_GPIO_EXTIPSELH_EXTIPSEL1_SHIFT * tmp),
                                (uint32_t)gpio->port << (_GPIO_EXTIPSELH_EXTIPSEL1_SHIFT * tmp));
#endif
      // EXTIPINSELH controls interrupt 8-15 of the interrupt/pin number mapping.
#if defined(_GPIO_EXTIPINSELH_EXTIPINSEL0_MASK)
      sl_hal_bus_reg_write_mask(&GPIO->EXTIPINSELH,
                                _GPIO_EXTIPINSELH_EXTIPINSEL0_MASK
                                << (_GPIO_EXTIPINSELH_EXTIPINSEL1_SHIFT * tmp),
                                ((gpio->pin % 4) & _GPIO_EXTIPINSELH_EXTIPINSEL0_MASK)
                                << (_GPIO_EXTIPINSELH_EXTIPINSEL1_SHIFT * tmp));
#endif
    }

    // Enable/disable rising edge interrupt.
    (((flags & SL_GPIO_INTERRUPT_RISING_EDGE) == SL_GPIO_INTERRUPT_RISING_EDGE)
     || ((flags & SL_GPIO_INTERRUPT_RISING_FALLING_EDGE) == SL_GPIO_INTERRUPT_RISING_FALLING_EDGE)) \
    ? sl_hal_bus_reg_write_bit(&(GPIO->EXTIRISE), int_no, true)                                     \
    : sl_hal_bus_reg_write_bit(&(GPIO->EXTIRISE), int_no, false);

    // Enable/disable falling edge interrupt.
    (((flags & SL_GPIO_INTERRUPT_FALLING_EDGE) == SL_GPIO_INTERRUPT_FALLING_EDGE)
     || (flags & SL_GPIO_INTERRUPT_RISING_FALLING_EDGE) == SL_GPIO_INTERRUPT_RISING_FALLING_EDGE) \
    ? sl_hal_bus_reg_write_bit(&(GPIO->EXTIFALL), int_no, true)                                   \
    : sl_hal_bus_reg_write_bit(&(GPIO->EXTIFALL), int_no, false);

    // Clear any pending interrupt.
    sl_hal_gpio_clear_interrupts(1 << int_no);
  }

  return int_no;
}

/**************************************************************************//**
 *   Enable GPIO pin wake-up from EM4. When the function exits,
 *   EM4 mode can be safely entered.
 *****************************************************************************/
void sl_hal_gpio_enable_pin_em4_wakeup(uint32_t pinmask,
                                       uint32_t polaritymask)
{
  EFM_ASSERT((pinmask & ~_GPIO_EM4WUEN_MASK) == 0);
  EFM_ASSERT((polaritymask & ~_GPIO_EM4WUPOL_MASK) == 0);

  GPIO->EM4WUPOL &= ~pinmask;               // Set the wakeup polarity.
  GPIO->EM4WUPOL |= pinmask & polaritymask;
  GPIO->EM4WUEN  |= pinmask;                // Enable wakeup.

  sl_hal_gpio_set_pin_em4_retention(true);  // Enable the pin retention.
  sl_hal_gpio_clear_interrupts(pinmask);    // clear any pending interrupt.
}

/***************************************************************************//**
 *    Configure EM4WU pins as external level-sensitive interrupts.
 ******************************************************************************/
int32_t sl_hal_gpio_configure_wakeup_em4_external_interrupt(const sl_gpio_t *gpio,
                                                            int32_t int_no,
                                                            bool polarity)
{
  EFM_ASSERT(gpio != NULL);
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  EFM_ASSERT(sl_hal_gpio_get_lock_status() == 0);

#if defined(HSIO_PRESENT)
  bool is_hsio = sl_hal_gpio_is_hsio_port(gpio->port);
  if (is_hsio) {
    return SL_GPIO_INTERRUPT_UNAVAILABLE;
  }
#endif

  int32_t em4_int_no = sl_hal_gpio_get_em4_interrupt_number(gpio);

  if (int_no == SL_GPIO_INTERRUPT_UNAVAILABLE) {
    int_no = em4_int_no;
  }

  if (em4_int_no == SL_GPIO_INTERRUPT_UNAVAILABLE || int_no != em4_int_no) {
    return SL_GPIO_INTERRUPT_UNAVAILABLE;
  }

  if (int_no != SL_GPIO_INTERRUPT_UNAVAILABLE) {
    // GPIO pin mode set.
    sl_hal_gpio_set_pin_mode(gpio, SL_GPIO_MODE_INPUT_PULL_FILTER, (unsigned int)!polarity);

    // Enable EM4WU function and set polarity.
    uint32_t polarityMask = (uint32_t)polarity << (int_no + _GPIO_EM4WUEN_EM4WUEN_SHIFT);
    uint32_t pinmask =  1UL << (int_no + _GPIO_EM4WUEN_EM4WUEN_SHIFT);

    sl_hal_gpio_enable_pin_em4_wakeup(pinmask, polarityMask);
  }

  return int_no;
}

/*******************************************************************************
 ***************************   LOCAL FUNCTIONS   *******************************
 ******************************************************************************/

static sl_gpio_mode_t sl_hal_gpio_map_gpio_mode(sl_gpio_mode_t mode)
{
  switch (mode) {
    #if defined(_GPIO_P_MODEL_MODE0_DISABLED)
        case SL_GPIO_MODE_DISABLED:
          return  _GPIO_P_MODEL_MODE0_DISABLED;
    #endif
    #if defined(_GPIO_P_MODEL_MODE0_INPUT)
        case SL_GPIO_MODE_INPUT:
          return _GPIO_P_MODEL_MODE0_INPUT;
    #endif
    #if defined(_GPIO_P_MODEL_MODE0_INPUTPULL)
        case SL_GPIO_MODE_INPUT_PULL:
          return _GPIO_P_MODEL_MODE0_INPUTPULL;
    #endif
    #if defined(_GPIO_P_MODEL_MODE0_INPUTPULLFILTER)
        case SL_GPIO_MODE_INPUT_PULL_FILTER:
          return _GPIO_P_MODEL_MODE0_INPUTPULLFILTER;
    #endif
    #if defined(_GPIO_P_MODEL_MODE0_PUSHPULL)
        case SL_GPIO_MODE_PUSH_PULL:
          return _GPIO_P_MODEL_MODE0_PUSHPULL;
    #endif
    #if defined(_GPIO_P_MODEL_MODE0_PUSHPULLALT)
        case SL_GPIO_MODE_PUSH_PULL_ALTERNATE:
          return _GPIO_P_MODEL_MODE0_PUSHPULLALT;
    #endif
    #if defined(_GPIO_P_MODEL_MODE0_WIREDOR)
        case SL_GPIO_MODE_WIRED_OR:
          return _GPIO_P_MODEL_MODE0_WIREDOR;
    #endif
    #if defined(_GPIO_P_MODEL_MODE0_WIREDORPULLDOWN)
        case SL_GPIO_MODE_WIRED_OR_PULL_DOWN:
          return _GPIO_P_MODEL_MODE0_WIREDORPULLDOWN;
    #endif
    #if defined(_GPIO_P_MODEL_MODE0_WIREDAND)
        case SL_GPIO_MODE_WIRED_AND:
          return _GPIO_P_MODEL_MODE0_WIREDAND;
    #endif
    #if defined(_GPIO_P_MODEL_MODE0_WIREDANDFILTER)
        case SL_GPIO_MODE_WIRED_AND_FILTER:
          return _GPIO_P_MODEL_MODE0_WIREDANDFILTER;
    #endif
    #if defined(_GPIO_P_MODEL_MODE0_WIREDANDPULLUP)
        case SL_GPIO_MODE_WIRED_AND_PULLUP:
          return _GPIO_P_MODEL_MODE0_WIREDANDPULLUP;
    #endif
    #if defined(_GPIO_P_MODEL_MODE0_WIREDANDPULLUPFILTER)
        case SL_GPIO_MODE_WIRED_AND_PULLUP_FILTER:
          return _GPIO_P_MODEL_MODE0_WIREDANDPULLUPFILTER;
    #endif
    #if defined(_GPIO_P_MODEL_MODE0_WIREDANDALT)
        case SL_GPIO_MODE_WIRED_AND_ALTERNATE:
          return _GPIO_P_MODEL_MODE0_WIREDANDALT;
    #endif
    #if defined(_GPIO_P_MODEL_MODE0_WIREDANDALTFILTER)
        case SL_GPIO_MODE_WIRED_AND_ALTERNATE_FILTER:
          return _GPIO_P_MODEL_MODE0_WIREDANDALTFILTER;
    #endif
    #if defined(_GPIO_P_MODEL_MODE0_WIREDANDALTPULLUP)
        case SL_GPIO_MODE_WIRED_AND_ALTERNATE_PULLUP:
          return _GPIO_P_MODEL_MODE0_WIREDANDALTPULLUP;
    #endif
    #if defined(_GPIO_P_MODEL_MODE0_WIREDANDALTPULLUPFILTER)
        case SL_GPIO_MODE_WIRED_AND_ALTERNATE_PULLUP_FILTER:
          return _GPIO_P_MODEL_MODE0_WIREDANDALTPULLUPFILTER;
    #endif
        default:
          EFM_ASSERT(false);
          return SL_GPIO_MODE_DISABLED;
    }
}

static sl_gpio_mode_t sl_hal_gpio_map_gpio_reg_to_mode(sl_gpio_mode_t mode)
{
  // Map the hardware-specific mode to the corresponding sl_gpio_mode_t value
  switch (mode) {
#if defined(_GPIO_P_MODEL_MODE0_DISABLED)
    case _GPIO_P_MODEL_MODE0_DISABLED:
      return SL_GPIO_MODE_DISABLED;
#endif
#if defined(_GPIO_P_MODEL_MODE0_INPUT)
    case _GPIO_P_MODEL_MODE0_INPUT:
      return SL_GPIO_MODE_INPUT;
#endif
#if defined(_GPIO_P_MODEL_MODE0_INPUTPULL)
    case _GPIO_P_MODEL_MODE0_INPUTPULL:
      return SL_GPIO_MODE_INPUT_PULL;
#endif
#if defined(_GPIO_P_MODEL_MODE0_INPUTPULLFILTER)
    case _GPIO_P_MODEL_MODE0_INPUTPULLFILTER:
      return SL_GPIO_MODE_INPUT_PULL_FILTER;
#endif
#if defined(_GPIO_P_MODEL_MODE0_PUSHPULL)
    case _GPIO_P_MODEL_MODE0_PUSHPULL:
      return SL_GPIO_MODE_PUSH_PULL;
#endif
#if defined(_GPIO_P_MODEL_MODE0_PUSHPULLALT)
    case _GPIO_P_MODEL_MODE0_PUSHPULLALT:
      return SL_GPIO_MODE_PUSH_PULL_ALTERNATE;
#endif
#if defined(_GPIO_P_MODEL_MODE0_WIREDOR)
    case _GPIO_P_MODEL_MODE0_WIREDOR:
      return SL_GPIO_MODE_WIRED_OR;
#endif
#if defined(_GPIO_P_MODEL_MODE0_WIREDORPULLDOWN)
    case _GPIO_P_MODEL_MODE0_WIREDORPULLDOWN:
      return SL_GPIO_MODE_WIRED_OR_PULL_DOWN;
#endif
#if defined(_GPIO_P_MODEL_MODE0_WIREDAND)
    case _GPIO_P_MODEL_MODE0_WIREDAND:
      return SL_GPIO_MODE_WIRED_AND;
#endif
#if defined(_GPIO_P_MODEL_MODE0_WIREDANDFILTER)
    case _GPIO_P_MODEL_MODE0_WIREDANDFILTER:
      return SL_GPIO_MODE_WIRED_AND_FILTER;
#endif
#if defined(_GPIO_P_MODEL_MODE0_WIREDANDPULLUP)
    case _GPIO_P_MODEL_MODE0_WIREDANDPULLUP:
      return SL_GPIO_MODE_WIRED_AND_PULLUP;
#endif
#if defined(_GPIO_P_MODEL_MODE0_WIREDANDPULLUPFILTER)
    case _GPIO_P_MODEL_MODE0_WIREDANDPULLUPFILTER:
      return SL_GPIO_MODE_WIRED_AND_PULLUP_FILTER;
#endif
#if defined(_GPIO_P_MODEL_MODE0_WIREDANDALT)
    case _GPIO_P_MODEL_MODE0_WIREDANDALT:
      return SL_GPIO_MODE_WIRED_AND_ALTERNATE;
#endif
#if defined(_GPIO_P_MODEL_MODE0_WIREDANDALTFILTER)
    case _GPIO_P_MODEL_MODE0_WIREDANDALTFILTER:
      return SL_GPIO_MODE_WIRED_AND_ALTERNATE_FILTER;
#endif
#if defined(_GPIO_P_MODEL_MODE0_WIREDANDALTPULLUP)
    case _GPIO_P_MODEL_MODE0_WIREDANDALTPULLUP:
      return SL_GPIO_MODE_WIRED_AND_ALTERNATE_PULLUP;
#endif
#if defined(_GPIO_P_MODEL_MODE0_WIREDANDALTPULLUPFILTER)
    case _GPIO_P_MODEL_MODE0_WIREDANDALTPULLUPFILTER:
      return SL_GPIO_MODE_WIRED_AND_ALTERNATE_PULLUP_FILTER;
#endif
    default:
      EFM_ASSERT(false);
      return mode; // returning the default state
  }
}

#if defined(HSIO_PRESENT)
// Map logical GPIO mode to HSIO register encoding (HSIO MODEL/MODEH only).
static sl_gpio_mode_t sl_hal_gpio_map_hsio_mode(sl_gpio_mode_t mode)
{
  switch (mode) {
#if defined(_HSIO_P_MODEL_MODE0_DISABLED)
    case SL_GPIO_MODE_DISABLED:
      return _HSIO_P_MODEL_MODE0_DISABLED;
#endif
#if defined(_HSIO_P_MODEL_MODE0_INPUT)
    case SL_GPIO_MODE_INPUT:
      return _HSIO_P_MODEL_MODE0_INPUT;
#endif
#if defined(_HSIO_P_MODEL_MODE0_INPUTPULL)
    case SL_GPIO_MODE_INPUT_PULL:
      return _HSIO_P_MODEL_MODE0_INPUTPULL;
#endif
#if defined(_HSIO_P_MODEL_MODE0_INPUTPULLFILTER)
    case SL_GPIO_MODE_INPUT_PULL_FILTER:
      return _HSIO_P_MODEL_MODE0_INPUTPULLFILTER;
#endif
#if defined(_HSIO_P_MODEL_MODE0_PUSHPULL)
    case SL_GPIO_MODE_PUSH_PULL:
      return _HSIO_P_MODEL_MODE0_PUSHPULL;
#endif
#if defined(_HSIO_P_MODEL_MODE0_WIREDOR)
    case SL_GPIO_MODE_WIRED_OR:
      return _HSIO_P_MODEL_MODE0_WIREDOR;
#endif
#if defined(_HSIO_P_MODEL_MODE0_WIREDORPULLDOWN)
    case SL_GPIO_MODE_WIRED_OR_PULL_DOWN:
      return _HSIO_P_MODEL_MODE0_WIREDORPULLDOWN;
#endif
#if defined(_HSIO_P_MODEL_MODE0_WIREDAND)
    case SL_GPIO_MODE_WIRED_AND:
      return _HSIO_P_MODEL_MODE0_WIREDAND;
#endif
#if defined(_HSIO_P_MODEL_MODE0_WIREDANDFILTER)
    case SL_GPIO_MODE_WIRED_AND_FILTER:
      return _HSIO_P_MODEL_MODE0_WIREDANDFILTER;
#endif
#if defined(_HSIO_P_MODEL_MODE0_WIREDANDPULLUP)
    case SL_GPIO_MODE_WIRED_AND_PULLUP:
      return _HSIO_P_MODEL_MODE0_WIREDANDPULLUP;
#endif
#if defined(_HSIO_P_MODEL_MODE0_WIREDANDPULLUPFILTER)
    case SL_GPIO_MODE_WIRED_AND_PULLUP_FILTER:
      return _HSIO_P_MODEL_MODE0_WIREDANDPULLUPFILTER;
#endif
    default:
      EFM_ASSERT(false);
      return SL_GPIO_MODE_DISABLED;
  }
}

// Map HSIO register encoding to logical GPIO mode.
static sl_gpio_mode_t sl_hal_gpio_map_hsio_reg_to_mode(sl_gpio_mode_t mode)
{
  switch (mode) {
#if defined(_HSIO_P_MODEL_MODE0_DISABLED)
    case _HSIO_P_MODEL_MODE0_DISABLED:
      return SL_GPIO_MODE_DISABLED;
#endif
#if defined(_HSIO_P_MODEL_MODE0_INPUT)
    case _HSIO_P_MODEL_MODE0_INPUT:
      return SL_GPIO_MODE_INPUT;
#endif
#if defined(_HSIO_P_MODEL_MODE0_INPUTPULL)
    case _HSIO_P_MODEL_MODE0_INPUTPULL:
      return SL_GPIO_MODE_INPUT_PULL;
#endif
#if defined(_HSIO_P_MODEL_MODE0_INPUTPULLFILTER)
    case _HSIO_P_MODEL_MODE0_INPUTPULLFILTER:
      return SL_GPIO_MODE_INPUT_PULL_FILTER;
#endif
#if defined(_HSIO_P_MODEL_MODE0_PUSHPULL)
    case _HSIO_P_MODEL_MODE0_PUSHPULL:
      return SL_GPIO_MODE_PUSH_PULL;
#endif
#if defined(_HSIO_P_MODEL_MODE0_WIREDOR)
    case _HSIO_P_MODEL_MODE0_WIREDOR:
      return SL_GPIO_MODE_WIRED_OR;
#endif
#if defined(_HSIO_P_MODEL_MODE0_WIREDORPULLDOWN)
    case _HSIO_P_MODEL_MODE0_WIREDORPULLDOWN:
      return SL_GPIO_MODE_WIRED_OR_PULL_DOWN;
#endif
#if defined(_HSIO_P_MODEL_MODE0_WIREDAND)
    case _HSIO_P_MODEL_MODE0_WIREDAND:
      return SL_GPIO_MODE_WIRED_AND;
#endif
#if defined(_HSIO_P_MODEL_MODE0_WIREDANDFILTER)
    case _HSIO_P_MODEL_MODE0_WIREDANDFILTER:
      return SL_GPIO_MODE_WIRED_AND_FILTER;
#endif
#if defined(_HSIO_P_MODEL_MODE0_WIREDANDPULLUP)
    case _HSIO_P_MODEL_MODE0_WIREDANDPULLUP:
      return SL_GPIO_MODE_WIRED_AND_PULLUP;
#endif
#if defined(_HSIO_P_MODEL_MODE0_WIREDANDPULLUPFILTER)
    case _HSIO_P_MODEL_MODE0_WIREDANDPULLUPFILTER:
      return SL_GPIO_MODE_WIRED_AND_PULLUP_FILTER;
#endif
    default:
      EFM_ASSERT(false);
      return mode;
  }
}
#endif /* defined(HSIO_PRESENT) */

#endif /* defined(GPIO_PRESENT)*/
