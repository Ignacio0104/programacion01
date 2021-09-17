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

int calculadora_pedirChar (char mensaje[],char* textoError,char*pRespuesta, char opcionUno, char opcionDos);
int calculadora_factorial (float operadorUno, int*pResultado);



int main(void) {

	setbuf(stdout,NULL);
	float numeroUno;
	float numeroDos;

	int factorialUno;
	int factorialDos;

	numeroUno=20.00;
	numeroDos=50.00;

	calculadora_factorial (numeroUno, &factorialUno);
	calculadora_factorial (numeroDos, &factorialDos);

	printf("El factorial uno es %d y el dos es %d",factorialUno,factorialDos);

	return EXIT_SUCCESS;
}

int calculadora_factorial (float operadorUno, int*pResultado)
{

	int huboError;
	int factUno;
	int i;

	huboError=-1;

	factUno=1;
	if(pResultado!= NULL&&operadorUno>0)
	{
		for(i=1;i<=(int)operadorUno;i++)
		{
			factUno=factUno*i;
			huboError=0;
		}

	}

	*pResultado=factUno;
	return huboError;

}



int calculadora_pedirChar (char mensaje[],char* textoError,char*pRespuesta, char opcionUno, char opcionDos)
{

	char respuesta;
	int huboError;

	huboError=-1;

	if(mensaje != NULL && textoError != NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%c", &respuesta);


		while(respuesta!=opcionUno&&respuesta!=opcionDos)

				{
					printf("%s\n",textoError);
					printf("%s",mensaje);
					fflush(stdin);
					scanf("%c", &respuesta);
				}

		*pRespuesta=respuesta;
		huboError=0;

	}
	return huboError;
}
