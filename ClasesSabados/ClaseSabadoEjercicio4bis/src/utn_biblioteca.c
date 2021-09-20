
//Retomar con https://www.onlinegdb.com/7w94zfFpG



#include <stdio.h>
#include "biblioteca.h"

int PedirEnteroExcluyente(char mensaje[],char mensajeError[], int numeroExcluyente)
{
    int numeroIngresado;

    printf("%s\n",mensaje);
    scanf("%d",&numeroIngresado);

    while(numeroIngresado ==numeroExcluyente)
    {
        printf("%s\n",mensajeError);
        scanf("%d",&numeroIngresado);
    }
    return numeroIngresado;
}



int CargarArrayEnterosExcluyente(int lista[], int tam, char mensaje[],char mensajeError[], int numeroExcluyente)
{
    int i;
    int banderaTodoBien;

    banderaTodoBien = 0;

    if(lista != NULL && tam>0)
    {
        banderaTodoBien = 1;
        for (i=0; i<tam ;i++)
        {
            lista[i] = PedirEnteroExcluyente(mensaje, mensajeError, numeroExcluyente);
        }
    }
    return banderaTodoBien;

}

int MostrarArrayEnteros(int lista[], int tam) {

    int banderaTodoBien;

    banderaTodoBien = 0;

    if(lista != NULL && tam>0) {
        banderaTodoBien = 1;

        for (int i = 0; i < tam; i++) {
            printf("Posición [%d]: %d\n", i, lista[i]);
        }
    }

    return banderaTodoBien;
}

int clasificarNumero(int numeroAClasficiar)
{

    int retorno= 0;

    if (numeroAClasficiar>0)
    {
        retorno = 1;
    }else
    {
        if(numeroAClasficiar<0)
        {
            retorno = -1;
        }
    }

    return retorno;

}

int ordenarArrayEnterosExcluyentes(int lista[], int tam)
{
    int i;
    int j;
    int buffer;//int auxiliar;
    int banderaTodoBien;

    banderaTodoBien = 0;



    if(lista != NULL && tam>0)
    {
        for(i=0;i<tam-1;i++)  // toma el elemento y compara con el if el resto de los elementos
        {
            for(j=i+1;j<tam;j++) // el resto de los elementos
            {
                if(lista[i]>lista[j]) // > de menor a mayor
                {
                    buffer=lista[i];
                    lista[i]=lista[j];
                    lista[j]=buffer;
                }// else if(lista[i]<lista[j] && criterio==0){ //< de mayor a menor 2 4 3 -1




            }
        }
        banderaTodoBien = 1;
    }

    return banderaTodoBien;

}

//4, 5, 6, 10, 18, 29
//-12, -9,-5,-1

int mostrarPrimos(int lista[], int tam){
    int banderaTodoBien = 0;

    if(lista != NULL && tam>0) {
        banderaTodoBien = 1;
        printf("Lista de numeros Primos \n");
        for (int i = 0; i < tam; i++) {

            if(clasificarNumero(lista[i])==1){

                if(clasificarPrimos(lista[i])!=0){
                    mostrarEntero(lista[i]);
                }
            }
        }
    }

    return banderaTodoBien;
}


int clasificarPrimos(int numero){
    int noPrimo=1;
    int contadordiv=0;

    for (int i = numero; i>0 ; i--) {

        if(numero%i==0){
            contadordiv++;
        }
        if(contadordiv>2){
            noPrimo=0;
            break;
        }
    }

    return noPrimo;

}

void mostrarEntero(int entero){
    printf("%d \n", entero);

}


