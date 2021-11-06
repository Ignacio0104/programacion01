#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "biblioteca_input.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo dataDos.csv (modo binario). NUEVO ARCHIVO PARA BINARIOS
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo dataDos.bin(modo binario).NUEVO ARCHIVO PARA BINARIOS
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout,NULL);
    int eleccionUsuario = 0;
    char banderaCierre='n';
    LinkedList* listaEmpleados = ll_newLinkedList();
    Employee * employeeAux;
    char nombreAux[128];
    char idAuxTxt[128];
    char sueldoAuxTxt[128];
    char horasAuxTxt[128];

    pedirIntIntentosRango(&eleccionUsuario, 1, 10, 5,
    		"1)Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n "
    		"2)Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
    		"3)Alta de empleado\n"
    		"4)Modificar datos de empleado\n"
    		"5)Baja de empleado\n"
    		"6)Listar empleados\n"
    		"7)Ordenar empleados\n"
    		"8)Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
    		"9)Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
    		"10)Salir", "Error, dato ingresado inválido");

    while(banderaCierre!='s')
    {
        switch(eleccionUsuario)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
            	printf("En construcción....\n");
            	pedirIntIntentosRango(&eleccionUsuario, 1, 10, 5,"Ingresa otra opción","Error");
                break;
            case 2:
            	printf("En construcción....\n");
            	pedirIntIntentosRango(&eleccionUsuario, 1, 10, 5,"Ingresa otra opción","Error");
                break;
            case 3:
				if(askForInformation(idAuxTxt, nombreAux, horasAuxTxt, sueldoAuxTxt)==0)
				{
					printf("%s %s %s %s",idAuxTxt,nombreAux,horasAuxTxt,sueldoAuxTxt);

					employeeAux=employee_newParametros(idAuxTxt,nombreAux,horasAuxTxt, sueldoAuxTxt);

					if(employeeAux!=NULL)
					{
						printf("Se cargo exitosamente");
						ll_add(listaEmpleados,employeeAux);
						printEmployee(employeeAux);
					}
				}
            	pedirIntIntentosRango(&eleccionUsuario, 1, 10, 5,"Ingresa otra opción","Error");
                break;
            case 4:
            	printf("En construcción....\n");
            	pedirIntIntentosRango(&eleccionUsuario, 1, 10, 5,"Ingresa otra opción","Error");
                break;
            case 5:
            	printf("En construcción....\n");
            	pedirIntIntentosRango(&eleccionUsuario, 1, 10, 5,"Ingresa otra opción","Error");
                break;
            case 6:
            	printf("En construcción....\n");
            	pedirIntIntentosRango(&eleccionUsuario, 1, 10, 5,"Ingresa otra opción","Error");
                break;
            case 7:
            	printf("En construcción....\n");
            	pedirIntIntentosRango(&eleccionUsuario, 1, 10, 5,"Ingresa otra opción","Error");
                break;
            case 8:
            	printf("En construcción....\n");
            	pedirIntIntentosRango(&eleccionUsuario, 1, 10, 5,"Ingresa otra opción","Error");
                break;
            case 9:
            	printf("En construcción....\n");
            	pedirIntIntentosRango(&eleccionUsuario, 1, 10, 5,"Ingresa otra opción","Error");
                break;
            case 10:
                printf("Saliendo...");
                banderaCierre='s';
                break;
        }
    }
    return 0;
}

