/*
 * Copyright (c) 2022 Antmicro <www.antmicro.com>
 * 
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include <stdbool.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/bluetooth/hci_driver.h>
#include <sl_hci_common_transport.h>

enum h4_packet {
	h4_command = 1,
	h4_acl     = 2,
	h4_sco     = 3,
	h4_event   = 4
};

/**
 * @brief BTLE_LL_Process process linklayer events
 * @param events
 */
void BTLE_LL_Process(uint32_t events);

/**
 * @brief BTLE_LL_EventRaise raise events to be notified as soon as possible to linklayer
 * function is implemented by upper layer
 * @param events bitmap of events to raise
 */
void BTLE_LL_EventRaise(uint32_t events);

/**
 * @brief Check if event bitmap indicates pending events
 * @return bool pending events
 */
bool sli_pending_btctrl_events(void);

/**
 * @brief Thread entry point that calls Link Layer to process raised events
 */
void slz_ll_thread_func(void);
