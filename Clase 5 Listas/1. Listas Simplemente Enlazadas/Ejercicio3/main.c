/*Ej 3.- Dada una lista de enteros, desarrollar una función int que cuente la cantidad de elementos
pares de la misma. Realizar una versión iterativa y otra recursiva. */


#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *sig;
}Nodo;

typedef Nodo* Lista;


void cargarLista(Lista *L);
void mostrarLista(Lista L);
int contarParesIterativa(Lista L);

int main(){

    Lista L = NULL;

    cargarLista(&L);

    printf("Lista:\n");
    mostrarLista(L);

    printf("\nCantidad de pares (iterativa): %d\n",contarParesIterativa(L));

    printf("Cantidad de pares (recursiva): %d\n",contarParesRecursiva(L));

    return 0;
}


void cargarLista(Lista *L){

    FILE *arch;

    int valor;

    arch = fopen("Ejercicio3.txt", "r");

    if(arch == NULL){
        printf("Error al abrir el archivo\n");

    }else{

    while(fscanf(arch, "%d", &valor) == 1){

  Nodo *nuevo, *aux;

    nuevo = (Nodo*) malloc(sizeof(Nodo));

    nuevo->dato = valor;
    nuevo->sig = NULL;

    if(*L == NULL){

        *L = nuevo;
    }
    else{

        aux = *L;

        while(aux->sig != NULL){
            aux = aux->sig;
        }

        aux->sig = nuevo;
    }
    }

    fclose(arch);
}
}


void mostrarLista(Lista L){

    while(L != NULL){

        printf("%d -> ", L->dato);

        L = L->sig;
    }

    printf("NULL");

}



int contarParesIterativa(Lista L){

    int contador = 0;

    while(L != NULL){

        if(L->dato % 2 == 0){
            contador++;
        }

        L = L->sig;
    }

    return contador;
}


int contarParesRecursiva(Lista L){

    if(L == NULL){
        return 0;
    }

    if(L->dato % 2 == 0){
        return 1 + contarParesRecursiva(L->sig);
    }
    else{
        return contarParesRecursiva(L->sig);
    }
}



