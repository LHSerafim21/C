/*Faça um programa para ler dois números e o símbolo de uma operação
aritmética. Em seguida, o programa apresenta o resultado da operação. Para tanto,
utilize os seguintes símbolos:
 Soma: +
 Subtração: -
 Divisão: /
 Multiplicação: * */
#include <stdio.h>
int main()
{
 int escolha,num1,num2,soma,subtracao,divisao,resto,multiplicacao;

   printf("Escolha uma operacao Aritmetica:\nSoma(+): Digite 1\nSubtracao(-): Digite 2\nDivisao(/): Digite 3\nMultiplicacao(*): Digite 4\nEscolha: ");   
   scanf ("%d",&escolha);

   if (escolha == 1)
   {
    printf("Voce escolheu soma\n");
    printf("Digite o numero 1: ");
    scanf ("%d",&num1);
    printf("Digite o numero 2: ");
    scanf ("%d",&num2);
    soma=num1+num2;
    printf("A soma de %d com %d e: %d",num1,num2,soma);   
   }

   if (escolha == 2)
   {
    printf("Voce escolheu subtracao\n");
    printf("Digite o numero 1: ");
    scanf ("%d",&num1);
    printf("Digite o numero 2: ");
    scanf ("%d",&num2);
    subtracao=num1-num2;
    printf("A subtracao de %d com %d e: %d",num1,num2,subtracao);    
   }

   if (escolha == 3)
   {
    printf("Voce escolheu divisao\n");
    printf("Digite o numero 1: ");
    scanf ("%d",&num1);
    printf("Digite o numero 2: ");
    scanf ("%d",&num2);
    divisao=num1/num2;
    resto=num1%num2;    
    printf("A divisao entre o numero %d com %d e: %d com resto de %d",num1,num2,divisao,resto);
   }

   if (escolha == 4)
   {
    printf("Voce escolheu multiplicacao\n");
    printf("Digite o numero 1: ");
    scanf ("%d",&num1);
    printf("Digite o numero 2: ");
    scanf ("%d",&num2);
    multiplicacao=num1*num2;
    printf("A multiplicacao de %d com %d e: %d",num1,num2,multiplicacao);   
   }
   return 0;
}