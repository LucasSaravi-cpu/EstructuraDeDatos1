
/*Se tiene un conjunto de datos referidos a las ganancias mensuales de un
grupo de contribuyentes de la AFIP en el término de un año. Los datos se encuentran
almacenados en una estructura de lista enlazada con sublistas. En las listas se encuentran
almacenados sólo los nros. y nombres de aquellos contribuyentes que tuvieron ganancias en
al menos uno de los meses del año (ordenada por nro de contribuyente) Se tiene para cada
contribuyente, una sublista (ordenada por mes de ganancia) en la que cada uno de los nodos
 almacena el mes en que obtuvo la ganancia y el monto de la misma.

 Se pide:
 a.- Eliminar los datos de un número de contribuyente dado (es válido).
 b.- Insertar datos referidos a la ganancia mensual
de un determinado contribuyente (suponer que el contribuyente puede no existir) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodoS{
    int mes;
    float ganancia;
    struct nodoS *sig;
}nodoS;

typedef nodoS *SubLista;

typedef struct nodoP{
    int nro;
    char nombre[30];
    SubLista sub;
    struct nodoP *sig;
}nodoP;

typedef nodoP *Lista;


void insertarMesOrdenado(SubLista *S,int mes,float ganancia);
void insertarContribuyente(Lista *L,int nro,char nombre[],int mes,float ganancia);
void cargarDesdeArchivo(Lista *L);
void mostrar(Lista L);
void eliminarContribuyente(Lista *L,int nro);
void insertarGanancia(Lista *L);


int main(){

    Lista L=NULL;
    int nro;

    cargarDesdeArchivo(&L);

    printf("\nLISTA ORIGINAL\n");
    mostrar(L);

    printf("\nNumero de contribuyente a eliminar: ");
    scanf("%d",&nro);

    eliminarContribuyente(&L,nro);

    printf("\nLISTA LUEGO DE ELIMINAR\n");
    mostrar(L);

    printf("\nINSERTAR NUEVA GANANCIA\n");
    insertarGanancia(&L);

    printf("\nLISTA FINAL\n");
    mostrar(L);

    return 0;
}


void insertarMesOrdenado(SubLista *S,int mes,float ganancia){

    nodoS *nuevo,*act,*ant;

    nuevo=(nodoS*)malloc(sizeof(nodoS));

    nuevo->mes=mes;
    nuevo->ganancia=ganancia;

    act=*S;
    ant=NULL;

    while(act!=NULL && act->mes<mes){
        ant=act;
        act=act->sig;
    }

    nuevo->sig=act;

    if(ant==NULL)
        *S=nuevo;
    else
        ant->sig=nuevo;
}


void insertarContribuyente(Lista *L,int nro,char nombre[],int mes,float ganancia){

    nodoP *nuevo,*act,*ant;

    act=*L;
    ant=NULL;

    while(act!=NULL && act->nro<nro){
        ant=act;
        act=act->sig;
    }

    if(act!=NULL && act->nro==nro){

        insertarMesOrdenado(&(act->sub),mes,ganancia);
    }
    else{

        nuevo=(nodoP*)malloc(sizeof(nodoP));

        nuevo->nro=nro;
        strcpy(nuevo->nombre,nombre);
        nuevo->sub=NULL;

        insertarMesOrdenado(&(nuevo->sub),mes,ganancia);

        nuevo->sig=act;

        if(ant==NULL)
            *L=nuevo;
        else
            ant->sig=nuevo;
    }
}



void cargarDesdeArchivo(Lista *L){

    FILE *arch;

    int nro,mes;
    float ganancia;
    char nombre[30];

    *L=NULL;

    arch=fopen("Ejercicio8.txt","rt");

    if(arch==NULL){
        printf("Error al abrir archivo\n");

    }else{

    while(fscanf(arch,"%d %s %d %f",&nro,nombre,&mes,&ganancia)==4){

        printf("%d %s %d %.2f\n",nro,nombre,mes,ganancia);

        insertarContribuyente(L,nro,nombre,mes,ganancia);
    }
    }
    fclose(arch);
}

void mostrar(Lista L){

    nodoP *auxP;
    nodoS *auxS;

    auxP=L;

    while(auxP!=NULL){

        printf("\nContribuyente: %d %s\n",auxP->nro,auxP->nombre);

        auxS=auxP->sub;

        while(auxS!=NULL){

            printf("Mes: %d  Ganancia: %.2f\n",auxS->mes,auxS->ganancia);

            auxS=auxS->sig;
        }

        auxP=auxP->sig;
    }
}

void eliminarContribuyente(Lista *L,int nro){

    nodoP *elim,*act,*ant;
    nodoS *aux;

    act=*L;
    ant=NULL;

    while(act!=NULL && act->nro!=nro){

        ant=act;
        act=act->sig;
    }

    if(act!=NULL){

        aux=act->sub;

        while(aux!=NULL){

            nodoS *bor=aux;
            aux=aux->sig;
            free(bor);
        }

        elim=act;

        if(ant==NULL)
            *L=act->sig;
        else
            ant->sig=act->sig;

        free(elim);
    }
}



void insertarGanancia(Lista *L){

    int nro,mes;
    float ganancia;
    char nombre[30];

    printf("Numero contribuyente: ");
    scanf("%d",&nro);

    printf("Nombre: ");
    scanf("%s",nombre);

    printf("Mes: ");
    scanf("%d",&mes);

    printf("Ganancia: ");
    scanf("%f",&ganancia);

    insertarContribuyente(L,nro,nombre,mes,ganancia);
}



