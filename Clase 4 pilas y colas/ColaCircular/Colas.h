#ifndef COLAS_H_INCLUDED
#define COLAS_H_INCLUDED

#define MAX 50 
typedef int TElementoC; 
typedef struct { 
   TElementoC datos[MAX]; 
    int pri, ult; } TCola;


void iniciaC (TCola *);
int vaciaC(TCola );
void poneC (TCola *, TElementoC );
void sacaC (TCola *, TElementoC *);
TElementoC consultaC (TCola );
#endif // COLAS_H_INCLUDED
