#ifndef CONTACTO_H_INCLUDED
#define CONTACTO_H_INCLUDED

typedef struct {
    char nombre[50];
    long telefono;
} contacto;

typedef struct {
    contacto a[20];
    int tam;
} agenda;

void inicializaA(agenda *);
void agregaC(agenda *, char [], long);
void listaAgenda(contacto [], int);
void buscaNombre(contacto [], int, char []);
void buscaNombreB(contacto [], int, char []);

#endif
