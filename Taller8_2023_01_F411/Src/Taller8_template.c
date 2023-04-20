/*
 * Taller8_template.c
 *
 *  Created on: 28/03/2023
 *      Author: alvelezp - jutoroa
 */

// Taller 8 - Paso por valor y paso por referencia

#include <stdint.h>

// Creacion de una funcion que duplique el valor de un numero

// 1.0 Paso por valor Básico

void duplicarNumero(uint8_t numero){
	numero *= 2;
}

// 1.1 Paso por referencia

void duplicarNumeroRef(uint8_t *numero){
	*numero = (*numero)*2;
}

// 1.2 Paso por valor reasignando variables.

uint8_t duplicarNumeroReturn(uint8_t numero){
	return(numero*2);
}

// 1.3 Arreglos por Referencia

void abonarDeudas(uint16_t misDeudas[], uint8_t cantidadDeudas){

	// Vamos a recorrer el arreglo
	for(uint8_t i = 0; i<cantidadDeudas;i++){
		misDeudas[i] /= 2;
	}
}

// ***** // SOLUCION EJERCICIO // ***** //

char string[]="hola";

void stringCaseConverter(uint8_t *string){

	// Crear un contador
	uint8_t i = 0;

	// Preguntar si llegué al final del arreglo
	while(string[i] != '\0'){

		// Preguntar si es mayuscula
		if((*(string+i) > 64)&&(*(string+i) < 91)){
			//AUMENTAR 32
			*(string+i) = *(string+i)+32;
		}
		else if((*(string+i) > 96)&&(*(string+i) < 123)){
			//DISMINUIR 32
			*(string+i) = *(string+i)-32;
		}
		// si es otra letra
		else{
			*(string+i) = *(string+i);
		}



		i++;
	}






}

int main(void){

	// Crear una variable
	uint8_t n = 10;

	// Pasar por valor
	duplicarNumero(n);

	// Pasar por referencia
	duplicarNumeroRef(&n);

	// Reasignación paso por valor
	n = duplicarNumeroReturn(n);

	// Pasar por referencia el arreglo
	uint16_t deudasMensuales[5]={15000,25,1000,0,600};

	abonarDeudas(deudasMensuales,5);



	/* 1.5 EJERCICIO:

	Crear una función llamada stringCaseConverter que no retorne ningún
	valor, y reciba una string.

	Esta función deberá cambiar las minúsculas por mayúsculas y viceversa
	del string original. */

	uint8_t miPrimerString[] = "HoLLa MuuuNDO";

	stringCaseConverter(miPrimerString);

	n = 0;

	'a';
	'b';


}
