#include "Employee.h"
#include "Validaciones.h"
#include <string.h>
#include <limits.h>
#define NOMBRE_LEN 128

Employee* employee_new()
{
	Employee* pEmployee=(Employee*)malloc(sizeof(Employee));
	return pEmployee;
}

int employee_askForInformation(char *pNombre, int *pHoras, int* pSueldo)
{
	int retorno=-1;
	char nombreAux[256];
	int horasAux;
	int sueldoAux;

	if(pNombre!=NULL&&pHoras!=NULL&&pSueldo!=NULL)
	{
		if(pedirNombre(nombreAux,NOMBRE_LEN, 3, "Ingrese el nombre del empleado: ", "Error, dato ingresado inválido")==0)
		{
			if(pedirIntIntentosRango(&horasAux,0, INT_MAX, 3, "Ingrese las horas trabajadas: ", "Error, dato ingresado inválido")==0)
			{
				if(pedirIntIntentosRango(&sueldoAux,0, INT_MAX, 3, "Ingrese el sueldo: ", "Error, dato ingresado inválido")==0)
				{
					strncpy(pNombre,nombreAux,NOMBRE_LEN);
					*pHoras=horasAux;
					*pSueldo=sueldoAux;
					retorno=0;
				}
			}
		}
	}

	return retorno;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* pEmployee=employee_new();

	if(pEmployee!=NULL)
	{
		if(idStr!=NULL&&horasTrabajadasStr!=NULL&&sueldoStr!=NULL&&nombreStr!=NULL)
		{
			if(employee_setIdTxt(pEmployee,idStr)==0)
			{
				if(employee_setNombre(pEmployee,nombreStr)==0)
				{
					if(employee_setHorasTrabajadasTxt(pEmployee,horasTrabajadasStr)==0)
					{
						employee_setSueldoTxt(pEmployee,sueldoStr);

					}
				}
			}
		}
	}


	return pEmployee;
}
/*
int emplooyee_findLastId(LinkedList* listEmployee)
{
	Employee* pElemento;
	int idLista;
	int longitud;
	int idMaxima=-1;

	if(listEmployee!=NULL)
	{
		idMaxima=0;
		longitud=ll_len(listEmployee);
		for(int i=0;i<longitud;i++)
		{
			if(ll_get(listEmployee, i)!=NULL)
			{
				pElemento=ll_get(listEmployee, i);

				employee_getId(pElemento,&idLista);

				if(idLista>idMaxima)
				{
					idMaxima=idLista;
				}

			}

		}

	}

	return idMaxima;
}*/
int employee_createFirstId (LinkedList* listEmployee)
{
	int idAnterior;
	int idNueva;
	idAnterior=1000;

	if(idAnterior>=0)
	{
		idNueva=idAnterior+1;
	}

	return idNueva;
}


int employee_createNewId (LinkedList* listEmployee)
{
	int idAnterior;
	int idNueva;
	char idAux[10];

	idNueva=-1;

	if(listEmployee!=NULL)
	{
		FILE* f = fopen("IdMaxima.txt","r");
			if(f!=NULL)
			{
				fscanf(f,"%s",idAux);

				if(esNumerica(idAux)==0)
				{
					idAnterior=atoi(idAux);
				}
				fclose(f);
			}

			if(idAnterior>=0)
			{
				idNueva=idAnterior+1;
			}
	}


	return idNueva;
}

int employee_findById(LinkedList* listEmployee,int id)
{
	int retorno;
	Employee* pElemento;
	int idLista;
	int longitud;

	retorno=-1;

	if(listEmployee!=NULL&&id>=0)
	{
		longitud=ll_len(listEmployee);
		for(int i=0;i<longitud;i++)
		{
			if(ll_get(listEmployee, i)!=NULL)
			{
				pElemento=ll_get(listEmployee, i);

				if(employee_getId(pElemento,&idLista)==0)
				{
					if(idLista==id)
					{
						retorno=i;
						break;
					}
				}

			}

		}

	}

	return retorno;
}


