/*
 ============================================================================
 Name        : Clase05Arrays.c
 Author      : Ignacio

Hacer un programa que pida al usuario 10 int y 10 char, con array.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_biblioteca.h"

int main(void) {

	setbuf(stdout,NULL);
	float arrayNumeros[5];

	for (int i=0;i<5;i++)
	{
		utn_pedirFloatAUsuario(&arrayNumeros[i],-10.00,8000.00,2,"Ingrese un numero: \n","Error! fuera de rango");
	}

	for (int i=0;i<5;i++)
	{
		printf("\n En la posición i %d está el número %.2f",i,arrayNumeros[i]);
	}


	return EXIT_SUCCESS;
}
