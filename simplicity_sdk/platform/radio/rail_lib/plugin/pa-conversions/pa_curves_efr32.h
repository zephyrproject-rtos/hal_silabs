/***************************************************************************//**
 * @file
 * @brief PA power conversion curves used by Silicon Labs PA power conversion
 *   functions.
 * @details This file contains the curves needed convert PA power levels to
 *   dBm powers.
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef PA_CURVES_EFR32_H
#define PA_CURVES_EFR32_H

#ifdef __cplusplus
extern "C" {
#endif

#include "em_device.h"

#ifdef _SILICON_LABS_32B_SERIES_1
#include "efr32xg1x/sl_rail_util_pa_curves.h"
#elif defined (_SILICON_LABS_32B_SERIES_2_CONFIG_1)
#include "efr32xg21/sl_rail_util_pa_curves.h"
#elif defined(_SILICON_LABS_32B_SERIES_2_CONFIG_2)
#include "efr32xg22/sl_rail_util_pa_curves.h"
#elif (_SILICON_LABS_32B_SERIES_2_CONFIG == 3)
#if defined(_SILICON_LABS_EFR32_SUBGHZ_HP_PA_PRESENT)
  #if (_SILICON_LABS_EFR32_SUBGHZ_HP_PA_MAX_OUTPUT_DBM == 20)
  #include "efr32xg23/sl_rail_util_pa_curves_20dbm.h"
  #elif (_SILICON_LABS_EFR32_SUBGHZ_HP_PA_MAX_OUTPUT_DBM == 10)
  #include "efr32xg23/sl_rail_util_pa_curves_10dbm_434M.h"
  #else
  #include "efr32xg23/sl_rail_util_pa_curves_14dbm.h"
  #endif
#else
#error "No valid PA available for selected chip."
#endif
#elif (_SILICON_LABS_32B_SERIES_2_CONFIG == 8)
#if defined(_SILICON_LABS_EFR32_SUBGHZ_HP_PA_PRESENT)
  #if (_SILICON_LABS_EFR32_SUBGHZ_HP_PA_MAX_OUTPUT_DBM == 20)
    #if defined(HARDWARE_BOARD_SUPPORTS_RF_BAND_868)
      #include "efr32xg28/sl_rail_util_pa_curves_20dbm_868M.h"
    #else
      #include "efr32xg28/sl_rail_util_pa_curves_20dbm_915M.h"
    #endif
  #else
    #if defined(HARDWARE_BOARD_SUPPORTS_RF_BAND_868)
      #include "efr32xg28/sl_rail_util_pa_curves_14dbm_868M.h"
    #else
      #include "efr32xg28/sl_rail_util_pa_curves_14dbm_915M.h"
    #endif
  #endif
#else
#error "No valid PA available for selected chip."
#endif
#elif (_SILICON_LABS_32B_SERIES_2_CONFIG == 4)
  #if defined(_SILICON_LABS_EFR32_2G4HZ_HP_PA_PRESENT) \
  && (_SILICON_LABS_EFR32_2G4HZ_HP_PA_MAX_OUTPUT_DBM > 10)
  #include "efr32xg24/sl_rail_util_pa_curves_20dbm.h"
  #else
  #include "efr32xg24/sl_rail_util_pa_curves_10dbm.h"
  #endif
#elif (_SILICON_LABS_32B_SERIES_2_CONFIG == 5)
#include "efr32xg25/sl_rail_util_pa_dbm_powersetting_mapping_table.h"
#include "efr32xg25/sl_rail_util_pa_curves.h"
#elif (_SILICON_LABS_32B_SERIES_2_CONFIG == 6)
  #if defined(_SILICON_LABS_EFR32_2G4HZ_HP_PA_PRESENT) \
  && (_SILICON_LABS_EFR32_2G4HZ_HP_PA_MAX_OUTPUT_DBM > 10)
  #include "efr32xg26/sl_rail_util_pa_curves_20dbm.h"
  #else
  #if defined(EFR32MG26B510F3200IL136)
  #include "efr32xg26/sl_rail_util_pa_curves_BGA.h"
  #else
  #include "efr32xg26/sl_rail_util_pa_curves_10dbm.h"
  #endif
  #endif
#elif (_SILICON_LABS_32B_SERIES_2_CONFIG == 7)
// EFR32XG27 boards come in two different packaging -- CSP and QFN
// These packages have different matching circuits which leads
// to different PA curves.
// CSP packages have _SILICON_LABS_EFR32_2G4HZ_HP_PA_MAX_OUTPUT_DBM
// = 4 whereas for QFN package it is 6 or 8dBm, so this parameter
// is used to differentiate it.
#if (_SILICON_LABS_EFR32_2G4HZ_HP_PA_MAX_OUTPUT_DBM < 6)
#include "efr32xg27/sl_rail_util_pa_curves_CSP.h"
#else
#include "efr32xg27/sl_rail_util_pa_curves_QFN.h"
#endif
#elif (_SILICON_LABS_32B_SERIES_2_CONFIG == 9)
#include "efr32xg29/sl_rail_util_pa_curves.h"
#elif defined(_SILICON_LABS_32B_SERIES_3)
#include "sixg301/sl_rail_util_pa_dbm_powersetting_mapping_table.h"
#include "sixg301/sl_rail_util_pa_curves.h"
#else
#ifdef RAIL_INTERNAL_BUILD
#include "pa_curves_efr32_internal.h"
#else
#error "Unsupported platform!"
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif // PA_CURVES_EFR32_H
