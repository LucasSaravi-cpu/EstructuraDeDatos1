/*Ejercicio 5 Poner el primer elemento de una pila en la última posición, dejando los demás elementos en
el mismo orden (en la pila original)


*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pilas.h"


void Intercambio(TPila *p,TPila *p2);

void main(){
    TPila p,p2;
    int x;
    IniciaP(&p); // Inicialiso la pila
    for(int i = 0;i<10;i++) { // Cargo la pila del 0 al 10
        poneP(&p,i);
    }

    Intercambio(&p,&p2); // Se intercambiara el 0 por el 9
     while (!VaciaP(p2)) {
        sacaP(&p2,&x);
        printf("%d\n",x);
     }

}


void Intercambio(TPila *p,TPila *p2) {  //Va salir p2 modificada
     int elemento,ultimo,primero;
     TPila aux;
     IniciaP(p2);
     IniciaP(&aux); //Uso una pila auxiliar
     sacaP(p,&primero);
     poneP(p2,primero);//Saco el primer elemento de la pila
     while(!VaciaP(*p)) {  // Luego mientras la pila no esta vacia voy sacando y poniendo en el ultimo
        sacaP(p,&elemento);
        poneP(&aux,elemento);
     }
     if(!VaciaP(aux))  //Si la pila no esta vacia entonces saco el ultimo que ahora es el primero
       sacaP(&aux,&ultimo);
     while(!VaciaP(aux)) {  //Mientras qe la pila se encuentre llena la vacio y la pongo en p2
        sacaP(&aux,&elemento);
        poneP(p2,elemento);
     }
     poneP(p2,ultimo); //Se le agrega el ultimo elemento guardado a la pila modificada
}
