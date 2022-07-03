/*
Três amigos jogaram na loteria. Caso eles ganhem, o prêmio deve ser repartido
proporcionalmente ao valor que cada deu para a realização da aposta.
Faça um programa que leia quanto cada apostador investiu, o valor do prêmio, e
imprima quanto cada um ganharia do prêmio com base no valor investido.
*/

#include<stdio.h>
#include<locale.h>
int main(){
    setlocale(LC_ALL, "portuguese");
    float investimento1, investimento2, investimento3, total, premio;
    float proporcao1, proporcao2, proporcao3;
    printf("Investimento do amigo 1: R$ ");
    scanf("%f",&investimento1);
    printf("Investimento do amigo 2: R$ ");
    scanf("%f",&investimento2);
    printf("Investimento do amigo 3: R$ ");
    scanf("%f",&investimento3);
    printf("Digite o valor do prêmio: R$");
    scanf("%f",&premio);

    total = investimento1 + investimento2 + investimento3;

    proporcao1 = investimento1 / total;
    proporcao2 = investimento2 / total;
    proporcao3 = investimento3 / total;

    printf("Amigo 1 ganharia R$ %.2f, pois colaborou com %.2f%%\n", premio * proporcao1, proporcao1*100);
    printf("Amigo 2 ganharia R$ %.2f, pois colaborou com %.2f%%\n", premio * proporcao2, proporcao2*100);
    printf("Amigo 3 ganharia R$ %.2f, pois colaborou com %.2f%%\n", premio * proporcao3, proporcao3*100);
    return 0;
}