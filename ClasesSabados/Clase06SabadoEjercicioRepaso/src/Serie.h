/*
 * Serie.h
 *
 *  Created on: 2 oct 2021
 *      Author: Nacho
 */

#ifndef SERIE_H_
#define SERIE_H_
#include "Genero.h"

typedef struct
{
	int idSerie;
	char descripcion[50];
	int cantidadTemporadas;
	//eGenero genero; //Se añidan con otra estructura, pero es redundante. Poco performante
	int idGenero; //Anidamiento de estructuras

}eSerie;




#endif /* SERIE_H_ */
