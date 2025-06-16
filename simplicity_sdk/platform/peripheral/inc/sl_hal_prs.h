/***************************************************************************//**
 * @file
 * @brief Peripheral Reflex System (PRS) peripheral API
 *******************************************************************************
 * # License
 * <b>Copyright 2025 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef SL_HAL_PRS_H
#define SL_HAL_PRS_H

#include "em_device.h"

#if defined(PRS_COUNT) && (PRS_COUNT > 0)

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>
#include <stddef.h>
#include "sl_assert.h"
#include "sl_status.h"
#include "sl_hal_gpio.h"
#include "sl_enum.h"

#if defined(HAL_PRS_INTERNAL_PRESENT)
#include "sl_hal_prs_enums_internal.h"
#else
#include "sl_hal_prs_enums.h"
#endif

/***************************************************************************//**
 * @addtogroup prs PRS - Peripheral Reflex System
 * @brief Peripheral Reflex System (PRS) Peripheral API
 * @details
 *  This module contains functions to control the PRS peripheral of Silicon
 *  Labs 32-bit MCUs and SoCs. The PRS allows configurable, fast, and autonomous
 *  communication between peripherals on the MCU or SoC.
 * @{
 ******************************************************************************/

/*******************************************************************************
 *******************************   DEFINES   ***********************************
 ******************************************************************************/

/// PRS Synchronous channel count.
#define SL_HAL_PRS_SYNC_CHAN_COUNT    PRS_SYNC_CH_NUM
/// PRS Asynchronous channel count.
#define SL_HAL_PRS_ASYNC_CHAN_COUNT   PRS_ASYNC_CH_NUM

/*******************************************************************************
 ********************************   ENUMS   ************************************
 ******************************************************************************/

/// PRS Channel type.
SL_ENUM(sl_hal_prs_channel_type_t) {
  SL_HAL_PRS_TYPE_ASYNC,   ///< Asynchronous channel type.
  SL_HAL_PRS_TYPE_SYNC     ///< Synchronous channel type.
};

#if defined(_PRS_ASYNC_CH_CTRL_FNSEL_MASK)
/// Logic functions that can be used when combining two PRS channels.
SL_ENUM(sl_hal_prs_logic_t) {
  SL_HAL_PRS_LOGIC_ZERO        = _PRS_ASYNC_CH_CTRL_FNSEL_LOGICAL_ZERO, ///< Logical 0.
  SL_HAL_PRS_LOGIC_A_NOR_B     = _PRS_ASYNC_CH_CTRL_FNSEL_A_NOR_B,      ///< A NOR B.
  SL_HAL_PRS_LOGIC_NOT_A_AND_B = _PRS_ASYNC_CH_CTRL_FNSEL_NOT_A_AND_B,  ///< (!A) NOR B.
  SL_HAL_PRS_LOGIC_NOT_A       = _PRS_ASYNC_CH_CTRL_FNSEL_NOT_A,        ///< !A.
  SL_HAL_PRS_LOGIC_A_AND_NOT_B = _PRS_ASYNC_CH_CTRL_FNSEL_A_AND_NOT_B,  ///< A AND (!B).
  SL_HAL_PRS_LOGIC_NOT_B       = _PRS_ASYNC_CH_CTRL_FNSEL_NOT_B,        ///< !B.
  SL_HAL_PRS_LOGIC_A_XOR_B     = _PRS_ASYNC_CH_CTRL_FNSEL_A_XOR_B,      ///< A XOR B.
  SL_HAL_PRS_LOGIC_A_NAND_B    = _PRS_ASYNC_CH_CTRL_FNSEL_A_NAND_B,     ///< A NAND B.
  SL_HAL_PRS_LOGIC_A_AND_B     = _PRS_ASYNC_CH_CTRL_FNSEL_A_AND_B,      ///< A AND B.
  SL_HAL_PRS_LOGIC_A_XNOR_B    = _PRS_ASYNC_CH_CTRL_FNSEL_A_XNOR_B,     ///< A XNOR B.
  SL_HAL_PRS_LOGIC_B           = _PRS_ASYNC_CH_CTRL_FNSEL_B,            ///< B.
  SL_HAL_PRS_LOGIC_NOT_A_OR_B  = _PRS_ASYNC_CH_CTRL_FNSEL_NOT_A_OR_B,   ///< (!A) OR B.
  SL_HAL_PRS_LOGIC_A           = _PRS_ASYNC_CH_CTRL_FNSEL_A,            ///< A.
  SL_HAL_PRS_LOGIC_A_OR_NOT_B  = _PRS_ASYNC_CH_CTRL_FNSEL_A_OR_NOT_B,   ///< A OR (!B).
  SL_HAL_PRS_LOGIC_A_OR_B      = _PRS_ASYNC_CH_CTRL_FNSEL_A_OR_B,       ///< A OR B.
  SL_HAL_PRS_LOGIC_ONE         = _PRS_ASYNC_CH_CTRL_FNSEL_LOGICAL_ONE,  ///< Logical 1.
};
#endif

