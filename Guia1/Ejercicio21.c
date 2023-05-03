/*Ej 21 – Dado un archivo binario en el que cada registro es de 17 dígitos para tres campos, 5
iniciales de ciudad, 5 superficie y 7 cantidad de habitantes. Escribir un programa que por pantalla
muestre la ciudad con mas densidad de habitantes y la de menor densidad.*/
#include <stdio.h>
#include <string.h>



typedef struct {
    char ciudad[20];
    int superficie;
    long canHabitantes;
} Treg;


void cantDensidad(char max[], char min[]);
void ingresaDatos();


//Principal
int main (){
    CreoArchivo();

    char max[20], min[20];
    cantDensidad(max, min);
    printf("la ciudad con mayor densidad de habitantes es: %s y la de menor cantidad es: %s", max, min);

    return 0;
}




void cantDensidad(char max[], char min[]){
    FILE *archb;
    float maxn, minn;
    Treg reg;
    archb=fopen("ejercicio21.dat", "rb");   // Se abre el archivo


    fread(&reg, sizeof(Treg), 1, archb);  // Se lee la primera linea si o si
    minn=maxn=(float)reg.canHabitantes/reg.superficie;  // primera dencidad de la primera ciudad
    strcpy(max,reg.ciudad); // se copia en el max
    strcpy(min,reg.ciudad); // se copia en el min
    while (!feof(archb)){
        if ((float)reg.canHabitantes/reg.superficie > maxn){
            maxn=(float)reg.canHabitantes/reg.superficie;
            strcpy(max,reg.ciudad);
        }else if((float)reg.canHabitantes/reg.superficie<minn){
            minn=(float)reg.canHabitantes/reg.superficie;
            strcpy(min,reg.ciudad);
        }
        fread(&reg, sizeof(Treg), 1, archb);
    }

    fclose(archb);
}



//Se crea el archivo binario !

void  CreoArchivo(){
    FILE * archb;
    int n,i;
    Treg reg;
    archb=fopen("ejercicio21.dat", "wb");   // Se abre para lectura y escritura

    printf("Ingrese la cantidad de ciudades ");
    scanf("%d",&n);


    for (i=0; i<n; i++){
        printf("ingrese nombre de la ciudad \n");
        fflush(stdin);
        gets(reg.ciudad);
        printf("ingrese la superficie");
        fflush(stdin);
        scanf("%d", &reg.superficie);
        printf("ingrese la cantidad de habitantes");
        fflush(stdin);
        scanf("%d", &reg.canHabitantes);

        fwrite(&reg, sizeof(Treg), 1, archb); // Se escribe en el archivo
    }
    fclose(archb);
}
