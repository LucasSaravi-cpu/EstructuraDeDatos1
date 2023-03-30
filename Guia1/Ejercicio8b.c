/* ingresar N caracteres y determinar y mostrar la cantidad de vocales indicando si la A es la
vocal que más veces apareció.
*/

#include<stdio.h>
void main() {

  int inicio=1,cantidad,vocales=0,contadorA=0,contadorE=0,contadorI=0,contadorO=0,contadorU=0;

  char caracter;

  printf("Ingrese la cantida de caracteres");
  scanf("%d",&cantidad);
  fflush(stdin);                       //borra el búfer de entrada se usa despues de scanf

  for (inicio;inicio<=cantidad;inicio++){

        printf("Ingrese caracter");
        scanf("%c",&caracter);
        fflush(stdin);
        switch(caracter){
           case 'a':
           case 'A':vocales++;
                    contadorA++;

           break;
           case 'e':
           case 'E':vocales++;
                    contadorE++;
           break;
           case 'i':
           case 'I':vocales++;
                    contadorI++;
           break;
            case 'o':
            case 'O': vocales++;
                      contadorO++;
           break;
            case 'u':
            case 'U':vocales++;
                     contadorU++;
           break;


  }


}

if ((contadorA>contadorE) && (contadorA>contadorI) && (contadorA>contadorO) && (contadorA>contadorU))
    printf("La A es la vocal que mas veces aparecio\n ");

printf("La cantidad de vocales ingresadas es %d",vocales);
}
