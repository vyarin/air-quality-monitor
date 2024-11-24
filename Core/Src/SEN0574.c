#include "SEN0574.h"
uint16_t read_ADC(void){
  HAL_ADC_Start(&hadc1); //ADC conversion begins
	if (HAL_ADC_PollForConversion(&hadc1, 100) == HAL_OK) {
	        return HAL_ADC_GetValue(&hadc1); //reading ADC value
	    }
	    return 0;  // If something went wrong
	}
float voltage_to_ppm(float voltage){
	if (voltage < 1.0 || voltage >= 4.7) {
	        return 0.0f;
	    }
	else if (voltage >=1.0 && voltage <= 1.3) { // b/t 1 and 1.3 volts
	        return (voltage - 0.3) * 0.5f;
	}
	else if (voltage > 1.3 && voltage <= 1.5){ // b/t 1.3 and 1.5 volts
		return (voltage - 0.5) * 1.0f;
	}
	else if (voltage > 1.5 && voltage <=1.8){ // b/t 1.5 and 1.8 volts
		return (voltage - 0.8) * 2.0f;
	}
	else if (voltage > 1.8 && voltage <= 2.3){ // b/t 1.8 and 2.3 volts
		return (voltage - 1.3) * 3.0f
	}
	else if (voltage > 2.3 && voltage <= 2.6){ // b/t 2.3 and 2.6 volts
		return (voltage - 1.6) * 4.0f
	}
	else if (voltage > 2.6 && voltage <= 3.1){ // b/t 2.6 and 3.1 volts
		return (voltage - 2.1) * 5.0f
	}
	else if (voltage > 3.1 && voltage <= 3.4){ // b/t 3.1 and 3.4 volts
		return (voltage - 2.4) * 6.0f
	}
	else if (voltage > 3.4 && voltage <= 3.8){ // b/t 3.4 and 3.8 volts
		return (voltage - 2.8) * 7.0f
	}
	else if (voltage > 3.8 && voltage <= 4.1){ // b/t 3.8 and 4.1 volts
		return (voltage - 3.1) * 8.0f
	}
	else if (voltage > 4.1 && voltage <= 4.5){ // b/t 4.1 and 4.5 volts
		return (voltage - 3.5) * 9.0f
	}
	else if (voltage > 4.5 && voltage < 4.7){ // b/t 4.5 and 4.7 volts
		return (voltage - 3.7) * 10.0f
	}
}
