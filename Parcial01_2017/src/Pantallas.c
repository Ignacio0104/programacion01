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
#define INACTIVO 1
#define ACTIVO 0

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
			displaysList[i].flagEmpty=INACTIVO;
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
	char nameAux[128];
	char addressAux[128];

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

						pDisplay->type=typeAux;
						pDisplay->pricePerDay=pricePerDayAux;
						pDisplay->id=dameUnIdNuevo();
						strncpy(pDisplay->name,nameAux,sizeof(pDisplay->name));
						strncpy(pDisplay->address,addressAux,sizeof(pDisplay->address));
						pDisplay->flagEmpty=ACTIVO;
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
	static int contador=1000; //Es una variable global que solo tiene visibilidad dentro de la función. Mantiene su valor por mas que salga de la fn
	return (contador++);
}

int disp_buscarDisponible(eDisplay *displaysList, int lenght)
{
	int retorno;
	retorno=-1;

	if(displaysList!=NULL&&lenght>0)
	{
		retorno=0;
		for(int i=0;i<lenght;i++)
		{
			if(displaysList[i].flagEmpty==INACTIVO)
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

int disp_askForId (void)
{
	int retorno;
	int requestedId;

			if(pedirIntIntentosRango(&requestedId, 0, 100000, 3, "Ingrese el ID: ", "Error, dato ingresado invalido")==0)
			{
				retorno=requestedId;
			} else
			{
				retorno=-2;
			}


	return retorno;
}

int disp_buscarPorId (eDisplay *displaysList, int lenght, int idIngresada)
{
	int retorno;
	retorno=-1;

	if(displaysList!=NULL&&lenght>0)
	{

		for(int i=0;i<lenght;i++)
		{
			if(displaysList[i].id==idIngresada)
			{

				if(displaysList[i].flagEmpty==ACTIVO)
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

int disp_remove (eDisplay *displaysList, int lenght, int idIngresada)
{
	int retorno;
	char userChoice;
	int posicionSolicitada;

	retorno=-1;

	if(displaysList!=NULL&&lenght>0)
	{
		retorno=-2;

		posicionSolicitada=disp_buscarPorId (displaysList,lenght, idIngresada);

		if(posicionSolicitada>0)
		{
			printf("\nSe va a eliminar la siguiente pantalla: \n\n"
							"Tipo: %02d. Precio: %18.2f. ID: %d.   Nombre: %15s.  Direccion: %15s.\n\n",
							displaysList[posicionSolicitada].type,displaysList[posicionSolicitada].pricePerDay,displaysList[posicionSolicitada].id ,displaysList[posicionSolicitada].name,displaysList[posicionSolicitada].address);

					if(pedirCharSiNo(&userChoice, 's', 'n', 5, "Presione [s] para confirmar o [n] para volver al menu principal\n",
							"Error, dato ingresado inválido\n")==0)
					{
						if(userChoice=='s')
						{
							displaysList[posicionSolicitada].flagEmpty=INACTIVO;
							printf("Empleado borrado exitosamente.\n");
							retorno=0;
						} else
						{
							if(userChoice=='n')
							{
								printf("No se borrará al empleado. Volviendo al menú principal...\n");
								retorno=0;
							}
						}

					}
				}

			}

		if(retorno==-2)
		{
			printf("\nNo se pudo realizar la acción\n");
		}

	return retorno;

}


int disp_modificarPantalla(eDisplay *displaysList,int lenght, int idIngresada)
{
	int retorno;
	int posicionPedida;

	retorno=-1;
	if(displaysList!=NULL&&lenght>0)
	{
		retorno=0;
		posicionPedida=disp_buscarPorId (displaysList,lenght, idIngresada);
		if(posicionPedida>=0)
		{
			if(displaysList[posicionPedida].flagEmpty==ACTIVO)
			{
				printf("Se van a modificar los datos del ID %d\n",posicionPedida);

				disp_loadDisplay(&displaysList[posicionPedida]);
			} else
			{
				printf("Aca está fallando");
			}

		} else
		{
			printf("Acá está el error");
		}

	}

	return retorno;

}


int disp_imprimirCompleto(eDisplay *displaysList, int lenght)
{
	int retorno;
	retorno=-1;

	if(displaysList!=NULL&&lenght>0)
	{
		retorno=0;
		for(int i=0;i<lenght;i++)
		{

			if(displaysList[i].flagEmpty==ACTIVO)
			{

				printf("Tipo: %d. Precio: %f. ID: %d. Nombre: %s. Direccion: %s.\n",
						displaysList[i].type, displaysList[i].pricePerDay, displaysList[i].id,
						displaysList[i].name,displaysList[i].address);
			}

		}

	}

	return retorno;

}


void disp_altaForzada(eDisplay *pDisplay,int tipo, float precio, int id, char nombre[], char direccion[], int indice)
{
	pDisplay[indice].type=tipo;
	pDisplay[indice].pricePerDay=precio;
	pDisplay[indice].id=id;
	strncpy(pDisplay[indice].name,nombre,sizeof(pDisplay[indice].name));
	strncpy(pDisplay[indice].address,direccion,sizeof(pDisplay[indice].address));
	pDisplay[indice].flagEmpty=ACTIVO;

}




