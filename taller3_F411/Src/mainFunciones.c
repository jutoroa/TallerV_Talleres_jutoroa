

// Librería para los tipos de variables
#include <stdint.h>
// Librería para tipos de variables booleanas.
#include <stdbool.h>
// Librería para usar funciones matemáticas
#include <math.h>

#define NOP() __asm("NOP")

#define CONSTANTE 100

// Funcion Main: Funcion imprescindible del lenguaje C.
// Debe ser necesariamente int, y no recibir parámetros
// La funcion Main define el punto de partida de ejecución del programa
// En esta función se ejecuta todo el código que NO sea definicion e inicialización
// Se busca implementar funciones en el main, para hacer más sencillo el código.
// El main no requiere prototipo.
// El main, debe ser la primera función del programa.

bool primeraVariableGlobal = true;
void miPrimeraFuncion(void);

uint8_t getMaxChar(void);

// Explicación IF
uint16_t getMaxValue(uint16_t x, uint16_t y, uint16_t z);

// Primer ejercicio:
/* Crear una función que tenga dos argumentos (parámetros de entrada). El primero, tendrá el valor
 * correspondiente al número de bits de la variable. El segundo, representa si la variable tiene signo
 * o no.
 */

uint64_t getMaxBits(uint8_t nBits, uint8_t signo);

#define UNSIGNED 0
#define SIGNED 	 1

int main(void)
{
	miPrimeraFuncion();

	uint8_t charMax = getMaxChar();
	(void) charMax;

	// Ejemplo básico if
	uint16_t maxValue = getMaxValue(150,0b00101111,0xFEA);

	// Primer ejercicio
	uint64_t maxBits = getMaxBits(16, UNSGINED);
	maxBits = getMaxBits(16, SIGNED);
	maxBits = getMaxBits(13, UNSIGNED);

	// Ejemplo for básico

	// Tabla del siete

	uint8_t resultado = 0;

	for(uint8_t contador = 0; contador < 10; contador ++){
		resultado = 7 * contador;
	}

	// Ejemplo for anidado Taxímetro 3 dígitos

	for(uint8_t centenas = 0; centenas < 10; centenas ++){
		// For para las decenas
		for(uint8_t decenas = 0; decenas < 10; decenas++){
			// For para las unidades
			for(uint8_t unidades = 0; unidades < 10; unidades++){
				// Observar Variables en el debugger
				NOP();
			}
		}
	}

	// Ejercicio de clase

	// Crear un conversor de 8 bits binarios, a decimal	haciendo uso de los ciclos For
	// y de la librería math.h

	uint8_t bin, var, dec = 0;
	bin = 0b11101110;

	for (int i=0; i<8; i++){
		var = bin & (1<<i);
		var = var>>i;
		dec = dec + (var*pow(2, i));
	}

	// Crear un conversor de decimal a binario, haciendo uso de operadores BitWise y ciclo FOR
	for(int i=0; i<8;i++){
		var = (dec%2);
		dec /= 2;
		bin |= var<<i;
	}

	// Crear un conversor de n bits binarios, a decimal	haciendo uso de los ciclos For
	// y de la librería math.h

	for (int i=0; i< (sizeof(x)*8); i++){
		var=x&(1<<i);
		var=var>>i;
		dec=dec+(var*pow(2, i));
	}


}

// Definicion Funciones

// Funciones VOID: Este tipo de funciones se utilizan para inicializar algunas
// configuración del MCU.
// También se pueden emplear para realizar acciones específicas (prender un led, iniciar un contador).
//
void miPrimeraFuncion(void){

	// Manejo de variables booleanas
	primeraVariableGlobal = false;
}

uint8_t getMaxChar(void){

	uint8_t charBits = 8;
	uint8_t maxChar = (2 * 2 * 2 * 2 * 2 * 2 * 2 * 2) - 1;
	maxChar = pow(2, charBits) - 1;

	return maxChar;
}

uint16_t getMaxValue(uint16_t x, uint16_t y, uint16_t z){
	if((x >= y) && (x >= z)){
		return x;
	}
	else if((y >= x) && (y >= z)){
		return y;
	}
	else{
		return z;
	}
}

getMaxBits(uint8_t nBits, uint8_t signo){
	if((nBits == 8)||(nBits == 16)||(nBits == 32)||(nBits==64)){
		if(signo == UNSIGNED){
			return (pow(2,nBits)-1);
		}
		else{
			return (pow(2,nBits)/2)-1;
		}
	}
	else{
		return false;
	}
}
