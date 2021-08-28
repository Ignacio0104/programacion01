/*
 ============================================================================
Ignacio Smirlian (1H)
ignaciosmirlian@gmail.com

Ejercicio 1-2

Ingresar 5 n�meros. Determinar cu�l es el m�ximo y el m�nimo e indicar en qu� orden fue ingresado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL);
	int numeroIngresado;
	int maximo;
	int minimo;
	int i;
	int ordenMaximo;
	int ordenMinimo;
	char primerIngreso;

	primerIngreso='s';

	for (i=0;i<5;i++)
	{
		printf ("Ingrese el n�mero: ");
		scanf("%d",&numeroIngresado);

		if(primerIngreso=='s')
		{
			maximo=numeroIngresado;
			minimo=numeroIngresado;
			primerIngreso='n';
			ordenMaximo=i+1;
			ordenMinimo=i+1;
		} else
		{
			if(numeroIngresado>maximo)
			{
				maximo=numeroIngresado;
				ordenMaximo=i+1;
			} else
			{
				if (numeroIngresado<minimo)
				{
					minimo=numeroIngresado;
					ordenMinimo=i+1;
				}
			}
		}


	}


	printf("El numero m�ximo ingresado es %d en la posici�n %d  y el n�mero m�nimo es %d en la posici�n %d"
			,maximo,ordenMaximo,minimo,ordenMinimo);


	return EXIT_SUCCESS;
}
