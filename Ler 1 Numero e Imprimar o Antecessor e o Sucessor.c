/*Faça um programa para ler um número inteiro e imprima o seu antecessor e o seu sucessor*/
#include <stdio.h>
int main ()
{
 int n,ant,suc;
 printf("Digite um numero: ");
 scanf ("%d",&n);
 ant=n-1;
 suc=n+1;
printf ("o antecessor de %d e: %d\no sucessor de %d e: %d",n,ant,n,suc);

 return 0;
}