/***************************************************************************//**
 * @file
 * @brief PA power conversion functions provided to the customer as source for
 *   highest level of customization.
 * @details This file contains the curves and logic that convert PA power
 *   levels to dBm powers.
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
// For details on how to use this plugin, see
//   https://www.silabs.com/documents/public/application-notes/an1127-power-amplifier-power-conversion-functions.pdf

#include "em_device.h"
#if defined(_SILICON_LABS_32B_SERIES_2) || defined(SIMULATION_DEVICE)
#include "em_cmu.h"
#else
#include "sl_clock_manager.h"
#endif

#include "pa_conversions_efr32.h"
#include "rail.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

static RAIL_TxPowerCurvesConfigAlt_t powerCurvesState;

// Make sure SUPPORTED_PA_INDICES match the per-platform PA curves
// provided by RAIL_DECLARE_TX_POWER_CURVES_CONFIG_ALT and resulting
// RAIL_TxPowerCurvesConfigAlt_t!
#ifndef SUPPORTED_PA_INDICES
#if defined(_SILICON_LABS_32B_SERIES_1)
#define SUPPORTED_PA_INDICES {                   \
    0U,        /* 2P4GIG_HP  */                  \
    RAIL_NUM_PA, /* 2P4GIG_MP  */                \
    1U,        /* 2P4GIG_LP  */                  \
    RAIL_NUM_PA, /* 2P4GIG_LLP */                \
    RAIL_NUM_PA, /* 2P4GIG_HIGHEST */            \
    RAIL_NUM_PA, /* SUBGIG_POWERSETTING_TABLE */ \
    2U,        /* SUBGIG_HP */                   \
    /* The rest are unsupported */               \
}
#elif (_SILICON_LABS_32B_SERIES_2_CONFIG == 1)
#define SUPPORTED_PA_INDICES {     \
    0U,        /* 2P4GIG_HP  */    \
    1U,        /* 2P4GIG_MP  */    \
    2U,        /* 2P4GIG_LP  */    \
    /* The rest are unsupported */ \
}
#elif (_SILICON_LABS_32B_SERIES_2_CONFIG == 2)
#define SUPPORTED_PA_INDICES {     \
    0U,        /* 2P4GIG_HP  */    \
    RAIL_NUM_PA, /* 2P4GIG_MP  */  \
    1U,        /* 2P4GIG_LP  */    \
    /* The rest are unsupported */ \
}
#elif (_SILICON_LABS_32B_SERIES_2_CONFIG == 3)
#define SUPPORTED_PA_INDICES {                   \
    RAIL_NUM_PA, /* 2P4GIG_HP  */                \
    RAIL_NUM_PA, /* 2P4GIG_MP  */                \
    RAIL_NUM_PA, /* 2P4GIG_LP  */                \
    RAIL_NUM_PA, /* 2P4GIG_LLP */                \
    RAIL_NUM_PA, /* 2P4GIG_HIGHEST */            \
    RAIL_NUM_PA, /* SUBGIG_POWERSETTING_TABLE */ \
    0U,        /* SUBGIG_HP */                   \
    1U,        /* SUBGIG_MP */                   \
    2U,        /* SUBGIG_LP */                   \
    3U,        /* SUBGIG_LLP */                  \
    /* The rest are unsupported */               \
}
#elif ((_SILICON_LABS_32B_SERIES_2_CONFIG == 4) || (_SILICON_LABS_32B_SERIES_2_CONFIG == 6) || !defined(_SILICON_LABS_32B_SERIES_2))
#define SUPPORTED_PA_INDICES {     \
    0U,        /* 2P4GIG_HP  */    \
    RAIL_NUM_PA, /* 2P4GIG_MP  */  \
    1U,        /* 2P4GIG_LP  */    \
    /* The rest are unsupported */ \
}
#elif (_SILICON_LABS_32B_SERIES_2_CONFIG == 5)
#define SUPPORTED_PA_INDICES {                  \
    RAIL_NUM_PA, /* 2P4GIG_HP  */               \
    RAIL_NUM_PA, /* 2P4GIG_MP  */               \
    RAIL_NUM_PA, /* 2P4GIG_LP  */               \
    RAIL_NUM_PA, /* 2P4GIG_LLP */               \
    RAIL_NUM_PA, /* 2P4GIG_HIGHEST */           \
    0U,        /* SUBGIG_POWERSETTING_TABLE */  \
    RAIL_NUM_PA, /* SUBGIG_HP */                \
    RAIL_NUM_PA, /* SUBGIG_MP */                \
    RAIL_NUM_PA, /* SUBGIG_LP */                \
    RAIL_NUM_PA, /* SUBGIG_LLP */               \
    RAIL_NUM_PA, /* SUBGIG_HIGHEST */           \
    1U,        /* OFDM_PA_POWERSETTING_TABLE */ \
}
#elif (_SILICON_LABS_32B_SERIES_2_CONFIG == 7)
#define SUPPORTED_PA_INDICES {     \
    0U,        /* 2P4GIG_HP  */    \
    RAIL_NUM_PA, /* 2P4GIG_MP  */  \
    1U,        /* 2P4GIG_LP  */    \
    /* The rest are unsupported */ \
}
#elif (_SILICON_LABS_32B_SERIES_2_CONFIG == 8)
#define SUPPORTED_PA_INDICES {                   \
    0U,        /* 2P4GIG_HP  */                  \
    RAIL_NUM_PA, /* 2P4GIG_MP  */                \
    RAIL_NUM_PA, /* 2P4GIG_LP  */                \
    RAIL_NUM_PA, /* 2P4GIG_LLP */                \
    RAIL_NUM_PA, /* 2P4GIG_HIGHEST */            \
    RAIL_NUM_PA, /* SUBGIG_POWERSETTING_TABLE */ \
    1U,        /* SUBGIG_HP */                   \
    2U,        /* SUBGIG_MP */                   \
    3U,        /* SUBGIG_LP */                   \
    4U,        /* SUBGIG_LLP */                  \
    /* The rest are unsupported */               \
}
#elif (_SILICON_LABS_32B_SERIES_2_CONFIG == 9)
#define SUPPORTED_PA_INDICES {     \
    0U,        /* 2P4GIG_HP  */    \
    RAIL_NUM_PA, /* 2P4GIG_MP  */  \
    1U,        /* 2P4GIG_LP  */    \
    /* The rest are unsupported */ \
}
#else
#error "unknown platform"
#endif
#endif

