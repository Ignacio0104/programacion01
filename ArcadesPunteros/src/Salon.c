/*
 * Salon.c
 *
 *  Created on: 16 oct 2021
 *      Author: Nacho
 */

#include "Salon.h"
#include <limits.h>
#include <string.h>

#define NAME_LEN 128
#define ADDRESS_LEN 128
#define TIPO_SHOPPING 1
#define TIPO_LOCAL 2



static int dameUnIdNuevo (void);

static int dameUnIdNuevo (void)
{
	static int contador=1;
	return (contador++);
}

eSalon* salon_nuevo (void) //MODIFICADA
{

	eSalon* pSalon=(eSalon*)malloc(sizeof(eSalon));
	return pSalon;
}


int salon_initList(eSalon *salonList[],int lenghtSalon) //MODIFICADA
{
	int retorno;

	retorno=-1;

	if(salonList!=NULL&&lenghtSalon>0)
	{
		retorno=0;
		for(int i=0;i<lenghtSalon;i++)
		{
			salonList[i]=NULL;
		}
	}

	return retorno;
}

int salon_loadSalon(eSalon *pSalon) //MODIFICADA (QUEDA IGUAL)
{
	int retorno;

	retorno=-1;

	char nameAux[128];
	char addressAux[128];
	char cadenaAuxUno[128]={"Shopping"};
	char cadenaAuxDos[128]={"Local"};
	int idAux;
	int typeAux;

	if(pSalon!=NULL)
	{
		if(pedirTexto(nameAux,sizeof(nameAux), 3, "Ingrese el nombre del salon: ", "Error")==0)
		{
			if(pedirDireccion(addressAux,sizeof(addressAux), 3, "Ingrese la direccion del salon: ", "Error, ingrese calle y altura")==0)
			{
				if(pedirIntIntentosRango(&typeAux,1, 2, 5, "Ingrese el tipo:\n"
															"	1)Shopping\n"
															"	2)Local\n", "Error")==0)
				{
					idAux=dameUnIdNuevo();

					salon_setName(pSalon, nameAux);
					salon_setAddress(pSalon,addressAux);
					salon_setType(pSalon,typeAux);
					salon_setIdSalon(pSalon,idAux);
					retorno=0;

					salon_getName(pSalon,nameAux);
					salon_getAddress(pSalon,addressAux);
					salon_getType(pSalon,&typeAux);
					salon_getIdSalon(pSalon,&idAux);

					if(typeAux==1)
					{
						printf("Arcade cargado con exito:\n");
						printf("%-15s %15s %15s %15s\n\n","Nombre", "Direccion","Tipo de Salon","ID de Salon");
						printf("%-15s %15s %15s  %15d  \n",
								nameAux,
								addressAux,
								cadenaAuxUno,
								idAux);
					} else
					{
						printf("Arcade cargado con exito:\n");
						printf("%-15s %15s %15s %15s\n\n","Nombre", "Direccion","Tipo de Salon","ID de Salon");
						printf("%-15s %15s %15s  %15d  \n",
								nameAux,
								addressAux,
								cadenaAuxDos,
								idAux);
					}


				}

			}
		}
	}

	return retorno;

}

