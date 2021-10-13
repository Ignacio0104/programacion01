/*
 * biblioteca_input.h
 *
 *  Created on: 28 sept 2021
 *      Author: Nacho
 */

#ifndef BIBLIOTECA_INPUT_H_
#define BIBLIOTECA_INPUT_H_
#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int pedirFloatIntentosRango(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError);
int pedirIntIntentosRango(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError);
int pedirCharAUsuarioIntentosRango(char* pResultado, char min, char max, int reintentos, char* variableTexto, char* textoError);
int pedirTextoAUsuario(char pResultado[],int lenght, char* variableTexto, char* textoError);
int pedirCharAUsuarioIntentosRango(char* pResultado, char min, char max, int reintentos, char* variableTexto, char* textoError);
int pedirFloat(float* pResultado, int reintentos, char* variableTexto, char* textoError);
int pedirInt(int* pResultado, int reintentos, char* variableTexto, char* textoError);
int pedirTexto(char pResultado[],int lenght, int reintentos, char* variableTexto, char* textoError);
int pedirChar(char* pResultado, int reintentos, char* variableTexto, char* textoError);
int pedirCharSiNo(char* pResultado, char opcion1, char opcion2, int reintentos, char* variableTexto, char* textoError);



#endif /* BIBLIOTECA_INPUT_H_ */
