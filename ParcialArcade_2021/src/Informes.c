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

static int arc_cambiarTexto (eArcade *arcadeList, int posicion, char pTextoConvertido[]);
static int salon_cambiarTexto (eSalon *salonList, int posicion, char pTextoConvertido[]);

int menuOperaciones (void)
{
	int eleccion;

	printf("\n	|Menu|\n\n"
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

	pedirIntIntentosRango(&eleccion, 1, 11, 20, "Ingrese aquí su elección: \n", "Error");

	return eleccion;
}

char info_subMenuReports (void)
{
	char eleccion;

	printf("Opciones:\n\n"
			"	a)Salones con mas de 4 arcades\n"
			"	b)Arcades para mas de 2 jugadores\n"
			"	c)Información de arcade por ID de Arcade\n"
			"	d)Información de arcades por ID de Salon\n"
			"	e)Salon con mayor cantidad de arcades\n"
			"	f)Monto maximo en pesos por ID de Salon\n"
			"	g)Cantidad de arcades que tienen un juego (por nombre)\n"
			"	h)Volver al menu principal");

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

					if(contadorSalones==5)
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

					salon_cambiarTexto (salonList, i, cadenaAux);

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

	printf("%15s %15s %25s %15s \n\n","ID del Arcade","Jugadores","Juego","Salon" );
	for(int i=0;i<lenghtArcade;i++)
	{
		for(int j=0;j<indiceDeArcades;j++)
		{
			if(arcadeList[i].flagEmpty==ACTIVO)
			{
				if(arcadeList[i].idArcade==listaDeArcades[j])
				{
					posicionSalon=salon_buscarPorId (salonList,lenghtSalon, arcadeList[i].idSalon);
					printf("%15d %15d %25s %15s\n",
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


	salon_cambiarTexto (salonList, posicionBuscada, cadenaAux);
	printf("%15s %15s %15s %15s \n\n","Nombre", "Tipo","Direccion","Arcades");
	printf("%15s %15s %15s %15d \n",
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
			salon_cambiarTexto (salonList, posicionBuscada, cadenaAux);
			printf("Salon %s. Tipo %s\n\n",salonList[posicionBuscada].name,cadenaAux);

			for (int i=0;i<lenghtArcade;i++)
			{
				if(arcadeList[i].idSalon==idIngresada)
				{
					arc_cambiarTexto (arcadeList, i, cadenaAuxDos);
					printf("ID del Arcade: %d. Nacionalidad: %s. Tipo de Sonido: %s. Cantidad de Jugadores: %d. Capacidad máxima de fichas: %d.  "
							"ID del Salon: %d Nombre del juego %s\n\n",
							arcadeList[i].idArcade,
							arcadeList[i].nationality,
							cadenaAuxDos,
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
	if(arcadeList!=NULL&&lenghtArcade>0&&salonList!=NULL&&lenghtSalon>0)
	{
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

	}

	return retorno;
}

float info_calcularGananciaTotal (int idIngresada, float valorFicha,eArcade *arcadeList, int lenghtArcade,eSalon *salonList,int lenghtSalon)
{
	float retorno;
	int cantidadFichasMax;
	int gananciaPesos;

	retorno=-1;
	if(arcadeList!=NULL&&lenghtArcade>0&&salonList!=NULL&&lenghtSalon>0)
	{
		cantidadFichasMax=info_calcularFichasTotal (idIngresada, arcadeList, lenghtArcade,salonList,lenghtSalon);

		if(cantidadFichasMax>=0)
		{
			gananciaPesos=cantidadFichasMax*valorFicha;
		}

		retorno=gananciaPesos;
	}

	return retorno;

}

int info_juegoEnArcades (eArcade *arcadeList, int lenghtArcade, char nombreJuego[])
{
	int retorno;
	int contadorDeArcades;
	retorno=-1;
	contadorDeArcades=0;

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=0;
		for (int i=0;i<lenghtArcade;i++)
		{
			if(arcadeList[i].flagEmpty==ACTIVO)
			{
				if(strncmp(arcadeList[i].gameName,nombreJuego,63)==0)
				{
					contadorDeArcades++;
				}
			}
		}

		retorno=contadorDeArcades;
	}

	return retorno;
}


int salon_cambiarTexto (eSalon *salonList, int posicion, char pTextoConvertido[])
{
	int retorno;

	retorno=-1;
	switch(salonList[posicion].type)
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


int arc_cambiarTexto (eArcade *arcadeList, int posicion, char pTextoConvertido[])
{
	int retorno;

	retorno=-1;
	switch(arcadeList[posicion].soundType)
	{
		case TIPO_MONO:
			retorno=0;
			strncpy(pTextoConvertido,"Mono",32);
			break;
		case TIPO_ESTEREO:
			strncpy(pTextoConvertido,"Estereo",32);
			retorno=0;
			break;
	}

	return retorno;
}

int info_imprimirInformes (eArcade *arcadeList, int lenghtArcade,eSalon *salonList,int lenghtSalon, char eleccionUsuario)
{
	int retorno;
	int idSolicitada;
	float valorFicha;
	float gananciaTotal;
	char nombreJuegoPedido[63];
	int juegoEnArcades;

	retorno=-2;
	if(arcadeList!=NULL&&lenghtArcade>0&&salonList!=NULL&&lenghtSalon>0)
	{
		retorno=0;
		switch (eleccionUsuario)
		{
			case 'a':
				info_contarArcades (arcadeList, ARCADE_LEN,salonList,SALON_LEN);
				break;

			case 'b':
				info_contarJugadores (arcadeList, ARCADE_LEN,salonList,SALON_LEN);
				break;
			case 'c':
				salon_imprimirCompleto(salonList,SALON_LEN);
				idSolicitada=salon_askForId();
				if(idSolicitada>0)
				{
					info_imprimirSalonPorId(arcadeList, ARCADE_LEN,salonList,SALON_LEN, idSolicitada);
				}

				break;
			case 'd':
				salon_imprimirCompleto(salonList,SALON_LEN);
				idSolicitada=salon_askForId();
				if(idSolicitada>0)
				{
					info_imprimirArcadePorId (arcadeList, ARCADE_LEN,salonList,SALON_LEN, idSolicitada);
				}
				break;
			case 'e':
				info_imprimirSalonMasArcade (arcadeList, ARCADE_LEN,salonList,SALON_LEN);
				break;
			case 'f':
				salon_imprimirCompleto(salonList,SALON_LEN);
				idSolicitada=salon_askForId();
				pedirFloatIntentosRango(&valorFicha, 1, 1000, 5, "Ingrese el valor de la ficha", "Error, dato ingresado invalido");
				if(idSolicitada>0)
				{
					gananciaTotal=info_calcularGananciaTotal (idSolicitada, valorFicha,arcadeList, ARCADE_LEN,salonList,SALON_LEN);

					printf("La ganancia total del salon %s es de $ %.2f",salonList[salon_buscarPorId(salonList,SALON_LEN, idSolicitada)].name,
																		gananciaTotal);
				}
				break;
			case 'g':
				pedirTexto(nombreJuegoPedido,63, 5, "Ingrese el número del juego","Error, dato ingresado invalido");
				juegoEnArcades=info_juegoEnArcades (arcadeList, ARCADE_LEN, nombreJuegoPedido);
				if(juegoEnArcades==0)
				{
					printf("No se encontró el juego en nuestros arcades");
				}else
				{
					printf("El juego %s se encuentra en %d arcades",nombreJuegoPedido,juegoEnArcades);
				}
				break;

		}


	}

	return retorno;


}



