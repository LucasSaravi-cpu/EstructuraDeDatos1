/*Ej 4) Las notas de pedidos de una librería a editoriales están en una lista de Pedidos con
sublistas en la que cada nodo representa una editorial con los siguientes campos: NroEditorial
(ordenado de 0 a 15), CantidadTitulos, CantidadTotalLibros y una SubLista de pedidos en la
que en cada nodo se tiene IdLibro(ANU12), NroSucursal (0 a 7) (la combinación
IdLibro+NroSucursal no se repite en la misma Editorial) y CantidadSolicitada.
Desarrollar un programa correctamente modularizado que implemente los siguientes
requerimientos:
a) Generar la lista Pedidos (inicialmente vacía) a partir del archivo de texto
CARGAACTUAL.TXT, cada campo separado con un espacio. Los campos son:
NroEditorial (clave secundaria, 1er campo de secuencia)
IdLibro (clave secundaria, 2do campo de secuencia)
NroSucursal (no se repite la terna)
CantidadSolicitada
b) Que cambiaria en el inciso a) si la información del archivo fuera:
NroEditorial (clave secundaria, 1er campo de secuencia)
IdLibro (clave secundaria)
NroSucursal (no se repite la terna)
CantidadSolicitada
c) En un archivo de texto SOLICITUDSUCURSALES.TXT se tienen las solicitudes pendientes de
la sucursal X. Cada línea contiene tres campos separados por espacio: NroEditorial, IdLibro
CantidadSolicitada. Leer X por teclado y actualizar la lista Pedidos desde el archivo para
aquellos pedidos válidos (debe existir la editorial); con las solicitudes para editoriales que
no están en la lista Pedidos, generar una cola de nombre PendienteX, cada elemento de
la cola contendrá los tres datos del archivo.

d) Generar una matriz E de 16x8, desde la lista Pedidos en la que en la posición [i,j] se
almacena la cantidad de total de libros solicitados a la editorial i para la sucursal j.

e) A partir de la matriz creada en c), obtener y mostrar de forma recursiva y eficiente el
número de las sucursales que no solicitaron libros. No utilizar ciclos.

f) La sucursal S (dato) ha cerrado sus puertas
I. Eliminar de la lista Pedidos todos los pedidos que eran de esa sucursal, indicar por fin
de proceso cuál era la editorial para la cual S tenía más pedidos de libros a satisfacer.
II. Eliminar de PendienteX, los pedidos de S, dejar el resto en el mismo orden.*/


#include <stdio.h>
#include <stdlib.h>
#include "Colas.h"
#include <string.h>
#define MAXFILA 16
#define MAXCOL 8

typedef struct nodoS{

    char idLibro[13];
    int nroSucursal;
    int cantidadSolicitada;

    struct nodoS *sig;

}nodoS;

typedef nodoS *SubLista;

typedef struct nodoP{

    int nroEditorial;
    int cantidadTitulos;
    int cantidadTotalLibros;

    SubLista pedidos;

    struct nodoP *sig;

}nodoP;

typedef nodoP *Lista;

void cargarPedidos(Lista *L);
void mostrarLista(Lista L);

void cargarPedidosB(Lista *L);
int existeLibro(SubLista S, char libro[]);

void actualizarPedidos(Lista L,TCola *PendienteX, int sucursal);
void mostrarCola(TCola *C);
void generarMatriz(Lista L, int E[MAXFILA][MAXCOL]);

void mostrarMatriz(int E[MAXFILA][MAXCOL]);

void mostrarSucursalesSinPedidos(int E[MAXFILA][MAXCOL],int fila,int suc, int tienePedidos);

void eliminarSucursalPedidos(Lista L, int S,int *maxLibros , int *maxEditorial);
void eliminarPendientesSucursal(TCola *PendienteX,int S,int X);

