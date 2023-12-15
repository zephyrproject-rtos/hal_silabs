/***************************************************************************//**
 * @file app_cli.c
 * @brief CLI commands for the proprietary_trx example.
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

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/util.h>
#include <zephyr/sys/printk.h>
#include <inttypes.h>
#include <zephyr/shell/shell.h>
#include <zephyr/logging/log.h>
#include <stdlib.h>
#include "em_chip.h"
#include "main.h"

// -----------------------------------------------------------------------------
// Public Function Definitions

/******************************************************************************
 * CLI - send: Sets a flag indicating that a packet has to be sent
 *****************************************************************************/
void cli_send_packet(const struct shell *sh, size_t argc, char **argv)
{
	shell_fprintf(sh, SHELL_NORMAL, "Send packet request\n");
	k_event_post(&s_sl_machine.smf_event, EVENT_REQUEST_SEND);
}

/******************************************************************************
 * CLI - info message: Unique ID of the board
 *****************************************************************************/
void cli_info(const struct shell *sh, size_t argc, char **argv)
{
	shell_fprintf(sh, SHELL_NORMAL, "Info:\n");
	shell_fprintf(sh, SHELL_NORMAL, "  MCU Id:       0x%llx\n", SYSTEM_GetUnique());
}

/******************************************************************************
 * CLI - receive: Turn on/off continues packet receiving
 *****************************************************************************/
void cli_receive_packet(const struct shell *sh, size_t argc, char **argv)
{
	unsigned long continues_receive = strtoul(argv[1], NULL, 0);
	s_sl_machine.allow_rx = continues_receive;
	shell_fprintf(sh, SHELL_NORMAL, "Continues packet receiving is %s\n",
		      (continues_receive == 0) ? "OFF" : "ON");
	k_event_post(&s_sl_machine.smf_event, EVENT_CLI_RECEIVE_SETTING);
}

SHELL_CMD_ARG_REGISTER(info, NULL, "Display unique ID of the MCU", cli_info, 1, 0);

SHELL_CMD_ARG_REGISTER(send, NULL, "Send a packet", cli_send_packet, 1, 0);

SHELL_CMD_ARG_REGISTER(receive, NULL, "Turn ON/OFF continues packet receiving", cli_receive_packet,
		       2, 0);
