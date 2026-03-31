/*Ej 2. Se ingresa por teclado N y a continuación N ternas: fil, col, num. Que representa que el
entero positivo Num, corresponde a la posición [fil, col] de la matriz M. La matriz puede a lo sumo
ser de 20x20 y los datos que se ingresan son correctos. Se pide, modularizando adecuadamente:
a) Generar la matriz M, considerando que no necesariamente se leen todas las posiciones y
los datos no vienen ordenados por ningún criterio.
b) Desarrollar una función void que reciba M y devuelva la cantidad de valores pares y de
valores impares que hay en las filas pares de la matriz (2, 4, 6, etc).
c) Escribir el main.c completo.*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void cargarMatriz(int M[MAX][MAX], int n);
void contarParImpar(int M[MAX][MAX], int *pares, int *impares, int n);
void mostrarMatriz(int M[MAX][MAX], int n);

int main() {
    int M[MAX][MAX];
    int n, pares, impares;

    printf("Ingresar tamanio de la matriz:\n");
    scanf("%d", &n);

    cargarMatriz(M, n);

    mostrarMatriz(M, n);

    contarParImpar(M, &pares, &impares, n);

    printf("Pares: %d - Impares: %d\n", pares, impares);

    return 0;
}


void cargarMatriz(int M[MAX][MAX], int n) {
    int fil, col, num;

    // inicializar
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            M[i][j] = 0;

    printf("Ingrese fila (0 para terminar): ");
    scanf("%d", &fil);

    while(fil != 0) {

        printf("Ingrese columna y numero: ");
        scanf("%d %d", &col, &num);

        if(fil >= 1 && fil <= n && col >= 1 && col <= n) {
            M[fil-1][col-1] = num;
        } else {
            printf("Posicion invalida\n");
        }

        printf("Ingrese fila (0 para terminar): ");
        scanf("%d", &fil);
    }
}
void contarParImpar(int M[MAX][MAX], int *pares, int *impares, int n) {
    *pares = 0;
    *impares = 0;

    for(int i=1;i<n;i+=2) {
        for(int j=0;j<n;j++) {
            if(M[i][j] != 0) {
                if(M[i][j] % 2 == 0)
                    (*pares)++;
                else
                    (*impares)++;
            }
        }
    }
}


void mostrarMatriz(int M[MAX][MAX], int n) {
    printf("\nMATRIZ:\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%4d", M[i][j]);
        }
        printf("\n");
    }
}
