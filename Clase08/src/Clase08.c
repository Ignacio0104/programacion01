/*
 ============================================================================
 Name        : Clase08.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_biblioteca.h"
#include <string.h>

int main(void) {

	setbuf(stdout,NULL);

	char cadenaDeCaracteres[50] = "Buenas tardes"; //Asi se inicializa por extensión. El \0 (ocupa un solo caracter) le pone limite a la cadena.
													//Es un caracter de escape
	char cadenaUno[30] = "Chau";
	char cadenaDos[30] = "Hola"; //Tamano de los arrays es 30-1. El ultimo lugar siempre es el \0

	int len=strlen(cadenaDeCaracteres); //Calcula la cantidad de caracteres

	puts("Holaaa"); //puts funcion especial para mostrar cadenas de texto. Termina con \n. No permite concatenar mascaras con printf
	puts(cadenaDeCaracteres);
	printf("Size of: %d\n", sizeof(cadenaDeCaracteres)); //Tamano de la CADENA

	printf("Size of: %d\n", sizeof(int)); //Puede recibir cualquier dato

	printf("%d\n",len); //Cantidad de caracteres

	puts(cadenaUno);
	puts(cadenaDos);

	//strcpy(cadenaUno,cadenaDos); //El segundo parametro puede ser una cadena, un valor, o un array. El primero tiene que ser una direccion de memoria
								// Copia los datos de una cadena a otra. Se asigna de izquierda a derecha.
								//Siempre verificar que el argumento de destino no sea menor que el argumento dos.

	strncpy(cadenaUno,cadenaDos,sizeof(cadenaUno)-1); //La diferencia es que se le pasa un parametro mas. El tamano del destino, de esta forma no es posible pasarse
													//Si se le pasa sizeof(cadenaUno)-1 se le deja un lugar para \0, sino no va a tener espacio.
													//SIEMPRE SE PONE EL TAMANO DE DESTINO - 1 >>> sizeof(cadenaUno)-1 <<<

	strncat(cadenaUno, "Lalalala", sizeof(cadenaUno));

	//Primer argumento = La variable a la que vamos a concatenar la otra
	//Segundo argumento = valor, cadena o dato a concatenar
	//Tamano

	//sprintf(cadenaUno, "Mi size of es de %d",sideof(cadenaUno); //Se imprime un valor DENTRO de la variable
	//snprintf()//Idem pero con limite de tamano
	puts(cadenaUno);
	puts(cadenaDos);

	return EXIT_SUCCESS;
}
