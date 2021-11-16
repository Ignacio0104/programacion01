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

/// \fn Employee employee_new*()
/// \brief Crea el espacio de memoria para la estructura
/// \return Devuelve el puntero a ese espacio de memoria
Employee* employee_new();

/// \fn Employee employee_newParametros*(char*, char*, char*, char*)
/// \brief Crea el espacio de memoria para la estructura y asigna los valors que se le pasan por paramentro
/// \param idStr Recibe el id en formato str
/// \param nombreStr Recibe el nombre en formato str
/// \param horasTrabajadasStr Recibe las horas en formato str
/// \param sueldoStr Recibe las horas en formato str
/// \return Devuelve el puntero a ese espacio de memoria
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/// \fn void employee_delete(Employee*)
/// \brief Borrar el espacio de memoria del employee y pasa su dirección a NULL
/// \param this Recibe el puntero al empleado a borrar
void employee_delete(Employee* this);

/// \fn int employee_findById(LinkedList*, int)
/// \brief Busca la posición de un empleado en la lista en base a su ID
/// \param listEmployee Recibe la lista de punteros a empleados
/// \param id Recibe el ID a buscar
/// \return Devuelve la posición o -1 si hubo un error
int employee_findById(LinkedList* listEmployee,int id);


/// \fn int employee_askForInformation(char*, char*, char*)
/// \brief Pide, verifica y almacena los datos necesario para el alta de un empleado
/// \param pNombre Puntero a array donde se guardará el nombre
/// \param pHoras Puntero a variable donde se guardarán las horas
/// \param pSueldo Puntero a variable  donde se guardará el sueldo
/// \return Devuelve 0 si todos los datos se cargaron de manera correcta o -1 si hubo un error
int employee_askForInformation(char *pNombre, int *pHoras, int* pSueldo);

/// \fn int employee_modify(Employee*)
/// \brief Solicita campo a modificar, y procede a la modificación
/// \param this Recibe el empleado a modificar
/// \return Devuelve 0 si los cambios pudieron realizarse o -1 si hubo un error
int employee_modify(Employee* this);

/// \fn int employee_printEmployee(Employee*)
/// \brief Imprime todos los datos de un empleado
/// \param this Recibe el empleado a imprimir
/// \return Devuelve 0 si salió OK o -1 si hubo un error
int employee_printEmployee(Employee* this);

/// \fn int employee_compareName(void*, void*)
/// \brief Compara el campo nombre de 2 empleados
/// \param empleadoUno Recibe el primer empleado
/// \param empleadoDos Recibe el segundo empleado
/// \return Devuelve 1 si empleadoUno > empleadoDos, 0 si empleadoUno=empleadoDos o -1 si empleadoUno<empleadoDos
int employee_compareName(void* empleadoUno,void* empleadoDos);

/// \fn int employee_compareName(void*, void*)
/// \brief Compara el campo ID de 2 empleados
/// \param empleadoUno Recibe el primer empleado
/// \param empleadoDos Recibe el segundo empleado
/// \return Devuelve 1 si empleadoUno > empleadoDos, 0 si empleadoUno=empleadoDos o -1 si empleadoUno<empleadoDos
int employee_compareId(void* empleadoUno,void* empleadoDos);

/// \fn int employee_compareName(void*, void*)
/// \brief Compara el campo horas de 2 empleados
/// \param empleadoUno Recibe el primer empleado
/// \param empleadoDos Recibe el segundo empleado
/// \return Devuelve 1 si empleadoUno > empleadoDos, 0 si empleadoUno=empleadoDos o -1 si empleadoUno<empleadoDos
int employee_compareHoras(void* empleadoUno,void* empleadoDos);

/// \fn int employee_compareName(void*, void*)
/// \brief Compara el campo sueldo de 2 empleados
/// \param empleadoUno Recibe el primer empleado
/// \param empleadoDos Recibe el segundo empleado
/// \return Devuelve 1 si empleadoUno > empleadoDos, 0 si empleadoUno=empleadoDos o -1 si empleadoUno<empleadoDos
int employee_compareSueldo(void* empleadoUno,void* empleadoDos);

/// \fn int emplooyee_findLastId(LinkedList*)
/// \brief Encuentra el id mas alto de la lista
/// \param listEmployee Recibe la lista de empleados
/// \return Devuelve el ID Maxima si se encontró o -1 si hubo un error
//int emplooyee_findLastId(LinkedList* listEmployee);

/// \fn int employee_createFirstId(LinkedList*)
/// \brief Crea una primer ID si no hay archivos ni lista de referencia
/// \param listEmployee Recibe la lista de empleados
/// \return Devuelve el ID creada
int employee_createFirstId (LinkedList* listEmployee);

/// \fn int employee_createNewId(LinkedList*)
/// \brief Crea un ID retomando el último valor máximo guardado en el archivo de ID
/// \param listEmployee Recibe la lista de empleados
/// \return Devuelve el ID creada
int employee_createNewId (LinkedList* listEmployee);


/// Setters y Getters ///


