/*
 * Salon.c
 *
 *  Created on: 16 oct 2021
 *      Author: Nacho
 */

#include "Salon.h"
#include <limits.h>
#define INACTIVO  1
#define ACTIVO  0


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
			if(pedirDireccion(addressAux,sizeof(addressAux), 3, "Ingrese la direccion del salon: ", "Error, ingrese calle y altura")==0)
			{
				if(pedirIntIntentosRango(&typeAux,1, 2, 5, "Ingrese el tipo:\n"
															"1)Shopping\n"
															"2)Local\n", "Error")==0)
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

	if(pedirIntIntentosRango(&requestedId, 0, INT_MAX, 3, "Ingrese el ID del salon: ", "Error, dato ingresado invalido")==0)
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
			printf("\nSe va a eliminar el siguiente salon: \n\n"
							"Nombre: %s. Direccion: %s. Tipo: %d. ID de Salon: %d.  \n\n",
							salonList[posicionSolicitada].name,
							salonList[posicionSolicitada].address,
							salonList[posicionSolicitada].type,
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

				printf("\n- Nombre: %s. Direccion: %s. Tipo: %d. ID de Salon: %d.  \n\n",
						salonList[i].name,
						salonList[i].address,
						salonList[i].type,
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
			"1)Alta de Salon\n"
			"2)Eliminar Salon\n"
			"3)Imprimir Salones\n"
			"4)Incorporar Arcade\n"
			"5)Modificar Arcade\n"
			"6)Eliminar Arcade\n"
			"7)Imprimir Arcades\n"
			"8)Imprimir Juegos\n"
			"9)Informes\n"
			"10)Salir\n");

	pedirIntIntentosRango(&eleccion, 1, 11, 20, "Ingrese aquí su elección", "Error");

	return eleccion;
}


void salon_altaForzada(eSalon *pSalon,char nombre[],char direccion[], int tipo, int id, int indice)
{
	strncpy(pSalon[indice].name,nombre,sizeof(pSalon[indice].name));
	strncpy(pSalon[indice].address,direccion,sizeof(pSalon[indice].address));
	pSalon[indice].type=tipo;
	pSalon[indice].idSalon=id;
	pSalon[indice].flagEmpty=ACTIVO;

}




