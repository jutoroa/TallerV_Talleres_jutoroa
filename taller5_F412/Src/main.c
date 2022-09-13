
// Taller 5 - Ciclos While y Switch Case

#include <stdint.h>



int main(void){

	// 1.0 Ejemplo básico punteros

	// Definimos una variable, y la inicializamos.
	uint8_t dato = 124;

	// Creamos un puntero con esa dirección de memoria.
	uint8_t *pDato = &dato;

	// Guardamos el valor del dato
	uint8_t valorDato = *pDato;

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

	uint32_t dir = (uint32_t) pVariable;

	uint16_t nuevoValor = 520;

	// Asignemos un valor a esa nueva posición en memoria
	*pVariable = nuevoValor;


}





// Función ejercicio 1
void delay(uint32_t time){

	uint32_t contador = 0;

	while(contador <= time){
		__asm("NOP");
		contador ++;
	}
}
