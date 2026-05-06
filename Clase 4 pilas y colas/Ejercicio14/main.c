/*
Ej 14.- Se tiene una pila P con números naturales, se pueden determinar secuencias cada vez que
aparece un 0 o se vacía la pila.
A partir de P (que puede destruirse), colocar en una Cola la suma de los valores de aquellas
secuencias que tengan al menos dos números pares (no contar el 0). Ejemplo:

Pila   10  7   3   0   2   3   2   0   3   4   3   8


Cola   7     18



 7= 2+3+2 y 18= 3+4+3+8*/

#include <stdio.h>
#include "Pilas.h"
#include "Colas.h"

int esPar(int x);

void procesarPila(TPila *p, TCola *c);
void mostrarCola(TCola *c);

void main()
{
    TPila p;
    TCola c;

    IniciaP(&p);
    iniciaC(&c);

    // Carga de la pila (IMPORTANTE: el último en entrar es el primero en salir)
    poneP(&p, 8);
    poneP(&p, 3);
    poneP(&p, 4);
    poneP(&p, 3);
    poneP(&p, 0);
    poneP(&p, 2);
    poneP(&p, 3);
    poneP(&p, 2);
    poneP(&p, 0);
    poneP(&p, 3);
    poneP(&p, 7);
    poneP(&p, 10);

    procesarPila(&p, &c);

    printf("Cola resultado:\n");
    mostrarCola(&c);
}


void mostrarCola(TCola *c)
{
    TCola aux;
    iniciaC(&aux);

    TElementoC x;

    while (!vaciaC(*c)) {
        sacaC(c, &x);
        printf("%d ", x);
        poneC(&aux, x);
    }

    while (!vaciaC(aux)) {
        sacaC(&aux, &x);
        poneC(c, x);
    }

    printf("\n");
}
void procesarPila(TPila *p, TCola *c)
{
    int x;
    int suma = 0;
    int pares = 0;

    while (!VaciaP(*p))
    {
        sacaP(p, &x);

        if (x == 0)
        {
            if (pares >= 2)
                poneC(c, suma);


            suma = 0;
            pares = 0;
        }
        else
        {
            suma += x;

            if (esPar(x))
                pares++;
        }
    }


    if (pares >= 2)
        poneC(c, suma);
}

int esPar(int x)
{
    return x % 2 == 0 && x != 0;
}
