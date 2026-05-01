#ifndef PILAS_H_INCLUDED
#define PILAS_H_INCLUDED
#ifndef PILASDINAMICAS_H_INCLUDED
#define PILASDINAMICAS_H_INCLUDED
typedef char ElementoP[50];

typedef struct nodop {
    ElementoP dato;
    struct nodop *sig;
} nodop;

typedef nodop *TPila;

void poneP(TPila *P, ElementoP x);
void sacaP(TPila *P, ElementoP *x);

int VaciaP(TPila P);
void IniciaP(TPila *P);
#endif // PILASDINAMICAS_H_INCLUDED
#endif // PILAS_H_INCLUDED
