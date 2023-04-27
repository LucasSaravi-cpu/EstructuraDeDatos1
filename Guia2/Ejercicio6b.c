/*Ej 6.-
a.- Desarrollar un programa que lea los datos de dos personas, en variables dinámicas (tipo
struct), y muestre el nombre del más joven. Utilizar las siguientes declaraciones que deben estar
en un archivo tipos.h:
 typedef struct {
 char Nombre[21];
 int Edad;
 } strPersona;
 typedef strPersona * ptPersona;
Facultad de Ingeniería – Universidad FASTA
Estructuras de Datos

b.- Modificar el tipo strPersona del inciso a.- agregando un campo sig de tipo puntero a
strPersona.
Enlazar pt1 con pt2, haciendo que pt2 sea el siguiente de pt1 y que pt2 no tenga siguiente.



c.- Dados los datos cargados en a.- y los enlaces efectuados en b.-, indicar si son correctas o no
las siguientes sentencias y en caso de ser correctas indicar el efecto que producen:

 i) printf("%d", pt1.Edad); No es incorrecto ya que es un puntero a una variable tipo struct por lo que deberia ser pt1->Edad

ii) printf("%s", pt1->sig->Nombre); Es correcto se escribiria el puntero nombre siguiente a ese

iii) pt1->sig = pt1; se apuntaria a si mismo

iv) pt2->sig = pt1->sig;   funconaria en caso de que pt2 sea distinta de null

v) pt1->Nombre = pt1->sig->Nombre;  para igualarlas se tiene que usar strcpy , se iguala el puntero a nombre con el siguiente puntero a nombre

*/


#include<stdio.h>
#include<string.h>
#include "Ejercicio6.h" //""porque esta en la misma carpeta del .c
void main() {
    char Joven[21];
    ptPersona Persona1 = (ptPersona) malloc(sizeof(strPersona));
    ptPersona Persona2 = (ptPersona) malloc(sizeof(strPersona));
    Persona1->sig = Persona2; // enlazar
    Persona2->sig = NULL; // No tiene siguiente persona2
    printf("Ingrese el nombre y luego la edad de la persona 1 \n");
    fflush(stdin);
    gets(Persona1->Nombre);
    fflush(stdin);
    scanf("%d",&Persona1->Edad);
    printf("Ingrese el nombre y luego la edad de la persona 2 \n");
    fflush(stdin);
    gets(Persona2->Nombre);
    fflush(stdin);
    scanf("%d",&Persona2->Edad);
    strcpy(Joven,((Persona1->Edad>Persona2->Edad)?Persona2->Nombre:Persona1->Nombre));
    printf("El mas joven sera: %s \n",Joven);

    free(Persona1);
    free(Persona2);
}
