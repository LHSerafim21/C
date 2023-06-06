#ifndef EXERCICIO_2_H_INCLUDED
#define EXERCICIO_2_H_INCLUDED
#endif // EXERCICIO_2_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um elemento da matriz esparsa
typedef struct {
    int linha;
    int coluna;
    int valor;
} Elemento;

// Função para somar uma constante a todos os elementos da matriz esparsa
void somarConstante(Elemento* matriz, int tamanho, int constante) {
    int i;
    for (i = 0; i < tamanho; i++) {
        matriz[i].valor += constante;
    }
}

// Função para imprimir a matriz esparsa
void imprimirMatrizEsparsa(Elemento* matriz, int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("(%d, %d): %d\n", matriz[i].linha, matriz[i].coluna, matriz[i].valor);
    }
}

int funcao_Exercicio2() {

    system("cls");
    Elemento matrizEsparsa[] = {
        {0, 0, 1},
        {0, 2, 2},
        {1, 1, 3},
        {2, 0, 4},
        {2, 2, 5}
    };
    int tamanho = sizeof(matrizEsparsa) / sizeof(Elemento);
    int constante;

    printf("Matriz esparsa original:\n");
    imprimirMatrizEsparsa(matrizEsparsa, tamanho);
    printf("\nDigite uma constante para realizar a soma:\n");
    scanf("%d",&constante);

    somarConstante(matrizEsparsa, tamanho, constante);

    printf("\nMatriz esparsa com a constante somada:\n");
    imprimirMatrizEsparsa(matrizEsparsa, tamanho);
    sleep(5);

    return 0;
}

