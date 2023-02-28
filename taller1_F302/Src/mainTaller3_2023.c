/*
 * mainOP.c
 *
 *  Created on: Aug 24, 2022
 *      Author: jutoroa
 */

// Este es el código para el manejo de bits.

#include <stdint.h>

int main(void){

	// Operaciones básicas

	uint16_t varOperadores = 12;

	// Operaciones (+,-,/,%)
	varOperadores = varOperadores + 1;
	varOperadores += 1;
	varOperadores++;

	// Modulo
	varOperadores = varOperadores % 2;
	varOperadores %= 2;

	// SHIFT

	uint8_t testVar = 0b00000101;

	testVar = testVar << 1;
	testVar >>= 1;

	testVar = testVar << 4;

	// Operadores Bitwise (&,|,^,~)

	uint8_t variableA = 0b00111101;
	uint8_t variableB = 0b11111111;

	// OR
	uint8_t resultado = variableA | variableB;
	// AND
	resultado = variableA & variableB;
	// NOT
	resultado = ~variableA;
	// XOR
	resultado = variableA ^ variableB;

	// Varias operaciones
	resultado = ~(0b111 << 2);

	variableA &= resultado;

	variableA |= (0b11 << 6);

	// Ejercicio

	uint8_t ejercicioVar = 0b10111010;

	// Poner en los bits [4:7] el número 0xD

	// Primer paso
	// 0xD = 0b1101

	// Segundo paso: Limpiar los bits [4:7] (Poner en 0).
	ejercicioVar &= ~(0b1111 << 4);

	// Tercer paso: Poner el numero
	ejercicioVar |= (0b1101 << 4);

	// GUESS WHO

	/*
	A partir de las imágenes crear dos variables de 16 bits en donde
	los 0 representen las caras masculinas, y los 1 las caras femeninas

	A partir de operaciones bitwise crear una variable que contenga la
	información de:

	A) Las posiciones de las caras masculinas
	B) Las posiciones de las caras femeninas que usen lente
	C) Las posiciones de las caras masculinas que tengan bigote
	D) Las posiciones de los que tengan sombrero

	Finalmente, cree una variable de 32 bits, que contenga las dos variables
	anteriores. En donde los 16 bits más significativos, corresponden a los datos
	del grupo 1, y los 16 bits menos significativos, corresponden a los datos del
	grupo 2.
*/

}
