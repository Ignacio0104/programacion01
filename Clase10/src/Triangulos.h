/*
 * Triangulos.h
 *
 *  Created on: 28 sept 2021
 *      Author: Nacho
 */

#ifndef TRIANGULOS_H_
#define TRIANGULOS_H_
#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

	int ladoUno;
	int ladoDos;
	int ladoTres;

}eTrianguloEscaleno;


void trianguloMostrarValor(eTrianguloEscaleno unTriangulo);
void trianguloMostrarPorReferencia (eTrianguloEscaleno * pUnTriangulo);
int trianguloCarga (eTrianguloEscaleno * pUnTriangulo);
int trianguloPerimetro(eTrianguloEscaleno * pUnTriangulo);
int trianguloArea(eTrianguloEscaleno * pUnTriangulo);
int cargaTriangulosLista (eTrianguloEscaleno cadena[],int largo,eTrianguloEscaleno * pUnTriangulo);

#endif /* TRIANGULOS_H_ */
