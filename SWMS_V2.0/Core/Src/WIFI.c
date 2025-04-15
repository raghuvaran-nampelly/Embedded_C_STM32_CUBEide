/*
 * WIFI.c
 *
 *  Created on: Apr 11, 2025
 *      Author: nampelly-raghuvaran
 */



#include "main.h"


//#include "UART.h"

#include "km_lcd.h"
#include "WIFI.h"
#include <string.h>
//#include "../All_Task.h"
#include <stdio.h>
//extern unsigned char timeout_flag;
//extern int temp_sensor;
//	char Rx_Buffer[800];
extern UART_HandleTypeDef huart6;



uint8_t Rx_Buffer[800];



int cip_status_flag=0;


void wifi_init(void)
{
//	int counter=1,timeout=0;
	KM_LCD_Write_Cmd(0x01);
	KM_LCD_Write_Str((unsigned char*)"WIFI Init....");

	HAL_UART_Transmit(&huart6,(uint8_t*)"AT\r\n", strlen("AT\r\n"), 100);

		if(Wifi_Responce("OK",2000)==0)
			{
				KM_LCD_Write_Cmd(0x01);
				KM_LCD_Write_Str((unsigned char*)"AT OK");
			}
		else
		{
		KM_LCD_Write_Cmd(0x01);
		KM_LCD_Write_Str((unsigned char*)"AT error");
		}

			//	HAL_Delay(1000);
	HAL_UART_Transmit(&huart6,(uint8_t*) "AT+RST\r\n", strlen("AT+RST\r\n"), 100);

	if(Wifi_Responce("OK",5000)==0)
	{
		KM_LCD_Write_Cmd(0x01);
		KM_LCD_Write_Str((unsigned char*)"RST 0k");

	}
	else
	{
		KM_LCD_Write_Cmd(0x01);
		KM_LCD_Write_Str((unsigned char*)"RST error");

	}

	//HAL_Delay(1000);

	HAL_UART_Transmit(&huart6,(uint8_t*) "AT+CWMODE=3\r\n", strlen("AT+CWMODE=3\r\n"), 100);


	if(Wifi_Responce("OK",1000)==0)
	{
		KM_LCD_Write_Cmd(0x01);
		KM_LCD_Write_Str((unsigned char*)"CWMODE 0k");


	}
	else
	{
		KM_LCD_Write_Cmd(0x01);
		KM_LCD_Write_Str((unsigned char*)"CWMODE error");


	}
	//HAL_Delay(1000);

	HAL_UART_Transmit(&huart6,(uint8_t*) "AT+CWJAP=\"Raghuvaran\",\"000000000\"\r\n",strlen("AT+CWJAP=\"Raghuvaran\",\"000000000\"\r\n"), 100);



		if(Wifi_Responce("OK",7000)==0)
	{
		KM_LCD_Write_Cmd(0x01);
		KM_LCD_Write_Str((unsigned char*)"CWJAP 0k");
		HAL_Delay(100 );
		KM_LCD_Write_Cmd(0x01);
		KM_LCD_Write_Str((unsigned char*)"wi-fi connected");


	}
	else
	{
		KM_LCD_Write_Cmd(0x01);
		KM_LCD_Write_Str((unsigned char*)"CWJAP FAIL");
		HAL_Delay(100);
		KM_LCD_Write_Cmd(0x01);
		KM_LCD_Write_Str((unsigned char*)"wifi not connected");


	}
		HAL_Delay(1000);

		HAL_UART_Transmit(&huart6,(uint8_t*) "AT+CIFSR\r\n", strlen("AT+CIFSR\r\n"), 100);


	if(Wifi_Responce("OK",1000)==0)
	{
		KM_LCD_Write_Cmd(0x01);
		KM_LCD_Write_Str((unsigned char*)"CIFSR 0k");


	}
	else
	{
		KM_LCD_Write_Cmd(0x01);
		KM_LCD_Write_Str((unsigned char*)"CIFSR error");


	}

	//HAL_Delay(1000);

	HAL_UART_Transmit(&huart6,(uint8_t*) "AT+CIPMUX=0\r\n", strlen("AT+CIPMUX=0\r\n"), 100);


	if(Wifi_Responce("OK",1000)==0)
	{



	}
	else
	{
		KM_LCD_Write_Cmd(0x01);
		KM_LCD_Write_Str((unsigned char*)"CIPMUX error");

	}
//	HAL_Delay(1000);

	HAL_UART_Transmit(&huart6,(uint8_t*) "AT+CIPMODE=0\r\n",strlen("AT+CIPMODE=0\r\n"), 100);


	//UART6_Outstr("AT+CIPMODE=0\r\n");
	if(Wifi_Responce("OK",1000)==0)
	{
		KM_LCD_Write_Cmd(0x01);
		KM_LCD_Write_Str((unsigned char*)"wifi connected");


	}
	else
	{
		KM_LCD_Write_Cmd(0x01);
		KM_LCD_Write_Str((unsigned char*)"CIPMODE error");

	}
//	HAL_Delay(1000);




}













int Wifi_Responce(char str[],int loop)
{
	int i=0;

	HAL_UART_Receive(&huart6, Rx_Buffer, 800, loop);


	  if(mystrstr(Rx_Buffer , str)==0)
		{
			return 0;
		}

	return -1;

}






//my strstr function

int mystrstr(char str[],char substr[])
{
    int i=0,j=0,n=0;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]==substr[j])
        {
            n=i;
            while(str[n]==substr[j]&&substr[j]!=0)
            {
                n++;
                j++;
            }
            if(substr[j]=='\0')
            {
                return 0;
            }
            j=0;
        }
    }



return 1;
}

