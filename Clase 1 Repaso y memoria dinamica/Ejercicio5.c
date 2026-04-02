/*Escribir un programa que cree un arreglo estático de punteros a enteros,
 y luego cargue en él N enteros (N y los enteros se encuentran en un archivo de texto).
Mostrar aquellos que sean positivos. Al finalizar, liberar la memoria solicitada en tiempo de ejecución.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    FILE *archivo;
    int *vec[MAX];  // arreglo estático de punteros
    int N, i;

    archivo = fopen("datos.txt", "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");

    }else{


    fscanf(archivo, "%d", &N);


    for (i = 0; i < N; i++) {
        vec[i] = (int *) malloc(sizeof(int));
        fscanf(archivo, "%d", vec[i]);
    }

    fclose(archivo);


    printf("Numeros positivos:\n");
    for (i = 0; i < N; i++) {
        if (*vec[i] >= 0) {
            printf("%d\n", *vec[i]);
        }
    }


    for (i = 0; i < N; i++) {
        free(vec[i]);
    }
}
    return 0;
}
