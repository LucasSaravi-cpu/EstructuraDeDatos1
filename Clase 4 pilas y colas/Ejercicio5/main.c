/*Ejercicio 5 Poner el primer elemento de una pila en la última posición, dejando los demás elementos en
el mismo orden (en la pila original)


*/

#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"


void Intercambio(TPila *p);

void muestraP(TPila *p);

void main(){
    TPila p;
ElementoP x;
    IniciaP(&p);
    for(int i = 0;i<10;i++) {
        poneP(&p,i);
    }


    Intercambio(&p); // Se intercambiara el 0 por el 9
 muestraP(&p);



}


void Intercambio(TPila *p) {
     int primero;
     ElementoP x;
     TPila aux;
     IniciaP(&aux);

     while(!VaciaP(*p)) {
        sacaP(p,&x);
        poneP(&aux,x);
     }
     primero = x ;
     sacaP(&aux,&x);

     while(!VaciaP(aux)) {

        sacaP(&aux,&x);

        poneP(p,x);
     }
    poneP(p,primero);
}


void muestraP(TPila *p) {
    TPila aux;
    ElementoP x;

    IniciaP(&aux);

    printf("Tope ->\n");

    while (!VaciaP(*p)) {
        sacaP(p, &x);
        printf("%d\n", x);
        poneP(&aux, x);
    }

    while (!VaciaP(aux)) {
        sacaP(&aux, &x);
        poneP(p, x);
    }

    printf("Base -> \n");
}
