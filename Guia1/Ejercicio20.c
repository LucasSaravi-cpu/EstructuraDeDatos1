/*Ej 20 – Desarrollar un programa que lea un archivo de texto que contiene un número entero en
cada línea y almacene los números pares en un vector y los impares en otro ignorando los 0.
Luego regrabar el archivo con los pares primero y los impares después.
NOTA: Suponer que en el archivo hay como máximo 25 elementos
*/
#include <stdio.h>

void Leeoarchivo (FILE *arch,int pares[], int impares[],int *Cpar,int *Cimp);

void EscribeTexto(FILE *arch,int pares[], int impares[],int Cpar,int Cimp);

void main(){
    int pares[30],impares[30],Cpar = 0,Cimp = 0;
    FILE *arch;
    Leeoarchivo (arch,pares,impares,&Cpar,&Cimp);
    escribearchivo(arch,pares,impares,Cpar,Cimp);
    printf("El archivo se creo correctamente");

}

void Leeoarchivo(FILE *arch,int pares[], int impares[],int *Cpar,int *Cimp) {
    int num;
    arch = fopen("Ejercicio20.txt","r");
    fscanf(arch,"%d",&num);
    while(!feof(arch)) {
        if (num != 0) {
            if(num%2 == 0) { //si es par
                pares[*Cpar] = num;
                (*Cpar)++;
            }else { //si es impar
                impares[*Cimp] = num;
                (*Cimp)++;   //se debe colocar después de la variable para que se incremente después de la asignación.
            }
        }
        fscanf(arch,"%d",&num);
    }
    fclose(arch);
}

void escribearchivo(FILE *arch,int pares[], int impares[],int Cpar,int Cimp) {
    int i;
    arch = fopen("NuevoEjercicio20.txt","w"); // En caso de regrabar se pone el mismo nombre de archivo .
    for (i = 0;i<Cpar;i++) {
        fprintf(arch,"%d \n",pares[i]);
    }
     for (i = 0;i<Cimp;i++) {
        fprintf(arch,"%d \n",impares[i]);
    }
    fclose(arch);
}
