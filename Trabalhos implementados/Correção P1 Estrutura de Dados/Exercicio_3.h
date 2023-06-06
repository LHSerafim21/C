#ifndef EXERCICIO_3_H_INCLUDED
#define EXERCICIO_3_H_INCLUDED
#endif // EXERCICIO_3_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>

#define MAX_PESO 50
#define MAX_DIMENSOES 100

// Estrutura para armazenar uma encomenda
typedef struct {
    char remetente[50];
    char destinatario[50];
    char tipo_cliente[15];
    int peso;
    int dimensoes;
} Encomenda;

// Estrutura de n� para a fila de entrada
typedef struct Node {
    Encomenda encomenda;
    struct Node* prox;
} Node;

// Estrutura para a fila de entrada
typedef struct {
    Node* inicio;
    Node* fim;
} FilaEntrada;

// Estrutura para a pilha de espera
typedef struct {
    Encomenda items[100];
    int topo;
} PilhaEspera;

// Estrutura de n� para a fila de sa�da
typedef struct DoubleNode {
    Encomenda encomenda;
    struct DoubleNode* ant;
    struct DoubleNode* prox;
} DoubleNode;

// Estrutura para a fila de sa�da (Deque)
typedef struct {
    DoubleNode* inicio;
    DoubleNode* fim;
} FilaSaida;

// Inicializa a fila de entrada
void inicializarFilaEntrada(FilaEntrada* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

// Verifica se a fila de entrada est� vazia
bool filaEntradaVazia(FilaEntrada* fila) {
    return (fila->inicio == NULL);
}

// Insere uma encomenda na fila de entrada
void inserirFilaEntrada(FilaEntrada* fila, Encomenda encomenda) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->encomenda = encomenda;
    novoNo->prox = NULL;

    if (filaEntradaVazia(fila)) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        fila->fim->prox = novoNo;
        fila->fim = novoNo;
    }
}

// Remove uma encomenda da fila de entrada
Encomenda removerFilaEntrada(FilaEntrada* fila) {
    if (filaEntradaVazia(fila)) {
        printf("Erro: fila de entrada vazia!\n");
        exit(1);
    }

    Node* noInicio = fila->inicio;
    Encomenda encomenda = noInicio->encomenda;

    fila->inicio = fila->inicio->prox;

    if (fila->inicio == NULL)
        fila->fim = NULL;

    free(noInicio);

    return encomenda;
}

// Verifica se a pilha est� cheia
bool pilhaCheia(PilhaEspera* pilha) {
    return (pilha->topo == 99);
}

// Verifica se a pilha est� vazia
bool pilhaVazia(PilhaEspera* pilha) {
    return (pilha->topo == -1);
}

// Insere uma encomenda na pilha
void push(PilhaEspera* pilha, Encomenda encomenda) {
    if (pilhaCheia(pilha)) {
        printf("Erro: pilha cheia!\n");
        exit(1);
    }

    pilha->topo++;
    pilha->items[pilha->topo] = encomenda;
}

// Remove uma encomenda da pilha
Encomenda pop(PilhaEspera* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Erro: pilha vazia!\n");
        exit(1);
    }

    Encomenda encomenda = pilha->items[pilha->topo];
    pilha->topo--;

    return encomenda;
}

// Inicializa a fila de sa�da
void inicializarFilaSaida(FilaSaida* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

// Verifica se a fila de sa�da est� vazia
bool filaSaidaVazia(FilaSaida* fila) {
    return (fila->inicio == NULL);
}

// Insere uma encomenda no in�cio da fila de sa�da
void inserirInicioFilaSaida(FilaSaida* fila, Encomenda encomenda) {
    DoubleNode* novoNo = (DoubleNode*)malloc(sizeof(DoubleNode));
    novoNo->encomenda = encomenda;
    novoNo->ant = NULL;
    novoNo->prox = NULL;

    if (filaSaidaVazia(fila)) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        novoNo->prox = fila->inicio;
        fila->inicio->ant = novoNo;
        fila->inicio = novoNo;
    }
}

// Insere uma encomenda no final da fila de sa�da
void inserirFimFilaSaida(FilaSaida* fila, Encomenda encomenda) {
    DoubleNode* novoNo = (DoubleNode*)malloc(sizeof(DoubleNode));
    novoNo->encomenda = encomenda;
    novoNo->ant = NULL;
    novoNo->prox = NULL;

    if (filaSaidaVazia(fila)) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        novoNo->ant = fila->fim;
        fila->fim->prox = novoNo;
        fila->fim = novoNo;
    }
}

