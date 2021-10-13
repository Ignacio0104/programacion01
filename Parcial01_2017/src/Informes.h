/*
 * Informes.h
 *
 *  Created on: 13 oct 2021
 *      Author: Nacho
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include "Contratacion.h"
#include "Pantallas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INACTIVO 1
#define ACTIVO 0



int imprimirPantallasPorCuit (eContratacion*contList, int lenght, float cuit,eDisplay *displaysList,int lenghtDisplay);

#endif /* INFORMES_H_ */
