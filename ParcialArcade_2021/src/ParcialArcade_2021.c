/*
 ============================================================================
 Name        : ParcialArcade_2021.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include "Salon.h"
#include "Arcade.h"
#include "Informes.h"
#include "biblioteca_input.h"
#define INACTIVO  1
#define ACTIVO  0
#define SALON_LEN 100
#define ARCADE_LEN 1000


int main(void) {

	setbuf(stdout,NULL);

	int posicionLibre;
	int idSolicitada;
	int eleccionUsuario;
	char subEleccionUsuario;
	char llaveDeCierre;
	float gananciaTotal;
	float valorFicha;
	int juegoEnArcades;
	char nombreJuegoPedido[63];
	llaveDeCierre='n';

	eSalon salonList [SALON_LEN];
	salon_initList(salonList,SALON_LEN);

	eArcade arcadeList[ARCADE_LEN];
	arc_initList(arcadeList,ARCADE_LEN);

	salon_altaForzada(salonList,"Sacoa","Maipu 225", 1, 10, 0);
	salon_altaForzada(salonList,"Showcase","Peatonal 14", 2, 11, 1);
	salon_altaForzada(salonList,"Juguelandia","Paseo 15", 1, 12, 2);
	salon_altaForzada(salonList,"Travalcase","Guemes 678", 1, 13, 3);
	salon_altaForzada(salonList,"Fichines","Arenales 1965", 2, 14, 4);
	salon_altaForzada(salonList,"Juego.com","Alsina 500", 2, 15, 5);

	arc_altaForzada(arcadeList,"USA", 1, 4, 2000, 11,"WonderBoy",1000, 0);
	arc_altaForzada(arcadeList,"Tokyo", 2, 5, 3000, 11,"Sonic",1001, 1);
	arc_altaForzada(arcadeList,"Alemania", 2, 6, 1500, 11,"Pacman",1002, 2);
	arc_altaForzada(arcadeList,"Holanda", 1, 5, 2600, 11,"Daytona",1006, 6);
	arc_altaForzada(arcadeList,"Argentina", 2, 3, 2100, 11,"Pacman",1004, 4);
	arc_altaForzada(arcadeList,"USA", 2, 6, 100, 11,"Street Fighter",1007, 7);
	arc_altaForzada(arcadeList,"Rusia", 2, 1, 1000, 13,"Metal Slug",1005, 5);
	arc_altaForzada(arcadeList,"Rusia", 2, 2, 1000, 13,"Megaman",1012, 12);
	arc_altaForzada(arcadeList,"Portugal", 2, 2, 3000, 14,"Booger Man",1008, 8);
	arc_altaForzada(arcadeList,"Finlandia", 2, 2, 1500, 14,"Pacman",1009, 9);
	arc_altaForzada(arcadeList,"USA", 1, 3, 3500, 14,"Prince of Persia",1010, 10);
	arc_altaForzada(arcadeList,"Alemania", 1, 6, 2600, 14,"Daytona",1013, 13);
	arc_altaForzada(arcadeList,"USA", 1, 3, 3500, 13,"Pacman",1003, 3);
	arc_altaForzada(arcadeList,"China", 2, 4, 2100, 13,"Capcom",1011,11);


	eleccionUsuario=menuOperaciones();

	while(llaveDeCierre!='s')
	{
		switch(eleccionUsuario)
		{
		case 1:
			posicionLibre=salon_buscarDisponible(salonList,SALON_LEN);
			if(posicionLibre>=0)
				{
					salon_loadSalon(&salonList[posicionLibre]);
				}
			eleccionUsuario=menuOperaciones();
			break;
		case 2:
			salon_imprimirCompleto(salonList,SALON_LEN);
			idSolicitada=salon_askForId();
			if(idSolicitada>0)
			{
				if(salon_buscarPorId (salonList,SALON_LEN, idSolicitada)>=0)
				{
					if(arc_removePorSalon(arcadeList,ARCADE_LEN, idSolicitada)==0)
					{
						salon_remove (salonList,SALON_LEN,idSolicitada);
					}
				} else
				{
					printf("La ID ingresada no coincide con ninguno de nuestro sistema\n");
				}


			}
			eleccionUsuario=menuOperaciones();
			break;
		case 3:
			salon_imprimirCompleto(salonList,SALON_LEN);
			eleccionUsuario=menuOperaciones();
			break;
		case 4:
			salon_imprimirCompleto(salonList,SALON_LEN);
			idSolicitada=salon_askForId();
			if(idSolicitada>0)
			{
				if(salon_buscarPorId(salonList,SALON_LEN,idSolicitada)>=0)
				{
					posicionLibre=arc_buscarDisponible(arcadeList, ARCADE_LEN);

					if(posicionLibre>=0)
					{
						arc_loadArcade(&arcadeList[posicionLibre],idSolicitada);
					}else
					{
						printf("No hay lugar disponible");
					}
				} else
				{
					printf("El ID no coincide con ningún salón");
				}
			}
			eleccionUsuario=menuOperaciones();
			break;
		case 5:
			arc_imprimirCompleto(arcadeList, ARCADE_LEN);
			idSolicitada=arc_askForId();
			if(idSolicitada>0)
			{
				arc_modificarArcade(arcadeList,ARCADE_LEN, idSolicitada);
			}
			eleccionUsuario=menuOperaciones();
			break;
		case 6:
			arc_imprimirCompleto(arcadeList, ARCADE_LEN);
			idSolicitada=arc_askForId();
			if(idSolicitada>0)
			{
				arc_remove (arcadeList,ARCADE_LEN,idSolicitada);
			}
			eleccionUsuario=menuOperaciones();
			break;
		case 7:
			arc_imprimirCompleto(arcadeList, ARCADE_LEN);
			eleccionUsuario=menuOperaciones();
			break;
		case 8:
			arc_imprimirJuegosSinRepetir (arcadeList, ARCADE_LEN);
			eleccionUsuario=menuOperaciones();
			break;
		case 9:
			subEleccionUsuario=info_subMenuReports ();
			switch (subEleccionUsuario)
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

			eleccionUsuario=menuOperaciones();
			break;
		case 10:
			llaveDeCierre='s';
			printf("Saliendo del sistema...");
			break;

		}

	}
	return EXIT_SUCCESS;
}
