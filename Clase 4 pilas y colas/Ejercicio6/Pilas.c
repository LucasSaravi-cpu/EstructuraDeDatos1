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


