/*
 ============================================================================
Crear una función que permita ingresar un numero al usuario y lo retorne.
Crear una función que reciba el radio de un círculo y retorne su área.
Utilizar las funciones de los puntos 1 y 2 para hacer un programa que calcule el área de un círculo cuyo radio
es ingresado por el usuario. Documentar las funciones al estilo Doxygen.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

float pedirNumero();
float calcularArea(float radio);

int main(void) {

	setbuf(stdout,NULL);

	float numeroIngresado;
	float resultadoArea;

	numeroIngresado=pedirNumero();

	resultadoArea=calcularArea(numeroIngresado);

	printf("El área del círculo es %.2f",resultadoArea);


	return EXIT_SUCCESS;
}

float pedirNumero()
{
	float numero;
	printf("Ingrese un número: ");
	scanf("%f",&numero);

	return numero;
}

float calcularArea(float radio)
{
	float area;

	area=3.14*(radio*radio);

	return area;
}