/// \fn int employee_setId(Employee*, int)
/// \brief Asigna el ID al campo de la estructura empleado indicada
/// \param this Recibe puntero a empleado donde cargar
/// \param id Recibe el ID (int)
/// \return Devuelve 0 si se completó o -1 si hubo algún error
int employee_setId(Employee* this,int id);

/// \fn int employee_getId(Employee*, int*)
/// \brief Consigue el ID de la estructura empleado indicada
/// \param this Recibe puntero a empleado donde buscar
/// \param id Recibe el puntero donde guardar el ID
/// \return Devuelve 0 si se completó o -1 si hubo algún error
int employee_getId(Employee* this,int* id);

/// \fn int employee_setIdTxt(Employee*, char*)
/// \brief Asigna el ID al campo de la estructura empleado indicada
/// \param this Recibe puntero a empleado donde cargar
/// \param id Recibe el ID (str)
/// \return Devuelve 0 si se completó o -1 si hubo algún error
int employee_setIdTxt(Employee* this,char* id);

/// \fn int employee_getIdTxt(Employee*, int*)
/// \brief Consigue el ID del empleado desde un formato txt
/// \param this Recibe puntero a empleado donde cargar
/// \param id Recibe el puntero donde guardar el ID
/// \return Devuelve 0 si se completó o -1 si hubo algún error
int employee_getIdTxt(Employee* this,int* id);

/// \fn int employee_setNombre(Employee*, char*)
/// \brief Asigna el nombre al campo de la estructura empleado indicada
/// \param this Recibe puntero a empleado donde cargar
/// \param id Recibe el nombre (str)
/// \return Devuelve 0 si se completó o -1 si hubo algún error
int employee_setNombre(Employee* this,char* nombre);

/// \fn int employee_getNombre(Employee*, char*)
/// \brief Consigue el nombre de la estructura empleado indicada
/// \param this Recibe puntero a empleado donde buscar
/// \param id Recibe el puntero donde guardar el nombre
/// \return Devuelve 0 si se completó o -1 si hubo algún error
int employee_getNombre(Employee* this,char* nombre);

/// \fn int employee_setHorasTrabajadas(Employee*, int)
/// \brief Asigna las horas al campo de la estructura empleado indicada
/// \param this Recibe puntero a empleado donde cargar
/// \param horasTrabajadas Recibe las horas (int)
/// \return Devuelve 0 si se completó o -1 si hubo algún error
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/// \fn int employee_getHorasTrabajadas(Employee*, int*)
/// \brief Consigue las horas de la estructura empleado indicada
/// \param this Recibe puntero a empleado donde buscar
/// \param horasTrabajadas Recibe el puntero donde guardar las horas
/// \return Devuelve 0 si se completó o -1 si hubo algún error
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/// \fn int employee_setHorasTrabajadasTxt(Employee*, char*)
/// \brief Asigna las horas al campo de la estructura empleado indicada
/// \param this Recibe puntero a empleado donde cargar
/// \param horasTrabajadas Recibe las horas (str)
/// \return Devuelve 0 si se completó o -1 si hubo algún error
int employee_setHorasTrabajadasTxt(Employee* this,char* horasTrabajadas);

/// \fn int employee_getHorasTrabajadasTxt(Employee*, int*)
/// \brief Consigue las horas de la estructura empleado indicada
/// \param this Recibe puntero a empleado donde buscar
/// \param horasTrabajadas Recibe el puntero donde guardar las horas
/// \return Devuelve 0 si se completó o -1 si hubo algún error
int employee_getHorasTrabajadasTxt(Employee* this,int* horasTrabajadas);

/// \fn int employee_setSueldo(Employee*, int)
/// \brief Asigna el sueldo al campo de la estructura empleado indicada
/// \param this Recibe puntero a empleado donde cargar
/// \param sueldo Recibe el sueldo (int)
/// \return Devuelve 0 si se completó o -1 si hubo algún error
int employee_setSueldo(Employee* this,int sueldo);

/// \fn int employee_getSueldo(Employee*, int*)
/// \brief Consigue el sueldo de la estructura empleado indicada
/// \param this Recibe puntero a empleado donde buscar
/// \param sueldo Recibe el puntero donde guardar el sueldo
/// \return Devuelve 0 si se completó o -1 si hubo algún error
int employee_getSueldo(Employee* this,int* sueldo);

/// \fn int employee_setSueldoTxt(Employee*, char*)
/// \brief Asigna el sueldo al campo de la estructura empleado indicada
/// \param this Recibe puntero a empleado donde cargar
/// \param sueldo Recibe el sueldo (str)
/// \return Devuelve 0 si se completó o -1 si hubo algún error
int employee_setSueldoTxt(Employee* this,char* sueldo);

/// \fn int employee_getSueldoTxt(Employee*, int*)
/// \brief Consigue el sueldo de la estructura empleado indicada
/// \param this Recibe puntero a empleado donde buscar
/// \param sueldo Recibe el puntero donde guardar el sueldo
/// \return Devuelve 0 si se completó o -1 si hubo algún error
int employee_getSueldoTxt(Employee* this,int* sueldo);



#endif // employee_H_INCLUDED
