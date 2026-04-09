//Actividad A Realizar el seguimiento indicando qué muestran las siguientes funciones
#include <stdio.h>

// 1
void quehace1(int n) {
    if (n > 0) {
        printf("%d ", n);
        quehace1(n - 2);
    }
}

// 2
void quehace2(int n) {
    if (n > 0) {
        quehace2(n - 2);
        printf("%d ", n);
    }
}

// 3 (INFINITA)
/*
void quehace3(int n) {
    printf("%d ", n);
    quehace3(n - 2);
}
*/

// 4 (INFINITA)
/*
void quehace4(int n) {
    if (n != 0) {
        printf("%d ", n);
        quehace4(n - 2);
    }
}
*/

// 5
void quehace5(int n) {
    if (n > 0) {
        printf("%d ", n);
        quehace5(n - 2);
        printf("%d ", n);
    }
}

// 6 (INFINITA)
/*
void quehace6(int n) {
    if (n > 0) {
        quehace6(n--);
        printf("%d ", n);
    }
}
*/

// 7
void quehace7(int n) {
    if (n > 0) {
        quehace7(--n);
        printf("%d ", n);
    }
}

int main() {

    printf("Funcion 1:\n");
    quehace1(6);
    printf("\n\n");

    printf("Funcion 2:\n");
    quehace2(6);
    printf("\n\n");

    printf("Funcion 5:\n");
    quehace5(6);
    printf("\n\n");

    printf("Funcion 7:\n");
    quehace7(6);
    printf("\n\n");

    return 0;
}
