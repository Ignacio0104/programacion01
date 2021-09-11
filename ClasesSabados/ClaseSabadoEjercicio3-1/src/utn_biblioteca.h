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

float utn_dividir (int operador1,int operador2,float*direccionVariable);
int utn_pedirFloatAUsuario(float* pResultado, float min, float max, char* variableTexto, char* textoError);
//ponindo utn_ se accede mas rapido a la funcion
int utn_pedirIntAUsuario(int* pResultado, int min, int max, char* variableTexto, char* textoError);
//int utn_pedirCharAUsuario(char* pResultado, char min, char max, char* variableTexto, char* textoError);
void imprimirArray (int *pArray, int len);
void imprimirArrayEdadesVersionDos(int edades[], int len);
void utn_inicializarArrayFloat(float array[], int len, int valorInicial);
void modificarArray (int pArray[], int indice, int modificacion);
void evaluarNegativosPositivos (int *pContadorNegativos, int *pContadorPositivos, int cadena [], int posicion);
void sumatoriaDePares (int* pAcumulador,int cadena [], int indice);
int mayorDeImpares (int*pMayorDeImpares,int cadena[], int posicion, char* pBandera);


#endif /* UTN_BIBLIOTECA_H_ */
