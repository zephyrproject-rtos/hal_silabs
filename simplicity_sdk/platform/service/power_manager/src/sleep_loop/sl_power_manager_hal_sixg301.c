/***************************************************************************//**
 * @file
 * @brief Power Manager HAL API implementation.
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

#include "em_device.h"
#if defined(_SILICON_LABS_32B_SERIES_3)
#include "sl_assert.h"
#include "sli_power_manager_private.h"
#include "sl_power_manager.h"
#include "sl_power_manager_config.h"
#if defined(SL_COMPONENT_CATALOG_PRESENT)
#include "sl_component_catalog.h"
#endif
#include "sl_clock_manager.h"
#include "sli_clock_manager_hal.h"
#include <stdbool.h>

#if !defined(SL_CATALOG_POWER_MANAGER_NO_DEEPSLEEP_PRESENT)
#warning "SIXG301 devices only support the power_manager_no_deepsleep sub-component of Power Manager."
#endif

/*******************************************************************************
 ***************************  LOCAL VARIABLES   ********************************
 ******************************************************************************/

static uint32_t sysclk_prescalers_value;
sl_oscillator_t qspi_reference_clock;

/***************************************************************************//**
 * Do some hardware initialization if necessary.
 ******************************************************************************/
void sli_power_manager_init_hardware(void)
{
  sysclk_prescalers_value = (CMU->SYSCLKCTRL & (_CMU_SYSCLKCTRL_HCLKPRESC_MASK | _CMU_SYSCLKCTRL_PCLKPRESC_MASK));
}

/***************************************************************************//**
 * Enable or disable fast wake-up in EM2 and EM3.
 ******************************************************************************/
void sli_power_manager_em23_voltage_scaling_enable_fast_wakeup(bool enable)
{
  (void)enable;
}

/***************************************************************************//**
 * Applies energy mode.
 *
 * @param em  Energy mode to apply:
 *            SL_POWER_MANAGER_EM1
 *            SL_POWER_MANAGER_EM2
 *            SL_POWER_MANAGER_EM3
 ******************************************************************************/
