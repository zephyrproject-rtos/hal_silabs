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

/***************************************************************************//**
 * @addtogroup dma_manager DMA Manager
 * @details
 * ## Overview
 *
 * The DMA Manager is a platform service module responsible for initializing
 * and enabling the DMA peripheral(s) on the device, managing DMA interrupts,
 * configuring channel prioritization (for example round-robin arbitration),
 * and dynamically allocating DMA channels and sync bits at runtime.
 *
 * Each DMA peripheral managed by the DMA Manager is associated with an
 * ::sl_dma_handle_t variable. A default handle is provided and can be
 * retrieved through sl_dma_manager_get_default_handle().
 *
 * The DMA Manager is the single entry point for DMA channel ownership: any
 * application or driver that needs a DMA channel must request it from the DMA
 * Manager rather than touching the DMA peripheral directly. Once a channel has
 * been allocated, the application is free to drive transfers on it through the
 * DMA Channel Driver (its companion higher-level API) or directly through the
 * low level sl_hal_ldma HAL, depending on the level of control needed. In
 * either case the channel itself must always come from the DMA Manager.
 *
 * ## Initialization
 *
 * When the `dma_manager_init` component is included in the project, all
 * configured DMA peripheral instances are initialized automatically during system
 * initialization through sl_dma_manager_instances_init(). Applications that do
 * not use the SL Main component to auto-init can call sl_dma_manager_init() directly,
 * passing either a user-allocated handle or NULL to let the DMA Manager
 * allocate one internally.
 *
 * The following snippet shows a manual initialization of the default DMA
 * peripheral exposed by the HAL, with a caller-allocated handle:
 * @code{.c}
 * static sl_dma_handle_t my_dma_handle;
 * sl_status_t status;
 *
 * // Pass NULL as DMA peripheral to use the device's default DMA peripheral.
 * status = sl_dma_manager_init(&my_dma_handle, NULL);
 * if (status != SL_STATUS_OK) {
 *   // Process the error condition.
 * }
 * @endcode
 *
 * ## Examples
 *
 * ### Channel Allocation and Release
 *
 * The most common pattern is to allocate a channel from the default DMA
 * Manager handle, use it, and release it once the transfer is done. Passing
 * NULL as the DMA handle automatically targets the default handle of the
 * default DMA peripheral:
 * @code{.c}
 * uint8_t channel_nbr;
 * sl_status_t status;
 *
 * status = sl_dma_manager_allocate_channel(NULL, &channel_nbr);
 * if (status != SL_STATUS_OK) {
 *   // Process the error condition (for example SL_STATUS_NO_MORE_RESOURCE).
 * }
 *
 * // Use the channel, e.g. through the DMA Channel Driver or sl_hal_ldma.
 * // ...
 *
 * status = sl_dma_manager_free_channel(NULL, channel_nbr);
 * if (status != SL_STATUS_OK) {
 *   // Process the error condition.
 * }
 * @endcode
 *
 * If the application needs to operate on an explicit handle (for example to
 * query or share it with another module), the default handle can be retrieved
 * with sl_dma_manager_get_default_handle():
 * @code{.c}
 * sl_dma_handle_t *dma_handle = NULL;
 * uint8_t channel_nbr;
 * sl_status_t status;
 *
 * status = sl_dma_manager_get_default_handle(&dma_handle);
 * if (status != SL_STATUS_OK || dma_handle == NULL) {
 *   // Process the error condition (no default handle initialized yet).
 * }
 *
 * status = sl_dma_manager_allocate_channel(dma_handle, &channel_nbr);
 * if (status != SL_STATUS_OK) {
 *   // Process the error condition.
 * }
 *
 * // ... use the channel ...
 *
 * sl_dma_manager_free_channel(dma_handle, channel_nbr);
 * @endcode
 *
 * ### Channel Allocation with Properties
 *
 * sl_dma_manager_allocate_channel_with_properties() lets the caller request
 * specific channel features. The example below requests a high-priority
 * channel that supports interleaved transfers:
 * @code{.c}
 * uint8_t channel_nbr;
 * uint32_t properties = SL_DMA_CHANNEL_HIGH_PRIORITY
 *                     | SL_DMA_CHANNEL_SUPPORTS_INTERLEAVING;
 * sl_status_t status;
 *
 * status = sl_dma_manager_allocate_channel_with_properties(NULL,
 *                                                          properties,
 *                                                          &channel_nbr);
 * if (status != SL_STATUS_OK) {
 *   // No channel matching the requested properties is available.
 * }
 * @endcode
 *
 * Note that ::SL_DMA_CHANNEL_HIGH_PRIORITY and
 * ::SL_DMA_CHANNEL_USES_ROUND_ROBIN are mutually exclusive.
 *
 * ### Reserving a Specific Channel
 *
 * When a deterministic channel number is required (for example to match a
 * fixed peripheral signal mapping), sl_dma_manager_reserve_channel() locks a
 * specific channel out of the dynamic allocation pool. The channel is
 * released with the same sl_dma_manager_free_channel() call as an allocated
 * channel:
 * @code{.c}
 * sl_status_t status;
 *
 * status = sl_dma_manager_reserve_channel(NULL, 3);
 * if (status == SL_STATUS_NOT_AVAILABLE) {
 *   // Channel 3 is already reserved or allocated by someone else.
 * } else if (status != SL_STATUS_OK) {
 *   // Process the error condition.
 * }
 *
 * // ... use channel 3 ...
 *
 * sl_dma_manager_free_channel(NULL, 3);
 * @endcode
 *
 * ### SYNC Bit Allocation
 *
 * SYNC bits used to synchronize DMA channels with peripheral or software
 * events are managed the same way as channels:
 * @code{.c}
 * uint8_t sync_nbr;
 * sl_status_t status;
 *
 * status = sl_dma_manager_allocate_sync(NULL, &sync_nbr);
 * if (status != SL_STATUS_OK) {
 *   // Process the error condition (for example SL_STATUS_NO_MORE_RESOURCE).
 * }
 *
 * // ... use the SYNC bit ...
 *
 * sl_dma_manager_free_sync(NULL, sync_nbr);
 * @endcode
 *
 * ### IRQ Callback and User Data
 *
 * When driving a channel directly through the sl_hal_ldma HAL, the
 * application can register a per-channel IRQ callback so the DMA Manager
 * dispatches the IRQ to it on Series 2 (and forwards the registration to the
 * Interrupt Manager on Series 3). A user-data pointer can be associated with
 * the channel and retrieved from inside the callback through
 * sl_dma_manager_retrieve_current_channel_user_data():
 * @code{.c}
 * static volatile bool transfer_done;
 *
 * static void my_dma_irq_callback(void)
 * {
 *   uint8_t channel_nbr;
 *   void *user_data;
 *
 *   if (sl_dma_manager_retrieve_current_channel_user_data(&channel_nbr,
 *                                                         &user_data)
 *       == SL_STATUS_OK) {
 *     // 'user_data' is the pointer registered for 'channel_nbr'.
 *     *((volatile bool *)user_data) = true;
 *   }
 * }
 *
 * void start_dma_transfer(void)
 * {
 *   uint8_t channel_nbr;
 *
 *   sl_dma_manager_allocate_channel(NULL, &channel_nbr);
 *   sl_dma_manager_register_channel_user_data(NULL,
 *                                             channel_nbr,
 *                                             (void *)&transfer_done);
 *   sl_dma_manager_register_channel_irq_callback(NULL,
 *                                                channel_nbr,
 *                                                my_dma_irq_callback);
 *
 *   // Configure and start the transfer through sl_hal_ldma.
 *   // ...
 * }
 * @endcode
 *
 * The DMA Channel Driver registers and dispatches its own per-channel
 * callbacks; this flow is therefore only needed for users that drive the
 * channel directly through the sl_hal_ldma HAL.
 *
 * @{
 ******************************************************************************/

