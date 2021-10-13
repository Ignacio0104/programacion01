/*
 * biblioteca_calculadora.c
 *
 * Funciones de calculos
 *
 *  Created on: 28 sept 2021
 *      Author: Nacho
 */


#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




float calculadora_dividir (int operador1,int operador2,float*direccionVariable)
{
	float resul;
	int huboError;

	huboError=-1;

	if(direccionVariable != NULL)
	{
		if(operador2!=0)
			{
				resul=(float)operador1/operador2;
				*direccionVariable=resul;
				huboError=0;
			}
	}

	return huboError;
}



float calculadora_sumar (float operadorUno, float operadorDos)
{
	float resultado;

	resultado=operadorUno+operadorDos;

	return resultado;
}


float calculadora_restar (float operadorUno, float operadorDos)
{
	float resultado;

	resultado=operadorUno-operadorDos;

	return resultado;
}



float calculadora_multiplicar (float operadorUno, float operadorDos)
{
	float resultado;

	resultado=operadorUno*operadorDos;

	return resultado;
}


int calculadora_factorial (float operadorUno, int*pResultado)
{

	int huboError;
	int factUno;
	int i;
	int buffer;
	float resta;

	huboError=-1;

	buffer=(int)operadorUno;

	resta=operadorUno-buffer;

	factUno=1;
	if(pResultado!= NULL&&operadorUno>0)
	{
		if(operadorUno<13&&resta==0)
		{
			for(i=1;i<=operadorUno;i++)
			{
				factUno=factUno*i;
				huboError=0;
			}
		}

	}

	*pResultado=factUno;
	return huboError;

}



int mostrarResultado (float operadorUno,float operadorDos,float resultadoOperacion,int retornoOperacion, char*mensajeError, char*operacion)
{
	int retorno;

	retorno=-1;

	if(mensajeError!=NULL&&operacion!=NULL)
	{
		retorno=0;
		if(retornoOperacion==-1)
		{
			printf("%s\n",mensajeError);
		} else
		{
			printf("El resultado de %s de %.2f y %.2f es %.2f\n",operacion,operadorUno,operadorDos,resultadoOperacion);
		}
	}

	return retorno;

}

int mostrarResultadoFact (float operadorUno,int resultadoOperacion,int retornoOperacion, char*mensajeError)
{
	int retorno;
	float numero;

	retorno=-1;

	if(mensajeError!=NULL)
	{
		numero=operadorUno;
		retorno=0;
		if(retornoOperacion==-1)
		{
			printf("%s\n",mensajeError);
		} else
		{
			printf("El factorial de %.2f es %d\n",numero,resultadoOperacion);
		}
	}

	return retorno;

}





