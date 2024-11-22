#include "receive.h"
#include "usart.h"

receive_status receive(sensor_data *data) {
    uint8_t rx_buffer[8] = {0};

    if (HAL_UART_Receive(&huart2, rx_buffer, 8, 1000) == HAL_OK) {
        if (check(rx_buffer) == RECEIVE_OK) {
        	(*data).PM25_high = rx_buffer[2];
			(*data).PM25_low = rx_buffer[3];
			(*data).O3_high = rx_buffer[4];
			(*data).O3_low = rx_buffer[5];
			(*data).NO2_high = rx_buffer[6];
			(*data).NO2_low = rx_buffer[7];

            return RECEIVE_OK;
        } else {
        	return RECEIVE_FAIL;
        }
    }

    return RECEIVE_FAIL;
}

receive_status check(uint8_t *rx_buffer) {
    if ((rx_buffer[0] == 0x43) && (rx_buffer[1] == 0x45)) {
        return RECEIVE_OK;
    } else {
        return RECEIVE_FAIL;
    }
}