static const uint8_t supportedPaIndices[] = SUPPORTED_PA_INDICES;

#if defined(_SILICON_LABS_32B_SERIES_1) || defined(_SILICON_LABS_32B_SERIES_2_CONFIG_1)
  #define PA_CONVERSION_MINIMUM_PWRLVL 1U
#else
  #define PA_CONVERSION_MINIMUM_PWRLVL 0U
#endif

//   This macro is defined when Silicon Labs builds this into the library as WEAK
//   to ensure it can be overriden by customer versions of these functions. The macro
//   should *not* be defined in a customer build.
#ifdef RAIL_PA_CONVERSIONS_WEAK
__WEAK
#endif
const RAIL_TxPowerCurves_t *RAIL_GetTxPowerCurve(RAIL_TxPowerMode_t mode)
{
  static RAIL_TxPowerCurves_t powerCurves;
  RAIL_TxPowerLevel_t maxPowerLevel, minPowerLevel;
  if (RAIL_SupportsTxPowerModeAlt(RAIL_EFR32_HANDLE,
                                  &mode,
                                  &maxPowerLevel,
                                  &minPowerLevel)
      && (mode < sizeof(supportedPaIndices))
      && (supportedPaIndices[mode] < RAIL_NUM_PA)) {
    const RAIL_PaDescriptor_t *modeInfo = &powerCurvesState.curves[supportedPaIndices[mode]];
    const RAIL_TxPowerCurveAlt_t *curve = modeInfo->conversion.powerCurve;
    // Check for an invalid power curve
    if (curve == NULL) {
      return NULL;
    }

#if RAIL_SUPPORTS_DBM_POWERSETTING_MAPPING_TABLE
    if (modeInfo->algorithm == RAIL_PA_ALGORITHM_DBM_POWERSETTING_MAPPING_TABLE) {
      powerCurves.maxPower = modeInfo->maxPowerDbm;
      powerCurves.minPower = modeInfo->minPowerDbm;
      // Mapping table does not have RAIL_TxPowerCurveSegment_t segments
      powerCurves.powerParams = NULL;
    } else
#endif
    {
      powerCurves.maxPower = curve->maxPower;
      powerCurves.minPower = curve->minPower;
      powerCurves.powerParams = &curve->powerParams[0];
    }
    return &powerCurves;
  }
  return NULL;
}

