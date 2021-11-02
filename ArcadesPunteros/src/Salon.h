/*
 * Salon.h
 *
 *  Created on: 16 oct 2021
 *      Author: Nacho
 */

#ifndef SALON_H_
#define SALON_H_
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "biblioteca_input.h"

typedef struct {

	char name[128];
	char address[128];
	int type;
	int idSalon;

}eSalon;


int salon_initList(eSalon *salonList[],int lenghtSalon);
int salon_loadSalon(eSalon *pSalon);
int salon_buscarDisponible(eSalon *salonList[], int lenghtSalon);
int salon_askForId (void);
int salon_buscarPorId (eSalon *salonList[], int lenghtSalon, int idIngresada);
int salon_imprimirCompleto(eSalon *salonList[], int lenghtSalon);
int salon_remove (eSalon *salonList[], int lenghtSalon, int idIngresada);
void salon_altaForzada(eSalon *pSalon,char nombre[],char direccion[], int tipo);
int salon_occupancy (eSalon *salonList[], int lenghtSalon, int* pNotEmpty);
eSalon* salon_nuevo (void);
int salon_cambiarTexto (eSalon *salonList[], int posicion, char pTextoConvertido[]);

///Setters y getters///

int salon_setName (eSalon* pSalon, char nombre[]);
int salon_getName (eSalon* pSalon, char nombre[]);

int salon_setAddress (eSalon* pSalon, char direccion[]);
int salon_getAddress (eSalon* pSalon, char direccion[]);

int salon_setType (eSalon* pSalon, int tipo);
int salon_getType (eSalon* pSalon, int* tipo);

int salon_setIdSalon(eSalon* pSalon, int idSalon);
int salon_getIdSalon (eSalon* pSalon, int* idSalon);

#endif /* SALON_H_ */
