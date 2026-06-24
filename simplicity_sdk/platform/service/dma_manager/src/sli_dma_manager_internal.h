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
#include "sl_component_catalog.h"
#include "sl_dma_manager.h"
#include "sl_code_classification.h"

// -----------------------------------------------------------------------------
// HAL FUNCTION PROTOTYPES

/***************************************************************************//**
 * Initializes the LDMA peripheral for the DMA Manager.
 *
 * @param[in]  dma_peripheral Pointer to DMA peripheral.
 ******************************************************************************/
void sli_dma_manager_hal_init(const sl_peripheral_dma_t dma_peripheral);

#if defined(SL_CATALOG_DMA_MANAGER_ROUND_ROBIN_PRESENT)
/***************************************************************************//**
 * Sets the number of round robin channels in LDMA Hardware instance.
 *
 * @param[in]  dma_peripheral Pointer to DMA peripheral.
 *
 * @param[in]  nbr_round_robin_channels Number of round robin channels.
 *
 * @note By default, all channels are fixed priorities (no round-robin).
 ******************************************************************************/
void sli_dma_manager_hal_configure_round_robin_channel_nbr(const sl_peripheral_dma_t dma_peripheral,
                                                           uint8_t nbr_round_robin_channels);

/***************************************************************************//**
 * Sets the number of round robin channels.
 *
 * @param[in]  dma_handle Pointer to DMA handle. NULL will take the default
 *                        DMA instance.
 *
 * @param[in]  nbr_round_robin_channels Number of round robin channels.
 *
 * @return 0 if successful. Error code otherwise.
 *
 * @note Called automatically by sl_dma_manager_init() using the configured
 *       SL_DMA_MANAGER_ROUND_ROBIN_CHANNEL_COUNT value.
 *
 * @note Must be called before any channel is allocated.
 ******************************************************************************/
sl_status_t sli_dma_manager_set_nbr_round_robin_channels(sl_dma_handle_t *dma_handle,
                                                         uint8_t nbr_round_robin_channels);
#endif

/***************************************************************************//**
 * Gets the DMA peripheral object for the current device.
 *
 * @return Peripheral object for the current device, if only one exists.
 *         NULL otherwise.
 ******************************************************************************/
sl_peripheral_dma_t sli_dma_manager_hal_get_dma_peripheral(void);

/***************************************************************************//**
 * Configuration related the a specific channel Interrupt.
 *
 * @param[in]  channel_nbr Channel number.
 ******************************************************************************/
void sli_dma_manager_hal_configure_channel_irq(uint8_t channel_nbr);

// -----------------------------------------------------------------------------
// INTERNAL FUNCTION PROTOTYPES

/***************************************************************************//**
 * Interrupt handler to call channel IRQ callbacks.
 *
 * @param[in]  peripheral_base_addr Base address of the peripheral.
 *
 * @param[in]  channel_nbr Channel number.
 ******************************************************************************/
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
void sli_dma_manager_interrupt_handler(uint32_t peripheral_base_addr, uint8_t channel_nbr);

/***************************************************************************//**
 *  Get the pending errors for the DMA manager.
 *  This function retrieves the current pending errors.
 *  @param[in]  channel_nbr Channel number.
 *  @return The pending errors bitmap.
 ******************************************************************************/
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
uint32_t sli_dma_manager_hal_get_pending_errors(uint8_t channel_nbr);

/***************************************************************************//**
 *  Clear the pending errors for the DMA manager.
 *  This function clears the pending error flag for the specified channel.
 *  It is idempotent and safe to call multiple times.
 *
 * @param[in]  channel_nbr Channel number.
 ******************************************************************************/
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
void sli_dma_manager_hal_clear_pending_errors(uint8_t channel_nbr);

/***************************************************************************//**
 *  Latch a pending error bitmap for the DMA manager.
 *
 *  Used by callers that detect a DMA channel error outside of the regular IRQ
 *  dispatch path (for example, when polling channel completion while the DMA
 *  IRQ is masked) and need the next call to the DMA Channel Driver to consume
 *  the error and invoke abort callbacks.
 *
 * @param[in]  channel_nbr Channel number.
 * @param[in]  errors      Error bitmap to latch (typically @p (1U << channel_nbr)).
 ******************************************************************************/
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
void sli_dma_manager_hal_set_pending_errors(uint8_t channel_nbr, uint32_t errors);

/***************************************************************************//**
 *  Latch a pending error bitmap for the DMA manager.
 *
 *  Public-internal forwarder around @ref sli_dma_manager_hal_set_pending_errors.
 *
 * @param[in]  channel_nbr Channel number.
 * @param[in]  errors      Error bitmap to latch (typically @p (1U << channel_nbr)).
 ******************************************************************************/
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
void sli_dma_manager_set_pending_errors(uint8_t channel_nbr, uint32_t errors);
