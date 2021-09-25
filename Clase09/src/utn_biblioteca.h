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
#include <string.h>
#include "utn_biblioteca.h"

float utn_dividir (int operador1,int operador2,float*direccionVariable);
int utn_pedirFloatAUsuario(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError);
//ponindo utn_ se accede mas rapido a la funcion
int utn_pedirIntAUsuario(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError);
int utn_pedirCharAUsuario(char* pResultado, char min, char max, int reintentos, char* variableTexto, char* textoError);
void imprimirArray (int *pArray, int len);
void imprimirArrayEdadesVersionDos(int edades[], int len);
void utn_inicializarArrayFloat(float array[], int len, int valorInicial);
int utn_pedirTextoAUsuario(char pResultado[],int lenght, char* variableTexto, char* textoError);

#endif /* UTN_BIBLIOTECA_H_ */
