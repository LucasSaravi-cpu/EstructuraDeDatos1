#include <stdio.h>
#include <string.h>
#include "Contacto.h"

void inicializaA(agenda *A) {
    A->tam = 0;
}

// Inserta ORDENADO
void agregaC(agenda *A, char Nombre[], long tel) {
    int i = A->tam - 1;

    while (i >= 0 && strcmp(A->a[i].nombre, Nombre) > 0) {
        A->a[i + 1] = A->a[i];
        i--;
    }

    strcpy(A->a[i + 1].nombre, Nombre);
    A->a[i + 1].telefono = tel;
    A->tam++;
}

void listaAgenda(contacto A[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%s %ld\n", A[i].nombre, A[i].telefono);
    }
}

void buscaNombre(contacto A[], int N, char nom[]) {
    int i = 0;

    while (i < N && strcmp(A[i].nombre, nom) != 0) {
        i++;
    }

    if (i == N) {
        printf("Ese contacto no esta en la lista\n");
    } else {
        printf("El telefono es %ld\n", A[i].telefono);
    }
}


void buscaNombreB(contacto A[], int N, char nom[]) {
    int primero = 0, ultimo = N - 1, medio;

    while (primero <= ultimo) {
        medio = (primero + ultimo) / 2;

        int cmp = strcmp(A[medio].nombre, nom);

        if (cmp == 0) {
            printf("El telefono es %ld\n", A[medio].telefono);
            return;
        } else if (cmp > 0) {
            ultimo = medio - 1;
        } else {
            primero = medio + 1;
        }
    }

    printf("Ese contacto no esta en la lista\n");
}
