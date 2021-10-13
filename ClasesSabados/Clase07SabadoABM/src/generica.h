/*
 * generica.h
 *
 *  Created on: 9 oct 2021
 *      Author: Nacho
 */

#ifndef GENERICA_H_
#define GENERICA_H_
typedef struct
{
	int id;
	char descripcion [50];
	int idRelacion;
	int isEmpty;

}eGenerico;

int eGenerico_AltaDatos(eGenerico*lista,int tamGenerico, eDatoRelacion listaRelacion[], int tamRelacion);
int buscarLibre (eGenerico* lista,int tam);
void inicializarArray (eGenerico* lista,int tam);
void eGenerico_MostrarDatos(eGenerico*list,int tamano);

#endif /* GENERICA_H_ */
