/***************************************************************************//**
 * @file
 * @brief Pulse Counter (PCNT) peripheral API
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
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

#include "em_pcnt.h"
#if defined(PCNT_COUNT) && (PCNT_COUNT > 0)

#include "em_cmu.h"
#include "sl_assert.h"
#include "em_bus.h"

/***************************************************************************//**
 * @addtogroup pcnt PCNT - Pulse Counter
 * @brief Pulse Counter (PCNT) Peripheral API
 * @details
 *  This module contains functions to control the PCNT peripheral of Silicon
 *  Labs 32-bit MCUs and SoCs. The PCNT decodes incoming pulses. The module has
 *  a quadrature mode which may be used to decode the speed and direction of a
 *  mechanical shaft.
 * @{
 ******************************************************************************/

/*******************************************************************************
 *******************************   DEFINES   ***********************************
 ******************************************************************************/

/** @cond DO_NOT_INCLUDE_WITH_DOXYGEN */

/** Validation of the PCNT register block pointer reference for assert statements. */
#if (PCNT_COUNT == 1)
#define PCNT_REF_VALID(ref)    ((ref) == PCNT0)
#elif (PCNT_COUNT == 2)
#define PCNT_REF_VALID(ref)    (((ref) == PCNT0) || ((ref) == PCNT1))
#elif (PCNT_COUNT == 3)
#define PCNT_REF_VALID(ref)    (((ref) == PCNT0) || ((ref) == PCNT1) \
                                || ((ref) == PCNT2))
#else
#error "Undefined number of pulse counters (PCNT)."
#endif

/** @endcond */

/*******************************************************************************
 **************************   LOCAL VARIABLES   ********************************
 ******************************************************************************/
#if defined(_SILICON_LABS_32B_SERIES_2)
static PCNT_CntEvent_TypeDef initCntEvent;
static PCNT_CntEvent_TypeDef initAuxCntEvent;
#endif

/*******************************************************************************
 **************************   LOCAL FUNCTIONS   ********************************
 ******************************************************************************/

/** @cond DO_NOT_INCLUDE_WITH_DOXYGEN */

#if defined(_SILICON_LABS_32B_SERIES_0) || defined(_SILICON_LABS_32B_SERIES_1)
/***************************************************************************//**
 * @brief
 *   Map PCNT structure into an instance number.
 *
 * @param[in] pcnt
 *   A pointer to the PCNT peripheral register block.
 *
 * @return
 *   An instance number.
 ******************************************************************************/
__STATIC_INLINE unsigned int PCNT_Map(PCNT_TypeDef *pcnt)
{
  return ((uint32_t)pcnt - PCNT0_BASE) / 0x400;
}
#endif
/** @endcond */

/*******************************************************************************
 **************************   GLOBAL FUNCTIONS   *******************************
 ******************************************************************************/

/***************************************************************************//**
 * @brief
 *   Reset PCNT counters and TOP register.
 *
 * @note
 *   Notice that special SYNCBUSY handling is not applicable for the RSTEN
 *   bit of the control register, so we don't need to wait for it when only
 *   modifying RSTEN. (It would mean undefined wait time if clocked by an external
 *   clock.) The SYNCBUSY bit will however be set, leading to a synchronization
 *   in the LF domain, with, in reality, no changes.
 *
 * @param[in] pcnt
 *   A pointer to the PCNT peripheral register block.
 ******************************************************************************/
void PCNT_CounterReset(PCNT_TypeDef *pcnt)
{
  EFM_ASSERT(PCNT_REF_VALID(pcnt));

#if defined(_SILICON_LABS_32B_SERIES_0) || defined(_SILICON_LABS_32B_SERIES_1)
  /* Enable reset of the CNT and TOP register. */
  BUS_RegBitWrite(&(pcnt->CTRL), _PCNT_CTRL_RSTEN_SHIFT, 1);

  /* Disable reset of the CNT and TOP register. */
  BUS_RegBitWrite(&(pcnt->CTRL), _PCNT_CTRL_RSTEN_SHIFT, 0);
#else
  /* Reset of the CNT and TOP register. */
  PCNT_Sync(pcnt, PCNT_SYNCBUSY_CMD);
  pcnt->CMD_SET = PCNT_CMD_CNTRST | PCNT_CMD_AUXCNTRST;
  PCNT_Sync(pcnt, PCNT_SYNCBUSY_TOP);
  pcnt->TOP = _PCNT_TOP_RESETVALUE;
#endif
}

/***************************************************************************//**
 * @brief
 *   Set PCNT operational mode.
 *
 * @details
 *   Notice that this function does not do any configuration. Setting operational
 *   mode is normally only required after initialization is done, and if not
 *   done as part of initialization or if requiring to disable/reenable pulse
 *   counter.
 *
 * @note
 *   This function may stall until synchronization to low-frequency domain is
 *   completed. For that reason, it should normally not be used when
 *   an external clock is used for the PCNT module, since stall time may be
 *   undefined.
 *
 * @param[in] pcnt
 *   A pointer to the PCNT peripheral register block.
 *
 * @param[in] mode
 *   An operational mode to use for PCNT.
 ******************************************************************************/
