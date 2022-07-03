/*/3) Faça um programa que peca ao usuário para digitar três valores inteiros e imprima a soma
deles/*/
#include <stdio.h>
int main()
{
int n1,n2,n3,soma;
printf("Digite um numero inteiro: ");
scanf ("%d",&n1);
printf("Digite um numero inteiro: ");
scanf ("%d",&n2);
printf("Digite um numero inteiro: ");
scanf ("%d",&n3);
soma=n1+n2+n3;
printf("a soma dos valores %d, %d, e %d e igual a %d",n1,n2,n3,soma);
return 0;
}