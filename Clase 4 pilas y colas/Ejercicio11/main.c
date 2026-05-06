/*Se tiene una cola de numeros enteros ordenados de forma ascendente ,
puede haber repeticiones . Dejar en la cola solo una aparicion de cada numero , Sin utilizar estructuras auxiliares */

#include <stdio.h>
#include <stdlib.h>
#include "Colas.h"

void SacarRepetidos ( TCola *c);
void mostrarCola(TCola *c);

void main()
{
    TCola c;

    iniciaC(&c);


    poneC(&c, 1);
    poneC(&c, 1);
    poneC(&c, 2);
    poneC(&c, 2);
    poneC(&c, 3);
    poneC(&c, 4);
    poneC(&c, 4);

    printf("Cola original:\n");
    mostrarCola(&c);

    SacarRepetidos(&c);

    printf("\nCola sin repetidos:\n");
    mostrarCola(&c);
}


void mostrarCola(TCola *c)
{
    TCola aux;
    iniciaC(&aux);

    TElementoC x;

    while (!vaciaC(*c)) {
        sacaC(c, &x);
        printf("%d ", x);
        poneC(&aux, x);
    }


    while (!vaciaC(aux)) {
        sacaC(&aux, &x);
        poneC(c, x);
    }

    printf("\n");
}


void SacarRepetidos ( TCola *c){

TElementoC x,ultimo;
int bandera= 1;

TElementoC aux=0;  //El numero de corte es 0 si se trabaja con 0 poner algun negativo o poner un numero que sepamos que nunca estara disponible
poneC(c,aux);       // si conocemos claramente la informacion de la pila
sacaC(c,&x);


while (x!=aux){

    if (bandera || x != ultimo){ // Por se pone una bandera por que ultimo puede ser un numero basura entonces para la primera iteracion
        poneC(c,x);               // tenemos que poner una bandera para comenzar por que si ultimo tiene un numero cargado igual a 0 el programa no funcionaria
        ultimo =x ;               // Si sacamos bandera funciona igual por que se da la coincidencia de que ultimo es un numero diferente de 0 un numero basura
        bandera = 0;
    }
     sacaC(c, &x);

}
}







