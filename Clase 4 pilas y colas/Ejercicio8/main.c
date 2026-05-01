/*Dada una palabra , comprobar si es palindroma . AYUDA  utilizar una pila y una cola como estructura auxiliares*/

#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"
#include "Colas.h"

//En la cola el prmero que entra cundo lees es el primero que sale , en cambio en la pila el primero que entra cuando lees es el ultimo que sale por que la pone alrevez.

void esPalindromo(TPila *p, TCola *c, int *ok);
void mostrarCola(TCola *c) ;
void mostrarPila(TPila *p) ;

void main() {
    TPila p;
    TCola c;
    IniciaP(&p);
    IniciaP(&c);
    int ok = 1 ;
    char letra;

     do {
        printf("Ingrese una letra (0 para terminar): ");
        scanf(" %c", &letra);

        if (letra != '0') {
            poneP(&p, letra);
            poneC(&c, letra);
        }

    } while (letra != '0');


    mostrarPila(&p);
    mostrarCola(&c);

    esPalindromo(&p,&c,&ok);
    if (ok) {
        printf("Es palindromo\n");
    } else {
        printf("No es palindromo\n");
    }


}


void esPalindromo(TPila *p, TCola *c, int *ok){
    ElementoP xP;
    TElementoC xC;





    while (!VaciaP(*p) && !vaciaC(*c)) {
        sacaP(p, &xP);
        sacaC(c, &xC);

        if (xP != xC)
            *ok=0;

    }

}



void mostrarPila(TPila *p) {
    TPila aux;
    IniciaP(&aux);

    ElementoP x;

    printf("Pila: ");

    while (!VaciaP(*p)) {
        sacaP(p, &x);
        printf("%c ", x);   // si usás char

        poneP(&aux, x);     // guardo en auxiliar
    }

    // restaurar pila original
    while (!VaciaP(aux)) {
        sacaP(&aux, &x);
        poneP(p, x);
    }

    printf("\n");
}



void mostrarCola(TCola *c) {
    TCola aux;
    iniciaC(&aux);

    TElementoC x;

    printf("Cola: ");

    while (!vaciaC(*c)) {
        sacaC(c, &x);
        printf("%c ", x);

        poneC(&aux, x);
    }


    while (!vaciaC(aux)) {
        sacaC(&aux, &x);
        poneC(c, x);
    }

    printf("\n");
}
