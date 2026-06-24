/***************************************************************************//**
 * @file
 * @brief General Purpose IO (GPIO) peripheral API
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef SL_HAL_GPIO_H
#define SL_HAL_GPIO_H

#include "em_device.h"

#if defined(GPIO_PRESENT)

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stddef.h>
#include "sl_status.h"
#include "sl_assert.h"
#include "sl_device_gpio.h"
#include "sl_code_classification.h"

/***************************************************************************//**
 * @addtogroup gpio GPIO - General Purpose Input Output
 * @brief General Purpose Input Output peripheral
 * @li @ref gpio_intro
 *
 *@n @section gpio_intro Introduction
 *  This module contains functions to control the GPIO peripheral of Silicon Labs 32-bit MCUs and SoCs.
 *  The GPIO peripheral is used for interrupt configuration, pin configuration and direct pin manipulation
 *  as well as routing for peripheral pin connections.
 *
 * @{
 ******************************************************************************/

/*******************************************************************************
 ********************************   DEFINES   **********************************
 ******************************************************************************/

/** @cond DO_NOT_INCLUDE_WITH_DOXYGEN */

#if defined(__CM33_REV) || defined(__CM55_REV)
#define SL_HAL_GPIO_IRQN_SUPPORTED
#endif

/// Capability: device has GPIO with HSIO (high-speed I/O) ports.
/// Only defined when both GPIO and HSIO are present.
#if defined(HSIO_PRESENT)
#define SL_GPIO_HSIO_PRESENT
#endif

/** @endcond */

/// Define for port specific pin mask
#if defined(GPIO_PA_MASK)
#define SL_HAL_GPIO_PORT_A_PIN_MASK (GPIO_PA_MASK)
#else
#define SL_HAL_GPIO_PORT_A_PIN_MASK 0
#endif
#if defined(GPIO_PB_MASK)
#define SL_HAL_GPIO_PORT_B_PIN_MASK (GPIO_PB_MASK)
#else
#define SL_HAL_GPIO_PORT_B_PIN_MASK 0
#endif
#if defined(GPIO_PC_MASK)
#define SL_HAL_GPIO_PORT_C_PIN_MASK (GPIO_PC_MASK)
#else
#define SL_HAL_GPIO_PORT_C_PIN_MASK 0
#endif
#if defined(GPIO_PD_MASK)
#define SL_HAL_GPIO_PORT_D_PIN_MASK (GPIO_PD_MASK)
#else
#define SL_HAL_GPIO_PORT_D_PIN_MASK 0
#endif
#if defined(GPIO_PE_MASK)
#define SL_HAL_GPIO_PORT_E_PIN_MASK (GPIO_PE_MASK)
#else
#define SL_HAL_GPIO_PORT_E_PIN_MASK 0
#endif
#if defined(GPIO_PF_MASK)
#define SL_HAL_GPIO_PORT_F_PIN_MASK (GPIO_PF_MASK)
#else
#define SL_HAL_GPIO_PORT_F_PIN_MASK 0
#endif
#if defined(GPIO_PG_MASK)
#define SL_HAL_GPIO_PORT_G_PIN_MASK (GPIO_PG_MASK)
#else
#define SL_HAL_GPIO_PORT_G_PIN_MASK 0
#endif
#if defined(GPIO_PH_MASK)
#define SL_HAL_GPIO_PORT_H_PIN_MASK (GPIO_PH_MASK)
#else
#define SL_HAL_GPIO_PORT_H_PIN_MASK 0
#endif
#if defined(GPIO_PI_MASK)
#define SL_HAL_GPIO_PORT_I_PIN_MASK (GPIO_PI_MASK)
#else
#define SL_HAL_GPIO_PORT_I_PIN_MASK 0
#endif
#if defined(GPIO_PJ_MASK)
#define SL_HAL_GPIO_PORT_J_PIN_MASK (GPIO_PJ_MASK)
#else
#define SL_HAL_GPIO_PORT_J_PIN_MASK 0
#endif
#if defined(GPIO_PK_MASK)
#define SL_HAL_GPIO_PORT_K_PIN_MASK (GPIO_PK_MASK)
#else
#define SL_HAL_GPIO_PORT_K_PIN_MASK 0
#endif

/// Define for port specific pin count
#if defined(GPIO_PA_COUNT)
#define SL_HAL_GPIO_PORT_A_PIN_COUNT (GPIO_PA_COUNT)
#else
#define SL_HAL_GPIO_PORT_A_PIN_COUNT 0
#endif
#if defined(GPIO_PB_COUNT)
#define SL_HAL_GPIO_PORT_B_PIN_COUNT (GPIO_PB_COUNT)
#else
#define SL_HAL_GPIO_PORT_B_PIN_COUNT 0
#endif
#if defined(GPIO_PC_COUNT)
#define SL_HAL_GPIO_PORT_C_PIN_COUNT (GPIO_PC_COUNT)
#else
#define SL_HAL_GPIO_PORT_C_PIN_COUNT 0
#endif
#if defined(GPIO_PD_COUNT)
#define SL_HAL_GPIO_PORT_D_PIN_COUNT (GPIO_PD_COUNT)
#else
#define SL_HAL_GPIO_PORT_D_PIN_COUNT 0
#endif
#if defined(GPIO_PE_COUNT)
#define SL_HAL_GPIO_PORT_E_PIN_COUNT (GPIO_PE_COUNT)
#else
#define SL_HAL_GPIO_PORT_E_PIN_COUNT 0
#endif
#if defined(GPIO_PF_COUNT)
#define SL_HAL_GPIO_PORT_F_PIN_COUNT (GPIO_PF_COUNT)
#else
#define SL_HAL_GPIO_PORT_F_PIN_COUNT 0
#endif
#if defined(GPIO_PG_COUNT)
#define SL_HAL_GPIO_PORT_G_PIN_COUNT (GPIO_PG_COUNT)
#else
#define SL_HAL_GPIO_PORT_G_PIN_COUNT 0
#endif
#if defined(GPIO_PH_COUNT)
#define SL_HAL_GPIO_PORT_H_PIN_COUNT (GPIO_PH_COUNT)
#else
#define SL_HAL_GPIO_PORT_H_PIN_COUNT 0
#endif
#if defined(GPIO_PI_COUNT)
#define SL_HAL_GPIO_PORT_I_PIN_COUNT (GPIO_PI_COUNT)
#else
#define SL_HAL_GPIO_PORT_I_PIN_COUNT 0
#endif
#if defined(GPIO_PJ_COUNT)
#define SL_HAL_GPIO_PORT_J_PIN_COUNT (GPIO_PJ_COUNT)
#else
#define SL_HAL_GPIO_PORT_J_PIN_COUNT 0
#endif
#if defined(GPIO_PK_COUNT)
#define SL_HAL_GPIO_PORT_K_PIN_COUNT (GPIO_PK_COUNT)
#else
#define SL_HAL_GPIO_PORT_K_PIN_COUNT 0
#endif

/// @cond DO_NOT_INCLUDE_WITH_DOXYGEN

/// Highest GPIO port number.

#if (SL_HAL_GPIO_PORT_K_PIN_COUNT > 0)
#define SL_HAL_GPIO_PORT_MAX  10
#elif (SL_HAL_GPIO_PORT_J_PIN_COUNT > 0)
#define SL_HAL_GPIO_PORT_MAX  9
#elif (SL_HAL_GPIO_PORT_I_PIN_COUNT > 0)
#define SL_HAL_GPIO_PORT_MAX  8
#elif (SL_HAL_GPIO_PORT_H_PIN_COUNT > 0)
#define SL_HAL_GPIO_PORT_MAX  7
#elif (SL_HAL_GPIO_PORT_G_PIN_COUNT > 0)
#define SL_HAL_GPIO_PORT_MAX  6
#elif (SL_HAL_GPIO_PORT_F_PIN_COUNT > 0)
#define SL_HAL_GPIO_PORT_MAX  5
#elif (SL_HAL_GPIO_PORT_E_PIN_COUNT > 0)
#define SL_HAL_GPIO_PORT_MAX  4
#elif (SL_HAL_GPIO_PORT_D_PIN_COUNT > 0)
#define SL_HAL_GPIO_PORT_MAX  3
#elif (SL_HAL_GPIO_PORT_C_PIN_COUNT > 0)
#define SL_HAL_GPIO_PORT_MAX  2
#elif (SL_HAL_GPIO_PORT_B_PIN_COUNT > 0)
#define SL_HAL_GPIO_PORT_MAX  1
#elif (SL_HAL_GPIO_PORT_A_PIN_COUNT > 0)
#define SL_HAL_GPIO_PORT_MAX  0
#else
#error "Max GPIO port number is undefined for this part."
#endif

/// Highest GPIO pin number.
#define SL_HAL_GPIO_PIN_MAX 15

/// @endcond

