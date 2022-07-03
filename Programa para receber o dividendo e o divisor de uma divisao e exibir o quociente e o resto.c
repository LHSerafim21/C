/*Faça um programa para receber o dividendo e o divisor de uma operação de divisão de inteiros.
Em seguida, deverá exibir o quociente e o resto.*/
#include <stdio.h>
int main()
{
 int dividendo,divisor,quociente,resto;
 printf("Insira o dividendo da operacao: ");
 scanf ("%d",&dividendo);
 printf("Insira o divisor da operacao: ");
 scanf ("%d",&divisor);
 quociente=dividendo/divisor;
 resto=dividendo%divisor;
 printf("O quociente e: %d\nO resto e: %d",quociente,resto); 
 return 0;
}