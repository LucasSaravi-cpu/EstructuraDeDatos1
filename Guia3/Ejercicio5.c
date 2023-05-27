#include <stdio.h>

#define N 3
#define M 4
#define L 4
#define C 3



int main() {
    int matriz[N][M] = {{5, 9, 2, 8},
                       {3, 1, 7, 4},
                       {6, 9, 2, 5}};

    int matriz2[N][M] = {{5, 0, 2, 0},
                       {0, 1, 7, 4},
                       {6, 9, 0, 5}};

      int matriz3[L][L] = {{1, -2, 3, 0},
                        {4, 0, -4, 2},
                        {0, 5, -5, -3},
                        {-1, 1, -1, 1}};

        int matriz4[C][C] =  {{5, 2, 3},
                        {1, 6, 4},
                        {4, 3, 9}};

     int matriz5[C][C] = {{1, 0, 0},
                        {0, 1, 0},
                        {0, 0, 1}};


   //Ejercicio A
    int minimo = encontrarMinimo(matriz);
    printf("El minimo elemento de la matriz es: %d\n", minimo);

//Ejercicio B

   int cumple = verificarColumnasConCero(matriz2,0,0);

    if (cumple)
        printf("La matriz cumple con la condicion \n");
    else
        printf("La matriz no cumple con la condicion \n");


   //Ejercicio C

    int cumple2 =verificarFilasConUnCeroRecursivo(matriz2,0,0);

     if (cumple2)
        printf("La matriz cumple con la condicion \n");
    else
        printf("La matriz no cumple con la condicion \n");

  //Ejercicio D

  printf("La cantidad de filas con la misma cantidad de positivos y negativos es : %d \n",contarFilas(matriz3,0,0));

  //Ejercicio E

  int cumple3 = verificarCondicionRecursivo(matriz4, 0);

  if (cumple3)
        printf("La matriz cumple con la condicion \n");
    else
        printf("La matriz no cumple con la condicion \n");

  //Ejercicio F

 int cumple4 = verificarIdentidadRecursivo(matriz5,0,0);


  if (cumple4)
        printf("La matriz cumple con la condicion \n");
    else
        printf("La matriz no cumple con la condicion\n");

    return 0;
}




// Calcular el mínimo elemento de una matriz de NxM enteros (función int y void)

void encontrarMinimoRecursivo(int matriz[N][M], int fila, int columna, int *minimo) {
    if (fila == N - 1 && columna == M - 1) {
        if (matriz[fila][columna] < *minimo) {
            *minimo = matriz[fila][columna];
        }
        return;
    }

    if (matriz[fila][columna] < *minimo) {
        *minimo = matriz[fila][columna];
    }

    if (columna == M - 1) {
        encontrarMinimoRecursivo(matriz, fila + 1, 0, minimo);
    } else {
        encontrarMinimoRecursivo(matriz, fila, columna + 1, minimo);
    }
}

int encontrarMinimo(int matriz[N][M]) {
    int minimo = matriz[0][0];
    encontrarMinimoRecursivo(matriz, 0, 0, &minimo);
    return minimo;
}


 //Verificar si una matriz A de NxM cumple que en todas sus columnas hay por lo menos un cero (función int y void)

int verificarColumnasConCero(int matriz[N][M], int fila, int columna) {
    if (columna == M)
        return 1; // Todas las columnas tienen al menos un cero

    int hayCeroEnColumna = 0;

    for (int i = 0; i < N; i++) {
        if (matriz[i][columna] == 0) {
            hayCeroEnColumna = 1;
            break;
        }
    }

    if (hayCeroEnColumna)
        return verificarColumnasConCero(matriz, fila, columna + 1);
    else
        return 0; // No hay cero en la columna actual
}



// Dada una matriz de NxM enteros, determinar si en todas las filas hay exactamente un cero
int verificarFilasConUnCeroRecursivo(int matriz[N][M], int fila, int contadorCeros) {
    if (fila == N)
        return 1; // Todas las filas tienen exactamente un cero

    if (contadorCeros > 1)
        return 0; // Hay más de un cero en la fila actual

    int contadorCerosFila = 0;

    for (int j = 0; j < M; j++) {
        if (matriz[fila][j] == 0) {
            contadorCerosFila++;
        }
    }

    return verificarFilasConUnCeroRecursivo(matriz, fila + 1, contadorCeros + contadorCerosFila);
}

// Para una matriz de NxN, contar cuántas filas tienen la misma cantidad de positivos y negativos (no contar los ceros)

int contarFilas(int matriz[N][N], int fila, int contador) {
    if (fila == N)
        return contador;

    int cantidadPositivos = 0;
    int cantidadNegativos = 0;

    for (int j = 0; j < N-1; j++) {
        if (matriz[fila][j] > 0)
            cantidadPositivos++;
        else if (matriz[fila][j] < 0)
            cantidadNegativos++;
    }

    if (cantidadPositivos == cantidadNegativos)
        contador++;

    return contarFilas(matriz, fila + 1, contador);
}

//Verificar si una matriz A de NxN de números enteros cumple que para cada fila el elemento
//respectivo de la diagonal principal es mayor a la suma del resto de los elementos de la fila. recursivo

int verificarCondicionRecursivo(int matriz[N][N], int fila) {
    if (fila == N)
        return 1; // La condición se cumple para todas las filas

    int elementoDiagonal = matriz[fila][fila];
    int sumaRestoElementos = 0;

    // Sumar el resto de los elementos de la fila
    for (int j = 0; j < N-1; j++) {
        if (j != fila) {
            sumaRestoElementos += matriz[fila][j];
        }
    }

    if (elementoDiagonal > sumaRestoElementos) {
        // Verificar la siguiente fila
        return verificarCondicionRecursivo(matriz, fila + 1);
    } else {
        // La condición no se cumple para esta fila
        return 0;
    }
}

//Dada una matriz de NxN de números enteros, verificar si es la identidad

int verificarIdentidadRecursivo(int matriz[N][N], int fila, int columna) {
    if (fila == N)
        return 1; // La matriz es la identidad

    if (matriz[fila][columna] != 1 && fila == columna)
        return 0; // El elemento de la diagonal principal no es 1

    if (matriz[fila][columna] != 0 && fila != columna)
        return 0; // Los elementos fuera de la diagonal principal no son 0

    if (columna == N - 1)
        return verificarIdentidadRecursivo(matriz, fila + 1, 0); // Pasar a la siguiente fila

    return verificarIdentidadRecursivo(matriz, fila, columna + 1); // Pasar al siguiente elemento de la fila
}
