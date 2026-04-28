
/*Ej 2.-
    a.- Invertir una pila sobre otra pila. (La original debe perderse)
    b.- Invertir el orden de una pila dada sobre sí misma */


#include "Pilas.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    TPila P, Q;
    int i;

    IniciaP(&P);
    IniciaP(&Q);


    //Cargo la pila
    for (i = 1; i <= 5; i++) {
        poneP(&P, i);
    }

    printf("La  pila P original:\n");
    mostrarPila(&P);


    printf("\nInvertir P en otra pila Q (P se pierde):\n");
    invertirEnOtra(&P, &Q);

    printf("Pila Q (invertida):\n");
    mostrarPila(&Q);


    printf("\nRecargando pila P con valores 1 a 5...\n");
    for (i = 1; i <= 5; i++) {
        poneP(&P, i);
    }

    printf("Pila P original:\n");
    mostrarPila(&P);


    printf("\nInvertir P sobre si misma:\n");
    invertirMisma(&P);

    printf("Pila P invertida:\n");
    mostrarPila(&P);

    return 0;
}





void invertirEnOtra(TPila *P, TPila *Q) {
    ElementoP x;
    IniciaP(Q);

    while (!VaciaP(*P)) {
        sacaP(P, &x);
        poneP(Q, x);
    }
}

void invertirMisma(TPila *P) {
    TPila aux;
    ElementoP x;

    IniciaP(&aux);

    while (!VaciaP(*P)) {
        sacaP(P, &x);
        poneP(&aux, x);
    }

    while (!VaciaP(aux)) {
        sacaP(&aux, &x);
        poneP(P, x);
    }
}


// (sin perder los datos)
void mostrarPila(TPila *P) {
    TPila aux;
    ElementoP x;

    IniciaP(&aux);

    printf("Tope ->\n ");

    while (!VaciaP(*P)) {
        sacaP(P, &x);
        printf("%d\n", x);
        poneP(&aux, x);
    }

    // restaurar pila original
    while (!VaciaP(aux)) {
        sacaP(&aux, &x);
        poneP(P, x);
    }

    printf("<- Base\n");
}