// This function will not be supported for any parts after efr32xg1x
#ifdef RAIL_PA_CONVERSIONS_WEAK
__WEAK
#endif
RAIL_Status_t RAIL_InitTxPowerCurves(const RAIL_TxPowerCurvesConfig_t *config)
{
#ifdef _SILICON_LABS_32B_SERIES_1
  // First PA is 2.4 GHz high power, using a piecewise fit
  RAIL_PaDescriptor_t *current = &powerCurvesState.curves[0];
  current->algorithm = RAIL_PA_ALGORITHM_PIECEWISE_LINEAR;
  current->segments = config->piecewiseSegments;
  current->min = RAIL_TX_POWER_LEVEL_2P4_HP_MIN;
  current->max = RAIL_TX_POWER_LEVEL_2P4_HP_MAX;
  static RAIL_TxPowerCurveAlt_t txPower2p4 = {
    .minPower = 0U,
    .maxPower = 0U,
    .powerParams = { // The current max number of piecewise segments is 8
      { 0U, 0U, 0U }, { 0U, 0U, 0U }, { 0U, 0U, 0U }, { 0U, 0U, 0U },
      { 0U, 0U, 0U }, { 0U, 0U, 0U }, { 0U, 0U, 0U }, { 0U, 0U, 0U },
    }
  };
  txPower2p4.maxPower = config->txPowerSgCurves->maxPower;
  txPower2p4.minPower = config->txPowerSgCurves->minPower;
  (void) memcpy(&txPower2p4.powerParams[0],
                config->txPowerSgCurves->powerParams,
                config->piecewiseSegments * sizeof(RAIL_TxPowerCurveSegment_t));
  current->conversion.powerCurve = &txPower2p4;

  // Second PA is 2.4 GHz low power, using a mapping table
  current = &powerCurvesState.curves[1];
  current->algorithm = RAIL_PA_ALGORITHM_MAPPING_TABLE;
  current->segments = 0U;
  current->min = RAIL_TX_POWER_LEVEL_2P4_LP_MIN;
  current->max = RAIL_TX_POWER_LEVEL_2P4_LP_MAX;
  current->conversion.mappingTable = config->txPower24LpCurves;

  // Third and final PA is Sub-GHz, using a piecewise fit
  current = &powerCurvesState.curves[2];
  current->algorithm = RAIL_PA_ALGORITHM_PIECEWISE_LINEAR;
  current->segments = config->piecewiseSegments;
  current->min = RAIL_TX_POWER_LEVEL_SUBGIG_MIN;
  current->max = RAIL_TX_POWER_LEVEL_SUBGIG_HP_MAX;
  static RAIL_TxPowerCurveAlt_t txPowerSubGig = {
    .minPower = 0U,
    .maxPower = 0U,
    .powerParams = { // The current max number of piecewise segments is 8
      { 0U, 0U, 0U }, { 0U, 0U, 0U }, { 0U, 0U, 0U }, { 0U, 0U, 0U },
      { 0U, 0U, 0U }, { 0U, 0U, 0U }, { 0U, 0U, 0U }, { 0U, 0U, 0U },
    }
  };
  txPowerSubGig.maxPower = config->txPowerSgCurves->maxPower;
  txPowerSubGig.minPower = config->txPowerSgCurves->minPower;
  (void) memcpy(&txPowerSubGig.powerParams[0],
                config->txPowerSgCurves->powerParams,
                config->piecewiseSegments * sizeof(RAIL_TxPowerCurveSegment_t));
  current->conversion.powerCurve = &txPowerSubGig;

  return RAIL_STATUS_NO_ERROR;
#else
  (void) config;
  return RAIL_STATUS_INVALID_CALL;
#endif
}

#ifdef RAIL_PA_CONVERSIONS_WEAK
__WEAK
#endif
RAIL_Status_t RAIL_InitTxPowerCurvesAlt(const RAIL_TxPowerCurvesConfigAlt_t *config)
{
  RAIL_Status_t status = RAIL_VerifyTxPowerCurves(config);
  if (status == RAIL_STATUS_NO_ERROR) {
    powerCurvesState = *config;
  }
  return status;
}

