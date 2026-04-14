/*Ej 2 – Dado un número entero N, resolver de forma recursiva:
a.- escribirlo al revés. Por ejemplo, si N = 123, debe escribir 321
b.- contar la cantidad de dígitos del mismo. Por ejemplo, si N = 123, debe devolver 3
c.- contar la cantidad de dígitos pares del mismo. Por ejemplo, si N = 1230, debe devolver 2.
d.- listar todos los pares de números que son suma de N.
Por ejemplo, si N = 5, debe listar ( 1 , 4 ) ; ( 2 , 3 ).
e.- obtener Fibonacci de N */

#include <stdio.h>


void escribirAlReves(int n);
int contarDigitos(int n);
int contarDigitosPares(int n);
void paresSumaN(int a, int b);
int fibonacci(int n) ;



int main() {
    int numero ;

    printf("Ingrese un numero");
    scanf("%d", &numero);
    printf("Ejercicio A \n");
    printf("El numero al revez es: ");
    escribirAlReves(numero);
    printf("\n");
    printf("Ejercicio B \n");
    printf("La cantidad de digitos son %d \n",contarDigitos(numero));
    printf("Ejercicio C \n");
    printf("La cantidad de digitos pares que tiene el numero es %d \n",contarDigitosPares(numero));
    printf("Ejercicio D \n");
    paresSumaN(1, numero - 1);
    printf("Ejercicio E \n");
    printf("El fibonacci es %d",fibonacci(numero));


    return 0;
}


void escribirAlReves(int n) {
    if (n < 10) {
        printf("%d", n);
    } else {
        printf("%d", n % 10);  // A la ida va escribiendo los numeros
        escribirAlReves(n / 10);
    }
}


int contarDigitos(int n) {
    if (n < 10) {
        return 1;
    } else {
        return 1 + contarDigitos(n / 10);
    }
}


int contarDigitosPares(int n) {
    if (n == 0) {
        return 0;
    } else {
        int digito = n % 10;
        int cantidadDigitosParesRestantes = contarDigitosPares(n / 10);  // Funciona a la vuelta
        if (digito % 2 == 0) {
            return cantidadDigitosParesRestantes + 1;
        } else {
            return cantidadDigitosParesRestantes;
        }
    }
}


void paresSumaN(int a, int b) {
    if (a < b) {
        printf("(%d , %d)\n", a, b);
        paresSumaN(a + 1, b - 1);
    }
}


int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

