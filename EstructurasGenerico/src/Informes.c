/*
 * Informes.c
 *
 *  Created on: 13 oct 2021
 *      Author: Nacho
 */


#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include "Informes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


				}

			}
			retorno=totalFacturacion;

		}

	return retorno;
}

float imprimirFacturacionPorCliente (eContratacion*contList, int lenght,eDisplay *displaysList,int lenghtDisplay, int* pIndiceMaximo, float* pCantidadMaximo)
{
	float retorno;
	int idPantalla;
	int indiceArrayPantalla;
	float totalFacturacion;
	int indiceMaximo;
	float cantidadMaximo;
	char flagPrimerIngreso;

	retorno=-1;
	totalFacturacion=0;
	flagPrimerIngreso='s';

	if(contList!=NULL&&lenght>0&&displaysList!=NULL&&lenghtDisplay>0)
		{
			retorno=0;
			for(int i=0;i<lenght;i++)
			{
					{
						if(contList[i].flagEmpty==ACTIVO)
						{
							idPantalla=contList[i].idPantalla;
							indiceArrayPantalla=disp_buscarPorId (displaysList, lenghtDisplay, idPantalla);

							totalFacturacion=contList[i].cantidadDeDias*displaysList[indiceArrayPantalla].pricePerDay;

							printf("El cliente %f tiene un importe a pagar de %f\n",contList[i].cuitCliente,totalFacturacion);

							if(totalFacturacion>cantidadMaximo||flagPrimerIngreso=='s')
							{
								indiceMaximo=i;
								cantidadMaximo=totalFacturacion;
							}
						}

					}

					flagPrimerIngreso='n';
				}

			}
			*pIndiceMaximo=indiceMaximo;
			*pCantidadMaximo=cantidadMaximo;
			retorno=totalFacturacion;

	return retorno;
}




