/*Em um supermercado, a cada R$ 20,00 gastos em compra o cliente ganha um cupom para concorrer
a uma bicicleta. Faça um programa para ler o valor gasto pelo cliente em uma compra e exibir quantos
cupons ele deverá receber*/
#include <stdio.h>
int main()
{
 float compra,cupoms;   
 printf("Insira o valor da compra: ");
 scanf ("%f",&compra);
 cupoms=compra/20;
 printf("Voce recebera o total de %.0f cupoms",cupoms);
 return 0;
}