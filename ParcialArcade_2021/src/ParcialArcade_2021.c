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
	//float cuitAux;
	char llaveDeCierre;
	//float totalFacturacion;
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
	arc_altaForzada(arcadeList,"Tokyo", 2, 2, 3000, 10,"Sonic",1001, 1);
	arc_altaForzada(arcadeList,"Alemania", 2, 6, 1500, 15,"Tetris",1002, 2);
	arc_altaForzada(arcadeList,"USA", 1, 1, 3500, 14,"Pacman",1003, 3);
	arc_altaForzada(arcadeList,"Argentina", 2, 4, 2100, 11,"Rayman",1004, 4);
	arc_altaForzada(arcadeList,"Rusia", 2, 6, 1000, 13,"Metal Slug",1005, 5);
	arc_altaForzada(arcadeList,"USA", 1, 1, 2600, 11,"Daytona",1006, 6);


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
				salon_remove (salonList,SALON_LEN,idSolicitada);
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
