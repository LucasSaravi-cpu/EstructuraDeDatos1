#include <stdio.h>

#include <stdlib.h>

float suma(float v[],int n);
float productoDeLosElementos(float v[],int n);
int encuentra(float v[],int n,float numero);
int CuantasApariciones (float v[],int n,float numero);
int arreglosIguales (float v1[],float v2[],int n);
int SonCreciente (float v[],int n) ;
float Maximo (float v[], int n);
int PosMax (float v[], int n);
float Promedio (float v[], int n, int Dim);
void Imprimir (float v[],int n,int i);


int main() {

   float a[5] = {2.5,1.0,8.0,1.5,2.0};
   float b[5] = {7.0,3.1,4.2,4.5,5.5};

 //Ejercicio A
   printf("la suma del arreglo a es %f \n",suma(a,4));
   printf("la suma del arreglo b es %f \n",suma(b,4));

  //Ejercicio B
   printf("la multiplicacion del arreglo a es %f \n",productoDeLosElementos(a,4));
   printf("la multiplicacion del arreglo b es %f \n",productoDeLosElementos(b,4));

  //Ejercicio C

   if(encuentra(a,4,7.0) == 1)
        printf("El valor %f se encuentra en el arreglo a \n",7.0);
    else
        printf("El valor %f no se encuentra en el arreglo a  \n",7.0);


    if(encuentra(b,4,7.0) == 1)
        printf("El valor %f se encuentra en el arreglo b \n",7.0);
    else
        printf("El valor %f no se encuentra en el arreglo b  \n",7.0);

  //Ejercicio D
    printf("El valor %f se encuentra en el arreglo unas %d \n",1.0,  CuantasApariciones(a,4,1.0));
  //Ejercicio E
     if (arreglosIguales(a,b,4) == 1)
        printf("Los arreglos son iguales \n");
    else
        printf("Los arreglos no son iguales \n");
  //Ejercicio F
   if(SonCreciente(b,4) == 1)
        printf("El arreglo es creciente \n");
    else
        printf("El arreglo no es creciente \n");
  //Ejercicio G y H
   printf("El maximo del arreglo a es %f y su posicion es %d \n ",Maximo (a,4) ,PosMax(a,4) );
   //Ejercicio I
  printf("El promedio de los elementos es %f \n",Promedio(a,4,4));
  //Ejercicio J
  printf("El arreglo a es \n ");
  Imprimir (a,4,0);
}


//Hallar la suma de los elementos del arreglo (función float)

float suma(float v[],int n){
    if(n == 0)
        return v[0];
    else
        return v[n] + suma(v,n-1);
}


//Hallar el producto de los elementos del arreglo (función float y void)

float productoDeLosElementos(float v[],int n) {
    if(n == 0)
        return v[0];
    else
        return v[n] *  productoDeLosElementos(v,n-1);
}

void productoDeLosElementosV(float v[],int n,float *res) {
    if (n == 0)
        *res = v[0];
    else{
        productoDeLosElementosV(v,n-1,res);
        *res *= v[n];
    }
}

//Verificar que un determinado elemento se encuentre en el arreglo (función int)

int encuentra(float v[],int n,float numero) {
    if (n<0)
        return 2;
    else {
        if (numero == v[n])
            return 1;
        else {
           return encuentra(v,n-1,numero);
        }
    }
}


//Contar la cantidad de ocurrencias de un valor X en el arreglo (función int)

int CuantasApariciones (float v[],int n,float numero) {
        if (n<0)
            return 0;
        else {
            if (numero == v[n])
                return 1 + CuantasApariciones (v,n-1,numero);
            else
                return CuantasApariciones (v,n-1,numero);
        }
}


//Verificar si es igual a un arreglo B de N elementos (función int)

int arreglosIguales (float v1[],float v2[],int n) {
    if(n<0)
        return 1;
    else {
        if (v1[n] != v2[n])
            return 2;
        else {
            return (arreglosIguales(v1,v2,n-1));
        }
    }
}
//Verificar si los elementos de A respetan un orden creciente o no. (función int)

int SonCreciente (float v[],int n) {
    if (n == 0)
        return 1;
    else {
        if (v[n] < v[n-1])
            return 2;
        else {
           return (SonCreciente(v,n-1));
        }
    }
}


//Hallar el máximo valor (función float y void)

float Maximo (float v[], int n) {
    float aux;
    if (n == 0)
        return v[0];
    else{
        aux = Maximo(v,n-1);
        if (v[n] > aux)
            return v[n];
        else
            return aux;
    }
}

void MaximoV(float v[], int n, float *mx) {
    if(n == 0)
        *mx = v[0];
    else {
        MaximoV (v,n-1,mx);
        if(v[n]>*mx){
            *mx = v[n];
        }
    }
}


//Hallar la posición del máximo valor (función int)
int PosMax (float v[], int n) {
    int pos;
    if (n == 0)
        return 0;
    else{
        pos = PosMax(v,n-1);
        if (v[n] > v[pos])
            return n;
        else
            return pos;
    }
}


//Calcular el promedio de sus elementos (función float)
float Promedio (float v[], int n, int Dim) {
    float aux;
    if (n == 0)
        return v[0];
    else {
        aux = v[n] + Promedio(v,n-1,Dim);
        if (Dim != n)
            return aux;
        else
            return aux/(n+1);
    }
}


/*Imprimir los elementos de la siguiente forma:
A[1], A[2],......, A[N]
A[2],......, A[N]
........
A[N]*/

void Imprimir (float v[],int n,int i) {
    int j = i;
    i += 1;
    if(j < n){
        for (;j<=n;j++) {
            printf("%2.2f ",v[j]);
        }
        printf ("\n");
        Imprimir(v,n,i);
    }else
        printf("%2.2f \n",v[n]);
}

