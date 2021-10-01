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
	int perimetro;

}eTriangulo;


void trianguloMostrarValor(eTriangulo unTriangulo);
void trianguloMostrarPorReferencia (eTriangulo * pUnTriangulo);
int trianguloCarga (eTriangulo * pUnTriangulo);
int trianguloPerimetro(eTriangulo * pUnTriangulo);
int trianguloArea(eTriangulo* pUnTriangulo);
int cargaTriangulosLista (eTriangulo cadena[],int largo,eTriangulo * pUnTriangulo);

#endif /* TRIANGULOS_H_ */
