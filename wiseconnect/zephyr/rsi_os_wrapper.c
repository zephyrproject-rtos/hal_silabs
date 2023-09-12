/*******************************************************************************
* @file  rsi_os_wrapper.c
* @brief 
*******************************************************************************
* # License
* Copyright 2020 Silicon Laboratories Inc. http://www.silabs.com/
*******************************************************************************
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*  http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
******************************************************************************/

/*
 * Copyright (c) 2021 T-Mobile USA, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RSI_ZEPHYR
#define RSI_ZEPHYR

#include <rsi_driver.h>
#ifdef RSI_WITH_OS
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include "rsi_wlan_non_rom.h"

K_SEM_DEFINE(sem_mgmt, 1, 1);
K_SEM_DEFINE(mut_mgmt, 1, 1);

static struct k_mutex muts[32];
uint32_t mut_map = 0;
static struct k_sem sems[64];
uint64_t sem_map = 0;

extern rsi_socket_info_non_rom_t *rsi_socket_pool_non_rom;


/*==============================================*/
/**
 * @fn          rsi_reg_flags_t rsi_critical_section_entry()
 * @brief       This API's to enter critical section
 * @param[in]   none,
 * @return      flags, interrupt status before entering critical section
 *
 *
 * @section description
 * This API disable interrupt to enter crtical section.
 *
 *
 */
rsi_reg_flags_t rsi_critical_section_entry()
{
	//! hold interrupt status before entering critical section
	//! disable interrupts
	rsi_reg_flags_t xflags;
	//! hold interrupt status before entering critical section
	//! disable interrupts
	xflags = 0;

  //taskENTER_CRITICAL();
    xflags = irq_lock();

	//! return stored interrupt status
	return (xflags);
}



/*==============================================*/
/**
 * @fn         rsi_critical_section_exit(rsi_reg_flags_t xflags)
 * @brief      This API to exit critical section
 * @param[in]  xflags, interrupt status to restore interrupt on exit from critical section
 * @return     None
 *
 *
 * @section description
 * This API to exit/restore critical section.
 *
 *
 */

void  rsi_critical_section_exit(rsi_reg_flags_t xflags)
{
	//! restore interrupts while exiting critical section
  irq_unlock(xflags);
  
}




/*==============================================*/
/**
 * @fn           rsi_error_t rsi_mutex_create(rsi_mutex_handle_t *mutex)
 * @brief        This API is creates the mutex 
 * @param[in]    mutex handle pointer  
 * @param[out]   Mutex created   
 * @return       0 = success 
 *              <0 = failure
 * @section description
 * This function is OS Abstraction layer API which creates the mutex 
 *
 *
 */

rsi_error_t rsi_mutex_create(rsi_mutex_handle_t *mutex)
{
	struct k_mutex *kmutex;
	if (mutex == NULL){
		return RSI_ERROR_IN_OS_OPERATION;
	}
	*mutex = 0;
	k_sem_take(&mut_mgmt, K_FOREVER);
	for (int i = 0; i < 32; i++){
		if (!(mut_map & BIT(i))){
			mut_map |= BIT(i);
			*mutex = i + 1;
			kmutex = &muts[i];
			k_mutex_init(kmutex);
			break;
		}
	}
	k_sem_give(&mut_mgmt);
	if (*mutex == 0) {
		return RSI_ERROR_IN_OS_OPERATION;
	}

	return RSI_ERROR_NONE;
}



/*==============================================*/
/**
 * @fn           rsi_error_t rsi_mutex_lock(volatile rsi_mutex_handle_t *mutex)
 * @brief        This API is takes the mutex 
 * @param[in]    mutex handle pointer  
 * @return       0 = success 
 *              <0 = failure
 * @section description
 * This function is OS Abstraction layer API which takes the mutex
 *
 *
 */
rsi_error_t rsi_mutex_lock(volatile rsi_mutex_handle_t *mutex)
{
	if (mutex == NULL || *mutex < 1 || *mutex > ARRAY_SIZE(muts) || !(mut_map & BIT((*mutex - 1)))){
		return RSI_ERROR_INVALID_PARAM;
	}

	struct k_mutex *kmutex = &muts[*mutex - 1];

	if(k_mutex_lock(kmutex, K_FOREVER) == 0)
	{
		return RSI_ERROR_NONE;
	}

	return RSI_ERROR_IN_OS_OPERATION;
}


