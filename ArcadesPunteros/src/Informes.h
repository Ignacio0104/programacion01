/*
 * Informes.h
 *
 *  Created on: 16 oct 2021
 *      Author: Nacho
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "biblioteca_input.h"
#include "Arcade.h"
#include "Salon.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INACTIVO 1
#define ACTIVO 0


int menuOperaciones (void);
char info_subMenuReports (void);
int info_contarArcades (eArcade *arcadeList, int lenghtArcade,eSalon *salonList[],int lenghtSalon);
int info_contarJugadores (eArcade *arcadeList, int lenghtArcade,eSalon *salonList[],int lenghtSalon);
int info_imprimirSalonPorId (eArcade *arcadeList, int lenghtArcade,eSalon *salonList[],int lenghtSalon, int idIngresada);
int info_imprimirArcadePorId (eArcade *arcadeList, int lenghtArcade,eSalon *salonList[],int lenghtSalon, int idIngresada);
int info_imprimirSalonMasArcade (eArcade *arcadeList, int lenghtArcade,eSalon *salonList[],int lenghtSalon);
int info_calcularFichasTotal (int idIngresada, eArcade *arcadeList, int lenghtArcade,eSalon *salonList[],int lenghtSalon);
float info_calcularGananciaTotal (int idIngresada, float valorFicha,eArcade *arcadeList, int lenghtArcade,eSalon *salonList[],int lenghtSalon);
int info_juegoEnArcades (eArcade *arcadeList, int lenghtArcade, char nombreJuego[]);
int info_imprimirInformes (eArcade *arcadeList, int lenghtArcade,eSalon *salonList [],int lenghtSalon, char eleccionUsuario);
int info_arcadesCompletos (eArcade *arcadeList, int lenghtArcade,eSalon *salonList[],int lenghtSalon);
float info_promedioDeArcades (eArcade *arcadeList, int lenghtArcade,eSalon *salonList[],int lenghtSalon);
#endif /* INFORMES_H_ */
