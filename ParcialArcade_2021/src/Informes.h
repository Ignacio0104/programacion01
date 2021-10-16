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
int info_contarArcades (eArcade *arcadeList, int lenghtArcade,eSalon *salonList,int lenghtSalon);


#endif /* INFORMES_H_ */
