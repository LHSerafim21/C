#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct pilha{
    int vetor[MAX];
    int topo;
}Pilha;

void inicializarPilha(Pilha* p){

    system("cls");
    p->topo = 0;
    printf("Pilha Inicializada");
    sleep(1);
}

void inserirPilha(Pilha* p){

    system("cls");
    int y;
    printf("Digite o elemento que deseja inserir: \n");
    scanf("%d",&y);

    if(p->topo == MAX){
        system("cls");
        printf("A Pilha esta cheia\n");
        sleep(1);
    }else{
        p->vetor[p->topo] = y;
        p->topo++;
        printf("Elemento %d Inserido!!\n",y);
        sleep(1);
    }
}

int removerPilha(Pilha* p){

    printarPilha(p);

    if(p->topo == 0){
        printf("A pilha esta vazia!!");
        sleep(1);
    }else{
        p->topo--;
        int aux = p->vetor[p->topo];
        p->vetor[p->topo] = -1;
        system("cls");
        printarPilha(p);
        printf("Elemento Removido!!");
        return aux;
    }
}

void printarPilha(Pilha* p){

    system("cls");
    if (p->topo == 0){
        printf("Pilha vazia\n");
    }else{
        printf("Base: ");
        for (int i=0; i < p->topo; i++){
            printf("| %d ", p->vetor[i]);
        }
    }
    sleep(2);
}

int main(){
   Pilha p;
   int n,x=1;

  while(x!=0){

    system("cls");
    printf("Digite oque deseja\n\n1-Inicializar\n2-Inserir\n3-Remover\n4-Printar\n");
    scanf("%d",&n);

    switch(n){
        case 0: x=0;break;
        case 1: inicializarPilha(&p);break;
        case 2: inserirPilha(&p);break;
        case 3: removerPilha(&p);break;
        case 4: printarPilha(&p);break;
    }
  }
}
