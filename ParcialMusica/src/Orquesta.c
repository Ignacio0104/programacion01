/*
 * Pantallas.c
 *
 *  Created on: 30 sept 2021
 *      Author: Nacho
 */

#include "Orquesta.h"

#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INACTIVO 1
#define ACTIVO 0

static int dameUnIdNuevo (void);


int orq_initList(eOrquesta *orquestList,int orquestLenght)
{
	int retorno;

	retorno=-1;

	if(orquestList!=NULL&&orquestLenght>0)
	{
		retorno=0;
		for(int i=0;i<orquestLenght;i++)
		{
			orquestList[i].flagEmpty=INACTIVO;
		}
	}

	return retorno;
}

int orq_loadDisplay(eOrquesta *pOrquesta)
{
	int retorno;

	retorno=-1;

	int typeAux;
	//int idAux;
	char nameAux[128];
	char addressAux[128];

	if(pOrquesta!=NULL)
	{
		if(pedirTexto(nameAux,sizeof(nameAux), 3, "Ingrese el nombre de la Orquesta: ", "Error")==0)
		{
			if(pedirTexto(addressAux,sizeof(nameAux), 3, "Ingrese la direccion: ", "Error")==0)
			{
				if(pedirIntIntentosRango(&typeAux,1, 3, 10, "Ingrese el tipo 1)Sinfonica 2)Filarmonica 3)Camara", "Error")==0)
					{
						strncpy(pOrquesta->name,nameAux,sizeof(pOrquesta->name));
						strncpy(pOrquesta->place,addressAux,sizeof(pOrquesta->place));
						pOrquesta->type=typeAux;
						pOrquesta->idOrquesta=dameUnIdNuevo();
						pOrquesta->flagEmpty=ACTIVO;
						retorno=0;
					}

				}
			}
		}


	return retorno;

}


static int dameUnIdNuevo (void)
{
	static int contador=1; //Es una variable global que solo tiene visibilidad dentro de la función. Mantiene su valor por mas que salga de la fn
	return (contador++);
}

int orq_buscarDisponible(eOrquesta *orquestList, int orquestLenght)
{
	int retorno;
	retorno=-1;

	if(orquestList!=NULL&&orquestLenght>0)
	{
		retorno=0;
		for(int i=0;i<orquestLenght;i++)
		{
			if(orquestList[i].flagEmpty==INACTIVO)
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

int orq_askForId (void)
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

int orq_buscarPorId (eOrquesta *orquestList, int orquestLenght, int idIngresada)
{
	int retorno;
	retorno=-1;

	if(orquestList!=NULL&&orquestLenght>0)
	{

		for(int i=0;i<orquestLenght;i++)
		{
			if(orquestList[i].idOrquesta==idIngresada)
			{

				if(orquestList[i].flagEmpty==ACTIVO)
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

int orq_remove (eOrquesta *orquestList, int orquestLenght, int idIngresada)
{
	int retorno;
	char userChoice;
	int posicionSolicitada;

	retorno=-1;

	if(orquestList!=NULL&&orquestLenght>0)
	{
		retorno=-2;

		posicionSolicitada=orq_buscarPorId (orquestList,orquestLenght, idIngresada);

		if(posicionSolicitada>0)
		{
			printf("\nSe va a eliminar la siguiente orquesta: \n\n"
							"Nombre: %s. Lugar: %s. Tipo: %d. ID: %d.\n\n",
							orquestList[posicionSolicitada].name,
							orquestList[posicionSolicitada].place,
							orquestList[posicionSolicitada].type,
							orquestList[posicionSolicitada].idOrquesta);

					if(pedirCharSiNo(&userChoice, 's', 'n', 5, "Presione [s] para confirmar o [n] para volver al menu principal\n",
							"Error, dato ingresado inválido\n")==0)
					{
						if(userChoice=='s')
						{
							orquestList[posicionSolicitada].flagEmpty=INACTIVO;
							printf("Orquesta borrada exitosamente.\n");
							retorno=0;
						} else
						{
							if(userChoice=='n')
							{
								printf("No se borrará la orquesta Volviendo al menú principal...\n");
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


int orq_modificarPantalla(eOrquesta *orquestList,int orquestLenght, int idIngresada)
{
	int retorno;
	int posicionPedida;

	retorno=-1;
	if(orquestList!=NULL&&orquestLenght>0)
	{
		retorno=0;
		posicionPedida=orq_buscarPorId (orquestList,orquestLenght, idIngresada);
		if(posicionPedida>0)
		{
			if(orquestList[posicionPedida].flagEmpty==ACTIVO)
			{
				printf("Se van a modificar los datos de la orquesta %s\n",orquestList[posicionPedida].name);

				orq_loadDisplay(&orquestList[posicionPedida]);
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


int orq_imprimirCompleto(eOrquesta *orquestList, int orquestLenght)
{
	int retorno;
	retorno=-1;

	if(orquestList!=NULL&&orquestLenght>0)
	{
		retorno=0;
		for(int i=0;i<orquestLenght;i++)
		{

			if(orquestList[i].flagEmpty==ACTIVO)
			{

				printf("Nombre: %s. Lugar: %s. Tipo %d, ID: %d\n",
						orquestList[i].name,
						orquestList[i].place,
						orquestList[i].type,
						orquestList[i].idOrquesta);

			}

		}

	}

	return retorno;

}


void orq_altaForzada(eOrquesta *pOrquesta,char nombre[],char direccion[], int tipo, int id, int indice)
{
	strncpy(pOrquesta[indice].name,nombre,sizeof(pOrquesta[indice].name));
	strncpy(pOrquesta[indice].place,direccion,sizeof(pOrquesta[indice].place));
	pOrquesta[indice].type=tipo;
	pOrquesta[indice].idOrquesta=id;

	pOrquesta[indice].flagEmpty=ACTIVO;

}






