
// Taller 4 - Ciclos While y Switch Case

#include <stdint.h>

#include "GPIOxDriver.h"

#define SUMA	'+'
#define RESTA	'-'
#define MULTIPLICACION	'*'
#define DIVISION		'/'

// FUNCION SWITCH CASE
uint16_t resultadoOperacion(uint8_t tipoDeOperacion, uint8_t numeroA, uint8_t numeroB);

// FUNCION EJERCICIO #1
void delay(uint32_t time);


int main(void)
{
	// Ejemplo Switch Case básico

    uint16_t operacionFinal = 0;

    operacionFinal = resultadoOperacion(SUMA,12,16);

    operacionFinal++;

    // Ejemplo While básico

    uint8_t contador = 0;

    while(contador < 10){

    	// Diferencia entre While y For
    	contador += 3;
    }

    contador = 0;

    /*
    // Explicación acciones perpetuas
    while(1){

    }*/

    // ACTIVIDAD #1:
    // Crear una funcion delay, que tome un parámetro y que no retorne nada.
    // El parámetro que toma debe de mantener ocupado al MCU haciendo nada (NOP).

    // ACTIVIDAD #2:
    // Prender y apagar un LED con el delay y la funcion WRITEPIN

    GPIO_Handler_t handlerStateLED 			= {0};	// StateLED

	// Configuración el State LED
	handlerStateLED.pGPIOx								= GPIOA;
	handlerStateLED.GPIO_PinConfig.GPIO_PinNumber		= PIN_5;
	handlerStateLED.GPIO_PinConfig.GPIO_PinMode			= GPIO_MODE_OUT;
	handlerStateLED.GPIO_PinConfig.GPIO_PinOPType		= GPIO_OTYPE_PUSHPULL;
	handlerStateLED.GPIO_PinConfig.GPIO_PinPuPdControl	= GPIO_PUPDR_NOTHING;
	handlerStateLED.GPIO_PinConfig.GPIO_PinSpeed		= GPIO_OSPEED_HIGH;

	GPIO_Config(&handlerStateLED);

	while(1){
		GPIO_WritePin(&handlerStateLED, SET);

		delay(150000);

		GPIO_WritePin(&handlerStateLED, RESET);

		delay(70000);

	}


}

// Ejemplo Switch Case básico
uint16_t resultadoOperacion(uint8_t tipoDeOperacion, uint8_t numeroA, uint8_t numeroB){

	uint16_t resultado = 0;

	switch(tipoDeOperacion){

    case SUMA:
    {
    	resultado = numeroA + numeroB;
    	return resultado;
    	break;
    }
    case RESTA:
    {
    	resultado = numeroA - numeroB;
    	return resultado;
    	break;
    }
    case MULTIPLICACION:
    {
    	resultado = numeroA * numeroB;
    	return resultado;
    	break;
    }
    case DIVISION:
    {
    	resultado = numeroA / numeroB;
    	return resultado;
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

// Función ejercicio 1
void delay(uint32_t time){

	uint32_t contador = 0;

	while(contador <= time){
		__asm("NOP");
	}
}
