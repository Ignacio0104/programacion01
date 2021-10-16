/*
 * Informes.c
 *
 *  Created on: 16 oct 2021
 *      Author: Nacho
 */
#include "biblioteca_input.h"
#include "Informes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INACTIVO  1
#define ACTIVO  0
#define SALON_LEN 100
#define ARCADE_LEN 1000

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

char info_subMenuReports (void)
{
	char eleccion;

	printf("Opciones:\n\n"
			"a)Salones con mas de 4 arcades\n"
			"b)Arcades para mas de 2 jugadores\n"
			"c)Información de arcade por ID de Arcade\n"
			"d)Información de arcades por ID de Salon\n"
			"e)Salon con mayor cantidad de arcades\n"
			"f)Monto maximo en pesos por ID de Salon\n"
			"g)Cantidad de arcades que tienen un juego (por nombre)\n"
			"h)Volver al menu principal");

	pedirCharAUsuarioIntentosRango(&eleccion, 'a', 'h', 5, "\n\nIngrese su elección: ", "Error");

	return eleccion;
}

int info_contarArcades (eArcade *arcadeList, int lenghtArcade,eSalon *salonList,int lenghtSalon)
{
	int retorno;
	retorno=-1;
	int contadorSalones;
	int listaDeId[1000];
	int indiceDeId;

	arc_ordenarArcades (arcadeList, lenghtArcade,2);
	contadorSalones=1;
	indiceDeId=0;

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=0;
		for(int i=0;i<lenghtArcade;i++)
		{
			if(arcadeList[i].flagEmpty==ACTIVO)
			{
				if(arcadeList[i].idSalon == arcadeList[i+1].idSalon)
				{
					contadorSalones++;
					printf("Estoy aca\n");

					if(contadorSalones>4)
					{
						listaDeId[indiceDeId]=arcadeList[i].idSalon;
						indiceDeId++;
						if(contadorSalones>5)
						{
							continue;
						}
					}

				}else
				{
					contadorSalones=1;
				}

			}

		}

	}

	for(int i=0;i<lenghtSalon;i++)
	{
		for(int j=0;j<indiceDeId;j++)
		{
			if(salonList[i].flagEmpty==ACTIVO)
			{
				if(salonList[i].idSalon==listaDeId[j])
				{
					printf("Nombre: %s. Direccion: %s. Tipo: %d. ID de Salon: %d.  \n\n",
													salonList[i].name,
													salonList[i].address,
													salonList[i].type,
													salonList[i].idSalon);
				}
			}

		}
	}



	return retorno;
}



