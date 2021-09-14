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


void cargarArrayEnteros(int numeros[],int tamano, int max, int minimo,char* variableTexto,char* textoError);
int utn_pedirIntSinIntentos(char* variableTexto, char* textoError, int maximo, int minimo);
void imprimirArray (int *pArray, int len);
int esPar (int numero);
int sumarPares (int numeros[], int tamano, int* pMayorImpar);
int negativoPositivo (int numero);
int contadorNegativosPositivos (int numeros[], int tamano, int* pContadorNegativos, int* pContadorPositivos);
void imprimirArrayDePares (int *pArray, int len);




#endif /* UTN_BIBLIOTECA_H_ */
