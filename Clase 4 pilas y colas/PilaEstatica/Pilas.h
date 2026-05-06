#ifndef PILAS_H_INCLUDED

#define MAX 50; 
typedef int ElementoP; 
typedef struct { 
 ElementoP datos[MAX]; 
 int tope; } TPila 


void poneP(TPila *P, ElementoP x);
void sacaP(TPila *P, ElementoP * x);
ElementoP consultaP(TPila P);
int VaciaP(TPila P);
void IniciaP (TPila *P);

#endif // PILAS_H_INCLUDED

