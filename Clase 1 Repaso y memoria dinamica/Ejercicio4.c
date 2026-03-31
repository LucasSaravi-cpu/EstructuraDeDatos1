/*Escribir un programa que cree dinámicamente 3 variables enteras
y ponga en ellas 3 valores leídos por teclado, luego calcule y muestre su suma y su producto. Al finalizar liberar la memoria reservada.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int *a = (int *)malloc(sizeof(int));
    int *b = (int *)malloc(sizeof(int));
    int *c = (int *)malloc(sizeof(int));


    if (a == NULL || b == NULL || c == NULL) {
        printf("Error al asignar memoria\n");

    }

    else {

    printf("Ingrese el primer numero: ");
    scanf("%d", a);

    printf("Ingrese el segundo numero: ");
    scanf("%d", b);

    printf("Ingrese el tercer numero: ");
    scanf("%d", c);


    int suma = *a + *b + *c;
    int producto = (*a) * (*b) * (*c);

    printf("Suma: %d\n", suma);
    printf("Producto: %d\n", producto);


    free(a);
    free(b);
    free(c);
    }

    return 0;
}