#define SL_HAL_GPIO_PORT_SIZE(port) (                     \
    (port) == SL_GPIO_PORT_A  ? SL_HAL_GPIO_PORT_A_PIN_COUNT \
    : (port) == SL_GPIO_PORT_B  ? SL_HAL_GPIO_PORT_B_PIN_COUNT \
    : (port) == SL_GPIO_PORT_C  ? SL_HAL_GPIO_PORT_C_PIN_COUNT \
    : (port) == SL_GPIO_PORT_D  ? SL_HAL_GPIO_PORT_D_PIN_COUNT \
    : (port) == SL_GPIO_PORT_E  ? SL_HAL_GPIO_PORT_E_PIN_COUNT \
    : (port) == SL_GPIO_PORT_F  ? SL_HAL_GPIO_PORT_F_PIN_COUNT \
    : (port) == SL_GPIO_PORT_G  ? SL_HAL_GPIO_PORT_G_PIN_COUNT \
    : (port) == SL_GPIO_PORT_H  ? SL_HAL_GPIO_PORT_H_PIN_COUNT \
    : (port) == SL_GPIO_PORT_I  ? SL_HAL_GPIO_PORT_I_PIN_COUNT \
    : (port) == SL_GPIO_PORT_J  ? SL_HAL_GPIO_PORT_J_PIN_COUNT \
    : (port) == SL_GPIO_PORT_K  ? SL_HAL_GPIO_PORT_K_PIN_COUNT \
    : 0)

#define SL_HAL_GPIO_PORT_MASK(port) (                        \
    ((int)port) == SL_GPIO_PORT_A  ? SL_HAL_GPIO_PORT_A_PIN_MASK \
    : ((int)port) == SL_GPIO_PORT_B  ? SL_HAL_GPIO_PORT_B_PIN_MASK \
    : ((int)port) == SL_GPIO_PORT_C  ? SL_HAL_GPIO_PORT_C_PIN_MASK \
    : ((int)port) == SL_GPIO_PORT_D  ? SL_HAL_GPIO_PORT_D_PIN_MASK \
    : ((int)port) == SL_GPIO_PORT_E  ? SL_HAL_GPIO_PORT_E_PIN_MASK \
    : ((int)port) == SL_GPIO_PORT_F  ? SL_HAL_GPIO_PORT_F_PIN_MASK \
    : ((int)port) == SL_GPIO_PORT_G  ? SL_HAL_GPIO_PORT_G_PIN_MASK \
    : ((int)port) == SL_GPIO_PORT_H  ? SL_HAL_GPIO_PORT_H_PIN_MASK \
    : ((int)port) == SL_GPIO_PORT_I  ? SL_HAL_GPIO_PORT_I_PIN_MASK \
    : ((int)port) == SL_GPIO_PORT_J  ? SL_HAL_GPIO_PORT_J_PIN_MASK \
    : ((int)port) == SL_GPIO_PORT_K  ? SL_HAL_GPIO_PORT_K_PIN_MASK \
    : 0UL)

/// Validation of port.
#define SL_HAL_GPIO_PORT_IS_VALID(port)          (SL_HAL_GPIO_PORT_MASK(port) != 0x0UL)

/// Validation of port and pin.
#define SL_HAL_GPIO_PORT_PIN_IS_VALID(port, pin) ((((SL_HAL_GPIO_PORT_MASK(port)) >> (pin)) & 0x1UL) == 0x1UL)

/// Number of external/EM4 interrupt lines for array sizing (0-15 = 16 elements)
#define SL_HAL_GPIO_NO_OF_EXT_INTERRUPTS 16

/// Maximum valid interrupt index for validation (highest valid index is 15)
#define SL_HAL_GPIO_INTERRUPT_MAX 15

/// Shift value for EM4WUEN
#define SL_HAL_GPIO_EM4WUEN_SHIFT _GPIO_EM4WUEN_EM4WUEN_SHIFT

/// Masks for even and odd interrupt bits.
#define SL_HAL_GPIO_INT_IF_EVEN_MASK ((_GPIO_IF_MASK) & 0x55555555UL)
#define SL_HAL_GPIO_INT_IF_ODD_MASK  ((_GPIO_IF_MASK) & 0xAAAAAAAAUL)

/// Validation of mode.
#define SL_HAL_GPIO_MODE_IS_VALID(mode)  ((mode & _GPIO_P_MODEL_MODE0_MASK) == mode)

/// Validation of interrupt number and pin.
#define SL_HAL_GPIO_INTNO_PIN_VALID(int_no, pin)    (((int_no) & ~_GPIO_EXTIPINSELL_EXTIPINSEL0_MASK) == ((pin) & ~_GPIO_EXTIPINSELL_EXTIPINSEL0_MASK))

#if defined(HSIO_PRESENT)
/***************************************************************************//**
 * HSIO handling and port mapping
 *
 * Some chipsets implement a High-Speed I/O (HSIO) GPIO block that is accessed
 * through a dedicated register array (GPIO->H[0..N-1]) instead of the regular
 * GPIO port array (GPIO->P[port]). The public API still takes a GPIO port enum,
 * so we must translate the enum value into an HSIO array index when the port
 * belongs to the HSIO block.
 *
 * Port membership is determined by the HSIO_PORT_INDEX bitmap supplied by the
 * device header; it flags which port enums are HSIO-capable. The translation
 * is implemented as a fixed offset: index = port - SL_HAL_GPIO_HSIO_PORT_BASE.
 * This is valid because HSIO ports are contiguous in the port enum on supported
 * devices, and the HSIO register array is zero-based.
 *
 * If a chipset maps HSIO to a different starting port, define
 * SL_HAL_GPIO_HSIO_PORT_BASE in the device header or build configuration to
 * point at the first HSIO port. If a future device uses non-contiguous HSIO
 * ports, this mapping must be replaced with a chipset-specific translation.
 ******************************************************************************/
#define SL_HAL_GPIO_HSIO_PORT_BASE HSIO_PORT_BASE

/** @cond DO_NOT_INCLUDE_WITH_DOXYGEN */
#define SL_HAL_HSIO_PORT_INDEX(port)  ((uint8_t)((port) - SL_HAL_GPIO_HSIO_PORT_BASE))
/** @endcond */

#endif /* HSIO_PRESENT */

/*******************************************************************************
 ********************************   ENUMS   ************************************
 ******************************************************************************/

/*******************************************************************************
 *****************************   PROTOTYPES   **********************************
 ******************************************************************************/

/***************************************************************************//**
 * Set the mode for a GPIO pin.
 *
 * @param[in] gpio Pointer to GPIO structure with port and pin
 * @param[in] mode The desired pin mode.
 * @param[in] output_value A value to set for the pin in the DOUT register. The DOUT setting is important for
 *                         some input mode configurations to determine the pull-up/down direction.
 ******************************************************************************/
void sl_hal_gpio_set_pin_mode(const sl_gpio_t *gpio,
                              sl_gpio_mode_t mode,
                              bool output_value);

/***************************************************************************//**
 * Get the mode for a GPIO pin.
 *
 * @param[in] gpio Pointer to GPIO structure with port and pin
 *
 * @return Return the pin mode.
 ******************************************************************************/
sl_gpio_mode_t sl_hal_gpio_get_pin_mode(const sl_gpio_t *gpio);

/***************************************************************************//**
 * Configure the GPIO external pin interrupt by connecting external interrupt id with gpio pin.
 *
 * @note This function configure the pin interrupt with pin ,port and external interrupt id as input.
 *       If external interrupt id is provided as input it will be considered as the input or else
 *       available interrupt number will be generated by looping through the interrupt group and will be used.
 *       User can provide SL_HAL_GPIO_INTERRUPT_UNAVAILABLE if user don't want to provide interrupt id.
 * @note the pin number can be selected freely within a group.
 *       Interrupt numbers are divided into 4 groups (int_no / 4) and valid pin
 *       number within the interrupt groups are:
 *       0: pins 0-3   (interrupt number 0-3)
 *       1: pins 4-7   (interrupt number 4-7)
 *       2: pins 8-11  (interrupt number 8-11)
 *       3: pins 12-15 (interrupt number 12-15)
 * @note It is recommended to disable interrupts before configuring the GPIO pin interrupt.
 *       See sl_hal_gpio_disable_interrupts() for more information.
 *       The GPIO interrupt handler must be in place before enabling the interrupt.
 *       Notice that any pending interrupt for the selected interrupt is cleared by this function.
 *       Notice that only interrupt will be configured by this function. It is not enabled.
 *       It is recommended to enable interrupts after configuring the GPIO pin interrupt if needed.
 *       See sl_hal_gpio_enable_interrupts() for more information.
 *
 * @param[in] gpio Pointer to GPIO structure with port and pin
 * @param[in] int_no The interrupt number to trigger.
 * @param[in] flags Interrupt configuration flags. sl_hal_gpio_interrupt_flag_t for more information.
 *
 * @return Return the available interrupt number
 ******************************************************************************/
int32_t sl_hal_gpio_configure_external_interrupt(const sl_gpio_t *gpio,
                                                 int32_t int_no,
                                                 sl_gpio_interrupt_flag_t flags);

