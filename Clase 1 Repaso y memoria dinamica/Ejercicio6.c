#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"

int main() {
    ptPersona pt1, pt2;

    pt1 = (ptPersona) malloc(sizeof(strPersona)); // Se reserva memoria para el puntero
    pt2 = (ptPersona) malloc(sizeof(strPersona));

    printf("Persona 1:\n");
    printf("Nombre: ");
    scanf("%s", pt1->Nombre);
    printf("Edad: ");
    scanf("%d", &pt1->Edad);

    printf("\nPersona 2:\n");
    printf("Nombre: ");
    scanf("%s", pt2->Nombre);
    printf("Edad: ");
    scanf("%d", &pt2->Edad);


    //Se enlasa
    /*pt1->sig = pt2;
    pt2->sig = NULL;*/

    if (pt1->Edad < pt2->Edad) {
        printf("El mas joven es: %s\n", pt1->Nombre);
    } else {
        printf("El mas joven es: %s\n", pt2->Nombre);
    }

    //printf("\nAccediendo al siguiente de pt1: %s\n", pt1->sig->Nombre);

    free(pt1);
    free(pt2);

    return 0;
}
