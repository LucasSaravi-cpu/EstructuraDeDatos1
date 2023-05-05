#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int paso1();
int paso2();
int paso3();

int main()
{
    int i;
    i=paso1(); //Lee el archivo completo y lo muestra
    i=paso2(); // Crea el archivo binario
    i=paso3();//  muestra el archivo binario creado solo los que tienen hijos

}


//paso 1 lee el archivo de texto

int paso1()
{
   FILE * archt;
   int   edad, canti, i;
   char sexo, nom[12];

   archt = fopen("Clientes.txt","rt");
   if (archt == NULL) {
       printf("archivo clientes no existe!");
       return 1;
   }
   system("cls");    //Limpiamos la pantalla
   printf("Listado de Clientes (archivo de texto):\n\n");
   fscanf(archt,"%s %c %d %d", nom,&sexo, &edad,&canti);  // Leemos del archivo los datos , primera parte del cliente si o si antes de hacer el while

   while(!feof(archt)) {
          printf("Cliente: %s  sexo : %c Edad: %2d  Hijos: %2d \n",nom,sexo, edad,canti);
         for(i=0;i < canti;i++){  // Leemos depende de la cantidad de hijos
              fscanf(archt,"%s %d", nom,&edad);
              printf("       Hijo #%2d -> %11s  Edad: %2d \n",i,nom,edad);
         }
          fscanf(archt,"%s %c %d %d", nom,&sexo, &edad,&canti);
   }

   fclose(archt);
   printf("\n\n Presione cualquier tecla ");
   getch();
   return 1;
}


//paso #2 Creamos un archivo Binario

int paso2()
{
   FILE * archt, *archb;
   int   edad, canti, i;
   char sexo, nom[12];
   struct dato{
      char nombre[12];
      char sexo;
      int edad;
      int cantiHijos;
   } reg;

   archt = fopen("Clientes.txt","rt");
   if (archt == NULL) {
       printf("archivo clientes no existe!");
       return 1;
   }
   archb = fopen("ConHijos.dat","wb");
   if (archb == NULL) {
       printf("No pudo crear el archivo ConHijos.dat!");
       return 1;
   }
   system("cls");
   printf("Listado de Clientes (Crea archivo binario):\n\n");

   fscanf(archt,"%s %c %d %d", nom,&sexo, &edad,&canti);
   while(!feof(archt)) {
        if(canti > 0 ){
           strcpy(reg.nombre, nom);
           reg.edad = edad;
           reg.sexo = sexo;
           reg.cantiHijos = canti;
           fwrite(&reg, sizeof(struct dato), 1, archb);
           for(i=0;i < canti;i++){
              fscanf(archt,"%s %d", nom,&edad);
              fwrite(nom,12, 1, archb);
              fwrite(&edad, sizeof(int), 1, archb);
           }
         }
         fscanf(archt,"%s %c %d %d", nom,&sexo, &edad,&canti);
   }

   fclose(archt);
   fclose(archb);

   printf("\nFin ");
   printf("\nPresione cualquier tecla");
   getch();
}


//Paso 3 Leemos un archivo binario

int paso3()
{
   FILE  *archb;
   int   edad, canti, i;
   char sexo, nom[12];
   struct dato{
      char nombre[12];
      char sexo;
      int edad;
      int cantiHijos;
   } reg;

   archb = fopen("ConHijos.dat","rb");
   if (archb == NULL) {
       printf("archivo ClientesConHijos.dat no existe!");
       return 1;
    }
    fread(&reg, sizeof(reg), 1, archb);
    system("CLS");
    printf("Listado de Clientes con hijos (lee archivo binario):\n\n");

    while(!feof(archb)) {
       printf("\nCliente:%11s  Sexo:%c  Edad:%2d  Hijos%2d", reg.nombre, reg.sexo, reg.edad, reg.cantiHijos);
       for(i=0;i < reg.cantiHijos;i++){
              fread(nom,12,1,archb);
              fread(&edad,sizeof(int),1,archb);
              printf("\n     Hijo #%2d ->%11s  Edad:%2d",i+1,nom,edad);
           }
       fread(&reg, sizeof(reg), 1, archb);
    }
    fclose(archb);

    return 1;
}


