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


   eleccionUsuario=controller_MainMenu();

    while(banderaCierre!='s')
    {
        switch(eleccionUsuario)
        {
            case 1:

                if(controller_loadFromText("dataGenerado.csv",listaEmpleados)==0)
                {
                	printf("Carga realizada con éxito");
                }
                eleccionUsuario=controller_MainMenu();
                break;
            case 2:
            	printf("En construcción....\n");
            	eleccionUsuario=controller_MainMenu();
                break;
            case 3:
            	controller_addEmployee(listaEmpleados);
            	eleccionUsuario=controller_MainMenu();
                break;
            case 4:
            	controller_editEmployee(listaEmpleados);
            	eleccionUsuario=controller_MainMenu();
                break;
            case 5:
            	printf("En construcción....\n");
            	eleccionUsuario=controller_MainMenu();
                break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
            	eleccionUsuario=controller_MainMenu();
                break;
            case 7:
            	controller_sortEmployee(listaEmpleados);
            	eleccionUsuario=controller_MainMenu();
                break;
            case 8:
            	controller_saveAsText("dataGenerado.csv", listaEmpleados);
            	eleccionUsuario=controller_MainMenu();
                break;
            case 9:
            	printf("En construcción....\n");
            	eleccionUsuario=controller_MainMenu();
                break;
            case 10:
                printf("Saliendo...");
                banderaCierre='s';
                break;
        }
    }
    return 0;
}

