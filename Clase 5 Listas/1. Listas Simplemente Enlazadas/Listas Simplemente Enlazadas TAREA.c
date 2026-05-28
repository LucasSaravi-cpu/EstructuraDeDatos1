/*TAREAS*/







/*1) Dada una lista simplemente enlazada de enteros, sumar el valor de los K primeros nodos*/

int suma (TlistaE L , int k ) {
	int suma =0;
	int i=0;
	
	TlistaE aux;
	aux=L;
	
	while ( aux!=NULL && i<k) {
	     suma += aux->dato;
         aux = aux->sig;
         i++;
	}
return suma ;	
		
	}
	
/*2) Dada una lista de enteros modificar cada aparición de X por X+1*/

void remplazar (Tlista L , int x ) {
	
Tlista aux =L;

while ( aux!=NULL ) {
   if (aux -> dato == x ) 
	   (aux->)++;
   aux = aux -> sig;
}	
	
}


/*3) Destruir una lista simplemente enlazada*/

void DestruirLista ( Tlista *L) {

Tlista aux;

while ( *L!=NULL ) {
	
	aux = *L ;
	*L = (*L)->sig;
	free(aux);
}

}


/*4) Eliminar todas las apariciones de X de una lista simplemente enlazada de enteros ORDENADA*/

void eliminaE(TListaE *L, int x){

    TListaE ant, act;

    if (*L != NULL)

        /* IMPORTANTE:
           siempre hay que verificar
           si el nodo está al principio */

        while (*L != NULL && (*L)->dato == x){
            act = *L;
            *L = (*L)->sig;
            free(act);
        }

    if (*L != NULL){

        ant = *L;
        act = (*L)->sig;

        while (act != NULL && act->dato <= x){

            if (act->dato == x){

                ant->sig = act->sig;
                free(act);

                act = ant->sig;
            }
            else{
                ant = act;
                act = act->sig;
            }
        }
    }
}

/*5) Eliminar todas las apariciones de X de una lista simplemente enlazada ordenada de enteros SIN ORDENAR */
void eliminaE(TListaE *L, int x){

    TListaE ant, act;

    if (*L != NULL)

        /* IMPORTANTE:
           siempre hay que verificar
           si el nodo está al principio */

        while (*L != NULL && (*L)->dato == x){
            act = *L;
            *L = (*L)->sig;
            free(act);
        }

    if (*L != NULL){

        ant = *L;
        act = (*L)->sig;

        while (act != NULL){

            if (act->dato == x){

                ant->sig = act->sig;
                free(act);

                act = ant->sig;
            }
            else{
                ant = act;
                act = act->sig;
            }
        }
    }
}


/*/*DIFERENCIAS ENTRE LOS EJERCICIOS 4 Y 5

En la lista ORDENADA el recorrido se realiza
hasta encontrar un valor mayor que X, porque
a partir de ese momento ya se sabe que no
pueden existir más apariciones de X.

En cambio, en la lista SIN ORDENAR es necesario
recorrer toda la lista, ya que X puede aparecer
en cualquier posición.

Además, al comienzo se utiliza un while para
verificar si existen varias apariciones consecutivas
de X en la cabeza de la lista y eliminarlas todas.
*/

/*6) Dada una lista de cadenas eliminar los nodos que contengan cadenas que comiencen con vocal, informar cuantos se han eliminado*/

int eliminarVocales(TListaC *L){

    TListaC ant, act;
    int cont = 0;

    while (*L != NULL &&
          ((*L)->cad[0] == 'a' || (*L)->cad[0] == 'e' ||
           (*L)->cad[0] == 'i' || (*L)->cad[0] == 'o' ||
           (*L)->cad[0] == 'u' || (*L)->cad[0] == 'A' ||
           (*L)->cad[0] == 'E' || (*L)->cad[0] == 'I' ||
           (*L)->cad[0] == 'O' || (*L)->cad[0] == 'U')){

        act = *L;
        *L = (*L)->sig;

        free(act);
        cont++;
    }

    if (*L != NULL){

        ant = *L;
        act = (*L)->sig;

        while (act != NULL){

            if (act->cad[0] == 'a' || act->cad[0] == 'e' ||
                act->cad[0] == 'i' || act->cad[0] == 'o' ||
                act->cad[0] == 'u' || act->cad[0] == 'A' ||
                act->cad[0] == 'E' || act->cad[0] == 'I' ||
                act->cad[0] == 'O' || act->cad[0] == 'U'){

                ant->sig = act->sig;

                free(act);

                act = ant->sig;

                cont++;
            }
            else{
                ant = act;
                act = act->sig;
            }
        }
    }

    return cont;
}
