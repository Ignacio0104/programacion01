/*
 ============================================================================
 Name        : Clase06.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_biblioteca.h"
#define EDADES_LEN 5
void imprimirArrayEdades(int edades[], int len);
void imprimirArrayEdadesVersionDos(int edades[], int len);
void inicializarArrayEdades(int edades[], int len, int valorInicial);

int main(void) {

	setbuf(stdout,NULL);
	int edades[EDADES_LEN];  //={0,0,0,0,0};


	inicializarArrayEdades(edades,EDADES_LEN,0);

	imprimirArrayEdades(edades,EDADES_LEN);

	imprimirArrayEdadesVersionDos(edades,EDADES_LEN);


	return EXIT_SUCCESS;
}



void imprimirArrayEdadesVersionDos(int edades[], int len)
{
	int indice;

	for (indice=0;indice<EDADES_LEN;indice++)
		{
			printf("%d\n",edades[indice]);

		}

}


void imprimirArrayEdades (int *pArrayEdades, int len) //(int pArrayEdades []) sintaxis alternativa
{
	int indice;

	for (indice=0;indice<EDADES_LEN;indice++)
		{
			printf("%d\n",pArrayEdades[indice]);

		}

}

void inicializarArrayEdades(int edades[], int len, int valorInicial)
{
	int indice;
	for (indice=0;indice<len;indice++)
		{
			edades[indice]=indice+50;

		}
}




