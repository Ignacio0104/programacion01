/*
 ============================================================================
Ignacio Smirlian (1H)
ignaciosmirlian@gmail.com

Ejercicio 2-1

Crear una función que reciba como parámetro un numero entero. La función retornara
1 en caso de que sea positivo, -1 en caso de que sea negativo y 0 en caso de que sea 0.
Realizar la prueba lógica de la función en el main.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int positivoNegativo (int numeroUno);

int main(void) {

	setbuf(stdout,NULL);
	int numeroIngresado;
	int resultadoPositivo;


	printf("Ingrese un número: ");
	scanf("%d",&numeroIngresado);

	resultadoPositivo=positivoNegativo(numeroIngresado);

	if(resultadoPositivo==1)
	{
		printf("El número ingresado es positivo");
	} else
	{
		if(resultadoPositivo==-1)
		{
			printf("El número ingresado es negativo");
		} else
		{
			printf("El número ingresado es cero");
		}
	}


	return EXIT_SUCCESS;
}

int positivoNegativo (int numeroUno)
{
	int retorno;

	if(numeroUno>0)
	{
		retorno=1;
	} else
	{
		if(numeroUno<0)
		{
			retorno=-1;
		} else
		{
			retorno=0;
		}
	}

	return retorno;
}