void PCNT_Enable(PCNT_TypeDef *pcnt, PCNT_Mode_TypeDef mode)
{
  uint32_t tmp;

  EFM_ASSERT(PCNT_REF_VALID(pcnt));

  /* Set as specified. */
#if defined(_SILICON_LABS_32B_SERIES_0) || defined(_SILICON_LABS_32B_SERIES_1)
  tmp  = pcnt->CTRL & ~_PCNT_CTRL_MODE_MASK;
  tmp |= (uint32_t)mode << _PCNT_CTRL_MODE_SHIFT;

  /* LF register about to be modified requires sync; busy check. */
  PCNT_Sync(pcnt, PCNT_SYNCBUSY_CTRL);
  pcnt->CTRL = tmp;
#else
  /* Disable module if disable mode is passed. */
  if (mode == pcntModeDisable) {
    PCNT_Sync(pcnt, _PCNT_SYNCBUSY_MASK);
    pcnt->EN_CLR = PCNT_EN_EN;
#if defined(_PCNT_EN_DISABLING_MASK)
    while (pcnt->EN & _PCNT_EN_DISABLING_MASK) {
    }
#endif
    return;
  }
  /* Check if given mode is same as already configured. */
  tmp = (pcnt->CFG & _PCNT_CFG_MODE_MASK) >> _PCNT_CFG_MODE_SHIFT;
  if (tmp != mode) {
    PCNT_Sync(pcnt, _PCNT_SYNCBUSY_MASK);
    pcnt->EN_CLR = PCNT_EN_EN;
#if defined(_PCNT_EN_DISABLING_MASK)
    while (pcnt->EN & _PCNT_EN_DISABLING_MASK) {
    }
#endif
    pcnt->CFG_SET = (uint32_t)mode << _PCNT_CFG_MODE_SHIFT;
  }
  /* Enable module */
  pcnt->EN_SET = PCNT_EN_EN;
  /* Start Counters*/
  if (initCntEvent != pcntCntEventNone) {
    PCNT_StartMainCnt(pcnt);
  }
  if (initAuxCntEvent != pcntCntEventNone) {
    PCNT_StartAuxCnt(pcnt);
  }

#endif
}

/***************************************************************************//**
 * @brief
 *   Returns if the PCNT module is enabled or not.
 *
 * @details
 *   Notice that this function does not do any configuration.
 *
 * @param[in] pcnt
 *   A pointer to the PCNT peripheral register block.
 *
 * @return Returns TRUE if the module is enabled.
 ******************************************************************************/
bool PCNT_IsEnabled(PCNT_TypeDef *pcnt)
{
  EFM_ASSERT(PCNT_REF_VALID(pcnt));

#if defined(_SILICON_LABS_32B_SERIES_0) || defined(_SILICON_LABS_32B_SERIES_1)
  return ((pcnt->CTRL & _PCNT_CTRL_MODE_MASK) != PCNT_CTRL_MODE_DISABLE);
#else
  return (pcnt->EN & _PCNT_EN_EN_MASK);
#endif
}

/***************************************************************************//**
 * @brief
 *   Set the counter and top values.
 *
 * @details
 *   The pulse counter is disabled while changing these values and reenabled
 *   (if originally enabled) when values have been set.
 *
 * @note
 *   This function will stall until synchronization to low-frequency domain is
 *   completed. For that reason, it should normally not be used when
 *   an external clock is used for the PCNT module, since stall time may be
 *   undefined. The counter should normally only be set when
 *   operating in (or about to enable) #pcntModeOvsSingle mode.
 *
 * @param[in] pcnt
 *   A pointer to the PCNT peripheral register block.
 *
 * @param[in] count
 *   A value to set in the counter register.
 *
 * @param[in] top
 *   A value to set in the top register.
 ******************************************************************************/
