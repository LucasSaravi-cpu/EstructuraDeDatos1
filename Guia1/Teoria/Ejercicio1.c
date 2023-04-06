/*Leer un número y obtener y mostrar su factorial.*/
#include <stdio.h>
#include <string.h>

int main() {

    int numero ,f=1,i;

    printf("ingrese un numero");
    scanf("%d" ,&numero);


    for (i=2 ; i<=numero ; i++)
        f=f*i;

    printf("Su factorial es %d" , f );

    return 0;
}
