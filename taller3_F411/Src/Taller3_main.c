/*
 * Taller3_main.c
 *
 *  Created on: Sep 2, 2022
 *      Author: jutoroa
 */

// Libreria variables
#include <stdint.h>

// Libreria para tipos de variables booleanas
#include <stdbool.h>

// Libreria para operaciones matematicas
#include <math.h>

#define NOP() __asm("NOP")


void miPrimeraFuncion(void);


int main(void){

	miPrimeraFuncion();

	while(1){

		miPrimeraFuncion();

	}

}

void miPrimeraFuncion(void){

	// Manejo de varibales booleanas

	uint8_t miPrimeraBandera = true;
	uint8_t miSegundaBandera = false;

	uint8_t XOR = miPrimeraBandera ^ miSegundaBandera;
	uint8_t OR = miPrimeraBandera || miSegundaBandera;
	uint8_t AND = miPrimeraBandera && miSegundaBandera;

	XOR ^= 1;
	XOR ^= 1;
}


