/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include <stdint.h>

int main(void)
{
    // Operaciones básicas

	uint16_t varOperadores = 12;

	// Operaciones
	varOperadores = varOperadores + 1;
	varOperadores ++;
	varOperadores += 1;

	// Modulo
	varOperadores = varOperadores % 2;
	varOperadores %= 2;

	// SHIFT

	uint8_t testVar = 0b00000101;

	testVar = testVar << 1;
	testVar >>= 1;

	testVar = testVar << 4;

	// Operadores Bitwise

	uint8_t variableA = 0b00111101;
	uint8_t variableB = 0b11111111;

	//OR
	uint8_t resultado = variableA | variableB;

	//AND
	resultado = variableA & variableB;
	//NOT
	resultado = ~resultado;
	//XOR
	resultado = variableA ^ variableB;
	//					 00111101
//111 << 2 = ~00011100 = 11100011
	// Varias operaciones
	resultado = ~(0b111 << 2);

	variableA &= resultado;

	variableA |= (0b11 << 6);


**++~~^^^











































}
