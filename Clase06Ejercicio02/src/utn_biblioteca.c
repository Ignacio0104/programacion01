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

	if(numeros!=NULL && tamano>0 &&variableTexto != NULL && textoError != NULL)
	{
		for(i=0;i<tamano;i++)
		{
			numeros[i]=utn_pedirIntSinIntentos(variableTexto, textoError);
		}
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

void imprimirArray (int *pArray, int len)
{
	int indice;

	if(pArray!=NULL && len>=0)
	{
		for (indice=0;indice<len;indice++)
			{
				printf("%d\n",pArray[indice]);

			}
	}


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

	if(pArray!= NULL &&len>=0)
	{
		for (indice=0;indice<len;indice++)
			{
				if(esPar(pArray[indice])==-1)
				{
					modificarArray(pArray, indice,reemplazo);
				}
			}
	}


}

void modificarArray (int pArray[], int indice, int modificacion)
{

	if(pArray!= NULL)
	{
		pArray[indice]=modificacion;
	}

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





