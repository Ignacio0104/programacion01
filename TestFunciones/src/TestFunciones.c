/*
 ============================================================================
 Name        : TestFunciones.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int utn_pedirFloatSinIntentos(char* variableTexto, char* textoError);


int main(void) {

	setbuf(stdout,NULL);
	float numero;

	numero=utn_pedirFloatSinIntentos("Ingrese numero", "Error");

	printf("%f",numero);

	return EXIT_SUCCESS;
}


int utn_pedirFloatSinIntentos(char* variableTexto, char* textoError)
{
	float numero;
	int salidaScanf;
	if(variableTexto != NULL && textoError != NULL)
	{
		printf("%s",variableTexto);
		salidaScanf=scanf("%f", &numero);

		while(salidaScanf!=1)
			{
				printf("%s\n",textoError);
				printf("%s",variableTexto);
				fflush(stdin);
				salidaScanf=scanf("%f", &numero);
			}

	}
	return numero;
}
