/*Ejercicio 6- Dada una pila que contiene al menos un 8, pasar a otra pila todos aquellos elementos que
preceden al primer 8 encontrado, sin alterar el orden. Por ejemplo:
Tope 7 1 8 2 3 5 Tope 2 3 5 Tope 7 1 8
*/


#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"
#include <ctype.h>

void pasaP(TPila *,TPila *);
void muestraP(TPila* p);



void main() {
    TPila p,p2;
    IniciaP(&p);
    IniciaP(&p2);
    for(int i = 0;i<20;i++) {
        poneP(&p,i);
    }

    printf("La pila inicial es \n");
    muestraP(&p);
    pasaP(&p,&p2);
    printf("La pila queda como \n");
    muestraP(&p2);
    printf("La segunda pila queda\n ");
    muestraP(&p);
}

void pasaP(TPila *p,TPila *p2) {
  int x = consultaP(*p); //devolver el elemento que está en el tope de la pila sin sacarlo

    while(!(VaciaP(*p) || x == 8)) { //Frena cuando la pila esta vacia o cuando encuentra un 8
        sacaP(p,&x);  //Va sacando hasta encontrar un 8 , si lo encuentra sale si no muestra la pila tal cual es
        poneP(p2,x);  // En caso que encuentre dos ochos , que no es este caso , solo muestra hasta el primero
        x = consultaP(*p); //hasta encontrar un 8 en el tope (sin sacarlo)
    }
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

    printf("Base\n");
}
