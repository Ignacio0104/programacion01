/*
 ============================================================================
Proyecto para crear funciones y agruparlas.
 ============================================================================
 */
#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void) {

	setbuf(stdout,NULL);

	char texto[40];
	int retorno;

	retorno=pedirTexto(texto,40, 5, "Ingrese el texto", "Error");

	printf("El retorno fue %d y el texto %s",retorno,texto);


	return EXIT_SUCCESS;
}



