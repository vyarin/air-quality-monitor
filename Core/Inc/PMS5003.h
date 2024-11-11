#ifndef PMS5003_H
#define PMS5003_H
#include "main.h"

typedef enum {
	PMS5003_OK = 1,
	PMS5003_FAIL = 0
}
PMS5003_status;

// Read PM2.5 concentration under atmospheric environment
PMS5003_status read_PM25_data(uint16_t *PM25);
PMS5003_status PMS5003_checksum(uint8_t *rx_buffer);

#endif
