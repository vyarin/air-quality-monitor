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

typedef struct gas_concentrations {
	uint16_t PM25;
	uint16_t O3;
	uint16_t NO2;
}
gas_concentrations;

uint16_t get_concentration(sensor_data const *raw_data, gas_concentrations *data);

#endif
