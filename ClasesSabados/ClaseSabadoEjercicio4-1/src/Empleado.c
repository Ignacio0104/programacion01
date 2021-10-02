/*
 * Empleado.c
 *
 *  Created on: 2 oct 2021
 *      Author: Nacho
 */


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "Input.h"
#include "Empleado.h"

void CargarEmpleados(eEmpleado lista[], int largo)
{
	for (int i = 0; i < largo; i++)
	{
		lista[i] = IngresarUnEmpleado();
	}
}
void MostrarTodosLosEmpleados(eEmpleado lista[], int largo)
{
	for (int i = 0; i < largo; i++)
	{
		MostrarUnEmpleado(lista[i]);
	}
}

void MostrarUnEmpleado(eEmpleado unEmpleado)
{
	printf("%4d %-20s %10.2f %-20s\n", unEmpleado.idEmpleado, unEmpleado.nombre,
			unEmpleado.sueldo, unEmpleado.puesto);

}
eEmpleado IngresarUnEmpleado(void)
{
	eEmpleado dato;

	dato.idEmpleado = IngresarEntero("Ingrese el id: ");
	getString(dato.nombre, "Ingrese el nombre: ", 50);
	dato.sueldo = IngresarFlotante("Ingrese el sueldo: ");
	getString(dato.puesto, "Ingrese puesto (Programador - Analista - Tester): ", 50);

	return dato;
}

void OrdenarPorPuesto(eEmpleado lista[], int largo)
{
    int i;
    eEmpleado aux;
    int j;

    for(i=0;i<largo-1;i++)
    {
        for(j=i+1;j<largo;j++)
        {
            if(strcmp(lista[i].puesto,lista[j].puesto ) < 0)
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }

        }
    }

}

void MostrarPorPuesto(eEmpleado lista[], int largo, char puesto[])
{
    int i;

    for(i=0;i<largo;i++)
    {
        if(strcmp(lista[i].puesto , puesto ) == 0)
        {
            MostrarUnEmpleado(lista[i]);
        }

    }
}

int ContarPorPuesto(eEmpleado lista[], int largo, char puesto[])
{
    int i;
    int contador;
    contador = 0;

    for(i=0 ; i<largo; i++)
    {
        if(strcmp(lista[i].puesto , puesto ) == 0)
        {
            contador ++;

        }
    }


    return contador;
}

int CalcularPromedioDeSueldos(eEmpleado lista[], int largo, float* promedio)
{
    int i;
    int retorno;
    retorno = -1;
    float acumuladorSueldos;
    acumuladorSueldos = 0;
    if(promedio != NULL && lista != NULL && largo > 0)
    {
        for(i=0; i<largo; i++)
        {
            acumuladorSueldos += lista[i].sueldo;
        }
        retorno = 1;
    }


    *promedio = acumuladorSueldos / largo;

    return retorno;
}

