#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "validaciones.h"
#include "biblioteca_input.h"
#include "parser.h"


int controller_MainMenu (void)
{
	int userChoice=0;

	 pedirIntIntentosRango(&userChoice, 1, 10, 5,
	"\n\n1)Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n "
	"2)Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
	"3)Alta de empleado\n"
	"4)Modificar datos de empleado\n"
	"5)Baja de empleado\n"
	"6)Listar empleados\n"
	"7)Ordenar empleados\n"
	"8)Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
	"9)Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
	"10)Salir\n\n", "Error, dato ingresado inválido");

	 return userChoice;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{

	int retorno=-1;

	FILE* f = fopen(path,"r");
	if(f!=NULL&&parser_EmployeeFromText(f, pArrayListEmployee)==0)
	{
		retorno=0;

	}
	fclose(f);

	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;

		FILE* f = fopen(path,"rb");
		if(f!=NULL&&parser_EmployeeFromBinary(f, pArrayListEmployee)==0)
		{
			retorno=0;
		}
		fclose(f);

	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
    char nombreAux[128];
    char idAuxTxt[128];
    char sueldoAuxTxt[128];
    char horasAuxTxt[128];
    Employee* employeeAux;


	if(employee_askForInformation(idAuxTxt, nombreAux, horasAuxTxt, sueldoAuxTxt)==0)
	{
		employeeAux=employee_newParametros(idAuxTxt,nombreAux,horasAuxTxt,sueldoAuxTxt);

		if(employeeAux!=NULL)
		{
			ll_add(pArrayListEmployee,employeeAux);
			retorno=0;
		}
		else
		{
			printf("No se pudo agregar el empleado");
		}
	}else
		{
			printf("Error al cargar la informacion");
		}
    return retorno;
}



/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;

    Employee* pEmpleadoAux;
    int posicionEmpleado;
    int idPedida;
	char nombreAux[256];
	int horasAux;
	int sueldoAux;
	char userChoice;

    pedirInt(&idPedida, 5, "Ingrese el ID del empleado que desea borrar\n", "Error, ID ingresada inválida\n");

    posicionEmpleado=employee_findById(pArrayListEmployee,idPedida);
    if(posicionEmpleado>=0)
    {
    	pEmpleadoAux=ll_get(pArrayListEmployee, posicionEmpleado);

    	if(pEmpleadoAux!=NULL)
    	{
    		employee_getNombre(pEmpleadoAux,nombreAux);
    		employee_getHorasTrabajadas(pEmpleadoAux,&horasAux);
    		employee_getSueldo(pEmpleadoAux,&sueldoAux);

    		printf("Se va a eliminar al empleado:\n"
    				"ID: %d, Nombre: %s, Horas trabajadas: %d, Sueldo %d",idPedida,nombreAux,horasAux,sueldoAux);

    		pedirCharSiNo(&userChoice, 's', 'n', 5, "\n\n ---------Presione [s] para confirmar o [n] para volver al menu principal---------\n",
    									"Error, dato ingresado inválido\n");
    		if(userChoice=='s')
			{
    			ll_remove(pArrayListEmployee,posicionEmpleado);
    			printf("Empleado borrado del sistema\n");
    			retorno=0;
			}
    		else
    		{
    			printf("No se borrará al empleado\n");
    			retorno=0;
    		}
    	}


    }
    else
    {
    	printf("No se encontró al empleado en la lista\n");
    }

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int i;
	int length;
	Employee * pEmpleadoAux;

	if (pArrayListEmployee!=NULL)
	{
		retorno=0;
		length=ll_len(pArrayListEmployee);
		if(length>=0)
		{
			for (i=0;length>i;i++)
			{
				pEmpleadoAux=ll_get(pArrayListEmployee, i);
				if(pEmpleadoAux!=NULL)
				{
					employee_printEmployee(pEmpleadoAux);
				}

			}
		}

	}
	else
	{
		printf("\nLa lista esta vacia");
	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int idPedida;
	int posicionPedida;
	Employee * empleadoAux;

	controller_ListEmployee(pArrayListEmployee);

	pedirInt(&idPedida, 5, "Ingrese el ID que del empleado que desea modificar", "Error");

	posicionPedida=employee_findById(pArrayListEmployee,idPedida);

	if(posicionPedida>=0)
	{
		empleadoAux=ll_get(pArrayListEmployee, posicionPedida);

		if(empleadoAux!=NULL)
		{
			if(employee_modify(empleadoAux)==0)
			{
				retorno=0;
				printf("Modificación realizada con exito\n");
			}
		}
	}

    return retorno;
}
/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
	int userChoice;


	printf("Que criterio quiere utilizar para ordenar?\n"
			"1)ID\n"
			"2)Nombre\n"
			"3)Horas trabajadas\n"
			"4)Sueldo\n"
			"5)Volver al menu principal\n");

	pedirIntIntentosRango(&userChoice, 1, 5, 5, "Ingrese aquí su opción: ", "Error");


    if (pArrayListEmployee!=NULL)
    {

    	switch (userChoice)
    	{
    	case 1:
    		ll_sort(pArrayListEmployee,employee_compareId,1);
    		retorno=0;
    		break;
    	case 2:
    		ll_sort(pArrayListEmployee,employee_compareName,1);
    		retorno=0;
    		break;
    	case 3:
    		ll_sort(pArrayListEmployee,employee_compareHoras,1);
    		retorno=0;
    		break;
    	case 4:
    		ll_sort(pArrayListEmployee,employee_compareSueldo,1);
    		break;
    	case 5:
    		printf("Volviendo al menú");
    		retorno=0;
    		break;
    	}
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	Employee* pEmpleadoAux;
	int idAux;
	char nombreAux[256];
	int horasAux;
	int sueldoAux;

	int retorno=-1;

	FILE* f = fopen(path,"w");

    if(f!=NULL)
    {
    	retorno=0;
        fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
        	pEmpleadoAux = ll_get(pArrayListEmployee,i);
        	if(pEmpleadoAux!=NULL)
        	{
    			employee_getId(pEmpleadoAux,&idAux);
    			employee_getNombre(pEmpleadoAux,nombreAux);
    			employee_getHorasTrabajadas(pEmpleadoAux,&horasAux);
    			employee_getSueldo(pEmpleadoAux,&sueldoAux);

                fprintf(f,"%d,%s,%d,%d\n",idAux,nombreAux,horasAux,sueldoAux);
        	}

        }
        fclose(f);
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	Employee * pEmpleadoAux;
	int length;

	int retorno=-1;

	FILE* f = fopen(path,"w+b");

	if(f!=NULL)
	{
		length= ll_len(pArrayListEmployee);
		retorno=0;
		for(int i=0; i<length; i++)
		{
			pEmpleadoAux=ll_get(pArrayListEmployee,i);
			if(pEmpleadoAux!=NULL)
			{
				 fwrite(pEmpleadoAux,sizeof(Employee),1,f);
			}

		}
		fclose(f);
	}

	return retorno;
}


