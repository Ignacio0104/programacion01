#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "Input.h"
#include "Empleado.h"

/*Crear la estructura empleado con idEmpleado, nombre, sueldo y puesto (programador, analista, tester).
 Crear un menu con las siguientes opciones:
 Cargar empleados. Carga secuencial.
 Mostrar empleados. Ordenados por puesto.
 Mostrar solo los empleados analistas.
 Mostrar cuantos empleados tester hay.
 Calcular el sueldo promedio
 Mostrar los datos de los empleados analistas con mayor sueldo

 LINK GBD >>> https://www.onlinegdb.com/PZWVfFu9T

 * */
#define TAM 5


int main(void)
{
	setbuf(stdout, NULL);
	eEmpleado listaEmpleados[TAM] = {{1000,"Maria",100000,"Tester"}, {1001,"Juan Carlos",90000,"Programador"}, {1005,"Luis",50000,"Tester"},{1003,"Jose",100050,"Analista"}, {1006,"Eugenia",70000,"Programador"}};
	int opcion;
	int testers;
	float promedio;

	do
	{
		printf("1. Cargar\n2. Mostrar\n3. Mostrar Analistas\n4. Contar Tester\n5. Mostrar promedio de sueldos.\n10. Salir\n");
		opcion = IngresarEntero("Ingrese una opcion: ");
		switch (opcion)
		{
			case 1:
				CargarEmpleados(listaEmpleados, TAM);
			break;
			case 2:
			    OrdenarPorPuesto(listaEmpleados, TAM);
				MostrarTodosLosEmpleados(listaEmpleados, TAM);
			break;
			case 3:
			    MostrarPorPuesto(listaEmpleados, TAM, "Analista");
			break;

			case 4:
	            testers = ContarPorPuesto(listaEmpleados, TAM, "Tester");
	            if(testers == 0)
	            {
	                printf("\nNo hay testers.\n");

	            }
	            else
	            {
    	           printf("\nLa cantidad de testers es: %d\n", testers);
    	        }

			break;

			case 5:
			if(CalcularPromedioDeSueldos(listaEmpleados, TAM, &promedio) == 1)
			{
			    printf("\nEl promedio de sueldos es: %.2f\n", promedio);
			}
			else
			{
			    printf("\nNo se pudo calcular el promedio.\n");
			}
			break;
		}

	} while (opcion != 10);

	return EXIT_SUCCESS;
}




