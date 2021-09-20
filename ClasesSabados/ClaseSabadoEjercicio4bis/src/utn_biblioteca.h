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



int PedirEnteroExcluyente(char mensaje[],char mensajeError[], int numeroExcluyente);
int CargarArrayEnterosExcluyente(int lista[], int tam, char mensaje[],char mensajeError[], int numeroExcluyente);
int MostrarArrayEnteros(int lista[], int tam);
int clasificarNumero(int numeroAClasficiar);
int ordenarArrayEnterosExcluyentes(int lista[], int tam);
int mostrarPrimos(int lista[], int tam);
void mostrarEntero(int entero);
int clasificarPrimos(int numero);




#endif /* UTN_BIBLIOTECA_H_ */
