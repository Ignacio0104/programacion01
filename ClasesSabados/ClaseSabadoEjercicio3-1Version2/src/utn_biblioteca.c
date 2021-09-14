/*
 * utn_biblioteca.c
 *
 *  Created on: 7 sept 2021
 *      Author: Nacho
 */

#include "utn_biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
/*
int utn_pedirFloatAUsuario(float* pResultado, float min, float max, char* variableTexto, char* textoError)
{
	float buffer;
	int retorno;
	int salidaScanf;
	if(pResultado != NULL && min<max && variableTexto != NULL && textoError != NULL)
	{

		printf("%s",variableTexto);

		salidaScanf=scanf("%f", &buffer); //si scanf devuelve 1 quiere decir que pudo guardar el dato, o sea que está ok

		//printf("\nLa salida del scanf es : %d\n\n",salidaScanf);
		if (salidaScanf>0 && buffer>=min && buffer<=max)
		{

			retorno = 0; // OK
			*pResultado=buffer;
		}
		else
		{
			retorno=-1;
			printf("%s\n",textoError);
		}

	}
	return retorno;
}

int utn_pedirIntAUsuario(int* pResultado, int min, int max, char* variableTexto, char* textoError)
{
	int buffer;
	int retorno;
	int salidaScanf;
	if(pResultado != NULL && min<max && variableTexto != NULL && textoError != NULL)
	{

		printf("%s",variableTexto);
		salidaScanf=scanf("%d", &buffer);

		//printf("\nLa salida del scanf es : %d\n\n",salidaScanf);
		if (salidaScanf>0 && buffer>=min && buffer<=max)
		{

			retorno = 0; // OK
			*pResultado=buffer;
		}
		else
		{
			retorno=-1;
			printf("%s\n",textoError);
		}

	}
	return retorno;
}


int utn_pedirCharAUsuario(char* pResultado, char min, char max, int reintentos, char* variableTexto, char* textoError)
{
	char buffer;
	int retorno=-1;
	int i;
	if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);
			fflush(stdin);
			scanf("%c", &buffer);

			//printf("\nLa salida del scanf es : %d\n\n",salidaScanf);
			if (buffer>=min && buffer<=max)
			{
				retorno = 0; // OK
				*pResultado=buffer;

			}
			else
			{
				retorno=-1;
				printf("%s\n",textoError);
			}
		}
	}
	return retorno;
}



float utn_dividir (int operador1,int operador2,float*direccionVariable)
{
	float resul;
	int huboError;

	if(operador2!=0)
	{
		resul=(float)operador1/operador2;
		*direccionVariable=resul; //Escribime en la memoria esto
		huboError=0;
	} else
	{
		huboError=1;
	}

	return huboError;
}


void imprimirArrayEdadesVersionDos(int edades[], int len)
{
	int indice;

	for (indice=0;indice<len;indice++)
		{
			printf("%d\n",edades[indice]);

		}

}


void imprimirArray (int *pArray, int len) //(int pArrayEdades []) sintaxis alternativa
{
	int indice;

	for (indice=0;indice<len;indice++)
		{
			printf("%d\n",pArray[indice]);

		}

}

void utn_inicializarArray(int array[], int len, int valorInicial)
{
	int indice;
	for (indice=0;indice<len;indice++)
		{
			array[indice]=indice+50;

		}
}

void utn_inicializarArrayFloat(float array[], int len, int valorInicial)
{
	int indice;
	for (indice=0;indice<len;indice++)
		{
			array[indice]=valorInicial;

		}
}

void modificarArray (int pArray[], int indice, int modificacion)
{
	pArray[indice]=modificacion;
}

void evaluarNegativosPositivos (int *pContadorNegativos, int *pContadorPositivos, int cadena [], int posicion)
{

	if(cadena[posicion]>0)
	{
		*pContadorPositivos+=1;
	} else
	{
		if(cadena[posicion]<0)
		{
			*pContadorNegativos+=1;
		}
	}

}

void sumatoriaDePares (int* pAcumulador,int cadena [], int indice)
{
	if(cadena[indice]%2==0)
	{
		*pAcumulador+=cadena[indice];

	}
}
int mayorDeImpares (int*pMayorDeImpares,int cadena[], int posicion, char* pBandera)
{
	int mayorValorImpar;
	int retorno;
	mayorValorImpar=cadena[posicion];
	retorno=-1;
	if(cadena[posicion]%2!=0)
	{
		if(*pBandera=='s')
		{
			mayorValorImpar=cadena[posicion];
			*pMayorDeImpares=mayorValorImpar;
			*pBandera='n';
		} else
		{
			if(cadena[posicion]>mayorValorImpar)
			{
				mayorValorImpar=cadena[posicion];
				*pMayorDeImpares=mayorValorImpar;
			}
		}
		retorno=0;
	}

	return retorno;

}*/

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



