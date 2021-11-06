#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
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
    return 1;
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
    return 1;
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
			"4)Sueldo\n");

	pedirIntIntentosRango(&userChoice, 1, 4, 5, "Ingrese aquí su opción: ", "Error");


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
    return 1;
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
    return 1;
}

