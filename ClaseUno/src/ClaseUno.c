/*
 ============================================================================
 Name        : ClaseUno.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL); //Hay que ponerlo siempre, para que empiece de cero.
	/*printf("Esta es la primera clase");

	int numero;
	int suma;

	printf("\n Ingrese el numero: \n");
	scanf("%d",&numero);

	suma=numero+numero;

	printf("La suma del n?mero es: %d ",suma);

	if(numero>17)
	{
		printf("\n Sos mayor de edad");
	}*/

	int numero;
	int acumulador;
	int contador;
	char letra = 's';

	acumulador=0;
	contador=0;

	printf("\n Quiere ingresar un numero? \n");
	fflush(stdin); //Limpiar el buffer
	scanf("%c",&letra);

	while(letra=='s')
	{
		printf("\n Ingrese el n?mero: ");
		scanf("%d",&numero);
		acumulador=acumulador+numero;
		contador=contador+1;
		printf("\n Quiere ingresar un numero? \n");
		fflush(stdin);
		scanf("%c",&letra);
	}

	printf("\n La suma total es de: %d \n ",acumulador);
	printf("La cantidad de numeros ingresados es de: %d",contador);



	return EXIT_SUCCESS;
}
