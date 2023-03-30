/*Leer 3 valores correspondientes un ángulo en grados, minutos y segundos y obtener y
mostrar el valor equivalente en radianes*/

#include<stdio.h>
#define PI 3.14159265358979323846
float radianes(float , float, float );


float main() {

    float grados, minutos,segundos;
    float resultado;
    printf("Ingrese los grados ");
    scanf("%f",&grados);
    printf("Ingrese los minutos ");
    scanf("%f",&minutos);
    printf("Ingrese los segundos ");
    scanf("%f",&segundos);
     resultado=radianes(grados,minutos,segundos);
    printf("radianes %f",resultado);
    return 0;
    }


float radianes(float grados,float minutos,float segundos){

float gra,graSeg,graMin;

graMin=minutos/60;
graSeg=segundos/3600;

gra=grados+graMin+graSeg;

return  gra * PI / 180;
}

/* Otra forma
#include <stdio.h>

int main(){
double grados,min,seg,grFinal;
printf("Ingrese los grados, minutos y segundos de un angulo, asi lo pasamos a radianes \n");
scanf(" %f %f %f",&grados,&min,&seg);
grFinal = (grados + min/60.0 + seg/3600.0)/180.0;
//pasamos todo a grados, teniendo en cuenta cuantos minutos y segundos son 1 grado.
printf("En radianes ese angulo es %2.4f pi",grados);
 return 0;
}*/