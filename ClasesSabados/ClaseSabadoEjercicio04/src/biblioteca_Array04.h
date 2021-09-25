/*
 * biblioteca_Array04.h
 *
 *  Created on: 20 sept 2021
 *      Author: Nacho
 */

#ifndef BIBLIOTECA_ARRAY04_H_
#define BIBLIOTECA_ARRAY04_H_
#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_Array04.h"

int cargarArray (int cadena[], int lenght, int exclusion,char* mensajeUsuario, char*mensajeError);
int pedirNumeroExcluyente(int exclusion, char* mensajeUsuario, char*mensajeError);
void imprimirArray (int cadena[], int lenght);
int ordenarArray (int cadena[], int lenght);
int imprimirArrayCondicional (int cadena[], int lenght, int condicion);
int ordenarArrayNegativos (int cadena[], int lenght);
int mayorDeLosPrimos (int cadena[], int lenght, int* pMayorPrimo);
int evaluarRepetidos (int cadena[], int lenght);


#endif /* BIBLIOTECA_ARRAY04_H_ */
