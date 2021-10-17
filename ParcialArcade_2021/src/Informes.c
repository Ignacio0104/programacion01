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

#define TIPO_SHOPPING 1
#define TIPO_LOCAL 2
#define TIPO_MONO 1
#define TIPO_ESTEREO 2

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
	char cadenaAux[32];

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

					switch(salonList[i].type)
					{
						case TIPO_SHOPPING:
							strncpy(cadenaAux,"Shopping",32);
							break;
						case TIPO_LOCAL:
							strncpy(cadenaAux,"Local",32);
							break;
					}

					printf("Nombre: %s. Direccion: %s. Tipo: %s. ID de Salon: %d.  \n\n",
													salonList[i].name,
													salonList[i].address,
													cadenaAux,
													salonList[i].idSalon);
				}
			}

		}
	}

	return retorno;
}


int info_contarJugadores (eArcade *arcadeList, int lenghtArcade,eSalon *salonList,int lenghtSalon)
{
	int retorno;
	retorno=-1;
	int listaDeArcades[1000];
	int indiceDeArcades;
	int posicionSalon;
	char banderaExiste;

	indiceDeArcades=0;
	banderaExiste='n';

	if(arcadeList!=NULL&&lenghtArcade>0&&salonList!=NULL&&lenghtSalon>0)
	{
		retorno=0;
		for(int i=0;i<lenghtArcade;i++)
		{
			if(arcadeList[i].flagEmpty==ACTIVO)
			{
				if(arcadeList[i].numberOfPlayers>2)
				{
					listaDeArcades[indiceDeArcades]=arcadeList[i].idArcade;
					indiceDeArcades++;
				}

			}

		}

	}


	for(int i=0;i<lenghtArcade;i++)
	{
		for(int j=0;j<indiceDeArcades;j++)
		{
			if(arcadeList[i].flagEmpty==ACTIVO)
			{
				if(arcadeList[i].idArcade==listaDeArcades[j])
				{
					posicionSalon=salon_buscarPorId (salonList,lenghtSalon, arcadeList[i].idSalon);
					printf("ID arcade: %d. Cantidad Jugadores: %d. Nombre del juego: %s. Nombre Salon: %s.  \n\n",
													arcadeList[i].idArcade,
													arcadeList[i].numberOfPlayers,
													arcadeList[i].gameName,
													salonList[posicionSalon].name);
					banderaExiste='s';
				}
			}

		}
	}

	if(banderaExiste=='n')
	{
		printf("No hay ningún arcade cargado para mas de 2 jugadores");
	}

	return retorno;
}

int info_imprimirSalonPorId (eArcade *arcadeList, int lenghtArcade,eSalon *salonList,int lenghtSalon, int idIngresada)
{
	int retorno;
	int posicionBuscada;
	int contadorArcades;
	char cadenaAux[32];

	retorno=-1;
	contadorArcades=0;

	if(arcadeList!=NULL&&lenghtArcade>0&&salonList!=NULL&&lenghtSalon>0)
	{
		retorno=0;

		posicionBuscada=salon_buscarPorId (salonList,lenghtSalon, idIngresada);

		if(posicionBuscada>=0)
		{
			for (int i=0;i<lenghtArcade;i++)
			{
				if(arcadeList[i].idSalon==idIngresada)
				{
					contadorArcades++;
				}
			}
		} else
		{
			printf("Error, ID no coincide con ningún salon");
		}
	}

	retorno=contadorArcades;


	switch(salonList[posicionBuscada].type)
	{
		case TIPO_SHOPPING:
			strncpy(cadenaAux,"Shopping",32);
			break;
		case TIPO_LOCAL:
			strncpy(cadenaAux,"Local",32);
			break;
	}
	printf("Nombre: %s. Tipo: %s. Direccion: %s. Cantidad de arcades: %d.  \n\n",
									salonList[posicionBuscada].name,
									cadenaAux,
									salonList[posicionBuscada].address,
									contadorArcades);

	return retorno;
}

