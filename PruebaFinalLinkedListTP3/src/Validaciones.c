/*
 * Validaciones.c
 *
 *  Created on: 7 nov 2021
 *      Author: Nacho
 */
#include "Validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int myGets(char pResultado[], int len);


int pedirNombre(char pResultado[],int lenght, int reintentos, char* variableTexto, char* textoError)
{
	int retorno=-1;
	char bufferCadenaAux[128];
	int i;

	if(pResultado != NULL && reintentos >0 && lenght>0 && variableTexto != NULL && textoError != NULL)
	{

		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);

			if (myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				if(esNombre(bufferCadenaAux)==0)
				{

					retorno = 0; // OK
					strncpy (pResultado,bufferCadenaAux,lenght);
					break;
					}else
					{
						printf("%s\n",textoError);
					}

				} else
				{
					printf("%s\n",textoError);
				}

			}

	}
	return retorno;

}

int esNombre(char cadena[])
{
	int retorno;
	int i;

	retorno=-1;
	i=0;

	if(cadena!=NULL&&strlen(cadena)>0)
	{
		retorno=0;
		while(cadena[i]!='\0')
		{
			if((cadena[i]>='A'&&cadena[i]<='z')||cadena[i]=='-'||cadena[i]==32)
			{
				if(cadena[i]>'Z'&&cadena[i]<'a')
				{
					retorno=-1;
					break;
				}
				i++;

			} else
			{
				retorno=-1;
				break;
			}

		}
	}

	return retorno;

}
static int myGets(char pResultado[], int len)
{
	int retorno=-1;
	int indexFinal;
	fflush(stdin);

	if(fgets(pResultado,len,stdin)!=NULL)
	{
		// borro el \n del final
		indexFinal = strlen(pResultado)-1;
		if(pResultado[indexFinal] == '\n')
		{
			pResultado[indexFinal] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}


