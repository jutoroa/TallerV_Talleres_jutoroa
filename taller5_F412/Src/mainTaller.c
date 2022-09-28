/*
 * mainTaller.c
 *
 *  Created on: Sep 16, 2022
 *      Author: jutoroa
 */


#include <stdint.h>

int main(void){

	// 1.0 Ejemplo punteros

	uint8_t dato = 124;

	// Creacion de un puntero
	uint8_t *pDato;

	// Asignando el valor en memoria al puntero
	pDato = &dato;

	// Crear una variable para almacenar el valor de memoria
	uint32_t direccionDato = (uint32_t) pDato;

	// Acceder al valor a través del puntero
	*pDato = 200;

	// Pasar a la siguiente direccion de memoria
	pDato++;

	uint8_t nuevoDato = *pDato;

	// Crear variable de 16 bits

	uint16_t variable = 12;

	// Creamos un puntero para variable
	uint16_t *pVariable;

	// Asignar direccion de memoria
	pVariable = &variable;

	// Direccion de memoria
	uint32_t dir = (uint32_t) pVariable;

	pVariable++;

	// Guardar un nuevo valor a traves del puntero
	*pVariable = 12;

	// 2.1 Creacion arreglo

	#define sizeOfArray 4

	uint8_t miPrimerArreglo[sizeOfArray] = {5, 0xA, 'a', 254};

	// 2.1 Recorrer los arreglos con ciclos

	for(uint8_t i = 0; i < sizeOfArray; i++){
		uint8_t contenido = miPrimerArreglo[i];
	}

	// 2.2 Recorrer arreglos con punteros
	for(uint8_t i = 0; i < sizeOfArray; i++){
		uint8_t contenido = * (miPrimerArreglo + i);
	}


	// 3.0 Estructuras

	// Definicion general

	typedef struct{
		uint8_t elemento1;
		uint16_t elemento2;
		uint32_t elemento3;
		uint8_t arreglo[sizeOfArray];
	}miPrimeraEstructura_t;

	// Inicializando la estructura
	miPrimeraEstructura_t estructuraEjemplo = {0};

	// Asignamos valores
	estructuraEjemplo.elemento1 = 'F';
	estructuraEjemplo.arreglo[0] = 10;

	// Como acceder a las estructuras con punteros

	miPrimeraEstructura_t *ptrMiPrimeraEstructura;

	ptrMiPrimeraEstructura -> elemento3 = 9;
	ptrMiPrimeraEstructura -> arreglo[0] = 3;










}
