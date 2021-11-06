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

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
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

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
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