#ifdef RAIL_PA_CONVERSIONS_WEAK
__WEAK
#endif
#if RAIL_SUPPORTS_DBM_POWERSETTING_MAPPING_TABLE
const RAIL_PaPowerSetting_t *RAIL_GetPowerSettingTable(RAIL_Handle_t railHandle, RAIL_TxPowerMode_t mode,
                                                       RAIL_TxPower_t *minPower, RAIL_TxPower_t *maxPower,
                                                       RAIL_TxPowerLevel_t *step)
{
  (void)railHandle;
#if RAIL_SUPPORTS_DBM_POWERSETTING_MAPPING_TABLE
  if ((mode < sizeof(supportedPaIndices))
      && (supportedPaIndices[mode] < RAIL_NUM_PA)) {
    RAIL_PaDescriptor_t *modeInfo = &powerCurvesState.curves[supportedPaIndices[mode]];
    *minPower = modeInfo->minPowerDbm;
    *maxPower = modeInfo->maxPowerDbm;
    *step = modeInfo->step;
    return (RAIL_PaPowerSetting_t*)(modeInfo->conversion.mappingTable);
  }
  return NULL;
#else
  (void)mode;
  (void)minPower;
  (void)maxPower;
  (void)step;
  return NULL;
#endif
}
#endif // RAIL_SUPPORTS_DBM_POWERSETTING_MAPPING_TABLE

