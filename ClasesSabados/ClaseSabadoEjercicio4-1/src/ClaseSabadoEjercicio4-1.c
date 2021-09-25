/*
 ============================================================================
Crear la estructura empleado con idEmpleado, nombre, sueldo y puesto (programador,
analista, tester).

Crear un menu con las siguientes opciones:

1. Cargar empleados. Carga secuencial.
2. Mostrar empleados. Ordenados por puesto.
3. Mostrar solo los empleados analistas.
4. Mostrar cuantos empleados tester hay.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "utn_biblioteca.h"
#define TAM 5

//LINK DE GBD RESUELTO!! >>>> https://onlinegdb.com/PZWVfFu9T

typedef struct
{
	int idEmpleado;
	char nombre [50];
	float sueldo;
	char puesto[50];
}eEmpleado;

eEmpleado ingresarUnEmpleado (void);
void mostrarEmpleado (eEmpleado unEmpleado);
void cargarEmpleados(eEmpleado lista[], int lenght);
void mostrarTodosLosEmpleados (eEmpleado lista[], int lenght);

int main(void) {
	setbuf(stdout,NULL);

	/*eEmpleado miEmpleado;//= {1000,"Juan Carlos", 60000, "Programador"} ;
	miEmpleado=ingresarUnEmpleado();
	mostrarEmpleado(miEmpleado);*/
	eEmpleado listaEmpleados [TAM]={{1000,"Maria",10000,"Analista"},{1001,"Juan Carlos",9000,"Programador"},{1002,"Carlos",12000,"Analista"},{1005,"Luis",50000,"Tester"},{1003,"Jose",70000,"Analista"}};
	//Aca se hardcodean los datos para no cargarlos en cada prueba!
	int opcion;

	do
	{
		printf("1. Cargar\n2. Mostrar\n3. Mostrar Analistas\n4. Contar Tester\n10. Salir");
		utn_pedirIntAUsuario(&opcion, 1, 11, 5000, "Elija una opcion", "Error");

		switch (opcion)
		{
		case 1:
			cargarEmpleados(listaEmpleados,TAM);
			break;
		case 2:
			mostrarTodosLosEmpleados (listaEmpleados,TAM);
			break;
		}

	}while(opcion!=10);




	return EXIT_SUCCESS;
}

void mostrarEmpleado (eEmpleado unEmpleado)
{
	printf("%2d %15s %15.2f %15s\n",unEmpleado.idEmpleado,unEmpleado.nombre,unEmpleado.sueldo,unEmpleado.puesto);
			//Esos numeros despues de la mascara sirven para ordenar en columnas (espaciado)
}

eEmpleado ingresarUnEmpleado (void) //Pedir un empleado
{
	eEmpleado dato;

	utn_pedirIntAUsuario(&dato.idEmpleado, 0, 3000, 5000, "Ingrese ID", "Error");
	utn_pedirTextoAUsuario(dato.nombre, 50, "Ingrese el nombre", "Error");
	utn_pedirFloatAUsuario(&dato.sueldo, 0, 1000000, 5000, "Ingrese el sueldo", "Error");
	utn_pedirTextoAUsuario(dato.puesto, 50, "Ingrese el puesto (Programador - Analista - Tester)", "Error");

	return dato;
}


void cargarEmpleados(eEmpleado lista[], int lenght)
{
	for (int i=0;i<lenght;i++)
	{
		lista[i]= ingresarUnEmpleado();
	}

}
void mostrarTodosLosEmpleados (eEmpleado lista[], int lenght)
{
	for (int i=0;i<lenght;i++)
	{
		mostrarEmpleado(lista[i]);
	}
}
