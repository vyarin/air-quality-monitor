#include "MQ131.h"

uint16_t read_ADC(ADC_HandleTypeDef hadc1){
	HAL_ADC_Start(&hadc1); //ADC conversion begins
	if (HAL_ADC_PollForConversion(&hadc1, 100) == HAL_OK) {
	        return HAL_ADC_GetValue(&hadc1); //reading ADC value
	    }
	    return 0;  // If something went wrong
	}

float voltage_to_ppb(float voltage){
	if (voltage >= 4.0 || voltage<1.7) {
	        return 0.0f;
	    }
	else if (voltage <4.0 && voltage >= 3.5) { //b/t 4 and 3.5 volts
	        return (4.5f - voltage) * 75.0f;
	    }
	else if (voltage < 3.5 && voltage >= 3.0) { //b/t 3.5 and 3 volts
	        return (4.0f - voltage) * 100.0f;
	    }
	else if (voltage < 3.0 && voltage >=2.5) { //b/t 3.0 and 2.5 volts
		        return (3.5f - voltage) * 200.0f;
		    }
	else if (voltage < 2.5 && voltage >=2.0) { //b/t 2.5 and 2.0 volts
			        return (3.0f - voltage) * 400.0f;
			    }
	else if (voltage < 2.0 && voltage >=1.7) { //b/t 2.0 and 1.7 volts
			        return (2.7f - voltage) * 1000.0f;
			    }
}