/**************************************************************************//**
 * Enable GPIO pin wake-up from EM4. When the function exits,
 * EM4 mode can be safely entered.
 *
 * @note It is assumed that the GPIO pin modes are set correctly.
 *       Valid modes are SL_GPIO_MODE_INPUT and SL_GPIO_MODE_INPUT_PULL.
 *
 * @param[in] pinmask A bitmask containing the bitwise logic OR of which GPIO pin(s) to enable.
 * @param[in] polaritymask A bitmask containing the bitwise logic OR of GPIO pin(s) wake-up polarity.
 *****************************************************************************/
void sl_hal_gpio_enable_pin_em4_wakeup(uint32_t pinmask,
                                       uint32_t polaritymask);

/***************************************************************************//**
 * Configure EM4WU pins as external level-sensitive interrupts.
 *
 * @note It is recommended to disable interrupts before configuring the GPIO pin interrupt.
 *       See sl_hal_gpio_disable_interrupts() for more information.
 *       The provided port, pin and int_no inputs should be valid EM4 related parameters
 *       because there are dedicated port, pin and EM4 Wakeup interrupt combination for
 *       configuring the port, pin for EM4 functionality.
 *       User can provide SL_HAL_GPIO_INTERRUPT_UNAVAILABLE if user don't want to provide interrupt id.
 *       The GPIO interrupt handler must be in place before enabling the interrupt.
 *       Notice that any pending interrupt for the selected interrupt is cleared by this function.
 *       Notice that any only EM4WU interrupt is configured by this function. It is not enabled.
 *       It is recommended to enable interrupts after configuring the GPIO pin interrupt if needed.
 *       See sl_hal_gpio_enable_interrupts() for more information.
 *
 * @param[in] gpio Pointer to GPIO structure with port and pin
 * @param[in] int_no The EM4WU interrupt number to trigger.
 * @param[in] polarity true = Active high level-sensitive interrupt.
 *                     false = Active low level-sensitive interrupt.
 *
 * @return Return the available EM4WU interrupt number
 ******************************************************************************/
int32_t sl_hal_gpio_configure_wakeup_em4_external_interrupt(const sl_gpio_t *gpio,
                                                            int32_t int_no,
                                                            bool polarity);

/***************************************************************************//**
 * Lock the GPIO configuration.
 *
 * @note Configuration lock affects the GPIO_Px_MODEL, GPIO_Px_MODEH, GPIO_Px_CTRL,
 *       GPIO_Px_PINLOCKN, GPIO_EXTIPSELL, GPIO_EXTIPSELH, GPIO_EXTIPINSELL,
 *       GPIO_EXTIPINSELH, GPIO_INSENSE, GPIO_ROUTE, GPIO_ROUTEPEN, and
 *       GPIO_ROUTELOC0 registers when they are present on a specific device.
 * @note Unwanted or accidental changes to GPIO configuration can be avoided by
 *       using the configuration lock register. Any value other than 0xA534 written to
 *       GPIO_LOCK enables the configuration lock. Pins are unlocked by a reset or
 *       by writing 0xA534 to the GPIO_LOCK register.
 ******************************************************************************/
__INLINE void sl_hal_gpio_lock(void)
{
  GPIO->LOCK = ~GPIO_LOCK_LOCKKEY_UNLOCK;
}

/***************************************************************************//**
 * Unlock the GPIO configuration.
 *
 * @note Configuration lock affects the GPIO_Px_MODEL, GPIO_Px_MODEH, GPIO_Px_CTRL,
 *       GPIO_Px_PINLOCKN, GPIO_EXTIPSELL, GPIO_EXTIPSELH, GPIO_EXTIPINSELL,
 *       GPIO_EXTIPINSELH, GPIO_INSENSE, GPIO_ROUTE, GPIO_ROUTEPEN, and
 *       GPIO_ROUTELOC0 registers when they are present on a specific device.
 * @note Unwanted or accidental changes to GPIO configuration can be avoided by
 *       using the configuration lock register. Any value other than 0xA534 written to
 *       GPIO_LOCK enables the configuration lock. Pins are unlocked by a reset or
 *       by writing 0xA534 to the GPIO_LOCK register.
 ******************************************************************************/
__INLINE void sl_hal_gpio_unlock(void)
{
  GPIO->LOCK = GPIO_LOCK_LOCKKEY_UNLOCK;
}

/***************************************************************************//**
 * Gets the GPIO configuration state.
 *
 * @return Return the GPIO lock state.
 ******************************************************************************/
__INLINE uint32_t sl_hal_gpio_get_lock_status(void)
{
  return GPIO->GPIOLOCKSTATUS;
}

#if defined(HSIO_PRESENT)
/***************************************************************************//**
 * Check if the port is an HSIO port.
 *
 * @param[in] port The GPIO port to check.
 *
 * @return true if the port is an HSIO port, false otherwise.
 ******************************************************************************/
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_HAL_GPIO, SL_CODE_CLASS_TIME_CRITICAL)
__INLINE bool sl_hal_gpio_is_hsio_port(sl_gpio_port_t port)
{
  return ((1UL << (uint32_t)port) & HSIO_PORT_INDEX) != 0u;
}

/***************************************************************************//**
 * Check if the port is a GPIO port (P[]).
 *
 * @note When HSIO is present, the device has both GPIO ports (P[]) and HSIO ports (H[]).
 *       This returns true for GPIO ports only. Use sl_hal_gpio_is_hsio_port() for HSIO.
 *       When HSIO is not present, all valid ports are GPIO ports.
 *
 * @param[in] port The GPIO port to check.
 *
 * @return true if the port is a GPIO (P[]) port, false otherwise.
 ******************************************************************************/
__INLINE bool sl_hal_gpio_is_gpio_port(sl_gpio_port_t port)
{
  return SL_HAL_GPIO_PORT_IS_VALID(port) && !sl_hal_gpio_is_hsio_port(port);
}
#else
__INLINE bool sl_hal_gpio_is_gpio_port(sl_gpio_port_t port)
{
  return SL_HAL_GPIO_PORT_IS_VALID(port);
}
#endif

#if defined(SL_GPIO_HSIO_PRESENT)
/***************************************************************************//**
 * Set a single pin in GPIO data out register to 1.
 *
 * @param[in] gpio Pointer to GPIO structure with port and pin
 ******************************************************************************/
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_HAL_GPIO, SL_CODE_CLASS_TIME_CRITICAL)
__INLINE void sl_hal_gpio_set_pin(const sl_gpio_t *gpio)
{
  EFM_ASSERT(gpio != NULL);
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  if (sl_hal_gpio_is_hsio_port(gpio->port)) {
    uint8_t hsio_index = SL_HAL_HSIO_PORT_INDEX(gpio->port);
    GPIO->H_SET[hsio_index].DOUT = 1UL << gpio->pin;
  } else {
    GPIO->P_SET[gpio->port].DOUT = 1UL << gpio->pin;
  }
}

/***************************************************************************//**
 * Set bits GPIO data out register to 1.
 *
 * @param[in] port The GPIO port to access.
 * @param[in] pins Bit mask for bits to set to 1 in DOUT register.
 ******************************************************************************/
__INLINE void sl_hal_gpio_set_port(sl_gpio_port_t port,
                                  uint32_t pins)
{
  EFM_ASSERT(SL_HAL_GPIO_PORT_IS_VALID(port));
  if (sl_hal_gpio_is_hsio_port(port)) {
    uint8_t hsio_index = SL_HAL_HSIO_PORT_INDEX(port);
    GPIO->H_SET[hsio_index].DOUT = pins;
  } else {
    GPIO->P_SET[port].DOUT = pins;
  }
}

/***************************************************************************//**
 * Set GPIO port data out register.
 *
 * @param[in] port The GPIO port to access.
 * @param[in] val Value to write to port data out register.
 * @param[in] mask Mask indicating which bits to modify.
 ******************************************************************************/
__INLINE void sl_hal_gpio_set_port_value(sl_gpio_port_t port,
                                         uint32_t val,
                                         uint32_t mask)
{
  EFM_ASSERT(SL_HAL_GPIO_PORT_IS_VALID(port));
  if (sl_hal_gpio_is_hsio_port(port)) {
    uint8_t hsio_index = SL_HAL_HSIO_PORT_INDEX(port);
    GPIO->H[hsio_index].DOUT = (GPIO->H[hsio_index].DOUT & ~mask) | (val & mask);
  } else {
    GPIO->P[port].DOUT = (GPIO->P[port].DOUT & ~mask) | (val & mask);
  }
}

/***************************************************************************//**
 * Set a single pin in GPIO data out port register to 0.
 *
 * @param[in] gpio Pointer to GPIO structure with port and pin
 ******************************************************************************/
__INLINE void sl_hal_gpio_clear_pin(const sl_gpio_t *gpio)
{
  EFM_ASSERT(gpio != NULL);
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  if (sl_hal_gpio_is_hsio_port(gpio->port)) {
    uint8_t hsio_index = SL_HAL_HSIO_PORT_INDEX(gpio->port);
    GPIO->H_CLR[hsio_index].DOUT = 1UL << gpio->pin;
  } else {
    GPIO->P_CLR[gpio->port].DOUT = 1UL << gpio->pin;
  }
}

/***************************************************************************//**
 * Set bits in DOUT register for a port to 0.
 *
 * @param[in] port The GPIO port to access.
 * @param[in] pins Bit mask for bits to clear in DOUT register.
 ******************************************************************************/
