#include <stdio.h>

#define MAX 100

int sumaV_original(int A[], int i, int n);
int sumaV_condicion(int A[], int i, int n);
int sumaV_sin_i(int A[], int n);
int apaX(int A[], int i, int n, int X);
void sumaV_void(int A[], int n, int *res);
void cargar(int A[], int *n);
void mostrar(int A[], int n);

int main() {
    int A[MAX], n;
    int resultado;

    cargar(A, &n);
    mostrar(A, n);

    printf("\n--- RESULTADOS ---\n");

    // 1) Original
    printf("Suma (original): %d\n", sumaV_original(A, 0, n - 1));

    // 1) Condición i > n
    printf("Suma (i > n): %d\n", sumaV_condicion(A, 0, n - 1));

    // 2) Sin i
    printf("Suma (sin i): %d\n", sumaV_sin_i(A, n - 1));

    // 3) Apariciones
    int X;
    printf("\nIngrese valor a buscar: ");
    scanf("%d", &X);
    printf("Cantidad de apariciones de %d: %d\n", X, apaX(A, 0, n - 1, X));

    // 4) void
    sumaV_void(A, n - 1, &resultado);
    printf("Suma (void): %d\n", resultado);

    return 0;
}


// 1) Función original sumaV (recursiva)
int sumaV_original(int A[], int i, int n) {
    if (i == n)
        return A[n];
    else
        return A[i] + sumaV_original(A, i + 1, n);
}

// 1) Modificada: condición (i > n)
int sumaV_condicion(int A[], int i, int n) {
    if (i > n)
        return 0;
    else
        return A[i] + sumaV_condicion(A, i + 1, n);
}

// 2) Sin parámetro i
int sumaV_sin_i(int A[], int n) {
    if (n == 0)   // otra forma n<0
        return A[0]; //return 0 ;
    else
        return A[n] + sumaV_sin_i(A, n - 1);
}

// 3) Contar apariciones de X
int apaX(int A[], int i, int n, int X) {
    if (i > n)
        return 0;

    if (A[i] == X)
        return 1 + apaX(A, i + 1, n, X);
    else
        return apaX(A, i + 1, n, X);
}

// 4) sumaV como función void (usa puntero)
void sumaV_void(int A[], int n, int *res) {
    if (n == 0) {
        *res = A[0];
    } else {
        sumaV_void(A, n - 1, res);
        *res += A[n];
    }
}

// Función para cargar el arreglo
void cargar(int A[], int *n) {
    printf("Ingrese cantidad de elementos: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }
}




// Mostrar arreglo
void mostrar(int A[], int n) {
    printf("Arreglo: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
