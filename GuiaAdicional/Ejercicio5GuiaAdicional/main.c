/*Ej 5) En un gimnasio, sus actividades para sus socios están en una lista con sublistas en la
que cada nodo representa una actividad o clase, con los siguientes campos:
Código de actividad (0 a 40 - ordenada), Nombre de actividad (cadena de 15), Legajo de
Profesor (0 a 99), Capacidad máxima, Cantidad de socios inscriptos y una SubLista con los
números de socios (0 a 299) inscriptos.
Desarrollar un programa que implemente los siguientes requerimientos, mediante un
subprograma por cada ítem:
a) Generar la lista de ACTIVIDADES (inicialmente vacía) a partir del archivo de texto
CARGAGIM.TXT, hay una actividad por línea, separando cada campo con un espacio. Los
campos son: Codigo Actividad, Nombre Actividad, Legajo Profesor, Capacidad máxima,
Cantidad Inscriptos, y los numeros de socios. Los datos de las actividades vienen ordenados
por código de actividad.
b) En un archivo de texto INSCRIPTOS.TXT (provisto por la cátedra) se tienen los socios que
desean inscribirse a las actividades. Cada línea contiene dos campos Número Socio, Código
Actividad.
Actualizar la lista de ACTIVIDADES desde el archivo considerando: si la actividad ya tiene
su capacidad máxima cubierta o si la actividad no existe, el socio no podrá insertarse en las
sublista y deberá colocarse en una cola Pendientes que contendrá en cada dato: Nro de
Socio, Código de actividad.
c) A partir de la lista de ACTIVIDADES, generar una matriz de 40x300, desde la
lista ACTIVIDADES en la que en la posición [i,j] se almacene un 1 si el número de socio j
hace la actividad i.
d) A partir de la matriz creada en c) obtener y mostrar de forma recursiva los números de
socios que realicen 3 o mas actividades.
e) Dado un número de socio, eliminarlo de la lista ACTIVIDADES (suponer que un socio puede
hacer una o más actividades)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Colas.h"
#define MAXCOL 300
#define MAXFILA 40

typedef struct nodoS{
    int nroSocio;
    struct nodoS *sig;
}nodoS;

typedef nodoS *SubLista;

typedef struct nodoA{
    int codigo;
    char nombre[16];
    int legajoProfesor;
    int capacidadMax;
    int cantInscriptos;

    SubLista sub;

    struct nodoA *sig;
}nodoA;

typedef nodoA *Lista;


void insertarSocio(SubLista *S,int nroSocio);
void insertarActividad(Lista *L,int codigo, char nombre[],int legajo,int capacidad,int cantIns,SubLista sub);

void cargarActividades(Lista *L);
void mostrar(Lista L);

void mostrarPendientes(TCola C);
void actualizarInscriptos(Lista L,TCola *pendientes);
void generarMatriz(Lista L,int M[MAXFILA][MAXCOL]);
void mostrarSociosRec(int M[MAXFILA][MAXCOL],int socio);
void eliminarSocioActividades(Lista *L,int socio);
void eliminarActividad(Lista *L, int codActividad);



int main(){

    Lista L=NULL;

    TCola pendientes;

    int M[MAXFILA][MAXCOL];
    iniciaC(&pendientes);

    cargarActividades(&L);

      actualizarInscriptos(L,&pendientes);

    printf("\nLISTA DE ACTIVIDADES\n");

    mostrar(L);

    printf("\nMOSTRAR COLA DE  PENDIENTES\n");
    mostrarPendientes(pendientes);

    generarMatriz(L,M);

   // printf("\nMATRIZ GENERADA\n");
   // mostrarMatriz(M);

    printf("\nSOCIOS CON 3 O MAS ACTIVIDADES\n");
    mostrarSociosRec(M,0);

    eliminarSocioActividades(&L,180);


    printf("\nLISTA DE ACTIVIDADES ACTUALIZADA\n");
    mostrar(L);

    return 0;
}



void insertarSocio(SubLista *S,int nroSocio){

    nodoS *nuevo,*aux;

    nuevo=(nodoS*)malloc(sizeof(nodoS));

    nuevo->nroSocio=nroSocio;
    nuevo->sig=NULL;

    if(*S==NULL)
        *S=nuevo;
    else{

        aux=*S;

        while(aux->sig!=NULL)
            aux=aux->sig;

        aux->sig=nuevo;
    }
}



void insertarActividad(Lista *L,int codigo, char nombre[],int legajo,int capacidad,int cantIns,SubLista sub){

    nodoA *nuevo,*aux;

    nuevo=(nodoA*)malloc(sizeof(nodoA));

    nuevo->codigo=codigo;
    strcpy(nuevo->nombre,nombre);
    nuevo->legajoProfesor=legajo;
    nuevo->capacidadMax=capacidad;
    nuevo->cantInscriptos=cantIns;
    nuevo->sub=sub;
    nuevo->sig=NULL;

    if(*L==NULL)
        *L=nuevo;
    else{

        aux=*L;

        while(aux->sig!=NULL)
            aux=aux->sig;

        aux->sig=nuevo;
    }
}



void cargarActividades(Lista *L){

    FILE *arch;

    int codigo;
    int legajo;
    int capacidad;
    int cantIns;
    int socio;
    int i;

    char nombre[16];

    SubLista sub;

    *L=NULL;

    arch=fopen("CARGAGIM.TXT","rt");

    if(arch==NULL){

        printf("Error al abrir archivo\n");

    }else{

    while(fscanf(arch,"%d %s %d %d %d",&codigo, nombre,&legajo,&capacidad,&cantIns)==5){

        sub=NULL;

        for(i=0;i<cantIns;i++){

            fscanf(arch,"%d",&socio);

            insertarSocio(&sub,socio);
        }

        insertarActividad(L,codigo, nombre,legajo, capacidad,cantIns,sub);
    }
    }
    fclose(arch);
}


void mostrar(Lista L){

    nodoA *auxA;
    nodoS *auxS;

    auxA=L;

    while(auxA!=NULL){

        printf("\nCodigo: %d",
               auxA->codigo);

        printf("\nActividad: %s",
               auxA->nombre);

        printf("\nLegajo Profesor: %d",
               auxA->legajoProfesor);

        printf("\nCapacidad Maxima: %d",
               auxA->capacidadMax);

        printf("\nCantidad Inscriptos: %d",
               auxA->cantInscriptos);

        printf("\nSocios: ");

        auxS=auxA->sub;

        while(auxS!=NULL){

            printf("%d ",auxS->nroSocio);

            auxS=auxS->sig;
        }

        printf("\n----------------------------------\n");

        auxA=auxA->sig;
    }
}


void mostrarPendientes(TCola C){

    TElementoC dato;

    printf("\nPENDIENTES\n");

    while(!vaciaC(C)){

        sacaC(&C,&dato);

        printf("Socio: %d  Actividad: %d\n",dato.nroSocio,dato.codigoActividad);
    }
}

void actualizarInscriptos(Lista L,TCola *pendientes){

    FILE *arch;

    int socio,codigo;

    nodoA *actividad;

    TElementoC datoCola;

    arch=fopen("INSCRIPTOS.TXT","rt");

    if(arch==NULL){

        printf("Error al abrir archivo\n");

    }else{

    while(fscanf(arch,"%d %d",&codigo,&socio)==2){

        actividad=L;

        while(actividad!=NULL && actividad->codigo!=codigo)

            actividad=actividad->sig;

        if(actividad==NULL ){

            datoCola.nroSocio=socio;
            datoCola.codigoActividad=codigo;

            poneC(pendientes,datoCola);
        }
        else{

            if(actividad->cantInscriptos>= actividad->capacidadMax){

                datoCola.nroSocio=socio;
                datoCola.codigoActividad=codigo;

                poneC(pendientes,datoCola);
            }
            else{

                insertarSocio(&(actividad->sub),
                              socio);

                actividad->cantInscriptos++;
            }
        }
    }
    }
    fclose(arch);
}


void generarMatriz(Lista L,int M[MAXFILA][MAXCOL]){

    int i,j;

    nodoA *auxA;
    nodoS *auxS;

    for(i=0;i<MAXFILA;i++)
        for(j=0;j<MAXCOL;j++)
            M[i][j]=0;

    auxA=L;

    while(auxA!=NULL){

        auxS=auxA->sub;

        while(auxS!=NULL){

            M[auxA->codigo][auxS->nroSocio]=1;

            auxS=auxS->sig;
        }

        auxA=auxA->sig;
    }
}

void mostrarMatriz(int M[MAXFILA][MAXCOL]){

    int i,j;

    printf("\nMATRIZ ACTIVIDADES - SOCIOS\n\n");

    for(i=0;i<MAXFILA;i++){

        printf("Actividad %2d: ",i);

        for(j=0;j<MAXCOL;j++){

            printf("%d ",M[i][j]);
        }

        printf("\n");
    }
}

void mostrarSociosRec(int M[MAXFILA][MAXCOL],int socio){

    int i;
    int contador=0;

    if(socio < 300){ // Se corta cuando es menor a 300

        for(i=0;i<MAXFILA;i++)
            if(M[i][socio]==1)
                contador++;

        if(contador>=3)
            printf("Socio %d realiza %d actividades\n",socio,contador);

        mostrarSociosRec(M,socio+1);
    }
}


void eliminarSocioActividades(Lista *L,int socio){

    nodoA *auxA;
    nodoS *act,*ant;

    auxA=*L;

    while(auxA!=NULL){

        act=auxA->sub;
        ant=NULL;

        while(act!=NULL && act->nroSocio>socio){

            ant=act;
            act=act->sig;
        }

        if(act!=NULL && act->nroSocio == socio ){ // encontró el socio

            if(ant==NULL)
                auxA->sub=act->sig;
            else
                ant->sig=act->sig;

            free(act);

            auxA->cantInscriptos--;
        }

        auxA=auxA->sig;
    }
}


void eliminarActividad(Lista *L, int codActividad)
{
    nodoA *act, *ant;
    nodoS *auxS;

    act = *L;
    ant = NULL;

    // Buscar la actividad
    while(act != NULL && act->codActividad != codActividad)
    {
        ant = act;
        act = act->sig;
    }

    // Si la encontró
    if(act != NULL)
    {
        // Eliminar toda la sublista de socios
        while(act->sub != NULL)
        {
            auxS = act->sub;
            act->sub = act->sub->sig;
            free(auxS);
        }

        // Si la actividad está al principio
        if(ant == NULL)
            *L = act->sig;
        else
            ant->sig = act->sig;

        // Liberar el nodo actividad
        free(act);
    }
}
