/*En esta estructura cada nodo almacena la dirección del nodo siguiente y del nodo anterior. Esto permite recorrer la lista en ambos sentidos.


      Cada nodo almacena:
      +------+------+------+
<-----| Ant  | Dato | Sig | ----->
      +------+------+------+


Se debe mantener la dirección del primer nodo y del último para acceder a la lista, por el principio y por el final
      aux->ant       aux->sig
      +------+------+------+ +------+ +------+
<-----| 2    | 6    |   12 | |  18  | | 30   |        
      +------+------+------+ +------+ +------+
       |        |                        |
	   |		|                        |
	   |		v                        |
	   |	   aux                       | 
       |                                 |
	   |  +------+------+                |
       -> |  pri | ult  |   <------------|       
          +------+------+

Donde:

ant apunta al nodo anterior.
sig apunta al nodo siguiente.

LD
+------+------+
| Pri  | Ult  |
+------+------+
   |       |
   v       v
 [2] ... [30]
 
pri apunta al primer nodo (2).
Ult apunta al último nodo (30).


*/

typedef struct nodo {
    int num;
    struct nodo *sig;
} nodo;

typedef struct nodo *TLista;

typedef struct nodoD {
    int num;
    struct nodoD *ant, *sig;
} nodoD;

typedef struct nodoD *PnodoD;

typedef struct {
    PnodoD pri, ult;
} TListaD;


void arma(TListaD *LD, TLista L) {
    TLista aux;
    PnodoD nuevo, act;

    aux = L;
    (*LD).pri = NULL;
    (*LD).ult = NULL;

    while (aux != NULL) {
        nuevo = (PnodoD) malloc(sizeof(nodoD));
        nuevo->num = aux->num;

        if ((*LD).pri == NULL || nuevo->num < (*LD).pri->num) {
            nuevo->sig = (*LD).pri;
            nuevo->ant = NULL;

            if ((*LD).pri == NULL)
                (*LD).ult = nuevo;
            else
                (*LD).pri->ant = nuevo;

            (*LD).pri = nuevo;
        }
        else
            if (nuevo->num > (*LD).ult->num) {
                nuevo->ant = (*LD).ult;
                nuevo->sig = NULL;

                (*LD).ult->sig = nuevo;
                (*LD).ult = nuevo;
            }
            else {
                act = (*LD).pri;

                while (nuevo->num > act->num)
                    act = act->sig;

                nuevo->sig = act;
                nuevo->ant = act->ant;

                act->ant->sig = nuevo;
                act->ant = nuevo;
            }

        aux = aux->sig;
    }
}

void eliminaVarios(TListaD *LD) {
    PnodoD elim, act;

    if ((*LD).pri != NULL) {
        act = (*LD).pri->sig;

        while (act != NULL)
            if (act->num % 2 == act->ant->num % 2) {
                elim = act;
                act = act->sig;

                if (elim->sig == NULL) {
                    (*LD).ult = elim->ant;
                    (*LD).ult->sig = NULL;
                }
                else {
                    elim->ant->sig = elim->sig;
                    elim->sig->ant = elim->ant;
                }

                free(elim);
            }
            else
                act = act->sig;
    }
}