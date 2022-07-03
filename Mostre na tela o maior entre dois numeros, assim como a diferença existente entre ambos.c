/*Faça um programa que, dados dois números inteiros, mostre na tela o maior deles, assim
como a diferença existente entre ambos. Por exemplo:
Informe o Primeiro Número: 3
Informe o Segundo Número: 5
O maior é o número 5
A diferença entre eles é 2*/
 #include <stdio.h>
 int main ()
 {
  int n1,n2;
  printf("Insira um numero inteiro: ");
  scanf ("%d",&n1);   
  printf("Insira um numero inteiro: ");
  scanf ("%d",&n2);
   if (n1<n2)
   {
   printf("O maior numero e o %d",n2);   
   }
   if (n1>n2)
   {
   printf("O maior numero e o %d",n1);    
   }
   if (n1==n2) 
   {
   printf("Os numeros sao iguais"); 
   }
     
 }