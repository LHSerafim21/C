#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int n;
    struct no *prox;
}No;

typedef struct pilha{
    struct no *topo;
}Pilha;

void inicializaPilha(Pilha *p){
    system("cls");
    p->topo = -1;
    printf("Pilha inicializada!!");
    sleep(1);
}

int main(){

    Pilha p;
    int x=1, n;

    while(x!=0){

        system("cls");
        printf("teste");
        printf("Digite o numero desejado\n\n1-Inicializa Pilha\n");
        scanf("%d",&n);

        switch(n){
            case 0: x=0;
            case 1: inicializaPilha(&p);break;
            case 2: inserirPilha(&p);break;
            case 3:break;
        }
    }
}

