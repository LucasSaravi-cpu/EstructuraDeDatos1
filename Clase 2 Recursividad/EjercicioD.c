#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void cargarMatrizInt(int A[][10], int n, int m);
//int sumaM(int A[][10], int i, int j, int n, int m);
int esVocal(char c) ;
void cantVocalC(char A[][MAX], int i, int j, int n, int cant);
int cantvocalF(char A[][MAX], int i, int j, int n);
void cargarMatrizChar(char A[][MAX], int n);
int sumaM(int A[][10], int i, int j, int n);
int todasFilasConVocal(char A[][MAX], int i, int j, int n, int encontro) ;
int cantColumnasPares(int A[][MAX], int i, int j, int n);

int main(){

    int n, m;
    int A[MAX][MAX];
     char B[MAX][MAX];

   printf("Filas (n): ");
   scanf("%d",&n);
   printf("Columnas (m): ");
   scanf("%d",&m);

   cargarMatrizInt(A,n,m);

  // printf ("Ejercicio 0 \n");
 //  printf ("La suma de elementos de A: %d", sumaM(A,0,0,n-1,m-1));

    printf("Ejercicio 1 \n");
    printf("Suma total: %d\n", sumaM(A,n-1,m-1,n-1));

   printf("Ejercicio 2 \n");

    cargarMatrizChar(B, n);

    cantVocalC(B, 0, 0, n-1, 0);


    printf("Ejercicio 3 \n");
    printf("\nFilas con al menos una vocal: %d\n", cantvocalF(B, 0,0, n-1));



    printf("Ejercicio 4 \n");
    if (todasFilasConVocal(B, 0, 0,n,0))
        printf("Todas las filas tienen almenos una vocal\n");
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
/*
//Ejercicio 0
//Obtener la suma de una matriz nxm elementos
//Recorre la matriz de izquierda a derecha y de arriba hacia abajo
//la suma se va armando cuando vuelve (de atrás hacia adelante)
int sumaM(int A[][10], int i, int j, int n, int m){
  //Caso base Cuando llega a la última posición de la matriz, devuelve ese valor y termina el programa
    if(i == n && j == m)
        return A[i][j];


    //Si está en la última columna de una fila, hace:

//Suma el valor actual A[i][j]
//Baja a la siguiente fila (i+1)
//Reinicia la columna en 0
    if(j == m)
        return A[i][j] + sumaM(A, i+1, 0, n, m);
    else
   // Sigue avanzando hacia la derecha en la misma fila.
        return A[i][j] + sumaM(A, i, j+1, n, m);
}*/




//Ejercicio 1
//Modificar sumaM() de modo ue la invocacion sea
//printf("%d",SumaM(A,n-1,m-1,n-1));

int sumaM(int A[][10], int i, int j, int n){
    if(i == 0 && j == 0)
        return A[i][j];

    if(i == 0)
        return A[i][j] + sumaM(A, n, j-1, n);
    else
        return A[i][j] + sumaM(A, i-1, j, n);
}

//Ejercicio 2

//Dado una matriz de NxN de caracteres desarrollar una funcion oid que muestre la cantidad de vocales por columnas


int esVocal(char c) {
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
            c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
}

void cantVocalC(char A[][MAX], int i, int j, int n ,int cant) {

    if (j <= n) {  // mientras haya columnas

        if (i <= n) {  // recorremos de arriba hacia abajo

            //  cuenta en la IDA
            if (esVocal(A[i][j])) {
                cant++;
            }

            // Luego baja de fila y sigue en la misma columna y se le pasa si conto o no y se repite el ciclo
            cantVocalC(A, i+1, j, n, cant);

        } else {
            // terminamos la columna
            printf("Columna %d: %d\n", j, cant);

            // pasamos a la siguiente columna y reiniciamos la fila
            cantVocalC(A, 0, j+1, n, 0);
        }
    }
}

void cargarMatrizChar(char A[][MAX], int n) {
    printf("Ingrese matriz de caracteres:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf(" %c", &A[i][j]);
        }
    }
}

//Ejercicio 3

//Cuenta la cantidad de filas que almenos tengan una vocal

//Ida: modificás variables antes de llamar  cant++
//Vuelta: usás el return para construir el resultado

int cantvocalF(char A[][MAX], int i, int j, int n) {
 if ( i>n)
    return 0;
else
    if (j>n)
      return cantvocalF(A,i+1,0,n);
    else
       if (esVocal(A[i][j]))
           return  cantvocalF(A,i+1,0,n)+1;

        else
           return cantvocalF(A,i,j+1,n);

}



//Ejercicio 4
//Dada una matriz de nxn caracteres , desarrollar una funcion revursiva int que determine si todas las finales tinen alguna vocal
int todasFilasConVocal(char A[][MAX], int i, int j, int n, int encontro) {

    // Terminamos todas las filas
    if (i == n)
        return 1;

    // Recorremos columnas de la fila i
    if (j < n) {

        if (esVocal(A[i][j]))
            encontro = 1;

        return todasFilasConVocal(A, i, j+1, n, encontro);
    }

    // Terminamos la fila i
    if (encontro == 0)
        return 0;  // esta fila NO tiene vocal

    // Pasamos a la siguiente fila
    return todasFilasConVocal(A, i+1, 0, n, 0);
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

