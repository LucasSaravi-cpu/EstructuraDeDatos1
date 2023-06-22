#ifndef PILAS_H_INCLUDED
#define PILAS_H_INCLUDED
typedef int ElementoP;//tipo de dato que la pila almacena
typedef struct nodop{//le doy un nombre "nodop" al struct, asi puedo tener dentro una variable de ese mismo tipo
ElementoP dato; //el dato que se almacena en cada nodo que se cree
struct nodop *sig; // puntero a otro nodop, que debera apuntar siempre al nodo que le sigue
} nodop;//nombre del struct
typedef nodop *TPila;//otro puntero a nodop, pero el mas importante, ya que este representa la pila, siendo la cabeza
//es decir, el puntero que apunta al ultimo nodo creado
#endif // PILAS_H_INCLUDED

