/* Leer un conjunto de números positivos y mostrar el factorial de cada uno de ellos.*/
#include <stdio.h>
#include <string.h>

int main() {

    int cantidad ,numero,f,i,j;

    printf("ingrese la cantidad de numero");
    scanf("%d" ,&cantidad);

    for (j=1 ; j<=cantidad ; j++){

     printf("ingrese el numero");
    scanf("%d" ,&numero);
    f=1;
    if (numero>0){
    for (i=2 ; i<=numero ; i++){
        f=f*i;}


    printf("Su factorial es %d \n " , f );
    }
    }

    return 0;
}