// Remove uma encomenda do in�cio da fila de sa�da
Encomenda removerInicioFilaSaida(FilaSaida* fila) {
    if (filaSaidaVazia(fila)) {
        printf("Erro: fila de sa�da vazia!\n");
        exit(1);
    }

    DoubleNode* noInicio = fila->inicio;
    Encomenda encomenda = noInicio->encomenda;

    fila->inicio = fila->inicio->prox;

    if (fila->inicio == NULL)
        fila->fim = NULL;
    else
        fila->inicio->ant = NULL;

    free(noInicio);

    return encomenda;
}

// Remove uma encomenda do final da fila de sa�da
Encomenda removerFimFilaSaida(FilaSaida* fila) {
    if (filaSaidaVazia(fila)) {
        printf("Erro: fila de sa�da vazia!\n");
        exit(1);
    }

    DoubleNode* noFim = fila->fim;
    Encomenda encomenda = noFim->encomenda;

    fila->fim = fila->fim->ant;

    if (fila->fim == NULL)
        fila->inicio = NULL;
    else
        fila->fim->prox = NULL;

    free(noFim);

    return encomenda;
}

// Gera um n�mero aleat�rio entre min e max (inclusive)
int gerarAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

int funcao_Exercicio3() {

    // Colocando o sistema em PT-BR
    setlocale(LC_ALL, "portuguese");

    // Inicializa��o das estruturas de dados
    FilaEntrada filaEntrada;
    PilhaEspera pilhaEspera;
    FilaSaida filaSaida;
    inicializarFilaEntrada(&filaEntrada);
    pilhaEspera.topo = -1;
    inicializarFilaSaida(&filaSaida);

    // Defini��o das vari�veis globais para as dimens�es permitidas
    int maxPesoPermitido = MAX_PESO;
    int maxDimensoesPermitidas = MAX_DIMENSOES;

    // Semente para gera��o de n�meros aleat�rios
    srand(time(NULL));

    // Simula��o das encomendas chegando a cada 5 unidades de tempo
    int tempo = 0;
    while (true) {
        // Verifica se � hora de uma encomenda chegar
        if (tempo % 5 == 0) {
            Encomenda novaEncomenda;

            // Preenche as informa��es da encomenda
            sprintf(novaEncomenda.remetente, "Remetente %d", tempo);
            sprintf(novaEncomenda.destinatario, "Destinatario %d", tempo);

            // Define o tipo de cliente aleatoriamente
            int tipoClienteAleatorio = gerarAleatorio(0, 1);
            if (tipoClienteAleatorio == 0)
                sprintf(novaEncomenda.tipo_cliente, "Regular");
            else
                sprintf(novaEncomenda.tipo_cliente, "Preferencial");

            novaEncomenda.peso = gerarAleatorio(1, maxPesoPermitido);
            novaEncomenda.dimensoes = gerarAleatorio(1, maxDimensoesPermitidas);

            // Insere a encomenda na fila de entrada
            inserirFilaEntrada(&filaEntrada, novaEncomenda);
        }

        // Verifica se h� encomendas na fila de entrada
        if (!filaEntradaVazia(&filaEntrada)) {
            // Remove a encomenda da fila de entrada
            Encomenda encomenda = removerFilaEntrada(&filaEntrada);

            // Verifica se o peso e as dimens�es est�o dentro do permitido
            if (encomenda.peso <= maxPesoPermitido && encomenda.dimensoes <= maxDimensoesPermitidas) {
                // Verifica se o destinat�rio � preferencial
                if (strcmp(encomenda.tipo_cliente, "Preferencial") == 0) {
                    // Insere a encomenda no in�cio da fila de sa�da
                    inserirInicioFilaSaida(&filaSaida, encomenda);
                } else {
                    // Adiciona a encomenda na pilha de espera
                    push(&pilhaEspera, encomenda);
                }
            } else {
                printf("Encomenda inv�lida: Peso ou dimens�es excedem o permitido.\n");
            }
        }

        // Verifica se h� encomendas na pilha de espera
        if (!pilhaVazia(&pilhaEspera)) {
            // Remove a encomenda da pilha de espera
            Encomenda encomenda = pop(&pilhaEspera);

            // Insere a encomenda no final da fila de sa�da
            inserirFimFilaSaida(&filaSaida, encomenda);
        }

        // Verifica se h� encomendas na fila de sa�da
        if (!filaSaidaVazia(&filaSaida)) {
            // Remove a encomenda da fila de sa�da
            Encomenda encomenda = removerInicioFilaSaida(&filaSaida);

            // Processa a encomenda (envia, entrega, etc.)
            printf("Encomenda processada: Remetente: %s, Destinat�rio: %s\n", encomenda.remetente, encomenda.destinatario);
        }

        // Incrementa o tempo
        tempo++;
    }

    return 0;
}
