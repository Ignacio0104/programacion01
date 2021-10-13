/*
 * Informes.c
 *
 *  Created on: 13 oct 2021
 *      Author: Nacho
 */


#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include "Informes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INACTIVO 1
#define ACTIVO 0

int imprimirPantallasPorCuit (eContratacion*contList, int lenght, float cuit,eDisplay *displaysList,int lenghtDisplay)
{
	int retorno;
	int idPantalla;
	int indiceArrayPantalla;

	retorno=-1;

	if(contList!=NULL&&lenght>0&&displaysList!=NULL&&lenghtDisplay>0)
		{
			retorno=0;
			for(int i=0;i<lenght;i++)
			{
				if(contList[i].cuitCliente==cuit)
				{
					idPantalla=contList[i].idPantalla;
					indiceArrayPantalla=disp_buscarPorId (displaysList, lenghtDisplay, idPantalla);

					printf("\n\nId Contratacion: %d. Tipo: %d. Precio: %f. ID: %d. Nombre: %s. Direccion: %s.\n",
						contList[i].idCliente,displaysList[indiceArrayPantalla].type, displaysList[indiceArrayPantalla].pricePerDay, displaysList[indiceArrayPantalla].id,
						displaysList[indiceArrayPantalla].name,displaysList[indiceArrayPantalla].address);

				}

			}

		}

	return retorno;
}
