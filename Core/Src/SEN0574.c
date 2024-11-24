#include "SEN0574.h"
uint16_t read_ADC(void){
  HAL_ADC_Start(&hadc1); //ADC conversion begins
	if (HAL_ADC_PollForConversion(&hadc1, 100) == HAL_OK) {
	        return HAL_ADC_GetValue(&hadc1); //reading ADC value
	    }
	    return 0;  // If something went wrong
	}
float voltage_to_PPB(float voltage){
}
