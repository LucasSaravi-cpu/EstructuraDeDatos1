/*ingresar N números enteros y calcular y mostrar el promedio de los positivos. */
#include<stdio.h>

void main() {

  int numero,inicio=1,cantidad,contador=0;
  float promedio,sumador=0;

  printf("Ingrese la cantida de numeros");

  scanf("%d",&cantidad);

  for (inicio;inicio<=cantidad;inicio++){

        printf("Ingrese el numero");
        scanf("%d",&numero);

    if (numero>0){
        contador++;
        sumador=sumador+numero;
        }
  }
   promedio=sumador/contador ;
    printf("el promedio de los numeros positivo es %f",promedio);
}
