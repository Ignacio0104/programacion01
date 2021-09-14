/*
 * utn_biblioteca.c
 *
 *  Created on: 7 sept 2021
 *      Author: Nacho
 */

#include "utn_biblioteca.h"
#include <stdio.h>
#include <stdlib.h>



void imprimirArray (int *pArray, int len) //(int pArrayEdades []) sintaxis alternativa
{
	int indice;

	for (indice=0;indice<len;indice++)
		{
			printf("%d\n",pArray[indice]);

		}

}



void cargarArrayEnteros(int numeros[],int tamano, int max, int minimo,char* variableTexto,char* textoError)
{
	int i;

	for(i=0;i<tamano;i++)
	{
		numeros[i]=utn_pedirIntSinIntentos(variableTexto, textoError, max, minimo);
	}
}



int utn_pedirIntSinIntentos(char* variableTexto, char* textoError, int maximo,int minimo)
{
	int numero;
	int salidaScanf;
	if(variableTexto != NULL && textoError != NULL && maximo>minimo)
	{
		printf("%s",variableTexto);
		salidaScanf=scanf("%d", &numero);

		while(salidaScanf!=1||numero>maximo||numero<minimo)
			{
				printf("%s\n",textoError);
				printf("%s",variableTexto);
				fflush(stdin);
				salidaScanf=scanf("%d", &numero);
			}

	}
	return numero;
}

int esPar (int numero)
{
	int retorno;

	if(numero%2==0)
	{
		retorno=1;
	} else
	{
		retorno=-1;
	}

	return retorno;
}


int sumarPares (int numeros[], int tamano, int* pMayorImpar)
{
	int acumulador;
	int i;
	int mayorDeLosImpares;
	char primerImpar='s';

	acumulador=0;

	for(i=0;i<tamano;i++)
	{
		if (esPar(numeros[i])==1)
		{
			acumulador+=numeros[i];
		} else
		{
			if(numeros[i]>mayorDeLosImpares||primerImpar=='s')
			{
				mayorDeLosImpares=numeros[i];
				primerImpar='n';
			}
		}
	}

	*pMayorImpar=mayorDeLosImpares;

	return acumulador;
}


int negativoPositivo (int numero)
{
	int retorno;

		if(numero>0)
		{
			retorno=1;
		} else
		{
			if(numero<0)
			{
				retorno=-1;
			} else
			{
				retorno=0;
			}
		}

	return retorno;
}

int contadorNegativosPositivos (int numeros[], int tamano, int* pContadorNegativos, int* pContadorPositivos)
{
	int contadorNegativos;
	int contadorPositivos;
	int i;
	char banderaNegativos='n';
	char banderaPositivos='n';
	int estado;

	estado=-10;

	contadorNegativos=0;
	contadorPositivos=0;

	for(i=0;i<tamano;i++)
	{
		if (negativoPositivo(numeros[i])==1)
		{
			contadorPositivos+=1;
			banderaPositivos='s';

		} else
		{
			if(negativoPositivo(numeros[i])==-1)
			{
				contadorNegativos+=1;
				banderaNegativos='s';
			}
		}
	}

	*pContadorNegativos=contadorNegativos;
	*pContadorPositivos=contadorPositivos;

	if(banderaNegativos=='s'&&banderaPositivos=='n')
	{
		estado=-1;
	} else
	{
		if(banderaNegativos=='n'&&banderaPositivos=='s')
		{
			estado=0;
		} else
		{
			if(banderaNegativos=='s'&&banderaPositivos=='s')
			{
				estado=10;
			}
		}
	}

	return estado;
}

void imprimirArrayDePares (int *pArray, int len)
{
	int indice;

	for (indice=0;indice<len;indice++)
		{
			if(esPar(pArray[indice])==1)
			{
				printf("El número %d es par \n",pArray[indice]);
			} else
			{
				printf("En la posición %d hay un número impar\n",indice);
			}


		}
}














