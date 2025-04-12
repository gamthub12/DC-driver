/*
 * IncFile1.h
 *
 * Created: 19/10/2024 10:17:01 AM
 *  Author: Admin
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

#include <avr/io.h>
#include <stdint.h>

typedef enum{
	Pull_Down,
	Pull_Up,
	Default,
}GPIO_Pull_Type;

typedef enum{
	Input,
	Output,
}GPIO_Direction_Type;

typedef enum{
	PORT_B,
	PORT_C,
	PORT_D,	
}GPIO_PORT_Type;

typedef enum{
	Low,
	High,
}GPIO_Output_value;

typedef struct{
	uint8_t PIN;
	GPIO_PORT_Type PORT;
	GPIO_Direction_Type Direction;
	GPIO_Pull_Type Pull;
}GPIO_Type;

void GPIO_Config(GPIO_Type *GPIOx);
void GPIO_Write_PIN(GPIO_PORT_Type PORTx, uint8_t PIN,GPIO_Output_value Value);
void GPIO_Toggle_PIN(GPIO_PORT_Type PORTx, uint8_t PIN);
uint8_t GPIO_Read_PIN(GPIO_PORT_Type PORTx, uint8_t PIN);


#endif /* INCFILE1_H_ */