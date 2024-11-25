#include "AQI_Calculator.h"
#include "math.h"
uint8_t get_AQHI(uint16_t PM25, uint16_t O3, uint16_t NO2){
	//Conversions
	float PM25_ppb = PM25 * 0.001f;

	uint16_t NO2_ppb = NO2 * 1000;

	uint16_t O3_ppb = O3;

	// Applying AQHI formula
	float exp_O3 = exp(0.000537 * O3_ppb) - 1; // exponent for O3
	float exp_NO2 = exp(0.000871 * NO2_ppb) - 1; // exponent for NO2
	float exp_PM25 = exp(0.000537 * PM25_ppb) - 1; //exponent for PM25

	float AQHI = (10/10.4) * 100 * (exp_O3 + exp_NO2 + exp_PM25);

	if (AQHI < 0) {
		AQHI = 0;
	} else if (AQHI > 10) {
		AQHI = 10;
	}

	return (uint8_t)(AQHI);  // Return the AQHI value as uint8_t
}
