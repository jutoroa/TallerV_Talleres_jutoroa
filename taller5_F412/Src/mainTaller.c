/*
 * mainTaller.c
 *
 *  Created on: Mar 22, 2023
 *      Author: jutoroa
 */

#include <stdint.h>

int main(void){

	// 1.0 Ejemplo básico punteros
	// Definimos variables
	uint8_t dato = 124;

	// Creamos un puntero con la direccion de memoria de la var
	uint8_t *pDato = &dato;

	// Guardar el valor que esta en esa direccion de memoria
	uint8_t valorDato = *pDato;

	// Casteo básico
	uint16_t casteoDato = (uint16_t) dato;

	// Crear un puntero en una direccion especifica
	uint16_t *punteroDireccion = (uint16_t *) 0x20000001;

	// Cambiar direccion de memoria del puntero

	punteroDireccion = (uint16_t *) 0x20000002;

	// Guardar la direccion de memoria de un puntero
	uint32_t direccionDato = (uint32_t) pDato;

	// Cambiar el valor almacenado en el puntero
	*pDato = 200;

	// Aumentar 8 bits el puntero
	pDato++;

	// 2.0 Ejemplo arreglos

	#define sizeOfArray	4

	uint8_t miPrimerArreglo[sizeOfArray] = {5, 0xAE, 'a', 254};

	// 2.1 Recorrer un arreglo con ciclos

	uint8_t contenido = 0;

	for(uint8_t i=0; i<sizeOfArray; i++){
		contenido = miPrimerArreglo[i];
	}

	for(uint8_t i=0; i<sizeOfArray; i++){
		contenido = *(miPrimerArreglo+i);
	}

	// Cambiar elementos de un arreglo

	miPrimerArreglo[1] = 12;

	*(miPrimerArreglo + 1) = 12;

	// 3.0 Estructuras

	//Definicion

	typedef struct{
		uint8_t elemento1;
		uint16_t elemento2;
		uint8_t arreglo[sizeOfArray];
	}miPrimeraEstructura;

	miPrimeraEstructura estructuraEjemplo = {0};

	// Acceder a los elementos de la estructura
	estructuraEjemplo.elemento1 = 'F';
	estructuraEjemplo.arreglo[2] = 10;

	// Crear un puntero que apunte a la estructura

	miPrimeraEstructura *ptrMiPrimeraEstructura = &estructuraEjemplo;

	ptrMiPrimeraEstructura->elemento1 = 9;
	ptrMiPrimeraEstructura->arreglo[2] = 15;
	*((ptrMiPrimeraEstructura->arreglo)+2) = 15;







}
