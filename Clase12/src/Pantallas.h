/*
 * Pantallas.h
 *
 *  Created on: 30 sept 2021
 *      Author: Nacho
 */

#ifndef PANTALLAS_H_
#define PANTALLAS_H_
#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include "Pantallas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

	int type;
	float pricePerDay;
	int id;
	char name[128];
	char address[60];
	int flagEmpty; //0=ocupado 1=libre

}eDisplay;

int disp_initList(eDisplay displaysList[],int lenght);
int disp_loadDisplay(eDisplay *pDisplay, int posicion);
int buscarDisponible(eDisplay *displaysList, int *pPosicionVacia, int lenght);
int imprimirLista (eDisplay *displaysList,int lenght);


#endif /* PANTALLAS_H_ */
