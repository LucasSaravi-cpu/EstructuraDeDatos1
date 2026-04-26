#include "complejos.h"
#include <stdio.h>

void suma (complex c1, complex c2, complex *c3){
  c3->r=c1.r+c2.r;
  c3->i=c1.i+c2.i;
}


void producto(complex a, complex b, complex *res) {
    res->r = a.r * b.r - a.i * b.i;
    res->i = a.r * b.i + a.i * b.r;
}

void conjugado(complex a, complex *res) {
    res->r = a.r;
    res->i = -a.i;
}

void ingresa (complex *c){
printf("Ingrese las componente de un complejo");
scanf("%f %f",&(c->r), &(c->i));
}

void muestra (complex c){
    printf("%5.2f",c.r );
    (c.i > 0) ? printf("+%5.2f i",c.i ): printf("%5.2f i",c.i );
}

float creal (complex c){ return c.r; }

float cimag (complex c){ return c.i; }