int main()
{
    Lista Pedidos = NULL;
     int X;
     TCola PendienteX;
     int E[MAXFILA][MAXCOL];
     int maxLibros=0;
     int maxEditorial=0;
     int sucursal;
    //Ejercicio A
    cargarPedidos(&Pedidos);

    printf("\n\nLISTA GENERADA\n");

    mostrarLista(Pedidos);

    //Ejercicio B
   //cargarPedidosB(&Pedidos);

 //printf("\n\nLISTA GENERADA\n");

 //  mostrarLista(Pedidos);


iniciaC(&PendienteX);


printf("Ingrese sucursal: ");
scanf("%d",&X);

actualizarPedidos(Pedidos,&PendienteX,X);


printf("\n\nLISTA ACTUALIZADA \n");

mostrarLista(Pedidos);
printf("\n\nLa cola creada es \n");
mostrarCola(&PendienteX);

generarMatriz(Pedidos, E);
mostrarMatriz(E);


printf("\nSucursales sin pedidos:\n");


mostrarSucursalesSinPedidos(E, 0, 0,0);


printf("Ingrese la sucursal que quiere eliminar: \n");
scanf("%d",&sucursal);

eliminarSucursalPedidos(Pedidos,sucursal,&maxLibros,&maxEditorial);
printf("\n  La editorial con mas libros para la sucursal %d fue %d",sucursal,maxEditorial);
printf("\nCantidad de libros: %d\n",maxLibros);


eliminarPendientesSucursal(&PendienteX,sucursal,X);

printf("\n\nLISTA FINAL\n");

mostrarLista(Pedidos);
printf("\n\nLa cola final es\n");
mostrarCola(&PendienteX);

return 0;
}

void mostrarLista(Lista L){

    SubLista aux;

    while(L != NULL){

        printf("\n=====================================");
        printf("\nEDITORIAL: %d",L->nroEditorial);
        printf("\nCantidad de Titulos: %d",
               L->cantidadTitulos);
        printf("\nCantidad Total Libros: %d",
               L->cantidadTotalLibros);

        printf("\n\nPEDIDOS:");

        aux = L->pedidos;

        while(aux != NULL){

            printf("\nISBN: %s",
                   aux->idLibro);

            printf("  Sucursal: %d",
                   aux->nroSucursal);

            printf("  Cantidad: %d",
                   aux->cantidadSolicitada);

            aux = aux->sig;
        }

        printf("\n");

        L = L->sig;
    }
}



void cargarPedidos(Lista *L){

    FILE *fp;   /* puntero al archivo */

    int nroEditorial;
    int nroSucursal;
    int cantidad;

    int editorialActual;   /* guarda la editorial del corte */

    char idLibro[13];
    char libroActual[13];  /* guarda el libro del corte */

    Lista nueE, ultE=NULL; /* nuevo nodo editorial y último editorial */

    SubLista nueP, ultP;   /* nuevo pedido y último pedido */

    /* apertura del archivo */
    fp=fopen("CARGAACTUAL.TXT","rt");

    if(fp!=NULL){

        /* leo el primer registro */
        fscanf(fp,"%d %s %d %d",&nroEditorial,idLibro, &nroSucursal,&cantidad);

        /* mientras no llegue al final del archivo */
        while(!feof(fp)){

            /*====================================*/
            /* COMIENZA UNA NUEVA EDITORIAL       */
            /*====================================*/

            /* guardo la editorial actual */
            editorialActual=nroEditorial;

            /* reservo memoria para el nodo editorial */
            nueE=(Lista)malloc(sizeof(nodoP));

            /* cargo los datos de la editorial */
            nueE->nroEditorial=editorialActual;

            /* inicializo acumuladores */
            nueE->cantidadTitulos=0;
            nueE->cantidadTotalLibros=0;

            /* inicialmente no tiene pedidos */
            nueE->pedidos=NULL;

            /* no apunta a ninguna otra editorial */
            nueE->sig=NULL;

            /* inserto la editorial al final de la lista */
            if(*L==NULL)
                *L=nueE;
            else
                ultE->sig=nueE;

            /* actualizo último editorial */
            ultE=nueE;

            /* la sublista comienza vacía */
            ultP=NULL;


            while(!feof(fp) &&nroEditorial==editorialActual){

                /* guardo el ISBN actual para el corte */
                strcpy(libroActual,idLibro);

                /* apareció un nuevo título */
                nueE->cantidadTitulos++;


                while(!feof(fp) &&nroEditorial==editorialActual &&strcmp(idLibro,libroActual)==0){

                    /* creo un nuevo nodo pedido */
                    nueP=
                    (SubLista)malloc(sizeof(nodoS));

                    /* copio ISBN */
                    strcpy(nueP->idLibro,idLibro);

                    /* copio sucursal */
                    nueP->nroSucursal=
                    nroSucursal;

                    /* copio cantidad solicitada */
                    nueP->cantidadSolicitada=
                    cantidad;

                    /* inicialmente no apunta a nadie */
                    nueP->sig=NULL;

                    /* inserto el pedido al final de la sublista */
                    if(nueE->pedidos==NULL)
                        nueE->pedidos=nueP;
                    else
                        ultP->sig=nueP;

                    /* actualizo último pedido */
                    ultP=nueP;

                    /* acumulo cantidad total de libros */
                    nueE->cantidadTotalLibros += cantidad;

                    /* leo el siguiente registro */
                    fscanf(fp,"%d %s %d %d", &nroEditorial, idLibro,&nroSucursal,&cantidad);

                }/* fin corte por libro */

            }/* fin corte por editorial */

        }/* fin while archivo */

        fclose(fp);
    }
}





