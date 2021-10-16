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
#include "biblioteca_input.h"

typedef struct {

	char name[128];
	char address[128];
	int type;
	int idSalon;
	int flagEmpty;

}eSalon;


int salon_initList(eSalon *salonList,int lenghtSalon);
int salon_loadSalon(eSalon *pSalon);
int salon_buscarDisponible(eSalon *salonList, int lenghtSalon);
int salon_askForId (void);
int salon_buscarPorId (eSalon *salonList, int lenghtSalon, int idIngresada);
int menuOperaciones (void);
int salon_imprimirCompleto(eSalon *salonList, int lenghtSalon);
int salon_remove (eSalon *salonList, int lenghtSalon, int idIngresada);

#endif /* SALON_H_ */
