#include "Employee.h"
#include <string.h>
#define NOMBRE_LEN 128

static int employee_createNewId (LinkedList* listEmployee);

Employee* employee_new()
{
	Employee* pEmployee=(Employee*)malloc(sizeof(Employee));
	return pEmployee;
}

int employee_askForInformation(char* pId, char *pNombre, char *pHoras, char* pSueldo)
{
	int retorno=-1;
	char idAux[256];
	char nombreAux[256];
	char horasAux[256];
	char sueldoAux[256];

	if(pedirNumeroTxt(idAux,256, 3, "Ingrese el ID","Error")==0)
	{
		if(pedirTexto(nombreAux,NOMBRE_LEN, 3, "Ingrese el nombre", "Error")==0)
		{
			if(pedirNumeroTxt(horasAux,256, 3, "Ingrese las horas","Error")==0)
			{
				if(pedirNumeroTxt(sueldoAux,256, 3, "Ingrese el salario","Error")==0)
				{
					strncpy(pHoras,horasAux,256);
					strncpy(pSueldo,sueldoAux,256);
					strncpy(pId,idAux,256);
					strncpy(pNombre,nombreAux,NOMBRE_LEN);
					retorno=0;
				}
			}
		}
	}


	return retorno;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{

	int idAux;
	char nombreAux[256];
	int horasAux;
	int sueldoAux;
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
						if(employee_setSueldoTxt(pEmployee,sueldoStr)==0)
						{

							employee_getId(pEmployee,&idAux);
							employee_getNombre(pEmployee,nombreAux);
							employee_getHorasTrabajadas(pEmployee,&horasAux);
							employee_getSueldo(pEmployee,&sueldoAux);
							//printf("Empleado ID: %d - Nombre: %s - Horas trabajadas: %d - Sueldo: %d",idAux,nombreAux,horasAux,sueldoAux);


						}
					}
				}
			}
		}
	}


	return pEmployee;
}

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
}

static int employee_createNewId (LinkedList* listEmployee)
{
	int idAnterior;
	int idNueva;
	idAnterior=emplooyee_findLastId(listEmployee);

	if(idAnterior>=0)
	{
		idNueva=idAnterior+1;
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



int employee_findEmpty(LinkedList* listEmployee)
{
	int retorno=-1;
	int lengt;

	if(listEmployee!=NULL)
	{
		lengt=ll_len(listEmployee);
		for(int i=0;i<lengt;i++)
		{
			if(ll_get(listEmployee, i)==NULL)
			{

				retorno=i;
				break;

			}

		}
	}
	return retorno;
}

int employee_modify(Employee* this)
{
	int retorno=-1;
	char nombreAux[256];
	char horasAux[256];
	char sueldoAux[256];
	char banderaSalir='n';


	int userChoice;

	printf("Que dato desea modificar?\n"
			"1)Nombre\n"
			"2)Horas trabajadas\n"
			"3)Sueldo\n"
			"4)Salir\n");

	pedirIntIntentosRango(&userChoice, 1, 4, 5, "Ingrese aquí su opción: ", "Error");

	while(banderaSalir!='s')
	{
		switch (userChoice)
			{
				case 1:
					if(pedirTexto(nombreAux,NOMBRE_LEN, 3, "Ingrese el nuevo nombre", "Error")==0)
					{
						if(employee_setNombre(this,nombreAux)==0)
						{
							printf("Nombre modificado con éxito");
							retorno=0;
						} else
						{
							printf("No se pudo modificar");

						}
					}else
					{
						printf("Error al ingresar los datos");
					}

					printf("Que dato desea modificar?\n"
								"1)Nombre\n"
								"2)Horas trabajadas\n"
								"3)Sueldo\n"
								"4)Salir\n");

						pedirIntIntentosRango(&userChoice, 1, 4, 5, "Ingrese aquí su opción: ", "Error");

					break;
				case 2:

					if(pedirNumeroTxt(horasAux,256, 3, "Ingrese las nuevas horas","Error")==0)
					{
						if(employee_setHorasTrabajadasTxt(this,horasAux)==0)
						{
							printf("Horas trabajadas modificadas con éxito");
							retorno=0;
						}else
						{
							printf("No se pudo modificar");

						}
					}else
					{
						printf("Error al ingresar los datos");
					}

					printf("Que dato desea modificar?\n"
								"1)Nombre\n"
								"2)Horas trabajadas\n"
								"3)Sueldo\n"
								"4)Salir\n");

						pedirIntIntentosRango(&userChoice, 1, 4, 5, "Ingrese aquí su opción: ", "Error");
					break;
				case 3:

					if(pedirNumeroTxt(sueldoAux,256, 3, "Ingrese el nuevo sueldo","Error")==0)
					{
						if(employee_setSueldoTxt(this,sueldoAux)==0)
						{
							printf("Sueldo modificado con éxito");
							retorno=0;
						}else
						{
							printf("No se pudo modificar");

						}
					}else
					{
						printf("Error al ingresar los datos");
					}
					printf("Que dato desea modificar?\n"
								"1)Nombre\n"
								"2)Horas trabajadas\n"
								"3)Sueldo\n"
								"4)Salir\n");

						pedirIntIntentosRango(&userChoice, 1, 4, 5, "Ingrese aquí su opción: ", "Error");

					break;
				case 4:
					printf("Volviendo al menú principal");
					banderaSalir='s';
					break;
			}
	}


	return retorno;
}

int employee_compareName(void* empleadoUno,void* empleadoDos)
{
    int retorno;

    char nombreAuxUno[NOMBRE_LEN];
    char nombreAuxDos[NOMBRE_LEN];

    employee_getNombre(empleadoUno,nombreAuxUno);
    employee_getNombre(empleadoDos,nombreAuxDos);

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

    return retorno;
}

int employee_compareId(void* empleadoUno,void* empleadoDos)
{
    int retorno;
    int idAuxUno;
    int idAuxDos;

    employee_getId(empleadoUno,&idAuxUno);
    employee_getId(empleadoDos,&idAuxDos);

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

    return retorno;
}

int employee_compareHoras(void* empleadoUno,void* empleadoDos)
{
    int retorno;
    int horasAuxUno;
    int horasAuxDos;

    employee_getHorasTrabajadas(empleadoUno,&horasAuxUno);
    employee_getHorasTrabajadas(empleadoDos,&horasAuxDos);

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

    return retorno;
}

int employee_compareSueldo(void* empleadoUno,void* empleadoDos)
{
    int retorno;
    int sueldoAuxUno;
    int sueldoAuxDos;

    employee_getSueldo(empleadoUno,&sueldoAuxUno);
    employee_getSueldo(empleadoDos,&sueldoAuxDos);

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

    return retorno;
}



void employee_delete(Employee* this)
{
	free(this);
	this=NULL;
}

int employee_printEmployee(Employee* this)
{
	int retorno;
	int idAux;
	char nombreAux[256];
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
		if(esTexto(nombre)==0)
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
		if(esTexto(this->nombre)==0)
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