/*==============================================*/
/**
 * @fn           rsi_error_t rsi_mutex_unlock(volatile rsi_mutex_handle_t *mutex)
 * @brief        This API is gives the mutex 
 * @param[in]    mutex handle pointer  
 * @return       0 = success 
 *              <0 = failure
 * @section description
 * This function is OS Abstraction layer API which gives the mutex 
 *
 */
rsi_error_t rsi_mutex_unlock(volatile rsi_mutex_handle_t *mutex)
{
	if (mutex == NULL || *mutex < 1 || *mutex > ARRAY_SIZE(muts) || !(mut_map & BIT((*mutex - 1)))){
		return RSI_ERROR_INVALID_PARAM;
	}

	struct k_mutex *kmutex = &muts[*mutex - 1];
	
	if (k_mutex_unlock(kmutex) == 0)
	{
		return RSI_ERROR_NONE;
	}

	return RSI_ERROR_IN_OS_OPERATION;
}



/*==============================================*/
/**
 * @fn           rsi_error_t rsi_mutex_destroy(rsi_mutex_handle_t *mutex)
 * @brief        This API is destroyes the mutex 
 * @param[in]    mutex handle pointer  
 * @return       0 = success 
 *              <0 = failure
 * @section description
 * This function is OS Abstraction layer API which destroy/delete the mutex 
 *
 */
rsi_error_t rsi_mutex_destroy(rsi_mutex_handle_t *mutex)
{
	if (mutex == NULL || *mutex < 1 || *mutex > ARRAY_SIZE(muts)){
		return RSI_ERROR_INVALID_PARAM;
	}

	k_sem_take(&mut_mgmt, K_FOREVER);
	mut_map &= ~BIT((*mutex - 1));
	k_sem_give(&mut_mgmt);

	return RSI_ERROR_NONE;
}



/*==============================================*/
/**
 * @fn           rsi_error_t rsi_semaphore_create(rsi_semaphore_handle_t *semaphore,uint32_t count)
 * @brief        This API is creates the semaphore instance 
 * @param[in]    Semaphore handle pointer  
 * @param[in]    resource count
 * @param[out]   Semaphore handler created   
 * @return       0 = success 
 *              <0 = failure
 * @section description
 * This function is OS Abstraction layer API which creates the semaphore 
 *
 */
rsi_error_t rsi_semaphore_create(rsi_semaphore_handle_t *semaphore,uint32_t count)
{
	struct k_sem *ksem;
	if (semaphore == NULL){
		return RSI_ERROR_INVALID_PARAM;
	}
	*semaphore = 0;
	k_sem_take(&sem_mgmt, K_FOREVER);
	for (int i = 0; i < 64; i++){
		if (!(sem_map & BIT(i))){
			sem_map |= BIT(i);
			*semaphore = i + 1;
			ksem = &sems[i];
			k_sem_init(ksem, count, 1);
			break;
		}
	}
	k_sem_give(&sem_mgmt);
	if (*semaphore == 0) {
		return RSI_ERROR_IN_OS_OPERATION;
	}

	return RSI_ERROR_NONE;
}

/*==============================================*/
/**
 * @fn           rsi_error_t rsi_semaphore_destroy(rsi_semaphore_handle_t *semaphore)
 * @brief        This API is destroys the semaphore instance
 * @param[in]    Semaphore handle pointer  
 * @return       0 = success 
 *              <0 = failure
 * @section description
 * This function is OS Abstraction layer API which destroys the semaphore 
 *
 */
rsi_error_t rsi_semaphore_destroy(rsi_semaphore_handle_t *semaphore)
{
	if (semaphore == NULL || *semaphore < 1 || *semaphore > ARRAY_SIZE(sems)){
		return RSI_ERROR_INVALID_PARAM;
	}

	if (!(sem_map & BIT((*semaphore - 1)))) {
		return RSI_ERROR_IN_OS_OPERATION;
	}

	sem_map &= ~BIT((*semaphore - 1));
	return RSI_ERROR_NONE;
}

/*==============================================*/
/**
 * @fn           rsi_error_t rsi_semaphore_check_and_destroy(rsi_semaphore_handle_t *semaphore)
 * @brief        This API should check whether semaphore is created or not, It
 *               destroys the semaphore instance,if its created, otherwise should return success
 * @param[in]    Semaphore handle pointer  
 * @return       0 = success 
 *              <0 = failure
 * @section description
 * This function is OS Abstraction layer API which destroys the semaphore 
 *
 */

