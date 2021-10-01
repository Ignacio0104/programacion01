/*
 * Pantallas.c
 *
 *  Created on: 30 sept 2021
 *      Author: Nacho
 */

#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include "Pantallas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int dameUnIdNuevo (void);


int disp_initList(eDisplay *displaysList,int lenght)
{
	int retorno;

	retorno=-1;

	if(displaysList!=NULL&&lenght>0)
	{
		retorno=0;
		for(int i=0;i<lenght;i++)
		{
			displaysList[i].flagEmpty=1;
		}
	}

	return retorno;
}

int disp_loadDisplay(eDisplay *pDisplay)
{
	int retorno;

	retorno=-1;

	int typeAux;
	float pricePerDayAux;
	//int idAux;
	char nameAux[128];
	char addressAux[60];

	if(pDisplay!=NULL)
	{
		if(pedirIntIntentosRango(&typeAux,0, 1, 10, "Ingrese el tipo LCD>0 LED>1:  ", "Error")==0)
		{
			if(pedirFloatIntentosRango(&pricePerDayAux,0, 100000, 10, "Ingrese el precio:  ", "Error")==0)
			{
				if(pedirTexto(nameAux,128, "Ingrese el nombre: ", "Error")==0)
				{
					if(pedirTexto(addressAux,60, "Ingrese la direccion: ", "Error")==0)
					{
						pDisplay->type=typeAux;
						pDisplay->pricePerDay=pricePerDayAux;
						pDisplay->id=dameUnIdNuevo();
						strncpy(pDisplay[0]->name,nameAux,sizeof(pDisplay->name));
						strncpy(pDisplay[0]->address,addressAux,sizeof(pDisplay->address));
						pDisplay[0]->flagEmpty=0;
						retorno=0;
					}

				}
			}
		}

	}

	return retorno;

}


static int dameUnIdNuevo (void)
{
	static int contador=0; //Es una variable global que solo tiene visibilidad dentro de la función. Mantiene su valor por mas que salga de la fn
	return (contador++);
}

int disp_print(eDisplay *displaysList,int lenght)
{
	int retorno;

	retorno=-1;

	if(displaysList!=NULL&&lenght>0)
	{
		retorno=0;
		for(int i=0;i<lenght;i++)
		{
			printf("%d",displaysList[i].flagEmpty);
		}
	}

	return retorno;
}
