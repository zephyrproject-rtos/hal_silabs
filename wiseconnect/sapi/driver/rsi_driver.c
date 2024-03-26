/*******************************************************************************
* @file  rsi_driver.c
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
  Includes
  */

#include "rsi_driver.h"
/** @addtogroup DRIVER5
* @{
*/
/*===================================================*/
/**
 * @fn			void rsi_interrupt_handler(void)
 * @brief		Handle the interrupt coming from the module. 
 * @param[in]	void 
 * @return	  Void 
 */
/// @private
void rsi_interrupt_handler(void)
{
#ifndef RSI_M4_INTERFACE
  // Disable the interrupt
  rsi_hal_intr_mask();
#ifdef RSI_WITH_OS
  // Set event RX pending from device
  rsi_set_event_from_isr(RSI_RX_EVENT);
#else
  // Set event RX pending from device
  rsi_set_event(RSI_RX_EVENT);
#endif
#endif
  return;
}
/*===================================================*/
/**
 * @fn			void rsi_mask_ta_interrupt(void)
 * @brief		Mask the TA interrupt. 
 * @param[in]	void 
 * @return	    Void
 */
/// @private
void rsi_mask_ta_interrupt(void)
{
#ifdef RSI_M4_INTERFACE
  // mask P2P interrupt
  mask_ta_interrupt(TX_PKT_TRANSFER_DONE_INTERRUPT | RX_PKT_TRANSFER_DONE_INTERRUPT);
#else
  rsi_hal_intr_mask();
#endif
}
/*===================================================*/
/**
 * @fn			void rsi_unmask_ta_interrupt(void)
 * @brief		Unmask the TA interrupt. 
 * @param[in]	void 
 * @return	    Void
 */
/// @private
void rsi_unmask_ta_interrupt(void)
{
#ifdef RSI_M4_INTERFACE
  // unmask P2P interrupt
  unmask_ta_interrupt(TX_PKT_TRANSFER_DONE_INTERRUPT | RX_PKT_TRANSFER_DONE_INTERRUPT);
#else
  rsi_hal_intr_unmask();
#endif
}
/** @} */
