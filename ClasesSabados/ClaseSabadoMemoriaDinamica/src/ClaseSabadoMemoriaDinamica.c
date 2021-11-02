/*
 ============================================================================
Realizar una funci�n que reciba como par�metro un array de enteros, su tama�o y un
entero. La funci�n se encargar� de buscar el valor� y borrar� la primera ocurrencia del
mismo. El array deber� reestructurarse din�micamente.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_input.h"

int funcionBuscarYReemplazar(int* pEntero,int* tamano, int valor);
int main(void) {

	int* pAuxiliar;
	int tamanoPunteros;

	tamanoPunteros=5;
	pAuxiliar=(int*)malloc(sizeof(int)*tamanoPunteros);


	if(pAuxiliar!=NULL)
	{
		for(int i=0;i<tamanoPunteros ;i++)
		{
			*(pAuxiliar+i)=i+1;
		}
	}

	for(int i=0;i<tamanoPunteros ;i++)
	{
		printf("%d\n",*(pAuxiliar+i));
	}

	funcionBuscarYReemplazar(pAuxiliar,&tamanoPunteros, 2);

	for(int i=0;i<tamanoPunteros ;i++)
	{
		printf("%d\n",*(pAuxiliar+i));
	}

	return EXIT_SUCCESS;
}

int funcionBuscarYReemplazar(int* pEntero,int* tamano, int valor)
{
	int retorno=-1;
	if(pEntero!=NULL)
	{
		for(int i=0;i<*tamano ;i++)
		{
			if(*(pEntero+i)==valor)
			{
				for(int j=i;j<*tamano-1;j++)
				{
					*(pEntero+j)=*(pEntero+j+1);
				}
				retorno=0;
				pEntero=(int*)realloc(pEntero,sizeof(int)*(*tamano-1));
				*tamano=*tamano-1;
				break;
			}

		}
	}

	return retorno;
}
