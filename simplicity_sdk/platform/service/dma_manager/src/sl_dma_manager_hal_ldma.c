/***************************************************************************//**
 * @file
 * @brief DMA Manager APIs.
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

#include <stdbool.h>
#include <stdlib.h>
#include "em_device.h"
#include "sl_status.h"
#include "sl_assert.h"
#include "sl_bit.h"
#include "sl_device_peripheral.h"
#include "sli_dma_manager_internal.h"
#include "sl_clock_manager.h"
#include "sl_interrupt_manager.h"
#include "sl_hal_ldma.h"

// -----------------------------------------------------------------------------
// FUNCTION DECLARATIONS

#if !defined(_SILICON_LABS_32B_SERIES_2)
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
static void ldma_irq_channel_handler(uint8_t channel_nbr);

SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
static void ldma_irq_handler_channel0(void);

SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
static void ldma_irq_handler_channel1(void);

SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
static void ldma_irq_handler_channel2(void);

SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
static void ldma_irq_handler_channel3(void);

SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
static void ldma_irq_handler_channel4(void);

SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
static void ldma_irq_handler_channel5(void);

SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
static void ldma_irq_handler_channel6(void);

SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
static void ldma_irq_handler_channel7(void);

#if (DMA_CHAN_COUNT > 8)
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
static void ldma_irq_handler_channel8(void);
#endif

#if (DMA_CHAN_COUNT > 9)
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
static void ldma_irq_handler_channel9(void);
#endif

#if (DMA_CHAN_COUNT > 10)
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
static void ldma_irq_handler_channel10(void);
#endif

#if (DMA_CHAN_COUNT > 11)
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
static void ldma_irq_handler_channel11(void);
#endif

#if (DMA_CHAN_COUNT > 12)
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
static void ldma_irq_handler_channel12(void);
#endif

#if (DMA_CHAN_COUNT > 13)
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
static void ldma_irq_handler_channel13(void);
#endif

#if (DMA_CHAN_COUNT > 14)
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
static void ldma_irq_handler_channel14(void);
#endif

#if (DMA_CHAN_COUNT > 15)
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
static void ldma_irq_handler_channel15(void);
#endif

#if (DMA_CHAN_COUNT > 16)
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
static void ldma_irq_handler_channel16(void);
#endif

#if (DMA_CHAN_COUNT > 17)
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
static void ldma_irq_handler_channel17(void);
#endif
#endif

// -----------------------------------------------------------------------------
// GLOBAL VARIABLES
#if !defined(_SILICON_LABS_32B_SERIES_2)
static sl_dma_manager_channel_irq_callback_t channel_irq_callbacks[DMA_CHAN_COUNT] = {
  ldma_irq_handler_channel0,
  ldma_irq_handler_channel1,
  ldma_irq_handler_channel2,
  ldma_irq_handler_channel3,
  ldma_irq_handler_channel4,
  ldma_irq_handler_channel5,
  ldma_irq_handler_channel6,
  ldma_irq_handler_channel7
#if (DMA_CHAN_COUNT > 8)
  , ldma_irq_handler_channel8
#endif
#if (DMA_CHAN_COUNT > 9)
  , ldma_irq_handler_channel9
#endif
#if (DMA_CHAN_COUNT > 10)
  , ldma_irq_handler_channel10
#endif
#if (DMA_CHAN_COUNT > 11)
  , ldma_irq_handler_channel11
#endif
#if (DMA_CHAN_COUNT > 12)
  , ldma_irq_handler_channel12
#endif
#if (DMA_CHAN_COUNT > 13)
  , ldma_irq_handler_channel13
#endif
#if (DMA_CHAN_COUNT > 14)
  , ldma_irq_handler_channel14
#endif
#if (DMA_CHAN_COUNT > 15)
  , ldma_irq_handler_channel15
#endif
#if (DMA_CHAN_COUNT > 16)
  , ldma_irq_handler_channel16
#endif
#if (DMA_CHAN_COUNT > 17)
  , ldma_irq_handler_channel17
#endif
};
#endif

// Pending errors bitmap
static uint32_t sli_dma_manager_pending_errors[DMA_CHAN_COUNT] = { 0 };

// -----------------------------------------------------------------------------
// FUNCTION DEFINITIONS

/***************************************************************************//**
 * Initializes the LDMA peripheral for the DMA Manager.
 ******************************************************************************/
