/*Faça um programa para ler um número inteiro e verificar se este número é par ou ímpar.*/
#include <stdio.h>
int main()
{
 int n;   
 printf("Digite um numero inteiro: ");
 scanf ("%d",&n);
  
 if (n%2==1)
 {
  printf("O numero e impar");  
 }
 else
 {
  printf("O numero e par");
 }
 return 0;
}