#ifdef RAIL_PA_CONVERSIONS_WEAK
__WEAK
#endif
RAIL_TxPowerLevel_t RAIL_ConvertDbmToRaw(RAIL_Handle_t railHandle,
                                         RAIL_TxPowerMode_t mode,
                                         RAIL_TxPower_t power)
{
  (void)railHandle;
  // When a channel dBm limitation greater than or equal to \ref RAIL_TX_POWER_MAX
  // is converted to raw units, the max RAIL_TxPowerLevel_t will be
  // returned. When compared to the current power level of the PA,
  // it will always be greater, indicating that no power coercion
  // is necessary to comply with channel limitations.
  if (power >= RAIL_TX_POWER_MAX) {
    return 255U;
  }

  if ((mode < sizeof(supportedPaIndices))
      && (supportedPaIndices[mode] < RAIL_NUM_PA)) {
    RAIL_PaDescriptor_t const *modeInfo = &powerCurvesState.curves[supportedPaIndices[mode]];
    uint32_t minPowerLevel = MAX(modeInfo->min, PA_CONVERSION_MINIMUM_PWRLVL);
#if RAIL_SUPPORTS_DBM_POWERSETTING_MAPPING_TABLE
    if (modeInfo->algorithm == RAIL_PA_ALGORITHM_DBM_POWERSETTING_MAPPING_TABLE) {
      RAIL_TxPower_t minPower = modeInfo->minPowerDbm;
      RAIL_TxPower_t maxPower = modeInfo->maxPowerDbm;
      RAIL_TxPowerLevel_t step = modeInfo->step;

      // Cap the power to within the range of the mapping table
      if (power < minPower) {
        power = minPower;
      } else if (power > maxPower) {
        power = maxPower;
      } else {
        // Power level is within bounds (MISRA required else)
      }

      uint32_t powerIndex = (power - minPower) / step;
      RAIL_SetPaPowerSetting(railHandle, modeInfo->conversion.mappingTable[powerIndex], minPower, maxPower, power);
#ifdef _SILICON_LABS_32B_SERIES_3
      // Hack until librail is switched over to enforcing power limits in dBm
      // This should work on rainier as rainier power table is only based on RAC_TX_PAPOWERSCALOR register,
      // so the table value is guaranteed to be monotonic.
      // As sol using a combination of more than a register field, the resulting power table is not guaranteed to be monotonic
      return (RAIL_TxPowerLevel_t)(modeInfo->conversion.mappingTable[powerIndex]);
#else
      return 0U;
#endif
    }
#endif

    // If we're in low power mode, just use the simple lookup table
    if (modeInfo->algorithm == RAIL_PA_ALGORITHM_MAPPING_TABLE) {
      // Binary search through the lookup table to find the closest power level
      // without going over.
      uint32_t lower = 0U;
      // Track the high side of the estimate
      uint32_t powerIndex = modeInfo->max - minPowerLevel;

      while (lower < powerIndex) {
        // Calculate the midpoint of the current range
        uint32_t index = powerIndex - (powerIndex - lower) / 2U;
        if (power < modeInfo->conversion.mappingTable[index]) {
          powerIndex = index - 1U;
        } else {
          lower = index;
        }
      }
      return (RAIL_TxPowerLevel_t)(powerIndex + minPowerLevel);
    }

    // Here we know we're using the piecewise linear conversion
    RAIL_TxPowerCurveAlt_t const *paParams = modeInfo->conversion.powerCurve;
    // Check for valid paParams before using them
    if (paParams == NULL) {
      return 0U;
    }

    // Cap the power based on the PA settings.
    if (power > paParams->maxPower) {
      // If we go above the maximum dbm the chip supports
      // Then provide maximum powerLevel
      power = paParams->maxPower;
    } else if (power < paParams->minPower) {
      // If we go below the minimum we want included in the curve fit, force it.
      power = paParams->minPower;
    } else {
      // Do nothing, power is OK
    }
    // Map the power value to a 0 - 7 curveIndex value
    //There are 8 segments of step size of RAIL_TX_POWER_CURVE_INCREMENT in deci dBm
    //starting from maximum RAIL_TX_POWER_CURVE_MAX in deci dBm
    // These are just starting points to give the code
    // a rough idea of which segment to use, based on
    // how they were fit. Adjustments are made later on
    // if this turns out to be incorrect.
    RAIL_TxPower_t txPowerMax = RAIL_TX_POWER_CURVE_DEFAULT_MAX;
    RAIL_TxPower_t txPowerIncrement = RAIL_TX_POWER_CURVE_DEFAULT_INCREMENT;
    int16_t curveIndex = 0;
    // if the first curve segment starts with RAIL_TX_POWER_LEVEL_INVALID
    //It is an extra curve segment to depict the maxpower and increment
    // (in deci-dBm) used while generating the curves.
    // The extra segment is only present when curve segment is generated by
    //using values different than the default - RAIL_TX_POWER_CURVE_DEFAULT_MAX
    // and RAIL_TX_POWER_CURVE_DEFAULT_INCREMENT.
    if ((paParams->powerParams[0].maxPowerLevel) == RAIL_TX_POWER_LEVEL_INVALID) {
      curveIndex += 1;
      txPowerMax = (RAIL_TxPower_t) paParams->powerParams[0].slope;
      txPowerIncrement = (RAIL_TxPower_t) paParams->powerParams[0].intercept;
    }

    curveIndex += (txPowerMax - power) / txPowerIncrement;
    if ((curveIndex > ((int16_t)modeInfo->segments - 1))
        || (curveIndex < 0)) {
      curveIndex = ((int16_t)modeInfo->segments - 1);
    }

    uint32_t powerLevel;
    do {
      // Select the correct piecewise segment to use for conversion.
      RAIL_TxPowerCurveSegment_t const *powerParams =
        &paParams->powerParams[curveIndex];

      // powerLevel can only go down to 0.
      int32_t powerLevelInt = powerParams->intercept + ((int32_t)powerParams->slope * (int32_t)power);
      if (powerLevelInt < 0) {
        powerLevel = 0U;
      } else {
        powerLevel = (uint32_t) powerLevelInt;
      }
      // RAIL_LIB-8330: Modified from adding 500 to adding 92, this was tested on xg21 as being the highest
      // number we can use without exceeding the requested power in dBm
      powerLevel = ((powerLevel + 92U) / 1000U);

      // In case it turns out the resultant power level was too low and we have
      // to recalculate with the next curve...
      curveIndex++;
    } while ((curveIndex < (int16_t)modeInfo->segments)
             && (powerLevel <= paParams->powerParams[curveIndex].maxPowerLevel));

    // We already know that curveIndex is at most modeInfo->segments
    if (powerLevel > paParams->powerParams[curveIndex - 1].maxPowerLevel) {
      powerLevel = paParams->powerParams[curveIndex - 1].maxPowerLevel;
    }

    // If we go below the minimum we want included in the curve fit, force it.
    if (powerLevel < minPowerLevel) {
      powerLevel = minPowerLevel;
    }

    return (RAIL_TxPowerLevel_t)powerLevel;
  }
  return 0U;
}

