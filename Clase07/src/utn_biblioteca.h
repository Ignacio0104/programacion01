/*
 * utn_biblioteca.h
 *
 *  Created on: 7 sept 2021
 *      Author: Nacho
 */

#ifndef UTN_BIBLIOTECA_H_
#define UTN_BIBLIOTECA_H_
#include <stdio.h>
#include <stdlib.h>
#include "utn_biblioteca.h"

void cargarArrayEnteros(int numeros[],int tamano,char* variableTexto,char* textoError);
int utn_pedirIntSinIntentos(char* variableTexto, char* textoError);
int imprimirArray (int *pArray, int len);
int esPar (int numero);
void borrarImpares (int *pArray, int len, int reemplazo);
void modificarArray (int pArray[], int indice, int modificacion);
void ordernarArray (int *pArray, int len);
void imprimirElemento (int elemento, int indice);
int ordenarArray (int pArray[],int tamano);

#endif /* UTN_BIBLIOTECA_H_ */
