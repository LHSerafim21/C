#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// Implementação de uma lista estatica de int

typedef struct lista{
    int v[MAX];
    int quantElem;
}lista;

void inicializaLista(lista *Aux){
    Aux->quantElem = 0;
    Aux->v[0] = -1;
    printf("Quantidade de elementos na lista: %d\n", Aux->quantElem);
    printf("Primeiro elemento na lista: %d", Aux->v[0]);
}

int main()
{
    lista L;
    inicializaLista(&L);

    return 0;
}
