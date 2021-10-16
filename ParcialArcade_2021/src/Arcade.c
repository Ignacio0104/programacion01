/*
 * Arcade.c
 *
 *  Created on: 16 oct 2021
 *      Author: Nacho
 */

#include "Arcade.h"
#include <limits.h>
#define INACTIVO  1
#define ACTIVO  0
#define ARCADE_LEN 1000



static int dameUnIdNuevo (void);

static int dameUnIdNuevo (void)
{
	static int contador=100;
	return (contador++);
}


int arc_initList(eArcade *arcadeList,int lenghtArcade)
{
	int retorno;

	retorno=-1;

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=0;
		for(int i=0;i<lenghtArcade;i++)
		{
			arcadeList[i].flagEmpty=INACTIVO;
		}
	}

	return retorno;
}

int arc_loadArcade(eArcade *pArcade, int idIngresada)
{
	int retorno;

	retorno=-1;

	char nationalityAux[128];
	int typeAux;
	int jugadoresAux;
	int fichasAux;
	char gameAux[63];



	if(pArcade!=NULL)
	{
		if(pedirTexto(nationalityAux,sizeof(nationalityAux), 3, "Ingrese la nacionalidad del arcade: ", "Error")==0)
		{
			if(pedirIntIntentosRango(&typeAux,1, 2, 5, "Ingrese el tipo de sonido:\n"
																		"1)Mono\n"
																		"2)Est�reo\n", "Error")==0)
			{
				if(pedirIntIntentosRango(&jugadoresAux,1, 6, 5, "Ingrese la cantidad de jugadores: \n", "Error")==0)
				{
					if(pedirIntIntentosRango(&fichasAux,1, 3000, 5, "Ingrese la capacidad m�xima de fichas: \n", "Error")==0)
					{
						if(pedirTexto(gameAux,sizeof(gameAux), 3, "Ingrese el nombre del juego: ", "Error")==0)
						{
								strncpy(pArcade->nationality,nationalityAux,sizeof(pArcade->nationality));
								pArcade->soundType=typeAux;
								pArcade->numberOfPlayers=jugadoresAux;
								pArcade->maximumTokens=fichasAux;;
								pArcade->idSalon=idIngresada;
								strncpy(pArcade->gameName,gameAux,sizeof(pArcade->gameName));
								pArcade->idArcade=dameUnIdNuevo();
								pArcade->flagEmpty=ACTIVO;
								retorno=0;
						}

					}
				}
			}
		}
	}
	return retorno;

}

int arc_buscarDisponible(eArcade *arcadeList, int lenghtArcade)
{
	int retorno;
	retorno=-1;

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=0;
		for(int i=0;i<lenghtArcade;i++)
		{
			if(arcadeList[i].flagEmpty==INACTIVO)
			{
				retorno=i;
				break;
			} else
			{
				retorno=-2;
			}

		}

	}

	return retorno;

}

int arc_askForId (void)
{
	int retorno;
	int requestedId;

	if(pedirIntIntentosRango(&requestedId, 0, INT_MAX, 3, "Ingrese el ID del arcade: ", "Error, dato ingresado invalido")==0)
	{
		retorno=requestedId;
	} else
	{
		retorno=-2;
	}


	return retorno;
}


int arc_buscarPorId (eArcade *arcadeList, int lenghtArcade, int idIngresada)
{
	int retorno;
	retorno=-1;

	if(arcadeList!=NULL&&lenghtArcade>0)
	{

		for(int i=0;i<lenghtArcade;i++)
		{
			if(arcadeList[i].idArcade==idIngresada)
			{

				if(arcadeList[i].flagEmpty==ACTIVO)
				{
					retorno=i;
					break;
				}

			} else
			{
				retorno=-1;
			}

		}
	}

	return retorno;
}

int arc_remove (eArcade *arcadeList, int lenghtArcade, int idIngresada)
{
	int retorno;
	char userChoice;
	int posicionSolicitada;

	retorno=-1;

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=-2;

		posicionSolicitada=arc_buscarPorId (arcadeList,lenghtArcade, idIngresada);

		if(posicionSolicitada>=0)
		{
			printf("\nSe va a eliminar el siguiente arcade: \n\n"
							"ID del Arcade: %d. Nacionalidad: %s. Tipo de Sonido: %d. Cantidad de Jugadores: %d. Capacidad m�xima de fichas: %d.  "
							"ID del Salon: %d Nombre del juego %s\n\n",
							arcadeList[posicionSolicitada].idArcade,
							arcadeList[posicionSolicitada].nationality,
							arcadeList[posicionSolicitada].soundType,
							arcadeList[posicionSolicitada].numberOfPlayers,
							arcadeList[posicionSolicitada].maximumTokens,
							arcadeList[posicionSolicitada].idSalon,
							arcadeList[posicionSolicitada].gameName);

					if(pedirCharSiNo(&userChoice, 's', 'n', 5, "Presione [s] para confirmar o [n] para volver al menu principal\n",
							"Error, dato ingresado inv�lido\n")==0)
					{
						if(userChoice=='s')
						{
							arcadeList[posicionSolicitada].flagEmpty=INACTIVO;
							printf("Arcade borrado exitosamente.\n");
							retorno=0;
						} else
						{
							if(userChoice=='n')
							{
								printf("No se borrar� el Arcade. Volviendo al men� principal...\n");
								retorno=0;
							}
						}

					}
				}

			}

		if(retorno==-2)
		{
			printf("\nNo se pudo realizar la acci�n\n");
		}

	return retorno;

}


