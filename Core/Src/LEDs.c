#include "LEDs.h"
void control_LEDs(float index){
  int turn_on = 0;

//Determining how many LEDs to turn on based on AQI
  if(index <= 3)         // Good air quality
    turn_on = 2;
  else if (index <=  6) // Moderate air quality
    turn_on = 4;
  else if (index <= 9) // Bad air quality
    turn_on = 6;
  else                // Very bad air quality
    turn_on = 8;

//Turning on/off LEDs based on num from above
  if(turn_on >= 2){ // Blue LEDs
    HAL_GPIO_WritePin(GPIOB, LED1_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, LED2_PIN, GPIO_PIN_SET);
  }

  if(turn_on >= 4){ // Green LEDs
    HAL_GPIO_WritePin(GPIOC, LED3_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, LED4_PIN, GPIO_PIN_SET);
  }
  else{
    HAL_GPIO_WritePin(GPIOC, LED3_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, LED4_PIN, GPIO_PIN_RESET);
  }

  if(turn_on >= 6){ // Yellow LEDs
    HAL_GPIO_WritePin(GPIOC, LED5_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, LED6_PIN, GPIO_PIN_SET);
  }
  else{
    HAL_GPIO_WritePin(GPIOC, LED5_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, LED6_PIN, GPIO_PIN_RESET);
  }

  if(turn_on >= 8){ // Red LEDs
    HAL_GPIO_WritePin(GPIOB, LED7_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, LED8_PIN, GPIO_PIN_SET);
  }
  else{
    HAL_GPIO_WritePin(GPIOB, LED7_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, LED8_PIN, GPIO_PIN_RESET);
  }
}

