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
	eArcade* pArcadeAuxiliar;
	llaveDeCierre='n';


	eSalon* salonList [SALON_LEN];
	salon_initList(salonList,SALON_LEN);

	eArcade* arcadeList[ARCADE_LEN];
	arc_initList(arcadeList,ARCADE_LEN);



	//Hardcodeo Salones

	eSalon* pSalonAuxiliarAltaForzada;

	pSalonAuxiliarAltaForzada=salon_nuevo();
	salon_altaForzada(pSalonAuxiliarAltaForzada,"Sacoa","Maipu 225", 1);
	salonList[0]=pSalonAuxiliarAltaForzada;

	pSalonAuxiliarAltaForzada=salon_nuevo();
	salon_altaForzada(pSalonAuxiliarAltaForzada,"Showcase","Peatonal 14", 2);
	salonList[5]=pSalonAuxiliarAltaForzada;


	pSalonAuxiliarAltaForzada=salon_nuevo();
	salon_altaForzada(pSalonAuxiliarAltaForzada,"Juguelandia","Paseo 15", 1);
	salonList[1]=pSalonAuxiliarAltaForzada;

	pSalonAuxiliarAltaForzada=salon_nuevo();
	salon_altaForzada(pSalonAuxiliarAltaForzada,"Travalcase","Guemes 678", 1);
	salonList[2]=pSalonAuxiliarAltaForzada;

	pSalonAuxiliarAltaForzada=salon_nuevo();
	salon_altaForzada(pSalonAuxiliarAltaForzada,"Fichines","Arenales 1965", 2);
	salonList[3]=pSalonAuxiliarAltaForzada;

	pSalonAuxiliarAltaForzada=salon_nuevo();
	salon_altaForzada(pSalonAuxiliarAltaForzada,"Juego.com","Alsina 500", 2);
	salonList[4]=pSalonAuxiliarAltaForzada;

	//Hardcodeo Arcades
	pArcadeAuxiliar=arcade_nuevo();
	arc_altaForzada(pArcadeAuxiliar,"USA", 1, 4, 2000, 1,"WonderBoy");
	arcadeList[0]=pArcadeAuxiliar;

	pArcadeAuxiliar=arcade_nuevo();
	arc_altaForzada(pArcadeAuxiliar,"Tokyo", 2, 5, 3000, 1,"Sonic");
	arcadeList[1]=pArcadeAuxiliar;

	pArcadeAuxiliar=arcade_nuevo();
	arc_altaForzada(pArcadeAuxiliar,"Alemania", 4, 1, 1500, 1,"Pacman");
	arcadeList[2]=pArcadeAuxiliar;

	pArcadeAuxiliar=arcade_nuevo();
	arc_altaForzada(pArcadeAuxiliar,"Holanda", 1, 1, 2600, 1,"Daytona");
	arcadeList[3]=pArcadeAuxiliar;

	pArcadeAuxiliar=arcade_nuevo();
	arc_altaForzada(pArcadeAuxiliar,"Argentina", 1, 3, 2100, 1,"Pacman");
	arcadeList[4]=pArcadeAuxiliar;

	pArcadeAuxiliar=arcade_nuevo();
	arc_altaForzada(pArcadeAuxiliar,"USA", 2, 6, 100, 2,"Street Fighter");
	arcadeList[5]=pArcadeAuxiliar;

	pArcadeAuxiliar=arcade_nuevo();
	arc_altaForzada(pArcadeAuxiliar,"Rusia", 2, 4, 1000, 3,"Metal Slug");
	arcadeList[6]=pArcadeAuxiliar;

	pArcadeAuxiliar=arcade_nuevo();
	arc_altaForzada(pArcadeAuxiliar,"Rusia", 2, 3, 1000, 2,"Megaman");
	arcadeList[7]=pArcadeAuxiliar;

	pArcadeAuxiliar=arcade_nuevo();
	arc_altaForzada(pArcadeAuxiliar,"Portugal", 2, 3, 3000, 3,"Booger Man");
	arcadeList[8]=pArcadeAuxiliar;

	pArcadeAuxiliar=arcade_nuevo();
	arc_altaForzada(pArcadeAuxiliar,"Finlandia", 2, 2, 1500, 4,"Pacman");
	arcadeList[9]=pArcadeAuxiliar;

	pArcadeAuxiliar=arcade_nuevo();
	arc_altaForzada(pArcadeAuxiliar,"USA", 1, 3, 3500, 4,"Prince of Persia");
	arcadeList[10]=pArcadeAuxiliar;

	eleccionUsuario=menuOperaciones();

	while(llaveDeCierre!='s')
	{
		switch(eleccionUsuario)
		{
		case 1:
			posicionLibre=salon_buscarDisponible(salonList,SALON_LEN);
			if(posicionLibre>=0)
				{
					pSalonAuxiliar=salon_nuevo();
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
							pArcadeAuxiliar=arcade_nuevo ();
							if(pArcadeAuxiliar!=NULL)
							{
								arc_loadArcade(pArcadeAuxiliar,idSolicitada);
								arcadeList[posicionLibre]=pArcadeAuxiliar;
							}

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
