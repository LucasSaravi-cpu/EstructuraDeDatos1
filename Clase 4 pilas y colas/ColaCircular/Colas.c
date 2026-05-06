#include "Colas.h"
#include <stdio.h>
#include <stdlib.h>

void iniciaC (TCola *C) { 
 (*C).pri = (*C).ult =-1; 
} 
int vaciaC(TCola C){ 
  return C.pri == -1; 
} 


void poneC (TCola *C, TElementoC dato) { 
   if  (!(*C).ult == MAX-1 && (*C).pri==0 || (*C).ult+1==(*C).pri) { // no llena 
     if ((*C).pri==-1)   //vacia 
       (*C).pri =  (*C).ult = 0; 
     else 
      if ((*C).ult == MAX-1)   
          (*C).ult = 0; 
      else 
           (*C).ult += 1; 
    (*C).datos[(*C).ult]=dato; 
  } 
} 
void sacaC (TCola *C, TElementoC *dato) { 
  if ((*C).pri != -1) {     
     *dato = (*C).datos[(*C).pri]; 
    if ((*C).pri == (*C).ult) 
       iniciaC(C); 
    else 
      if ((*C).pri == MAX-1)   
          (*C).pri = 0; 
      else 
           (*C).pri += 1; 
  } 
}


TElementoC consultaC (TCola C){ 
if (C.pri !=-1) 
   return C.dato[C.pri]; 
} 
