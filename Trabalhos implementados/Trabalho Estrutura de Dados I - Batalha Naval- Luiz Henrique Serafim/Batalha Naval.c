#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-------------------------------------------------------------MENU INICIAR---------------------------------------------------------------*/
int funcao_menu_inicial(){

    int x=0,y,b=0;

    system("cls");
    system("color 9F");

    while(y!=1){

        system("cls");
        system("color 9F");

        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n                                                                 BATALHA NAVAL\n\n                                                          Escolha a Opicao Desejada!!\n\n                                                             1-Para iniciar o jogo\n                                                             2-Sobre\n                                                             3-Sair\n");
        printf("\n\n\n\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
        scanf("%d",&y);

        switch(y){
            case 1:funcao_jogo();y==0;return y;break;    //inicia o jogo
            case 2:funcao_sobre();y==0;return y; break;  //informacoes sobre o jogo
            case 3:y==1;return y;break;                  //sair
            default:
                system("cls");
                system ("color 4F");
                printf("\n\n                                                              Numero invalido, Digite outro numero!");
                sleep(1); break;}
    }
    getchar();
}
/*---------------------------------------------------------------SOBRE--------------------------------------------------------------------*/
int funcao_sobre(){  //Explicação Jogo

    system("cls");
    int z;

    printf("\n\n                                                                 SOBRE\n\nBatalha naval e um jogo de tabuleiro de dois jogadores, no qual os jogadores tem de adivinhar em que quadrados estao os navios do oponente. Embora o primeiro jogo em tabuleiro comercializado e publicado pela Milton Bradley Company em 1931, o jogo foi originalmente jogado com lapis e papel. Seu objectivo e derrubar os barcos do oponente adversario, ganha quem derrubar todos os navios adversarios primeiro.");
    printf(" O jogo original e jogado em duas grelhas para cada jogador, uma que representa a disposicao dos barcos do jogador, e outra que representa a do oponente. As grelhas sao tipicamente quadradas, estando identificadas na horizontal por numeros e na vertical por letras. Em cada grelha o jogador coloca os seus navios e regista os tiros do oponente.");
    printf("\n\n                                                        DIGITE 1 PARA VOLTAR PARA O MENU PRINCIPAL\n");
    scanf("%d",&z);

    if(z!=1){
            while(z!=1){
                system("cls");
                system ("color 4F");
                printf("\n\n                                                              Numero invalido, Digite outro numero!");
                sleep(1);

                system("cls");
                system ("color 9F");

                printf("\n\n                                                                 SOBRE\n\nBatalha naval e um jogo de tabuleiro de dois jogadores, no qual os jogadores tem de adivinhar em que quadrados estao os navios do oponente. Embora o primeiro jogo em tabuleiro comercializado e publicado pela Milton Bradley Company em 1931, o jogo foi originalmente jogado com lapis e papel. Seu objectivo e derrubar os barcos do oponente adversario, ganha quem derrubar todos os navios adversarios primeiro.");
                printf(" O jogo original e jogado em duas grelhas para cada jogador, uma que representa a disposicao dos barcos do jogador, e outra que representa a do oponente. As grelhas sao tipicamente quadradas, estando identificadas na horizontal por numeros e na vertical por letras. Em cada grelha o jogador coloca os seus navios e regista os tiros do oponente.");
                printf("\n\n                                                        DIGITE 1 PARA VOLTAR PARA O MENU PRINCIPAL\n");
                scanf("%d",&z);

                if(z==1){
                    z==1;
                }

            }
    }
    return funcao_menu_inicial();
}
/*-----------------------------------------------------------CRIAR TABULEIRO 1--------------------------------------------------------------*/
void funcao_cria_tabuleiro(int tabuleiro[][5])
{
    int linha, coluna;                                  //cria a matriz que sera o tabuleiro do player 1, que o player 2 vai atacar
        for(linha=0 ; linha < 5 ; linha++ )
            for(coluna=0 ; coluna < 5 ; coluna++ )
                tabuleiro[linha][coluna]=-1;
}
/*-----------------------------------------------------------CRIAR TABULEIRO 2--------------------------------------------------------------*/
void funcao_cria_tabuleiro_1(int tabuleiro1[][5])
{
    int linha1, coluna1;                                  //cria a matriz que sera o tabuleiro do player 2, que o player 1 vai atacar
        for(linha1=0 ; linha1 < 5 ; linha1++ )
            for(coluna1=0 ; coluna1 < 5 ; coluna1++ )
                tabuleiro1[linha1][coluna1]=-1;
}
/*----------------------------------------------------------MOSTRAR TABULEIRO-------------------------------------------------------------*/
void funcao_mostrar_tabuleiro(int tabuleiro[][5])
{

    int linha, coluna;                                      //mostra o tabuleiro do player 1, que o player 2 atacou

        printf("\n\n\t\t\t\t\t\t1 \t2 \t3 \t4 \t5");
        printf("\n");

        for(linha=0 ; linha < 5 ; linha++ ){                //for para mostrar as linhas
            printf("\t\t\t\t\t%d",linha+1);                 
            for(coluna=0 ; coluna < 5 ; coluna++ ){         //for para mostrar as colunas
                if(tabuleiro[linha][coluna]==-1){
                    printf("\t~");
                }else if(tabuleiro[linha][coluna]==0){
                    printf("\t*");
                }else if(tabuleiro[linha][coluna]==1){
                    printf("\tX");
                }

            }
            printf("\n");
        }

    }
/*----------------------------------------------------------MOSTRAR TABULEIRO 2-------------------------------------------------------------*/
void funcao_mostrar_tabuleiro_1(int tabuleiro1[][5])
{

    int linha1, coluna1;                                      //mostra o tabuleiro do player 2, que o player 1 atacou

        printf("\n\n\t\t\t\t\t\t1 \t2 \t3 \t4 \t5");
        printf("\n");

        for(linha1=0 ; linha1 < 5 ; linha1++ ){                //for para mostrar as linhas
            printf("\t\t\t\t\t%d",linha1+1);                 
            for(coluna1=0 ; coluna1 < 5 ; coluna1++ ){         //for para mostrar as colunas
                if(tabuleiro1[linha1][coluna1]==-1){
                    printf("\t~");
                }else if(tabuleiro1[linha1][coluna1]==0){
                    printf("\t*");
                }else if(tabuleiro1[linha1][coluna1]==1){
                    printf("\tX");
                }

            }
            printf("\n");
        }

    }
/*------------------------------------------------------------CRIAR NAVIOS 1----------------------------------------------------------------*/
void funcao_cria_navios(int navios[][2]){
        srand(time(NULL));
        int navio, anterior;

        for(navio=0 ; navio < 3 ; navio++){                                                                           //cria 3 navios aleatoriamente, em posiçoes distintas, para o tabuleiro do player 1
            navios[navio][0]= rand()%5;
            navios[navio][1]= rand()%5;

            for(anterior=0 ; anterior < navio ; anterior++){                                                          //verifica se o navio foi criado em uma posição com um navio ja existente, caso tenha sido ele repete ate ser criado em uma posicao diferente
                if( (navios[navio][0] == navios[anterior][0])&&(navios[navio][1] == navios[anterior][1]) )
                    do{
                        navios[navio][0]= rand()%5;
                        navios[navio][1]= rand()%5;
                    }while( (navios[navio][0] == navios[anterior][0])&&(navios[navio][1] == navios[anterior][1]) );
            }

        }
    }
/*------------------------------------------------------------CRIAR NAVIOS 2----------------------------------------------------------------*/
void funcao_cria_navios_1(int navios1[][2]){
        srand(time(NULL));
        int navio1, anterior1;

        for(navio1=0 ; navio1 < 3 ; navio1++){                                                                     //cria 3 navios aleatoriamente, em posiçoes distintas, para o tabuleiro do player 2
            navios1[navio1][0]= rand()%5;
            navios1[navio1][1]= rand()%5;
            navios1[navio1][0]= rand()%5;
            navios1[navio1][1]= rand()%5;
            navios1[navio1][0]= rand()%5;
            navios1[navio1][1]= rand()%5;

            for(anterior1=0 ; anterior1 < navio1 ; anterior1++){                                                    //verifica se o navio foi criado em uma posição com um navio ja existente, caso tenha sido ele repete ate ser criado em uma posicao diferente
                if( (navios1[navio1][0] == navios1[anterior1][0])&&(navios1[navio1][1] == navios1[anterior1][1]) )
                    do{
                        navios1[navio1][0]= rand()%5;
                        navios1[navio1][1]= rand()%5;
                        navios1[navio1][0]= rand()%5;
                        navios1[navio1][1]= rand()%5;
                        navios1[navio1][0]= rand()%5;
                        navios1[navio1][1]= rand()%5;
                    }while( (navios1[navio1][0] == navios1[anterior1][0])&&(navios1[navio1][1] == navios1[anterior1][1]) );
            }

        }
    }
/*--------------------------------------------------------------DAR TIRO------------------------------------------------------------------*/
void funcao_dar_tiro(int tiro[2])
{

        printf("\nInsira a posicao da linha que deseja bombardear:");       //seta em que linha sera dado o tiro , na jogada do player 2
        scanf("%d",&tiro[0]);
        tiro[0]--;

        printf("\nInsira a posicao da coluna que deseja bombardear:");      //seta em que coluna sera dado o tiro, na jogada do player 2
        scanf("%d",&tiro[1]);
        tiro[1]--;

}
/*--------------------------------------------------------------DAR TIRO 2------------------------------------------------------------------*/
void funcao_dar_tiro_1(int tiro1[2])
{

        printf("\nInsira a posicao da linha que deseja bombardear:");       //seta em que linha sera dado o tiro, na jogada do player 1
        scanf("%d",&tiro1[0]);
        tiro1[0]--;

        printf("\nInsira a posicao da coluna que deseja bombardear:");      //seta em que coluna sera dado o tiro, na jogada do player 1
        scanf("%d",&tiro1[1]);
        tiro1[1]--;

}
/*--------------------------------------------------------------ACERTAR-------------------------------------------------------------------*/
int funcao_acertar(int tiro[2], int navios[][2])
{
    int navio;

        for(navio=0 ; navio < 3 ; navio++){                                                 
            if( tiro[0]==navios[navio][0] && tiro[1]==navios[navio][1]){   //verifica se o tiro foi dado na mesma posicao que o navio esta, player 2
                return 1;
            }
        }
        return 0;
}
/*--------------------------------------------------------------ACERTAR 2-------------------------------------------------------------------*/
int funcao_acertar_1(int tiro1[2], int navios1[][2])
{
    int navio1;

        for(navio1=0 ; navio1 < 3 ; navio1++){                                                 
            if( tiro1[0]==navios1[navio1][0] && tiro1[1]==navios1[navio1][1]){   //verifica se o tiro foi dado na mesma posicao que o navio esta, player 1
                return 1;
            }
        }
        return 0;
    }
/*----------------------------------------------------------ALTERA TABULEIRO--------------------------------------------------------------*/
void funcao_altera_tabuleiro(int tiro[2], int navios[][2], int tabuleiro[][5]){ 
        if(funcao_acertar(tiro,navios))         //altera o tabuleiro. caso nao acerte o navio o valor sera 0 que equivale a "*". e caso acerte o navio, o valor sera 1 que equivale a "X". tabuleiro do player 1
            tabuleiro[tiro[0]][tiro[1]]=1;
        else
            tabuleiro[tiro[0]][tiro[1]]=0;
    }
/*----------------------------------------------------------ALTERA TABULEIRO 2--------------------------------------------------------------*/
void funcao_altera_tabuleiro_1(int tiro1[2], int navios1[][2], int tabuleiro1[][5]){ 
        if(funcao_acertar_1(tiro1,navios1))         //altera o tabuleiro. caso nao acerte o navio o valor sera 0 que equivale a "*". e caso acerte o navio, o valor sera 1 que equivale a "X". tabuleiro do player 2
            tabuleiro1[tiro1[0]][tiro1[1]]=1;
        else
            tabuleiro1[tiro1[0]][tiro1[1]]=0;
    }    
/*---------------------------------------------------------------DICA---------------------------------------------------------------------*/
void funcao_dica(int tiro[2], int navios[][2], int tentativas)
{
        int linha=0,
            coluna=0,
            fila;

        for(fila=0 ; fila < 3 ; fila++){            //percorer a linha e a coluna pelo tiro dado para verificar quantos barcos tem na linha e na coluna
            if(navios[fila][0]==tiro[0])
                linha++;
            if(navios[fila][1]==tiro[1])
                coluna++;
        }

        printf("\nDica %d: \nlinha %d -> %d navios\ncoluna %d -> %d navios\n",tentativas,tiro[0]+1,linha,tiro[1]+1,coluna);
}
/*---------------------------------------------------------------DICA 2---------------------------------------------------------------------*/
void funcao_dica_1(int tiro1[2], int navios1[][2], int tentativas)
{
        int linha1=0,
            coluna1=0,
            fila1;

        for(fila1=0 ; fila1 < 3 ; fila1++){            //percorer a linha e a coluna escolhidas pelo tiro para verificar quantos barcos tem em cada linha
            if(navios1[fila1][0]==tiro1[0])
                linha1++;
            if(navios1[fila1][1]==tiro1[1])
                coluna1++;
        }

        printf("\nDica %d: \nlinha %d -> %d navios\ncoluna %d -> %d navios\n",tentativas,tiro1[0]+1,linha1,tiro1[1]+1,coluna1);
}
/*----------------------------------------------------------------JOGO--------------------------------------------------------------------*/
int funcao_jogo() {

        int tabuleiro[5][5];
        int tabuleiro1[5][5];
        int navios[3][2];
        int navios1[3][2];
        int tiro[2];
        int tiro1[2];
        int tentativas=0,acertos=0;
        int J=0,N1=0,N2=0,S,T,SAI;
        char P1[10],P2[10];

        system("cls");
        system("color 1F");

        printf("\n\n                                                                 INICIO DA PARTIDA!!");
        sleep(1);
        system("cls");

        printf("\n                                                              Digite o primeiro nome do PLAYER 1:\n");
        scanf("%s",P1);
        system("cls");

        printf("\n                                                              Digite o primeiro nome do PLAYER 2:\n");
        scanf("%s",P2);
        system("cls");

        funcao_cria_tabuleiro(tabuleiro);                                                   //cria o tabuleiro do player 1, que o player 2 vai atacar
        funcao_cria_navios(navios);                                                          //cria os navios do player 1, que o player 2 vai atacar
        
        funcao_cria_tabuleiro_1(tabuleiro1);                                                 //cria o tabuleiro do player 1, que o player 2 vai atacar
        funcao_cria_navios_1(navios1);                                                         //cria os navios do player 1, que o player 2 vai atacar

        system("cls");
        printf("\n");

        N1=0;N2=0;SAI=0;

        do{
            
            if(J%2==0){                                                                    //vez do player 1 jogar
                    
                    system("color 2F");
                    printf("\t\t\t\t\t\t     Sua vez de jogar %s",P1); 

                        funcao_mostrar_tabuleiro_1(tabuleiro1);                                        //mostrar o tabuleiro do player 2
                        funcao_dar_tiro_1(tiro1);                                                      //dar o tiro no tabuleiro 
                        tentativas++;

                        if(funcao_acertar_1(tiro1,navios1)){                                            //se acertar
                            funcao_dica_1(tiro1,navios1,tentativas);                    
                            acertos++;
                            sleep(3);
                            system("cls");
                            printf("\n\n\t\t\t\t\tPARABENS %s. VOCE ACERTOU O TIRO!!!",P1);
                            sleep(3);
                            N1++;
                        }

                        else                                                                            //se nao acertar
                            funcao_dica_1(tiro1,navios1,tentativas);        

                        funcao_altera_tabuleiro_1(tiro1,navios1,tabuleiro1);                             //altera o tabuleiro de acordo com os eventos ocorridos na rodada
                        sleep(3);
                        system("cls");
                        
            }
               
            else{                                                                               //vez do player 2 jogar
                
                system("color 4F");
                printf("\t\t\t\t\t\t     Sua vez de jogar %s",P2);

                    funcao_mostrar_tabuleiro(tabuleiro);                                        //mostrar o tabuleiro do player 1 que o player 2 vai atacar
                    funcao_dar_tiro(tiro);                                                      //dar o tiro no tabuleiro
                    tentativas++;

                    if(funcao_acertar(tiro,navios)){                                            //se acertar
                        funcao_dica(tiro,navios,tentativas);                    
                        acertos++;
                        sleep(3);
                        system("cls");
                        printf("\n\n\t\t\t\t\tPARABENS %s. VOCE ACERTOU O TIRO!!!",P2);
                        sleep(3);  
                        N2++;

                    }

                    else                                                                        //se errar
                        funcao_dica(tiro,navios,tentativas);        

                    funcao_altera_tabuleiro(tiro,navios,tabuleiro);                             //altera o tabuleiro de acordo com os eventos ocorridos na rodada
                    sleep(3);
                    system("cls");

            }
            if( N1 == 3){SAI=1;}                                                                //se o player 1 derrubar os 3 barcos
            if( N2 == 3){SAI=1;}                                                                //se o player 2 derrubar os 3 barcos
            J++;

        }while(SAI!=1);
            
        system("color 1F");

        if(N1>N2){                                                                                                // se o player 1 ganhar
            T=(tentativas/2)+1;
            printf("\n\n\t\t\tJogo terminado. Parabens %s, voce venceu e acertou 3 navios em %d tentativas",P1,T);  
            funcao_mostrar_tabuleiro(tabuleiro1);
            printf("\n\t\t\t\t\t\t\tTabuleiro %s",P2);
            funcao_mostrar_tabuleiro_1(tabuleiro);                   
        }

        if(N2>N1){                                                                                                // se o player 2 ganhar
            T=(tentativas/2);
            printf("\n\n\t\t\tJogo terminado. Parabens %s, voce venceu e acertou 3 navios em %d tentativas",P2,T);  
            funcao_mostrar_tabuleiro(tabuleiro);
            printf("\n\t\t\t\t\t\t\tTabuleiro %s",P1);
            funcao_mostrar_tabuleiro_1(tabuleiro1);  
        }

        printf("\n\n\n\t\t\t\t\t\tDigite 1 para voltar ao menu\n");
        scanf("%d",&S);
        return funcao_menu_inicial();                                                                               //voltar para o menu
    }

int main() {
       
    system("cls");
    funcao_menu_inicial();          //ir para o menu
}