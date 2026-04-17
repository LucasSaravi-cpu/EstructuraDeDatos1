/*Ej 5 -
a.- Calcular el mínimo elemento de una matriz de NxM enteros (función int y void)
b.- Verificar si una matriz A de NxM cumple que en todas sus columnas hay por lo menos un cero
(función int y void)
c.- Dada una matriz de NxM enteros, determinar si en todas las filas hay exactamente un cero.
d.- Para una matriz de NxN, contar cuántas filas tienen la misma cantidad de positivos y negativos
(no contar los ceros)
e.- Verificar si una matriz A de NxN de números enteros cumple que para cada fila el elemento
respectivo de la diagonal principal es mayor a la suma del resto de los elementos de la fila.
f.- Dada una matriz de NxN de números enteros, verificar si es la identidad. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void cargarMatrizInt(int A[][10], int n, int m);
int minimoMatriz(int A[][MAX], int i, int j, int n, int m);
void minimoMatrizVoid(int A[][MAX], int i, int j, int n, int m, int *min);
int verificar(int A[][MAX], int i, int j, int n, int m);
void verificarvoid(int A[][MAX], int i, int j, int n, int m, int *ok);
int verificarsitodaslasfilastienecero(int A[][MAX], int i, int j, int n, int m, int cant);
int contarFilas(int A[][MAX], int i, int j, int n, int pos, int neg);
int verificarDiagonal(int A[][MAX], int i, int j, int n, int suma);

int esIdentidad(int A[][MAX], int i, int j, int n);





int main(){

    int n, m;
    int A[MAX][MAX];
    int min = A[0][0];


   printf("Filas (n): ");
   scanf("%d",&n);
   printf("Columnas (m): ");
   scanf("%d",&m);
   cargarMatrizInt(A,n,m);
   printf("Ejercicio a \n");

   printf("Minimo de la matriz es (funcion int) : %d \n", minimoMatriz(A, n-1, m-1, n, m)); // Se empieza del ultimo elemento

   minimoMatrizVoid(A, 0, 0, n, m, &min);
   printf(" El minimo de la matriz es (funcion void ) %d \n", min);
   printf("Ejercicio b \n");

   if (verificar(A, 0, 0, n, m))

        printf ("Todas las columnas tienen algun 0 \n");
    else
        printf (" NO Todas las columnas tienen algun 0\n");


int ok = 1;
verificarvoid(A, 0, 0, n, m, &ok);


 if (ok)

        printf ("Todas las columnas tienen algun 0\n");
    else
        printf (" NO Todas las columnas tienen algun 0\n");


printf("Ejercicio c \n");

if (verificarsitodaslasfilastienecero(A, 0,0,n, m,0))
    printf ("Todas filas tienen 0\n");
else
    printf ("NO todas las filas tienen 0 \n");

printf("Ejercicio d \n");
printf(" Las filas que tienen la misma cantidad de positivos y negativos (sin contar los ceros) son %d \n" , contarFilas(A, 0, 0, n, 0, 0));
printf("Ejercicio e \n");

if (verificarDiagonal(A,0, 0, n, 0))

    printf("cumple que para cada fila el elemento respectivo de la diagonal principal es mayor a la suma del resto de los elementos de la fila.\n");

else
      printf(" NO cumple que para cada fila el elemento respectivo de la diagonal principal es mayor a la suma del resto de los elementos de la fila.\n");
printf("Ejercicio f \n");

if (esIdentidad(A,0,0,n)  )
     printf("Es identidad \n");
else
    printf("no es identidad \n");


    return 0;
}


void cargarMatrizInt(int A[][10], int n, int m){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            printf("A[%d][%d]: ", i,j);
            scanf("%d",&A[i][j]);
        }
}


//a.- Calcular el mínimo elemento de una matriz de NxM enteros (función int y void)


//Como funciona primero va iterando la matriz de atras para adelante hasta el caso base que es 0,0
//Por ejemplo si la matriz es 5 → 8 → 2 → 7 → 1 → 9 hace alrevez 9 → 1 → 7 → 2 → 8 → 5 cuando llega al caso base devuelve 5
//Como esto compara a la vuelta cuando esta en la vuelta dice el caso base min=5 lo compara con el (0,1) hasta que halla uno menor al 5
//En la ida no pasa nada visible TODO pasa en la vuelta
int minimoMatriz(int A[][MAX], int i, int j, int n, int m) {

    int min;

    if (i == 0 && j == 0)
        return A[0][0];

    if (j > 0) //mientras que la posicion de la columna sea mayor a 0 osea no llegue al final de la columna ( va de derecha a izquierda) si llega cambia de fila i-1 y se posiciona en la posicion m-1 al final de la columna
        min = minimoMatriz(A, i, j - 1, n, m);
    else
        min = minimoMatriz(A, i - 1, m - 1, n, m);

    if (A[i][j] < min)
        return A[i][j];
    else
        return min;
}



void minimoMatrizVoid(int A[][MAX], int i, int j, int n, int m, int *min) {

    // Solo ejecuto si NO termina
    if (i < n) {

        // Trabajo a la ida
        if (A[i][j] < *min)
            *min = A[i][j];

        // Avanzo
        if (j < m - 1)
            minimoMatrizVoid(A, i, j + 1, n, m, min);
        else
            minimoMatrizVoid(A, i + 1, 0, n, m, min);
    }
}


// Verificar si una matriz A de NxM cumple que en todas sus columnas hay por lo menos un cero (función int y void)
//Recorre columna por columna
//Dentro de cada columna busca un 0
//Si lo encuentra → pasa a la siguiente columna
//Si termina la columna sin 0 → retorna 0

int verificar(int A[][MAX], int i, int j, int n, int m) {

    if (j == m) {
        return 1;
    }
    else {

        if (i < n) {

            if (A[i][j] == 0) {
                return verificar(A, 0, j + 1, n, m);
            }
            else {
                return verificar(A, i + 1, j, n, m);
            }

        }
        else {
            // terminé la columna y no encontré ningún 0
            return 0;
        }
    }
}

void verificarvoid(int A[][MAX], int i, int j, int n, int m, int *ok) {

    if (j < m) {

        if (i < n) {

            if (A[i][j] == 0) {
                // columna válida → salto a la siguiente
                verificarvoid(A, 0, j + 1, n, m, ok);
            }
            else {
                verificarvoid(A, i + 1, j, n, m, ok);
            }

        }
        else {
            // terminé columna y no encontré 0
            *ok = 0;


            verificarvoid(A, 0, j + 1, n, m, ok);
        }

    }
}


int verificarsitodaslasfilastienecero(int A[][MAX], int i, int j, int n, int m, int cant) {

    if (i == n)
        return 1;  // todas las filas cumplen

    if (j < m) {

        if (A[i][j] == 0)
            cant++;

        return verificarsitodaslasfilastienecero(A, i, j + 1, n, m, cant);

    } else {
        // terminé la fila
        if (cant != 1)
            return 0;
        else
            return verificarsitodaslasfilastienecero(A, i + 1, 0, n, m, 0);
    }
}



int contarFilas(int A[][MAX], int i, int j, int n, int pos, int neg) {

    if (i == n)
        return 0;

    if (j < n) {

        if (A[i][j] > 0)
            pos++;
        else if (A[i][j] < 0)
            neg++;

        return contarFilas(A, i, j + 1, n, pos, neg);

    } else {
        // fin de fila
        if (pos == neg && pos + neg > 0)
            return 1 + contarFilas(A, i + 1, 0, n, 0, 0);
        else
            return contarFilas(A, i + 1, 0, n, 0, 0);
    }
}


int verificarDiagonal(int A[][MAX], int i, int j, int n, int suma) {

    if (i == n)
        return 1;

    if (j < n) {

        if (j != i)
            suma += A[i][j];

        return verificarDiagonal(A, i, j + 1, n, suma);

    } else {
        // fin de fila
        if (A[i][i] <= suma)
            return 0;

        return verificarDiagonal(A, i + 1, 0, n, 0);
    }
}



int esIdentidad(int A[][MAX], int i, int j, int n) {

    if (i == n)
        return 1;

    if (j < n) {

        if (i == j) {
            if (A[i][j] != 1)
                return 0;
        } else {
            if (A[i][j] != 0)
                return 0;
        }

        return esIdentidad(A, i, j + 1, n);

    } else {
        return esIdentidad(A, i + 1, 0, n);
    }
}


