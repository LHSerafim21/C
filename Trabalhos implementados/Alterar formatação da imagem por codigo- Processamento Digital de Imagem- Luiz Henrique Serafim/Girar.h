#ifndef GIRAR_H_INCLUDED
#define GIRAR_H_INCLUDED
#endif // GIRAR_H_INCLUDED

void Inverter(){

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

    //----------------------Inverter matriz-------------------

    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            MatrizEspelhada[i][j] = MatrizOriginal[i][coluna-j];
        }
    }
    //----------------------Criar nova matriz--------------

    arq = fopen("MatInvertida.pgm", "w");
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

    return 0;
}

void Girar90_AntiHorario(){

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

    //-----------------Girar 90° AntiHorario matriz-------------------

    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            MatrizEspelhada[i][j] = MatrizOriginal[j][linha-i];

        }
    }
    //----------------------Criar nova matriz--------------

    arq = fopen("MatGirada90_AntiHorario.pgm", "w");
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

void Girar90_Horario(){

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

    //----------------------Girar 90° Horario matriz-------------------

    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            MatrizEspelhada[j][coluna-i] = MatrizOriginal[i][j];

        }
    }
    //----------------------Criar nova matriz--------------

    arq = fopen("MatGirada90_Horario.pgm", "w");
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

void Girar180(){

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

    //----------------------Girar matriz  180°-------------------

    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            MatrizEspelhada[j][coluna-i] = MatrizOriginal[i][j];

        }
    }

    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            MatrizOriginal[j][coluna-i] = MatrizEspelhada[i][j];

        }
    }

    //----------------------Criar nova matriz--------------

    arq = fopen("MatGirada180.pgm", "w");
    fprintf(arq,"P2\n");
    fprintf(arq,"%d %d\n", coluna, linha);
    fprintf(arq,"%d\n", brilho);



    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            fprintf(arq, "%3d\n",MatrizOriginal[i][j]);
            //fprintf(arq, "%3d\n",MatrizOriginal[i][j]);
        }
    }

    system("cls");
    printf("Coluna:%d Linha:%d\nBrilho:%d\nOperacao Concluida\n",coluna,linha,brilho);
    sleep(3);
    fclose(arq);

    return 0;
}

void Principal__Girar(){

    int a;

    system("cls");
    printf("Digite a opcao desejada: \n0- Inverter imagem\n1- Girar 90 graus ANTI-HORARIO\n2- Girar 90 graus HORARIO\n3- Girar 180 graus\n");
    scanf("%d",&a);

    switch(a){
        case 0: Inverter(); break;
        case 1: Girar90_AntiHorario(); break;
        case 2: Girar90_Horario(); break;
        case 3: Girar180();break;
    }
}
