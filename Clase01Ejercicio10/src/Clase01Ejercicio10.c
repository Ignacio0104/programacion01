/*
 ============================================================================
 Name        : Clase01Ejercicio10.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Escribir un programa que realice las siguientes acciones:

- Solicite al usuario 10 n?meros
- Calcule cu?ntos son negativos y cuantos son positivos
- Muestre por pantalla la cantidad de negativos y la cantidad de positivos

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	int numero;
	int acumuladorPositivos;
	int acumuladorNegativos;
	int i;

	acumuladorPositivos=0;
	acumuladorNegativos=0;

	for(i=0;i<10;i++)
	{
		printf("Ingrese un n?mero: ");
		scanf("%d",&numero);

		if(numero>0)
		{
			acumuladorPositivos=acumuladorPositivos+1;
		} else
		{
			acumuladorNegativos=acumuladorNegativos+1;
		}
	}

	printf("Se ingresaron %d n?meros positivos y %d n?meros negativos",acumuladorPositivos,acumuladorNegativos);

	return EXIT_SUCCESS;
}
