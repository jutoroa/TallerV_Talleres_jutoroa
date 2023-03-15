/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stm32f4xx.h>

#include "GPIOxDriver.h"

GPIO_Handler_t 		handlerOnBoardLed 		= {0};

int main(void)
{

	/* Configuración PIN, led on-board */
	handlerOnBoardLed.pGPIOx							= GPIOA;
	handlerOnBoardLed.GPIO_PinConfig.GPIO_PinNumber		= PIN_5;
	handlerOnBoardLed.GPIO_PinConfig.GPIO_PinMode		= GPIO_MODE_OUT;
	handlerOnBoardLed.GPIO_PinConfig.GPIO_PinOType		= GPIO_OTYPE_PUSHPULL;
	handlerOnBoardLed.GPIO_PinConfig.GPIO_PinSpeed		= GPIO_OSPEED_FAST;

	GPIO_Config(&handlerOnBoardLed);
	GPIO_WritePin(&handlerOnBoardLed, SET);

	/* Configuración Timer */
	/* Se activa la señal de reloj*/
	RCC->APB1ENR &= ~RCC_APB1ENR_TIM2EN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	/* Configuración de la dirección */
	TIM2->CR1 &= ~TIM_CR1_DIR;

	/* Configuración preescaler */
	TIM2->PSC = 16000;

	/* Configuración counter */
	TIM2->CNT = 0;

	/* Configuración del autoreload */
	TIM2->ARR = 250;

	/* Activación Timer */
	TIM2->CR1 |= TIM_CR1_CEN;

	/* Loop forever */
	while(1){

		if(TIM2->SR & TIM_SR_UIF){
			TIM2->SR &= ~TIM_SR_UIF;
			GPIO_TooglePin(&handlerOnBoardLed);
		}

	}
}
