/*
 * LCD_interface.h
 *
 *  Created on: Aug 29, 2021
 *      Author: hp
 */

#ifndef LCD_LCD_INTERFACE_H_
#define LCD_LCD_INTERFACE_H_
#include"../lib/bitmath.h"

void lcdcmd(unsigned char x);
void lcddata(unsigned char data);
void lcd_read();
void lcdint();

/*
void LCD_sendCommand(u8 command);
void LCD_sendCharcter(u8 charcter);
void LCD_int(void);
void LCD_string(u8 * name);
void LCD_setCursorPosition(u8 x , u8 y);
void LCD_saveCustomCharacter(u8 char_arr[] , u8 CGRAM_address);
void LCD_PrintNumber(s32 number);
*/
#endif /* LCD_LCD_INTERFACE_H_ */