#ifdef RAIL_PA_CONVERSIONS_WEAK
__WEAK
#endif
RAIL_TxPower_t RAIL_ConvertRawToDbm(RAIL_Handle_t railHandle,
                                    RAIL_TxPowerMode_t mode,
                                    RAIL_TxPowerLevel_t powerLevel)
{
  (void)railHandle;

  if ((mode < sizeof(supportedPaIndices))
      && (supportedPaIndices[mode] < RAIL_NUM_PA)) {
    RAIL_PaDescriptor_t const *modeInfo = &powerCurvesState.curves[supportedPaIndices[mode]];
    if (modeInfo->algorithm == RAIL_PA_ALGORITHM_MAPPING_TABLE) {
      // Limit the max power level
      if (powerLevel > modeInfo->max) {
        powerLevel = modeInfo->max;
      }

      // We 1-index low power PA power levels, but of course arrays are 0 indexed
      powerLevel -= MAX(modeInfo->min, PA_CONVERSION_MINIMUM_PWRLVL);

      //If the index calculation above underflowed, then provide the lowest array index.
      if (powerLevel > (modeInfo->max - modeInfo->min)) {
        powerLevel = 0U;
      }
      return modeInfo->conversion.mappingTable[powerLevel];
    } else {
#if defined(_SILICON_LABS_32B_SERIES_1) || defined(_SILICON_LABS_32B_SERIES_2_CONFIG_1)
      // Although 0 is a legitimate power on non-2.4 LP PA's and can be set via
      // "RAIL_SetTxPower(railHandle, 0)" it is MUCH lower than power
      // level 1 (approximately -50 dBm). Including it in the piecewise
      // linear fit would skew the curve substantially, so we exclude it
      // from the conversion.
      if (powerLevel == 0U) {
        return -500;
      }
#endif

      RAIL_TxPowerCurveAlt_t const *powerCurve = modeInfo->conversion.powerCurve;
      // Check for a valid powerCurve pointer before using it
      if (powerCurve == NULL) {
        return RAIL_TX_POWER_MIN;
      }

      RAIL_TxPowerCurveSegment_t const *powerParams = powerCurve->powerParams;

      // Hard code the extremes (i.e. don't use the curve fit) in order
      // to make it clear that we are reaching the extent of the chip's
      // capabilities
      if (powerLevel <= modeInfo->min) {
        return powerCurve->minPower;
      } else if (powerLevel >= modeInfo->max) {
        return powerCurve->maxPower;
      } else {
        // Power level is within bounds (MISRA required else)
      }

      // Figure out which parameter to use based on the power level
      uint8_t x = 0;
      uint8_t upperBound = modeInfo->segments - 1U;

      // If the first curve segment starts with RAIL_TX_POWER_LEVEL_INVALID,
      // then it is an additional curve segment that stores maxpower and increment
      // (in deci-dBm) used to generate the curves.
      // The extra info segment is present only if the curves were generated using
      // values other than default - RAIL_TX_POWER_CURVE_DEFAULT_MAX and
      // RAIL_TX_POWER_CURVE_DEFAULT_INCREMENT.
      if ((powerParams[0].maxPowerLevel) == RAIL_TX_POWER_LEVEL_INVALID) {
        x = 1U; // skip over the first entry
      }

      for (; x < upperBound; x++) {
        if (powerParams[x + 1U].maxPowerLevel < powerLevel) {
          break;
        }
      }
      int32_t power;
      power = ((1000 * (int32_t)(powerLevel)) - powerParams[x].intercept);
      power = ((power + ((int32_t)powerParams[x].slope / 2)) / (int32_t)powerParams[x].slope);

      if (power > powerCurve->maxPower) {
        return powerCurve->maxPower;
      } else if (power < powerCurve->minPower) {
        return powerCurve->minPower;
      } else {
        return (RAIL_TxPower_t)power;
      }
    }
  }
  return RAIL_TX_POWER_MIN;
}

#ifdef RAIL_PA_CONVERSIONS_WEAK
__WEAK
#endif
RAIL_Status_t RAIL_GetTxPowerCurveLimits(RAIL_Handle_t railHandle,
                                         RAIL_TxPowerMode_t mode,
                                         RAIL_TxPower_t *maxPower,
                                         RAIL_TxPower_t *increment)
{
  (void)railHandle;
  if ((mode < sizeof(supportedPaIndices))
      && (supportedPaIndices[mode] < RAIL_NUM_PA)) {
    RAIL_PaDescriptor_t const *modeInfo = &powerCurvesState.curves[supportedPaIndices[mode]];
#if RAIL_SUPPORTS_DBM_POWERSETTING_MAPPING_TABLE
    if (modeInfo->algorithm == RAIL_PA_ALGORITHM_DBM_POWERSETTING_MAPPING_TABLE) {
      *maxPower = modeInfo->maxPowerDbm;
      *increment = modeInfo->step;
      return RAIL_STATUS_NO_ERROR;
    }
#endif

    //The power max info only for available Linear fit
    if (modeInfo->algorithm == RAIL_PA_ALGORITHM_MAPPING_TABLE) {
      return RAIL_STATUS_INVALID_CALL;
    }
    *maxPower = RAIL_TX_POWER_CURVE_DEFAULT_MAX;
    *increment = RAIL_TX_POWER_CURVE_DEFAULT_INCREMENT;
    RAIL_TxPowerCurveAlt_t const *paParams = modeInfo->conversion.powerCurve;
    if ((paParams->powerParams[0].maxPowerLevel) == RAIL_TX_POWER_LEVEL_INVALID) {
      *maxPower = paParams->powerParams[0].slope;
      *increment = (RAIL_TxPower_t)paParams->powerParams[0].intercept;
    }
    return RAIL_STATUS_NO_ERROR;
  }
  return RAIL_STATUS_INVALID_PARAMETER;
}