void PCNT_CounterTopSet(PCNT_TypeDef *pcnt, uint32_t count, uint32_t top)
{
#if defined(_SILICON_LABS_32B_SERIES_0) || defined(_SILICON_LABS_32B_SERIES_1)
  uint32_t ctrl;
#endif

  EFM_ASSERT(PCNT_REF_VALID(pcnt));

#ifdef PCNT0
  if (PCNT0 == pcnt) {
    EFM_ASSERT((1 << PCNT0_CNT_SIZE) > count);
    EFM_ASSERT((1 << PCNT0_CNT_SIZE) > top);
  }
#endif

#ifdef PCNT1
  if (PCNT1 == pcnt) {
    EFM_ASSERT((1 << PCNT1_CNT_SIZE) > count);
    EFM_ASSERT((1 << PCNT1_CNT_SIZE) > top);
  }
#endif

#ifdef PCNT2
  if (PCNT2 == pcnt) {
    EFM_ASSERT((1 << PCNT2_CNT_SIZE) > count);
    EFM_ASSERT((1 << PCNT2_CNT_SIZE) > top);
  }
#endif

#if defined(_SILICON_LABS_32B_SERIES_0) || defined(_SILICON_LABS_32B_SERIES_1)
  /* Keep the current control setting, must be restored. */
  ctrl = pcnt->CTRL;

  /* If enabled, disable pulse counter before changing values. */
  if ((ctrl & _PCNT_CTRL_MODE_MASK) != PCNT_CTRL_MODE_DISABLE) {
    PCNT_Sync(pcnt, PCNT_SYNCBUSY_CTRL);
    pcnt->CTRL = (ctrl & ~_PCNT_CTRL_MODE_MASK) | PCNT_CTRL_MODE_DISABLE;
  }

  /* Load into TOPB. */
  PCNT_Sync(pcnt, PCNT_SYNCBUSY_TOPB);
  pcnt->TOPB = count;

  /* Load TOPB value into TOP. */
  PCNT_Sync(pcnt, PCNT_SYNCBUSY_TOPB | PCNT_SYNCBUSY_CMD);

  /* This bit has no effect on rev. C and onwards parts - for compatibility. */
  pcnt->CMD = PCNT_CMD_LTOPBIM;
  PCNT_Sync(pcnt, PCNT_SYNCBUSY_CMD);

  /* Load TOP into CNT. */
  pcnt->CMD = PCNT_CMD_LCNTIM;

  /* Restore TOP. ('count' setting has been loaded into pcnt->TOP, better
   * to use 'top' than pcnt->TOP in compare, since latter may not
   * be visible yet.) */
  if (top != count) {
    /* Wait for the command to sync LCNTIM before setting TOPB. */
    PCNT_Sync(pcnt, PCNT_SYNCBUSY_CMD);

    /* Load into TOPB. No need to check for TOPB sync complete, which
     * has been ensured above. */
    pcnt->TOPB = top;

    /* Load TOPB value into TOP. */
    PCNT_Sync(pcnt, PCNT_SYNCBUSY_TOPB | PCNT_SYNCBUSY_CMD);
    pcnt->CMD = PCNT_CMD_LTOPBIM;
  }

  /* Reenable if it was enabled. */
  PCNT_Enable(pcnt, (PCNT_Mode_TypeDef)(ctrl & _PCNT_CTRL_MODE_MASK));
  if ((ctrl & _PCNT_CTRL_MODE_MASK) != PCNT_CTRL_MODE_DISABLE) {
    PCNT_Sync(pcnt, PCNT_SYNCBUSY_CTRL | PCNT_SYNCBUSY_CMD);
    pcnt->CTRL = ctrl;
  }
#else
  /* Load into TOP. */
  PCNT_Sync(pcnt, PCNT_SYNCBUSY_TOP);
  pcnt->TOP = count;
  PCNT_Sync(pcnt, PCNT_SYNCBUSY_TOP);

  /* Load TOP into CNT. */
  PCNT_Sync(pcnt, PCNT_SYNCBUSY_CMD);
  pcnt->CMD = PCNT_CMD_LCNTIM;

  if (top != count) {
    /* Wait for the command to sync LCNTIM before setting TOPB. */
    PCNT_Sync(pcnt, PCNT_SYNCBUSY_CMD);

    pcnt->TOP = top;
  }
#endif
}

#if defined(_PCNT_INPUT_MASK) || defined(_SILICON_LABS_32B_SERIES_2)
/***************************************************************************//**
 * @brief
 *   Enable/disable the selected PRS input of PCNT.
 *
 * @details
 *   Notice that this function does not do any configuration.
 *
 * @param[in] pcnt
 *   A pointer to the PCNT peripheral register block.
 *
 * @param[in] prsInput
 *   PRS input (S0 or S1) of the selected PCNT module.
 *
 * @param[in] enable
 *   Set to true to enable, false to disable the selected PRS input.
 ******************************************************************************/
void PCNT_PRSInputEnable(PCNT_TypeDef *pcnt,
                         PCNT_PRSInput_TypeDef prsInput,
                         bool enable)
{
  EFM_ASSERT(PCNT_REF_VALID(pcnt));

#if defined(_SILICON_LABS_32B_SERIES_2)
  bool module_enable = PCNT_IsEnabled(pcnt);

  /* Disable module before writing to CFG register. */
  if (module_enable == true) {
    PCNT_Sync(pcnt, _PCNT_SYNCBUSY_MASK);
  }

  pcnt->EN_CLR = PCNT_EN_EN;
#if defined(_PCNT_EN_DISABLING_MASK)
  while (pcnt->EN & _PCNT_EN_DISABLING_MASK) {
  }
#endif
#endif

  /* Enable/disable the selected PRS input on the selected PCNT module. */
  switch (prsInput) {
    /* Enable/disable PRS input S0. */
    case pcntPRSInputS0:
#if defined(_PCNT_INPUT_MASK)
      BUS_RegBitWrite(&(pcnt->INPUT), _PCNT_INPUT_S0PRSEN_SHIFT, enable);
#elif defined(_SILICON_LABS_32B_SERIES_2)
      BUS_RegBitWrite(&(pcnt->CFG), _PCNT_CFG_S0PRSEN_SHIFT, enable);
#endif
      break;

    /* Enable/disable PRS input S1. */
    case pcntPRSInputS1:
#if defined(_PCNT_INPUT_MASK)
      BUS_RegBitWrite(&(pcnt->INPUT), _PCNT_INPUT_S1PRSEN_SHIFT, enable);
#elif defined(_SILICON_LABS_32B_SERIES_2)
      BUS_RegBitWrite(&(pcnt->CFG), _PCNT_CFG_S1PRSEN_SHIFT, enable);
#endif
      break;

    /* An invalid parameter, asserted. */
    default:
      EFM_ASSERT(0);
      break;
  }

#if defined(_SILICON_LABS_32B_SERIES_2)
  /* Re-Enable if necessary the PCNT module after change. */
  if (module_enable == true) {
    pcnt->EN_SET = PCNT_EN_EN;
  }
#endif
}
#endif

