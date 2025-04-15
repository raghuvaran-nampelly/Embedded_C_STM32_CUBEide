/*
 * km_lcd.c
 *
 *  Created on: Apr 9, 2025
 *      Author: nampelly-raghuvaran
 */

/*
*Description :This file contain all the lcd functions
*/

#include "km_lcd.h"
#include "main.h"






void KM_LCD_Init(void)
{
		//HAL_Delay(20);
		KM_LCD_Write_Cmd(0x33);	//used to initialize the display in 4-bit mode
		HAL_Delay(1);
		KM_LCD_Write_Cmd(0x32);	// used to set the LCD to 4-bit mode
		KM_LCD_Write_Cmd(0x0C);	//Display on, cursor off
		KM_LCD_Write_Cmd(0x01);	//Display on, cursor off

}




void KM_LCD_Write_Str(unsigned char str[])
{
	int i=0;
	while(str[i]!='\0')
	{
		KM_LCD_Write_Data(str[i]);//SEND CHARACTER BY CHARACTER
		i++;
	}
}




void KM_LCD_Write_Cmd( unsigned char data)
{
    HAL_GPIO_WritePin(GPIOB, GPIOB_4_Pin, GPIO_PIN_RESET); // RS = 0 for command
	//CLEAR 4TH BIT  TO ENABLE COMMAND MODE
	 write_high_nibble(data);	//CALL HIGHER NIBBLE COMMAND
	 write_low_nibble(data);	//CALL LOWER NIBBLE COMMAND


}




void KM_LCD_Write_Data( unsigned char data)
{
    HAL_GPIO_WritePin(GPIOB,GPIOB_4_Pin , GPIO_PIN_SET); // RS = 1 for data //SET 4TH BIT TO 1 TO ENABLE DATAMODE
	write_high_nibble(data);//CALL HIGHER NIBBLE DATA
	write_low_nibble(data);//CALL LOWER NIBBLE DATA
}




void write_high_nibble( unsigned char data )
{
	data=data>>4;	//SHIFT HIGHER NIBBLE DATA TO LOWER NIBBLE

	// Clear PB0-PB3
	    HAL_GPIO_WritePin(GPIOB, GPIOB_0_Pin, (data & 0x01));
	    HAL_GPIO_WritePin(GPIOB, GPIOB_1_Pin, (data & 0x02));
	    HAL_GPIO_WritePin(GPIOB, GPIOB_2_Pin, (data & 0x04));
	    HAL_GPIO_WritePin(GPIOB, GPIOB_3_Pin, (data & 0x08));

	    HAL_GPIO_WritePin(GPIOB, GPIOB_8_Pin, GPIO_PIN_SET); // EN = 1
	    HAL_Delay(10);
	    HAL_GPIO_WritePin(GPIOB, GPIOB_8_Pin, GPIO_PIN_RESET); // EN = 0

}






void write_low_nibble(unsigned char data)
{
	data &=~(0xf0);	//EXTRACT LOWER NIBBLE

		HAL_GPIO_WritePin(GPIOB, GPIOB_0_Pin, (data & 0x01));
	    HAL_GPIO_WritePin(GPIOB, GPIOB_1_Pin, (data & 0x02));
	    HAL_GPIO_WritePin(GPIOB, GPIOB_2_Pin, (data & 0x04));
	    HAL_GPIO_WritePin(GPIOB, GPIOB_3_Pin, (data & 0x08));

	    HAL_GPIO_WritePin(GPIOB, GPIOB_8_Pin, GPIO_PIN_SET); // EN = 1
	    HAL_Delay(10);
	    HAL_GPIO_WritePin(GPIOB, GPIOB_8_Pin, GPIO_PIN_RESET); // EN = 0
	}



