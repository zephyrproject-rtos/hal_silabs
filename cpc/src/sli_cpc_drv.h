/***************************************************************************/ /**
 * @file
 * @brief CPC Driver Interface
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

#ifndef SLI_CPC_DRV_H
#define SLI_CPC_DRV_H

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>

#include "sl_status.h"
#include "sli_cpc.h"
#include "sli_cpc_frame_list.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief CPC driver operations.
 *
 * Ops take `sl_cpc_bus_t *bus` — the bus embedded in the driver's private
 * handle. Drivers that need per-instance state recover it with:
 * @code
 *   sli_cpc_drv_t *drv = container_of(bus, sli_cpc_drv_t, bus);
 * @endcode
 */
typedef struct sli_cpc_drv_ops {
  /// Initialize the rest of the driver after the hardware peripheral has been
  /// initialized.
  /// @param[in] bus Bus bound to this driver.
  /// @return SL_STATUS_OK if successful. Error code otherwise.
  sl_status_t (*init)(sl_cpc_bus_t *bus);

  /// Start receiving packets
  /// @param[in] bus Bus whose driver should start RX.
  /// @return SL_STATUS_OK if successful. Error code otherwise.
  sl_status_t (*start_rx)(sl_cpc_bus_t *bus);

#if defined(SL_CATALOG_CPC_NG_PRIMARY_PRESENT)
  /// De-Initializes CPC driver for the firmware upgrade to take over control.
  /// @param[in] bus Bus whose driver to deinitialize.
  void (*deinit)(sl_cpc_bus_t *bus);
#endif

  /// Reads data from driver.
  /// @param[in]  bus      Bus to read from.
  /// @param[out] frames   List that receives frames read from the bus.
  /// @return SL_STATUS_OK if successful. Error code otherwise.
  sl_status_t (*read)(sl_cpc_bus_t *bus, sli_cpc_frame_list_t *frames);

  /// Send a list of frames to the driver to be sent on the bus.
  /// @param[in]     bus      Bus to write to.
  /// @param[in,out] frames   List of frames to send. On return, the list has
  ///                         x fewer elements, where x is the number queued.
  /// @return Number of frames queued.
  uint32_t (*write)(sl_cpc_bus_t *bus, sli_cpc_frame_list_t *frames);

  /// Get the number of available frame slots to be sent immediately over the bus.
  /// @param[in] bus Bus to query.
  /// @return Number of frame slots available to be sent immediately.
  uint32_t (*get_available_write_frame_slots)(sl_cpc_bus_t *bus);

  /// Notification on freed RX frame
  /// @param[in] bus Bus whose driver freed an RX frame.
  void (*on_rx_frame_free)(sl_cpc_bus_t *bus);

  /// Get the local capabilities of the driver.
  /// @param[in]  bus          Bus whose driver to query.
  /// @param[out] caps_p       Receives a pointer to the local capability blob.
  /// @param[out] caps_size_p  Receives the size of the capability blob.
  void (*get_local_capabilities)(sl_cpc_bus_t *bus, const void **caps_p, uint16_t *caps_size_p);

  /// Set the remote capabilities of the driver.
  /// @note These capabilities MUST NOT break the PHY.
  /// @param[in,out] bus       Bus whose driver to update.
  /// @param[in]     caps      Remote capability blob.
  /// @param[in]     caps_size Size of @p caps.
  /// @return SL_STATUS_OK if successful. Error code otherwise.
  sl_status_t (*set_remote_capabilities)(sl_cpc_bus_t *bus, const void *caps, uint16_t caps_size);
} sli_cpc_drv_ops_t;

/** @} (end addtogroup cpc) */

#ifdef __cplusplus
}
#endif

#endif // SLI_CPC_DRV_H