#if defined(_SILICON_LABS_32B_SERIES_0) || defined(_SILICON_LABS_32B_SERIES_1)
/***************************************************************************//**
 * @brief
 *   PCNT register synchronization freeze control.
 *
 * @details
 *   Some PCNT registers require synchronization into the low-frequency (LF)
 *   domain. The freeze feature allows for several registers to be
 *   modified before passing them to the LF domain simultaneously, which
 *   takes place when the freeze mode is disabled.
 *
 * @note
 *   When enabling freeze mode, this function will wait for all current
 *   ongoing PCNT synchronization to the LF domain to complete (normally
 *   synchronization will not be in progress). However, for this reason, when
 *   using freeze mode, modifications of registers requiring the LF synchronization
 *   should be done within one freeze enable/disable block to avoid unnecessary
 *   stalling.
 *
 * @param[in] pcnt
 *   A pointer to the PCNT peripheral register block.
 *
 * @param[in] enable
 *   @li True - enable freeze, modified registers are not propagated to the
 *       LF domain.
 *   @li False - disables freeze, modified registers are propagated to LF
 *       domain.
 ******************************************************************************/
void PCNT_FreezeEnable(PCNT_TypeDef *pcnt, bool enable)
{
  EFM_ASSERT(PCNT_REF_VALID(pcnt));

  if (enable) {
    /* Wait for any ongoing LF synchronization to complete to
     * protect against the rare case when a user:
     * - modifies a register requiring LF sync
     * - then enables freeze before LF sync completed
     * - then modifies the same register again
     * since modifying a register while it is in sync progress should be
     * avoided. */
    while (pcnt->SYNCBUSY) {
    }

    pcnt->FREEZE = PCNT_FREEZE_REGFREEZE;
  } else {
    pcnt->FREEZE = 0;
  }
}
#endif

/***************************************************************************//**
 * @brief
 *   Initialize the pulse counter.
 *
 * @details
 *   This function will configure the pulse counter. The clock selection is
 *   configured as follows, depending on operational mode:
 *
 *   @li #pcntModeOvsSingle - Use LFACLK.
 *   @li #pcntModeExtSingle - Use external PCNTn_S0 pin.
 *   @li #pcntModeExtQuad - Use external PCNTn_S0 pin.
 *
 *   Notice that the LFACLK must be enabled in all modes, since some basic setup
 *   is done with this clock even if the external pin clock usage mode is chosen.
 *   The pulse counter clock for the selected instance must also be enabled
 *   prior to initialization.
 *
 *   Notice that pins used by the PCNT module must be properly configured
 *   by the user explicitly through setting the ROUTE register for
 *   the PCNT to work as intended.
 *
 *   Writing to CNT will not occur in external clock modes (EXTCLKQUAD and
 *   EXTCLKSINGLE) because the external clock rate is unknown. The user should
 *   handle it manually depending on the application.
 *
 *   TOPB is written for all modes but in external clock mode it will take
 *   3 external clock cycles to sync to TOP.
 *
 *
 * @note
 *   Initializing requires synchronization into the low-frequency domain. This
 *   may cause a delay.
 *
 * @param[in] pcnt
 *   A pointer to the PCNT peripheral register block.
 *
 * @param[in] init
 *   A pointer to the initialization structure.
 ******************************************************************************/
