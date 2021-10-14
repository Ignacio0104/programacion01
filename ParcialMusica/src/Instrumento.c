/*
 * Instrument.c
 *
 *  Created on: 14 oct 2021
 *      Author: Nacho
 */
#include "Instrumento.h"

#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INACTIVO 1
#define ACTIVO 0

static int dameUnIdNuevo (void);

static int dameUnIdNuevo (void)
{
	static int contador=100; //Es una variable global que solo tiene visibilidad dentro de la función. Mantiene su valor por mas que salga de la fn
	return (contador++);
}


int inst_initList(eInstrumento *instList,int lenghtInst)
{
	int retorno;

	retorno=-1;

	if(instList!=NULL&&lenghtInst>0)
	{
		retorno=0;
		for(int i=0;i<lenghtInst;i++)
		{
			instList[i].flagEmpty=INACTIVO;
		}
	}

	return retorno;
}

int inst_buscarDisponible(eInstrumento* instList, int lenghtInst)
{
	int retorno;
	retorno=-1;

	if(instList!=NULL&&lenghtInst>0)
	{
		retorno=0;
		for(int i=0;i<lenghtInst;i++)
		{
			if(instList[i].flagEmpty==INACTIVO)
			{
				retorno=i;
				break;
			} else
			{
				retorno=-2;
			}

		}


	}

	return retorno;

}

int inst_loadCont(eInstrumento *pInstrumento)
{
	int retorno;

	retorno=-1;
	char nameAux[128];
	int tipoAux;


	if(pInstrumento!=NULL)
	{
		if(pedirTexto(nameAux,sizeof(nameAux), 3, "Ingrese el nombre del intrumento: ", "Error")==0)
			{
				if(pedirIntIntentosRango(&tipoAux,1, 4, 10, "Ingrese el tipo de instrumento\n"
						"1)Cuerdas\n"
						"2)Viento-madera\n"
						"3)Viento-metal\n"
						"4)Percusion\n", "Error")==0)
				{
					strncpy(pInstrumento->name,nameAux,sizeof(pInstrumento->name));
					pInstrumento->tipo=tipoAux;
					pInstrumento->idInstrumento=dameUnIdNuevo();
					pInstrumento->flagEmpty=ACTIVO;
					retorno=0;

				}
			}




	}

	return retorno;

}

int inst_askForId ()
{
	int retorno;
	int requestedId;

	if(pedirIntIntentosRango(&requestedId, 0, 100000, 3, "Ingrese el ID del instrumento: ", "Error, dato ingresado invalido")==0)
	{
		retorno=requestedId;
	} else
	{
		retorno=-1;
	}

	return retorno;
}

int inst_buscarPorId (eInstrumento *instList, int lenghtInst, int idIngresada)
{
	int retorno;
	retorno=-1;

	if(instList!=NULL&&lenghtInst>0)
	{

		for(int i=0;i<lenghtInst;i++)
		{
			if(instList[i].idInstrumento==idIngresada)
			{

				if(instList[i].flagEmpty==ACTIVO)
				{
					retorno=i;
					break;
				}

			} else
			{
				retorno=-1;
			}

		}

	}

	return retorno;
}
int inst_imprimirCompleto(eInstrumento *instList, int lenghtInst)
{
	int retorno;
	retorno=-1;

	if(instList!=NULL&&lenghtInst>0)
	{
		retorno=0;
		for(int i=0;i<lenghtInst;i++)
		{

			if(instList[i].flagEmpty==ACTIVO)
			{
				printf("\n"
						"Nombre: %s. Tipo: %d. ID: %d. \n",
						instList[i].name,
						instList[i].tipo,
						instList[i].idInstrumento);
			}

		}

	}

	return retorno;

}


void inst_altaForzada(eInstrumento *instList,char nombre[],int tipo, int id, int indice)
{

	strncpy(instList[indice].name,nombre,sizeof(instList[indice].name));
	instList[indice].tipo=tipo;
	instList[indice].idInstrumento=id;
	instList[indice].flagEmpty=ACTIVO;
}
