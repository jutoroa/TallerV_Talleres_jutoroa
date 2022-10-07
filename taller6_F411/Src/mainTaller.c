/*
 * mainTaller.c
 *
 *  Created on: Sep 30, 2022
 *      Author: jutoroa
 */


// Taller 6 - Paso por valor y referencia

#include <stdint.h>


// 1.0 Paso por valor básico

void duplicarNumero(uint8_t numero){
	numero *= 2;
}

//1.1 Paso por referencia

void duplicarNumeroRef(uint8_t *numero){
	*numero = (*numero) * 2;
}

// 1.2 Paso por valor reasignando valores

uint8_t duplicarNumeroReturn(uint8_t numero){
	return(numero * 2);
}

// 1.3 Arreglos por referencia

void abonarDeudas(uint16_t misDeudas[], uint8_t cantidadDeudas){

	// Vamos a recorrer el arreglo

	for(uint8_t i = 0; i < cantidadDeudas; i++){
		misDeudas[i] /= 2;
	}
}

// 1.4 Ejercicio

void stringCaseConverter(uint8_t *string){

	uint8_t i = 0;

	while(string[i] != '\0'){

		// Si el caracter es mayuscula
		if((*(string + i) > 64) && (*(string + i) < 91)){
			// Aumentamos
			*(string + i) = *(string + i) + 32;
		}
		// Si el caracter es minuscula
		else if((*(string + i) > 96) && (*(string + i) < 123)){
			// Aumentamos
			*(string + i) = *(string + i) - 32;
		}
		else{
			// Dejar el mismo caracter
			*(string + i) = *(string + i);
		}

		i++;
	}


}




int main(void){

	uint8_t n = 10;

	// Pasamos por valor
	duplicarNumero(n);

	uint8_t m = 20;

	duplicarNumeroRef(&m);

	//Reasignamos valores

	n = 12;

	n = duplicarNumeroReturn(n);

	n = 50;

	// Ejemplo String básico

	uint8_t miPrimerString[] = "H0llllAh M8Undo";

	n = 0;

	uint16_t deudasMensuales[5] = {15000,2500,200,3600,2};

	abonarDeudas(deudasMensuales, 5);

	// 1.4

	// Crear una funcion llamada stringCaseConverter que no retorne ningun valor
	// y reciba un string.

	// Cambiar letras mayúscula por minúsculas

	stringCaseConverter(&miPrimerString);






}
