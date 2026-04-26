#include <stdio.h>
#include <stdlib.h>
#include "Contacto.h"

int main() {
    FILE *arch;
    agenda A;
    int res;
    char Nombre[50];
    long telefono;

    inicializaA(&A);

    arch = fopen("Texto.txt", "r");

    if (arch == NULL) {
        printf("Archivo no existe\n");

    }else{

    //Cargar agenda
    while (fscanf(arch, "%d %s", &telefono, Nombre) == 2) {
        agregaC(&A, Nombre, telefono);
    }

    fclose(arch);

    printf("\n--- AGENDA ---\n");
    listaAgenda(A.a, A.tam);

    printf("\nDesea buscar un nombre? (1-si,0-no): ");
    scanf("%d", &res);

    while (res != 0) {
        printf("Ingrese un nombre: ");
        scanf("%s", Nombre);

        buscaNombreB(A.a, A.tam, Nombre);

        printf("\nDesea buscar otro? (1-si,0-no): ");
        scanf("%d", &res);
    }

    }
    return 0;
}
