#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H
#include "main.h"

typedef struct sensor_data {
	uint8_t PM25_high;
	uint8_t PM25_low;
	uint8_t O3_high;
	uint8_t O3_low;
	uint8_t NO2_high;
	uint8_t NO2_low;
}
sensor_data;

#endif
