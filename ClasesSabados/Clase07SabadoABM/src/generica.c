/*
 * generica.c
 *
 *  Created on: 9 oct 2021
 *      Author: Nacho
 */

void inicializarArray (eGenerico* lista,int tam)
{
	int i;
	for (i=0;i<tam;i++)
	{
		lista[i].isEmpty=1;
	}

}


int buscarLibre (eGenerico* lista,int tam)
{
	int i;
	int index;

	index=-1;
	for (i=0;i<tam;i++)
	{
		if(lista[i].isEmpty==1)
		{
			index=i;
			break;
		}
	}

	return index;
}

int eGenerico_AltaDatos(eGenerico*lista,int tamGenerico, eDatoRelacion listaRelacion[], int tamRelacion)
{
	int index;

	index=buscarLibre (lista,tamGenerico);
	if(index!=-1)
	{
		//lista[index].index=pedirInt(int* pResultado, int reintentos, char* variableTexto, char* textoError);
		//pedirTexto
		//DatoRelacion_MostrarDatos (listaRelacion, tamRelacion);

		//Pedir los datos de relacion
		//lista[index].idRelacion = IngresarEntero ("Ingrese id relación: ");
		//lista[index].isEmpty=0;
	}

	return index;

}

void eGenerico_MostrarDatos(eGenerico*list,int tamano)
{
	for (int i=0;i<tamano;i++)
	{
		printf("%d %s &d\n",list[i].id,list[i].descripcion,list[i].idRelacion);
	}
}

