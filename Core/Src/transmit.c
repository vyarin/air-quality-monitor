#include "transmit.h"
#include "sensor_data.h"
#include "usart.h"

transmit_status transmit(sensor_data *data) {
	uint8_t tx_buffer[8] = {0x43,
							0x45,
							(*data).PM25_high,
							(*data).PM25_low,
							(*data).O3_high,
							(*data).O3_low,
							(*data).NO2_high,
							(*data).NO2_low};

	if (HAL_UART_Transmit(&huart2, tx_buffer, 8, 1000) == HAL_OK) {
		return TRANSMIT_OK;
	} else {
		return TRANSMIT_FAIL;
	}
}
