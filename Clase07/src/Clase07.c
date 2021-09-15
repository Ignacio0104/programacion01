/*
 ============================================================================
 Name        : Clase07.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "utn_biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#define QY_COD_AREA 5

int main(void) {

	setbuf(stdout,NULL);

	int codigosArea[QY_COD_AREA] = {5,4,3,2,1};
	int cantidadDeVueltas;

	imprimirArray (codigosArea, QY_COD_AREA);

	cantidadDeVueltas=ordenarArray (codigosArea, QY_COD_AREA);

	if(cantidadDeVueltas==1)
	{
		printf("Estaba todo ordenado");
	}

	printf("\n");
	imprimirArray (codigosArea, QY_COD_AREA);

	printf("\n La cantidad de vueltas fue %d",cantidadDeVueltas);

	return EXIT_SUCCESS;
}


/*

 >>>Resulucion propia

int main(void) {

	setbuf(stdout,NULL);
	int i;
	int flagPrimerIngreso;
	int recorridos;
	int indiceDelMayor;

	flagPrimerIngreso=1;
	recorridos=0;

	int arrayOrdenado[QY_COD_AREA];

	int codigosArea[QY_COD_AREA] = {23,56,102,65,0};

	imprimirArray (codigosArea, QY_COD_AREA);

    while(recorridos<5)
    {
    	int maximo;
    	flagPrimerIngreso=1;
		for(i=0;i<QY_COD_AREA;i++)
		{
			if(flagPrimerIngreso==1||codigosArea[i]>maximo)
			{
				maximo=codigosArea[i];
				indiceDelMayor=i;
				flagPrimerIngreso=0;
			}

		}

		arrayOrdenado[recorridos]=maximo;

		codigosArea[indiceDelMayor]=0;

		recorridos+=1;

    }

    printf("\n\n\n");
	imprimirArray (arrayOrdenado, QY_COD_AREA);


	return EXIT_SUCCESS;
}*/

