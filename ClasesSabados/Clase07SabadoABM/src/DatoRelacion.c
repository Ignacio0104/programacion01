/*
 * DatoRelacion.c
 *
 *  Created on: 9 oct 2021
 *      Author: Nacho
 */

void eDetaRelacion_MostrarDatos(eDatoRelacion*list,int tamano)
{
	for (int i=0;i<tamano;i++)
	{
		printf("%d %d\n",list[i].idRelacion,list[i].valor);
	}
}
