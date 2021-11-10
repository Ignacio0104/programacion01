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
	"\n\n1)Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
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
    int idAux;
    char sueldoAuxTxt[128];
    char horasAuxTxt[128];
    Employee* employeeAux;

    employeeAux=employee_new();
	if(employeeAux!=NULL)
	{
		if(employee_askForInformation(nombreAux, horasAuxTxt, sueldoAuxTxt)==0)
		{
			FILE* f = fopen("IdMaxima.txt","r");
			if(f!=NULL)
			{
				idAux=employee_createNewId(pArrayListEmployee);

			} else
			{
				idAux=employee_createFirstId(pArrayListEmployee);
			}
			fclose(f);

			if(employee_setId(employeeAux,idAux)==0)
			{
				if(employee_setNombre(employeeAux,nombreAux)==0)
				{
					if(employee_setHorasTrabajadasTxt(employeeAux,horasAuxTxt)==0)
					{
						if(employee_setSueldoTxt(employeeAux,sueldoAuxTxt)==0)
						{
							ll_add(pArrayListEmployee,employeeAux);
							retorno=0;
							FILE* f = fopen("IdMaxima.txt","w");
						    if(f!=NULL)
						    {
						    	retorno=0;
						        fprintf(f,"%d",idAux);
						        fclose(f);
						    }
						}
					}
				}
			}
		}
	}
	else
	{
		printf("No se pudo agregar el empleado");
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
	int lenght;

	lenght=ll_len(pArrayListEmployee);

	if(lenght>0)
	{
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
					employee_delete(pEmpleadoAux);
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

	} else
	{
		printf("No hay ningún empleado cargado para borrar");
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
		if(length>0)
		{
			for (i=0;length>i;i++)
			{
				pEmpleadoAux=ll_get(pArrayListEmployee, i);
				if(pEmpleadoAux!=NULL)
				{
					employee_printEmployee(pEmpleadoAux);
				}

			}
		} else
		{
			printf("No hay ningún empleado cargado para mostrar\n");
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
	int lenght;
	Employee * empleadoAux;

	lenght=ll_len(pArrayListEmployee);

	if(lenght>0)
	{
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
	} else
	{
		printf("No hay ningún empleado cargado para editar");
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
	int lenght;

	lenght=ll_len(pArrayListEmployee);


	if(lenght>0)
	{
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
	    		ll_sort(pArrayListEmployee,employee_compareId,0);
	    		printf("Lista ordenada por ID");
	    		retorno=0;
	    		break;
	    	case 2:
	    		ll_sort(pArrayListEmployee,employee_compareName,0);
	    		printf("Lista ordenada por Nombre");
	    		retorno=0;
	    		break;
	    	case 3:
	    		ll_sort(pArrayListEmployee,employee_compareHoras,0);
	    		printf("Lista ordenada por Horas Trabajadas");
	    		retorno=0;
	    		break;
	    	case 4:
	    		ll_sort(pArrayListEmployee,employee_compareSueldo,0);
	    		printf("Lista ordenada por Sueldo");
	    		retorno=0;
	    		break;
	    	case 5:
	    		printf("Volviendo al menú");
	    		retorno=0;
	    		break;
	    	}
	    }
	}else
	{
		printf("No hay empleados cargados para ordenar\n");
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


