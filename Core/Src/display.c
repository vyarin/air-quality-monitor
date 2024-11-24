#include "display.h"

display_status display_PM25(sensor_data const *data) {
    uint16_t concentration = get_concentration(data, 0);
    return DISPLAY_FAIL;
}

display_status display_O3(sensor_data const *data) {
    uint16_t concentration = get_concentration(data, 1);
    return DISPLAY_FAIL;
}

display_status display_NO2(sensor_data const *data) {
    uint16_t concentration = get_concentration(data, 2);
    return DISPLAY_FAIL;
}

// Display gas concentration; try three times
display_status display_concentration(display_state const state, sensor_data const *data) {
    uint8_t tries = 3;

    while (tries > 0) {    
        switch (state) {
        case 0:
            if (display_PM25(&data) == DISPLAY_FAIL) {
                --tries;
            } else {
                return DISPLAY_OK;
            }
            break;
        case 1:
            if (display_O3(&data) == DISPLAY_FAIL) {
                --tries;
            } else {
                return DISPLAY_OK;
            }
            break;

        case 2:
            if (display_NO2(&data) == DISPLAY_FAIL) {
                --tries;
            } else {
                return DISPLAY_OK;
            }
            break;

        default:
            --tries;
            break;
        }
    }

    return DISPLAY_FAIL;
}

void cycle_status(display_state *state) {
    if (*state != 2) {
        state += 1;
    } else {
        state = 0;
    }

    return;
}