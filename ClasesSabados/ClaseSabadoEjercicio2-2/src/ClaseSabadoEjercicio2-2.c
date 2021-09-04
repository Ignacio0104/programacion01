/*
 ============================================================================

Realizar un programa que permita el ingreso de 10 números enteros. Determinar el
promedio de los positivos, la cantidad de ceros y del menor de los negativos la suma
de los antecesores.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"


int main(void) {

	setbuf(stdout,NULL);
	int numeroIngresado;
	int i;
	int iNegativo;
	int contadorPositivos;
	int acumuladorPositivos;
	int contadorDeCeros;
	char primerNegativo;
	int menorNegativo;
	int sumaNegativos;
	int returnPromedio;
	float resultadoPromedio;

	contadorPositivos=0;
	acumuladorPositivos=0;
	contadorDeCeros=0;
	primerNegativo='s';
	sumaNegativos=0;

	for(i=0;i<10;i++)
	{
		numeroIngresado=pedirNumero();

		if(evaluarNumeros(numeroIngresado)==1)
		{
			contadorPositivos+=1;
			acumuladorPositivos+=numeroIngresado;
		} else
		{
			if(evaluarNumeros(numeroIngresado)==0)
			{
				contadorDeCeros+=1;
			} else
			{
				if(primerNegativo=='s'||numeroIngresado<menorNegativo)
				{
					menorNegativo=numeroIngresado;
					primerNegativo='n';
				}
			}
		}
	}

	for (iNegativo=menorNegativo;iNegativo<1;iNegativo++)
	{
		sumaNegativos+=iNegativo;
	}

	returnPromedio=promediar(acumuladorPositivos,contadorPositivos,&resultadoPromedio);

	if(returnPromedio==1)
	{
		printf("Error. No se puede dividir por cero\n");
	} else
	{
		printf("\nEl promedio de los positivos es %f\n", resultadoPromedio);
	}


	printf("La cantidad de ceros es %d\n",contadorDeCeros);
	printf("El menor de los negativos es %d\n",menorNegativo);
	printf("La suma de los antecesores del menor de los negativos es %d\n",sumaNegativos);

	return EXIT_SUCCESS;
}

