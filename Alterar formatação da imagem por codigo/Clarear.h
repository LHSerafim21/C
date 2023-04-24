#ifndef CLAREAR_H_INCLUDED
#define CLAREAR_H_INCLUDED
#endif // CLAREAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

int** funcaoAlocarMatrizA(int x, int y){

    int **matriz;

    matriz = (int **) calloc(x, sizeof(int *));
    for(int i = 0; i < x; i++){
        matriz[i] = (int *) calloc(y, sizeof(int));
    }
    return matriz;
}

void Principal__Clarear(){

    system("cls");
    int linha, coluna,A,i,j,brilho,e;
    char Linha1[5], Linha2[100];
    int** MatrizOriginal;
    int** MatrizEspelhada;

    //-------------------Abrir Arquivo-------------------------

    FILE *arq;
    arq = fopen("Imagem1.pgm", "r");

    if (arq == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
        return;
    }

    fgets(Linha1, 5 , arq);
    fgets(Linha2, 100 , arq);
    fscanf(arq,"%d %d",&coluna,&linha);
    fscanf(arq,"%d",&brilho);

    MatrizOriginal = funcaoAlocarMatrizA(coluna, linha);
    MatrizEspelhada = funcaoAlocarMatrizA(coluna, linha);

    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            fscanf(arq, "%d", &A);
            MatrizOriginal[i][j]=A;
        }
    }

    fclose(arq);

    //---------------------escurecer Matriz-----------------------

    printf("Digite a porcentagem de Clareamento da imagem:\n");
    scanf("%d",&e);

    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            MatrizEspelhada[i][j]= (MatrizOriginal[i][j]+e);
        }
    }

    //--------------------Criar nova matriz-----------------------

    arq = fopen("MatClareada.pgm", "w");
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

