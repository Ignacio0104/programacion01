/*
 * Pantallas.c
 *
 *  Created on: 30 sept 2021
 *      Author: Nacho
 */

#include "estructuraSecundaria.h"
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
	static int contador=10; //Es una variable global que solo tiene visibilidad dentro de la función. Mantiene su valor por mas que salga de la fn
	return (contador++);
}

int cont_initList(eSecundaria *secundariaList,int lenghtSecundaria)
{
	int retorno;

	retorno=-1;

	if(secundariaList!=NULL&&lenghtSecundaria>0)
	{
		retorno=0;
		for(int i=0;i<lenghtSecundaria;i++)
		{
			secundariaList[i].flagEmpty=INACTIVO;
		}
	}

	return retorno;
}

int cont_buscarDisponible(eSecundaria* secundariaList, int lenghtSecundaria)
{
	int retorno;
	retorno=-1;

	if(secundariaList!=NULL&&lenghtSecundaria>0)
	{
		retorno=0;
		for(int i=0;i<lenghtSecundaria;i++)
		{
			if(secundariaList[i].flagEmpty==INACTIVO)
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


int cont_loadCont(eSecundaria *pCont, int idPantalla)
{
	int retorno;

	retorno=-1;

	float cuitAux;
	int cantidadDiasAux;
	char nameAux[128];

	if(pCont!=NULL)
	{
		if(pedirFloatIntentosRango(&cuitAux,0, 1000000, 10, "Ingrese el CUIT  ", "Error")==0)
		{
			if(pedirIntIntentosRango(&cantidadDiasAux,1, 365, 10, "Ingrese la cantidad de dias:  ", "Error")==0)
			{
				if(pedirTexto(nameAux,sizeof(nameAux), 3, "Ingrese el nombre del cliente: ", "Error")==0)
				{
					pCont->idCliente=dameUnIdNuevo();
					pCont->idPantalla=idPantalla;
					pCont->cuitCliente=cuitAux;
					pCont->cantidadDeDias=cantidadDiasAux;
					strncpy(pCont->name,nameAux,sizeof(pCont->name));
					pCont->flagEmpty=ACTIVO;
					retorno=0;

				}
			}

		}


	}

	return retorno;

}

float askForCuit ()
{
	float retorno;
	float requestedId;

	if(pedirFloatIntentosRango(&requestedId, 0, 100000, 3, "Ingrese el CUIT:  ", "Error, dato ingresado invalido")==0)
	{
		retorno=requestedId;
	} else
	{
		retorno=-1;
	}

	return retorno;
}

int cont_buscarPorCuit (eSecundaria *secundariaList, int lenghtSecundaria, float cuitIngresado)
{
	int retorno;
	retorno=-1;

	if(secundariaList!=NULL&&lenghtSecundaria>0)
	{

		for(int i=0;i<lenghtSecundaria;i++)
		{
			if(secundariaList[i].cuitCliente==cuitIngresado)
			{

				if(secundariaList[i].flagEmpty==ACTIVO)
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

int cont_askForId ()
{
	int retorno;
	int requestedId;

	if(pedirIntIntentosRango(&requestedId, 0, 100000, 3, "Ingrese el ID: ", "Error, dato ingresado invalido")==0)
	{
		retorno=requestedId;
	} else
	{
		retorno=-1;
	}

	return retorno;
}

int cont_buscarPorId (eSecundaria *secundariaList, int lenghtSecundaria, int idIngresada)
{
	int retorno;
	retorno=-1;

	if(secundariaList!=NULL&&lenghtSecundaria>0)
	{

		for(int i=0;i<lenghtSecundaria;i++)
		{
			if(secundariaList[i].idCliente==idIngresada)
			{

				if(secundariaList[i].flagEmpty==ACTIVO)
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

int cont_modificarContratacion(eSecundaria *secundariaList,int lenghtSecundaria, int idIngresada)
{
	int retorno;
	int posicionPedida;
	int cantidadDiasAux;

	retorno=-1;
	if(secundariaList!=NULL&&lenghtSecundaria>0)
	{
		retorno=0;
		posicionPedida=cont_buscarPorId (secundariaList,lenghtSecundaria, idIngresada);
		if(posicionPedida>0)
		{
			if(secundariaList[posicionPedida].flagEmpty==ACTIVO)
			{
				if(pedirIntIntentosRango(&cantidadDiasAux,1, 365, 10, "Ingrese la nueva cantidad de dias:  ", "Error")==0)
					{
						secundariaList[posicionPedida].cantidadDeDias=cantidadDiasAux;
					}

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



int cont_remove (eSecundaria*secundariaList, int lenghtSecundaria, int idIngresada)
{
	int retorno;
	char userChoice;
	int posicionSolicitada;

	retorno=-1;

	if(secundariaList!=NULL&&lenghtSecundaria>0)
	{
		retorno=-2;

		posicionSolicitada=cont_buscarPorId (secundariaList,lenghtSecundaria, idIngresada);

		if(posicionSolicitada>0)
		{
			printf("\nSe va a eliminar la siguiente contratacion: \n\n"
					"ID Pantalla: %d ID Cliente: %d. CUIT: %f. Cantidad de dias: %d.   Nombre: %s. \n\n",
					secundariaList[posicionSolicitada].idCliente,secundariaList[posicionSolicitada].idPantalla,secundariaList[posicionSolicitada].cuitCliente,
					secundariaList[posicionSolicitada].cantidadDeDias ,secundariaList[posicionSolicitada].name);

			if(pedirCharSiNo(&userChoice, 's', 'n', 5, "Presione [s] para confirmar o [n] para volver al menu principal\n",
					"Error, dato ingresado inválido\n")==0)
			{
				if(userChoice=='s')
				{
					secundariaList[posicionSolicitada].flagEmpty=INACTIVO;
					printf("Publicidad borrada exitosamente.\n");
					retorno=0;
				} else
				{
					if(userChoice=='n')
					{
						printf("No se borrará la publicidad. Volviendo al menú principal...\n");
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


int cont_imprimirCompleto(eSecundaria *secundariaList, int lenghtSecundaria)
{
	int retorno;
	retorno=-1;

	if(secundariaList!=NULL&&lenghtSecundaria>0)
	{
		retorno=0;
		for(int i=0;i<lenghtSecundaria;i++)
		{

			if(secundariaList[i].flagEmpty==ACTIVO)
			{
				printf("Id Cliente: %d. Id Pantalla: %d. CUIT: %f. Cantidad de dias: %d.   Nombre: %s. \n\n",
						secundariaList[i].idCliente,secundariaList[i].idPantalla,secundariaList[i].cuitCliente,
						secundariaList[i].cantidadDeDias ,secundariaList[i].name);
			}

		}

	}

	return retorno;

}


void cont_altaForzada(eSecundaria *secundariaList,int idCliente, int id, float cuit, int dias, char nombre[], int indice)
{
	secundariaList[indice].idCliente=idCliente;
	secundariaList[indice].idPantalla=id;
	secundariaList[indice].cuitCliente=cuit;
	secundariaList[indice].cantidadDeDias=dias;
	strncpy(secundariaList[indice].name,nombre,sizeof(secundariaList[indice].name));
	secundariaList[indice].flagEmpty=ACTIVO;
}



