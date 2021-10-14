/*
 * Pantallas.c
 *
 *  Created on: 30 sept 2021
 *      Author: Nacho
 */

#include "Musico.h"

#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INACTIVO 1
#define ACTIVO 0

static int dameUnIdNuevo (void);

static int dameUnIdNuevo (void)
{
	static int contador=10; //Es una variable global que solo tiene visibilidad dentro de la función. Mantiene su valor por mas que salga de la fn
	return (contador++);
}

int music_initList(eMusico *musicList,int lenghtMusic)
{
	int retorno;

	retorno=-1;

	if(musicList!=NULL&&lenghtMusic>0)
	{
		retorno=0;
		for(int i=0;i<lenghtMusic;i++)
		{
			musicList[i].flagEmpty=INACTIVO;
		}
	}

	return retorno;
}

int music_buscarDisponible(eMusico* musicList, int lenghtMusic)
{
	int retorno;
	retorno=-1;

	if(musicList!=NULL&&lenghtMusic>0)
	{
		retorno=0;
		for(int i=0;i<lenghtMusic;i++)
		{
			if(musicList[i].flagEmpty==INACTIVO)
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


int music_loadCont(eMusico *pMusico, int idOrquesta)
{
	int retorno;

	retorno=-1;
	char nameAux[128];
	char lastNameAux[128];
	int edadAux;


	if(pMusico!=NULL)
	{
		if(pedirTexto(nameAux,sizeof(nameAux), 3, "Ingrese el nombre del musico: ", "Error")==0)
			{
			if(pedirTexto(lastNameAux,sizeof(lastNameAux), 3, "Ingrese el apellido del musico: ", "Error")==0)
			{
				if(pedirIntIntentosRango(&edadAux,15, 95, 10, "Ingrese la edad:  ", "Error")==0)
				{
					strncpy(pMusico->name,nameAux,sizeof(pMusico->name));
					strncpy(pMusico->lastName,lastNameAux,sizeof(pMusico->lastName));
					pMusico->edad=edadAux;
					pMusico->idOrquesta=idOrquesta;
					pMusico->idInstrumento=dameUnIdNuevo();
					pMusico->flagEmpty=ACTIVO;
					retorno=0;

				}
			}

		}


	}

	return retorno;

}
/*
float music_askForCuit ()
{
	float retorno;
	float requestedId;

	if(pedirFloatIntentosRango(&requestedId, 0, 100000, 3, "Ingrese el CUIT:  ", "Error, dato ingresado invalido")==0)
	{
		retorno=requestedId;
	} else
	{
		retorno=-1;
	}

	return retorno;
}

int music_buscarPorCuit (eMusico *musicList, int lenghtMusic, float cuitIngresado)
{
	int retorno;
	retorno=-1;

	if(musicList!=NULL&&lenghtMusic>0)
	{

		for(int i=0;i<lenghtMusic;i++)
		{
			if(musicList[i].cuitCliente==cuitIngresado)
			{

				if(musicList[i].flagEmpty==ACTIVO)
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
}*/

int music_askForId ()
{
	int retorno;
	int requestedId;

	if(pedirIntIntentosRango(&requestedId, 0, 100000, 3, "Ingrese el ID del instrumento: ", "Error, dato ingresado invalido")==0)
	{
		retorno=requestedId;
	} else
	{
		retorno=-1;
	}

	return retorno;
}

int music_buscarPorId (eMusico *musicList, int lenghtMusic, int idIngresada)
{
	int retorno;
	retorno=-1;

	if(musicList!=NULL&&lenghtMusic>0)
	{

		for(int i=0;i<lenghtMusic;i++)
		{
			if(musicList[i].idInstrumento==idIngresada)
			{

				if(musicList[i].flagEmpty==ACTIVO)
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


int music_modificarEdad(eMusico *musicList,int lenghtMusic, int idIngresada)
{
	int retorno;
	int posicionPedida;
	int edadAux;

	retorno=-1;
	if(musicList!=NULL&&lenghtMusic>0)
	{
		retorno=0;
		posicionPedida=music_buscarPorId (musicList,lenghtMusic, idIngresada);
		if(posicionPedida>=0)
		{
			if(idIngresada==musicList[posicionPedida].idOrquesta)
			{
				if(musicList[posicionPedida].flagEmpty==ACTIVO)
						{

						if(pedirIntIntentosRango(&edadAux,1, 365, 10, "Ingrese la nueva edad:  ", "Error")==0)
						{
							musicList[posicionPedida].edad=edadAux;
						}

					} else
					{
						printf("ID ingresada no coincide con ningún musico\n");
					}
			}


		}
	}

	return retorno;

}

int music_modificarOrquesta(eMusico *musicList,int lenghtMusic, int idIngresada)
{
	int retorno;
	int posicionPedida;


	retorno=-1;
	if(musicList!=NULL&&lenghtMusic>0)
	{
		retorno=0;
		posicionPedida=music_buscarPorId (musicList,lenghtMusic, idIngresada);
		if(posicionPedida>=0)
		{

			if(musicList[posicionPedida].flagEmpty==ACTIVO)
				{

					musicList[posicionPedida].idOrquesta=idIngresada;
					printf("Se realizo el cambio de orquesta");

				} else
				{
					printf("ID ingresada no coincide con ningún musico\n");
				}



		}
	}

	return retorno;

}



int music_remove (eMusico*musicList, int lenghtMusic, int idIngresada)
{
	int retorno;
	char userChoice;
	int posicionSolicitada;


	if(musicList!=NULL&&lenghtMusic>0)
	{
		retorno=-2;

		posicionSolicitada=music_buscarPorId (musicList,lenghtMusic, idIngresada);

		if(posicionSolicitada>=0)
		{
			if(idIngresada==musicList[posicionSolicitada].idInstrumento)
			{
				printf("\nSe va a eliminar al siguiente musico: \n\n"
						"Nombre: %s. Apellido: %s. Edad: %d. Id Orquesta: %d. Id Instrumento: %d. \n\n",
						musicList[posicionSolicitada].name,
						musicList[posicionSolicitada].lastName,
						musicList[posicionSolicitada].edad,
						musicList[posicionSolicitada].idOrquesta,
						musicList[posicionSolicitada].idInstrumento);

				if(pedirCharSiNo(&userChoice, 's', 'n', 5, "Presione [s] para confirmar o [n] para volver al menu principal\n",
						"Error, dato ingresado inválido\n")==0)
				{
					if(userChoice=='s')
					{
						musicList[posicionSolicitada].flagEmpty=INACTIVO;
						printf("Músico borrado exitosamente.\n");
						retorno=0;
					} else
					{
						if(userChoice=='n')
						{
							printf("No se borrará al musico. Volviendo al menú principal...\n");
							retorno=0;
						}
					}

				}
			} printf("ID ingresada no coincide con ningun musico\n");

			}

		}

		if(retorno==-2)
		{
			printf("\nNo se pudo realizar la acción\n");
		}

	return retorno;

}


int music_removePorOrquesta (eMusico*musicList, int lenghtMusic, int idIngresada)
{
	int retorno;
	char userChoice;



	if(musicList!=NULL&&lenghtMusic>0)
	{
		retorno=-2;

		printf("\n >>>Se van a eliminar a los siguientes musicos tambien:<<< \n");

		for(int i=0;i<lenghtMusic;i++)
		{
			if(idIngresada==musicList[i].idOrquesta)
			{

				printf("Nombre: %s. Apellido: %s. Edad: %d. Id Orquesta: %d. Id Instrumento: %d. \n\n",
						musicList[i].name,
						musicList[i].lastName,
						musicList[i].edad,
						musicList[i].idOrquesta,
						musicList[i].idInstrumento);
			}

		}

		if(pedirCharSiNo(&userChoice, 's', 'n', 5, "Presione [s] para confirmar o [n] para volver al menu principal\n",
						"Error, dato ingresado inválido\n")==0)
				{
					if(userChoice=='s')
					{
						for(int i=0;i<lenghtMusic;i++)
						{
							if(idIngresada==musicList[i].idOrquesta)
							{
								musicList[i].flagEmpty=INACTIVO;
							}

						}

						printf("Músicos borrado exitosamente.\n");
						retorno=0;
					} else
					{
						if(userChoice=='n')
						{
							printf("No se borrará al musico. Volviendo al menú principal...\n");
							retorno=0;
						}
					}

				}

			} printf("ID ingresada no coincide con ningun musico\n");



		if(retorno==-2)
		{
			printf("\nNo se pudo realizar la acción\n");
		}

	return retorno;

}



int music_imprimirCompleto(eMusico *musicList, int lenghtMusic)
{
	int retorno;
	retorno=-1;

	if(musicList!=NULL&&lenghtMusic>0)
	{
		retorno=0;
		for(int i=0;i<lenghtMusic;i++)
		{

			if(musicList[i].flagEmpty==ACTIVO)
			{
				printf("\n"
						"Nombre: %s. Apellido: %s. Edad: %d. Id Orquesta: %d. Id Instrumento: %d.\n",
						musicList[i].name,
						musicList[i].lastName,
						musicList[i].edad,
						musicList[i].idOrquesta,
						musicList[i].idInstrumento);
			}

		}

	}

	return retorno;

}


void music_altaForzada(eMusico *musicList,char nombre[],char apellido[], int edad, int orquesta, int instrumento, int indice)
{

	strncpy(musicList[indice].name,nombre,sizeof(musicList[indice].name));
	strncpy(musicList[indice].lastName,apellido,sizeof(musicList[indice].lastName));
	musicList[indice].edad=edad;
	musicList[indice].idOrquesta=orquesta;
	musicList[indice].idInstrumento=instrumento;
	musicList[indice].flagEmpty=ACTIVO;
}

int subMenu (void)
{
	int eleccion;

	printf("Elija el cambio que desea cambiar:\n\n"
			"1)Edad\n"
			"2)ID Orquesta");

	pedirIntIntentosRango(&eleccion, 1, 2, 20, "Ingrese aquí su elección", "Error");

	return eleccion;
}


int ordenarMusicos (eMusico *musicList, int lenghtMusic)
{
	int i;
	int retorno;
	eMusico aux;
	int j;

	retorno=-1;

	if(musicList!=NULL&&lenghtMusic>0)
	{
		retorno=0;

		for(i=0;i<lenghtMusic-1;i++)
		{
			for(j=i+1;j<lenghtMusic;j++)
			{
				if(musicList[i].idOrquesta>musicList[j].idOrquesta)
				{
					aux = musicList[i];
					musicList[i] = musicList[j];
					musicList[j] = aux;
				}
			}
		}
	}

	return retorno;
}


