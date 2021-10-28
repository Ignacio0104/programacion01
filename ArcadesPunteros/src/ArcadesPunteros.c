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
	int salonesOcupados;
	int arcadesOcupados;
	eSalon* pSalonAuxiliar;
	llaveDeCierre='n';


	eSalon* salonList [SALON_LEN];
	salon_initList(salonList,SALON_LEN);

	eArcade arcadeList[ARCADE_LEN];
	arc_initList(arcadeList,ARCADE_LEN);





	//Hardcode
/*
	eSalon* pSalonAuxiliarAltaForzada;
	pSalonAuxiliarAltaForzada=salon_nuevo;
	salon_altaForzada(pSalonAuxiliarAltaForzada,"Sacoa","Maipu 225", 1, 10, 0);


	pSalonAuxiliarAltaForzada=salon_nuevo;
	salon_altaForzada(pSalonAuxiliarAltaForzada,"Showcase","Peatonal 14", 2, 11, 1);

	pSalonAuxiliarAltaForzada=salon_nuevo;

	salon_altaForzada(pSalonAuxiliarAltaForzada,"Juguelandia","Paseo 15", 1, 12, 2);

	pSalonAuxiliarAltaForzada=salon_nuevo;

	salon_altaForzada(pSalonAuxiliarAltaForzada,"Travalcase","Guemes 678", 1, 13, 3);

	pSalonAuxiliarAltaForzada=salon_nuevo;

	salon_altaForzada(pSalonAuxiliarAltaForzada,"Fichines","Arenales 1965", 2, 14, 4);

	pSalonAuxiliarAltaForzada=salon_nuevo;

	salon_altaForzada(pSalonAuxiliarAltaForzada,"Juego.com","Alsina 500", 2, 15, 5);


	arc_altaForzada(arcadeList,"USA", 1, 4, 2000, 11,"WonderBoy",1000, 0);
	arc_altaForzada(arcadeList,"Tokyo", 2, 5, 3000, 11,"Sonic",1001, 1);
	arc_altaForzada(arcadeList,"Alemania", 4, 1, 1500, 11,"Pacman",1002, 2);
	arc_altaForzada(arcadeList,"Holanda", 1, 1, 2600, 11,"Daytona",1006, 6);
	arc_altaForzada(arcadeList,"Argentina", 1, 3, 2100, 11,"Pacman",1004 , 4);
	arc_altaForzada(arcadeList,"USA", 2, 6, 100, 11,"Street Fighter",1007, 7);
	arc_altaForzada(arcadeList,"Rusia", 2, 4, 1000, 11,"Metal Slug",1005, 5);
	arc_altaForzada(arcadeList,"Rusia", 2, 3, 1000, 11,"Megaman",1012, 12);
	arc_altaForzada(arcadeList,"Portugal", 2, 3, 3000, 11,"Booger Man",1008, 8);
	arc_altaForzada(arcadeList,"Finlandia", 2, 2, 1500, 14,"Pacman",1009, 9);
	arc_altaForzada(arcadeList,"USA", 1, 3, 3500, 14,"Prince of Persia",1010, 10);
	arc_altaForzada(arcadeList,"USA", 1, 3, 3500, 13,"Pacman",1003, 3);
	arc_altaForzada(arcadeList,"China", 2, 4, 2100, 13,"Capcom",1012,20);
	arc_altaForzada(arcadeList,"China", 2, 4, 2100, 13,"Capcom",1013,21);
	arc_altaForzada(arcadeList,"China", 2, 4, 2100, 13,"Capcom",1014,23);
	arc_altaForzada(arcadeList,"China", 2, 4, 2100, 13,"Capcom",1015,25);*/

	eleccionUsuario=menuOperaciones();

	while(llaveDeCierre!='s')
	{
		switch(eleccionUsuario)
		{
		case 1:
			posicionLibre=salon_buscarDisponible(salonList,SALON_LEN);
			if(posicionLibre>=0)
				{
					pSalonAuxiliar=salon_nuevo ();
					if(pSalonAuxiliar!=NULL)
					{
						salon_loadSalon(pSalonAuxiliar);

						salonList[posicionLibre]=pSalonAuxiliar;
					}

				} else
				{
					printf("No hay mas lugar");
				}
			eleccionUsuario=menuOperaciones();
			break;
		case 2:
			salon_occupancy (salonList,SALON_LEN, &salonesOcupados);
			if(salonesOcupados>0)
			{
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
			} else
			{
				printf("\nNo hay ningún salón cargado para borrar\n");
			}

			eleccionUsuario=menuOperaciones();
			break;
		case 3:
			salon_occupancy (salonList,SALON_LEN, &salonesOcupados);
			if(salonesOcupados>0)
			{
				salon_imprimirCompleto(salonList,SALON_LEN);
			} else
			{
				printf("\nNo hay salones para mostrar");
			}
			eleccionUsuario=menuOperaciones();
			break;
		case 4:
			salon_occupancy(salonList,SALON_LEN, &salonesOcupados);
			if(salonesOcupados>0)
			{
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
			}else
			{
				printf("\nNo hay salones cargados. Favor ingresar un salón y luego cargar el arcade\n");
			}
			eleccionUsuario=menuOperaciones();
			break;
		case 5:
			arc_occupancy (arcadeList, ARCADE_LEN, &arcadesOcupados);
			if(arcadesOcupados>0)
			{
				arc_imprimirCompleto(arcadeList, ARCADE_LEN);
				idSolicitada=arc_askForId();
				if(idSolicitada>0)
				{
					arc_modificarArcade(arcadeList,ARCADE_LEN, idSolicitada);
				} else
				{
					printf("La ID no coincide con ningún arcade");
				}
			}else
			{
				printf("\nNo hay arcades cargados en el sistema\n");
			}
			eleccionUsuario=menuOperaciones();
			break;
		case 6:
			arc_occupancy (arcadeList, ARCADE_LEN, &arcadesOcupados);
			if(arcadesOcupados>0)
			{
				arc_imprimirCompleto(arcadeList, ARCADE_LEN);
				idSolicitada=arc_askForId();
				if(idSolicitada>0)
				{
					arc_remove (arcadeList,ARCADE_LEN,idSolicitada);
				}
			}else
			{
				printf("\nNo hay arcades cargados en el sistema\n");
			}
			eleccionUsuario=menuOperaciones();
			break;
		case 7:
			arc_occupancy (arcadeList, ARCADE_LEN, &arcadesOcupados);
			if(arcadesOcupados>0)
			{
				arc_imprimirCompleto(arcadeList, ARCADE_LEN);
			}else
			{
				printf("\nNo hay arcades cargados en el sistema\n");
			}
			eleccionUsuario=menuOperaciones();
			break;
		case 8:
			arc_occupancy (arcadeList, ARCADE_LEN, &arcadesOcupados);
			if(arcadesOcupados>0)
			{
				arc_imprimirJuegosSinRepetir (arcadeList, ARCADE_LEN);
			}else
			{
				printf("\nNo hay juegos cargados en el sistema\n");
			}
			eleccionUsuario=menuOperaciones();
			break;
		case 9:
			salon_occupancy (salonList,SALON_LEN, &salonesOcupados);
			arc_occupancy (arcadeList, ARCADE_LEN, &arcadesOcupados);
			if(salonesOcupados>0&&arcadesOcupados>0)
			{
				subEleccionUsuario=info_subMenuReports ();
				info_imprimirInformes (arcadeList, ARCADE_LEN,salonList,SALON_LEN, subEleccionUsuario);
			}else
			{
				printf("\nError, faltan cargar datos. Favor realizar la carga completa de por lo menos 1 salon y 1 arcade");
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
