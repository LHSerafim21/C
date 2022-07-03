/* Faça um programa que leia o valor de um produto e imprima o valor com desconto, tendo
em vista que o desconto foi de 12% */
#include <stdio.h>
int main ()
{
float produto;
printf("Insira o valor do produto: ");
scanf ("%f",&produto);
printf("valor do desconto: R$ %.2f\n",produto*12/100);
printf("Preco final com desconto: R$ %.2f\n",produto-produto*12/100);
return 0;
}