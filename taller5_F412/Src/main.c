
// Taller 7 - Punteros

#include <stdint.h>


int main(void){

	// 1.0 Ejemplo básico punteros

	// Definimos una variable, y la inicializamos.
	uint8_t dato = 124;

	// Creamos un puntero con esa dirección de memoria.
	uint8_t *pDato = &dato;

	// Guardamos el valor del dato
	uint8_t valorDato = *pDato;

	// Explicar CASTEO
	uint16_t casteoDato = (uint16_t) dato;

	// Creación de un puntero a una dirección específica.
	// Explicar Memory Mapping | DataSheet
	uint16_t *punteroDireccion = (uint16_t*) 0x20000001;

	// Cambiar dirección de un puntero
	punteroDireccion = (uint16_t*) 0x20000005;

	// Guardar el valor de la dirección de memoria.
	uint32_t direccionDato = (uint32_t) pDato;

	// Cambiar el valor en memoria asociado al puntero
	*pDato = 200;

	// Cambiar la dirreción a la que apunta el puntero

	pDato++;		// Aumentamos en 1

	// Almacenamos el valor que está en esta nueva dirección.
	uint8_t nuevoDato = *pDato;

	// Definimos una varibale de 16 bits
	uint16_t variable = 12;

	// Creamos un puntero que apunte a esa dirección de memoria
	uint16_t *pVariable = &variable;

	// Desplazemos el puntero 16 bits
	pVariable++;

	// Guardamos la dirección en una variable
	uint32_t dir = (uint32_t) pVariable;

	uint16_t nuevoValor = 520;

	// Asignemos un valor a esa nueva posición en memoria
	*pVariable = nuevoValor;


	// 2.0 Ejemplo básico arreglo

	#define sizeOfArray  4

	uint8_t miPrimerArreglo[sizeOfArray] = {5, 0xAE, 'a', 254};

	// 2.1 Recorrer un arreglo con ciclos

	uint8_t contenido = 0;

	for(uint8_t i = 0; i < sizeOfArray; i++){
		contenido = miPrimerArreglo[i];
	}

	// 2.2 Recorrer un arreglo con punteros

	for(uint8_t i = 0; i < sizeOfArray; i++){
		contenido = * (miPrimerArreglo + i);
	}

	/* Un arreglo es un puntero al primer elemento del arreglo

	 miPrimerArreglo[0] es igual a *miPrimerArreglo
     miPrimerArreglo[1] es igual a *(miPrimerArreglo + 1).

	*/

	// 2.3 Cambiar valor de un elemento de un arreglo

	miPrimerArreglo[1]	   = 12;

	*(miPrimerArreglo + 1) = 9;		// Ambas notaciones son iguales

	// Consultar la dirección de un arreglo
	uint32_t dir2 = (uint32_t) miPrimerArreglo;

	// 3.0 Estructuras

	// Definición General:

    typedef struct
    {
        uint8_t 	Elemento1;
        uint16_t 	Elemento2;
        uint32_t 	Elemento3;
        uint64_t 	Elemento4;
        uint8_t		arreglo[sizeOfArray];
    } miPrimeraEstructura_t;

    // 3.1 Creamos una variable con el tipo de dato de la estructura

    miPrimeraEstructura_t 	estructuraEjemplo = {0};

    // Accedemos a los elementos de la estructura

    estructuraEjemplo.Elemento3 = 'F';
    estructuraEjemplo.arreglo[0]   = 10;

    // 3.2 Creación de un puntero a una estructura

    // Creamos un puntero que apunta a ese tipo de estructura
    miPrimeraEstructura_t *ptrMiPrimeraEstructura = &estructuraEjemplo;

    ptrMiPrimeraEstructura -> Elemento1 	= 9;
    ptrMiPrimeraEstructura -> arreglo[2] 	= 5;
    *((ptrMiPrimeraEstructura -> arreglo)+2) 	= 36;

    (void) casteoDato;
    (void) dir;
    (void) dir2;
    (void) direccionDato;
    (void) nuevoDato;
    (void) punteroDireccion;
    (void) valorDato;
    (void) contenido;

}
