/*
 ============================================================================
 Name        : Clase16PunterosMemoria.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Contratacion.h"
#include "Pantallas.h"
#include "Informes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {


	setbuf(stdout,NULL);

	int posLibre;
	eDisplay* pAuxiliarDisplay;
	int idPedida;

	//Array de punteros estatico

	eDisplay * arrayDisplays [1000];


	//Se iniciliza con NULL>>> lo usamos como flag isEmpty

	disp_initList(arrayDisplays,1000);


	//>>>>ALTA DE DISPLAY<<<<<//

	posLibre=disp_buscarDisponible(arrayDisplays, 1000); //Busco libre

	if(posLibre>=0) //Verifico que hay uno libre
	{
		pAuxiliarDisplay=display_new(); //Creo el espacio para el nuevo display

		if(pAuxiliarDisplay!=NULL)
		{
			disp_loadDisplay(pAuxiliarDisplay);//Se le pasa la direccion del espacio de memoria creado (por fuera del array). Se cargan los datos

			arrayDisplays[posLibre]= pAuxiliarDisplay; //asignamos la dirrecion de memoria del nuevo display a la posicion libre de la lista
		}												//de punteros
	} else
	{
		printf("No hay mas lugar");
	}

	//>>>>>IMPRIMIR LISTA<<<<<<< ///

	disp_imprimirCompleto(arrayDisplays, 1000);

	//>>>>>>ELIMIAR POR ID<<<<<<//

	idPedida=disp_askForId ();

	if(idPedida>=0)
	{
		disp_remove (arrayDisplays, 1000,idPedida);
	}

	//>>>>>MODIFICAR<<<<<<//

	idPedida=disp_askForId ();
	if(idPedida>=0)
	{
		disp_modificarPantalla(arrayDisplays, 1000,idPedida);
	}


	return EXIT_SUCCESS;
}



/*float *pDireccion =(float*) malloc(sizeof(float));
printf("Me dio la direccion: %f",*pDireccion);
*pDireccion=3.14;*/

