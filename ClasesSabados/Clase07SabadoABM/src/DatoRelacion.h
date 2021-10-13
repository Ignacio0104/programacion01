/*
 * DatoRelacion.h
 *
 *  Created on: 9 oct 2021
 *      Author: Nacho
 */

#ifndef DATORELACION_H_
#define DATORELACION_H_

typedef struct
{
	int idRelacion;
	int valor;
	int isEmpty;
}eDatoRelacion;

void eDetaRelacion_MostrarDatos(eDatoRelacion*list,int tamano);

#endif /* DATORELACION_H_ */