void sli_power_manager_apply_em(sl_power_manager_em_t em)
{
  sl_status_t status;
  uint32_t sysclk_freq;
  uint32_t clk_division_value;

  // Perform required actions according to energy mode
  switch (em) {
    case SL_POWER_MANAGER_EM1:
      // Enter sleep mode
      SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
      __WFI();
      break;

#if defined(SL_CATALOG_POWER_MANAGER_NO_DEEPSLEEP_PRESENT)
    case SL_POWER_MANAGER_EM2:
    case SL_POWER_MANAGER_EM3:
      // Retrieve SYSCLK frequency
      status = sl_clock_manager_get_clock_branch_frequency(SL_CLOCK_BRANCH_SYSCLK, &sysclk_freq);
      EFM_ASSERT(status == SL_STATUS_OK);
      // Evaluate what HCLK divsion can be done in respect of the lowest LSPCLK branch frequency possible (1MHz)
      if (sysclk_freq >= 32000000) {
        // HCLK/16: Minimum SYSCLK frequency = 1MHz x (LSPCLK PRESC) x (HCLK PRESC 16) = 1MHz x 2 x 16 = 32MHz
        clk_division_value = CMU_SYSCLKCTRL_HCLKPRESC_DIV16;
        // Adjust PCLK divider if needed
        if (sysclk_freq >= 64000000) {
          // Case where SYSCLK frequency can allow to have HCLK = SYSCLK/16 + PCLK/2
          clk_division_value |= CMU_SYSCLKCTRL_PCLKPRESC_DIV2;
        } else {
          // PCLK divider must be set to 1 to not go below 1MHz for LSPCLK branch.
          clk_division_value |= CMU_SYSCLKCTRL_PCLKPRESC_DIV1;
        }
      } else if (sysclk_freq >= 16000000) {
        // HCLK/8: Minimum SYSCLK frequency = 1MHz x (LSPCLK PRESC) x (HCLK PRESC 8) = 1MHz x 2 x 8 = 16MHz
        clk_division_value = CMU_SYSCLKCTRL_HCLKPRESC_DIV8 | CMU_SYSCLKCTRL_PCLKPRESC_DIV1;
      } else if (sysclk_freq >= 8000000) {
        // HCLK/4: Minimum SYSCLK frequency = 1MHz x (LSPCLK PRESC) x (HCLK PRESC 4) = 1MHz x 2 x 4 = 8MHz
        clk_division_value = CMU_SYSCLKCTRL_HCLKPRESC_DIV4 | CMU_SYSCLKCTRL_PCLKPRESC_DIV1;
      } else if (sysclk_freq >= 4000000) {
        // HCLK/2: Minimum SYSCLK frequency = 1MHz x (LSPCLK PRESC) x (HCLK PRESC 2) = 1MHz x 2 x 2 = 4MHz
        clk_division_value = CMU_SYSCLKCTRL_HCLKPRESC_DIV2 | CMU_SYSCLKCTRL_PCLKPRESC_DIV1;
      } else {
        // Case where SYSCLK frequency cannot allow to have HCLK division
        clk_division_value = CMU_SYSCLKCTRL_HCLKPRESC_DIV1 | CMU_SYSCLKCTRL_PCLKPRESC_DIV1;
      }
      // Apply HCLK and PCLK divisions
      CMU->SYSCLKCTRL = (CMU->SYSCLKCTRL & ~(_CMU_SYSCLKCTRL_HCLKPRESC_MASK | _CMU_SYSCLKCTRL_PCLKPRESC_MASK)) | clk_division_value;
      // Enter sleep mode
      SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
      __WFI();
      // Restore HCLK and PCLK prescaler
      CMU->SYSCLKCTRL = (CMU->SYSCLKCTRL & ~(_CMU_SYSCLKCTRL_HCLKPRESC_MASK | _CMU_SYSCLKCTRL_PCLKPRESC_MASK)) | sysclk_prescalers_value;
      break;
#endif

    default:
      EFM_ASSERT(false);
      break;
  }
}

/*******************************************************************************
 * Gets the delay associated the wake-up process from EM23.
 *
 * @return Delay for the complete wake-up process with full restore.
 ******************************************************************************/
uint32_t sli_power_manager_get_wakeup_process_time_overhead(void)
{
  return 0;
}

/*******************************************************************************
 * HAL hook function for pre EM1HCLKDIV sleep.
 ******************************************************************************/
void sli_power_manager_em1hclkdiv_presleep_operations(void)
{
#if defined(SL_POWER_MANAGER_QSPI_CLOCK_SWITCH_IN_SLEEP_EN) && (SL_POWER_MANAGER_QSPI_CLOCK_SWITCH_IN_SLEEP_EN == 1)
  sl_status_t status;
  // Save current QSPI reference clock.
  status = sli_clock_manager_get_current_qspi_clk(&qspi_reference_clock);
  EFM_ASSERT(status == SL_STATUS_OK);
  // Update QSPI clock source.
  status = sli_clock_manager_hal_update_qspi_clk(SL_OSCILLATOR_FSRCO);
  EFM_ASSERT(status == SL_STATUS_OK);
#endif
}

/*******************************************************************************
 * HAL hook function for post EM1HCLKDIV sleep.
 ******************************************************************************/
void sli_power_manager_em1hclkdiv_postsleep_operations(void)
{
#if defined(SL_POWER_MANAGER_QSPI_CLOCK_SWITCH_IN_SLEEP_EN) && (SL_POWER_MANAGER_QSPI_CLOCK_SWITCH_IN_SLEEP_EN == 1)
  sl_status_t status;
  // Restore original QSPI clock source.
  status = sli_clock_manager_hal_update_qspi_clk(qspi_reference_clock);
  EFM_ASSERT(status == SL_STATUS_OK);
#endif
}
#endif // _SILICON_LABS_32B_SERIES_3
