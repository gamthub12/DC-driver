/*
 * main.h
 *
 * Created: 16/11/2024 7:05:12 PM
 *  Author: Admin
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#include <avr/io.h>
#include "GPIO.h"
#include "PWM.h"
#include "LCD_1602.h"
#include "EXTI.h"
#include "stdlib.h"
#define F_CPU				16000000UL
#include "util/delay.h"


#define Start_Invert		2
#define Increase			1
#define Decrease			4
#define Stop				0

#define IN1					4
#define IN2					5
#define EN1					3


#define WORK				1
#define NOT_WORK			0
#define Iniatilize			2

static uint16_t duty_cycle = 128;
static uint16_t old_Value;
static char snum[3];
static char snum2[3];
static uint8_t State = Iniatilize;
static uint8_t old_State = Iniatilize;
static uint8_t rotate_direction = 0;
static uint8_t old_direction = 0;
static uint16_t pulse = 0;
static uint16_t rpm = 0;
static uint8_t i = 0;
static uint8_t PWM_Percentage = 50;




#endif /* MAIN_H_ */