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
	int idArcadeAux;


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
								idArcadeAux=dameUnIdNuevo();
								arc_setNationality (pArcade,nationalityAux);
								arc_setType(pArcade,typeAux);
								arc_setNumPlayers(pArcade,jugadoresAux);
								arc_setMaxTokens(pArcade,fichasAux);
								arc_setIdSalon(pArcade,idIngresada);
								arc_setGameName(pArcade,gameAux);
								arc_setIdArcade(pArcade,idArcadeAux);
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
	int idArcadeAux;
	retorno=-1;

	if(arcadeList!=NULL&&lenghtArcade>0)
	{

		for(int i=0;i<lenghtArcade;i++)
		{
			if(arcadeList[i]!=NULL)
			{
				arc_getIdArcade(arcadeList[i],&idArcadeAux);

				if(idArcadeAux==idIngresada)
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

	char nationalityAux[128];
	int idSalonAux;
	int jugadoresAux;
	int fichasAux;
	char gameAux[63];
	int idArcadeAux;

	retorno=-1;

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=-2;

		posicionSolicitada=arc_buscarPorId (arcadeList,lenghtArcade, idIngresada);

		if(posicionSolicitada>=0)
		{

			arc_cambiarTexto (arcadeList, posicionSolicitada, cadenaAux);
			arc_getIdArcade(arcadeList[posicionSolicitada],&idArcadeAux);
			arc_getNationality(arcadeList[posicionSolicitada],nationalityAux);
			arc_getNumPlayers(arcadeList[posicionSolicitada],&jugadoresAux);
			arc_getMaxTokens(arcadeList[posicionSolicitada],&fichasAux);
			arc_getIdSalon(arcadeList[posicionSolicitada],&idSalonAux);
			arc_getGameName(arcadeList[posicionSolicitada],gameAux);

			printf("\nSe va a eliminar el siguiente arcade: \n\n");
			printf("%15s %15s %15s %15s %15s %15s %15s\n\n","ID del Arcade", "Nacionalidad","Sonido","Jugadores","Fichas máximas","ID de Salon", "Juego");
			printf("%15d %15s %15s %15d %15d %15d %15s\n",
					idArcadeAux,nationalityAux,cadenaAux,jugadoresAux,fichasAux,idSalonAux,gameAux);


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

	int idArcadeAux;

	retorno=-1;
	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=0;
		posicionPedida=arc_buscarPorId (arcadeList,lenghtArcade, idIngresada);
		if(posicionPedida>=0)
		{
			if(arcadeList[posicionPedida]!=NULL)
			{
				arc_getIdArcade(arcadeList[posicionPedida],&idArcadeAux);
				if(idIngresada==idArcadeAux)
						{

							eleccionUsuario=arc_subMenuModificaciones ();
							while(llaveDeCierre!='s')
							{
								switch (eleccionUsuario)
								{
									case 1:
										if(pedirIntIntentosRango(&cantidadJuegosAux,1, 6, 5, "Ingrese la nueva cantidad de jugadores:  ", "Error")==0)
										{
											arc_setNumPlayers(arcadeList[posicionPedida],cantidadJuegosAux);
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

	char nationalityAux[128];
	int idSalonAux;
	int jugadoresAux;
	int fichasAux;
	char gameAux[63];
	int idArcadeAux;

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		printf("%15s %15s %15s %15s %15s %15s %25s\n\n","ID del Arcade", "Nacionalidad","Sonido","Jugadores","Fichas máximas","ID de Salon", "Juego");
		retorno=0;
		for(int i=0;i<lenghtArcade;i++)
		{
			if(arcadeList[i]!=NULL)
			{
				arc_cambiarTexto (arcadeList, i, cadenaAux);
				arc_getIdArcade(arcadeList[i],&idArcadeAux);
				arc_getNationality(arcadeList[i],nationalityAux);
				arc_getNumPlayers(arcadeList[i],&jugadoresAux);
				arc_getMaxTokens(arcadeList[i],&fichasAux);
				arc_getIdSalon(arcadeList[i],&idSalonAux);
				arc_getGameName(arcadeList[i],gameAux);

				printf("%15d %15s %15s %15d %15d %15d %25s\n",
						idArcadeAux,nationalityAux,cadenaAux,jugadoresAux,fichasAux,idSalonAux,gameAux);


			}

		}

	}

	return retorno;

}



void arc_altaForzada(eArcade *pArcade,char nacionalidad[], int tipoSonido, int jugadores, int capacidad, int idSalon,char nombre[])
//MODIFICADA
{
	int idArcadeAux;

	idArcadeAux=dameUnIdNuevo();

	arc_setNationality (pArcade,nacionalidad);
	arc_setType(pArcade,tipoSonido);
	arc_setNumPlayers(pArcade,jugadores);
	arc_setMaxTokens(pArcade,capacidad);
	arc_setIdSalon(pArcade,idSalon);
	arc_setGameName(pArcade,nombre);
	arc_setIdArcade(pArcade,idArcadeAux);

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
	char gameAux[63];

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=0;
		for(int i=0;i<lenghtArcade;i++)
		{
			if(arcadeList[i]!=NULL)
			{
				arc_getGameName(arcadeList[i],gameAux);
				if(strncmp(gameAux,nombreJuego,GAME_LEN)==0)
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
				arc_setGameName(arcadeList[posicionPedida],nombreJuego);
				printf("Juego repetido modificado exitosamente.\n");
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
		arc_setGameName(arcadeList[posicionPedida],nombreJuego);
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

	int idSalonAuxUno;
	int idSalonAuxDos;
	char gameAuxUno[63];
	char gameAuxDos[63];

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
						arc_getGameName(arcadeList[i],gameAuxUno);
						arc_getGameName(arcadeList[j],gameAuxDos);
						if(strncmp(gameAuxUno,gameAuxDos,GAME_LEN)>0)
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
							arc_getIdSalon(arcadeList[i],&idSalonAuxUno);
							arc_getIdSalon(arcadeList[j],&idSalonAuxDos);
							if(idSalonAuxUno>idSalonAuxDos)
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

	char gameAuxUno[63];
	char gameAuxDos[63];

	arc_ordenarArcades (arcadeList, lenghtArcade,1);

	if(arcadeList!=NULL&&lenghtArcade>0)
	{
		retorno=0;
		for(int i=0;i<lenghtArcade;i++)
		{
			if(arcadeList[i]!=NULL&&arcadeList[i+1]!=NULL)
			{
				arc_getGameName(arcadeList[i],gameAuxUno);
				arc_getGameName(arcadeList[i+1],gameAuxDos);
				if(strncmp(gameAuxUno,gameAuxDos,GAME_LEN)==0)
				{
					continue;

				}else
				{
					printf("- Nombre del juego:		%s\n\n",gameAuxUno);
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

	int idSalonAux;
	char nationalityAux[128];
	int jugadoresAux;
	int fichasAux;
	char gameAux[63];
	int idArcadeAux;


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
				arc_getIdSalon(arcadeList[i],&idSalonAux);
				if(idIngresada==idSalonAux)
				{
					arc_cambiarTexto (arcadeList, i, cadenaAux);
					arc_getIdArcade(arcadeList[i],&idArcadeAux);
					arc_getNationality(arcadeList[i],nationalityAux);
					arc_getNumPlayers(arcadeList[i],&jugadoresAux);
					arc_getMaxTokens(arcadeList[i],&fichasAux);
					arc_getGameName(arcadeList[i],gameAux);

					printf("%15d %15s %15s %15d %15d %15d %25s\n",
							idArcadeAux,nationalityAux,cadenaAux,jugadoresAux,fichasAux,idSalonAux,gameAux);
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
									arc_getIdSalon(arcadeList[i],&idSalonAux);
									if(idIngresada==idSalonAux)
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
	int typeAux;

	retorno=-1;
	arc_getType(arcadeList[posicion],&typeAux);
	switch(typeAux)
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

int arc_setType (eArcade* pArcade, int tipo)
{
	int retorno=-1;
	if(pArcade!=NULL)
	{
		pArcade->soundType=tipo;
		retorno=0;
	}

	return retorno;
}


int arc_getType (eArcade* pArcade, int* tipo)
{
	int retorno=-1;
	if(pArcade!=NULL)
	{
		*tipo=pArcade->soundType;
		retorno=0;
	}

	return retorno;
}


int arc_setNumPlayers (eArcade* pArcade, int numero)
{
	int retorno=-1;
	if(pArcade!=NULL)
	{
		pArcade->numberOfPlayers=numero;
		retorno=0;
	}

	return retorno;
}


int arc_getNumPlayers (eArcade* pArcade, int* numero)
{
	int retorno=-1;
	if(pArcade!=NULL)
	{
		*numero=pArcade->numberOfPlayers;
		retorno=0;
	}

	return retorno;
}

int arc_setMaxTokens(eArcade* pArcade, int numero)
{
	int retorno=-1;
	if(pArcade!=NULL)
	{
		pArcade->maximumTokens=numero;
		retorno=0;
	}

	return retorno;
}


int arc_getMaxTokens (eArcade* pArcade, int* numero)
{
	int retorno=-1;
	if(pArcade!=NULL)
	{
		*numero=pArcade->maximumTokens;
		retorno=0;
	}

	return retorno;
}

int arc_setIdSalon(eArcade* pArcade, int id)
{
	int retorno=-1;
	if(pArcade!=NULL)
	{
		pArcade->idSalon=id;
		retorno=0;
	}

	return retorno;
}


int arc_getIdSalon (eArcade* pArcade, int* id)
{
	int retorno=-1;
	if(pArcade!=NULL)
	{
		*id=pArcade->idSalon;
		retorno=0;
	}

	return retorno;
}



int arc_setGameName(eArcade* pArcade, char nombre[])
{
	int retorno=-1;
	if(pArcade!=NULL&&nombre!=NULL)
	{
		strncpy(pArcade->gameName,nombre,GAME_LEN);
		retorno=0;
	}

	return retorno;
}


int arc_getGameName (eArcade* pArcade, char nombre[])
{
	int retorno=-1;
	if(pArcade!=NULL&&nombre!=NULL)
	{
		strncpy(nombre,pArcade->gameName,GAME_LEN);
		retorno=0;
	}

	return retorno;
}



int arc_setIdArcade(eArcade* pArcade, int idArcade)
{
	int retorno=-1;
	if(pArcade!=NULL)
	{
		pArcade->idArcade=idArcade;
		retorno=0;
	}

	return retorno;
}


int arc_getIdArcade(eArcade* pArcade, int* idArcade)
{
	int retorno=-1;
	if(pArcade!=NULL)
	{
		*idArcade=pArcade->idArcade;
		retorno=0;
	}

	return retorno;
}














