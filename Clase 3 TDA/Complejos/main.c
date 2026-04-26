/*Ej 1.- Dado el TDA "Complex", implementación de los números complejos dado en clase agregarle
conjugado de un complejo y producto de dos complejos
Escribir un programa que ingrese dos complejos y mediante un menú elija una o varias de las
operaciones. */

#include <stdio.h>
#include <stdlib.h>
#include "complejos.h"

void main()
{

  complex c1, c2, res;
    int opcion;


    ingresa(&c1);
    ingresa(&c2);

    do {
        printf("\n--- MENU ---\n");
        printf("1. Suma\n");
        printf("2. Producto\n");
        printf("3. Conjugado de C1\n");
        printf("4. Conjugado de C2\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                suma(c1, c2, &res);
                printf("Resultado suma:\n");
                muestra(res);
                break;

            case 2:
                producto(c1, c2, &res);
                printf("Resultado producto:\n");
                muestra(res);
                break;

            case 3:
                conjugado(c1, &res);
                printf("Conjugado de C1:\n");
                muestra(res);
                break;

            case 4:
                conjugado(c2, &res);
                printf("Conjugado de C2:\n");
                muestra(res);
                break;

            case 5:
                printf("Saliendo... \n");
                break;

            default:
                printf("Opcion invalida\n");
        }

    } while(opcion != 5);

 // printf("%5.2f",creal(c3));
 //(cimag(c3)>0)?printf(" +%5.2fi",cimag(c3)):printf("%5.2f i",cimag(c3));
}
