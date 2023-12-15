/***************************************************************************//**
 * @file app_rail.c
 * @brief RAIL handling for the proprietary_trx example.
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
#include <assert.h>
#include "rail.h"
#include "rail_types.h"
#include "pa_conversions_efr32.h"
#include "sl_rail_util_init.h"
#include "app_rail.h"
#include "main.h"

// -----------------------------------------------------------------------------
// Macros and Typedefs

LOG_MODULE_DECLARE(trx_app_log);

// Generated radio protocol phy have multiply channels to cover the RF band from
// start to end with selected channel spacing, RAIL need to know which is the
// active channel to send/receive, range is from radio_config.c
// from channelNumberStart to channelNumberEnd
#define CHANNEL 0U

// -----------------------------------------------------------------------------
// Static Function Declarations

static void set_up_tx_fifo(RAIL_Handle_t rail_handle);

static void prepare_package(RAIL_Handle_t rail_handle, uint8_t *out_data, uint16_t length);

static uint16_t unpack_packet(uint8_t *rx_destination,
			      const RAIL_RxPacketInfo_t *packet_information,
			      uint8_t **start_of_payload);

// Install RAIL interrupt service routines (ISRs)
static void rail_isr_installer(void);

// -----------------------------------------------------------------------------
// Global Variables

// -----------------------------------------------------------------------------
// Static Variables

// -----------------------------------------------------------------------------
// Public Function Definitions

void handle_send(bool *packet_sent)
{
	// Default payload packet content
	static uint8_t out_packet[16] = {
		0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
		0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF,
	};
	RAIL_Handle_t rail_handle = sl_rail_util_get_handle(SL_RAIL_UTIL_HANDLE_INST0);
	if (*packet_sent) {
		prepare_package(rail_handle, out_packet, sizeof(out_packet));
		LOG_INF("Packet prepared");
		RAIL_StartTx(rail_handle, CHANNEL, RAIL_TX_OPTIONS_DEFAULT, NULL);
		LOG_INF("Packet is being sent");
		*packet_sent = false;
	} else {
		LOG_WRN("Sending is in progress");
	}
}

void handle_sent(bool *packet_sent)
{
	*packet_sent = true;
	LOG_INF("Packet successfully sent");
}

void handle_error(uint64_t *error_code)
{
	LOG_ERR("Radio Error occurred\nEvents: %llX", *error_code);
	*error_code = 0;
}

void set_continuous_rx(bool enable_continuous_rx)
{
	RAIL_Status_t status;
	RAIL_RadioState_t selected_state = RAIL_RF_STATE_IDLE;
	RAIL_StateTransitions_t tx_transitions;
	RAIL_StateTransitions_t rx_transitions;
	RAIL_Handle_t rail_handle = sl_rail_util_get_handle(SL_RAIL_UTIL_HANDLE_INST0);

	if (enable_continuous_rx) {
		selected_state = RAIL_RF_STATE_RX;
	}

	tx_transitions.success = selected_state;
	tx_transitions.error = selected_state;
	rx_transitions.success = selected_state;
	rx_transitions.error = selected_state;

	status = RAIL_SetTxTransitions(rail_handle, &tx_transitions);
	if (status) {
		LOG_ERR("RAIL_SetTxTransitions failed, return value: %d", status);
	} else {
		LOG_INF("RAIL_SetTxTransitions success");
	}

	status = RAIL_SetRxTransitions(rail_handle, &rx_transitions);

	if (status) {
		LOG_ERR("RAIL_SetRxTransitions failed, return value: %d", status);
	} else {
		LOG_INF("RAIL_SetTxTransitions success");
	}

	if (enable_continuous_rx) {
		RAIL_StartRx(rail_handle, CHANNEL, NULL);
	} else {
		RAIL_Idle(rail_handle, RAIL_IDLE, true);
	}
}

void handle_receive(void)
{
	RAIL_RxPacketHandle_t rx_packet_handle;
	RAIL_RxPacketInfo_t packet_info;
	RAIL_Status_t rail_status = RAIL_STATUS_NO_ERROR;
	uint8_t *start_of_packet = NULL;
	uint16_t packet_size = 0;
	static __ALIGNED(RAIL_FIFO_ALIGNMENT) uint8_t rx_fifo[128];
	RAIL_Handle_t rail_handle = sl_rail_util_get_handle(SL_RAIL_UTIL_HANDLE_INST0);
	rx_packet_handle = RAIL_GetRxPacketInfo(rail_handle, RAIL_RX_PACKET_HANDLE_OLDEST_COMPLETE,
						&packet_info);
	while (rx_packet_handle != RAIL_RX_PACKET_HANDLE_INVALID) {
		packet_size = unpack_packet(rx_fifo, &packet_info, &start_of_packet);
		rail_status = RAIL_ReleaseRxPacket(rail_handle, rx_packet_handle);
		if (rail_status) {
			LOG_WRN("RAIL_ReleaseRxPacket() result:%d", rail_status);
		}
		LOG_INF("Length of packet: %d", packet_size);
		LOG_HEXDUMP_INF(start_of_packet, packet_size, "Received Packet: ");
		rx_packet_handle = RAIL_GetRxPacketInfo(
			rail_handle, RAIL_RX_PACKET_HANDLE_OLDEST_COMPLETE, &packet_info);
	}
}

void app_rail_init(void)
{
	RAIL_Status_t status = RAIL_STATUS_NO_ERROR;
	RAIL_Handle_t rail_handle;
	rail_isr_installer();
	sl_rail_util_pa_init();
	sl_rail_util_init();

	rail_handle = sl_rail_util_get_handle(SL_RAIL_UTIL_HANDLE_INST0);
	set_up_tx_fifo(rail_handle);

	status = RAIL_StartRx(rail_handle, CHANNEL, NULL);
	if (status) {
		LOG_WRN("After initialization RAIL_StartRx() result:%d ", status);
	}

	if (IS_ENABLED(CONFIG_PM)) {
		status = RAIL_InitPowerManager();
		if (status) {
			LOG_ERR("RAIL: failed to initialize power management, status=%d", status);
		}
	}
}

/******************************************************************************
 * RAIL callback, called if a RAIL event occurs.
 *****************************************************************************/
