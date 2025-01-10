/**************************************************************************/ /**
 * @file
 * @brief OS abstraction layer primitives for platform/security on CMSIS RTOS2
 *******************************************************************************
 * # License
 * <b>Copyright 2024 Silicon Laboratories Inc. www.silabs.com</b>
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

// -----------------------------------------------------------------------------
// Includes
#include "sl_common.h"
#include "sli_psec_osal_cmsis_rtos2.h"

// -----------------------------------------------------------------------------
// Functions

/// Check if lock is open for calling thread
SL_CODE_CLASSIFY(SL_CODE_COMPONENT_PSEC_OSAL, SL_CODE_CLASS_TIME_CRITICAL)
sl_status_t sli_psec_osal_lock_is_accessible(sli_psec_osal_lock_t *lock)
{
  sl_status_t sl_status;
  CORE_DECLARE_IRQ_STATE;
  if (lock == NULL) {
    return SL_STATUS_FAIL;
  }
  CORE_ENTER_CRITICAL();
  osThreadId_t mutex_owner = osMutexGetOwner(lock->mutex_ID);
  if (mutex_owner == NULL) {
    sl_status = SL_STATUS_OK;
  } else {
    if (mutex_owner != osThreadGetId()) {
      sl_status = SL_STATUS_FAIL;
    } else {
      if (lock->mutex_attr.attr_bits & osMutexRecursive) {
        sl_status = SL_STATUS_OK;
      } else {
        sl_status = SL_STATUS_FAIL;
      }
    }
  }
  CORE_EXIT_CRITICAL();
  return sl_status;
}

/// Attempt to take ownership or lock. Wait until available if already locked, or timeout.
sl_status_t sli_psec_osal_take_lock_timeout(sli_psec_osal_lock_t *lock, uint32_t timeout)
{
  if (lock == NULL) {
    return SL_STATUS_FAIL;
  }

  osStatus_t status = osOK;
  if (osKernelGetState() == osKernelRunning) {
    if (CORE_IRQ_DISABLED()) {
      return sli_psec_osal_lock_is_accessible(lock);
    } else {
      status = osMutexAcquire(lock->mutex_ID, timeout);
    }
  }
  return (status == osOK ? SL_STATUS_OK : SL_STATUS_FAIL);
}

/// Release ownership of a lock.
sl_status_t sli_psec_osal_give_lock(sli_psec_osal_lock_t *lock)
{
  if (lock == NULL) {
    return SL_STATUS_FAIL;
  }

  osStatus_t status = osOK;
  if (osKernelGetState() == osKernelRunning) {
    if (CORE_IRQ_DISABLED()) {
      return sli_psec_osal_lock_is_accessible(lock);
    } else {
      status = osMutexRelease(lock->mutex_ID);
    }
  }

  return (status == osOK ? SL_STATUS_OK : SL_STATUS_FAIL);
}
