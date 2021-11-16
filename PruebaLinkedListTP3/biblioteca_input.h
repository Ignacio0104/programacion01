/*
 * biblioteca_input.h
 *
 *  Created on: 28 sept 2021
 *      Author: Nacho
 */

#ifndef BIBLIOTECA_INPUT_H_
#define BIBLIOTECA_INPUT_H_
#include "biblioteca_input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// \fn int pedirFloatIntentosRango(float*, float, float, int, char*, char*)
/// \brief Pide al usuario un numero dentro de los limites e intentos indicador. Valida si es numero (int o float)
/// \param pResultado * puntero a la variable donde se guardara el numero
/// \param min recibe el menor valor posible
/// \param max recibe el mayor valor posible
/// \param reintentos receives la cantidad de intentos
/// \param variableTexto recibe el texto que verá el usuario
/// \param textoError recibe el texto que verá el usuario al equivocarse
/// \return Return 0 si  salio bien. -1 si algunos de los parametros es invalido, o el sistema no pudo procesar el input del usuario
int pedirFloatIntentosRango(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError);



/// \fn int pedirIntIntentosRango(int*, int, int, int, char*, char*)
/// \brief Pide al usuario un numero dentro de los limites e intentos indicador. Valida si es numero (int o float)
/// \param pResultado * puntero a la variable donde se guardara el numero
/// \param min recibe el menor valor posible
/// \param max recibe el mayor valor posible
/// \param reintentos receives la cantidad de intentos
/// \param variableTexto recibe el texto que verá el usuario
/// \param textoError recibe el texto que verá el usuario al equivocarse
/// \return Return 0 si  salio bien. -1 si algunos de los parametros es invalido, o el sistema no pudo procesar el input del usuario
int pedirIntIntentosRango(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError);



/// \fn int pedirCharAUsuarioIntentosRango(char*, char, char, int, char*, char*)
/// \brief Pide al usuario un char dentro de los limites e intentos indicador. Valida si es texto
/// \param pResultado * puntero a la variable donde se guardara el char
/// \param min recibe el menor valor posible (ASCII)
/// \param max recibe el mayor valor posible (ASCII)
/// \param reintentos recibe la cantidad de intentos
/// \param variableTexto recibe el texto que verá el usuario
/// \param textoError recibe el texto que verá el usuario al equivocarse
/// \return Return 0 si  salio bien. -1 si algunos de los parametros es invalido, o el sistema no pudo procesar el input del usuario
int pedirCharAUsuarioIntentosRango(char* pResultado, char min, char max, int reintentos, char* variableTexto, char* textoError);




/// \fn int pedirFloat(float*, int, char*, char*)
/// \brief Pide al usuario un float dentro del intentos indicados. Valida que sea exclusivamente float
/// \param pResultado * puntero a la variable donde se guardara el float
/// \param reintentos recibe la cantidad de intentos
/// \param variableTexto recibe el texto que verá el usuario
/// \param textoError recibe el texto que verá el usuario al equivocarse
/// \return Return 0 si  salio bien. -1 si algunos de los parametros es invalido, o el sistema no pudo procesar el input del usuario
int pedirFloat(float* pResultado, int reintentos, char* variableTexto, char* textoError);



/// \fn int pedirInt(int*, int, char*, char*)
/// \brief Pide al usuario un int dentro del intentos indicados. Valida que sea numerico
/// \param pResultado * puntero a la variable donde se guardara el int
/// \param reintentos recibe la cantidad de intentos
/// \param variableTexto recibe el texto que verá el usuario
/// \param textoError recibe el texto que verá el usuario al equivocarse
/// \return Return 0 si  salio bien. -1 si algunos de los parametros es invalido, o el sistema no pudo procesar el input del usuario
int pedirInt(int* pResultado, int reintentos, char* variableTexto, char* textoError);



/// \fn int pedirTextoAUsuario(char[], int, char*, char*)
/// \brief Pide al usuario un texto dentro de los intentos indicados. Valida si es texto
/// \param pResultado puntero a la cadena donde se guardara el texto
/// \param lenght longitud maxima del texto
/// \param reintentos recibe la cantidad de intentos
/// \param variableTexto recibe el texto que verá el usuario
/// \param textoError recibe el texto que verá el usuario al equivocarse
/// \return Return 0 si  salio bien. -1 si algunos de los parametros es invalido, o el sistema no pudo procesar el input del usuario
int pedirTexto(char pResultado[],int lenght, int reintentos, char* variableTexto, char* textoError);



/// \fn int pedirChar(char*, int, char*, char*)
/// \brief Pide al usuario un char dentro de los intentos indicados. Valida que sea texto
/// \param pResultado * puntero a la variable donde se guardara el char
/// \param reintentos recibe la cantidad de intentos
/// \param variableTexto recibe el texto que verá el usuario
/// \param textoError recibe el texto que verá el usuario al equivocarse
/// \return Return 0 si  salio bien. -1 si algunos de los parametros es invalido, o el sistema no pudo procesar el input del usuario
int pedirChar(char* pResultado, int reintentos, char* variableTexto, char* textoError);



/// \fn int pedirCharSiNo(char*, char, char, int, char*, char*)
/// \brief Pide al usuario un char dentro de los intentos indicados. Valida que sea texto y una de las 2 opciones
/// \param pResultado * puntero a la variable donde se guardara el char
/// \param opcion1 opcion numero 1 que el usuario puede ingresar
/// \param opcion2 opcion numero 2 que el usuario puede ingresar
/// \param reintentos recibe la cantidad de intentos
/// \param variableTexto recibe el texto que verá el usuario
/// \param textoError recibe el texto que verá el usuario al equivocarse
/// \return Return 0 si  salio bien. -1 si algunos de los parametros es invalido, o el sistema no pudo procesar el input del usuario
int pedirCharSiNo(char* pResultado, char opcion1, char opcion2, int reintentos, char* variableTexto, char* textoError);


int pedirDireccion(char pResultado[],int lenght, int reintentos, char* variableTexto, char* textoError);

int pedirNumeroTxt(char pResultado[],int lenght, int reintentos, char* variableTexto, char* textoError);


int esNumerica (char cadena[]);
int esFloat (char cadena[]);
int esTexto (char cadena[]);
int esAlfaNumerica (char cadena[]);


#endif /* BIBLIOTECA_INPUT_H_ */
