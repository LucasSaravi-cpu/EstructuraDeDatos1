/*Ej 5.- Una posible implementación para matrices es definir un struct que contenga fila, columna,
dato y enlace al siguiente. Asumiendo que la lista que representa la matriz esta almacenada por filas,
resolver: Definir el tipo y desarrollar un subprograma para cada uno de los siguientes problemas asumiendo
la implementación mencionada:

a.- Dado un archivo DATOS.TXT de n líneas y que en cada línea tiene 3 datos fila, columna, dato y no viene ordenado por ningún criterio, generar una lista que represente una matriz de nxn
b.- Dada una matriz de nxm hallar el máximo de cada columna y almacenarlo en un vector.
c.- Dada una matriz de nxn, hallar cuál es la fila que tiene mayor cantidad de ceros.
d.- Dada una matriz de nxn, hallar si alguna fila tiene todos sus elementos pares.*/


#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int fila;
    int columna;
    int dato;
    struct nodo *sig;
}Nodo;

typedef Nodo *Lista;

void insertarOrdenado(Lista *L, int fila, int columna, int dato);
void cargarMatriz(Lista *L);
void mostrarMatriz(Lista L);
void maximosColumnas(Lista L, int n, int m, int vec[]);

int main(){

    /*la matriz se representa mediante una lista enlazada.*/
    /*No hay que reservar una matriz de n x n; la propia lista es la representación de la matriz.*/

    Lista matriz = NULL;

    int n, m;
    int i;
    cargarMatriz(&matriz);

    printf("\n Matriz representada en una Lista :\n");
    mostrarMatriz(matriz);


    printf("\nCantidad de filas: \n");
    scanf("%d",&n);

    printf("\nCantidad de columnas:\n ");
    scanf("%d",&m);


 /* Inciso b */
    int maxCol[m];

    maximosColumnas(matriz,n,m,maxCol);

    printf("\nMaximos de cada columna:\n");
    for(i=0;i<m;i++){
        printf("Columna %d -> %d\n",i,maxCol[i]);
    }

    //   Inciso c
    printf("\nFila con mayor cantidad de ceros: %d\n",filaMasCeros(matriz,n));

  //   Inciso d
    if(existeFilaPares(matriz,n))
        printf("\nExiste una fila con todos sus elementos pares\n");
    else
        printf("\nNo existe una fila con todos sus elementos pares\n");

    return 0;
}


void insertarOrdenado(Lista *L, int fila, int columna, int dato){

    Nodo *nuevo, *act, *ant;

    nuevo = (Nodo*) malloc(sizeof(Nodo));

    nuevo->fila = fila;
    nuevo->columna = columna;
    nuevo->dato = dato;
    nuevo->sig = NULL;

    act = *L;
    ant = NULL;

    while(act != NULL && (act->fila < fila || (act->fila == fila && act->columna < columna))){

        ant = act;
        act = act->sig;
    }

    if(ant == NULL){
        nuevo->sig = *L;
        *L = nuevo;
    }
    else{
        nuevo->sig = act;
        ant->sig = nuevo;
    }
}


void cargarMatriz(Lista *L){

    FILE *arch;

    int fila, columna, dato;

    arch = fopen("Ejercicio5.txt","r");

    if(arch == NULL){
        printf("Error al abrir archivo\n");

    }else{

    while(fscanf(arch,"%d %d %d ",&fila,&columna,&dato) == 3){

        insertarOrdenado(L,fila,columna,dato);
    }
    }
    fclose(arch);
}

void mostrarMatriz(Lista L){

    while(L != NULL){

        printf("(%d,%d) %d -> \n", L->fila,L->columna,L->dato);

        L = L->sig;
    }

    printf("NULL");
}


void maximosColumnas(Lista L, int n, int m, int vec[]){

    int i;

    for(i=0;i<m;i++)
        vec[i] = 0;

    while(L != NULL){

        if(L->dato > vec[L->columna])

            vec[L->columna] = L->dato;

        L = L->sig;
    }
}


/* Inciso c */
int filaMasCeros(Lista L, int n){

    int fila, maxFila = 0;
    int maxCeros = -1;
    Lista aux ;

    for(fila = 0; fila < n; fila++){

        int cont = 0;
        aux =L;

        while(aux != NULL){

            if(aux->fila == fila && aux->dato == 0)
                cont++;

            aux = aux->sig;
        }

        if(cont > maxCeros){
            maxCeros = cont;
            maxFila = fila;
        }
    }

    return maxFila;
}

/* Inciso d */
//Si la fila esta ordenada
int existeFilaPares(Lista L){

    int filaActual;
    int todosPares;

    while(L != NULL){

        filaActual = L->fila;
        todosPares = 1;

        while(L != NULL && L->fila == filaActual){

            if(L->dato % 2 != 0)
                todosPares = 0;

            L = L->sig;
        }

        if(todosPares)
            return 1;
    }

    return 0;
}
