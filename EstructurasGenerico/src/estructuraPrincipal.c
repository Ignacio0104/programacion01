/*
 * Pantallas.c
 *
 *  Created on: 30 sept 2021
 *      Author: Nacho
 */

#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include "estructuraPrincipal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INACTIVO 1
#define ACTIVO 0

static int dameUnIdNuevo (void);


int princ_initList(ePrincipal *principalList,int lenghtPrincipal)
{
	int retorno;

	retorno=-1;

	if(principalList!=NULL&&lenghtPrincipal>0)
	{
		retorno=0;
		for(int i=0;i<lenghtPrincipal;i++)
		{
			principalList[i].flagEmpty=INACTIVO;
		}
	}

	return retorno;
}

int princ_loadPrincipal(ePrincipal *principalList)
{
	int retorno;

	retorno=-1;

	int numeroAux;
	float floatAux;
	//int idAux;
	char nombreAux[128];
	char direccionAux[60];

	if(principalList!=NULL)
	{
		if(pedirIntIntentosRango(&numeroAux,1, 2, 10, "Ingrese el tipo: 1 o 2  ", "Error")==0)
		{
			if(pedirFloatIntentosRango(&floatAux,0, 100000, 10, "Ingrese el precio:  ", "Error")==0)
			{
				if(pedirTexto(nombreAux,sizeof(nombreAux), 3, "Ingrese el nombre: ", "Error")==0)
				{
					if(pedirTexto(direccionAux,sizeof(direccionAux), 3, "Ingrese la direccion: ", "Error")==0)
					{
						principalList->type=numeroAux;
						principalList->pricePerDay=floatAux;
						principalList->id=dameUnIdNuevo();
						strncpy(principalList->name,nombreAux,sizeof(principalList->name));
						strncpy(principalList->address,direccionAux,sizeof(principalList->address));
						principalList->flagEmpty=ACTIVO;
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

int princ_buscarDisponible(ePrincipal *principalList, int lenghtPrincipal)
{
	int retorno;
	retorno=-1;

	if(principalList!=NULL&&lenghtPrincipal>0)
	{
		retorno=0;
		for(int i=0;i<lenghtPrincipal;i++)
		{
			if(principalList[i].flagEmpty==INACTIVO)
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

int princ_askForId (ePrincipal *principalList, int lenghtPrincipal)
{
	int retorno;
	int requestedId;

	retorno=-1;
	if(principalList!=NULL&&lenghtPrincipal>0)
		{
			retorno=0;
			if(pedirIntIntentosRango(&requestedId, 0, 100000, 3, "Ingrese el ID: ", "Error, dato ingresado invalido")==0)
			{
				retorno=requestedId;
			} else
			{
				retorno=-2;
			}
		}

	return retorno;
}

int princ_buscarPorId (ePrincipal *principalList, int lenghtPrincipal, int idIngresada)
{
	int retorno;
	retorno=-1;

	if(principalList!=NULL&&lenghtPrincipal>0)
	{

		for(int i=0;i<lenghtPrincipal;i++)
		{
			if(principalList[i].id==idIngresada)
			{

				if(principalList[i].flagEmpty==ACTIVO)
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

int princ_remove (ePrincipal *principalList, int lenghtPrincipal, int idIngresada)
{
	int retorno;
	char userChoice;
	int posicionSolicitada;

	retorno=-1;

	if(principalList!=NULL&&lenghtPrincipal>0)
	{
		retorno=-2;

		posicionSolicitada=princ_buscarPorId (principalList,lenghtPrincipal, idIngresada);

		if(posicionSolicitada>0)
		{
			printf("\nSe va a eliminar la siguiente pantalla: \n\n"
							"Tipo: %02d. Precio: %18.2f. ID: %d.   Nombre: %15s.  Direccion: %15s.\n\n",
							principalList[posicionSolicitada].type,principalList[posicionSolicitada].pricePerDay,principalList[posicionSolicitada].id ,principalList[posicionSolicitada].name,principalList[posicionSolicitada].address);

					if(pedirCharSiNo(&userChoice, 's', 'n', 5, "Presione [s] para confirmar o [n] para volver al menu principal\n",
							"Error, dato ingresado inválido\n")==0)
					{
						if(userChoice=='s')
						{
							principalList[posicionSolicitada].flagEmpty=INACTIVO;
							printf("Dato borrado exitosamente.\n");
							retorno=0;
						} else
						{
							if(userChoice=='n')
							{
								printf("No se borrará el dato. Volviendo al menú principal...\n");
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


int princ_modificarPrincipal(ePrincipal *principalList,int lenghtPrincipal, int idIngresada)
{
	int retorno;
	int posicionPedida;

	retorno=-1;
	if(principalList!=NULL&&lenghtPrincipal>0)
	{
		retorno=0;
		posicionPedida=princ_buscarPorId (principalList,lenghtPrincipal, idIngresada);
		if(posicionPedida>0)
		{
			if(principalList[posicionPedida].flagEmpty==ACTIVO)
			{
				printf("Se van a modificar los datos del ID %d\n",posicionPedida);

				princ_loadDisplay(&principalList[posicionPedida]);
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


int princ_imprimirCompleto(ePrincipal *principalList, int lenghtPrincipal)
{
	int retorno;
	retorno=-1;

	if(principalList!=NULL&&lenghtPrincipal>0)
	{
		retorno=0;
		for(int i=0;i<lenghtPrincipal;i++)
		{

			if(principalList[i].flagEmpty==ACTIVO)
			{
				printf("Tipo: %d. Precio: %f. ID: %d. Nombre: %s. Direccion: %s.\n",
						principalList[i].type, principalList[i].pricePerDay, principalList[i].id,
						principalList[i].name,principalList[i].address);
			}

		}

	}

	return retorno;

}


void princ_altaForzada(ePrincipal *principalList,int tipo, float precio, int id, char nombre[], char direccion[], int indice)
{
	principalList[indice].type=tipo;
	principalList[indice].pricePerDay=precio;
	principalList[indice].id=id;
	strncpy(principalList[indice].name,nombre,sizeof(principalList[indice].name));
	strncpy(principalList[indice].address,direccion,sizeof(principalList[indice].address));
	principalList[indice].flagEmpty=ACTIVO;

}




