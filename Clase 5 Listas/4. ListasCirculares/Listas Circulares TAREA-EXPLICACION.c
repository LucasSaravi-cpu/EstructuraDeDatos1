/*Listas Circulares

En esta estructura, el último nodo está vinculado con el primero, permitiendo acceder a cualquier nodo independientemente de dónde se parta.

Ejemplo de dos listas con 5 y 1 nodos respectivamente.

Dibujo (representación)

Lista circular con 5 nodos:

  +---------------------------------------+
  |                                       ¦
  v                                       ¦
+---+   +---+   +----+   +----+   +----+  |  
| 2 |-->| 6 |-->| 12 |-->| 18 |-->| 30 |--+
+---+   +---+   +----+   +----+   +----+
                                    ?
                                    ¦
                                   LC
								   

Lista circular con 1 nodo:

+----+
¦ 30 ¦
+----+
(mismo nodo)
 LC
	
LC almacena la dirección del último nodo, este en su campo 
siguiente contiene la dirección del primer nodo de la lista ordenada.

Mantener la dirección del último, en lugar del primero, permite insertar al final de la lista sin tener que recorrerla. Para insertar al comienzo se recurre al último nodo 
y se modifica su campo siguiente con la dirección del nodo nuevo.


1) Mostrar el contenido de una lista circular 
TIPO DE DATOS 
typedef struct nodo{ 
     int dato; 
     struct nodo * sig;} nodo; 
     typedef nodo * TListaC; 
	 
	 */
	 
void mostrarLista(TListaC LC)
{
    TListaC aux;

    if (LC == NULL)
        printf("Lista vacia\n");
    else
    {
        aux = LC->sig;   // primer nodo

        do
        {
            printf("%d ", aux->dato);
            aux = aux->sig;
        }
        while (aux != LC->sig);

        printf("\n");
    }
}
	 
/*	 
Ej) Se tiene una lista circular que almacena palabras (ordenada por este criterio) y cantidad de 
apariciones de cada una de ellas.  
a) (SOLUCION EN VIDEO) Insertar una palabra en la lista. 
b) Eliminar una aparición de una palabra 
TIPO DE DATOS 
 typedef struct nodo { 
     int cant; 
     char palabra [15]; 
     struct nodo * sig;} nodo; 
 typedef nodo * TListaC; */
 
 a) void insertaPal (TListaC *LC, char *cad)
{
    TListaC nuevo, aux, ant;

    nuevo = (TListaC) malloc(sizeof(nodo));
    strcpy(nuevo->palabra, cad);
    nuevo->cant = 1;

    if ((*LC) == NULL)
    {
        (*LC) = nuevo;
        nuevo->sig = nuevo;
    }
    else
    {
        if (strcmp(cad, (*LC)->palabra) > 0)
        {
            nuevo->sig = (*LC)->sig;
            (*LC)->sig = nuevo;
            (*LC) = nuevo;
        }
        else
        {
            ant = *LC;
            aux = (*LC)->sig;

            while (strcmp(cad, aux->palabra) > 0)
            {
                ant = aux;
                aux = aux->sig;
            }

            if (strcmp(cad, aux->palabra) == 0)
            {
                free(nuevo);
                aux->cant++;
            }
            else
            {
                ant->sig = nuevo;
                nuevo->sig = aux;
            }
        }
    }
}	 
	 
 
 void eliminaPal(TListaC *LC, char *cad)
{
    TListaC aux, ant;

    if (*LC != NULL)
    {
        ant = *LC;
        aux = (*LC)->sig;

        while ((aux != *LC) && strcmp(cad, aux->palabra) > 0)
        {
            ant = aux;
            aux = aux->sig;
        }

        if (strcmp(cad, aux->palabra) == 0)
        {
            if (aux->cant > 1)
            {
                aux->cant--;
            }
            else
            {
                if (aux == ant) // único nodo
                {
                    *LC = NULL;
                }
                else
                {
                    ant->sig = aux->sig;

                    if (aux == *LC) // era el último
                        *LC = ant;
                }

                free(aux);
            }
        }
    }
}
 
 
 
/*Ej 3.- Dada una lista circular de enteros, eliminar X, si existe. */


void eliminarX(TListaC *LC, int X)
{
    TListaC aux, ant;

    if (*LC != NULL)
    {
        ant = *LC;
        aux = (*LC)->sig;

        while ((aux != *LC) && (aux->dato != X))
        {
            ant = aux;
            aux = aux->sig;
        }

        if (aux->dato == X)
        {
            if (aux == ant) // único nodo
            {
                *LC = NULL;
            }
            else
            {
                ant->sig = aux->sig;

                if (aux == *LC) // se elimina el último
                    *LC = ant;
            }

            free(aux);
        }
    }
}