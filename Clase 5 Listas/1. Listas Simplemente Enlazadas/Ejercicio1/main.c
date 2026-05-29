/*Ej 1.- Considerar una lista simplemente enlazada en memoria dinámica cuyos nodos:
✓ NOMBRE y APELLIDO
✓ DNI
✓ EDAD
 { cadena, ordenada por éste campo }
Desarrollar subprogramas para:
a.- Recorrer la lista y mostrar el contenido de las personas cuya edad sea mayor a 20.
b.- Dados los datos de una persona, insertarla en orden con respecto al DNI
c.- Crear una lista para almacenar la información de N personas. Utilizar el subprograma desarrollado en el inciso b.-
d.- Modificar en un nodo el campo EDAD
i) recibiendo la posición del nodo
ii) conociendo el DNI del dato a modificar
e.- Eliminar un nodo
i) recibiendo la posición del nodo a eliminar
 ii) recibiendo el DNI del dato a eliminar*/

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
void insertarOrdenado(Lista *L, char nombreyapellido[],int dni,int edad);
void modificarEdadDNI(Lista L, int dniBuscado, int nuevaEdad);
void modificarEdadPosicion(Lista L, int posicion, int nuevaEdad);
void eliminarPosicion(Lista *L, int posicion);
void eliminarDNI(Lista *L, int dniBuscado);



// Al recorrer una lista usando posiciones, normalmente se utiliza:
//
// while(i < posicion)
//
// porque significa:
// "mientras todavía no llegué a la posición buscada".
//
// Cuando i == posicion, el puntero ya está ubicado
// en el nodo correcto y el recorrido debe detenerse.
//
// Si se utilizara:
//
// while(i <= posicion)
//
// el ciclo seguiría avanzando incluso estando en
// la posición buscada, provocando que el puntero
// avance un nodo más y se pase de la posición deseada.
int main()
{
    Lista L = NULL;

    int N;


    cargarLista(&L);
    printf("\nLISTA DE PERSONAS \n");

    mostrarLista(L);

   modificarEdadPosicion(L,2,32);
   modificarEdadDNI(L,43125784,32);
   eliminarPosicion(&L,3);
   eliminarDNI(&L ,31587412);

    printf("\nLISTA DE PERSONAS CON MODIFICACIONES \n");

    mostrarLista(L);
    return 0;
}




/*c.- Crear una lista para almacenar la información de N personas. Utilizar el subprograma desarrollado en el inciso b.-*/

void cargarLista(Lista *L){

    char nombreyapellido[30];
    int dni;
    int edad;
    FILE* arch;
    arch = fopen("Ejercicio1.txt","r");

     while(!feof(arch)) {
        fscanf(arch,"%s %d %d",nombreyapellido,&dni,&edad);
       insertarOrdenado(L, nombreyapellido, dni, edad);
    }

}


/*a.- Recorrer la lista y mostrar el contenido de las personas cuya edad sea mayor a 20.*/

void mostrarLista(Lista L){

    while(L != NULL){

        if ( L->edad>20) {

        printf("\nNombre y apellido: %s",L->nombreyapellido);

        printf("\nDNI: %d", L->dni);

        printf("\nEdad: %d\n", L->edad);

        }

        L = L->sig;
    }
}

/*b.- Dados los datos de una persona, insertarla en orden con respecto al DNI*/
void insertarOrdenado(Lista *L, char nombreyapellido[],int dni,int edad){

    Nodo *nuevo = (Nodo*) malloc(sizeof(Nodo));

    strcpy(nuevo->nombreyapellido, nombreyapellido);
    nuevo->dni = dni;
    nuevo->edad = edad;

    Nodo *ant = NULL;
    Nodo *act = *L;

    while(act != NULL && act->dni < dni){

        ant = act;
        act = act->sig;
    }

    nuevo->sig = act;

    if(ant == NULL) // Cabeza
        *L = nuevo;
    else
        ant->sig = nuevo;
}

/*d.- Modificar en un nodo el campo EDAD
i) recibiendo la posición del nodo*/



void modificarEdadPosicion(Lista L, int posicion, int nuevaEdad){

    int i = 1;
    Lista aux = L;

    while(aux != NULL && i < posicion){

        aux = aux->sig;
        i++;
    }

    if(aux != NULL && posicion ==i ){

        aux->edad = nuevaEdad;

   }
}

/*ii) conociendo el DNI del dato a modificar*/

void modificarEdadDNI(Lista L, int dniBuscado, int nuevaEdad){


     Lista aux = L;

    while(aux != NULL && aux->dni<dniBuscado){

        aux = aux->sig;
    }

    if(aux != NULL && aux->dni == dniBuscado){

        aux->edad = nuevaEdad;


}

}
/*
/*e.- Eliminar un nodo
i) recibiendo la posición del nodo a eliminar*/


void eliminarPosicion(Lista *L, int posicion){

    Lista act = *L;
    Lista  ant = NULL;

    int i = 1;

    while(act != NULL && i < posicion){

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
 /*ii) recibiendo el DNI del dato a eliminar*/

void eliminarDNI(Lista *L, int dniBuscado){

    Lista act = *L;
    Lista  ant = NULL;

    while(act != NULL && act->dni <dniBuscado){

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