// This macro is defined when Silicon Labs builds curves into the library as WEAK
// to ensure it can be overriden by customer versions of these functions. It
// should *not* be defined in a customer build.
#if !defined(RAIL_PA_CONVERSIONS_WEAK) && !defined(HAL_CONFIG)

#include "sl_rail_util_pa_config.h"

void sl_rail_util_pa_init(void)
{
#if SL_RAIL_UTIL_PA_VOLTAGE_MV > 1800
  (void)RAIL_InitTxPowerCurvesAlt(&RAIL_TxPowerCurvesVbat);
#else
  (void)RAIL_InitTxPowerCurvesAlt(&RAIL_TxPowerCurvesDcdc);
#endif
#if SL_RAIL_UTIL_PA_CALIBRATION_ENABLE
  RAIL_EnablePaCal(true);
#else
  RAIL_EnablePaCal(false);
#endif
}

#if RAIL_SUPPORTS_2P4GHZ_BAND
static RAIL_TxPowerConfig_t txPowerConfig2p4Ghz = {
  .mode = SL_RAIL_UTIL_PA_SELECTION_2P4GHZ,
  .voltage = SL_RAIL_UTIL_PA_VOLTAGE_MV,
  .rampTime = SL_RAIL_UTIL_PA_RAMP_TIME_US,
};
#endif
RAIL_TxPowerConfig_t *sl_rail_util_pa_get_tx_power_config_2p4ghz(void)
{
#if RAIL_SUPPORTS_2P4GHZ_BAND
  return &txPowerConfig2p4Ghz;
#else
  return NULL;
#endif
}

#if RAIL_SUPPORTS_SUBGHZ_BAND
static RAIL_TxPowerConfig_t txPowerConfigSubGhz = {
  .mode = SL_RAIL_UTIL_PA_SELECTION_SUBGHZ,
  .voltage = SL_RAIL_UTIL_PA_VOLTAGE_MV,
  .rampTime = SL_RAIL_UTIL_PA_RAMP_TIME_US,
};
#endif
RAIL_TxPowerConfig_t *sl_rail_util_pa_get_tx_power_config_subghz(void)
{
#if RAIL_SUPPORTS_SUBGHZ_BAND
  return &txPowerConfigSubGhz;
#else
  return NULL;
#endif
}

#if RAIL_SUPPORTS_OFDM_PA
#ifndef SL_RAIL_UTIL_PA_SELECTION_OFDM
#define SL_RAIL_UTIL_PA_SELECTION_OFDM RAIL_TX_POWER_MODE_OFDM_PA_POWERSETTING_TABLE
#endif
static RAIL_TxPowerConfig_t txPowerConfigOFDM = {
  .mode = SL_RAIL_UTIL_PA_SELECTION_OFDM,
  .voltage = SL_RAIL_UTIL_PA_VOLTAGE_MV,
};
#endif // RAIL_SUPPORTS_OFDM_PA
RAIL_TxPowerConfig_t *sl_rail_util_pa_get_tx_power_config_ofdm(void)
{
#if RAIL_SUPPORTS_OFDM_PA
  return &txPowerConfigOFDM;
#else
  return NULL;
#endif // RAIL_SUPPORTS_OFDM_PA
}

