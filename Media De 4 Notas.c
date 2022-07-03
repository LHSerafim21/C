/*/Faça um programa para ler quatro notas, calcular a média aritmética e imprimir o resultado/*/
#include <stdio.h>
int main ()
{
float nota1,nota2,nota3,nota4,media;
printf("Digite a nota 1: ");
scanf ("%f",&nota1);

printf("Digite a nota 2: ");
scanf ("%f",&nota2);

printf("Digite a nota 3: ");
scanf ("%f",&nota3);

printf("Digite a nota 4: ");
scanf ("%f",&nota4);

media=(nota1+nota2+nota3+nota4)/4;

printf("A media das notas %.2f, %.2f, %.2f, e %.2f e igual a: %.2f",nota1,nota2,nota3,nota4,media);

return 0;
}