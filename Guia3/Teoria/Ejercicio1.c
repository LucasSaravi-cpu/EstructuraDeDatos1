#include <stdio.h>

int Potencia(int a, int b) {
    if (b == 0) {
        return 1;
    } else {
        return a * Potencia(a, b-1);
    }
}

int main() {
    int a, b, resultado;

    printf("Ingrese la base a: ");
    scanf("%d", &a);

    printf("Ingrese el exponente b: ");
    scanf("%d", &b);

    resultado = Potencia(a, b);

    printf("%d elevado a %d es igual a %d", a, b, resultado);

    return 0 ;

    }
