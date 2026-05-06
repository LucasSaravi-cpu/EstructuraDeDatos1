#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"
void IniciaP(TPila *P) {
    *P = NULL;
}

int VaciaP(TPila P) {
    return P == NULL;
}

void poneP(TPila *P, ElementoP x) {
    nodop *nuevo = (nodop*) malloc(sizeof(nodop));
    strcpy(nuevo->dato, x);
    nuevo->sig = *P;
    *P = nuevo;
}

void sacaP(TPila *P, ElementoP *x) {
    nodop *aux = *P;
    strcpy(*x, aux->dato);
    *P = aux->sig;
    free(aux);
}

ElementoP* consultaP(TPila P) { //consulta ,no modifica
    //y devuelve el tipo de elemento que almacene
if (P!= NULL) //si la cabeza apunta a algo
 return P->dato; //devuelve el dato que haya en el interior de la cabeza de la pila
}

