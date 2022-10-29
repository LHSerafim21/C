/*      FCT- UNESP, SIMPLETRON-LINGUAGEM DE PROGRAMAÇÃO     
        
              NOME:LUIZ HENRIQUE SERAFIM DA SILVA    */

/*##################################################################################################################################*/
//////////////////Bibliotecas
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
 
/////////////////////////Algumas definicoes
#define SIZE 1000
#define SENTINEL -99999
#define TRUE 1
#define FALSE 0
////////////////////////Operações de entrada/saida
#define READ 10
#define WRITE 11
////////////////////////Operações de carregamento/armazenamento
#define NEWLINE 12
#define LOAD 20
#define STORE 21
//////////////////////Operações  aritmeticas
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
/////////////////////Operações de transferencia de controle
#define EXPONENT 34
#define MODULUS 35
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43
 /*##################################################################################################################################*/

 ///////////////////////////////////////////Protótipos de função
void carregar(int *CarregarMemoria);
void executar(int *memoria, int *acPtr, int *icPtr, int *irPtr, int *opCodePtr, int *opPtr);
void dump(int *memoria, int acumulador, int Contador_de_Instrucao, int Registrador_de_Instrucao, int Codigo_de_Operacao, int operando);
int ValidarWord(int word);
//instrucao instruction
////////////////////////////////////////////Testar a validade da palavra
int ValidarWord(int word)
{
    return word >= -9999 && word <= 9999;
}
 
///////////////////////////////////////////Carrega instrução
void carregar(int *CarregarMemoria)
{
    long int instrucao; //instrução atual
    int i = 0;  //variável de indexação
 
    system("cls");
    printf("Bem-Vindo ao Simpletron.\n\n Por favor, digite no programa uma word de dados (instrucao) de cada vez.\n\n Vou digitar o numero do local e um ponto de interrogacao (?).");
    printf("Voce entao digita a palavra para esse local.\n Digite o sentinel -99999 para parar de entrar no seu programa.\n\n\n");
 
    printf("00 ?");
    scanf("%ld", &instrucao); //lê a instrução
 
     while(instrucao != SENTINEL)  //////enquanto o sentinel não é inserido pelo usuário
    {
        //teste de instrução para validade
        if(!ValidarWord(instrucao))
        {
            printf("Numero fora do intervalo. Por favor, digite novamente.\n");
        }
        //carregar instrucao
        else
        {
            CarregarMemoria[i++] = instrucao;
        }//end else
 
 
        printf("%02d ? ", i);
        scanf("%ld", &instrucao);
    }
}

