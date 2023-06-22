/* Ejercicio2
Generar una pila de enteros a partir de un archivo de texto, luego desarrollar subprogramas
para hallar:
a.- el promedio de sus elementos.
b.- el elemento que está en el fondo de la pila
c.- la cantidad de elementos que son mayores que el promedio
d.- intercambiar el primer elemento con el último elemento
En ninguna de las soluciones anteriores se puede perder la pila*/


#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"


void promedio (TPila* ,float* );
void elementofondo(TPila* ,int*);
void cantidadMayoresAlProm(TPila* ,float ,int*);
void Intercambio(TPila *,int);

void main(){
   int cantidad;
   float prom;
   TPila P;

   FILE *arch;
   arch = fopen("Ejercicio.txt","r");


   IniciaP(&P);
   while (!feof(arch)) {
        fscanf(arch,"%d\n",&cantidad);
        poneP(&P,cantidad);
        printf("Se ingreso el dato correcto a la pila | %d | \n",cantidad);
   }
   fclose(arch);

   //Muestra la pila del txt , si lo hago se perdera
 /*while (!VaciaP(P)) {
        sacaP(&P,&cantidad);
        printf("%d\n",cantidad);
   }*/

   /*promedio (&P,&prom);
   printf("El promedio de los elementos es: %2.2f\n",prom);*/

  /*elementofondo(&P,&cantidad);
   printf("El valor del fondo de la pila es: %d\n",cantidad);*/

  /* cantidadMayoresAlProm(&P,5,&cantidad); //ingreso el promedio ya registrado en funcion promedio
   printf("La cantidad de elementos mayores al promedio es: %d\n",cantidad); */

/*printf("La fila que intercambia el ultimo elemento con el primero es: \n");

   Intercambio(&P,7);  //Se ingresa la cantidad de elementos del arreglo

   while (!VaciaP(P)) {
        sacaP(&P,&cantidad);
        printf("%d\n",cantidad);
   }*/

   return 0;


}

void promedio (TPila* P,float* promedio) { // El promedo va salir como variable por eso es un puntero
    *promedio = 0;
    int n = 0,x;
    while (!VaciaP(*P)) {
        n++;
        sacaP(P,&x);
        *promedio += x;
    }
    if(n!=0)
       *promedio /= n;
    else
       *promedio = 0;
}

void elementofondo(TPila* P,int* Fondo ) {
    int x;
    while (!VaciaP(*P)) {
        sacaP(P,&x);
    }
    *Fondo = x;
}
void cantidadMayoresAlProm(TPila* P,float prom,int* cant) {
    int n = 0,x;
    while (!VaciaP(*P)) {
        sacaP(P,&x);
        if(x>prom)
            n++;
    }
    *cant = n;
}
void Intercambio(TPila *P,int cantEl) {
    int x,i;
    int primero,ultimo;
    TPila N,M;
    N = *P;
    while (!VaciaP(*P)) {
        sacaP(P,&x);
        poneP(&M,x);
    }
    sacaP(&N,&primero);
    poneP(P,primero);
    sacaP(&M,&x);
    for (i = cantEl-1;i>=0;i--) {
            sacaP(&M,&x);
            poneP(P,x);
            sacaP(&N,&x);
    }
    sacaP(&N,&ultimo);
    poneP(P,ultimo);
}

