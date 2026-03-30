/*. Se tiene un archivo EMPRESAS2023.TXT con los datos de empresas tecnológicas, en cada línea: Nombre (ANU30),
 CantEmpleados2023, País (1 a 50), Ganancias2023 (en millones), Proyeccion2024(*). (*) indica el % de crecimiento (>0) o
 decrecimiento (<0) de las ganancias para 2024 Se pide, considerando los archivos anteriores, y modularizando adecuadamente: a
 ) generar un archivo binario EMPRESAS2024.DAT en el que cada elemento sea un registro que contenga: Nombre (ANU30),
 GananciasProyectadas2024 (en millones) solo para las empresas de latinoamérica (códigos del 10 al 19); a la
 vez generar un arreglo de EmpresasxPais de 50 elementos que en cada posición contenga un registro con dos campos
 (crecen y decrecen) en el que se almacene la cantidad de empresas en cada país que tienen expectativas de crecimiento y de decrecimiento.
 b) A partir del vector EmpresasxPais, escribir una función int que obtenga la cantidad de países europeos
 (códigos de 5 a 9 y de 25 a 35) en los que la cantidad de empresas que esperan crecer supera a las que no lo esperan.
 c) Escribir el main.c completo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nombre[31]; // Se agrega por el /n
    int cantEmpleados2023;
    int pais; // 1 a 50
    float ganancias2023; // En millones
    float proyeccion; //Indica el % de crecimiento >0 o <0 de las ganancias para el 2024
} EmpresaTxt;

typedef struct {
    char nombre[31];
    float gananciasProyectadas2024;  // Solo empresas de latinoamerica codigo del 10 al 19
} EmpresaDat;

typedef struct {
    int crecen;  //se almacene la cantidad de empresas en cada país que tienen expectativas de crecimiento y de decrecimiento.
    int decrecen;
} EmpresasxPais;

void procesarArchivo( EmpresasxPais v[]);
int contarPaisesEuropeos(EmpresasxPais v[]);
void mostrarArchivoLatam();

int main()
{

    EmpresasxPais v[50];
    procesarArchivo(v);


    printf("Paises europeos con mayor crecimiento: %d \n ", contarPaisesEuropeos(v));

    mostrarArchivoLatam();
    return 0;
}


//Inciso a generar archivo dat y vector

void procesarArchivo( EmpresasxPais v[]) {


    FILE *ftxt = fopen("EMPRESAS2023.TXT", "r"); // Se abre el archivo solo lectura
    FILE *fdat = fopen("EMPRESAS2024.DAT", "wb"); // Se crea el archivo si no esta y se abre para escribir . Si existe el archivo lo borra y lo crea de nuevo



    EmpresaTxt empresatxt;
    EmpresaDat empresadat;

    // inicializar vector
    for(int i=0;i<50;i++) {
        v[i].crecen = 0;
        v[i].decrecen = 0;
    }

    if(ftxt == NULL || fdat == NULL) {
        printf("Error en archivos \n ");

    }else{



    while(fscanf(ftxt, "%s %d %d %f %f ",empresatxt.nombre, &empresatxt.cantEmpleados2023, &empresatxt.pais,&empresatxt.ganancias2023, &empresatxt.proyeccion) == 5) {

        // calcular crecimiento/decrecimiento
        if(empresatxt.proyeccion > 0)
            v[empresatxt.pais-1].crecen++;
        else
            v[empresatxt.pais-1].decrecen++;

        // solo latinoamérica (10 a 19)
        if(empresatxt.pais >= 10 && empresatxt.pais <= 19) {
            strcpy(empresadat.nombre, empresatxt.nombre);  // copia empresatxt en reg.nombre
            empresadat.gananciasProyectadas2024 = empresatxt.ganancias2023 * (1 + empresatxt.proyeccion/100.0);

            fwrite(&empresadat, sizeof(EmpresaDat), 1, fdat);



        }
    }

    }
  fclose(ftxt);
  fclose(fdat);

}

int contarPaisesEuropeos(EmpresasxPais v[]) {
    int cont = 0;

    for(int i=0;i<50;i++) {
        int cod = i + 1;

        if((cod >= 5 && cod <= 9) || (cod >= 25 && cod <= 35)) {
            if(v[i].crecen > v[i].decrecen){//si hay más empresas que crecen que las que decrecen lo cuenta
                cont++;
                printf("Pais %d -> Crecen: %d | Decrecen: %d\n",cod, v[i].crecen, v[i].decrecen);} // solo esta para ver si es correcto no se puede usar un printf en una funcion int
        }



    }

    return cont;
}



void mostrarArchivoLatam() {
    FILE *fdat = fopen("EMPRESAS2024.DAT", "rb");

    EmpresaDat reg;

    printf(" EMPRESAS LATINOAMERICANAS \n");

    while(fread(&reg, sizeof(EmpresaDat), 1, fdat) == 1) {
        printf("Nombre: %s  Ganancia proyectada: %.2f\n",reg.nombre, reg.gananciasProyectadas2024);
    }

    fclose(fdat);
}
