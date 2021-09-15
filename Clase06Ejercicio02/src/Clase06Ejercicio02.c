/*
 ============================================================================
Ejercicio 2:
 a) Realizar un programa que le pida 5 numeros int al usuario y los almacene en un array. >>>Listo
 Luego ejecutar la funcion borrarImpares() pasandole el array y que deberá reemplazar
 los numeros que son impares por un cero. >>> Listo
 b) Luego imprimir el array para chequear el funcionamiento. >>> Listo
 c) Ordenar el array y volver a imprimirlo ordenado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_biblioteca.h"
#define TAM 5

int main(void) {

	setbuf(stdout,NULL);

	int listaNumeros[TAM];

	cargarArrayEnteros(listaNumeros,TAM, "Ingrese un número: ","Error, dato ingresado inválido");

	printf("El array original es: \n");

	imprimirArray(listaNumeros, TAM);

	borrarImpares(listaNumeros, TAM, 0);
	printf("El array modificado es: \n");
	imprimirArray(listaNumeros, TAM);

	return EXIT_SUCCESS;
}


