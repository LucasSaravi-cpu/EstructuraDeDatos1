#ifndef COLAS_H_INCLUDED
#define COLAS_H_INCLUDED

typedef struct{
     int nroEditorial;
    char idLibro[13];
    int cantidadSolicitada;
}TElementoC;

typedef struct nodo{
    TElementoC datos;
    struct nodo *sig;
}nodo;

typedef struct{
    nodo *pri;
    nodo *ult;
}TCola;

void iniciaC(TCola *C);
int vaciaC(TCola C);
void poneC(TCola *C,TElementoC dato);
void sacaC(TCola *C,TElementoC *dato);
TElementoC consultaC(TCola C);

#endif
