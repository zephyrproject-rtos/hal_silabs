/*
 * Copyright (c) 2022 Antmicro <www.antmicro.com>
 * 
 * SPDX-License-Identifier: Apache-2.0
 */

#include <sl_bt_ll_zephyr.h>

K_SEM_DEFINE(slz_ll_sem, 0, 1);

static atomic_t sli_btctrl_events;

bool sli_pending_btctrl_events(void)
{
	return false;
}

void BTLE_LL_EventRaise(uint32_t events)
{
	atomic_or(&sli_btctrl_events, events);
	k_sem_give(&slz_ll_sem);
}

void slz_ll_thread_func(void)
{
	while (true) {
		k_sem_take(&slz_ll_sem, K_FOREVER);
		uint32_t events = atomic_clear(&sli_btctrl_events);
		BTLE_LL_Process(events);
	}
}

void sl_bt_controller_init()
{
	/* No extra initialization procedure required */
}
