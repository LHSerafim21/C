#include <stdio.h>
#include <stdlib.h>

void funcao_espelhada_Horizontal(){
    //------------------------------Matriz Espelhada Horizontalmente------------------------
    system("cls");
    int linha, coluna,A,i,j,brilho;
    char Linha1[5], Linha2[100];

    FILE *arq;
    arq = fopen("MatOrig.pgm", "r");

    if (arq == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
        return;
    }

    fgets(Linha1, 5 , arq);
    fgets(Linha2, 100 , arq);
    fscanf(arq,"%d %d",&coluna,&linha);
    fscanf(arq,"%d",&brilho);

    int MatrizOriginal[452][374], MatrizEspelhada[452][374];

    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            fscanf(arq, "%d ", &A);
            MatrizOriginal[i][j] = A;
        }
    }

    fclose(arq);

    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            MatrizEspelhada[i][j] = MatrizOriginal[i][coluna-j];
        }
    }

    arq = fopen("MatEspelhadaHorizontalmente.pgm", "w");
    fprintf(arq,"P2\n");
    fprintf(arq,"%d %d\n", coluna, linha);
    fprintf(arq,"%d\n", brilho);



    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            fprintf(arq, "%3d\n",MatrizEspelhada[i][j]);
            //fprintf(arq, "%3d\n",MatrizOriginal[i][j]);
        }
    }
    printf("Coluna:%d Linha:%d\nBrilho:%d\nOperacao Concluida\n",coluna,linha,brilho);
    sleep(3);
    fclose(arq);
}

void funcao_espelhada_Verticalmente(){
    system("cls");
    int linha, coluna,A,i,j,brilho;
    char Linha1[5], Linha2[100];

    FILE *arq;
    arq = fopen("MatOrig.pgm", "r");

    if (arq == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
        return;
    }

    fgets(Linha1, 5 , arq);
    fgets(Linha2, 100 , arq);
    fscanf(arq,"%d %d",&coluna,&linha);
    fscanf(arq,"%d",&brilho);

    int MatrizOriginal[452][374], MatrizEspelhada[452][374];

    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            fscanf(arq, "%d ", &A);
            MatrizOriginal[i][j] = A;
        }
    }

    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            MatrizEspelhada[i][j] = MatrizOriginal[linha-i][j];
        }
    }

    fclose(arq);
    arq = fopen("MatEspelhadaVerticalmente.pgm", "w");
    fprintf(arq,"P2\n");
    fprintf(arq,"%d %d\n", coluna, linha);
    fprintf(arq,"%d\n", brilho);



    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            fprintf(arq, "%3d\n",MatrizEspelhada[i][j]);
            //fprintf(arq, "%3d\n",MatrizOriginal[i][j]);
        }
    }

    printf("Coluna:%d Linha:%d\nBrilho:%d\nOperacao Concluida\n",coluna,linha,brilho);
    sleep(3);
    fclose(arq);

}

void funcao_Binarizacao_histograma(){

    system("cls");
    int linha, coluna,A,i,j,brilho;
    char Linha1[5], Linha2[100];

    FILE *arq;
    arq = fopen("MatOrig.pgm", "r");

    if (arq == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
        return;
    }

    fgets(Linha1, 5 , arq);
    fgets(Linha2, 100 , arq);
    fscanf(arq,"%d %d",&coluna,&linha);
    fscanf(arq,"%d",&brilho);

    int MatrizOriginal[452][374], MatrizEspelhada[452][374];

    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            fscanf(arq, "%d ", &A);
            MatrizOriginal[i][j] = A;
        }
    }

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
    fclose(arq);

    fclose(arq);
    arq = fopen("MatEspelhadaBinarizacao.pgm", "w");
    fprintf(arq,"P2\n");
    fprintf(arq,"%d %d\n", coluna, linha);
    fprintf(arq,"%d\n", 1);



    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            fprintf(arq, "%3d\n",MatrizEspelhada[i][j]);
            //fprintf(arq, "%3d\n",MatrizOriginal[i][j]);
        }
    }

    printf("Coluna:%d Linha:%d\nOperacao Concluida\n",coluna,linha);
    sleep(3);
    fclose(arq);
}

funcao_Reducao_Nivel_Cinza(){
    system("cls");
    int linha, coluna,A,i,j,brilho;
    char Linha1[5], Linha2[100];

    FILE *arq;
    arq = fopen("MatOrig.pgm", "r");

    if (arq == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
        return;
    }

    fgets(Linha1, 5 , arq);
    fgets(Linha2, 100 , arq);
    fscanf(arq,"%d %d",&coluna,&linha);
    fscanf(arq,"%d",&brilho);

    int MatrizOriginal[452][374], MatrizEspelhada[452][374];

    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            fscanf(arq, "%d ", &A);
            MatrizOriginal[i][j] = A;
        }
    }

    fclose(arq);
    //-----------------------------------------------------------------------------

    printf("Digite a porcentagem de brilho que deseja diminuir");

    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            MatrizEspelhada[i][j]= (MatrizOriginal[i][j]-50);
        }
    }

    //-----------------------------------------------------------------------------
    arq = fopen("MatReducao_Nivel_Cinza.pgm", "w");
    fprintf(arq,"P2\n");
    fprintf(arq,"%d %d\n", coluna, linha);
    fprintf(arq,"%d\n", brilho);



    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            fprintf(arq, "%3d\n",MatrizEspelhada[i][j]);
            //fprintf(arq, "%3d\n",MatrizOriginal[i][j]);
        }
    }
    printf("Coluna:%d Linha:%d\nOperacao Concluida\n",coluna,linha,brilho);
    sleep(3);
    fclose(arq);

}

int main()
{
    int quebra,n;

    while(quebra==0){

        system("cls");
        printf("DIGITE A OPERACAO DESEJADA:\n\n0- SAIR\n1- Espelhar Horizontalmente\n2- Espelhar Verticalmente\n3- Binarizacao Histograma\n4- Reducao Nivel Cinza\n");
        scanf("%d",&n);

        switch(n){
            case 0:quebra=1;system("cls");break;
            case 1:funcao_espelhada_Horizontal();break;
            case 2:funcao_espelhada_Verticalmente();break;
            case 3:funcao_Binarizacao_histograma();break;
            case 4:funcao_Reducao_Nivel_Cinza();break;
            default:system("cls");printf("NUMERO INVALIDO, DIGITE NOVAMENTE!!");sleep(3);break;
        }

    }


return 0;
}

