/* Sea A una matriz de NxM elementos reales, escribir funciones que permitan:
a) hallar el promedio de los elementos positivos (función float).
b) hallar el mínimo de las columnas impares (función int)
c) hallar el máximo de las filas pares (función void)
d) generar un archivo de texto que contengas una línea por cada fila de la matriz que tienen
todos los valores pares, colocando en la línea NROFILA SUMPARES
e) escribir un programa que lea N, M y la matriz desde un archivo de texto DATOS.TXT, y
luego mediante un menú repetitivo invoque a la función correspondiente (desarrolladas de
a) a d)) mostrando el resultado*/
#include <stdio.h>
#define MAXFILAS 100
#define MAXCOLUMNAS 100


float promedioPositivos(float matriz[MAXFILAS][MAXCOLUMNAS], int filas, int columnas);
int minimoColumnasImpares(float matriz[MAXFILAS][MAXCOLUMNAS],int filas, int columnas);
void maximoFilasPares(float matriz[MAXFILAS][MAXCOLUMNAS], int filas, int columnas);
void generarArchivoPares(float matriz[MAXFILAS][MAXCOLUMNAS], int filas, int columnas);





int main() {

    int filas , columnas;
    float matriz[MAXFILAS][MAXCOLUMNAS];
    int opcion;
    int i,j;

    //Leeo primero las filas y las columnas
    FILE *archivo=fopen("Ejercicio26.txt","r");
    fscanf(archivo,"%d %d" , &filas , &columnas);


    //leeo la matriz
    fseek(archivo,3*sizeof(char),SEEK_SET); // Salta la primera linea
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            fscanf(archivo, "%f", &matriz[i][j]);
        }
    }
    printf("La matriz a evaluar es\n");
     for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            printf("%f ", matriz[i][j]);
        }
        printf("\n");
    }

   fclose(archivo);

   do {
        printf("\n");
        printf("Menu:\n");
        printf("1) Hallar el promedio de los elementos positivos.\n");
        printf("2) Hallar el minimo de las columnas impares.\n");
        printf("3) Hallar el maximo de las filas pares.\n");
        printf("4) Generar un archivo con las filas que tienen todos los valores pares.\n");
        printf("5) Salir.\n");
        printf("Seleccione una opcion: ");
        scanf(" %d", &opcion);

        switch (opcion) {
            case 1: {
                float promedio = promedioPositivos(matriz, filas, columnas);
                printf("El promedio de los elementos positivos es: %f \n", promedio);
                break;
            }
            case 2: {
                 for (j = 1; j < columnas; j += 2) {
                int minimo = minimoColumnasImpares(matriz,filas, j);
                printf("El minimo de la columna %d es: %d \n", j,minimo);
                 }
                break;
            }
            case 3: {
                maximoFilasPares(matriz, filas, columnas);
                break;
            }
            case 4: {
                generarArchivoPares(matriz, filas, columnas);
                printf("El archivo PARES.TXT ha sido generado exitosamente.\n");
                break;
            }
            case 5: {
                printf("Saliendo del programa...\n");
                break;
            }
            default: {
                printf("Opcion invalida. Intente nuevamente.\n");
                break;
            }
        }
    } while (opcion != 5);



    return 0;

}

//Ejercicio 1
float promedioPositivos(float matriz[MAXFILAS][MAXCOLUMNAS], int filas, int columnas) {
    int i, j;
    float suma = 0;
    int contador = 0;

    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            if (matriz[i][j] > 0) {
                suma += matriz[i][j];
                contador++;
            }
        }
    }

    if (contador > 0) {
        return suma / contador;
    } else {
        return 0;
    }
}





//Ejercicio 2
int minimoColumnasImpares(float matriz[MAXFILAS][MAXCOLUMNAS],int filas ,int columnas) {
    int i;
    int minimo=999;

    for (i = 1; i < filas; i++) {
          if (matriz[i][columnas] < minimo) {

                minimo = matriz[i][columnas];
            }

        }

    return minimo;
}











void maximoFilasPares(float matriz[MAXFILAS][MAXCOLUMNAS], int filas, int columnas) {
    int i, j;
    float maximo;

    for (i = 0; i < filas; i += 2) {
        maximo = matriz[i][0];

        for (j = 1; j < columnas; j++) {
            if (matriz[i][j] > maximo) {
                maximo = matriz[i][j];
            }
        }

        printf("El maximo de la fila %d es: %.2f\n", i, maximo);
    }
}




void generarArchivoPares(float matriz[MAXFILAS][MAXCOLUMNAS], int filas, int columnas) {
    int i, j;
    int todosPares;
    int sumaPares;
    FILE *archivo = fopen("PARES.TXT", "w");

    for (i = 0; i < filas; i++) {
        todosPares = 1;
        sumaPares = 0;

        for (j = 0; j < columnas; j++) {
                sumaPares += (int)matriz[i][j];
            if ((int)matriz[i][j] % 2 != 0) {
                todosPares = 0;
                break;
            }
        }

        if (todosPares) {

            fprintf(archivo,"%s", "numero Fila Suma de todos los Pares\n");
            fprintf(archivo, "%d ", i);
            fprintf(archivo, "%d\n", sumaPares);
        }
    }

    fclose(archivo);
}
