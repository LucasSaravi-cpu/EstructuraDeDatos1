/*Ej 19 - Desarrollar un programa que grabe en un archivo binario números enteros ingresados por teclado.
  Si aparecen dos números consecutivos iguales, finaliza el ingreso.*/

#include <stdio.h>
#include <string.h>
void main (){
    int aux, num;
    FILE * arch;
    arch= fopen("ejercicio19.dat", "wb" );
    printf(" ingrese un numero entero: \n");
    scanf("%d", &num);


    aux  = -1;
    while (aux!=num){
        fwrite(&num, sizeof(int), 1, arch);
        aux=num;
        printf(" ingrese un numero entero: \n");
        scanf("%d", &num);

    }
    fclose(arch);


	//Se abre de nuevo el archivo para una lectura
    arch= fopen("ejercicio19.dat", "rb" );
    fread(&num,sizeof(int),1,arch);
    while(!feof(arch)) {
        printf("%d",num);
        fread(&num,sizeof(int),1,arch);

    }
    fclose(arch);
}

