/*
 * GPIO.c
 *
 * Created: 19/10/2024 10:17:31 AM
 *  Author: Admin
 */ 
#include "GPIO.h"

void GPIO_Config(GPIO_Type *GPIOx){
	switch(GPIOx->PORT){
		case PORT_B:{
			DDRB |= (GPIOx->Direction << GPIOx->PIN);
			if(GPIOx->Direction == Input){
				PORTB |= (GPIOx->Pull << GPIOx->PIN);
			}
			break;
		}
		case PORT_C:{
			DDRC |= (GPIOx->Direction << GPIOx->PIN);
			if(GPIOx->Direction == Input){
				PORTC |= (GPIOx->Pull << GPIOx->PIN);
			}
			break;
		}
		case PORT_D:{
			DDRD |= (GPIOx->Direction << GPIOx->PIN);
			if(GPIOx->Direction == Input){
				PORTD |= (GPIOx->Pull << GPIOx->PIN);
			}
			break;
		}		
	}
}

void GPIO_Write_PIN(GPIO_PORT_Type PORTx, uint8_t PIN, GPIO_Output_value Value){
	switch(PORTx){
		case PORT_B:{
			if(Value == High){
				PORTB |= (1u << PIN);
			}
			else{
				PORTB &= ~(1u << PIN);
			}
			break;
		}
		case PORT_C:{
			if(Value == High){
				PORTC |= (1u << PIN);
			}
			else{
				PORTC &= ~(1u << PIN);
			}
			break;
		}
		case PORT_D:{
			if(Value == High){
				PORTD |= (1u << PIN);
			}
			else{
				PORTD &= ~(1u << PIN);
			}
			break;
		}				
	}
}

void GPIO_Toggle_PIN(GPIO_PORT_Type PORTx, uint8_t PIN){
	switch(PORTx){
		case PORT_B:{
			PORTB ^= (1u << PIN);
			break;
		}
		case PORT_C:{
			PORTC ^= (1u << PIN);
			break;
		}
		case PORT_D:{
			PORTD ^= (1u << PIN);
			break;
		}
	}	
}

uint8_t GPIO_Read_PIN(GPIO_PORT_Type PORTx, uint8_t PIN){
	switch(PORTx){
		case PORT_B:{
			if(PINB & (1u << PIN)){
				return 1;
			}
			break;
		}
		case PORT_C:{
			if(PINC & (1u << PIN)){
				return 1;
			}
			break;
		}
		case PORT_D:{
			if(PIND & (1u << PIN)){
				return 1;
			}
			break;
		}
	}
	return 0;	
}
