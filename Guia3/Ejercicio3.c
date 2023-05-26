#include <stdio.h>




int main() {
    int numero1;
    int numero2;
    int numero3;
    int numero4;
    int numero5;
    int producto;
    int cociente, resto;

    //Ejercicio A
    printf("Ingrese un numero para el ejercicio A");
    scanf("%d", &numero1);
    printf("Ingrese otro numero para el ejercicio A : " );
    scanf("%d", &numero2);
    producto = calcularProducto(numero1, numero2);
    printf("El producto de %d y %d es: %d\n", numero1, numero2, producto);

    //Ejercicio B

     printf("Ingrese el dividendo ");
    scanf("%d", &numero3);
    printf("Ingrese el divisor" );
    scanf("%d", &numero4);
    calcularCocienteResto(numero3, numero4, &cociente, &resto);
    printf("Dividendo: %d, Divisor: %d\n", numero3, numero4);
    printf("Cociente: %d, Resto: %d\n", cociente, resto);

    //Ejercicio C

    printf("Ingrese un numero para saber si esta ordenado ");
    scanf("%d", &numero5);


      if (estanDigitosOrdenados(numero5)) {
        printf("%d: Los digitos están dispuestos de forma creciente.\n", numero5);
    } else {
        printf("%d: Los dígitos no están dispuestos de forma creciente.\n", numero5);
    }


    return 0;
}


int calcularProducto(int num1, int num2) {
    if (num2 == 0) {
        return 0;
    } else {
        return num1 + calcularProducto(num1, num2 - 1);
    }
}

void calcularCocienteResto(int dividendo, int divisor, int *cociente, int *resto) {
    if (dividendo < divisor) {
        *cociente = 0;
        *resto = dividendo;
    } else {
        calcularCocienteResto(dividendo - divisor, divisor, cociente, resto);
        (*cociente)++;
    }
}

int estanDigitosOrdenados(int n) {
    if (n < 10) {
        return 1;
    }

    int ultimoDigito = n % 10;
    int penultimoDigito = (n / 10) % 10;

    if (ultimoDigito >= penultimoDigito) {
        return estanDigitosOrdenados(n / 10);
    } else {
        return 0;
    }
}


