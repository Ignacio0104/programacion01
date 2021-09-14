/*
 ============================================================================
Pedir el ingreso de 10 n�meros enteros entre -1000 y 1000. >>> Listo
Determinar:
Cantidad de positivos y negativos. >>> Listo
Sumatoria de los pares >>> Listo
El mayor de los impares. >> Listo
Listado de los n�meros ingresados. >> Listo
Listado de los n�meros pares. >> Listo
Listado de los n�meros de las posiciones impares. >> Listo
Se deber�n utilizar funciones y vectores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_biblioteca.h"
#define TAM 10


int main(void) {

	setbuf(stdout,NULL);

	int listaNumero[TAM];
	int totalPares;
	int contadorNegativos;
	int contadorPositivos;
	int mayorImpar;


	cargarArrayEnteros(listaNumero,TAM, 1000, -1000,"Ingrese el n�mero" ,"Error, dato ingresado inv�lido");


	totalPares=sumarPares(listaNumero,TAM,&mayorImpar);

	if(totalPares==0)
	{
		printf("No hay n�meros pares\n");
	} else
	{
		printf("La suma de los pares es %d\n", totalPares);
	}

	if(contadorNegativosPositivos (listaNumero,TAM, &contadorNegativos, &contadorPositivos)==-10)
	{
		printf("No hubo ning�n n�mero positivo ni negativo\n");
	} else
	{
		if(contadorNegativosPositivos (listaNumero,TAM, &contadorNegativos, &contadorPositivos)==-1)
		{
			printf("No hubo ning�n n�mero positivo ingresado. La cantidad de negativos fue de %d\n",contadorNegativos);
		} else
		{
			if(contadorNegativosPositivos (listaNumero,TAM, &contadorNegativos, &contadorPositivos)==0)
			{
				printf("No hubo ning�n n�mero negativo ingresado. La cantidad de positivos fue de %d\n",contadorPositivos);
			} else
			{
				printf("Se cargaron %d numeros positivos y %d numeros negativos\n",contadorPositivos,contadorNegativos);
			}
		}
	}

	printf("El mayor de los n�meros impares es el %d\n", mayorImpar);

	printf("La lista original es: \n");
	imprimirArray (listaNumero, TAM);
	imprimirArrayDePares (listaNumero, TAM);

	return EXIT_SUCCESS;


}