__INLINE void sl_hal_gpio_clear_port(sl_gpio_port_t port,
                                    uint32_t pins)
{
  EFM_ASSERT(SL_HAL_GPIO_PORT_IS_VALID(port));
  if (sl_hal_gpio_is_hsio_port(port)) {
    uint8_t hsio_index = SL_HAL_HSIO_PORT_INDEX(port);
    GPIO->H_CLR[hsio_index].DOUT = pins;
  } else {
    GPIO->P_CLR[port].DOUT = pins;
  }
}

/***************************************************************************//**
 * Read the pad value for a single pin in a GPIO port.
 *
 * @param[in] gpio Pointer to GPIO structure with port and pin.
 *
 * @return The pin value, 0 or 1.
 ******************************************************************************/
__INLINE bool sl_hal_gpio_get_pin_input(const sl_gpio_t *gpio)
{
  EFM_ASSERT(gpio != NULL);
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  if (sl_hal_gpio_is_hsio_port(gpio->port)) {
    uint8_t hsio_index = SL_HAL_HSIO_PORT_INDEX(gpio->port);
    return ((GPIO->H[hsio_index].DIN) >> gpio->pin) & 1UL;
  }

  return ((GPIO->P[gpio->port].DIN) >> gpio->pin) & 1UL;
}

/***************************************************************************//**
 * Get current setting for a pin in a GPIO port data out register.
 *
 * @param[in] gpio Pointer to GPIO structure with port and pin.
 *
 * @return The DOUT setting for the requested pin, 0 or 1.
 ******************************************************************************/
__INLINE bool sl_hal_gpio_get_pin_output(const sl_gpio_t *gpio)
{
  EFM_ASSERT(gpio != NULL);
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  if (sl_hal_gpio_is_hsio_port(gpio->port)) {
    uint8_t hsio_index = SL_HAL_HSIO_PORT_INDEX(gpio->port);
    return ((GPIO->H[hsio_index].DOUT) >> gpio->pin) & 1UL;
  }

  return ((GPIO->P[gpio->port].DOUT) >> gpio->pin) & 1UL;
}

/***************************************************************************//**
 * Read the pad values for GPIO port.
 *
 * @param[in] port The GPIO port to access.
 *
 * @return The pad values for the GPIO port.
 ******************************************************************************/
__INLINE uint32_t sl_hal_gpio_get_port_input(sl_gpio_port_t port)
{
  EFM_ASSERT(SL_HAL_GPIO_PORT_IS_VALID(port));
  if (sl_hal_gpio_is_hsio_port(port)) {
    uint8_t hsio_index = SL_HAL_HSIO_PORT_INDEX(port);
    return GPIO->H[hsio_index].DIN;
  }

  return GPIO->P[port].DIN;
}

/***************************************************************************//**
 * Get current setting for a GPIO port data out register.
 *
 * @param[in] port The GPIO port to access.
 *
 * @return The data out setting for the requested port.
 ******************************************************************************/
__INLINE uint32_t sl_hal_gpio_get_port_output(sl_gpio_port_t port)
{
  EFM_ASSERT(SL_HAL_GPIO_PORT_IS_VALID(port));
  if (sl_hal_gpio_is_hsio_port(port)) {
    uint8_t hsio_index = SL_HAL_HSIO_PORT_INDEX(port);
    return GPIO->H[hsio_index].DOUT;
  }

  return GPIO->P[port].DOUT;
}

/***************************************************************************//**
 * Toggle a single pin in GPIO port data out register.
 *
 * @param[in] gpio Pointer to GPIO structure with port and pin.
 ******************************************************************************/
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_HAL_GPIO, SL_CODE_CLASS_TIME_CRITICAL)
__INLINE void sl_hal_gpio_toggle_pin(const sl_gpio_t *gpio)
{
  EFM_ASSERT(gpio != NULL);
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  if (sl_hal_gpio_is_hsio_port(gpio->port)) {
    uint8_t hsio_index = SL_HAL_HSIO_PORT_INDEX(gpio->port);
    GPIO->H_TGL[hsio_index].DOUT = 1UL << gpio->pin;
  } else {
    GPIO->P_TGL[gpio->port].DOUT = 1UL << gpio->pin;
  }
}

/***************************************************************************//**
 * Toggle pins in GPIO port data out register.
 *
 * @param[in] port The GPIO port to access.
 * @param[in] pins Bit mask with pins to toggle.
 ******************************************************************************/
__INLINE void sl_hal_gpio_toggle_port(sl_gpio_port_t port,
                                      uint32_t pins)
{
  EFM_ASSERT(SL_HAL_GPIO_PORT_IS_VALID(port));
  if (sl_hal_gpio_is_hsio_port(port)) {
    uint8_t hsio_index = SL_HAL_HSIO_PORT_INDEX(port);
    GPIO->H_TGL[hsio_index].DOUT = pins;
  } else {
    GPIO->P_TGL[port].DOUT = pins;
  }
}

#else  /* GPIO-only implementations */

/***************************************************************************//**
 * Set a single pin in GPIO data out register to 1.
 *
 * @param[in] gpio Pointer to GPIO structure with port and pin
 ******************************************************************************/
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_HAL_GPIO, SL_CODE_CLASS_TIME_CRITICAL)
__INLINE void sl_hal_gpio_set_pin(const sl_gpio_t *gpio)
{
  EFM_ASSERT(gpio != NULL);
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  GPIO->P_SET[gpio->port].DOUT = 1UL << gpio->pin;
}

/***************************************************************************//**
 * Set bits GPIO data out register to 1.
 *
 * @param[in] port The GPIO port to access.
 * @param[in] pins Bit mask for bits to set to 1 in DOUT register.
 ******************************************************************************/
__INLINE void sl_hal_gpio_set_port(sl_gpio_port_t port, uint32_t pins)
{
  EFM_ASSERT(SL_HAL_GPIO_PORT_IS_VALID(port));
  GPIO->P_SET[port].DOUT = pins;
}

/***************************************************************************//**
 * Set GPIO port data out register.
 *
 * @param[in] port The GPIO port to access.
 * @param[in] val Value to write to port data out register.
 * @param[in] mask Mask indicating which bits to modify.
 ******************************************************************************/
__INLINE void sl_hal_gpio_set_port_value(sl_gpio_port_t port,
                                         uint32_t val,
                                         uint32_t mask)
{
  EFM_ASSERT(SL_HAL_GPIO_PORT_IS_VALID(port));
  GPIO->P[port].DOUT = (GPIO->P[port].DOUT & ~mask) | (val & mask);
}

/***************************************************************************//**
 * Set a single pin in GPIO data out port register to 0.
 *
 * @param[in] gpio Pointer to GPIO structure with port and pin
 ******************************************************************************/
__INLINE void sl_hal_gpio_clear_pin(const sl_gpio_t *gpio)
{
  EFM_ASSERT(gpio != NULL);
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  GPIO->P_CLR[gpio->port].DOUT = 1UL << gpio->pin;
}

/***************************************************************************//**
 * Set bits in DOUT register for a port to 0.
 *
 * @param[in] port The GPIO port to access.
 * @param[in] pins Bit mask for bits to clear in DOUT register.
 ******************************************************************************/
__INLINE void sl_hal_gpio_clear_port(sl_gpio_port_t port, uint32_t pins)
{
  EFM_ASSERT(SL_HAL_GPIO_PORT_IS_VALID(port));
  GPIO->P_CLR[port].DOUT = pins;
}

/***************************************************************************//**
 * Read the pad value for a single pin in a GPIO port.
 *
 * @param[in] gpio Pointer to GPIO structure with port and pin.
 *
 * @return The pin value, 0 or 1.
 ******************************************************************************/
__INLINE bool sl_hal_gpio_get_pin_input(const sl_gpio_t *gpio)
{
  EFM_ASSERT(gpio != NULL);
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  return ((GPIO->P[gpio->port].DIN) >> gpio->pin) & 1UL;
}

/***************************************************************************//**
 * Get current setting for a pin in a GPIO port data out register.
 *
 * @param[in] gpio Pointer to GPIO structure with port and pin.
 *
 * @return The DOUT setting for the requested pin, 0 or 1.
 ******************************************************************************/
__INLINE bool sl_hal_gpio_get_pin_output(const sl_gpio_t *gpio)
{
  EFM_ASSERT(gpio != NULL);
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  return ((GPIO->P[gpio->port].DOUT) >> gpio->pin) & 1UL;
}

/***************************************************************************//**
 * Read the pad values for GPIO port.
 *
 * @param[in] port The GPIO port to access.
 *
 * @return The pad values for the GPIO port.
 ******************************************************************************/
__INLINE uint32_t sl_hal_gpio_get_port_input(sl_gpio_port_t port)
{
  EFM_ASSERT(SL_HAL_GPIO_PORT_IS_VALID(port));
  return GPIO->P[port].DIN;
}

/***************************************************************************//**
 * Get current setting for a GPIO port data out register.
 *
 * @param[in] port The GPIO port to access.
 *
 * @return The data out setting for the requested port.
 ******************************************************************************/
