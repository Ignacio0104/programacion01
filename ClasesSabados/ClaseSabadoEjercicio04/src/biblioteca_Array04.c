/*
 * biblioteca_Array04.c
 *
 *  Created on: 20 sept 2021
 *      Author: Nacho
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_Array04.h"

static int esPositivo (int numero);
static int esPrimo (int numero);

int cargarArray (int cadena[], int lenght, int exclusion,char* mensajeUsuario, char*mensajeError)
{
	int retorno;
	int i;

	retorno=-1;

	if(cadena!=NULL&&lenght>0&&mensajeUsuario!=NULL&&mensajeError!=NULL)
	{
		retorno=0;
		for(i=0;i<lenght;i++)
			{
				cadena[i]=pedirNumeroExcluyente(exclusion, mensajeUsuario, mensajeError);
			}
	}

	return retorno;
}

int pedirNumeroExcluyente(int exclusion, char* mensajeUsuario, char*mensajeError)
{
	int salidaScanf;
	int numero;

	if(mensajeUsuario!=NULL&&mensajeError!=NULL)
	{
		printf("%s",mensajeUsuario);
		fflush(stdin);
		salidaScanf=scanf("%d",&numero);

		while(salidaScanf==0||numero==exclusion)
		{
			printf("%s",mensajeError);
			fflush(stdin);
			salidaScanf=scanf("%d",&numero);
		}

	}
	return numero;
}

void imprimirArray (int cadena[], int lenght)
{
	int i;

	for(i=0;i<lenght;i++)
	{
		printf("Posición %d: Numero %d\n",i,cadena[i]);
	}
}

static int esPositivo (int numero)
{
	int esPositivo;

	esPositivo=-1;

	if(numero>0)
	{
		esPositivo=0;
	}

	return esPositivo;
}

int ordenarArray (int cadena[], int lenght)
{
	int retorno;
	int i;
	int flagSwap=0;
	int buffer;
	int nuevoLimite;

	retorno=-1;


	if(cadena!=NULL&&lenght>0)
	{
		nuevoLimite=lenght-1;
		retorno=0;
		flagSwap=1;
		while(flagSwap==1)
		{
			flagSwap=0;
			for (i=0;i<nuevoLimite;i++)
			{
				if(cadena[i]>cadena[i+1])
				{
					flagSwap=1;
					buffer=cadena[i];
					cadena[i]=cadena[i+1];
					cadena[i+1]=buffer;
				}
			}

			nuevoLimite--;
		}

	}

	return retorno;
}

int ordenarArrayNegativos (int cadena[], int lenght)
{
	int retorno;
	int i;
	int flagSwap=0;
	int buffer;
	int nuevoLimite;

	retorno=-1;

	if(cadena!=NULL&&lenght>0)
	{
		nuevoLimite=lenght-1;
		retorno=0;
		flagSwap=1;
		while(flagSwap==1)
		{
			flagSwap=0;
			for (i=0;i<nuevoLimite;i++)
			{
				if(cadena[i]>0)
				{
					break;

				} else
				{
					if(cadena[i]<cadena[i+1])
					{
						flagSwap=1;
						buffer=cadena[i];
						cadena[i]=cadena[i+1];
						cadena[i+1]=buffer;
					}
				}

			}

			nuevoLimite--;
		}

	}

	return retorno;
}


int imprimirArrayCondicional (int cadena[], int lenght, int condicion)
{
	int i;
	int retorno;

	retorno=-1;

	if(cadena!=NULL && lenght>0)
	{

		for(i=0;i<lenght;i++)
		{
			if(condicion==1)
			{
				if(esPositivo(cadena[i])==0)
						{
							printf("Posición %d: Numero %d\n",i,cadena[i]);
							retorno=0;
						}
			} else
			{
				if(condicion==-1)
				{
					if(esPositivo(cadena[i])!=0)
							{
								printf("Posición %d: Numero %d\n",i,cadena[i]);
								retorno=0;

							}
				} else
				{
					if(condicion==2)
					{
						if(esPrimo(cadena[i])==0&&cadena[i]>0)
						{
							printf("Posición %d: Numero %d\n",i,cadena[i]);
							retorno=0;

						}
					}
				}
			}

		}

	}

	return retorno;
}


static int esPrimo (int numero)
{
	int esPrimo;
	int divisores;
	int i;

	divisores=0;
	esPrimo=0;

		for (i=1;i<=numero;i++)
		{
			if(numero%i==0)
			{
				divisores++;
			}
			if(divisores>2)
			{
				esPrimo=-1;
				break;
			}
		}


	return esPrimo;
}

int mayorDeLosPrimos (int cadena[], int lenght, int* pMayorPrimo)
{
	int i;
	int mayorDeLosPrimos;
	char banderaPrimerPrimo='s';
	int retorno;

	retorno=-1;

	for(i=0;i<lenght;i++)
	{
		if(esPrimo(cadena[i])==0&&cadena[i]>0)
		{
			if(cadena[i]>mayorDeLosPrimos||banderaPrimerPrimo=='s')
			{
				mayorDeLosPrimos=cadena[i];
				banderaPrimerPrimo='n';
				retorno=0;
			}
		}
	}

	*pMayorPrimo=mayorDeLosPrimos;

	return retorno;

}

int evaluarRepetidos (int cadena[], int lenght)
{
	int i;
	int j;
	int retorno;

	retorno=-1;

	if(cadena!=NULL&&lenght>0)
	{
		retorno=0;
		for(i=0;i<lenght;i++)
		{
			for(j=i;j<lenght;j++)
			{
				if(cadena[i]==cadena[j]&&i!=j)
				{
					printf("El numero %d es repetido\n",cadena[i]);
					break;
				}

			}
		}
	}

	return retorno;
}
