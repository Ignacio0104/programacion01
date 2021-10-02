/*
 ============================================================================
Serie
idSerie
descripcion
cantidadTemporadas

Genero
idGenero
descripcion
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "SerieGenero.h"

int main(void) {

	setbuf(stdout,NULL);

	eSerie series[5]=
	{
			{100,"La casa de papel",4,1},
			{101,"WandaVision",2,3},
			{102,"El juego del Calamar",5,2},
			{103,"Evangelion",2,3},
			{104,"Hannibal",3,2}
	};

	eGenero generos [3]=
	{
			{1,"Accion"},{2,"Terror"},{3,"Ciencia Ficción"}
	};

	MostrarSeriesConSuGenero(series, 5, generos, 3);

	MostrarListadoDeGenerosConSusSeries(generos, series, 3, 5);

	return EXIT_SUCCESS;
}


