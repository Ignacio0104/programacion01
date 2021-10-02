/*
 * SerieGenero.c
 *
 *  Created on: 2 oct 2021
 *      Author: Nacho
 */

#include "Genero.h"
#include "Serie.h"
#include <stdio.h>
#include <stdlib.h>


void MostrarSeriesConSuGenero (eSerie listaSeries[], int tamanioSeries, eGenero listaGeneros[], int tamanioGeneros) {

    for (int i = 0; i < tamanioSeries; i++) {

        for (int j = 0; j < tamanioGeneros; j++) {

            if (listaSeries[i].idGenero == listaGeneros[j].idGenero) {
                printf("%d %-30s %d %4s\n", listaSeries[i].idSerie, listaSeries[i].descripcion, listaSeries[i].cantidadTemporadas,
                                        listaGeneros[j].descripcion);

            }

        }
    }

}

void MostrarListadoDeGenerosConSusSeries (eGenero listaGenero[],eSerie listaSerie[], int tamanoGenero, int tamanoSerie)
{

	for(int i=0;i<tamanoGenero;i++)
	{
		printf("%s: \n",listaGenero[i].descripcion);
		for(int j=0;j<tamanoSerie;j++)
		{
			if(listaGenero[i].idGenero==listaSerie[j].idGenero)
			{
				printf("%d %-30s %d \n", listaSerie[j].idSerie, listaSerie[j].descripcion, listaSerie[j].cantidadTemporadas);
			}
		}


	}
}
