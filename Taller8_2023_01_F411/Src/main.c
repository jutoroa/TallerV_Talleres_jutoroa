
// Taller 6 - Paso por valor y referencia

#include <stdint.h>

// Creacion de una funcion que duplique el valor de un numero

// 1.0 Paso por valor Básico

void duplicarNumero(uint8_t numero){
	numero *= 2;
}

// 1.1 Paso por referencia

void duplicarNumeroRef(uint8_t *numero){
	*numero = (*numero) * 2;
}

// 1.2 Paso por valor reasignando variables.
uint8_t duplicarNumeroReturn(uint8_t numero){
	return (numero * 2);
}

// 1.3 Arreglos por Referencia

void abonarDeudas(uint16_t misDeudas[], uint8_t cantidadDeudas){

	// Vamos a recorrer cada elemento del arreglo
	for(uint8_t i = 0; i < cantidadDeudas;i++){
		misDeudas[i] /= 2;
	}

}

// ***** // SOLUCION EJERCICIO // ***** //

void stringCaseConverter(uint8_t *string){

	// Creamos un contador
	uint8_t i = 0;

	// Barremos todos los elementos del string(arreglo) hasta encontrar
	// el caracter nulo
	while(string[i] != '\0'){

		// Si el caracter es mayúscula
		if((*(string + i) > 64) && (*(string + i) < 91)){
			// Le aumentamos 32 al código ascii
			*(string + i) = *(string + i) + 32;
		}
		// Si el caracter es minúscula
		else if((*(string + i) > 96) && (*(string + i) < 123)){
			// Le disminuimos 32 al código ascii
			*(string + i) = *(string + i) - 32;
		}
		// Si el caracter no es una letra
		else{
			// Dejamos el mismo caracter
			*(string + i) = *(string + i);
		}

		i++;	// Aumentamos el contador
	}

}

int main(void){

	// Creamos una variable
	uint8_t n = 10;

	// Pasamos por valor la variable (Se genera una copia en la funcion)
	duplicarNumero(n);

	// Creamos una variable
	uint8_t m = 12;

	// Pasamos por referencia la variable (Se modifica directamente)
	duplicarNumeroRef(&m);

	// Reasignación con paso por valor
	n = 36;
	n = duplicarNumeroReturn(n);

	m = 50;

	// 1.3 Los arreglos SIEMPRE se pasan por referencia
	// Recordar que los arreglos son punteros al primer elemento.

	uint16_t deudasMensuales[5] = {15000, 2500, 100, 3600, 0};

	// Dividimos las deudas a la mitad
	abonarDeudas(deudasMensuales,5);

	// 1.4 Ejemplo String básico
	uint8_t miPrimerString[] = "HolAA MuNNdo";

	// 1.5 EJERCICIO:

	// Crear una función llamada stringCaseConverter que no retorne ningún
	// valor, y reciba una string.

	// Esta función deberá cambiar las minúsculas por mayúsculas y viceversa
	// del string original.


	// Llamamos la funcion
	stringCaseConverter(miPrimerString);

	n = 0;
}
