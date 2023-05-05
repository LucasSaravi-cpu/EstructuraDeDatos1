#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n, resultado;

    printf("Ingrese el valor de n: ");
    scanf("%d", &n);

    resultado = fibonacci(n);

    printf("El termino %d de la sucesion de Fibonacci es %d", n, resultado);

    return 0;
}
