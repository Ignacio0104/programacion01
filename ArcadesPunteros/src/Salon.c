/*
 * Salon.c
 *
 *  Created on: 16 oct 2021
 *      Author: Nacho
 */

#include "Salon.h"
#include <limits.h>


#define TIPO_SHOPPING 1
#define TIPO_LOCAL 2



static int dameUnIdNuevo (void);

static int dameUnIdNuevo (void)
{
	static int contador=0;
	return (contador++);
}

eSalon* salon_nuevo (void) //MODIFICADA
{

	eSalon* pSalon=malloc(sizeof(eSalon));
	return pSalon;
}


int salon_initList(eSalon *salonList[],int lenghtSalon) //MODIFICADA
{
	int retorno;

	retorno=-1;

	if(salonList!=NULL&&lenghtSalon>0)
	{
		retorno=0;
		for(int i=0;i<lenghtSalon;i++)
		{
			salonList[i]=NULL;
		}
	}

	return retorno;
}

int salon_loadSalon(eSalon *pSalon) //MODIFICADA (QUEDA IGUAL)
{
	int retorno;

	retorno=-1;

	char nameAux[128];
	char addressAux[128];
	char cadenaAuxUno[128]={"Shopping"};
	char cadenaAuxDos[128]={"Local"};
	int typeAux;

	if(pSalon!=NULL)
	{
		if(pedirTexto(nameAux,sizeof(nameAux), 3, "Ingrese el nombre del salon: ", "Error")==0)
		{
			if(pedirDireccion(addressAux,sizeof(addressAux), 3, "Ingrese la direccion del salon: ", "Error, ingrese calle y altura")==0)
			{
				if(pedirIntIntentosRango(&typeAux,1, 2, 5, "Ingrese el tipo:\n"
															"	1)Shopping\n"
															"	2)Local\n", "Error")==0)
				{


					strncpy(pSalon->name,nameAux,sizeof(pSalon->name));
					strncpy(pSalon->address,addressAux,sizeof(pSalon->address));
					pSalon->type=typeAux;
					pSalon->idSalon=dameUnIdNuevo();
					retorno=0;

					if(pSalon->type==1)
					{
						printf("Arcade cargado con exito:\n");
						printf("%-15s %15s %15s %15s\n\n","Nombre", "Direccion","Tipo de Salon","ID de Salon");
						printf("%-15s %15s %15s  %15d  \n",
								pSalon->name,
								pSalon->address,
								cadenaAuxUno,
								pSalon->idSalon);
					} else
					{
						printf("Arcade cargado con exito:\n");
						printf("%-15s %15s %15s %15s\n\n","Nombre", "Direccion","Tipo de Salon","ID de Salon");
						printf("%-15s %15s %15s  %15d  \n",
									pSalon->name,
									pSalon->address,
									cadenaAuxDos,
									pSalon->idSalon);
					}


				}

			}
		}
	}

	return retorno;

}

int salon_buscarDisponible(eSalon *salonList[], int lenghtSalon) //Modificada
{
	int retorno;
	retorno=-1;

	if(salonList!=NULL&&lenghtSalon>0)
	{
		retorno=0;
		for(int i=0;i<lenghtSalon;i++)
		{
			if(salonList[i]==NULL)
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

int salon_askForId (void) //MODIFICADA (QUEDA IGUAL)
{
	int retorno;
	int requestedId;

	if(pedirIntIntentosRango(&requestedId, 0, INT_MAX, 3, "Ingrese el ID del salon: ", "Error, dato ingresado invalido")==0)
	{
		retorno=requestedId;
	} else
	{
		retorno=-1;
	}


	return retorno;
}


int salon_buscarPorId (eSalon *salonList[], int lenghtSalon, int idIngresada) //MODIFICADA
{
	int retorno;
	retorno=-1;

	if(salonList!=NULL&&lenghtSalon>0)
	{

		for(int i=0;i<lenghtSalon;i++)
		{
			if(salonList[i]!=NULL)
			{

				if(salonList[i]->idSalon==idIngresada)
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

int salon_remove (eSalon *salonList[], int lenghtSalon, int idIngresada) //MODIFICADA
{
	int retorno;
	char userChoice;
	int posicionSolicitada;
	char cadenaAux [32];

	retorno=-1;

	if(salonList!=NULL&&lenghtSalon>0)
	{
		retorno=-2;

		posicionSolicitada=salon_buscarPorId (salonList,lenghtSalon, idIngresada);

		if(posicionSolicitada>=0)
		{
			salon_cambiarTexto (salonList, posicionSolicitada, cadenaAux);

			printf("\nSe va a eliminar el siguiente salon: \n\n");
			printf("%-15s %15s %15s  %15d  \n",
					salonList[posicionSolicitada]->name,
					salonList[posicionSolicitada]->address,
					cadenaAux,
					salonList[posicionSolicitada]->idSalon);

					if(pedirCharSiNo(&userChoice, 's', 'n', 5, "\n\n ---------Presione [s] para confirmar o [n] para volver al menu principal---------\n",
							"Error, dato ingresado inválido\n")==0)
					{
						if(userChoice=='s')
						{
							free(salonList[posicionSolicitada]);
							salonList[posicionSolicitada]=NULL;
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

int salon_imprimirCompleto(eSalon *salonList[], int lenghtSalon) //MODIFICADA
{
	int retorno;
	retorno=-1;
	char cadenaAux[32];

	if(salonList!=NULL&&lenghtSalon>0)
	{
		retorno=0;
		printf("%-15s %15s %15s %15s\n\n","Nombre", "Direccion","Tipo de Salon","ID de Salon");
		for(int i=0;i<lenghtSalon;i++)
		{

			if(salonList[i]!=NULL)
			{
				salon_cambiarTexto (salonList, i, cadenaAux);


				printf("%-15s %15s %15s  %15d  \n",
						salonList[i]->name,
						salonList[i]->address,
						cadenaAux,
						salonList[i]->idSalon);

			}

		}

	}

	return retorno;

}



void salon_altaForzada(eSalon *pSalon,char nombre[],char direccion[], int tipo) //MODIFICADA
{

	strncpy(pSalon->name,nombre,sizeof(pSalon->name));
	strncpy(pSalon->address,direccion,sizeof(pSalon->address));
	pSalon->type=tipo;
	pSalon->idSalon=dameUnIdNuevo();
}

int salon_cambiarTexto (eSalon *salonList[], int posicion, char pTextoConvertido[]) //MODIFICADA
{
	int retorno;

	retorno=-1;
	switch(salonList[posicion]->type)
	{
		case TIPO_SHOPPING:
			retorno=0;
			strncpy(pTextoConvertido,"Shopping",32);
			break;
		case TIPO_LOCAL:
			strncpy(pTextoConvertido,"Local",32);
			retorno=0;
			break;
	}

	return retorno;
}

int salon_occupancy (eSalon *salonList[], int lenghtSalon, int* pNotEmpty) //MODIFICADA
{
	int retorno;
	int notEmpty;
	int i;

	retorno=-1;
	notEmpty=0;

	if(salonList!=NULL&&lenghtSalon>0)
		{
			retorno=0;

			for (i=0;i<lenghtSalon;i++)
			{
				if(salonList[i]!=NULL)
				{
					notEmpty++;
				}

			}
		}

	*pNotEmpty=notEmpty;

	return retorno;
}











