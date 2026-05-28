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

typedef struct nodito {
    char fecha[9];
    float imp;
    struct nodito * sig;
} nodito;

typedef nodito * SubLista;

typedef struct nodoC {
    int numC;
    float cred, deuda;
    struct nodoC * sig;
    SubLista sub;
} nodoC;

typedef nodoC * TListaC;


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


    insertarPago(LC,100,"20260730",5000);

    printf("\nDESPUES DE INSERTAR PAGO \n");

    mostrarLista(LC);



    eliminarPago(LC,100,"20260715");

    printf("\nDESPUES DE ELIMINAR PAGO \n");

    mostrarLista(LC);

    eliminarCliente(&LC,100);

    printf("\nDESPUES DE ELIMINAR CLIENTE \n");

    mostrarLista(LC);


    eliminarSinDeuda(&LC);

    printf("\nLISTA FINAL \n");

    mostrarLista(LC);

    return 0;
}





void insertarCliente(TListaC *LC,int nro,float total,float adeudado){

    TListaC nuevo, act, ant;

    nuevo = (TListaC) malloc(sizeof(nodoC));

    nuevo->numC = nro;
    nuevo->cred = total;
    nuevo->deuda = adeudado;
    nuevo->sub = NULL;

    ant = NULL;
    act = *LC;

    while(act != NULL && act->numC < nro){

        ant = act;
        act = act->sig;
    }

    nuevo->sig = act;

    /* SI INSERTA AL PRINCIPIO */

    if(ant == NULL){

        *LC = nuevo;
    }
    else{

        ant->sig = nuevo;
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
    char fecha[9];
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

void insertarPago(TListaC L,int nro,char fecha[],float imp){

    TListaC aux =L;

    SubLista nuevo,acts,ants;

    while(aux->numC != nro){

        aux = aux->sig;

    }
//encuentro al cliente
        nuevo = (SubLista) malloc(sizeof(nodito));

        strcpy(nuevo->fecha, fecha);
        nuevo->imp= imp;
        aux->deuda-=imp;



        if(aux->sub == NULL ||strcmp(fecha, aux->sub->fecha) > 0){

            nuevo->sig = aux->sub;
            aux->sub= nuevo ;
        }else{

            acts= aux->sub;

        while (acts!=NULL && strcmp( fecha , ants->fecha <0)){
            acts= ants;
            acts=acts->sig;
        }

            nuevo->sig = acts;
            ants->sig= nuevo;
    }
}


void mostrarPagos(SubLista sub){

    while(sub != NULL){

        printf("      Fecha: %s\n",
               sub->fecha);

        printf("      Importe: %.2f\n",
               sub->imp);

        sub = sub->sig;
    }
}




void mostrarLista(TListaC LC){

    while(LC != NULL){

        printf("\n--------------\n");

        printf("CLIENTE: %d\n",
               LC->numC);

        printf("TOTAL CREDITO: %.2f\n",
               LC->cred);

        printf("ADEUDADO: %.2f\n",
               LC->deuda);

        printf("PAGOS:\n");

        if(LC->sub == NULL)
            printf("      Sin pagos\n");

        else
            mostrarPagos(LC->sub);

        LC = LC->sig;
    }
}


/*b.- Dado un número de cliente y una fecha, eliminar el pago (si existe) actualizando el valor adeudado.*/




void eliminarPago(TListaC L,int nro,char fecha[]){

    TListaC aux=L;

    SubLista ants,acts;


    while(aux!= NULL &&aux->numC != nro){

        aux= aux->sig;
    }
    if(aux!= NULL && aux->numC ==nro ){

        ants = NULL;
        acts = aux->sub;

        while(acts != NULL && strcmp(acts->fecha,fecha) >0){

            ants=acts;
            acts= acts->sig;
        }

        if(acts != NULL){

            aux->deuda += acts->imp;


            if(ants == NULL){

                aux->sub = acts->sig;;
            }

            else{

                ants->sig = acts->sig;

            }

            free(acts);
        }
    }
}


/*c.- Dado un número de cliente, eliminarlo de la lista*/


void eliminarCliente(TListaC *L, int nro){

    TListaC aux= *L;
    TListaC ant;

    SubLista auxs;

    while(aux != NULL &&aux->numC != nro){

        ant = aux;
        aux = aux->sig;
    }

    if(aux != NULL && aux -> numC==nro){

        while ( aux->sub!=NULL){ // Eliminar nodo por nodo

        auxs=aux->sub;
        aux->sub = auxs->sig;
         free(auxs);

        }

    if ( aux == *L){

        *L= aux ->sig ;
    } else {
        ant->sig=aux->sig;
    }

free(aux);
    }
}


/*d.- Eliminar de la lista los clientes que ya no tienen deuda.*/


void eliminarSinDeuda(TListaC *L){
    TListaC aux = *L;
    SubLista auxs;
     TListaC ant;

    while ( aux!=NULL && aux->deuda !=0){

        ant=aux;
        aux=aux->sig;

    }

    if (aux!=NULL && aux->deuda==0){

        while (aux ->sub!=NULL){

        auxs = aux->sub;
        aux->sub = auxs->sig;
        free(auxs);
        }
        if (aux==*L){

            *L=aux->sig;
        }
        else{

            ant->sig=aux->sig;
        }
        free(aux);
        }
    }

