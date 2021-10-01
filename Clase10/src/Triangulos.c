/*
 * estructuras.c
 *
 *  Created on: 28 sept 2021
 *      Author: Nacho
 */

#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include "Triangulos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void trianguloMostrarValor(eTriangulo unTriangulo)
{
	printf("Lado 1: %d. Lado 2: %d. Lado 3: %d\n\n",unTriangulo.ladoUno,unTriangulo.ladoDos,unTriangulo.ladoTres);
}

void trianguloMostrarPorReferencia (eTriangulo * pUnTriangulo)
{
	printf("Lado 1: %d. Lado 2: %d. Lado 3: %d\n\n",pUnTriangulo->ladoUno,pUnTriangulo->ladoDos,pUnTriangulo->ladoTres);
}


int trianguloCarga (eTriangulo * pUnTriangulo)
{
	int retorno;

	retorno=-1;

	//Si susamos el pedir int con intentos se usan variables auxiliares.

	int ladoUnoAux;
	int ladoDosAux;
	int ladoTresAux;

	if(pedirIntIntentosRango(&ladoUnoAux,0, 1000, 10, "Ingrese lado 1: ", "Error")==0)
	{
		if(pedirIntIntentosRango(&ladoDosAux,0, 1000, 10, "Ingrese lado 2: ", "Error")==0)
		{
			if(pedirIntIntentosRango(&ladoTresAux,0, 1000, 10, "Ingrese lado 3: ", "Error")==0)
			{
				pUnTriangulo->ladoUno=ladoUnoAux;
				pUnTriangulo->ladoDos=ladoDosAux;
				pUnTriangulo->ladoTres=ladoTresAux;

			}
		}
	}


	/*
	if(pUnTriangulo!=NULL)
	{
		retorno=0;
		pedirInt(&pUnTriangulo->ladoUno, "Ingrese lado 1: ", "Error. ");
		pedirInt(&pUnTriangulo->ladoDos, "Ingrese lado 2: ", "Error");
		pedirInt(&pUnTriangulo->ladoTres, "Ingrese lado 3: ", "Error");
	}*/

	return retorno;


}

int trianguloPerimetro(eTriangulo * pUnTriangulo)
{
	int perimetro;

	perimetro=pUnTriangulo->ladoUno+pUnTriangulo->ladoDos+pUnTriangulo->ladoDos;

	return perimetro;

}

int trianguloArea(eTriangulo * pUnTriangulo)
{
	int area;

	area=(pUnTriangulo->ladoDos*pUnTriangulo->ladoTres)/2; //Tomo el lado 2 como altura y lado 3 como base

	return area;

}
/*
int cargaTriangulosLista (eTrianguloEscaleno cadena[],int largo,eTrianguloEscaleno * pUnTriangulo)
{
	int i;
	int retorno;

	retorno=-1;

	if(cadena!=NULL&&largo>0)
	{
		retorno=0;
		for(i=0;i<largo;i++)
		{
			cadena[i]=trianguloCarga(&pUnTriangulo);
		}
	}

	return retorno;

}

*/


