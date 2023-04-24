#ifndef BINARIZACAO_H_INCLUDED
#define BINARIZACAO_H_INCLUDED
#endif // BINARIZACAO_H_INCLUDED

int** funcaoAlocarMatrizB(int x, int y){

    int **matriz;

    matriz = (int **) calloc(x, sizeof(int *));
    for(int i = 0; i < x; i++){
        matriz[i] = (int *) calloc(y, sizeof(int));
    }
    return matriz;

}

void Principal__Binarizacao(){

    system("cls");
    int linha, coluna,A,i,j,brilho,e;
    char Linha1[5], Linha2[100];
    int** MatrizOriginal;
    int** MatrizEspelhada;

    //-------------------Abrir Arquivo-------------------------

    FILE *arq;
    arq = fopen("Imagem2.pgm", "r");

    if (arq == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
        return;
    }

    fgets(Linha1, 5 , arq);
    fgets(Linha2, 100 , arq);
    fscanf(arq,"%d %d",&coluna,&linha);
    fscanf(arq,"%d",&brilho);

    MatrizOriginal = funcaoAlocarMatrizB(coluna, linha);
    MatrizEspelhada = funcaoAlocarMatrizB(coluna, linha);

    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            fscanf(arq, "%d", &A);
            MatrizOriginal[i][j]=A;
        }
    }

    fclose(arq);

    //----------------Binarizacao-----------------------------



        for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){

            if(MatrizOriginal[i][j] <= 112){
                MatrizEspelhada[i][j] = 0;
            }
            else{
                MatrizEspelhada[i][j] = 1;
            }
        }
        }

    //--------------------Criar nova matriz-----------------------

    arq = fopen("MatBinarizacaoHistograma.pgm", "w");
    fprintf(arq,"P2\n");
    fprintf(arq,"%d %d\n", coluna, linha);
    fprintf(arq,"%d\n", brilho);



    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            fprintf(arq, "%3d\n",MatrizEspelhada[i][j]);
            //fprintf(arq, "%3d\n",MatrizOriginal[i][j]);
        }
    }

    system("cls");
    printf("Coluna:%d Linha:%d\nBrilho:%d\nOperacao Concluida\n",coluna,linha,brilho);
    sleep(3);
    fclose(arq);

    return 0;

}
