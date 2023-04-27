#ifndef EJERCICIO6_H_INCLUDED
#define EJERCICIO6_H_INCLUDED

typedef struct strPersona{
 char Nombre[21];
 int Edad;
 struct strPersona* sig;
 } strPersona;
 typedef strPersona* ptPersona;

#endif // EJERCICIO6_H_INCLUDED
