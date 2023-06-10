#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int n;
    struct node *prox;
}node;

int main(){
    node a[] = {};
    node *p;
    node no;
    node no1;
    no.n = 10;
    no.prox = &no1;
    no1.n = 20;
    no1.prox = NULL;
    p = &no;
    a[0] = no;
    printf("Endereço de no: %d\n", &no);
    printf("Valor de no.n = %d\n", no.n);
    printf("Valor de no.prox = %d\n", no.prox);
    printf("Endereço de no1: %d\n", &no1);
    printf("Valor de no1.n = %d\n", no.prox->n);
    printf("Valor de no1.prox = %d\n", no.prox->prox);
    printf("Endereco de p = %d\n", &p);
    printf("Endereco apontado por p = %d\n", p);
    printf("Valor no endereço apontado por p = %d\n", *p);
    printf("Endereco de a[0] = %d\n", &a[0]);
    printf("Conteudo de a[0] (primeiro elemento da lista) = %d\n", a[0]);
    printf("Segundo elemento da lista: %d\n", a[0].prox->n);
return 0;
}
