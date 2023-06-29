#include <stdlib.h>
#include <stdio.h>
#include "colas.h"
/*Ej 10.- Corregir los errores en el siguiente código manualmente, el cual carga una cola de tipo
TCOLA de enteros y luego calcula y muestra el menor de sus elementos.*/
void leerCola(TCola *c);
int main(void) {
 TCola cola;
 int n,min;
 leerCola(&cola);
 if(!vaciaC(cola))
    sacaC(&cola,&min);
 while(!vaciaC(cola)) {
    sacaC(&cola, &n);
    if(n<min)
        min = n;
 }
 printf("El minimo es %d", min);
 return 0;
}
void leerCola(TCola *c) {
 int n;
 iniciaC(c);
 scanf("%d", &n);
 while(n){
    poneC(c, n);
    scanf("%d", &n);
 }
}