/*******************************************************************************
 ********************************   STRUCTS   **********************************
 ******************************************************************************/

/// PRS async channel configuration structure.
typedef struct {
  uint8_t channel;                                      ///< Channel number.
#if defined(_PRS_ASYNC_CH_CTRL_AUXSEL_MASK)
  uint8_t aux_prs;                                      ///< Channel to input to logic block.
#endif
  sl_hal_prs_logic_t logic;                             ///< Lookup function for configurable logic.
  sl_hal_prs_async_producer_signal_t producer_signal;   ///< Peripheral signal.
  sl_hal_prs_consumer_event_t consumer_event;           ///< Peripheral consumer. Used to select which signal to listen to.
} sl_hal_prs_async_channel_config_t;

/// PRS sync channel configuration structure.
typedef struct {
  uint8_t channel;                                      ///< Channel number.
  sl_hal_prs_sync_producer_signal_t producer_signal;    ///< Peripheral signal.
  sl_hal_prs_consumer_event_t consumer_event;           ///< Peripheral consumer. Used to select which signal to listen to.
} sl_hal_prs_sync_channel_config_t;

#if defined(_PRS_ASYNC_CH_CTRL_AUXSEL_MASK)
/// PRS async initializer (No channel combination).
#define SL_HAL_PRS_ASYNC_INIT_DEFAULT(channel, producer_signal, consumer_event)         \
  {                                                                                     \
    channel,                                              /* PRS channel. */            \
    (uint8_t)_PRS_ASYNC_CH_CTRL_AUXSEL_DEFAULT,           /* Aux PRS Not used. */       \
    (sl_hal_prs_logic_t)_PRS_ASYNC_CH_CTRL_FNSEL_DEFAULT, /* No channel combination. */ \
    producer_signal,                                      /* Signal of producer. */     \
    consumer_event,                                       /* Peripheral consumer. */    \
  }
#else
#define SL_HAL_PRS_ASYNC_INIT_DEFAULT(channel, producer_signal, consumer_event)         \
  {                                                                                     \
    channel,                                              /* PRS channel. */            \
    (sl_hal_prs_logic_t)_PRS_ASYNC_CH_CTRL_FNSEL_DEFAULT, /* No channel combination. */ \
    producer_signal,                                      /* Signal of producer. */     \
    consumer_event,                                       /* Peripheral consumer. */    \
  }
#endif

/// PRS sync initializer.
#define SL_HAL_PRS_SYNC_INIT_DEFAULT(channel, producer_signal, consumer_event) \
  {                                                                            \
    channel,                              /* PRS channel. */                   \
    producer_signal,                      /* Signal of producer. */            \
    consumer_event,                       /* Peripheral consumer. */           \
  }

/*******************************************************************************
 *****************************   PROTOTYPES   **********************************
 ******************************************************************************/

/***************************************************************************//**
 * @brief
 *   Configure Async channel.
 *
 * @param[in] config
 *   Pointer to configuration structure.
 ******************************************************************************/
void sl_hal_prs_async_init_channel(const sl_hal_prs_async_channel_config_t *config);

/***************************************************************************//**
 * @brief
 *   Configure Sync channel.
 *
 * @param[in] config
 *   Pointer to configuration structure.
 ******************************************************************************/
void sl_hal_prs_sync_init_channel(const sl_hal_prs_sync_channel_config_t *config);

/***************************************************************************//**
 * @brief
 *   Search for the first free PRS channel. It applies for sync/async channels.
 *
 * @param[in] channel
 *   PRS channel number.
 *
 * @param[in] channel_type
 *   PRS channel type. This can be either
 *   @ref SL_HAL_PRS_TYPE_ASYNC or @ref SL_HAL_PRS_TYPE_SYNC.
 *
 * @return
 *   SL_STATUS_OK if an unused PRS channel was found. If no free PRS
 *   channel was found then SL_STATUS_FAIL is returned.
 ******************************************************************************/