int info_imprimirArcadePorId (eArcade *arcadeList, int lenghtArcade,eSalon *salonList,int lenghtSalon, int idIngresada)
{
	int retorno;
	int posicionBuscada;
	char cadenaAux[32];
	char cadenaAuxDos[32];

	retorno=-1;

	if(arcadeList!=NULL&&lenghtArcade>0&&salonList!=NULL&&lenghtSalon>0)
	{
		retorno=0;

		posicionBuscada=salon_buscarPorId (salonList,lenghtSalon, idIngresada);

		if(posicionBuscada>=0)
		{
			switch(salonList[posicionBuscada].type)
			{
				case TIPO_SHOPPING:
					strncpy(cadenaAux,"Shopping",32);
					break;
				case TIPO_LOCAL:
					strncpy(cadenaAux,"Local",32);
					break;
			}
			printf("Salon %s. Tipo %s\n\n",salonList[posicionBuscada].name,cadenaAux);

			for (int i=0;i<lenghtArcade;i++)
			{
				if(arcadeList[i].idSalon==idIngresada)
				{
					switch(arcadeList[i].soundType)
					{
						case TIPO_MONO:
							strncpy(cadenaAuxDos,"Mono",32);
							break;
						case TIPO_ESTEREO:
							strncpy(cadenaAuxDos,"Estereo",32);
							break;
					}

					printf("ID del Arcade: %d. Nacionalidad: %s. Tipo de Sonido: %s. Cantidad de Jugadores: %d. Capacidad máxima de fichas: %d.  "
							"ID del Salon: %d Nombre del juego %s\n\n",
							arcadeList[i].idArcade,
							arcadeList[i].nationality,
							cadenaAux,
							arcadeList[i].numberOfPlayers,
							arcadeList[i].maximumTokens,
							arcadeList[i].idSalon,
							arcadeList[i].gameName);
				}
			}
		} else
		{
			printf("Error, ID no coincide con ningún salon");
		}
	}

	return retorno;
}


int info_imprimirSalonMasArcade (eArcade *arcadeList, int lenghtArcade,eSalon *salonList,int lenghtSalon)
{
	int retorno;
	int contadorDeArcades;
	char cadenaAux[32];
	int maximo;
	int idSalonMaximo;
	int posicionMaximo;

	retorno=-1;
	contadorDeArcades=0;
	maximo=0;

	if(arcadeList!=NULL&&lenghtArcade>0&&salonList!=NULL&&lenghtSalon>0)
	{
		for(int i=0;i<lenghtSalon;i++)
		{
			contadorDeArcades=0;
			for (int j=0;j<lenghtArcade;j++)
			{
				if(salonList[i].flagEmpty==ACTIVO&&arcadeList[j].flagEmpty==ACTIVO)
				{
					if(salonList[i].idSalon==arcadeList[j].idSalon)
					{
						contadorDeArcades++;

						if(contadorDeArcades>maximo)
						{
							idSalonMaximo=salonList[i].idSalon;
							maximo=contadorDeArcades;
						}

					}
				}

			}
		}

		} else
		{
			printf("Error, dato ingresado inválido\n");
		}

	posicionMaximo=salon_buscarPorId(salonList,lenghtSalon, idSalonMaximo);

	switch(salonList[posicionMaximo].type)
	{
		case TIPO_SHOPPING:
			strncpy(cadenaAux,"Shopping",32);
			break;
		case TIPO_LOCAL:
			strncpy(cadenaAux,"Local",32);
			break;
	}
	printf("El salon con mas cantidad de arcades es:\n\n"
			"Nombre: %s. Direccion: %s. Tipo: %s. ID de Salon: %d. Arcades: %d \n\n",
			salonList[posicionMaximo].name,
			salonList[posicionMaximo].address,
			cadenaAux,
			salonList[posicionMaximo].idSalon,
			maximo);


	return retorno;
}

int info_calcularFichasTotal (int idIngresada, eArcade *arcadeList, int lenghtArcade,eSalon *salonList,int lenghtSalon)
{
	int retorno;
	int acumuladorDeFichas;
	int posicionSolicitada;

	retorno=-1;
	acumuladorDeFichas=0;

	posicionSolicitada=salon_buscarPorId(salonList,lenghtSalon, idIngresada);

	if(posicionSolicitada>=0)
	{
		retorno=0;
		for(int i=0;i<lenghtArcade;i++)
		{
			if(arcadeList[i].flagEmpty==ACTIVO)
			{
				if(arcadeList[i].idSalon==idIngresada)
				{
					acumuladorDeFichas=acumuladorDeFichas + arcadeList[i].maximumTokens;
					retorno=acumuladorDeFichas;
				}
			}
		}

	}

	return retorno;

}




