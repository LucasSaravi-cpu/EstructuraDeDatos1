/*Ej 14 – Desarrollar un programa que contenga una función void que reciba una cadena que
representa una fecha de la forma aaaammdd y devuelva un struct con 3 campos: dd, mm y aaaa.
La lectura de la cadena y la impresión del registro deben estar en el main*/

#include <stdio.h>

typedef struct {
    int dd;
    int mm;
    int aaaa;
} Fecha;

void obtener_fecha(Fecha *fecha) {
    char cadena[9];
    printf("Ingrese una fecha en formato aaaammdd: ");
    gets(cadena);
// Se usa flechita ya que .* es flechita
    sscanf(cadena, "%4d%2d%2d", &fecha->aaaa, &fecha->mm, &fecha->dd);
}

int main() {
    Fecha fecha;
    obtener_fecha(&fecha);
    printf("La fecha ingresada es: %02d/%02d/%d\n", fecha.dd, fecha.mm, fecha.aaaa);
    return 0;
}
