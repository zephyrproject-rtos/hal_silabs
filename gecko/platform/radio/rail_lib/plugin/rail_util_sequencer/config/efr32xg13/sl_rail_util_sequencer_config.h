/***************************************************************************//**
 * @file
 * @brief
 *******************************************************************************
 * # License
 * <b>Copyright 2023 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef SL_RAIL_UTIL_SEQUENCER_H
#define SL_RAIL_UTIL_SEQUENCER_H

#include "rail.h"
#if defined(SL_COMPONENT_CATALOG_PRESENT)
#include "sl_component_catalog.h"
#endif

#if defined(SL_CATALOG_RAIL_UTIL_IEEE802154_HIGH_SPEED_PHY_PRESENT)
#include "sl_rail_util_ieee802154_high_speed_phy_config.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define SL_RAIL_UTIL_SEQUENCER_RUNTIME_IMAGE_SELECTION 0

#if (defined(SL_CATALOG_RAIL_UTIL_IEEE802154_HIGH_SPEED_PHY_PRESENT) \
  && (SL_RAIL_UTIL_IEEE802154_2P4_2MBPS_PHY_ENABLED == 1))
#define SL_RAIL_UTIL_SEQUENCER_IMAGE RAIL_SEQ_IMAGE_HIGH_BW_PHY
#else
#define SL_RAIL_UTIL_SEQUENCER_IMAGE RAIL_SEQ_IMAGE_ZWAVE
#endif

#ifdef __cplusplus
}
#endif

#endif // SL_RAIL_UTIL_SEQUENCER_H
