#include "display.h"
#include "lcd.h"

display_status display_PM25(gas_concentrations *data) {
    uint16_t concentration = data->PM25;
    char buffer[13];
    sprintf((&buffer), "PM2.5: %d", concentration);
	clearLCD();
	writeLCD(&buffer);
    return DISPLAY_OK;
}

display_status display_O3(gas_concentrations *data) {
    uint16_t concentration = data->O3;
    char buffer[10];
    sprintf((&buffer), "O3: %d", concentration);
	clearLCD();
	writeLCD(&buffer);
    return DISPLAY_OK;
}

display_status display_NO2(gas_concentrations *data) {
    uint16_t concentration = data->NO2;
	char buffer[11];
    sprintf((&buffer), "NO2: %d", concentration);
	clearLCD();
	writeLCD(&buffer);
    return DISPLAY_OK;
}

// Display gas concentration; try three times
display_status display_concentration(display_state state, gas_concentrations *data) {
    uint8_t tries = 3;

    while (tries > 0) {
    	if (state == 0) {
    		if (display_PM25(data) != DISPLAY_OK) {
				--tries;
			} else {
				return DISPLAY_OK;
			}
    	} else if (state == 1) {
    		 if (display_O3(data) != DISPLAY_OK) {
				--tries;
			} else {
				return DISPLAY_OK;
			}
    	} else {
    		if (display_NO2(data) != DISPLAY_OK) {
				--tries;
			} else {
				return DISPLAY_OK;
			}
    	}
    }

    return DISPLAY_FAIL;
}

void cycle_status(display_state *state) {
    if (*state != 2) {
        *state += 1;
    } else {
        *state = 0;
    }

    return;
}
