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
	int flagEmpty;

}eArcade;


/// \fn int arc_initList(eArcade*, int)
/// \brief  Iniciliza todos los lugares de la lista en INACTIVO
///
/// \param arcadeList recibe la lista a recorrer
/// \param lenghtArcade recibe la longitud de la lista
/// \returnDevuelve 0 si todo OK o -1 sin algo salio mal [lista o longitud invalida]
int arc_initList(eArcade *arcadeList,int lenghtArcade);



/// \fn int arc_loadArcade(eArcade*, int)
/// \brief Solicita los datos y los asigna a las posiciones indicadas de la estructura
///
/// \param pArcade recibe el puntero a la posicion libre de la estructura
/// \param idIngresada recibe la ID del salon asociado al arcade
/// \returnDevuelve 0 si no hubo error o -1 si hubo error [lista o longitud invalida o datos invalidos]
int arc_loadArcade(eArcade *pArcade, int idIngresada);



/// \fn int arc_buscarDisponible(eArcade*, int)
/// \brief Busca una posicion libre en el array
///
/// \param arcadeList recibe la lista a recorrer
/// \param lenghtArcade recibe la longitud de la lista
/// \return Devuelve -1  [lista o longitud invalida], -2 si no hay lugar libre o 0 si no hubo error
int arc_buscarDisponible(eArcade *arcadeList, int lenghtArcade);


/// \fn int arc_askForId(void)
/// \brief Pide un numero y valida que esté dentro de los parametros establecidos
/// \return Devuelve el ID o -1 si hubo error
int arc_askForId (void);



/// \fn int arc_buscarPorId(eArcade*, int, int)
/// \brief Busca en la estructura la posicion que coincida con id ingresado
/// \param arcadeList recibe la lista a recorrer
/// \param lenghtArcade recibe la longitud de la lista
/// \param idIngresada numero de id ingresada por el usuario
/// \return Devuelve posicion del array o -1 si hubo error
int arc_buscarPorId (eArcade *arcadeList, int lenghtArcade, int idIngresada);



/// \fn int arc_imprimirCompleto(eArcade*, int)
/// \brief Recorre el array e imprime todos los elementos
///
/// \param arcadeList recibe la longitud de la lista
/// \param lenghtArcade recibe la longitud de la lista
/// \return Devuelve 0 si no hubo error o -1 si hubo error
int arc_imprimirCompleto(eArcade *arcadeList, int lenghtArcade);



/// \fn int arc_remove(eArcade*, int, int)
/// \brief  Recibe ID, la busca en el array y cambiar el flagEmpty a INACTIVO
///
/// \param arcadeList recibe la longitud de la lista
/// \param lenghtArcade recibe la longitud de la lista
/// \param idIngresada numero de id ingresada por el usuario
/// \return
int arc_remove (eArcade *arcadeList, int lenghtArcade, int idIngresada);



/// \fn void arc_altaForzada(eArcade*, char[], int, int, int, int, char[], int, int)
/// \brief Funcion de alta forzada para testear funciones
///
/// \param pArcade array de la estructura a cargar
/// \param nacionalidad cadena a cargar
/// \param tipoSonido numero a cargar
/// \param jugadores numero a cargar
/// \param capacidad numero a cargar
/// \param idSalon numero a cargar
/// \param nombre cadena a cargar
/// \param idArcade numero a cargar
/// \param indice donde cargarlo
void arc_altaForzada(eArcade *pArcade,char nacionalidad[], int tipoSonido, int jugadores, int capacidad, int idSalon,char nombre[], int idArcade, int indice);



/// \fn int arc_subMenuModificaciones(void)
/// \brief Imprime el sub menu para realizar modificaciones y toma un numero
///
/// \return Devuelve la el numero ingresado por el usuario
int arc_subMenuModificaciones (void);



/// \fn int arc_modificarArcade(eArcade*, int, int)
/// \brief Muestra el sub menu de modificaciones y realiza los cambios segun indique el usuario
///
/// \param arcadeList recibe la longitud de la lista
/// \param lenghtArcade recibe la longitud de la lista
/// \param idIngresada numero de id ingresada por el usuario
/// \return Devuelve 0 si no hubo error o -1 si la lista o la longitud son invalidas
int arc_modificarArcade(eArcade *arcadeList,int lenghtArcade, int idIngresada);



/// \fn int arc_validarNombreRepetido(eArcade*, int, char[])
/// \brief Informa si el nombre de juego ingresado está ingresado en el sistema
///
/// \param arcadeList recibe la longitud de la lista
/// \param lenghtArcade recibe la longitud de la lista
/// \param nombreJuego cadena de char ingresada por el usuario
/// \return Devuelve 1 si el nombre está ingresado, -1 si no está repetido
int arc_validarNombreRepetido (eArcade *arcadeList, int lenghtArcade, char nombreJuego[]);



/// \fn int arc_modificarNombreRepetido(eArcade*, int, char[], int)
/// \brief Ante un nombre repetido, se consulta si el usuario quiere ingresarlo nuevamente
///
/// \param arcadeList recibe la longitud de la lista
/// \param lenghtArcade recibe la longitud de la lista
/// \param nombreJuego cadena de char ingresada por el usuario
/// \param posicionPedida recibe la posicion donde se realizará el cambio
/// \return Devuelve 0 si no hubo error o -1 si hubo error.
int arc_modificarNombreRepetido(eArcade *arcadeList, int lenghtArcade, char nombreJuego[], int posicionPedida);



/// \fn int arc_imprimirJuegosSinRepetir(eArcade*, int)
/// \brief Imprime todos los juegos ingresados en el sistema sin repetir
///
/// \param arcadeList recibe la longitud de la lista
/// \param lenghtArcade recibe la longitud de la lista
/// \return Devuelve 0 si no hubo error o -1 si hubo error.
int arc_imprimirJuegosSinRepetir (eArcade *arcadeList, int lenghtArcade);



/// \fn int arc_ordenarArcades(eArcade*, int, int)
/// \brief Ordena los arcades por 2 parametros, id de salon o nombre de juego
///
/// \param arcadeList recibe la longitud de la lista
/// \param lenghtArcade recibe la longitud de la lista
/// \param order numero que indica cual de los 2 parametros se usará para ordenar
/// \return Devuelve 0 si no hubo error o -1 si hubo error.
int arc_ordenarArcades (eArcade *arcadeList, int lenghtArcade, int order);



/// \fn int arc_removePorSalon(eArcade*, int, int)
/// \brief Se activa cuando se borra un salon con id asociada a este arcade. Informa al usuario y pide confirmacion para proceder
///
/// \param arcadeList recibe la longitud de la lista
/// \param lenghtArcade recibe la longitud de la lista
/// \param idIngresada numero de id ingresada por el usuario
/// \return Devuelve 0 si no hubo error o -1 si hubo error.
int arc_removePorSalon (eArcade *arcadeList, int lenghtArcade, int idIngresada);



/// \fn int arc_occupancy(eArcade*, int, int*)
/// \brief  Determina cuantas posicion están ocupadas
///
/// \param arcadeList recibe la longitud de la lista
/// \param lenghtArcade recibe la longitud de la lista
/// \param pNotEmpty puntero a donde se guardará la cantidad de ocupados
/// \return Devuelve -1 si hubo error o 0 si no hubo error
int arc_occupancy (eArcade *arcadeList, int lenghtArcade, int* pNotEmpty);



#endif /* ARCADE_H_ */
