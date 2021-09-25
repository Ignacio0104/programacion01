/*
 ============================================================================
 Name        : Clase09.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn_biblioteca.h"

int main(void) {

	setbuf(stdout,NULL);

	int numero;

	//HACER EL PEDIRFLOATUSUARIO


	if(utn_pedirIntAUsuario(&numero, 1, 120, 3, "Ingrese la edad", "Error")==0)
	{
		printf("Tu edad es: %d", numero);
	}



	/*char cadena[8];


	if(utn_pedirTextoAUsuario(cadena,sizeof(cadena), 3, "Ingresa tu nombre", "Error")==0)
	{
		printf("El numero es %s",cadena);
	}*/


	return EXIT_SUCCESS;
}


