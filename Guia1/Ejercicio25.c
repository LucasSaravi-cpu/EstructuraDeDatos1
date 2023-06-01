/* Sea A un vector de N elementos enteros, escribir funciones que permitan:
a) hallar el promedio de los elementos positivos (función float).
b) hallar el mínimo de los impares (función int)
c) hallar el máximo de las posiciones pares (función void)
d) generar un vector B con los elementos de A que sean mayores a K (K debe leerse)
e) escribir un programa que lea N y un vector N elementos desde un archivo de texto
DATOS.TXT, y luego mediante un menú repetitivo invoque a la función correspondiente
(desarrolladas de a) a d)) mostrando el resultado.*/

#include <stdio.h>
#define MAX 100

float Promedio (int v[], int n);
int Minimo(int A[], int N);
void  MaximoPosPares(int v[], int n);

int main() {

    int vector[MAX];
    int k;
    int vectorb[MAX];
    int tamB;
    int n=0;
    int opcion;

    FILE *archivo = fopen("datos.txt", "r"); //r solo para lectura

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    while (!feof(archivo)) {
        int elemento;
        if (fscanf(archivo, "%d", &elemento) == 1) { // Si se lee bien devolvera un 1
            vector[n++] = elemento;
        }
    }

    do {
        printf("\nMenu:\n");
        printf("1. Calcular promedio de los elementos positivos\n");
        printf("2. Encontrar el minimo de los impares\n");
        printf("3. Encontrar el maximo de las posiciones pares\n");
        printf("4. Generar vector B con elementos mayores a K\n");
        printf("5. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
     switch (opcion) {
            case 1:printf("El promedio de los elementos positivos es: %f \n", Promedio(vector, n));
                   break;
            case 2:printf("El minimo de los impares es: %d\n", Minimo(vector,n));
                   break;
            case 3: MaximoPosPares(vector,n);
                    break;
            case 4: printf("Ingrese el valor K: ");
                    scanf("%d", &k);
                    GenerarVectorB(vector,n, k, vectorb, &tamB);
                    printf("El nuevo vector es\n");
                    for (int i = 0; i < tamB; i++) {
                    printf("%d ", vectorb[i]);
                    }
                    break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("opcion incorrecta \n");
                break;
        }
     } while (opcion != 5);







    return 0;


}


// Ejercicio A Función para calcular el promedio de los elementos positivos

float Promedio (int v[], int n) {
    int suma = 0;
    int canPositivos = 0;

    for (int i = 0; i < n; i++) {
        if (v[i] > 0) {
            suma += v[i];
            canPositivos++;
        }
    }

    if (canPositivos > 0) {
        return (float)suma / canPositivos;
    } else {
        return 0.0;
    }
}

// Ejercicio B Función para encontrar el mínimo de los impares
int Minimo(int v[], int n) {

    int minimo = v[0]; // El minimo va ser el primer numero del arreglo

    for (int i = 0; i < n; i++) {

        if (v[i] % 2 != 0 && v[i] < minimo  && v[i]>0) {  // El minimo Impar positivo
            minimo = v[i];
        }

    }

return minimo;

}


// EJERCICIO C hallar el máximo de las posiciones pares (función void)

void  MaximoPosPares(int v[], int n) {
    int maximo = v[0];

    for (int i = 0; i < n; i += 2) {
        if (v[i] > maximo) {
            maximo = v[i];
        }
    }

 printf("El maximo de las posiciones pares es: %d\n", maximo);

}

// Ejercicio D generar un vector B con los elementos de A que sean mayores a K (K debe leerse)

void GenerarVectorB(int v[], int n, int k, int b[], int* tamB) {
    *tamB = 0;

    for (int i = 0; i < n; i++) {
        if (v[i] > k) {
            b[*tamB] = v[i];
            (*tamB)++;
        }
    }
}
