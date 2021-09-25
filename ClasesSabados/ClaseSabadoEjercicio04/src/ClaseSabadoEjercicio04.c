/*
 ============================================================================

Realizar un programa que permita el ingreso de 10 números enteros distintos de cero. >>> Listo

Listar los números positivos de manera creciente y negativos de manera decreciente. (Como máximo 5 for) >>> Listo

Ejemplo:

Listado 1 : 4, 5, 6, 10, 18, 29 >>> Listo
Listado 2 : -1,-5,-9,-12 >>> Listo
Listar solo los números primos. >>> Listo
El mayor de los primos >>> Listo
Los números que se repiten >>> Listo

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


	cargarArray(listaNumeros,tamano,0,"Ingrese un número","Error, vuelva a ingresarlo");

	imprimirArray(listaNumeros,tamano);

	ordenarArray(listaNumeros,tamano);
	ordenarArrayNegativos(listaNumeros,tamano);

	printf("\n La lista de positivos ordenados es:\n");
	if(imprimirArrayCondicional(listaNumeros,tamano,1)==-1)
	{
		printf("\nNo hubo ningún número positivo");
	}

	printf("\n La lista de negativos ordenados es:\n");
	if(imprimirArrayCondicional(listaNumeros,tamano,-1)==-1)
	{
		printf("\nNo hubo ningún número negativo");
	}

	printf("\n La lista de numeros primos es:\n");
	if(imprimirArrayCondicional(listaNumeros,tamano,2)==-1)
	{
		printf("\nNo hubo ningún número primo");
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



