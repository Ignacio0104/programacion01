/*
 ============================================================================
 Name        : Clase11.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
//#include "biblioteca_arrays.h"
//#include "Pantallas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DISPLAYS_LEN 100


int main(void) {

	setbuf(stdout,NULL);
/*
	eDisplay displaysList [DISPLAYS_LEN];

	disp_initList(displaysList,DISPLAYS_LEN);

	disp_loadDisplay(displaysList);

	disp_print(displaysList,DISPLAYS_LEN);*/

	char texto [100];
	int retorno;

	retorno=pedirTexto(texto,100, "Ingrese texto", "Texto");

	printf("El retorno es %d",retorno);

	printf("El texto es %s",texto);


	return EXIT_SUCCESS;
}
