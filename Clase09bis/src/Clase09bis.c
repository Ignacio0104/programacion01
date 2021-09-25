/*
 ============================================================================
Estructuras: Crear tipo de datos
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_biblioteca.h"
#define LARGO_CADENA 32

struct EstructuraPersona //Defino el tipo
{
	char nombre[LARGO_CADENA]; //Campo de la estructura
	int edad; //Campo de la estructura
};

typedef int NumeroEntero;

typedef struct EstructuraPersona Persona; //Defino el nombre del tipo de dato de EstructuraPersona

int main(void) {
	//Tipo                  Nombre
	Persona                 persona1;
	NumeroEntero            k;
	int                     l;

	return EXIT_SUCCESS;
}
