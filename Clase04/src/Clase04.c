/*
 ============================================================================
 Name        : Clase04.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#define REINTENTOS 3
float dividir (float operador1,float operador2,float*direccionVariable);
int pedirNumero(float*pNumero1, float minimo, float maximo, int intentos, char* variableTexto, char* mensajeError);

//02/09 mensajes por SLACK, código ejemplo

int main(void) {

	setbuf(stdout,NULL);
	float numeroUno;
	float numeroDos;
	float resultadoDivision;
	int retornoDivision;

	if(pedirNumero(&numeroUno,0.0,1000.0,REINTENTOS,"Ingrese el precio: ", "\nPrecio inválido\n")==0)
	{
		if(pedirNumero(&numeroDos,0.0,1000.0, REINTENTOS,"Ingrese la temperatura: ","\nTemperatura inválida\n")==0)
		{
			retornoDivision=dividir(numeroUno,numeroDos,&resultadoDivision);
				if(retornoDivision==0)
				{
					printf("\nEl resultado de la división es %.2f\n",resultadoDivision);
				} else
				{
					printf("\nError, no se puede dividir por cero");
				}
		} else
		{
			printf("\nSe acabaron los intentos.");
		}

	}

	return EXIT_SUCCESS;
}


int pedirNumero(float*pNumero1, float minimo, float maximo, int intentos, char* variableTexto,char* mensajeError)
{
	float num1;
	int retorno;
	int i;

	retorno=1;
	if(minimo<maximo)
	{
		for(i=0;i<=intentos;i++)
		{
			printf("%s",variableTexto);
			scanf("%f",&num1);

			if(num1>=minimo && num1<=maximo)
			{
				retorno=0;
				*pNumero1=num1;
				break;
			}
			else
			{
				retorno=1;
				printf("%s",mensajeError);
			}
		}
	}

	return retorno;

}

float dividir (float operador1,float operador2,float*direccionVariable)
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