rsi_error_t rsi_semaphore_check_and_destroy(rsi_semaphore_handle_t *semaphore)
{
	if (semaphore == NULL){
		return RSI_ERROR_INVALID_PARAM;
	}
	if (*semaphore < 1 || *semaphore > ARRAY_SIZE(sems) || !(sem_map & BIT((*semaphore - 1)))) {
		return RSI_ERR_NONE;
	}

	sem_map &= ~BIT((*semaphore - 1));

	return RSI_ERROR_NONE;
}



/*==============================================*/
/**
 * @fn          rsi_error_t rsi_semaphore_wait(rsi_semaphore_handle_t *semaphore, uint32_t timeout_ms ) 
 * @brief       This API is used by wireless library to acquire or wait for semaphore.
 * @param[in]   Semaphore handle pointer  
 * @param[in]   Maximum time to wait to acquire semaphore. If timeout_ms is 0 then wait
                till acquire semaphore.
 * @return      0 = Success
 *              <0 = failure
 * @section description
 * This API is used by Wireless Library to acquire or wait for semaphore.
 *
 */

rsi_error_t rsi_semaphore_wait(rsi_semaphore_handle_t *semaphore, uint32_t timeout_ms )
{
	if (semaphore == NULL || *semaphore < 1 || *semaphore > ARRAY_SIZE(sems)){
		return RSI_ERROR_INVALID_PARAM;
	}

	struct k_sem *ksem = &sems[*semaphore - 1];
	k_timeout_t timeout;

	if(!timeout_ms) {
		timeout = K_FOREVER;
	} else {
		timeout = K_MSEC(timeout_ms);
	}

	if(k_sem_take(ksem, timeout) == 0) {
		return RSI_ERROR_NONE;
	}

	return RSI_ERROR_IN_OS_OPERATION;
}


/*==============================================*/
/**
 * @fn          rsi_error_t rsi_semaphore_post(rsi_semaphore_handle_t *semaphore) 
 * @brief       This API is used by wireless library to release semaphore, which was acquired.
 * @param[in]   Semaphore handle pointer  
 * @param[in]   Maximum time to wait to acquire semaphore. If timeout_ms is 0 then wait
                till acquire semaphore.
 * @return      0 = Success
 *              <0 = failure
 * @section description
 * This API is used by Wireless Library to acquire or wait for semaphore.
 *
 */


rsi_error_t rsi_semaphore_post(rsi_semaphore_handle_t *semaphore)
{
	if (semaphore == NULL || *semaphore < 1 || *semaphore > ARRAY_SIZE(sems)){
		return RSI_ERROR_INVALID_PARAM;
	}

	struct k_sem *ksem = &sems[*semaphore - 1];
	k_sem_give(ksem);
	return RSI_ERR_NONE;
}

/*====================================================*/
/**
 * @fn          rsi_error_t rsi_semaphore_post_from_isr(rsi_semaphore_handle_t *semaphore)
 * @brief       This API is used by wireless library to release semaphore, which was acquired.
 * @param[in]   Semaphore handle pointer 
 * @return      
 *                0 = Success
 *              <0 = failure
 * @section description 
 * This API is used by Wireless Library to acquire or wait for semaphore.
 */

rsi_error_t rsi_semaphore_post_from_isr(rsi_semaphore_handle_t *semaphore)
{
	return rsi_semaphore_post(semaphore);
}

/*==============================================*/
/**
 * @fn          rsi_error_t rsi_semaphore_reset(rsi_semaphore_handle_t *semaphore) 
 * @brief       This API is used by wireless library Wireless Library to the semaphore to initial state
 * @param[in]   Semaphore handle pointer  
 * @return      0 = Success
 *              <0 = failure
 * @section description
 * This API is used by Wireless Library to reset the semaphore.
 *
 */
rsi_error_t rsi_semaphore_reset(rsi_semaphore_handle_t *semaphore)
{
	if (semaphore == NULL || *semaphore < 1 || *semaphore > ARRAY_SIZE(sems)){
		return RSI_ERROR_INVALID_PARAM;
	}

	struct k_sem *ksem = &sems[*semaphore - 1];
	k_sem_reset(ksem);
	return RSI_ERROR_NONE;
}


