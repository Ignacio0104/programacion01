#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "biblioteca_input.h"
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete(Employee* this);
int employee_findById(LinkedList* listEmployee,int id);
int employee_findEmpty(LinkedList* listEmployee);
int employee_askForInformation(char* pId, char *pNombre, char *pHoras, char* pSueldo);
int employee_modify(Employee* this);
int employee_printEmployee(Employee* this);
int employee_compareName(void* empleadoUno,void* empleadoDos);
int employee_compareId(void* empleadoUno,void* empleadoDos);
int employee_compareHoras(void* empleadoUno,void* empleadoDos);
int employee_compareSueldo(void* empleadoUno,void* empleadoDos);
int emplooyee_findLastId(LinkedList* listEmployee);


/// Setters y Getters ///
int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setIdTxt(Employee* this,char* id);
int employee_getIdTxt(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setHorasTrabajadasTxt(Employee* this,char* horasTrabajadas);
int employee_getHorasTrabajadasTxt(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_setSueldoTxt(Employee* this,char* sueldo);
int employee_getSueldoTxt(Employee* this,int* sueldo);



#endif // employee_H_INCLUDED
