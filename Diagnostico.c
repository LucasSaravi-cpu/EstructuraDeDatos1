/*Desarrollar una función para cargar datos en una matriz A de NxN  elementos de tipo float.

Desarrollar una función para generar un arreglo V de registros que en cada elemento contenga los siguientes campos: fila y promedio (es el promedio de los valores positivos de la fila). Ignorar las filas de A en las que haya algún 0.

Desarrollar una función int que a partir de V devuelva la cantidad de filas que tengan un promedio mayor a K (k dato de entrada).

Escribir la función main() con las declaraciones e invocaciones correspondientes. Definir los tipos que considere necesarios.*/

#include <stdio.h>
#define MAX 50

typedef struct {
    int fila;
    float promedio;
} Registro;


void cargarMatriz(float a[][MAX],int n);
void generarVector(float a[][MAX], int n, Registro v[MAX], int *cant);
int contarMayores(Registro v[], int cant, float k);


int main() {
    float a[MAX][MAX];
    Registro v[MAX];
    int n,cantidad;
    float k;

    printf("Ingresar la dimension de la matriz ");
    scanf("%d", &n);

    cargarMatriz(a, n);

    generarVector(a, n, v, &cantidad);

    printf("Ingrese valor ");
    scanf("%f", &k);


    printf("Cantidad de filas con promedio %d", contarMayores(v, cantidad,k));

    return 0;
}

void cargarMatriz(float a[][MAX], int n) {
    int i,j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
        printf("Ingresar el numero que va en la posicion [%d][%d] \n",i,j);
            scanf("%f", &a[i][j]);
        }
    }
}


void generarVector(float a[][MAX], int n, Registro v[], int *cant) {
    int k = 0;
    int j;
    int tieneCero;
    float suma;
    int cantPos;

    for (int i = 0; i < n; i++) {

        j = 0;
        tieneCero = 0;
        suma = 0;
        cantPos = 0;


        while (j < n && tieneCero == 0) {
            if (a[i][j] == 0) {
                tieneCero = 1;
            } else {
                if (a[i][j] > 0) {
                    suma += a[i][j];
                    cantPos++;
                }
            }
            j++;
        }


        if (tieneCero == 0 && cantPos > 0) {
            v[k].fila = i;
            v[k].promedio = suma / cantPos;
            k++;
        }
    }

    *cant = k;
}

int contarMayores(Registro v[], int cant, float k) {
    int contador = 0;
    int i;
    for (i = 0; i < cant; i++) {
        if (v[i].promedio > k) {
            contador++;
        }
    }

    return contador;
}
