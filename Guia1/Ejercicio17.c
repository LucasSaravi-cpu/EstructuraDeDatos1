/*Ej 17 – Desarrollar un programa que imprima el equivalente en letras de un número introducido
de un rango de 0 a 999.
Por ejemplo: se introdujo 119, imprime ciento diecinueve*/



#include <stdio.h>

int main()
{
    int num, unidades, decenas, centenas;

    char* unidades_txt[] = {"cero", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
    char* especiales_txt[] = {"diez", "once", "doce", "trece", "catorce", "quince", "dieciseis", "diecisiete", "dieciocho", "diecinueve"};
    char* decenas_txt[] = {"", "diez", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
    char* centenas_txt[] = {"", "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos"};

    printf("Ingrese un número entre 0 y 999: ");
    scanf("%d", &num);

    if (num == 0) {
        printf("%s\n", unidades_txt[num]);
    }
    else if (num < 10) {
        printf("%s\n", unidades_txt[num]);
    }
    else if (num < 20) {
        printf("%s\n", especiales_txt[num - 10]);
    }
    else if (num < 100) {
        unidades = num % 10;
        decenas = num / 10;
        if (unidades == 0) {
            printf("%s\n", decenas_txt[decenas]);
        }
        else {
            printf("%s y %s\n", decenas_txt[decenas], unidades_txt[unidades]);
        }
    }
    else if (num < 1000) {
        unidades = num % 10;
        decenas = (num / 10) % 10;
        centenas = num / 100;
        if (decenas == 0 && unidades == 0) {
            printf("%s\n", centenas_txt[centenas]);
        }
        else if (decenas == 0) {
            printf("%s %s\n", centenas_txt[centenas], unidades_txt[unidades]);
        }
        else if (decenas == 1) {
            printf("%s %s\n", centenas_txt[centenas], especiales_txt[unidades]);
        }
        else if (unidades == 0) {
            printf("%s %s\n", centenas_txt[centenas], decenas_txt[decenas]);
        }
        else {
            printf("%s %s y %s\n", centenas_txt[centenas], decenas_txt[decenas], unidades_txt[unidades]);
        }
    }
    else {
        printf("El número ingresado está fuera de rango.\n");
    }

    return 0;
}
