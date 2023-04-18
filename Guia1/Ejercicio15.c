/*Ej 15 – Desarrollar un programa que solicite por teclado N y los siguientes datos de N alumnos:
Nombre (cadena de 30), Numero de Matricula (entero), Nombre de Carrera (cadena de 30).
Almacenar estos datos en un arreglo de structs.
Muestre por pantalla los datos ingresados con un alumno por línea solo para aquellos que estudian
Ingeniería en Informática
*/

#include <stdio.h>
#include <string.h>

// Definición de la estructura Alumno
struct Alumno {
    char nombre[30];
    int matricula;
    char carrera[30];
};

int main() {
    int n;

    // Solicitar por teclado el número de alumnos
    printf("Ingrese el número de alumnos: ");
    scanf("%d", &n);

    // Declarar y crear un arreglo de N elementos de tipo Alumno
    struct Alumno alumnos[n];

    // Solicitar por teclado los datos de cada alumno
    for (int i = 0; i < n; i++) {
        printf("Datos del alumno #%d\n", i + 1);

        // Nombre
        printf("Nombre: ");
        scanf(" %[^\n]s", alumnos[i].nombre);

        // Número de matrícula
        printf("Número de matrícula: ");
        scanf("%d", &alumnos[i].matricula);

        // Carrera
        printf("Carrera: ");
        scanf(" %[^\n]s", alumnos[i].carrera);

        printf("\n");
    }

    // Mostrar los datos de los alumnos que estudian Ingeniería en Informática
    printf("Alumnos de Ingeniería en Informática:\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(alumnos[i].carrera, "Ingenieria en Informatica") == 0) {
            printf("%s y su numero de matricula es %d \n", alumnos[i].nombre, alumnos[i].matricula);
        }
    }

    return 0;
}