sl_status_t sl_hal_prs_get_free_channel(uint8_t *channel,
                                        sl_hal_prs_channel_type_t channel_type);

/***************************************************************************//**
 * @brief
 *   Reset all PRS channels
 *
 * @details
 *   This function will reset all the PRS channel configuration.
 ******************************************************************************/
void sl_hal_prs_reset(void);

/***************************************************************************//**
 * @brief
 *   Connect a peripheral consumer to a PRS channel.
 *
 * @details
 *   Different peripherals can use PRS channels as their input. This
 *   function can be used to connect a peripheral consumer to a PRS channel.
 *   Multiple consumers can be connected to a single PRS channel.
 *   It applies for sync/async channels.
 *
 * @param[in] channel
 *   PRS channel number.
 *
 * @param[in] channel_type
 *   PRS channel type. This can be either
 *   @ref SL_HAL_PRS_TYPE_ASYNC or @ref SL_HAL_PRS_TYPE_SYNC.
 *
 * @param[in] consumer_event
 *   This is the PRS consumer.
 ******************************************************************************/
void sl_hal_prs_connect_channel_consumer(uint8_t channel,
                                         sl_hal_prs_channel_type_t channel_type,
                                         sl_hal_prs_consumer_event_t consumer_event);

/***************************************************************************//**
 * @brief
 *   Send the output of a PRS channel to a GPIO pin.
 *
 * @details
 *   This function is used to send the output of a PRS channel to a GPIO pin.
 *
 * @note
 *  There are certain restrictions to where a PRS channel can be routed. Consult
 *  the datasheet of the device to see if the selected @p channel is routable
 *  to the requested gpio @p port . Some devices for instance can only route
 *  the async channels 0-5 on GPIO pins PAx and PBx while async channels 6-11
 *  can only be routed to GPIO pins PCx and PDx. It applies for sync/async
 *  channels.
 *
 * @param[in] channel
 *   PRS channel number.
 *
 * @param[in] channel_type
 *   PRS channel type. This can be either
 *                         @ref SL_HAL_PRS_TYPE_ASYNC or @ref SL_HAL_PRS_TYPE_SYNC.
 *
 * @param[in] port
 *   GPIO port
 *
 * @param[in] pin
 *   GPIO pin
 ******************************************************************************/
void sl_hal_prs_pin_output(uint8_t channel,
                           sl_hal_prs_channel_type_t channel_type,
                           sl_gpio_port_t port,
                           uint8_t pin);

/***************************************************************************//**
 * @brief
 *   Set level control bit for one channel.
 *
 * @details The level value for a channel is XORed with both the pulse possibly
 *          issued by sl_hal_prs_async_set_channel_swpulse() and the PRS input
 *          signal selected for the channel(s).
 *
 * @param[in] channel
 *   channel to set level for. Use logical OR combination
 *   of PRS_SWLEVEL_CHnLEVEL defines.
 *
 * @param[in] level
 *   Level to use for channel @p channel. Use logical OR combination
 *   of PRS_SWLEVEL_CHnLEVEL defines for channels to set high level,
 *   otherwise 0.
 ******************************************************************************/
__INLINE void sl_hal_prs_async_set_channel_swlevel(uint8_t channel,
                                                   bool level)
{
  EFM_ASSERT(channel < SL_HAL_PRS_ASYNC_CHAN_COUNT);

  level ? (PRS->ASYNC_SWLEVEL_SET = 0x1 << channel) \
  : (PRS->ASYNC_SWLEVEL_CLR = 0x1 << channel);
}

/***************************************************************************//**
 * @brief
 *   Get level control bit for a channel.
 *
 * @param[in] channel
 *   Channel to get level for.
 *
 * @return
 *   The current software level configuration for a channel.
 ******************************************************************************/
__INLINE bool sl_hal_prs_async_get_channel_swlevel(uint8_t channel)
{
  EFM_ASSERT(channel < SL_HAL_PRS_ASYNC_CHAN_COUNT);

  return (PRS->ASYNC_SWLEVEL >> channel) & _PRS_ASYNC_SWLEVEL_CH0LEVEL_MASK;
}

