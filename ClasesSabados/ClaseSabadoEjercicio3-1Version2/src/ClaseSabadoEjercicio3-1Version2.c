/*
 ============================================================================
Pedir el ingreso de 10 números enteros entre -1000 y 1000. Determinar:
Cantidad de positivos y negativos.
Sumatoria de los pares.
El mayor de los impares.
Listado de los números ingresados.
Listado de los números pares.
Listado de los números de las posiciones impares.
Se deberán utilizar funciones y vectores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_biblioteca.h"
#define TAM 10

int determinarParidad (int numero);

void cargarArrayEnteros(int numeros[],int tamano);
void mostrarArrayEnteros (int numeros[], int tamano);
int sumaDePares (int numeros[],int tamano, int* pSuma);

int main(void) {

	setbuf(stdout,NULL);
	int listaNumeros[TAM];
	int sumaPares;

	cargarArrayEnteros(listaNumeros,TAM);
	mostrarArrayEnteros(listaNumeros,TAM);

	if(sumaDePares(listaNumeros,TAM,&sumaPares)==0)
	{
		printf("No hay números pares");
	} else
	{
		printf("La suma de los pares es %d", sumaPares);
	}


	return EXIT_SUCCESS;
}

int determinarParidad (int numero)
{
	int esPar;

	esPar=0;

	if(numero%2==0)
	{
		esPar=1;
	}

	return esPar;
}


void mostrarArrayEnteros (int numeros[], int tamano)
{
	int i;
	for(i=0;i<tamano;i++)
	{
		printf("%d\n",numeros[i]);
	}
}

int sumaDePares (int numeros[],int tamano, int* pSuma)
{
	int acumuladorPares;
	int i;
	int esPar;
	acumuladorPares=0;
	esPar=0;


	for(i=0;i<tamano;i++)
	{
		if(determinarParidad(numeros[i])==1)
		{
			esPar=1;
			acumuladorPares+=numeros[i];
		}
	}

	*pSuma=acumuladorPares;

	return esPar;


}
