
// Taller 6 - Ciclos While y Switch Case

#include <stdint.h>

#include "GPIOxDriver.h"

#define SUMA '+'
#define RESTA '-'
#define MULTIPLICACION '*'
#define DIVISION '/'

// Funcion swtich case
uint16_t resultadoOperacion(uint8_t tipoDeOperacion, uint8_t numeroA,
		uint8_t numeroB);

int main(void){

	uint16_t operacionFinal = 0;
	operacionFinal = resultadoOperacion(SUMA, 7, 10);
	operacionFinal++;


}

uint16_t resultadoOperacion(uint8_t tipoDeOperacion, uint8_t numeroA,
		uint8_t numeroB){
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