void PCNT_Init(PCNT_TypeDef *pcnt, const PCNT_Init_TypeDef *init)
{
  unsigned int inst = 0;
  uint32_t     tmp;

  (void)&tmp;

  EFM_ASSERT(PCNT_REF_VALID(pcnt));

#ifdef PCNT0
  if (PCNT0 == pcnt) {
    EFM_ASSERT((1 << PCNT0_CNT_SIZE) > init->counter);
    EFM_ASSERT((1 << PCNT0_CNT_SIZE) > init->top);
  }
#endif

#ifdef PCNT1
  if (PCNT1 == pcnt) {
    EFM_ASSERT((1 << PCNT1_CNT_SIZE) > init->counter);
    EFM_ASSERT((1 << PCNT1_CNT_SIZE) > init->top);
  }
#endif

#ifdef PCNT2
  if (PCNT2 == pcnt) {
    EFM_ASSERT((1 << PCNT2_CNT_SIZE) > init->counter);
    EFM_ASSERT((1 << PCNT2_CNT_SIZE) > init->top);
  }
#endif

#if defined(_SILICON_LABS_32B_SERIES_0) || defined(_SILICON_LABS_32B_SERIES_1)
  /* Map the pointer to an instance. */
  inst = PCNT_Map(pcnt);
#endif

#if defined(_PCNT_INPUT_MASK)
  /* Selecting the PRS channels for the PRS input sources of the PCNT. These are
   * written with a Read-Modify-Write sequence to keep the value of the
   * input enable bits which can be modified using PCNT_PRSInputEnable(). */
  tmp = pcnt->INPUT & ~(_PCNT_INPUT_S0PRSSEL_MASK | _PCNT_INPUT_S1PRSSEL_MASK);
  tmp |= ((uint32_t)init->s0PRS << _PCNT_INPUT_S0PRSSEL_SHIFT)
         | ((uint32_t)init->s1PRS << _PCNT_INPUT_S1PRSSEL_SHIFT);
  pcnt->INPUT = tmp;
#endif

#if defined(_SILICON_LABS_32B_SERIES_0) || defined(_SILICON_LABS_32B_SERIES_1)
  /* Build the CTRL setting, except for mode. */
  tmp = 0;
  if (init->negEdge) {
    tmp |= PCNT_CTRL_EDGE_NEG;
  }

  if (init->countDown) {
    tmp |= PCNT_CTRL_CNTDIR_DOWN;
  }

#if defined(PCNT_CTRL_FILT)
  if (init->filter) {
    tmp |= PCNT_CTRL_FILT;
  }
#endif

#if defined(PCNT_CTRL_HYST)
  if (init->hyst) {
    tmp |= PCNT_CTRL_HYST;
  }
#endif

#if defined(PCNT_CTRL_S1CDIR)
  if (init->s1CntDir) {
    tmp |= PCNT_CTRL_S1CDIR;
  }
#endif

  /* Configure counter events for regular and auxiliary counters. */
#if defined(_PCNT_CTRL_CNTEV_SHIFT)
  tmp |= ((uint32_t)init->cntEvent) << _PCNT_CTRL_CNTEV_SHIFT;
#endif

#if defined(_PCNT_CTRL_AUXCNTEV_SHIFT)
  {
    /* Modify the auxCntEvent value before writing to the AUXCNTEV field in
       the CTRL register because the AUXCNTEV field values are different than
       the CNTEV field values, and cntEvent and auxCntEvent are of the same type
       PCNT_CntEvent_TypeDef.
     */
    uint32_t auxCntEventField = 0; /* Get rid of compiler warning. */
    switch (init->auxCntEvent) {
      case pcntCntEventBoth:
        auxCntEventField = pcntCntEventNone;
        break;

#if defined(_PCNT_CTRL_CNTEV_NONE)
      case pcntCntEventNone:
        auxCntEventField = pcntCntEventBoth;
        break;
#endif

      case pcntCntEventUp:
      case pcntCntEventDown:
        auxCntEventField = init->auxCntEvent;
        break;

      default:
        /* An invalid parameter, asserted. */
        EFM_ASSERT(0);
        break;
    }
    tmp |= auxCntEventField << _PCNT_CTRL_AUXCNTEV_SHIFT;
  }
#endif

  /* Reset the pulse counter while changing the clock source. The reset bit */
  /* is asynchronous, no need to check for SYNCBUSY. */
  BUS_RegBitWrite(&(pcnt->CTRL), _PCNT_CTRL_RSTEN_SHIFT, 1);

  /* Select LFACLK to clock in the control setting. */
  CMU_PCNTClockExternalSet(inst, false);

  /* Handling depends on whether using an external clock. */
  switch (init->mode) {
    case pcntModeExtSingle:
    case pcntModeExtQuad:
      tmp |= ((uint32_t)init->mode) << _PCNT_CTRL_MODE_SHIFT;

      /* In most cases, the SYNCBUSY bit is set due to the reset bit set and waiting
       * for asynchronous reset bit is strictly not necessary.
       * In theory, other operations on CTRL register may have been done
       * outside this function, so wait. */
      PCNT_Sync(pcnt, PCNT_SYNCBUSY_CTRL);

      /* Enable PCNT Clock Domain Reset. The PCNT must be in reset before changing
       * the clock source to an external clock. */
      pcnt->CTRL = PCNT_CTRL_RSTEN;

      /* Wait until the CTRL write is synchronized into the LF domain. */
      PCNT_Sync(pcnt, PCNT_SYNCBUSY_CTRL);

      /* Change to the external clock BEFORE disabling reset. */
      CMU_PCNTClockExternalSet(inst, true);

      /* Write to TOPB. If using the external clock, TOPB will sync to TOP at the same
       * time as the mode ensuring that if the user chooses to count
       * down, the first "countable" pulse will make CNT go to TOP and not 0xFF
       * (default TOP value). */
      pcnt->TOPB = init->top;

      /* This bit has no effect on rev. C and onwards parts - for compatibility. */
      pcnt->CMD = PCNT_CMD_LTOPBIM;

      /* Write the CTRL register with the configurations.
       * This should be written after TOPB in the eventuality of a pulse between
       * these two writes that would cause the CTRL register to be synced one
       * clock cycle earlier than the TOPB. */
      pcnt->CTRL = tmp;

      /* There are no syncs for TOP, CMD, or CTRL because the clock rate is unknown
       * and the program could stall.
       * These will be synced within 3 clock cycles of the external clock.  /
       * For the same reason CNT cannot be written here. */
      break;

    /* pcntModeDisable */
    /* pcntModeOvsSingle */
    /* pcntModeOvsQuadx */
    default:
      /* No need to set disabled mode if already disabled. */
      if ((pcnt->CTRL & _PCNT_CTRL_MODE_MASK) != PCNT_CTRL_MODE_DISABLE) {
        /* Set control to disabled mode and leave reset on until ensured disabled.
         * No need to wait for CTRL SYNCBUSY completion. It was
         * triggered by the reset bit above, which is asynchronous. */
        pcnt->CTRL = tmp | PCNT_CTRL_MODE_DISABLE | PCNT_CTRL_RSTEN;

        /* Wait until the CTRL write is synchronized into the LF domain before proceeding
         * to disable reset. */
        PCNT_Sync(pcnt, PCNT_SYNCBUSY_CTRL);
      }

      /* Disable reset bit. The counter should now be in disabled mode. */
      BUS_RegBitWrite(&(pcnt->CTRL), _PCNT_CTRL_RSTEN_SHIFT, 0);

      /* Set the counter and top values as specified. */
      PCNT_CounterTopSet(pcnt, init->counter, init->top);

      /* Enter oversampling mode if selected. */
      if (init->mode != pcntModeDisable) {
        PCNT_Sync(pcnt, PCNT_SYNCBUSY_CTRL);
        pcnt->CTRL = tmp | (init->mode << _PCNT_CTRL_MODE_SHIFT);
      }
      break;
  }

#else
  /* If PCNT is enabled wait for all SYNCBUSY signals to complete. */
  if (pcnt->EN == 1U) {
    PCNT_Sync(pcnt, _PCNT_SYNCBUSY_MASK);
  }

  /* Disable PCNT. */
  pcnt->EN_CLR = PCNT_EN_EN;
#if defined(_PCNT_EN_DISABLING_MASK)
  while (pcnt->EN & _PCNT_EN_DISABLING_MASK) {
  }
#endif
  /* Build the CFG setting. */
  pcnt->CFG &= ~(_PCNT_CFG_DEBUGHALT_MASK | _PCNT_CFG_FILTEN_MASK | _PCNT_CFG_HYST_MASK);
  pcnt->CFG |= (((uint32_t)init->filter) << _PCNT_CFG_FILTEN_SHIFT)
               | (((uint32_t)init->hyst) << _PCNT_CFG_HYST_SHIFT)
               | (((uint32_t)init->debugHalt) << _PCNT_CFG_DEBUGHALT_SHIFT);

  /* Set Mode setting. */
  /* Write the CFG register with the configurations. */
  if (init->mode != pcntModeDisable) {
    pcnt->CFG = ((pcnt->CFG & (~_PCNT_CFG_MODE_MASK)) | (((uint32_t)init->mode) << _PCNT_CFG_MODE_SHIFT));
  }

  pcnt->EN_SET = PCNT_EN_EN;
  PCNT_Sync(pcnt, _PCNT_SYNCBUSY_MASK);

  /* Build the CTRL setting */
  tmp = (((uint32_t)init->negEdge) << _PCNT_CTRL_EDGE_SHIFT)
        | (((uint32_t)init->countDown) << _PCNT_CTRL_CNTDIR_SHIFT)
        | (((uint32_t)init->s1CntDir) << _PCNT_CTRL_S1CDIR_SHIFT);

  /* Configure counter events for regular and auxiliary counters. */
  if (init->cntEvent != PCNT_CNT_EVENT_NONE) {
    tmp |= ((uint32_t)init->cntEvent) << _PCNT_CTRL_CNTEV_SHIFT;
  }
  if (init->auxCntEvent != PCNT_CNT_EVENT_NONE) {
    tmp |= ((uint32_t)init->auxCntEvent) << _PCNT_CTRL_AUXCNTEV_SHIFT;
  }

  pcnt->CTRL = tmp;

  /* Set PRS inputs */
  EFM_ASSERT(init->s0PRS < PRS_ASYNC_CH_NUM);
  EFM_ASSERT(init->s1PRS < PRS_ASYNC_CH_NUM);
  PRS->CONSUMER_PCNT0_S0IN = init->s0PRS;
  PRS->CONSUMER_PCNT0_S1IN = init->s1PRS;

  if (init->mode == pcntModeExtSingle || init->mode == pcntModeExtQuad) {
    /* Enable PCNT Clock Domain Reset. The PCNT must be in reset before changing
       the clock source to an external clock. */
    pcnt->CMD_SET = PCNT_CMD_CORERST;
    /* Change to the external clock. */
    CMU_PCNTClockExternalSet(inst, true);
  } else {
    /* Change to the internal clock. */
    CMU_PCNTClockExternalSet(inst, false);
  }

  /* Start counter(s) */
  if (init->cntEvent != pcntCntEventNone) {
    PCNT_StartMainCnt(pcnt);
  }
  if (init->auxCntEvent != pcntCntEventNone) {
    PCNT_StartAuxCnt(pcnt);
  }

  PCNT_CounterTopSet(pcnt, init->counter, init->top);
  PCNT_TopBufferSet(pcnt, init->top);

  /* Save values of primary and auxiliary counter event. */
  initCntEvent = init->cntEvent;
  initAuxCntEvent = init->auxCntEvent;

  if (init->mode == pcntModeDisable) {
    /* Disable PCNT. */
    pcnt->EN_CLR = PCNT_EN_EN;
#if defined(_PCNT_EN_DISABLING_MASK)
    while (pcnt->EN & _PCNT_EN_DISABLING_MASK) {
    }
#endif
  }
#endif
}

