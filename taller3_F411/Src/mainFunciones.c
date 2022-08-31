

// Librería para los tipos de variables
#include <stdint.h>
// Librería para tipos de variables booleanas.
#include <stdbool.h>
// Librería para usar funciones matemáticas
#include <math.h>

#define NOP() __asm("NOP")

#define CONSTANTE 100

// Funcion Main: Funcion imprescindible del lenguaje C.
// Debe ser necesariamente int, y no recibir parámetros
// La funcion Main define el punto de partida de ejecución del programa
// En esta función se ejecuta todo el código que NO sea definicion e inicialización
// Se busca implementar funciones en el main, para hacer más sencillo el código.
// El main no requiere prototipo.
// El main, debe ser la primera función del programa.

void miPrimeraFuncion(void);
uint8_t getMaxChar(void);

int main(void)
{
	miPrimeraFuncion();

	uint8_t charMax = getMaxChar();
	(void) charMax;

	while(1){

		// Ejemplo básico if

		uint8_t estatura = 0;
		bool puedeIngresar;

		if(estatura >= 150){
			puedeIngresar = true;
		}
		else{
			puedeIngresar = false;
		}

		// Ejemplo else if anidado

		uint32_t dineroEnLaCuenta = 400000;
		bool tieneCarro = true;

		if(dineroEnLaCuenta < 1000000){
			if(tieneCarro == false){
				char hermosura[] = "FEO";
			}
			else{
				char hermosura[] = "Feo, pero le acepto la salida";
				int n = sizeof(hermosura);
				int a = 1+2;
			}
		}
		else if(dineroEnLaCuenta >= 1000000 && dineroEnLaCuenta < 5000000){
			if(tieneCarro == false){
				char hermosura[] = "Breve";
			}
			else{
				char hermosura[] = "Le roto el instagram";
			}
		}
		else if(dineroEnLaCuenta >= 5000000 && dineroEnLaCuenta < 10000000){
			char hermosura[] = "Bonito";
		}
		else{
			char hermosura[] = "Me caso";
		}



		// Ejemplo for básico

		// Tabla del siete

		uint8_t resultado = 0;

		for(uint8_t contador = 0; contador < 10; contador ++){
			resultado = 7 * contador;
		}

		// Ejemplo for anidado Cronómetro

		for(uint8_t horas = 0; horas < 24; horas ++){
			// For para los minutos
			for(uint8_t minutos = 0; minutos < 60; minutos++){
				// For para los segundos
				for(uint8_t segundos = 0; segundos < 60; segundos++){
					// Observar Variables en el debugger
					NOP();
				}
			}
		}

		// Ejercicio de clase

		// Crear un conversor de 8 bits binarios, a decimal	haciendo uso de los ciclos For
		// y de la librería math.h

		uint8_t x, var, dec;
		x = 0b11101110;

		for (int i=0; i<8; i++){
			var=x&(1<<i);
			var=var>>i;
			dec=dec+(var*pow(2, i));
		}

		// Crear un conversor de n bits binarios, a decimal	haciendo uso de los ciclos For
		// y de la librería math.h

		for (int i=0; i< (sizeof(x)*8); i++){
			var=x&(1<<i);
			var=var>>i;
			dec=dec+(var*pow(2, i));
		}

	}
}

// Definicion Funciones

// Funciones VOID: Este tipo de funciones se utilizan para inicializar algunas
// configuración del MCU.
// También se pueden emplear para realizar acciones específicas (prender un led, iniciar un contador).
//
void miPrimeraFuncion(void){

	// Manejo de variables booleanas

	uint8_t miPrimeraBandera = true;
	uint8_t miSegundaBandera = false;

	uint8_t XOR = miPrimeraBandera ^ miSegundaBandera;
	uint8_t OR  = miPrimeraBandera || miSegundaBandera;
	uint8_t AND = miPrimeraBandera && miSegundaBandera;

	XOR ^= 1;
	XOR ^= 1;
}

uint8_t getMaxChar(void){

	uint8_t charBits = 8;

	uint8_t maxChar = (2 * 2 * 2 * 2 * 2 * 2 * 2 * 2) - 1;

	return maxChar;

}

