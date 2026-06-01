/*Ej 4.- Desarrollar una función void que incorpore una palabra en una lista enlazada ordenada
alfabéticamente (ascendente). En el caso en que el nodo anterior a donde debe ser insertada
contenga una palabra cuya última letra (mayúscula o minúscula) coincida con la primera letra de la
palabra a insertar, concatenar ambas palabras y ubicarlas en el nodo existente escribiendo una sola
vez la letra que tienen en común.  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct nodo{
    char palabra[50];
    struct nodo *sig;
}Nodo;

typedef Nodo *Lista;


void cargarListaArchivo(Lista *L);
void mostrarLista(Lista L);
void insertarPalabra(Lista *L, char palabra[]);

int main(){

    Lista L = NULL;
    char palabra[50];

    cargarListaArchivo(&L);

    printf("Lista cargada:\n");
    mostrarLista(L);

    printf("\nIngrese una palabra a insertar: ");
    scanf("%s", palabra);

    insertarPalabra(&L, palabra);

    printf("\nLista resultante:\n");
    mostrarLista(L);

    return 0;
}


void cargarListaArchivo(Lista *L){

    FILE *arch;
    char palabra[50];

    arch = fopen("Ejercicio4.txt","r");

    if(arch == NULL){
        printf("Error al abrir el archivo\n");

    }else{

    while(fscanf(arch,"%s", palabra) == 1){
        insertarPalabra(L, palabra);
    }
    }
    fclose(arch);
}


void mostrarLista(Lista L){

    while(L != NULL){

        printf("%s -> ", L->palabra);
        L = L->sig;
    }

    printf("NULL\n");
}


void insertarPalabra(Lista *L, char p[]){

    /* Reserva memoria para el nuevo nodo */
    Lista aux = (Lista)malloc(sizeof(Nodo));

    /* Copia la palabra recibida al nodo nuevo */
    strcpy(aux->palabra,p);

    /* Punteros auxiliares para recorrer la lista */
    Lista act = *L, ant = NULL;

    /* Busca la posición donde insertar la palabra
       manteniendo el orden alfabético */
    while(act != NULL && strcmp(act->palabra,p) < 1){

            ant = act;
            act = act->sig;
    }

    /* Si ant sigue siendo NULL significa que la palabra
       debe insertarse al principio de la lista */
    if(ant == NULL) {

        aux->sig = *L;
        *L = aux;

    }else{

        /* Verifica si la última letra de la palabra del nodo
           anterior coincide con la primera letra de la palabra
           a insertar (ignorando mayúsculas/minúsculas) */
        if(toupper(ant->palabra[strlen(ant->palabra)-1]) == toupper(p[0])) {

            /* Concatena las palabras.

               aux->palabra+1 apunta al segundo carácter de la
               nueva palabra para evitar repetir la letra común.


            */
            strcat(ant->palabra,aux->palabra+1);

            /* Como no se inserta el nodo, se libera la memoria */
            free(aux);

        }else{

            /* Inserción normal entre ant y act */

            ant->sig = aux;
            aux->sig = act;
        }
    }
}