/*==============================================*/
/**
 * @fn           rsi_error_t rsi_task_create( rsi_task_function_t task_function,uint8_t *task_name,
                 uint32_t stack_size, void *parameters,
                 uint32_t task_priority,rsi_task_handle_t  *task_handle)
 * @brief        This API is used to create different tasks in OS supported platforms 
 * @param[in]    Pointer to function to be executed by created thread. Prototype of the function
 * @param[in]    Name of the created task  
 * @param[in]    Stack size given to the created task  
 * @param[in]    Pointer to the parameters to be passed to task function
 * @param[in]    task priority 
 * @param[in]    task handle/instance created 
 * @return       0 = Success
 *              <0 = Failure
 * @section description
 * This API is used by Wireless Library to create platform specific OS
 * task/thread. 
 *
 *
 */


rsi_error_t rsi_task_create( rsi_task_function_t task_function,uint8_t *task_name,
		uint32_t stack_size, void *parameters,
		uint32_t task_priority, rsi_task_handle_t  *task_handle)
{
	//Not needed?
	return RSI_ERROR_IN_OS_OPERATION;
}


/*==============================================*/
/**
 * @fn          void rsi_task_destroy(rsi_task_handle_t *task_handle)
 * @brief       This function deletes the task created
 * @param[in]   Task handle/instance to be deleted
 * @return      None
 * @section description
 * This API is used to delete/destroy the task created
 *
 */


void rsi_task_destroy(rsi_task_handle_t *task_handle)
{
	//Not needed?
	return;
}



/*==============================================*/
/**
 * @fn          void rsi_os_task_delay(uint32_t timeout_ms)
 * @brief       This function induces required delay in milli seconds
 * @param[in]   Expected delay in milli seconds
 * @return      None
 * @section description
 * This API is used to induce OS delay
 *
 */
void rsi_os_task_delay(uint32_t timeout_ms)
{
	//Not needed?
	k_msleep(timeout_ms);
}




/*==============================================*/
/**
 * @fn           void rsi_start_os_scheduler()
 * @brief        This function schedules the tasks created
 * @param[in]    None 
 * @return       None
 * @section description
 * This API Schedules the tasks created
 *
 */
void rsi_start_os_scheduler()
{
	//Not needed?
	//vTaskStartScheduler();
}

/*==============================================*/
/**
 * @fn          int32_t rsi_get_error(void)
 * @brief       This sets the os error .
 * @param[in]   Error
 * @param[out]  None
 * @return      None
 *
 * @section description
 * This sets the os error.
 *
 */
void rsi_set_os_errno(int32_t error)
{
	int z_error;
	switch (error) {
	case RSI_ERROR_ECONNREFUSED:
		z_error = ECONNREFUSED;
		break;
	case RSI_ERROR_ECONNABORTED:
		z_error = ECONNABORTED;
		break;
	case RSI_ERROR_ETIMEDOUT:
		z_error = ETIMEDOUT;
		break;
	case RSI_ERROR_EACCES:
		z_error = EACCES;
		break;
	case RSI_ERROR_EPERM:
		z_error = EPERM;
		break;
	case RSI_ERROR_EMSGSIZE:
		z_error = EMSGSIZE;
		break;
	case RSI_ERROR_EBADF:
		z_error = EBADF;
		break;
	case RSI_ERROR_EAGAIN:
		z_error = EAGAIN;
		break;
	case RSI_ERROR_EISCONN:
		z_error = EISCONN;
		break;
	case RSI_ERROR_ENOTCONN:
		z_error = ENOTCONN;
		break;
	case RSI_ERROR_EADDRINUSE:
		z_error = EADDRINUSE;
		break;
	case RSI_ERROR_ENOTSOCK:
		z_error = ENOTSOCK;
		break;
	case RSI_ERROR_ENOMEM:
		z_error = ENOMEM;
		break;
	case RSI_ERROR_EINVAL:
		z_error = EINVAL;
		break;
	default:
		z_error = error;
		break;
	}
	errno = z_error;
}

/*==============================================*/
/**
 * @fn          int32_t rsi_get_error(void)
 * @brief       Returns wlan status
 * @param[in]   None
 * @param[out]  None
 * @return      wlan status
 *
 * @section description
 * This function returns wlan status
 *
 */
