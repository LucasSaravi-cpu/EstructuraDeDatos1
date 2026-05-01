#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"

void invertirPila(TPila *p, TPila *aux);
void mostrarPila(TPila *p);
void armarpila(TPila *p);


void main()
{
    TPila p,aux;

    IniciaP(&p);
    IniciaP(&aux);

    char letra;

     do {
        printf("Ingrese una letra (0 para terminar): ");
        scanf(" %c", &letra);

        if (letra != '0') {
            poneP(&p, letra);
        }

    } while (letra != '0');

 invertirPila(&p,&aux) ;
 mostrarPila(&aux);
 armarpila(&aux);
 printf("La pila armada queda \n");
 mostrarPila(&aux);

}

void armarpila(TPila *p) {
    ElementoP x;
    TPila aux;
    IniciaP(&aux);

    while (!VaciaP(*p)) {
        sacaP(p, &x);

        if (x != '*') {
            poneP(&aux, x);
        }else
        {
            sacaP(p, &x);
        }

    }

    while (!VaciaP(aux)) {
        sacaP(&aux, &x);
        poneP(p, x);
    }
}





void invertirPila(TPila *p, TPila *aux) {
    ElementoP x;
    while (!VaciaP(*p)) {
        sacaP(p, &x);
        poneP(aux, x);
    }
}


void mostrarPila(TPila *p) {
    TPila aux;
    IniciaP(&aux);

    ElementoP x;

    printf("Pila: ");

    while (!VaciaP(*p)) {
        sacaP(p, &x);
        printf("%c ", x);

        poneP(&aux, x);
    }


    while (!VaciaP(aux)) {
        sacaP(&aux, &x);
        poneP(p, x);
    }

    printf("\n");
}

