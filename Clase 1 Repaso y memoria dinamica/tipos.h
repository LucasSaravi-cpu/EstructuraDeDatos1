#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct {
    char Nombre[21];
    int Edad;
} strPersona;

typedef strPersona * ptPersona;

#endif


/*typedef struct strPersona {
    char Nombre[21];
    int Edad;
    struct strPersona *sig;
} strPersona;

typedef strPersona * ptPersona;*/
