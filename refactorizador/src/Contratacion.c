/*
 * Pantallas.c
 *
 *  Created on: 30 sept 2021
 *      Author: Nacho
 */

#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include "Pantallas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VACIO 1
#define OCUPADO 0

static int dameUnIdNuevo (void);


int disp_initList(eContratacion *displaysList,int lenght)
{
	int retorno;

	retorno=-1;

	if(displaysList!=NULL&&lenght>0)
	{
		retorno=0;
		for(int i=0;i<lenght;i++)
		{
			displaysList[i].flagEmpty=VACIO;
		}
	}

	return retorno;
}

int disp_loadDisplay(eContratacion *pDisplay)
{
	int retorno;

	retorno=-1;

	int typeAux;
	float pricePerDayAux;
	//int idAux;
	char nameAux[128];
	char addressAux[60];

	if(pDisplay!=NULL)
	{
		if(pedirIntIntentosRango(&typeAux,0, 1, 10, "Ingrese el tipo LCD>0 LED>1:  ", "Error")==0)
		{
			if(pedirFloatIntentosRango(&pricePerDayAux,0, 100000, 10, "Ingrese el precio:  ", "Error")==0)
			{
				if(pedirTexto(nameAux,sizeof(nameAux), 3, "Ingrese el nombre: ", "Error")==0)
				{
					if(pedirTexto(addressAux,sizeof(nameAux), 3, "Ingrese la direccion: ", "Error")==0)
					{
						pDisplay->type=typeAux;
						pDisplay->pricePerDay=pricePerDayAux;
						pDisplay->id=dameUnIdNuevo();
						strncpy(pDisplay->name,nameAux,sizeof(pDisplay->name));
						strncpy(pDisplay->address,addressAux,sizeof(pDisplay->address));
						pDisplay->flagEmpty=OCUPADO;
						retorno=0;
					}

				}
			}
		}

	}

	return retorno;

}


static int dameUnIdNuevo (void)
{
	static int contador=1000; //Es una variable global que solo tiene visibilidad dentro de la función. Mantiene su valor por mas que salga de la fn
	return (contador++);
}

int disp_buscarDisponible(eDisplay *displaysList, int *pPosicionVacia, int lenght)
{
	int retorno;
	int posicionLibre;
	retorno=-1;

	if(displaysList!=NULL&&lenght>0)
	{
		retorno=0;
		for(int i=0;i<lenght;i++)
		{
			if(displaysList[i].flagEmpty==VACIO)
			{
				posicionLibre=i;
				*pPosicionVacia=posicionLibre;
				break;
			} else
			{
				retorno=-2;
			}

		}


	}

	return retorno;

}

int disp_buscarPorId (eDisplay *displaysList, int *pPosicionSolicitada, int lenght)
{
	int retorno;
	int posicionPedida;
	retorno=-1;

	if(displaysList!=NULL&&lenght>0)
	{
		int idIngresada;
		pedirIntIntentosRango(&idIngresada, 0, 10000, 3, "Ingrese el ID", "Error");

		for(int i=0;i<lenght;i++)
		{
			if(displaysList[i].id==idIngresada)
			{

				if(displaysList[i].flagEmpty==OCUPADO)
				{
					posicionPedida=i;
					retorno=0;
					break;
				}

			} else
			{
				retorno=-1;
			}

		}

		*pPosicionSolicitada=posicionPedida;
	}

	return retorno;

}

int disp_remove (eDisplay *displaysList, int lenght)
{
	int retorno;
	char userChoice;
	int posicionSolicitada;

	retorno=-1;

	if(displaysList!=NULL&&lenght>0)
	{
		retorno=-2;

		disp_buscarPorId (displaysList, &posicionSolicitada, lenght);

				printf("\nSe va a eliminar al siguiente empleado: \n\n"
						"Tipo: %02d. Precio: %18.2f. ID: %d.   Nombre: %15s.  Direccion: %15s.\n\n",
						displaysList[posicionSolicitada].type,displaysList[posicionSolicitada].pricePerDay,displaysList[posicionSolicitada].id ,displaysList[posicionSolicitada].name,displaysList[posicionSolicitada].address);

				if(pedirCharSiNo(&userChoice, 's', 'n', 5, "Presione [s] para confirmar o [n] para volver al menu principal\n",
						"Error, dato ingresado inválido\n")==0)
				{
					if(userChoice=='s')
					{
						displaysList[posicionSolicitada].flagEmpty=VACIO;
						printf("Empleado borrado exitosamente.\n");
						retorno=0;
					} else
					{
						if(userChoice=='n')
						{
							printf("No se borrará al empleado. Volviendo al menú principal...\n");
							retorno=0;
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


int disp_modificarPantalla(eDisplay *displaysList,int lenght)
{
	int retorno;
	int posicionPedida;

	retorno=-1;
	if(displaysList!=NULL&&lenght>0)
	{
		retorno=0;
		if(disp_buscarPorId (displaysList, &posicionPedida, lenght)==0)
		{
			if(displaysList[posicionPedida].flagEmpty==OCUPADO)
			{
				printf("Se van a modificar los datos del ID %d\n",posicionPedida);

				disp_loadDisplay(&displaysList[posicionPedida]);
			} else
			{
				printf("Aca está fallando");
			}

		} else
		{
			printf("Acá está el error");
		}

	}

	return retorno;

}

int disp_cargarPantalla(eDisplay *displaysList,int lenght)
{
	int retorno;
	int posicionPedida;

	retorno=-1;
	if(displaysList!=NULL&&lenght>0)
	{
		retorno=0;
		if(disp_buscarPorId (displaysList, &posicionPedida, lenght)==0 && displaysList->flagEmpty==VACIO)
		{
			printf("Se van a cargar los datos de la posición %d",posicionPedida);

			disp_loadDisplay(&displaysList[posicionPedida]);

		} else
		{
			if(disp_buscarPorId (displaysList, &posicionPedida, lenght)==-1)
			{
				printf("Error, ID inexistente");
			}
		}

	}

	return retorno;

}

int disp_imprimirCompleto(eDisplay *displaysList, int lenght)
{
	int retorno;
	retorno=-1;

	if(displaysList!=NULL&&lenght>0)
	{
		retorno=0;
		for(int i=0;i<lenght;i++)
		{

			if(displaysList[i].flagEmpty==0)
			{
				printf("Tipo: %d. Precio: %f. ID: %d. Nombre: %s. Direccion: %s.\n",
						displaysList[i].type, displaysList[i].pricePerDay, displaysList[i].id,
						displaysList[i].name,displaysList[i].address);
			}

		}

	}

	return retorno;

}

int menuOperaciones (void)
{
	int eleccion;

	printf("Opciones:\n\n"
			"1)Alta de pantalla\n"
			"2)Modificar datos de pantalla\n"
			"3)Baja de pantalla\n"
			"4)Contratar una publicidad\n"
			"5)Modificar condiciones de publicacion\n"
			"6)Cancelar contratación\n"
			"7)Consulta facturacion\n"
			"8)Lista contrataciones\n"
			"9)Lista pantallas\n"
			"10)Informar\n"
			"11)Salir\n");

	pedirIntIntentosRango(&eleccion, 1, 11, 20, "Ingrese aquí su elección", "Error");

	return eleccion;
}

