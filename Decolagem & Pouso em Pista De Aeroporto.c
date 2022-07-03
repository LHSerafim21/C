/*/O aeroporto possui uma única pista, na qual aviões podem pousar e decolar. Os aviões &quot;aparecem&quot;
aleatoriamente a intervalos entre 1 e 5 segundos e devem entrar na fila de pouso ou decolagem. Os aviões na
fila de pouso têm prioridade. Ou seja, os aviões que desejam decolar devem aguardar até que a fila de pouso
esteja vazia. Ao chegar à fila, os aviões solicitam pouso ou decolagem à torre de controle. Por sua vez, a torre
de controle aguarda que a pista seja liberada e autoriza o próximo avião. Após liberados, os aviões levam 5
segundos para decolar e 10 segundos para pousar. Ao final do pouso/decolagem, deve ser mostrado o tempo
total de espera (tempo entre a chegada ao aeroporto e o final do procedimento. Considerando que as funções
de inserção e remoção na fila estão prontas, implemente o processo de simulação descrito acima./*/

#include "Aeroporto.h"

int ramdom(int x){
    return 1 + rand()%x;
}

void CriaFila(Fila *f){
    f->inicio = NULL;
    f->fim = NULL;
}

bool vazia(Fila *fila) {
	if (fila->inicio == NULL) return true;
else return false;
}

bool cheia(Fila *fila) {
    struct noFila *novoNo;
    novoNo = (struct noFila*) malloc(sizeof(struct noFila));
        if (novoNo == NULL) return true;
    else return false;
}


void InserirAviao(Fila *p,Fila *d, int t){
    struct noFila *novo;
    novo = (struct noFila*) malloc (sizeof(struct noFila));
    novo->aviao = ramdom(1000);
    novo->tempo = t;
    novo->prox = NULL;
    int x = ramdom(5);
    if(x==1){
        if(vazia(p)){
            p->inicio = novo;
            p->fim = novo;
        }else{
            p->fim->prox = novo;
            p->fim = novo;
        }
        printf("Aviao %d entrou na fila de pouso\n",novo->aviao);
    }else{
        if(vazia(d)){
            d->inicio = novo;
            d->fim = novo;
        }else{
            d->fim->prox = novo;
            d->fim = novo;
        }
        printf("Aviao %d entrou na fila de decolagem\n",novo->aviao);
    }
}

void RemoverAviao(Fila *p,Fila *d,int *t){
    struct noFila *aux;
    if(vazia(p)){
        if(vazia(d)){
            printf("Pista vazia");
        }else{
            aux = d->inicio;
            printf("Aviao %d saiu da fila de decolagem",aux->aviao);
            *t = aux->tempo;
            d->inicio = d->inicio->prox;
            free(aux);
        }
    }else{
        aux = p->inicio;
        printf("Aviao %d saiu da fila de pouso",aux->aviao);
        *t = aux->tempo;
        p->inicio = p->inicio->prox;
        free(aux);
    }
}

void Imprimir(Fila *f){
    struct noFila *aux = f->inicio;
    while(aux!=NULL){
        printf("%d , ",aux->aviao);
        aux = aux->prox;
    }
}

void Simulacao(Fila *p,Fila *d){
    int tsimula = 500, tatual = 1;
    int i=0,r=0, jp=11,jd=5;
    while(tatual<=tsimula){
        printf("Tempo: %ds\n",tatual);
        if(i==0){
            i = ramdom(5);
           }
        if(i==1){
                InserirAviao(p,d,tatual);
            }
            if(vazia (p) && vazia(d)){
                    jd = 6;
                    jp = 11;
                }else{
                    if(vazia(p)){
                        r = 1;
                        jp = 11;
                    }else{
                        r = 2;
                        jd = 6;
                    }
                    }
                if((r==1) && (jd==0)){
                    int x;
                    RemoverAviao(p,d,&x);
                    printf(", Tempo de espera de %d segundos\n",tatual-x);
                    jd = 5;
                }
                if((r==2) && (jp==0)){
                    int x;
                    RemoverAviao(p,d,&x);
                    printf(", Tempo de espera de %d segundos\n",tatual-x);
                    jp = 11;
                }
                 i--;
                 jp--;
                 jd--;

                 printf("\nFILA DE POUSO --> ");
                 Imprimir(p);
                 printf("\nFILA DE DECOLAGEM --> ");
                 Imprimir(d);

            Sleep(3000); //Tempo em milisegundos (3000 = 3 segundos)
            system("cls");
            tatual++;
    }

    }
