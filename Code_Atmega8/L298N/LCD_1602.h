/*
 * LCD_1602.h
 *
 * Created: 25/10/2024 11:22:15 PM
 *  Author: Admin
 */ 
#include <avr/io.h>
#define F_CPU		16000000UL
#include <util/delay.h>

#ifndef LCD_1602_H_
#define LCD_1602_H_

#define sbi(sfr,bit)			sfr |= (1u << bit)
#define cbi(sfr,bit)			sfr &= ~(1u << bit)

#define EN                      2
#define RW                      1
#define RS                      0

#define CTRL                    PORTD
#define DDR_CTRL				DDRD

#define DATA_O                  PORTD
#define DDR_DATA				DDRD

void Write2Nib(uint8_t chr);
void wait_LCD();
void init_LCD();
void clr_LCD();
void home_LCD();
void move_LCD(uint8_t y,uint8_t x);
void putChar_LCD(uint8_t chr);
void print_LCD(char* str);





#endif /* LCD_1602_H_ */