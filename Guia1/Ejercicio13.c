/*Ej 13 – Dado un vector de enteros de n elementos, desarrollar una función que encuentre la
posición del máximo. Implementar 3 veces utilizando for, while y do while.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n , i ;
    int v[50];
    printf("Ingrese la cantidad de numeros\n ");
    scanf("%d",&n);


    for (i=0 ;i<n ; i++){
     printf("Ingrese el numero %d \n",i+1);
        scanf("%d", &v[i]);
    }

    printf("La posicion del maximo es %d",encuentrapos(v,n));
    return 0;
}



/*int encuentrapos (int v[] , int n ){

int max=v[0],pos=0,i;

for (i=1;i<n;i++){
    if (v[i]>max){
       max=v[i];
       pos=i;
    }
}
return pos+1;

}*/

/*int encuentrapos(int v[], int n){
int max=v[0],pos=0,i;
 while (i<n) {
        if (v[i]>max) {
            max = v[i];
            pos = i;
        }
        i++;
    }
    return pos+1;


}
*/


int encuentrapos (int v[], int n) {
    int max = v[0],pos = 0,i = 1;
    if (n>1) {
        do{
            if (v[i]>max) {
                max = v[i];
                pos = i;
            }
            i++;
        }while(i<n);
    }
    return pos+1;
}

