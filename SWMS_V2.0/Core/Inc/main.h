/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define GPIOB_0_Pin GPIO_PIN_0
#define GPIOB_0_GPIO_Port GPIOB
#define GPIOB_1_Pin GPIO_PIN_1
#define GPIOB_1_GPIO_Port GPIOB
#define GPIOB_2_Pin GPIO_PIN_2
#define GPIOB_2_GPIO_Port GPIOB
#define UP_SW_Pin GPIO_PIN_8
#define UP_SW_GPIO_Port GPIOC
#define DN_SW_Pin GPIO_PIN_9
#define DN_SW_GPIO_Port GPIOC
#define ENT_SW_Pin GPIO_PIN_10
#define ENT_SW_GPIO_Port GPIOC
#define ENT_SW_EXTI_IRQn EXTI15_10_IRQn
#define GPIOB_3_Pin GPIO_PIN_3
#define GPIOB_3_GPIO_Port GPIOB
#define GPIOB_4_Pin GPIO_PIN_4
#define GPIOB_4_GPIO_Port GPIOB
#define GPIOB_5_Pin GPIO_PIN_5
#define GPIOB_5_GPIO_Port GPIOB
#define GPIOB_8_Pin GPIO_PIN_8
#define GPIOB_8_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
