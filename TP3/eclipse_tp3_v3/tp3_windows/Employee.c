#include "Employee.h"
#include <string.h>
#define NOMBRE_LEN 128

Employee* employee_new()
{
	Employee* pEmployee=(Employee*)malloc(sizeof(Employee));
	return pEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	int idAux;
	int horasAux;
	int sueldoAux;
	Employee* pEmployee=employee_new();

	if(idStr!=NULL)
	{
		if(esNumerica(idStr)==0)
		{
			idAux=atoi(idStr);

			if(horasTrabajadasStr!=NULL)
			{
				if(esNumerica(horasTrabajadasStr)==0)
				{
					horasAux=atoi(horasTrabajadasStr);

					if(sueldoStr!=NULL)
					{
						if(esNumerica(sueldoStr)==0)
						{
							sueldoAux=atoi(sueldoStr);

							if(nombreStr!=NULL)
							{

								employee_setId(pEmployee,idAux);
								employee_setNombre(pEmployee,nombreStr);
								employee_setHorasTrabajadas(pEmployee,horasAux);
								employee_setSueldo(pEmployee,sueldoAux);


							}
						}
					}
				}

			}
		}
	}

	return pEmployee;
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
		if(esTexto(this->nombre)==0)
		{
			strncpy(nombre,this->nombre,NOMBRE_LEN);
			retorno=0;
		}
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

int employee_findById(LinkedList* listEmployee,int id)
{
	int retorno;
	Employee* pElemento;
	int idLista;
	int indice;
	int longitud;

	retorno=-1;

	if(listEmployee!=NULL&&id>=0)
	{
		longitud=ll_len(listEmployee);
		for(int i=0;i<longitud;i++)
		{
			pElemento=ll_get(listEmployee, i);

			employee_getId(pElemento,&idLista);
			if(idLista==id)
			{
				retorno=i;
				break;
			}
		}

	}

	return retorno;
}
