/*
 ============================================================================
 Name        : Parcial01_2021.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 static TEXTO NUMERO CLASE 11 PARTE III minuto 57
 */

#include <stdio.h>
#include <stdlib.h>
#include "Salon.h"
#include "biblioteca_input.h"
#define INACTIVO  1
#define ACTIVO  0
#define SALON_LEN 100


int main(void) {

	setbuf(stdout,NULL);

	int posicionLibre;
	int idSolicitada;
	//int posicionSolicitada;
	int eleccionUsuario;
	//float cuitAux;
	char llaveDeCierre;
	//float totalFacturacion;
	llaveDeCierre='n';

	eSalon salonList [SALON_LEN];
	salon_initList(salonList,SALON_LEN);

	salon_altaForzada(salonList,"Sacoa","Maipu 225", 1, 10, 0);
	salon_altaForzada(salonList,"Showcase","Peatonal 14", 2, 11, 1);
	salon_altaForzada(salonList,"Juguelandia","Paseo 15", 1, 12, 2);
	salon_altaForzada(salonList,"Travalcase","Guemes 678", 1, 13, 3);
	salon_altaForzada(salonList,"Fichines","Arenales 1965", 2, 14, 4);
	salon_altaForzada(salonList,"Juego.com","Alsina 500", 2, 15, 5);


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
			if(idSolicitada>=0)
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
			eleccionUsuario=menuOperaciones();
			break;
		case 5:
			eleccionUsuario=menuOperaciones();
			break;
		case 6:

			eleccionUsuario=menuOperaciones();
			break;
		case 7:

			eleccionUsuario=menuOperaciones();
			break;
		case 8:
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
