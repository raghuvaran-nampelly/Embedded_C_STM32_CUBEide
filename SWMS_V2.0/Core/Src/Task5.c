/*
 * Task5.c
 *
 *  Created on: Apr 13, 2025
 *      Author: nampelly-raghuvaran
 */
#include "Task5.h"
#include "km_lcd.h"
#include "main.h"
extern I2C_HandleTypeDef hi2c1;
void Task5_SWMS_Config(void)
{
	extern unsigned char str[16];
	//extern unsigned char current_date[20];

	unsigned int hour;
	unsigned int minutes;
	unsigned int seconds;
	unsigned int date;
	unsigned int month;
	unsigned int year;

  unsigned char today_date[10];
//	extern unsigned int ENT_SW_Flag;
//	extern unsigned int UP_SW_Flag;
//	extern unsigned int DN_SW_Flag;

	 int config=0;

	//EXTI_IMR &= ~(0X01<<8);
	//EXTI_IMR &= ~(0X01<<9);
	//EXTI_IMR &= ~(0X01<<10);

	KM_LCD_Write_Cmd(0x01);
	KM_LCD_Write_Str((unsigned char *)" HH:MM:SS");
	KM_LCD_Write_Cmd(0xc0);
	KM_LCD_Write_Str((unsigned char *)" DD-MM-YY");

	/*Hours INCREMENT++*/
		if(config==0)
		{
			while(1)
			{
				KM_LCD_Write_Cmd(0xca);
	      KM_LCD_Write_Str((unsigned char *)"Hours");

				if(!(HAL_GPIO_ReadPin(GPIOC,UP_SW_Pin)))
					{
						hour++;
						if(hour > 23)
							{
								hour = 0; // Reset after 23
							}

				if(hour <= 9)
					{
						// For 0-9: Print at 0x82 (leave 0x81 empty)
						KM_LCD_Write_Cmd(0x81);
						KM_LCD_Write_Str((unsigned char *)"0");  // Ensure '0' stays at 0x81
						int_to_asci(hour);
						KM_LCD_Write_Str((unsigned char *)str);
					}

				else
					{
						// For 10-23: Replace '0' at 0x81 and print full hours
						int_to_asci(hour);
						KM_LCD_Write_Cmd(0x81);
						KM_LCD_Write_Str((unsigned char *)str);
					}
			HAL_Delay(300);
		}



	/*Hours DECREMENT--*/


		if(!(HAL_GPIO_ReadPin(GPIOC,DN_SW_Pin)))
		{
			hour--;
			if (hour > 23)
				{
					hour = 0; // Reset after 23
				}

			if(hour <= 9)
				{
					// For 0-9: Print at 0x82 (leave 0x81 empty)
					KM_LCD_Write_Cmd(0x81);
					KM_LCD_Write_Str((unsigned char *)"0");  // Ensure '0' stays at 0x81
					int_to_asci(hour);
					KM_LCD_Write_Str((unsigned char *)str);
				}
			else
				{
					// For 10-23: Replace '0' at 0x81 and print full hours
					int_to_asci(hour);
					KM_LCD_Write_Cmd(0x81);
					KM_LCD_Write_Str((unsigned char *)str);
				}
				HAL_Delay(300);
		}

		if(!(HAL_GPIO_ReadPin(GPIOC,ENT_SW_Pin)))
		{
			config++;
			hour=dectohex(hour);
			today_date[2]=hour;
			HAL_Delay(300);
			KM_LCD_Write_Cmd(0x8B);
			KM_LCD_Write_Str((unsigned char *)"OK");
			HAL_Delay(300);
			KM_LCD_Write_Cmd(0x8B);
			KM_LCD_Write_Str((unsigned char *)"  ");
			KM_LCD_Write_Cmd(0xca);
	    KM_LCD_Write_Str((unsigned char *)"     ");
			break;
		}
	 }
 }

			/********** Minutes INCREMENT ++ *************/

		if(config==1)
		{
				while(1)
					{
						KM_LCD_Write_Cmd(0xca);
						KM_LCD_Write_Str((unsigned char *)"Mins");

						if(!(HAL_GPIO_ReadPin(GPIOC,UP_SW_Pin)))
							{
								minutes++;

								if(minutes > 59)
									{
										minutes = 0;
									}

						KM_LCD_Write_Cmd(0x84);

            if (minutes <= 9)
							{
								KM_LCD_Write_Cmd(0x84);
								KM_LCD_Write_Str((unsigned char *)"0");
								int_to_asci(minutes);
								KM_LCD_Write_Str((unsigned char *)str);
							}

						else
							{
								int_to_asci(minutes);
								KM_LCD_Write_Cmd(0x84);  // Start printing from 0xC1 for two-digit numbers
								KM_LCD_Write_Str((unsigned char *)str);
							}

							HAL_Delay(300);
        }

		/********** Minutes DECREMENT -- *************/
        if (!(HAL_GPIO_ReadPin(GPIOC,DN_SW_Pin)))
        {
            minutes--;
            if (minutes > 59)
            {
                minutes = 0;
            }
            if (minutes <= 9)
						{
						KM_LCD_Write_Cmd(0x84);
						KM_LCD_Write_Str((unsigned char *)"0");
            int_to_asci(minutes);
            KM_LCD_Write_Str((unsigned char *)str);
						}
						else
							{
									int_to_asci(minutes);
									KM_LCD_Write_Cmd(0x84);  // Start printing from 0xC1 for two-digit numbers
									KM_LCD_Write_Str((unsigned char *)str);
							}
							HAL_Delay(300);
        }
				if(!(HAL_GPIO_ReadPin(GPIOC,ENT_SW_Pin)))
		{
			config++;
			minutes=dectohex(minutes);
			today_date[1]=minutes;
			HAL_Delay(300);
			KM_LCD_Write_Cmd(0x8B);
			KM_LCD_Write_Str((unsigned char *)"OK");
			HAL_Delay(300);
			KM_LCD_Write_Cmd(0x8B);
			KM_LCD_Write_Str((unsigned char *)"  ");
			KM_LCD_Write_Cmd(0xca);
	    KM_LCD_Write_Str((unsigned char *)"    ");
			break;
		}
	}
}

        /********** Seconds INCREMENT ++ *************/

		if(config==2)
		{
				while(1)
	{
				KM_LCD_Write_Cmd(0xca);
	      KM_LCD_Write_Str((unsigned char *)"secs");
        if (!(HAL_GPIO_ReadPin(GPIOC,UP_SW_Pin)))
        {
            seconds++;
            if (seconds > 59)
            {
                seconds = 0;  // Reset after 59
            }
            if (seconds <= 9)
						{
						KM_LCD_Write_Cmd(0x87);
						KM_LCD_Write_Str((unsigned char *)"0");
            int_to_asci(seconds);
            KM_LCD_Write_Str((unsigned char *)str);
						}
						 else
							{
									int_to_asci(seconds);
									KM_LCD_Write_Cmd(0x87);  // Start printing from 0xC1 for two-digit numbers
									KM_LCD_Write_Str((unsigned char *)str);
							}
							HAL_Delay(300);
        }

        /********** Seconds DECREMENT -- *************/
        if (!(HAL_GPIO_ReadPin(GPIOC,DN_SW_Pin)))
        {
            seconds--;
            if (seconds > 59)
            {
                seconds = 0;
            }
            KM_LCD_Write_Cmd(0x87);
            if (seconds <= 9)
						{
						KM_LCD_Write_Cmd(0x87);
						KM_LCD_Write_Str((unsigned char *)"0");
            int_to_asci(seconds);
            KM_LCD_Write_Str((unsigned char *)str);
						}
						 else
							{
									int_to_asci(seconds);
									KM_LCD_Write_Cmd(0x87);  // Start printing from 0xC1 for two-digit numbers
									KM_LCD_Write_Str((unsigned char *)str);
							}
							HAL_Delay(300);
        }

			if(!(HAL_GPIO_ReadPin(GPIOC,ENT_SW_Pin)))
				{
					config++;
					seconds=dectohex(seconds);
					today_date[0]=seconds;
					HAL_Delay(300);
					KM_LCD_Write_Cmd(0x8B);
					KM_LCD_Write_Str((unsigned char *)"OK");
					HAL_Delay(300);
					KM_LCD_Write_Cmd(0x8B);
					KM_LCD_Write_Str((unsigned char *)"  ");
					KM_LCD_Write_Cmd(0xca);
					KM_LCD_Write_Str((unsigned char *)"     ");
					break;
				}
		}
}

	/********** Date INCREMENT ++ *************/

	if(config==3)
			{
				while(1)
					{
					KM_LCD_Write_Cmd(0xca);
					KM_LCD_Write_Str((unsigned char *)"date");

					if(!(HAL_GPIO_ReadPin(GPIOC,UP_SW_Pin)))
						{
							date++;

							if(date > 31)
								{
									date = 1;  // Reset after 31
								}

							if (date <= 9)
								{
									KM_LCD_Write_Cmd(0xC1);
									KM_LCD_Write_Str((unsigned char *)"0");  // Print leading zero
									int_to_asci(date);
									KM_LCD_Write_Cmd(0xC2);
									KM_LCD_Write_Str((unsigned char *)str);
								}
							else
								{
									int_to_asci(date);
									KM_LCD_Write_Cmd(0xC1);  // Start printing from 0xC1 for two-digit numbers
									KM_LCD_Write_Str((unsigned char *)str);
								}
					HAL_Delay(300);
		}
	/********** Date DECREMENT -- *************/


	if (!(HAL_GPIO_ReadPin(GPIOC,DN_SW_Pin)))
	{
			date--;
			if (date > 31)
			{
					date = 0;  // Wrap around to 31
			}
			 if (date <= 9)
			{
					KM_LCD_Write_Cmd(0xC1);
					KM_LCD_Write_Str((unsigned char *)"0");  // Print leading zero
					int_to_asci(date);
					KM_LCD_Write_Str((unsigned char *)str);
			}
			else
			{
					int_to_asci(date);
					KM_LCD_Write_Cmd(0xC1);  // Start printing from 0xC1 for two-digit numbers
					KM_LCD_Write_Str((unsigned char *)str);
			}
				HAL_Delay(300);
	}
	if(!(HAL_GPIO_ReadPin(GPIOC,ENT_SW_Pin)))
			{
				config++;
				date=dectohex(date);
				today_date[4]=date;
				HAL_Delay(300);
				KM_LCD_Write_Cmd(0x8B);
				KM_LCD_Write_Str((unsigned char *)"OK");
				HAL_Delay(300);
				KM_LCD_Write_Cmd(0x8B);
				KM_LCD_Write_Str((unsigned char *)"  ");
				KM_LCD_Write_Cmd(0xca);
				KM_LCD_Write_Str((unsigned char *)"    ");
				break;
			}
		 }
		}

	/********** Month INCREMENT ++ *************/
	if(config==4)
			{
				while(1)
					{
						KM_LCD_Write_Cmd(0xca);
						KM_LCD_Write_Str((unsigned char *)"MONTH");
						if(!(HAL_GPIO_ReadPin(GPIOC,UP_SW_Pin)))
							{
								month++;
								if(month > 12)
									{
										month = 1;  // Reset after December
									}

						if(month <= 9)
							{
								KM_LCD_Write_Cmd(0xC4);
								KM_LCD_Write_Str((unsigned char *)"0");  // Print leading zero
								int_to_asci(month);
								KM_LCD_Write_Str((unsigned char *)str);
							}
						else
							{
								int_to_asci(month);
								KM_LCD_Write_Cmd(0xC4);  // Start printing from 0xC4 for two-digit numbers
								KM_LCD_Write_Str((unsigned char *)str);
							}
				HAL_Delay(300);
		}

	/********** Month DECREMENT -- *************/
	if (!(HAL_GPIO_ReadPin(GPIOC,DN_SW_Pin)))
	{
			month--;
			if (month > 12)
			{
					month = 0;
			}

			if (month <= 9)
			{
					KM_LCD_Write_Cmd(0xC4);
					KM_LCD_Write_Str((unsigned char *)"0");  // Print leading zero
					int_to_asci(month);
					KM_LCD_Write_Str((unsigned char *)str);
			}
			else
			{
					int_to_asci(month);
					KM_LCD_Write_Cmd(0xC4);  // Start printing from 0xC4 for two-digit numbers
					KM_LCD_Write_Str((unsigned char *)str);
			}
			HAL_Delay(300);
	}

	if(!(HAL_GPIO_ReadPin(GPIOC,ENT_SW_Pin)))
			{
				config++;
				month=dectohex(month);
				today_date[5]=month;
				HAL_Delay(300);
				KM_LCD_Write_Cmd(0x8B);
				KM_LCD_Write_Str((unsigned char *)"OK");
				HAL_Delay(300);
				KM_LCD_Write_Cmd(0x8B);
				KM_LCD_Write_Str((unsigned char *)"  ");
				KM_LCD_Write_Cmd(0xca);
				KM_LCD_Write_Str((unsigned char *)"     ");
				break;
			}
		}
	}

	/********** Year INCREMENT ++ *************/
	if(config==5)
	{
		while(1)
		{
			KM_LCD_Write_Cmd(0xca);
			KM_LCD_Write_Str((unsigned char *)"YEAR");

			if(!(HAL_GPIO_ReadPin(GPIOC,UP_SW_Pin)))
				{
					year++;
					if(year > 99)
						{
							year = 0;  // Reset after 99
						}

				if(year <= 9)
					{
						KM_LCD_Write_Cmd(0xC7);
						KM_LCD_Write_Str((unsigned char *)"0");  // Print leading zero
						int_to_asci(year);
						KM_LCD_Write_Str((unsigned char *)str);
					}
				else
					{
						int_to_asci(year);
						KM_LCD_Write_Cmd(0xC7);  // Start printing from 0xC7 for two-digit numbers
						KM_LCD_Write_Str((unsigned char *)str);
					}
			HAL_Delay(300);
		}

	/********** Year DECREMENT -- *************/
	if (!(HAL_GPIO_ReadPin(GPIOC,DN_SW_Pin)))
	{
			year--;
			if (year > 99)
			{
					year = 0;
			}
			 if (year <= 9)
			{
					KM_LCD_Write_Cmd(0xC7);
					KM_LCD_Write_Str((unsigned char *)"0");  // Print leading zero
					int_to_asci(year);
					KM_LCD_Write_Str((unsigned char *)str);
			}
			else
			{
					int_to_asci(year);
					KM_LCD_Write_Cmd(0xC7);  // Start printing from 0xC7 for two-digit numbers
					KM_LCD_Write_Str((unsigned char *)str);
			}
			HAL_Delay(300);
	}


	if(!(HAL_GPIO_ReadPin(GPIOC,ENT_SW_Pin)))
			{
				config++;
				year=dectohex(year);
				today_date[6]=year;
				HAL_Delay(300);
				KM_LCD_Write_Cmd(0x8B);
				KM_LCD_Write_Str((unsigned char *)"OK");
				HAL_Delay(300);
				KM_LCD_Write_Cmd(0x8B);
				KM_LCD_Write_Str((unsigned char *)"  ");
				KM_LCD_Write_Cmd(0xca);
				KM_LCD_Write_Str((unsigned char *)"    ");
				break;
			}
		}
	}


	KM_LCD_Write_Cmd(0x01);
	HAL_I2C_Mem_Write(&hi2c1,0x68<<1,0x00,0x01,today_date,7,200); //write data to RTC with I2C protocol

	//EXTI_IMR |= (0X01<<8);
	//EXTI_IMR |= (0X01<<9);
	//EXTI_IMR |= (0X01<<10);
}
















int dectohex(int x)
{
	// Take the remainder of the number when divided by 10, which gives the units digit

	int y=0;

	y=x%10; // Divide the number by 10 and multiply by 16, which shifts the digits to the left by 4 bits

	x = (x / 10) * 16; 	// Add the two values together to give the hexadecimal equivalent of the input number

	return (x + y);

}
