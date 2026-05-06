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
   if ((*C).ult != MAX-1) {       // no llena 
     if ((*C).pri==-1) 
       (*C).pri = 0; 
    (*C).ult += 1; 
    (*C).datos[(*C).ult]=dato; 
  } 
} 
void sacaC (TCola *C, TElementoC *dato) { 
  if ((*C).pri != -1) {      // !vaciaC(*C) 
     *dato = (*C).datos[(*C).pri]; 
    if ((*C).pri == (*C).ult) 
       iniciaC(C); 
    else 
       (*C).pri +=1; 
  } 
} 
TElementoC consultaC (TCola C){ 
if (C.pri !=-1) 
   return C.dato[C.pri]; 
} 
