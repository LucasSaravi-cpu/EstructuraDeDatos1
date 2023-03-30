/* mostrar el valor medio de dos enteros leidos*/

#include<stdio.h>
float promedio(int , int );


void main() {

    int a,b;
    float resultado;
    printf("Ingrese el primer numero ");
    scanf("%d",&a);
    printf("Ingrese el segundo numero ");
    scanf("%d",&b);
     resultado=promedio(a,b);
    printf("el promedio es %f",resultado);

    }


float promedio(int a,int b){

return (a+b)/2.0;
}