void sli_dma_manager_hal_init(const sl_peripheral_dma_t dma_peripheral)
{
  LDMA_TypeDef *ldma_hw_instance = sl_device_peripheral_ldma_get_base_addr((sl_peripheral_t)dma_peripheral);
  sl_bus_clock_t bus_clock = sl_device_peripheral_get_bus_clock((sl_peripheral_t)dma_peripheral);

  sl_clock_manager_enable_bus_clock(bus_clock);
  // Enable LDMAXBAR0 clock
  sl_clock_manager_enable_bus_clock(SL_BUS_CLOCK_LDMAXBAR0);

#if defined(_SILICON_LABS_32B_SERIES_2)
  sl_interrupt_manager_clear_irq_pending(LDMA_IRQn);
  sl_interrupt_manager_enable_irq(LDMA_IRQn);
#endif

  // Initialize LDMA
  sl_hal_ldma_config_t dma_init = SL_HAL_LDMA_INIT_DEFAULT;

  sl_hal_ldma_init(ldma_hw_instance, &dma_init);
  sl_hal_ldma_enable(ldma_hw_instance);
}

#if defined(SL_CATALOG_DMA_MANAGER_ROUND_ROBIN_PRESENT)
/***************************************************************************//**
 * Sets the number of round robin channels in LDMA Hardware instance.
 ******************************************************************************/
void sli_dma_manager_hal_configure_round_robin_channel_nbr(const sl_peripheral_dma_t dma_peripheral,
                                                           uint8_t nbr_round_robin_channels)
{
  LDMA_TypeDef *ldma_hw_instance = sl_device_peripheral_ldma_get_base_addr((sl_peripheral_t)dma_peripheral);
  uint8_t numfixed_config_value = DMA_CHAN_COUNT - nbr_round_robin_channels;

  ldma_hw_instance->CTRL = (ldma_hw_instance->CTRL & ~_LDMA_CTRL_NUMFIXED_MASK) | (numfixed_config_value << _LDMA_CTRL_NUMFIXED_SHIFT);
}
#endif

/***************************************************************************//**
 * Gets the DMA peripheral object for the current device.
 ******************************************************************************/
sl_peripheral_dma_t sli_dma_manager_hal_get_dma_peripheral(void)
{
  return SL_PERIPHERAL_DMA_LDMA0;
}

/***************************************************************************//**
 * Sets the channel IRQ handler for a specific DMA channel.
 ******************************************************************************/
void sli_dma_manager_hal_configure_channel_irq(uint8_t channel_nbr)
{
#if defined(_SILICON_LABS_32B_SERIES_2)
  (void)channel_nbr;
#else

  // Enable Interrupt in NVIC
  sl_interrupt_manager_clear_irq_pending(LDMA0_CHNL0_IRQn + channel_nbr);
  sl_interrupt_manager_enable_irq(LDMA0_CHNL0_IRQn + channel_nbr);

  // Register the callback with the Interrupt Manager
  sl_interrupt_manager_set_irq_handler((IRQn_Type)(LDMA0_CHNL0_IRQn + channel_nbr), channel_irq_callbacks[channel_nbr]);
#endif
}

/***************************************************************************//**
 *  Get the pending errors for the DMA manager.
 *  This function retrieves the current pending errors.
 ******************************************************************************/
uint32_t sli_dma_manager_hal_get_pending_errors(uint8_t channel_nbr)
{
  return sli_dma_manager_pending_errors[channel_nbr];
}

/***************************************************************************//**
 *  Clear the pending errors for the DMA manager.
 *  This function clears the pending error flag for the specified channel.
 *  It is idempotent and safe to call multiple times.
 *
 * @param[in]  channel_nbr Channel number.
 ******************************************************************************/
void sli_dma_manager_hal_clear_pending_errors(uint8_t channel_nbr)
{
  sli_dma_manager_pending_errors[channel_nbr] = 0;
}

