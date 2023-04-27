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
 i) printf("%d", pt1.Edad);
ii) printf("%s", pt1->sig->Nombre);
iii) pt1->sig = pt1;
iv) pt2->sig = pt1->sig;
v) pt1->Nombre = pt1->sig->Nombre;*/

#include<stdio.h>


typedef struct {
 char Nombre[21];
 int Edad;
 } strPersona;
 typedef strPersona * ptPersona;


void main() {
    char Joven[21];
    ptPersona Persona1 = (ptPersona) malloc(sizeof(strPersona)); // Creo memoria para lo que se va a guardar en ese puntero
    ptPersona Persona2 = (ptPersona) malloc(sizeof(strPersona));
    printf("Ingrese el nombre y la edad de la primera persona \n");
    fflush(stdin);
    gets(Persona1->Nombre); //P1.(*)nombre
    fflush(stdin);
    scanf("%d",&Persona1->Edad);
    printf("Ingrese el nombre y la edad de la segunda persona \n");
    fflush(stdin);
    gets(Persona2->Nombre);
    fflush(stdin);
    scanf("%d",&Persona2->Edad);
    strcpy(Joven,((Persona1->Edad>Persona2->Edad)?Persona2->Nombre:Persona1->Nombre)); // se guarda en joven el resultado
    printf("El mas joven sera: %s",Joven);
    free(Persona1);
    free(Persona2);
}