void cargarPedidosB(Lista *L){

    FILE *fp;

    int nroEditorial;
    int nroSucursal;
    int cantidad;

    int editorialActual;

    char idLibro[13];

    Lista nueE, ultE = NULL;

    SubLista nueP, ultP;

    fp = fopen("CARGAACTUALB.TXT","rt");

    if(fp != NULL){

        fscanf(fp,"%d %s %d %d",&nroEditorial,idLibro, &nroSucursal,&cantidad);

        while(!feof(fp)){

            editorialActual = nroEditorial;

            nueE = (Lista)malloc(sizeof(nodoP));

            nueE->nroEditorial = editorialActual;
            nueE->cantidadTitulos = 0;
            nueE->cantidadTotalLibros = 0;
            nueE->pedidos = NULL;
            nueE->sig = NULL;

            if(*L == NULL)
                *L = nueE;
            else
                ultE->sig = nueE;

            ultE = nueE;

            ultP = NULL;

            while(!feof(fp) && nroEditorial == editorialActual){

                /* Si el ISBN no apareció antes,
                   incremento cantidad de títulos */
                if(!existeLibro(nueE->pedidos,idLibro))
                    nueE->cantidadTitulos++;

                nueP = (SubLista)malloc(sizeof(nodoS));

                strcpy(nueP->idLibro,idLibro);
                nueP->nroSucursal = nroSucursal;
                nueP->cantidadSolicitada = cantidad;
                nueP->sig = NULL;

                if(nueE->pedidos == NULL)
                    nueE->pedidos = nueP;
                else
                    ultP->sig = nueP;

                ultP = nueP;

                nueE->cantidadTotalLibros += cantidad;

                fscanf(fp,"%d %s %d %d",&nroEditorial, idLibro,&nroSucursal, &cantidad);
            }
        }

        fclose(fp);
    }
}

int existeLibro(SubLista S, char libro[]){

    int existe = 0;

    while(S != NULL && existe == 0){

        if(strcmp(S->idLibro, libro) == 0)
            existe = 1;

        S = S->sig;
    }

    return existe;
}


void actualizarPedidos(Lista L,TCola *PendienteX, int sucursal){
    FILE *fp;

    int nroEditorial;
    int cantidad;

    char idLibro[13];

    Lista auxE;

    SubLista nuevo, auxS;

    TElementoC dato;

    /* apertura del archivo */
    fp = fopen("SOLICITUDSUCURSALES.TXT","rt");

    if(fp != NULL){

        /* lectura inicial */
        fscanf(fp,"%d %s %d",
               &nroEditorial,
               idLibro,
               &cantidad);

        while(!feof(fp)){



            auxE = L;

            while(auxE != NULL && auxE->nroEditorial != nroEditorial)

                auxE = auxE->sig;



            if(auxE != NULL){

                /* si es un ISBN nuevo,
                   aumenta cantidad de títulos */
                if(!existeLibro(auxE->pedidos,
                                idLibro))

                    auxE->cantidadTitulos++;

                /* crear nuevo pedido */
                nuevo =
                (SubLista)malloc(sizeof(nodoS));

                strcpy(nuevo->idLibro,
                       idLibro);

                nuevo->nroSucursal =
                sucursal;

                nuevo->cantidadSolicitada =
                cantidad;

                nuevo->sig = NULL;

                /* insertar al final
                   de la sublista */

                if(auxE->pedidos == NULL)

                    auxE->pedidos = nuevo;

                else{

                    auxS = auxE->pedidos;

                    while(auxS->sig != NULL)

                        auxS = auxS->sig;

                    auxS->sig = nuevo;
                }

                /* actualizar total de libros */

                auxE->cantidadTotalLibros +=
                cantidad;
            }

           // si a editorial no existe
            else{

                dato.nroEditorial =
                nroEditorial;

                strcpy(dato.idLibro,
                       idLibro);

                dato.cantidadSolicitada =
                cantidad;

                poneC(PendienteX,dato);
            }

            /* leer siguiente registro */
            fscanf(fp,"%d %s %d",
                   &nroEditorial,
                   idLibro,
                   &cantidad);
        }

        fclose(fp);
    }
}



