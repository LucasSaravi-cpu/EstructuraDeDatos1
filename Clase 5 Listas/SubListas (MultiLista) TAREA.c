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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct pago{

    char fecha[15];
    float importe;
    struct pago *sig;
    struct pago *ant;

} pago;

typedef struct pago *SubLista;


typedef struct cliente{

    int nroCli;

    float totalCredito;
    float adeudado;

    struct cliente *sig;
    struct cliente *ant;

    SubLista sub;

} cliente;

typedef struct cliente *TListaC;


void insertarCliente(TListaC *LC,int nro,float total,float adeudado);
void insertarPago(TListaC LC,int nro,char fecha[],float imp);
void cargarPagos(TListaC LC);
void cargarClientes(TListaC *LC);
void mostrarPagos(SubLista sub);
void mostrarLista(TListaC LC);
void eliminarSinDeuda(TListaC *LC);
void eliminarCliente(TListaC *LC, int nro);
void eliminarPago(TListaC LC,int nro,char fecha[]);




int main(){

    TListaC LC = NULL;


    cargarClientes(&LC);

    cargarPagos(LC);

    printf("\n LISTA ORIGINAL \n");

    mostrarLista(LC);


    insertarPago(LC,100,"2026-07-30",5000);

    printf("\nDESPUES DE INSERTAR PAGO \n");

    mostrarLista(LC);



    eliminarPago(LC,100,"2026-07-15");

    printf("\nDESPUES DE ELIMINAR PAGO \n");

    mostrarLista(LC);

    eliminarCliente(&LC,300);

    printf("\nDESPUES DE ELIMINAR CLIENTE \n");

    mostrarLista(LC);


    eliminarSinDeuda(&LC);

    printf("\nLISTA FINAL \n");

    mostrarLista(LC);

    return 0;
}





void insertarCliente(TListaC *LC,int nro,float total,float adeudado){

    TListaC aux, ant, act;

    aux = (TListaC) malloc(sizeof(cliente));

    aux->nroCli = nro;
    aux->totalCredito = total;
    aux->adeudado = adeudado;

    aux->sub = NULL;

    /* INSERTAR AL PRINCIPIO */

    if(*LC == NULL ||
       nro < (*LC)->nroCli){

        aux->sig = *LC;
        aux->ant = NULL;

        if(*LC != NULL)
            (*LC)->ant = aux;

        *LC = aux;
    }

    else{

        ant = NULL;
        act = *LC;

        while(act != NULL &&
              nro > act->nroCli){

            ant = act;
            act = act->sig;
        }

        aux->sig = act;
        aux->ant = ant;

        ant->sig = aux;

        /* SI NO ESTA AL FINAL */

        if(act != NULL)
            act->ant = aux;
    }
}






void cargarClientes(TListaC *LC){

    FILE *arch;

    int nro;
    float total;
    float adeudado;

    arch = fopen("clientes.txt", "r");

    if(arch == NULL){

        printf("Error al abrir clientes.txt\n");

    }else{

    while(fscanf(arch,"%d %f %f",&nro,&total,&adeudado) == 3){

        insertarCliente(LC,nro,total,adeudado);
    }
    }

    fclose(arch);
}




void cargarPagos(TListaC LC){

    FILE *arch;

    int nro;
    char fecha[15];
    float importe;

    arch = fopen("pagos.txt", "r");

    if(arch == NULL){

        printf("Error al abrir pagos.txt\n");

    }else{

    while(fscanf(arch,"%d %s %f",&nro,fecha,&importe) == 3){

        insertarPago(LC,nro,fecha,importe);
    }
    }
    fclose(arch);
}



/*a.- Dado un número de cliente correcto, una fecha y un importe, insertar el pago actualizando el valor adeudado.*/

