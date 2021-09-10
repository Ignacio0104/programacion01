/*
 * utn_biblioteca.c
 *
 *  Created on: 7 sept 2021
 *      Author: Nacho
 */

#include "utn_biblioteca.h"
#include <stdio.h>
#include <stdlib.h>

int utn_pedirFloatAUsuario(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError)
{
	float buffer;
	int retorno=-1;
	int i;
	int salidaScanf;
	if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);

			salidaScanf=scanf("%f", &buffer); //si scanf devuelve 1 quiere decir que pudo guardar el dato, o sea que está ok

			//printf("\nLa salida del scanf es : %d\n\n",salidaScanf);
			if (salidaScanf>0 && buffer>=min && buffer<=max)
			{

				retorno = 0; // OK
				*pResultado=buffer;
				break;
			}
			else
			{
				retorno=-2;
				printf("%s\n",textoError);
			}
		}
	}
	return retorno;
}

int utn_pedirIntAUsuario(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError)
{
	int buffer;
	int retorno=-1;
	int i;
	int salidaScanf;
	if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);
			salidaScanf=scanf("%d", &buffer);

			//printf("\nLa salida del scanf es : %d\n\n",salidaScanf);
			if (salidaScanf>0 && buffer>=min && buffer<=max)
			{

				retorno = 0; // OK
				*pResultado=buffer;
				break;
			}
			else
			{
				retorno=-2;
				printf("%s\n",textoError);
			}
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
				break;
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