__INLINE uint32_t sl_hal_gpio_get_port_output(sl_gpio_port_t port)
{
  EFM_ASSERT(SL_HAL_GPIO_PORT_IS_VALID(port));
  return GPIO->P[port].DOUT;
}

/***************************************************************************//**
 * Toggle a single pin in GPIO port data out register.
 *
 * @param[in] gpio Pointer to GPIO structure with port and pin.
 ******************************************************************************/
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_HAL_GPIO, SL_CODE_CLASS_TIME_CRITICAL)
__INLINE void sl_hal_gpio_toggle_pin(const sl_gpio_t *gpio)
{
  EFM_ASSERT(gpio != NULL);
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  GPIO->P_TGL[gpio->port].DOUT = 1UL << gpio->pin;
}

/***************************************************************************//**
 * Toggle pins in GPIO port data out register.
 *
 * @param[in] port The GPIO port to access.
 * @param[in] pins Bit mask with pins to toggle.
 ******************************************************************************/
__INLINE void sl_hal_gpio_toggle_port(sl_gpio_port_t port, uint32_t pins)
{
  EFM_ASSERT(SL_HAL_GPIO_PORT_IS_VALID(port));
  GPIO->P_TGL[port].DOUT = pins;
}

#endif /* SL_GPIO_HSIO_PRESENT */

/***************************************************************************//**
 * Set slewrate for pins on a GPIO port which are configured into normal modes.
 *
 * @note
 *   - This API supports both port-specific slew rate (one setting for the whole
 *     port) and per-pin slew rate (each pin in a port configured separately);
 *     which applies depends on the part.
 *
 * @param[in] gpio Pointer to GPIO structure with port and pin
 * @param[in] slewrate The slewrate to configure for pins on this GPIO port.
 *
 * @return SL_STATUS_OK if there's no error.
 *         SL_STATUS_INVALID_PARAMETER if port is invalid.
 *         SL_STATUS_NOT_SUPPORTED if the feature is not supported on this device
 *         or for the selected port.
 ******************************************************************************/