/***************************************************************************//**
 * @brief
 *   Reset PCNT to the same state that it was in after a hardware reset.
 *
 * @details
 *   Notice the LFACLK must be enabled, since some basic reset is done with
 *   this clock. The pulse counter clock for the selected instance must also
 *   be enabled prior to initialization.
 *
 * @note
 *   The ROUTE register is NOT reset by this function to allow for
 *   centralized setup of this feature.
 *
 * @param[in] pcnt
 *   A pointer to the PCNT peripheral register block.
 ******************************************************************************/
void PCNT_Reset(PCNT_TypeDef *pcnt)
{
  unsigned int inst = 0;
  EFM_ASSERT(PCNT_REF_VALID(pcnt));

#if defined(_SILICON_LABS_32B_SERIES_0) || defined(_SILICON_LABS_32B_SERIES_1)
  /* A map pointer to the instance and clock information. */
  inst = PCNT_Map(pcnt);
  pcnt->IEN = _PCNT_IEN_RESETVALUE;

  /* Notice that special SYNCBUSY handling is not applicable for the RSTEN
   * bit of the control register, so no need to wait for it when only
   * modifying RSTEN. The SYNCBUSY bit will be set, leading to a
   * synchronization in the LF domain, with, in reality, no changes to the LF domain.
   * Enable reset of the CNT and TOP register. */
  BUS_RegBitWrite(&(pcnt->CTRL), _PCNT_CTRL_RSTEN_SHIFT, 1);

  /* Select LFACLK as default. */
  CMU_PCNTClockExternalSet(inst, false);

  PCNT_TopBufferSet(pcnt, _PCNT_TOPB_RESETVALUE);

  /* Reset CTRL leaving RSTEN set. */
  pcnt->CTRL = _PCNT_CTRL_RESETVALUE | PCNT_CTRL_RSTEN;

  /* Disable reset after CTRL register has been synchronized. */
  PCNT_Sync(pcnt, PCNT_SYNCBUSY_CTRL);
  BUS_RegBitWrite(&(pcnt->CTRL), _PCNT_CTRL_RSTEN_SHIFT, 0);

  /* Clear pending interrupts. */
  pcnt->IFC = _PCNT_IFC_MASK;

  /* Do not reset route register, setting should be done independently. */
#else
  /* Disable PCNT module. */
  PCNT_Sync(pcnt, _PCNT_SYNCBUSY_MASK);
  pcnt->EN_CLR = PCNT_EN_EN;

  /* Select LFACLK as default. */
  /* Recommended to switch to internal clock before reset. */
  CMU_PCNTClockExternalSet(inst, false);

  while (pcnt->EN & _PCNT_EN_DISABLING_MASK) {
  }

  /* Clear registers. */
  pcnt->SWRST_SET = PCNT_SWRST_SWRST;

  while (pcnt->SWRST & PCNT_SWRST_RESETTING) {
  }

#endif
}

