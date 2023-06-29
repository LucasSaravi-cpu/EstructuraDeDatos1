#include <stdlib.h>
#include <stdio.h>
#include "colas.h"
/*Ej 10.- Corregir los errores en el siguiente código manualmente, el cual carga una cola de tipo
TCOLA de enteros y luego calcula y muestra el menor de sus elementos.*/

void leerCola(TCola *c);
int main(void) {
 TCola cola;
 int n,min; //TELEMENTO C n es de tipo int ya que son numeros naturales
 leerCola(&cola); //No hace falta inicializar el min ya que el min sera uno de los datos de la cola
 if(!vaciaC(cola))
    sacaC(&cola,&min); //Inicializo min con el primer elemento que saco de la cola si la cola no esta vacia
 while(!vaciaC(cola)) { // Mientras qe la cola no este vacia
    sacaC(&cola, &n); //le asigno a n los siguientes elementos que saco
    if(n<min)         //Hago un min entre los elementos ...
        min = n;
 }
 printf("El minimo es %d", min);
 return 0;
}


void leerCola(TCola *c) {
 int n;
 iniciaC(c);  //No lleva & y se inicializa una sola vez la cola
 printf("Escribe el numero \n");
 scanf("%d", &n);
 while(!n==0){ //Si no hay algo que corte el while sigue ejecutandose infinitamente
    poneC(c, n);
    printf("Escribe el siguiente numero para salir ingrese 0 \n");
    scanf("%d", &n);
 }
}
