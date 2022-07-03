/*/César é um detetive que investiga uma série de roubos que acontecem em sua cidade. Em todo lugar que um crime acontece, 
a pessoa que cometeu tal crime deixa uma mensagem escrita, formada por letras maiúsculas e minúsculas. César conseguiu achar 
um padrão nestas mensagens e agora extrai um texto oculto em cada mensagem e pede a sua ajuda para tentar descobrir quem está
 cometendo tais crimes.

Entrada
A entrada é composta por vários casos de teste. A primeira linha contém um número inteiro C (2 <= C <= 99) relativo ao número 
de casos de teste. Nas C linhas seguintes, haverá mensagens codificadas, todas com um mesmo padrão em relação ao exemplo 
abaixo.

Saída
Para cada caso de teste de entrada do seu programa, você deve imprimir o texto extraído da mensagem original

EXEMPLO DE ENTRADA: 3, NoTApasCAL, atEQUEatabELATERMINE, zoEIrrRRRRa
EXEMPLO DE SAIDA: sapo, batata, arroz
/*/

#include <stdio.h>

int getNum(char letra) {
    switch (letra) {
        case '1':
            return 1;
            break;
        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        case '4':
            return 4;
            break;
        case '5':
            return 5;
            break;
        case '6':
            return 6;
            break;
        case '7':
            return 7;
            break;
        case '8':
            return 8;
            break;
        case '9':
            return 9;
            break;
        default:
            return 0;
            break;
    }
}

int main() {
    
    int n, i;
    scanf("%d ", &n);
    
    while (n--) {
        char palavra[14];
        gets(palavra);
        fflush(palavra);
        int termos1 = getNum(palavra[2])*10 + getNum(palavra[3]);
        int termos2 = getNum(palavra[5])*100 + getNum(palavra[6])*10 + getNum(palavra[7]);
        int termos3 = getNum(palavra[11])*10 + getNum(palavra[12]);
        printf("%d\n", termos1 + termos2 + termos3);
    }

    return 0;
}