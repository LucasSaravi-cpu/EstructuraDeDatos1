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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
    char codC[15], dest[15];
    float peso;
    struct nodo * sig;
} nodo;

typedef nodo* TListaC;

typedef struct nodito {
    char codC[15];
    float peso;
    struct nodito * sig;
} nodito;

typedef nodito* SubLista;

typedef struct nodoB {
    char codB[15], dest[15];
    float capac;
    struct nodoB * sig;
    SubLista sub;  //Sublista de contenedores
} nodoB;

typedef nodoB* TListaB;

void cargarContenedores(TListaC *LC);
void cargarBarcos(TListaB *LB);
void envios(TListaC *LC, TListaB LB);
void mostrarBarcos(TListaB LB);
void mostrarContenedoresNoDespachados(TListaC LC);


int main() {
    TListaC LC = NULL;
    TListaB LB = NULL;

    cargarContenedores(&LC);
    cargarBarcos(&LB);

    printf("Contenedores iniciales \n");
    mostrarContenedoresNoDespachados(LC);

    printf("\nBarcos antes del embarque \n");
    mostrarBarcos(LB);

   
    envios(&LC, LB);

    printf("\nBarcos después del embarque \n");
    mostrarBarcos(LB);

    printf("\n Contenedores NO despachados (quedan en lista) \n");
    mostrarContenedoresNoDespachados(LC);



    return 0;
}

// =Cargar contenedores desde archivo

void cargarContenedores(TListaC *LC) {
    FILE *f = fopen("contenedores.txt", "r");
    if (!f) {
        printf("Error al abrir el archivo \n");

    }else{

    char cod[15], dest[15];
    float peso;

    while (fscanf(f, "%s %s %f", cod, dest, &peso) == 3) {

        nodo *nuevo = (nodo*)malloc(sizeof(nodo));
        strcpy(nuevo->codC, cod);
        strcpy(nuevo->dest, dest);
        nuevo->peso = peso;
        nuevo->sig = *LC;
        *LC = nuevo;
    }
    }

    fclose(f);


}


void cargarBarcos(TListaB *LB) {
    FILE *f = fopen("barcos.txt", "r");
    if (!f) {
        printf("Error al abrir el archivo");

    }else{

    char cod[15], dest[15];
    float capac;

    while (fscanf(f, "%s %s %f", cod, dest, &capac) == 3) {
        nodoB *nuevo = (nodoB*)malloc(sizeof(nodoB));
        strcpy(nuevo->codB, cod);
        strcpy(nuevo->dest, dest);
        nuevo->capac = capac;
        nuevo->sig = *LB;
        nuevo->sub = NULL;  // Sublista vacía al inicio
        *LB = nuevo;
    }
    }

    fclose(f);
}

void envios(TListaC *LC, TListaB LB) {
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
                    nuevo = (SubLista)malloc(sizeof(nodito));
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
        } else {
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


void mostrarBarcos(TListaB LB) {
    TListaB b = LB;
    while (b != NULL) {
        printf("Barco: %s | Destino: %s | Capacidad: %.1f | Embarcados: ", b->codB, b->dest, b->capac);
        SubLista s = b->sub;
        if (s == NULL) {
            printf("(ninguno)");
        } else {
            while (s != NULL) {
                printf("[%s, %.1f] ", s->codC, s->peso);
                s = s->sig;
            }
        }
        printf("\n");
        b = b->sig;
    }
}


void mostrarContenedoresNoDespachados(TListaC LC) {
    TListaC aux = LC;
    if (aux == NULL) {
        printf("(Ningún contenedor pendiente)\n");

    }else{
    while (aux != NULL) {
        printf("Contenedor: %s | Destino: %s | Peso: %.1f\n", aux->codC, aux->dest, aux->peso);
        aux = aux->sig;
    }
    }
}