int employee_modify(Employee* this)
{
	int retorno=-1;
	char nombreAux[NOMBRE_LEN];
	int horasAux;
	int sueldoAux;
	char banderaSalir='n';

	int userChoice;

	if(this!=NULL)
	{
		printf("Que dato desea modificar?\n"
					"1)Nombre\n"
					"2)Horas trabajadas\n"
					"3)Sueldo\n"
					"4)Salir\n");


			if(pedirIntIntentosRango(&userChoice, 1, 4, 3, "Ingrese aquí su opción: ", "Error")!=0)
			{
				userChoice=4;
			}

			while(banderaSalir!='s')
			{
				switch (userChoice)
				{
					case 1:
						if(pedirTexto(nombreAux,NOMBRE_LEN, 1, "Ingrese el nuevo nombre: ", "Error, dato ingresado inválido\n")==0)
						{
							if(employee_setNombre(this,nombreAux)==0)
							{
								printf("\n >>> Nombre modificado con éxito <<< \n");
								retorno=0;
							} else
							{
								printf("\nNo se pudo modificar\n");

							}
						}else
						{
							printf("\nError al ingresar los datos\n");
						}

						printf("Que dato desea modificar?\n"
									"1)Nombre\n"
									"2)Horas trabajadas\n"
									"3)Sueldo\n"
									"4)Salir\n");

							if(pedirIntIntentosRango(&userChoice, 1, 4, 3, "Ingrese aquí su opción: ", "Error")!=0)
							{
								userChoice=4;
							}

						break;
					case 2:

						if(pedirIntIntentosRango(&horasAux,0, INT_MAX, 1, "Ingrese las horas trabajadas: ", "Error, dato ingresado inválido")==0)
						{
							if(employee_setHorasTrabajadas(this,horasAux)==0)
							{
								printf("\n >>> Horas trabajadas modificadas con éxito <<< \n");
								retorno=0;
							}else
							{
								printf("\nNo se pudo modificar\n");

							}
						}else
						{
							printf("\nError al ingresar los datos\n");
						}

						printf("Que dato desea modificar?\n"
									"1)Nombre\n"
									"2)Horas trabajadas\n"
									"3)Sueldo\n"
									"4)Salir\n");

						if(pedirIntIntentosRango(&userChoice, 1, 4, 3, "Ingrese aquí su opción: ", "Error")!=0)
						{
							userChoice=4;
						}
						break;
					case 3:

						if(pedirIntIntentosRango(&sueldoAux,0, INT_MAX, 1, "Ingrese el nuevo sueldo: ", "Error, dato ingresado inválido")==0)
						{
							if(employee_setSueldo(this,sueldoAux)==0)
							{
								printf("\n >>> Sueldo modificado con éxito <<< \n");
								retorno=0;
							}else
							{
								printf("\nNo se pudo modificar\n");

							}
						}else
						{
							printf("\nError al ingresar los datos\n");
						}
						printf("Que dato desea modificar?\n"
									"1)Nombre\n"
									"2)Horas trabajadas\n"
									"3)Sueldo\n"
									"4)Salir\n");

						if(pedirIntIntentosRango(&userChoice, 1, 4, 3, "Ingrese aquí su opción: ", "Error")!=0)
						{
							userChoice=4;
						}
						break;
					case 4:
						printf("Volviendo al menú principal\n");
						banderaSalir='s';
						break;
				}
		}
}




	return retorno;
}

int employee_compareName(void* empleadoUno,void* empleadoDos)
{
    int retorno;

    char nombreAuxUno[NOMBRE_LEN];
    char nombreAuxDos[NOMBRE_LEN];

    if(empleadoUno!=NULL&&empleadoDos!=NULL)
	{
		employee_getNombre((Employee*)empleadoUno,nombreAuxUno);
		employee_getNombre((Employee*)empleadoDos,nombreAuxDos);

		int comparacion = strcmp(nombreAuxUno,nombreAuxDos);
		if (comparacion<0)
		{
			retorno=1;
		}
		else
		{
			if (comparacion>0)
			{
				retorno=-1;
			} else
			{
				retorno=0;
			}
		}
	}

    return retorno;
}

int employee_compareId(void* empleadoUno,void* empleadoDos)
{
    int retorno;
    int idAuxUno;
    int idAuxDos;

    if(empleadoUno!=NULL&&empleadoDos!=NULL)
	{
		employee_getId((Employee*)empleadoUno,&idAuxUno);
		employee_getId((Employee*)empleadoDos,&idAuxDos);

		if (idAuxUno<idAuxDos)
		{
			retorno=1;
		}
		else
		{
			if (idAuxUno>idAuxDos)
			{
				retorno=-1;
			} else
			{
				retorno=0;
			}
		}
	}

    return retorno;
}

int employee_compareHoras(void* empleadoUno,void* empleadoDos)
{
    int retorno;
    int horasAuxUno;
    int horasAuxDos;

    if(empleadoUno!=NULL&&empleadoDos!=NULL)
    {
        employee_getHorasTrabajadas((Employee*)empleadoUno,&horasAuxUno);
        employee_getHorasTrabajadas((Employee*)empleadoDos,&horasAuxDos);

        if (horasAuxUno<horasAuxDos)
        {
            retorno=1;
        }
        else
    	{
    		if (horasAuxUno>horasAuxDos)
    		{
    			retorno=-1;
    		} else
    		{
    			retorno=0;
    		}
    	}
    }

    return retorno;
}

