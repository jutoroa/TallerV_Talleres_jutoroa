/*
 * Este es el código para desarrollar el segundo taller de la asignatura taller 5
 * Este cuenta con una introducción a la definición de variables, al debugger del STM32
 */


#include <stdint.h>

// ****** // Definicipon de variables // ****** //

// Variables de 8 bits
unsigned char siempreUsarCamelCase;			// Definición de una variable
uint8_t 	  diasDeLaSemana 		= 7;	// Definición e inicialización de una variable
char 		  miPrimerCaracter 		= 'J';	// Definición e inicialización de una variable
int8_t		  miSegundoCaracter 	= 'u';	// Definición e inicialización de una variable

// Variables de 16 bits
unsigned short diasAnuales				= 365;	// Es equivalente al uint16_t
short		   miPrimerNumeroNegativo 	= -12;	// Es equivalente al int16_t

// Variables de 32 bits
unsigned long x, y, z;
long 		  a = 1, b = 2, c = 3;
unsigned int i; unsigned long j; long k;

// Otros tipos de variables
char	miPrimerArreglo[5] = "LINUX";	// Definición e inicialización de un arreglo
// MIRAR ERROR uint32_t miSegundoArreglo[3] = {299792458,7969344578,0};
uint64_t miSegundoArreglo[3] = {299792458,7969344578,0};

int main(void)
{
	// Tamaño de variables en diferentes compiladores.
	char edad;	 	//definición de variable
	edad = 22; 		//inicialización de variable

	char sizeChar		 = sizeof(edad); //el tipo de dato que devuelve sizeof es un char
	char sizeShort		 = sizeof(short);
	char sizeInt 		 = sizeof(int);
	char sizeIntLong 	 = sizeof(long int);
	char sizelonglongint = sizeof(long long int);

	// Explicación operadores

	uint16_t varOperadores = 12;

	// Suma
	varOperadores = varOperadores + 1;
	varOperadores += 1;
	varOperadores++;

	// De igual forma para la resta

	// Multiplicacion
	varOperadores = varOperadores * 2;
	varOperadores *= 2;

	// Division
	varOperadores = varOperadores / 2;
	varOperadores /= 2;

	// Modulo
	varOperadores = varOperadores % 2;
	varOperadores %= 2;

    /* Loop forever */
	while(1){

	}
}