/**
 * @brief RAIL callback for handling RAIL events.
 *
 * RAIL event's callback, and it handles RX, TX, and calibration events.
 *
 * @param rail_handle RAIL handle for communication.
 * @param events      RAIL events that occurred.
 */
void sl_rail_util_on_event(RAIL_Handle_t rail_handle, RAIL_Events_t events)
{
	// Contains the status of RAIL Calibration
	static RAIL_Status_t calibration_status = 0;
	s_sl_machine.error_code = events;
	// Handle Rx events
	if (events & RAIL_EVENTS_RX_COMPLETION) {
		if (events & RAIL_EVENT_RX_PACKET_RECEIVED) {
			// Keep the packet in the radio buffer, download it later at the state
			// machine
			RAIL_HoldRxPacket(rail_handle);
			k_event_post(&s_sl_machine.smf_event, EVENT_RADIO_RECEIVED);
		} else {
			k_event_post(&s_sl_machine.smf_event, EVENT_RADIO_ERROR);
		}
	}
	// Handle Tx events
	if (events & RAIL_EVENTS_TX_COMPLETION) {
		if (events & RAIL_EVENT_TX_PACKET_SENT) {
			k_event_post(&s_sl_machine.smf_event, EVENT_RADIO_SENT);
		} else {
			k_event_post(&s_sl_machine.smf_event, EVENT_RADIO_ERROR);
		}
	}

	// Perform all calibrations when needed
	if (events & RAIL_EVENT_CAL_NEEDED) {
		calibration_status = RAIL_Calibrate(rail_handle, NULL, RAIL_CAL_ALL_PENDING);
		if (calibration_status) {
			k_event_post(&s_sl_machine.smf_event, EVENT_RADIO_ERROR);
		}
	}
}

// -----------------------------------------------------------------------------
// Static Function Definitions

static void set_up_tx_fifo(RAIL_Handle_t rail_handle)
{
	uint16_t allocated_tx_fifo_size = 0;
	static __ALIGNED(RAIL_FIFO_ALIGNMENT) uint8_t tx_fifo[128];
	allocated_tx_fifo_size = RAIL_SetTxFifo(rail_handle, tx_fifo, 0, sizeof(tx_fifo));
	if (allocated_tx_fifo_size != sizeof(tx_fifo)) {
		LOG_WRN("RAIL_SetTxFifo allocation failed %d instead of %d", allocated_tx_fifo_size,
			sizeof(tx_fifo));
	}
}

/**
 * Prepares the packet for sending and load it in the RAIL TX FIFO
 *
 * @param rail_handle Which rail handlers should be used for the TX FIFO writing
 * @param out_data The payload buffer
 * @param length The length of the payload
 */
static void prepare_package(RAIL_Handle_t rail_handle, uint8_t *out_data, uint16_t length)
{
	// Check if write fifo has written all bytes
	uint16_t bytes_writen_in_fifo = 0;
	bytes_writen_in_fifo = RAIL_WriteTxFifo(rail_handle, out_data, length, true);
	if (bytes_writen_in_fifo != length) {
		LOG_WRN("RAIL_SetTxFifo allocation failed %d instead of %d", bytes_writen_in_fifo,
			length);
	}
}

/**
 * Helps to unpack the received packet, point to the payload and returns the length.
 *
 * @param rx_destination Where should the full packet be unpacked
 * @param packet_information Where should all the information of the packet stored
 * @param start_of_payload Pointer where the payload starts
 * @return The length of the received payload
 */
static uint16_t unpack_packet(uint8_t *rx_destination,
			      const RAIL_RxPacketInfo_t *packet_information,
			      uint8_t **start_of_payload)
{
	RAIL_CopyRxPacket(rx_destination, packet_information);
	*start_of_payload = rx_destination;
	return packet_information->packetBytes;
}

static void rail_isr_installer(void)
{
#ifdef CONFIG_SOC_SERIES_EFR32MG24
	IRQ_CONNECT(SYNTH_IRQn, 0, SYNTH_IRQHandler, NULL, 0);
#else
	IRQ_CONNECT(RDMAILBOX_IRQn, 0, RDMAILBOX_IRQHandler, NULL, 0);
#endif
	IRQ_CONNECT(RAC_SEQ_IRQn, 0, RAC_SEQ_IRQHandler, NULL, 0);
	IRQ_CONNECT(RAC_RSM_IRQn, 0, RAC_RSM_IRQHandler, NULL, 0);
	IRQ_CONNECT(PROTIMER_IRQn, 0, PROTIMER_IRQHandler, NULL, 0);
	IRQ_CONNECT(MODEM_IRQn, 0, MODEM_IRQHandler, NULL, 0);
	IRQ_CONNECT(FRC_IRQn, 0, FRC_IRQHandler, NULL, 0);
	IRQ_CONNECT(BUFC_IRQn, 0, BUFC_IRQHandler, NULL, 0);
	IRQ_CONNECT(AGC_IRQn, 0, AGC_IRQHandler, NULL, 0);
}
