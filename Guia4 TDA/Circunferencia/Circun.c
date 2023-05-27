#include <stdio.h>
#include <stdlib.h>
#include "Circun.h"
#define PI 3.14
 float distancia(punto a,punto b) {
    return (float)sqrt((double)((a.x-b.x)*(a.x-b.x))+(double)((a.y-b.y)*(a.y-b.y)));
 }
 float superf(Circun c) {
    return PI*c.r*c.r;
 }
 float perimetro(Circun c) {
    return 2*PI*c.r;
 }
 void inclu(Circun a,Circun b) {
    (distancia(a.centro,b.centro)>(a.r-b.r))?printf("La primera esta incluida en la segunda"):printf("La primera no esta incluida en la segunda");
 }
 void ingresaC(Circun *c) {
    fflush(stdin);
    scanf("%f %f %f",&c->centro.x,&c->centro.y,&c->r);
 }
