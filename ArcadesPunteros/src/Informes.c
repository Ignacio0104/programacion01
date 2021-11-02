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

#define SALON_LEN 100
#define ARCADE_LEN 1000
#define NATION_LEN 128
#define GAME_LEN 63
#define NAME_LEN 128
#define ADDRESS_LEN 128

#define TIPO_SHOPPING 1
#define TIPO_LOCAL 2
#define TIPO_MONO 1
#define TIPO_ESTEREO 2

//static int arc_cambiarTexto (eArcade *arcadeList, int posicion, char pTextoConvertido[]);


int menuOperaciones (void)
{
	int eleccion;

	printf("\n <<<|Menu|>>>\n\n"
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
			"	h)Cantidad de salones completos\n"
			"	i)Promedio de arcades por salon\n"
			"	j)Volver al menu principal");

	pedirCharAUsuarioIntentosRango(&eleccion, 'a', 'j', 5, "\n\nIngrese su elección: ", "Error");

	return eleccion;
}

int info_contarArcades (eArcade *arcadeList[], int lenghtArcade,eSalon *salonList[],int lenghtSalon) //MODIFICADA
{
	int retorno;
	retorno=-1;
	int contadorSalones;
	int listaDeId[1000];
	int indiceDeId;
	char cadenaAux[32];

	int idSalonAuxUno;
	int idSalonAuxDos;
	char nombreAux[NAME_LEN];
	char addressAux[ADDRESS_LEN];

	arc_ordenarArcades (arcadeList, lenghtArcade,2);
	contadorSalones=1;
	indiceDeId=0;

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=0;
		for(int i=0;i<lenghtArcade;i++)
		{
			if(arcadeList[i]!=NULL&&arcadeList[i+1]!=NULL)
			{
				arc_getIdSalon(arcadeList[i],&idSalonAuxUno);
				arc_getIdSalon(arcadeList[i+1],&idSalonAuxDos);

				if(idSalonAuxUno == idSalonAuxDos)
				{
					contadorSalones++;

					if(contadorSalones==5)
					{
						listaDeId[indiceDeId]=idSalonAuxUno;
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
			if(salonList[i]!=NULL)
			{
				salon_getIdSalon(salonList[i],&idSalonAuxUno);
				if(idSalonAuxUno==listaDeId[j])
				{
					salon_cambiarTexto (salonList, i, cadenaAux);
					salon_getName(salonList[i],nombreAux);
					salon_getAddress(salonList[i],addressAux);

					printf("Nombre: %s. Direccion: %s. Tipo: %s. ID de Salon: %d.  \n\n",
							nombreAux,addressAux,cadenaAux,idSalonAuxUno);

				}
			}

		}
	}
	if(contadorSalones==1)
	{
		printf("Ningún salon tiene mas de 4 arcades");
	}

	return retorno;
}


int info_contarJugadores (eArcade *arcadeList[], int lenghtArcade,eSalon *salonList[],int lenghtSalon)//MODIFICADA
{
	int retorno;
	retorno=-1;
	int listaDeArcades[1000];
	int indiceDeArcades;
	int posicionSalon;
	char banderaExiste;

	int jugadoresAux;
	int idArcadeAux;
	int idSalonAux;
	char gameNameAux[GAME_LEN];
	char salonNameAux[NAME_LEN];

	indiceDeArcades=0;
	banderaExiste='n';

	if(arcadeList!=NULL&&lenghtArcade>0&&salonList!=NULL&&lenghtSalon>0)
	{
		retorno=0;
		for(int i=0;i<lenghtArcade;i++)
		{
			if(arcadeList[i]!=NULL)
			{
				arc_getNumPlayers(arcadeList[i],&jugadoresAux);
				if(jugadoresAux>2)
				{
					arc_getIdArcade(arcadeList[i],&idArcadeAux);
					listaDeArcades[indiceDeArcades]=idArcadeAux;
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
			if(arcadeList[i]!=NULL)
			{
				arc_getIdArcade(arcadeList[i],&idArcadeAux);
				if(idArcadeAux==listaDeArcades[j])
				{
					arc_getIdSalon(arcadeList[i],&idSalonAux);
					posicionSalon=salon_buscarPorId (salonList,lenghtSalon, idSalonAux);

					arc_getIdArcade(arcadeList[i],&idArcadeAux);
					arc_getNumPlayers(arcadeList[i],&jugadoresAux);
					arc_getGameName(arcadeList[i],gameNameAux);
					salon_getName(salonList[posicionSalon],salonNameAux);

					printf("%15d %15d %25s %15s\n",
							idArcadeAux,jugadoresAux,gameNameAux,salonNameAux);
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

int info_imprimirSalonPorId (eArcade *arcadeList[], int lenghtArcade,eSalon *salonList[],int lenghtSalon, int idIngresada) //MODIFICADA
{
	int retorno;
	int posicionBuscada;
	int contadorArcades;
	char cadenaAux[32];

	int idSalonAux;
	char nameAux[NAME_LEN];
	char addressAux [ADDRESS_LEN];

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
				if(arcadeList[i]!=NULL)
				{
					arc_getIdSalon(arcadeList[i],&idSalonAux);
					if(idSalonAux==idIngresada)
						{
							contadorArcades++;
						}
				}

			}
		} else
		{
			printf("Error, ID no coincide con ningún salon");
		}
	}

	retorno=contadorArcades;


	salon_cambiarTexto (salonList, posicionBuscada, cadenaAux);

	salon_getName(salonList[posicionBuscada],nameAux);
	salon_getAddress(salonList[posicionBuscada],addressAux);

	printf("%15s %15s %15s %15s \n\n","Nombre", "Tipo","Direccion","Arcades");
	printf("%15s %15s %15s %15d \n",
			nameAux,cadenaAux,addressAux,contadorArcades);

	return retorno;
}

int info_imprimirArcadePorId (eArcade *arcadeList[], int lenghtArcade,eSalon *salonList[],int lenghtSalon, int idIngresada) //MODIFICADA
{
	int retorno;
	int posicionBuscada;
	char cadenaAux[32];
	char cadenaAuxDos[32];

	char nameAux[NAME_LEN];
	int idSalonAux;
	int idArcadeAux;
	char nationalityAux[NATION_LEN];
	int jugadoresAux;
	int tokensAux;
	char gameNameAux[GAME_LEN];

	retorno=-1;

	if(arcadeList!=NULL&&lenghtArcade>0&&salonList!=NULL&&lenghtSalon>0)
	{
		retorno=0;

		posicionBuscada=salon_buscarPorId (salonList,lenghtSalon, idIngresada);

		if(posicionBuscada>=0)
		{
			salon_getName(salonList[posicionBuscada],nameAux);
			salon_cambiarTexto (salonList, posicionBuscada, cadenaAux);
			printf("\n\nSalon %s. Tipo %s\n\n",nameAux,cadenaAux);

			printf("%15s %15s %15s %15s %15s %15s %15s\n\n","ID del Arcade", "Nacionalidad","Sonido","Jugadores","Fichas máximas","ID de Salon", "Juego");
			for (int i=0;i<lenghtArcade;i++)
			{
				if(arcadeList[i]!=NULL)
				{
					arc_getIdSalon(arcadeList[i],&idSalonAux);
					if(idSalonAux==idIngresada)
					{
						arc_cambiarTexto (arcadeList, i, cadenaAuxDos);
						arc_getIdArcade(arcadeList[i],&idArcadeAux);
						arc_getNationality(arcadeList[i],nationalityAux);
						arc_getNumPlayers(arcadeList[i],&jugadoresAux);
						arc_getMaxTokens(arcadeList[i], &tokensAux);
						arc_getGameName(arcadeList[i],gameNameAux);
						printf("%15d %15s %15s %15d %15d %15d %15s\n",
								idArcadeAux,nationalityAux,cadenaAux,jugadoresAux,tokensAux,idSalonAux,gameNameAux);
					}
				}
			}
		} else
		{
			printf("Error, ID no coincide con ningún salon");
		}
	}

	return retorno;
}


int info_imprimirSalonMasArcade (eArcade *arcadeList[], int lenghtArcade,eSalon *salonList[],int lenghtSalon) //MODIFICADA
{
	int retorno;
	int contadorDeArcades;
	char cadenaAux[32];
	int maximo;
	int idSalonMaximo;
	int posicionMaximo;

	int idSalonAuxUno;
	int idSalonAuxDos;
	char addressAux[ADDRESS_LEN];
	char nameAux[NAME_LEN];

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
				if(salonList[i]!=NULL&&arcadeList[j]!=NULL)
				{
					arc_getIdSalon(arcadeList[i],&idSalonAuxUno);
					arc_getIdSalon(arcadeList[j],&idSalonAuxDos);
					if(idSalonAuxUno==idSalonAuxDos)
					{
						contadorDeArcades++;

						if(contadorDeArcades>maximo)
						{
							idSalonMaximo=idSalonAuxUno;
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

	salon_cambiarTexto (salonList, posicionMaximo, cadenaAux);
	salon_getName(salonList[posicionMaximo],nameAux);
	salon_getAddress(salonList[posicionMaximo],addressAux);
	salon_getIdSalon(salonList[posicionMaximo],&idSalonAuxUno);

	printf("El salon con mas cantidad de arcades es:\n\n"
			"Nombre: %s. Direccion: %s. Tipo: %s. ID de Salon: %d. Arcades: %d \n\n",
			nameAux,addressAux,cadenaAux,idSalonAuxUno,maximo);

	return retorno;
}

int info_calcularFichasTotal (int idIngresada, eArcade *arcadeList[], int lenghtArcade,eSalon *salonList[],int lenghtSalon) //MODIFICADA
{
	int retorno;
	int acumuladorDeFichas;
	int posicionSolicitada;

	int idSalonAux;
	int tokensAux;

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
				if(arcadeList[i]!=NULL)
				{
					arc_getIdSalon(arcadeList[i],&idSalonAux);
					if(idSalonAux==idIngresada)
					{
						arc_getMaxTokens(arcadeList[i],&tokensAux);
						acumuladorDeFichas=acumuladorDeFichas + tokensAux;
						retorno=acumuladorDeFichas;
					}
				}
			}

		}

	}

	return retorno;
}

float info_calcularGananciaTotal (int idIngresada, float valorFicha,eArcade *arcadeList[], int lenghtArcade,eSalon *salonList[],int lenghtSalon) //MODIFICADA
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

int info_juegoEnArcades (eArcade *arcadeList[], int lenghtArcade, char nombreJuego[]) //MODIFICADA
{
	int retorno;
	int contadorDeArcades;
	retorno=-1;
	contadorDeArcades=0;

	char gameNameAux[GAME_LEN];

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=0;
		for (int i=0;i<lenghtArcade;i++)
		{
			if(arcadeList[i]!=NULL)
			{
				arc_getGameName(arcadeList[i],gameNameAux);
				if(strncmp(gameNameAux,nombreJuego,GAME_LEN)==0)
				{
					contadorDeArcades++;
				}
			}
		}

		retorno=contadorDeArcades;
	}

	return retorno;
}



int info_imprimirInformes (eArcade *arcadeList[], int lenghtArcade,eSalon *salonList [],int lenghtSalon, char eleccionUsuario) //MODIFICADA
{
	int retorno;
	int idSolicitada;
	float valorFicha;
	float gananciaTotal;
	char nombreJuegoPedido[63];
	int juegoEnArcades;
	int posicionSolicitada;
	char nameAux[NAME_LEN];

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

					posicionSolicitada=salon_buscarPorId(salonList,SALON_LEN, idSolicitada);
					salon_getName(salonList[posicionSolicitada],nameAux);
					printf("La ganancia total del salon %s es de $ %.2f",nameAux,gananciaTotal);
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

			case 'h':
				info_arcadesCompletos (arcadeList, ARCADE_LEN,salonList,SALON_LEN);
				break;
			case 'i':
				info_promedioDeArcades (arcadeList, ARCADE_LEN,salonList,SALON_LEN);
				break;

		}


	}

	return retorno;


}

int info_arcadesCompletos (eArcade *arcadeList[], int lenghtArcade,eSalon *salonList[],int lenghtSalon) //MODIFICADA
{
	int retorno;
	retorno=-1;
	int contadorSalonesCompletos;
	int listaDeId[1000];
	int indiceDeId;
	char cadenaAux[32];

	int idSalonAuxUno;
	int idSalonAuxDos;
	int jugadoresAux;
	char nameAux[NAME_LEN];
	char addressAux[ADDRESS_LEN];

	arc_ordenarArcades (arcadeList, lenghtArcade,2);
	contadorSalonesCompletos=0;
	indiceDeId=0;

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=0;
		for(int i=0;i<lenghtArcade;i++)
		{
			if(arcadeList[i]!=NULL)
			{
				arc_getIdSalon(arcadeList[i],&idSalonAuxUno);
				arc_getIdSalon(arcadeList[i+1],&idSalonAuxDos);
				if(idSalonAuxUno == idSalonAuxDos)
				{
					arc_getNumPlayers(arcadeList[i],&jugadoresAux);
					if(jugadoresAux>2)
					{
						contadorSalonesCompletos++;
						if(contadorSalonesCompletos==7)
						{
							arc_getIdSalon(arcadeList[i],&idSalonAuxUno);
							listaDeId[indiceDeId]=idSalonAuxUno;
							indiceDeId++;

							if(contadorSalonesCompletos>7)
							{
								continue;
							}
						}

					}
				}
				else
				{
					contadorSalonesCompletos=0;
				}

			}

		}

	}

	for(int i=0;i<lenghtSalon;i++)
	{
		for(int j=0;j<indiceDeId;j++)
		{
			if(salonList[i]!=NULL)
			{
				salon_getIdSalon(salonList[i],&idSalonAuxUno);
				if(idSalonAuxUno==listaDeId[j])
				{
					salon_cambiarTexto (salonList, i, cadenaAux);
					salon_getName(salonList[i],nameAux);
					salon_getAddress(salonList[i],addressAux);

					printf("Nombre: %s. Direccion: %s. Tipo: %s. ID de Salon: %d.  \n\n",nameAux,addressAux,cadenaAux,idSalonAuxUno);


				}
			}

		}
	}
	if(indiceDeId==0)
	{
		printf("No hay ningún salon completo");
	}

	return retorno;
}

float info_promedioDeArcades (eArcade *arcadeList[], int lenghtArcade,eSalon *salonList[],int lenghtSalon) //MODIFICADA
{
	float retorno;
	retorno=-1;
	int contadorSalonesTotal;
	int contadorArcadesTotal;

	contadorArcadesTotal=0;
	contadorSalonesTotal=0;

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=0;
		for(int i=0;i<lenghtArcade;i++)
		{
			if(arcadeList[i]!=NULL)
			{
				contadorArcadesTotal++;
			}
		}


		for(int i=0;i<lenghtSalon;i++)
		{
			if(salonList[i]!=NULL)
			{
				contadorSalonesTotal++;
			}
		}
	}

	if(contadorSalonesTotal>0&&contadorArcadesTotal>0)
	{
		retorno=(float)contadorArcadesTotal/contadorSalonesTotal;
		printf("El promedio de arcades por salon es de %.2f",retorno);
	}


	return retorno;


}

