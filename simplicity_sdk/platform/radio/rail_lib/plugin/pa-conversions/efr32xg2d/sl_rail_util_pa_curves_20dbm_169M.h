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

#define RAIL_PA_CURVES_SUBGIG_HP_VBAT_MAX_POWER      211
#define RAIL_PA_CURVES_SUBGIG_HP_VBAT_MIN_POWER      -140
#define RAIL_PA_CURVES_SUBGIG_HP_VBAT_CURVES \
  { { 255, 211, 22 },                        \
    { 240, 4235, -675168 },                  \
    { 119, 1551, -170902 },                  \
    { 82, 952, -73199 },                     \
    { 62, 707, -38223 },                     \
    { 45, 525, -16671 },                     \
    { 35, 370, -1432 },                      \
    { 26, 293, 4230 },                       \
    { 15, 95, 11665 } }

#define RAIL_PA_CURVES_SUBGIG_MP_VBAT_MAX_POWER      126
#define RAIL_PA_CURVES_SUBGIG_MP_VBAT_MIN_POWER      -320
#define RAIL_PA_CURVES_SUBGIG_MP_VBAT_CURVES \
  { { 255, 126, 20 },                        \
    { 240, 2369, -57343 },                   \
    { 173, 2036, -24778 },                   \
    { 140, 1500, 18906 },                    \
    { 111, 1195, 37765 },                    \
    { 86, 872, 50950 },                      \
    { 68, 765, 53110 },                      \
    { 54, 537, 53515 },                      \
    { 32, 157, 38167 } }

#define RAIL_PA_CURVES_SUBGIG_LP_VBAT_MAX_POWER      26
#define RAIL_PA_CURVES_SUBGIG_LP_VBAT_MIN_POWER      -450
#define RAIL_PA_CURVES_SUBGIG_LP_VBAT_CURVES \
  { { 255, 26, 22 },                         \
    { 240, 2079, 188428 },                   \
    { 170, 1902, 186984 },                   \
    { 143, 1463, 176953 },                   \
    { 113, 1157, 163735 },                   \
    { 86, 817, 141077 },                     \
    { 64, 721, 132099 },                     \
    { 53, 495, 107461 },                     \
    { 30, 137, 51650 } }

#define RAIL_PA_CURVES_SUBGIG_LLP_VBAT_MAX_POWER      -57
#define RAIL_PA_CURVES_SUBGIG_LLP_VBAT_MIN_POWER      -530
#define RAIL_PA_CURVES_SUBGIG_LLP_VBAT_CURVES \
  { { 255, -57, 22 },                         \
    { 240, 1983, 355749 },                    \
    { 163, 1884, 346219 },                    \
    { 147, 1451, 300739 },                    \
    { 116, 1169, 264934 },                    \
    { 89, 818, 212087 },                      \
    { 68, 762, 202265 },                      \
    { 54, 487, 148956 },                      \
    { 31, 143, 65809 } }

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
