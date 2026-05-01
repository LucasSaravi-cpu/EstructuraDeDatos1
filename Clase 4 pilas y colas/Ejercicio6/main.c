#include <stdio.h>
#include <string.h>
#include "Pilas.h"


void dejarCadenasPares(TPila *p);
void muestraP(TPila *p);

void main() {
    TPila p;
    IniciaP(&p);


    poneP(&p, "hola");
    poneP(&p, "chau");
    poneP(&p, "sol");
    poneP(&p, "luna");
    poneP(&p, "cielo");
    poneP(&p, "mar");

    printf("Pila original:\n");
    muestraP(&p);

    dejarCadenasPares(&p);

    printf("\nPila solo con cadenas de longitud par:\n");
    muestraP(&p);


}


void dejarCadenasPares(TPila *p) {
    TPila aux;
    ElementoP x;

    IniciaP(&aux);

    while (!VaciaP(*p)) {
        sacaP(p, &x);

        if (strlen(x) % 2 == 0) {
            poneP(&aux, x);
        }
    }

    while (!VaciaP(aux)) {
        sacaP(&aux, &x);
        poneP(p, x);
    }
}


void muestraP(TPila *p) {
    TPila aux;
    ElementoP x;

    IniciaP(&aux);

    printf("Tope ->\n");

    while (!VaciaP(*p)) {
        sacaP(p, &x);
        printf("%s\n", x);
        poneP(&aux, x);
    }


    while (!VaciaP(aux)) {
        sacaP(&aux, &x);
        poneP(p, x);
    }

    printf("Base\n");
}
