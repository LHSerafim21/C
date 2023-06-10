#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char c;
    struct node *prox;
}node;

typedef struct lista{
    struct node *prim;
}lista;

void inicializar(lista *lista){
    lista->prim = NULL;
    if (lista->prim == NULL){
        printf("Lista inicializada com sucesso!\n");
    }
}

void inserir_elemento(lista *lista, char carac){
    node* novoNo = (node*) (malloc(sizeof(node)));
    novoNo->c = carac;
    novoNo->prox = NULL;

    if (lista->prim == NULL){       // LISTA VAZIA
        lista->prim = novoNo;
        printf("\nInserido em lista vazia!\n");
    }else{                          //LISTA NAO VAZIA
        node* aux = lista->prim;
        for (; aux->prox != NULL; ){
            aux = aux->prox;
        }
        aux->prox = novoNo;
        printf("\nInserido em lista NAO vazia!\n");
    }
}

int print_lista(lista *lista){
    printf("\n");
    if (lista->prim == NULL){
        printf("String vazia!\n");
        return 0;
    }
    node* aux = lista->prim;
    for (; aux->prox != NULL;){
        printf("%c",aux->c);
        aux = aux->prox;
    }
    printf("%c\n",aux->c);
}

void print_menu(){
    printf("\nMENU\n");
    printf("1 - Inserir caractere na String\n");
    printf("2 - Printar String\n");
    printf("3 - Reinicializar String\n");
    printf("4 - Printar Tamanho da String\n");
    printf("9 - SAIR\n");
}

void reinicializar(lista *lista){
    node *atual = lista->prim;
    node *prox = NULL;
    while (atual != NULL){
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
    lista->prim = atual;
    if (lista->prim == NULL){
        printf("\nString reinicializada com sucesso!\n");
    }
}

void tamanho_lista(lista *lista){
    node *aux = lista->prim;
    int cont = 0;
    while (aux != NULL){
        cont++;
        aux = aux->prox;
    }
    printf("\nTamanho da String: %d\n",cont);
}

int main()
{
    lista lista;
    inicializar(&lista);
    char carac;
    int opcao = 0;

    while (opcao != 9){
        print_menu();
        printf("\nDigite a opcao escolhida: ");
        scanf("%d",&opcao);
        fflush(stdin);

        switch (opcao){
            case 1: //INSERIR CARACTERE NA STRING
                printf("Digite uma letra: ");
                scanf("%c",&carac);
                inserir_elemento(&lista, carac);
                fflush(stdin);
                break;

            case 2: //PRINTAR STRING
                print_lista(&lista);
                break;

            case 3: //REINICIALIZAR STRING
                reinicializar(&lista);
                break;

            case 4: //RETORNAR O TAMANHO DA STRING
                tamanho_lista(&lista);
                break;

            case 9:
                printf("\nObrigado por usar o programa!\n");
                return 0;
        }
    }
    printf("Digite uma letra: ");
    scanf("%c",&carac);
    inserir_elemento(&lista, carac);
    fflush(stdin);
    print_lista(&lista);
    return 0;
}
