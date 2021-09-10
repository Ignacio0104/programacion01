/*
 ============================================================================
 * Ejercicio 1:
 * crear un programa que permita registrar el valor de temperatura maxima de cada dia de un mes.
 * Definir un array de floats de 31 posiciones. Cada posicion corresponderá a un dia
 * del mes. Hacer un programa con un menu de dos opciones, 1.imprimir array y 2.cargar array
 * Al elegir la opcion 1, se imprimira el indice y el valor de cada posicion del array.
 * Al elegir la opcion 2 que le pida al usuario que ingrese un numero de dia (1 a 31)
 * y luego que ingrese un valor de temperatura. Almacenar el valor en el indice correspondiente
 * Ambas opciones deben volver al menu ppal.
 * Utilizar la funcion utn_getNumeroFloat() de la biblioteca utn.h
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_biblioteca.h"
#define TEMPERATURAS_LEN 31
int menuOpciones (void);
void imprimirArrayFloat (float pArray[], int len);
int pedirIntUsuario ();
float pedirFloatUsuario ();
void modificarArray (float pArray[], int indice, float modificacion);

int main(void) {

	setbuf(stdout,NULL);

	float arrayTemperaturas[31];
	int eleccionUser;
	int retornoPedirInt;
	int diaElegidoUsuario;
	float modificacionUsuario;
	int bucle;

	bucle=0;

	utn_inicializarArrayFloat(arrayTemperaturas, TEMPERATURAS_LEN, 0);

	eleccionUser=menuOpciones();

	while(bucle==0)
	{
		switch (eleccionUser)
		{
			case 1:
				imprimirArrayFloat(arrayTemperaturas, TEMPERATURAS_LEN);
				eleccionUser=menuOpciones();
				break;

			case 2:

				retornoPedirInt=utn_pedirIntAUsuario(&diaElegidoUsuario, 1, 31,600, "Ingrese el número del día: ", "Error, día fuera de rango");
				//Retorno debería usarlo para validar si hubo error, pero como puse 600 intentos, no me interesa verificar eso.
				modificacionUsuario=pedirFloatUsuario();
				modificarArray(arrayTemperaturas, diaElegidoUsuario, modificacionUsuario);
				eleccionUser=menuOpciones();
				break;
			case 3:
				printf("Saliendo del programa....");
				bucle=1;
				break;

		}
	}


	return EXIT_SUCCESS;
}

int menuOpciones (void)
{
	int eleccionUsuario;

	printf("1) imprimir la temperatura de todos los días del mes\n");
	printf("2) elegir un día y cargar una temperatura\n");
	printf("3) Salir del programa\n");

	scanf("%d",&eleccionUsuario);

	return eleccionUsuario;

}

void imprimirArrayFloat (float pArray[], int len) //(int pArrayEdades []) sintaxis alternativa
{
	int indice;

	for (indice=0;indice<len;indice++)
		{
			printf("En el día %d hizo %.2f grados\n", indice + 1, pArray[indice]);

		}
}

int pedirIntUsuario ()
{
	int numeroDeDia;

	printf("Ingrese el numero de día: ");
	scanf("%d",&numeroDeDia);

	return numeroDeDia;
}

float pedirFloatUsuario ()
{
	float numeroDeDia;

	printf("Ingrese la temperatura de ese día: ");
	scanf("%f",&numeroDeDia);

	return numeroDeDia;
}


void modificarArray (float pArray[], int indice, float modificacion)
{
	pArray[indice-1]=modificacion;
}