void mostrarCola(TCola *C){

    TElementoC dato;
    TCola aux;

    iniciaC(&aux);

    printf("\nCOLA PENDIENTES\n");

    while(!vaciaC(*C)){

        sacaC(C,&dato);

        printf("\nEditorial: %d",
               dato.nroEditorial);

        printf("\nISBN: %s",
               dato.idLibro);

        printf("\nCantidad: %d\n",
               dato.cantidadSolicitada);

        poneC(&aux,dato);
    }

    while(!vaciaC(aux)){

        sacaC(&aux,&dato);
        poneC(C,dato);
    }
}




void generarMatriz(Lista L, int E[MAXFILA][MAXCOL])
{
    int i, j;
    SubLista auxS;

    // Inicializar matriz en 0
    for(i=0; i<MAXFILA; i++)
        for(j=0; j<MAXCOL; j++)
            E[i][j] = 0;

    // Recorrer lista de editoriales
    while(L != NULL)
    {
        auxS = L->pedidos;

        // Recorrer pedidos de la editorial
        while(auxS != NULL)
        {
            E[L->nroEditorial][auxS->nroSucursal] +=auxS->cantidadSolicitada;

            auxS = auxS->sig;
        }

        L = L->sig;
    }
}


void mostrarMatriz(int E[MAXFILA][MAXCOL])
{
    int i, j;

    printf("\n\nMATRIZ E\n\n");


    for(i = 0; i < MAXFILA; i++)
    {


        for(j = 0; j < MAXCOL; j++)
            printf("%6d", E[i][j]);

        printf("\n");
    }
}


void mostrarSucursalesSinPedidos(int E[MAXFILA][MAXCOL], int fila, int suc, int tienePedidos){
    /* Mientras existan sucursales por analizar */
    if(suc < 8)
    {
        /* Todavía estoy recorriendo las editoriales
           de la sucursal actual */
        if(fila < 16)
        {
            /* Si encuentro algún pedido,
               marco que la sucursal sí solicitó libros */
            if(E[fila][suc] != 0)
                tienePedidos = 1;

            /* Continúo con la siguiente editorial
               de la misma sucursal */
            mostrarSucursalesSinPedidos(E,
                                        fila + 1,
                                        suc,
                                        tienePedidos);
        }
        else
        {
            /* Llegué al final de la columna (sucursal).
               Si nunca encontré pedidos, la sucursal
               no solicitó libros */
            if(!tienePedidos)
                printf("Sucursal %d \n", suc);

            /* Paso a analizar la siguiente sucursal.
               Reinicio fila y la bandera */
            mostrarSucursalesSinPedidos(E,
                                        0,
                                        suc + 1,
                                        0);
        }
    }
}



void eliminarSucursalPedidos(Lista L, int S,int *maxLibros , int *maxEditorial)
{
    SubLista *p, elim;
    int acumEditorial;

    while(L != NULL)
    {
        acumEditorial = 0;

        p = &(L->pedidos);

        while(*p != NULL)
        {
            if((*p)->nroSucursal == S)
            {
                acumEditorial +=
                (*p)->cantidadSolicitada;

                L->cantidadTotalLibros -=
                (*p)->cantidadSolicitada;

                elim = *p;
                *p = (*p)->sig;
                free(elim);
            }
            else
                p = &((*p)->sig);
        }

        if(acumEditorial > *maxLibros)
        {
            *maxLibros = acumEditorial;
            *maxEditorial = L->nroEditorial;
        }

        L = L->sig;
    }
}


void eliminarPendientesSucursal(TCola *PendienteX, int S,int X)
{
    TCola aux;
    TElementoC dato;

    iniciaC(&aux);

    while(!vaciaC(*PendienteX))
    {
        sacaC(PendienteX,&dato);

        if(S != X)
            poneC(&aux,dato);
    }

    while(!vaciaC(aux))
    {
        sacaC(&aux,&dato);
        poneC(PendienteX,dato);
    }
}
