/*
 ============================================================================
 Name        : Clase11.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include "Pantallas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DISPLAYS_LEN 100


int main(void) {

	setbuf(stdout,NULL);

	eDisplay displaysList [DISPLAYS_LEN];

	disp_initList(displaysList,DISPLAYS_LEN);

	disp_loadDisplay(displaysList);

	//TAREA!!!!
	//Hacer funcion para buscar lugar libre en el array.
	//Hacer funcion para modificar: Pedir un ID y realizar funcion que busque por ID. Llamar a funcion que modifica

	disp_print(displaysList,DISPLAYS_LEN);


	return EXIT_SUCCESS;
}