void sl_rail_util_pa_on_channel_config_change(RAIL_Handle_t rail_handle,
                                              const RAIL_ChannelConfigEntry_t *entry)
{
  if (!RAIL_IsPaAutoModeEnabled(rail_handle)) {
    RAIL_TxPowerConfig_t currentTxPowerConfig;
    RAIL_TxPowerConfig_t *newTxPowerConfigPtr;
    RAIL_Status_t status;

    // Get current TX Power Config.
    status = RAIL_GetTxPowerConfig(rail_handle, &currentTxPowerConfig);
    if (status != RAIL_STATUS_NO_ERROR) {
      while (true) {
      } // Error: Can't get TX Power Config
    }

#if RAIL_SUPPORTS_DUAL_BAND
    // Determine new TX Power Config.
    if (entry->baseFrequency < 1000000000UL) {
      newTxPowerConfigPtr = &txPowerConfigSubGhz;
    } else {
      newTxPowerConfigPtr = &txPowerConfig2p4Ghz;
    }
#else
    (void) entry;
#if RAIL_SUPPORTS_2P4GHZ_BAND
    newTxPowerConfigPtr = &txPowerConfig2p4Ghz;
#else
    newTxPowerConfigPtr = &txPowerConfigSubGhz;
#endif
#endif

#if RAIL_IEEE802154_SUPPORTS_DUAL_PA_CONFIG
    if (currentTxPowerConfig.mode == RAIL_TX_POWER_MODE_NONE) {
#if RAIL_SUPPORTS_OFDM_PA
      if (RAIL_SupportsTxPowerModeAlt(rail_handle,
                                      &txPowerConfigOFDM.mode,
                                      NULL, NULL)) {
        // Apply OFDM Power Config.
        status = RAIL_ConfigTxPower(rail_handle, &txPowerConfigOFDM);
        if (status != RAIL_STATUS_NO_ERROR) {
          while (true) {
          } // Error: Can't set TX Power Config
        }
        // Set default TX power after RAIL_ConfigTxPower.
        status = RAIL_SetTxPowerDbm(rail_handle, SL_RAIL_UTIL_PA_POWER_DECI_DBM);
        if (status != RAIL_STATUS_NO_ERROR) {
          while (true) {
          } // Error: Can't set TX Power
        }
      }
#endif // RAIL_SUPPORTS_OFDM_PA
      // Apply FSK Power Config.
      status = RAIL_ConfigTxPower(rail_handle, newTxPowerConfigPtr);
      if (status != RAIL_STATUS_NO_ERROR) {
        while (true) {
        } // Error: Can't set TX Power Config
      }
      // Set default TX power after RAIL_ConfigTxPower.
      status = RAIL_SetTxPowerDbm(rail_handle, SL_RAIL_UTIL_PA_POWER_DECI_DBM);
      if (status != RAIL_STATUS_NO_ERROR) {
        while (true) {
        } // Error: Can't set TX Power
      }
    }
#else
    // Call RAIL_ConfigTxPower only if TX Power Config mode has changed.
    if (currentTxPowerConfig.mode != newTxPowerConfigPtr->mode) {
      // Save current TX power before RAIL_ConfigTxPower (because not preserved).
      RAIL_TxPower_t txPowerDeciDbm;
      if (currentTxPowerConfig.mode == RAIL_TX_POWER_MODE_NONE) {
        txPowerDeciDbm = SL_RAIL_UTIL_PA_POWER_DECI_DBM;
      } else {
        txPowerDeciDbm = RAIL_GetTxPowerDbm(rail_handle);
      }

      // Apply new TX Power Config.
      status = RAIL_ConfigTxPower(rail_handle, newTxPowerConfigPtr);
      if (status != RAIL_STATUS_NO_ERROR) {
        while (true) {
        } // Error: Can't set TX Power Config
      }
      // Restore TX power after RAIL_ConfigTxPower.
      status = RAIL_SetTxPowerDbm(rail_handle, txPowerDeciDbm);
      if (status != RAIL_STATUS_NO_ERROR) {
        while (true) {
        } // Error: Can't set TX Power
      }
      // If requested a HIGHEST setting, update it with the real one selected
      // to short-circuit the next time through here since HIGHEST never
      // matches the real PA returned by RAIL_GetTxPowerConfig(), causing
      // reconfiguration of the same PA on every callback.
      if (false
         #ifdef  RAIL_TX_POWER_MODE_2P4GIG_HIGHEST
          || (newTxPowerConfigPtr->mode == RAIL_TX_POWER_MODE_2P4GIG_HIGHEST)
         #endif
         #ifdef  RAIL_TX_POWER_MODE_SUBGIG_HIGHEST
          || (newTxPowerConfigPtr->mode == RAIL_TX_POWER_MODE_SUBGIG_HIGHEST)
         #endif
          ) {
        (void) RAIL_GetTxPowerConfig(rail_handle, &currentTxPowerConfig);
        newTxPowerConfigPtr->mode = currentTxPowerConfig.mode;
      }
    }
#endif
  } // !RAIL_IsPaAutoModeEnabled
}
#endif // !RAIL_PA_CONVERSIONS_WEAK