/***************************************************************************//**
 * @brief
 *   Get the PRS channel value for one channel. It applies for sync/async channels
 *
 * @param[in] channel
 *   PRS channel to get value for.
 *
 * @param[in] channel_type
 *   PRS channel type. This can be either
 *   @ref SL_HAL_PRS_TYPE_ASYNC or @ref SL_HAL_PRS_TYPE_SYNC.
 *
 * @return
 *   The current PRS channel output value.
 ******************************************************************************/
__INLINE bool sl_hal_prs_get_channel_value(uint8_t channel,
                                           sl_hal_prs_channel_type_t channel_type)
{
  if (channel_type == SL_HAL_PRS_TYPE_ASYNC) {
    EFM_ASSERT(channel < SL_HAL_PRS_ASYNC_CHAN_COUNT);

    return (PRS->ASYNC_PEEK >> channel) & _PRS_ASYNC_PEEK_CH0VAL_MASK;
  } else {
    EFM_ASSERT(channel < SL_HAL_PRS_SYNC_CHAN_COUNT);

    return (PRS->SYNC_PEEK >> channel) & _PRS_SYNC_PEEK_CH0VAL_MASK;
  }
}

/***************************************************************************//**
 * @brief
 *   Trigger a high pulse (one HFPERCLK) for one channel.
 *
 * @details
 *   Setting a bit for a channel causes the bit in the register to remain
 *   high for one HFPERCLK cycle. Pulse is XORed with both the corresponding
 *   bit in PRS SWLEVEL register and the PRS input signal selected for the
 *   channel(s).
 *
 * @param[in] channel
 *   PRS channel to trigger a pulse.
 ******************************************************************************/
__INLINE void sl_hal_prs_async_set_channel_swpulse(uint8_t channel)
{
  EFM_ASSERT(channel < SL_HAL_PRS_ASYNC_CHAN_COUNT);

  PRS->ASYNC_SWPULSE_SET = 0x1 << channel;
}

/***************************************************************************//**
 * @brief
 *   Set PRS signal for an async channel.
 *
 * @param[in] channel
 *   PRS channel number.
 *
 * @param[in] producer_signal
 *   An async peripheral signal selected as a producer
 *   for PRS channel. It is a combination of source
 *   select and signal select values.
 ******************************************************************************/
__INLINE void sl_hal_prs_async_connect_channel_producer(uint8_t channel,
                                                        sl_hal_prs_async_producer_signal_t producer_signal)
{
  EFM_ASSERT(channel < SL_HAL_PRS_ASYNC_CHAN_COUNT);

  PRS->ASYNC_CH[channel].CTRL &= ~(_PRS_ASYNC_CH_CTRL_SIGSEL_MASK | _PRS_ASYNC_CH_CTRL_SOURCESEL_MASK);
  PRS->ASYNC_CH[channel].CTRL |= producer_signal;
}

/***************************************************************************//**
 * @brief
 *   Set PRS signal for a sync channel.
 *
 * @param[in] channel
 *   PRS channel number.
 *
 * @param[in] producer_signal
 *   A sync peripheral signal selected as a producer
 *   for PRS channel. It is a combination of source
 *   select and signal select values.
 ******************************************************************************/
__INLINE void sl_hal_prs_sync_connect_channel_producer(uint8_t channel,
                                                       sl_hal_prs_sync_producer_signal_t producer_signal)
{
  EFM_ASSERT(channel < SL_HAL_PRS_SYNC_CHAN_COUNT);

  PRS->SYNC_CH[channel].CTRL &= ~(_PRS_SYNC_CH_CTRL_SIGSEL_MASK | _PRS_SYNC_CH_CTRL_SOURCESEL_MASK);
  PRS->SYNC_CH[channel].CTRL |= producer_signal;
}

/***************************************************************************//**
 * @brief
 *   Combine two PRS channels using a logic function.
 *
 * @details This function allows you to combine the output of one PRS channel
 *          with the the signal of another PRS channel using various logic functions.
 *          Note that for series 2, config 1 devices, the hardware only allows
 *          a PRS channel to be combined with the previous channel. So for
 *          instance channel 5 can be combined only with channel 4.
 *          The logic function operates on two PRS channels called A and B.
 *          The output of PRS channel B is combined with the PRS source configured
 *          for channel A to produce an output.
 *          This output is used as the output of channel A.
 *
 * @param[in] channel_a PRS Channel for the A input.
 * @param[in] channel_b PRS Channel for the B input.
 * @param[in] logic The logic function to use when combining the Channel A and Channel B.
 *                  The output of the logic function is the output of Channel A.
 *                  Function like AND, OR, XOR, NOT and more are available.
 ******************************************************************************/