__INLINE sl_status_t sl_hal_gpio_set_slew_rate(const sl_gpio_t *gpio,
                                               uint8_t slewrate)
{
  EFM_ASSERT(gpio != NULL);
#if defined(_GPIO_P_CTRL_SLEWRATE_MASK)
  EFM_ASSERT(SL_HAL_GPIO_PORT_IS_VALID(gpio->port));
  EFM_ASSERT(slewrate <= (_GPIO_P_CTRL_SLEWRATE_MASK >> _GPIO_P_CTRL_SLEWRATE_SHIFT));

  GPIO->P[gpio->port].CTRL = (GPIO->P[gpio->port].CTRL
                              & ~_GPIO_P_CTRL_SLEWRATE_MASK)
                             | (slewrate << _GPIO_P_CTRL_SLEWRATE_SHIFT);
#elif defined(_GPIO_P_SLEWRATEL_MASK)
  /* Per-pin slew rate. */
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  EFM_ASSERT(slewrate <= (_GPIO_P_SLEWRATEL_SLEWRATE0_MASK >> _GPIO_P_SLEWRATEL_SLEWRATE0_SHIFT));
  if (!sl_hal_gpio_is_gpio_port(gpio->port)) {
    EFM_ASSERT(false);
    return SL_STATUS_INVALID_PARAMETER;
  }

  uint32_t pin_shift = (uint32_t)(gpio->pin % 8) << 2;
  uint32_t field_mask = _GPIO_P_SLEWRATEL_SLEWRATE0_MASK << pin_shift;
  uint32_t field_val = (slewrate & _GPIO_P_SLEWRATEL_SLEWRATE0_MASK) << pin_shift;

  if (gpio->pin < 8) {
    uint32_t reg_val = GPIO->P[gpio->port].SLEWRATEL;
    GPIO->P[gpio->port].SLEWRATEL = (reg_val & ~field_mask) | field_val;
  } else {
    uint32_t reg_val = GPIO->P[gpio->port].SLEWRATEH;
    GPIO->P[gpio->port].SLEWRATEH = (reg_val & ~field_mask) | field_val;
  }
#endif
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Get slewrate for pins on a GPIO port.
 *
 * @note
 *   - This API supports both port-specific slew rate (one setting for the whole
 *     port) and per-pin slew rate (each pin in a port configured separately);
 *     which applies depends on the part.
 *
 * @param[in] gpio Pointer to GPIO structure with port and pin
 *
 * @param[out] slewrate Pointer to store the slewrate of selected GPIO port.
 *
 * @return SL_STATUS_OK if there's no error.
 *         SL_STATUS_INVALID_PARAMETER if port is invalid.
 *         SL_STATUS_NOT_SUPPORTED if the feature is not supported on this device
 *         or for the selected port.
 ******************************************************************************/
__INLINE sl_status_t sl_hal_gpio_get_slew_rate(const sl_gpio_t *gpio,
                                               uint8_t *slewrate)
{
  EFM_ASSERT((gpio != NULL) && (slewrate != NULL));

#if defined(_GPIO_P_CTRL_SLEWRATE_MASK)
  EFM_ASSERT(SL_HAL_GPIO_PORT_IS_VALID(gpio->port));

  *slewrate = (GPIO->P[gpio->port].CTRL & _GPIO_P_CTRL_SLEWRATE_MASK) >> _GPIO_P_CTRL_SLEWRATE_SHIFT;
#elif defined(_GPIO_P_SLEWRATEL_MASK)
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  if (!sl_hal_gpio_is_gpio_port(gpio->port)) {
    EFM_ASSERT(false);
    return SL_STATUS_INVALID_PARAMETER;
  }

  uint32_t pin_shift = (uint32_t)(gpio->pin % 8) << 2;
  uint32_t reg_val = (gpio->pin < 8)
                      ? GPIO->P[gpio->port].SLEWRATEL
                      : GPIO->P[gpio->port].SLEWRATEH;
  *slewrate = (uint8_t)((reg_val >> pin_shift) & _GPIO_P_SLEWRATEL_SLEWRATE0_MASK);
#endif
  return SL_STATUS_OK;
}

#if defined(_GPIO_P_CTRL_SLEWRATEALT_MASK)
/***************************************************************************//**
 * Set slewrate for pins on a GPIO port which are configured into alternate modes.
 *
 * @param[in] port The GPIO port to configure.
 * @param[in] slewrate_alt The slewrate to configure for pins using alternate modes on this GPIO port.
 ******************************************************************************/
__INLINE void sl_hal_gpio_set_slew_rate_alternate(sl_gpio_port_t port,
                                                  uint8_t slewrate_alt)
{
  (void)slewrate_alt;
  EFM_ASSERT(SL_HAL_GPIO_PORT_IS_VALID(port));

  EFM_ASSERT(slewrate_alt <= (_GPIO_P_CTRL_SLEWRATEALT_MASK
                              >> _GPIO_P_CTRL_SLEWRATEALT_SHIFT));

  GPIO->P[port].CTRL = (GPIO->P[port].CTRL
                        & ~_GPIO_P_CTRL_SLEWRATEALT_MASK)
                       | (slewrate_alt << _GPIO_P_CTRL_SLEWRATEALT_SHIFT);
}

/***************************************************************************//**
 * Get slewrate for pins on a GPIO port which are configured into alternate modes.
 *
 * @param[in] port The GPIO port to access to get slew rate.
 *
 * @return Return the alternate slewrate setting for selected GPIO port.
 ******************************************************************************/
__INLINE uint8_t sl_hal_gpio_get_slew_rate_alternate(sl_gpio_port_t port)
{
  EFM_ASSERT(SL_HAL_GPIO_PORT_IS_VALID(port));
  return (uint8_t)((GPIO->P[port].CTRL & _GPIO_P_CTRL_SLEWRATEALT_MASK) >> _GPIO_P_CTRL_SLEWRATEALT_SHIFT);
}
#endif /* _GPIO_P_CTRL_SLEWRATEALT_MASK */

/***************************************************************************//**
 * Enable one or more GPIO interrupts.
 *
 * @param[in] flags GPIO interrupt sources to enable.
 ******************************************************************************/
__INLINE void sl_hal_gpio_enable_interrupts(uint32_t flags)
{
  GPIO->IEN_SET = flags;
}

/***************************************************************************//**
 * Disable one or more GPIO interrupts.
 *
 * @param[in] flags GPIO interrupt sources to disable.
 ******************************************************************************/
__INLINE void sl_hal_gpio_disable_interrupts(uint32_t flags)
{
  GPIO->IEN_CLR = flags;
}

/***************************************************************************//**
 * Clear one or more pending GPIO interrupts.
 *
 * @param[in] flags Bitwise logic OR of GPIO interrupt sources to clear.
 ******************************************************************************/
__INLINE void sl_hal_gpio_clear_interrupts(uint32_t flags)
{
  GPIO->IF_CLR = flags;
}

/**************************************************************************//**
 * Set one or more pending GPIO interrupts from SW.
 *
 * @param[in] flags GPIO interrupt sources to set to pending.
 *****************************************************************************/
__INLINE void sl_hal_gpio_set_interrupts(uint32_t flags)
{
  GPIO->IF_SET = flags;
}

/***************************************************************************//**
 * Get pending GPIO interrupts.
 *
 * @return GPIO interrupt sources pending.
 ******************************************************************************/
__INLINE uint32_t sl_hal_gpio_get_pending_interrupts(void)
{
  return GPIO->IF;
}

/***************************************************************************//**
 * Get enabled GPIO interrupts.
 *
 * @return Enabled GPIO interrupt sources.
 ******************************************************************************/
__INLINE uint32_t sl_hal_gpio_get_enabled_interrupts(void)
{
  return GPIO->IEN;
}

/***************************************************************************//**
 * Get enabled and pending GPIO interrupt flags.
 *
 * @return Enabled and pending interrupt sources.
 *
 * @note Useful for handling more interrupt sources in the same interrupt handler.
 ******************************************************************************/
__INLINE uint32_t sl_hal_gpio_get_enabled_pending_interrupts(void)
{
  uint32_t tmp;

  tmp = GPIO->IEN;

  return GPIO->IF & tmp;
}

/***************************************************************************//**
 * The available external interrupt number getter.
 *
 * @param[in] pin  The GPIO pin to access.
 * @param[in] enabled_interrupts_mask Contains enabled GPIO interrupts mask.
 *
 * @return  The available interrupt number based on interrupt and pin grouping.
 ******************************************************************************/
__INLINE int32_t sl_hal_gpio_get_external_interrupt_number(uint8_t pin,
                                                           uint32_t enabled_interrupts_mask)
{
  uint32_t interrupt_to_check;
  uint32_t int_group_start = (pin & 0xFFC);
  int32_t int_no = -1;
  // loop through the interrupt group, starting
  // from the pin number, and take
  // the first available.
  for (uint8_t i = 0; i < 4; i++) {
    interrupt_to_check = int_group_start + ((pin + i) & 0x3);     // modulo 4
    if (((enabled_interrupts_mask >> interrupt_to_check) & 0x1) == 0) {
      int_no = interrupt_to_check;
      break;
    }
  }
  return int_no;
}

/***************************************************************************//**
 * The available em4 wakeup interrupt number getter.
 *
 * @param[in] gpio Pointer to GPIO structure with port and pin.
 *
 * @return The available em4 wakeup interrupt number based on associated port and pin.
 ******************************************************************************/
__INLINE int32_t sl_hal_gpio_get_em4_interrupt_number(const sl_gpio_t *gpio)
{
  EFM_ASSERT(gpio != NULL);
  int32_t em4_int_no;

  if (false) {
    // Check all the EM4WU Pins and check if given port, pin matches any of them.
    #if defined(GPIO_EM4WU0_PORT)
  } else if (GPIO_EM4WU0_PORT == gpio->port && GPIO_EM4WU0_PIN == gpio->pin) {
    em4_int_no = 0;
    #endif
    #if defined(GPIO_EM4WU1_PORT)
  } else if (GPIO_EM4WU1_PORT == gpio->port && GPIO_EM4WU1_PIN == gpio->pin) {
    em4_int_no = 1;
    #endif
    #if defined(GPIO_EM4WU2_PORT)
  } else if (GPIO_EM4WU2_PORT == gpio->port && GPIO_EM4WU2_PIN == gpio->pin) {
    em4_int_no = 2;
    #endif
    #if defined(GPIO_EM4WU3_PORT)
  } else if (GPIO_EM4WU3_PORT == gpio->port && GPIO_EM4WU3_PIN == gpio->pin) {
    em4_int_no = 3;
    #endif
    #if defined(GPIO_EM4WU4_PORT)
  } else if (GPIO_EM4WU4_PORT == gpio->port && GPIO_EM4WU4_PIN == gpio->pin) {
    em4_int_no = 4;
    #endif
    #if defined(GPIO_EM4WU5_PORT)
  } else if (GPIO_EM4WU5_PORT == gpio->port && GPIO_EM4WU5_PIN == gpio->pin) {
    em4_int_no = 5;
    #endif
    #if defined(GPIO_EM4WU6_PORT)
  } else if (GPIO_EM4WU6_PORT == gpio->port && GPIO_EM4WU6_PIN == gpio->pin) {
    em4_int_no = 6;
    #endif
    #if defined(GPIO_EM4WU7_PORT)
  } else if (GPIO_EM4WU7_PORT == gpio->port && GPIO_EM4WU7_PIN == gpio->pin) {
    em4_int_no = 7;
    #endif
    #if defined(GPIO_EM4WU8_PORT)
  } else if (GPIO_EM4WU8_PORT == gpio->port && GPIO_EM4WU8_PIN == gpio->pin) {
    em4_int_no = 8;
    #endif
    #if defined(GPIO_EM4WU9_PORT)
  } else if (GPIO_EM4WU9_PORT == gpio->port && GPIO_EM4WU9_PIN == gpio->pin) {
    em4_int_no = 9;
    #endif
    #if defined(GPIO_EM4WU10_PORT)
  } else if (GPIO_EM4WU10_PORT == gpio->port && GPIO_EM4WU10_PIN == gpio->pin) {
    em4_int_no = 10;
    #endif
  } else {
    em4_int_no = -1;
  }

  return em4_int_no;
}

/*************************************************************************//**
* Disable GPIO pin wake-up from EM4.
*
* @param[in] pinmask Bit mask containing the bitwise logic OR of which GPIO pin(s) to disable.
*****************************************************************************/
__INLINE void sl_hal_gpio_disable_pin_em4_wakeup(uint32_t pinmask)
{
  EFM_ASSERT((pinmask & ~_GPIO_EM4WUEN_MASK) == 0UL);

  GPIO->EM4WUEN_CLR = pinmask;
}

/**************************************************************************//**
 * Enable GPIO pin retention of output enable, output value, pull enable, and
 * pull direction in EM4.
 *
 * @note The behavior of this function depends on the configured GPIO retention mode.
 *       If the GPIO retention mode is configured to be "SWUNLATCH" then this
 *       function will not change anything. If the retention mode is anything else
 *       then this function will set the GPIO retention mode to "EM4EXIT" when the
 *       enable argument is true, and "Disabled" when false.
 *
 * @param[in] enable true - enable EM4 pin retention.
 *                   false - disable EM4 pin retention.
 *****************************************************************************/
__INLINE void sl_hal_gpio_set_pin_em4_retention(bool enable)
{
  // Leave configuration alone when software unlatch is used.
  uint32_t mode = EMU->EM4CTRL & _EMU_EM4CTRL_EM4IORETMODE_MASK;

  if (mode == EMU_EM4CTRL_EM4IORETMODE_SWUNLATCH) {
    return;
  }

  if (enable) {
    EMU->EM4CTRL = (EMU->EM4CTRL & ~_EMU_EM4CTRL_EM4IORETMODE_MASK)
                   | EMU_EM4CTRL_EM4IORETMODE_EM4EXIT;
  } else {
    EMU->EM4CTRL = (EMU->EM4CTRL & ~_EMU_EM4CTRL_EM4IORETMODE_MASK)
                   | EMU_EM4CTRL_EM4IORETMODE_DISABLE;
  }
}

/**************************************************************************//**
 * Check which GPIO pin(s) that caused a wake-up from EM4.
 *
 * @return Bit mask containing the bitwise logic OR of which GPIO pin(s) caused the wake-up.
 *****************************************************************************/
__INLINE uint32_t sl_hal_gpio_get_pin_em4_wakeup_cause(void)
{
  return GPIO->IF & _GPIO_EM4WUEN_EM4WUEN_MASK;
}

/***************************************************************************//**
 * Enable/Disable serial wire output pin.
 *
 * @note Enabling this pin is not sufficient to fully enable serial wire output,
 *       which is also dependent on issues outside the GPIO module.
 * @note If debug port is locked, SWO pin is not disabled automatically. To avoid
 *       information leakage through SWO, disable SWO pin after locking debug port.
 *
 * @param[in] enable false - disable serial wire viewer pin (default after reset).
 *                   true - enable serial wire viewer pin.
 ******************************************************************************/
__INLINE void sl_hal_gpio_enable_debug_swo(bool enable)
{
  uint32_t bit = enable ? 0x1UL : 0x0UL;

  if (bit != 0U) {
    GPIO->TRACEROUTEPEN_SET = 1UL << _GPIO_TRACEROUTEPEN_SWVPEN_SHIFT;
  } else {
    GPIO->TRACEROUTEPEN_CLR = 1UL << _GPIO_TRACEROUTEPEN_SWVPEN_SHIFT;
  }
}

/***************************************************************************//**
 * Enable/disable serial wire clock pin.
 *
 * @note Disabling SWDClk will disable the debug interface, which may result in
 *       a lockout if done early in startup (before debugger is able to halt core).
 *
 * @param[in] enable false - disable serial wire clock.
 *                   true - enable serial wire clock (default after reset).
 ******************************************************************************/
__INLINE void sl_hal_gpio_enable_debug_swd_clk(bool enable)
{
  uint32_t bit = enable ? 0x1UL : 0x0UL;

  if (bit != 0U) {
    GPIO->DBGROUTEPEN_SET = 1UL << _GPIO_DBGROUTEPEN_SWCLKTCKPEN_SHIFT;
  } else {
    GPIO->DBGROUTEPEN_CLR = 1UL << _GPIO_DBGROUTEPEN_SWCLKTCKPEN_SHIFT;
  }
}

/***************************************************************************//**
 * Enable/disable serial wire data I/O pin.
 *
 * @note Disabling SWDClk will disable the debug interface, which may result in
 *       a lockout if done early in startup (before debugger is able to halt core).
 *
 * @param[in] enable false - disable serial wire data pin.
 *                   true - enable serial wire data pin (default after reset).
 ******************************************************************************/
__INLINE void sl_hal_gpio_enable_debug_swd_io(bool enable)
{
  uint32_t bit = enable ? 0x1UL : 0x0UL;

  if (bit != 0U) {
    GPIO->DBGROUTEPEN_SET = 1UL << _GPIO_DBGROUTEPEN_SWDIOTMSPEN_SHIFT;
  } else {
    GPIO->DBGROUTEPEN_CLR = 1UL << _GPIO_DBGROUTEPEN_SWDIOTMSPEN_SHIFT;
  }
}

#if defined(_HSIO_P_PRDRVSTRENGTH_PRDRVSTRENGTH0_MASK) && defined(HSIO_PRESENT)
/***************************************************************************//**
 * Set predriver strength for an HSIO pin.
 *
 * @note HSIO ports (H[]) have a single PRDRVSTRENGTH register per port.
 *
 * @param[in] gpio Pointer to GPIO structure (must be an HSIO port).
 * @param[in] predrv_strength Predriver strength value (0 to mask max).
 *
 * @return SL_STATUS_OK on success.
 *         SL_STATUS_INVALID_PARAMETER if the port is not an HSIO port.
 ******************************************************************************/
__INLINE sl_status_t sl_hal_gpio_set_pre_driver_strength(sl_gpio_t *gpio,
                                                         uint8_t predrv_strength)
{
  EFM_ASSERT(gpio != NULL);
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  EFM_ASSERT(predrv_strength <= (_HSIO_P_PRDRVSTRENGTH_PRDRVSTRENGTH0_MASK
                                 >> _HSIO_P_PRDRVSTRENGTH_PRDRVSTRENGTH0_SHIFT));
  if (!sl_hal_gpio_is_hsio_port(gpio->port)) {
    EFM_ASSERT(false);
    return SL_STATUS_INVALID_PARAMETER;
  }

  /* Single PRDRVSTRENGTH register per HSIO port; 2 bits per pin. */
  uint32_t pin_shift = (uint32_t)gpio->pin << 1;
  uint32_t field_mask = _HSIO_P_PRDRVSTRENGTH_PRDRVSTRENGTH0_MASK << pin_shift;
  uint32_t field_val = (predrv_strength & _HSIO_P_PRDRVSTRENGTH_PRDRVSTRENGTH0_MASK) << pin_shift;

  uint32_t idx = SL_HAL_HSIO_PORT_INDEX(gpio->port);
  uint32_t reg_val = GPIO->H[idx].PRDRVSTRENGTH;
  GPIO->H[idx].PRDRVSTRENGTH = (reg_val & ~field_mask) | field_val;
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Get predriver strength for an HSIO pin.
 *
 * @param[in] gpio Pointer to GPIO structure (must be an HSIO port).
 * @param[out] predrv_strength Pointer to store the predriver strength value.
 *
 * @return SL_STATUS_OK on success.
 *         SL_STATUS_INVALID_PARAMETER if the port is not an HSIO port.
 ******************************************************************************/
__INLINE sl_status_t sl_hal_gpio_get_pre_driver_strength(sl_gpio_t *gpio,
                                                         uint8_t *predrv_strength)
{
  EFM_ASSERT(gpio != NULL);
  EFM_ASSERT(predrv_strength != NULL);
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  if (!sl_hal_gpio_is_hsio_port(gpio->port)) {
    EFM_ASSERT(false);
    return SL_STATUS_INVALID_PARAMETER;
  }

  uint32_t pin_shift = (uint32_t)gpio->pin << 1;
  uint32_t idx = SL_HAL_HSIO_PORT_INDEX(gpio->port);
  uint32_t reg_val = GPIO->H[idx].PRDRVSTRENGTH;
  *predrv_strength = (uint8_t)((reg_val >> pin_shift) & _HSIO_P_PRDRVSTRENGTH_PRDRVSTRENGTH0_MASK);
  return SL_STATUS_OK;
}
#endif

#if defined(_HSIO_P_DRVSTRENGTH_MASK) && defined(HSIO_PRESENT)
/***************************************************************************//**
 * Set drive strength (controller TX driver strength) for an HSIO pin.
 *
 * @note HSIO ports (H[]) have a single DRVSTRENGTH register per port.
 *
 * @param[in] gpio Pointer to GPIO structure (must be an HSIO port).
 * @param[in] drive_strength Drive strength value (0 to mask max).
 *
 * @return SL_STATUS_OK on success.
 *         SL_STATUS_INVALID_PARAMETER if the port is not an HSIO port.
 ******************************************************************************/
__INLINE sl_status_t sl_hal_gpio_set_drive_strength(sl_gpio_t *gpio,
                                                    uint8_t drive_strength)
{
  EFM_ASSERT(gpio != NULL);
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  EFM_ASSERT(drive_strength <= (_HSIO_P_DRVSTRENGTH_DRVSTRENGTH0_MASK
                                >> _HSIO_P_DRVSTRENGTH_DRVSTRENGTH0_SHIFT));
  if (!sl_hal_gpio_is_hsio_port(gpio->port)) {
    EFM_ASSERT(false);
    return SL_STATUS_INVALID_PARAMETER;
  }

  /* Single DRVSTRENGTH register per HSIO port; 2 bits per pin. */
  uint32_t pin_shift = (uint32_t)gpio->pin << 1;
  uint32_t field_mask = _HSIO_P_DRVSTRENGTH_DRVSTRENGTH0_MASK << pin_shift;
  uint32_t field_val = (drive_strength & _HSIO_P_DRVSTRENGTH_DRVSTRENGTH0_MASK) << pin_shift;

  uint32_t idx = SL_HAL_HSIO_PORT_INDEX(gpio->port);
  uint32_t reg_val = GPIO->H[idx].DRVSTRENGTH;
  GPIO->H[idx].DRVSTRENGTH = (reg_val & ~field_mask) | field_val;
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Get drive strength (controller TX driver strength) for an HSIO pin.
 *
 * @param[in] gpio Pointer to GPIO structure (must be an HSIO port).
 * @param[out] drive_strength Pointer to store the drive strength value.
 *
 * @return SL_STATUS_OK on success.
 *         SL_STATUS_INVALID_PARAMETER if the port is not an HSIO port.
 ******************************************************************************/
__INLINE sl_status_t sl_hal_gpio_get_drive_strength(sl_gpio_t *gpio,
                                                    uint8_t *drive_strength)
{
  EFM_ASSERT(gpio != NULL);
  EFM_ASSERT(drive_strength != NULL);
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  if (!sl_hal_gpio_is_hsio_port(gpio->port)) {
    EFM_ASSERT(false);
    return SL_STATUS_INVALID_PARAMETER;
  }

  uint32_t pin_shift = (uint32_t)gpio->pin << 1;
  uint32_t idx = SL_HAL_HSIO_PORT_INDEX(gpio->port);
  uint32_t reg_val = GPIO->H[idx].DRVSTRENGTH;
  *drive_strength = (uint8_t)((reg_val >> pin_shift) & _HSIO_P_DRVSTRENGTH_DRVSTRENGTH0_MASK);
  return SL_STATUS_OK;
}
#endif

#if defined(_HSIO_P_HSRX_MASK) && defined(HSIO_PRESENT)
/***************************************************************************//**
 * Check if High-Speed RX is enabled for an HSIO pin.
 *
 * @param[in] gpio Pointer to GPIO structure (must be an HSIO port).
 * @param[out] is_enabled Pointer to store true if High-Speed RX is enabled, false otherwise.
 *
 * @return SL_STATUS_OK on success.
 *         SL_STATUS_INVALID_PARAMETER if the port is not an HSIO port..
 ******************************************************************************/
__INLINE sl_status_t sl_hal_gpio_is_high_speed_rx_enabled(sl_gpio_t *gpio,
                                                          bool *is_enabled)
{
  EFM_ASSERT(gpio != NULL);
  EFM_ASSERT(is_enabled != NULL);
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  if (!sl_hal_gpio_is_hsio_port(gpio->port)) {
    EFM_ASSERT(false);
    return SL_STATUS_INVALID_PARAMETER;
  }

  uint32_t idx = SL_HAL_HSIO_PORT_INDEX(gpio->port);
  uint32_t bit = (_HSIO_P_HSRX_HSRX0_MASK << (uint32_t)gpio->pin);
  *is_enabled = (GPIO->H[idx].HSRX & bit) != 0u;
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Configure High-Speed RX for an HSIO pin.
 *
 * @note HSIO ports (H[]) have a single HSRX register per port; one bit per pin.
 *       Set bit to enable High-Speed RX for that pin, clear to disable.
 *
 * @param[in] gpio Pointer to GPIO structure (must be an HSIO port).
 * @param[in] enable true to enable High-Speed RX for the pin, false to disable.
 *
 * @return SL_STATUS_OK on success.
 *         SL_STATUS_INVALID_PARAMETER if the port is not an HSIO port.
 ******************************************************************************/
__INLINE sl_status_t sl_hal_gpio_configure_high_speed_rx(sl_gpio_t *gpio,
                                                         bool enable)
{
  EFM_ASSERT(gpio != NULL);
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  if (!sl_hal_gpio_is_hsio_port(gpio->port)) {
    EFM_ASSERT(false);
    return SL_STATUS_INVALID_PARAMETER;
  }

  uint32_t idx = SL_HAL_HSIO_PORT_INDEX(gpio->port);
  uint32_t bit = (_HSIO_P_HSRX_HSRX0_MASK << (uint32_t)gpio->pin);

  if (enable) {
    GPIO->H[idx].HSRX |= bit;
  } else {
    GPIO->H[idx].HSRX &= ~bit;
  }
  return SL_STATUS_OK;
}

#endif

#if defined(_HSIO_P_HSRXHYST_MASK) && defined(HSIO_PRESENT)
/***************************************************************************//**
 * Set High-Speed RX hysteresis for an HSIO port.
 *
 * @note HSRXHYST is a port-level 2-bit field; one value per HSIO port.
 *
 * @param[in] gpio Pointer to GPIO structure (must be an HSIO port).
 * @param[in] hysteresis Hysteresis value (0-3).
 *
 * @return SL_STATUS_OK on success.
 *         SL_STATUS_INVALID_PARAMETER if the port is not an HSIO port.
 ******************************************************************************/
__INLINE sl_status_t sl_hal_gpio_set_high_speed_rx_hysteresis(sl_gpio_t *gpio,
                                                               uint8_t hysteresis)
{
  EFM_ASSERT(gpio != NULL);
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  EFM_ASSERT(hysteresis <= _HSIO_P_HSRXHYST_HSRXHYST_MASK);
  if (!sl_hal_gpio_is_hsio_port(gpio->port)) {
    EFM_ASSERT(false);
    return SL_STATUS_INVALID_PARAMETER;
  }

  uint32_t idx = SL_HAL_HSIO_PORT_INDEX(gpio->port);
  GPIO->H[idx].HSRXHYST = (GPIO->H[idx].HSRXHYST & ~_HSIO_P_HSRXHYST_MASK)
                          | ((uint32_t)hysteresis & _HSIO_P_HSRXHYST_MASK);
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Get High-Speed RX hysteresis for an HSIO port.
 *
 * @param[in] gpio Pointer to GPIO structure (must be an HSIO port).
 * @param[out] hysteresis Pointer to store the current hysteresis value (0-3).
 *
 * @return SL_STATUS_OK on success.
 *         SL_STATUS_INVALID_PARAMETER if the port is not an HSIO port.
 ******************************************************************************/
__INLINE sl_status_t sl_hal_gpio_get_high_speed_rx_hysteresis(sl_gpio_t *gpio,
                                                               uint8_t *hysteresis)
{
  EFM_ASSERT(gpio != NULL);
  EFM_ASSERT(hysteresis != NULL);
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  if (!sl_hal_gpio_is_hsio_port(gpio->port)) {
    EFM_ASSERT(false);
    return SL_STATUS_INVALID_PARAMETER;
  }

  uint32_t idx = SL_HAL_HSIO_PORT_INDEX(gpio->port);
  *hysteresis = (uint8_t)(GPIO->H[idx].HSRXHYST & _HSIO_P_HSRXHYST_MASK);
  return SL_STATUS_OK;
}
#endif

#if defined(_HSIO_P_NONOVRLPDIS_MASK) && defined(HSIO_PRESENT)
/***************************************************************************//**
 * Set Non-Overlap Protection Disable for an HSIO TX pin.
 *
 * @note
 *   - HSIO ports (H[]) have a single NONOVRLPDIS register per port; one bit
 *     per pin.
 *   - When the bit is clear (default), non-overlap protection is
 *     enabled, preventing shoot-through in the push-pull output stage.
 *   - When the bit is set, protection is disabled for that pin.
 *
 * @param[in] gpio Pointer to GPIO structure (must be an HSIO port).
 * @param[in] disable true to disable non-overlap protection (set NONOVRLPDIS
 *                    bit); false to enable protection (clear bit).
 *
 * @return SL_STATUS_OK on success.
 *         SL_STATUS_INVALID_PARAMETER if the port is not an HSIO port.
 ******************************************************************************/
__INLINE sl_status_t sl_hal_gpio_set_non_overlap_protection_disable(sl_gpio_t *gpio,
                                                                    bool disable)
{
  EFM_ASSERT(gpio != NULL);
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  if (!sl_hal_gpio_is_hsio_port(gpio->port)) {
    EFM_ASSERT(false);
    return SL_STATUS_INVALID_PARAMETER;
  }

  uint32_t idx = SL_HAL_HSIO_PORT_INDEX(gpio->port);
  uint32_t bit = (1UL << (uint32_t)gpio->pin);

  if (disable) {
    GPIO->H[idx].NONOVRLPDIS |= bit;
  } else {
    GPIO->H[idx].NONOVRLPDIS &= ~bit;
  }
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Get Non-Overlap Protection Disable state for an HSIO pin.
 *
 * @param[in] gpio Pointer to GPIO structure (must be an HSIO port).
 * @param[out] disable Pointer to store true if non-overlap protection is disabled,
 *                     false if protection is enabled.
 *
 * @return SL_STATUS_OK on success.
 *         SL_STATUS_INVALID_PARAMETER if the port is not an HSIO port.
 ******************************************************************************/
__INLINE sl_status_t sl_hal_gpio_get_non_overlap_protection_disable(sl_gpio_t *gpio,
                                                                    bool *disable)
{
  EFM_ASSERT(gpio != NULL);
  EFM_ASSERT(disable != NULL);
  EFM_ASSERT(SL_HAL_GPIO_PORT_PIN_IS_VALID(gpio->port, gpio->pin));
  if (!sl_hal_gpio_is_hsio_port(gpio->port)) {
    EFM_ASSERT(false);
    return SL_STATUS_INVALID_PARAMETER;
  }

  uint32_t idx = SL_HAL_HSIO_PORT_INDEX(gpio->port);
  uint32_t bit = (1UL << (uint32_t)gpio->pin);
  *disable = (GPIO->H[idx].NONOVRLPDIS & bit) != 0u;
  return SL_STATUS_OK;
}
#endif

/** @} (end addtogroup gpio) */

#ifdef __cplusplus
}
#endif

/* *INDENT-OFF* */
/****************************************************************************//**
 * @addtogroup gpio GPIO - General Purpose Input Output
 * @{
 *
 * @n @section gpio_example Example
 *  The following example demonstrates the basic GPIO operations available in the Silicon Labs
 *  GPIO API. This example shows how to:
 *  - Define and configure a GPIO pin as an output
 *  - Control pin state (high, low, toggle)
 *  - Read the pin's input state
 *  - Configure and enable external interrupts
 *
 *   This code can be used as a starting point for controlling LEDs, reading button inputs,
 *   or configuring interrupt-driven GPIO events in your application.
 *
 *  @code{.c}
 *  {
 *    // Enable bus clock for GPIO
 *    sl_clock_manager_enable_bus_clock(SL_BUS_CLOCK_GPIO);
 *
 *    // Define GPIO pin
 *    sl_gpio_t led_pin = {
 *      .port = 0,  // Port A
 *      .pin = 0    // Pin 0
 *    };
 *
 *    // Configure pin as push-pull output
 *    sl_hal_gpio_set_pin_mode(&led_pin, SL_GPIO_MODE_PUSH_PULL, false);
 *
 *    // Set pin high
 *    sl_hal_gpio_set_pin(&led_pin);
 *
 *    // Wait a moment
 *    for(volatile int i = 0; i < 100000; i++);
 *
 *    // Clear pin (set low)
 *    sl_hal_gpio_clear_pin(&led_pin);
 *
 *    // Toggle pin
 *    sl_hal_gpio_toggle_pin(&led_pin);
 *
 *    // Read pin input
 *    bool pin_state = sl_hal_gpio_get_pin_input(&led_pin);
 *
 *    // Configure external interrupt
 *    int32_t int_no = sl_hal_gpio_configure_external_interrupt(&led_pin,
 *                                                             SL_HAL_GPIO_INTERRUPT_UNAVAILABLE,
 *                                                             SL_GPIO_INTERRUPT_RISING_EDGE);
 *
 *    // Enable interrupt
 *    sl_hal_gpio_enable_interrupts(1 << int_no);
 *  }
 *  @endcode
 *
 * @} (end addtogroup gpio)
 ******************************************************************************/
/* *INDENT-ON* */

#endif /* GPIO_PRESENT */
#endif /* SL_HAL_GPIO_H */
