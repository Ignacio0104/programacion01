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
#define VACIO 1
#define OCUPADO 0

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
			displaysList[i].flagEmpty=VACIO;
		}
	}

	return retorno;
}

int disp_loadDisplay(eDisplay *pDisplay, int posicion)
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
				if(pedirTexto(nameAux,sizeof(nameAux), 3, "Ingrese el nombre: ", "Error")==0)
				{
					if(pedirTexto(addressAux,sizeof(nameAux), 3, "Ingrese la direccion: ", "Error")==0)
					{
						pDisplay[posicion].type=typeAux;
						pDisplay[posicion].pricePerDay=pricePerDayAux;
						pDisplay[posicion].id=dameUnIdNuevo();
						strncpy(pDisplay[posicion].name,nameAux,sizeof(pDisplay[posicion].name));
						strncpy(pDisplay[posicion].address,addressAux,sizeof(pDisplay[posicion].address));
						pDisplay[posicion].flagEmpty=OCUPADO;
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
	static int contador=1000; //Es una variable global que solo tiene visibilidad dentro de la funci�n. Mantiene su valor por mas que salga de la fn
	return (contador++);
}

int buscarDisponible(eDisplay *displaysList, int *pPosicionVacia, int lenght)
{
	int retorno;
	int posicionLibre;
	retorno=-1;

	if(displaysList!=NULL&&lenght>0)
	{
		retorno=0;
		for(int i=0;i<lenght;i++)
		{
			if(displaysList[i].flagEmpty==VACIO)
			{
				posicionLibre=i;
				break;
			}

		}

		*pPosicionVacia=posicionLibre;
	}

	return retorno;

}

/*
  int buscarLibre (Display *unDisplay, int len)  VERSION CLASE
 {
	 int retorno=-1;
	 if(unDisplay!=NULL && len>0)
	 {
		 for (int i = 0;  i< len; ++i)
		 {
			if(unDisplay[i].flagEmpty==LIBRE)
			{
				retorno=i;
				break;
			}
		 }
	 }
	 return retorno;
 }
 */

int modificarPantalla(eDisplay *displaysList,int lenght)
{
	int retorno;
	int posicionPedida;

	retorno=-1;
	if(displaysList!=NULL&&lenght>0)
	{
		retorno=0;
		if(buscarPorId (displaysList, &posicionPedida, lenght)==0 && displaysList->flagEmpty==OCUPADO)
		{
			printf("Se van a modificar los datos del ID %d",posicionPedida);

			disp_loadDisplay(displaysList, posicionPedida);

		}

	}

	return retorno;

}

int cargarPantalla(eDisplay *displaysList,int lenght)
{
	int retorno;
	int posicionPedida;

	retorno=-1;
	if(displaysList!=NULL&&lenght>0)
	{
		retorno=0;
		if(buscarPorId (displaysList, &posicionPedida, lenght)==0 && displaysList->flagEmpty==VACIO)
		{
			printf("Se van a cargar los datos de la posici�n %d",posicionPedida);

			disp_loadDisplay(displaysList, posicionPedida);

		} else
		{
			if(buscarPorId (displaysList, &posicionPedida, lenght)==-1)
			{
				printf("Error, ID inexistente");
			}
		}

	}

	return retorno;

}

int buscarPorId (eDisplay *displaysList, int *pPosicionSolicitada, int lenght)
{
	int retorno;
	int posicionPedida;
	retorno=-1;

	if(displaysList!=NULL&&lenght>0)
	{
		retorno=0;
		int idIngresada;
		pedirIntIntentosRango(&idIngresada, 0, 10000, 3, "Ingrese el ID", "Error");

		for(int i=0;i<lenght;i++)
		{
			if(displaysList[i].id==idIngresada&&displaysList->flagEmpty==VACIO)
			{
				posicionPedida=i;
				break;
			} else
			{
				retorno=-1;
			}

		}

		*pPosicionSolicitada=posicionPedida;
	}

	return retorno;

}
/*
int buscarPorId(Display* pDisplay, int len, int IdBuscado)  VERSION DE CLASE
{
	int retorno=-1;
	int i;

	if(pDisplay!=NULL && len>0 && IdBuscado>0)
	{
		for(i=0;i<len;i++)
		{
			if(pDisplay[i].id==IdBuscado && pDisplay[i].flagEmpty==OCUPADO)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}*/

int imprimirCompleto(eDisplay *displaysList, int lenght)
{
	int retorno;
	retorno=-1;

	if(displaysList!=NULL&&lenght>0)
	{
		retorno=0;
		for(int i=0;i<lenght;i++)
		{

			if(displaysList[i].flagEmpty==0)
			{
				printf("Tipo: %d. Precio: %f. ID: %d. Nombre: %s. Direccion: %s. Vacio: %d\n",
						displaysList[i].type, displaysList[i].pricePerDay, displaysList[i].id,
						displaysList[i].name,displaysList[i].address, displaysList[i].flagEmpty);
			}

		}

	}

	return retorno;

}

