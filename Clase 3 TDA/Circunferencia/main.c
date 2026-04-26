#include <stdio.h>
#include <stdlib.h>
#include "Circun.h"
/*Ej 2.- Desarrollar el TDA "Circun" que representa el ente geométrico circunferencia, incluir al
menos las siguientes operaciones:
o la función SUPERF que dada una circunferencia devuelva su superficie (pi*radio2
).
o la función PERIM que dada una circunferencia devuelva su perímetro (2*pi*radio).
o la función INCLU que indique si una circunferencia está o no incluida en otra
Nota: si dist(O1 , O2) > r1 - r2 entonces la primera está incluida en la segunda,
recordar que dist2
(O1,O2) = (x1 - x2)
2 + (y1 - y2)
2
Desarrollar un programa que ingrese los datos de una circunferencia y mediante un menú elija una
o varias de las operaciones desarrolladas.
*/
void main(){

    Circun a, b;
    int opcion;
    printf("Ingrese la posicion en x del centro de la circunferencia, luego en y, y luego el radio \n");
    ingresaC(&a);
    printf("Ingrese la posicion en x del centro de la circunferencia, luego en y, y luego el radio \n");
    ingresaC(&b);

    do {
        printf("\n===== MENU =====\n");
        printf("1. Perimetro de A\n");
        printf("2. Superficie de B\n");
        printf("3. Ver si A esta incluida en B\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {

            case 1:
                printf("Perimetro de A: %f\n", perimetro(a));
                break;

            case 2:
                printf("Superficie de B: %f\n", superf(b));
                break;

            case 3:
                inclu(a, b);
                break;

            case 0:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion invalida\n");
        }

    } while(opcion != 0);
}