void insertarPago(TListaC LC,int nro,char fecha[],float imp){

    TListaC act;

    SubLista nuevo, aux, ant;

    act = LC;

    while(act != NULL &&act->nroCli != nro)

        act = act->sig;

    if(act != NULL){

        nuevo = (SubLista) malloc(sizeof(pago));

        strcpy(nuevo->fecha, fecha);
        nuevo->importe = imp;

        /* INSERTAR AL PRINCIPIO */

        if(act->sub == NULL ||
           strcmp(fecha,
                  act->sub->fecha) > 0){

            nuevo->sig = act->sub;
            nuevo->ant = NULL;

            if(act->sub != NULL)
                act->sub->ant = nuevo;

            act->sub = nuevo;
        }

        else{

            ant = act->sub;
            aux = act->sub->sig;

            while(aux != NULL &&
                  strcmp(aux->fecha,
                         fecha) > 0){

                ant = aux;
                aux = aux->sig;
            }

            nuevo->sig = aux;
            nuevo->ant = ant;

            ant->sig = nuevo;

            if(aux != NULL)
                aux->ant = nuevo;
        }

        act->adeudado -= imp;
    }
}


void mostrarPagos(SubLista sub){

    while(sub != NULL){

        printf("      Fecha: %s\n",
               sub->fecha);

        printf("      Importe: %.2f\n",
               sub->importe);

        sub = sub->sig;
    }
}




void mostrarLista(TListaC LC){

    while(LC != NULL){

        printf("\n--------------\n");

        printf("CLIENTE: %d\n",
               LC->nroCli);

        printf("TOTAL CREDITO: %.2f\n",
               LC->totalCredito);

        printf("ADEUDADO: %.2f\n",
               LC->adeudado);

        printf("PAGOS:\n");

        if(LC->sub == NULL)
            printf("      Sin pagos\n");

        else
            mostrarPagos(LC->sub);

        LC = LC->sig;
    }
}


/*b.- Dado un número de cliente y una fecha, eliminar el pago (si existe) actualizando el valor adeudado.*/




void eliminarPago(TListaC LC,int nro,char fecha[]){

    TListaC act;

    SubLista ant, aux, elim;

    act = LC;

    while(act != NULL &&act->nroCli != nro)

        act = act->sig;

    if(act != NULL){

        ant = NULL;
        aux = act->sub;

        while(aux != NULL &&strcmp(aux->fecha,fecha) != 0){

            ant = aux;
            aux = aux->sig;
        }

        if(aux != NULL){

            act->adeudado += aux->importe;

            elim = aux;

            /* SI ESTA AL PRINCIPIO */

            if(elim == act->sub){

                act->sub = act->sub->sig;

                if(act->sub != NULL)
                    act->sub->ant = NULL;
            }

            else{

                ant->sig = elim->sig;

                /* SI NO ESTA AL FINAL */

                if(elim->sig != NULL)
                    elim->sig->ant = ant;
            }

            free(elim);
        }
    }
}


/*c.- Dado un número de cliente, eliminarlo de la lista*/


void eliminarCliente(TListaC *LC, int nro){

    TListaC ant, aux, elim;

    ant = NULL;
    aux = *LC;

    while(aux != NULL &&aux->nroCli != nro){

        ant = aux;
        aux = aux->sig;
    }

    if(aux != NULL){

        elim = aux;

        /* SI ESTA AL PRINCIPIO */

        if(elim == *LC){

            *LC = (*LC)->sig;

            if(*LC != NULL)
                (*LC)->ant = NULL;
        }

        else{

            ant->sig = elim->sig;

            /* SI NO ESTA AL FINAL */

            if(elim->sig != NULL)
                elim->sig->ant = ant;
        }

        free(elim);
    }
}


/*d.- Eliminar de la lista los clientes que ya no tienen deuda.*/


void eliminarSinDeuda(TListaC *LC){

    TListaC ant, aux, elim;

    ant = NULL;
    aux = *LC;

    while(aux != NULL){

        if(aux->adeudado == 0){

            elim = aux;
            aux = aux->sig;

            /* SI ESTA AL PRINCIPIO */

            if(elim == *LC){

                *LC = aux;

                if(*LC != NULL)
                    (*LC)->ant = NULL;
            }

            else{

                ant->sig = aux;

                /* SI NO ESTA AL FINAL */

                if(aux != NULL)
                    aux->ant = ant;
            }

            free(elim);
        }

        else{

            ant = aux;
            aux = aux->sig;
        }
    }
}
