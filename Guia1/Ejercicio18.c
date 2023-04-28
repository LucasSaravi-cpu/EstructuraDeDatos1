/*Ej 17 – Desarrollar una función que pase la primera letra a mayúscula de cada palabra de una
cadena de caracteres. Ejemplo “calle jujuy 1085 6 a” pasa a “Calle Jujuy 1085 6 A”*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void Fun (char c[],char a[]);

int main (){
    char c[50],c2[50];
    printf("Escribi la cadena \n");
    gets(c);
    Fun(c2,c);
    printf("%s",c2);
}
void Fun (char c[], char a[]) {
    int i;
    strcpy(c,a);
    c[0] = toupper(c[0]);
    for(i = 1; i<strlen(c);i++) {
        if (c[i] == ' ') {
            if (c[i+1] != '\0')
                c[i+1] = toupper(c[i+1]);
        }
    }
}
