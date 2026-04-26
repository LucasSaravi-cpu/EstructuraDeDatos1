#ifndef COMPLEJOS_H_INCLUDED
#define COMPLEJOS_H_INCLUDED

typedef struct{
    float r, i;} complex;

void suma (complex c1, complex c2, complex *c3);
void producto(complex a, complex b, complex *res);
void conjugado(complex a, complex *res);
void ingresa (complex *c);
void muestra (complex c);
float creal (complex c);
float cimag (complex c);


#endif // COMPLEJOS_H_INCLUDED
