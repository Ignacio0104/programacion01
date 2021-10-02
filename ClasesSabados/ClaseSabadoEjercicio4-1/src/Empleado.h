/*
 * Empleado.h
 *
 *  Created on: 2 oct 2021
 *      Author: Nacho
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

typedef struct
{
	int idEmpleado;
	char nombre[50];
	float sueldo;
	char puesto[50];
} eEmpleado;

void CargarEmpleados(eEmpleado lista[], int largo);
void MostrarTodosLosEmpleados(eEmpleado lista[], int largo);
void MostrarUnEmpleado(eEmpleado unEmpleado);
eEmpleado IngresarUnEmpleado(void);
void OrdenarPorPuesto(eEmpleado lista[], int largo);
void MostrarPorPuesto(eEmpleado lista[], int largo, char puesto[]);
int ContarPorPuesto(eEmpleado lista[], int largo, char puesto[]);
int CalcularPromedioDeSueldos(eEmpleado lista[], int largo, float* sueldo);

#endif /* EMPLEADO_H_ */
