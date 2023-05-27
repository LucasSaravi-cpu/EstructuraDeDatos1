#include "Complex.h"
#include <stdio.h>
#include <stdlib.h>
complex suma(complex a, complex b) {
complex c;
c.r = a.r + b.r;
c.i = a.i + b.i;
return c;
}
complex resta(complex a, complex b) {
complex c;
c.r = a.r - b.r;
c.i = a.i - b.i;
return c;
}
void ingresaC (complex *c) {
    scanf("%f %f",&c->r,&(*c).i);
}
void muestraC(complex c) {
    (c.i>0)?printf("El numero es: %f+%fi",c.r,c.i):printf("El numero es: %f %fi",c.r,c.i);
}
