/*
 * Pantallas.h
 *
 *  Created on: 30 sept 2021
 *      Author: Nacho
 */

#ifndef ORQUESTA_H_
#define ORQUESTA_H_
#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

	char name[128];
	char place[128];
	int type;
	int idOrquesta;
	int flagEmpty; //0=ocupado 1=libre

}eOrquesta;

int orq_initList(eOrquesta *orquestList,int orquestLength);
int orq_loadDisplay(eOrquesta *pOrquesta);
int orq_askForId (void);
int orq_buscarDisponible(eOrquesta *orquestList, int orquestLength);
int orq_buscarPorId (eOrquesta *orquestList, int orquestLength, int idIngresada);
int orq_modificarPantalla(eOrquesta *orquestList,int orquestLength, int idIngresada);
int orq_imprimirCompleto(eOrquesta *orquestList, int orquestLength);
int orq_remove (eOrquesta *orquestList, int orquestLength, int idIngresada);
void orq_altaForzada(eOrquesta *pOrquesta,char nombre[],char direccion[], int tipo, int id, int indice);
int orq_imprimirCompleto(eOrquesta *orquestList, int orquestLength);
#endif /* ORQUESTA_H_ */
