#include "Pilas.h"
#include <stdio.h>
#include <stdlib.h>

void poneP( TPila *P, ElementoP x) { 
   if ( ((*P).tope) != MAX-1)   
       (*P).datos[++((*P).tope)] = x;  
} 
void sacaP(TPila *P, ElementoP* x)  { 
  if (((*P).tope) != -1) 
        (*x) = (*P).datos[((*P).tope)--]; 
} 
ElementoP consultaP(TPila P)  { 
  if ((P.tope) != -1) 
        return P.datos[P.tope]; 
} 
 
int VaciaP(TPila P)  { 
  return (P.tope == -1);   
} 
void IniciaP (TPila *P) { 
 (*P).tope=-1;   
} 
