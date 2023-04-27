
/*Ej 15 – Desarrollar un programa que solicite por teclado N y los siguientes datos de N alumnos:
Nombre (cadena de 30), Numero de Matricula (entero), Nombre de Carrera (cadena de 30).
Almacenar estos datos en un arreglo de structs.
Muestre por pantalla los datos ingresados con un alumno por línea solo para aquellos que estudian
Ingeniería en Informática
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100

typedef struct {
    char nombre[30];
    int matricula;
    char carrera[30];
} Alumno;

int main() {
    int n;
    Alumno alumnos[MAX_N];

    // Pedir el número de alumnos
    printf("Ingrese el numero de alumnos: ");
    scanf("%d", &n);

    // Limpiar el buffer de entrada
    fflush(stdin);

    // Leer los datos de cada alumno
    for (int i = 0; i < n; i++) {
        printf("Alumno %d:\n", i+1);
        printf("Nombre: ");
        fgets(alumnos[i].nombre, 30, stdin);
        printf("Matricula: ");
        scanf("%d", &alumnos[i].matricula);
        fflush(stdin);
        printf("Carrera: ");
        fgets(alumnos[i].carrera, 30, stdin);
    }

    // Mostrar los datos de los alumnos que estudian Ingeniería en Informática
    printf("Alumnos de Ingenieria en Informtaica:\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(alumnos[i].carrera, "ingenieria en informatica") == 0) {
            printf(" Nombre:%s Matricula: %d, Carrera: %s " , alumnos[i].nombre, alumnos[i].matricula, alumnos[i].carrera);

        }
    }

    return 0;
}

