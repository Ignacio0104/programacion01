/*
 * Salon.c
 *
 *  Created on: 16 oct 2021
 *      Author: Nacho
 */

#include <stdio.h>
#include <stdlib.h>
#include "Arcade.h"
#include "biblioteca_input.h"
#define INACTIVO  1
#define ACTIVO  0


static int dameUnIdNuevo (void);

static int dameUnIdNuevo (void)
{
	static int contador=1;
	return (contador++);
}


int arc_initList(eArcade *arcadeList,int lengtArcade)
{
	int retorno;

	retorno=-1;

	if(arcadeList!=NULL&&lengtArcade>0)
	{
		retorno=0;
		for(int i=0;i<lengtArcade;i++)
		{
			arcadeList[i].flagEmpty=INACTIVO;
		}
	}

	return retorno;
}

int arc_loadSalon(eArcade *pArcade)
{
	int retorno;

	retorno=-1;

	char nameAux[128];
	char addressAux[128];
	int typeAux;


	if(pArcade!=NULL)
	{
		if(pedirTexto(nameAux,sizeof(nameAux), 3, "Ingrese el nombre del salon: ", "Error")==0)
		{
			if(pedirDireccion(addressAux,sizeof(addressAux), 3, "Ingrese la direccion del salon: ", "Error, ingrese calle y altura")==0)
			{
				if(pedirIntIntentosRango(&typeAux,1, 2, 5, "Ingrese el tipo:\n"
															"1)Shopping\n"
															"2)Local\n", "Error")==0)
				{
					strncpy(pArcade->name,nameAux,sizeof(pArcade->name));
					strncpy(pArcade->address,addressAux,sizeof(pArcade->address));
					pArcade->type=typeAux;
					pArcade->idSalon=dameUnIdNuevo();
					pArcade->flagEmpty=ACTIVO;
					retorno=0;
				}

			}
		}
	}

	return retorno;

}

int arc_buscarDisponible(eArcade *arcadeList, int lengtArcade)
{
	int retorno;
	retorno=-1;

	if(arcadeList!=NULL&&lengtArcade>0)
	{
		retorno=0;
		for(int i=0;i<lengtArcade;i++)
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

	if(pedirIntIntentosRango(&requestedId, 0, 100000, 3, "Ingrese el ID del salon: ", "Error, dato ingresado invalido")==0)
	{
		retorno=requestedId;
	} else
	{
		retorno=-2;
	}


	return retorno;
}


int arc_buscarPorId (eArcade *arcadeList, int lengtArcade, int idIngresada)
{
	int retorno;
	retorno=-1;

	if(arcadeList!=NULL&&lengtArcade>0)
	{

		for(int i=0;i<lengtArcade;i++)
		{
			if(arcadeList[i].idSalon==idIngresada)
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

int arc_remove (eArcade *arcadeList, int lengtArcade, int idIngresada)
{
	int retorno;
	char userChoice;
	int posicionSolicitada;

	retorno=-1;

	if(arcadeList!=NULL&&lengtArcade>0)
	{
		retorno=-2;

		posicionSolicitada=arc_buscarPorId (arcadeList,lengtArcade, idIngresada);

		if(posicionSolicitada>=0)
		{
			printf("\nSe va a eliminar el siguiente arcade: \n\n"
							"Nombre: %s. Direccion: %s. Tipo: %s. ID de Salon: %d.  \n\n",
							arcadeList[posicionSolicitada].name,
							arcadeList[posicionSolicitada].address,
							TXT_TIPOS[arcadeList[posicionSolicitada].type-1],
							arcadeList[posicionSolicitada].idSalon);

					if(pedirCharSiNo(&userChoice, 's', 'n', 5, "Presione [s] para confirmar o [n] para volver al menu principal\n",
							"Error, dato ingresado inválido\n")==0)
					{
						if(userChoice=='s')
						{
							arcadeList[posicionSolicitada].flagEmpty=INACTIVO;
							printf("Salon borrado exitosamente.\n");
							retorno=0;
						} else
						{
							if(userChoice=='n')
							{
								printf("No se borrará el Salón. Volviendo al menú principal...\n");
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

int arc_imprimirCompleto(eArcade *arcadeList, int lengtArcade)
{
	int retorno;
	retorno=-1;

	if(arcadeList!=NULL&&lengtArcade>0)
	{
		retorno=0;
		for(int i=0;i<lengtArcade;i++)
		{

			if(arcadeList[i].flagEmpty==ACTIVO)
			{

				printf("\n- Nombre: %s. Direccion: %s. Tipo: %s. ID de Salon: %d.  \n\n",
						arcadeList[i].name,
						arcadeList[i].address,
						TXT_TIPOS[arcadeList[i].type-1],
						arcadeList[i].idSalon);

			}

		}

	}

	return retorno;

}

int menuOperaciones (void)
{
	int eleccion;

	printf("Opciones:\n\n"
			"1)Alta de Salon\n"
			"2)Eliminar Salon\n"
			"3)Imprimir Salones\n"
			"4)Incorporar Arcade\n"
			"5)Modificar Arcade\n"
			"6)Eliminar Arcade\n"
			"7)Imprimir Arcades\n"
			"8)Imprimir Juegos\n"
			"9)Informes\n"
			"10)Salir\n");

	pedirIntIntentosRango(&eleccion, 1, 11, 20, "Ingrese aquí su elección", "Error");

	return eleccion;
}


void arc_altaForzada(eArcade *pArcade,char nombre[],char direccion[], int tipo, int id, int indice)
{
	strncpy(pArcade[indice].name,nombre,sizeof(pArcade[indice].name));
	strncpy(pArcade[indice].address,direccion,sizeof(pArcade[indice].address));
	pArcade[indice].type=tipo;
	pArcade[indice].idSalon=id;
	pArcade[indice].flagEmpty=ACTIVO;

}




