/*
 * All_Task.c
 *
 *  Created on: Apr 11, 2025
 *      Author: nampelly-raghuvaran
 */

#include "main.h"
#include <stdio.h>
#include "km_lcd.h"
#include "ADC.h"
//#include "UART.h"
#include "WIFI.h"
#include "All_Task.h"
#include <string.h>



extern UART_HandleTypeDef huart6;
extern I2C_HandleTypeDef hi2c1;

#define RTC_ADDR (0x68<<1)
#define EEPROM_ADDR (0x50<<1)
extern int temp_sensor;
extern int Tick1,Tick2;
extern int cip_status_flag;
char fetch[20];
int lm35_flag=0;
int wifi_flag=0;
int i=0;
//int LM_35_flag=0;

extern unsigned char str[16];

char buffer[100];

unsigned char cur_date[30];





void Task1_ReadRTC_WriteLCD_1Sec(void)
{
	//			KM_I2C_Mem_Read(RTC_ADDR,0x00,0x1,cur_date,7);
	HAL_I2C_Mem_Read (&hi2c1, RTC_ADDR,0x00,0x01,(uint8_t *) cur_date,7, 100);
				sprintf(buffer,"%02d:%02d:%02d",(cur_date[2]-6*(cur_date[2]>>4)),(cur_date[1]-6*(cur_date[1]>>4)),(cur_date[0]-6*(cur_date[0]>>4)));
				KM_LCD_Write_Cmd(0x80);
				KM_LCD_Write_Str((unsigned char *)buffer);

				sprintf(buffer,"%02d/%02d/%02d",cur_date[4]-6*(cur_date[4]>>4),cur_date[5]-6*(cur_date[5]>>4),cur_date[6]-6*(cur_date[6]>>4));
				KM_LCD_Write_Cmd(0xC0);
				KM_LCD_Write_Str((unsigned char *)buffer);

}


void Task2_ReadLM35_WriteLCD_5Sec(void)
{
		char fetch[200];

	KM_ADC_Read();
	sprintf(fetch,"T:%d%c%c",temp_sensor,0xDF,'C');
	KM_LCD_Write_Cmd(0x8A);
	KM_LCD_Write_Str((unsigned char*)fetch);
				lm35_flag=1;


}



void Task3_WiFi_Tx(void)
{
	lm35_flag=0;
	HAL_UART_Transmit(&huart6,(uint8_t*)"AT+CIPSTART=\"TCP\",\"142.93.218.33\",80\r\n", strlen("AT+CIPSTART=\"TCP\",\"142.93.218.33\",80\r\n"), 100);

//	UART6_Outstr("AT+CIPSTART=\"TCP\",\"142.93.218.33\",80\r\n");
	HAL_Delay(5);
	HAL_UART_Transmit(&huart6,(uint8_t*) "AT+CIPSEND=39\r\n", strlen("AT+CIPSEND=39\r\n"), 100);

//	UART6_Outstr("AT+CIPSEND=39\r\n");
	HAL_Delay(5);
	sprintf(fetch,"GET /page.php?temp=%d&hum=70&dev=21\r\n\r\n",temp_sensor);

//	UART6_Outstr(fetch);
	HAL_UART_Transmit(&huart6,(uint8_t*)fetch , strlen(fetch), 100);

	HAL_Delay(5);
//  UART6_Outstr("AT+CIPCLOSE\r\n");
	HAL_UART_Transmit(&huart6,(uint8_t*) "AT+CIPCLOSE\r\n", strlen("AT+CIPCLOSE\r\n"), 100);

	KM_LCD_Write_Cmd(0xCA);
	KM_LCD_Write_Str((unsigned char *)"TCP:H");
	wifi_flag=0;
}



void EEPROM_Write(void)
{
		for(i=0;i<7;i++)
		{
			buffer[i]=cur_date[i]-6*(cur_date[i]>>4);
		}
		buffer[i]=temp_sensor;
		HAL_I2C_Mem_Write(&hi2c1,EEPROM_ADDR,0x00,0x01,(uint8_t *)buffer,9,100);
		KM_LCD_Write_Cmd(0xCA);
		KM_LCD_Write_Str((unsigned char *)"TCP:L");
		lm35_flag=0;
		wifi_flag=0;
}





void Task4_Check_InternetStatus(void)
{
//	UART6_Outstr("AT+CIPSTATUS\r\n");
	HAL_UART_Transmit(&huart6,(uint8_t*) "AT+CIPSTATUS\r\n", strlen("AT+CIPSTATUS\r\n"), 100);

	if(Wifi_Responce("STATUS:5",50)==0)
	{
		wifi_flag=0;
	}
	else
	{
		wifi_flag=1;
	}


}
