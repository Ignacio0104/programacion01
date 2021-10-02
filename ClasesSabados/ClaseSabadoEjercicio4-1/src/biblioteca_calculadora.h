/*
 * biblioteca_calculadora.h
 *
 *  Created on: 28 sept 2021
 *      Author: Nacho
 */

#ifndef BIBLIOTECA_CALCULADORA_H_
#define BIBLIOTECA_CALCULADORA_H_
#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float calculadora_dividir (int operador1,int operador2,float*direccionVariable);
float calculadora_sumar (float operadorUno, float operadorDos);
float calculadora_restar (float operadorUno, float operadorDos);
float calculadora_multiplicar (float operadorUno, float operadorDos);
int calculadora_factorial (float operadorUno, int*pResultado);
int mostrarResultado (float operadorUno,float operadorDos,float resultadoOperacion,int retornoOperacion, char*mensajeError, char*operacion);
int mostrarResultadoFact (float operadorUno,int resultadoOperacion,int retornoOperacion, char*mensajeError);

#endif /* BIBLIOTECA_CALCULADORA_H_ */
