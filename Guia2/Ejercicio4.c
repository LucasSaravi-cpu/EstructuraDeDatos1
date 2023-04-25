/*Ej 2.- Escribir un programa que cree dinámicamente 3 variables enteras y ponga en ellas 3 valores
leídos por teclado, luego calcule y muestre su suma y su producto. Al finalizar liberar la memoria
reservada*/

#include <stdio.h>
#include <stdlib.h>

void main () {
    int *varA = (int *) malloc(sizeof(int)); //Se crean dinamicamente las variables y se les reserva espacio
    int *varB = (int *) malloc(sizeof(int));
    int *varC = (int *) malloc(sizeof(int));


    if((varA != NULL)&&(varB!= NULL)&&(varC != NULL)) { //Si se crearon correctamente
        printf("Ingrese A,B,C \n");
        fflush(stdin);         //Limpia el buffer de salida
        scanf("%d", varA);
        fflush(stdin);
        scanf("%d", varB);
        fflush(stdin);
        scanf("%d", varC);
        printf("La suma es: %d \n",(*varA)+(*varB)+(*varC));
		printf("El producto: %d \n",(*varA)*(*varB)*(*varC));

        free(varA);
		free(varB);
		free(varC); //libero variables dinamicas
    }else{
        printf("No se pudo asignar la memoria correctamente");
    }
}
