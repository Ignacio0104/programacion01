/*
 * biblioteca_arrays.c
 *
 *  Created on: 28 sept 2021
 *      Author: Nacho
 */
#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cargarArrayEnteros(int numeros[], int reintentos , int tamano,char* variableTexto,char* textoError)
{
	int i;
	int retorno;

	retorno=-1;

	if(numeros!=NULL&&tamano>0&&variableTexto!=NULL&&textoError!=NULL)
	{
		retorno=0;
		for(i=0;i<tamano;i++)
		{
			pedirInt(&numeros[i],reintentos, variableTexto, textoError);
		}
	}

	return retorno;

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


int modificarArray (int pArray[], int indice, int modificacion)
{
	int retorno;

	retorno=-1;

	if(pArray!=NULL)
	{
		retorno=0;
		pArray[indice]=modificacion;
	}

	return retorno;

}


int ordenarArray (int pArray[],int tamano)
{
	int i;
	int flagSwap=0;
	int aux;
	int retorno;
	int limite=tamano;

	retorno=-1;
	if(pArray!=NULL&&tamano>=0)
	{
		retorno=0;
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


		} while(flagSwap==1);

	}
	return retorno;
}



