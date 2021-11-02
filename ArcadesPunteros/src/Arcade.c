/*
 * Arcade.c
 *
 *  Created on: 16 oct 2021
 *      Author: Nacho
 */

#include "Arcade.h"
#include <limits.h>

#define ARCADE_LEN 1000
#define NATION_LEN 128
#define GAME_LEN 63
#define TIPO_MONO 1
#define TIPO_ESTEREO 2


static int dameUnIdNuevo (void);

static int dameUnIdNuevo (void)
{
	static int contador=100;
	return (contador++);
}

eArcade* arcade_nuevo (void) //MODIFICADA
{
	eArcade* pArcade=(eArcade*)malloc(sizeof(eArcade));
	return pArcade;
}


int arc_initList(eArcade *arcadeList[],int lenghtArcade) //MODIFICADA
{
	int retorno;

	retorno=-1;

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=0;
		for(int i=0;i<lenghtArcade;i++)
		{
			arcadeList[i]=NULL;
		}
	}

	return retorno;
}

int arc_loadArcade(eArcade *pArcade, int idIngresada) //MODIFICADA
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
								retorno=0;

								printf("\nArcade ingresado con éxito!\n");
						}

					}
				}
			}
		}
	}
	return retorno;

}

int arc_buscarDisponible(eArcade *arcadeList[], int lenghtArcade) //MODIFICADA
{
	int retorno;
	retorno=-1;

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=0;
		for(int i=0;i<lenghtArcade;i++)
		{
			if(arcadeList[i]==NULL)
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


int arc_buscarPorId (eArcade *arcadeList[], int lenghtArcade, int idIngresada) //MODIFICADA
{
	int retorno;
	retorno=-1;

	if(arcadeList!=NULL&&lenghtArcade>0)
	{

		for(int i=0;i<lenghtArcade;i++)
		{
			if(arcadeList[i]!=NULL)
			{

				if(arcadeList[i]->idArcade==idIngresada)
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

int arc_remove (eArcade *arcadeList[], int lenghtArcade, int idIngresada) //MODIFICADA
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
					arcadeList[posicionSolicitada]->idArcade,
					arcadeList[posicionSolicitada]->nationality,
					cadenaAux,
					arcadeList[posicionSolicitada]->numberOfPlayers,
					arcadeList[posicionSolicitada]->maximumTokens,
					arcadeList[posicionSolicitada]->idSalon,
					arcadeList[posicionSolicitada]->gameName);

					if(pedirCharSiNo(&userChoice, 's', 'n', 5, "\n\n ---------Presione [s] para confirmar o [n] para volver al menu principal---------\n",
							"Error, dato ingresado inválido\n")==0)
					{
						if(userChoice=='s')
						{
							free(arcadeList[posicionSolicitada]);
							arcadeList[posicionSolicitada]=NULL;
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



int arc_modificarArcade(eArcade *arcadeList[],int lenghtArcade, int idIngresada) //MODIFICADA
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
			if(arcadeList[posicionPedida]!=NULL)
			{
				if(idIngresada==arcadeList[posicionPedida]->idArcade)
						{

							eleccionUsuario=arc_subMenuModificaciones ();
							while(llaveDeCierre!='s')
							{
								switch (eleccionUsuario)
								{
									case 1:
										if(pedirIntIntentosRango(&cantidadJuegosAux,1, 6, 5, "Ingrese la nueva cantidad de jugadores:  ", "Error")==0)
										{
											arcadeList[posicionPedida]->numberOfPlayers=cantidadJuegosAux;
										} else
										{
											printf("Error");
										}
										eleccionUsuario=arc_subMenuModificaciones ();
										break;
									case 2:
										arc_imprimirJuegosSinRepetir(arcadeList,lenghtArcade);
										if(pedirTexto(gameAux,sizeof(gameAux), 3, "Ingrese el nuevo nombre del juego: ", "Error")==0)
										{
											posicionPedida=arc_buscarPorId (arcadeList,lenghtArcade, idIngresada);
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
			}


	}

	return retorno;

}


int arc_imprimirCompleto(eArcade *arcadeList[], int lenghtArcade) //MODIFICADA
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
			if(arcadeList[i]!=NULL)
			{
				arc_cambiarTexto (arcadeList, i, cadenaAux);

				printf("%15d %15s %15s %15d %15d %15d %25s\n",
						arcadeList[i]->idArcade,
						arcadeList[i]->nationality,
						cadenaAux,
						arcadeList[i]->numberOfPlayers,
						arcadeList[i]->maximumTokens,
						arcadeList[i]->idSalon,
						arcadeList[i]->gameName);

			}

		}

	}

	return retorno;

}



void arc_altaForzada(eArcade *pArcade,char nacionalidad[], int tipoSonido, int jugadores, int capacidad, int idSalon,char nombre[])
//MODIFICADA
{
	strncpy(pArcade->nationality,nacionalidad,sizeof(pArcade->nationality));
	pArcade->soundType=tipoSonido;
	pArcade->numberOfPlayers=jugadores;
	pArcade->maximumTokens=capacidad;
	pArcade->idSalon=idSalon;
	pArcade->idArcade=dameUnIdNuevo();
	strncpy(pArcade->gameName,nombre,sizeof(pArcade->gameName));

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

int arc_validarNombreRepetido (eArcade *arcadeList[], int lenghtArcade, char nombreJuego[]) //MODIFICADA
{
	int retorno;
	retorno=-1;

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=0;
		for(int i=0;i<lenghtArcade;i++)
		{
			if(arcadeList[i]!=NULL)
			{
				if(strncmp(arcadeList[i]->gameName,nombreJuego,63)==0)
					{
						retorno=1;
						break;

					} else
					{
						retorno=-1;
					}
			}


		}
	}

	return retorno;
}

int arc_modificarNombreRepetido(eArcade *arcadeList[], int lenghtArcade, char nombreJuego[], int posicionPedida) //MODIFICADA
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
				strncpy(arcadeList[posicionPedida]->gameName,nombreJuego,sizeof(arcadeList[posicionPedida]->gameName));
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
	}else
	{
		strncpy(arcadeList[posicionPedida]->gameName,nombreJuego,sizeof(arcadeList[posicionPedida]->gameName));
		printf("Juego modificado exitosamente.\n");
		retorno=0;
	}

	return retorno;
}


int arc_ordenarArcades (eArcade *arcadeList[], int lenghtArcade, int order) //MODIFICADA
{
	int i;
	int retorno;
	eArcade* aux;
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
					if(arcadeList[i]!=NULL&&arcadeList[j]!=NULL)
					{
						if(strncmp(arcadeList[i]->gameName,arcadeList[j]->gameName,63)>0)
						{
							aux = arcadeList[i];
							arcadeList[i] = arcadeList[j];
							arcadeList[j] = aux;
						}
					} else
					{
						continue;
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
						if(arcadeList[i]!=NULL&&arcadeList[j]!=NULL)
						{
							if(arcadeList[i]->idSalon>arcadeList[j]->idSalon)
								{
									aux = arcadeList[i];
									arcadeList[i] = arcadeList[j];
									arcadeList[j] = aux;
								}
						} else
						{
							continue;
						}



					}
				}

			}
		}


	}
	return retorno;
}

