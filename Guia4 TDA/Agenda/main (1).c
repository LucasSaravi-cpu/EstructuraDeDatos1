#include <stdio.h>
#include <stdlib.h>
#include "contacto.h"
/*Ej 3.- Desarrollar una agenda de contactos mediante un TDA. Para cada contacto se almacena
nombre y teléfono. Los contactos deben estar ordenados alfabéticamente. El TDA debe contar con
los siguientes operadores: agregar contacto, listar agenda, buscar por nombre (búsqueda lineal).
Se solicitan dos implementaciones: una con arreglos paralelos y otra con arreglo de registros.
Mejorar el operador buscar por nombre, recodificándolo como búsqueda binaria.*/
int main(){
    FILE *arch;
    int i = 0,res;
    char Nombre[15];
    long telefono;//7 numeros
    contacto A[20];
    if ((arch = fopen("Texto.txt","r")) == NULL) {
        printf("Archivo no existe \n");
    }else {
        fscanf(arch,"%ld%[^\n]\n",&telefono,Nombre);
        while(!feof(arch)) {
            agregaC(A,Nombre,telefono);
            i++;
            fscanf(arch,"%ld%[^\n]\n",&telefono,Nombre);
        }
        listaAgenda(A,i);
        printf("Desea buscar un nombre? (1-si,0-no) \n");
        fflush(stdin);
        scanf("%d",&res);
        while(res != 0) {
            printf("Ingrese un nombre para buscar \n");
            fflush(stdin);
            scanf("%s",Nombre);
            buscaNombreB(A,i,Nombre);
            printf("Desea buscar otro nombre? (1-si,0-no) \n");
            fflush(stdin);
            scanf("%d",&res);
        }
    }
    return 0;
}
//como hacer un array de cadenas? es una matriz? char c[15][20];
//gets(c[0]);
//no entiendo por que el while !feof(arch) no lee el ultimo nombre, ya que se supone que la implementacion esta bien realizada
//pero si lo hago leyendo al comienzo del ciclo, me lo lee bien y funciona todo bien.