/***************************************************************************//**
 *  Latch a pending error bitmap for the DMA manager.
 *
 *  Allows callers outside the IRQ dispatch path to surface a DMA channel error
 *  to the DMA Channel Driver. The next call to
 *  @ref sli_dma_manager_hal_get_pending_errors for this channel will return
 *  the latched value.
 ******************************************************************************/
void sli_dma_manager_hal_set_pending_errors(uint8_t channel_nbr, uint32_t errors)
{
  sli_dma_manager_pending_errors[channel_nbr] = errors;
}

#if defined(_SILICON_LABS_32B_SERIES_2)
/***************************************************************************//**
 * Interrupt handler for LDMA module.
 ******************************************************************************/
void LDMA_IRQHandler(void)
{
  uint32_t pending;
  uint32_t pending_done;
  uint32_t pending_error;

  // Get all pending and enabled interrupts.
  pending = sl_hal_ldma_get_enabled_pending_interrupts(LDMA);
  // clear interrupts
  sl_hal_ldma_clear_interrupts(LDMA, pending);
  pending_done = pending & 0xFFFF;
  pending_error = pending & _LDMA_IF_ERROR_MASK;

  if (pending_error) {
    // get channel that caused the error by checking CHERROR bitfield in status register LDMA->STATUS
    uint8_t error_channel = (LDMA->STATUS & _LDMA_STATUS_CHERROR_MASK) >> _LDMA_STATUS_CHERROR_SHIFT;
    // Set pending error for the channel
    sli_dma_manager_pending_errors[error_channel] = 1UL << error_channel;
    // Call the interrupt handler for the channel
    sli_dma_manager_interrupt_handler((uint32_t)LDMA, error_channel);
    return;
  }

  // Call the interrupt callback(s)
  while (pending_done) {
    uint8_t channel_nbr = 32 - __CLZ(pending_done) - 1;

    // Call the interrupt handler for the channel
    sli_dma_manager_interrupt_handler((uint32_t)LDMA, channel_nbr);

    SL_CLEAR_BIT(pending_done, SL_DEF_BIT(channel_nbr));
  }
}

#else

/***************************************************************************//**
 *  Generic interrupt handler for every LDMA channel.
 *
 * @param channel_nbr      The channel number to handle.
 ******************************************************************************/
static void ldma_irq_channel_handler(uint8_t channel_nbr)
{
  uint32_t pending;
  uint32_t pending_done;
  uint32_t pending_error;
  uint32_t channel_mask = (1 << channel_nbr);

  // Get all pending and enabled interrupts.
  pending = sl_hal_ldma_get_enabled_pending_interrupts(LDMA0);
  sl_hal_ldma_clear_interrupts(LDMA0, channel_mask | (channel_mask << 16));
  pending_done = pending & 0xFFFF;
  pending_error = (pending & 0xFFFF0000) >> 16;
#if defined(_LDMA_IFH_MASK)
  uint32_t pending_high = sl_hal_ldma_get_enabled_pending_high_interrupts(LDMA0);
  pending_done |= ((pending_high & 0xFFFF) << 16);
  pending_error |= (pending_high & 0xFFFF0000);
  sl_hal_ldma_clear_high_interrupts(LDMA0, channel_mask | (channel_mask >> 16));
#endif

  if (pending_error) {
    // Store pending error for the channel
    sli_dma_manager_pending_errors[channel_nbr] = pending_error & channel_mask;
    // Call the interrupt callback
    sli_dma_manager_interrupt_handler((uint32_t)LDMA0, channel_nbr);
    return;
  }

  if (pending_done & channel_mask) {
    // Call the interrupt callback
    sli_dma_manager_interrupt_handler((uint32_t)LDMA0, channel_nbr);
  }
}

/***************************************************************************//**
 *  Root interrupt handler for LDMA channel 0.
 ******************************************************************************/
static void ldma_irq_handler_channel0(void)
{
  ldma_irq_channel_handler(0);
}

/***************************************************************************//**
 *  Root interrupt handler for LDMA channel 1.
 ******************************************************************************/
static void ldma_irq_handler_channel1(void)
{
  ldma_irq_channel_handler(1);
}

