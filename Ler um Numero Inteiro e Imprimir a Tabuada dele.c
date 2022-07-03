/*Faça um programa para ler um número inteiro e imprimir a sua tabuada*/
#include <stdio.h>
int main ()
{
 int n,m1,m2,m3,m4,m5,m6,m7,m8,m9,m10;
 printf("Digite um numero: ");
 scanf ("%d",&n);
 m1=n*1;
 m2=n*2;
 m3=n*3;
 m4=n*4;
 m5=n*5;
 m6=n*6;
 m7=n*7;
 m8=n*8;
 m9=n*9;
 m10=n*10;
 printf("A taboada de %d e:\n %d*1=%d\n %d*2=%d\n %d*3=%d\n %d*4=%d\n %d*5=%d\n %d*6=%d\n %d*7=%d\n %d*8=%d\n %d*9=%d\n %d*10=%d",n,n,m1,n,m2,n,m3,n,m4,n,m5,n,m6,n,m7,n,m8,n,m9,n,m10);
 return 0;
}