#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void funcao_cria_Matriz(int Matriz[][4])                //cria a matriz que sera a tabela de tarefas
{
    int linha, coluna;                                  
        for(linha=0 ; linha < 4 ; linha++ )
            for(coluna=0 ; coluna < 4 ; coluna++ )
                Matriz[linha][coluna]=-1;
}

void funcao_mostrar_Matriz(int Matriz[][4])
{


    int linha, coluna, pessoa;                                      //mostra a Matriz

        printf("\n\n\t    |Tarefa 1|Tarefa 2|Tarefa 3|Tarefa 4|");
        printf("\n");

        for(linha=0 ; linha < 4 ; linha++ ){                //for para mostrar as linhas
            printf("Pessoa %d",linha+1);                 
            for(coluna=0 ; coluna < 4 ; coluna++ ){         //for para mostrar as colunas
                if(Matriz[linha][coluna]==-1){
                    printf("        ~");
                }
                if(Matriz[linha][coluna]!=-1){
                    printf ("        %d", Matriz[linha][coluna]);
                }
   

            }
            printf("\n");
        }
        printf("\n");

}

void funcao_Branch_and_Bound(int Matriz[][4]){  //funcao branch and bound
    
    int M=1,N=1,x=0,linha=0,coluna=0,Q,i=1,Custo=0,Solucao[4],MelhorSolucao[4],inf=0,y=0,CusAnt=0,infCus=0,infPessoa=0,infValor=0,infValor2=0,k;

    Solucao[1]=-1;MelhorSolucao[1]=-1;   //vetores q armazenaram a melhor distribuicao das tarefas
    Solucao[2]=-1;MelhorSolucao[2]=-1;
    Solucao[3]=-1;MelhorSolucao[3]=-1;
    Solucao[4]=-1;MelhorSolucao[4]=-1;
    
    system("color 9F");
    printf("/------------------------RESULTADO----------------------------/\n");
    funcao_mostrar_Matriz(Matriz);

    printf("\n\nComecar verificacao...\n");
    sleep(3);

    while(x!=16){
        
        system("cls");

        printf("Menor Custo atual: %d, A atual melhor distribuicao das pessoas por tarefa |Tarefa 1: Pessoa %d |\n                                                                         |Tarefa 2: Pessoa %d |\n                                                                         |Tarefa 3: Pessoa %d |\n                                                                         |Tarefa 4: Pessoa %d |",Custo, Solucao[1],Solucao[2],Solucao[3],Solucao[4]);
        funcao_mostrar_Matriz(Matriz);
         
        printf("Pessoa %d: Peso da tarefa %d a ser verificado: %d\n",N,M, Matriz[linha][coluna]);

        
            if(Solucao[i]==-1){                                   //custo da checagem inicial e referencia para a verificacao 
                Solucao[i] =  N;                                    //a  posicao i do vetor e atribuida ao numero da pessoa
                Custo=Custo + Matriz[linha][coluna];                //calcular custo
                linha=linha+1;coluna=coluna+1;            
            }

            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            else if(((Solucao[1])&&(Solucao[2])&&(Solucao[3])&&(Solucao[4]))!= -1){     //se todos os valores que serao usados como referencia ja tiverem no vetor
                
                ;
                linha=linha-1;coluna=coluna-1;N=4;
                system("cls");
                printf("A REFERENCIA PARA A VERIFICACAO e:|Tarefa 1: Pessoa %d |\n                                  |Tarefa 2: Pessoa %d |\n                                  |Tarefa 3: Pessoa %d |\n                                  |Tarefa 4: Pessoa %d |", Solucao[1],Solucao[2],Solucao[3],Solucao[4]);
                CusAnt=Custo;
                printf("\n\nCOM O CUSTO IGUAL A: %d\n\nESPERE....",Custo);
                

                sleep(6);
                system("cls");

                do{                               //verificacao tarefa 4
                    
                    Custo=Custo-Matriz[linha][coluna];      //subtrai o valor do custo da posicao 4x4 da matriz
                    N=N-1;                                  
                    linha=linha-1;
                    Solucao[4]= N;                          //Atribui a pessoa ao vetor
                    y=y+1;
                    Custo=Custo+Matriz[linha][coluna];      //calcula o custo apartir da nova forma

                    funcao_mostrar_Matriz(Matriz);
                    printf("/---Verificacao %d de 3- Verificando qual o menor custo para a TAREFA 4---/\n\nCusto atual: %d\n\nCusto Anterior: %d\n\nVETOR ATUAL: {%d,%d,%d,%d}",y,Custo,CusAnt,Solucao[1],Solucao[2],Solucao[3],Solucao[4]);
                    
                    if(Custo<CusAnt){                               //Se o custo for menor que o custo anterior salva as informacoes analisadas
                        infValor = linha; infValor2 = coluna;
                        infCus = Custo;
                        infPessoa = N;

                        printf("Apos a verificacao a pessoa mais qualificada para fazer a TAREFA 4 e %d, com o valor de desempenho %d e o custo total %d\n\nESPERE....",infPessoa,Matriz[infValor][infValor2],infCus);
                        sleep(10);
                    }

                    CusAnt=Custo;
                    sleep(6);
                    system("cls");
                }while(y!=3);

                if(y==3){

                    printf("/-----------------------------------------------------------------/\n\nApos a verificacao, ate o momento, a pessoa mais qualificada para fazer a TAREFA 4 e: %d\n\n Com o valor de desempenho %d e o custo total %d\n\nESPERE....",infPessoa,Matriz[infValor][infValor2],infCus);
                    sleep(6);
                    linha=k;coluna=coluna-1;
                    Custo=infCus;
                    N=infPessoa;
                    system("cls");
                    printf("/-------------------Agora verificando a tarefa 3------------------/");
                }

                
            }       
            i=i+1;M=M+1;N=N+1;

            sleep(6);


            x++;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
    
    int custo, Matriz[4][4], pessoa = 0, tarefa = 0,x,A=1,B=1,teste=0;
    funcao_cria_Matriz(Matriz);

    while(teste!=16){       //Inserir os elementos na matriz
        
        
        system("cls");
        printf("ELEMENTO %d\n",teste);
        printf("/------------------------INTERFACE (Branch-and-Bound)----------------------------/\n\nDigite o valor do custo que a PESSOA %d vai desepenhar na TAREFA %d:\n\n",A,B++);
        funcao_mostrar_Matriz(Matriz);
        scanf("%d",&custo);

        Matriz[pessoa][tarefa]=custo;

        tarefa=tarefa+1;

        if(B==5){
            A=A+1;      
            B=1;    
        }

        sleep(1);
        teste++;

    }

    system("cls");
    funcao_Branch_and_Bound(Matriz);  

    return 0;
}







