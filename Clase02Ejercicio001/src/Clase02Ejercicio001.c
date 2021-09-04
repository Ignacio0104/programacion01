/*
 ============================================================================
 Realizar un programa que solicite cinco números e imprima por pantalla el promedio, el máximo y el mínimo.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int promediar (int operadorUno, int operadorDos,float*direccionVariable);

int main(void) {
	setbuf(stdout,NULL);

	int numeroIngresado;
	int maximo;
	int minimo;
	float promedio;
	float resultadoPromedio;
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

	promedio=promediar(acumuladorNumeros,contadorNumeros,&resultadoPromedio);


	if(promedio==0) //Bien hecho pero innecesario, no debería nunca dar cero el contador de numeros
	{
		printf("El promedio de los números ingresados es %.2f",resultadoPromedio);
	} else {
		printf("Error, no se puede dividir por cero");
	}

	return EXIT_SUCCESS;
}

int promediar (int operadorUno, int operadorDos,float*direccionVariable)
{
	int huboError;

	if(operadorDos!=0)
	{
		*direccionVariable=(float)operadorUno/operadorDos;
		huboError=0;
	} else
	{
		huboError=1;
	}

	return huboError;
}
