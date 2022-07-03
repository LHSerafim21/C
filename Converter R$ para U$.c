/*/Faça um programa para ler um valor em real e a cotação do dólar. Em seguida, imprima o
valor correspondente em dólares/*/
#include <stdio.h>
 int main ()
{
float dolar,real,cotacao;
printf("Digite a cotacao do dolar: ");
scanf ("%f",&cotacao);
printf("Digite o valor em real: ");
scanf ("%f",&real);
dolar=real/cotacao;
printf("o valor em Dolar e: %.2f",dolar);
return 0;
}