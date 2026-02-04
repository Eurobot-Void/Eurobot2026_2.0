/*
 * ax12.c
 *
 *  Created on: Feb 3, 2026
 *      Author: Win11
 */

#include "void_moduli/ax12.h"
#include "usart.h"

void ax12_set_position(uint8_t id, uint16_t position) {
	uint8_t packet[9];
	uint8_t checksum = 0;

	packet[0] = 0xFF;
	packet[1] = 0xFF;
	packet[2] = id;
	packet[3] = 5;
	packet[4] = INSTRUCTION_WRITE;
	packet[5] = AX12_GOAL_POSITION;
	packet[6] = position & 0xFF;
	packet[7] = (position >> 8) & 0xFF;

	for (int i = 2; i < 8; i++)
		checksum += packet[i];

	packet[8] = ~checksum;

	HAL_UART_Transmit(&huart6, packet, 9, 100);
}
void ax12_rack_down(void) {
	ax12_set_position(AX12_ID, AX12_RACK_DOWN);
}

void ax12_rack_up(void) {
	ax12_set_position(AX12_ID, AX12_RACK_UP);
}