int employee_compareSueldo(void* empleadoUno,void* empleadoDos)
{
    int retorno;
    int sueldoAuxUno;
    int sueldoAuxDos;

    if(empleadoUno!=NULL&&empleadoDos!=NULL)
        {
			employee_getSueldo((Employee*)empleadoUno,&sueldoAuxUno);
			employee_getSueldo((Employee*)empleadoDos,&sueldoAuxDos);

			if (sueldoAuxUno<sueldoAuxDos)
			{
				retorno=1;
			}
			else
			{
				if (sueldoAuxUno>sueldoAuxDos)
				{
					retorno=-1;
				} else
				{
					retorno=0;
				}
			}
		}

    return retorno;
}



void employee_delete(Employee* this)
{
	if(this!=NULL)
	{
		free(this);
		this=NULL;
	}

}

int employee_printEmployee(Employee* this)
{
	int retorno;
	int idAux;
	char nombreAux[NOMBRE_LEN];
	int horasAux;
	int sueldoAux;

	retorno=-1;

	if(this!=NULL)
	{
		employee_getId(this,&idAux);
		employee_getNombre(this,nombreAux);
		employee_getHorasTrabajadas(this,&horasAux);
		employee_getSueldo(this,&sueldoAux);
		printf("Empleado ID: %d - Nombre: %s - Horas trabajadas: %d - Sueldo: %d\n",idAux,nombreAux,horasAux,sueldoAux);
		retorno=0;
	}

	return retorno;
}

/////// SETTERS Y GETTERS ///////

int employee_setIdTxt(Employee* this,char* id)
{
	int retorno=-1;
	int idAux;
	if(this!=NULL&&id!=NULL)
	{
		retorno=-2;

		if(esNumerica(id)==0)
		{
			idAux=atoi(id);
			this->id=idAux;
			retorno=0;

		}

	}

	return retorno;
}


int employee_getIdTxt(Employee* this,int* pId) //REVISAR
{
	int retorno=-1;
	if(this!=NULL&&pId!=NULL)
	{
		*pId=this->id;
		retorno=0;
	}

	return retorno;
}


int employee_setId(Employee* this,int id)
{
	int retorno=-1;
	if(this!=NULL&&id>=0)
	{
		this->id=id;
		retorno=0;
	}

	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno=-1;
	if(this!=NULL&&id!=NULL)
	{
		*id=this->id;
		retorno=0;
	}

	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL&&nombre!=NULL)
	{
		retorno=-2;
		if(esNombre(nombre)==0)
		{
			strncpy(this->nombre,nombre,NOMBRE_LEN);
			retorno=0;
		}
	}

	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL&&nombre!=NULL)
	{
		retorno=-2;
		if(esNombre(this->nombre)==0)
		{
			strncpy(nombre,this->nombre,NOMBRE_LEN);
			retorno=0;
		}
	}

	return retorno;
}

int employee_setHorasTrabajadasTxt(Employee* this,char* horasTrabajadas)
{
	int retorno=-1;
	int horasAux;
	if(this!=NULL&&horasTrabajadas!=NULL)
	{
		retorno=-2;
		if(esNumerica(horasTrabajadas)==0)
		{
			horasAux=atoi(horasTrabajadas);
			this->horasTrabajadas=horasAux;
			retorno=0;
		}
	}

	return retorno;
}

int employee_getHorasTrabajadasTxt(Employee* this,int* horasTrabajadas) //REVISAR
{
	int retorno=-1;
	if(this!=NULL&&horasTrabajadas!=NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		retorno=0;

	}

	return retorno;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno=-1;
	if(this!=NULL&&horasTrabajadas>=0)
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno=0;
	}

	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno=-1;
	if(this!=NULL&&horasTrabajadas!=NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		retorno=0;
	}

	return retorno;
}

int employee_setSueldoTxt(Employee* this,char* sueldo)
{
	int retorno=-1;
	int sueldoAux;
	if(this!=NULL&&sueldo!=NULL)
	{

		if(esNumerica(sueldo)==0)
		{

			sueldoAux=atoi(sueldo);
			this->sueldo=sueldoAux;
			retorno=0;
		}
	}

	return retorno;
}

int employee_getSueldoTxt(Employee* this,int* sueldo) //REVISAR
{
	int retorno=-1;

	if(this!=NULL&&sueldo!=NULL)
	{
		*sueldo=this->sueldo;
		retorno=0;

	}

	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno=-1;
	if(this!=NULL&&sueldo>=0)
	{
		this->sueldo=sueldo;
		retorno=0;
	}

	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno=-1;
	if(this!=NULL&&sueldo!=NULL)
	{
		*sueldo=this->sueldo;
		retorno=0;
	}

	return retorno;
}

