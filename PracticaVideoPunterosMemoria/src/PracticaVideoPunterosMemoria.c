/*
 ============================================================================
 Name        : PracticaVideoPunterosMemoria.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_input.h"
typedef int (*tSaludar) (char*);

int saludarEsp (char*mensaje)
{
	printf("Hola %s",mensaje);

	return 0;
}


int saludarIng (char*mensaje)
{
	printf("Hello %s",mensaje);

	return 0;
}

void saludo(char*mensaje,tSaludar pSaludar) // Para evitar esto ultimo >>> int (*pSaludar) (char*) >>> Se hace un typedef
{
	pSaludar(mensaje);

}


int main(void) {

	saludo("Esto andaaaaa\n", saludarEsp);
	saludo("This works\n", saludarIng);

	/*int (*pSaludar) (char*);
	pSaludar=saludar;

	if(pSaludar("Holaaa\n")==0)
	{
		printf("Salio todo OK");
	}*/
	return EXIT_SUCCESS;
}
