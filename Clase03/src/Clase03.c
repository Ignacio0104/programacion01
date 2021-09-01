/*
 ============================================================================
Las funciones constan de 3 partes:
- Desarrollo de función: TipoDeDatoReturn nombreFuncion parametros.
- Uso de la función: Llamar a la función
- Prototipo de la función

Ejercicio resuelto SIN PASAJE POR REFERENCIA
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//Prototipo de la función
int sumarEnteros(int numUno, int numDos);
int restarEnteros(int numUno, int numDos);
int multiplicarEnteros (int numUno, int numDos);
int dividirEnteros(int numUno, int numDos);
int modulo(int numUno, int numDos);
void imprimirResultado(int numero);

int main(void) {
	setbuf(stdout,NULL);

	int numeroUno;
	int numeroDos;
	int resultadoSuma;
	int resultadoResta;
	int resultadoMultiplicacion;
	float resultadoDivision;
	int resultadoModulo;

	printf("Ingrese el numero uno: \n");
	scanf("%d",&numeroUno);
	printf("Ingrese el numero dos: \n");
	scanf("%d",&numeroDos);

	//Uso de la función
	resultadoSuma=sumarEnteros(numeroUno,numeroDos);
	resultadoResta=restarEnteros(numeroUno,numeroDos);
	resultadoMultiplicacion=multiplicarEnteros(numeroUno,numeroDos);
	resultadoModulo=modulo(numeroUno,numeroDos);
	resultadoDivision=dividirEnteros(numeroUno,numeroDos);

	imprimirResultado(resultadoSuma);
	imprimirResultado(resultadoResta);
	imprimirResultado(resultadoMultiplicacion);
	imprimirResultado(resultadoDivision);
	imprimirResultado(resultadoModulo);


	return EXIT_SUCCESS;
}

//Desarrollo de la función

int sumarEnteros(int numUno, int numDos)
{
	int retorno;
	retorno=numUno + numDos;
	return retorno;
}

int restarEnteros(int numUno, int numDos)
{
	int retorno;
	retorno=numUno - numDos;
	return retorno;
}

int multiplicarEnteros (int numUno, int numDos)
{
	int retorno;
	retorno=numUno * numDos;
	return retorno;
}

int dividirEnteros (int numUno, int numDos)//Puntero
{
	int retorno;

	if(numDos!=0)
	{
		retorno=(float)numUno/numDos;
	} else
	{
		retorno=1;
	}

	return retorno;
}

int modulo (int numUno,int numDos)
{
	int retorno;
	retorno=numUno%numDos;
	return retorno;
}

void imprimirResultado(int numero) //void porque es una función que no retorna nada

{
	printf("El resultado es %d\n",numero);
}

/*Otra forma de ponerlo es:
void imprimirResultado(char mensaje[],int numero)
{
	printf("%s %d",mensaje,numero);
}

*/


