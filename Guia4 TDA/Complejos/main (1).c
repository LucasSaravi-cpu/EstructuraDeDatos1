#include <stdio.h>
#include <stdlib.h>
#include "Complex.h"
/*Ej 1.- Dado el TDA "Complex", implementación de los números complejos dado en clase agregarle
conjugado de un complejo y producto de dos complejos
Escribir un programa que ingrese dos complejos y mediante un menú elija una o varias de las
operaciones.*/
void main(){
    complex a,b,c;
    printf("Ingresa la parte real y luego imaginaria del primer numero \n");
    ingresaC(&a);
    printf("Ingresa la parte real y luego imaginaria del segundo numero \n");
    ingresaC(&b);
    c = suma(a,b);
    muestraC(c);
}

