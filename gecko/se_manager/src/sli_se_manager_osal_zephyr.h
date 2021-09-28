/*
 * Copyright (c) 2021 Safran Passenger Innovations Germany GmbH
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef SE_MANAGER_OSAL_ZEPHYR_H
#define SE_MANAGER_OSAL_ZEPHYR_H

#include <kernel.h>
#include <devicetree.h>

#ifdef __cplusplus
extern "C" {
#endif

// -----------------------------------------------------------------------------
// Defines

#define DT_DRV_COMPAT silabs_gecko_semailbox

/// In order to wait forever in blocking functions the user can pass the
/// following value.
#define SE_MANAGER_OSAL_WAIT_FOREVER  (-1)
/// In order to return immediately in blocking functions the user can pass the
/// following value.
#define SE_MANAGER_OSAL_NON_BLOCKING  (0)

/// Priority to use for SEMBRX IRQ
#if defined(SE_MANAGER_USER_SEMBRX_IRQ_PRIORITY)
  #define SE_MANAGER_SEMBRX_IRQ_PRIORITY SE_MANAGER_USER_SEMBRX_IRQ_PRIORITY
#else
  #define SE_MANAGER_SEMBRX_IRQ_PRIORITY (DT_INST_IRQ_BY_NAME(0, sembrx, priority))
#endif

/// Determine if executing at interrupt level on ARM Cortex-M.
#define RUNNING_AT_INTERRUPT_LEVEL (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk)

// -----------------------------------------------------------------------------
// Typedefs

/// Completion object used to wait for and signal end of an operation.
typedef struct k_sem se_manager_osal_completion_t;
/// SE manager mutex definition for zephyr.
typedef struct k_mutex se_manager_osal_mutex_t;

// -----------------------------------------------------------------------------
// Functions

/// Initialize a mutex object.
__STATIC_INLINE
sl_status_t se_manager_osal_init_mutex(se_manager_osal_mutex_t *mutex)
{
  int err;

  err = k_mutex_init(mutex);
  return (err == 0 ? SL_STATUS_OK : SL_STATUS_FAIL);
}

/// Free a mutex object.
__STATIC_INLINE
sl_status_t se_manager_osal_free_mutex(se_manager_osal_mutex_t *mutex)
{
  return SL_STATUS_OK;
}

/// Acquire ownership of a mutex. If busy, wait until available.
__STATIC_INLINE
sl_status_t se_manager_osal_take_mutex(se_manager_osal_mutex_t *mutex)
{
  int err;

  if ( (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) != 0U ) {
    // Illegal call from ISR
    return SL_STATUS_ISR;
  }

  err = k_mutex_lock(mutex, K_FOREVER);
  return (err == 0 ? SL_STATUS_OK : SL_STATUS_FAIL);
}

/// Try to acquire ownership of a mutex without waiting.
__STATIC_INLINE
sl_status_t se_manager_osal_take_mutex_non_blocking(se_manager_osal_mutex_t *mutex)
{
  int err;

  if ( (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) != 0U ) {
    // Illegal call from ISR
    return SL_STATUS_ISR;
  }

  err = k_mutex_lock(mutex, K_NO_WAIT);
  return (err == 0 ? SL_STATUS_OK : SL_STATUS_FAIL);
}

/// Release ownership of a mutex.
__STATIC_INLINE
sl_status_t se_manager_osal_give_mutex(se_manager_osal_mutex_t *mutex)
{
  int err = k_mutex_unlock(mutex);
  return (err == 0 ? SL_STATUS_OK : SL_STATUS_FAIL);
}

/// Initialize a completion object.
__STATIC_INLINE sl_status_t
se_manager_osal_init_completion(se_manager_osal_completion_t *p_comp)
{
  int err = k_sem_init(p_comp, 0, 1);
  EFM_ASSERT(err == 0);
  return (err == 0 ? SL_STATUS_OK : SL_STATUS_FAIL);
}

/// Free a completion object.
__STATIC_INLINE sl_status_t
se_manager_osal_free_completion(se_manager_osal_completion_t *p_comp)
{
  return SL_STATUS_OK;
}

// Wait for a completion object to be completed.
__STATIC_INLINE sl_status_t
se_manager_osal_wait_completion(se_manager_osal_completion_t *p_comp, int ticks)
{
  int err;

  err = k_sem_take(p_comp, ticks ==
                   SE_MANAGER_OSAL_NON_BLOCKING ? K_NO_WAIT : K_TICKS(ticks));

  if (err == 0) {
    err = SL_STATUS_OK;
  } else if (err == -ETIMEDOUT) {
      err = SL_STATUS_TIMEOUT;
  } else {
    /* Assert that no other error codes occur. */
    EFM_ASSERT(false);
    err = SL_STATUS_FAIL;
  }

  return err;
}

// Complete a completion object.
__STATIC_INLINE sl_status_t
se_manager_osal_complete(se_manager_osal_completion_t* p_comp)
{
  k_sem_give(p_comp);

  return SL_STATUS_OK;
}

#ifdef __cplusplus
}
#endif

#endif // SE_MANAGER_OSAL_ZEPHYR_H
