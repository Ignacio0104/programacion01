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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

	int idCliente;
	int idPantalla;
	float cuitCliente;
	int cantidadDeDias;
	char name[128];
	int flagEmpty; //0=ocupado 1=libre

}eContratacion;

int cont_initList(eContratacion *contList,int lenght);
int cont_buscarDisponible(eContratacion* contList, int lenght);
int cont_loadCont(eContratacion *pCont, int idPantalla);
int cont_buscarPorCuit (eContratacion *contList, int lenght, float cuitIngresado);
int cont_remove (eContratacion*contList, int lenght, int idIngresada);
int cont_imprimirCompleto(eContratacion *contList, int lenght);
void cont_altaForzada(eContratacion *contList,int idCliente, int id, float cuit, int dias, char nombre[], int indice);
float askForCuit ();
int cont_buscarPorId (eContratacion *contList, int lenght, int idIngresada);
int cont_askForId ();
int cont_modificarContratacion(eContratacion *contList,int lenght, int idIngresada);


#endif /* PANTALLAS_H_ */
