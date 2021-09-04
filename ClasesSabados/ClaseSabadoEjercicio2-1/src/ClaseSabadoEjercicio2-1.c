/*
 ============================================================================
Ignacio Smirlian (1H)
ignaciosmirlian@gmail.com

Ejercicio 2-1

Crear una funci�n que reciba como par�metro un numero entero. La funci�n retornara
1 en caso de que sea positivo, -1 en caso de que sea negativo y 0 en caso de que sea 0.
Realizar la prueba l�gica de la funci�n en el main.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int positivoNegativo (int numeroUno);

int main(void) {

	setbuf(stdout,NULL);
	int numeroIngresado;
	int resultadoPositivo;


	printf("Ingrese un n�mero: ");
	scanf("%d",&numeroIngresado);

	resultadoPositivo=positivoNegativo(numeroIngresado);

	if(resultadoPositivo==1)
	{
		printf("El n�mero ingresado es positivo");
	} else
	{
		if(resultadoPositivo==-1)
		{
			printf("El n�mero ingresado es negativo");
		} else
		{
			printf("El n�mero ingresado es cero");
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





