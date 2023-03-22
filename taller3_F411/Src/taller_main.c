// importar las librerías

#include <stdint.h>
#include <stdbool.h> // Variables booleanas
#include <math.h>		// Operaciones matematicas

#define NOP() __asm("NOP")

#define CONSTANTE 100

bool miPrimerVariableGlobal = true;

// Definicion prototipos de funciones
void miPrimeraFuncion(void);
uint8_t getMaxChar(void);
uint16_t getMaxValue(uint16_t x, uint16_t y, uint16_t z);
#define UNSIGNED 17
#define SIGNED 	 25

uint64_t getMaxBits(uint8_t nBits, uint8_t signo);


#define UNSIGNED 17
#define SIGNED 	 25

uint64_t getMaxBits(uint8_t nBits, uint8_t signo);


int main(void){

	// For básico

	// Tabla del siete

	uint8_t resultado = 0;

	for(uint8_t contador = 0; contador <= 10; contador ++){
		resultado = 7 * contador;
	}

	// Ejemplo taxímetro
	for(uint8_t decenas = 0; decenas<10;decenas++){
		for(uint8_t unidades = 0; unidades<10;unidades++){
			NOP();
		}
	}

	// CONVERSOR DE 8 BITS BINARIOS A DECIMALES

	uint8_t bin, var, dec = 0;
	bin = 0b11101110;

	for(int i=0; i<8;i++){
		var = bin & (1<<i);
		var = var>>i;
		dec = dec + (var*pow(2,i));
	}

	// Conversor de decimal a binario, usando operadores BITWISE
	//y ciclo for



	miPrimeraFuncion();

	uint8_t charMax = getMaxChar();
	(void) charMax;

	uint16_t maxValue = getMaxValue(150, 0b00101101, 0xFEA);
}

void miPrimeraFuncion(void){

	miPrimerVariableGlobal = false;
}

uint8_t getMaxChar(void){

	uint8_t charBits = 8;
	uint8_t maxChar = (2*2*2*2*2*2*2*2)-1;
	maxChar = pow(2,charBits)-1;

	return maxChar;
}

uint16_t getMaxValue(uint16_t x, uint16_t y, uint16_t z){
	if((x>=y) && (x>=z)){
		return x;
	}
	else if((y>=x)&&(y>=z)){
		return y;
	}
	else if((z>=x)&&(z>=y)){
		return z;
	}
	else{
		return 0;
	}
}








