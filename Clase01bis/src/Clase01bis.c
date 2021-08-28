/*
 ============================================================================
 Name        : Clase01bis.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define CLIENTES 3 //Algo parecido al concepto de constante

int main(void) {
	setbuf(stdout,NULL);

	int numeroUno;
	int suma;
	int i;

	suma=0;

	for(i=0;i<CLIENTES;i++)
	{
		printf("\n Ingrese el numero: \n");
		scanf("%d",&numeroUno);
		suma = suma + numeroUno;
	}

	printf("\nLa suma del numero es: %d",suma);
}
