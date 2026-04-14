#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void cargarMatrizInt(int A[][10], int n, int m);
int sumaM(int A[][10], int i, int j, int n, int m);
int esVocal(char c) ;
void vocalesPorColumna(char A[][MAX], int i, int j, int n, int m, int cont[]);
int filaTieneVocal(char A[][MAX], int i, int j, int n);
void cargarMatrizChar(char A[][MAX], int n, int m);
int cantColumnasPares(int A[][MAX], int i, int j, int n);

int main()
{

    int n, m;
    int A[10][10];
     char B[MAX][MAX];

   printf("Filas (n): ");
   scanf("%d",&n);
   printf("Columnas (m): ");
   scanf("%d",&m);

   cargarMatrizInt(A,n,m);

    printf("Ejercicio 1 \n");
    printf("Suma total: %d\n", sumaM(A,n-1,m-1,n-1,m-1));

   printf("Ejercicio 2 \n");
    int cont[MAX] = {0};
    cargarMatrizChar(B, n, m);

    vocalesPorColumna(B, 0, 0, n, m, cont);

    printf("\nVocales por columna:\n");
    for (int j = 0; j < m; j++) {
        printf("Columna %d: %d\n", j, cont[j]);
    }

    printf("Ejercicio 3 \n");
    printf("\nFilas con al menos una vocal: %d\n", cantvocf(B, 0, n));

    printf("Ejercicio 4 \n");
    if (todasFilasConVocal(B, 0, n))
        printf("Todas las filas tienen vocal\n");
    else
        printf("NO todas las filas tienen vocal\n");

    printf("Ejercicio 5 \n");
    printf("Columnas con todos pares: %d\n", cantColumnasPares(A, 0,0, n));

    return 0;
}


void cargarMatrizInt(int A[][10], int n, int m){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            printf("A[%d][%d]: ", i,j);
            scanf("%d",&A[i][j]);
        }
}


//Ejercicio 1
int sumaM(int A[][10], int i, int j, int n, int m){
    if(i == 0 && j == 0)
        return A[i][j];

    if(j == 0)
        return A[i][j] + sumaM(A, i-1, m, n, m);
    else
        return A[i][j] + sumaM(A, i, j-1, n, m);
}

//Ejercicio 2


int esVocal(char c) {
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
            c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
}

void vocalesPorColumna(char A[][MAX], int i, int j, int n, int m, int cont[]) {
    if (i == n)
        return;

    if (j == m) {
        vocalesPorColumna(A, i+1, 0, n, m, cont);
        return;
    }

    if (esVocal(A[i][j])) {
        cont[j]++;
    }

    vocalesPorColumna(A, i, j+1, n, m, cont);
}



//Ejercicio 3

int filaTieneVocal(char A[][MAX], int i, int j, int n) {
    if (j == n)
        return 0;

    if (esVocal(A[i][j]))
        return 1;

    return filaTieneVocal(A, i, j+1, n);
}

int cantvocf(char A[][MAX], int i, int n) {
    if (i == n)
        return 0;

    return filaTieneVocal(A, i, 0, n) + cantvocf(A, i+1, n);
}


//Ejercicio 4

int todasFilasConVocal(char A[][MAX], int i, int n) {
    if (i == n)
        return 1;

    if (!filaTieneVocal(A, i, 0, n))
        return 0;

    return todasFilasConVocal(A, i+1, n);


}


void cargarMatrizChar(char A[][MAX], int n, int m) {
    printf("Ingrese matriz de caracteres:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf(" %c", &A[i][j]);
        }
    }
}


int cantColumnasPares(int A[][MAX], int i, int j, int n) {

    // Caso: terminamos todas las columnas
    if (j == n)
        return 0;

    // Caso: estamos recorriendo filas de una columna
    if (i < n) {
        // Si encuentra impar → descarta columna
        if (A[i][j] % 2 != 0)
            return cantColumnasPares(A, 0, j + 1, n);

        // Sigue recorriendo la misma columna
        return cantColumnasPares(A, i + 1, j, n);
    }

    // Si llegó al final de la columna (todos eran pares)
    return 1 + cantColumnasPares(A, 0, j + 1, n);
}
