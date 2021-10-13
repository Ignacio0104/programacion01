/*
 * Pantallas.h
 *
 *  Created on: 30 sept 2021
 *      Author: Nacho
 */

#ifndef CONTRATACIONES_H_
#define CONTRATACIONES_H_
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
	char address[128];
	int flagEmpty; //0=ocupado 1=libre

}eContratacion;

int disp_initList(eContratacion *displaysList,int lenght);
int disp_loadDisplay(eContratacion *pDisplay);
int disp_buscarDisponible(eContratacion *displaysList, int *pPosicionVacia, int lenght);
int disp_buscarPorId (eContratacion *displaysList, int *pPosicionSolicitada, int lenght);
int disp_modificarPantalla(eContratacion *displaysList,int lenght);
int disp_cargarPantalla(eContratacion *displaysList,int lenght);
int disp_imprimirCompleto(eContratacion *displaysList, int lenght);
int menuOperaciones (void);
int disp_remove (eContratacion *displaysList, int lenght);


#endif /* PANTALLAS_H_ */
