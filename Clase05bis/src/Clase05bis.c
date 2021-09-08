/*
 ============================================================================
 Name        : Clase05bis.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn_biblioteca.h"
#define REINTENTOS 3 //Define dentro de la biblioteca, acá no. Y no sirve en c. Mejor no usar define

//02/09 mensajes por SLACK, código ejemplo

int main(void) {

	setbuf(stdout,NULL);
	char ingresoUno;
	//char ingresoDos;

	if(utn_pedirCharAUsuario(&ingresoUno,'a','z',REINTENTOS,"Ingrese la letra: ", "Letra inválida")==0)
	{
		printf("Salio todo bien!");

		} else
		{
			printf("\nSe acabaron los intentos.");
		}


	return EXIT_SUCCESS;
}

//Static, darle privacidad a las funciones

