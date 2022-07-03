/*Faça um programa que leia um número inteiro positivo de três dígitos (de 100 a 999).
Gere outro número formado pelos dígitos invertidos do número lido*/
#include <stdio.h>
int main()
{
 int n,centena,dezena,unidade;
  printf("Insira um numero de 3 digitos: ");
  scanf ("%d",&n);
   centena= n/100;
   dezena=(n-centena*100) /10;
   unidade=(n-((centena*100)+(dezena*10)));
  printf("O numero digitado e: %d\nO numero invertido e:%d%d%d",n,unidade,dezena,centena);

}