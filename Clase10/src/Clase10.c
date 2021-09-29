/*
 ============================================================================
 Name        : Clase10.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "biblioteca_calculadora.h"
#include "biblioteca_input.h"
#include "biblioteca_arrays.h"
#include "Triangulos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10


int main(void) {

	setbuf(stdout,NULL);

	//int perimetro;
	//int area;

	//eTrianguloEscaleno nuevoTriangulo;

	eTrianguloEscaleno listaDeTriangulos[TAM];

	cargaTriangulosLista(listaDeTriangulos,TAM,&nuevoTriangulo);

	imprimirArray (listaDeTriangulos,TAM);

	/*trianguloCarga (&nuevoTriangulo);

	trianguloMostrarValor(nuevoTriangulo);
	printf("\n\n");
	trianguloMostrarPorReferencia (&nuevoTriangulo);

	perimetro=trianguloPerimetro(&nuevoTriangulo);

	printf("\nEl perimetro es %d",perimetro);

	area= trianguloArea(&nuevoTriangulo);

	printf("\nEl area es %d",area);*/


	return EXIT_SUCCESS;
}






/*
 *
 *
 * 	typedef struct {
	char nombre[20];
	char direccion[20];
	int telefono;
	char usuario[20];
	char email[20];
	int dni;
	int catCliente;
	char feNacimiento[20];

}Cliente;

int main(void) {

	setbuf(stdout,NULL);


	Cliente clienteUno;

	strncpy(clienteUno.nombre,"Marina",sizeof(clienteUno.nombre));

	return EXIT_SUCCESS;
}
 * 	Cliente clienteUno; //Si se pone typedef no es necesario poner struct

	Cliente clienteDos;

	Cliente arrayClientes[2];

	arrayClientes[0].dni = 2556; //Se accede al cliente de la posicion cero, al valor dni
 *
 */
