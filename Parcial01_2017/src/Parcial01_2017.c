/*
 ============================================================================
 Name        : Parcial01_2017.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include "Contratacion.h"
#include "Pantallas.h"
#include "Informes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DISPLAYS_LEN 20

int main(void) {

	setbuf(stdout,NULL);

	int posicionLibre;
	int idSolicitada;
	//int posicionSolicitada;
	int eleccionUsuario;
	float cuitAux;
	char llaveDeCierre;
	llaveDeCierre='n';

	eDisplay displaysList [DISPLAYS_LEN];

	eContratacion contList [DISPLAYS_LEN];

	disp_initList(displaysList,DISPLAYS_LEN);
	cont_initList(contList,DISPLAYS_LEN);

	disp_altaForzada(displaysList,1, 2678, 10, "Nacho", "Suipacha", 1);
	disp_altaForzada(displaysList,1, 1000, 11, "Esteban", "Arenales", 2);
	disp_altaForzada(displaysList,1, 1600, 12, "Martin", "Cabrera", 3);
	disp_altaForzada(displaysList,1, 4564, 13, "Juan", "Maipu", 4);
	disp_altaForzada(displaysList,1, 7890, 14, "Pedro", "Cochaabamba", 5);
	disp_altaForzada(displaysList,1, 124, 15, "Tomas", "Alsina", 6);

	cont_altaForzada(contList,2,10, 20646, 64, "Juan", 1);
	cont_altaForzada(contList,3,11, 20244, 5, "Matis", 2);
	cont_altaForzada(contList,4,12, 20345, 10, "XXX", 3);
	cont_altaForzada(contList,20,13, 20345, 30, "FFF", 4);
	cont_altaForzada(contList,30,14, 20345, 55, "AAA", 5);
	cont_altaForzada(contList,40,15, 20345, 26, "BBB", 6);
	cont_altaForzada(contList,6,10, 78566, 25, "CC", 7);
	cont_altaForzada(contList,100,13, 90734, 100, "OOO", 8);

	eleccionUsuario=menuOperaciones();

	while(llaveDeCierre!='s')
	{
		switch(eleccionUsuario)
		{
		case 1:
			posicionLibre=disp_buscarDisponible(displaysList,DISPLAYS_LEN);
			if(posicionLibre>=0)
				{
					disp_loadDisplay(&displaysList[posicionLibre]);
				}
			eleccionUsuario=menuOperaciones();
			break;
		case 2:
			idSolicitada=askForId(displaysList,DISPLAYS_LEN);
			if(idSolicitada>0)
			{
				disp_modificarPantalla(displaysList,DISPLAYS_LEN, idSolicitada);
			}
			eleccionUsuario=menuOperaciones();
			break;
		case 3:
			idSolicitada=askForId(displaysList,DISPLAYS_LEN);
			if(idSolicitada>0)
			{
				disp_remove (displaysList,DISPLAYS_LEN,idSolicitada);
			}
			eleccionUsuario=menuOperaciones();
			break;
		case 4:
			disp_imprimirCompleto(displaysList,DISPLAYS_LEN);
			idSolicitada=askForId(displaysList,DISPLAYS_LEN);
			if(idSolicitada>0)
			{
				posicionLibre=cont_buscarDisponible(contList, DISPLAYS_LEN);
				if(posicionLibre>=0)
				{
					cont_loadCont(&contList[posicionLibre], idSolicitada);
				} else
				{
					printf("No hay lugar disponible");
				}

			} else
			{
				printf("Error, dato ingresado invalido");
			}

			eleccionUsuario=menuOperaciones();
			break;
		case 5:
			cuitAux=askForCuit ();
			if(cont_buscarPorCuit (contList,DISPLAYS_LEN,cuitAux)>0)
			{
				imprimirPantallasPorCuit (contList,DISPLAYS_LEN, cuitAux,displaysList,DISPLAYS_LEN);
				idSolicitada=cont_askForId();
				if(cont_buscarPorId (contList,DISPLAYS_LEN, idSolicitada)>=0)
				{
					cont_modificarContratacion(contList,DISPLAYS_LEN, idSolicitada);
				}
			} else
			{
				printf("Error, dato ingresado invalido");
			}
			eleccionUsuario=menuOperaciones();
			break;
		case 6:
			cuitAux=askForCuit ();
			if(cont_buscarPorCuit (contList,DISPLAYS_LEN,cuitAux)>0)
			{
				cont_remove (contList,DISPLAYS_LEN,cuitAux);
			}else
			{
				printf("Error, dato ingresado invalido");
			}
			eleccionUsuario=menuOperaciones();
			break;
		case 7:
			eleccionUsuario=menuOperaciones();
			break;
		case 8:
			cont_imprimirCompleto(contList,DISPLAYS_LEN);
			eleccionUsuario=menuOperaciones();
			break;
		case 9:
			disp_imprimirCompleto(displaysList,DISPLAYS_LEN);
			eleccionUsuario=menuOperaciones();
			break;
		case 10:
			eleccionUsuario=menuOperaciones();
			break;
		case 11:
			llaveDeCierre='s';
			break;
		}

	}
	return EXIT_SUCCESS;
}