int arc_modificarArcade(eArcade *arcadeList,int lenghtArcade, int idIngresada)
{
	int retorno;
	int posicionPedida;
	int cantidadJuegosAux;
	int eleccionUsuario;
	char gameAux[63];
	char llaveDeCierre='n';

	retorno=-1;
	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=0;
		posicionPedida=arc_buscarPorId (arcadeList,lenghtArcade, idIngresada);
		if(posicionPedida>=0)
		{
			if(idIngresada==arcadeList[posicionPedida].idArcade)
			{
				if(arcadeList[posicionPedida].flagEmpty==ACTIVO)
						{

							eleccionUsuario=arc_subMenuModificaciones ();
							while(llaveDeCierre!='s')
							{
								switch (eleccionUsuario)
								{
									case 1:
										if(pedirIntIntentosRango(&cantidadJuegosAux,1, 6, 5, "Ingrese la nueva cantidad de jugadores:  ", "Error")==0)
										{
											arcadeList[posicionPedida].numberOfPlayers=cantidadJuegosAux;
										} else
										{
											printf("Error");
										}
										eleccionUsuario=arc_subMenuModificaciones ();
										break;
									case 2:
										arc_imprimirJuegos(arcadeList,lenghtArcade);
										if(pedirTexto(gameAux,sizeof(gameAux), 3, "Ingrese el nuevo nombre del juego: ", "Error")==0)
										{
											arc_modificarNombreRepetido (arcadeList,lenghtArcade, gameAux, posicionPedida);

										} else
										{
											printf("Error");
										}
										eleccionUsuario=arc_subMenuModificaciones();
										break;
									case 3:
										printf("Volviendo al men�....");
										llaveDeCierre='s';
										break;

								}
							}


						} else
						{
							printf("Aca est� fallando");
						}

					} else
					{
						printf("ID ingresada no coincide con ning�n Arcade\n");
					}
			}


	}

	return retorno;

}

int arc_imprimirCompleto(eArcade *arcadeList, int lenghtArcade)
{
	int retorno;
	retorno=-1;

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=0;
		for(int i=0;i<lenghtArcade;i++)
		{

			if(arcadeList[i].flagEmpty==ACTIVO)
			{

				printf("ID del Arcade: %d. Nacionalidad: %s. Tipo de Sonido: %d. Cantidad de Jugadores: %d. Capacidad m�xima de fichas: %d.  "
						"ID del Salon: %d Nombre del juego %s\n\n",
						arcadeList[i].idArcade,
						arcadeList[i].nationality,
						arcadeList[i].soundType,
						arcadeList[i].numberOfPlayers,
						arcadeList[i].maximumTokens,
						arcadeList[i].idSalon,
						arcadeList[i].gameName);

			}

		}

	}

	return retorno;

}

int arc_imprimirJuegos(eArcade *arcadeList, int lenghtArcade)
{
	int retorno;
	retorno=-1;

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=0;
		for(int i=0;i<lenghtArcade;i++)
		{

			if(arcadeList[i].flagEmpty==ACTIVO)
			{

				printf("Nombre del juego %s\n\n",arcadeList[i].gameName);

			}

		}

	}

	return retorno;

}





void arc_altaForzada(eArcade *pArcade,char nacionalidad[], int tipoSonido, int jugadores, int capacidad, int idSalon,char nombre[], int idArcade, int indice)
{

	strncpy(pArcade[indice].nationality,nacionalidad,sizeof(pArcade[indice].nationality));
	pArcade[indice].soundType=tipoSonido;
	pArcade[indice].numberOfPlayers=jugadores;
	pArcade[indice].maximumTokens=capacidad;
	pArcade[indice].idSalon=idSalon;
	pArcade[indice].idArcade=idArcade;
	strncpy(pArcade[indice].gameName,nombre,sizeof(pArcade[indice].gameName));
	pArcade[indice].flagEmpty=ACTIVO;

}

int arc_subMenuModificaciones (void)
{
	int eleccion;

	printf("Elija qu� opci�n desea modificar: \n"
			"1)Cantidad de jugadores\n"
			"2)Nombre del juego\n"
			"3)Volver al men�\n");

	pedirIntIntentosRango(&eleccion, 1, 3, 20, "Ingrese aqu� su elecci�n", "Error");

	return eleccion;
}

int arc_validarNombreRepetido (eArcade *arcadeList, int lenghtArcade, char nombreJuego[])
{
	int retorno;
	retorno=-1;

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=0;
		for(int i=0;i<lenghtArcade;i++)
		{
			if(strncmp(arcadeList[i].gameName,nombreJuego,sizeof(arcadeList[i].gameName))==0)
			{
				retorno=1;
				break;

			} else
			{
				retorno=-1;
			}

		}
	}

	return retorno;
}

int arc_modificarNombreRepetido(eArcade *arcadeList, int lenghtArcade, char nombreJuego[], int posicionPedida)
{
	int retorno;
	char userChoice;
	retorno=-1;

	if(arc_validarNombreRepetido(arcadeList,lenghtArcade,nombreJuego)==1)
	{
		printf("Este juego ya se encuentra ingresado en el sistema. Desea volver a cargarlo?");

		if(pedirCharSiNo(&userChoice, 's', 'n', 5, "Presione [s] para confirmar o [n] para volver al menu principal\n",
				"Error, dato ingresado inv�lido\n")==0)
		{
			if(userChoice=='s')
			{
				strncpy(arcadeList[posicionPedida].gameName,nombreJuego,sizeof(arcadeList[posicionPedida].gameName));
				printf("Juego modificado exitosamente.\n");
				retorno=0;
			} else
			{
				if(userChoice=='n')
				{
					printf("No se modificar� el juego. Volviendo al men� principal...\n");
					retorno=0;
				}
			}

		}
	}

	return retorno;
}



