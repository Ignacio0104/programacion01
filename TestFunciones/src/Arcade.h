/*
 * Salon.h
 *
 *  Created on: 16 oct 2021
 *      Author: Nacho
 */

#ifndef ARCADE_H_
#define ARCADE_H_
#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_input.h"

typedef struct {

	char nationality[128];
	int soundType;
	int numberOfPlayers;
	int maximumTokens;
	int idSalon;
	char gameName[63];
	int flagEmpty;

}eArcade;


int arc_initList(eArcade *arcadeList,int lengtArcade);
int arc_loadSalon(eArcade *pArcade);
int arc_buscarDisponible(eArcade *arcadeList, int lengtArcade);
int arc_askForId (void);
int arc_buscarPorId (eArcade *arcadeList, int lengtArcade, int idIngresada);
int menuOperaciones (void);
int arc_imprimirCompleto(eArcade *arcadeList, int lengtArcade);
int arc_remove (eArcade *arcadeList, int lengtArcade, int idIngresada);
void arc_altaForzada(eArcade *pArcade,char nombre[],char direccion[], int tipo, int id, int indice);

#endif /* ARCADE_H_ */
