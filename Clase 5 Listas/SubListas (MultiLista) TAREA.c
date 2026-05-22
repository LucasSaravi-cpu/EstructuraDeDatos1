/*Aquí tienes la transcripción completa del texto de la imagen:

Se tiene una lista de clientes que registran pagos de un crédito con el siguiente diseño:

Numero de Cliente                (no se repite, ordenada ascendente)

Total Credito en $

Adeudado en $

Sublista de Pagos

Fecha (ordenada descendente, no se repite)

Importe  

Se pide:
a.- Dado un número de cliente correcto, una fecha y un importe, insertar el pago actualizando el valor adeudado.
b.- Dado un número de cliente y una fecha, eliminar el pago (si existe) actualizando el valor adeudado.
c.- Dado un número de cliente, eliminarlo de la lista
d.- Eliminar de la lista los clientes que ya no tienen deuda.*/

#include <stdlib.h>
#include <string.h>

/*-----------------------------------
SUBLISTA DE PAGOS
-----------------------------------*/

typedef struct pago{

    char fecha[15];
    float importe;

    struct pago *sig;
    struct pago *ant;

} pago;

typedef struct pago *SubLista;


/*-----------------------------------
LISTA DE CLIENTES
-----------------------------------*/

typedef struct cliente{

    int nroCli;

    float totalCredito;
    float adeudado;

    struct cliente *sig;
    struct cliente *ant;

    SubLista sub;

} cliente;

typedef struct cliente *TListaC;

/*a.- Dado un número de cliente correcto,
una fecha y un importe, insertar el pago
actualizando el valor adeudado*/

void insertarPago(TListaC LC, int nro, char fecha[], float imp){

    TListaC act;
    SubLista nuevo, aux, ant;

    act = LC;

    while (act != NULL && act->nroCli != nro)
        act = act->sig;

    if (act != NULL){

        nuevo = (SubLista) malloc(sizeof(pago));

        strcpy(nuevo->fecha, fecha);
        nuevo->importe = imp;

        aux = act->sub;
        ant = NULL;

        /* fecha ordenada descendente */

        while (aux != NULL &&
               strcmp(aux->fecha, fecha) > 0){

            ant = aux;
            aux = aux->sig;
        }

        nuevo->sig = aux;
        nuevo->ant = ant;

        if (ant == NULL)
            act->sub = nuevo;
        else
            ant->sig = nuevo;

        if (aux != NULL)
            aux->ant = nuevo;

        act->adeudado -= imp;
    }
}

/*b.- Dado un número de cliente y una fecha,
eliminar el pago si existe actualizando
el valor adeudado*/

void eliminarPago(TListaC LC, int nro, char fecha[]){

    TListaC act;
    SubLista elim;

    act = LC;

    while (act != NULL && act->nroCli != nro)
        act = act->sig;

    if (act != NULL){

        elim = act->sub;

        while (elim != NULL &&
               strcmp(elim->fecha, fecha) != 0)

            elim = elim->sig;

        if (elim != NULL){

            act->adeudado += elim->importe;

            if (elim == act->sub)
                act->sub = elim->sig;
            else
                elim->ant->sig = elim->sig;

            if (elim->sig != NULL)
                elim->sig->ant = elim->ant;

            free(elim);
        }
    }
}

/*c.- Dado un número de cliente,
eliminarlo de la lista*/

void eliminarCliente(TListaC *LC, int nro){

    TListaC elim;

    elim = *LC;

    while (elim != NULL && elim->nroCli != nro)
        elim = elim->sig;

    if (elim != NULL){

        if (elim == *LC)
            *LC = elim->sig;
        else
            elim->ant->sig = elim->sig;

        if (elim->sig != NULL)
            elim->sig->ant = elim->ant;

        free(elim);
    }
}

/*d.- Eliminar de la lista los clientes
que ya no tienen deuda*/

void eliminarSinDeuda(TListaC *LC){

    TListaC elim, aux;

    aux = *LC;

    while (aux != NULL){

        if (aux->adeudado == 0){

            elim = aux;
            aux = aux->sig;

            if (elim == *LC)
                *LC = elim->sig;
            else
                elim->ant->sig = elim->sig;

            if (aux != NULL)
                aux->ant = elim->ant;

            free(elim);
        }
        else
            aux = aux->sig;
    }
}