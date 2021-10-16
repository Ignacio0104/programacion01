/*
 * Salon.c
 *
 *  Created on: 16 oct 2021
 *      Author: Nacho
 */

#include <stdio.h>
#include <stdlib.h>
#include "Salon.h"
#include "biblioteca_input.h"
#define INACTIVO  1
#define ACTIVO  0

static const char TXT_TIPOS [2][15]= {"Shopping","Local"};

static int dameUnIdNuevo (void);

static int dameUnIdNuevo (void)
{
	static int contador=1;
	return (contador++);
}


int salon_initList(eSalon *salonList,int lenghtSalon)
{
	int retorno;

	retorno=-1;

	if(salonList!=NULL&&lenghtSalon>0)
	{
		retorno=0;
		for(int i=0;i<lenghtSalon;i++)
		{
			salonList[i].flagEmpty=INACTIVO;
		}
	}

	return retorno;
}

int salon_loadSalon(eSalon *pSalon)
{
	int retorno;

	retorno=-1;

	char nameAux[128];
	char addressAux[128];
	int typeAux;


	if(pSalon!=NULL)
	{
		if(pedirTexto(nameAux,sizeof(nameAux), 3, "Ingrese el nombre del salon: ", "Error")==0)
		{
			if(pedirTexto(addressAux,sizeof(addressAux), 3, "Ingrese la direccion del salon: ", "Error")==0)
			{
				if(pedirIntIntentosRango(&typeAux,1, 2, 5, "Ingrese el tipo:\n"
															"1)Shopping\n"
															"2)Local\n  ", "Error")==0)
				{
					strncpy(pSalon->name,nameAux,sizeof(pSalon->name));
					strncpy(pSalon->address,addressAux,sizeof(pSalon->address));
					pSalon->type=typeAux;
					pSalon->idSalon=dameUnIdNuevo();
					pSalon->flagEmpty=ACTIVO;
					retorno=0;
				}

			}
		}
	}

	return retorno;

}

int salon_buscarDisponible(eSalon *salonList, int lenghtSalon)
{
	int retorno;
	retorno=-1;

	if(salonList!=NULL&&lenghtSalon>0)
	{
		retorno=0;
		for(int i=0;i<lenghtSalon;i++)
		{
			if(salonList[i].flagEmpty==INACTIVO)
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

int salon_askForId (void)
{
	int retorno;
	int requestedId;

	if(pedirIntIntentosRango(&requestedId, 0, 100000, 3, "Ingrese el ID del salon: ", "Error, dato ingresado invalido")==0)
	{
		retorno=requestedId;
	} else
	{
		retorno=-2;
	}


	return retorno;
}


int salon_buscarPorId (eSalon *salonList, int lenghtSalon, int idIngresada)
{
	int retorno;
	retorno=-1;

	if(salonList!=NULL&&lenghtSalon>0)
	{

		for(int i=0;i<lenghtSalon;i++)
		{
			if(salonList[i].idSalon==idIngresada)
			{

				if(salonList[i].flagEmpty==ACTIVO)
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

int salon_remove (eSalon *salonList, int lenghtSalon, int idIngresada)
{
	int retorno;
	char userChoice;
	int posicionSolicitada;

	retorno=-1;

	if(salonList!=NULL&&lenghtSalon>0)
	{
		retorno=-2;

		posicionSolicitada=salon_buscarPorId (salonList,lenghtSalon, idIngresada);

		if(posicionSolicitada>=0)
		{
			printf("\nSe va a eliminar el siguiente arcade: \n\n"
							"Nombre: %15s. Direccion: %15s. Tipo: %s. ID de Salon: %d.  \n\n",
							salonList[posicionSolicitada].name,
							salonList[posicionSolicitada].address,
							TXT_TIPOS[salonList[posicionSolicitada].type],
							salonList[posicionSolicitada].idSalon);

					if(pedirCharSiNo(&userChoice, 's', 'n', 5, "Presione [s] para confirmar o [n] para volver al menu principal\n",
							"Error, dato ingresado inválido\n")==0)
					{
						if(userChoice=='s')
						{
							salonList[posicionSolicitada].flagEmpty=INACTIVO;
							printf("Salon borrado exitosamente.\n");
							retorno=0;
						} else
						{
							if(userChoice=='n')
							{
								printf("No se borrará el Salón. Volviendo al menú principal...\n");
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

int salon_imprimirCompleto(eSalon *salonList, int lenghtSalon)
{
	int retorno;
	retorno=-1;

	if(salonList!=NULL&&lenghtSalon>0)
	{
		retorno=0;
		for(int i=0;i<lenghtSalon;i++)
		{

			if(salonList[i].flagEmpty==ACTIVO)
			{

				printf("Nombre: %15s. Direccion: %15s. Tipo: %s. ID de Salon: %d.  \n\n",
						salonList[i].name,
						salonList[i].address,
						TXT_TIPOS[salonList[i].type],
						salonList[i].idSalon);
			}

		}

	}

	return retorno;

}

int menuOperaciones (void)
{
	int eleccion;

	printf("Opciones:\n\n"
			"1)Alta de pantalla\n"
			"2)Modificar datos de pantalla\n"
			"3)Baja de pantalla\n"
			"4)Contratar una publicidad\n"
			"5)Modificar condiciones de publicacion\n"
			"6)Cancelar contratación\n"
			"7)Consulta facturacion\n"
			"8)Lista contrataciones\n"
			"9)Lista pantallas\n"
			"10)Informar\n"
			"11)Salir\n");

	pedirIntIntentosRango(&eleccion, 1, 11, 20, "Ingrese aquí su elección", "Error");

	return eleccion;
}






