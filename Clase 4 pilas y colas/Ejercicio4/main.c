/*Ej 4.- Determinar si el valor que se encuentra en la base de una pila coincide con un valor dado.
Resolverlo de 3 formas diferentes:
a.- No es necesario conservar la pila.
b.- Conservar la pila (Utilizar estructura auxiliar)
c.- Conservar la pila (Sin utilizar estructura auxiliar) */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Pilas.h"


void SeEncuentra(TPila *p,int *x,int valor); //La pila se perdera
void SeEncuentraConAux(TPila *p,int *ok,int valor);//Se utiliza estrctura auxiliar y la pila se conserva
void SeEncuentraSinaux(TPila *p,int *ok,int valor);

void muestraP(TPila*p); //Muestra la pila

void main(){
    TPila p;
    int valor,ok;
    IniciaP(&p); // Inicialiso la pila
    for(int i = 0;i<10;i++) { // Cargo la pila del 0 al 10
        poneP(&p,i);
    }


    printf ("Ingrese el valor , el primer valor esta en la base de la pila  \n");
    scanf("%d",&valor);

  /*
    //EjercicioA
    SeEncuentra(&p,&ok,valor);

    if (ok)
         printf("El valor que se encuentra en la base de la pila coincide con el valor dado\n");
    else
        printf("El valor que se enceuntra en la base de la pila NO COINCIDE CON EL VALOR dado\n");

    //EjercicioB
    SeEncuentraConAux(&p,&ok,valor);

    if (ok)
         printf("El valor que se encuentra en la base de la pila coincide con el valor dado\n");

    else
        printf("El valor que se enceuntra en la base de la pila NO COINCIDE CON EL VALOR dado\n");*/

        //EjercicioC

 SeEncuentraSinaux(&p,&ok,valor);

    if (ok)
         printf("El valor que se encuentra en la base de la pila coincide con el valor dado\n");

    else
        printf("El valor que se enceuntra en la base de la pila NO COINCIDE CON EL VALOR dado\n");


}





void SeEncuentra(TPila *p,int *ok,int valor) {
   ElementoP x;
    while(!VaciaP(*p)) {
        sacaP(p,&x);
    }
    if(x == valor)
        *ok = 1;
    else
        *ok = 0;
}





void SeEncuentraConAux(TPila *p,int *ok,int valor) {
    ElementoP x;
    TPila aux;
    IniciaP(&aux);
    while(!VaciaP(*p)) {
        sacaP(p,&x);
        poneP(&aux,x);

    if(x== valor)
        *ok = 1;
    else
        *ok= 0;

    while(!VaciaP(aux)) {
        sacaP(&aux,&x);
        poneP(p,x);

    }

}}



void SeEncuentraSinaux(TPila *p,int *ok,int valor){

int aux =0 ;
ElementoP x;
poneP(p,aux);
sacaP(p,&x);

while (x!=aux) {
sacaP(p,&x);

}


  if(x== valor)
        *ok = 1;
    else
        *ok= 0;



}

