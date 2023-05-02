
#include "TPF.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Transformar_Grafo(char n_arq[],Grafo *mat){                                        //Transforma o grafo em arquivo para matriz de adjascencia

    FILE *arq = fopen(n_arq,"r");

    if(arq!=NULL){
        int i, j;

        fscanf(arq,"%d", &mat->n);                                                      //Guarda o numero de vertices

        for (i = 0; i <= mat->n; i++) {                                                 // Primeiramente declara todos os elementos da matriz como infinito
            for (j = 0; j <= mat->n; j++) {
                mat->grafo[i][j] = INFINITO;
            }
        }

        fscanf(arq,"%d", &mat->m);                                                      //Variavel que guarda o numero de arestas

        for (i = 0; i < mat->m; i++) {                                                  //Pega os vertices e o peso entre eles e declara a posicao da matriz com o peso determinado
            int Vinicial, Vfinal, peso;
            fscanf(arq,"%d %d %d", &Vinicial, &Vfinal, &peso);
            mat->grafo[Vinicial][Vfinal] = peso;
        }

            fclose(arq);
    }else{
        printf("O arquivo inexistente");
    }

}

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void imprimir_grafo(Grafo *mat){                                                        //Imprimir a matriz de adjascencia do grafo
    printf("Matriz de adjascencia que representa o grafo:\n");
    int i, j;
    printf("    ");
    for(i=1;i<=mat->n;i++) printf("%d  ",i);                                            //Imprime os vertices na parte de cima da matriz
    printf("\n");
    for (i = 1; i <= mat->n; i++) {                                                     //Imprime os vertices na esquerda da matriz
        printf("%d: ",i);
        for (j = 1; j <= mat->n; j++) {                                                  //Imprime o peso dos vertices no local correto
            if (mat->grafo[i][j] == INFINITO) {
                printf("IF ");
            } else {
                printf("%.2d ", mat->grafo[i][j]);
            }
        }
        printf("\n");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ImprimirMenorCaminho(Grafo *G,int s, int v){                                                 //Imprimir o menor caminho de um vertice ate outro
    if(v==s){
        printf(" %d",s);
    }else if(G->pi[v]==-1){
        printf("Nao existe trajeto");
    }else{
        ImprimirMenorCaminho(G,s,G->pi[v]);
        printf(" %d",v);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InicializaVetores(Grafo *G,int s) {                                                        //Inicializa os vetores d e pi
  for (int i = 0; i <= G->n; i++) {
    G->d[i] = INFINITO;                                                                 //Todos os elementos de d recebem o peso infinito
    G->pi[i] = -1;                                                                      //Todos os elementos de pi recebem -1, representando o NULL
  }
  G->d[s] = 0;                                                                          //A posicao inicial recebe 0 para que se comece por ela
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void EncontrarCaminhosMenores(int u, int v, Grafo *G,int Q[]) {                          //Encontrar caminhos menores
  if (G->d[v] > G->d[u] + G->grafo[u][v]) {                                              //Caso haja um caminho com peso menor do que o determinado anteriormente,
    G->d[v] = G->d[u] + G->grafo[u][v];                                                 //  o vetor d na posicao deste vertice vai receber o menor peso
    G->pi[v]=u;
    Q[v] = G->d[v];                                                                     //Q guarda todas as alteracoes feitas em d
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void EncontrarCaminhosMenoresA(int u, int v, Grafo *G) {                                //Encontrar caminhos menores
  if (G->d[v] > G->d[u] + G->grafo[u][v]) {                                             //Caso haja um caminho com peso menor do que o determinado anteriormente,
    G->d[v] = G->d[u] + G->grafo[u][v];                                                 //  o vetor d na posicao deste vertice vai receber o menor peso
    G->pi[v]=u;
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int EncontrarVerticesPesoMinimo(int Q[],int n){                                                              //Encontrar o vertice de peso minimo no momento
    int aux = INFINITO;
    int min;
    for(int i=0;i<=n;i++){                                                              //Como Q guarda as alteracoes de d, procuramos nele o valor minimo em cada momento, ignorando o NULL
        if(Q[i]!=-1 && Q[i]<=aux){
            aux = Q[i];
            min = i;
        }
    }
    return min;                                                                         //Retorna o vertice com o menor peso no momento
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Dijkstra(Grafo *G, int s) {                                                        //Encontrar o menor caminho entre 2 vertices
  int Q[G->n];

  InicializaVetores(G,s);                                                                      //Os vetores sao inicializados


  for(int i=1;i<=G->n;i++){                                                              //Q recebe todo o vetor d
    Q[i]= G->d[i];
    }

  for (int i = 1; i <= G->n ; i++) {                                                    //Laco e feito de acordo com a quantidade de vertices

    int u = EncontrarVerticesPesoMinimo(Q,G->n);                                                            // u recebe o vertice com peso minimo no momento

    for (int v = 1; v <= G->n; v++) {                                                   //O relaxamento e realizado para todos os adjascentes do vertice u
        if(G->grafo[u][v]!=INFINITO && G->grafo[u][v]>0){                               //So e feito o relaxamento se o vertice nao for negativo
            EncontrarCaminhosMenores(u,v,G,Q);
        }
    }
    Q[u]=-1;                                                                            //Como o vertice u ja foi totalmente manipulado o vetor Q o tona nulo denovo para evitar que seja usado novamente
  }

  printf("\nMelhor caminho para cada vertice, saindo do %d:\n",s);                      //lacos para exibir todos os menores caminhos e seus pesos
  for (int i = 1; i <= G->n; i++) {
    printf("%d:  ",i);
    ImprimirMenorCaminho(G,s,i);

    //Condicional para formatar a visualicao dos pesos
    if(s==i){
        printf("\t\t\t Peso: %d\n",G->d[i]);
    }else if(G->d[i] == INFINITO){
        printf(" \n");
    }else{
        printf("\t\t Peso: %d\n",G->d[i]);
    }
  }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void BellmanFord(Grafo *G, int r){                                                      //Determinar a melhor sequencia de arestas, podendo pesos negativos
    bool pn = true;                                                                     //Se pn for falso nao ha solucao, se for true ha solucao
    InicializaVetores(G,r);

    int i,u,v;
    for(i=0; i < G->n-1;i++){                                                           //Laco que determina o numero de vezes que os caminhos sao checados
        for(u=0;u<=G->n;u++){
            for(v=0;v<=G->n;v++){                                                       //Esses dois lacos em sequencia garantem a passagem por todas as arestas
                if(G->d[u]!=INFINITO){                                                  //O relaxamento e feito para todas as arestas do vertice
                    EncontrarCaminhosMenoresA(u,v,G);
                }
            }
        }
    }

// Agora e feita a checagem de ciclos de pesos negativos
    for(u=0; u<=G->n && pn==true ;u++){
        for(v=0; v<=G->n && pn==true;v++){
            if(G->d[u]!=INFINITO){
                if (G->d[v] > G->d[u] + G->grafo[u][v]){                                //Entra no if se houver ciclo de peso negativo
                    pn = false;                                                         //Logo, nao existe solucao para o programa
                }
            }
        }
    }

    //Imprime o melhor caminho ate cada vertice do grafo partindo da raiz r

    if(pn){                                                                             //Verifica se pn e true ou false
        printf("\nMelhor caminho saindo da raiz %d ate o vertice:\n",r);
        printf("\n");
        for(i=1;i<=G->n;i++){
            printf("%d: ",i);
            ImprimirMenorCaminho(G, r, i);                                                        //saida na tela dos caminhos

        //Condicional para formatar a visualicao dos pesos
            if(r==i){
                printf("\t\t\t Peso: %d\n",G->d[i]);
            }else if(G->d[i] == G->grafo[r][i] && G->d[i]!=INFINITO){
                printf("\t\t\t Peso: %d\n",G->d[i]);
            }else if(G->pi[i]==-1){
                printf("\n");
            }else{
                printf("\t\t Peso: %d\n",G->d[i]);
            }
        }
    }else{
        printf("Ha ciclos de peso negativo no grafo, logo, nao existe solucao!\n\n");
    }
}

