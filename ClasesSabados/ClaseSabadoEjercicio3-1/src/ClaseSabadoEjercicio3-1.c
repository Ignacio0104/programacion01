/*
 ============================================================================
Pedir el ingreso de 10 n�meros enteros entre -1000 y 1000. Determinar:
Cantidad de positivos y negativos.
Sumatoria de los pares.
El mayor de los impares.
Listado de los n�meros ingresados.
Listado de los n�meros pares.
Listado de los n�meros de las posiciones impares.
Se deber�n utilizar funciones y vectores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_biblioteca.h"

int main(void) {

	setbuf(stdout,NULL);

	int cadenaNumeros [10];
	int i;
	int numeroIngresado;
	int contadorNegativos;
	int contadorPositivos;
	int indice;
	int acumuladorDePares;
	char primerIngreso;
	int mayorImpares;

	contadorNegativos=0;
	contadorPositivos=0;
	acumuladorDePares=0;
	primerIngreso='s';

	for (i=0;i<10;i++)
	{
		utn_pedirIntAUsuario(&numeroIngresado,-1000, 1000, "Ingrese un n�mero ", "Error, n�mero ingresado inv�lido");
		modificarArray(cadenaNumeros,i,numeroIngresado);

	}

	for(indice=0;indice<10;indice++)
	{
		evaluarNegativosPositivos (&contadorNegativos, &contadorPositivos, cadenaNumeros,indice);
		sumatoriaDePares (&acumuladorDePares, cadenaNumeros, indice);
		mayorDeImpares (&mayorImpares,cadenaNumeros, indice, &primerIngreso);
	}

	imprimirArray (cadenaNumeros, 10);

	printf("%d positivos y %d negativos",contadorPositivos,contadorNegativos);
	printf("\nLa sumatoria de los pares es %d",acumuladorDePares);

	if(mayorDeImpares(&mayorImpares,cadenaNumeros, indice, &primerIngreso)==-1)
	{
		printf("\nNo se ingresaron n�mero impares");
	} else
	{
		printf("\nEl mayor de los n�meros impares es %d",mayorImpares);
	}

	return EXIT_SUCCESS;


}
