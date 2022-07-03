/*/Tabelas de dispersão (tabelas hash) armazenam elementos com base no valor absoluto de suas chaves e em
técnicas de tratamento de colisões. As funções de dispersão transformam chaves em endereços-base da
tabela, ao passo que o tratamento de colisões resolve conflitos em casos em que mais de uma chave é
mapeada para um mesmo endereço-base da tabela. Suponha que uma aplicação utilize uma tabela de
dispersão com 11 endereços-base (índices de 0 a 10) e empregue h(x) = x mod 11 como função de dispersão,
em que x representa a chave do elemento. Considerando que a tabela de dispersão trate colisões por meio de
encadeamento exterior (lista dinâmica duplamente encadeada), implemente a função de inserção de um novo
elemento na tabela de dispersão. Apresente todas as estruturas de dados utilizadas na implementação./*/

#include "Hash.h"

int hash(int chave){
    return chave%11;
}

void inicializaTabela(Tabela *t){
    for(int i =0; i<=10;i++){
        t->tab[i] = NULL;
    }
}

void Inserir(Tabela *t,int chv){
    int x = hash(chv);
        struct no *aux,*nv;
    if(t->tab[x]==NULL){
        aux = (struct no*) malloc(sizeof(struct no));
        aux->chave = chv;
        aux->prox = NULL;
        aux->ant = NULL;
        t->tab[x]=aux;
    }else{
        nv = (struct no*) malloc(sizeof(struct no));
        aux = t->tab[x];
        nv->chave = chv;
        nv->prox = NULL;
        while(aux->prox!=NULL){
            aux = aux->prox;
        }
        aux->prox = nv;
        nv->ant = aux;
    }
}


void Imprimir(Tabela *t){
    struct no *aux;

    for(int i=0;i<=10;i++){
        aux = t->tab[i];
        printf("tab[%d] = ",i);
        while(aux!=NULL){
            printf("%d ",aux->chave);
            aux = aux->prox;
        }
    printf("...\n");
}
}
