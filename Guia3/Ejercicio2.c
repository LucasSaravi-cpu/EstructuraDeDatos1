#include <stdio.h>

void escribirAlReves(int n);
int contarDigitos(int n);
void listarParesSuma(int n, int num1, int num2);



int main() {
    int numero ;
    int numero2;


    printf("Ingrese un numero para escribirlo al revez , contar sus digitos y contar sus digitos pares");
    scanf("%d", &numero);

    printf("El numero al revez es: " );
    escribirAlReves(numero);
    printf("\n");
    int cantidadDigitos = contarDigitos(numero);
    printf("La cantidad de digitos es: %d\n", cantidadDigitos);

    int cantidadDigitosPares = contarDigitosPares(numero);
    printf("La cantidad de digitos pares es %d\n", cantidadDigitosPares);


    printf("Ingrese un numero");
    scanf("%d", &numero2);
    printf(" Los pares de numeros que son suma del numero ingresado son \n");
    listarParesSuma(numero2,1,2);


    return 0;
}


void escribirAlReves(int n) {
    if (n < 10) {
        printf("%d", n);
    } else {
        printf("%d", n % 10);
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
        int cantidadDigitosParesRestantes = contarDigitosPares(n / 10);
        if (digito % 2 == 0) {
            return cantidadDigitosParesRestantes + 1;
        } else {
            return cantidadDigitosParesRestantes;
        }
    }
}

void listarParesSuma(int n, int num1, int num2) {
    if (num1 > n / 2) {
        return;
    }

    if (num1 + num2 == n) {
        printf("(%d, %d)\n", num1, num2);
    }

    if (num2 < n - num1) {
        listarParesSuma(n, num1, num2 + 1);
    } else {
        listarParesSuma(n, num1 + 1, num1 + 2);
    }
}
