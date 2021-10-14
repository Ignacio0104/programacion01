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

int princ_initList(ePrincipal *principalList,int lenghtPrincipal);
int princ_loadPrincipal(ePrincipal *principalList);
int princ_buscarDisponible(ePrincipal *principalList, int lenghtPrincipal);
int princ_askForId (ePrincipal *principalList, int lenghtPrincipal);
int princ_buscarPorId (ePrincipal *principalList, int lenghtPrincipal, int idIngresada);
int princ_remove (ePrincipal *principalList, int lenghtPrincipal, int idIngresada);
int princ_modificarPrincipal(ePrincipal *principalList,int lenghtPrincipal, int idIngresada);
int princ_imprimirCompleto(ePrincipal *principalList, int lenghtPrincipal);
void princ_altaForzada(ePrincipal *principalList,int tipo, float precio, int id, char nombre[], char direccion[], int indice);
int princ_askForId (ePrincipal *principalList, int lenghtPrincipal);



#endif /* ESTRUCTURAPRINCIPAL_H_ */
