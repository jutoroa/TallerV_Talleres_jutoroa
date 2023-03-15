
// Taller 6 - Ciclos While y Switch Case

#include <stdint.h>

#include "GPIOxDriver.h"

#define SUMA	'+'
#define RESTA	'-'
#define MULTIPLICACION	'*'
#define DIVISION		'/'


// FUNCION SWITCH CASE
uint16_t resultadoOperacion(uint8_t tipoDeOperacion, uint8_t numeroA, uint8_t numeroB);

// Ejercicio #1
#define FACTORIAL	0
#define FIBONACCI	1

uint16_t operacionesFunc(uint8_t typeOperation, uint8_t number);

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

    /* ACTIVIDAD #1:
    Crear una función que tome dos parámetros: 1er parametro deberá indicar el tipo de operación
    (Factorial, o la sucesión de Fibonacci). El 2do paramétro deberá dar cuenta del número al que
    se le quiera realizar el factorial, o hallar el n-ésimo término de la sucesión de fibonacci
   */

    uint16_t exampleVar;

    exampleVar = operacionesFunc(FIBONACCI,0);
    exampleVar = operacionesFunc(FIBONACCI,1);
    exampleVar = operacionesFunc(FIBONACCI,2);
    exampleVar = operacionesFunc(FIBONACCI,3);
    exampleVar = operacionesFunc(FIBONACCI,10);
    exampleVar = operacionesFunc(FIBONACCI,14);
    exampleVar = operacionesFunc(FIBONACCI,20);

    exampleVar = operacionesFunc(FACTORIAL,1);
    exampleVar = operacionesFunc(FACTORIAL,5);
    exampleVar = operacionesFunc(FACTORIAL,7);

}

// Ejemplo Switch Case básico
uint16_t resultadoOperacion(uint8_t tipoDeOperacion, uint8_t numeroA, uint8_t numeroB){

	uint16_t resultado = 0;

	switch(tipoDeOperacion){

    case SUMA:
    {
    	resultado = numeroA + numeroB;
    	break;
    }
    case RESTA:
    {
    	resultado = numeroA - numeroB;
    	break;
    }
    case MULTIPLICACION:
    {
    	resultado = numeroA * numeroB;
    	break;
    }
    case DIVISION:
    {
    	resultado = numeroA / numeroB;
    	break;
    }
    default:
    {
    	resultado = 0;
    	break;
    }

	}

	return resultado;
}

// Función ejercicio 1
uint16_t operacionesFunc(uint8_t typeOperation, uint8_t number){

	// Creamos una variable para guardar el resultado
	uint16_t resultado = 0;

	// Averiguar qué tipo de operación se quiere realizar a través de un switch Case
	switch(typeOperation){

    case FACTORIAL:
    {
    	resultado = 1;			// Iniciamos en 1
    	uint8_t contador = 1;

    	while(contador <= number){
    		resultado *= contador;	// Multiplicamos por todos los dígitos anteriores
    		contador++;				// Aumentamos el contador
    	}

    	break;
    }
    case FIBONACCI:
    {
    	// Definimos las variables iniciales
    	uint16_t nMenos2 = 0, nMenos1 = 1, n = 0, contador = 0;
    	while (contador < number) {
    		n = nMenos1 + nMenos2;
    		nMenos2 = nMenos1;
    		nMenos1 = n;
    		contador++;
    		}
    	resultado = n;
    	break;
    	}
    default:
    {
    	resultado = 0;
    	break;
    }
    }

	return resultado;

}

