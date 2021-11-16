#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "validaciones.h"
#include "biblioteca_input.h"
#include "parser.h"
#define NOMBRE_LEN 128

/// \fn int controller_MainMenu(void)
/// \brief Imprime el menú y captura la opción elegida por el usuario
/// \return Devuelve la elección del usuario o -1 si hubo un error;
int controller_MainMenu (void)
{
	int userChoice=-1;

	 pedirIntIntentosRango(&userChoice, 1, 10, 5,
	"\n====MENU====\n\n"
	"1)Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
	"2)Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n"
	"3)Alta de empleado\n"
	"4)Modificar datos de empleado\n"
	"5)Baja de empleado\n"
	"6)Listar empleados\n"
	"7)Ordenar empleados\n"
	"8)Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
	"9)Guardar los datos de los empleados en el archivo data.bin (modo binario).\n"
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
		fclose(f);
	}


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
			fclose(f);
		}


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
    int sueldoAux;
    int horasAux;
    Employee* employeeAux;

    employeeAux=employee_new();
	if(employeeAux!=NULL)
	{
		if(employee_askForInformation(nombreAux, &horasAux, &sueldoAux)==0)
		{
			FILE* f = fopen("IdMaxima.txt","r");
			if(f!=NULL)
			{
				idAux=employee_createNewId(pArrayListEmployee);
				fclose(f);
			} else
			{
				idAux=employee_createFirstId(pArrayListEmployee);
			}


			if(employee_setId(employeeAux,idAux)==0)
			{
				if(employee_setNombre(employeeAux,nombreAux)==0)
				{
					if(employee_setHorasTrabajadas(employeeAux,horasAux)==0)
					{
						if(employee_setSueldo(employeeAux,sueldoAux)==0)
						{
							ll_add(pArrayListEmployee,employeeAux);
							printf("\n >>> Empleado cargado con éxito! <<< \n");
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
		printf("\nNo se pudo agregar el empleado\n");
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
	char nombreAux[NOMBRE_LEN];
	int horasAux;
	int sueldoAux;
	char userChoice;
	int lenght;

	lenght=ll_len(pArrayListEmployee);

	if(lenght>0)
	{
	 if(pedirInt(&idPedida, 1, "Ingrese el ID del empleado que desea borrar: \n", "Error, ID ingresada inválida\n")==0)
	 {
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

					pedirCharSiNo(&userChoice, 's', 'n', 2, "\n\n ---------Presione [s] para confirmar o [n] para volver al menu principal---------\n",
												"Error, dato ingresado inválido\n");
					if(userChoice=='s')
					{
						ll_remove(pArrayListEmployee,posicionEmpleado);
						employee_delete(pEmpleadoAux);
						printf("\nEmpleado borrado del sistema\n");
						retorno=0;
					}
					else
					{
						printf("\nNo se borrará al empleado\n");
						retorno=0;
					}
				}


			}
			else
			{
				printf("\nNo se encontró al empleado en la lista\n");
			}

	 }


	} else
	{
		printf("\nNo hay ningún empleado cargado para borrar\n");
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
			printf("\nNo hay ningún empleado cargado para mostrar\n");
		}

	}
	else
	{
		printf("\nNo se encontró la lista\n");
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

		if(pedirInt(&idPedida, 1, "\n\nIngrese el ID que del empleado que desea modificar: ", "Error, dato ingresado inválido\n")==0)
		{
			posicionPedida=employee_findById(pArrayListEmployee,idPedida);

			if(posicionPedida>=0)
			{
				empleadoAux=ll_get(pArrayListEmployee, posicionPedida);

				if(empleadoAux!=NULL)
				{
					if(employee_modify(empleadoAux)==0)
					{
						retorno=0;
					}
				}
			}
		}


	} else
	{
		printf("\nNo hay ningún empleado cargado para editar\n");
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
				"	1)ID\n"
				"	2)Nombre\n"
				"	3)Horas trabajadas\n"
				"	4)Sueldo\n"
				"	5)Volver al menu principal\n");

		if(pedirIntIntentosRango(&userChoice, 1, 5, 3, "Ingrese aquí su opción: ", "Error")==0)

		{
		    if (pArrayListEmployee!=NULL)
		    {

		    	switch (userChoice)
		    	{
		    	case 1:
		    		printf("\nOrdenando lista por ID...\n");
		    		ll_sort(pArrayListEmployee,employee_compareId,0);
		    		printf("\nLista ordenada por ID\n");
		    		retorno=0;
		    		break;
		    	case 2:
		    		printf("\nOrdenando lista por nombre...\n");
		    		ll_sort(pArrayListEmployee,employee_compareName,0);
		    		printf("\nLista ordenada por Nombre\n");
		    		retorno=0;
		    		break;
		    	case 3:
		    		printf("\nOrdenando lista por horas trabajadas...\n");
		    		ll_sort(pArrayListEmployee,employee_compareHoras,0);
		    		printf("\nLista ordenada por Horas Trabajadas\n");
		    		retorno=0;
		    		break;
		    	case 4:
		    		printf("\nOrdenando lista por sueldo...\n");
		    		ll_sort(pArrayListEmployee,employee_compareSueldo,0);
		    		printf("\nLista ordenada por Sueldo\n");
		    		retorno=0;
		    		break;
		    	case 5:
		    		printf("\nVolviendo al menú");
		    		retorno=0;
		    		break;
		    	}
		    }
		}
	}else
	{
		printf("\nNo hay empleados cargados para ordenar\n");
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
	char nombreAux[NOMBRE_LEN];
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
/*
int controller_checkForDuplicated(LinkedList* pArrayListEmployee, char* userChoice)
{
	char user;
	int retorno=-1;


	printf("Se detectó una o mas entradas previas a la carga del archivo\n"
			"Validando que no haya duplicidad de datos...\n");
	if(employee_findRepeated(pArrayListEmployee)==0)
	{
		printf("Se encontró una duplicidad de ID y uno o mas empleados fueron reasignados.\n"
				"Recomendamos volver a imprimir la lista antes de proceder al guardado\n");
		retorno=0;

		pedirCharSiNo(&user, 's', 'n', 5, "\n\n ---------Presione [s] para continuar con el guardado o [n] para volver al menu principal---------\n",
									"Error, dato ingresado inválido\n");
		*userChoice=user;
	}

	return retorno;
}*/


