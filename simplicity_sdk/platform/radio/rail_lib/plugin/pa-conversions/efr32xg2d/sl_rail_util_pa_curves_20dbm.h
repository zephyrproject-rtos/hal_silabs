/***************************************************************************//**
 * @file
 * @brief PA power conversion curves used by Silicon Labs PA power conversion
 *   functions.
 * @details This file contains the curves needed convert PA power levels to
 *   dBm powers.
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

#ifndef __PA_CURVES_H_
#define __PA_CURVES_H_

#ifdef __cplusplus
extern "C" {
#endif

#define RAIL_PA_CURVES_PIECEWISE_SEGMENTS (9U)

#define RAIL_PA_CURVES_SUBGIG_HP_VBAT_MAX_POWER      200
#define RAIL_PA_CURVES_SUBGIG_HP_VBAT_MIN_POWER      -150
#define RAIL_PA_CURVES_SUBGIG_HP_VBAT_CURVES \
  { { 255, 200, 15 },                        \
    { 240, 4736, -711458 },                  \
    { 143, 2756, -353408 },                  \
    { 104, 1586, -159128 },                  \
    { 79, 1111, -87437 },                    \
    { 64, 849, -51800 },                     \
    { 50, 634, -25848 },                     \
    { 41, 474, -8967 },                      \
    { 25, 147, 14676 } }

#define RAIL_PA_CURVES_SUBGIG_MP_VBAT_MAX_POWER      130
#define RAIL_PA_CURVES_SUBGIG_MP_VBAT_MIN_POWER      -300
#define RAIL_PA_CURVES_SUBGIG_MP_VBAT_CURVES \
  { { 255, 130, 40 },                        \
    { 240, 2225, -46080 },                   \
    { 141, 1395, 24294 },                    \
    { 90, 881, 48684 },                      \
    { 54, 513, 51219 },                      \
    { 33, 330, 44753 },                      \
    { 20, 184, 34070 },                      \
    { 13, 135, 28576 },                      \
    { 7, 49, 14902 } }

#define RAIL_PA_CURVES_SUBGIG_LP_VBAT_MAX_POWER      21
#define RAIL_PA_CURVES_SUBGIG_LP_VBAT_MIN_POWER      -400
#define RAIL_PA_CURVES_SUBGIG_LP_VBAT_CURVES \
  { { 255, 21, 22 },                         \
    { 240, 2120, 196998 },                   \
    { 172, 1886, 194414 },                   \
    { 142, 1461, 182756 },                   \
    { 110, 1115, 165683 },                   \
    { 86, 873, 148459 },                     \
    { 66, 699, 132125 },                     \
    { 52, 509, 110395 },                     \
    { 30, 154, 54309 } }

#define RAIL_PA_CURVES_SUBGIG_LLP_VBAT_MAX_POWER      -67
#define RAIL_PA_CURVES_SUBGIG_LLP_VBAT_MIN_POWER      -430
#define RAIL_PA_CURVES_SUBGIG_LLP_VBAT_CURVES \
  { { 255, -67, 22 },                         \
    { 240, 2051, 380407 },                    \
    { 171, 1864, 361372 },                    \
    { 145, 1471, 316015 },                    \
    { 113, 1155, 272535 },                    \
    { 89, 893, 230921 },                      \
    { 69, 696, 195188 },                      \
    { 52, 555, 166245 },                      \
    { 32, 196, 79710 } }

// *INDENT-OFF*
// Macro to declare the variables needed to initialize RAIL_TxPowerCurvesConfig_t for use in
// RAIL_InitTxPowerCurves, assuming battery powered operation
#define RAIL_DECLARE_TX_POWER_VBAT_CURVES_ALT                      \
  static const RAIL_TxPowerCurveAlt_t RAIL_piecewiseDataHp = {     \
    RAIL_PA_CURVES_SUBGIG_HP_VBAT_MAX_POWER,                       \
    RAIL_PA_CURVES_SUBGIG_HP_VBAT_MIN_POWER,                       \
    RAIL_PA_CURVES_SUBGIG_HP_VBAT_CURVES,                          \
  };                                                               \
  static const RAIL_TxPowerCurveAlt_t RAIL_piecewiseDataMp = {     \
    RAIL_PA_CURVES_SUBGIG_MP_VBAT_MAX_POWER,                       \
    RAIL_PA_CURVES_SUBGIG_MP_VBAT_MIN_POWER,                       \
    RAIL_PA_CURVES_SUBGIG_MP_VBAT_CURVES,                          \
  };                                                               \
  static const RAIL_TxPowerCurveAlt_t RAIL_piecewiseDataLp = {     \
    RAIL_PA_CURVES_SUBGIG_LP_VBAT_MAX_POWER,                       \
    RAIL_PA_CURVES_SUBGIG_LP_VBAT_MIN_POWER,                       \
    RAIL_PA_CURVES_SUBGIG_LP_VBAT_CURVES,                          \
  };                                                               \
  static const RAIL_TxPowerCurveAlt_t RAIL_piecewiseDataLlp = {    \
    RAIL_PA_CURVES_SUBGIG_LLP_VBAT_MAX_POWER,                      \
    RAIL_PA_CURVES_SUBGIG_LLP_VBAT_MIN_POWER,                      \
    RAIL_PA_CURVES_SUBGIG_LLP_VBAT_CURVES,                         \
  };

// *INDENT-OFF*

// *INDENT-OFF*
// Macro to declare the variables needed to initialize RAIL_TxPowerCurvesConfig_t for use in
// RAIL_InitTxPowerCurves, assuming battery powered operation
#define RAIL_DECLARE_TX_POWER_CURVES_CONFIG_ALT                                \
  {                                                                            \
    .curves = {                                                                \
      {                                                                        \
        .algorithm = RAIL_PA_ALGORITHM_PIECEWISE_LINEAR,                       \
        .segments = RAIL_PA_CURVES_PIECEWISE_SEGMENTS,                         \
        .min = RAIL_TX_POWER_LEVEL_SUBGIG_HP_MIN,                              \
        .max = RAIL_TX_POWER_LEVEL_SUBGIG_HP_MAX,                              \
        .conversion = { .powerCurve = &RAIL_piecewiseDataHp },                 \
      },                                                                       \
      {                                                                        \
        .algorithm = RAIL_PA_ALGORITHM_PIECEWISE_LINEAR,                       \
        .segments = RAIL_PA_CURVES_PIECEWISE_SEGMENTS,                         \
        .min = RAIL_TX_POWER_LEVEL_SUBGIG_MP_MIN,                              \
        .max = RAIL_TX_POWER_LEVEL_SUBGIG_MP_MAX,                              \
        .conversion = { .powerCurve = &RAIL_piecewiseDataMp },                 \
      },                                                                       \
      {                                                                        \
        .algorithm = RAIL_PA_ALGORITHM_PIECEWISE_LINEAR,                       \
        .segments = RAIL_PA_CURVES_PIECEWISE_SEGMENTS,                         \
        .min = RAIL_TX_POWER_LEVEL_SUBGIG_LP_MIN,                              \
        .max = RAIL_TX_POWER_LEVEL_SUBGIG_LP_MAX,                              \
        .conversion = { .powerCurve = &RAIL_piecewiseDataLp },                 \
      },                                                                       \
      {                                                                        \
        .algorithm = RAIL_PA_ALGORITHM_PIECEWISE_LINEAR,                       \
        .segments = RAIL_PA_CURVES_PIECEWISE_SEGMENTS,                         \
        .min = RAIL_TX_POWER_LEVEL_SUBGIG_LLP_MIN,                             \
        .max = RAIL_TX_POWER_LEVEL_SUBGIG_LLP_MAX,                             \
        .conversion = { .powerCurve = &RAIL_piecewiseDataLlp },                \
      },                                                                       \
    }                                                                          \
  }
// *INDENT-OFF*

#ifdef __cplusplus
}
#endif

#endif
