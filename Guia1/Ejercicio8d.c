//d) leer N caracteres y hallar y escribir la cantidad de caracteres.

void main(){

char caracteres[100];
printf("Ingrese los caracteres que quieras, para terminar apreta enter \n");
gets(caracteres);
puts(caracteres);
printf("La cantidad de caracteres son: %d",strlen(caracteres));

}