__INLINE void sl_hal_prs_async_combine_signals(uint8_t channel_a,
                                               uint8_t channel_b,
                                               sl_hal_prs_logic_t logic)
{
  EFM_ASSERT(channel_a < SL_HAL_PRS_ASYNC_CHAN_COUNT);

#if defined(_PRS_ASYNC_CH_CTRL_AUXSEL_MASK)
  EFM_ASSERT(channel_b < SL_HAL_PRS_ASYNC_CHAN_COUNT);

  PRS->ASYNC_CH[channel_a].CTRL = (PRS->ASYNC_CH[channel_a].CTRL
                                   & ~(_PRS_ASYNC_CH_CTRL_FNSEL_MASK
                                       | _PRS_ASYNC_CH_CTRL_AUXSEL_MASK))
                                  | ((uint32_t)logic << _PRS_ASYNC_CH_CTRL_FNSEL_SHIFT)
                                  | ((uint32_t)channel_b << _PRS_ASYNC_CH_CTRL_AUXSEL_SHIFT);
#else
  EFM_ASSERT(channel_a == ((channel_b + 1) % SL_HAL_PRS_ASYNC_CHAN_COUNT));

  PRS->ASYNC_CH[channel_a].CTRL = (PRS->ASYNC_CH[channel_a].CTRL
                                   & ~(_PRS_ASYNC_CH_CTRL_FNSEL_MASK))
                                  | ((uint32_t)logic << _PRS_ASYNC_CH_CTRL_FNSEL_SHIFT);
#endif
}

/** @} (end addtogroup prs) */
#ifdef __cplusplus
}
#endif

/****************************************************************************//**
 * @addtogroup prs PRS - Peripheral Reflex System
 * @{
 *
 *@n @section prs_example Example
 *   This example demonstrates how to configure the Peripheral Reflex System (PRS)
 *   to connect a producer (timer overflow) directly to a consumer (GPIO pin toggle)
 *   without CPU intervention.
 *
 * @code
 * #include "sl_hal_prs.h"
 * #include "sl_hal_timer.h"
 * #include "sl_hal_gpio.h"
 *
 * void prs_example(void)
 * {
 *   // Initialize GPIO and timer peripherals (not shown)
 *   // ...
 *
 *   // Configure PRS source (TIMER0 overflow as producer)
 *   sl_hal_prs_source_config_t sourceConfig = SL_HAL_PRS_SOURCE_CONFIG_DEFAULT;
 *   sourceConfig.source = SL_HAL_PRS_SOURCE_TIMER0_OF;
 *   sourceConfig.signal = SL_HAL_PRS_SIGNAL_TIMER_OF;
 *
 *   // Configure PRS channel
 *   sl_hal_prs_channel_config_t channelConfig = SL_HAL_PRS_CHANNEL_CONFIG_DEFAULT;
 *   channelConfig.enable = true;
 *   channelConfig.async_mode = false; // Use synchronous PRS
 *
 *   // Initialize PRS channel 0 with TIMER0 overflow as source
 *   sl_hal_prs_init_channel(0, &channelConfig);
 *   sl_hal_prs_set_source(0, &sourceConfig);
 *
 *   // Route PRS channel to GPIO pin (configure GPIO port B pin 0 as output)
 *   sl_hal_gpio_pin_config_t gpioConfig = SL_HAL_GPIO_INIT_DEFAULT;
 *   gpioConfig.mode = SL_HAL_GPIO_MODE_PUSH_PULL;
 *   sl_hal_gpio_init_pin(SL_HAL_GPIO_PORT_B, 0, &gpioConfig);
 *
 *   // Connect PRS to GPIO
 *   sl_hal_prs_connect_gpio(0, SL_HAL_GPIO_PORT_B, 0, SL_HAL_PRS_GPIO_OUT_TOGGLE);
 *
 *   // Now, whenever TIMER0 overflows, it will automatically toggle GPIO PB0
 *   // without CPU intervention
 * }
 * @endcode
 * @} (end addtogroup prs)
 ******************************************************************************/

#endif /* defined(PRS_COUNT) && (PRS_COUNT > 0) */
#endif /* SL_HAL_PRS_H */
