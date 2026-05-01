#ifndef COLAS_H_INCLUDED
#define COLAS_H_INCLUDED
typedef int TElementoC;
typedef struct {
    TElementoC dato;
    struct nodo * sig;
 }nodo;
typedef struct {
nodo *pri, *ult;
} TCola;
void iniciaC (TCola *);
int vaciaC(TCola );
void poneC (TCola *, TElementoC );
void sacaC (TCola *, TElementoC *);
TElementoC consultaC (TCola );
#endif // COLAS_H_INCLUDED
