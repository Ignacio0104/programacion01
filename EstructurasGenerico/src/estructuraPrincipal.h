/*
 * Pantallas.h
 *
 *  Created on: 30 sept 2021
 *      Author: Nacho
 */

#ifndef ESTRUCTURAPRINCIPAL_H_
#define ESTRUCTURAPRINCIPAL_H_
#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
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

}ePrincipal;

int disp_initList(eDisplay *displaysList,int lenght);
int disp_loadDisplay(eDisplay *pDisplay);
int askForId (eDisplay *list, int lenght);
int disp_buscarDisponible(eDisplay *displaysList, int lenght);
int disp_buscarPorId (eDisplay *displaysList, int lenght, int idIngresada);
int disp_modificarPantalla(eDisplay *displaysList,int lenght, int idIngresada);
int disp_imprimirCompleto(eDisplay *displaysList, int lenght);
int disp_remove (eDisplay *displaysList, int lenght, int idIngresada);
void disp_altaForzada(eDisplay *pDisplay,int tipo, float precio, int id, char nombre[], char direccion[], int indice);
int disp_imprimirCompleto(eDisplay *displaysList, int lenght);

#endif /* ESTRUCTURAPRINCIPAL_H_ */