int32_t rsi_get_error(int32_t sockID)
{
  if(rsi_socket_pool_non_rom[sockID].socket_status == 0xFF87
      || rsi_socket_pool_non_rom[sockID].socket_status == 0xBB38)
  {
    return RSI_ERROR_ECONNREFUSED; 
  }
  else if(rsi_socket_pool_non_rom[sockID].socket_status == 0x00D2)
  {
    return RSI_ERROR_ECONNABORTED; 
  }
  else if(rsi_socket_pool_non_rom[sockID].socket_status == 0xFF6C
      || rsi_socket_pool_non_rom[sockID].socket_status == 0xFF6A
      || rsi_socket_pool_non_rom[sockID].socket_status == RSI_ERROR_RESPONSE_TIMEOUT
      || rsi_socket_pool_non_rom[sockID].socket_status == 0xBBD6)
  {
    return RSI_ERROR_ETIMEDOUT; 
  }
  else if(rsi_socket_pool_non_rom[sockID].socket_status == 0x0021
      || rsi_socket_pool_non_rom[sockID].socket_status == 0xFF82
      || rsi_socket_pool_non_rom[sockID].socket_status == 0xFF74
      || rsi_socket_pool_non_rom[sockID].socket_status == 0xBB27
      || rsi_socket_pool_non_rom[sockID].socket_status == 0xFF80
      || rsi_socket_pool_non_rom[sockID].socket_status == 0x00D1)
  {
    return RSI_ERROR_EACCES; 
  }
  else if(rsi_socket_pool_non_rom[sockID].socket_status == 0x00D3
      || rsi_socket_pool_non_rom[sockID].socket_status == 0xFFFE)
  {
    return RSI_ERROR_EPERM; 
  }
  else if(rsi_socket_pool_non_rom[sockID].socket_status == 0xFF7E
      || rsi_socket_pool_non_rom[sockID].socket_status == 0xBBED
      || rsi_socket_pool_non_rom[sockID].socket_status == 0x003E
      || rsi_socket_pool_non_rom[sockID].socket_status == 0x0030
      || rsi_socket_pool_non_rom[sockID].socket_status == 0xBB3E)
  {
    return RSI_ERROR_EMSGSIZE; 
  }
  else if(rsi_socket_pool_non_rom[sockID].socket_status == 0xFF86)
  {
    return RSI_ERROR_EBADF; 
  }
  else if(rsi_socket_pool_non_rom[sockID].socket_status == 0x0015)
  {
    return RSI_ERROR_EAGAIN; 
  }
  else if(rsi_socket_pool_non_rom[sockID].socket_status == 0xBB22
      || rsi_socket_pool_non_rom[sockID].socket_status == 0xBB42)
  {
    return RSI_ERROR_EISCONN; 
  }
  else if(rsi_socket_pool_non_rom[sockID].socket_status == 0xFFFF
      || rsi_socket_pool_non_rom[sockID].socket_status == 0xBB50)
  {
    return RSI_ERROR_ENOTCONN; 
  }
  else if(rsi_socket_pool_non_rom[sockID].socket_status == 0xBB33
      || rsi_socket_pool_non_rom[sockID].socket_status == 0xBB23
      || rsi_socket_pool_non_rom[sockID].socket_status == 0xBB45
      || rsi_socket_pool_non_rom[sockID].socket_status == 0xBB46
      || rsi_socket_pool_non_rom[sockID].socket_status == 0xBB50)
  {
    return RSI_ERROR_EADDRINUSE; 
  }
  else if(rsi_socket_pool_non_rom[sockID].socket_status == 0xBB36)
  {
    return RSI_ERROR_ENOTSOCK; 
  }
  else if(rsi_socket_pool_non_rom[sockID].socket_status == RSI_ERROR_PKT_ALLOCATION_FAILURE)
  {
    return RSI_ERROR_ENOMEM; 
  }
  return RSI_ERROR_EINVAL;
}



/*==============================================*/
/**n
 * @fn          void *rsi_malloc (uint32_t size)
 * @brief       Returns allocated memory starting address
 * @param[in]   required bytes in size
 * @param[out]  None
 * @return      Returns starting address of allocated memory
 *
 * @section description
 * This function allocates memory from the buffer which is maintained by freertos
 *
 */

void *rsi_malloc (uint32_t size)
{
	if(size == 0)
	{
		return NULL;
	}
	else
	{
		return k_malloc(size);
	}
}

/*==============================================*/
/**
 * @fn          void rsi_free (void *ptr)
 * @brief       frees the memory pointed by 'ptr'
 * @param[in]   starting address of the memory to be freed
 * @param[out]  None
 * @return      None
 *
 * @section description
 * This function frees the memory pointed by 'ptr'
 *
 */
void rsi_free (void *ptr)
{
	if(ptr == NULL)
	{
		//! do nothing
	}
	else
	{
	 k_free(ptr);
	}
}
#endif
#endif
