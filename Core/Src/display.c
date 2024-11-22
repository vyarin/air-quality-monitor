#include "display.h"

void cycle_status(display_state *state) {
    if (*state != 2) {
        state += 1;
    } else {
        state = 0;
    }

    return;
}