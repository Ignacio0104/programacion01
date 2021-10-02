/*
 * SerieGenero.h
 *
 *  Created on: 2 oct 2021
 *      Author: Nacho
 */

#ifndef SERIEGENERO_H_
#define SERIEGENERO_H_
#include "Genero.h"
#include "Serie.h"
#include <stdio.h>
#include <stdlib.h>


void MostrarSeriesConSuGenero (eSerie listaSeries[], int tamanioSeries, eGenero listaGeneros[], int tamanioGeneros);
void MostrarListadoDeGenerosConSusSeries(eGenero listaGenero[],eSerie listaSerie[], int tamanoGenero, int tamanoSerie);


#endif /* SERIEGENERO_H_ */
