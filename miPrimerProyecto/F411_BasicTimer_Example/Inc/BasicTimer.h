/*
 * BasicTimer.h
 *
 *  Created on: Apr 21, 2022
 *      Author: user
 */

#ifndef INC_BASICTIMER_H_
#define INC_BASICTIMER_H_

#include <stm32f4xx.h>

#define TIMER_MODE_UP		0
#define TIMER_MODE_DOWN		1

#define TIMER_INCR_SPEED_1ms	16000
#define TIMER_INCR_SPEED_100us	1600
#define TIMER_INCR_SPEED_10us	160
#define TIMER_INCR_SPEED_1us	16

#define TIMER_100MHz_INCR_SPEED_100us	10000
#define TIMER_100MHz_INCR_SPEED_10us	1000
#define TIMER_100MHz_INCR_SPEED_1us		100

#define TIMER_INTERRUPT_UPDATE	0
#define TIMER_INTERRUPT_CC1		1
#define TIMER_INTERRUPT_CC2		2
#define TIMER_INTERRUPT_CC3		3
#define TIMER_INTERRUPT_CC4		4

typedef struct
{
	uint8_t 	Timer_mode;			// Selecciona si va Up or Down
	uint16_t 	Timer_speed;		// Configura que tan rapido aumenta el counter
	uint32_t 	Timer_period;		// Cada cuanto se genera una interrupción
//	uint8_t		Timer_interrupt;	//Tipo de interrupción
}BTIMER_Config_t;


typedef struct
{
	TIM_TypeDef		*ptrTIMx;		// Estructura con los registros que componen al periférico
	BTIMER_Config_t	timerConfig;	// Configuración cargada por el usuario
}BTIMER_Handler_t;

/* Prototipo de las funciones - son las funciones publicas */
void BTimer_Config(BTIMER_Handler_t *ptrTimerConfig);
void BTimer2_Callback(void);
void BTimer3_Callback(void);
void BTimer4_Callback(void);
void BTimer5_Callback(void);
void startCounterTimer(BTIMER_Handler_t *ptrTimerConfig);
void stopCounterTimer(BTIMER_Handler_t *ptrTimerConfig);
void setPeriod(BTIMER_Handler_t *ptrTimerConfig, uint32_t newPeriod);

#endif /* INC_BASICTIMER_H_ */
