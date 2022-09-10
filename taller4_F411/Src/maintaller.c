/*
 * maintaller.c
 *
 *  Created on: Sep 9, 2022
 *      Author: jutoroa
 */


#include <stdint.h>
#include "GPIOxDriver.h"


#define SUMA	'+'
#define RESTA 	'-'
#define MULTIPLICACION 	'*'
#define DIVISION		'/'

// Funcion Ejemplo del Switch Case
uint16_t resultadoOperacion(uint8_t tipoDeOperacion, uint8_t numeroA,
		uint8_t numeroB);

void delay(uint32_t time);

// Main

int main(void){

	uint16_t operacionFinal = 0;

	operacionFinal = resultadoOperacion(SUMA,12,16);

	// Ejemplo básico del While

	uint8_t contador = 0;

	while(contador < 10){

		contador += 3;

	}

	// Actividad #1:

	// Crear una función llamada delay, que tome un parametro
	//y que no retorne nada.

	// El parametro que debe recibir tiene que mantener
	//ocupado al MCU haciendo nada NOP()

	delay(150000);

	// ACTIVIDAD #2:

	// Prender y apagar un led con la funcion delay

	GPIO_Handler_t handlerstateLED	= {0};

	handlerstateLED.pGPIOx	 = 	GPIOA;
	handlerstateLED.GPIO_PinConfig.GPIO_PinNumber = PIN_5;
	handlerstateLED.GPIO_PinConfig.GPIO_PinMode	= GPIO_MODE_OUT;
	handlerstateLED.GPIO_PinConfig.GPIO_PinOPType =
			GPIO_OTYPE_PUSHPULL;
	handlerstateLED.GPIO_PinConfig.GPIO_PinPuPdControl
	= GPIO_PUPDR_NOTHING;
	handlerstateLED.GPIO_PinConfig.GPIO_PinSpeed =
			GPIO_OSPEED_HIGH;

	GPIO_Config(&handlerstateLED);

	while(1){

		GPIO_WritePin(&handlerstateLED, SET);

		delay(150000);

		GPIO_WritePin(&handlerstateLED, RESET);

		delay(70000);


	}




}



void delay(uint32_t time){

	uint32_t contador = 0;

	while(contador <= time){
		__asm("NOP");
		contador++;
	}
}


uint16_t resultadoOperacion(uint8_t tipoDeOperacion, uint8_t numeroA,
		uint8_t numeroB){

	uint16_t resultado = 0;

	// Estructura switch case

	switch(tipoDeOperacion){

	case SUMA:
	{
		resultado = numeroA + numeroB;
		return resultado;
		// LO MÁS IMPORTANTE
		break;
	}
	case RESTA:
	{
		resultado = numeroA - numeroB;
		return resultado;
		// LO MÁS IMPORTANTE
		break;
	}
	case MULTIPLICACION:
	{
		resultado = numeroA * numeroB;
		return resultado;
		// LO MÁS IMPORTANTE
		break;
	}
	case DIVISION:
	{
		resultado = numeroA / numeroB;
		return resultado;
		// LO MÁS IMPORTANTE
		break;
	}

	default:
	{
		resultado = 0;
		return resultado;
		break;
	}


	}


}






