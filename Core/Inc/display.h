#ifndef DISPLAY_H
#define DISPLAY_H
#include "sensor_data.h"

typedef enum {
	DISPLAY_OK = 1,
	DISPLAY_FAIL = 0
}
display_status;

typedef enum {
	DISPLAY_PM25 = 0,
	DISPLAY_O3 = 1,
	DISPLAY_NO2 = 2
}
display_state;

display_status display_PM25(sensor_data const *data);
display_status display_O3(sensor_data const *data);
display_status display_NO2(sensor_data const *data);

display_status display_concentration(display_state const state, sensor_data const *data);

void cycle_status(display_state *state);

#endif
