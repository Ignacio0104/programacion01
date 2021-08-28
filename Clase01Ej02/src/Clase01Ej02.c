/*
 ============================================================================
 Name        : Clase01Ej02.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Pedir 5 números e imprimir el promedio

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL);

	int numero;
	int acumuladorNumero;
	int promedio;
	int i;

	acumuladorNumero=0;

	for(i=0;i<5;i++)
	{
		printf("Ingrese un número: ");

		scanf("%d",&numero);

		acumuladorNumero=acumuladorNumero+numero;

	}

	promedio=acumuladorNumero/i;

	printf("La suma de los números ingresados es: %d \n",acumuladorNumero);
	printf("El promedio de los números ingresados es de: %d",promedio);


	return EXIT_SUCCESS;
}
