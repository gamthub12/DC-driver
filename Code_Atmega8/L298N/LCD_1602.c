/*
 * LCD_1602.c
 *
 * Created: 25/10/2024 11:21:59 PM
 *  Author: Admin
 */ 
#include "LCD_1602.h"

void Write2Nib(uint8_t chr){
	uint8_t HNib, LNib, temp_data;
	temp_data=DATA_O & 0x0F; //doc 4 bit thap cua DATA_O de mask,
	HNib=chr & 0xF0;
	LNib=(chr<<4) & 0xF0;

	DATA_O =(HNib |temp_data);
	sbi(CTRL,EN); //enable
	cbi(CTRL,EN); //disable
	_delay_ms(2);

	DATA_O =(LNib|temp_data);
	sbi(CTRL,EN); //enable
	cbi(CTRL,EN); //disable
}

void wait_LCD(){
	_delay_ms(2);
}

void init_LCD(){
	_delay_ms(2);
	DDR_DATA=0xF7;
	//Function set------------------------------------------------------------------------------     
	cbi(CTRL,RS); // the following data is COMMAND
	wait_LCD();
	Write2Nib(0x03);
	wait_LCD();
	Write2Nib(0x03);
	wait_LCD();
	Write2Nib(0x03);
	wait_LCD();
	Write2Nib(0x02);//4 bit mode,
	wait_LCD();
	Write2Nib(0x28);//2 line, 5x8 font
	wait_LCD();
	Write2Nib(0x08);
	wait_LCD();
	Write2Nib(0x06);
	wait_LCD();
	Write2Nib(0x0C);
	wait_LCD();
}

void clr_LCD(){
	cbi(CTRL,RS); //RS=0 mean the following data is COMMAND (not normal DATA)
	Write2Nib(0x01);
	wait_LCD();
}

void putChar_LCD(uint8_t chr){
	sbi(CTRL,RS); //this is a normal DATA
	Write2Nib(chr);
	wait_LCD();
}

void print_LCD(char* str){ 
	unsigned char i;
	for (i=0; str[i] != 0; i++){
		if(str[i] > 0) putChar_LCD(str[i]);
		else putChar_LCD(' ');
	}
}

void move_LCD(uint8_t y,uint8_t x){
	uint8_t Ad;
	Ad = 64*(y-1) + (x-1) + 0x80; 
	cbi(CTRL,RS);
	Write2Nib(Ad);
	wait_LCD();
}

void home_LCD(){
	cbi(CTRL,RS); // the following data is COMMAND
	Write2Nib(0x02);
	wait_LCD();
}