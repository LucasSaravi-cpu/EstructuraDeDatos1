#include "colas.h"
#include <stdio.h>
#include <stdlib.h>

void iniciaC (TCola *C){
(*C).pri = (*C).ult=NULL;
}
int vaciaC(TCola C){
 return C.pri == NULL;
}
void poneC (TCola *C, TElementoC dato) {
 nodo * aux;
 aux = (nodo *) malloc (sizeof(nodo));
 aux->dato = dato;
 aux->sig = NULL;
 if ((*C).pri==NULL)
 (*C).pri=aux;
 else
 (*C).ult->sig=aux;
 (*C).ult=aux;
}
void sacaC (TCola *C, TElementoC *dato){
 nodo * aux;
 if ((*C).pri !=NULL) {
 aux = (*C).pri;
 *dato = aux->dato;
 if ((*C).pri == (*C).ult)
 iniciaC(C);
 else
 (*C).pri = (*C).pri->sig;
 free(aux);
 }
}
TElementoC consultaC (TCola C){
if (C.pri !=NULL)
 return C.pri-> dato;
}
