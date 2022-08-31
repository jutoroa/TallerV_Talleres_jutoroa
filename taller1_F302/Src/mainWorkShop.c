/*
 * mainWorkShop.c
 *
 *  Created on: Aug 25, 2022
 *      Author: jutoroa
 */

#include <stdint.h>

// Definición de variables

// Variables de 8 bits

unsigned char siempreUsarCamelCase	= 7;		// Definicion de una variable
uint8_t diasDeLaSemana = 7;						// Definicion e inicializacion de una variable


char miPrimerCaracter = 'j';					// Definicion caracter
int8_t miPrimerNumeroNegativo = -12;			// Definicion numero negativo

// Variables de 16 bits

unsigned short diasAnuales = 365;				// Definicion 16 bit
uint16_t diasAnuales2	   = 370;

// Variables de 32 bits

unsigned int x, y, z;
int		a = 1, b = 2, c = 3;
unsigned int i; int j; long k;

// Otros tipos de variables

char miPrimerArreglo[5] = "LINUX";
uint64_t miSegundoArreglo[3] = {299792458,7970190183,0};

int main(void){

	// Tamaño de variables en diferentes compiladores
	char edad = 22;

	char sizeChar 		= sizeof(edad);
	char sizeShort 		= sizeof(short);
	char sizeInt		= sizeof(int);
	char sizeIntLong 	= sizeof(long int);
	char sizelonglongint = sizeof(long long int);

}










