/*
 ============================================================================
Ignacio Smirlian (1H)
ignaciosmirlian@gmail.com

Ejercicio 1-1

Ingresar números enteros, hasta que el usuario lo decida. Calcular y mostrar:
El promedio de los números positivos.
El promedio de los números negativos.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL);
	int numeroIngresado;
	int contadorPositivos;
	int acumuladorPositivos;
	int contadorNegativos;
	int acumuladorNegativos;
	float promedioPositivos;
	float promedioNegativos;
	char respuesta;

	contadorPositivos=0;
	acumuladorPositivos=0;
	contadorNegativos=0;
	acumuladorNegativos=0;

	respuesta='s';

	while(respuesta=='s')
	{
		printf("Ingrese un numero: ");
		scanf("%d",&numeroIngresado);

		if(numeroIngresado>0)
		{
			contadorPositivos += 1;
			acumuladorPositivos += numeroIngresado;
		} else
		{
			contadorNegativos +=1;
			acumuladorNegativos += numeroIngresado;
		}

		printf("Desea continuar? s o n: ");
		fflush(stdin);
		scanf("%c",&respuesta);
	}

	if (contadorPositivos>0)
	{
		promedioPositivos=(float)acumuladorPositivos/contadorPositivos;
	}

	if (contadorNegativos>0)
	{
		promedioNegativos=(float)acumuladorNegativos/contadorNegativos;
	}


	printf("El promedio de los números positivos es %.2f.\nY el promedio de negativos es %.2f",promedioPositivos,promedioNegativos);

	return EXIT_SUCCESS;
}
