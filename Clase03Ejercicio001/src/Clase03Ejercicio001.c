/*
 ============================================================================
Crear una funci�n que permita ingresar un numero al usuario y lo retorne.
Crear una funci�n que reciba el radio de un c�rculo y retorne su �rea.
Utilizar las funciones de los puntos 1 y 2 para hacer un programa que calcule el �rea de un c�rculo cuyo radio
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

	printf("El �rea del c�rculo es %.2f",resultadoArea);


	return EXIT_SUCCESS;
}

float pedirNumero()
{
	float numero;
	printf("Ingrese un n�mero: ");
	scanf("%f",&numero);

	return numero;
}

float calcularArea(float radio)
{
	float area;

	area=3.14*(radio*radio);

	return area;
}
