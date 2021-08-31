/*
 ============================================================================
Escribir un programa que realice las siguientes acciones:

- Solicite al usuario 10 números
- Calcule cuántos son negativos y cuantos son positivos
- Muestre por pantalla la cantidad de negativos y la cantidad de positivos
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	int numeroIngresado;
	int i;
	int contadorNegativos;
	int contadorPositivos;


	contadorNegativos=0;
	contadorPositivos=0;

	for(i=0;i<10;i++)
	{
		printf("Ingrese un número: ");
		scanf("%d",&numeroIngresado);

		if(numeroIngresado>0)
		{
			contadorPositivos+=1;
		} else
		{
			if (numeroIngresado<0)
			{
				contadorNegativos+=1;
			}
		}
	}

	printf("La cantidad de números negativos es %d \nY la cantidad de positivios es %d.",contadorNegativos,contadorPositivos);

	return EXIT_SUCCESS;
}
