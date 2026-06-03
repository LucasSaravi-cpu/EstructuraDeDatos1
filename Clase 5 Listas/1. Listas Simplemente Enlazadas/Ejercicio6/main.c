#include <stdio.h>
#include <stdlib.h>

#define N 3

typedef struct nodo{
    int fila;
    int columna;
    int dato;
    struct nodo *sig;
}Nodo;

typedef Nodo *Lista;


void cargarLista(Lista *L);
void insertarFinal(Lista *L, int fila, int columna, int dato);
void mostrarLista(Lista L);
int filaMasCeros(Lista L);
int existeFilaTodosPares(Lista L);

int main(){

    Lista L = NULL;

    cargarLista(&L);

    printf("LISTA CARGADA\n\n");
    mostrarLista(L);

    printf("\nFila con mayor cantidad de ceros: %d\n",filaMasCeros(L));

    if(existeFilaTodosPares(L))
        printf("\nExiste al menos una fila con todos sus elementos pares\n");
    else
        printf("\nNo existe ninguna fila con todos sus elementos pares\n");

    return 0;
}



void insertarFinal(Lista *L, int fila, int columna, int dato){

    Nodo *nuevo = (Nodo*) malloc(sizeof(Nodo));

    nuevo->fila = fila;
    nuevo->columna = columna;
    nuevo->dato = dato;
    nuevo->sig = NULL;

    if(*L == NULL)
        *L = nuevo;
    else{

        Nodo *aux = *L;

        while(aux->sig != NULL)
            aux = aux->sig;

        aux->sig = nuevo;
    }
}


void cargarLista(Lista *L){

    FILE *arch;
    int fila, columna, dato;

    arch = fopen("Ejercicio6.txt","r");

    if(arch == NULL){
        printf("Error al abrir el archivo\n");

    }else{

    while(fscanf(arch,"%d%d%d",&fila,&columna,&dato) == 3){

        insertarFinal(L, fila, columna, dato);
    }
    }

    fclose(arch);
}



void mostrarLista(Lista L){

    while(L != NULL){

        printf("Fila: %d  Columna: %d  Dato: %d\n",L->fila,L->columna,L->dato);

        L = L->sig;
    }
}



int filaMasCeros(Lista L){

    int cantCeros[N];
    int i;
    int filaMax = 0;

    for(i = 0; i < N; i++)
        cantCeros[i] = N;

    while(L != NULL){

        cantCeros[L->fila]--;

        L = L->sig;
    }

    for(i = 1; i < N; i++){

        if(cantCeros[i] > cantCeros[filaMax])
            filaMax = i;
    }

    return filaMax;
}



int existeFilaTodosPares(Lista L){

    int todosPares[N];
    int i;

    for(i = 0; i < N; i++)
        todosPares[i] = 1;

    while(L != NULL){

        if(L->dato % 2 != 0)
            todosPares[L->fila] = 0;

        L = L->sig;
    }

    for(i = 0; i < N; i++){

        if(todosPares[i])
            return 1;
    }

    return 0;
}
