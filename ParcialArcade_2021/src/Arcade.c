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

#define TIPO_MONO 1
#define TIPO_ESTEREO 2

static int arc_cambiarTexto (eArcade *arcadeList, int posicion, char pTextoConvertido[]);

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
																		"2)Estéreo\n", "Error")==0)
			{
				if(pedirIntIntentosRango(&jugadoresAux,1, 6, 5, "Ingrese la cantidad de jugadores: \n", "Error")==0)
				{
					if(pedirIntIntentosRango(&fichasAux,1, 10000, 5, "Ingrese la capacidad máxima de fichas: \n", "Error")==0)
					{
						if(pedirTexto(gameAux,sizeof(gameAux), 3, "Ingrese el nombre del juego: ", "Error")==0)
						{
								strncpy(pArcade->nationality,nationalityAux,sizeof(pArcade->nationality));
								pArcade->soundType=typeAux;
								pArcade->numberOfPlayers=jugadoresAux;
								pArcade->maximumTokens=fichasAux;
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
	char cadenaAux[32];

	retorno=-1;

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=-2;

		posicionSolicitada=arc_buscarPorId (arcadeList,lenghtArcade, idIngresada);

		if(posicionSolicitada>=0)
		{

			arc_cambiarTexto (arcadeList, posicionSolicitada, cadenaAux);

			printf("\nSe va a eliminar el siguiente arcade: \n\n");
			printf("%15s %15s %15s %15s %15s %15s %15s\n\n","ID del Arcade", "Nacionalidad","Sonido","Jugadores","Fichas máximas","ID de Salon", "Juego");
			printf("%15d %15s %15s %15d %15d %15d %15s\n",
					arcadeList[posicionSolicitada].idArcade,
					arcadeList[posicionSolicitada].nationality,
					cadenaAux,
					arcadeList[posicionSolicitada].numberOfPlayers,
					arcadeList[posicionSolicitada].maximumTokens,
					arcadeList[posicionSolicitada].idSalon,
					arcadeList[posicionSolicitada].gameName);

					if(pedirCharSiNo(&userChoice, 's', 'n', 5, "\n\n ---------Presione [s] para confirmar o [n] para volver al menu principal---------\n",
							"Error, dato ingresado inválido\n")==0)
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
								printf("No se borrará el Arcade. Volviendo al menú principal...\n");
								retorno=0;
							}
						}

					}
				}

			}

		if(retorno==-2)
		{
			printf("\nNo se pudo realizar la acción\n");
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
										printf("Volviendo al menú....");
										llaveDeCierre='s';
										break;

								}
							}


						} else
						{
							printf("Aca está fallando");
						}

					} else
					{
						printf("ID ingresada no coincide con ningún Arcade\n");
					}
			}printf("ID ingresada no coincide con ningún Arcade\n");


	}

	return retorno;

}

int arc_imprimirCompleto(eArcade *arcadeList, int lenghtArcade)
{
	int retorno;
	retorno=-1;
	char cadenaAux[32];

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		printf("%15s %15s %15s %15s %15s %15s %25s\n\n","ID del Arcade", "Nacionalidad","Sonido","Jugadores","Fichas máximas","ID de Salon", "Juego");
		retorno=0;
		for(int i=0;i<lenghtArcade;i++)
		{

			if(arcadeList[i].flagEmpty==ACTIVO)
			{
				arc_cambiarTexto (arcadeList, i, cadenaAux);


				printf("%15d %15s %15s %15d %15d %15d %25s\n",
						arcadeList[i].idArcade,
						arcadeList[i].nationality,
						cadenaAux,
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

				printf("- Nombre del juego:		%s\n",arcadeList[i].gameName);
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

	printf("Elija qué opción desea modificar: \n"
			"	1)Cantidad de jugadores\n"
			"	2)Nombre del juego\n"
			"	3)Volver al menú\n");

	pedirIntIntentosRango(&eleccion, 1, 3, 20, "Ingrese aquí su elección", "Error");

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
		printf("\nEste juego ya se encuentra ingresado en el sistema. Desea volver a cargarlo?");

		if(pedirCharSiNo(&userChoice, 's', 'n', 5, "\nPresione [s] para confirmar o [n] para volver al menu principal\n",
				"Error, dato ingresado inválido\n")==0)
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
					printf("No se modificará el juego. Volviendo al menú principal...\n");
					retorno=0;
				}
			}

		}
	}

	return retorno;
}

