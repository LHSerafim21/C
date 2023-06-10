#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// Implementação de uma lista estatica de int

typedef struct lista{
    int v[MAX];
    int quantElem;
}lista;

void inicializaLista(lista *ptr){
    ptr->quantElem = 0;
    ptr->v[0] = -1;
    printf("Quantidade de elementos na lista: %d\n", ptr->quantElem);
    printf("Primeiro elemento na lista: %d\n", ptr->v[0]);
}

int vazia(lista *ptr){
    if (ptr->quantElem == 0){
        return 1;
    }
    return 0;
}

void inserirInicioLista(lista *Aux, int num){
    if (vazia(Aux))
    {
        Aux->v[0] = num;
        Aux->quantElem++;
    }
    else // Lista não está vazia!
    {
        for (int i=Aux->quantElem; i>0; i--){
            Aux->v[i] = Aux->v[i-1];
        }
        Aux->v[0] = num;
        Aux->quantElem++;
    }
}

void inserirFinalLista(lista *Aux, int num){
    if (vazia(Aux))
    {
        Aux->v[0] = num;
        Aux->quantElem++;
    }
    else // Lista não está vazia!
    {
        Aux->v[Aux->quantElem] = num;
        Aux->quantElem++;
    }
}

void inserirMeioLista(lista *Aux, int num, int pos){
    if (vazia(Aux))
    {
        Aux->v[0] = num;
        Aux->quantElem++;
    }
    else // Lista não está vazia!
    {
        for (int i=Aux->quantElem ; i>pos; i--){
            Aux->v[i] = Aux->v[i-1];
        }
        Aux->v[pos] = num;
        Aux->quantElem++;
    }
}

void printarLista(lista *Aux){
    if (vazia(Aux))
    {
        printf("Lista vazia!");
    }
    else // Lista não está vazia!
    {
        for (int cont=0; cont < (Aux->quantElem) ; cont++){
            printf("%d\t", Aux->v[cont]);
        }
    }
}

int main()
{
    lista L;
    inicializaLista(&L);
    inserirInicioLista(&L, 2);
    inserirInicioLista(&L, 9);
    inserirInicioLista(&L, 21);
    inserirMeioLista(&L, 18, 2);
    printarLista(&L);
    getchar();
    return 0;
}
