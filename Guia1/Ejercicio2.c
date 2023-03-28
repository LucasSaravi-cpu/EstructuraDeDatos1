#include<stdio.h>
void main() {
int A=34,B=1234 , C=-3;
float F=22.47;
char ch1='A';

printf("A=%d\n",A);
printf("A=%5d\n",A);
printf("A=%4d\n",A);
printf("A=%-5d\n",A);
printf("A=%-4d\n",A);
printf("A=%05d\n",A);
printf("B=%-05d\n",B);
printf("C=%+d\n",C);
printf("C=%+d\n",C);
printf("B=%3d\n",B);
printf("C=%c\n",C);
printf("C=%3c\n",C);
printf("C=%-3c\n",C);
printf("F=%f \n",F);
printf("F=%7.2f \n",F);
printf("F=%07.2f \n",F);
printf("F=%-7.2f \n",F);
printf("F=%7.1f \n",F);

printf("ch1=%c \n",ch1);
printf("ch1=%3c \n",ch1);
printf("%s \n","ELEFANTE");


}
