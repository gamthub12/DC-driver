/*
 * PWM.h
 *
 * Created: 23/10/2024 7:14:42 PM
 *  Author: Admin
 */ 


#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>

typedef void (*Timer1_t)();

typedef enum{
	Channel_A,
	Channel_B,
}TIM1_Channel;

void PWM_Innit();
void T1_delay1s(Timer1_t Callback);
void PWM_SetDuty(uint16_t duty);
void new_PWM_Init(TIM1_Channel Channel, uint16_t period);
void new_PWM_Set_Duty(TIM1_Channel Channel, uint16_t duty_cycle);
void new_PWM_Start();
void new1(Timer1_t CallBack);




#endif /* PWM_H_ */