#ifndef INC_LCD_CONFIG_H_
#define INC_LCD_CONFIG_H_

/* CONFIG FOR LIBRARY USER */
#define GPIO_PORT GPIOB

//4 pin mode -> pins
#define DATA5_Pin GPIO_PIN_1
#define DATA6_Pin GPIO_PIN_15
#define DATA7_Pin GPIO_PIN_14
#define DATA8_Pin GPIO_PIN_13

#define RS_Pin GPIO_PIN_12
#define E_Pin  GPIO_PIN_2
//RW Pin not used,connect to GND


#endif /* INC_LCD_CONFIG_H_ */
