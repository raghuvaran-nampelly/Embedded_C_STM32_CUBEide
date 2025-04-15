/*
 * i2c-lcd.h
 *
 *  Created on: Apr 8, 2025
 *      Author: nampelly-raghuvaran
 */

#ifndef INC_I2C_LCD_H_
#define INC_I2C_LCD_H_



#endif /* INC_I2C_LCD_H_ */

void lcd_clear(void);


void lcd_send_cmd (char cmd);

void lcd_send_data (char data);

void lcd_init (void);

void lcd_send_string (char *str);

void lcd_put_cur(int row, int col);

void lcd_clear();
