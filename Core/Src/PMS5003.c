#include "usart.h"
#include "PMS5003.h"

PMS5003_status read_PM25_data(uint16_t *PM25) {
	uint8_t rx_buffer[32] = {0};

	if (HAL_UART_Receive(&huart1, rx_buffer, 32, 1000) == HAL_OK) {
		if (PMS5003_checksum(rx_buffer) == PMS5003_OK) {
			*PM25 = (rx_buffer[7] | (((uint16_t) rx_buffer[6]) << 8));
			return PMS5003_OK;
		} else {
			return PMS5003_FAIL;
		}
	} else {
		return PMS5003_FAIL;
	}
}

PMS5003_status PMS5003_checksum(uint8_t *rx_buffer) {
	// Check start bit
	if (rx_buffer[0] == 0x42) {
		uint16_t sum = 0;

		for (int k = 0; k < 30; ++k) {
			sum += (uint16_t) rx_buffer[k];
		}

		// Checksum check
		if (sum != (rx_buffer[31] | (((uint16_t) rx_buffer[30]) << 8))) {
			return PMS5003_FAIL;
		} else {
			return PMS5003_OK;
		}

	} else {
		return PMS5003_FAIL;
	}

}
