/*
 ============================================================================
 Name        : PracticaVideoPunterosMemoria.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_input.h"
typedef int (*tSaludar) (char*);

int saludarEsp (char*mensaje)
{
	printf("Hola %s",mensaje);

	return 0;
}


int saludarIng (char*mensaje)
{
	printf("Hello %s",mensaje);

	return 0;
}

void saludo(char*mensaje,tSaludar pSaludar) // Para evitar esto ultimo >>> int (*pSaludar) (char*) >>> Se hace un typedef
{
	pSaludar(mensaje);

}

int initArray (int* pArray, int limite, int valor)
{
	int retorno=-1;
	int i;
	if(pArray!=NULL&&limite>0)
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			*(pArray+i)=valor;
		}
	}

	return retorno;
}

int imprimirArray (int* pArray, int limite)
{
	int retorno=-1;
	int i;
	if(pArray!=NULL&&limite>0)
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			printf("%d\n",i);
			//printf("%d\n",*(pArray+i));
		}
	}

	return retorno;
}

int resizeArray (int** pArray, int* size, int nuevoSize) //Doble puntero. Pasarle puntero a puntero
{
	int* pArrayAuxiliar=NULL;
	int retorno=-1;
	if(pArray!=NULL&&size!=NULL&&nuevoSize>=0)
	{
		pArrayAuxiliar=realloc(pArray,sizeof(int)*(nuevoSize));
		if(pArrayAuxiliar!=NULL)
		{
			*size=nuevoSize;
			*pArray= pArrayAuxiliar;
			retorno=0;

		}
	}
	return retorno;
}


int main(void) {

	int* pArrayEdades=NULL;
	int sizeArrayEdades=10;


	pArrayEdades=(int*) malloc (sizeof(int)*sizeArrayEdades);

	if(pArrayEdades!=NULL)
	{
		if(initArray(pArrayEdades,sizeArrayEdades,0)==0)
		{
			printf("INIT OK\n");
			imprimirArray(pArrayEdades,sizeArrayEdades);
		}

		if(resizeArray(&pArrayEdades,&sizeArrayEdades,100)==0)
		{
			imprimirArray(pArrayEdades,sizeArrayEdades);
		}


	}





	//saludo("Esto andaaaaa\n", saludarEsp);
	//saludo("This works\n", saludarIng);
	/*int (*pSaludar) (char*);
	pSaludar=saludar;

	if(pSaludar("Holaaa\n")==0)
	{
		printf("Salio todo OK");
	}*/
	return EXIT_SUCCESS;
}
