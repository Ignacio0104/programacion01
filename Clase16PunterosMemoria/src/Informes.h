/*
 * Informes.h
 *
 *  Created on: 13 oct 2021
 *      Author: Nacho
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "biblioteca_input.h"
#include "Contratacion.h"
#include "Pantallas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INACTIVO 1
#define ACTIVO 0

int imprimirPantallasPorCuit (eContratacion*contList, int lenght, float cuit,eDisplay *displaysList,int lenghtDisplay);
int menuOperaciones (void);
float calcularFacturacionPorCuit (eContratacion*contList, int lenght, float cuit,eDisplay *displaysList,int lenghtDisplay);
float imprimirFacturacionPorCliente (eContratacion*contList, int lenght,eDisplay *displaysList,int lenghtDisplay);
int info_calcularDeudaCliente(eContratacion*contList, int lenght,eDisplay *displaysList,int lenghtDisplay,float auxiliarCuit, float* deuda);
#endif /* INFORMES_H_ */
