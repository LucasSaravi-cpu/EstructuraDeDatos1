/*Ej 5.- Escribir un programa que cree un arreglo estático de punteros a enteros, y luego cargue en
él N enteros (N y los enteros se encuentran en un archivo de texto). Mostrar aquellos que sean
positivos. Al finalizar, liberar la memoria solicitada en tiempo de ejecución.
*/
#include <stdio.h>

void main() {
    FILE *arch;
    int n,i;
    int *vec[10];
    if ((arch = fopen("Ejercicio5.txt","r")) == NULL) {
        printf("error archivo");
    }else{
        fscanf(arch,"%d",&n);
        for(i=0;i<n;i++) {
            vec[i] = (int*) malloc(sizeof(int)); //arreglo estatico de puntero a entero

            fscanf(arch,"%d",vec[i]);

            if(*vec[i]>0) {
                printf("%d \n",*vec[i]);
            }
        }
        for (i=0;i<n;i++) {
            free(vec[i]);
        }
    }
    fclose(arch);
}
