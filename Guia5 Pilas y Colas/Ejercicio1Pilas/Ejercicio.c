#include "pilas.h"
#include <stdio.h>
#include <stdlib.h>

void poneP(TPila *P, ElementoP x) { //requiere el puntero a la ultima pila ,lo modifica
 TPila N; // crea un nuevo puntero a un nodo
N = (TPila)malloc(sizeof(nodop));//se crea en la memoria dinamica

 N->dato = x;//(*N).dato A donde N apunta , almacena el x que se pasa
 N->sig = *P;//(*N).sig A donde N apunta , guarda la pila P
 *P=N;//asigna como nueva cabeza de pila a el nuevo N creado
}

void sacaP(TPila *P, ElementoP * x) { //modifica el puntero y almacena en x el valor de la cabeza de la pila que se saca
TPila N; // creo un nuevo TPila (puntero a nodop)
 if (*P != NULL) { //el puntero no este vacio
 N = *P; //  apuntar al mismo lugar que a donde apunta la cabeza de la pila
 *x = (*P)->dato; //almaceno en x, el valor del dato de la cabeza
 *P = (*P)->sig;// almaceno en la cabeza de la pila, a donde apunta su siguiente
 free(N); //libero a donde apunta N
}
}

ElementoP consultaP(TPila P) { //consulta ,no modifica
    //y devuelve el tipo de elemento que almacene
if (P!= NULL) //si la cabeza apunta a algo
 return P->dato; //devuelve el dato que haya en el interior de la cabeza de la pila
}

int VaciaP(TPila P) {
    return (P == NULL);//devuelve 1 si no esta vacio y 0 si esta vacio
}

void IniciaP (TPila *P) { //inicia el puntero en NULL
*P =NULL;
}

