/*
 * Arcade.h
 *
 *  Created on: 16 oct 2021
 *      Author: Nacho
 */

#ifndef ARCADE_H_
#define ARCADE_H_
#include <stdio.h>
#include <stdlib.h>

#include "biblioteca_input.h"

typedef struct {

	char nationality[128];
	int soundType;
	int numberOfPlayers;
	int maximumTokens;
	int idSalon;
	char gameName[63];
	int idArcade;

}eArcade;

eArcade* arcade_nuevo (void);
int arc_initList(eArcade *arcadeList[],int lenghtArcade);
int arc_loadArcade(eArcade *pArcade, int idIngresada);
int arc_buscarDisponible(eArcade *arcadeList[], int lenghtArcade);
int arc_askForId (void);
int arc_buscarPorId (eArcade *arcadeList[], int lenghtArcade, int idIngresada);
int arc_imprimirCompleto(eArcade *arcadeList[], int lenghtArcade);
int arc_remove (eArcade *arcadeList[], int lenghtArcade, int idIngresada);
void arc_altaForzada(eArcade *pArcade,char nacionalidad[], int tipoSonido, int jugadores, int capacidad, int idSalon,char nombre[], int idArcade);
int arc_subMenuModificaciones (void);
int arc_modificarArcade(eArcade *arcadeList[],int lenghtArcade, int idIngresada);
int arc_validarNombreRepetido (eArcade *arcadeList[], int lenghtArcade, char nombreJuego[]);
int arc_modificarNombreRepetido(eArcade *arcadeList[], int lenghtArcade, char nombreJuego[], int posicionPedida);
int arc_imprimirJuegosSinRepetir (eArcade *arcadeList[], int lenghtArcade);
int arc_ordenarArcades (eArcade *arcadeList[], int lenghtArcade, int order);
int arc_removePorSalon (eArcade *arcadeList[], int lenghtArcade, int idIngresada);
int arc_occupancy (eArcade *arcadeList[], int lenghtArcade, int* pNotEmpty);
int arc_cambiarTexto (eArcade *arcadeList[], int posicion, char pTextoConvertido[]);



#endif /* ARCADE_H_ */
