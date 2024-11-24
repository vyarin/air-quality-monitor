#include "sensor_data.h"

uint16_t get_concentration(sensor_data const *raw_data, gas_concentrations *data) {
	data->PM25 = ((*raw_data).PM25_high << 8) | ((*raw_data).PM25_low);
	data->O3 = ((*raw_data).O3_high << 8) | ((*raw_data).O3_low);
	data->NO2 = ((*raw_data).NO2_high << 8) | ((*raw_data).NO2_low);
}
