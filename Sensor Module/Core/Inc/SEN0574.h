#ifndef SEN0574_H
#define SEN0574_H
#include "main.h"
uint16_t read_ADC(ADC_HandleTypeDef hadc1);
float voltage_to_ppm(float voltage);
#endif
