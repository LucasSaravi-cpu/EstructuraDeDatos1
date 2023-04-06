#include <stdio.h>
#include <string.h>

int main() {
    int cantidad, i;
    char nombre[10];
    float nota1, nota2, nota3;
    float promedio, maxpromedio = 0;
    char nombremaxpromedio[50];

    printf("Ingrese el número de alumnos (N): ");
    scanf("%d", &cantidad);


    for (i = 0; i < cantidad; i++) {
        printf("Ingrese el nombre del alumno ");
        scanf("%s", nombre);

        printf("Ingrese las 3 notas del alumno ");
        scanf("%f %f %f", &nota1, &nota2, &nota3);


        promedio = (nota1 + nota2 + nota3) / 3.0;


        if (promedio > maxpromedio) {
            maxpromedio = promedio;
            strcpy(nombremaxpromedio, nombre); // Copia una cadena de caracteres a otra
        }
    }

    printf("El alumno con el mejor promedio es %s, con un promedio de %.2f\n",
           nombremaxpromedio, maxpromedio);

    return 0;
}