/***************************************************************************//**
 *  Root interrupt handler for LDMA channel 2.
 ******************************************************************************/
static void ldma_irq_handler_channel2(void)
{
  ldma_irq_channel_handler(2);
}

/***************************************************************************//**
 *  Root interrupt handler for LDMA channel 3.
 ******************************************************************************/
static void ldma_irq_handler_channel3(void)
{
  ldma_irq_channel_handler(3);
}

/***************************************************************************//**
 *  Root interrupt handler for LDMA channel 4.
 ******************************************************************************/
static void ldma_irq_handler_channel4(void)
{
  ldma_irq_channel_handler(4);
}

/***************************************************************************//**
 *  Root interrupt handler for LDMA channel 5.
 ******************************************************************************/
static void ldma_irq_handler_channel5(void)
{
  ldma_irq_channel_handler(5);
}

/***************************************************************************//**
 *  Root interrupt handler for LDMA channel 6.
 ******************************************************************************/
static void ldma_irq_handler_channel6(void)
{
  ldma_irq_channel_handler(6);
}

/***************************************************************************//**
 *  Root interrupt handler for LDMA channel 7.
 ******************************************************************************/
static void ldma_irq_handler_channel7(void)
{
  ldma_irq_channel_handler(7);
}

#if (DMA_CHAN_COUNT > 8)
/***************************************************************************//**
 *  Root interrupt handler for LDMA channel 8.
 ******************************************************************************/
static void ldma_irq_handler_channel8(void)
{
  ldma_irq_channel_handler(8);
}
#endif

#if (DMA_CHAN_COUNT > 9)
/***************************************************************************//**
 *  Root interrupt handler for LDMA channel 9.
 ******************************************************************************/
static void ldma_irq_handler_channel9(void)
{
  ldma_irq_channel_handler(9);
}
#endif

#if (DMA_CHAN_COUNT > 10)
/***************************************************************************//**
 *  Root interrupt handler for LDMA channel 10.
 ******************************************************************************/
static void ldma_irq_handler_channel10(void)
{
  ldma_irq_channel_handler(10);
}
#endif

#if (DMA_CHAN_COUNT > 11)
/***************************************************************************//**
 *  Root interrupt handler for LDMA channel 11.
 ******************************************************************************/
static void ldma_irq_handler_channel11(void)
{
  ldma_irq_channel_handler(11);
}
#endif

#if (DMA_CHAN_COUNT > 12)
/***************************************************************************//**
 *  Root interrupt handler for LDMA channel 12.
 ******************************************************************************/
static void ldma_irq_handler_channel12(void)
{
  ldma_irq_channel_handler(12);
}
#endif

#if (DMA_CHAN_COUNT > 13)
/***************************************************************************//**
 *  Root interrupt handler for LDMA channel 13.
 ******************************************************************************/
static void ldma_irq_handler_channel13(void)
{
  ldma_irq_channel_handler(13);
}
#endif

#if (DMA_CHAN_COUNT > 14)
/***************************************************************************//**
 *  Root interrupt handler for LDMA channel 14.
 ******************************************************************************/
static void ldma_irq_handler_channel14(void)
{
  ldma_irq_channel_handler(14);
}
#endif

#if (DMA_CHAN_COUNT > 15)
/***************************************************************************//**
 *  Root interrupt handler for LDMA channel 15.
 ******************************************************************************/
static void ldma_irq_handler_channel15(void)
{
  ldma_irq_channel_handler(15);
}
#endif

#if (DMA_CHAN_COUNT > 16)
/***************************************************************************//**
 *  Root interrupt handler for LDMA channel 16.
 ******************************************************************************/
static void ldma_irq_handler_channel16(void)
{
  ldma_irq_channel_handler(16);
}
#endif

#if (DMA_CHAN_COUNT > 17)
/***************************************************************************//**
 *  Root interrupt handler for LDMA channel 17.
 ******************************************************************************/
static void ldma_irq_handler_channel17(void)
{
  ldma_irq_channel_handler(17);
}
#endif
#endif //_SILICON_LABS_32B_SERIES_2
