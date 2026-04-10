/*a) Desarrollar un programa que lea los datos de dos personas, en variables dinámicas (tipo 
struct), y muestre el nombre del más joven. Utilizar las siguientes declaraciones que deben 
estar en el archivo tipos.h: 
typedef struct { 
char Nombre[21]; 
int  
Edad; 
} strPersona; 
typedef strPersona * ptPersona; 
b) Modificar el tipo strPersona del inciso a.- agregando un campo sig de tipo puntero a 
strPersona.  
Enlazar pt1 con pt2, haciendo que pt2 sea el siguiente de pt1 y que pt2 no tenga           
siguiente. 
c) Dados los datos cargados en a.- y los enlaces efectuados en b.-, indicar si son correctas o 
no las siguientes sentencias y en caso de ser correctas indicar el efecto que producen: 
i. printf("%d", pt1.Edad); 
ii.  printf("%s", pt1->sig->Nombre);
iii. pt1->sig = pt1; 
iv. pt2->sig = pt1->sig; 
v. pt1->Nombre = pt1->sig->Nombre;*/


#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"

int main() {
    ptPersona pt1, pt2;

    pt1 = (ptPersona) malloc(sizeof(strPersona)); // Se reserva memoria para el puntero
    pt2 = (ptPersona) malloc(sizeof(strPersona));

    printf("Persona 1:\n");
    printf("Nombre: ");
    scanf("%s", pt1->Nombre);
    printf("Edad: ");
    scanf("%d", &pt1->Edad);

    printf("\nPersona 2:\n");
    printf("Nombre: ");
    scanf("%s", pt2->Nombre);
    printf("Edad: ");
    scanf("%d", &pt2->Edad);


    //Se enlasa Ejercicio B
    /*pt1->sig = pt2;
    pt2->sig = NULL;*/

    if (pt1->Edad < pt2->Edad) {
        printf("El mas joven es: %s\n", pt1->Nombre);
    } else {
        printf("El mas joven es: %s\n", pt2->Nombre);
    }

    //printf("\nAccediendo al siguiente de pt1: %s\n", pt1->sig->Nombre);

    free(pt1);
    free(pt2);

    return 0;
}



/*Ejercicio C

i) printf("%d", pt1.Edad); incorrecta pt1 es puntero → se usa ->, no . Correcta : printf("%d", pt1->Edad);
ii)printf("%s", pt1->sig->Nombre); es correcta accede al siguiente nodo ( pt2 ) imprime su nombre
iii)pt1->sig = pt1; Correcta pt1 se aputa a si mismo se genera una lista circular de un solo nodo puede provocar bocles infinitos si recorres la lista 
iv)pt2->sig = pt1->sig; pt2->sig pasa a apuntar a lo mismo que pt1->sig
v)pt1->Nombre = pt1->sig->Nombre; incorrecta no se puede asigar arrays en c directamente Correcto strcpy(pt1->Nombre, pt1->sig->Nombre);
 */
