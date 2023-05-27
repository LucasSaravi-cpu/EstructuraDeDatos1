#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contacto.h"
void agregaC(agenda *A,char Nombre[],long tel) {
        contacto c;
        strcpy(c.nombre,Nombre);
        c.telefono = tel;
        A.a[A.tam] = c;
        A.tam ++;
}
void inicializaA(agenda *A) {
    A.tam = 0;
}
void listaAgenda(contacto A[],int N) {
    int i;
    for (i = 0;i<N;i++) {
        printf("%s %ld \n",A[i].nombre,A[i].telefono);
    }
}
void buscaNombre(contacto A[],int N,char nom[]) {
    int i = 0;
    while((i<N) && (strcmp(nom,A[i].nombre) != 0)) {
        i++;
    }
    if (i==N) {
        printf("Ese contacto no esta en la lista \n");
    }else{
        printf("El telefono es %ld \n",A[i].telefono);
    }
}
void buscaNombreB(contacto A[],int N,char nom[]) {
    int primero = 0;
    int ultimo = N-1;
    int medio = (primero+ultimo)/2;
    while(primero<=ultimo) {
        if((strcmp(A[medio].nombre,nom) == 0)) { //es igual
           primero++;
        }else if (strcmp(A[medio].nombre,nom) > 0) { //esta mas abajo en las cadenas
            ultimo = medio - 1;
        }else {
            primero=medio+1;
        }
        medio = (primero+ultimo)/2;
    }
    if(strcmp(A[medio].nombre,nom) == 0) {
       printf("El telefono es %ld \n",A[medio].telefono);
    }else{
        printf("Ese contacto no esta en la lista \n");
    }
}
