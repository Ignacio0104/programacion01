/*
 ============================================================================
Agregar al programa adjunto la funcionalidad resaltada con un (*)

- Limpie la pantalla
- Solicite dos valores numéricos al usuario distintos de cero *
- Asigne a las variables numero1 y numero2 los valores obtenidos
- Realice la resta de dichas variables
- Muestre el resultado por pantalla
- Muestre por pantalla la leyenda "Resultado positivo" en caso de ser mayor *
- Muestre por pantalla la leyenda "Resultado negativo" si es menor que cero *
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int restar(int operador1,int operador2); //Prototipo de función

int main(void) {

	setbuf(stdout,NULL);

	int numUno;
	int numDos;
	int resultadoResta;


	printf("Ingrese el primer número: ");
	fflush(stdin);
	scanf("%d",&numUno);

	while(numUno<1)
	{
		printf("Error, el número debe ser mayor a cero: \n");
		fflush(stdin);
		scanf("%d",&numUno);
	}

	printf("Ingrese el segundo número: ");
	fflush(stdin);
	scanf("%d",&numDos);

		while(numUno<1)
		{
			printf("Error, el número debe ser mayor a cero: \n");
			fflush(stdin);
			scanf("%d",&numDos);
		}

	resultadoResta = restar(numUno,numDos);

	printf ("El resultado de la resta es %d \n",resultadoResta);

	if(resultadoResta>0)
	{
		printf("El resultado es positivo\n");
	} else
	{
		if(resultadoResta<0)
		{
			printf("El resultado es negativo\n");
		} else
		{
			printf("El resultado es cero\n");
		}
	}

	return EXIT_SUCCESS;
}

int restar(int operador1,int operador2)
{
	int resul;

	resul= operador1 - operador2;

	return resul;

}



