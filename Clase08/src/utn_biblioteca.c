/*
 * utn_biblioteca.c
 *
 *  Created on: 7 sept 2021
 *      Author: Nacho
 */

#include "utn_biblioteca.h"
#include <stdio.h>
#include <stdlib.h>

void cargarArrayEnteros(int numeros[],int tamano,char* variableTexto,char* textoError)
{
	int i;

	for(i=0;i<tamano;i++)
	{
		numeros[i]=utn_pedirIntSinIntentos(variableTexto, textoError);
	}
}

int utn_pedirIntSinIntentos(char* variableTexto, char* textoError)
{
	int numero;
	int salidaScanf;
	if(variableTexto != NULL && textoError != NULL)
	{
		printf("%s",variableTexto);
		salidaScanf=scanf("%d", &numero);

		while(salidaScanf!=1)
			{
				printf("%s\n",textoError);
				printf("%s",variableTexto);
				fflush(stdin);
				salidaScanf=scanf("%d", &numero);
			}

	}
	return numero;
}

int imprimirArray (int *pArray, int len)
{
	int retorno=-1;

	int indice;

	if(pArray !=NULL && len>=0)
	{
		for (indice=0;indice<len;indice++)
			{
				imprimirElemento(pArray[indice],indice);

			}
		retorno=0;
	}

	return retorno;

}

void imprimirElemento (int elemento, int indice)
{
	printf("Elemento debug %d posicion %d\n",elemento,indice);
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

void borrarImpares (int *pArray, int len, int reemplazo)
{
	int indice;

	for (indice=0;indice<len;indice++)
		{
			if(esPar(pArray[indice])==-1)
			{
				modificarArray(pArray, indice,reemplazo);
			}
		}
}

void modificarArray (int pArray[], int indice, int modificacion)
{
	pArray[indice]=modificacion;
}

void ordernarArray (int *pArray, int len)
{
	int i;
	int buffer;
	int flagSwap;
	int nuevoLimite;

	if(pArray!= NULL && len>=0)
	{
		nuevoLimite=len-1;
		do
		{
			flagSwap=0;
			for (i=0;i<nuevoLimite;i++)
			{
				if(pArray[i]<pArray[i+1])
				{
					flagSwap=1;
					buffer=pArray[i];
					pArray[i]=pArray[i+1];
					pArray[i+1]=buffer;
				}
				nuevoLimite--;
			}
		}while (flagSwap==0);

	}

}


int ordenarArrayContandoVueltas (int pArray[],int tamano)
{
	int i;
	int flagSwap=0;
	int aux;
	int contadorVueltas=0;
	int retorno;
	int limite=tamano;

	if(pArray!=NULL&&tamano>=0)
	{
		do
		{
			flagSwap=0;
			limite=limite-1;
			for(i=0;i<limite;i++)
			{
				if(pArray[i]<pArray[i+1])
				{
					flagSwap=1;
					//Swap
					aux=pArray[i];
					pArray[i]=pArray[i+1];
					pArray[i+1]=aux;
				}
			}

			contadorVueltas++;

		} while(flagSwap==1);
		retorno=contadorVueltas;
	}
	return retorno;
}







