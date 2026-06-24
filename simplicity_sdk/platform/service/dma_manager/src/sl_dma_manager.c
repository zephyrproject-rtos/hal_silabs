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
#include "sl_enum.h"
#include "sl_core.h"
#include "sl_common.h"
#include "sl_bit.h"
#include "sl_dma_manager.h"
#include "sli_dma_manager_internal.h"
#include "sl_component_catalog.h"
#if defined(SL_CATALOG_DMA_MANAGER_ROUND_ROBIN_PRESENT)
#include "sl_dma_manager_round_robin_config.h"
#endif
#include "sl_device_peripheral.h"
#include "sl_memory_manager.h"

// -----------------------------------------------------------------------------
// GLOBAL VARIABLES

sl_slist_node_t* dma_handle_list = NULL;
sl_dma_handle_t* default_dma_handle;

static const sl_dma_handle_t *current_irq_dma_handle = NULL;
static uint8_t current_irq_channel_nbr = 0;

// -----------------------------------------------------------------------------
// FUNCTION DEFINITIONS

/***************************************************************************//**
 * Initializes the DMA manager.
 ******************************************************************************/
sl_status_t sl_dma_manager_init(sl_dma_handle_t *dma_handle,
                                sl_peripheral_dma_t dma_peripheral)
{
  CORE_DECLARE_IRQ_STATE;
  sl_dma_handle_t* handle;
  sl_dma_handle_t* saved_default_handle;
  sl_status_t status;
  bool handle_allocated = false;

  // If no DMA peripheral is specified, get the default one from the HAL
  if (dma_peripheral == NULL) {
    dma_peripheral = sli_dma_manager_hal_get_dma_peripheral();
    if (dma_peripheral == NULL) {
      return SL_STATUS_NOT_FOUND;
    }
  }

  if (dma_peripheral->nbr_channel >= 32) {
    // The DMA Manager only supports up to 32 channels due to the use of a 32-bit bitmap
    return SL_STATUS_NOT_SUPPORTED;
  }

  CORE_ENTER_ATOMIC();

  // Check if the dma handle is already initialized
  SL_SLIST_FOR_EACH_ENTRY(dma_handle_list, handle, sl_dma_handle_t, node) {
    if (handle == dma_handle) {
      // The same dma_handle is already in the list
      CORE_EXIT_ATOMIC();
      return SL_STATUS_ALREADY_INITIALIZED;
    }

    if (handle->dma_peripheral != dma_peripheral) {
      // Continue looping if the DMA Manager handle has a different DMA peripheral
      continue;
    }

    if (dma_handle == NULL) {
      // We already have a default DMA handle for this peripheral
      CORE_EXIT_ATOMIC();
      return SL_STATUS_ALREADY_INITIALIZED;
    }

    // Assert if another DMA Manager handle has the same DMA peripheral
    EFM_ASSERT(false);
    CORE_EXIT_ATOMIC();
    return SL_STATUS_INVALID_CONFIGURATION;
  }

  saved_default_handle = default_dma_handle;

  if (dma_handle == NULL) {
    // Allocate DMA handle if no handle is passed as argument
    status = sl_memory_alloc(sizeof(sl_dma_handle_t), BLOCK_TYPE_LONG_TERM, (void **)&default_dma_handle);
    if (status != SL_STATUS_OK) {
      CORE_EXIT_ATOMIC();
      return status;
    }
    dma_handle = default_dma_handle;
    handle_allocated = true;
  } else {
    // Set default DMA handle if not already set.
    if (default_dma_handle == NULL) {
      default_dma_handle = dma_handle;
    }
  }

  // Allocate the table for the interrupt callback function pointers
  status = sl_memory_calloc(dma_peripheral->nbr_channel,
                            sizeof(sl_dma_manager_channel_irq_callback_t),
                            BLOCK_TYPE_LONG_TERM,
                            (void **)&dma_handle->channel_irq_callbacks_table);
  if (status != SL_STATUS_OK) {
    if (handle_allocated) {
      sl_memory_free((void *)dma_handle);
    }
    default_dma_handle = saved_default_handle;
    CORE_EXIT_ATOMIC();
    return status;
  }

  // Allocate the table for the per-channel user data pointers
  status = sl_memory_calloc(dma_peripheral->nbr_channel,
                            sizeof(void *),
                            BLOCK_TYPE_LONG_TERM,
                            (void **)&dma_handle->channel_user_data_table);
  if (status != SL_STATUS_OK) {
    sl_memory_free((void *)dma_handle->channel_irq_callbacks_table);
    if (handle_allocated) {
      sl_memory_free((void *)dma_handle);
    }
    default_dma_handle = saved_default_handle;
    CORE_EXIT_ATOMIC();
    return status;
  }

  // Initialize DMA handle parameters
  dma_handle->dma_channels_bitmap = 0;
  dma_handle->round_robin_channel_number = 0;
  dma_handle->sync_bit_bitmap = 0;
  dma_handle->dma_peripheral = dma_peripheral;

  // Add DMA handle to the list
  sl_slist_push(&dma_handle_list, &dma_handle->node);

  // Initialize the DMA peripheral Hardware module
  sli_dma_manager_hal_init(dma_peripheral);

#if defined(SL_CATALOG_DMA_MANAGER_ROUND_ROBIN_PRESENT)
  EFM_ASSERT(SL_DMA_MANAGER_ROUND_ROBIN_CHANNEL_COUNT <= dma_peripheral->nbr_channel);
  dma_handle->round_robin_channel_number = SL_DMA_MANAGER_ROUND_ROBIN_CHANNEL_COUNT;
  sli_dma_manager_hal_configure_round_robin_channel_nbr(dma_peripheral, SL_DMA_MANAGER_ROUND_ROBIN_CHANNEL_COUNT);
#endif

  CORE_EXIT_ATOMIC();

  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Sets the number of round robin channels.
 ******************************************************************************/
#if defined(SL_CATALOG_DMA_MANAGER_ROUND_ROBIN_PRESENT)
sl_status_t sli_dma_manager_set_nbr_round_robin_channels(sl_dma_handle_t *dma_handle,
                                                         uint8_t nbr_round_robin_channels)
{
  CORE_DECLARE_IRQ_STATE;

  if (dma_handle == NULL) {
    dma_handle = default_dma_handle;
  }

  // Number of Round-Robin channels must be between 0 and the number of Channels
  if (nbr_round_robin_channels > dma_handle->dma_peripheral->nbr_channel) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  CORE_ENTER_ATOMIC();

  // Check that no channels have been allocated yet
  if (dma_handle->dma_channels_bitmap != 0) {
    CORE_EXIT_ATOMIC();
    return SL_STATUS_FAIL;
  }

  dma_handle->round_robin_channel_number = nbr_round_robin_channels;

  sli_dma_manager_hal_configure_round_robin_channel_nbr(dma_handle->dma_peripheral, nbr_round_robin_channels);

  CORE_EXIT_ATOMIC();

  return SL_STATUS_OK;
}
#endif

/***************************************************************************//**
 * Gets the default DMA handle.
 ******************************************************************************/
sl_status_t sl_dma_manager_get_default_handle(sl_dma_handle_t **dma_handle)
{
  if (dma_handle == NULL) {
    return SL_STATUS_NULL_POINTER;
  }

  *dma_handle = default_dma_handle;

  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Allocates a DMA channel.
 ******************************************************************************/
sl_status_t sl_dma_manager_allocate_channel(sl_dma_handle_t *dma_handle,
                                            uint8_t *channel_nbr)
{
#if !defined(SL_CATALOG_DMA_MANAGER_ROUND_ROBIN_PRESENT)
  CORE_DECLARE_IRQ_STATE;

  EFM_ASSERT(channel_nbr != NULL);

  // Fall back on the default DMA instance if no handle is provided
  if (dma_handle == NULL) {
    dma_handle = default_dma_handle;
  }

  CORE_ENTER_ATOMIC();

  // Create mask for valid channels
  uint32_t dma_channel_nbr_channel_mask = (1U << dma_handle->dma_peripheral->nbr_channel) - 1U;

  // Get available channels (inverted bitmap) and mask to valid channels only
  uint32_t available_channels = ~dma_handle->dma_channels_bitmap & dma_channel_nbr_channel_mask;

  // Check if we have any available channels
  if (available_channels == 0) {
    CORE_EXIT_ATOMIC();
    return SL_STATUS_NO_MORE_RESOURCE;
  }

  // Find highest set bit (lowest priority channel = highest channel number)
  uint8_t dma_channel_tmp = (uint8_t)(31U - __CLZ(available_channels));

  // Mark the channel as allocated
  // This shift operation is safe because dma_channel_tmp is guaranteed to be less than 32
  // with the previous check.
  dma_handle->dma_channels_bitmap |= (1U << dma_channel_tmp);

  // Return channel value
  *channel_nbr = dma_channel_tmp;

  CORE_EXIT_ATOMIC();

  return SL_STATUS_OK;
#else
  return sl_dma_manager_allocate_channel_with_properties(dma_handle, 0, channel_nbr);
#endif
}

/***************************************************************************//**
 * Allocates a DMA channel. This function allows to describe desired properties
 * and features for the allocated channel.
 ******************************************************************************/
sl_status_t sl_dma_manager_allocate_channel_with_properties(sl_dma_handle_t *dma_handle,
                                                            uint32_t channel_properties,
                                                            uint8_t *channel_nbr)
{
  CORE_DECLARE_IRQ_STATE;

  EFM_ASSERT(channel_nbr != NULL);

  // Cannot have both High Priority and Round Robin properties
  EFM_ASSERT(!((channel_properties & (SL_DMA_CHANNEL_HIGH_PRIORITY | SL_DMA_CHANNEL_USES_ROUND_ROBIN))
               == (SL_DMA_CHANNEL_HIGH_PRIORITY | SL_DMA_CHANNEL_USES_ROUND_ROBIN)));

#if !defined(SL_CATALOG_DMA_MANAGER_ROUND_ROBIN_PRESENT)
  // Assert if Round Robin channels are not enabled but requested
  EFM_ASSERT((channel_properties & SL_DMA_CHANNEL_USES_ROUND_ROBIN) == 0);
#endif

  // Fall back on the default DMA instance if no handle is provided
  if (dma_handle == NULL) {
    dma_handle = default_dma_handle;
  }

  CORE_ENTER_ATOMIC();

  // The DMA Manager only supports up to 32 channels due to the use of a 32-bit bitmap.
  // Add check here, before doing a bitshift operations on a 32-bit variable.
  EFM_ASSERT((dma_handle->dma_peripheral->nbr_channel < 32));

  // Retrieve the first available dma channel from the DMA bitmask.
  // This will give us the available channel with the highest priority.
  uint32_t dma_channel_nbr_channel_mask = (1 << dma_handle->dma_peripheral->nbr_channel) - 1;
  uint8_t dma_channel_tmp = (uint8_t)SL_CTZ(~(dma_handle->dma_channels_bitmap | ~dma_channel_nbr_channel_mask));

  // Check if we have any available channels
  if (dma_channel_tmp >= dma_handle->dma_peripheral->nbr_channel) {
    CORE_EXIT_ATOMIC();
    return SL_STATUS_NO_MORE_RESOURCE;
  }

  if ((channel_properties & SL_DMA_CHANNEL_SUPPORTS_INTERLEAVING)
      && (SL_IS_BIT_CLEAR(dma_handle->dma_peripheral->rule_based_interleaving_map, SL_DEF_BIT(dma_channel_tmp)))) {
    // Return if no Interleaving channel is available
    CORE_EXIT_ATOMIC();
    return SL_STATUS_NO_MORE_RESOURCE;
  }

  if ((channel_properties & SL_DMA_CHANNEL_SUPPORTS_DUAL_DESTINATION)
      && (SL_IS_BIT_CLEAR(dma_handle->dma_peripheral->dual_destination_map, SL_DEF_BIT(dma_channel_tmp)))) {
    // Return if no Dual Destination channel is available
    CORE_EXIT_ATOMIC();
    return SL_STATUS_NO_MORE_RESOURCE;
  }

  // Find an available Round Robin Channel if Round-Robin is requested
  // or find the lowest priority channel available in case no Round Robin channels are available
  // or no channel properties are specified
  // If all channels are round-robin, we already found a good channel candidate and can skip this.
  if ((channel_properties == 0
       || channel_properties & SL_DMA_CHANNEL_USES_ROUND_ROBIN)
      && (dma_handle->dma_peripheral->nbr_channel != dma_handle->round_robin_channel_number)) {
    // Get the lowest priority channel that is not Round-Robin
    uint8_t lowest_priority_channel = (dma_handle->dma_peripheral->nbr_channel - dma_handle->round_robin_channel_number) - 1;
    if (dma_channel_tmp <= lowest_priority_channel) {
      uint32_t round_robin_channels_mask = ((1U << dma_handle->round_robin_channel_number) - 1U) << (dma_handle->dma_peripheral->nbr_channel - dma_handle->round_robin_channel_number);
      // If the current found channel is inside the priority range, we need to check if any channels are available in
      // the round-robin range when round-robin channel is requested.
      if ((channel_properties & SL_DMA_CHANNEL_USES_ROUND_ROBIN) != 0
          && (dma_handle->round_robin_channel_number != 0)) {
        // Find the first available Round-Robin channel
        uint8_t rr_channel = (uint8_t)SL_CTZ(~(dma_handle->dma_channels_bitmap | ~round_robin_channels_mask));
        if (rr_channel < dma_handle->dma_peripheral->nbr_channel) {
          dma_channel_tmp = rr_channel;
        }
      }
      // If not round-robin channels are left or if no channel properties were specified,
      // we need to find the lowest priority channel available.
      if (dma_channel_tmp < lowest_priority_channel) {
        dma_channel_tmp = 31 - __CLZ(~dma_handle->dma_channels_bitmap & (~round_robin_channels_mask & dma_channel_nbr_channel_mask));
      }
    }
  }

  // It should be guaranteed by the previous checks that dma_channel_tmp is less than 32.
  // Add a check here to be sure.
  EFM_ASSERT((dma_channel_tmp < 32));

  // Mark the channel as allocated
  // This shift operation is safe because dma_channel_tmp is guaranteed to be less than 32
  // with the previous check.
  dma_handle->dma_channels_bitmap |= (1U << dma_channel_tmp);

  // Return channel value
  *channel_nbr = dma_channel_tmp;

  CORE_EXIT_ATOMIC();
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Reserves a specific channel.
 ******************************************************************************/
sl_status_t sl_dma_manager_reserve_channel(sl_dma_handle_t *dma_handle,
                                           uint8_t channel_nbr)
{
  CORE_DECLARE_IRQ_STATE;

  // Fall back on the default DMA instance if no handle is provided
  if (dma_handle == NULL) {
    dma_handle = default_dma_handle;
  }

  // Check if the channel number is valid
  if (channel_nbr >= dma_handle->dma_peripheral->nbr_channel) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  CORE_ENTER_ATOMIC();

  // Check if the channel is already reserved
  if ((dma_handle->dma_channels_bitmap & (1U << channel_nbr)) != 0) {
    CORE_EXIT_ATOMIC();
    return SL_STATUS_NOT_AVAILABLE;
  }

  // Mark the channel as reserved
  dma_handle->dma_channels_bitmap |= (1U << channel_nbr);

  CORE_EXIT_ATOMIC();
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Frees a previously allocated/reserved channel.
 ******************************************************************************/
sl_status_t sl_dma_manager_free_channel(sl_dma_handle_t *dma_handle,
                                        uint8_t channel_nbr)
{
  CORE_DECLARE_IRQ_STATE;

  // Fall back on the default DMA instance if no handle is provided
  if (dma_handle == NULL) {
    dma_handle = default_dma_handle;
  }

  // Check if the channel number is valid
  if (channel_nbr >= dma_handle->dma_peripheral->nbr_channel) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  CORE_ENTER_ATOMIC();

  // Mark the channel as free
  dma_handle->dma_channels_bitmap &= ~(1U << channel_nbr);

  // Clear associated callback and user data
  dma_handle->channel_irq_callbacks_table[channel_nbr] = NULL;
  dma_handle->channel_user_data_table[channel_nbr] = NULL;

  CORE_EXIT_ATOMIC();
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Allocates a SYNC bit/channel.
 ******************************************************************************/
sl_status_t sl_dma_manager_allocate_sync(sl_dma_handle_t *dma_handle,
                                         uint8_t *sync_nbr)
{
  CORE_DECLARE_IRQ_STATE;

  EFM_ASSERT(sync_nbr != NULL);

  // Fall back on the default DMA instance if no handle is provided
  if (dma_handle == NULL) {
    dma_handle = default_dma_handle;
  }

  CORE_ENTER_ATOMIC();

  // Find first zero bit in bitmap (first available SYNC bit)
  uint8_t sync_bit_tmp = (uint8_t)SL_CTZ(~dma_handle->sync_bit_bitmap);

  // Check if we have any available SYNC bit
  if (sync_bit_tmp >= dma_handle->dma_peripheral->nbr_sync) {
    CORE_EXIT_ATOMIC();
    return SL_STATUS_NO_MORE_RESOURCE;
  }

  // Mark the SYNC bit as allocated
  dma_handle->sync_bit_bitmap |= (1U << sync_bit_tmp);

  *sync_nbr = sync_bit_tmp;

  CORE_EXIT_ATOMIC();
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Frees a previously allocated SYNC bit/channel.
 ******************************************************************************/
sl_status_t sl_dma_manager_free_sync(sl_dma_handle_t *dma_handle,
                                     uint8_t sync_nbr)
{
  CORE_DECLARE_IRQ_STATE;

  // Fall back on the default DMA instance if no handle is provided
  if (dma_handle == NULL) {
    dma_handle = default_dma_handle;
  }

  if (sync_nbr >= dma_handle->dma_peripheral->nbr_sync) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  CORE_ENTER_ATOMIC();

  // Mark the SYNC bit as free
  dma_handle->sync_bit_bitmap &= ~(1U << sync_nbr);

  CORE_EXIT_ATOMIC();
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Registers an IRQ callback.
 ******************************************************************************/
sl_status_t sl_dma_manager_register_channel_irq_callback(sl_dma_handle_t *dma_handle,
                                                         uint8_t channel_nbr,
                                                         sl_dma_manager_channel_irq_callback_t callback)
{
  CORE_DECLARE_IRQ_STATE;

  // Fall back on the default DMA instance if no handle is provided
  if (dma_handle == NULL) {
    dma_handle = default_dma_handle;
  }

  if (channel_nbr >= dma_handle->dma_peripheral->nbr_channel) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  CORE_ENTER_ATOMIC();

  // Store the callback
  dma_handle->channel_irq_callbacks_table[channel_nbr] = callback;

#if defined(_SILICON_LABS_32B_SERIES_3)
  // Configure the IRQ for the channel in case we have an IRQ line per channel
  if (callback != NULL) {
    sli_dma_manager_hal_configure_channel_irq(channel_nbr);
  }
#endif

  CORE_EXIT_ATOMIC();

  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Registers user data for a specific DMA channel.
 ******************************************************************************/
sl_status_t sl_dma_manager_register_channel_user_data(sl_dma_handle_t *dma_handle,
                                                      uint8_t channel_nbr,
                                                      void *user_data)
{
  CORE_DECLARE_IRQ_STATE;

  // Fall back on the default DMA instance if no handle is provided
  if (dma_handle == NULL) {
    dma_handle = default_dma_handle;
  }

  if (channel_nbr >= dma_handle->dma_peripheral->nbr_channel) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  CORE_ENTER_ATOMIC();

  dma_handle->channel_user_data_table[channel_nbr] = user_data;

  CORE_EXIT_ATOMIC();

  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Retrieves the user data and channel number for the DMA channel currently
 * being serviced in the interrupt dispatch context.
 ******************************************************************************/
sl_status_t sl_dma_manager_retrieve_current_channel_user_data(uint8_t *channel_nbr,
                                                              void **user_data)
{
  if (channel_nbr == NULL || user_data == NULL) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  if (current_irq_dma_handle == NULL) {
    return SL_STATUS_INVALID_STATE;
  }

  *channel_nbr = current_irq_channel_nbr;
  *user_data = current_irq_dma_handle->channel_user_data_table[current_irq_channel_nbr];

  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Interrupt handler to call channel IRQ callbacks.
 ******************************************************************************/
void sli_dma_manager_interrupt_handler(uint32_t peripheral_base_addr, uint8_t channel_nbr)
{
  CORE_DECLARE_IRQ_STATE;
  sl_dma_handle_t const *dma_handle = NULL;
  sl_dma_handle_t *handle;

  CORE_ENTER_ATOMIC();

  // Found the DMA Handle associated with the peripheral base address
  SL_SLIST_FOR_EACH_ENTRY(dma_handle_list, handle, sl_dma_handle_t, node) {
    if (handle->dma_peripheral->base == peripheral_base_addr) {
      dma_handle = handle;
      break;
    }
  }

  if (dma_handle == NULL) {
    // Handle error: DMA handle not found
    CORE_EXIT_ATOMIC();
    return;
  }

  // Validate that the DMA channel number is valid
  EFM_ASSERT(channel_nbr < dma_handle->dma_peripheral->nbr_channel);

  // Set the current IRQ context so that the callback can retrieve
  // the channel number and user data via
  // sl_dma_manager_retrieve_current_channel_user_data().
  current_irq_dma_handle = dma_handle;
  current_irq_channel_nbr = channel_nbr;

  // Check if we have an interrupt callback for this DMA channel
  // and call the function
  if (dma_handle->channel_irq_callbacks_table[channel_nbr] != NULL) {
    dma_handle->channel_irq_callbacks_table[channel_nbr]();
  }

  current_irq_dma_handle = NULL;

  CORE_EXIT_ATOMIC();
}

/***************************************************************************//**
 *  Get the pending errors for the DMA manager.
 *  This function retrieves the current pending errors.
 ******************************************************************************/
uint32_t sl_dma_manager_get_pending_errors(uint8_t channel_nbr)
{
  return sli_dma_manager_hal_get_pending_errors(channel_nbr);
}

/***************************************************************************//**
 *  Clear the pending errors for the DMA manager.
 *  This function clears the pending error flag for the specified channel.
 *  It is idempotent and safe to call multiple times.
 *
 * @param[in]  channel_nbr Channel number.
 ******************************************************************************/
void sl_dma_manager_clear_pending_errors(uint8_t channel_nbr)
{
  sli_dma_manager_hal_clear_pending_errors(channel_nbr);
}

/***************************************************************************//**
 *  Latch a pending error bitmap for the DMA manager.
 *  Forwards to the HAL implementation.
 ******************************************************************************/
void sli_dma_manager_set_pending_errors(uint8_t channel_nbr, uint32_t errors)
{
  sli_dma_manager_hal_set_pending_errors(channel_nbr, errors);
}
