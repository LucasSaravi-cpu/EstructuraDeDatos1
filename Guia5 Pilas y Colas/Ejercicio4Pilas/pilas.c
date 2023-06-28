#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"
void poneP(TPila *P, ElementoP x) {

 TPila N;
N = (TPila)malloc(sizeof(nodop));
 N->dato = x;
 N->sig = *P;
 *P=N;
}
void sacaP(TPila *P, ElementoP * x) {
TPila N;
 if (*P != NULL) {
 N = *P;
 *x = (*P)->dato;
 *P = (*P)->sig;
 free(N);
}
}
ElementoP consultaP(TPila P) {

if (P!= NULL)
 return P->dato;
}
int VaciaP(TPila P) {
return (P == NULL);
}
void IniciaP (TPila *P) {
*P =NULL;
}
