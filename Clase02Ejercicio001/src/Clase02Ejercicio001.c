/*
 ============================================================================
 Realizar un programa que solicite cinco números e imprima por pantalla el promedio, el máximo y el mínimo.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	int numeroIngresado;
	int maximo;
	int minimo;
	float promedio;
	int i;
	char primerIngreso;
	int acumuladorNumeros;
	int contadorNumeros;

	primerIngreso='s';
	acumuladorNumeros=0;
	contadorNumeros=0;

	for (i=0;i<5;i++)
	{
		printf("Ingrese el número: \n");
		scanf("%d",&numeroIngresado);

		acumuladorNumeros+=numeroIngresado;
		contadorNumeros+=1;

		if(primerIngreso=='s')
		{
			maximo=numeroIngresado;
			minimo=numeroIngresado;
			primerIngreso='n';
		} else
		{
			if(numeroIngresado>maximo)
			{
				maximo=numeroIngresado;
			} else
			{
				if(numeroIngresado<minimo)
				{
					minimo=numeroIngresado;
				}
			}
		}
	}

	printf("El valor máximo ingresado fue %d. Y el valor mínimo fue %d\n",maximo,minimo);

	if(acumuladorNumeros>0)
	{
		promedio=(float)acumuladorNumeros/contadorNumeros;
		printf("El promedio de los números ingresados es %.2f",promedio);
	} else
	{
		printf("No se ingresó ningún valor");
	}

	return EXIT_SUCCESS;
}
