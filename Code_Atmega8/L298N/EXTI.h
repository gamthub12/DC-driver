/*
 * EXTI.h
 *
 * Created: 18/9/2024 7:17:07 PM
 *  Author: Admin
 */ 
#include <avr/interrupt.h>
typedef void (*CallBackEXTI_t)();

typedef enum{
	INT_0,
	INT_1,
	}EXTI_Number_t;

typedef enum{
	Low_Level,
	Logical_Change,
	Falling_Edge,
	Rising_Edge,
	}EXTI_Event_t;
	
typedef struct{
	EXTI_Number_t EXTI_Number;
	EXTI_Event_t EXTI_Event;
	CallBackEXTI_t CallBack;
	}EXTI_User_Config_t;
	
void EXTI_Innit(EXTI_User_Config_t *EXTI_User_Config);