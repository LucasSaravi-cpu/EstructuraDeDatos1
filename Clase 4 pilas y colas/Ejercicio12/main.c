/* Ejercicio2
Generar una pila de enteros a partir de un archivo de texto, luego desarrollar subprogramas sin perder la pila de forma recursiva
a.- obtener promedio de sus elementos.
b.- obtener elemento que está en el fondo de la pila


En ninguna de las soluciones anteriores se puede perder la pila*/


#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"


void promedio (TPila* P,float* prom,int *n);
void elementofondo(TPila* P,int* Fondo );


void main(){
   int cantidad;
   float prom=0;
   int n=0;
   TPila P;


   FILE *arch;
   arch = fopen("Ejercicio12.txt","r");


   IniciaP(&P);
   printf("El primer dato ingresado es el dato que esta en el fondo de la pila  \n");
   while (!feof(arch)) {
        fscanf(arch,"%d\n",&cantidad);
        poneP(&P,cantidad);

        printf("Se ingreso el dato correcto a la pila | %d | \n",cantidad);
   }
   fclose(arch);

   promedio (&P,&prom,&n);
   printf("El promedio de los elementos es: %2.2f\n",  prom / n);




   elementofondo(&P,&cantidad);
   printf("El valor del fondo de la pila es: %d\n",cantidad);



while (!VaciaP(P)) {
        sacaP(&P,&cantidad);
        printf("%d\n",cantidad);
   }




}

void promedio (TPila* P,float* prom,int *n) { // El promedo va salir como variable por eso es un puntero
    ElementoP x;


        if (!VaciaP(*P)){

           sacaP(P,&x);
           *prom+=x;
            (*n)++;
            promedio(P,prom,n);
           poneP(P,x);
        }

}

void elementofondo(TPila* P,int* Fondo ) {
    ElementoP x;


    if (!VaciaP(*P)) {
        sacaP(P,&x);
        *Fondo = x;
        elementofondo(P,Fondo);
        poneP(P,x);
    }

}


