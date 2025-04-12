/*
 * L298N.c
 *
 * Created: 21/10/2024 9:58:01 AM
 * Author : Admin
 */ 
#include "main.h"


void Timer1_overflow(){
	//convert rpm
	if(State == Iniatilize){
		return;
	}
	rpm = pulse * 3;
	itoa(rpm,snum2,10);
	move_LCD(2,1);
	for(i = 0; i < 12; i++){
		print_LCD(" ");
	}
	move_LCD(2,1);
	print_LCD("rpm: ");
	print_LCD(snum2);
	pulse = 0;
}

void Pulse_Interrupt(){
	pulse++;
}

int main(void)
{
    /* Replace with your application code */
	GPIO_Type Button;
	Button.PORT = PORT_B;
	Button.Direction = Input;
	Button.Pull = Pull_Up;
	
	Button.PIN = Start_Invert;
	GPIO_Config(&Button);
					
	Button.PIN = Stop;
	GPIO_Config(&Button);
	
	Button.PIN = Increase;
	GPIO_Config(&Button);
	
	Button.PIN = Decrease;
	GPIO_Config(&Button);
	
	
	GPIO_Type IN;
	IN.PORT = PORT_C;
	IN.Direction = Output;
	IN.Pull = Default;
	
	IN.PIN = IN1;
	GPIO_Config(&IN);
	
	IN.PIN = IN2;
	GPIO_Config(&IN);
		
	GPIO_Type ENA;
	ENA.PORT = PORT_B;
	ENA.PIN = EN1;
	ENA.Direction = Output;
	ENA.Pull = Default;
	GPIO_Config(&ENA);
	
	GPIO_Type Encoder;
	Encoder.PORT = PORT_D;
	Encoder.PIN = 3;
	Encoder.Direction = Input;
	Encoder.Pull = Pull_Up;
	GPIO_Config(&Encoder);
	
	EXTI_User_Config_t Pulse;
	Pulse.EXTI_Event = Falling_Edge;
	Pulse.EXTI_Number = INT_1;
	Pulse.CallBack = &Pulse_Interrupt;
	EXTI_Innit(&Pulse);
	
	GPIO_Write_PIN(PORT_C, IN2, Low);
	GPIO_Write_PIN(PORT_C, IN1, Low);	
	
	//new_PWM_Init(Channel_A, 10000);
	//new_PWM_Set_Duty(Channel_A, duty_cycle);
	//new_PWM_Start();
	PWM_Innit();
	init_LCD();
	clr_LCD();
	//new1(&Timer2_overflow);
	print_LCD("Thien 20216243");
	move_LCD(2,1);
	print_LCD("Dung 20216065");
	T1_delay1s(&Timer1_overflow);
	while (1) 
    {
		if(State == WORK){
			if(old_Value != duty_cycle){
				itoa(PWM_Percentage, snum, 10);
				move_LCD(1,1);
				for(i = 0; i < 12; i++){
					print_LCD(" ");
				}
				move_LCD(1,1);
				print_LCD("PWM: ");
				print_LCD(snum);
				putChar_LCD(0x25);
				old_Value = duty_cycle;
			}
		}
		if(!GPIO_Read_PIN(PORT_B, Start_Invert)){
			if(State == Iniatilize || State == NOT_WORK){
				State = WORK;
				GPIO_Write_PIN(PORT_C, IN1, High);
				GPIO_Write_PIN(PORT_C, IN2, Low);
				move_LCD(2, 13);
				print_LCD("   ");
				move_LCD(2, 13);
				print_LCD("CW");
			}
			else{
				GPIO_Toggle_PIN(PORT_C, IN1);
				GPIO_Toggle_PIN(PORT_C, IN2);
				rotate_direction = ~rotate_direction;				
			}
			if(rotate_direction != old_direction){
				if(rotate_direction){
				move_LCD(2, 13);
				print_LCD("   ");
				move_LCD(2, 13);
				print_LCD("CCW");
				}
				else{
				move_LCD(2, 13);
				print_LCD("   ");
				move_LCD(2, 13);
				print_LCD("CW");
				}
				old_direction = rotate_direction;
			}

			while(!GPIO_Read_PIN(PORT_B, Start_Invert));
		}
		if(State == NOT_WORK){
			continue;
		}
		else if(!GPIO_Read_PIN(PORT_B, Increase)){
			if(duty_cycle >= 250){
				duty_cycle = 255;
			}
			else{
				duty_cycle = duty_cycle + 25;
				PWM_SetDuty(duty_cycle);
				PWM_Percentage += 10;
				while(!GPIO_Read_PIN(PORT_B, Increase));				
			}

		}
		else if(!GPIO_Read_PIN(PORT_B, Decrease)){
			if(duty_cycle <= 10){
				duty_cycle = 0;
			}
			else{
				duty_cycle = duty_cycle - 25;
				PWM_SetDuty(duty_cycle);
				PWM_Percentage -= 10;
				while(!GPIO_Read_PIN(PORT_B, Decrease));				
			}

		}	
		else if(!GPIO_Read_PIN(PORT_B, Stop)){
			State = NOT_WORK;
			GPIO_Write_PIN(PORT_C, IN1, Low);
			GPIO_Write_PIN(PORT_C, IN2, Low);
			while(!GPIO_Read_PIN(PORT_B, Stop));
		}
		if(State != old_State){
			if(State == WORK){
				move_LCD(1, 13);
				print_LCD("      ");
				move_LCD(1, 13);
				print_LCD("On");
				old_State = State;
			}
			else{
				move_LCD(1, 13);
				print_LCD("      ");
				move_LCD(1, 13);
				print_LCD("Off");
				old_State = State;
			}
		}
    }
}