int arc_ordenarArcades (eArcade *arcadeList, int lenghtArcade, int order)
{
	int i;
	int retorno;
	eArcade aux;
	int j;

	retorno=-1;

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=0;
		if(order==1)
		{
			for(i=0;i<lenghtArcade-1;i++)
			{
				for(j=i+1;j<lenghtArcade;j++)
				{
					if(strcmp(arcadeList[i].gameName,arcadeList[j].gameName)>0)
					{
						aux = arcadeList[i];
						arcadeList[i] = arcadeList[j];
						arcadeList[j] = aux;
					}

				}
			}

		}else

		{
			if(order==2)
			{
				for(i=0;i<lenghtArcade-1;i++)
				{
					for(j=i+1;j<lenghtArcade;j++)
					{
						if(arcadeList[i].idSalon>arcadeList[j].idSalon)
						{
							aux = arcadeList[i];
							arcadeList[i] = arcadeList[j];
							arcadeList[j] = aux;
						}

					}
				}

			}
		}


	}
	return retorno;
}

int arc_imprimirJuegosSinRepetir (eArcade *arcadeList, int lenghtArcade)
{
	int retorno;
	retorno=-1;

	arc_ordenarArcades (arcadeList, lenghtArcade,1);

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=0;
		for(int i=0;i<lenghtArcade;i++)
		{
			if(arcadeList[i].flagEmpty==ACTIVO)
			{
				if(strncmp(arcadeList[i].gameName,arcadeList[i+1].gameName,63)==0)
				{
					continue;

				}else
				{
					printf("- Nombre del juego:		%s\n\n",arcadeList[i].gameName);
				}

			}

		}

	}


	return retorno;

}

int arc_removePorSalon (eArcade *arcadeList, int lenghtArcade, int idIngresada)
{
	int retorno;
	char userChoice;
	int contador;
	char cadenaAux[32];

	contador=0;

	retorno=-2;

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=0;

		printf("\n >>>Se van a eliminar a los siguientes arcades asociados: <<< \n");

		for(int i=0;i<lenghtArcade;i++)
		{
			if(arcadeList[i].flagEmpty==ACTIVO)
			{
				if(idIngresada==arcadeList[i].idSalon)
				{
					arc_cambiarTexto (arcadeList, i, cadenaAux);

					printf("%15d %15s %15s %15d %15d %15d %25s\n",
							arcadeList[i].idArcade,
							arcadeList[i].nationality,
							cadenaAux,
							arcadeList[i].numberOfPlayers,
							arcadeList[i].maximumTokens,
							arcadeList[i].idSalon,
							arcadeList[i].gameName);
					contador++;
				}
			}

		} if(contador==0)
		{
			printf("\nEste salon no tiene ningún arcade asociado\n");
			retorno=0;
		}

		if(contador>0)
		{
			if(pedirCharSiNo(&userChoice, 's', 'n', 5, "---------Presione [s] para confirmar o [n] para volver al menu principal---------\n",
							"Error, dato ingresado inválido\n")==0)
					{
						if(userChoice=='s')
						{
							for(int i=0;i<lenghtArcade;i++)
							{
								if(idIngresada==arcadeList[i].idSalon)
								{
									arcadeList[i].flagEmpty=INACTIVO;
								}

							}

							printf("Arcades borrados exitosamente.\n");
							retorno=0;
						} else
						{
							if(userChoice=='n')
							{
								printf("No se borrará el arcade. Volviendo al menú principal...\n");
								retorno=-1;
							}
						}

					}

				}


			}

		if(retorno==-2)
		{
			printf("\nNo se pudo realizar la acción\n");
		}

	return retorno;

}

int arc_cambiarTexto (eArcade *arcadeList, int posicion, char pTextoConvertido[])
{
	int retorno;

	retorno=-1;
	switch(arcadeList[posicion].soundType)
	{
		case TIPO_MONO:
			retorno=0;
			strncpy(pTextoConvertido,"Mono",32);
			break;
		case TIPO_ESTEREO:
			strncpy(pTextoConvertido,"Estereo",32);
			retorno=0;
			break;
	}

	return retorno;
}

int arc_occupancy (eArcade *arcadeList, int lenghtArcade, int* pNotEmpty)
{
	int retorno;
	int empty;
	int notEmpty;
	int i;

	retorno=-1;
	empty=0;
	notEmpty=0;

	if(arcadeList!=NULL&&lenghtArcade>0)
		{
			retorno=0;

			for (i=0;i<lenghtArcade;i++)
			{
				if(arcadeList[i].flagEmpty==ACTIVO)
				{
					notEmpty++;
				}

			}
		}

	*pNotEmpty=notEmpty;

	return retorno;
}







