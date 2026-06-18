/*Ej. 12.- Se tiene una lista doblemente enlazada cuyos nodos representan depósitos de combustible en distintas zonas del país.

Los datos que se almacenan son:

ZONA (ANU4) (ordenada por este ítem – puede repetirse)
CAPACIDAD máxima del depósito (REAL)
RESERVA (REAL)

Desarrollar un subprograma tal que, a partir de un envío de combustible a una zona determinada, actualice la reserva del/los depósito/s que lo reciben, y eliminar los que colmen su capacidad máxima.

Informar si el envío pudo ser distribuido o no de forma completa.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo
{
    char zona[5];
    float capacidad;
    float reserva;

    struct nodo *ant;
    struct nodo *sig;

} nodo;

typedef nodo *ListaD;


void insertarFinal(ListaD *L,char zona[],float capacidad,float reserva);
void mostrar(ListaD L);
void distribuirCombustible(ListaD *L,char zonaBuscada[],float *envio);
void eliminarNodo(ListaD *L, nodo *elim);




int main()
{
    ListaD L = NULL;
    float envio=1000;
    insertarFinal(&L,"NORT",1000,700);
    insertarFinal(&L,"NORT",1500,1400);
    insertarFinal(&L,"NORT",2000,1800);
    insertarFinal(&L,"SUR ",1200,500);

    printf("LISTA ORIGINAL\n\n");
    mostrar(L);

    distribuirCombustible(&L,"NORT",&envio);

      if(envio == 0)
    {
        printf("\nEnvio distribuido completamente\n");
    }
    else
    {
        printf("\nNo pudo distribuirse completamente\n");
        printf("Sobran %.2f litros\n",envio);
    }



    printf("\nLISTA FINAL\n\n");
    mostrar(L);

    return 0;
}


void eliminarNodo(ListaD *L, nodo *elim)
{
    // Si ant == NULL significa que el nodo a eliminar
    // es el PRIMERO de la lista.
    if(elim->ant == NULL)
    {
        // El inicio de la lista pasa a ser el siguiente nodo.
        *L = elim->sig;

        // Si existe un siguiente nodo,
        // su campo anterior debe quedar en NULL
        // porque ahora será el primero.
        if(elim->sig != NULL)
        {
            elim->sig->ant = NULL;
        }
    }
    else
    {
        // El nodo anterior al eliminado pasa a apuntar
        // directamente al siguiente nodo.
        //
        // Antes:
        // A <-> elim <-> C
        //
        // Después:
        // A -------> C
        elim->ant->sig = elim->sig;

        // Si existe un nodo siguiente,
        // su puntero anterior debe apuntar
        // al nodo anterior del eliminado.
        //
        // Antes:
        // A <-> elim <-> C
        //
        // Después:
        // A <------- C
        if(elim->sig != NULL)
        {
            elim->sig->ant = elim->ant;
        }
    }

    // Libera la memoria ocupada por el nodo eliminado.
    free(elim);
}



void distribuirCombustible(ListaD *L,char zonaBuscada[],float *envio){
    nodo *aux;
    nodo *sigAux;
    float espacioLibre;

    aux = *L;

    /* Buscar primera aparición de la zona */
    while(aux != NULL && strcmp(aux->zona,zonaBuscada) != 0)
    {
        aux = aux->sig;
    }

    /* Procesar todos los depósitos de esa zona */
    while(aux != NULL &&strcmp(aux->zona,zonaBuscada) == 0 && *envio > 0){
        espacioLibre = aux->capacidad - aux->reserva;

        if(*envio >= espacioLibre)
        {
           *envio = *envio - espacioLibre;

            aux->reserva = aux->capacidad;

            sigAux = aux->sig;

            eliminarNodo(L,aux);

            aux = sigAux;
        }
        else
        {
            aux->reserva =aux->reserva + *envio;

            *envio = 0;
        }
    }


}



void insertarFinal(ListaD *L,char zona[],float capacidad,float reserva){
    nodo *nuevo;
    nodo *aux;

    nuevo = (nodo *)malloc(sizeof(nodo));

    strcpy(nuevo->zona,zona);
    nuevo->capacidad = capacidad;
    nuevo->reserva = reserva;

    nuevo->sig = NULL;
    nuevo->ant = NULL;

    if(*L == NULL) //Caso si la lista esta vacia
    {
        *L = nuevo;
    }
    else // Si la lista no esta vacia
    {
        aux = *L;

        while(aux->sig != NULL)
        {
            aux = aux->sig;
        }

        aux->sig = nuevo;
        nuevo->ant = aux;
    }
}


void mostrar(ListaD L){
    while(L != NULL){
        printf("%s  %.2f  %.2f\n",L->zona,L->capacidad,L->reserva);

        L = L->sig;
    }
}




