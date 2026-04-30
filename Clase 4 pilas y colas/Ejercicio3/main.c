#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"

int esPar(char a, char b) ;

void balanceado(TPila *P, int *ok);



void main(){
    TPila P;
    FILE *arch;
    char c;
    int ok=1;



    IniciaP(&P);

    arch = fopen("Ejercicio3.txt","r");

    if (arch == NULL) {
        printf("Error al abrir archivo\n");

    }else{


    while (fscanf(arch, "%c", &c) != EOF) {
        poneP(&P, c);


    }

    fclose(arch);



    balanceado(&P, &ok);

    if (ok){
        printf("La expresion esta BALANCEADA\n");
    } else {
        printf("La expresion NO esta balanceada\n");
    }

    }





}


int esPar(char a, char b) {
    return (a == '(' && b == ')') ||
           (a == '{' && b == '}') ||
           (a == '[' && b == ']');
}

void balanceado(TPila *P, int *ok) {
    TPila aux, control;
    ElementoP x, tope;

    IniciaP(&aux);
    IniciaP(&control);

    *ok = 1;


    while (!VaciaP(*P)) {
        sacaP(P, &x);
        poneP(&aux, x);
    }


    while (!VaciaP(aux)) {

        sacaP(&aux, &x);

        // restauramos la original
        poneP(P, x);

        if (*ok) {

            if (x == '(' || x == '{' || x == '[') {
                poneP(&control, x);
            }
            else if (x == ')' || x == '}' || x == ']') {

                if (VaciaP(control)) {
                    *ok = 0;
                } else {
                    sacaP(&control, &tope);

                    if (!esPar(tope, x)) {
                        *ok = 0;
                    }
                }
            }
        }
    }

    // aperturas sin cerrar
    if (!VaciaP(control)) {
        *ok = 0;
    }
}
