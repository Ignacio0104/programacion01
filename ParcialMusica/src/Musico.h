/*
 * Pantallas.h
 *
 *  Created on: 30 sept 2021
 *      Author: Nacho
 */

#ifndef MUSICO_H_
#define MUSICO_H_
#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

	char name[128];
	char lastName[128];
	int edad;
	int idOrquesta;
	int idInstrumento;
	int flagEmpty; //0=ocupado 1=libre

}eMusico;

int music_initList(eMusico *musicList,int lenghtMusic);
int music_buscarDisponible(eMusico* musicList, int lenghtMusic);
int music_loadCont(eMusico *pMusico, int idPantalla);
int music_buscarPorCuit (eMusico *musicList, int lenghtMusic, float cuitIngresado);
int music_remove (eMusico*musicList, int lenghtMusic, int idIngresada);
int music_imprimirCompleto(eMusico *musicList, int lenghtMusic);
void music_altaForzada(eMusico *musicList,char nombre[],char apellido[], int edad, int orquesta, int instrumento, int indice);
float music_askForCuit ();
int music_buscarPorId (eMusico *musicList, int lenghtMusic, int idIngresada);
int music_askForId ();
int music_modificarEdad(eMusico *musicList,int lenghtMusic, int idIngresada);
int subMenu (void);
int music_modificarOrquesta(eMusico *musicList,int lenghtMusic, int idIngresada);
int music_removePorOrquesta (eMusico*musicList, int lenghtMusic, int idIngresada);
int ordenarMusicos (eMusico *musicList, int lenghtMusic);

#endif /* PANTALLAS_H_ */
