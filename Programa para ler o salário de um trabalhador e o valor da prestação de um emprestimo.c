/*Faça um programa para ler o salário de um trabalhador e o valor da prestação de um
empréstimo. Se a prestação for maior que 20% do salário, o programa deverá imprimir
“Empréstimo não concedido”; caso contrário imprimirá “Empréstimo concedido”*/
#include <stdio.h>
int main()
{
 float salario,emprestimo,porcentagem;   
 printf("Digite o salario do funcionario: ");
 scanf ("%f",&salario);
 printf("Digite o valor do emprestimo: ");
 scanf ("%f",&emprestimo);
 porcentagem=salario/5;
 if(emprestimo>porcentagem)
 {
  printf("Emprestimo nao concedido");   
 }
 else
 {
  printf("Emprestimo concedido");   
 }
 return 0;
}