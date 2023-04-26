#ifndef HISTOGRAMA_H_INCLUDED
#define HISTOGRAMA_H_INCLUDED
#endif // HISTOGRAMA_H_INCLUDED

int** funcaoAlocarMatrizE(int x, int y){

    int **matriz;

    matriz = (int **) calloc(x, sizeof(int *));
    for(int i = 0; i < x; i++){
        matriz[i] = (int *) calloc(y, sizeof(int));
    }
    return matriz;

}

void Principal__Histograma(){

    system("cls");
    int linha, coluna,A,i,j,max,e;
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
    fscanf(arq,"%d",&max);

    MatrizOriginal = funcaoAlocarMatrizE(linha, coluna);

    //----Passar as informações do arquivo para a matriz---

    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            fscanf(arq, "%d", &A);
            MatrizOriginal[i][j]= A;
        }
    }

    fclose(arq);

    //----------------Histograma----------------------------



    //-----Criar e passar as novas informacoes para a matriz----

    arq = fopen("MatHistograma.pgm", "w");

    if(arq != NULL) {
        for(int i = 0; i < max; i++) {
            fprintf(arq, "%d\n", vetor[i]);
        }

    fclose(arq);




}
