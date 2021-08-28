/*
 ============================================================================
Ignacio Smirlian (1H)
ignaciosmirlian@gmail.com

Ejercicio 1-2

Ingresar 5 números. Determinar cuál es el máximo y el mínimo e indicar en qué orden fue ingresado.
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
		printf ("Ingrese el número: ");
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


	printf("El numero máximo ingresado es %d en la posición %d  y el número mínimo es %d en la posición %d"
			,maximo,ordenMaximo,minimo,ordenMinimo);


	return EXIT_SUCCESS;
}
