/*
 * biblioteca_arrays.h
 *
 *  Created on: 28 sept 2021
 *      Author: Nacho
 */

#ifndef BIBLIOTECA_ARRAYS_H_
#define BIBLIOTECA_ARRAYS_H_
#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cargarArrayEnteros(int numeros[], int reintentos , int tamano,char* variableTexto,char* textoError);
int imprimirArray (int *pArray, int len);
void imprimirElemento (int elemento, int indice);
int modificarArray (int pArray[], int indice, int modificacion);
int ordenarArray (int pArray[],int tamano);

#endif /* BIBLIOTECA_ARRAYS_H_ */
