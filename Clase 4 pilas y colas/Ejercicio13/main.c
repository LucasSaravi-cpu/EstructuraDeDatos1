
/*Ej 13.- Se tiene una cola que almacena solicitudes de entradas para un espectáculo deportivo. En
cada elemento se tiene:  NroCliente  (no se repite), CantidadEntradas, TEContacto
Se han puesto a disposición para este evento X entradas.
Dejar en la cola sólo las solicitudes no satisfechas (si un cliente pide N entradas, o se le dan todas
o no se le da ninguna) e informar qué porcentaje de las solicitudes han podido satisfacerse. */
#include <stdio.h>
#include "Colas.h"



void procesarSolicitudes(TCola *c, int entradas);
void mostrarCola(TCola *c);

void main()
{
    TCola c;
    iniciaC(&c);

    TElementoC x;

    int n = 4;
    int entradas = 8;

    for (int i = 1; i <= n; i++)
    {
        printf("Cliente %d\n", i);

        x.nroCliente = i;

        printf("Cantidad de entradas: ");
        scanf("%d", &x.cantidad);

        printf("Contacto: ");
        scanf("%d", &x.contacto);

        poneC(&c, x);
    }

    printf("\nCola original:\n");
    mostrarCola(&c);

    procesarSolicitudes(&c, entradas);

    printf("\nSolicitudes NO satisfechas:\n");
    mostrarCola(&c);
}



void mostrarCola(TCola *c)
{
    TCola aux;
    iniciaC(&aux);

    TElementoC x;

    while (!vaciaC(*c)) {
        sacaC(c, &x);
        printf("Cliente %d - Entradas: %d\n", x.nroCliente, x.cantidad);
        poneC(&aux, x);
    }

    while (!vaciaC(aux)) {
        sacaC(&aux, &x);
        poneC(c, x);
    }

    printf("\n");
}


void procesarSolicitudes(TCola *c, int entradas){
    TCola aux;
    iniciaC(&aux);

    TElementoC x;

    int total = 0;
    int satisfechas = 0;

    while (!vaciaC(*c))
    {
        sacaC(c, &x);
        total++;

        if (x.cantidad <= entradas)
        {
            entradas -= x.cantidad;   // Voy restando la cantidad de entradas ya que hay un limite de entradas disponibles
            satisfechas++;
        }
        else
        {
            poneC(&aux, x);
    }
    }

    // devolver los no satisfechos
    while (!vaciaC(aux))
    {
        sacaC(&aux, &x);
        poneC(c, x);
    }

    float porcentaje = 0;
    if (total > 0)
        porcentaje = (float)satisfechas * 100 / total;

    printf("Porcentaje satisfechas: %.2f%%\n", porcentaje);
}


