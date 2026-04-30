/* Ejercicio2
Generar una pila de enteros a partir de un archivo de texto, luego desarrollar subprogramas sin perder la pila
a.- obtener promedio de sus elementos.
b.- obtener elemento que está en el fondo de la pila
c.- obtener la cantidad de elementos que son mayores que el promedio
d.- intercambiar el primer elemento con el último elemento

En ninguna de las soluciones anteriores se puede perder la pila*/


#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"


void promedio (TPila* P,float* promedio);
void elementofondo(TPila* P,int* Fondo );
void cantidadMayoresAlProm(TPila* P,float prom,int* cant);
void Intercambio(TPila *P);

void main(){
   int cantidad;
   float prom;
   TPila P;


   FILE *arch;
   arch = fopen("Ejercicio2.txt","r");


   IniciaP(&P);
   printf("El primer dato ingresado es el dato que esta en el fondo de la pila  \n");
   while (!feof(arch)) {
        fscanf(arch,"%d\n",&cantidad);
        poneP(&P,cantidad);

        printf("Se ingreso el dato correcto a la pila | %d | \n",cantidad);
   }
   fclose(arch);

   promedio (&P,&prom);
   printf("El promedio de los elementos es: %2.2f\n",prom);

   elementofondo(&P,&cantidad);
   printf("El valor del fondo de la pila es: %d\n",cantidad);

   cantidadMayoresAlProm(&P,prom,&cantidad);
   printf("La cantidad de elementos mayores al promedio es: %d\n",cantidad);

   printf("La fila que intercambia el ultimo elemento con el primero es: \n");

   Intercambio(&P);

   while (!VaciaP(P)) {
        sacaP(&P,&cantidad);
        printf("%d\n",cantidad);
   }


}

void promedio (TPila* P,float* promedio) { // El promedo va salir como variable por eso es un puntero
    ElementoP x;
    *promedio = 0;
    int n = 0;
    TPila aux;  // Uso de pila auxiliar para no perder la pila
    IniciaP(&aux);

    while (!VaciaP(*P)) {
        n++;
        sacaP(P,&x);
        *promedio += x;
        poneP(&aux,x);
    }
    if(n!=0)
       *promedio /= n;
    else
       *promedio = 0;


    while (!VaciaP(aux)){

        sacaP(&aux,&x);
        poneP(P,x);


    }
}

void elementofondo(TPila* P,int* Fondo ) {
    ElementoP x;
    TPila aux;  // Uso de pila auxiliar para no perder la pila
    IniciaP(&aux);
    while (!VaciaP(*P)) {
        sacaP(P,&x);
        poneP(&aux,x);
    }
    *Fondo = x;

    while (!VaciaP(aux)) {
        sacaP(&aux,&x);
        poneP(P,x);

    }

}
void cantidadMayoresAlProm(TPila* P,float prom,int* cant) {
    ElementoP x;
    TPila aux;  // Uso de pila auxiliar para no perder la pila
    IniciaP(&aux);

    *cant = 0;
    while (!VaciaP(*P)) {
        sacaP(P,&x);
        if(x>prom)
            (*cant)++;

         poneP(&aux,x);

    }



      while (!VaciaP(aux)){

        sacaP(&aux,&x);
        poneP(P,x);


    }

}


void Intercambio(TPila *P) {
    TPila aux;
    IniciaP(&aux);

    ElementoP x;
    int primero, ultimo;


    sacaP(P, &x);
    ultimo = x;


    while (!VaciaP(*P)) {
        sacaP(P, &x);
        poneP(&aux, x);
    }
    sacaP(&aux, &x);
    primero = x;
    poneP(P, ultimo);

    while (!VaciaP(aux)) {
        sacaP(&aux, &x);
        poneP(P, x);
    }


    poneP(P, primero);
}
