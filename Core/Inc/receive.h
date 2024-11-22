#ifndef RECEIVE_H
#define RECEIVE_H
#include "sensor_data.h"

typedef enum {
	RECEIVE_OK = 1,
	RECEIVE_FAIL = 0
}
receive_status;

receive_status receive(sensor_data *data);
receive_status check(uint8_t *buffer);

#endif