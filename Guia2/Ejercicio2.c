/*Ej 2.- Corregir el siguiente programa para retornar la suma y la diferencia de los valores de las
variables a y b declaradas en el main().
#include <stdio.h>
int main(){
 int a = 30, b = 20;
 sumaresta(a, b, s, r);
 printf(" valor de a+b es %d\t valor de a-b es %d\n", &s, &r);
 return 0;
}
void sumaresta(int x, int y, int *s, int *r){
 s = a+b;
 r = a-b;
}
*/


#include <stdio.h>

void sumaresta( int x , int y , int *s , int *r);

int main () {
  int s,r;

  int a=30 , b=20;

  sumaresta(a,b,&s,&r);

  printf(" valor de a+b es %d\t valor de a-b es %d\n", *&s, *&r);   // Se anularian y podria escribirse solo s y r

  return 0;
  }

  void sumaresta(int x, int y, int *s, int *r){

   *s = x+y;//*  indica que se ponga el valor a donde apunta s

   *r = x-y;// * indica que se ponga el valor a donde apunta r

  }
