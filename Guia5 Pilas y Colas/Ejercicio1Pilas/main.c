/*Ej 2.-
    a.- Invertir una pila sobre otra pila. (La original debe perderse)
    b.- Invertir el orden de una pila dada sobre sí misma*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pilas.h"
#define MAX 10

void EjercicioA ();
void EjercicioB ();
void main(){


   printf("El ejercicio A invertir la pila sobre otra pila  \n");
   printf("Cuando la pila se invierte queda igual \n");
   EjercicioA();
   printf(" El ejercicio B invertir el orden de una pila dada sobre si misma \n");
   EjercicioB();
}
void EjercicioA () {
    TPila P,N;
    int x,i;
    IniciaP(&P);
    IniciaP(&N);
    for(i=0;i<MAX;i++) {
     poneP(&P,i);
    }
    // Muestra la pila invertida
    /*while(!VaciaP(P)) {
        sacaP(&P,&x);
        printf("%d\n",x);
    }
    IniciaP(&P);
    for(i=0;i<MAX;i++) {
     poneP(&P,i);
    }
    */


    while(!VaciaP(P)) {
        sacaP(&P,&x);
        poneP(&N,x);
    }
    // muestro la segunda pila invertida
    while(!VaciaP(N)) {
        sacaP(&N,&x);
        printf("%d\n",x);
    }

}

void EjercicioB() {
   TPila P;
   IniciaP(&P);
   int i,x;
   for(i=0;i<MAX;i++) {
     poneP(&P,i);
   }
   i = -1;
   int vec[MAX];
   while(!VaciaP(P)) {
    i++;
    sacaP(&P,&x);
    vec[i] = x;
   }
   for(;i>-1;i--) {
        x = vec[i];
        poneP(&P,x);
   }
   //Se muestra la primera pila invertida
    while(!VaciaP(P)) {
        sacaP(&P,&x);
        printf("%d\n",x);
    }


}
