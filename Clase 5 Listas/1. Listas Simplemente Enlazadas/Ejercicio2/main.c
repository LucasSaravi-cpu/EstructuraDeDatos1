/*Ej 2.- Suponer que la lista del ejercicio anterior no se encuentra ordenada por ningún criterio.
Rehacer los siguientes incisos: d.- ii) y e.- ii) */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct nodo{
    char nombreyapellido[30];
    int dni;
    int edad;

    struct nodo *sig;
}Nodo;

typedef Nodo* Lista;

void cargarLista(Lista *L);
void mostrarLista(Lista L);
void eliminarPosicion(Lista *L, int posicion);
void eliminarDNI(Lista *L, int dniBuscado);



int main()
{
    Lista L = NULL;

    int N;


    cargarLista(&L);
    printf("\nLISTA DE PERSONAS \n");

    mostrarLista(L);


   eliminarPosicion(&L,3);
   eliminarDNI(&L ,31587412);

    printf("\nLISTA DE PERSONAS CON MODIFICACIONES \n");

    mostrarLista(L);
    return 0;
}





void cargarLista(Lista *L){

    char nombreyapellido[30];
    int dni;
    int edad;

    FILE *arch;

    Lista nuevo, ult = NULL;

    arch = fopen("Ejercicio2.txt","r");

    if(arch == NULL){

        printf("Error al abrir archivo");

    } else{

    while(fscanf(arch,"%s %d %d",nombreyapellido,&dni,&edad) == 3){

        nuevo = (Nodo*)malloc(sizeof(Nodo));

        strcpy(nuevo->nombreyapellido, nombreyapellido);
        nuevo->dni = dni;
        nuevo->edad = edad;

        nuevo->sig = NULL;

        if(*L == NULL){

            *L = nuevo;
            ult = nuevo;
        }
        else{

            ult->sig = nuevo;
            ult = nuevo;
        }
    }
    }
    fclose(arch);
}



void mostrarLista(Lista L){

    while(L != NULL){



        printf("\nNombre y apellido: %s",L->nombreyapellido);

        printf("\nDNI: %d", L->dni);

        printf("\nEdad: %d\n", L->edad);



        L = L->sig;
    }
}




void eliminarPosicion(Lista *L, int posicion){

    Lista act = *L;
    Lista  ant = NULL;

    int i = 1;

    while(act != NULL && i != posicion){

        ant = act;
        act = act->sig;
        i++;
    }

    if(act != NULL && i==posicion ){

        if(ant == NULL)
            *L = act->sig;
        else
            ant->sig = act->sig;

        free(act);

    }
}


void eliminarDNI(Lista *L, int dniBuscado){

    Lista act = *L;
    Lista  ant = NULL;

    while(act != NULL && act->dni != dniBuscado){

        ant = act;
        act = act->sig;
    }

    if(act != NULL && dniBuscado  == act->dni ){

        if(ant == NULL)
            *L = act->sig;
        else
            ant->sig = act->sig;

        free(act);

    }
}
