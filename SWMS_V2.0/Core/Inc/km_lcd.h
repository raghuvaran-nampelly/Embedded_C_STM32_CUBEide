/*
 * km_lcd.h
 *
 *  Created on: Apr 9, 2025
 *      Author: nampelly-raghuvaran
 */

#ifndef INC_KM_LCD_H_
#define INC_KM_LCD_H_



#endif /* INC_KM_LCD_H_ */
void Lcd_gpiob_init_config(void);
void KM_LCD_Init(void);

void write_high_nibble( unsigned char data);
void write_low_nibble( unsigned char data);
void KM_LCD_Write_Cmd( unsigned char data);
void KM_LCD_Write_Data( unsigned char data);
void KM_LCD_Write_Str(unsigned char str[]);
void KM_LCD_Write_Int(int n);
void int_to_asci(int n);
