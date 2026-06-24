/***************************************************************************//**
 * @file
 * @brief Clock Manager Private API definition.
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

#ifndef SLI_CLOCK_MANAGER_H
#define SLI_CLOCK_MANAGER_H

#include "sl_clock_manager.h"
#include "sl_status.h"
#include "sl_compiler.h"
#include "sl_code_classification.h"

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************//**
 * When this callback function is called, it means that HFXO is ready.
 ******************************************************************************/
__WEAK void sli_clock_manager_notify_hfxo_ready(void);

/***************************************************************************//**
 * Gets the HFXO's average startup time.
 *
 * @param[out] val  The HFXO's AVGSTUP value.
 *
 * @return  Status code.
 *          SL_STATUS_OK if successful.
 *          SL_STATUS_NOT_READY if measure is not done yet.
 *          SL_STATUS_NOT_SUPPORTED if not supported.
 *
 ******************************************************************************/
sl_status_t sli_clock_manager_get_hfxo_average_startup_time(uint32_t *val);

/***************************************************************************//**
 * Retrieves the FREQPLAN NWP SOCPLL config.
 *
 * @param[out]  socpll_freqplan_config Table with SOCPLL FREQPLAN configurations
 *   for FREQPLAN_FREQSEL_WIDTH frequencies.
 *
 * @param[out]  target_frequency_index Index of the target frequency in the
 *   table with SOCPLL FREQPLAN configurations.
 *
 * @return  Status code.
 *          SL_STATUS_OK if successful. Error code otherwise.
 ******************************************************************************/
sl_status_t sli_clock_manager_get_nwp_socpll_freqplan_config(const uint16_t **socpll_freqplan_config,
                                                             uint8_t *target_frequency_index);

/***************************************************************************//**
 * Retrieves the FREQPLAN NWP CLKMULT config.
 *
 * @param[in]   clkmult_index Index of the CLKMULT instance (0 or 1).
 *
 * @param[out]  nwp_clkmult_freqplan_config Table with CLKMULT FREQPLAN
 *   configurations for FREQPLAN_FREQSEL_WIDTH frequencies.
 *
 * @param[out]  target_frequency_index Index of the target frequency in the
 *   table with CLKMULT FREQPLAN configurations.
 *
 * @return  Status code.
 *          SL_STATUS_OK if successful. Error code otherwise.
 ******************************************************************************/
sl_status_t sli_clock_manager_get_nwp_clkmult_freqplan_config(uint8_t clkmult_index,
                                                              const uint8_t **nwp_clkmult_freqplan_config,
                                                              uint8_t *target_frequency_index);

#if defined (SL_CLOCK_MANAGER_SYSCLK_OSPI_DYNAMIC_CFG_EN) && (SL_CLOCK_MANAGER_SYSCLK_OSPI_DYNAMIC_CFG_EN == 1)
/***************************************************************************//**
 * Sets the Radio Friendly mode state.
 *
 * @param[in] enable  true to enable RF-friendly mode, false to disable.
 *
 * @return  Status code.
 *          SL_STATUS_OK if successful. Error code otherwise.
 *
 * @note SYSCLK and OSPICLK branches can create radio interference depending on
 *       their frequency and the radio channels being used. To reduce
 *       interference, the FREQPLAN module is used to dynamically frequency
 *       plan the System Clock and OSPI clocks when SOCPLL is used as source.
 *       Since SOCPLL consumes more power than other oscillators, it can be wise
 *       to switch the SYSCLK and OSPICLKs oscillators for period of No-RF
 *       activities known by the application.
 *
 * @note This feature is only available with the
 *       SL_CLOCK_MANAGER_SYSCLK_OSPI_DYNAMIC_CFG_EN configurations enabled.
 ******************************************************************************/
sl_status_t sli_clock_manager_set_rf_friendly_clock_mode(bool enable);

/***************************************************************************//**
 * Gets the current RF-friendly clock mode state.
 *
 * @return  bool true if RF-friendly mode is enabled, false otherwise.
 *
 * @note This feature is only available with the
 *       SL_CLOCK_MANAGER_SYSCLK_OSPI_DYNAMIC_CFG_EN configuration enabled.
 ******************************************************************************/
bool sli_clock_manager_clock_mode_is_rf_friendly(void);

#endif // defined (SL_CLOCK_MANAGER_SYSCLK_OSPI_DYNAMIC_CFG_EN) && (SL_CLOCK_MANAGER_SYSCLK_OSPI_DYNAMIC_CFG_EN == 1)

#ifdef __cplusplus
}
#endif

#endif // SLI_CLOCK_MANAGER_H
