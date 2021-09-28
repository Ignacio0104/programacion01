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

	int cadena[10];

	cargarArrayEnteros(cadena,10,"Ingrese un numero","Error");
	imprimirArray (cadena, 10);
	ordenarArray (cadena,10);
	imprimirArray (cadena, 10);

	return EXIT_SUCCESS;
}



