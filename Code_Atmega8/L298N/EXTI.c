/*
 * EXTI.c
 *
 * Created: 18/9/2024 7:17:19 PM
 *  Author: Admin
 */ 
#include "EXTI.h"

static volatile CallBackEXTI_t INT0_Interrupt = (CallBackEXTI_t)0;
static volatile CallBackEXTI_t INT1_Interrupt = (CallBackEXTI_t)0;

void EXTI_Innit(EXTI_User_Config_t *EXTI_User_Config){
	if(EXTI_User_Config->EXTI_Number){
		MCUCR |= (EXTI_User_Config->EXTI_Event << 2);		//Event on INT1
		GICR |= (1u << INT1);									//INT 1 enabled
		INT1_Interrupt = EXTI_User_Config->CallBack;
	}
	else{
		MCUCR |= (EXTI_User_Config->EXTI_Event << 0);		//Event on INT0
		GICR |= (1u << INT0);									//INT 0 enabled
		INT0_Interrupt = EXTI_User_Config->CallBack;
	}
	sei();	
}

ISR(INT0_vect){
	INT0_Interrupt();
}

ISR(INT1_vect){
	INT1_Interrupt();
}
 