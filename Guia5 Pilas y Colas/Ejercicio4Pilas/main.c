/*Ejercicio 4 - Determinar si el valor que se encuentra en la base de una pila coincide con un valor dado.

a.- No es necesario conservar la pila.
b.- Conservar la pila (Utilizar estructura auxiliar)



*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pilas.h"


void SeEncuentra(TPila *,int *); //La pila se perdera
void SeEncuentraConAux(TPila *,int *); //Se utiliza estrctura auxiliar y la pila se conserva

void muestraP(TPila*); //Muestra la pila

void main(){
    TPila p;
    int x = 0
    int aux;
    IniciaP(&p); // Inicialiso la pila
    for(int i = 0;i<10;i++) { // Cargo la pila del 0 al 10
        poneP(&p,i);
    }

 
    /*
    //EjercicioA
    SeEncuentra(&p,&x);

    if (x==1)
         printf("El valor que se encuentra en la base de una pila coincide con el valor dado\n");
    else
        printf("El valor que se enceuntra en la base de la pila NO COINCIDE CON EL VALOR dado\n");
    */

       /*
    //EjercicioB
    SeEncuentraConAux(&p,&x);
     if (x==1)
         printf("El valor que se encuentra en la base de una pila coincide con el valor dado\n");
    else
        printf("El valor que se enceuntra en la base de la pila NO COINCIDE CON EL VALOR dado\n")
         */



    printf("La pila es \n");
    muestraP(&p);






}

void SeEncuentra(TPila *p,int *x) {
    int aux;
    while(!VaciaP(*p)) {
        sacaP(p,&aux);
    }
    if(aux == *x)
        *x = 1;
    else
        *x = 0;
}

void SeEncuentraConAux(TPila *p,int *x) {
    int aux;
    TPila a;
    while(!VaciaP(*p)) {
        sacaP(p,&aux);
        poneP(&a,aux);
    }
    if(aux == *x)
        *x = 1;
    else
        *x = 0;
    while(!VaciaP(a)) {
        sacaP(&a,&aux);
        poneP(p,aux);
    }

}




void muestraP(TPila* p) {
    ElementoP x;
    while(!VaciaP(*p)) {
        sacaP(p,&x);
        printf("%d\n",x);
    }
}