int arc_imprimirJuegosSinRepetir (eArcade *arcadeList[], int lenghtArcade) //MODIFICADA
{
	int retorno;
	retorno=-1;

	arc_ordenarArcades (arcadeList, lenghtArcade,1);

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=0;
		for(int i=0;i<lenghtArcade;i++)
		{
			if(arcadeList[i]!=NULL&&arcadeList[i+1]!=NULL)
			{
				if(strncmp(arcadeList[i]->gameName,arcadeList[i+1]->gameName,63)==0)
				{
					continue;

				}else
				{
					printf("- Nombre del juego:		%s\n\n",arcadeList[i]->gameName);
				}

			}else
			{
				continue;
			}

		}

	}


	return retorno;

}

int arc_removePorSalon (eArcade *arcadeList[], int lenghtArcade, int idIngresada) //MODIFICADA
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
			if(arcadeList[i]!=NULL)
			{
				if(idIngresada==arcadeList[i]->idSalon)
				{
					arc_cambiarTexto (arcadeList, i, cadenaAux);

					printf("%15d %15s %15s %15d %15d %15d %25s\n",
							arcadeList[i]->idArcade,
							arcadeList[i]->nationality,
							cadenaAux,
							arcadeList[i]->numberOfPlayers,
							arcadeList[i]->maximumTokens,
							arcadeList[i]->idSalon,
							arcadeList[i]->gameName);
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
								if(arcadeList[i]!=NULL)
								{
									if(idIngresada==arcadeList[i]->idSalon)
									{
										free(arcadeList[i]);
										arcadeList[i]=NULL;
									}
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

int arc_cambiarTexto (eArcade *arcadeList[], int posicion, char pTextoConvertido[]) //MODIFICADA
{
	int retorno;

	retorno=-1;
	switch(arcadeList[posicion]->soundType)
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

int arc_occupancy (eArcade *arcadeList[], int lenghtArcade, int* pNotEmpty) //MODIFICADA
{
	int retorno;
	int notEmpty;
	int i;

	retorno=-1;
	notEmpty=0;

	if(arcadeList!=NULL&&lenghtArcade>0)
		{
			retorno=0;

			for (i=0;i<lenghtArcade;i++)
			{
				if(arcadeList[i]!=NULL)
				{
					notEmpty++;
				}

			}
		}

	*pNotEmpty=notEmpty;

	return retorno;
}



///////// Setters y Getters /////////


int arc_setNationality (eArcade* pArcade, char nationality[])
{
	int retorno=-1;
	if(pArcade!=NULL)
	{
		strncpy(pArcade->nationality,nationality,sizeof(pArcade->nationality));
		retorno=0;
	}

	return retorno;
}


int arc_getNationality (eArcade* pArcade, char nationality[])
{
	int retorno=-1;
	if(pArcade!=NULL&&nationality!=NULL)
	{
		strncpy(nationality,pArcade->nationality,NATION_LEN);
		retorno=0;
	}

	return retorno;
}

int salon_setType (eSalon* pSalon, int tipo)
{
	int retorno=-1;
	if(pSalon!=NULL)
	{
		pSalon->type=tipo;
		retorno=0;
	}

	return retorno;
}


int salon_getType (eSalon* pSalon, int* tipo)
{
	int retorno=-1;
	if(pSalon!=NULL)
	{
		*tipo=pSalon->type;
		retorno=0;
	}

	return retorno;
}


int salon_setAddress (eSalon* pSalon, char direccion[])
{
	int retorno=-1;
	if(pSalon!=NULL)
	{
		strncpy(pSalon->address,direccion,sizeof(pSalon->address));
		retorno=0;
	}

	return retorno;
}


int salon_getAddress (eSalon* pSalon, char* direccion)
{
	int retorno=-1;
	if(pSalon!=NULL)
	{
		strncpy(direccion,pSalon->address,ADDRESS_LEN);
		retorno=0;
	}

	return retorno;
}




int salon_setIdSalon(eSalon* pSalon, int idSalon)
{
	int retorno=-1;
	if(pSalon!=NULL)
	{
		pSalon->idSalon=idSalon;
		retorno=0;
	}

	return retorno;
}


int salon_getIdSalon (eSalon* pSalon, int* idSalon)
{
	int retorno=-1;
	if(pSalon!=NULL)
	{
		*idSalon=pSalon->idSalon;
		retorno=0;
	}

	return retorno;
}














