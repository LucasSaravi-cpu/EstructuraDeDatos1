/*
En una escuela secundaria para el último año se tiene un archivo de texto Notas.txt con 
las notas finales de las 10 materias, el formato una línea por alumno con Número de matrícula (0 a 
99) y las 10 notas finales separadas por espacios (pueden no estar los 100 alumnos ni vienen
ordenados)
Desarrollar una función para generar una matriz de 100x10 con las notas finales donde las filas 
representan el número de matrícula y las columnas las materias (las filas que no representen 
alumnos pues no se encuentran los datos deben quedar en 0) y luego desarrollar: 
a) una función (int) que devuelva la cantidad de alumnos recibidos (todas las notas más de 4)
b) una función (int) que devuelva la cantidad de alumnos que deben rendir más de 2 materias 
(deben rendir aquellas en las que no tienen al menos 4).
c) una función (void) que devuelva en dos parámetros el alumno recibido con mayor nota 
promedio (número de matrícula y nota promedio final)*/
#include <stdio.h>
#include <stdlib.h>

#define NUM_ALUMNOS 100
#define NUM_MATERIAS 10

int main() {
    FILE *archivo;
    char linea[100];
    int matricula, notas[NUM_MATERIAS];
    int matriz_notas[NUM_ALUMNOS][NUM_MATERIAS] = {0}; // Inicializar todo en 0
    int aprobados,recuperar,matriMejor;
    float maxProm;

    archivo = fopen("Ejercicio23.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    while (fgets(linea, 100, archivo) != NULL) {
        sscanf(linea, "%d %d %d %d %d %d %d %d %d %d %d",
               &matricula, &notas[0], &notas[1], &notas[2], &notas[3],
               &notas[4], &notas[5], &notas[6], &notas[7], &notas[8], &notas[9]);

        // Indexar la fila correspondiente en la matriz y guardar las notas
        if (matricula >= 0 && matricula < NUM_ALUMNOS) {
            for (int i = 0; i < NUM_MATERIAS; i++) {
                matriz_notas[matricula][i] = notas[i];
            }
        }
    }

    fclose(archivo);

    // Imprimir la matriz de notas
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        printf("Alumno %d: ", i);
        for (int j = 0; j < NUM_MATERIAS; j++) {
            printf("%d ", matriz_notas[i][j]);
        }
        printf("\n");
    }

aprobados = contar_alumnos_aprobados(matriz_notas);
recuperar=contar_alumnos_a_recuperar(matriz_notas);
obtener_alumno_mejor_promedio(matriz_notas,&matriMejor,&maxProm);

printf("La cantidad de alumnos aprobados es %d \n" ,aprobados );
printf("La cantidad de alumnos a recuperar con dos materias desaprobadas es %d \n" ,recuperar );
printf("El mejor alumno es el %d y su promedio es de %f", matriMejor, maxProm);

    return 0;


}



int contar_alumnos_aprobados(int matriz_notas[][NUM_MATERIAS]) {
    int contador = 0;

    for (int i = 0; i < NUM_ALUMNOS; i++) {
        int aprobado = 1; // Suponemos que el alumno ha aprobado todas las materias

        for (int j = 0; j < NUM_MATERIAS; j++) {

            if (matriz_notas[i][j] <= 4) {
                aprobado = 0; // Si alguna nota es menor o igual a 4, no ha aprobado todas las materias
                break;
            }
        }
        if (aprobado) {
            contador++;
        }
    }

    return contador;
}

int contar_alumnos_a_recuperar(int matriz_notas[][NUM_MATERIAS]) {
    int contador = 0;

    for (int i = 0; i < NUM_ALUMNOS; i++) {
        int materias_a_recuperar = 0;
        for (int j = 0; j < NUM_MATERIAS; j++) {
            if ((matriz_notas[i][j] < 4) &&  (matriz_notas[i][j]>0) ) {
                materias_a_recuperar++;
            }
        }
        if (materias_a_recuperar > 2) {
            contador++;
        }
    }

    return contador;
}


void obtener_alumno_mejor_promedio(int matriz_notas[][NUM_MATERIAS], int *max_matricula, float *max_promedio) {
    float mejor_promedio = 0.0;
    int mejor_matricula = -1;

    for (int i = 0; i < NUM_ALUMNOS; i++) {
        int suma_notas = 0;
        int num_materias = 0;
        for (int j = 0; j < NUM_MATERIAS; j++) {
            if (matriz_notas[i][j] > 0) {
                suma_notas += matriz_notas[i][j];
                num_materias++;
            }
        }
        if (num_materias > 0) {
            float promedio = (float)suma_notas / num_materias;
            if (promedio > mejor_promedio) {
                mejor_promedio = promedio;
                mejor_matricula = i;
            }
        }
    }

    *max_matricula = mejor_matricula;
    *max_promedio = mejor_promedio;
}
