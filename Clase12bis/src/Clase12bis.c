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
#define DISPLAYS_LEN 20


int main(void) {

	setbuf(stdout,NULL);

	int posicionLibre;

	int i;
	int seguir;

	i=0;

	eDisplay displaysList [DISPLAYS_LEN];

	disp_initList(displaysList,DISPLAYS_LEN);


	printf("Desea cargar? 1 si 0 no");
	scanf("%d",&seguir);

	while(i<DISPLAYS_LEN&&seguir==1)
	{

		buscarDisponible(displaysList, &posicionLibre, DISPLAYS_LEN);

		printf("La posicion es %d\n",posicionLibre);

		disp_loadDisplay(&displaysList[posicionLibre]);

		i++;
		printf("Desea cargar? 1 si 0 no");
		scanf("%d",&seguir);
	}


	imprimirCompleto(displaysList,DISPLAYS_LEN);

	modificarPantalla(displaysList,DISPLAYS_LEN);


	return EXIT_SUCCESS;
}
