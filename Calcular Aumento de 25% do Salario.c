/*Faça um programa para ler o salário de um funcionário. Em seguida, deve-se calcular e
imprimir o valor do novo salário, sabendo que ele recebeu um aumento de 25%*/
#include <stdio.h>
int main()
{
float salario;
printf("Digite o salario do funcionario: ");
scanf ("%f",&salario);
printf("O valor do aumento e: %.2f\n",salario*25/100);
printf("O valor do salario com o aumento e: %.2f\n",salario+salario*25/100);
return 0;
}