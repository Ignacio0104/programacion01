/*
 * Pantallas.c
 *
 *  Created on: 30 sept 2021
 *      Author: Nacho
 */

#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include "Contratacion.h"
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

int cont_initList(eContratacion *contList,int lenght)
{
	int retorno;

	retorno=-1;

	if(contList!=NULL&&lenght>0)
	{
		retorno=0;
		for(int i=0;i<lenght;i++)
		{
			contList[i].flagEmpty=INACTIVO;
		}
	}

	return retorno;
}

int cont_buscarDisponible(eContratacion* contList, int lenght)
{
	int retorno;
	retorno=-1;

	if(contList!=NULL&&lenght>0)
	{
		retorno=0;
		for(int i=0;i<lenght;i++)
		{
			if(contList[i].flagEmpty==INACTIVO)
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


int cont_loadCont(eContratacion *pCont, int idPantalla)
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

int cont_buscarPorCuit (eContratacion *contList, int lenght, float cuitIngresado)
{
	int retorno;
	retorno=-1;

	if(contList!=NULL&&lenght>0)
	{

		for(int i=0;i<lenght;i++)
		{
			if(contList[i].cuitCliente==cuitIngresado)
			{

				if(contList[i].flagEmpty==ACTIVO)
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

int cont_buscarPorId (eContratacion *contList, int lenght, int idIngresada)
{
	int retorno;
	retorno=-1;

	if(contList!=NULL&&lenght>0)
	{

		for(int i=0;i<lenght;i++)
		{
			if(contList[i].idCliente==idIngresada)
			{

				if(contList[i].flagEmpty==ACTIVO)
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

int cont_modificarContratacion(eContratacion *contList,int lenght, int idIngresada)
{
	int retorno;
	int posicionPedida;
	int cantidadDiasAux;

	retorno=-1;
	if(contList!=NULL&&lenght>0)
	{
		retorno=0;
		posicionPedida=cont_buscarPorId (contList,lenght, idIngresada);
		if(posicionPedida>0)
		{
			if(contList[posicionPedida].flagEmpty==ACTIVO)
			{
				if(pedirIntIntentosRango(&cantidadDiasAux,1, 365, 10, "Ingrese la nueva cantidad de dias:  ", "Error")==0)
					{
						contList[posicionPedida].cantidadDeDias=cantidadDiasAux;
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



int cont_remove (eContratacion*contList, int lenght, int idIngresada)
{
	int retorno;
	char userChoice;
	int posicionSolicitada;

	retorno=-1;

	if(contList!=NULL&&lenght>0)
	{
		retorno=-2;

		posicionSolicitada=cont_buscarPorId (contList,lenght, idIngresada);

		if(posicionSolicitada>0)
		{
			printf("\nSe va a eliminar la siguiente contratacion: \n\n"
					"ID Pantalla: %d ID Cliente: %d. CUIT: %f. Cantidad de dias: %d.   Nombre: %s. \n\n",
					contList[posicionSolicitada].idCliente,contList[posicionSolicitada].idPantalla,contList[posicionSolicitada].cuitCliente,
					contList[posicionSolicitada].cantidadDeDias ,contList[posicionSolicitada].name);

			if(pedirCharSiNo(&userChoice, 's', 'n', 5, "Presione [s] para confirmar o [n] para volver al menu principal\n",
					"Error, dato ingresado inválido\n")==0)
			{
				if(userChoice=='s')
				{
					contList[posicionSolicitada].flagEmpty=INACTIVO;
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


int cont_imprimirCompleto(eContratacion *contList, int lenght)
{
	int retorno;
	retorno=-1;

	if(contList!=NULL&&lenght>0)
	{
		retorno=0;
		for(int i=0;i<lenght;i++)
		{

			if(contList[i].flagEmpty==ACTIVO)
			{
				printf("Id Cliente: %d. Id Pantalla: %d. CUIT: %f. Cantidad de dias: %d.   Nombre: %s. \n\n",
						contList[i].idCliente,contList[i].idPantalla,contList[i].cuitCliente,
						contList[i].cantidadDeDias ,contList[i].name);
			}

		}

	}

	return retorno;

}


void cont_altaForzada(eContratacion *contList,int idCliente, int id, float cuit, int dias, char nombre[], int indice)
{
	contList[indice].idCliente=idCliente;
	contList[indice].idPantalla=id;
	contList[indice].cuitCliente=cuit;
	contList[indice].cantidadDeDias=dias;
	strncpy(contList[indice].name,nombre,sizeof(contList[indice].name));
	contList[indice].flagEmpty=ACTIVO;
}