int salon_buscarDisponible(eSalon *salonList[], int lenghtSalon) //Modificada
{
	int retorno;
	retorno=-1;

	if(salonList!=NULL&&lenghtSalon>0)
	{
		retorno=0;
		for(int i=0;i<lenghtSalon;i++)
		{
			if(salonList[i]==NULL)
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

int salon_askForId (void) //MODIFICADA (QUEDA IGUAL)
{
	int retorno;
	int requestedId;

	if(pedirIntIntentosRango(&requestedId, 0, INT_MAX, 3, "Ingrese el ID del salon: ", "Error, dato ingresado invalido")==0)
	{
		retorno=requestedId;
	} else
	{
		retorno=-1;
	}


	return retorno;
}


int salon_buscarPorId (eSalon *salonList[], int lenghtSalon, int idIngresada) //MODIFICADA
{
	int retorno;
	int idSalonAux;
	retorno=-1;

	if(salonList!=NULL&&lenghtSalon>0)
	{

		for(int i=0;i<lenghtSalon;i++)
		{
			if(salonList[i]!=NULL)
			{
				salon_getIdSalon(salonList[i],&idSalonAux);
				if(idSalonAux==idIngresada)
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

int salon_remove (eSalon *salonList[], int lenghtSalon, int idIngresada) //MODIFICADA
{
	int retorno;
	char userChoice;
	int posicionSolicitada;
	char cadenaAux [32];
	char nameAux[128];
	char addressAux[128];
	int idAux;

	retorno=-1;

	if(salonList!=NULL&&lenghtSalon>0)
	{
		retorno=-2;

		posicionSolicitada=salon_buscarPorId (salonList,lenghtSalon, idIngresada);

		if(posicionSolicitada>=0)
		{
			salon_cambiarTexto (salonList, posicionSolicitada, cadenaAux);
			salon_getName(salonList[posicionSolicitada],nameAux);
			salon_getAddress(salonList[posicionSolicitada],addressAux);
			salon_getIdSalon(salonList[posicionSolicitada],&idAux);

			printf("\nSe va a eliminar el siguiente salon: \n\n");
			printf("%-15s %15s %15s  %15d  \n",
					nameAux,addressAux,cadenaAux,idAux);

					if(pedirCharSiNo(&userChoice, 's', 'n', 5, "\n\n ---------Presione [s] para confirmar o [n] para volver al menu principal---------\n",
							"Error, dato ingresado inválido\n")==0)
					{
						if(userChoice=='s')
						{
							free(salonList[posicionSolicitada]);
							salonList[posicionSolicitada]=NULL;
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

int salon_imprimirCompleto(eSalon *salonList[], int lenghtSalon) //MODIFICADA
{
	int retorno;
	retorno=-1;
	char cadenaAux[32];
	char nameAux[128];
	char addressAux[128];
	int idAux;

	if(salonList!=NULL&&lenghtSalon>0)
	{
		retorno=0;
		printf("%-15s %15s %15s %15s\n\n","Nombre", "Direccion","Tipo de Salon","ID de Salon");
		for(int i=0;i<lenghtSalon;i++)
		{

			if(salonList[i]!=NULL)
			{
				salon_cambiarTexto (salonList, i, cadenaAux);
				salon_getName(salonList[i],nameAux);
				salon_getAddress(salonList[i],addressAux);
				salon_getIdSalon(salonList[i],&idAux);

				printf("%-15s %15s %15s  %15d  \n",
						nameAux,addressAux,cadenaAux,idAux);

			}

		}

	}

	return retorno;

}



void salon_altaForzada(eSalon *pSalon,char nombre[],char direccion[], int tipo) //MODIFICADA
{
	int idAux;
	idAux=dameUnIdNuevo();

	salon_setName(pSalon, nombre);
	salon_setAddress(pSalon,direccion);
	salon_setType(pSalon,tipo);
	salon_setIdSalon(pSalon,idAux);

}

int salon_cambiarTexto (eSalon *salonList[], int posicion, char pTextoConvertido[]) //MODIFICADA
{
	int retorno;
	int typeAux;

	retorno=-1;
	salon_getType(salonList[posicion],&typeAux);

	switch(typeAux)
	{
		case TIPO_SHOPPING:
			retorno=0;
			strncpy(pTextoConvertido,"Shopping",32);
			break;
		case TIPO_LOCAL:
			strncpy(pTextoConvertido,"Local",32);
			retorno=0;
			break;
	}

	return retorno;
}

int salon_occupancy (eSalon *salonList[], int lenghtSalon, int* pNotEmpty) //MODIFICADA
{
	int retorno;
	int notEmpty;
	int i;

	retorno=-1;
	notEmpty=0;

	if(salonList!=NULL&&lenghtSalon>0)
		{
			retorno=0;

			for (i=0;i<lenghtSalon;i++)
			{
				if(salonList[i]!=NULL)
				{
					notEmpty++;
				}

			}
		}

	*pNotEmpty=notEmpty;

	return retorno;
}

////// SETTERS Y GETTERS //////

int salon_setName (eSalon* pSalon, char nombre[])
{
	int retorno=-1;
	if(pSalon!=NULL)
	{
		strncpy(pSalon->name,nombre,sizeof(pSalon->name));
		retorno=0;
	}

	return retorno;
}


int salon_getName (eSalon* pSalon, char* nombre)
{
	int retorno=-1;
	if(pSalon!=NULL&&nombre!=NULL)
	{
		strncpy(nombre,pSalon->name,NAME_LEN);
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

















