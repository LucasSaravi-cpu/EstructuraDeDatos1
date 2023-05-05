#include <stdio.h>
#include <string.h>

void invertirCadena(char *cadena) {
    if (*cadena != '\0') {
        invertirCadena(cadena + 1);
        printf("%c", *cadena);
    }
}

int main() {
    char cadena[100];

    printf("Ingrese una cadena: ");
    gets(cadena);

    printf("La cadena invertida es: ");
    invertirCadena(cadena);

    return 0;
}
