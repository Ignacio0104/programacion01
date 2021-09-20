/*/******************************************************************************


Realizar un programa que permita el ingreso de 10 n�meros enteros distintos de cero.
Listar los n�meros positivos de manera creciente y negativos de manera decreciente. (Como m�ximo 5 for)
Ejemplo:

Listado 1 : 4, 5, 6, 10, 18, 29
Listado 2 : -1,-5,-9,-12
Listar solo los n�meros primos.
El mayor de los primos
Los n�meros que se repiten

*******************************************************************************/
*/
#include <stdio.h>
#include "biblioteca.h"

#define TAM 10


int main()
{
   int numeros[TAM];
   int verificacionCargaArray;
    int verificarPrimos;
   verificacionCargaArray = CargarArrayEnterosExcluyente(numeros, TAM, "Ingrese un n�mero distinto de 0",
   "ERROR! Ingrese un n�mero distinto de 0", 0);

   if (verificacionCargaArray == 1)  // se puede dejar como if (verificacionCargaArray)
   {
       if (ordenarArrayEnterosExcluyentes(numeros,TAM)==0)
       {
        printf("Error en Ordernar Array");
       }
       if (MostrarArrayEnteros(numeros, TAM) == 0) {
          printf("Error en Mostrar Array");
       }
       if (mostrarPrimos(numeros,TAM)==0)
       {
           printf("No se ingresaron numeros primos");
       }
   }else{
        printf("Error en Cargar Array");
   }




    return 0;
}




