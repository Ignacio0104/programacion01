/*
 ============================================================================

Realizar un programa que permita el ingreso de 10 n�meros enteros distintos de cero. >>> Listo

Listar los n�meros positivos de manera creciente y negativos de manera decreciente. (Como m�ximo 5 for) >>> Listo

Ejemplo:

Listado 1 : 4, 5, 6, 10, 18, 29 >>> Listo
Listado 2 : -1,-5,-9,-12 >>> Listo
Listar solo los n�meros primos. >>> Listo
El mayor de los primos >>> Listo
Los n�meros que se repiten >>> Listo

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_Array04.h"
#define tamano 10


int main(void) {

	setbuf(stdout,NULL);
	int listaNumeros[tamano];
	int primoMasGrande;


	cargarArray(listaNumeros,tamano,0,"Ingrese un n�mero","Error, vuelva a ingresarlo");

	imprimirArray(listaNumeros,tamano);

	ordenarArray(listaNumeros,tamano);
	ordenarArrayNegativos(listaNumeros,tamano);

	printf("\n La lista de positivos ordenados es:\n");
	if(imprimirArrayCondicional(listaNumeros,tamano,1)==-1)
	{
		printf("\nNo hubo ning�n n�mero positivo");
	}

	printf("\n La lista de negativos ordenados es:\n");
	if(imprimirArrayCondicional(listaNumeros,tamano,-1)==-1)
	{
		printf("\nNo hubo ning�n n�mero negativo");
	}

	printf("\n La lista de numeros primos es:\n");
	if(imprimirArrayCondicional(listaNumeros,tamano,2)==-1)
	{
		printf("\nNo hubo ning�n n�mero primo");
	}


	if(mayorDeLosPrimos(listaNumeros, tamano, &primoMasGrande)==-1)
	{
		printf("\nNo hubo numeros primos");
	} else
	{
		if(mayorDeLosPrimos (listaNumeros, tamano, &primoMasGrande)==0)
		{
			printf("\n El Mayor de los primos es %d\n",primoMasGrande);
		}
	}

	evaluarRepetidos (listaNumeros, tamano);

	return EXIT_SUCCESS;
}



