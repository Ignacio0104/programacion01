#include "Employee.h"
#include <string.h>
#define NOMBRE_LEN 128

Employee* employee_new()
{
	Employee* pEmployee=(Employee*)malloc(sizeof(Employee));
	return pEmployee;
}

int askForInformation(char* pId, char *pNombre, char *pHoras, char* pSueldo)
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
					strncpy(pId,idAux,256);
					strncpy(pNombre,nombreAux,NOMBRE_LEN);
					strncpy(pHoras,horasAux,256);
					strncpy(pSueldo,sueldoAux,256);
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
							printf("Carga exitosa\n");

							employee_getId(pEmployee,&idAux);
							employee_getNombre(pEmployee,nombreAux);
							employee_getHorasTrabajadas(pEmployee,&horasAux);
							employee_getSueldo(pEmployee,&sueldoAux);
							printf("Empleado ID: %d - Nombre: %s - Horas trabajadas: %d - Sueldo: %d",idAux,nombreAux,horasAux,sueldoAux);


						}
					}
				}
			}
		}
	}


	return pEmployee;
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

void employee_delete(Employee* this)
{
	free(this);
	this=NULL;
	printf("Empleado borrado exitosamente");
}

int printEmployee(Employee* this)
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
		printf("Empleado ID: %d - Nombre: %s - Horas trabajadas: %d - Sueldo: %d",idAux,nombreAux,horasAux,sueldoAux);
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
		printf("Antes de Es Numerica\n\n");

		if(esNumerica(id)==0)
		{
			printf("La cadena es %s",id);
			printf("Despues de Es Numerica\n\n");
			idAux=atoi(id);
			this->id=idAux;
			printf("Se cargo la ID %d",this->id);
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

