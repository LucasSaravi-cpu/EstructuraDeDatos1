//Obtener el minimo de un vector de forma recursiva
#include <stdio.h>



int minimo(int v[], int n);

int main() {
    int v[] = {5, 2, 8, -3, 7};
    int n =int minimo(int v[], int n) 5;

    printf("Minimo: %d", minimo(v, n - 1));

    return 0;
}

 {
    int min;

    if (n == 0)
        return v[0];
    else {
        min = minimo(v, n - 1);

        if (v[n] < min)  // A la vuelta de la recursividad va comprando 
            return v[n];
        else
            return min;
    }
}