#ifndef SL_DMA_MANAGER_H
#define SL_DMA_MANAGER_H

#include <stdbool.h>
#include <stdlib.h>
#include "sl_status.h"
#include "sl_slist.h"
#include "sl_device_peripheral.h"
#include "sl_code_classification.h"

#ifdef __cplusplus
extern "C" {
#endif

// -----------------------------------------------------------------------------
// DEFINES

#define SL_DMA_CHANNEL_HIGH_PRIORITY                (1 << 0)
#define SL_DMA_CHANNEL_USES_ROUND_ROBIN             (1 << 1)
#define SL_DMA_CHANNEL_SUPPORTS_INTERLEAVING        (1 << 2)
#define SL_DMA_CHANNEL_SUPPORTS_DUAL_DESTINATION    (1 << 3)

// -----------------------------------------------------------------------------
// TYPE DEFINITIONS

typedef struct sl_dma_handle sl_dma_handle_t;

typedef void (*sl_dma_manager_channel_irq_callback_t)(void);

/// A DMA Manager instance handle data structure.
/// A handle is associated with a single DMA peripheral instance, and only one
/// handle can be associated with a given DMA peripheral instance at a time.
/// The handle can be allocated either by the application or by the DMA Manager.
/// The application must not modify the contents of this handle and should not
/// depend on its values.
struct sl_dma_handle {
  /// @cond DO_NOT_INCLUDE_WITH_DOXYGEN
  sl_peripheral_dma_t dma_peripheral;  ///< DMA peripheral.
  uint32_t dma_channels_bitmap;        ///< Bitmap of allocated channels.
  uint32_t sync_bit_bitmap;            ///< Bitmap of allocated sync bits.
  uint8_t  round_robin_channel_number; ///< Number of round robin channels.
  sl_dma_manager_channel_irq_callback_t* channel_irq_callbacks_table; ///< Table of IRQ callbacks per channel.
  void** channel_user_data_table;      ///< Table of user data pointers per channel.
  sl_slist_node_t node;                ///< Linked list node for DMA handle management.
  /// @endcond
};

// -----------------------------------------------------------------------------
// PROTOTYPES

/***************************************************************************//**
 * Initializes the DMA Manager for a given DMA peripheral.
 *
 * @param[in]  dma_handle      Pointer to a caller-allocated DMA handle to
 *                             initialize. If NULL, the DMA Manager allocates
 *                             the handle internally and uses it as the default
 *                             handle for the targeted DMA peripheral.
 *
 * @param[in]  dma_peripheral  DMA peripheral to associate with the handle.
 *                             If NULL, the default DMA peripheral exposed by
 *                             the HAL is used.
 *
 * @return 0 (SL_STATUS_OK) if successful. Error code otherwise.
 ******************************************************************************/
sl_status_t sl_dma_manager_init(sl_dma_handle_t *dma_handle,
                                sl_peripheral_dma_t dma_peripheral);

/***************************************************************************//**
 * Gets the default DMA handle.
 *
 * @param[out] dma_handle  Address of a variable that will receive the default
 *                         DMA handle. Must not be NULL. The variable is set to
 *                         NULL if no default handle has been initialized yet.
 *
 * @return 0 (SL_STATUS_OK) if successful. Error code otherwise.
 ******************************************************************************/
sl_status_t sl_dma_manager_get_default_handle(sl_dma_handle_t **dma_handle);

/***************************************************************************//**
 * Allocates a DMA channel.
 *
 * Selects the next available channel from the targeted DMA peripheral and
 * marks it as allocated. When the round-robin component is enabled, this
 * function delegates to sl_dma_manager_allocate_channel_with_properties()
 * with no requested properties; the lowest priority non round-robin channel
 * available is then returned.
 *
 * @param[in]  dma_handle   Pointer to the DMA handle to allocate from.
 *                          If NULL, the default handle is used.
 *
 * @param[out] channel_nbr  Pointer to a variable that will receive the
 *                          allocated channel number. Must not be NULL.
 *
 * @return 0 (SL_STATUS_OK) if successful. Error code otherwise.
 ******************************************************************************/
sl_status_t sl_dma_manager_allocate_channel(sl_dma_handle_t *dma_handle,
                                            uint8_t *channel_nbr);

/***************************************************************************//**
 * Allocates a DMA channel with the requested properties.
 *
 * Same as sl_dma_manager_allocate_channel() but lets the caller request
 * specific channel features.
 *
 * @param[in]  dma_handle          Pointer to the DMA handle to allocate from.
 *                                 If NULL, the default handle is used.
 *
 * @param[in]  channel_properties  Bitwise OR of the desired channel
 *                                 properties:
 *                                   - ::SL_DMA_CHANNEL_HIGH_PRIORITY
 *                                   - ::SL_DMA_CHANNEL_USES_ROUND_ROBIN
 *                                   - ::SL_DMA_CHANNEL_SUPPORTS_INTERLEAVING
 *                                   - ::SL_DMA_CHANNEL_SUPPORTS_DUAL_DESTINATION
 *
 *                                 ::SL_DMA_CHANNEL_HIGH_PRIORITY and
 *                                 ::SL_DMA_CHANNEL_USES_ROUND_ROBIN are
 *                                 mutually exclusive.
 *
 * @param[out] channel_nbr         Pointer to a variable that will receive the
 *                                 allocated channel number. Must not be NULL.
 *
 * @return 0 (SL_STATUS_OK) if successful. Error code otherwise.
 ******************************************************************************/
sl_status_t sl_dma_manager_allocate_channel_with_properties(sl_dma_handle_t *dma_handle,
                                                            uint32_t channel_properties,
                                                            uint8_t *channel_nbr);

/***************************************************************************//**
 * Reserves a specific DMA channel.
 *
 * Reserves the channel identified by @p channel_nbr so that subsequent
 * allocations through sl_dma_manager_allocate_channel() or
 * sl_dma_manager_allocate_channel_with_properties() will not return it.
 *
 * @param[in]  dma_handle   Pointer to the DMA handle. If NULL, the default
 *                          handle is used.
 *
 * @param[in]  channel_nbr  Channel number to reserve.
 *
 * @return 0 (SL_STATUS_OK) if successful. Error code otherwise.
 *         SL_STATUS_NOT_AVAILABLE is returned when the channel is already
 *         reserved or allocated.
 ******************************************************************************/
sl_status_t sl_dma_manager_reserve_channel(sl_dma_handle_t *dma_handle,
                                           uint8_t channel_nbr);

/***************************************************************************//**
 * Frees a previously allocated or reserved DMA channel.
 *
 * Releases the channel back to the DMA Manager and clears its associated IRQ
 * callback and user data, if any.
 *
 * @param[in]  dma_handle   Pointer to the DMA handle. If NULL, the default
 *                          handle is used.
 *
 * @param[in]  channel_nbr  Channel number to free.
 *
 * @return 0 (SL_STATUS_OK) if successful. Error code otherwise.
 ******************************************************************************/
sl_status_t sl_dma_manager_free_channel(sl_dma_handle_t *dma_handle,
                                        uint8_t channel_nbr);

/***************************************************************************//**
 * Allocates a DMA SYNC bit.
 *
 * @param[in]  dma_handle  Pointer to the DMA handle. If NULL, the default
 *                         handle is used.
 *
 * @param[out] sync_nbr    Pointer to a variable that will receive the
 *                         allocated SYNC bit number. Must not be NULL.
 *
 * @return 0 (SL_STATUS_OK) if successful. Error code otherwise.
 ******************************************************************************/
sl_status_t sl_dma_manager_allocate_sync(sl_dma_handle_t *dma_handle,
                                         uint8_t *sync_nbr);

/***************************************************************************//**
 * Frees a previously allocated DMA SYNC bit.
 *
 * @param[in]  dma_handle  Pointer to the DMA handle. If NULL, the default
 *                         handle is used.
 *
 * @param[in]  sync_nbr    SYNC bit number to free.
 *
 * @return 0 (SL_STATUS_OK) if successful. Error code otherwise.
 ******************************************************************************/
sl_status_t sl_dma_manager_free_sync(sl_dma_handle_t *dma_handle,
                                     uint8_t sync_nbr);

/***************************************************************************//**
 * Registers an IRQ callback for a DMA channel.
 *
 * @param[in]  dma_handle   Pointer to the DMA handle. If NULL, the default
 *                          handle is used.
 *
 * @param[in]  channel_nbr  Channel number the callback is registered for.
 *
 * @param[in]  callback     Function to be invoked from the DMA channel IRQ
 *                          context. Pass NULL to remove a previously
 *                          registered callback.
 *
 * @return 0 (SL_STATUS_OK) if successful. Error code otherwise.
 *
 * @note On Series 2 devices, all DMA channels share a single IRQ line and the
 *       DMA Manager owns the central IRQ dispatcher; callbacks must therefore
 *       be registered through this function. On Series 3 devices, each
 *       channel has its own IRQ line and callbacks should normally be
 *       registered directly through the Interrupt Manager. Calling this
 *       function on Series 3 simply forwards the registration to the
 *       Interrupt Manager.
 *
 * @note This function is intended for users that drive the DMA channel
 *       directly through the sl_hal_ldma HAL. The DMA Channel Driver
 *       registers and dispatches its own per-channel callbacks and does not
 *       require this function.
 ******************************************************************************/
sl_status_t sl_dma_manager_register_channel_irq_callback(sl_dma_handle_t *dma_handle,
                                                         uint8_t channel_nbr,
                                                         sl_dma_manager_channel_irq_callback_t callback);

/***************************************************************************//**
 * Registers user data for a DMA channel.
 *
 * The registered pointer is later returned to the IRQ callback through
 * sl_dma_manager_retrieve_current_channel_user_data(), allowing the callback
 * to share context with the code that allocated the channel.
 *
 * @param[in]  dma_handle   Pointer to the DMA handle. If NULL, the default
 *                          handle is used.
 *
 * @param[in]  channel_nbr  Channel number the user data is registered for.
 *
 * @param[in]  user_data    Pointer to user data to associate with the
 *                          channel. Pass NULL to remove previously registered
 *                          user data.
 *
 * @return 0 (SL_STATUS_OK) if successful. Error code otherwise.
 ******************************************************************************/
sl_status_t sl_dma_manager_register_channel_user_data(sl_dma_handle_t *dma_handle,
                                                      uint8_t channel_nbr,
                                                      void *user_data);

/***************************************************************************//**
 * Retrieves the channel number and user data for the DMA channel currently
 * being serviced in the DMA Manager interrupt dispatch context.
 *
 * Designed to be called from within a DMA channel IRQ callback registered via
 * sl_dma_manager_register_channel_irq_callback(). The returned user data is
 * the one previously registered through
 * sl_dma_manager_register_channel_user_data() for that channel.
 *
 * @param[out] channel_nbr  Pointer to a variable that will receive the
 *                          channel number currently being serviced.
 *
 * @param[out] user_data    Pointer to a variable that will receive the user
 *                          data associated with the channel.
 *
 * @return 0 (SL_STATUS_OK) if successful. Error code otherwise.
 *         SL_STATUS_INVALID_STATE is returned when called outside the DMA
 *         Manager interrupt dispatch context.
 ******************************************************************************/
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
sl_status_t sl_dma_manager_retrieve_current_channel_user_data(uint8_t *channel_nbr,
                                                              void **user_data);

/***************************************************************************//**
 * Gets the pending error bitmap for a DMA channel.
 *
 * @param[in]  channel_nbr  Channel number to query.
 *
 * @return Bitmap of pending errors for the channel. The exact bit layout is
 *         HAL-specific.
 ******************************************************************************/
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
uint32_t sl_dma_manager_get_pending_errors(uint8_t channel_nbr);

/***************************************************************************//**
 * Clears the pending errors for a DMA channel.
 *
 * The function is idempotent and safe to call multiple times.
 *
 * @param[in]  channel_nbr  Channel number whose pending errors must be cleared.
 ******************************************************************************/
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_DMA_MANAGER, SL_CODE_CLASS_DMA_CHANNEL_PERFORMANCE)
void sl_dma_manager_clear_pending_errors(uint8_t channel_nbr);

/** @} (end addtogroup dma_manager) */

#ifdef __cplusplus
}
#endif

#endif // SL_DMA_MANAGER_H
