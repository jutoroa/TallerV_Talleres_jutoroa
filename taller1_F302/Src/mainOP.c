/*
 * mainOP.c
 *
 *  Created on: Aug 24, 2022
 *      Author: jutoroa
 */

// Este es el código para el manejo de bits.

#include <stdint.h>

int main(void){

	// Clearing bits
	uint8_t clearingVar  = 0b10011010;
	uint8_t clearingMask = 0b00000010;

	uint8_t clearingResults = clearingVar & (~clearingMask);
	// Otra notación más directa
	clearingVar &= (~clearingMask);

	// Utilizando shift
	clearingMask = (0b1 << 1);

	// Finalmente
	clearingVar &= ~(0b1 << 1);

	// Setting bits
	uint8_t settingVar  = 0b10010001;
	uint8_t settingMask = 0b00000100;

	uint8_t settingResults = settingVar | settingMask;

	// Más directo
	settingVar |= settingMask;

	// Aún más directo
	settingVar |= (0b1 << 2);

	// Testing bits

	uint8_t testingVar  = 0b10010001;
	uint8_t testingMask = 0b00000001;

	uint8_t testingResults = testingVar & testingMask;

	// Más directo
	testingVar &= testingMask;

	// Aún más directo
	testingVar &= 0b1;

	// Ejercicio

	uint8_t ejercicioVar = 0b10111010;

	// Poner en los bits [4:7] el número 0xD

	// Primer paso
	// 0xD = 0b1101

	// Segundo paso: Limpiar los bits [4:7] (Poner en 0).
	ejercicioVar &= ~(0b1111 << 4);

	// Tercer paso: Poner el numero
	ejercicioVar |= (0b1101 << 4);

}
