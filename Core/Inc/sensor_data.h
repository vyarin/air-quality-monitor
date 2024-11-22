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

uint16_t get_concentration(sensor_data const *data, uint8_t particle) {
	if (particle == 0) {
		return ((*data).PM25_high << 8) | ((*data).PM25_low);
	} else if (particle == 1) {
		return ((*data).O3_high << 8) | ((*data).O3_low);
	} else {
		return ((*data).NO2_high << 8) | ((*data).NO2_low);
	}
}

#endif
