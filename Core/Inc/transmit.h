#ifndef TRANSMIT_H
#define TRANSMIT_H
#include "sensor_data.h"

typedef enum {
	TRANSMIT_OK = 1,
	TRANSMIT_FAIL = 0
}
transmit_status;

transmit_status transmit(sensor_data *data);

#endif