#if defined(PCNT_OVSCFG_FILTLEN_DEFAULT) || defined(_SILICON_LABS_32B_SERIES_2)
/***************************************************************************//**
 * @brief
 *   Set the filter configuration.
 *
 * @details
 *   This function will configure the PCNT input filter when the PCNT mode is
 *   configured to take an LFA-derived clock as an input clock.
 *
 * @param[in] pcnt
 *   A pointer to the PCNT peripheral register block.
 *
 * @param[in] config
 *   A pointer to the configuration structure to be applied.
 *
 * @param[in] enable
 *   Indicates whether to enable or disable filtering.
 ******************************************************************************/
void PCNT_FilterConfiguration(PCNT_TypeDef *pcnt, const PCNT_Filter_TypeDef *config, bool enable)
{
  uint32_t ovscfg = 0;
#if defined(_SILICON_LABS_32B_SERIES_2)
  bool module_enable = false;
#endif

  EFM_ASSERT(PCNT_REF_VALID(pcnt));

#if defined(PCNT_OVSCFG_FILTLEN_DEFAULT)
  /* Construct the new filter setting value. */
  ovscfg  = ((config->filtLen & _PCNT_OVSCFG_FILTLEN_MASK) << _PCNT_OVSCFG_FILTLEN_SHIFT)
            | ((config->flutterrm & 0x1) << _PCNT_OVSCFG_FLUTTERRM_SHIFT);

  /* Set the new configuration. LF register requires sync check before writing. */
  PCNT_Sync(pcnt, PCNT_SYNCBUSY_OVSCFG);
  pcnt->OVSCFG = ovscfg;

  /* Set new state of the filter. LF register requires sync check before writing. */
  PCNT_Sync(pcnt, PCNT_SYNCBUSY_CTRL);
  if (enable) {
    pcnt->CTRL |= PCNT_CTRL_FILT;
  } else {
    pcnt->CTRL &= ~PCNT_CTRL_FILT;
  }

#elif  defined(_SILICON_LABS_32B_SERIES_2)
  /* Disable module before changing CFG register. */
  module_enable = PCNT_IsEnabled(pcnt);
  if (module_enable == true) {
    PCNT_Sync(pcnt, _PCNT_SYNCBUSY_MASK);
  }
  pcnt->EN_CLR = PCNT_EN_EN;
#if defined(_PCNT_EN_DISABLING_MASK)
  while (pcnt->EN & _PCNT_EN_DISABLING_MASK) {
  }
#endif
  /* Construct the new filter setting value. */
  ovscfg  = ((config->filtLen & _PCNT_OVSCTRL_FILTLEN_MASK) << _PCNT_OVSCTRL_FILTLEN_SHIFT)
            | ((config->flutterrm & 0x1) << _PCNT_OVSCTRL_FLUTTERRM_SHIFT);

  /* Set the new configuration. LF register requires sync check before writing. */
  PCNT_Sync(pcnt, PCNT_SYNCBUSY_OVSCTRL);
  pcnt->OVSCTRL = ovscfg;

  /* Set new state of the filter. */
  if (enable) {
    pcnt->CFG_SET = PCNT_CFG_FILTEN;
  } else {
    pcnt->CFG_CLR = PCNT_CFG_FILTEN;
  }

  /* Re-Enable module if necessary after change. */
  if (module_enable == true) {
    pcnt->EN_SET = PCNT_EN_EN;
  }
#endif
}
#endif

