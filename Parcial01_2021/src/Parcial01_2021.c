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
			idSolicitada=salon_askForId();
			if(idSolicitada>=0)
			{
				salon_imprimirCompleto(salonList,SALON_LEN);
			}
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
			eleccionUsuario=menuOperaciones();
			break;
		case 11:
			llaveDeCierre='s';
			printf("Saliendo del sistema...");
			break;
		}

	}
	return EXIT_SUCCESS;
}
