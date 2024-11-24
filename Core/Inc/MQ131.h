#ifndef MQ131_H
#define MQ131_H
#include "main.h"
uint16_t read_ADC(ADC_HandleTypeDef hadc1);
float voltage_to_ppb(float voltage);
#endif
