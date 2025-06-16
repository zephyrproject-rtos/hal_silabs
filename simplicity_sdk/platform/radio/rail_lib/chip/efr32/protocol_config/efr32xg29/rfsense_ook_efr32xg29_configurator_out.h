/***************************************************************************//**
 * @brief RAIL Configuration
 * @details
 *   WARNING: Auto-Generated Radio Config Header  -  DO NOT EDIT
 *   Radio Configurator Version: 2404.4.4 (42ce28d3f3)
 *   RAIL Adapter Version: 2.4.33 (e3d4627956)
 *   RAIL Compatibility: 2.x
 *******************************************************************************
 * # License
 * <b>Copyright 2019 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef __RFSENSE_OOK_EFR32XG29_CONFIGURATOR_OUT_H__
#define __RFSENSE_OOK_EFR32XG29_CONFIGURATOR_OUT_H__

#include <stdint.h>
#include "rail_types.h"
#include "timing_state.h"

#define RFSENSE_ACCELERATION_BUFFER rfsenseAccelerationBuffer
extern uint32_t rfsenseAccelerationBuffer[];

extern const uint32_t rfsense_ook_1kbps_modemConfigBase[];

#define RAIL0_RFSENSE_OOK_1KBPS_PHY_RFSENSE_2450M_OOK_1KBPS
#define RAIL0_RFSENSE_OOK_1KBPS_PROFILE_BASE
extern const RAIL_ChannelConfig_t rfsense_ook_1kbps_channelConfig;
extern const RAIL_ChannelConfigEntry_t rfsense_ook_1kbps_channels[];

#endif // __RFSENSE_OOK_EFR32XG29_CONFIGURATOR_OUT_H__
