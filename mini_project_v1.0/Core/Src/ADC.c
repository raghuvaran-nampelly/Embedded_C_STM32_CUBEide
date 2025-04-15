/*
 * ADC.c
 *
 *  Created on: Apr 10, 2025
 *      Author: nampelly-raghuvaran
 */
#include "main.h"
//#include <stdint.h>

 extern ADC_HandleTypeDef hadc1;


uint32_t temp_val=0;

void Adc_Read(void)
{

		  HAL_ADC_Start(&hadc1);  // start ADC
		  HAL_ADC_PollForConversion(&hadc1, 1000);  // wait until ready

		  temp_val = HAL_ADC_GetValue(&hadc1);
		  temp_val=(temp_val*3300)/(4095*10);// get ADC value
			   HAL_Delay(500); // delay for visibility

}
