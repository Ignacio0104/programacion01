/*
 * Informes.c
 *
 *  Created on: 13 oct 2021
 *      Author: Nacho
 */

#include "biblioteca_input.h"
#include "Informes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DISPLAYS_LEN 100
#define CONTRATACIONES_LEN 1000

#define INACTIVO 1
#define ACTIVO 0

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


float calcularFacturacionPorCuit (eContratacion*contList, int lenght, float cuit,eDisplay *displaysList,int lenghtDisplay)
{
	float retorno;
	int idPantalla;
	int indiceArrayPantalla;
	float totalFacturacion;

	totalFacturacion=0;

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

					totalFacturacion+=contList[i].cantidadDeDias*displaysList[indiceArrayPantalla].pricePerDay;
					printf("\nID: %d - Archivo: %s - Cuit: %f - Dias: %d - IdPantalla: %d - Importe %.2f"
																				,contList[i].idCliente
																				,contList[i].name
																				,contList[i].cuitCliente
																				,contList[i].cantidadDeDias
																				,contList[i].idPantalla
																				,totalFacturacion);

				}

			}
			retorno=totalFacturacion;

		}

	return retorno;
}

float imprimirFacturacionPorCliente (eContratacion*contList, int lenght,eDisplay *displaysList,int lenghtDisplay)
{
	int retorno = -1;
	//char listaCuit[CANTIDAD_CLIENTES][CUIT_LEN];
	float listaCuit[CONTRATACIONES_LEN];
	int i;
	int j;
	char flagExisteCuit;
	int indiceCuitLibre = 0;
	float auxiliarDeuda;
	float deudaMaxima;
	int indiceClienteDeudaMaxima;

	for(i=0;i<lenght;i++)
	{
		flagExisteCuit = 'n';
		if(contList[i].flagEmpty == ACTIVO)
		{
			for(j=0;j<indiceCuitLibre;j++)
			{
				if(listaCuit[j]==contList[i].cuitCliente)
				{
					flagExisteCuit = 's';
					break;
				}
			}

			if(flagExisteCuit == 'n')
			{
				listaCuit[j]=contList[i].cuitCliente;
				indiceCuitLibre++;
			}
		}
	}

	for(j=0;j<indiceCuitLibre;j++)
	{
		printf("\n\n El cliente con cuit %f\n",listaCuit[j]);
		calcularFacturacionPorCuit (contList,lenght, listaCuit[j],displaysList,lenghtDisplay);

	}


	for(j=0;j<indiceCuitLibre;j++)
	{

		info_calcularDeudaCliente(contList,lenght,displaysList,lenghtDisplay,listaCuit[j], &auxiliarDeuda);
		if(j == 0|| (auxiliarDeuda > deudaMaxima))
		{
			deudaMaxima = auxiliarDeuda;
			indiceClienteDeudaMaxima = j;
		}

	}
	printf("\n\n El cliente con mas deuda es cuit %f - debe %.2f\n",listaCuit[indiceClienteDeudaMaxima],deudaMaxima);

	return retorno;

}


int info_calcularDeudaCliente(eContratacion*contList, int lenght,eDisplay *displaysList,int lenghtDisplay,float auxiliarCuit, float* deuda)
{
	int retorno = -1;
	int i;
	int indiceArrayPantalla;
	int idPantalla;
	float auxiliarDeuda=0;

	if(contList != NULL && lenght > 0 && displaysList != NULL && lenghtDisplay > 0)
	{
		for(i=0;i<lenght;i++)
		{
			if(contList[i].flagEmpty==ACTIVO)
			{
				if(contList[i].cuitCliente == auxiliarCuit)
				{
					idPantalla = contList[i].idPantalla;
					indiceArrayPantalla=disp_buscarPorId (displaysList, lenghtDisplay, idPantalla);
					auxiliarDeuda = auxiliarDeuda + (contList[i].cantidadDeDias* displaysList[indiceArrayPantalla].pricePerDay);
				}
			}
		}
		retorno = 0;
		*deuda=auxiliarDeuda;
	}
	return retorno;
}




