/*
 * LCD_program.c
 *
 *  Created on: Aug 29, 2021
 *      Author: hp
 */
#include"../lib/STD.h"
#include"../lib/bitmath.h"
#include "../DIO/DIO_interface.h"
#include"LCD_config.h"
#include"LCD_private.h"
#include<avr/eeprom.h>
#include <util/delay.h>

#define lcdport PORTA
#define signal PORTB

#define en PB2
#define rw PB1
#define rs PB0

void lcdcmd(unsigned char x)
{
	lcdport=x;

	signal=(0<<rs)|(0<<rw)|(1<<en);

	_delay_ms(1);

	signal=(0<<rs)|(0<<rw)|(0<<en);

	_delay_ms(50);
}

/*void lcdword(u8 *word)
{
	while(*word != "\0")
	{
		lcddata(*word);
		word++;
	}
}
*/
void lcddata(unsigned char data)
{
	lcdport= data;

	signal= (1<<rs)|(0<<rw)|(1<<en);

	_delay_ms(1);

	signal= (1<<rs)|(0<<rw)|(0<<en);

	_delay_ms(50);
}
/*
void lcd_read()
{
	signal= (1<<rs)|(1<<rw)|(1<<en);

	_delay_ms(1);

	signal= (1<<rs)|(1<<rw)|(0<<en);

	_delay_ms(50);
}
*/
void lcdint()
{
	lcdcmd(0x38);

	_delay_ms(1);

	lcdcmd(0x01);

	_delay_ms(1);

	lcdcmd(0x0F);

	_delay_ms(100);
   lcdcmd(0x82);

   _delay_ms(100);
   lcdcmd(0x89);
   _delay_ms(10);
   lcdcmd(0x01);
}


/*
void LCD_sendCommand(u8 command)
{
	DIO_SetPinValue(DIO_PORTA,DIO_PIN0,0);//RS
	DIO_SetPinValue(DIO_PORTA,DIO_PIN1,0);//RW
	_delay_ms(1);

	DIO_SetPortValue(DIO_PORTB,command);
	_delay_ms(1);

	DIO_SetPinValue(DIO_PORTA,DIO_PIN2,DIO_HIGH);//EN
	_delay_ms(1);
	DIO_SetPinValue(DIO_PORTA,DIO_PIN2,DIO_LOW);//EN
	_delay_ms(1);
}

void LCD_sendCharcter(u8 charcter)
{
	DIO_SetPinValue(DIO_PORTA,DIO_PIN0,1);//RS
	DIO_SetPinValue(DIO_PORTA,DIO_PIN1,0);//RW
	_delay_ms(1);

    DIO_SetPortValue(DIO_PORTB,charcter);
	_delay_ms(1);

	DIO_SetPinValue(DIO_PORTA,DIO_PIN2,DIO_HIGH);//EN
	_delay_ms(1);
	DIO_SetPinValue(DIO_PORTA,DIO_PIN2,DIO_LOW);//EN
	_delay_ms(1);
}

void LCD_init(void)
{
	DIO_SetPortDirection(DIO_PORTA,0xff);
	DIO_SetPortDirection(DIO_PORTB,0xff);
	_delay_ms(50);
	LCD_sendCommand(0b00111000);
	_delay_ms(1);
	LCD_sendCommand(0b00001100);
	_delay_ms(1);
	LCD_sendCommand(0b00000001);
	_delay_ms(5);
	LCD_sendCommand(0b00000110);
    _delay_ms(1);

}

void LCD_string(u8 * name)
{
	while(*name != "\0")
	{
      LCD_sendCharcter(*name);
      name++;
	}
}

void LCD_setCursorPosition(u8 x , u8 y)
{

   if(y == 0)
   {

	   LCD_sendCommand(0x80 + x + 0) ;

   }

   else if(y == 1)
   {

	   LCD_sendCommand(0x80 + x + 64) ;

   }

}


void LCD_saveCustomCharacter(u8 char_arr[] , u8 CGRAM_address)
{

   // CGRAM	address

   LCD_sendCommand(0b01000000 + (CGRAM_address * 8)) ;

   for(int i = 0 ; i < 8 ; i++)
   {

	   LCD_sendCharcter(char_arr[i]) ;

   }

}

void LCD_PrintNumber(u8 number)
{

	//u32 reversed = 0  ;
    char str[100] ;

    sprintf(str , "%d" , number) ;
    LCD_string(str) ;

}
*/
