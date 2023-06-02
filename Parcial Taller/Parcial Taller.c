/* Parcial taller de Programacion

1) Una linea area ha vendido en el hotSale pa[Q]uetes , [P]asajes y [A]lojamiento y ha almacenado las ventas en un archivo
binario VENTAS.DAT con el siguiente formato

typedef struct {
    int idTrans;
    char Tipo , Destino[20] ,TC[16] ; // tipo es Q , P o A
    float Precio; // precio unitario
    int Cantidad;  //personas
} RegVenta;

Se pide desarrollar un subprograma que a partir de los datos de VENTAS.DAT genere un archivo de texto
PASAJES.TXT en el que se almacenen los siguientes datos idtrans , PrecioTotal ( es precio unitario*cantidad) para cada
una de las ventas de PASAJES (con una venta por linea ) .
En la ultima linea colocar el total recaudado por estas ventas ( escribir la invocacion del sub programa desarrolado

2) Desarrollar una funcion int que dada una matriz de nxn naturales , calcule y devuelva
la cantidad de columnas que verifican que la suma de sus elementos es mayor al elemento correspondiente de la diagonal principal
(escribir la invocacion del subprograma desarrolado )

*/


//Ejercicio 1

#include <stdio.h>
#define N 3

void generarArchivoPasajes();
int CantColumnas(int matriz[N][N], int n);

int main() {
    //Ejercicio 1 invocación
    generarArchivoPasajes();

    //Ejercicio 2 invocación
    int matriz[N][N] =  {{5, 2, 3},
                        {1, 6, 4},
                        {4, 3, 9}};
    int cantidadColumnas = CantColumnas(matriz, N);
    printf("La cantidad de columnas con suma mayor a la diagonal principal es: %d \n", cantidadColumnas);
    return 0;

}

void generarArchivoPasajes() {
    FILE *ventasFile, *pasajesFile;
    RegVenta venta;
    float totalRecaudado = 0.0;
    ventasFile = fopen("VENTAS.DAT", "rb");
    pasajesFile = fopen("PASAJES.TXT", "w");
    while (fread(&venta, sizeof(RegVenta), 1, ventasFile) == 1) {
        if (venta.Tipo == 'P') {
            float precioTotal = venta.Precio * venta.Cantidad;
            totalRecaudado += precioTotal;
            fprintf(pasajesFile, "%d %.2f\n", venta.idTrans, precioTotal);
        }
    }
    fprintf(pasajesFile, "Total recaudado: %.2f\n", totalRecaudado);
    fclose(ventasFile);
    fclose(pasajesFile);
}


//Ejercicio 2

int CantColumnas(int matriz[N][N], int n) {
    int contador = 0;
    for (int j = 0; j < n; j++) {
        int sumaColumna = 0;

        for (int i = 0; i < n; i++) {
            sumaColumna += matriz[i][j];
        }
        if (sumaColumna > matriz[j][j]) {
            contador++;
        }
    }
    return contador;
}

/*3) Completar el codigo





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main (){

char fig ,*cal;
float L1=0 ,L2=0 ,L3 , res;
printf("ingrese el tipo de figura R rectangulo , T triangulo rectangulo , C cuadrado ");
scanf("%c",....fig);  &
switch(c){
....'T':printf("Ingrese la hipotenusa"); scanf("%f"....L1); case &
....'R':printf("Ingrese el lado ") ; scanf ("%f" .... L2); case &
....'C':printf("ingrese el lado"); scanf ("%f", ....L3);  case &
}
printf (" ingrese el tipo calculo PER perimetro ,sup superficie ");
cal= (....) malloc (......)  *char        size(int)*4
scanf("%s,...cal); no se agrega ampersal
calcula (L1,L2,L3,fig,cal,....res); &
printf("el %s de la figura es : %f ", .... , ....); cal res
free(cal);
}

void calcula(float L1 , float L2 , float L3 ,char fig , char *cal , float*res){

if ( fig=='C' )
...res=(strcmp(cal,"..."))?L3*4:L3*L3; * PER
else
 if (fig=='R')
   ... res=(strcmp(cal,"..."))?L3*2+L2*2: L3*L2; * PER
else
  ....res = (strmp(cal,"...."))?L1+L2+L3:(L3*L2)/2;   * PER




*/
