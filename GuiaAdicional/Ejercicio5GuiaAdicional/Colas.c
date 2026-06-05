#include "Colas.h"
#include <stdlib.h>

void iniciaC(TCola *C){

    C->pri=NULL;
    C->ult=NULL;
}

int vaciaC(TCola C){

    return C.pri==NULL;
}

void poneC(TCola *C,TElementoC dato){

    nodo *aux;

    aux=(nodo*)malloc(sizeof(nodo));

    aux->datos=dato;
    aux->sig=NULL;

    if(C->pri==NULL)
        C->pri=aux;
    else
        C->ult->sig=aux;

    C->ult=aux;
}

void sacaC(TCola *C,TElementoC *dato){

    nodo *elim;

    if(C->pri!=NULL){

        *dato=C->pri->datos;

        elim=C->pri;

        C->pri=C->pri->sig;

        if(C->pri==NULL)
            C->ult=NULL;

        free(elim);
    }
}

TElementoC consultaC(TCola C){

    return C.pri->datos;
}