#if defined(PCNT_CTRL_TCCMODE_DEFAULT)
/***************************************************************************//**
 * @brief
 *   Set Triggered Compare and Clear configuration.
 *
 * @details
 *   This function will configure the PCNT TCC (Triggered Compare and Clear)
 *   module. This module can, upon a configurable trigger source, compare the
 *   current counter value with the configured TOP value. Upon match, the counter
 *   will be reset and the TCC PRS output and TCC interrupt flag will be set.
 *
 *   Since there is a comparison with the TOP value, the counter will not stop
 *   counting nor wrap when hitting the TOP value, but it will keep on counting
 *   until its maximum value. Then, it will not wrap, but stop counting
 *   and set the overflow flag.
 *
 * @param[in] pcnt
 *   A pointer to the PCNT peripheral register block.
 *
 * @param[in] config
 *   A pointer to the configuration structure to be applied.
 ******************************************************************************/
void PCNT_TCCConfiguration(PCNT_TypeDef *pcnt, const PCNT_TCC_TypeDef *config)
{
  uint32_t ctrl = 0;
  uint32_t mask = _PCNT_CTRL_TCCMODE_MASK
                  | _PCNT_CTRL_TCCPRESC_MASK
                  | _PCNT_CTRL_TCCCOMP_MASK
                  | _PCNT_CTRL_PRSGATEEN_MASK
                  | _PCNT_CTRL_TCCPRSPOL_MASK
                  | _PCNT_CTRL_TCCPRSSEL_MASK;

  EFM_ASSERT(PCNT_REF_VALID(pcnt));

  /* Construct the TCC part of the configuration register. */
  ctrl |= (config->mode          << _PCNT_CTRL_TCCMODE_SHIFT)   & _PCNT_CTRL_TCCMODE_MASK;
  ctrl |= (config->prescaler     << _PCNT_CTRL_TCCPRESC_SHIFT)  & _PCNT_CTRL_TCCPRESC_MASK;
  ctrl |= (config->compare       << _PCNT_CTRL_TCCCOMP_SHIFT)   & _PCNT_CTRL_TCCCOMP_MASK;
  ctrl |= (config->tccPRS        << _PCNT_CTRL_TCCPRSSEL_SHIFT) & _PCNT_CTRL_TCCPRSSEL_MASK;
  ctrl |= (config->prsPolarity   << _PCNT_CTRL_TCCPRSPOL_SHIFT) & _PCNT_CTRL_TCCPRSPOL_MASK;
  ctrl |= (config->prsGateEnable << _PCNT_CTRL_PRSGATEEN_SHIFT) & _PCNT_CTRL_PRSGATEEN_MASK;

  /* Load new TCC configuration to PCNT. LF register requires a sync check before write. */
  PCNT_Sync(pcnt, PCNT_SYNCBUSY_CTRL);
  pcnt->CTRL = (pcnt->CTRL & (~mask)) | ctrl;
}
#endif

/***************************************************************************//**
 * @brief
 *   Set top buffer value.
 *
 * @note
 *   This function may stall until synchronization to low-frequency domain is
 *   completed. For that reason, it should normally not be used when
 *   an external clock is used for the PCNT module since stall time may be
 *   undefined.
 *
 * @param[in] pcnt
 *   A pointer to the PCNT peripheral register block.
 *
 * @param[in] val
 *   A value to set in the top buffer register.
 ******************************************************************************/
void PCNT_TopBufferSet(PCNT_TypeDef *pcnt, uint32_t val)
{
  EFM_ASSERT(PCNT_REF_VALID(pcnt));

  /* LF register about to be modified require sync. busy check */
  PCNT_Sync(pcnt, PCNT_SYNCBUSY_TOPB);
  pcnt->TOPB = val;
}

/***************************************************************************//**
 * @brief
 *   Set the top value.
 *
 * @note
 *   This function will stall until synchronization to low-frequency domain is
 *   completed. For that reason, it should normally not be used when
 *   an external clock is used for the PCNT module since stall time may be
 *   undefined.
 *
 * @param[in] pcnt
 *   A pointer to the PCNT peripheral register block.
 *
 * @param[in] val
 *   A value to set in the top register.
 ******************************************************************************/
void PCNT_TopSet(PCNT_TypeDef *pcnt, uint32_t val)
{
  EFM_ASSERT(PCNT_REF_VALID(pcnt));

#ifdef PCNT0
  if (PCNT0 == pcnt) {
    EFM_ASSERT((1 << PCNT0_CNT_SIZE) > val);
  }
#endif

#ifdef PCNT1
  if (PCNT1 == pcnt) {
    EFM_ASSERT((1 << PCNT1_CNT_SIZE) > val);
  }
#endif

#ifdef PCNT2
  if (PCNT2 == pcnt) {
    EFM_ASSERT((1 << PCNT2_CNT_SIZE) > val);
  }
#endif

#if defined(_SILICON_LABS_32B_SERIES_0) || defined(_SILICON_LABS_32B_SERIES_1)
  /* LF register about to be modified requires sync; busy check. */

  /* Load into TOPB. */
  PCNT_Sync(pcnt, PCNT_SYNCBUSY_TOPB);
  pcnt->TOPB = val;

  /* Load TOPB value into TOP. */
  PCNT_Sync(pcnt, PCNT_SYNCBUSY_TOPB | PCNT_SYNCBUSY_CMD);
  pcnt->CMD = PCNT_CMD_LTOPBIM;
#else
  /* LF register about to be modified requires sync; busy check. */
  PCNT_Sync(pcnt, PCNT_SYNCBUSY_TOP);
  /* Load into TOP. */
  pcnt->TOP = val;
#endif
}

/** @} (end addtogroup pcnt) */
#endif /* defined(PCNT_COUNT) && (PCNT_COUNT > 0) */
