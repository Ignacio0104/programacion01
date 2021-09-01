/*
 ============================================================================
Calculadora con PASAJE POR REFERENCIA
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int sumar (int operador1,int operador2);
int restar (int operador1,int operador2);
int multiplicar (int operador1,int operador2);
int dividir (int operador1,int operador2,float*direccionVariable);
int modulo (int operador1, int operador2, int*direccionVariable);

int main(void) {

	setbuf(stdout,NULL);
	int numeroUno;
	int numeroDos;
	int resultadoSuma;
	int resultadoResta;
	float resultadoDivision;
	int retornoDivision;
	int resultadoMultiplicacion;
	int retornoModulo;
	int resultadoModulo;

	printf("Ingrese el primer número:");
	scanf("\n%d",&numeroUno);
	printf("Ingrese el segundo número:");
	scanf("\n%d",&numeroDos);

	resultadoSuma=sumar(numeroUno,numeroDos);
	printf("El resultado de la suma es %d\n",resultadoSuma);

	resultadoResta=restar(numeroUno,numeroDos);
	printf("El resultado de la resta es %d\n",resultadoResta);

	resultadoMultiplicacion=multiplicar(numeroUno,numeroDos);
	printf("El resultado de la multiplicación es %d\n",resultadoMultiplicacion);

	retornoDivision=dividir(numeroUno,numeroDos,&resultadoDivision);
	if(retornoDivision==0)
	{
		printf("El resultado de la división es %.2f\n",resultadoDivision);
	} else
	{
		printf("Error, no se puede dividir por cero");
	}

	retornoModulo=modulo(numeroUno,numeroDos,&resultadoModulo);
	if(retornoModulo==0)
	{
		printf("El resultado del modulo es %d", resultadoModulo);
	} else
	{
		printf("\nError, no se puede dividir por cero");
	}

	return EXIT_SUCCESS;
}

int sumar (int operador1,int operador2)
{
	int retorno;

	retorno=operador1+operador2;

	return retorno;
}

int restar (int operador1,int operador2)
{
	int retorno;

	retorno=operador1-operador2;

	return retorno;
}

int multiplicar (int operador1,int operador2)
{
	int retorno;

	retorno=operador1*operador2;

	return retorno;
}

int dividir (int operador1,int operador2,float*direccionVariable)
{
	float resul;
	int huboError;

	if(operador2!=0)
	{
		resul=(float)operador1/operador2;
		*direccionVariable=resul; //Escribime en la memoria esto
		huboError=0;
	} else
	{
		huboError=1;
	}

	return huboError;
}

int modulo (int operador1, int operador2, int*direccionVariable)
{
	int resul;
	int huboError;

	if(operador2!=0)
	{
		resul=operador1%operador2;
		*direccionVariable=resul;
		huboError=0;
	} else
	{
		huboError=1;
	}
	return huboError;
}

