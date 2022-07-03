/*Faça um programa para ler as dimensões de um terreno retangular (comprimento e largura), bem
como o preço do metro de tela. Imprima o custo para cercar este mesmo terreno com tela*/
#include <stdio.h>
int main ()
{
int largura,comprimento,preco,metragem;
printf("Programa para ler a metragem de um terreno e imprimir o preco\n Insira a largura de um terreno: ");
scanf ("%d",&largura);
printf("Insira o comprimento de um terreno: ");
scanf ("%d",&comprimento);
printf("Insira o preco do metro de tela: ");
scanf ("%d",&preco);
metragem=(2*(largura+comprimento))*preco;
printf("o custo para cercar o terreno e: %d",metragem);
return 0;
}