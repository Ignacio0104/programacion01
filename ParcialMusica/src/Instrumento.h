/*
 * Instrumento.h
 *
 *  Created on: 14 oct 2021
 *      Author: Nacho
 */

#ifndef INSTRUMENTO_H_
#define INSTRUMENTO_H_
#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

	char name[128];
	int tipo;
	int idInstrumento;
	int flagEmpty; //0=ocupado 1=libre

}eInstrumento;

int inst_initList(eInstrumento *instList,int lenghtInst);
int inst_buscarDisponible(eInstrumento* instList, int lenghtInst);
int inst_loadCont(eInstrumento *pInstrumento);
int inst_imprimirCompleto(eInstrumento *instList, int lenghtInst);
void inst_altaForzada(eInstrumento *instList,char nombre[],int tipo, int id, int indice);
int inst_buscarPorId (eInstrumento *instList, int lenghtInst, int idIngresada);
int inst_askForId ();



#endif /* INSTRUMENTO_H_ */
