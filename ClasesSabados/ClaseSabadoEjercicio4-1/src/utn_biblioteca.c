/*
 * utn_biblioteca.c
 *
 *  Created on: 7 sept 2021
 *      Author: Nacho
 */

#include "utn_biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int esNumerica (char cadena[]);
static int myGets(char pResultado[], int len);

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
	char bufferCadenaAux[16];

	if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);

			if (myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				if(esNumerica(bufferCadenaAux)==0)
				{
					buffer=atoi(bufferCadenaAux); //atof es para float
					if(buffer>=min&&buffer<=max)
					{
						retorno = 0; // OK
						*pResultado=buffer;
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
	}
	return retorno;
}

int utn_pedirTextoAUsuario(char pResultado[],int lenght, char* variableTexto, char* textoError)
{
	int retorno=-1;

	if(pResultado != NULL && variableTexto != NULL && textoError != NULL)
	{

			printf("%s",variableTexto);

			if(myGets(pResultado,lenght)==0)
			{
				retorno = 0;
			} 	else
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



static int esNumerica (char cadena[])
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
			if(cadena[i]<'0'|| cadena[i]>'9')
			{
				retorno=-1;
				break;
			}
			i++;
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




/*Todo esto esta en MYGETS

	 * fflush(stdin);

	//salidaScanf=scanf("%s", &pResultado); //Scanf escribre hasta el primer espacia que encuentre. Buenas Tardes, guarda solo Buenas
										// El Scanf no puede saber el tamano de la cadena.

	//printf("\nLa salida del scanf es : %d\n\n",salidaScanf);
	//if (salidaScanf>0)

	if(fgets(pResultado,lenght,stdin)!=NULL) //Recibe cadena, limite de la cadena y puntero (Se le pasa la terminal para que lea de ahí)
	{                                        // Solo lee cadenas.
											//El enter lo toma como un caracter mas. Importante para validar
		indexFinal = strlen(pResultado)-1;
		if(pResultado[indexFinal]=='\n')
		{
			pResultado[indexFinal]='\0'; //Aca se cambia el enter por un \0
		}
		retorno = 0;
		break;
	}
	else
	{
		retorno=-1;
		printf("%s\n",textoError);
	}
}*/

