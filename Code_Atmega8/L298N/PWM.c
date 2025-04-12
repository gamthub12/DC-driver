/*
 * PWM.c
 *
 * Created: 23/10/2024 7:14:30 PM
 *  Author: Admin
 */ 
#include "PWM.h"

static volatile Timer1_t Timer1_Interrupt = (Timer1_t)0;
volatile uint8_t timer_overflow_count = 0;

ISR(TIMER2_OVF_vect) {
	timer_overflow_count++;
	if (timer_overflow_count >= 61){
		timer_overflow_count = 0;
		Timer1_Interrupt();
	}
}

ISR(TIMER1_OVF_vect) {
	// Mã th?c thi khi Timer1 tràn (1 giây)
	Timer1_Interrupt();
}

void PWM_Innit(){
	// Fast PWM mode, non-inverting
	TCCR2 |= (1 << WGM21) | (1 << WGM20); // Fast PWM mode
	TCCR2 |= (1 << COM21);                // Non-inverting mode

	// Prescaler = 64
	TCCR2 |= (1 << CS22) | (1 << CS21);   // CS22:1, CS21:1, CS20:0

	// Set initial duty cycle (50%)
	OCR2 = 128; // Duty cycle = 128/255 * 100% = 50%
}

void T1_delay1s(Timer1_t Callback){
	TCCR1A = 0;                         // Normal mode
	TCCR1B = (1 << CS12);               // Prescaler = 256, CS12:1, CS11:0, CS10:0

	// Xóa giá tr? b? ??m
	TCNT1 = 0;

	// B?t ng?t tràn Timer1
	TIMSK |= (1 << TOIE1);
	
	Timer1_Interrupt = Callback;

	// B?t toàn b? ng?t
	sei();
}

void PWM_SetDuty(uint16_t duty){
	OCR2 = duty;
}

void new_PWM_Init(TIM1_Channel Channel, uint16_t period){
	TCCR1A |=  (1u << WGM11);				//waveform = Fast PWM; TOP = ICR1; Bottom = TCNT
	TCCR1B |= (1u << WGM12) | (1u << WGM13);
	if(Channel == Channel_A){
		TCCR1A |= (1u << COM1A1);			//Set at bottom, clear at match
	}
	else{
		TCCR1A |= (1u << COM1B1);			//Set at bottom, clear at match
	}
	ICR1 = period;							//F_CPU => T_CPU => T = T_CPU * period
	TCNT1 = 0x00;
}

void new_PWM_Set_Duty(TIM1_Channel Channel, uint16_t duty_cycle){
	if(Channel == Channel_A){
		OCR1A = duty_cycle;
	}
	else{
		OCR1B = duty_cycle;
	}
}

void new_PWM_Start(){
	TCCR1B |= (1u << CS10);				//No prescaler
}

void new1(Timer1_t CallBack){
	TCCR2 = (1 << CS22) | (1 << CS21) | (1 << CS20); // Prescaler = 1024
	TIMSK |= (1 << TOIE2); // Kích ho?t ng?t Overflow
	Timer1_Interrupt = CallBack;
	sei();                 // Kích ho?t ng?t toàn c?c
}
