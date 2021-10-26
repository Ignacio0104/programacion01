/*
 ============================================================================
Realizar una función que reciba un puntero a char y dos char. La función deberá
reemplazar en la cadena cada ocurrencia del primer carácter recibido, por el segundo.
Retornando la cantidad de reemplazos o -1 en caso de error.
 ============================================================================

 >>> PUNTEROS <<<<

 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_input.h"
#include <string.h>

int reemplazarCaracteres(char* cadena,int tamanoCadena, char caracterAReemplazar, char caracterQueVaAReemplazar);

int main(void) {


	printf("%d",sizeof(char*));

	/*char cadenaChars[51]="sabado";

	int reemplazos;

	reemplazos=reemplazarCaracteres(cadenaChars,sizeof(cadenaChars),'o','i');

	printf("Cant reemplazos %d.Palabra nueva %s",reemplazos,cadenaChars);*/

	return EXIT_SUCCESS;
}

int reemplazarCaracteres(char* cadena,int tamanoCadena, char caracterAReemplazar, char caracterQueVaAReemplazar)
{
	int cantidadReemplazos;
	int longitudDeCadena;


	cantidadReemplazos=-1;

	if(cadena!=NULL)
	{
		cantidadReemplazos=0;
		longitudDeCadena=strnlen(cadena,tamanoCadena); //Cadena y tamano de Cadena

		for(int i=0;i<longitudDeCadena;i++)
		{
			if(*(cadena+i)==caracterAReemplazar)
			{
				*(cadena+i)=caracterQueVaAReemplazar;
				cantidadReemplazos++;
			}
		}
	}

	return cantidadReemplazos;
}
