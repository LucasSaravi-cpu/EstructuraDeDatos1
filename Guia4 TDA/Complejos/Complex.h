#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
typedef struct {
    float i,r;
}complex;
complex suma(complex, complex);
complex resta(complex, complex);
void ingresaC (complex *);
void muestraC(complex );
#endif // COMPLEX_H_INCLUDED
