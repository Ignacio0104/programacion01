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
#define DISPLAYS_LEN 100
#define CONTRATACIONES_LEN 1000


int main(void) {

	setbuf(stdout,NULL);

	int posicionLibre;
	int idSolicitada;
	int posicionSolicitada;
	int eleccionUsuario;
	float cuitAux;
	char llaveDeCierre;
	float totalFacturacion;
	llaveDeCierre='n';

	eDisplay displaysList [DISPLAYS_LEN];
	eContratacion contList [CONTRATACIONES_LEN];

	disp_initList(displaysList,DISPLAYS_LEN);
	cont_initList(contList,CONTRATACIONES_LEN);

	disp_altaForzada(displaysList,1, 100, 10, "Centro", "Suipacha", 1);
	disp_altaForzada(displaysList,1, 200, 11, "Shopping", "Arenales", 2);
	disp_altaForzada(displaysList,1, 300, 12, "Jumbo", "Cabrera", 3);
	disp_altaForzada(displaysList,1, 50, 13, "Microcentro", "Maipu", 4);
	disp_altaForzada(displaysList,1, 40, 14, "Mega Pantalla", "Cochabamba", 5);
	disp_altaForzada(displaysList,1, 20, 15, "Cine", "Alsina", 6);

	cont_altaForzada(contList,2,10, 20646, 30, "Video.avi", 1);
	cont_altaForzada(contList,3,11, 20244, 15, "Pelicula.avi", 2);
	cont_altaForzada(contList,4,12, 20345, 20, "Musica.avi", 3);
	cont_altaForzada(contList,20,13, 20345, 30, "Solos.avi", 4);
	cont_altaForzada(contList,30,14, 20345, 40, "Publicidad.avi", 5);
	cont_altaForzada(contList,40,15, 78566, 60, "Animales.avi", 6);
	cont_altaForzada(contList,6,10, 78566, 25, "Avengers.avi", 7);
	cont_altaForzada(contList,100,13, 78566, 100, "Museo.avi", 8);

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
			idSolicitada=disp_askForId();
			if(idSolicitada>=0)
			{
				disp_modificarPantalla(displaysList,DISPLAYS_LEN, idSolicitada);
			}
			eleccionUsuario=menuOperaciones();
			break;
		case 3:
			idSolicitada=disp_askForId();
			if(idSolicitada>=0)
			{
				disp_remove (displaysList,DISPLAYS_LEN,idSolicitada);
			}
			eleccionUsuario=menuOperaciones();
			break;
		case 4:
			disp_imprimirCompleto(displaysList,DISPLAYS_LEN);
			idSolicitada=disp_askForId();
			if(idSolicitada>0)
			{
				if(disp_buscarPorId(displaysList,DISPLAYS_LEN, idSolicitada)>0)
				{
					posicionLibre=cont_buscarDisponible(contList, CONTRATACIONES_LEN);
					if(posicionLibre>=0)
					{
						cont_loadCont(&contList[posicionLibre], idSolicitada);
					} else
					{
						printf("No hay lugar disponible");
					}
				} else
				{
					printf("ID no coincide con ninguna pantalla");
				}

			} else
			{
				printf("Error, dato ingresado invalido");
			}

			eleccionUsuario=menuOperaciones();
			break;
		case 5:
			cuitAux=cont_askForCuit ();
			if(cont_buscarPorCuit (contList,CONTRATACIONES_LEN,cuitAux)>=0)
			{
				imprimirPantallasPorCuit (contList,CONTRATACIONES_LEN, cuitAux,displaysList,DISPLAYS_LEN);
				idSolicitada=disp_askForId();
				posicionSolicitada=cont_buscarPorId (contList,CONTRATACIONES_LEN, idSolicitada);
				if(posicionSolicitada>=0)
				{
					cont_modificarContratacion(contList,CONTRATACIONES_LEN, idSolicitada);
				}
			} else
			{
				printf("Error, dato ingresado invalido");
			}
			eleccionUsuario=menuOperaciones();
			break;
		case 6:
			cuitAux=cont_askForCuit ();
			if(cont_buscarPorCuit (contList,CONTRATACIONES_LEN,cuitAux)>=0)
			{
				imprimirPantallasPorCuit (contList,CONTRATACIONES_LEN, cuitAux,displaysList,DISPLAYS_LEN);
				idSolicitada=disp_askForId();
				if(cont_buscarPorId (contList,CONTRATACIONES_LEN, idSolicitada)>=0)
				{
					cont_remove (contList,CONTRATACIONES_LEN, idSolicitada);
				}
			} else
			{
				printf("Error, dato ingresado invalido");
			}
			eleccionUsuario=menuOperaciones();
			break;
		case 7:
			cuitAux=cont_askForCuit ();
			if(cont_buscarPorCuit (contList,CONTRATACIONES_LEN,cuitAux)>=0)
			{
				totalFacturacion=calcularFacturacionPorCuit (contList,CONTRATACIONES_LEN, cuitAux,displaysList,DISPLAYS_LEN);

				printf("El total a pagar es de %f",totalFacturacion);

			} else
			{
				printf("Error, dato ingresado invalido");
			}
			eleccionUsuario=menuOperaciones();
			break;
		case 8:
			cont_imprimirCompleto(contList,CONTRATACIONES_LEN);
			eleccionUsuario=menuOperaciones();
			break;
		case 9:
			disp_imprimirCompleto(displaysList,DISPLAYS_LEN);
			eleccionUsuario=menuOperaciones();
			break;
		case 10:
			imprimirFacturacionPorCliente (contList,CONTRATACIONES_LEN,displaysList,DISPLAYS_LEN);
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
