/*Multilistas

Una multilista es una estructura de listas en la que los nodos tienen además del campo puntero al siguiente elemento un puntero al primer nodo de una lista o una pila o una cola como parte de los datos de cada nodo.

En el caso de que los nodos tengan Pilas o Colas como parte integrante de ellos, estas estructuras serán accedidas con el TDA correspondiente manteniendo el encapsulamiento.

En el caso en el que los nodos tengas algún puntero a una o más sublistas como parte de ellos, llamaremos a esta estructura Lista con Sublista y a continuación veremos un ejemplo de su tratamiento.

Listas con Sublistas - Ejemplo

Se tiene una lista L con la siguiente información:

Codigo de Contenedor (no se repite)
Destino
Peso (en toneladas)

Además, una lista de barcos en puerto esperando embarcar los contenedores que están en la lista:

Codigo de Barco (no se repite)
Destino (puede repetirse)
Capacidad
Sublista de Contenedores
Codigo de Contenedor
Peso

Procesar la información de L y distribuir los contenedores en los barcos. Si alguno no pudiera ser embarcado por falta 
de capacidad en el destino o por falta de barcos a ese destino, quedará en L, de forma tal que al terminar el proceso 
queden en la misma los contenedores que no pudieron ser despachados.*/


#include <stdlib.h>
#include <string.h>

typedef struct nodo {
    char codC[15], dest[15];
    float peso;
    struct nodo * sig;
} nodo;

typedef struct nodo * TListaC;

typedef struct nodito {
    char codC[15];
    float peso;
    struct nodito * sig;
} nodito;

typedef struct nodito * SubLista;

typedef struct nodoB {
    char codB[15], dest[15];
    float capac;
    struct nodoB * sig;
    SubLista sub;
} nodoB;

typedef struct nodoB * TListaB;

void envios (TListaC *LC, TListaB LB){

    int Despacho;
    float Suma;
    TListaB act;
    SubLista nuevo, actS;
    TListaC ant, aux, elim;

    ant = NULL;
    aux = *LC;

    while (aux != NULL) {

        Despacho = 0;
        act = LB;

        while (act != NULL && !Despacho) {

            if (strcmp(aux->dest, act->dest) == 0) {

                Suma = 0;
                actS = act->sub;

                while (actS != NULL) {

                    Suma += actS->peso;
                    actS = actS->sig;
                }

                if ((Suma + aux->peso) <= act->capac) {

                    nuevo = (SubLista) malloc(sizeof(nodito));

                    strcpy(nuevo->codC, aux->codC);
                    nuevo->peso = aux->peso;

                    nuevo->sig = act->sub;
                    act->sub = nuevo;

                    Despacho = 1;
                }
            }

            act = act->sig;
        }

        if (!Despacho) {

            ant = aux;
            aux = aux->sig;
        }
        else {

            elim = aux;
            aux = aux->sig;

            if (elim == *LC)
                *LC = (*LC)->sig;
            else
                ant->sig = aux;

            free(elim);
        }
    }
}