////////////////////////////////////////////////////Executa instrução  
void executar(int *memoria, int *acPtr, int *icPtr, int *irPtr, int *opCodePtr, int *opPtr)
{
    int fatal = FALSE; //flag de erro fatal
    int temp; //espaço de retenção temporário
 
    printf("\nCOMECAR A EXECUCAO SIMPLETRON\n\n");
     
    //codigo de operacao e operando separados
    *irPtr = memoria[*icPtr];
    *opCodePtr = *irPtr / 100;
    *opPtr = *irPtr % 100;
 
    //loop enquanto o comando não é HALT ou fatal ou seja, enquanto não paramos ou encontramos um erro
    while(*opCodePtr != HALT && !fatal)
    {
        //determinar a ação apropriada
        switch(*opCodePtr)
        {
            //ler dados em local na memória
            case READ:
                printf("Insira um numero inteiro: ");
                scanf("%d", &temp);
                 
                //verifique a validade
                while(!ValidarWord(temp))
                {
                    printf("Numero fora do intervalo. Por favor, digite novamente:  ");
                    scanf("%d", &temp);
                }
 
                memoria[*opPtr] = temp;
                ++(*icPtr);
                break;
 
            //gravar dados da memória para a tela
            case WRITE:
                printf("Conteudo de %02d: %d\n", *opPtr, memoria[*opPtr]);
                ++(*icPtr);
                break;
 
 
            //carregar dados da memória no acumulador
            case LOAD:
                *acPtr = memoria[*opPtr];
                ++(*icPtr);
                break;
 
 
            //armazenar dados do acumulador na memória
            case STORE:
                memoria[*opPtr] = *acPtr;
                ++(*icPtr);
                break;
 
 
            //adicionar dados da memória aos dados no acumulador
            case ADD:
                temp = *acPtr + memoria[*opPtr];
 
 
                //verificar validade
                if(!ValidarWord(temp))
                {
                    printf("FATAL ERROR:  Overflow no acumulador\n");
                    printf("EXECUCAO SIMPLETRON TERMINADA ANORMALMENTE\n");
                    fatal = TRUE;
                }
                else
                {
                    *acPtr = temp;
                    ++(*icPtr);
                }
                break;
 
 
                        case SUBTRACT:
                                temp = *acPtr - memoria[*opPtr];
 
 
                                //verificar validade
                                if(!ValidarWord(temp))
                                {
                                        printf("FATAL ERROR:  Overflow no acumulador\n");
                                        printf("EXECUCAO SIMPLETRON TERMINADA ANORMALMENTE\n");
                                        fatal = TRUE;
                                }
                                else
                                { 
                                        *acPtr = temp;
                                        ++(*icPtr);
                                }
                                break;
 
 
                        case MULTIPLY:
                                temp = *acPtr * memoria[*opPtr];
 
 
                                //verificar validade
                                if(!ValidarWord(temp))
                                {
                                        printf("FATAL ERROR:  Overflow no acumulador\n");
                                        printf("EXECUCAO SIMPLETRON TERMINADA ANORMALMENTE\n");
                                        fatal = TRUE;
                                }
                                else
                                { 
                                        *acPtr = temp;
                                        ++(*icPtr);
                                }
                                break;
 
 
                       case EXPONENT:
                                temp = pow(*acPtr, memoria[*opPtr]);
 
 
                                //verificar validade
                                if(!ValidarWord(temp))
                                {
                                        printf("FATAL ERROR:  Overflow no acumulador\n");
                                        printf("EXECUCAO SIMPLETRON TERMINADA ANORMALMENTE\n");
                                        fatal = TRUE;
                                }
                                else
                                { 
                                        *acPtr = temp;
                                        ++(*icPtr);
                                }
                                break;
 
 
 
 
            //dividir dados na memória em dados no acumulador
            case DIVIDE:
                //verifique se há erro de divisão por zero
                if(memoria[*opPtr] == 0)
                {
                    printf("FATAL ERROR: Tentei dividir por zero...\n");
                    printf("EXECUCAO SIMPLETRON TERMINADA ANORMALMENTE\n");
                    fatal = TRUE;
                }
                else
                {
                    *acPtr /= memoria[*opPtr];
                    ++(*icPtr);
                }
                break;
 
 
                       //dividir dados na memória em dados no acumulador
                       case MODULUS:
                                //verifique se há erro de divisão por zero
                                if(memoria[*opPtr] == 0)
                                {
                                        printf("FATAL ERROR: Tentei dividir por zero...\n");
                                        printf("EXECUCAO SIMPLETRON TERMINADA ANORMALMENTE\n");
                                        fatal = TRUE;
                                }
                                else
                                {
                                        *acPtr %= memoria[*opPtr];
                                        ++(*icPtr);
                                }
                                break;
 
 
 
 
            //ramificar para um local específico na memória
            case BRANCH:
                *icPtr = *opPtr;
                break; 
 
 
            //desvio para o local na memória se o acumulador for negativo
            case BRANCHNEG:
                //se o acumulador for negativo
                if(*acPtr < 0)
                {
                    *icPtr = *opPtr;
                }
                else
                {
                    ++(*icPtr);
                }
                break;
 
 
            //desvio para o local na memória se o acumulador for zero
            case BRANCHZERO:
                //se o acumulador for zero
                if(*acPtr == 0)
                {
                    *icPtr = *opPtr;
                }
                else
                {
                    ++(*icPtr);
                }
                break;
 
 
            default:
                printf("FATAL ERROR: opcode invalido detectado..\n\n");
                printf("EXECUCAO SIMPLETRON TERMINADA ANORMALMENTE\n\n");
                fatal = TRUE;
                break;
        }
        //Separe o próximo código de operação e o operando
        *irPtr = memoria[*icPtr];
        *opCodePtr = *irPtr / 100;
        *opPtr = *irPtr % 100;
    }
 
 
    printf("\nFIM DA EXECUCAO DO SIMPLETRON\n");
}
 
///////////////////////////////////////////////////////////////FUNCAO DUMP 
void dump(int *memoria, int acumulador, int Contador_de_Instrucao, int Registrador_de_Instrucao, int Codigo_de_Operacao, int operando)
{
    int i; /* contador */
     
    printf( "\n%s\n%-23s%+05d\n%-23s%5.2d\n%-23s%+05d\n%-23s%5.2d\n%-23s%5.2d", "REGISTROS:", "acumulador", acumulador, "contador de instrucao",
        Contador_de_Instrucao, "registro de instrucao", Registrador_de_Instrucao,  "codigo de operacao", Codigo_de_Operacao, "operando", operando );
 
 
    printf("\n\nMEMORIA:\n    ");
 
 
    //imprimir cabeçalhos de coluna
    for(i = 0; i <= 9; i++)
    {
        printf("%5d ", i);
    }
 
 
    //cabeçalhos de linha printf e conteúdo de memória
    for(i = 0; i < SIZE; i++)
    {
        //imprimir em incrementos de 10
        if(i % 10 == 0)
        {
            printf("\n%2d ", i);
        }
        printf("%+05d ", memoria[i]);
    }
    printf("\n");
}
 
 ///////////////////////////////////////////////////////FUNCAO PRINCIPAL
int main(void)
{
    int memoria[SIZE]; //definir matriz de memória
    int ac = 0;       //acumulador
    int ic = 0;   //contador de instruções
    int opCode = 0;   //código de operação
    int op = 0;       //operando
    int ir = 0;       //registrador de instruções
    int i;            //contador
 
 
    //limpar memória
    for(i = 0; i < SIZE; i++)
    {
        memoria[i] = 0;
    }
 
 
 
 
    carregar(memoria);
    executar(memoria, &ac, &ic, &ir, &opCode, &op);
    dump(memoria, ac, ic, ir, opCode, op);
 
 
    return 0;
}