/*
 * Pantallas.h
 *
 *  Created on: 30 sept 2021
 *      Author: Nacho
 */

#ifndef PANTALLAS_H_
#define PANTALLAS_H_

#include "biblioteca_input.h"
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

}eDisplay;

int disp_initList(eDisplay *displaysList[],int lenght);
int disp_loadDisplay(eDisplay *pDisplay);
int disp_askForId (void);
int disp_buscarDisponible(eDisplay *displaysList[], int lenght);
int disp_buscarPorId (eDisplay *displaysList[], int lenght, int idIngresada);
int disp_modificarPantalla(eDisplay *displaysList[],int lenght, int idIngresada);
int disp_imprimirCompleto(eDisplay *displaysList[], int lenght);
int disp_remove (eDisplay *displaysList[], int lenght, int idIngresada);
void disp_altaForzada(eDisplay *pDisplay,int tipo, float precio, int id, char nombre[], char direccion[], int indice);
eDisplay * display_new (void);

#endif /* PANTALLAS_H_ */
