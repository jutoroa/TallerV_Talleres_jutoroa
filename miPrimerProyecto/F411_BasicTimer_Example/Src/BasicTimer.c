/*
 * BasicTimer.c
 *
 *  Created on: Apr 21, 2022
 *      Author: user
 */

#include "BasicTimer.h"

/*
 * Función que configura un Timer Básico para que genere interruciones de forma periódica
 */

void BTimer_Config(BTIMER_Handler_t *ptrTimerConfig){

	/*0 Desactivamos las interrupciones globales */
	__disable_irq();

	/*1. Activamos la señal de reloj para el periférico especifíco */
	if(ptrTimerConfig->ptrTIMx == TIM2){

		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	}
	else if(ptrTimerConfig->ptrTIMx == TIM3){

		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	}
	else if(ptrTimerConfig->ptrTIMx == TIM4){

		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	}
	else if(ptrTimerConfig->ptrTIMx == TIM5){

		RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
	}

	/*2. Configuramos el modo del timer (UP or DOWN)*/
	if(ptrTimerConfig->timerConfig.Timer_mode == TIMER_MODE_UP){
		// Configuramos el timer en modo UP
		ptrTimerConfig->ptrTIMx->CR1 &= ~TIM_CR1_DIR;

		//Ponemos en cero el contador (CNT)
		ptrTimerConfig->ptrTIMx->CNT = 0;

	}
	else{
		// Configuramos el timer en modo UP
		ptrTimerConfig->ptrTIMx->CR1 |= TIM_CR1_DIR;

		//Ponemos en el contador (CNT) el valor del periodo
		ptrTimerConfig->ptrTIMx->CNT = ptrTimerConfig->timerConfig.Timer_period - 1;

	}

	/*3. COnfiguramos el preescaler */
	ptrTimerConfig->ptrTIMx->PSC = ptrTimerConfig->timerConfig.Timer_speed - 1;

	/*4. Configuramos el periodo de las interrupciones */
	ptrTimerConfig->ptrTIMx->ARR = ptrTimerConfig->timerConfig.Timer_period - 1;

//	/*5. Activamos al timer para que comience a incrementarse*/
//	ptrTimerConfig->ptrTIMx->CR1 |= TIM_CR1_CEN;

	/*6. Activamos la interrupción */
	//Verificamos si se desea interrupcion por "update event"
//	if(ptrTimerConfig->timerConfig.Timer_interrupt == TIMER_INTERRUPT_UPDATE){
		ptrTimerConfig->ptrTIMx->DIER |= TIM_DIER_UIE;
//	}
//	//O por el timer configurado como Compare/Capture
//	else if(ptrTimerConfig->timerConfig.Timer_interrupt == TIMER_INTERRUPT_CC1){
//		ptrTimerConfig->ptrTIMx->DIER |= TIM_DIER_CC1IE;
//	}
//	else if(ptrTimerConfig->timerConfig.Timer_interrupt == TIMER_INTERRUPT_CC2){
//		ptrTimerConfig->ptrTIMx->DIER |= TIM_DIER_CC2IE;
//	}
//	else if(ptrTimerConfig->timerConfig.Timer_interrupt == TIMER_INTERRUPT_CC3){
//		ptrTimerConfig->ptrTIMx->DIER |= TIM_DIER_CC3IE;
//	}
//	else if(ptrTimerConfig->timerConfig.Timer_interrupt == TIMER_INTERRUPT_CC4){
//		ptrTimerConfig->ptrTIMx->DIER |= TIM_DIER_CC4IE;
//	}

	/*7. Activamos la señal de la interrupción en el NVIC*/
	if(ptrTimerConfig->ptrTIMx == TIM2){
		// Activamos la IRQ del TIM2
		__NVIC_EnableIRQ(TIM2_IRQn);
	}
	else if(ptrTimerConfig->ptrTIMx == TIM3){
		// Activamos la IRQ del TIM3
		__NVIC_EnableIRQ(TIM3_IRQn);
	}
	else if(ptrTimerConfig->ptrTIMx == TIM4){
		// Activamos la IRQ del TIM3
		__NVIC_EnableIRQ(TIM4_IRQn);
	}
	else if(ptrTimerConfig->ptrTIMx == TIM5){
		// Activamos la IRQ del TIM3
		__NVIC_EnableIRQ(TIM5_IRQn);
	}

	/* x. Activamos todas las interrupciones globales */
	__enable_irq();
}

void setPeriod(BTIMER_Handler_t *ptrTimerConfig, uint32_t newPeriod){

	/*4. Configuramos el periodo de las interrupciones */
	ptrTimerConfig->ptrTIMx->ARR = newPeriod - 1;

}

/*Función comenzar conversión continua*/
void startCounterTimer(BTIMER_Handler_t *ptrTimerConfig){
	ptrTimerConfig->ptrTIMx->CR1 |= TIM_CR1_CEN;
}

/*Función detener conversión continua*/
void stopCounterTimer(BTIMER_Handler_t *ptrTimerConfig){
	ptrTimerConfig->ptrTIMx->CR1 &= ~TIM_CR1_CEN;
}

__attribute__((weak)) void BTimer2_Callback(void){
	__NOP();
}

__attribute__((weak)) void BTimer3_Callback(void){
	__NOP();
}

__attribute__((weak)) void BTimer4_Callback(void){
	__NOP();
}

__attribute__((weak)) void BTimer5_Callback(void){
	__NOP();
}

//__attribute__((weak)) void CC1_Callback(void){
//	__NOP();
//}
//
//__attribute__((weak)) void CC2_Callback(void){
//	__NOP();
//}
//
//__attribute__((weak)) void CC3_Callback(void){
//	__NOP();
//}
//
//__attribute__((weak)) void CC4_Callback(void){
//	__NOP();
//}

/* Rutina de atención a la interrupción del TIM2 */
void TIM2_IRQHandler(void){

	if(TIM2->SR & TIM_SR_UIF){

		TIM2->SR &= ~TIM_SR_UIF;

		BTimer2_Callback();

	}
//	else if(TIM2->SR & TIM_SR_CC1IF){
//
//		TIM2->SR &= ~TIM_SR_CC1IF;
//
//		CC1_Callback();
//
//	}else if(TIM2->SR & TIM_SR_CC2IF){
//
//		TIM2->SR &= ~TIM_SR_CC2IF;
//
//		CC2_Callback();
//
//	}else if(TIM2->SR & TIM_SR_CC3IF){
//
//		TIM2->SR &= ~TIM_SR_CC3IF;
//
//		CC3_Callback();
//
//	}else if(TIM2->SR & TIM_SR_CC4IF){
//
//		TIM2->SR &= ~TIM_SR_CC4IF;
//
//		CC4_Callback();
//
//	}

}

/* Rutina de atención a la interrupción del TIM3 */
void TIM3_IRQHandler(void){
	TIM3->SR &= ~TIM_SR_UIF;

	BTimer3_Callback();
}

/* Rutina de atención a la interrupción del TIM4 */
void TIM4_IRQHandler(void){
	TIM4->SR &= ~TIM_SR_UIF;

	BTimer4_Callback();
}

/* Rutina de atención a la interrupción del TIM5 */
void TIM5_IRQHandler(void){
	TIM5->SR &= ~TIM_SR_UIF;

	BTimer5_Callback();
}

