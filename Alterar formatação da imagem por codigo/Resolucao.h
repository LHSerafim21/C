#ifndef RESOLUCAO_H_INCLUDED
#define RESOLUCAO_H_INCLUDED
#endif // RESOLUCAO_H_INCLUDED

int** funcaoAlocarMatrizC(int x, int y){

    int **matriz;

    matriz = (int **) calloc(x, sizeof(int *));
    for(int i = 0; i < x; i++){
        matriz[i] = (int *) calloc(y, sizeof(int));
    }
    return matriz;

}

void Replicacao(){

    system("cls");
    int linha, coluna,A,i,j,brilho,e;
    char Linha1[5], Linha2[100];
    int** MatrizOriginal;
    int** MatrizEspelhada;

    //-------------------Abrir Arquivo-------------------------

    FILE *arq;
    arq = fopen("Imagem3.pgm", "r");

    if (arq == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
        return;
    }

    //----------------Ler informacoes do arquivo-------------

    fgets(Linha1, 5 , arq);
    fgets(Linha2, 100 , arq);
    fscanf(arq,"%d %d",&coluna,&linha);
    fscanf(arq,"%d",&brilho);

    //-----------------Alocar Matrizes------------------------

    MatrizOriginal = funcaoAlocarMatrizC(linha, coluna);
    MatrizEspelhada = funcaoAlocarMatrizC(linha, coluna);

    //------Passar as informações do arquivo para a matriz---

    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            fscanf(arq, "%d", &A);
            MatrizOriginal[i][j]= A;
        }
    }

    fclose(arq);

    //-------------------Replicacao------------------------

    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){

            MatrizEspelhada[2*i][2*j] = MatrizOriginal[i][j];
            MatrizEspelhada[2*i+1][2*j] = MatrizOriginal[i][j];
            MatrizEspelhada[2*i][2*j+1] = MatrizOriginal[i][j];
            MatrizEspelhada[2*i+1][2*j+1] = MatrizOriginal[i][j];
        }
    }

    //-----Criar e passar as novas informacoes para a matriz----

    arq = fopen("MatReplicacao.pgm", "w");
    fprintf(arq,"P2\n");
    fprintf(arq,"%d %d\n", coluna, linha);
    fprintf(arq,"%d\n", brilho);



    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            fprintf(arq, "%d\n",MatrizEspelhada[i][j]);
            //fprintf(arq, "%3d\n",MatrizOriginal[i][j]);
        }
    }

    system("cls");
    printf("Coluna:%d Linha:%d\nBrilho:%d\nOperacao Concluida\n",coluna,linha,brilho);
    sleep(3);
    fclose(arq);

    return 0;
}

void Media(){

    system("cls");
    int linha, coluna,A,i,j,brilho,e;
    char Linha1[5], Linha2[100];
    int** MatrizOriginal;
    int** MatrizEspelhada;

    //-------------------Abrir Arquivo-------------------------

    FILE *arq;
    arq = fopen("Imagem4.pgm", "r");

    if (arq == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
        return;
    }

    fgets(Linha1, 5 , arq);
    fgets(Linha2, 100 , arq);
    fscanf(arq,"%d %d",&coluna,&linha);
    fscanf(arq,"%d",&brilho);

    //-----------------Alocar Matrizes------------------------

    MatrizOriginal = funcaoAlocarMatrizC(linha, coluna);
    MatrizEspelhada = funcaoAlocarMatrizC(linha, coluna);

    //int MatrizOriginal[452][374], MatrizEspelhada[452][374];

    //------Passar as informações do arquivo para a matriz---

    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            fscanf(arq, "%d", &A);
            MatrizOriginal[i][j]= A;
        }
    }

    fclose(arq);

    //----------------Media-----------------------------

        for(i=0; i < (linha/2); i++){
            for(j=0; j < (coluna/2); j++){
                float valor = MatrizOriginal[2*i][2*j] + MatrizOriginal[2*i][2*j+1] + MatrizOriginal[2*i+1][2*j] + MatrizOriginal[2*i+1][2*j+1];
                MatrizEspelhada[i/2][j/2] = (int)(valor/4.00);
            }
        }

    //-----Criar e passar as novas informacoes para a matriz----

    arq = fopen("MatMedia.pgm", "w");
    fprintf(arq,"P2\n");
    fprintf(arq,"%d %d\n", coluna, linha);
    fprintf(arq,"%d\n", brilho);



    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            fprintf(arq, "%d\n",MatrizEspelhada[i][j]);
            //fprintf(arq, "%3d\n",MatrizOriginal[i][j]);
        }
    }

    system("cls");
    printf("Coluna:%d Linha:%d\nBrilho:%d\nOperacao Concluida\n",coluna,linha,brilho);
    sleep(3);
    fclose(arq);

    return 0;

}

void Principal__Resolucao(){

    system("cls");
    int a;

    while(a != 0){
        system("cls");
        printf("Digite o numero para a resolucao da imagem: \n0- SAIR\n1- Replicacao\n2- Media\n");
        scanf("%d",&a);

        switch(a){
            case 0: a=0;
            case 1: Replicacao(); break;
            case 2: Media(); break;
        }
    }
    return 0;
}
