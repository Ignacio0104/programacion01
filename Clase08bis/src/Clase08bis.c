/*
 ============================================================================
Ejercicio

hacer funcion esNumerica, esTexto,esAlfaNumerica o esMail

Determinar si las cadenas son numericas o de texto

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int esNumerica (char cadena[]);
int esTexto (char cadena[]);
int esAlfaNumerica (char cadena[]);
int esMail (char cadena[]);


int main(void) {

	setbuf(stdout,NULL);
	int retornoEsNumerica;
	int retornoEsTexto;
	int retornoAlfa;
	int retornoMail;

	char cadenaPrueba[30]="242412";

	retornoEsNumerica=esNumerica(cadenaPrueba);
	retornoEsTexto=esTexto(cadenaPrueba);
	retornoAlfa=esAlfaNumerica(cadenaPrueba);
	retornoMail=esMail(cadenaPrueba);

	if(retornoEsNumerica==-1)
	{
		printf("La cadena no es númerica\n");
	} else
	{
		printf("La cadena es númerica\n");
	}

	if(retornoEsTexto==-1)
	{
		printf("La cadena no es texto\n");
	} else
	{
		printf("La cadena es texto\n");
	}

	if(retornoAlfa==-1)
	{
		printf("La cadena no es alfanumérica\n");
	} else
	{
		printf("La cadena es alfanumérica\n");
	}

	if(retornoMail==-1)
	{
		printf("La cadena no es un mail\n");
	} else
	{
		printf("La cadena es un mail\n");
	}



	return EXIT_SUCCESS;
}


int esNumerica (char cadena[])
{
	int retorno;
	int i;

	retorno=-1;

	if(cadena!=NULL&&strlen(cadena)>0)
	{
		retorno=0;
		for(i=0;cadena[i]!='\0';i++)
		{
			if(cadena[i]<'0'|| cadena[i]>'9')
			{
				retorno=-1;
				break;
			}
		}
	}

	return retorno;

}

int esTexto (char cadena[])
{
	int retorno;
	int i;

	retorno=-1;


	if(cadena!=NULL&&strlen(cadena)>0)
	{
		for(i=0;cadena[i]!='\0';i++)
		{
			if(cadena[i]>='A'&& cadena[i]<='z')
			{
				retorno=0;
			} else
			{
				retorno=-1;
				break;
			}
		}
	}

	return retorno;

}

int esAlfaNumerica (char cadena[])
{
	int retorno;
	int i;
	char sinLetras;
	char sinNumeros;

	retorno=-1;
	sinLetras='s';
	sinNumeros='s';

	if(cadena!=NULL&&strlen(cadena)>0)
	{
		for(i=0;cadena[i]!='\0';i++)
		{
			if(cadena[i]>='A'&& cadena[i]<='z')
			{
				sinLetras='n';
			} else
			{
				if(cadena[i]>='0'&& cadena[i]<='9')
				sinNumeros='n';
			}
		}
	}

	if(sinNumeros=='n'&&sinLetras=='n')
	{
		retorno=0;
	}

	return retorno;

}



int esMail (char cadena[])
{
	int retorno;
	int i;
	char sinPuntoCom;
	char sinArrobas;

	retorno=-1;
	sinArrobas='s';
	sinPuntoCom='s';

	if(cadena!=NULL&&strlen(cadena)>0)
	{
		for(i=0;cadena[i]!='\0';i++)
		{
			if(cadena[i]==64&&i>3&&i<strlen(cadena)-3)
			{
				sinArrobas='n';
			} else
			{
				if(cadena[i]==46&&cadena[i+1]==99&&cadena[i+1+1]==111&&cadena[i+1+1+1]==109)
				{
					sinPuntoCom='n';
				}
			}
		}
	}

	if(sinPuntoCom=='n'&&sinArrobas=='n')
	{
		retorno=0;
	}

	return retorno;

}
//Ejemplos de clase

/*
int myStrlenMayusculas(char cadena[])
{
	int contMayus=0;
	int index=0;
	while(cadena[index]!='\0')
	{
		//if(cadena[index]>=65 && cadena[index]<=90)
		if(cadena[index]>='A' && cadena[index]<='Z')
		{
			contMayus++;
		}
		index++;
	}
	return contMayus;
}

int myStrlen(char cadena[])
{
	int index=0;
	while(cadena[index]!='\0')
	{
		index++;
	}
	return index; // index coincide con la cant de letras
}*/

