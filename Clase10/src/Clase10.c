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
#define TAM 3


int main(void) {

	setbuf(stdout,NULL);

	//int perimetros[TAM];
	int perimetroMayor;
	int indexDeTrianguloMayor;
	//int area;

	eTriangulo triangulos[TAM];

	for(int i=0;i<TAM;i++)
	{
		trianguloCarga(&triangulos[i]);
		//perimetros[i]=trianguloPerimetro(&triangulos[i]);
	}



	perimetroMayor = trianguloPerimetro(&triangulos[0]); // tomo la primera como mayor
	indexDeTrianguloMayor = 0;
	for(int i=1; i<TAM ; i++)
	{
		if(trianguloPerimetro(&triangulos[i]) > perimetroMayor)
		{
			// encontre un nuevo mayor!
			perimetroMayor = trianguloPerimetro(&triangulos[i]);
			indexDeTrianguloMayor = i;
		}
	}

	trianguloMostrarPorReferencia(&triangulos[indexDeTrianguloMayor]);


	/*eTriangulo nuevoTriangulo1;
	eTriangulonuevoTriangulo2;
	eTriangulo nuevoTriangulo3;

	trianguloCarga (&nuevoTriangulo1);
	trianguloCarga (&nuevoTriangulo2);
	trianguloCarga (&nuevoTriangulo3);

	trianguloMostrarPorReferencia (&nuevoTriangulo1);
	trianguloMostrarPorReferencia (&nuevoTriangulo2);
	trianguloMostrarPorReferencia (&nuevoTriangulo3);*/



	//area= trianguloArea(&nuevoTriangulo);
	//printf("\nEl perimetro es %d\n\n",perimetro);
	//printf("\nEl area es %d\n\n",area);




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
