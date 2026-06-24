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

#define RAIL_PA_CURVES_SUBGIG_HP_VBAT_MAX_POWER      144
#define RAIL_PA_CURVES_SUBGIG_HP_VBAT_MIN_POWER      -170
#define RAIL_PA_CURVES_SUBGIG_HP_VBAT_CURVES \
  { { 255, 144, 20 },                        \
    { 240, 5538, -579978 },                  \
    { 98, 1621, -99905 },                    \
    { 63, 896, -26848 },                     \
    { 45, 566, -367 },                       \
    { 34, 392, 10244 },                      \
    { 25, 316, 13153 },                      \
    { 19, 231, 14876 },                      \
    { 12, 79, 12766 } }

#define RAIL_PA_CURVES_SUBGIG_MP_VBAT_MAX_POWER      110
#define RAIL_PA_CURVES_SUBGIG_MP_VBAT_MIN_POWER      -290
#define RAIL_PA_CURVES_SUBGIG_MP_VBAT_CURVES \
  { { 255, 110, 40 },                        \
    { 240, 2690, -63168 },                   \
    { 123, 1242, 37108 },                    \
    { 71, 698, 52204 },                      \
    { 44, 425, 49007 },                      \
    { 27, 258, 40202 },                      \
    { 16, 155, 30748 },                      \
    { 10, 96, 22893 },                       \
    { 5, 45, 13594 } }

#define RAIL_PA_CURVES_SUBGIG_LP_VBAT_MAX_POWER      25
#define RAIL_PA_CURVES_SUBGIG_LP_VBAT_MIN_POWER      -370
#define RAIL_PA_CURVES_SUBGIG_LP_VBAT_CURVES \
  { { 255, 25, 22 },                         \
    { 240, 2293, 183918 },                   \
    { 170, 1938, 181821 },                   \
    { 135, 1461, 170387 },                   \
    { 104, 1101, 154160 },                   \
    { 82, 866, 138738 },                     \
    { 60, 617, 116234 },                     \
    { 48, 469, 99869 },                      \
    { 28, 155, 52007 } }

#define RAIL_PA_CURVES_SUBGIG_LLP_VBAT_MAX_POWER      -52
#define RAIL_PA_CURVES_SUBGIG_LLP_VBAT_MIN_POWER      -380
#define RAIL_PA_CURVES_SUBGIG_LLP_VBAT_CURVES \
  { { 255, -52, 22 },                         \
    { 240, 2094, 352073 },                    \
    { 164, 1955, 339597 },                    \
    { 142, 1482, 291954 },                    \
    { 111, 1151, 251582 },                    \
    { 85, 864, 210093 },                      \
    { 65, 647, 173747 },                      \
    { 53, 515, 149068 },                      \
    { 33, 220, 82571 } }

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
