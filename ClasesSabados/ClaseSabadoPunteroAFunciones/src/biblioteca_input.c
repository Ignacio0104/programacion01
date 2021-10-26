/*
 * biblioteca_input.c
 *
 *  Created on: 28 sept 2021
 *      Author: Nacho
 */

#include "biblioteca_input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int esNumerica (char cadena[]);
static int myGets(char pResultado[], int len);
static int esFloat (char cadena[]);
static int esTexto (char cadena[]);
//static int esAlfaNumerica (char cadena[]);

int pedirFloat(float* pResultado, int reintentos, char* variableTexto, char* textoError)
{
	float buffer;
	int retorno=-1;
	int i;
	char bufferCadenaAux[16];

	if(pResultado != NULL && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);

			if (myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				if(esFloat(bufferCadenaAux)==0)
				{
					buffer=atof(bufferCadenaAux);
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
	return retorno;
}


int pedirInt(int* pResultado, int reintentos, char* variableTexto, char* textoError)
{
	int buffer;
	int retorno=-1;
	int i;
	char bufferCadenaAux[16];

	if(pResultado != NULL && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);

			if (myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				if(esNumerica(bufferCadenaAux)==0)
				{
					buffer=atoi(bufferCadenaAux); //atof es para float

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

	return retorno;
}


int pedirFloatIntentosRango(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError)
{
	float buffer;
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
					buffer=atof(bufferCadenaAux);
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

int pedirIntIntentosRango(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError)
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

int pedirTexto(char pResultado[],int lenght, int reintentos, char* variableTexto, char* textoError)
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
				if(esTexto(bufferCadenaAux)==0)
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

int pedirChar(char* pResultado, int reintentos, char* variableTexto, char* textoError)
{
	int retorno=-1;
	char bufferCadenaAux[128];
	char buffer;
	int i;

	if(pResultado != NULL && reintentos >0 && variableTexto != NULL && textoError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);

			if (myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				if(esTexto(bufferCadenaAux)==0)
				{

					buffer=bufferCadenaAux[0];
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
	return retorno;

}

int pedirCharSiNo(char* pResultado, char opcion1, char opcion2, int reintentos, char* variableTexto, char* textoError)
{
	char buffer;
	int retorno=-1;
	int i;
	char bufferCadenaAux[16];

		if(pResultado != NULL && opcion1!=opcion2 && reintentos >=0 && variableTexto != NULL && textoError != NULL)
		{
			for (i=0; i<=reintentos; i++)
			{
				printf("%s",variableTexto);

				if (myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
				{
					if(esTexto(bufferCadenaAux)==0)
					{
						buffer=bufferCadenaAux[0];
						if(buffer==opcion1||buffer==opcion2)
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


int pedirCharAUsuarioIntentosRango(char* pResultado, char min, char max, int reintentos, char* variableTexto, char* textoError)
{
	char buffer;
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
					if(esTexto(bufferCadenaAux)==0)
					{
						buffer=bufferCadenaAux[0];
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



static int esNumerica (char cadena[])
{
	int retorno;
	int i;

	retorno=-1;
	i=0;

	if(cadena!=NULL&&strlen(cadena)>0)
	{
		retorno=0;

		if(cadena[0]=='-')
		{
			i=1;
		}
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

static int esFloat (char cadena[])
{
	int retorno;
	int i;
	int contadorPuntos;

	retorno=-1;
	i=0;
	contadorPuntos=0;

	if(cadena!=NULL&&strlen(cadena)>0)
	{
		retorno=0;
		while(cadena[i]!='\0')
		{
			if(cadena[0]=='-')
			{
				i=1;
			}

			if(cadena[i]<'.'|| cadena[i]>'9'||cadena[i]=='/')
			{
				retorno=-1;
				break;
			}
			if(cadena[i]=='.')
			{
				contadorPuntos++;
			}
			i++;
		}
	}

	if(contadorPuntos>1)
	{
		retorno=-1;
	}

	return retorno;

}

static int esTexto (char cadena[])
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
			if((cadena[i]>='A'&&cadena[i]<='z')||cadena[i]==32||cadena[i]=='.'||cadena[i]==',')
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

/*static int esAlfaNumerica (char cadena[])
{
	int retorno;
	int i;
	char sinLetras;
	char sinNumeros;

	retorno=-1;
	sinLetras='s';
	sinNumeros='s';

	if(cadena!=NULL&&strlen(cadena)>0)
	{
		for(i=0;cadena[i]!='\0';i++)
		{
			if(cadena[i]>='A'&& cadena[i]<='z')
			{
				sinLetras='n';
			} else
			{
				if(cadena[i]>='0'&& cadena[i]<='9')
				sinNumeros='n';
			}
		}
	}

	if(sinNumeros=='n'&&sinLetras=='n')
	{
		retorno=0;
	}

	return retorno;

}
*/

