/*
 * input.c
 *
 *  Created on: 4 sept 2021
 *      Author: Nacho
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"

int pedirNumero (void)
{
	int num;

	printf("Ingrese un número: ");
	scanf("%d",&num);

	return num;

}

int evaluarNumeros (int numero)
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

int promediar (int acumulador, int contador,float* pResultado)
{
	int huboError;
	float resul;

	if(contador==0)
	{
		huboError=1;
	} else
	{
		resul=(float)acumulador/contador;
		*pResultado=resul;
		huboError=0;
	}

	return huboError;

}

